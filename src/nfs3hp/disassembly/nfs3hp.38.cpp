#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_4f3a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3a32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a33  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3a35  e8d6ffffff             -call 0x4f3a10
    cpu.esp -= 4;
    sub_4f3a10(app, cpu);
    if (cpu.terminate) return;
    // 004f3a3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f3a3f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3a41  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004f3a44  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f3a46  e8f5bffdff             -call 0x4cfa40
    cpu.esp -= 4;
    sub_4cfa40(app, cpu);
    if (cpu.terminate) return;
    // 004f3a4b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004f3a4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f3a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a61  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f3a63  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3a65  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f3a67  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f3a69  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3a6d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f3a6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a70  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f3a74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3a75  e872050000             -call 0x4f3fec
    cpu.esp -= 4;
    sub_4f3fec(app, cpu);
    if (cpu.terminate) return;
    // 004f3a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a7b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f3a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3a81  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f3a83  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f3a85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3a87  e8cc070000             -call 0x4f4258
    cpu.esp -= 4;
    sub_4f4258(app, cpu);
    if (cpu.terminate) return;
    // 004f3a8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3a8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f3a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3a90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3a91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f3a93:
    // 004f3a93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3a95  42                     -inc edx
    (cpu.edx)++;
    // 004f3a96  e825090000             -call 0x4f43c0
    cpu.esp -= 4;
    sub_4f43c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3a9b  83fa10                 +cmp edx, 0x10
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
    // 004f3a9e  7cf3                   -jl 0x4f3a93
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3a93;
    }
    // 004f3aa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3aa2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3aa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3aa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3aa4  83f810                 +cmp eax, 0x10
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
    // 004f3aa7  7d0c                   -jge 0x4f3ab5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3aab  7c08                   -jl 0x4f3ab5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aad  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3ab4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ab5:
    // 004f3ab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ab5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f3ab5;
    // 004f3aa4  83f810                 +cmp eax, 0x10
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
    // 004f3aa7  7d0c                   -jge 0x4f3ab5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3aab  7c08                   -jl 0x4f3ab5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3ab5;
    }
    // 004f3aad  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3ab4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ab5:
L_entry_0x004f3ab5:
    // 004f3ab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ab8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ab9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3abb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3abc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3abd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3abe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3ac1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f3ac4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3ac9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3acb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3acd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3acf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f3ad3  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3ada:
    // 004f3ada  0fbe7016               -movsx esi, byte ptr [eax + 0x16]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
    // 004f3ade  39f2                   +cmp edx, esi
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
    // 004f3ae0  7d3a                   -jge 0x4f3b1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3b1c;
    }
    // 004f3ae2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3ae4  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3ae6  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3ae9  3b3c24                 +cmp edi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3aec  7506                   -jne 0x4f3af4
    if (!cpu.flags.zf)
    {
        goto L_0x004f3af4;
    }
L_0x004f3aee:
    // 004f3aee  83c52c                 +add ebp, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3af1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f3af2  ebe6                   -jmp 0x4f3ada
    goto L_0x004f3ada;
L_0x004f3af4:
    // 004f3af4  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3af8  39d7                   +cmp edi, edx
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
    // 004f3afa  7507                   -jne 0x4f3b03
    if (!cpu.flags.zf)
    {
        goto L_0x004f3b03;
    }
    // 004f3afc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b00  884817                 -mov byte ptr [eax + 0x17], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */) = cpu.cl;
L_0x004f3b03:
    // 004f3b03  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3b05  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004f3b0a  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3b0c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3b0e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b12  46                     -inc esi
    (cpu.esi)++;
    // 004f3b13  83c32c                 +add ebx, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3b16  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004f3b1a  ebd2                   -jmp 0x4f3aee
    goto L_0x004f3aee;
L_0x004f3b1c:
    // 004f3b1c  8a5016                 -mov dl, byte ptr [eax + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004f3b1f  fe4816                 -dec byte ptr [eax + 0x16]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */))--;
    // 004f3b22  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b25  3a5016                 +cmp dl, byte ptr [eax + 0x16]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3b28  7f0a                   -jg 0x4f3b34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3b34;
    }
    // 004f3b2a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3b34:
    // 004f3b34  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b37  fe4817                 -dec byte ptr [eax + 0x17]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */))--;
    // 004f3b3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f3b31;
    // 004f3ab8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ab9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3abb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3abc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3abd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3abe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3ac1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f3ac4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3ac9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3acb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3acd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3acf  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f3ad3  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3ada:
    // 004f3ada  0fbe7016               -movsx esi, byte ptr [eax + 0x16]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
    // 004f3ade  39f2                   +cmp edx, esi
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
    // 004f3ae0  7d3a                   -jge 0x4f3b1c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f3b1c;
    }
    // 004f3ae2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3ae4  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004f3ae6  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3ae9  3b3c24                 +cmp edi, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3aec  7506                   -jne 0x4f3af4
    if (!cpu.flags.zf)
    {
        goto L_0x004f3af4;
    }
L_0x004f3aee:
    // 004f3aee  83c52c                 +add ebp, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3af1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f3af2  ebe6                   -jmp 0x4f3ada
    goto L_0x004f3ada;
L_0x004f3af4:
    // 004f3af4  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3af8  39d7                   +cmp edi, edx
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
    // 004f3afa  7507                   -jne 0x4f3b03
    if (!cpu.flags.zf)
    {
        goto L_0x004f3b03;
    }
    // 004f3afc  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b00  884817                 -mov byte ptr [eax + 0x17], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */) = cpu.cl;
L_0x004f3b03:
    // 004f3b03  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004f3b05  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004f3b0a  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f3b0c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3b0e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3b12  46                     -inc esi
    (cpu.esi)++;
    // 004f3b13  83c32c                 +add ebx, 0x2c
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f3b16  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004f3b1a  ebd2                   -jmp 0x4f3aee
    goto L_0x004f3aee;
L_0x004f3b1c:
    // 004f3b1c  8a5016                 -mov dl, byte ptr [eax + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004f3b1f  fe4816                 -dec byte ptr [eax + 0x16]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */))--;
    // 004f3b22  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b25  3a5016                 +cmp dl, byte ptr [eax + 0x16]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3b28  7f0a                   -jg 0x4f3b34
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3b34;
    }
    // 004f3b2a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x004f3b31:
    // 004f3b31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3b34:
    // 004f3b34  8a5017                 -mov dl, byte ptr [eax + 0x17]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 004f3b37  fe4817                 -dec byte ptr [eax + 0x17]
    (app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */))--;
    // 004f3b3a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f3b3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3b44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3b45  8d50f4                 -lea edx, [eax - 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-12) /* -0xc */);
    // 004f3b48  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004f3b4a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f3b4f  8b04854c259f00         -mov eax, dword ptr [eax*4 + 0x9f254c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
    // 004f3b56  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3b59  e862c8fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3b5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3b5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3b62  8b8089259f00           -mov eax, dword ptr [eax + 0x9f2589]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429833) /* 0x9f2589 */);
    // 004f3b68  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004f3b6b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3b6d  8b1c854c259f00         -mov ebx, dword ptr [eax*4 + 0x9f254c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4);
L_0x004f3b74:
    // 004f3b74  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3b76  3b501c                 +cmp edx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3b79  7607                   -jbe 0x4f3b82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f3b82;
    }
    // 004f3b7b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f3b7d  2b481c                 -sub ecx, dword ptr [eax + 0x1c]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 004f3b80  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f3b82:
    // 004f3b82  015014                 -add dword ptr [eax + 0x14], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3b85  29501c                 -sub dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3b88  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f3b8b  3b5018                 +cmp edx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3b8e  7208                   -jb 0x4f3b98
    if (cpu.flags.cf)
    {
        goto L_0x004f3b98;
    }
    // 004f3b90  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3b93  e820ffffff             -call 0x4f3ab8
    cpu.esp -= 4;
    sub_4f3ab8(app, cpu);
    if (cpu.terminate) return;
L_0x004f3b98:
    // 004f3b98  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f3b9a  7495                   -je 0x4f3b31
    if (cpu.flags.zf)
    {
        return sub_4f3b31(app, cpu);
    }
    // 004f3b9c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f3b9e  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004f3ba0  ebd2                   -jmp 0x4f3b74
    goto L_0x004f3b74;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f3ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ba5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3ba6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3ba7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3ba8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3ba9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3bac  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f3bae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f3bb0  0fbe7817               -movsx edi, byte ptr [eax + 0x17]
    cpu.edi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3bb4  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004f3bbb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004f3bbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3bc0  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004f3bc2  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004f3bc5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3bc8  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3bcc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3bce  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f3bd0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f3bd3  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f3bd6  8d7d20                 -lea edi, [ebp + 0x20]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f3bd9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3bdd  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004f3bdf  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3be3  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f3be6  e8eddd0100             -call 0x5119d8
    cpu.esp -= 4;
    sub_5119d8(app, cpu);
    if (cpu.terminate) return;
    // 004f3beb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f3bee  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3bf2  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004f3bf5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f3bf7  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f3bfa  e8c1c7fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3bff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f3c01  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f3c04  e8e7df0100             -call 0x511bf0
    cpu.esp -= 4;
    sub_511bf0(app, cpu);
    if (cpu.terminate) return;
    // 004f3c09  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f3c0c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f3c11  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f3c14  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f3c16  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f3c18  7405                   -je 0x4f3c1f
    if (cpu.flags.zf)
    {
        goto L_0x004f3c1f;
    }
    // 004f3c1a  19c0                   +sbb eax, eax
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
    // 004f3c1c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f3c1f:
    // 004f3c1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3c21  7445                   -je 0x4f3c68
    if (cpu.flags.zf)
    {
        goto L_0x004f3c68;
    }
L_0x004f3c23:
    // 004f3c23  66837d1c00             +cmp word ptr [ebp + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3c28  755b                   -jne 0x4f3c85
    if (!cpu.flags.zf)
    {
        goto L_0x004f3c85;
    }
    // 004f3c2a  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004f3c2d  8d7d24                 -lea edi, [ebp + 0x24]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c30  8d7530                 -lea esi, [ebp + 0x30]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 004f3c33  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f3c36  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3c37  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f3c38  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004f3c39:
    // 004f3c39  807d1401               +cmp byte ptr [ebp + 0x14], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3c3d  741e                   -je 0x4f3c5d
    if (cpu.flags.zf)
    {
        goto L_0x004f3c5d;
    }
    // 004f3c3f  8d4d3c                 -lea ecx, [ebp + 0x3c]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */);
    // 004f3c42  8d5d24                 -lea ebx, [ebp + 0x24]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c45  8d551c                 -lea edx, [ebp + 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004f3c48  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f3c4b  e880d60100             -call 0x5112d0
    cpu.esp -= 4;
    sub_5112d0(app, cpu);
    if (cpu.terminate) return;
    // 004f3c50  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3c53  837d0800               +cmp dword ptr [ebp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3c57  7c32                   -jl 0x4f3c8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3c8b;
    }
    // 004f3c59  c6451401               -mov byte ptr [ebp + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x004f3c5d:
    // 004f3c5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3c5f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3c62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3c67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3c68:
    // 004f3c68  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 004f3c6d  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f3c71  8d7524                 -lea esi, [ebp + 0x24]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004f3c74  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f3c76  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 004f3c78  7405                   -je 0x4f3c7f
    if (cpu.flags.zf)
    {
        goto L_0x004f3c7f;
    }
    // 004f3c7a  19c0                   +sbb eax, eax
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
    // 004f3c7c  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004f3c7f:
    // 004f3c7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3c81  75a0                   -jne 0x4f3c23
    if (!cpu.flags.zf)
    {
        goto L_0x004f3c23;
    }
    // 004f3c83  ebb4                   -jmp 0x4f3c39
    goto L_0x004f3c39;
L_0x004f3c85:
    // 004f3c85  c6451402               -mov byte ptr [ebp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
    // 004f3c89  ebd2                   -jmp 0x4f3c5d
    goto L_0x004f3c5d;
L_0x004f3c8b:
    // 004f3c8b  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f3c90  bbc0cc5400             -mov ebx, 0x54ccc0
    cpu.ebx = 5557440 /*0x54ccc0*/;
    // 004f3c95  be15010000             -mov esi, 0x115
    cpu.esi = 277 /*0x115*/;
    // 004f3c9a  68d8cc5400             -push 0x54ccd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557464 /*0x54ccd8*/;
    cpu.esp -= 4;
    // 004f3c9f  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f3ca5  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f3cab  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f3cb1  e85ad3f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3cb6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3cb9  c6451401               -mov byte ptr [ebp + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004f3cbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3cbf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f3cc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3cc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3cc8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3cc9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3cca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3ccc  8d5a08                 -lea ebx, [edx + 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f3ccf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3cd2  e8e9c6fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3cd7  0fbe5117               -movsx edx, byte ptr [ecx + 0x17]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */)));
    // 004f3cdb  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3ce2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3ce4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3ce7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3ce9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3cec  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004f3cee  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3cf0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3cf2  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004f3cf5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3cfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3cfc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f3d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3d00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3d01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3d02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3d03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3d06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f3d08  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004f3d0b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f3d0f  8d420c                 -lea eax, [edx + 0xc]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f3d12  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f3d16  0fbe4b17               -movsx ecx, byte ptr [ebx + 0x17]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */)));
    // 004f3d1a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004f3d21  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3d23  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3d26  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f3d28  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3d2b  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3d2d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3d2f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f3d32  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004f3d34  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f3d38  01411c                 -add dword ptr [ecx + 0x1c], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3d3b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f3d3e  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 004f3d41  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004f3d44  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004f3d46  e889d70100             -call 0x5114d4
    cpu.esp -= 4;
    sub_5114d4(app, cpu);
    if (cpu.terminate) return;
    // 004f3d4b  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f3d4e  83790c00               +cmp dword ptr [ecx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3d52  7c12                   -jl 0x4f3d66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3d66;
    }
L_0x004f3d54:
    // 004f3d54  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3d58  7c3f                   -jl 0x4f3d99
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3d99;
    }
    // 004f3d5a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3d5f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3d62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3d65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3d66:
    // 004f3d66  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f3d6b  b814cd5400             -mov eax, 0x54cd14
    cpu.eax = 5557524 /*0x54cd14*/;
    // 004f3d70  ba58010000             -mov edx, 0x158
    cpu.edx = 344 /*0x158*/;
    // 004f3d75  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f3d7b  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f3d80  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f3d86  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f3d89  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f3d8a  6828cd5400             -push 0x54cd28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557544 /*0x54cd28*/;
    cpu.esp -= 4;
    // 004f3d8f  e87cd2f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3d94  83c408                 +add esp, 8
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
    // 004f3d97  ebbb                   -jmp 0x4f3d54
    goto L_0x004f3d54;
L_0x004f3d99:
    // 004f3d99  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f3d9c  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3d9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3da4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3da7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3da8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3da9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3daa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3dac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3dad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3daf  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3db2  e809c6fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3db7  8a4117                 -mov al, byte ptr [ecx + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */);
    // 004f3dba  fe4117                 -inc byte ptr [ecx + 0x17]
    (app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */))++;
    // 004f3dbd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3dc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3dc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3dc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3dc5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3dc6  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f3dc8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f3dcd  81fb5343446c           +cmp ebx, 0x6c444353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816413011 /*0x6c444353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3dd3  7424                   -je 0x4f3df9
    if (cpu.flags.zf)
    {
        goto L_0x004f3df9;
    }
    // 004f3dd5  81fb5343486c           +cmp ebx, 0x6c484353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816675155 /*0x6c484353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3ddb  7423                   -je 0x4f3e00
    if (cpu.flags.zf)
    {
        goto L_0x004f3e00;
    }
    // 004f3ddd  81fb5343456c           +cmp ebx, 0x6c454353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816478547 /*0x6c454353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3de3  7422                   -je 0x4f3e07
    if (cpu.flags.zf)
    {
        goto L_0x004f3e07;
    }
    // 004f3de5  81fb5343436c           +cmp ebx, 0x6c434353
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816347475 /*0x6c434353*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3deb  7521                   -jne 0x4f3e0e
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e0e;
    }
    // 004f3ded  e8d6feffff             -call 0x4f3cc8
    cpu.esp -= 4;
    sub_4f3cc8(app, cpu);
    if (cpu.terminate) return;
L_0x004f3df2:
    // 004f3df2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3df4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f3df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3df8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3df9:
    // 004f3df9  e802ffffff             -call 0x4f3d00
    cpu.esp -= 4;
    sub_4f3d00(app, cpu);
    if (cpu.terminate) return;
    // 004f3dfe  ebf2                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e00:
    // 004f3e00  e89ffdffff             -call 0x4f3ba4
    cpu.esp -= 4;
    sub_4f3ba4(app, cpu);
    if (cpu.terminate) return;
    // 004f3e05  ebeb                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e07:
    // 004f3e07  e8a0ffffff             -call 0x4f3dac
    cpu.esp -= 4;
    sub_4f3dac(app, cpu);
    if (cpu.terminate) return;
    // 004f3e0c  ebe4                   -jmp 0x4f3df2
    goto L_0x004f3df2;
L_0x004f3e0e:
    // 004f3e0e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f3e11  e8aac5fdff             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004f3e16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f3e18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3e1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3e1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3e1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3e1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3e1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f3e21  0fbe5017               -movsx edx, byte ptr [eax + 0x17]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */)));
    // 004f3e25  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3e2c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e2e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e31  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e33  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004f3e35  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e38  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f3e3a  83791000               +cmp dword ptr [ecx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3e3e  740e                   -je 0x4f3e4e
    if (cpu.flags.zf)
    {
        goto L_0x004f3e4e;
    }
    // 004f3e40  6683792800             +cmp word ptr [ecx + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3e45  7c0d                   -jl 0x4f3e54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3e54;
    }
    // 004f3e47  6683792800             +cmp word ptr [ecx + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f3e4c  750f                   -jne 0x4f3e5d
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e5d;
    }
L_0x004f3e4e:
    // 004f3e4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3e50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3e54:
    // 004f3e54  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f3e59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3e5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3e5d:
    // 004f3e5d  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f3e60  e8fbc5fdff             -call 0x4d0460
    cpu.esp -= 4;
    sub_4d0460(app, cpu);
    if (cpu.terminate) return;
    // 004f3e65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3e67  3d00093d00             +cmp eax, 0x3d0900
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000000 /*0x3d0900*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3e6c  7605                   -jbe 0x4f3e73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f3e73;
    }
    // 004f3e6e  ba00093d00             -mov edx, 0x3d0900
    cpu.edx = 4000000 /*0x3d0900*/;
L_0x004f3e73:
    // 004f3e73  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f3e7a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e7c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3e7f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e81  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f3e84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3e86  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f3e89  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3e8d  f77110                 -div dword ptr [ecx + 0x10]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004f3e90  0fbf5128               -movsx edx, word ptr [ecx + 0x28]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
    // 004f3e94  39d0                   +cmp eax, edx
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
    // 004f3e96  720c                   -jb 0x4f3ea4
    if (cpu.flags.cf)
    {
        goto L_0x004f3ea4;
    }
    // 004f3e98  66c741280000           -mov word ptr [ecx + 0x28], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004f3e9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ea0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ea3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3ea4:
    // 004f3ea4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f3ea7  e8e4c5fdff             -call 0x4d0490
    cpu.esp -= 4;
    sub_4d0490(app, cpu);
    if (cpu.terminate) return;
    // 004f3eac  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3eae  75a4                   -jne 0x4f3e54
    if (!cpu.flags.zf)
    {
        goto L_0x004f3e54;
    }
    // 004f3eb0  66c741280000           -mov word ptr [ecx + 0x28], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004f3eb6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3eb8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eb9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3ebb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f3ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3ebc  e8af510000             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004f3ec1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3ec3  0f85ecfbffff           -jne 0x4f3ab5
    if (!cpu.flags.zf)
    {
        return sub_4f3ab5(app, cpu);
    }
    // 004f3ec9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3eca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3ecb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f3ecc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f3ecd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004f3ecf:
    // 004f3ecf  8bb74c259f00           -mov esi, dword ptr [edi + 0x9f254c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429772) /* 0x9f254c */);
    // 004f3ed5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f3ed7  7406                   -je 0x4f3edf
    if (cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3ed9  807e1600               +cmp byte ptr [esi + 0x16], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3edd  750f                   -jne 0x4f3eee
    if (!cpu.flags.zf)
    {
        goto L_0x004f3eee;
    }
L_0x004f3edf:
    // 004f3edf  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3ee2  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3ee5  75e8                   -jne 0x4f3ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3ecf;
    }
    // 004f3ee7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3ee9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3eed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3eee:
    // 004f3eee  807e1402               +cmp byte ptr [esi + 0x14], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3ef2  7538                   -jne 0x4f3f2c
    if (!cpu.flags.zf)
    {
        goto L_0x004f3f2c;
    }
    // 004f3ef4  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3ef7  e884d70100             -call 0x511680
    cpu.esp -= 4;
    sub_511680(app, cpu);
    if (cpu.terminate) return;
    // 004f3efc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3efe  7fdf                   -jg 0x4f3edf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3edf;
    }
    // 004f3f00  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f3f03  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f3f06  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3f09  8d4e3c                 -lea ecx, [esi + 0x3c]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 004f3f0c  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f3f0f  8d561c                 -lea edx, [esi + 0x1c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f3f12  e805d90100             -call 0x51181c
    cpu.esp -= 4;
    sub_51181c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f17  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3f1a  e8b1d30100             -call 0x5112d0
    cpu.esp -= 4;
    sub_5112d0(app, cpu);
    if (cpu.terminate) return;
    // 004f3f1f  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f3f22  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004f3f26  7c5d                   -jl 0x4f3f85
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f3f85;
    }
L_0x004f3f28:
    // 004f3f28  c6461401               -mov byte ptr [esi + 0x14], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x004f3f2c:
    // 004f3f2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f3f2e  e8e9feffff             -call 0x4f3e1c
    cpu.esp -= 4;
    sub_4f3e1c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3f35  75a8                   -jne 0x4f3edf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3f37  807e1401               +cmp byte ptr [esi + 0x14], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f3f3b  0f8476000000           -je 0x4f3fb7
    if (cpu.flags.zf)
    {
        goto L_0x004f3fb7;
    }
    // 004f3f41  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
L_0x004f3f46:
    // 004f3f46  e8d5ce0000             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004f3f4b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f3f4d:
    // 004f3f4d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f3f50  49                     -dec ecx
    (cpu.ecx)--;
    // 004f3f51  e8aac3fdff             -call 0x4d0300
    cpu.esp -= 4;
    sub_4d0300(app, cpu);
    if (cpu.terminate) return;
    // 004f3f56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3f58  740b                   -je 0x4f3f65
    if (cpu.flags.zf)
    {
        goto L_0x004f3f65;
    }
    // 004f3f5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f3f5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f3f5e  e861feffff             -call 0x4f3dc4
    cpu.esp -= 4;
    sub_4f3dc4(app, cpu);
    if (cpu.terminate) return;
    // 004f3f63  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f3f65:
    // 004f3f65  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f3f67  7404                   -je 0x4f3f6d
    if (cpu.flags.zf)
    {
        goto L_0x004f3f6d;
    }
    // 004f3f69  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f3f6b  7fe0                   -jg 0x4f3f4d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f3f4d;
    }
L_0x004f3f6d:
    // 004f3f6d  e80acf0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f3f72  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3f75  83ff40                 +cmp edi, 0x40
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3f78  0f8551ffffff           -jne 0x4f3ecf
    if (!cpu.flags.zf)
    {
        goto L_0x004f3ecf;
    }
    // 004f3f7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f3f80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3f84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f3f85:
    // 004f3f85  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f3f8a  bb5ccd5400             -mov ebx, 0x54cd5c
    cpu.ebx = 5557596 /*0x54cd5c*/;
    // 004f3f8f  b835020000             -mov eax, 0x235
    cpu.eax = 565 /*0x235*/;
    // 004f3f94  6874cd5400             -push 0x54cd74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557620 /*0x54cd74*/;
    cpu.esp -= 4;
    // 004f3f99  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f3f9f  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f3fa5  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f3faa  e861d0f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f3faf  83c404                 +add esp, 4
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
    // 004f3fb2  e971ffffff             -jmp 0x4f3f28
    goto L_0x004f3f28;
L_0x004f3fb7:
    // 004f3fb7  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f3fba  e8f9d50100             -call 0x5115b8
    cpu.esp -= 4;
    sub_5115b8(app, cpu);
    if (cpu.terminate) return;
    // 004f3fbf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f3fc1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f3fc3  0f8416ffffff           -je 0x4f3edf
    if (cpu.flags.zf)
    {
        goto L_0x004f3edf;
    }
    // 004f3fc9  e978ffffff             -jmp 0x4f3f46
    goto L_0x004f3f46;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f3fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f3fd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f3fd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f3fd5:
    // 004f3fd5  83b84c259f0000         +cmp dword ptr [eax + 0x9f254c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429772) /* 0x9f254c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f3fdc  7401                   -je 0x4f3fdf
    if (cpu.flags.zf)
    {
        goto L_0x004f3fdf;
    }
    // 004f3fde  42                     -inc edx
    (cpu.edx)++;
L_0x004f3fdf:
    // 004f3fdf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f3fe2  83f840                 +cmp eax, 0x40
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
    // 004f3fe5  75ee                   -jne 0x4f3fd5
    if (!cpu.flags.zf)
    {
        goto L_0x004f3fd5;
    }
    // 004f3fe7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f3fe9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f3fea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f3fec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f3fec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f3fed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f3fee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f3fef  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f3ff2  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f3ff6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f3ffa  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f3ffe  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f4000  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4007  0f847e010000           -je 0x4f418b
    if (cpu.flags.zf)
    {
        goto L_0x004f418b;
    }
    // 004f400d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f400f  7e08                   -jle 0x4f4019
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4019;
    }
    // 004f4011  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4017  7c32                   -jl 0x4f404b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f404b;
    }
L_0x004f4019:
    // 004f4019  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f401e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4022  b8accd5400             -mov eax, 0x54cdac
    cpu.eax = 5557676 /*0x54cdac*/;
    // 004f4027  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4028  ba80020000             -mov edx, 0x280
    cpu.edx = 640 /*0x280*/;
    // 004f402d  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f4033  68c0cd5400             -push 0x54cdc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557696 /*0x54cdc0*/;
    cpu.esp -= 4;
    // 004f4038  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f403d  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f4043  e8c8cff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4048  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004f404b:
    // 004f404b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f404d  752d                   -jne 0x4f407c
    if (!cpu.flags.zf)
    {
        goto L_0x004f407c;
    }
    // 004f404f  bdb4cc5400             -mov ebp, 0x54ccb4
    cpu.ebp = 5557428 /*0x54ccb4*/;
    // 004f4054  b8accd5400             -mov eax, 0x54cdac
    cpu.eax = 5557676 /*0x54cdac*/;
    // 004f4059  ba85020000             -mov edx, 0x285
    cpu.edx = 645 /*0x285*/;
    // 004f405e  6810ce5400             -push 0x54ce10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557776 /*0x54ce10*/;
    cpu.esp -= 4;
    // 004f4063  892d90215500           -mov dword ptr [0x552190], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebp;
    // 004f4069  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 004f406e  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 004f4074  e897cff0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4079  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f407c:
    // 004f407c  8b0d4c259f00           -mov ecx, dword ptr [0x9f254c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */);
    // 004f4082  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4084  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4086  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4088  7416                   -je 0x4f40a0
    if (cpu.flags.zf)
    {
        goto L_0x004f40a0;
    }
L_0x004f408a:
    // 004f408a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f408d  42                     -inc edx
    (cpu.edx)++;
    // 004f408e  83f840                 +cmp eax, 0x40
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
    // 004f4091  0f8d02010000           -jge 0x4f4199
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4199;
    }
    // 004f4097  83b84c259f0000         +cmp dword ptr [eax + 0x9f254c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10429772) /* 0x9f254c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f409e  75ea                   -jne 0x4f408a
    if (!cpu.flags.zf)
    {
        goto L_0x004f408a;
    }
L_0x004f40a0:
    // 004f40a0  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f40a4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f40a8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f40af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f40b1  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004f40b3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f40b6  83ef4c                 -sub edi, 0x4c
    (cpu.edi) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f40b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f40bb  83c64c                 -add esi, 0x4c
    (cpu.esi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004f40be  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f40c1  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 004f40c4  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f40c6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f40c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f40ca  e841d10100             -call 0x511210
    cpu.esp -= 4;
    sub_511210(app, cpu);
    if (cpu.terminate) return;
    // 004f40cf  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004f40d2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f40d4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f40d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f40d8  b9603b4f00             -mov ecx, 0x4f3b60
    cpu.ecx = 5192544 /*0x4f3b60*/;
    // 004f40dd  e82ed10100             -call 0x511210
    cpu.esp -= 4;
    sub_511210(app, cpu);
    if (cpu.terminate) return;
    // 004f40e2  bb443b4f00             -mov ebx, 0x4f3b44
    cpu.ebx = 5192516 /*0x4f3b44*/;
    // 004f40e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f40e9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f40ec  e837d10100             -call 0x511228
    cpu.esp -= 4;
    sub_511228(app, cpu);
    if (cpu.terminate) return;
    // 004f40f1  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f40f4  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f40f8  0f8ca9000000           -jl 0x4f41a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f41a7;
    }
    // 004f40fe  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f4101  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4105  88908c259f00           -mov byte ptr [eax + 0x9f258c], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10429836) /* 0x9f258c */) = cpu.dl;
    // 004f410b  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 004f4110  0f84d0000000           -je 0x4f41e6
    if (cpu.flags.zf)
    {
        goto L_0x004f41e6;
    }
    // 004f4116  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f4118  0f8c95000000           -jl 0x4f41b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f41b3;
    }
L_0x004f411e:
    // 004f411e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f4122  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4125  c6451801               -mov byte ptr [ebp + 0x18], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 1 /*0x1*/;
L_0x004f4129:
    // 004f4129  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f4130  c74508ffffffff         -mov dword ptr [ebp + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f4137  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f413b  884515                 -mov byte ptr [ebp + 0x15], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 004f413e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4142  8d7d3c                 -lea edi, [ebp + 0x3c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(60) /* 0x3c */);
    // 004f4145  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4146  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4147  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4148  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4149  e882feffff             -call 0x4f3fd0
    cpu.esp -= 4;
    sub_4f3fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f414e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4150  751c                   -jne 0x4f416e
    if (!cpu.flags.zf)
    {
        goto L_0x004f416e;
    }
    // 004f4152  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f4157  b8bc3e4f00             -mov eax, 0x4f3ebc
    cpu.eax = 5193404 /*0x4f3ebc*/;
    // 004f415c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f415e  be903a4f00             -mov esi, 0x4f3a90
    cpu.esi = 5192336 /*0x4f3a90*/;
    // 004f4163  e8b833ffff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 004f4168  8935309ba000           -mov dword ptr [0xa09b30], esi
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.esi;
L_0x004f416e:
    // 004f416e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4172  892c854c259f00         -mov dword ptr [eax*4 + 0x9f254c], ebp
    app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.eax * 4) = cpu.ebp;
    // 004f4179  e8c2020000             -call 0x4f4440
    cpu.esp -= 4;
    sub_4f4440(app, cpu);
    if (cpu.terminate) return;
    // 004f417e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4182  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4185  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4186  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4187  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4188  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f418b:
    // 004f418b  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f4190  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4193  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4194  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4195  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4196  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f4199:
    // 004f4199  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 004f419e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f41a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41a4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f41a7:
    // 004f41a7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f41aa  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f41ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f41b0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f41b3:
    // 004f41b3  bab4cc5400             -mov edx, 0x54ccb4
    cpu.edx = 5557428 /*0x54ccb4*/;
    // 004f41b8  b9accd5400             -mov ecx, 0x54cdac
    cpu.ecx = 5557676 /*0x54cdac*/;
    // 004f41bd  bbb5020000             -mov ebx, 0x2b5
    cpu.ebx = 693 /*0x2b5*/;
    // 004f41c2  6834ce5400             -push 0x54ce34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557812 /*0x54ce34*/;
    cpu.esp -= 4;
    // 004f41c7  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f41cd  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f41d3  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f41d9  e832cef0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f41de  83c404                 +add esp, 4
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
    // 004f41e1  e938ffffff             -jmp 0x4f411e
    goto L_0x004f411e;
L_0x004f41e6:
    // 004f41e6  81ff00600000           +cmp edi, 0x6000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24576 /*0x6000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f41ec  7d2d                   -jge 0x4f421b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f421b;
    }
    // 004f41ee  b9b4cc5400             -mov ecx, 0x54ccb4
    cpu.ecx = 5557428 /*0x54ccb4*/;
    // 004f41f3  bbaccd5400             -mov ebx, 0x54cdac
    cpu.ebx = 5557676 /*0x54cdac*/;
    // 004f41f8  b8c2020000             -mov eax, 0x2c2
    cpu.eax = 706 /*0x2c2*/;
    // 004f41fd  6834ce5400             -push 0x54ce34
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557812 /*0x54ce34*/;
    cpu.esp -= 4;
    // 004f4202  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f4208  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004f420e  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f4213  e8f8cdf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4218  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004f421b:
    // 004f421b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f421f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004f4224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4225  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f4227  40                     -inc eax
    (cpu.eax)++;
    // 004f4228  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f422a  e851b8fdff             -call 0x4cfa80
    cpu.esp -= 4;
    sub_4cfa80(app, cpu);
    if (cpu.terminate) return;
    // 004f422f  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4232  c6451800               -mov byte ptr [ebp + 0x18], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004f4236  e8c5c2fdff             -call 0x4d0500
    cpu.esp -= 4;
    sub_4d0500(app, cpu);
    if (cpu.terminate) return;
    // 004f423b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f423d  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004f4242  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f4245  f7fb                   +idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f4247  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f424a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f424c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f424e  e84dda0100             -call 0x511ca0
    cpu.esp -= 4;
    sub_511ca0(app, cpu);
    if (cpu.terminate) return;
    // 004f4253  e9d1feffff             -jmp 0x4f4129
    goto L_0x004f4129;
}

/* align: skip  */
void Application::sub_4f4258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4258  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4259  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f425a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f425b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f425e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4262  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f4265  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004f4267  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f4269  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f426d  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4274  750e                   -jne 0x4f4284
    if (!cpu.flags.zf)
    {
        goto L_0x004f4284;
    }
    // 004f4276  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f427b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f427e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f427f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4280  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4281  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4284:
    // 004f4284  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4288  e817f8ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f428d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f428f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f4291  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4293  750e                   -jne 0x4f42a3
    if (!cpu.flags.zf)
    {
        goto L_0x004f42a3;
    }
    // 004f4295  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f429a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f429d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f429e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f429f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f42a0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f42a3:
    // 004f42a3  e878cb0000             -call 0x500e20
    cpu.esp -= 4;
    sub_500e20(app, cpu);
    if (cpu.terminate) return;
    // 004f42a8  8a4216                 -mov al, byte ptr [edx + 0x16]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 004f42ab  3a4215                 +cmp al, byte ptr [edx + 0x15]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f42ae  0f8dae000000           -jge 0x4f4362
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4362;
    }
    // 004f42b4  0fbe4216               -movsx eax, byte ptr [edx + 0x16]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */)));
    // 004f42b8  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004f42bf  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f42c1  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004f42c4  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004f42c6  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004f42cd  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004f42cf  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f42d1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f42d3  0f859c000000           -jne 0x4f4375
    if (!cpu.flags.zf)
    {
        goto L_0x004f4375;
    }
    // 004f42d9  b95343456c             -mov ecx, 0x6c454353
    cpu.ecx = 1816478547 /*0x6c454353*/;
    // 004f42de  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f42e1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f42e3  e808bcfdff             -call 0x4cfef0
    cpu.esp -= 4;
    sub_4cfef0(app, cpu);
    if (cpu.terminate) return;
L_0x004f42e8:
    // 004f42e8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004f42ea:
    // 004f42ea  833e00                 +cmp dword ptr [esi], 0
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
    // 004f42ed  0f84a4000000           -je 0x4f4397
    if (cpu.flags.zf)
    {
        goto L_0x004f4397;
    }
    // 004f42f3  81471000010000         -add dword ptr [edi + 0x10], 0x100
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004f42fa  837f1000               +cmp dword ptr [edi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f42fe  7d07                   -jge 0x4f4307
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4307;
    }
    // 004f4300  c7471000000000         -mov dword ptr [edi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004f4307:
    // 004f4307  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004f430a  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f430e  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f4310  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4313  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f4316  66894628               -mov word ptr [esi + 0x28], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 004f431a  8a4716                 -mov al, byte ptr [edi + 0x16]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 004f431d  fe4716                 -inc byte ptr [edi + 0x16]
    (app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */))++;
    // 004f4320  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004f4327  c74608ffffffff         -mov dword ptr [esi + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f432e  c7460cffffffff         -mov dword ptr [esi + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 004f4335  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f433c  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f4343  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f434a  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004f4351  e826cb0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f4356  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4359  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f435c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f435f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4362:
    // 004f4362  e815cb0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f4367  b8f3ffffff             -mov eax, 0xfffffff3
    cpu.eax = 4294967283 /*0xfffffff3*/;
    // 004f436c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f436f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4370  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4371  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4372  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f4375:
    // 004f4375  83f901                 +cmp ecx, 1
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
    // 004f4378  7407                   -je 0x4f4381
    if (cpu.flags.zf)
    {
        goto L_0x004f4381;
    }
    // 004f437a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004f437c  e969ffffff             -jmp 0x4f42ea
    goto L_0x004f42ea;
L_0x004f4381:
    // 004f4381  b95343456c             -mov ecx, 0x6c454353
    cpu.ecx = 1816478547 /*0x6c454353*/;
    // 004f4386  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f4389  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004f438b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f438d  e81ebcfdff             -call 0x4cffb0
    cpu.esp -= 4;
    sub_4cffb0(app, cpu);
    if (cpu.terminate) return;
    // 004f4392  e951ffffff             -jmp 0x4f42e8
    goto L_0x004f42e8;
L_0x004f4397:
    // 004f4397  e8e0ca0000             -call 0x500e7c
    cpu.esp -= 4;
    sub_500e7c(app, cpu);
    if (cpu.terminate) return;
    // 004f439c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f43a1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f43a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43a7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f43ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f43ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f43af  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f43b1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f43b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43b6  e831fcffff             -call 0x4f3fec
    cpu.esp -= 4;
    sub_4f3fec(app, cpu);
    if (cpu.terminate) return;
    // 004f43bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43bc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f43c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f43c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f43c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f43c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f43c4  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f43cb  7508                   -jne 0x4f43d5
    if (!cpu.flags.zf)
    {
        goto L_0x004f43d5;
    }
    // 004f43cd  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f43d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f43d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f43d5:
    // 004f43d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f43d7  e8c8f6ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f43dc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f43de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f43e0  744b                   -je 0x4f442d
    if (cpu.flags.zf)
    {
        goto L_0x004f442d;
    }
    // 004f43e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f43e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f43e5  e856000000             -call 0x4f4440
    cpu.esp -= 4;
    sub_4f4440(app, cpu);
    if (cpu.terminate) return;
    // 004f43ea  e8e1fbffff             -call 0x4f3fd0
    cpu.esp -= 4;
    sub_4f3fd0(app, cpu);
    if (cpu.terminate) return;
    // 004f43ef  83f801                 +cmp eax, 1
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
    // 004f43f2  7514                   -jne 0x4f4408
    if (!cpu.flags.zf)
    {
        goto L_0x004f4408;
    }
    // 004f43f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f43f5  b8bc3e4f00             -mov eax, 0x4f3ebc
    cpu.eax = 5193404 /*0x4f3ebc*/;
    // 004f43fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f43fc  e8df31ffff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
    // 004f4401  891d309ba000           -mov dword ptr [0xa09b30], ebx
    app->getMemory<x86::reg32>(x86::reg32(10525488) /* 0xa09b30 */) = cpu.ebx;
    // 004f4407  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f4408:
    // 004f4408  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f440b  e8c0d40100             -call 0x5118d0
    cpu.esp -= 4;
    sub_5118d0(app, cpu);
    if (cpu.terminate) return;
    // 004f4410  80791800               +cmp byte ptr [ecx + 0x18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4414  7508                   -jne 0x4f441e
    if (!cpu.flags.zf)
    {
        goto L_0x004f441e;
    }
    // 004f4416  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4419  e812b9fdff             -call 0x4cfd30
    cpu.esp -= 4;
    sub_4cfd30(app, cpu);
    if (cpu.terminate) return;
L_0x004f441e:
    // 004f441e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f4420  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4422  8934954c259f00         -mov dword ptr [edx*4 + 0x9f254c], esi
    app->getMemory<x86::reg32>(x86::reg32(10429772) /* 0x9f254c */ + cpu.edx * 4) = cpu.esi;
    // 004f4429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f442c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f442d:
    // 004f442d  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f4432  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4433  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f4438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4438  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f443a  e819feffff             -call 0x4f4258
    cpu.esp -= 4;
    sub_4f4258(app, cpu);
    if (cpu.terminate) return;
    // 004f443f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f4440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4440  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4441  803df49aa00000         +cmp byte ptr [0xa09af4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10525428) /* 0xa09af4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4448  7507                   -jne 0x4f4451
    if (!cpu.flags.zf)
    {
        goto L_0x004f4451;
    }
    // 004f444a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 004f444f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4450  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4451:
    // 004f4451  e84ef6ffff             -call 0x4f3aa4
    cpu.esp -= 4;
    sub_4f3aa4(app, cpu);
    if (cpu.terminate) return;
    // 004f4456  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f445a  7473                   -je 0x4f44cf
    if (cpu.flags.zf)
    {
        goto L_0x004f44cf;
    }
    // 004f445c  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4460  7c08                   -jl 0x4f446a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f446a;
    }
    // 004f4462  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f4465  e8b2d30100             -call 0x51181c
    cpu.esp -= 4;
    sub_51181c(app, cpu);
    if (cpu.terminate) return;
L_0x004f446a:
    // 004f446a  c74108ffffffff         -mov dword ptr [ecx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 004f4471  80791800               +cmp byte ptr [ecx + 0x18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4475  7508                   -jne 0x4f447f
    if (!cpu.flags.zf)
    {
        goto L_0x004f447f;
    }
    // 004f4477  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f447a  e8a1bdfdff             -call 0x4d0220
    cpu.esp -= 4;
    sub_4d0220(app, cpu);
    if (cpu.terminate) return;
L_0x004f447f:
    // 004f447f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4481  c6411600               -mov byte ptr [ecx + 0x16], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004f4485  c6411700               -mov byte ptr [ecx + 0x17], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */) = 0 /*0x0*/;
    // 004f4489  c6411400               -mov byte ptr [ecx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004f448d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f4492  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004f4495  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4497  e8a4c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f449c  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f44a1  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004f44a4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44a6  e895c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44ab  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004f44b0  8d4124                 -lea eax, [ecx + 0x24]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004f44b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44b5  e886c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44ba  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004f44bf  8d4130                 -lea eax, [ecx + 0x30]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004f44c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f44c4  e877c1feff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004f44c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f44cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f44cf:
    // 004f44cf  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004f44d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f44d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f44e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f44e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f44e1  39d0                   +cmp eax, edx
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
    // 004f44e3  7526                   -jne 0x4f450b
    if (!cpu.flags.zf)
    {
        goto L_0x004f450b;
    }
    // 004f44e5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f44e8  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004f44eb  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f44ee  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f44f1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f44f4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f44f7  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004f44fa  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f44fd  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f4500  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f4503  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f4506  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004f4509  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f450a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f450b:
    // 004f450b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004f450d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004f450f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f4512  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004f4515  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004f4518  894a08                 -mov dword ptr [edx + 8], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f451b  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f451e  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f4521  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f4524  894a10                 -mov dword ptr [edx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004f4527  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004f452a  894a14                 -mov dword ptr [edx + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004f452d  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4530  894a18                 -mov dword ptr [edx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004f4533  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004f4536  894a1c                 -mov dword ptr [edx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004f4539  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f453c  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f453f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f4544(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4544  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4546  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4547  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4548  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f454a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f454c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f454e  f72f                   -imul dword ptr [edi]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 004f4550  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4552  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4555  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f4557  f76f0c                 -imul dword ptr [edi + 0xc]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004f455a  01c5                   +add ebp, eax
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
    // 004f455c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f455f  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f4561  f76f18                 -imul dword ptr [edi + 0x18]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */))));
    // 004f4564  01e8                   +add eax, ebp
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
    // 004f4566  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f4568  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f456c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f456e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f4570  f76f04                 -imul dword ptr [edi + 4]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004f4573  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4575  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4578  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f457a  f76f10                 -imul dword ptr [edi + 0x10]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */))));
    // 004f457d  01c5                   +add ebp, eax
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
    // 004f457f  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4582  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f4584  f76f1c                 -imul dword ptr [edi + 0x1c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))));
    // 004f4587  01e8                   +add eax, ebp
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
    // 004f4589  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f458b  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f458f  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4592  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004f4594  f76f08                 -imul dword ptr [edi + 8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004f4597  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4599  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f459c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f459e  f76f14                 -imul dword ptr [edi + 0x14]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */))));
    // 004f45a1  01c5                   +add ebp, eax
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
    // 004f45a3  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f45a6  11d1                   -adc ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004f45a8  f76f20                 -imul dword ptr [edi + 0x20]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */))));
    // 004f45ab  01e8                   +add eax, ebp
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
    // 004f45ad  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004f45af  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004f45b3  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f45b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f45c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f45c1  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f45c9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f45cb  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 004f45cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4f45d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f45d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45d1  87442404               -xchg dword ptr [esp + 4], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004f45d5  e807000000             -call 0x4f45e1
    cpu.esp -= 4;
    sub_4f45e1(app, cpu);
    if (cpu.terminate) return;
    // 004f45da  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f45de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f45e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f45e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45e2  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45e4  731a                   -jae 0x4f4600
    if (!cpu.flags.cf)
    {
        goto L_0x004f4600;
    }
    // 004f45e6  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004f45e8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f45ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f45eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45ec  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f45f4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f5  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f8  7606                   -jbe 0x4f4600
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f4600;
    }
    // 004f45fa  e811000000             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f45ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4600:
    // 004f4600  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4601  b8cc625600             -mov eax, 0x5662cc
    cpu.eax = 5661388 /*0x5662cc*/;
    // 004f4606  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f460b  e8fcd60100             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 004f4610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4611  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4612  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4616  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004f461b:
    // 004f461b  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004f461e  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004f4624  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4629  7ff0                   -jg 0x4f461b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f461b;
    }
    // 004f462b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f4610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004f4610;
    // 004f45e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45e2  39e0                   +cmp eax, esp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45e4  731a                   -jae 0x4f4600
    if (!cpu.flags.cf)
    {
        goto L_0x004f4600;
    }
    // 004f45e6  29e0                   -sub eax, esp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esp));
    // 004f45e8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004f45ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f45eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f45ec  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f45f2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f45f4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f5  3b06                   +cmp eax, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f45f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f45f8  7606                   -jbe 0x4f4600
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f4600;
    }
    // 004f45fa  e811000000             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f45ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4600:
    // 004f4600  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4601  b8cc625600             -mov eax, 0x5662cc
    cpu.eax = 5661388 /*0x5662cc*/;
    // 004f4606  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f460b  e8fcd60100             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004f4610:
    // 004f4610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4611  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4612  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4616  bbfcffffff             -mov ebx, 0xfffffffc
    cpu.ebx = 4294967292 /*0xfffffffc*/;
L_0x004f461b:
    // 004f461b  891c1c                 -mov dword ptr [esp + ebx], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 1) = cpu.ebx;
    // 004f461e  81eb00100000           -sub ebx, 0x1000
    (cpu.ebx) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004f4624  2d00100000             +sub eax, 0x1000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f4629  7ff0                   -jg 0x4f461b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f461b;
    }
    // 004f462b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f462d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4f4630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4630  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4631  e8daffffff             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 004f4636  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4637  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f463b  2b0424                 +sub eax, dword ptr [esp]
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
    // 004f463e  94                     -xchg esp, eax
    {
        x86::reg32 tmp = cpu.esp;
        cpu.esp = cpu.eax;
        cpu.eax = tmp;
    }
    // 004f463f  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4642  ffe0                   -jmp eax
    return app->dynamic_call(cpu.eax, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4653  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4655  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f4657  8b15e0625600           -mov edx, dword ptr [0x5662e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */);
    // 004f465d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f4664  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4666  bf24f57900             -mov edi, 0x79f524
    cpu.edi = 7992612 /*0x79f524*/;
    // 004f466b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f466e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f4670  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004f4671:
    // 004f4671  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004f4673  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004f4675  3c00                   +cmp al, 0
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
    // 004f4677  7410                   -je 0x4f4689
    if (cpu.flags.zf)
    {
        goto L_0x004f4689;
    }
    // 004f4679  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004f467c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f467f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004f4682  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f4685  3c00                   +cmp al, 0
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
    // 004f4687  75e8                   -jne 0x4f4671
    if (!cpu.flags.zf)
    {
        goto L_0x004f4671;
    }
L_0x004f4689:
    // 004f4689  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f468a  8b15e0625600           -mov edx, dword ptr [0x5662e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */);
    // 004f4690  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004f4697  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4699  42                     -inc edx
    (cpu.edx)++;
    // 004f469a  890c852cf57900         -mov dword ptr [eax*4 + 0x79f52c], ecx
    app->getMemory<x86::reg32>(x86::reg32(7992620) /* 0x79f52c */ + cpu.eax * 4) = cpu.ecx;
    // 004f46a1  8915e0625600           -mov dword ptr [0x5662e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5661408) /* 0x5662e0 */) = cpu.edx;
    // 004f46a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f46b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f46b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f46b1  a158e55500             -mov eax, dword ptr [0x55e558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629272) /* 0x55e558 */);
    // 004f46b6  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004f46bd  a1c4f57900             -mov eax, dword ptr [0x79f5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7992772) /* 0x79f5c4 */);
    // 004f46c2  8b0402                 -mov eax, dword ptr [edx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 004f46c5  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f46c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f46d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f46d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f46d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f46d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f46d3  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f46d8  bef44f5600             -mov esi, 0x564ff4
    cpu.esi = 5656564 /*0x564ff4*/;
    // 004f46dd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f46df  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f46e1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f46e6  be2c505600             -mov esi, 0x56502c
    cpu.esi = 5656620 /*0x56502c*/;
    // 004f46eb  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004f46ee  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f46f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f46f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f4700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4701  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4702  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4703  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4704  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4706  8b150c445600           -mov edx, dword ptr [0x56440c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004f470c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f470e  bf2c505600             -mov edi, 0x56502c
    cpu.edi = 5656620 /*0x56502c*/;
    // 004f4713  890d0c445600           -mov dword ptr [0x56440c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004f4719  e88266ffff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 004f471e  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004f4723  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004f4726  89150c445600           -mov dword ptr [0x56440c], edx
    app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.edx;
    // 004f472c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f472e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f472f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4730  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4741  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4742  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4743  b92e000000             -mov ecx, 0x2e
    cpu.ecx = 46 /*0x2e*/;
    // 004f4748  bef4715600             -mov esi, 0x5671f4
    cpu.esi = 5665268 /*0x5671f4*/;
    // 004f474d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f474f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4751  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4752  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4754  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f4760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4763  b92e000000             -mov ecx, 0x2e
    cpu.ecx = 46 /*0x2e*/;
    // 004f4768  bff4715600             -mov edi, 0x5671f4
    cpu.edi = 5665268 /*0x5671f4*/;
    // 004f476d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f476f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f4771  e80a7a0100             -call 0x50c180
    cpu.esp -= 4;
    sub_50c180(app, cpu);
    if (cpu.terminate) return;
    // 004f4776  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4778  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4779  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4782  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4784  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004f4787  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 004f478c  39f0                   +cmp eax, esi
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
    // 004f478e  7324                   -jae 0x4f47b4
    if (!cpu.flags.cf)
    {
        goto L_0x004f47b4;
    }
    // 004f4790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x004f4791:
    // 004f4791  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4793  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4795  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004f4797  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004f4799  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f479b  668b0c4d546b5600       -mov cx, word ptr [ecx*2 + 0x566b54]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5663572) /* 0x566b54 */ + cpu.ecx * 2);
    // 004f47a3  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f47a9  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004f47ac  40                     -inc eax
    (cpu.eax)++;
    // 004f47ad  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f47af  39f0                   +cmp eax, esi
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
    // 004f47b1  72de                   -jb 0x4f4791
    if (cpu.flags.cf)
    {
        goto L_0x004f4791;
    }
    // 004f47b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f47b4:
    // 004f47b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f47b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f47c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f47c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f47c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f47c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f47c3  8a5803                 -mov bl, byte ptr [eax + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004f47c6  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004f47cb  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004f47ce  7405                   -je 0x4f47d5
    if (cpu.flags.zf)
    {
        goto L_0x004f47d5;
    }
    // 004f47d0  f6c3c0                 +test bl, 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 192 /*0xc0*/));
    // 004f47d3  7406                   -je 0x4f47db
    if (cpu.flags.zf)
    {
        goto L_0x004f47db;
    }
L_0x004f47d5:
    // 004f47d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f47d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f47da  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f47db:
    // 004f47db  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f47de  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f47e1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004f47e3  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f47e8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f47ed  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f47ef  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f47f1  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f47f3  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f47fa  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f47fc  3d444e4542             +cmp eax, 0x42454e44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1111838276 /*0x42454e44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4801  74d2                   -je 0x4f47d5
    if (cpu.flags.zf)
    {
        goto L_0x004f47d5;
    }
    // 004f4803  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4805  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4807  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4808  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4809  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f480a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f4810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4812  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4813  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4814  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4815  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4816  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f4819  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004f481c  8b3c85c0f59e00         -mov edi, dword ptr [eax*4 + 0x9ef5c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 004f4823  8b5738                 -mov edx, dword ptr [edi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004f4826  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4828  7537                   -jne 0x4f4861
    if (!cpu.flags.zf)
    {
        goto L_0x004f4861;
    }
L_0x004f482a:
    // 004f482a  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x004f482d:
    // 004f482d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f482f  e88cffffff             -call 0x4f47c0
    cpu.esp -= 4;
    sub_4f47c0(app, cpu);
    if (cpu.terminate) return;
    // 004f4834  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4838  7530                   -jne 0x4f486a
    if (!cpu.flags.zf)
    {
        goto L_0x004f486a;
    }
L_0x004f483a:
    // 004f483a  8b6f38                 -mov ebp, dword ptr [edi + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    // 004f483d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f483f  7407                   -je 0x4f4848
    if (cpu.flags.zf)
    {
        goto L_0x004f4848;
    }
    // 004f4841  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4842  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f4848:
    // 004f4848  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f484a  7509                   -jne 0x4f4855
    if (!cpu.flags.zf)
    {
        goto L_0x004f4855;
    }
    // 004f484c  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4853  751e                   -jne 0x4f4873
    if (!cpu.flags.zf)
    {
        goto L_0x004f4873;
    }
L_0x004f4855:
    // 004f4855  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4857  83c408                 +add esp, 8
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
    // 004f485a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f485f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4860  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4861:
    // 004f4861  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4862  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4868  ebc0                   -jmp 0x4f482a
    goto L_0x004f482a;
L_0x004f486a:
    // 004f486a  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004f486d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f486f  75bc                   -jne 0x4f482d
    if (!cpu.flags.zf)
    {
        goto L_0x004f482d;
    }
    // 004f4871  ebc7                   -jmp 0x4f483a
    goto L_0x004f483a;
L_0x004f4873:
    // 004f4873  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f4875  88642404               -mov byte ptr [esp + 4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 004f4879  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004f487c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f487f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f4884  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f4886  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f4888  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f488a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f488c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f4893  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f4895  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f4897  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f489a  c7059821550051000000   -mov dword ptr [0x552198], 0x51
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 81 /*0x51*/;
    // 004f48a4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f48a6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48a7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f48aa  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004f48ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48ad  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f48b0  bd88ce5400             -mov ebp, 0x54ce88
    cpu.ebp = 5557896 /*0x54ce88*/;
    // 004f48b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f48b6  b978ce5400             -mov ecx, 0x54ce78
    cpu.ecx = 5557880 /*0x54ce78*/;
    // 004f48bb  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f48c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f48c2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f48c4  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004f48ca  e811cdfeff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 004f48cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f48d0  689cce5400             -push 0x54ce9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5557916 /*0x54ce9c*/;
    cpu.esp -= 4;
    // 004f48d5  e836c7f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f48da  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004f48dd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f48df  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f48e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f48e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f48f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f48f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f48f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f48f2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f48f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f48f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f48fb:
    // 004f48fb  83b9c0f59e0000         +cmp dword ptr [ecx + 0x9ef5c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10417600) /* 0x9ef5c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4902  7510                   -jne 0x4f4914
    if (!cpu.flags.zf)
    {
        goto L_0x004f4914;
    }
L_0x004f4904:
    // 004f4904  42                     -inc edx
    (cpu.edx)++;
    // 004f4905  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4908  83fa10                 +cmp edx, 0x10
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
    // 004f490b  7d04                   -jge 0x4f4911
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4911;
    }
    // 004f490d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f490f  75ea                   -jne 0x4f48fb
    if (!cpu.flags.zf)
    {
        goto L_0x004f48fb;
    }
L_0x004f4911:
    // 004f4911  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4913  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4914:
    // 004f4914  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4916  e8f5feffff             -call 0x4f4810
    cpu.esp -= 4;
    sub_4f4810(app, cpu);
    if (cpu.terminate) return;
    // 004f491b  ebe7                   -jmp 0x4f4904
    goto L_0x004f4904;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4f4920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4920  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4922  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4923  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f4927  39ca                   +cmp edx, ecx
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
    // 004f4929  0f8c6e000000           -jl 0x4f499d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f499d;
    }
    // 004f492f  39fa                   +cmp edx, edi
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
    // 004f4931  7f6a                   -jg 0x4f499d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f499d;
    }
    // 004f4933  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004f4938:
    // 004f4938  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004f493a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f493c  7557                   -jne 0x4f4995
    if (!cpu.flags.zf)
    {
        goto L_0x004f4995;
    }
    // 004f493e  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4945  744e                   -je 0x4f4995
    if (cpu.flags.zf)
    {
        goto L_0x004f4995;
    }
    // 004f4947  39f9                   +cmp ecx, edi
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
    // 004f4949  0f8598000000           -jne 0x4f49e7
    if (!cpu.flags.zf)
    {
        goto L_0x004f49e7;
    }
    // 004f494f  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f4954  744b                   -je 0x4f49a1
    if (cpu.flags.zf)
    {
        goto L_0x004f49a1;
    }
    // 004f4956  bf04cf5400             -mov edi, 0x54cf04
    cpu.edi = 5558020 /*0x54cf04*/;
    // 004f495b  be14cf5400             -mov esi, 0x54cf14
    cpu.esi = 5558036 /*0x54cf14*/;
    // 004f4960  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4961  893594215500           -mov dword ptr [0x552194], esi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.esi;
    // 004f4967  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f496b  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f4971  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4972  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4975  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 004f497a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f497b  893d98215500           -mov dword ptr [0x552198], edi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004f4981  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4984  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4985  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4987  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4988  6828cf5400             -push 0x54cf28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558056 /*0x54cf28*/;
    cpu.esp -= 4;
    // 004f498d  e87ec6f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4992  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004f4995:
    // 004f4995  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4997  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4998  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4999  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f499a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f499d:
    // 004f499d  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f499f  eb97                   -jmp 0x4f4938
    goto L_0x004f4938;
L_0x004f49a1:
    // 004f49a1  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f49ab  be16000000             -mov esi, 0x16
    cpu.esi = 22 /*0x16*/;
    // 004f49b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f49b1  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f49b7  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f49bb  bf14cf5400             -mov edi, 0x54cf14
    cpu.edi = 5558036 /*0x54cf14*/;
    // 004f49c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f49c1  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004f49c7  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f49ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f49cb  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f49ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f49cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f49d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f49d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f49d2  687ccf5400             -push 0x54cf7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558140 /*0x54cf7c*/;
    cpu.esp -= 4;
    // 004f49d7  e834c6f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f49dc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f49df  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f49e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f49e4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f49e7:
    // 004f49e7  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004f49ec  7446                   -je 0x4f4a34
    if (cpu.flags.zf)
    {
        goto L_0x004f4a34;
    }
    // 004f49ee  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f49f8  c7059421550014cf5400   -mov dword ptr [0x552194], 0x54cf14
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5558036 /*0x54cf14*/;
    // 004f4a02  be1b000000             -mov esi, 0x1b
    cpu.esi = 27 /*0x1b*/;
    // 004f4a07  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4a08  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f4a0e  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f4a12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a13  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4a16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a17  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4a1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a1d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a1e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a1f  68d0cf5400             -push 0x54cfd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558224 /*0x54cfd0*/;
    cpu.esp -= 4;
    // 004f4a24  e8e7c5f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4a29  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f4a2c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4a2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a31  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004f4a34:
    // 004f4a34  c7059021550004cf5400   -mov dword ptr [0x552190], 0x54cf04
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = 5558020 /*0x54cf04*/;
    // 004f4a3e  c7059421550014cf5400   -mov dword ptr [0x552194], 0x54cf14
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = 5558036 /*0x54cf14*/;
    // 004f4a48  be1d000000             -mov esi, 0x1d
    cpu.esi = 29 /*0x1d*/;
    // 004f4a4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4a4e  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004f4a54  0fb6701c               -movzx esi, byte ptr [eax + 0x1c]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */));
    // 004f4a58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a59  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4a5c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a5d  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f4a60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a62  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a63  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a65  6828d05400             -push 0x54d028
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558312 /*0x54d028*/;
    cpu.esp -= 4;
    // 004f4a6a  e8a1c5f0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f4a6f  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f4a72  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f4a74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4a77  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f4a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4a82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4a83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4a84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4a85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4a87  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f4a89  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 004f4a8e  68444e4957             -push 0x57494e44
    app->getMemory<x86::reg32>(cpu.esp-4) = 1464421956 /*0x57494e44*/;
    cpu.esp -= 4;
    // 004f4a93  bb80d05400             -mov ebx, 0x54d080
    cpu.ebx = 5558400 /*0x54d080*/;
    // 004f4a98  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004f4a9a  e881feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4a9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4aa1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4aa6  bb84d05400             -mov ebx, 0x54d084
    cpu.ebx = 5558404 /*0x54d084*/;
    // 004f4aab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f4aad  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4ab2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4ab5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ab7  e864feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4abc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4abe  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4ac3  bb8cd05400             -mov ebx, 0x54d08c
    cpu.ebx = 5558412 /*0x54d08c*/;
    // 004f4ac8  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4acb  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4ad0  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4ad2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ad4  e847feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4ad9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4adb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f4ae0  bb94d05400             -mov ebx, 0x54d094
    cpu.ebx = 5558420 /*0x54d094*/;
    // 004f4ae5  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4ae7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4ae9  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f4aeb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4aed  8a561c                 -mov dl, byte ptr [esi + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f4af0  e82bfeffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4af5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f4af7  bb98d05400             -mov ebx, 0x54d098
    cpu.ebx = 5558424 /*0x54d098*/;
    // 004f4afc  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4afe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4b00  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b02  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 004f4b04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b06  8a561d                 -mov dl, byte ptr [esi + 0x1d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */);
    // 004f4b09  e812feffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b0e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b10  bba0d05400             -mov ebx, 0x54d0a0
    cpu.ebx = 5558432 /*0x54d0a0*/;
    // 004f4b15  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f4b18  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b1a  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b1f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b23  e8f8fdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b28  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b2c  bba8d05400             -mov ebx, 0x54d0a8
    cpu.ebx = 5558440 /*0x54d0a8*/;
    // 004f4b31  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b33  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b38  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004f4b3b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b3d  e8defdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b42  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b44  bbb0d05400             -mov ebx, 0x54d0b0
    cpu.ebx = 5558448 /*0x54d0b0*/;
    // 004f4b49  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004f4b4c  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b4e  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b53  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b57  e8c4fdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b5c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4b5e  bbb8d05400             -mov ebx, 0x54d0b8
    cpu.ebx = 5558456 /*0x54d0b8*/;
    // 004f4b63  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004f4b66  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4b68  6800400000             -push 0x4000
    app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004f4b6d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4b6f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4b71  e8aafdffff             -call 0x4f4920
    cpu.esp -= 4;
    sub_4f4920(app, cpu);
    if (cpu.terminate) return;
    // 004f4b76  21f8                   -and eax, edi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edi));
    // 004f4b78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f4b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4b81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4b82  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4b85  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f4b89  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f4b8b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f4b8f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f4b92  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f4b96  e879a40000             -call 0x4ff014
    cpu.esp -= 4;
    sub_4ff014(app, cpu);
    if (cpu.terminate) return;
    // 004f4b9b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4b9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4b9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ba0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f4bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4bb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4bb3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4bb4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4bb6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f4bb8  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f4bba  3b10                   +cmp edx, dword ptr [eax]
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
    // 004f4bbc  7534                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bbe  668b5704               -mov dx, word ptr [edi + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004f4bc2  663b5604               +cmp dx, word ptr [esi + 4]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f4bc6  752a                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bc8  668b5f06               -mov bx, word ptr [edi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004f4bcc  663b5e06               +cmp bx, word ptr [esi + 6]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f4bd0  7520                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
    // 004f4bd2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f4bd4  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f4bd7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4bd9  8a7f08                 -mov bh, byte ptr [edi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f4bdc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4bde  38fb                   +cmp bl, bh
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
    // 004f4be0  7510                   -jne 0x4f4bf2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4bf2;
    }
L_0x004f4be2:
    // 004f4be2  40                     -inc eax
    (cpu.eax)++;
    // 004f4be3  42                     -inc edx
    (cpu.edx)++;
    // 004f4be4  41                     -inc ecx
    (cpu.ecx)++;
    // 004f4be5  83fa08                 +cmp edx, 8
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
    // 004f4be8  7d0f                   -jge 0x4f4bf9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4bf9;
    }
    // 004f4bea  8a5808                 -mov bl, byte ptr [eax + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f4bed  3a5908                 +cmp bl, byte ptr [ecx + 8]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f4bf0  74f0                   -je 0x4f4be2
    if (cpu.flags.zf)
    {
        goto L_0x004f4be2;
    }
L_0x004f4bf2:
    // 004f4bf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f4bf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4bf9:
    // 004f4bf9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f4bfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4bff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4c11  833de86d560000         +cmp dword ptr [0x566de8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4c18  742b                   -je 0x4f4c45
    if (cpu.flags.zf)
    {
        goto L_0x004f4c45;
    }
L_0x004f4c1a:
    // 004f4c1a  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4c1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4c21  e84a980100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f4c26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4c28  7407                   -je 0x4f4c31
    if (cpu.flags.zf)
    {
        goto L_0x004f4c31;
    }
    // 004f4c2a  e831020000             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
    // 004f4c2f  ebe9                   -jmp 0x4f4c1a
    goto L_0x004f4c1a;
L_0x004f4c31:
    // 004f4c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4c32  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4c37  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c39  e8a2910100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f4c3e  890de86d5600           -mov dword ptr [0x566de8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */) = cpu.ecx;
    // 004f4c44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f4c45:
    // 004f4c45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f4c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c50  833de06d560001         +cmp dword ptr [0x566de0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4c57  7d01                   -jge 0x4f4c5a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f4c5a;
    }
    // 004f4c59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4c5a:
    // 004f4c5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4c5b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4c5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4c5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4c5f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c61  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f4c63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4c65  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f4c67  e814d50100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f4c6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4c6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f4c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4c70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4c71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4c72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4c73  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4c76  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f4c7a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f4c7d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004f4c81  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004f4c83  b8c0d05400             -mov eax, 0x54d0c0
    cpu.eax = 5558464 /*0x54d0c0*/;
    // 004f4c88  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f4c8d  e8beffffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4c92  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4c94  8b1de46d5600           -mov ebx, dword ptr [0x566de4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4c9a  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004f4c9e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f4ca0  7e46                   -jle 0x4f4ce8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4ce8;
    }
    // 004f4ca2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f4ca4:
    // 004f4ca4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4ca6  7440                   -je 0x4f4ce8
    if (cpu.flags.zf)
    {
        goto L_0x004f4ce8;
    }
    // 004f4ca8  8b86b0259f00           -mov eax, dword ptr [esi + 0x9f25b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10429872) /* 0x9f25b0 */);
    // 004f4cae  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004f4cb2  753d                   -jne 0x4f4cf1
    if (!cpu.flags.zf)
    {
        goto L_0x004f4cf1;
    }
    // 004f4cb4  83ff20                 +cmp edi, 0x20
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
    // 004f4cb7  7719                   -ja 0x4f4cd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004f4cd2;
    }
    // 004f4cb9  8b86d0259f00           -mov eax, dword ptr [esi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4cbf  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4cc2  bbfa000000             -mov ebx, 0xfa
    cpu.ebx = 250 /*0xfa*/;
    // 004f4cc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4cc9  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004f4ccc  ff542408               -call dword ptr [esp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f4cd0:
    // 004f4cd0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004f4cd2:
    // 004f4cd2  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4cd6  8b0de46d5600           -mov ecx, dword ptr [0x566de4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4cdc  45                     -inc ebp
    (cpu.ebp)++;
    // 004f4cdd  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4ce0  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004f4ce4  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4ce6  7cbc                   -jl 0x4f4ca4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f4ca4;
    }
L_0x004f4ce8:
    // 004f4ce8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4cea  83c410                 +add esp, 0x10
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
    // 004f4ced  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4cf0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4cf1:
    // 004f4cf1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4cf5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f4cf8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f4cfa  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004f4cfc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4d00  ff5504                 -call dword ptr [ebp + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4d03  ebcb                   -jmp 0x4f4cd0
    goto L_0x004f4cd0;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f4d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4d10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4d11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f4d13  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4d16  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4d18  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f4d1c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f4d1f  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004f4d23  b8d0d05400             -mov eax, 0x54d0d0
    cpu.eax = 5558480 /*0x54d0d0*/;
    // 004f4d28  e823ffffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4d2d  8b15e86d5600           -mov edx, dword ptr [0x566de8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */);
    // 004f4d33  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f4d35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f4d37  0f84a4000000           -je 0x4f4de1
    if (cpu.flags.zf)
    {
        goto L_0x004f4de1;
    }
L_0x004f4d3d:
    // 004f4d3d  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4d42  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f4d44  e8d7940100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4d49  83f8ff                 +cmp eax, -1
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
    // 004f4d4c  7407                   -je 0x4f4d55
    if (cpu.flags.zf)
    {
        goto L_0x004f4d55;
    }
    // 004f4d4e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4d50  e80b010000             -call 0x4f4e60
    cpu.esp -= 4;
    sub_4f4e60(app, cpu);
    if (cpu.terminate) return;
L_0x004f4d55:
    // 004f4d55  baac000000             -mov edx, 0xac
    cpu.edx = 172 /*0xac*/;
    // 004f4d5a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4d5c  e8abb9feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f4d61  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f4d63  a1e46d5600             -mov eax, dword ptr [0x566de4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4d68  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004f4d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4d6e  7e62                   -jle 0x4f4dd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f4dd2;
    }
    // 004f4d70  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004f4d72:
    // 004f4d72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4d74  755c                   -jne 0x4f4dd2
    if (!cpu.flags.zf)
    {
        goto L_0x004f4dd2;
    }
    // 004f4d76  8b87d0259f00           -mov eax, dword ptr [edi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4d7c  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f4d7f  8b87b0259f00           -mov eax, dword ptr [edi + 0x9f25b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429872) /* 0x9f25b0 */);
    // 004f4d85  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f4d88  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f4d8c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f4d8f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4d92  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004f4d96  0f848d000000           -je 0x4f4e29
    if (cpu.flags.zf)
    {
        goto L_0x004f4e29;
    }
L_0x004f4d9c:
    // 004f4d9c  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004f4da0  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f4da4  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f4da8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f4da9  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4dad  8b6e04                 -mov ebp, dword ptr [esi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4db0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4db1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4db3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4db7  ff5508                 -call dword ptr [ebp + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4dba  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004f4dbc:
    // 004f4dbc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f4dc0  8b1de46d5600           -mov ebx, dword ptr [0x566de4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664228) /* 0x566de4 */);
    // 004f4dc6  42                     -inc edx
    (cpu.edx)++;
    // 004f4dc7  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4dca  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004f4dce  39da                   +cmp edx, ebx
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
    // 004f4dd0  7ca0                   -jl 0x4f4d72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f4d72;
    }
L_0x004f4dd2:
    // 004f4dd2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f4dd4  7572                   -jne 0x4f4e48
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e48;
    }
    // 004f4dd6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4dd8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4ddb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ddc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4dde  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004f4de1:
    // 004f4de1  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4de6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4de8  e8e38e0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f4ded  b8104c4f00             -mov eax, 0x4f4c10
    cpu.eax = 5196816 /*0x4f4c10*/;
    // 004f4df2  e881dcffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f4df7  833ddc6d560000         +cmp dword ptr [0x566ddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664220) /* 0x566ddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f4dfe  751a                   -jne 0x4f4e1a
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e1a;
    }
    // 004f4e00  8b15d8435600           -mov edx, dword ptr [0x5643d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653464) /* 0x5643d8 */);
    // 004f4e06  83c209                 -add edx, 9
    (cpu.edx) += x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004f4e09  bf0a000000             -mov edi, 0xa
    cpu.edi = 10 /*0xa*/;
    // 004f4e0e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4e10  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004f4e13  f7ff                   +idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004f4e15  a3dc6d5600             -mov dword ptr [0x566ddc], eax
    app->getMemory<x86::reg32>(x86::reg32(5664220) /* 0x566ddc */) = cpu.eax;
L_0x004f4e1a:
    // 004f4e1a  c705e86d560001000000   -mov dword ptr [0x566de8], 1
    app->getMemory<x86::reg32>(x86::reg32(5664232) /* 0x566de8 */) = 1 /*0x1*/;
    // 004f4e24  e914ffffff             -jmp 0x4f4d3d
    goto L_0x004f4d3d;
L_0x004f4e29:
    // 004f4e29  8b87d0259f00           -mov eax, dword ptr [edi + 0x9f25d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10429904) /* 0x9f25d0 */);
    // 004f4e2f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f4e33  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f4e36  e875fdffff             -call 0x4f4bb0
    cpu.esp -= 4;
    sub_4f4bb0(app, cpu);
    if (cpu.terminate) return;
    // 004f4e3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f4e3d  0f8559ffffff           -jne 0x4f4d9c
    if (!cpu.flags.zf)
    {
        goto L_0x004f4d9c;
    }
    // 004f4e43  e974ffffff             -jmp 0x4f4dbc
    goto L_0x004f4dbc;
L_0x004f4e48:
    // 004f4e48  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e4d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f4e4f  e8fc8f0100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f4e54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4e56  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f4e59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e5c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f4e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4e63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4e65  b8e0d05400             -mov eax, 0x54d0e0
    cpu.eax = 5558496 /*0x54d0e0*/;
    // 004f4e6a  e8e1fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4e6f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4e71  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e76  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f4e78  e8a3930100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4e7d  83f8ff                 +cmp eax, -1
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
    // 004f4e80  7506                   -jne 0x4f4e88
    if (!cpu.flags.zf)
    {
        goto L_0x004f4e88;
    }
    // 004f4e82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f4e84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4e87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4e88:
    // 004f4e88  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4e8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4e8d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4e8f  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4e92  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f4e94  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4e99  e8b2920100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f4e9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f4ea0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ea3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f4eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4eb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4eb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4eb2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4eb4  b8f0d05400             -mov eax, 0x54d0f0
    cpu.eax = 5558512 /*0x54d0f0*/;
    // 004f4eb9  e892fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ebe  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4ec1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4ec3  ff5710                 -call dword ptr [edi + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4ec6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ec7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ec8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ed1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4ed2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ed4  b800d15400             -mov eax, 0x54d100
    cpu.eax = 5558528 /*0x54d100*/;
    // 004f4ed9  e872fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ede  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4ee1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4ee3  ff5614                 -call dword ptr [esi + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4ee6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ee7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4ee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ef0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ef1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4ef2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ef4  b80cd15400             -mov eax, 0x54d10c
    cpu.eax = 5558540 /*0x54d10c*/;
    // 004f4ef9  e852fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4efe  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f01  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f03  ff5618                 -call dword ptr [esi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4f11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f4f12  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f4f14  b81cd15400             -mov eax, 0x54d11c
    cpu.eax = 5558556 /*0x54d11c*/;
    // 004f4f19  e832fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f1e  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f4f21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f4f23  ff571c                 -call dword ptr [edi + 0x1c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f27  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f34  b828d15400             -mov eax, 0x54d128
    cpu.eax = 5558568 /*0x54d128*/;
    // 004f4f39  e812fdffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f3e  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f43  ff5320                 -call dword ptr [ebx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f54  b838d15400             -mov eax, 0x54d138
    cpu.eax = 5558584 /*0x54d138*/;
    // 004f4f59  e8f2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f5e  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4f61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4f63  ff5324                 -call dword ptr [ebx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4f72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f4f74  b848d15400             -mov eax, 0x54d148
    cpu.eax = 5558600 /*0x54d148*/;
    // 004f4f79  e8d2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f7e  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f4f81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f4f83  ff5128                 -call dword ptr [ecx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4f86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4f88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4f90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4f91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f4f92  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4f94  b858d15400             -mov eax, 0x54d158
    cpu.eax = 5558616 /*0x54d158*/;
    // 004f4f99  e8b2fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4f9e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f4fa0  b8f0259f00             -mov eax, 0x9f25f0
    cpu.eax = 10429936 /*0x9f25f0*/;
    // 004f4fa5  e876920100             -call 0x50e220
    cpu.esp -= 4;
    sub_50e220(app, cpu);
    if (cpu.terminate) return;
    // 004f4faa  83f8ff                 +cmp eax, -1
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
    // 004f4fad  7508                   -jne 0x4f4fb7
    if (!cpu.flags.zf)
    {
        goto L_0x004f4fb7;
    }
    // 004f4faf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f4fb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f4fb7:
    // 004f4fb7  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4fba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4fbc  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4fbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f4fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4fd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f4fd2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4fd4  b864d15400             -mov eax, 0x54d164
    cpu.eax = 5558628 /*0x54d164*/;
    // 004f4fd9  e872fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4fde  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f4fe1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f4fe3  ff5630                 -call dword ptr [esi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f4fe6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f4fe8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f4ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f4ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f4ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f4ff2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f4ff4  b874d15400             -mov eax, 0x54d174
    cpu.eax = 5558644 /*0x54d174*/;
    // 004f4ff9  e852fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f4ffe  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f5001  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5003  ff5334                 -call dword ptr [ebx + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5006  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5007  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5008  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5011  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5013  b884d15400             -mov eax, 0x54d184
    cpu.eax = 5558660 /*0x54d184*/;
    // 004f5018  e833fcffff             -call 0x4f4c50
    cpu.esp -= 4;
    sub_4f4c50(app, cpu);
    if (cpu.terminate) return;
    // 004f501d  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f5020  83783c00               +cmp dword ptr [eax + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5024  7504                   -jne 0x4f502a
    if (!cpu.flags.zf)
    {
        goto L_0x004f502a;
    }
    // 004f5026  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5029  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f502a:
    // 004f502a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f502b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f502d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f502f  ff533c                 -call dword ptr [ebx + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5033  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5034  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5041  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5044  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5047  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f504a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f504b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5050  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5051  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5054  837e3800               +cmp dword ptr [esi + 0x38], 0
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
    // 004f5058  7504                   -jne 0x4f505e
    if (!cpu.flags.zf)
    {
        goto L_0x004f505e;
    }
    // 004f505a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f505c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f505d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f505e:
    // 004f505e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5061  ff5638                 -call dword ptr [esi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5064  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5070  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5071  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5074  837e3c00               +cmp dword ptr [esi + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5078  7504                   -jne 0x4f507e
    if (!cpu.flags.zf)
    {
        goto L_0x004f507e;
    }
    // 004f507a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f507c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f507d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f507e:
    // 004f507e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5081  ff563c                 -call dword ptr [esi + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5084  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5090  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5091  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5094  837a2400               +cmp dword ptr [edx + 0x24], 0
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
    // 004f5098  7504                   -jne 0x4f509e
    if (!cpu.flags.zf)
    {
        goto L_0x004f509e;
    }
    // 004f509a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f509c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f509d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f509e:
    // 004f509e  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f50a1  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f50a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f50a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f50b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f50b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f50c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50c0  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f50c7  7501                   -jne 0x4f50ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f50ca;
    }
    // 004f50c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f50ca:
    // 004f50ca  e8b1010000             -call 0x4f5280
    cpu.esp -= 4;
    sub_4f5280(app, cpu);
    if (cpu.terminate) return;
    // 004f50cf  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f50d4  e8078d0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f50d9  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f50de  e9fd8c0100             -jmp 0x50dde0
    return sub_50dde0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f50f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f50f0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f50f3  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f50f7  7506                   -jne 0x4f50ff
    if (!cpu.flags.zf)
    {
        goto L_0x004f50ff;
    }
    // 004f50f9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f50fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f50ff:
    // 004f50ff  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5102  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5107  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5111  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5112  baf0504f00             -mov edx, 0x4f50f0
    cpu.edx = 5198064 /*0x4f50f0*/;
    // 004f5117  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f511c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f511e  e8bd970100             -call 0x50e8e0
    cpu.esp -= 4;
    sub_50e8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5123  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5124  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f5130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5130  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5131  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5133  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5135  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004f5137  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f5139  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004f513b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f513f  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5146  0f84b5000000           -je 0x4f5201
    if (cpu.flags.zf)
    {
        goto L_0x004f5201;
    }
L_0x004f514c:
    // 004f514c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f514e  745e                   -je 0x4f51ae
    if (cpu.flags.zf)
    {
        goto L_0x004f51ae;
    }
    // 004f5150  66837e2a00             +cmp word ptr [esi + 0x2a], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f5155  7506                   -jne 0x4f515d
    if (!cpu.flags.zf)
    {
        goto L_0x004f515d;
    }
    // 004f5157  66c7462a0200           -mov word ptr [esi + 0x2a], 2
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(42) /* 0x2a */) = 2 /*0x2*/;
L_0x004f515d:
    // 004f515d  66837e2c00             +cmp word ptr [esi + 0x2c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f5162  7506                   -jne 0x4f516a
    if (!cpu.flags.zf)
    {
        goto L_0x004f516a;
    }
    // 004f5164  66c7462c0400           -mov word ptr [esi + 0x2c], 4
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */) = 4 /*0x4*/;
L_0x004f516a:
    // 004f516a  66837e2e00             +cmp word ptr [esi + 0x2e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004f516f  7506                   -jne 0x4f5177
    if (!cpu.flags.zf)
    {
        goto L_0x004f5177;
    }
    // 004f5171  66c7462e0600           -mov word ptr [esi + 0x2e], 6
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */) = 6 /*0x6*/;
L_0x004f5177:
    // 004f5177  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f517b  7507                   -jne 0x4f5184
    if (!cpu.flags.zf)
    {
        goto L_0x004f5184;
    }
    // 004f517d  c74614b0504f00         -mov dword ptr [esi + 0x14], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 5198000 /*0x4f50b0*/;
L_0x004f5184:
    // 004f5184  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5188  7507                   -jne 0x4f5191
    if (!cpu.flags.zf)
    {
        goto L_0x004f5191;
    }
    // 004f518a  c7461cb0504f00         -mov dword ptr [esi + 0x1c], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 5198000 /*0x4f50b0*/;
L_0x004f5191:
    // 004f5191  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5195  7507                   -jne 0x4f519e
    if (!cpu.flags.zf)
    {
        goto L_0x004f519e;
    }
    // 004f5197  c74618b0504f00         -mov dword ptr [esi + 0x18], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 5198000 /*0x4f50b0*/;
L_0x004f519e:
    // 004f519e  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51a2  7507                   -jne 0x4f51ab
    if (!cpu.flags.zf)
    {
        goto L_0x004f51ab;
    }
    // 004f51a4  c74620b0504f00         -mov dword ptr [esi + 0x20], 0x4f50b0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 5198000 /*0x4f50b0*/;
L_0x004f51ab:
    // 004f51ab  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x004f51ae:
    // 004f51ae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51b0  741f                   -je 0x4f51d1
    if (cpu.flags.zf)
    {
        goto L_0x004f51d1;
    }
    // 004f51b2  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51b6  7419                   -je 0x4f51d1
    if (cpu.flags.zf)
    {
        goto L_0x004f51d1;
    }
    // 004f51b8  833df86d560000         +cmp dword ptr [0x566df8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51bf  750a                   -jne 0x4f51cb
    if (!cpu.flags.zf)
    {
        goto L_0x004f51cb;
    }
    // 004f51c1  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f51c6  e865d7ffff             -call 0x4f2930
    cpu.esp -= 4;
    sub_4f2930(app, cpu);
    if (cpu.terminate) return;
L_0x004f51cb:
    // 004f51cb  ff05f86d5600           -inc dword ptr [0x566df8]
    (app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */))++;
L_0x004f51d1:
    // 004f51d1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51d3  7536                   -jne 0x4f520b
    if (!cpu.flags.zf)
    {
        goto L_0x004f520b;
    }
L_0x004f51d5:
    // 004f51d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f51d7  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f51da  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004f51dc:
    // 004f51dc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f51de  7419                   -je 0x4f51f9
    if (cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51e0  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f51e4  7413                   -je 0x4f51f9
    if (cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004f51e8  750f                   -jne 0x4f51f9
    if (!cpu.flags.zf)
    {
        goto L_0x004f51f9;
    }
    // 004f51ea  8b0df86d5600           -mov ecx, dword ptr [0x566df8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
    // 004f51f0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f51f1  890df86d5600           -mov dword ptr [0x566df8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */) = cpu.ecx;
    // 004f51f7  741f                   -je 0x4f5218
    if (cpu.flags.zf)
    {
        goto L_0x004f5218;
    }
L_0x004f51f9:
    // 004f51f9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f51fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f51fe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004f5201:
    // 004f5201  e82a000000             -call 0x4f5230
    cpu.esp -= 4;
    sub_4f5230(app, cpu);
    if (cpu.terminate) return;
    // 004f5206  e941ffffff             -jmp 0x4f514c
    goto L_0x004f514c;
L_0x004f520b:
    // 004f520b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f520d  e84ed40100             -call 0x512660
    cpu.esp -= 4;
    sub_512660(app, cpu);
    if (cpu.terminate) return;
    // 004f5212  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5214  75bf                   -jne 0x4f51d5
    if (!cpu.flags.zf)
    {
        goto L_0x004f51d5;
    }
    // 004f5216  ebc4                   -jmp 0x4f51dc
    goto L_0x004f51dc;
L_0x004f5218:
    // 004f5218  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f521d  e88ed7ffff             -call 0x4f29b0
    cpu.esp -= 4;
    sub_4f29b0(app, cpu);
    if (cpu.terminate) return;
    // 004f5222  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5224  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5225  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5226  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5227  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5230  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5231  8b15f46d5600           -mov edx, dword ptr [0x566df4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
    // 004f5237  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5239  7402                   -je 0x4f523d
    if (cpu.flags.zf)
    {
        goto L_0x004f523d;
    }
    // 004f523b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f523c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f523d:
    // 004f523d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f523e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f523f  b828269f00             -mov eax, 0x9f2628
    cpu.eax = 10429992 /*0x9f2628*/;
    // 004f5244  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5246  e8858a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f524b  b80c269f00             -mov eax, 0x9f260c
    cpu.eax = 10429964 /*0x9f260c*/;
    // 004f5250  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5252  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5254  e8778a0100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5259  b8c0504f00             -mov eax, 0x4f50c0
    cpu.eax = 5198016 /*0x4f50c0*/;
    // 004f525e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5263  e810d8ffff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 004f5268  890df46d5600           -mov dword ptr [0x566df4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */) = cpu.ecx;
    // 004f526e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f526f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5270  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f5280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5284  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5285  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5286  833df46d560000         +cmp dword ptr [0x566df4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664244) /* 0x566df4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f528d  7434                   -je 0x4f52c3
    if (cpu.flags.zf)
    {
        goto L_0x004f52c3;
    }
    // 004f528f  bb28269f00             -mov ebx, 0x9f2628
    cpu.ebx = 10429992 /*0x9f2628*/;
    // 004f5294  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f5296:
    // 004f5296  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5298  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f529a  e8d1910100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f529f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52a1  7527                   -jne 0x4f52ca
    if (!cpu.flags.zf)
    {
        goto L_0x004f52ca;
    }
    // 004f52a3  be0c269f00             -mov esi, 0x9f260c
    cpu.esi = 10429964 /*0x9f260c*/;
    // 004f52a8  bf94d15400             -mov edi, 0x54d194
    cpu.edi = 5558676 /*0x54d194*/;
    // 004f52ad  bda4d15400             -mov ebp, 0x54d1a4
    cpu.ebp = 5558692 /*0x54d1a4*/;
    // 004f52b2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f52b4:
    // 004f52b4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f52b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f52b8  e8b3910100             -call 0x50e470
    cpu.esp -= 4;
    sub_50e470(app, cpu);
    if (cpu.terminate) return;
    // 004f52bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f52bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52c1  750e                   -jne 0x4f52d1
    if (!cpu.flags.zf)
    {
        goto L_0x004f52d1;
    }
L_0x004f52c3:
    // 004f52c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f52c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f52ca:
    // 004f52ca  e861000000             -call 0x4f5330
    cpu.esp -= 4;
    sub_4f5330(app, cpu);
    if (cpu.terminate) return;
    // 004f52cf  ebc5                   -jmp 0x4f5296
    goto L_0x004f5296;
L_0x004f52d1:
    // 004f52d1  e85a000000             -call 0x4f5330
    cpu.esp -= 4;
    sub_4f5330(app, cpu);
    if (cpu.terminate) return;
    // 004f52d6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f52d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f52da  e8718e0100             -call 0x50e150
    cpu.esp -= 4;
    sub_50e150(app, cpu);
    if (cpu.terminate) return;
    // 004f52df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f52e1  74d1                   -je 0x4f52b4
    if (cpu.flags.zf)
    {
        goto L_0x004f52b4;
    }
    // 004f52e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f52e4  b8db000000             -mov eax, 0xdb
    cpu.eax = 219 /*0xdb*/;
    // 004f52e9  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 004f52ef  68b4d15400             -push 0x54d1b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5558708 /*0x54d1b4*/;
    cpu.esp -= 4;
    // 004f52f4  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004f52fa  a398215500             -mov dword ptr [0x552198], eax
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004f52ff  e80cbdf0ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004f5304  83c408                 +add esp, 8
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
    // 004f5307  ebab                   -jmp 0x4f52b4
    goto L_0x004f52b4;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5310  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f5313  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f5317  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004f531a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f531c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004f5321  e84ad40100             -call 0x512770
    cpu.esp -= 4;
    sub_512770(app, cpu);
    if (cpu.terminate) return;
    // 004f5326  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004f5329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5330  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5331  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5333  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5335  7406                   -je 0x4f533d
    if (cpu.flags.zf)
    {
        goto L_0x004f533d;
    }
    // 004f5337  83781000               +cmp dword ptr [eax + 0x10], 0
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
    // 004f533b  7504                   -jne 0x4f5341
    if (!cpu.flags.zf)
    {
        goto L_0x004f5341;
    }
L_0x004f533d:
    // 004f533d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f533f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5340  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5341:
    // 004f5341  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5342  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5343  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5344  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004f5347  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f534a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f534c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f534e  742a                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5350  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5353  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 004f5357  7421                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5359  8b35f86d5600           -mov esi, dword ptr [0x566df8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */);
    // 004f535f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f5361  7417                   -je 0x4f537a
    if (cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5363  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004f5366  893df86d5600           -mov dword ptr [0x566df8], edi
    app->getMemory<x86::reg32>(x86::reg32(5664248) /* 0x566df8 */) = cpu.edi;
    // 004f536c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f536e  750a                   -jne 0x4f537a
    if (!cpu.flags.zf)
    {
        goto L_0x004f537a;
    }
    // 004f5370  b810514f00             -mov eax, 0x4f5110
    cpu.eax = 5198096 /*0x4f5110*/;
    // 004f5375  e836d6ffff             -call 0x4f29b0
    cpu.esp -= 4;
    sub_4f29b0(app, cpu);
    if (cpu.terminate) return;
L_0x004f537a:
    // 004f537a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f537c  e83fd30100             -call 0x5126c0
    cpu.esp -= 4;
    sub_5126c0(app, cpu);
    if (cpu.terminate) return;
    // 004f5381  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5384  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5385  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5386  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5387  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f5390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5392  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5394  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5395  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5397  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004f5399  8b15006e5600           -mov edx, dword ptr [0x566e00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f539f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f53a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f53a3  7e1a                   -jle 0x4f53bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f53bf;
    }
    // 004f53a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f53a7:
    // 004f53a7  8b8148269f00           -mov eax, dword ptr [ecx + 0x9f2648]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10430024) /* 0x9f2648 */);
    // 004f53ad  39c7                   +cmp edi, eax
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
    // 004f53af  7419                   -je 0x4f53ca
    if (cpu.flags.zf)
    {
        goto L_0x004f53ca;
    }
L_0x004f53b1:
    // 004f53b1  8b1d006e5600           -mov ebx, dword ptr [0x566e00]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f53b7  46                     -inc esi
    (cpu.esi)++;
    // 004f53b8  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f53bb  39de                   +cmp esi, ebx
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
    // 004f53bd  7ce8                   -jl 0x4f53a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f53a7;
    }
L_0x004f53bf:
    // 004f53bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004f53c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f53ca:
    // 004f53ca  8b9944269f00           -mov ebx, dword ptr [ecx + 0x9f2644]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(10430020) /* 0x9f2644 */);
    // 004f53d0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004f53d2  83c334                 -add ebx, 0x34
    (cpu.ebx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f53d5  e866fcffff             -call 0x4f5040
    cpu.esp -= 4;
    sub_4f5040(app, cpu);
    if (cpu.terminate) return;
    // 004f53da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f53dc  74d3                   -je 0x4f53b1
    if (cpu.flags.zf)
    {
        goto L_0x004f53b1;
    }
    // 004f53de  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f53e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f53e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f53f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f53f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f53f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f53f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f53f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f53f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f53f5  81eccc000000           -sub esp, 0xcc
    (cpu.esp) -= x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f53fb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f53fd  899424c8000000         -mov dword ptr [esp + 0xc8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */) = cpu.edx;
    // 004f5404  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f540a  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004f540f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5411  7510                   -jne 0x4f5423
    if (!cpu.flags.zf)
    {
        goto L_0x004f5423;
    }
    // 004f5413  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f5415  7c56                   -jl 0x4f546d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f546d;
    }
    // 004f5417  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f541d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f541e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f541f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5420  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5421  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5422  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5423:
    // 004f5423  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5424  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f542a  8b9424c8000000         -mov edx, dword ptr [esp + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004f5431  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5433  e858ffffff             -call 0x4f5390
    cpu.esp -= 4;
    sub_4f5390(app, cpu);
    if (cpu.terminate) return;
    // 004f5438  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f543a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f543c  7c12                   -jl 0x4f5450
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5450;
    }
    // 004f543e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004f5441  8b8044269f00           -mov eax, dword ptr [eax + 0x9f2644]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10430020) /* 0x9f2644 */);
    // 004f5447  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f544a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f544c  7402                   -je 0x4f5450
    if (cpu.flags.zf)
    {
        goto L_0x004f5450;
    }
    // 004f544e  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f5450:
    // 004f5450  8b35fc6d5600           -mov esi, dword ptr [0x566dfc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5456  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5457  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f545d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f545f  7c0c                   -jl 0x4f546d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f546d;
    }
    // 004f5461  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f5467  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5468  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5469  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f546c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f546d:
    // 004f546d  8dbc24ac000000         -lea edi, [esp + 0xac]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004f5474  8bb424c8000000         -mov esi, dword ptr [esp + 0xc8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(200) /* 0xc8 */);
    // 004f547b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f547f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5480  68ac000000             -push 0xac
    app->getMemory<x86::reg32>(cpu.esp-4) = 172 /*0xac*/;
    cpu.esp -= 4;
    // 004f5485  bf746164ea             -mov edi, 0xea646174
    cpu.edi = 3932447092 /*0xea646174*/;
    // 004f548a  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f548e  89bc24c4000000         -mov dword ptr [esp + 0xc4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */) = cpu.edi;
    // 004f5495  8d9c24c4000000         -lea ebx, [esp + 0xc4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f549c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f549f  8d9424b0000000         -lea edx, [esp + 0xb0]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004f54a6  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f54a9  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f54ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f54ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f54b0  742b                   -je 0x4f54dd
    if (cpu.flags.zf)
    {
        goto L_0x004f54dd;
    }
    // 004f54b2  83bc24c000000000       +cmp dword ptr [esp + 0xc0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(192) /* 0xc0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f54ba  7421                   -je 0x4f54dd
    if (cpu.flags.zf)
    {
        goto L_0x004f54dd;
    }
    // 004f54bc  8d9424c4000000         -lea edx, [esp + 0xc4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f54c3  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004f54c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f54c6  8b9c24c4000000         -mov ebx, dword ptr [esp + 0xc4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(196) /* 0xc4 */);
    // 004f54cd  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f54d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f54d1  8d9424b4000000         -lea edx, [esp + 0xb4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004f54d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f54da  ff5640                 -call dword ptr [esi + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f54dd:
    // 004f54dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f54df  758c                   -jne 0x4f546d
    if (!cpu.flags.zf)
    {
        goto L_0x004f546d;
    }
    // 004f54e1  81c4cc000000           -add esp, 0xcc
    (cpu.esp) += x86::reg32(x86::sreg32(204 /*0xcc*/));
    // 004f54e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f54ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f54f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f54f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f54f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f54f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f54f5  8b684c                 -mov ebp, dword ptr [eax + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f54f8  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004f54fb  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f54fe  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f5501  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f5503  0f84c1000000           -je 0x4f55ca
    if (cpu.flags.zf)
    {
        goto L_0x004f55ca;
    }
    // 004f5509  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f550c  837a4800               +cmp dword ptr [edx + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5510  0f85a4000000           -jne 0x4f55ba
    if (!cpu.flags.zf)
    {
        goto L_0x004f55ba;
    }
L_0x004f5516:
    // 004f5516  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5517  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5518  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5519  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f551d  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004f5522  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f5525  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f5528  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f552a  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f552d  ff565c                 -call dword ptr [esi + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5530  833dfc6d560000         +cmp dword ptr [0x566dfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5537  750a                   -jne 0x4f5543
    if (!cpu.flags.zf)
    {
        goto L_0x004f5543;
    }
    // 004f5539  e8a25dffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f553e  a3fc6d5600             -mov dword ptr [0x566dfc], eax
    app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */) = cpu.eax;
L_0x004f5543:
    // 004f5543  8b35fc6d5600           -mov esi, dword ptr [0x566dfc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5549  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f554a  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5550  8b35006e5600           -mov esi, dword ptr [0x566e00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5556  c1e605                 -shl esi, 5
    cpu.esi <<= 5 /*0x5*/ % 32;
    // 004f5559  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f555d  898644269f00           -mov dword ptr [esi + 0x9f2644], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10430020) /* 0x9f2644 */) = cpu.eax;
    // 004f5563  8dbe4c269f00           -lea edi, [esi + 0x9f264c]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(10430028) /* 0x9f264c */);
    // 004f5569  89ae48269f00           -mov dword ptr [esi + 0x9f2648], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10430024) /* 0x9f2648 */) = cpu.ebp;
    // 004f556f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5571  8d7634                 -lea esi, [esi + 0x34]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f5574  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5575  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5576  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5577  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5578  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5579  8b85a8000000           -mov eax, dword ptr [ebp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */);
    // 004f557f  8b3d006e5600           -mov edi, dword ptr [0x566e00]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5585  40                     -inc eax
    (cpu.eax)++;
    // 004f5586  47                     -inc edi
    (cpu.edi)++;
    // 004f5587  8985a8000000           -mov dword ptr [ebp + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004f558d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5591  893d006e5600           -mov dword ptr [0x566e00], edi
    app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */) = cpu.edi;
    // 004f5597  c74048ffffffff         -mov dword ptr [eax + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
    // 004f559e  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f55a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f55a5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f55ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55ae  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f55b1  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f55b4  83c404                 +add esp, 4
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
    // 004f55b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f55ba:
    // 004f55ba  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f55bc  8d5034                 -lea edx, [eax + 0x34]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004f55bf  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f55c2  ff5648                 -call dword ptr [esi + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f55c5  e94cffffff             -jmp 0x4f5516
    goto L_0x004f5516;
L_0x004f55ca:
    // 004f55ca  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 004f55cd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004f55d0  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004f55d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f55d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f55d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f55e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f55e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f55e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f55e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f55e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f55e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f55e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f55e7  8b784c                 -mov edi, dword ptr [eax + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f55ea  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004f55ed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f55ef  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f55f1  7409                   -je 0x4f55fc
    if (cpu.flags.zf)
    {
        goto L_0x004f55fc;
    }
    // 004f55f3  83bfa800000000         +cmp dword ptr [edi + 0xa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f55fa  7512                   -jne 0x4f560e
    if (!cpu.flags.zf)
    {
        goto L_0x004f560e;
    }
L_0x004f55fc:
    // 004f55fc  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f5603  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5608  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5609  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f560d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f560e:
    // 004f560e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f560f  8b2dfc6d5600           -mov ebp, dword ptr [0x566dfc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5615  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5616  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f561c  8b0d006e5600           -mov ecx, dword ptr [0x566e00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f5622  8b2d44269f00           -mov ebp, dword ptr [0x9f2644]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10430020) /* 0x9f2644 */);
    // 004f5628  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f562a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f562c  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004f562f  39eb                   +cmp ebx, ebp
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
    // 004f5631  7412                   -je 0x4f5645
    if (cpu.flags.zf)
    {
        goto L_0x004f5645;
    }
L_0x004f5633:
    // 004f5633  39c8                   +cmp eax, ecx
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
    // 004f5635  7d0e                   -jge 0x4f5645
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5645;
    }
    // 004f5637  8b9864269f00           -mov ebx, dword ptr [eax + 0x9f2664]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10430052) /* 0x9f2664 */);
    // 004f563d  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f5640  42                     -inc edx
    (cpu.edx)++;
    // 004f5641  39de                   +cmp esi, ebx
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
    // 004f5643  75ee                   -jne 0x4f5633
    if (!cpu.flags.zf)
    {
        goto L_0x004f5633;
    }
L_0x004f5645:
    // 004f5645  8b2d006e5600           -mov ebp, dword ptr [0x566e00]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */);
    // 004f564b  b944269f00             -mov ecx, 0x9f2644
    cpu.ecx = 10430020 /*0x9f2644*/;
    // 004f5650  4d                     -dec ebp
    (cpu.ebp)--;
    // 004f5651  8b87a8000000           -mov eax, dword ptr [edi + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */);
    // 004f5657  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f5659  48                     -dec eax
    (cpu.eax)--;
    // 004f565a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f565c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004f565f  8987a8000000           -mov dword ptr [edi + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 004f5665  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f5667  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004f566a  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 004f566d  0544269f00             -add eax, 0x9f2644
    (cpu.eax) += x86::reg32(x86::sreg32(10430020 /*0x9f2644*/));
    // 004f5672  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5674  892d006e5600           -mov dword ptr [0x566e00], ebp
    app->getMemory<x86::reg32>(x86::reg32(5664256) /* 0x566e00 */) = cpu.ebp;
    // 004f567a  e8714effff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f567f  8b15fc6d5600           -mov edx, dword ptr [0x566dfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664252) /* 0x566dfc */);
    // 004f5685  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5686  bb746164ea             -mov ebx, 0xea646174
    cpu.ebx = 3932447092 /*0xea646174*/;
    // 004f568b  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5691  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5696  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004f5699  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f569c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004f569f  ff555c                 -call dword ptr [ebp + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f56a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56a3  c7464800000000         -mov dword ptr [esi + 0x48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f56aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f56af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f56c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f56c0  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f56c4  7412                   -je 0x4f56d8
    if (cpu.flags.zf)
    {
        goto L_0x004f56d8;
    }
    // 004f56c6  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f56c9  83b89c00000000         +cmp dword ptr [eax + 0x9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f56d0  7406                   -je 0x4f56d8
    if (cpu.flags.zf)
    {
        goto L_0x004f56d8;
    }
    // 004f56d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f56d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f56d8:
    // 004f56d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f56da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f56e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f56e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f56e1  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f56e4  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f56e7  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f56ea  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f56ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f56ef  7408                   -je 0x4f56f9
    if (cpu.flags.zf)
    {
        goto L_0x004f56f9;
    }
    // 004f56f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f56f3  66a1206e5600           -mov ax, word ptr [0x566e20]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5664288) /* 0x566e20 */);
L_0x004f56f9:
    // 004f56f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f56fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5700  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5701  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f5704  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5707  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f570a  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f570d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f570e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f5710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5711  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5712  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5713  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5714  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5717  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f571b  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004f571f  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004f5723  8b684c                 -mov ebp, dword ptr [eax + 0x4c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
L_0x004f5726:
    // 004f5726  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004f572b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004f572d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f5731  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004f5735  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f5739  8d7634                 -lea esi, [esi + 0x34]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f573c  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5741  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5742  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5743  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5744  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5745  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f5746  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f574a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004f574d  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5751  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004f5754  ff5658                 -call dword ptr [esi + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5757  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5759  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f575b  750a                   -jne 0x4f5767
    if (!cpu.flags.zf)
    {
        goto L_0x004f5767;
    }
L_0x004f575d:
    // 004f575d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f575f  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5762  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5763  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5764  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5765  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5766  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5767:
    // 004f5767  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f576b  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f576f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5770  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f5774  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004f5777  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5778  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f577c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f577e  ff5640                 -call dword ptr [esi + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5781  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5785  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5787  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f5789  7509                   -jne 0x4f5794
    if (!cpu.flags.zf)
    {
        goto L_0x004f5794;
    }
    // 004f578b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f578f  895824                 -mov dword ptr [eax + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004f5792  eb15                   -jmp 0x4f57a9
    goto L_0x004f57a9;
L_0x004f5794:
    // 004f5794  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5796  7411                   -je 0x4f57a9
    if (cpu.flags.zf)
    {
        goto L_0x004f57a9;
    }
    // 004f5798  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f579c  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f57a0  7407                   -je 0x4f57a9
    if (cpu.flags.zf)
    {
        goto L_0x004f57a9;
    }
    // 004f57a2  c7404801000000         -mov dword ptr [eax + 0x48], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
L_0x004f57a9:
    // 004f57a9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f57ab  0f8475ffffff           -je 0x4f5726
    if (cpu.flags.zf)
    {
        goto L_0x004f5726;
    }
    // 004f57b1  ebaa                   -jmp 0x4f575d
    goto L_0x004f575d;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f57c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f57c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f57c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f57c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f57c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f57c4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004f57c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f57c9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f57cc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f57ce  ba746164ea             -mov edx, 0xea646174
    cpu.edx = 3932447092 /*0xea646174*/;
    // 004f57d3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f57d7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004f57db  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004f57df  7d32                   -jge 0x4f5813
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5813;
    }
    // 004f57e1  837848fc               +cmp dword ptr [eax + 0x48], -4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f57e5  7d59                   -jge 0x4f5840
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5840;
    }
    // 004f57e7  b86e706fea             -mov eax, 0xea6f706e
    cpu.eax = 3933171822 /*0xea6f706e*/;
    // 004f57ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f57ee  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f57f2  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 004f57f5  bb6e706fea             -mov ebx, 0xea6f706e
    cpu.ebx = 3933171822 /*0xea6f706e*/;
    // 004f57fa  8d5634                 -lea edx, [esi + 0x34]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004f57fd  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5800  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5802  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5805  ff5554                 -call dword ptr [ebp + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5808  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f580a  7407                   -je 0x4f5813
    if (cpu.flags.zf)
    {
        goto L_0x004f5813;
    }
    // 004f580c  c74648ffffffff         -mov dword ptr [esi + 0x48], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */) = 4294967295 /*0xffffffff*/;
L_0x004f5813:
    // 004f5813  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f5817  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f581b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004f581e  8b404c                 -mov eax, dword ptr [eax + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004f5821  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5825  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5826  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f5829  83c234                 -add edx, 0x34
    (cpu.edx) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004f582c  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f582f  ff5654                 -call dword ptr [esi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5832  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5834  7402                   -je 0x4f5838
    if (cpu.flags.zf)
    {
        goto L_0x004f5838;
    }
    // 004f5836  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004f5838:
    // 004f5838  83c40c                 +add esp, 0xc
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
    // 004f583b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f583f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5840:
    // 004f5840  ff4848                 +dec dword ptr [eax + 0x48]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004f5843  ebce                   -jmp 0x4f5813
    goto L_0x004f5813;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5850  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5851  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5852  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004f5854  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5856  740a                   -je 0x4f5862
    if (cpu.flags.zf)
    {
        goto L_0x004f5862;
    }
    // 004f5858  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004f585f  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
L_0x004f5862:
    // 004f5862  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004f5864  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f5867  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f5869  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f586b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f586d  ff5738                 -call dword ptr [edi + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f5870  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5871  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5872  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f5880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5880  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5881  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5882  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5883  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5885  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f5887  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f588c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f588f  e85c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f5894  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 004f5899  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004f589c  8d4606                 -lea eax, [esi + 6]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004f589f  e84c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58a4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f58a9  8d510a                 -lea edx, [ecx + 0xa]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 004f58ac  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f58af  e83c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f58c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f58c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f58c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f58c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f58c3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f58c5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f58c7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004f58cc  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004f58cf  e81c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58d4  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 004f58d9  8d5106                 -lea edx, [ecx + 6]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004f58dc  8d4604                 -lea eax, [esi + 4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004f58df  e80c4cffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58e4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f58e9  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f58ec  8d460a                 -lea eax, [esi + 0xa]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004f58ef  e8fc4bffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f58f4  66c7010600             -mov word ptr [ecx], 6
    app->getMemory<x86::reg16>(cpu.ecx) = 6 /*0x6*/;
    // 004f58f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f58fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f5900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5902  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5905  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f5908  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f590a  8d4202                 -lea eax, [edx + 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004f590d  66c7020600             -mov word ptr [edx], 6
    app->getMemory<x86::reg16>(cpu.edx) = 6 /*0x6*/;
    // 004f5912  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5914  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004f5919  e8f8adfeff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 004f591e  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004f5923  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004f5928  8d4106                 -lea eax, [ecx + 6]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 004f592b  e8e6adfeff             -call 0x4e0716
    cpu.esp -= 4;
    sub_4e0716(app, cpu);
    if (cpu.terminate) return;
    // 004f5930  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f5935  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5937  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f593a  e8b14bffff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004f593f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5944  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f5950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5952  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5953  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5954  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5957  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5959  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f595b  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f595f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5960  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5964  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5965  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5967  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004f596c  681c010000             -push 0x11c
    app->getMemory<x86::reg32>(cpu.esp-4) = 284 /*0x11c*/;
    cpu.esp -= 4;
    // 004f5971  8d5e24                 -lea ebx, [esi + 0x24]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f5974  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004f5978  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5979  8b4f58                 -mov ecx, dword ptr [edi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(88) /* 0x58 */);
    // 004f597c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f597d  e8dae40300             -call 0x533e5c
    cpu.esp -= 4;
    sub_533e5c(app, cpu);
    if (cpu.terminate) return;
    // 004f5982  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f5985  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5987  7e16                   -jle 0x4f599f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f599f;
    }
    // 004f5989  807f2600               +cmp byte ptr [edi + 0x26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(38) /* 0x26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f598d  741a                   -je 0x4f59a9
    if (cpu.flags.zf)
    {
        goto L_0x004f59a9;
    }
    // 004f598f  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004f5991  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5993  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f5996  e8f5ce0100             -call 0x512890
    cpu.esp -= 4;
    sub_512890(app, cpu);
    if (cpu.terminate) return;
    // 004f599b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f599d  740a                   -je 0x4f59a9
    if (cpu.flags.zf)
    {
        goto L_0x004f59a9;
    }
L_0x004f599f:
    // 004f599f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f59a1  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f59a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f59a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f59a9:
    // 004f59a9  a1a0c17900             -mov eax, dword ptr [0x79c1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f59ae  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f59b3  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f59b6  8d4624                 -lea eax, [esi + 0x24]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004f59b9  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f59bb  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f59bd  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f59bf  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f59c6  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f59c8  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004f59cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f59cd  7445                   -je 0x4f5a14
    if (cpu.flags.zf)
    {
        goto L_0x004f5a14;
    }
    // 004f59cf  837e0804               +cmp dword ptr [esi + 8], 4
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
    // 004f59d3  7c3f                   -jl 0x4f5a14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a14;
    }
    // 004f59d5  837c24100e             +cmp dword ptr [esp + 0x10], 0xe
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
    // 004f59da  7538                   -jne 0x4f5a14
    if (!cpu.flags.zf)
    {
        goto L_0x004f5a14;
    }
    // 004f59dc  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004f59df  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f59e1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004f59e3  e898feffff             -call 0x4f5880
    cpu.esp -= 4;
    sub_4f5880(app, cpu);
    if (cpu.terminate) return;
    // 004f59e8  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f59ef  7c16                   -jl 0x4f5a07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a07;
    }
    // 004f59f1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f59f3  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 004f59f8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f59fa  b810d25400             -mov eax, 0x54d210
    cpu.eax = 5558800 /*0x54d210*/;
    // 004f59ff  8d5620                 -lea edx, [esi + 0x20]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004f5a02  e879c70100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5a07:
    // 004f5a07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5a0c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5a0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5a14:
    // 004f5a14  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004f5a1b  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f5a22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5a24  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f5a27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f5a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5a30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5a31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5a32  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a35  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004f5a37  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004f5a3a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004f5a3c  8d5026                 -lea edx, [eax + 0x26]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004f5a3f  bb30000000             -mov ebx, 0x30
    cpu.ebx = 48 /*0x30*/;
    // 004f5a44  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5a46  e84559ffff             -call 0x4eb390
    cpu.esp -= 4;
    sub_4eb390(app, cpu);
    if (cpu.terminate) return;
    // 004f5a4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5a4d  7406                   -je 0x4f5a55
    if (cpu.flags.zf)
    {
        goto L_0x004f5a55;
    }
    // 004f5a4f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a52  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a53  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5a55:
    // 004f5a55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5a56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a57  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004f5a59  bb767273ea             -mov ebx, 0xea737276
    cpu.ebx = 3933434486 /*0xea737276*/;
    // 004f5a5e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5a60  49                     -dec ecx
    (cpu.ecx)--;
    // 004f5a61  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f5a63  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f5a65  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f5a67  49                     -dec ecx
    (cpu.ecx)--;
    // 004f5a68  41                     -inc ecx
    (cpu.ecx)++;
    // 004f5a69  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f5a6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a6e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5a70  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004f5a72  e839060000             -call 0x4f60b0
    cpu.esp -= 4;
    sub_4f60b0(app, cpu);
    if (cpu.terminate) return;
    // 004f5a77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a79  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5a7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f5a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5a82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5a83  8b0da0c17900           -mov ecx, dword ptr [0x79c1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7979424) /* 0x79c1a0 */);
    // 004f5a89  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004f5a8c  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 004f5a8f  7c07                   -jl 0x4f5a98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5a98;
    }
    // 004f5a91  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f5a94  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5a96  7409                   -je 0x4f5aa1
    if (cpu.flags.zf)
    {
        goto L_0x004f5aa1;
    }
L_0x004f5a98:
    // 004f5a98  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5a9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5a9f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aa0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5aa1:
    // 004f5aa1  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5aa4  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5aa7  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f5aaa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5aac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f5aae  e82d050000             -call 0x4f5fe0
    cpu.esp -= 4;
    sub_4f5fe0(app, cpu);
    if (cpu.terminate) return;
    // 004f5ab3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5ab5  75e1                   -jne 0x4f5a98
    if (!cpu.flags.zf)
    {
        goto L_0x004f5a98;
    }
    // 004f5ab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ab9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5ac3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5ac4  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004f5ac7  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004f5ac9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5acb  39d9                   +cmp ecx, ebx
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
    // 004f5acd  750e                   -jne 0x4f5add
    if (!cpu.flags.zf)
    {
        goto L_0x004f5add;
    }
    // 004f5acf  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004f5ad2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5ad4  7511                   -jne 0x4f5ae7
    if (!cpu.flags.zf)
    {
        goto L_0x004f5ae7;
    }
L_0x004f5ad6:
    // 004f5ad6  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x004f5add:
    // 004f5add  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5ae2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ae6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5ae7:
    // 004f5ae7  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004f5aea  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004f5aed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5aef  e8ec040000             -call 0x4f5fe0
    cpu.esp -= 4;
    sub_4f5fe0(app, cpu);
    if (cpu.terminate) return;
    // 004f5af4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5af6  75de                   -jne 0x4f5ad6
    if (!cpu.flags.zf)
    {
        goto L_0x004f5ad6;
    }
    // 004f5af8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5afd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5afe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5aff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b00  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4f5b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5b15  8b1d50369f00           -mov ebx, dword ptr [0x9f3650]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */);
    // 004f5b1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5b1d  e8de9ffeff             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004f5b22  891550369f00           -mov dword ptr [0x9f3650], edx
    app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */) = cpu.edx;
    // 004f5b28  8b4b20                 -mov ecx, dword ptr [ebx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004f5b2b  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f5b2e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f5b30  743f                   -je 0x4f5b71
    if (cpu.flags.zf)
    {
        goto L_0x004f5b71;
    }
    // 004f5b32  8dbb8c000000           -lea edi, [ebx + 0x8c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(140) /* 0x8c */);
    // 004f5b38  8d7370                 -lea esi, [ebx + 0x70]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
L_0x004f5b3b:
    // 004f5b3b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5b3d  e81e840100             -call 0x50df60
    cpu.esp -= 4;
    sub_50df60(app, cpu);
    if (cpu.terminate) return;
    // 004f5b42  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5b44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5b46  7449                   -je 0x4f5b91
    if (cpu.flags.zf)
    {
        goto L_0x004f5b91;
    }
    // 004f5b48  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f5b4a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f5b4c  e8fffdffff             -call 0x4f5950
    cpu.esp -= 4;
    sub_4f5950(app, cpu);
    if (cpu.terminate) return;
    // 004f5b51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5b53  7431                   -je 0x4f5b86
    if (cpu.flags.zf)
    {
        goto L_0x004f5b86;
    }
    // 004f5b55  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5b57  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f5b59  e872830100             -call 0x50ded0
    cpu.esp -= 4;
    sub_50ded0(app, cpu);
    if (cpu.terminate) return;
    // 004f5b5e  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5b61  7408                   -je 0x4f5b6b
    if (cpu.flags.zf)
    {
        goto L_0x004f5b6b;
    }
    // 004f5b63  8d510c                 -lea edx, [ecx + 0xc]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004f5b66  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004f5b69  ff13                   -call dword ptr [ebx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004f5b6b:
    // 004f5b6b  837b2000               +cmp dword ptr [ebx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5b6f  75ca                   -jne 0x4f5b3b
    if (!cpu.flags.zf)
    {
        goto L_0x004f5b3b;
    }
L_0x004f5b71:
    // 004f5b71  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004f5b74  e887a0feff             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004f5b79  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004f5b80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5b85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5b86:
    // 004f5b86  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5b88  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5b8a  e8c1820100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f5b8f  ebda                   -jmp 0x4f5b6b
    goto L_0x004f5b6b;
L_0x004f5b91:
    // 004f5b91  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004f5b94  e8d79ffeff             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004f5b99  ebd0                   -jmp 0x4f5b6b
    goto L_0x004f5b6b;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f5ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ba1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5ba2  81ec90010000           -sub esp, 0x190
    (cpu.esp) -= x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f5ba8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5baa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5bab  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004f5bb0  e8fbe20300             -call 0x533eb0
    cpu.esp -= 4;
    sub_533eb0(app, cpu);
    if (cpu.terminate) return;
    // 004f5bb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5bb7  751f                   -jne 0x4f5bd8
    if (!cpu.flags.zf)
    {
        goto L_0x004f5bd8;
    }
    // 004f5bb9  8b942488010000         -mov edx, dword ptr [esp + 0x188]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 004f5bc0  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004f5bc3  740c                   -je 0x4f5bd1
    if (cpu.flags.zf)
    {
        goto L_0x004f5bd1;
    }
    // 004f5bc5  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
L_0x004f5bc8:
    // 004f5bc8  81c490010000           +add esp, 0x190
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
    // 004f5bce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5bcf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5bd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5bd1:
    // 004f5bd1  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 004f5bd6  ebf0                   -jmp 0x4f5bc8
    goto L_0x004f5bc8;
L_0x004f5bd8:
    // 004f5bd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5bda  81c490010000           -add esp, 0x190
    (cpu.esp) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 004f5be0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5be2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f5bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5bf1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5bf2  e8a7e20300             -call 0x533e9e
    cpu.esp -= 4;
    sub_533e9e(app, cpu);
    if (cpu.terminate) return;
    // 004f5bf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5bf9  7508                   -jne 0x4f5c03
    if (!cpu.flags.zf)
    {
        goto L_0x004f5c03;
    }
    // 004f5bfb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5c00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5c03:
    // 004f5c03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5c07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5c11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5c12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f5c13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5c14  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004f5c17  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004f5c1b  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004f5c1f  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004f5c23  ba1cd25400             -mov edx, 0x54d21c
    cpu.edx = 5558812 /*0x54d21c*/;
    // 004f5c28  b928d25400             -mov ecx, 0x54d228
    cpu.ecx = 5558824 /*0x54d228*/;
    // 004f5c2d  bb0a010000             -mov ebx, 0x10a
    cpu.ebx = 266 /*0x10a*/;
    // 004f5c32  b838d25400             -mov eax, 0x54d238
    cpu.eax = 5558840 /*0x54d238*/;
    // 004f5c37  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f5c3d  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f5c43  baa8400100             -mov edx, 0x140a8
    cpu.edx = 82088 /*0x140a8*/;
    // 004f5c48  8b1df4435600           -mov ebx, dword ptr [0x5643f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 004f5c4e  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f5c54  e8c7b9feff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004f5c59  baa8400100             -mov edx, 0x140a8
    cpu.edx = 82088 /*0x140a8*/;
    // 004f5c5e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5c60  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5c62  e8a5aafeff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f5c67  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5c69  8d6970                 -lea ebp, [ecx + 0x70]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 004f5c6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5c6e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004f5c70  e85b800100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5c75  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 004f5c7b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5c7d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5c7f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004f5c81  e84a800100             -call 0x50dcd0
    cpu.esp -= 4;
    sub_50dcd0(app, cpu);
    if (cpu.terminate) return;
    // 004f5c86  8d81a8000000           -lea eax, [ecx + 0xa8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 004f5c8c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004f5c8e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f5c90  8da800400100           -lea ebp, [eax + 0x14000]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(81920) /* 0x14000 */);
L_0x004f5c96:
    // 004f5c96  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5c98  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f5c9a  81c140010000           -add ecx, 0x140
    (cpu.ecx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f5ca0  e8ab810100             -call 0x50de50
    cpu.esp -= 4;
    sub_50de50(app, cpu);
    if (cpu.terminate) return;
    // 004f5ca5  39e9                   +cmp ecx, ebp
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
    // 004f5ca7  75ed                   -jne 0x4f5c96
    if (!cpu.flags.zf)
    {
        goto L_0x004f5c96;
    }
    // 004f5ca9  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 004f5cae  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004f5cb0  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004f5cb2  e8f3e10300             -call 0x533eaa
    cpu.esp -= 4;
    sub_533eaa(app, cpu);
    if (cpu.terminate) return;
    // 004f5cb7  c7462001000000         -mov dword ptr [esi + 0x20], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 004f5cbe  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004f5cc1  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004f5cc5  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f5cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5cca  0f85ad010000           -jne 0x4f5e7d
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e7d;
    }
L_0x004f5cd0:
    // 004f5cd0  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5cd7  7c1a                   -jl 0x4f5cf3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5cf3;
    }
    // 004f5cd9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5cdb  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004f5ce0  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5ce4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5ce6  b828d25400             -mov eax, 0x54d228
    cpu.eax = 5558824 /*0x54d228*/;
    // 004f5ceb  8d5e58                 -lea ebx, [esi + 0x58]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5cee  e88dc40100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5cf3:
    // 004f5cf3  837e58ff               +cmp dword ptr [esi + 0x58], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5cf7  0f8423010000           -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5cfd  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5cff  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d04  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f5d09  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004f5d0b  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004f5d0f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f5d14  8b5e58                 -mov ebx, dword ptr [esi + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5d18  e839e10300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d1d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5d1f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d23  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d24  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004f5d26  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 004f5d2b  896c2420               -mov dword ptr [esp + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004f5d2f  68ffff0000             -push 0xffff
    app->getMemory<x86::reg32>(cpu.esp-4) = 65535 /*0xffff*/;
    cpu.esp -= 4;
    // 004f5d34  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d38  e819e10300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d3d  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004f5d3f  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5d43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d44  680f400000             -push 0x400f
    app->getMemory<x86::reg32>(cpu.esp-4) = 16399 /*0x400f*/;
    cpu.esp -= 4;
    // 004f5d49  68e8030000             -push 0x3e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 1000 /*0x3e8*/;
    cpu.esp -= 4;
    // 004f5d4e  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5d52  e8ffe00300             -call 0x533e56
    cpu.esp -= 4;
    sub_533e56(app, cpu);
    if (cpu.terminate) return;
    // 004f5d57  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f5d5b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d5c  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004f5d60  687e660480             -push 0x8004667e
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147772030 /*0x8004667e*/;
    cpu.esp -= 4;
    // 004f5d65  8b5e58                 -mov ebx, dword ptr [esi + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5d68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5d69  e8e2e00300             -call 0x533e50
    cpu.esp -= 4;
    sub_533e50(app, cpu);
    if (cpu.terminate) return;
    // 004f5d6e  ba0e000000             -mov edx, 0xe
    cpu.edx = 14 /*0xe*/;
    // 004f5d73  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5d75  e892a9feff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f5d7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5d7c  668b442410             -mov ax, word ptr [esp + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f5d81  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 004f5d86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d87  6689542404             -mov word ptr [esp + 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004f5d8c  e8b9e00300             -call 0x533e4a
    cpu.esp -= 4;
    sub_533e4a(app, cpu);
    if (cpu.terminate) return;
    // 004f5d91  6a0e                   -push 0xe
    app->getMemory<x86::reg32>(cpu.esp-4) = 14 /*0xe*/;
    cpu.esp -= 4;
    // 004f5d93  6689442410             -mov word ptr [esp + 0x10], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004f5d98  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5d9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5d9d  8b6e58                 -mov ebp, dword ptr [esi + 0x58]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5da0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5da1  e89ee00300             -call 0x533e44
    cpu.esp -= 4;
    sub_533e44(app, cpu);
    if (cpu.terminate) return;
    // 004f5da6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5da8  0f8572000000           -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dae  c74424180e000000       -mov dword ptr [esp + 0x18], 0xe
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 14 /*0xe*/;
    // 004f5db6  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f5dba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dbb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f5dbf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dc0  8b5658                 -mov edx, dword ptr [esi + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5dc3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5dc4  e875e00300             -call 0x533e3e
    cpu.esp -= 4;
    sub_533e3e(app, cpu);
    if (cpu.terminate) return;
    // 004f5dc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5dcb  7553                   -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dcd  837c24180e             +cmp dword ptr [esp + 0x18], 0xe
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5dd2  754c                   -jne 0x4f5e20
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5dd4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f5dd6  8d565c                 -lea edx, [esi + 0x5c]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004f5dd9  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004f5dde  e89dfaffff             -call 0x4f5880
    cpu.esp -= 4;
    sub_4f5880(app, cpu);
    if (cpu.terminate) return;
    // 004f5de3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5de7  893550369f00           -mov dword ptr [0x9f3650], esi
    app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */) = cpu.esi;
    // 004f5ded  66894624               -mov word ptr [esi + 0x24], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ax;
    // 004f5df1  8d4608                 -lea eax, [esi + 8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004f5df4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004f5df9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f5dfa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5dfc  b8105b4f00             -mov eax, 0x4f5b10
    cpu.eax = 5200656 /*0x4f5b10*/;
    // 004f5e01  e89a99feff             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004f5e06  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004f5e08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f5e0a  7414                   -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
L_0x004f5e0c:
    // 004f5e0c  833d50369f0000         +cmp dword ptr [0x9f3650], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434128) /* 0x9f3650 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5e13  740b                   -je 0x4f5e20
    if (cpu.flags.zf)
    {
        goto L_0x004f5e20;
    }
    // 004f5e15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f5e17  e8c49afeff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5e1c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5e1e  75ec                   -jne 0x4f5e0c
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e0c;
    }
L_0x004f5e20:
    // 004f5e20  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004f5e22  754f                   -jne 0x4f5e73
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e73;
    }
    // 004f5e24  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5e2b  7d5b                   -jge 0x4f5e88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5e88;
    }
L_0x004f5e2d:
    // 004f5e2d  8b6e58                 -mov ebp, dword ptr [esi + 0x58]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5e30  83fdff                 +cmp ebp, -1
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
    // 004f5e33  7435                   -je 0x4f5e6a
    if (cpu.flags.zf)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f5e36  e869e00300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f5e3b  83f8ff                 +cmp eax, -1
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
    // 004f5e3e  752a                   -jne 0x4f5e6a
    if (!cpu.flags.zf)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e40  e8f3df0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f5e45  8b15e06d5600           -mov edx, dword ptr [0x566de0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f5e4b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004f5e4f  83fa04                 +cmp edx, 4
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
    // 004f5e52  7c16                   -jl 0x4f5e6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5e6a;
    }
    // 004f5e54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5e56  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f5e5a  b84cd25400             -mov eax, 0x54d24c
    cpu.eax = 5558860 /*0x54d24c*/;
    // 004f5e5f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5e61  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5e63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5e65  e816c30100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
L_0x004f5e6a:
    // 004f5e6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5e6c  e81fbafeff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f5e71  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004f5e73:
    // 004f5e73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5e75  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f5e78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5e7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5e7d:
    // 004f5e7d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004f5e81  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004f5e83  e948feffff             -jmp 0x4f5cd0
    goto L_0x004f5cd0;
L_0x004f5e88:
    // 004f5e88  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5e8a  b840d25400             -mov eax, 0x54d240
    cpu.eax = 5558848 /*0x54d240*/;
    // 004f5e8f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5e91  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5e93  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5e95  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f5e97  e8e4c20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5e9c  eb8f                   -jmp 0x4f5e2d
    goto L_0x004f5e2d;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4f5ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5ea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f5ea1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f5ea2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5ea5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f5ea7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5ea9  833de06d560004         +cmp dword ptr [0x566de0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5eb0  7d4b                   -jge 0x4f5efd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004f5efd;
    }
L_0x004f5eb2:
    // 004f5eb2  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004f5eb5  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004f5ebc  e86f9cfeff             -call 0x4dfb30
    cpu.esp -= 4;
    sub_4dfb30(app, cpu);
    if (cpu.terminate) return;
    // 004f5ec1  8b4e58                 -mov ecx, dword ptr [esi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004f5ec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5ec5  e8dadf0300             -call 0x533ea4
    cpu.esp -= 4;
    sub_533ea4(app, cpu);
    if (cpu.terminate) return;
    // 004f5eca  83f8ff                 +cmp eax, -1
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
    // 004f5ecd  7444                   -je 0x4f5f13
    if (cpu.flags.zf)
    {
        goto L_0x004f5f13;
    }
L_0x004f5ecf:
    // 004f5ecf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f5ed1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5ed2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f5ed3:
    // 004f5ed3  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f5ed6  7567                   -jne 0x4f5f3f
    if (!cpu.flags.zf)
    {
        goto L_0x004f5f3f;
    }
    // 004f5ed8  8d4670                 -lea eax, [esi + 0x70]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 004f5edb  e8007f0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f5ee0  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004f5ee6  e8f57e0100             -call 0x50dde0
    cpu.esp -= 4;
    sub_50dde0(app, cpu);
    if (cpu.terminate) return;
    // 004f5eeb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f5eed  e89eb9feff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004f5ef2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f5ef7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f5efa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5efb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5efc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f5efd:
    // 004f5efd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5eff  b858d25400             -mov eax, 0x54d258
    cpu.eax = 5558872 /*0x54d258*/;
    // 004f5f04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5f06  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5f08  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f5f0a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004f5f0c  e86fc20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5f11  eb9f                   -jmp 0x4f5eb2
    goto L_0x004f5eb2;
L_0x004f5f13:
    // 004f5f13  e820df0300             -call 0x533e38
    cpu.esp -= 4;
    sub_533e38(app, cpu);
    if (cpu.terminate) return;
    // 004f5f18  8b1de06d5600           -mov ebx, dword ptr [0x566de0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5664224) /* 0x566de0 */);
    // 004f5f1e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f5f22  83fb04                 +cmp ebx, 4
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
    // 004f5f25  7ca8                   -jl 0x4f5ecf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f5ecf;
    }
    // 004f5f27  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f5f29  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f5f2d  b868d25400             -mov eax, 0x54d268
    cpu.eax = 5558888 /*0x54d268*/;
    // 004f5f32  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004f5f34  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f5f36  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004f5f38  e843c20100             -call 0x512180
    cpu.esp -= 4;
    sub_512180(app, cpu);
    if (cpu.terminate) return;
    // 004f5f3d  eb90                   -jmp 0x4f5ecf
    goto L_0x004f5ecf;
L_0x004f5f3f:
    // 004f5f3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f5f41  e89a99feff             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004f5f46  eb8b                   -jmp 0x4f5ed3
    goto L_0x004f5ed3;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f5f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5f51  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004f5f56  83c024                 -add eax, 0x24
    (cpu.eax) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004f5f59  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004f5f5b  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004f5f5d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004f5f5f  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004f5f66  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004f5f68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f5f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f5f71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f5f72  8d485c                 -lea ecx, [eax + 0x5c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004f5f75  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f5f77  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004f5f79  e802cd0100             -call 0x512c80
    cpu.esp -= 4;
    sub_512c80(app, cpu);
    if (cpu.terminate) return;
    // 004f5f7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f5f80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4f5f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f5f90  e9dbcd0100             -jmp 0x512d70
    return sub_512d70(app, cpu);
}

}
