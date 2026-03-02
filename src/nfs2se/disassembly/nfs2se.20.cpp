#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_480b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b7c  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00480b7f  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 00480b84  a3908f4c00             -mov dword ptr [0x4c8f90], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */) = cpu.eax;
    // 00480b89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480b8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b8c  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00480b8f  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00480b92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480ba0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480ba1  baa4e54b00             -mov edx, 0x4be5a4
    cpu.edx = 4973988 /*0x4be5a4*/;
    // 00480ba6  e805000000             -call 0x480bb0
    cpu.esp -= 4;
    sub_480bb0(app, cpu);
    if (cpu.terminate) return;
    // 00480bab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480bb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bb2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480bb4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480bb6  e865040000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480bbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480bbd  7508                   -jne 0x480bc7
    if (!cpu.flags.zf)
    {
        goto L_0x00480bc7;
    }
L_0x00480bbf:
    // 00480bbf  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00480bc4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bc5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480bc7:
    // 00480bc7  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480bcd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480bcf  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480bd1  e826020000             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00480bd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480bd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480bda  7405                   -je 0x480be1
    if (cpu.flags.zf)
    {
        goto L_0x00480be1;
    }
    // 00480bdc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480bde  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bdf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480be0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480be1:
    // 00480be1  bab4e54b00             -mov edx, 0x4be5b4
    cpu.edx = 4974004 /*0x4be5b4*/;
    // 00480be6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480be8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480bea  e831040000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480bef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480bf1  74cc                   -je 0x480bbf
    if (cpu.flags.zf)
    {
        goto L_0x00480bbf;
    }
    // 00480bf3  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480bf9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480bfb  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480bfd  e8fa010000             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00480c02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480c04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480c06  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c07  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480c0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c0c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480c0d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480c0e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480c0f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480c11  bac0e54b00             -mov edx, 0x4be5c0
    cpu.edx = 4974016 /*0x4be5c0*/;
    // 00480c16  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480c18  e803040000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480c1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c1f  7509                   -jne 0x480c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00480c2a;
    }
    // 00480c21  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00480c26  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c27  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c28  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480c2a:
    // 00480c2a  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480c30  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480c32  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480c34  e8c3010000             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00480c39  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c3a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c3b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480c41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480c42  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480c43  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480c44  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480c45  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00480c48  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00480c4a  bec8e54b00             -mov esi, 0x4be5c8
    cpu.esi = 4974024 /*0x4be5c8*/;
    // 00480c4f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480c51  e8b6ffffff             -call 0x480c0c
    cpu.esp -= 4;
    sub_480c0c(app, cpu);
    if (cpu.terminate) return;
    // 00480c56  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00480c57:
    // 00480c57  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480c59  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00480c5b  3c00                   +cmp al, 0
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
    // 00480c5d  7410                   -je 0x480c6f
    if (cpu.flags.zf)
    {
        goto L_0x00480c6f;
    }
    // 00480c5f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480c62  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480c65  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00480c68  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480c6b  3c00                   +cmp al, 0
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
    // 00480c6d  75e8                   -jne 0x480c57
    if (!cpu.flags.zf)
    {
        goto L_0x00480c57;
    }
L_0x00480c6f:
    // 00480c6f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c70  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480c72  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480c74  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00480c79  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480c7a  2bc9                   +sub ecx, ecx
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
    // 00480c7c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480c7d  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00480c7f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00480c81  4f                     -dec edi
    (cpu.edi)--;
L_0x00480c82:
    // 00480c82  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480c84  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00480c86  3c00                   +cmp al, 0
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
    // 00480c88  7410                   -je 0x480c9a
    if (cpu.flags.zf)
    {
        goto L_0x00480c9a;
    }
    // 00480c8a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480c8d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480c90  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00480c93  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480c96  3c00                   +cmp al, 0
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
    // 00480c98  75e8                   -jne 0x480c82
    if (!cpu.flags.zf)
    {
        goto L_0x00480c82;
    }
L_0x00480c9a:
    // 00480c9a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c9b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480c9d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00480c9f  e87c030000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480ca4  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00480ca7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ca8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ca9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480caa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480cab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480cac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480cb0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480cb1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480cb2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480cb3  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00480cb6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00480cb8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480cba  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00480cbc  e84bffffff             -call 0x480c0c
    cpu.esp -= 4;
    sub_480c0c(app, cpu);
    if (cpu.terminate) return;
    // 00480cc1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00480cc2:
    // 00480cc2  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480cc4  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00480cc6  3c00                   +cmp al, 0
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
    // 00480cc8  7410                   -je 0x480cda
    if (cpu.flags.zf)
    {
        goto L_0x00480cda;
    }
    // 00480cca  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480ccd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480cd0  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00480cd3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480cd6  3c00                   +cmp al, 0
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
    // 00480cd8  75e8                   -jne 0x480cc2
    if (!cpu.flags.zf)
    {
        goto L_0x00480cc2;
    }
L_0x00480cda:
    // 00480cda  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480cdb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480cdd  7464                   -je 0x480d43
    if (cpu.flags.zf)
    {
        goto L_0x00480d43;
    }
    // 00480cdf  becce54b00             -mov esi, 0x4be5cc
    cpu.esi = 4974028 /*0x4be5cc*/;
L_0x00480ce4:
    // 00480ce4  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480ce6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480ce7  2bc9                   +sub ecx, ecx
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
    // 00480ce9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480cea  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00480cec  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00480cee  4f                     -dec edi
    (cpu.edi)--;
L_0x00480cef:
    // 00480cef  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480cf1  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00480cf3  3c00                   +cmp al, 0
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
    // 00480cf5  7410                   -je 0x480d07
    if (cpu.flags.zf)
    {
        goto L_0x00480d07;
    }
    // 00480cf7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480cfa  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480cfd  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00480d00  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480d03  3c00                   +cmp al, 0
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
    // 00480d05  75e8                   -jne 0x480cef
    if (!cpu.flags.zf)
    {
        goto L_0x00480cef;
    }
L_0x00480d07:
    // 00480d07  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d08  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480d0a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480d0c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00480d11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480d12  2bc9                   +sub ecx, ecx
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
    // 00480d14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480d15  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00480d17  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00480d19  4f                     -dec edi
    (cpu.edi)--;
L_0x00480d1a:
    // 00480d1a  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480d1c  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00480d1e  3c00                   +cmp al, 0
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
    // 00480d20  7410                   -je 0x480d32
    if (cpu.flags.zf)
    {
        goto L_0x00480d32;
    }
    // 00480d22  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00480d25  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480d28  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00480d2b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480d2e  3c00                   +cmp al, 0
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
    // 00480d30  75e8                   -jne 0x480d1a
    if (!cpu.flags.zf)
    {
        goto L_0x00480d1a;
    }
L_0x00480d32:
    // 00480d32  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d33  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480d35  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00480d37  e8e4020000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480d3c  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d3f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d40  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d41  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d43:
    // 00480d43  bed0e54b00             -mov esi, 0x4be5d0
    cpu.esi = 4974032 /*0x4be5d0*/;
    // 00480d48  eb9a                   -jmp 0x480ce4
    goto L_0x00480ce4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480d4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480d4c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480d4d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480d4e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480d4f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480d51  e8b6feffff             -call 0x480c0c
    cpu.esp -= 4;
    sub_480c0c(app, cpu);
    if (cpu.terminate) return;
    // 00480d56  bac8e54b00             -mov edx, 0x4be5c8
    cpu.edx = 4974024 /*0x4be5c8*/;
    // 00480d5b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480d5d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480d5f  e8bc020000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480d64  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480d6a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480d6c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480d6e  e889000000             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00480d73  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d74  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d75  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480d78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480d78  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480d79  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480d7a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480d7b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480d7d  e88afeffff             -call 0x480c0c
    cpu.esp -= 4;
    sub_480c0c(app, cpu);
    if (cpu.terminate) return;
    // 00480d82  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00480d87  bad4e54b00             -mov edx, 0x4be5d4
    cpu.edx = 4974036 /*0x4be5d4*/;
    // 00480d8c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480d8e  e88d020000             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00480d93  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d94  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d95  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480d98  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480d99  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480d9a  bbdce54b00             -mov ebx, 0x4be5dc
    cpu.ebx = 4974044 /*0x4be5dc*/;
    // 00480d9f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00480da4  e8a70e0000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00480da9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480daa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480dac  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480dad  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480dae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480db0  a134824c00             -mov eax, dword ptr [0x4c8234]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480db5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480db7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480dba  c1e202                 +shl edx, 2
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
    // 00480dbd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00480dbf  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00480dc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480dc4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480dc6  e831000000             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00480dcb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480dcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480dcf  741e                   -je 0x480def
    if (cpu.flags.zf)
    {
        goto L_0x00480def;
    }
    // 00480dd1  83f802                 +cmp eax, 2
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
    // 00480dd4  7419                   -je 0x480def
    if (cpu.flags.zf)
    {
        goto L_0x00480def;
    }
    // 00480dd6  83f8ff                 +cmp eax, -1
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
    // 00480dd9  7414                   -je 0x480def
    if (cpu.flags.zf)
    {
        goto L_0x00480def;
    }
    // 00480ddb  83f801                 +cmp eax, 1
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
    // 00480dde  740a                   -je 0x480dea
    if (cpu.flags.zf)
    {
        goto L_0x00480dea;
    }
    // 00480de0  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480de3  7405                   -je 0x480dea
    if (cpu.flags.zf)
    {
        goto L_0x00480dea;
    }
    // 00480de5  83f80a                 +cmp eax, 0xa
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
    // 00480de8  7c0a                   -jl 0x480df4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480df4;
    }
L_0x00480dea:
    // 00480dea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480dec  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ded  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480def:
    // 00480def  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480df1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480df2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480df3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480df4:
    // 00480df4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00480df9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dfa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480dfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480dfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480dfc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480dfd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480dfe  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480dff  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480e00  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480e01  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480e04  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00480e08  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00480e0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480e0c  8b1da08f4c00           -mov ebx, dword ptr [0x4c8fa0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */);
    // 00480e12  8954243c               -mov dword ptr [esp + 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00480e16  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480e18  7518                   -jne 0x480e32
    if (!cpu.flags.zf)
    {
        goto L_0x00480e32;
    }
    // 00480e1a  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00480e20  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480e22  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480e25  c1e202                 +shl edx, 2
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
    // 00480e28  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00480e2a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00480e2d  a3a08f4c00             -mov dword ptr [0x4c8fa0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */) = cpu.eax;
L_0x00480e32:
    // 00480e32  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00480e34  89359c904c00           -mov dword ptr [0x4c909c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5017756) /* 0x4c909c */) = cpu.esi;
    // 00480e3a  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00480e3f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00480e41  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00480e45  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00480e47  48                     -dec eax
    (cpu.eax)--;
    // 00480e48  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00480e4a  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x00480e4e:
    // 00480e4e  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00480e52  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00480e57  39f8                   +cmp eax, edi
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
    // 00480e59  7c0e                   -jl 0x480e69
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480e69;
    }
    // 00480e5b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00480e60  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480e63  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e64  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e65  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e66  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e67  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480e69:
    // 00480e69  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00480e6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480e6d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00480e72  e80972ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00480e77  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00480e7b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00480e7d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00480e7f  e8cc120000             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 00480e84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480e86  0f846b010000           -je 0x480ff7
    if (cpu.flags.zf)
    {
        goto L_0x00480ff7;
    }
    // 00480e8c  ff442434               -inc dword ptr [esp + 0x34]
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))++;
    // 00480e90  8a242c                 -mov ah, byte ptr [esp + ebp]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1);
    // 00480e93  45                     -inc ebp
    (cpu.ebp)++;
    // 00480e94  80fc20                 +cmp ah, 0x20
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
    // 00480e97  0f8384000000           -jae 0x480f21
    if (!cpu.flags.cf)
    {
        goto L_0x00480f21;
    }
    // 00480e9d  c6442cff5f             -mov byte ptr [esp + ebp - 1], 0x5f
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ebp * 1) = 95 /*0x5f*/;
L_0x00480ea2:
    // 00480ea2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00480ea4:
    // 00480ea4  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00480ea8  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00480eac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480eae  0f8489000000           -je 0x480f3d
    if (cpu.flags.zf)
    {
        goto L_0x00480f3d;
    }
L_0x00480eb4:
    // 00480eb4  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00480eb6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00480eb8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00480eba  883c2c                 -mov byte ptr [esp + ebp], bh
    *app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1) = cpu.bh;
L_0x00480ebd:
    // 00480ebd  8b0da0904c00           -mov ecx, dword ptr [0x4c90a0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5017760) /* 0x4c90a0 */);
    // 00480ec3  49                     -dec ecx
    (cpu.ecx)--;
    // 00480ec4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480ec6  0f8cc1000000           -jl 0x480f8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480f8d;
    }
    // 00480ecc  6bd90c                 -imul ebx, ecx, 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00480ecf  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00480ed1:
    // 00480ed1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00480ed3  8b93a88f4c00           -mov edx, dword ptr [ebx + 0x4c8fa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5017512) /* 0x4c8fa8 */);
    // 00480ed9  e829b10000             -call 0x48c007
    cpu.esp -= 4;
    sub_48c007(app, cpu);
    if (cpu.terminate) return;
    // 00480ede  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480ee0  0f849b000000           -je 0x480f81
    if (cpu.flags.zf)
    {
        goto L_0x00480f81;
    }
    // 00480ee6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480ee8  0f8e64000000           -jle 0x480f52
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480f52;
    }
    // 00480eee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00480ef3:
    // 00480ef3  8b1da4904c00           -mov ebx, dword ptr [0x4c90a4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017764) /* 0x4c90a4 */);
    // 00480ef9  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480efb  a1a08f4c00             -mov eax, dword ptr [0x4c8fa0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */);
    // 00480f00  891da4904c00           -mov dword ptr [0x4c90a4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5017764) /* 0x4c90a4 */) = cpu.ebx;
    // 00480f06  e80972ffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 00480f0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f0d  0f8d43000000           -jge 0x480f56
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480f56;
    }
L_0x00480f13:
    // 00480f13  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00480f18  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480f1b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f1c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f1d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f1e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f1f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480f21:
    // 00480f21  80fc30                 +cmp ah, 0x30
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480f24  0f8278ffffff           -jb 0x480ea2
    if (cpu.flags.cf)
    {
        goto L_0x00480ea2;
    }
    // 00480f2a  80fc39                 +cmp ah, 0x39
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480f2d  0f876fffffff           -ja 0x480ea2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480ea2;
    }
    // 00480f33  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480f38  e967ffffff             -jmp 0x480ea4
    goto L_0x00480ea4;
L_0x00480f3d:
    // 00480f3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f3f  0f846fffffff           -je 0x480eb4
    if (cpu.flags.zf)
    {
        goto L_0x00480eb4;
    }
    // 00480f45  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00480f49  8944243c               -mov dword ptr [esp + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00480f4d  e962ffffff             -jmp 0x480eb4
    goto L_0x00480eb4;
L_0x00480f52:
    // 00480f52  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480f54  eb9d                   -jmp 0x480ef3
    goto L_0x00480ef3;
L_0x00480f56:
    // 00480f56  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00480f5d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480f5f  8b1485a88f4c00         -mov edx, dword ptr [eax*4 + 0x4c8fa8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017512) /* 0x4c8fa8 */ + cpu.eax * 4);
    // 00480f66  8b0485b08f4c00         -mov eax, dword ptr [eax*4 + 0x4c8fb0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017520) /* 0x4c8fb0 */ + cpu.eax * 4);
    // 00480f6d  89159c904c00           -mov dword ptr [0x4c909c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5017756) /* 0x4c909c */) = cpu.edx;
    // 00480f73  e8bea40000             -call 0x48b436
    cpu.esp -= 4;
    sub_48b436(app, cpu);
    if (cpu.terminate) return;
    // 00480f78  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480f7b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f7c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f7d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f7e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f7f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480f81:
    // 00480f81  49                     -dec ecx
    (cpu.ecx)--;
    // 00480f82  83eb0c                 -sub ebx, 0xc
    (cpu.ebx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480f85  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480f87  0f8d44ffffff           -jge 0x480ed1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480ed1;
    }
L_0x00480f8d:
    // 00480f8d  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480f90  47                     -inc edi
    (cpu.edi)++;
    // 00480f91  83fe08                 +cmp esi, 8
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
    // 00480f94  0f8c23ffffff           -jl 0x480ebd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480ebd;
    }
    // 00480f9a  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00480f9e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480fa0  7455                   -je 0x480ff7
    if (cpu.flags.zf)
    {
        goto L_0x00480ff7;
    }
    // 00480fa2  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480fa7  754e                   -jne 0x480ff7
    if (!cpu.flags.zf)
    {
        goto L_0x00480ff7;
    }
    // 00480fa9  833da4904c0000         +cmp dword ptr [0x4c90a4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017764) /* 0x4c90a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480fb0  7445                   -je 0x480ff7
    if (cpu.flags.zf)
    {
        goto L_0x00480ff7;
    }
    // 00480fb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480fb4  e87da40000             -call 0x48b436
    cpu.esp -= 4;
    sub_48b436(app, cpu);
    if (cpu.terminate) return;
    // 00480fb9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480fbb  83f80a                 +cmp eax, 0xa
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
    // 00480fbe  7c4e                   -jl 0x48100e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048100e;
    }
    // 00480fc0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00480fc5:
    // 00480fc5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00480fcc  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480fce  8b0485a88f4c00         -mov eax, dword ptr [eax*4 + 0x4c8fa8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017512) /* 0x4c8fa8 */ + cpu.eax * 4);
    // 00480fd5  a39c904c00             -mov dword ptr [0x4c909c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017756) /* 0x4c909c */) = cpu.eax;
L_0x00480fda:
    // 00480fda  a1a08f4c00             -mov eax, dword ptr [0x4c8fa0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */);
    // 00480fdf  e83071ffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 00480fe4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480fe6  0f8c27ffffff           -jl 0x480f13
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480f13;
    }
    // 00480fec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480fee  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480ff1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ff2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ff3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ff4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ff5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ff6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480ff7:
    // 00480ff7  83fd29                 +cmp ebp, 0x29
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ffa  0f8c4efeffff           -jl 0x480e4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480e4e;
    }
    // 00481000  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00481005  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00481008  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481009  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048100d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048100e:
    // 0048100e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481010  7c04                   -jl 0x481016
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481016;
    }
    // 00481012  7db1                   -jge 0x480fc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480fc5;
    }
    // 00481014  ebc4                   -jmp 0x480fda
    goto L_0x00480fda;
L_0x00481016:
    // 00481016  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048101b  ebbd                   -jmp 0x480fda
    goto L_0x00480fda;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481020  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481021  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481022  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481023  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481024  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481027  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00481029  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048102c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048102e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481030  49                     -dec ecx
    (cpu.ecx)--;
    // 00481031  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481033  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00481035  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00481037  49                     -dec ecx
    (cpu.ecx)--;
    // 00481038  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048103a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048103c  891598904c00           -mov dword ptr [0x4c9098], edx
    *app->getMemory<x86::reg32>(x86::reg32(5017752) /* 0x4c9098 */) = cpu.edx;
    // 00481042  83f931                 +cmp ecx, 0x31
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481045  0f8fb5000000           -jg 0x481100
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00481100;
    }
    // 0048104b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048104d  7407                   -je 0x481056
    if (cpu.flags.zf)
    {
        goto L_0x00481056;
    }
    // 0048104f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481051  e85a080000             -call 0x4818b0
    cpu.esp -= 4;
    sub_4818b0(app, cpu);
    if (cpu.terminate) return;
L_0x00481056:
    // 00481056  a134824c00             -mov eax, dword ptr [0x4c8234]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048105b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048105d  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00481062  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00481065  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00481067  e8a870ffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 0048106c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048106e  0f8c8c000000           -jl 0x481100
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481100;
    }
    // 00481074  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481076  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00481079  e812080000             -call 0x481890
    cpu.esp -= 4;
    sub_481890(app, cpu);
    if (cpu.terminate) return;
    // 0048107e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00481080  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481082  e8c90b0000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00481087  bbe4e54b00             -mov ebx, 0x4be5e4
    cpu.ebx = 4974052 /*0x4be5e4*/;
    // 0048108c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00481091  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481093  e8b80b0000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00481098  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0048109d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048109f  a134824c00             -mov eax, dword ptr [0x4c8234]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 004810a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004810a6  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 004810ab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004810ae  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004810b0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004810b2  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004810b4:
    // 004810b4  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 004810b9  39f8                   +cmp eax, edi
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
    // 004810bb  7d4d                   -jge 0x48110a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048110a;
    }
    // 004810bd  833d98904c0000         +cmp dword ptr [0x4c9098], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017752) /* 0x4c9098 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004810c4  7544                   -jne 0x48110a
    if (!cpu.flags.zf)
    {
        goto L_0x0048110a;
    }
    // 004810c6  bbe4ba5100             -mov ebx, 0x51bae4
    cpu.ebx = 5356260 /*0x51bae4*/;
    // 004810cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004810cd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004810d2  e8a96fffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 004810d7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004810d9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004810db  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004810dd  e86e100000             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004810e2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004810e4  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004810e6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004810e9  88a6e4ba5100           -mov byte ptr [esi + 0x51bae4], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5356260) /* 0x51bae4 */) = cpu.ah;
    // 004810ef  b8e4ba5100             -mov eax, 0x51bae4
    cpu.eax = 5356260 /*0x51bae4*/;
    // 004810f4  e80eaf0000             -call 0x48c007
    cpu.esp -= 4;
    sub_48c007(app, cpu);
    if (cpu.terminate) return;
    // 004810f9  a398904c00             -mov dword ptr [0x4c9098], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017752) /* 0x4c9098 */) = cpu.eax;
    // 004810fe  ebb4                   -jmp 0x4810b4
    goto L_0x004810b4;
L_0x00481100:
    // 00481100  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481102  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481105  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481106  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481107  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481108  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481109  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048110a:
    // 0048110a  833d98904c0000         +cmp dword ptr [0x4c9098], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017752) /* 0x4c9098 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481111  74ed                   -je 0x481100
    if (cpu.flags.zf)
    {
        goto L_0x00481100;
    }
    // 00481113  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481118  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048111b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048111c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048111d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048111e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048111f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481120  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481121  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481122  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481123  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481124  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481125  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481127  833da08f4c0000         +cmp dword ptr [0x4c8fa0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048112e  7518                   -jne 0x481148
    if (!cpu.flags.zf)
    {
        goto L_0x00481148;
    }
    // 00481130  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00481136  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481138  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048113b  c1e202                 +shl edx, 2
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
    // 0048113e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00481140  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00481143  a3a08f4c00             -mov dword ptr [0x4c8fa0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */) = cpu.eax;
L_0x00481148:
    // 00481148  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048114e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00481155  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00481157  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481159  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048115c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048115e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00481160  e8af6fffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 00481165  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481167  7d08                   -jge 0x481171
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481171;
    }
L_0x00481169:
    // 00481169  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048116b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048116c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048116d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048116e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048116f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481170  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481171:
    // 00481171  bbe8e54b00             -mov ebx, 0x4be5e8
    cpu.ebx = 4974056 /*0x4be5e8*/;
    // 00481176  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048117b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048117d  e8ce0a0000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00481182  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00481188  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048118f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00481191  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481193  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00481196  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00481198  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048119a  e8756fffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 0048119f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004811a1  7cc6                   -jl 0x481169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481169;
    }
    // 004811a3  8b1da48f4c00           -mov ebx, dword ptr [0x4c8fa4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017508) /* 0x4c8fa4 */);
    // 004811a9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004811ab  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004811ad  49                     -dec ecx
    (cpu.ecx)--;
    // 004811ae  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004811b0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004811b2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004811b4  49                     -dec ecx
    (cpu.ecx)--;
    // 004811b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004811b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004811b9  e8920a0000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 004811be  a1a08f4c00             -mov eax, dword ptr [0x4c8fa0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017504) /* 0x4c8fa0 */);
    // 004811c3  e84c6fffff             -call 0x478114
    cpu.esp -= 4;
    sub_478114(app, cpu);
    if (cpu.terminate) return;
    // 004811c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004811ca  7c9d                   -jl 0x481169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481169;
    }
    // 004811cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004811ce  baece54b00             -mov edx, 0x4be5ec
    cpu.edx = 4974060 /*0x4be5ec*/;
    // 004811d3  e8b8060000             -call 0x481890
    cpu.esp -= 4;
    sub_481890(app, cpu);
    if (cpu.terminate) return;
    // 004811d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004811da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004811dc  e83ffeffff             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 004811e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004811e3  7484                   -je 0x481169
    if (cpu.flags.zf)
    {
        goto L_0x00481169;
    }
    // 004811e5  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 004811eb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004811ed  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004811ef  e808fcffff             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 004811f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004811f6  0f856dffffff           -jne 0x481169
    if (!cpu.flags.zf)
    {
        goto L_0x00481169;
    }
    // 004811fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481201  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481202  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481203  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481204  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481205  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481206  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481208(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481208  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481209  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048120a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048120b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048120d  baf0e54b00             -mov edx, 0x4be5f0
    cpu.edx = 4974064 /*0x4be5f0*/;
    // 00481212  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481214  e807feffff             -call 0x481020
    cpu.esp -= 4;
    sub_481020(app, cpu);
    if (cpu.terminate) return;
    // 00481219  8b1534824c00           -mov edx, dword ptr [0x4c8234]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0048121f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481221  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481223  e8d4fbffff             -call 0x480dfc
    cpu.esp -= 4;
    sub_480dfc(app, cpu);
    if (cpu.terminate) return;
    // 00481228  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481229  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048122a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048122b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_481230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481230  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481231  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481233  833da8904c0000         +cmp dword ptr [0x4c90a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048123a  7416                   -je 0x481252
    if (cpu.flags.zf)
    {
        goto L_0x00481252;
    }
L_0x0048123c:
    // 0048123c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048123e  42                     -inc edx
    (cpu.edx)++;
    // 0048123f  e88c060000             -call 0x4818d0
    cpu.esp -= 4;
    sub_4818d0(app, cpu);
    if (cpu.terminate) return;
    // 00481244  83fa10                 +cmp edx, 0x10
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
    // 00481247  7d09                   -jge 0x481252
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481252;
    }
    // 00481249  833da8904c0000         +cmp dword ptr [0x4c90a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481250  75ea                   -jne 0x48123c
    if (!cpu.flags.zf)
    {
        goto L_0x0048123c;
    }
L_0x00481252:
    // 00481252  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481253  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481254  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481255  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481257  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048125c  e8a7ddffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481261  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00481268  8b8820bb5100           -mov ecx, dword ptr [eax + 0x51bb20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5356320) /* 0x51bb20 */);
    // 0048126e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481270  750c                   -jne 0x48127e
    if (!cpu.flags.zf)
    {
        goto L_0x0048127e;
    }
    // 00481272  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481277  e8a4ddffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048127c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048127d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048127e:
    // 0048127e  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00481280  8b15ac904c00           -mov edx, dword ptr [0x4c90ac]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017772) /* 0x4c90ac */);
    // 00481286  b860bb5100             -mov eax, 0x51bb60
    cpu.eax = 5356384 /*0x51bb60*/;
    // 0048128b  e850dcffff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00481290  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481295  e886ddffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048129a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048129b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48129c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048129c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048129d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048129e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048129f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004812a0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004812a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004812a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004812a4  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004812a9  e85addffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004812ae  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004812b2  7518                   -jne 0x4812cc
    if (!cpu.flags.zf)
    {
        goto L_0x004812cc;
    }
    // 004812b4  8d7318                 -lea esi, [ebx + 0x18]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004812b7  8d6b14                 -lea ebp, [ebx + 0x14]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004812ba  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
L_0x004812bd:
    // 004812bd  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004812c0  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004812c6  0f8cbb000000           -jl 0x481387
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481387;
    }
L_0x004812cc:
    // 004812cc  8dbb3c020000           -lea edi, [ebx + 0x23c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 004812d2  8dab38020000           -lea ebp, [ebx + 0x238]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 004812d8  8db350020000           -lea esi, [ebx + 0x250]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(592) /* 0x250 */);
L_0x004812de:
    // 004812de  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004812e5  0f854c010000           -jne 0x481437
    if (!cpu.flags.zf)
    {
        goto L_0x00481437;
    }
    // 004812eb  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 004812f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004812f3  0f8e3e010000           -jle 0x481437
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481437;
    }
    // 004812f9  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 004812ff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481301  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481307  0f8e03010000           -jle 0x481410
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481410;
    }
    // 0048130d  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 00481312  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481314:
    // 00481314  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481315  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481316  c7833c02000000000000   -mov dword ptr [ebx + 0x23c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(572) /* 0x23c */) = 0 /*0x0*/;
    // 00481320  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481321  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00481323  c7834002000000000000   -mov dword ptr [ebx + 0x240], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = 0 /*0x0*/;
    // 0048132d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048132e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00481331  c7834402000000000000   -mov dword ptr [ebx + 0x244], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(580) /* 0x244 */) = 0 /*0x0*/;
    // 0048133b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048133c  c7834802000000000000   -mov dword ptr [ebx + 0x248], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(584) /* 0x248 */) = 0 /*0x0*/;
    // 00481346  2eff15b0554b00         -call dword ptr cs:[0x4b55b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937136) /* 0x4b55b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048134d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048134f  0f84c6000000           -je 0x48141b
    if (cpu.flags.zf)
    {
        goto L_0x0048141b;
    }
    // 00481355  8b8338020000           -mov eax, dword ptr [ebx + 0x238]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048135b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 00481361  8b8b38020000           -mov ecx, dword ptr [ebx + 0x238]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 00481367  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481369  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048136f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00481371  899334020000           -mov dword ptr [ebx + 0x234], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edx;
    // 00481377  25ff010000             +and eax, 0x1ff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/))));
    // 0048137c  898330020000           -mov dword ptr [ebx + 0x230], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 00481382  e957ffffff             -jmp 0x4812de
    goto L_0x004812de;
L_0x00481387:
    // 00481387  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048138a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048138c  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00481391  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00481394  39d0                   +cmp eax, edx
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
    // 00481396  7d4e                   -jge 0x4813e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004813e6;
    }
L_0x00481398:
    // 00481398  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048139a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048139b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048139c  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004813a3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004813a4  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004813a6  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004813ad  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004813ae  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004813b1  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004813b8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004813b9  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004813c0  2eff1530554b00         -call dword ptr cs:[0x4b5530]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937008) /* 0x4b5530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004813c9  7422                   -je 0x4813ed
    if (cpu.flags.zf)
    {
        goto L_0x004813ed;
    }
    // 004813cb  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004813ce  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004813d1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004813d3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004813d6  894b10                 -mov dword ptr [ebx + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004813d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004813db  0f84dcfeffff           -je 0x4812bd
    if (cpu.flags.zf)
    {
        goto L_0x004812bd;
    }
    // 004813e1  e9e6feffff             -jmp 0x4812cc
    goto L_0x004812cc;
L_0x004813e6:
    // 004813e6  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 004813eb  ebab                   -jmp 0x481398
    goto L_0x00481398;
L_0x004813ed:
    // 004813ed  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004813f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004813f6  750c                   -jne 0x481404
    if (!cpu.flags.zf)
    {
        goto L_0x00481404;
    }
L_0x004813f8:
    // 004813f8  c7430801000000         -mov dword ptr [ebx + 8], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 004813ff  e9c8feffff             -jmp 0x4812cc
    goto L_0x004812cc;
L_0x00481404:
    // 00481404  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481409  74ed                   -je 0x4813f8
    if (cpu.flags.zf)
    {
        goto L_0x004813f8;
    }
    // 0048140b  e9bcfeffff             -jmp 0x4812cc
    goto L_0x004812cc;
L_0x00481410:
    // 00481410  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 00481416  e9f9feffff             -jmp 0x481314
    goto L_0x00481314;
L_0x0048141b:
    // 0048141b  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481422  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481424  7407                   -je 0x48142d
    if (cpu.flags.zf)
    {
        goto L_0x0048142d;
    }
    // 00481426  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048142b  750a                   -jne 0x481437
    if (!cpu.flags.zf)
    {
        goto L_0x00481437;
    }
L_0x0048142d:
    // 0048142d  c7832c02000001000000   -mov dword ptr [ebx + 0x22c], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 1 /*0x1*/;
L_0x00481437:
    // 00481437  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048143c  e8dfdbffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481441  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481442  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481443  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481444  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481445  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481446  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481447  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481448  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481449  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048144a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048144b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048144e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481450  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481455  e8aedbffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048145a  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048145e  751e                   -jne 0x48147e
    if (!cpu.flags.zf)
    {
        goto L_0x0048147e;
    }
L_0x00481460:
    // 00481460  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481467  0f856e000000           -jne 0x4814db
    if (!cpu.flags.zf)
    {
        goto L_0x004814db;
    }
L_0x0048146d:
    // 0048146d  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481472  e8a9dbffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481477  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048147a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048147d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048147e:
    // 0048147e  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00481481  e866daffff             -call 0x47eeec
    cpu.esp -= 4;
    sub_47eeec(app, cpu);
    if (cpu.terminate) return;
    // 00481486  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481488  74d6                   -je 0x481460
    if (cpu.flags.zf)
    {
        goto L_0x00481460;
    }
    // 0048148a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048148c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00481490  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481491  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00481494  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481495  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00481498  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481499  2eff15e0544b00         -call dword ptr cs:[0x4b54e0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936928) /* 0x4b54e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004814a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004814a2  7418                   -je 0x4814bc
    if (cpu.flags.zf)
    {
        goto L_0x004814bc;
    }
    // 004814a4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004814a5  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004814a9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004814ab  750a                   -jne 0x4814b7
    if (!cpu.flags.zf)
    {
        goto L_0x004814b7;
    }
L_0x004814ad:
    // 004814ad  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004814b4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004814b5  eba9                   -jmp 0x481460
    goto L_0x00481460;
L_0x004814b7:
    // 004814b7  017310                 +add dword ptr [ebx + 0x10], esi
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004814ba  ebf1                   -jmp 0x4814ad
    goto L_0x004814ad;
L_0x004814bc:
    // 004814bc  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004814c3  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004814c8  750a                   -jne 0x4814d4
    if (!cpu.flags.zf)
    {
        goto L_0x004814d4;
    }
    // 004814ca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004814cf  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004814d2  eb8c                   -jmp 0x481460
    goto L_0x00481460;
L_0x004814d4:
    // 004814d4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004814d6  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004814d9  eb85                   -jmp 0x481460
    goto L_0x00481460;
L_0x004814db:
    // 004814db  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 004814e1  e806daffff             -call 0x47eeec
    cpu.esp -= 4;
    sub_47eeec(app, cpu);
    if (cpu.terminate) return;
    // 004814e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004814e8  7483                   -je 0x48146d
    if (cpu.flags.zf)
    {
        goto L_0x0048146d;
    }
    // 004814ea  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004814ec  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004814f0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004814f1  8d833c020000           -lea eax, [ebx + 0x23c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 004814f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004814f8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004814fb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004814fc  2eff15e0544b00         -call dword ptr cs:[0x4b54e0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936928) /* 0x4b54e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481503  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481505  743c                   -je 0x481543
    if (cpu.flags.zf)
    {
        goto L_0x00481543;
    }
    // 00481507  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048150a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048150c  741a                   -je 0x481528
    if (cpu.flags.zf)
    {
        goto L_0x00481528;
    }
    // 0048150e  299334020000           -sub dword ptr [ebx + 0x234], edx
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00481514  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048151a  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 0048151d  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00481522  898330020000           -mov dword ptr [ebx + 0x230], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
L_0x00481528:
    // 00481528  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 00481532  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481537  e8e4daffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048153c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048153f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481540  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481541  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481542  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481543:
    // 00481543  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048154a  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048154f  751c                   -jne 0x48156d
    if (!cpu.flags.zf)
    {
        goto L_0x0048156d;
    }
    // 00481551  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00481556:
    // 00481556  89832c020000           -mov dword ptr [ebx + 0x22c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = cpu.eax;
    // 0048155c  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481561  e8badaffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481566  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481569  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048156c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048156d:
    // 0048156d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048156f  ebe5                   -jmp 0x481556
    goto L_0x00481556;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481574(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481574  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481575  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481576  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481577  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048157d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00481582  a1ac904c00             -mov eax, dword ptr [0x4c90ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017772) /* 0x4c90ac */);
    // 00481587  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048158a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048158c:
    // 0048158c  8b9020bb5100           -mov edx, dword ptr [eax + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5356320) /* 0x51bb20 */);
    // 00481592  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481594  7422                   -je 0x4815b8
    if (cpu.flags.zf)
    {
        goto L_0x004815b8;
    }
    // 00481596  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048159a  7408                   -je 0x4815a4
    if (cpu.flags.zf)
    {
        goto L_0x004815a4;
    }
    // 0048159c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048159d  8b5a28                 -mov ebx, dword ptr [edx + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 004815a0  895c8cfc               -mov dword ptr [esp + ecx*4 - 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.ebx;
L_0x004815a4:
    // 004815a4  83ba2c02000000         +cmp dword ptr [edx + 0x22c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004815ab  740b                   -je 0x4815b8
    if (cpu.flags.zf)
    {
        goto L_0x004815b8;
    }
    // 004815ad  41                     -inc ecx
    (cpu.ecx)++;
    // 004815ae  8b924c020000           -mov edx, dword ptr [edx + 0x24c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(588) /* 0x24c */);
    // 004815b4  89548cfc               -mov dword ptr [esp + ecx*4 - 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.edx;
L_0x004815b8:
    // 004815b8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004815bb  83f840                 +cmp eax, 0x40
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
    // 004815be  75cc                   -jne 0x48158c
    if (!cpu.flags.zf)
    {
        goto L_0x0048158c;
    }
    // 004815c0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004815c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004815c4  e8cfd9ffff             -call 0x47ef98
    cpu.esp -= 4;
    sub_47ef98(app, cpu);
    if (cpu.terminate) return;
    // 004815c9  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 004815cf  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815d0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815d1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004815d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4815d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004815d4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004815d5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004815d6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004815d7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004815d8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004815d9  e8eed8ffff             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 004815de  a3ac904c00             -mov dword ptr [0x4c90ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017772) /* 0x4c90ac */) = cpu.eax;
    // 004815e3  833da8904c0000         +cmp dword ptr [0x4c90a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004815ea  0f8479000000           -je 0x481669
    if (cpu.flags.zf)
    {
        goto L_0x00481669;
    }
    // 004815f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004815f2:
    // 004815f2  e87dffffff             -call 0x481574
    cpu.esp -= 4;
    sub_481574(app, cpu);
    if (cpu.terminate) return;
    // 004815f7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004815f9:
    // 004815f9  8b9e20bb5100           -mov ebx, dword ptr [esi + 0x51bb20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5356320) /* 0x51bb20 */);
    // 004815ff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481601  7456                   -je 0x481659
    if (cpu.flags.zf)
    {
        goto L_0x00481659;
    }
    // 00481603  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481605  e83efeffff             -call 0x481448
    cpu.esp -= 4;
    sub_481448(app, cpu);
    if (cpu.terminate) return;
    // 0048160a  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048160c  743c                   -je 0x48164a
    if (cpu.flags.zf)
    {
        goto L_0x0048164a;
    }
    // 0048160e  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481613  e8f0d9ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481618  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0048161a  83f803                 +cmp eax, 3
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
    // 0048161d  7362                   -jae 0x481681
    if (!cpu.flags.cf)
    {
        goto L_0x00481681;
    }
    // 0048161f  83f802                 +cmp eax, 2
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
    // 00481622  751a                   -jne 0x48163e
    if (!cpu.flags.zf)
    {
        goto L_0x0048163e;
    }
    // 00481624  6a0a                   -push 0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00481626  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00481629  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048162a  2eff1528554b00         -call dword ptr cs:[0x4b5528]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937000) /* 0x4b5528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481631  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481633  e810feffff             -call 0x481448
    cpu.esp -= 4;
    sub_481448(app, cpu);
    if (cpu.terminate) return;
    // 00481638  897b0c                 -mov dword ptr [ebx + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048163b  897b10                 -mov dword ptr [ebx + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048163e:
    // 0048163e  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00481640  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481645  e8d6d9ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x0048164a:
    // 0048164a  3bbe20bb5100           +cmp edi, dword ptr [esi + 0x51bb20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5356320) /* 0x51bb20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481650  7407                   -je 0x481659
    if (cpu.flags.zf)
    {
        goto L_0x00481659;
    }
    // 00481652  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481654  e843fcffff             -call 0x48129c
    cpu.esp -= 4;
    sub_48129c(app, cpu);
    if (cpu.terminate) return;
L_0x00481659:
    // 00481659  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048165c  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048165f  7598                   -jne 0x4815f9
    if (!cpu.flags.zf)
    {
        goto L_0x004815f9;
    }
    // 00481661  3b3da8904c00           +cmp edi, dword ptr [0x4c90a8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481667  7589                   -jne 0x4815f2
    if (!cpu.flags.zf)
    {
        goto L_0x004815f2;
    }
L_0x00481669:
    // 00481669  a1ac904c00             -mov eax, dword ptr [0x4c90ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017772) /* 0x4c90ac */);
    // 0048166e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00481670  e833d9ffff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00481675  891dac904c00           -mov dword ptr [0x4c90ac], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5017772) /* 0x4c90ac */) = cpu.ebx;
    // 0048167b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048167c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048167d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048167e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048167f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481680  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481681:
    // 00481681  7642                   -jbe 0x4816c5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004816c5;
    }
    // 00481683  83f804                 +cmp eax, 4
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
    // 00481686  75b6                   -jne 0x48163e
    if (!cpu.flags.zf)
    {
        goto L_0x0048163e;
    }
    // 00481688  6a0f                   -push 0xf
    *app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0048168a  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048168d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048168e  2eff1528554b00         -call dword ptr cs:[0x4b5528]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937000) /* 0x4b5528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481695  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481697  e8acfdffff             -call 0x481448
    cpu.esp -= 4;
    sub_481448(app, cpu);
    if (cpu.terminate) return;
    // 0048169c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048169f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004816a0  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004816a7  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004816aa  e8f9d8ffff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 004816af  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 004816b5  e8eed8ffff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 004816ba  89be20bb5100           -mov dword ptr [esi + 0x51bb20], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5356320) /* 0x51bb20 */) = cpu.edi;
    // 004816c0  e979ffffff             -jmp 0x48163e
    goto L_0x0048163e;
L_0x004816c5:
    // 004816c5  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004816c7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004816ca  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004816cb  2eff1528554b00         -call dword ptr cs:[0x4b5528]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937000) /* 0x4b5528 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004816d2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004816d4  e86ffdffff             -call 0x481448
    cpu.esp -= 4;
    sub_481448(app, cpu);
    if (cpu.terminate) return;
    // 004816d9  89bb30020000           -mov dword ptr [ebx + 0x230], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.edi;
    // 004816df  89bb34020000           -mov dword ptr [ebx + 0x234], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edi;
    // 004816e5  e954ffffff             -jmp 0x48163e
    goto L_0x0048163e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4816ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004816ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004816ee  7c10                   -jl 0x481700
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481700;
    }
    // 004816f0  83f810                 +cmp eax, 0x10
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
    // 004816f3  7d0b                   -jge 0x481700
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481700;
    }
    // 004816f5  833c8520bb510000       +cmp dword ptr [eax*4 + 0x51bb20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004816fd  7504                   -jne 0x481703
    if (!cpu.flags.zf)
    {
        goto L_0x00481703;
    }
    // 004816ff  90                     -nop 
    ;
L_0x00481700:
    // 00481700  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481702  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481703:
    // 00481703  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00481708  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48170c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048170c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048170d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048170e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048170f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481711  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481718  750a                   -jne 0x481724
    if (!cpu.flags.zf)
    {
        goto L_0x00481724;
    }
    // 0048171a  e899d8ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0048171f  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481724:
    // 00481724  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481729  e8dad8ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048172e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481730  e8b7ffffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481735  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481737  750e                   -jne 0x481747
    if (!cpu.flags.zf)
    {
        goto L_0x00481747;
    }
L_0x00481739:
    // 00481739  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048173e  e8ddd8ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481743  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481744  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481745  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481746  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481747:
    // 00481747  8b049520bb5100         -mov eax, dword ptr [edx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 0048174e  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00481750  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481753  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481754  2eff1550544b00         -call dword ptr cs:[0x4b5450]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936784) /* 0x4b5450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048175b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048175d  75da                   -jne 0x481739
    if (!cpu.flags.zf)
    {
        goto L_0x00481739;
    }
    // 0048175f  e834d9ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
    // 00481764  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481769  e8b2d8ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048176e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048176f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481770  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481771  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481774(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481774  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481775  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481776  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481777  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481779  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481780  750a                   -jne 0x48178c
    if (!cpu.flags.zf)
    {
        goto L_0x0048178c;
    }
    // 00481782  e831d8ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481787  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x0048178c:
    // 0048178c  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481791  e872d8ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481796  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481798  e84fffffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 0048179d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048179f  750e                   -jne 0x4817af
    if (!cpu.flags.zf)
    {
        goto L_0x004817af;
    }
L_0x004817a1:
    // 004817a1  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004817a6  e875d8ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004817ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004817af:
    // 004817af  8b049520bb5100         -mov eax, dword ptr [edx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 004817b6  6a06                   -push 6
    *app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004817b8  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004817bb  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004817bc  2eff1550544b00         -call dword ptr cs:[0x4b5450]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936784) /* 0x4b5450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004817c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004817c5  75da                   -jne 0x4817a1
    if (!cpu.flags.zf)
    {
        goto L_0x004817a1;
    }
    // 004817c7  e8ccd8ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
    // 004817cc  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004817d1  e84ad8ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004817d6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817d7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817d8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004817d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4817dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004817dc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004817dd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004817de  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004817df  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004817e0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004817e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004817e5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004817ea  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004817f1  750a                   -jne 0x4817fd
    if (!cpu.flags.zf)
    {
        goto L_0x004817fd;
    }
    // 004817f3  e8c0d7ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 004817f8  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x004817fd:
    // 004817fd  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481802  e801d8ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481807  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481809  e8defeffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 0048180e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481810  7514                   -jne 0x481826
    if (!cpu.flags.zf)
    {
        goto L_0x00481826;
    }
    // 00481812  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481817  e804d8ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048181c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048181e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481821  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481822  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481823  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481824  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481825  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481826:
    // 00481826  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481828  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481829  8b049520bb5100         -mov eax, dword ptr [edx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 00481830  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481833  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481834  2eff1578544b00         -call dword ptr cs:[0x4b5478]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936824) /* 0x4b5478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048183b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048183d  751f                   -jne 0x48185e
    if (!cpu.flags.zf)
    {
        goto L_0x0048185e;
    }
    // 0048183f  f6042480               +test byte ptr [esp], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp) & 128 /*0x80*/));
    // 00481843  7432                   -je 0x481877
    if (cpu.flags.zf)
    {
        goto L_0x00481877;
    }
    // 00481845  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048184a  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048184f  e8ccd7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481854  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481856  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481859  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048185a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048185b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048185c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048185d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048185e:
    // 0048185e  e835d8ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
    // 00481863  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481868  e8b3d7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048186d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048186f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481872  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481873  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481874  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481875  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481876  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481877:
    // 00481877  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481879  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048187e  e89dd7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481883  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481885  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481888  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481889  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048188a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048188b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048188c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481890  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481891  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481893  e854feffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481898  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048189a  7502                   -jne 0x48189e
    if (!cpu.flags.zf)
    {
        goto L_0x0048189e;
    }
    // 0048189c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048189d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048189e:
    // 0048189e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048189f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004818a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004818a6  e8a9f9ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 004818ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4818b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004818b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004818b3  e834feffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 004818b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004818ba  7502                   -jne 0x4818be
    if (!cpu.flags.zf)
    {
        goto L_0x004818be;
    }
    // 004818bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004818be:
    // 004818be  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004818bf  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004818c4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004818c6  e889f9ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 004818cb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818cc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004818cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4818d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004818d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004818d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004818d2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004818d4  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004818db  0f8480000000           -je 0x481961
    if (cpu.flags.zf)
    {
        goto L_0x00481961;
    }
L_0x004818e1:
    // 004818e1  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004818e6  e81dd7ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004818eb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004818ed  e8fafdffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 004818f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004818f4  0f8476000000           -je 0x481970
    if (cpu.flags.zf)
    {
        goto L_0x00481970;
    }
    // 004818fa  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004818fb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004818fc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004818fd  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00481904  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00481909  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048190b  8bb320bb5100           -mov esi, dword ptr [ebx + 0x51bb20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356320) /* 0x51bb20 */);
    // 00481911  e83ef9ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 00481916  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048191b  e800d7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481920  8bbb20bb5100           -mov edi, dword ptr [ebx + 0x51bb20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356320) /* 0x51bb20 */);
    // 00481926  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00481928  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048192a  7418                   -je 0x481944
    if (cpu.flags.zf)
    {
        goto L_0x00481944;
    }
    // 0048192c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00481931:
    // 00481931  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481933  e824d3ffff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00481938  83ba20bb510000         +cmp dword ptr [edx + 0x51bb20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5356320) /* 0x51bb20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048193f  75f0                   -jne 0x481931
    if (!cpu.flags.zf)
    {
        goto L_0x00481931;
    }
    // 00481941  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00481944:
    // 00481944  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481946  e88171ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0048194b  ff0da8904c00           -dec dword ptr [0x4c90a8]
    (*app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */))--;
    // 00481951  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481952  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481953  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481954  8b15a8904c00           -mov edx, dword ptr [0x4c90a8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
    // 0048195a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048195c  7429                   -je 0x481987
    if (cpu.flags.zf)
    {
        goto L_0x00481987;
    }
    // 0048195e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048195f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481960  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481961:
    // 00481961  e852d6ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481966  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
    // 0048196b  e971ffffff             -jmp 0x4818e1
    goto L_0x004818e1;
L_0x00481970:
    // 00481970  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481975  e8a6d6ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048197a  8b15a8904c00           -mov edx, dword ptr [0x4c90a8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
    // 00481980  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481982  7403                   -je 0x481987
    if (cpu.flags.zf)
    {
        goto L_0x00481987;
    }
    // 00481984  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481985  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481986  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481987:
    // 00481987  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481989  e8c6f8ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 0048198e  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481993  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481995  e89ad6ffff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 0048199a  890db0904c00           -mov dword ptr [0x4c90b0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.ecx;
    // 004819a0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004819a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4819a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004819a4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004819a5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004819a6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004819a7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004819a8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004819a9  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004819ac  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004819ae  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004819b0  83f8ff                 +cmp eax, -1
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
    // 004819b3  752e                   -jne 0x4819e3
    if (!cpu.flags.zf)
    {
        goto L_0x004819e3;
    }
    // 004819b5  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 004819ba  8b155cbb5100           -mov edx, dword ptr [0x51bb5c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356380) /* 0x51bb5c */);
    // 004819c0  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 004819c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004819c7  7412                   -je 0x4819db
    if (cpu.flags.zf)
    {
        goto L_0x004819db;
    }
L_0x004819c9:
    // 004819c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004819cb  7c0e                   -jl 0x4819db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004819db;
    }
    // 004819cd  8b881cbb5100           -mov ecx, dword ptr [eax + 0x51bb1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5356316) /* 0x51bb1c */);
    // 004819d3  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004819d6  4e                     -dec esi
    (cpu.esi)--;
    // 004819d7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004819d9  75ee                   -jne 0x4819c9
    if (!cpu.flags.zf)
    {
        goto L_0x004819c9;
    }
L_0x004819db:
    // 004819db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004819dd  0f8ccf000000           -jl 0x481ab2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00481ab2;
    }
L_0x004819e3:
    // 004819e3  ff05a8904c00           -inc dword ptr [0x4c90a8]
    (*app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */))++;
    // 004819e9  833da8904c0001         +cmp dword ptr [0x4c90a8], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004819f0  0f84ca000000           -je 0x481ac0
    if (cpu.flags.zf)
    {
        goto L_0x00481ac0;
    }
L_0x004819f6:
    // 004819f6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004819fb  ba50040000             -mov edx, 0x450
    cpu.edx = 1104 /*0x450*/;
    // 00481a00  b8f8e54b00             -mov eax, 0x4be5f8
    cpu.eax = 4974072 /*0x4be5f8*/;
    // 00481a05  e85e6cffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00481a0a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a0c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a0e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481a10  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481a12  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00481a19  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a1b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00481a1d  897804                 -mov dword ptr [eax + 4], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00481a20  2eff1528544b00         -call dword ptr cs:[0x4b5428]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936744) /* 0x4b5428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481a27  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a29  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00481a30  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a32  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00481a39  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00481a3b  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 00481a45  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481a47  894328                 -mov dword ptr [ebx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00481a4a  2eff1528544b00         -call dword ptr cs:[0x4b5428]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936744) /* 0x4b5428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481a51  c7833002000000000000   -mov dword ptr [ebx + 0x230], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = 0 /*0x0*/;
    // 00481a5b  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00481a60  89834c020000           -mov dword ptr [ebx + 0x24c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */) = cpu.eax;
    // 00481a66  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481a68  c7833402000000000000   -mov dword ptr [ebx + 0x234], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = 0 /*0x0*/;
    // 00481a72  e865d6ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00481a77  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481a79  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481a7a  ba19000000             -mov edx, 0x19
    cpu.edx = 25 /*0x19*/;
    // 00481a7f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481a80  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00481a84  2eff153c554b00         -call dword ptr cs:[0x4b553c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937020) /* 0x4b553c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481a8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481a8d  7505                   -jne 0x481a94
    if (!cpu.flags.zf)
    {
        goto L_0x00481a94;
    }
    // 00481a8f  e804d6ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
L_0x00481a94:
    // 00481a94  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00481a99  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481a9b  892cb520bb5100         -mov dword ptr [esi*4 + 0x51bb20], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.esi * 4) = cpu.ebp;
    // 00481aa2  e8adf7ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 00481aa7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481aa9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481aac  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481aad  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481aae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481aaf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ab0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481ab1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ab2:
    // 00481ab2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00481ab7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481aba  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481abf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481ac0:
    // 00481ac0  b830124800             -mov eax, 0x481230
    cpu.eax = 4723248 /*0x481230*/;
    // 00481ac5  e8529b0000             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 00481aca  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ad1  750a                   -jne 0x481add
    if (!cpu.flags.zf)
    {
        goto L_0x00481add;
    }
    // 00481ad3  e8e0d4ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481ad8  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481add:
    // 00481add  6860bb5100             -push 0x51bb60
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5356384 /*0x51bb60*/;
    cpu.esp -= 4;
    // 00481ae2  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00481ae7  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00481aec  b8d4154800             -mov eax, 0x4815d4
    cpu.eax = 4724180 /*0x4815d4*/;
    // 00481af1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481af3  e8a8d0ffff             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 00481af8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481afa  0f85f6feffff           -jne 0x4819f6
    if (!cpu.flags.zf)
    {
        goto L_0x004819f6;
    }
    // 00481b00  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481b05  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481b07  e828d5ffff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 00481b0c  890db0904c00           -mov dword ptr [0x4c90b0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.ecx;
    // 00481b12  a1a8904c00             -mov eax, dword ptr [0x4c90a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */);
    // 00481b17  ff0da8904c00           -dec dword ptr [0x4c90a8]
    (*app->getMemory<x86::reg32>(x86::reg32(5017768) /* 0x4c90a8 */))--;
    // 00481b1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00481b22  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00481b25  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b26  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b27  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b28  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b29  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481b2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b2c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481b2d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481b2e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481b2f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481b32  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00481b34  8b148520bb5100         -mov edx, dword ptr [eax*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.eax * 4);
    // 00481b3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00481b3d  7407                   -je 0x481b46
    if (cpu.flags.zf)
    {
        goto L_0x00481b46;
    }
    // 00481b3f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481b42  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b43  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b44  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481b46:
    // 00481b46  40                     -inc eax
    (cpu.eax)++;
    // 00481b47  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b48  6804e64b00             -push 0x4be604
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4974084 /*0x4be604*/;
    cpu.esp -= 4;
    // 00481b4d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481b51  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b52  e8ca88ffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00481b57  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00481b5a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481b5b  6880000040             -push 0x40000080
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1073741952 /*0x40000080*/;
    cpu.esp -= 4;
    // 00481b60  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00481b62  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481b63  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481b64  68000000c0             -push 0xc0000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3221225472 /*0xc0000000*/;
    cpu.esp -= 4;
    // 00481b69  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00481b6d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481b6e  2eff152c544b00         -call dword ptr cs:[0x4b542c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936748) /* 0x4b542c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481b75  83f8ff                 +cmp eax, -1
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
    // 00481b78  7410                   -je 0x481b8a
    if (cpu.flags.zf)
    {
        goto L_0x00481b8a;
    }
    // 00481b7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481b7c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481b7e  e821feffff             -call 0x4819a4
    cpu.esp -= 4;
    sub_4819a4(app, cpu);
    if (cpu.terminate) return;
    // 00481b83  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481b86  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b87  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b88  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b89  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481b8a:
    // 00481b8a  e809d5ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
    // 00481b8f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481b92  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b93  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b94  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481b95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481b98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481b98  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481b99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481b9b  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ba2  750a                   -jne 0x481bae
    if (!cpu.flags.zf)
    {
        goto L_0x00481bae;
    }
    // 00481ba4  e80fd4ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481ba9  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481bae:
    // 00481bae  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481bb3  e850d4ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481bb8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481bba  e82dfbffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481bbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481bc1  740b                   -je 0x481bce
    if (cpu.flags.zf)
    {
        goto L_0x00481bce;
    }
    // 00481bc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481bc5  e822030000             -call 0x481eec
    cpu.esp -= 4;
    sub_481eec(app, cpu);
    if (cpu.terminate) return;
    // 00481bca  39d0                   +cmp eax, edx
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
    // 00481bcc  7d10                   -jge 0x481bde
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481bde;
    }
L_0x00481bce:
    // 00481bce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481bd0  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481bd5  e846d4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481bda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481bdc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bdd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481bde:
    // 00481bde  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481be0  e86b000000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00481be5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481be7  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481bec  e82fd4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481bf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481bf3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481bf4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481bf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481bf8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481bf9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481bfa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481bfc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00481bfe  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00481c00  e8e7faffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481c05  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00481c07  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481c09  742d                   -je 0x481c38
    if (cpu.flags.zf)
    {
        goto L_0x00481c38;
    }
    // 00481c0b  031d20b05100           -add ebx, dword ptr [0x51b020]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */)));
L_0x00481c11:
    // 00481c11  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481c13  e8d4020000             -call 0x481eec
    cpu.esp -= 4;
    sub_481eec(app, cpu);
    if (cpu.terminate) return;
    // 00481c18  39d0                   +cmp eax, edx
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
    // 00481c1a  7d11                   -jge 0x481c2d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481c2d;
    }
    // 00481c1c  3b1d20b05100           +cmp ebx, dword ptr [0x51b020]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c22  7e09                   -jle 0x481c2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481c2d;
    }
    // 00481c24  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481c26  e85564ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00481c2b  ebe4                   -jmp 0x481c11
    goto L_0x00481c11;
L_0x00481c2d:
    // 00481c2d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481c2f  e8b8020000             -call 0x481eec
    cpu.esp -= 4;
    sub_481eec(app, cpu);
    if (cpu.terminate) return;
    // 00481c34  39d0                   +cmp eax, edx
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
    // 00481c36  7d05                   -jge 0x481c3d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00481c3d;
    }
L_0x00481c38:
    // 00481c38  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481c3a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c3b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481c3d:
    // 00481c3d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00481c3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481c41  e80a000000             -call 0x481c50
    cpu.esp -= 4;
    sub_481c50(app, cpu);
    if (cpu.terminate) return;
    // 00481c46  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481c48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481c4a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c4b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481c4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481c50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481c51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481c52  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481c53  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481c54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481c56  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00481c58  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481c5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00481c5c  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c63  750a                   -jne 0x481c6f
    if (!cpu.flags.zf)
    {
        goto L_0x00481c6f;
    }
    // 00481c65  e84ed3ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481c6a  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481c6f:
    // 00481c6f  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481c74  e88fd3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481c79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481c7b  e86cfaffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481c80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481c82  0f84b1000000           -je 0x481d39
    if (cpu.flags.zf)
    {
        goto L_0x00481d39;
    }
    // 00481c88  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481c8f  8bb034020000           -mov esi, dword ptr [eax + 0x234]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00481c95  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481c97  81fe00020000           +cmp esi, 0x200
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481c9d  7e0b                   -jle 0x481caa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481caa;
    }
    // 00481c9f  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 00481ca4  2b9034020000           -sub edx, dword ptr [eax + 0x234]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */)));
L_0x00481caa:
    // 00481caa  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481cb1  8b9830020000           -mov ebx, dword ptr [eax + 0x230]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 00481cb7  8b8034020000           -mov eax, dword ptr [eax + 0x234]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00481cbd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481cbf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481cc1  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 00481cc6  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00481cc9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00481ccb  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481cd1  7e0b                   -jle 0x481cde
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481cde;
    }
    // 00481cd3  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 00481cd8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00481cda  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00481cdc  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00481cde:
    // 00481cde  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481ce0  7418                   -je 0x481cfa
    if (cpu.flags.zf)
    {
        goto L_0x00481cfa;
    }
    // 00481ce2  8b148d20bb5100         -mov edx, dword ptr [ecx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481ce9  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 00481cef  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00481cf1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00481cf3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00481cf5  e856eaffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x00481cfa:
    // 00481cfa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00481cfc  7417                   -je 0x481d15
    if (cpu.flags.zf)
    {
        goto L_0x00481d15;
    }
    // 00481cfe  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00481d00  8b148d20bb5100         -mov edx, dword ptr [ecx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481d07  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 00481d0a  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 00481d10  e83beaffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x00481d15:
    // 00481d15  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481d1c  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00481d1f  8ba834020000           -mov ebp, dword ptr [eax + 0x234]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 00481d25  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481d27  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00481d2c  89a834020000           -mov dword ptr [eax + 0x234], ebp
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */) = cpu.ebp;
    // 00481d32  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481d34  e81bf5ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
L_0x00481d39:
    // 00481d39  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481d3e  e8ddd2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481d43  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00481d46  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d47  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d48  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d49  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481d4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481d4c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481d4d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481d4e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481d4f  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00481d52  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481d54  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00481d56  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00481d58  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00481d5a  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481d61  750a                   -jne 0x481d6d
    if (!cpu.flags.zf)
    {
        goto L_0x00481d6d;
    }
    // 00481d63  e850d2ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481d68  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481d6d:
    // 00481d6d  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481d72  e891d2ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481d77  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481d79  e86ef9ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481d7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481d80  7513                   -jne 0x481d95
    if (!cpu.flags.zf)
    {
        goto L_0x00481d95;
    }
L_0x00481d82:
    // 00481d82  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481d87  e894d2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481d8c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00481d8f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d90  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d91  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481d92  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00481d95:
    // 00481d95  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481d97  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481d98  8b04b520bb5100         -mov eax, dword ptr [esi*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.esi * 4);
    // 00481d9f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481da2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481da3  2eff1580544b00         -call dword ptr cs:[0x4b5480]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936832) /* 0x4b5480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481daa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481dac  745c                   -je 0x481e0a
    if (cpu.flags.zf)
    {
        goto L_0x00481e0a;
    }
    // 00481dae  804c240801             -or byte ptr [esp + 8], 1
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00481db3  6681642408fdb0         -and word ptr [esp + 8], 0xb0fd
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) &= x86::reg16(x86::sreg16(45309 /*0xb0fd*/));
    // 00481dba  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481dbd  7f07                   -jg 0x481dc6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00481dc6;
    }
    // 00481dbf  8b3cbdb4904c00         -mov edi, dword ptr [edi*4 + 0x4c90b4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5017780) /* 0x4c90b4 */ + cpu.edi * 4);
L_0x00481dc6:
    // 00481dc6  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00481dca  0405                   -add al, 5
    (cpu.al) += x86::reg8(x86::sreg8(5 /*0x5*/));
    // 00481dcc  897c2404               -mov dword ptr [esp + 4], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00481dd0  88442412               -mov byte ptr [esp + 0x12], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 00481dd4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00481dd6  764a                   -jbe 0x481e22
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481e22;
    }
    // 00481dd8  83fb01                 +cmp ebx, 1
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
    // 00481ddb  7545                   -jne 0x481e22
    if (!cpu.flags.zf)
    {
        goto L_0x00481e22;
    }
    // 00481ddd  c644241402             -mov byte ptr [esp + 0x14], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x00481de2:
    // 00481de2  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481de5  7343                   -jae 0x481e2a
    if (!cpu.flags.cf)
    {
        goto L_0x00481e2a;
    }
L_0x00481de7:
    // 00481de7  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00481de9  884c2413               -mov byte ptr [esp + 0x13], cl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.cl;
L_0x00481ded:
    // 00481ded  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00481def  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481df0  8b04b520bb5100         -mov eax, dword ptr [esi*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.esi * 4);
    // 00481df7  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00481dfa  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481dfb  2eff1538554b00         -call dword ptr cs:[0x4b5538]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937016) /* 0x4b5538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481e02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481e04  0f8578ffffff           -jne 0x481d82
    if (!cpu.flags.zf)
    {
        goto L_0x00481d82;
    }
L_0x00481e0a:
    // 00481e0a  e889d2ffff             -call 0x47f098
    cpu.esp -= 4;
    sub_47f098(app, cpu);
    if (cpu.terminate) return;
    // 00481e0f  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481e14  e807d2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481e19  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00481e1c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e1d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e1e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e1f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00481e22:
    // 00481e22  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 00481e24  88742414               -mov byte ptr [esp + 0x14], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 00481e28  ebb8                   -jmp 0x481de2
    goto L_0x00481de2;
L_0x00481e2a:
    // 00481e2a  7707                   -ja 0x481e33
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00481e33;
    }
    // 00481e2c  c644241301             -mov byte ptr [esp + 0x13], 1
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 1 /*0x1*/;
    // 00481e31  ebba                   -jmp 0x481ded
    goto L_0x00481ded;
L_0x00481e33:
    // 00481e33  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e36  75af                   -jne 0x481de7
    if (!cpu.flags.zf)
    {
        goto L_0x00481de7;
    }
    // 00481e38  c644241302             -mov byte ptr [esp + 0x13], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 2 /*0x2*/;
    // 00481e3d  ebae                   -jmp 0x481ded
    goto L_0x00481ded;
}

/* align: skip 0x90 */
void Application::sub_481e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481e40  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481e41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481e43  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481e4a  750a                   -jne 0x481e56
    if (!cpu.flags.zf)
    {
        goto L_0x00481e56;
    }
    // 00481e4c  e867d1ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481e51  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481e56:
    // 00481e56  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481e5b  e8a8d1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481e60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e62  e885f8ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481e67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481e69  741b                   -je 0x481e86
    if (cpu.flags.zf)
    {
        goto L_0x00481e86;
    }
    // 00481e6b  8b149520bb5100         -mov edx, dword ptr [edx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 00481e72  8b9234020000           -mov edx, dword ptr [edx + 0x234]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 00481e78  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481e7d  e89ed1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481e82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e84  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481e86:
    // 00481e86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481e88  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481e8d  e88ed1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481e92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481e94  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481e95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_481e98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481e98  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481e99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481e9b  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ea2  750a                   -jne 0x481eae
    if (!cpu.flags.zf)
    {
        goto L_0x00481eae;
    }
    // 00481ea4  e80fd1ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481ea9  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481eae:
    // 00481eae  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481eb3  e850d1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481eb8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481eba  e82df8ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481ebf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481ec1  7418                   -je 0x481edb
    if (cpu.flags.zf)
    {
        goto L_0x00481edb;
    }
    // 00481ec3  8b149520bb5100         -mov edx, dword ptr [edx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 00481eca  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00481ecd  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481ed2  e849d1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481ed7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ed9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481eda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481edb:
    // 00481edb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481edd  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481ee2  e839d1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481ee7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481ee9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481eea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_481eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481eec  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481eed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481eef  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481ef6  750a                   -jne 0x481f02
    if (!cpu.flags.zf)
    {
        goto L_0x00481f02;
    }
    // 00481ef8  e8bbd0ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481efd  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481f02:
    // 00481f02  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481f07  e8fcd0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481f0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f0e  e8d9f7ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481f13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481f15  7426                   -je 0x481f3d
    if (cpu.flags.zf)
    {
        goto L_0x00481f3d;
    }
    // 00481f17  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481f18  8b149520bb5100         -mov edx, dword ptr [edx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.edx * 4);
    // 00481f1f  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 00481f24  8b9a34020000           -mov ebx, dword ptr [edx + 0x234]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 00481f2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481f2c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481f2e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f2f  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481f34  e8e7d0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481f39  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f3b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481f3d:
    // 00481f3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00481f3f  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481f44  e8d7d0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00481f49  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481f4b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481f4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_481f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481f50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00481f51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00481f52  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481f53  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00481f54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00481f56  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00481f58  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00481f5a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00481f5c  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481f63  750a                   -jne 0x481f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00481f6f;
    }
    // 00481f65  e84ed0ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00481f6a  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00481f6f:
    // 00481f6f  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481f74  e88fd0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00481f79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00481f7b  e86cf7ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00481f80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481f82  0f846e000000           -je 0x481ff6
    if (cpu.flags.zf)
    {
        goto L_0x00481ff6;
    }
    // 00481f88  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481f8f  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00481f92  39f2                   +cmp edx, esi
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
    // 00481f94  7e02                   -jle 0x481f98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481f98;
    }
    // 00481f96  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00481f98:
    // 00481f98  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481f9f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481fa2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481fa4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00481fa6  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481fac  7e14                   -jle 0x481fc2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00481fc2;
    }
    // 00481fae  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 00481fb3  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481fb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00481fb8  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00481fba  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00481fbc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00481fbe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00481fc0  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00481fc2:
    // 00481fc2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481fc4  7418                   -je 0x481fde
    if (cpu.flags.zf)
    {
        goto L_0x00481fde;
    }
    // 00481fc6  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481fcd  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00481fd0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00481fd3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00481fd5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00481fd7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00481fd9  e872e7ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x00481fde:
    // 00481fde  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00481fe0  7414                   -je 0x481ff6
    if (cpu.flags.zf)
    {
        goto L_0x00481ff6;
    }
    // 00481fe2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00481fe4  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00481feb  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 00481fee  83c02c                 -add eax, 0x2c
    (cpu.eax) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00481ff1  e85ae7ffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
L_0x00481ff6:
    // 00481ff6  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00481ffb  e820d0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00482000  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00482003  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482004  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482005  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482006  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482007  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_482008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482008  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482009  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048200b  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482012  750a                   -jne 0x48201e
    if (!cpu.flags.zf)
    {
        goto L_0x0048201e;
    }
    // 00482014  e89fcfffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00482019  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x0048201e:
    // 0048201e  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00482023  e8e0cfffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00482028  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048202a  e821ffffff             -call 0x481f50
    cpu.esp -= 4;
    sub_481f50(app, cpu);
    if (cpu.terminate) return;
    // 0048202f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482031  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482033  750e                   -jne 0x482043
    if (!cpu.flags.zf)
    {
        goto L_0x00482043;
    }
    // 00482035  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048203a  e8e1cfffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048203f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482041  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482042  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482043:
    // 00482043  8b148d20bb5100         -mov edx, dword ptr [ecx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 0048204a  294210                 -sub dword ptr [edx + 0x10], eax
    (*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048204d  8b148d20bb5100         -mov edx, dword ptr [ecx*4 + 0x51bb20]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00482054  03420c                 -add eax, dword ptr [edx + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 00482057  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048205c  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048205f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00482064  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482066  e8e9f1ffff             -call 0x481254
    cpu.esp -= 4;
    sub_481254(app, cpu);
    if (cpu.terminate) return;
    // 0048206b  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00482070  e8abcfffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00482075  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482077  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48207c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048207c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048207d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048207e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00482080  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00482082  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482089  750a                   -jne 0x482095
    if (!cpu.flags.zf)
    {
        goto L_0x00482095;
    }
    // 0048208b  e828cfffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00482090  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00482095:
    // 00482095  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048209a  e869cfffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048209f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004820a1  e846f6ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 004820a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004820a8  7435                   -je 0x4820df
    if (cpu.flags.zf)
    {
        goto L_0x004820df;
    }
    // 004820aa  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
L_0x004820b1:
    // 004820b1  8b8320bb5100           -mov eax, dword ptr [ebx + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5356320) /* 0x51bb20 */);
    // 004820b7  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004820ba  7e09                   -jle 0x4820c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004820c5;
    }
    // 004820bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004820be  e8bd5fffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 004820c3  ebec                   -jmp 0x4820b1
    goto L_0x004820b1;
L_0x004820c5:
    // 004820c5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004820c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004820c9  e83affffff             -call 0x482008
    cpu.esp -= 4;
    sub_482008(app, cpu);
    if (cpu.terminate) return;
    // 004820ce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004820d0  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004820d5  e846cfffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004820da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004820dc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004820df:
    // 004820df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004820e1  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 004820e6  e835cfffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004820eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004820ed  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820ee  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004820ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4820f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004820f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004820f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004820f3  833db0904c0000         +cmp dword ptr [0x4c90b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004820fa  750a                   -jne 0x482106
    if (!cpu.flags.zf)
    {
        goto L_0x00482106;
    }
    // 004820fc  e8b7ceffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00482101  a3b0904c00             -mov dword ptr [0x4c90b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */) = cpu.eax;
L_0x00482106:
    // 00482106  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048210b  e8f8ceffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00482110  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482112  e8d5f5ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 00482117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482119  740c                   -je 0x482127
    if (cpu.flags.zf)
    {
        goto L_0x00482127;
    }
    // 0048211b  8b048d20bb5100         -mov eax, dword ptr [ecx*4 + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356320) /* 0x51bb20 */ + cpu.ecx * 4);
    // 00482122  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482125  7e10                   -jle 0x482137
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00482137;
    }
L_0x00482127:
    // 00482127  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482129  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 0048212e  e8edceffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00482133  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482135  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482136  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482137:
    // 00482137  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00482139  e8cafeffff             -call 0x482008
    cpu.esp -= 4;
    sub_482008(app, cpu);
    if (cpu.terminate) return;
    // 0048213e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482140  a1b0904c00             -mov eax, dword ptr [0x4c90b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017776) /* 0x4c90b0 */);
    // 00482145  e8d6ceffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048214a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048214c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048214d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482150  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482151  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482152  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482154  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00482156  e891f5ffff             -call 0x4816ec
    cpu.esp -= 4;
    sub_4816ec(app, cpu);
    if (cpu.terminate) return;
    // 0048215b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048215d  7434                   -je 0x482193
    if (cpu.flags.zf)
    {
        goto L_0x00482193;
    }
    // 0048215f  8b1d20b05100           -mov ebx, dword ptr [0x51b020]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */);
    // 00482165  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00482167  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0048216e:
    // 0048216e  8b8120bb5100           -mov eax, dword ptr [ecx + 0x51bb20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5356320) /* 0x51bb20 */);
    // 00482174  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482177  7e11                   -jle 0x48218a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048218a;
    }
    // 00482179  3b1d20b05100           +cmp ebx, dword ptr [0x51b020]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5353504) /* 0x51b020 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048217f  7e09                   -jle 0x48218a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048218a;
    }
    // 00482181  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482183  e8f85effff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00482188  ebe4                   -jmp 0x48216e
    goto L_0x0048216e;
L_0x0048218a:
    // 0048218a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048218c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048218e  e875feffff             -call 0x482008
    cpu.esp -= 4;
    sub_482008(app, cpu);
    if (cpu.terminate) return;
L_0x00482193:
    // 00482193  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482194  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482195  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4821a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821a0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821aa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821ac  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821ae  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004821b5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004821b7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821b8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004821bc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004821bd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004821be  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004821c2  e8e32b0300             -call 0x4b4daa
    cpu.esp -= 4;
    sub_4b4daa(app, cpu);
    if (cpu.terminate) return;
    // 004821c7  8b1d9cb55100           -mov ebx, dword ptr [0x51b59c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5354908) /* 0x51b59c */);
    // 004821cd  43                     -inc ebx
    (cpu.ebx)++;
    // 004821ce  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004821d1  891d9cb55100           -mov dword ptr [0x51b59c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5354908) /* 0x51b59c */) = cpu.ebx;
    // 004821d7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004821da  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821db  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4821b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004821b0;
    // 004821a0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821a8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821aa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821ac  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004821ae  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004821b0:
    // 004821b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821b2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004821b5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004821b7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821b8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004821bc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004821bd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004821be  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004821c2  e8e32b0300             -call 0x4b4daa
    cpu.esp -= 4;
    sub_4b4daa(app, cpu);
    if (cpu.terminate) return;
    // 004821c7  8b1d9cb55100           -mov ebx, dword ptr [0x51b59c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5354908) /* 0x51b59c */);
    // 004821cd  43                     -inc ebx
    (cpu.ebx)++;
    // 004821ce  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004821d1  891d9cb55100           -mov dword ptr [0x51b59c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5354908) /* 0x51b59c */) = cpu.ebx;
    // 004821d7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004821da  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821db  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004821dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4821e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004821e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004821e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821e2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004821e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004821e4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004821e7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004821e9  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004821ec  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004821ef  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004821f0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004821f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004821f6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004821f7  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004821fa  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00482200  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482202  48                     -dec eax
    (cpu.eax)--;
    // 00482203  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00482206  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482207  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048220a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048220c  e883180000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 00482211  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482213  7408                   -je 0x48221d
    if (cpu.flags.zf)
    {
        goto L_0x0048221d;
    }
L_0x00482215:
    // 00482215  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00482218  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482219  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048221c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048221d:
    // 0048221d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00482220  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482223  80e4b7                 -and ah, 0xb7
    cpu.ah &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00482226  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482227  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048222b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048222c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048222e  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00482231  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00482237  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482239  48                     -dec eax
    (cpu.eax)--;
    // 0048223a  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048223d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048223e  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482241  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482243  e84c180000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 00482248  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048224a  7531                   -jne 0x48227d
    if (!cpu.flags.zf)
    {
        goto L_0x0048227d;
    }
    // 0048224c  f644240140             +test byte ptr [esp + 1], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 64 /*0x40*/));
    // 00482251  746c                   -je 0x4822bf
    if (cpu.flags.zf)
    {
        goto L_0x004822bf;
    }
    // 00482253  804c240508             -or byte ptr [esp + 5], 8
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00482258:
    // 00482258  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048225b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048225c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482260  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482261  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482263  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00482266  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048226c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048226e  48                     -dec eax
    (cpu.eax)--;
    // 0048226f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482272  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482273  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00482276  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482278  e817180000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
L_0x0048227d:
    // 0048227d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048227f  7594                   -jne 0x482215
    if (!cpu.flags.zf)
    {
        goto L_0x00482215;
    }
    // 00482281  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482288  768b                   -jbe 0x482215
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482215;
    }
    // 0048228a  8a7c2405               -mov bh, byte ptr [esp + 5]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 0048228e  80e7b7                 -and bh, 0xb7
    cpu.bh &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 00482291  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482294  887c2405               -mov byte ptr [esp + 5], bh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.bh;
    // 00482298  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482299  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048229d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048229e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004822a1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004822a2  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004822a5  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004822a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004822a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004822ab  c6866304000001         -mov byte ptr [esi + 0x463], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 004822b2  e8dd170000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 004822b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004822ba  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822bb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822bd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004822bf:
    // 004822bf  804c240540             +or byte ptr [esp + 5], 0x40
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004822c4  eb92                   -jmp 0x482258
    goto L_0x00482258;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4822c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004822c8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004822c9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004822ca  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004822cb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004822cd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004822cf  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004822d1  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004822d3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004822d4  c7036c000000           -mov dword ptr [ebx], 0x6c
    *app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 004822da  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004822dc  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004822de  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004822df  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004822e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004822e4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004822ea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004822ec  7408                   -je 0x4822f6
    if (cpu.flags.zf)
    {
        goto L_0x004822f6;
    }
    // 004822ee  81fac2010000           +cmp edx, 0x1c2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(450 /*0x1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004822f4  7406                   -je 0x4822fc
    if (cpu.flags.zf)
    {
        goto L_0x004822fc;
    }
L_0x004822f6:
    // 004822f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004822f8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822f9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822fa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004822fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004822fc:
    // 004822fc  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004822fd  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004822ff  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482302  8b9644040000           -mov edx, dword ptr [esi + 0x444]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00482308  39d7                   +cmp edi, edx
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
    // 0048230a  7418                   -je 0x482324
    if (cpu.flags.zf)
    {
        goto L_0x00482324;
    }
    // 0048230c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048230e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048230f  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00482311  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482314  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482316  740c                   -je 0x482324
    if (cpu.flags.zf)
    {
        goto L_0x00482324;
    }
    // 00482318  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048231e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048231f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482321  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482324:
    // 00482324  8b8e48040000           -mov ecx, dword ptr [esi + 0x448]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048232a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048232c  741a                   -je 0x482348
    if (cpu.flags.zf)
    {
        goto L_0x00482348;
    }
    // 0048232e  39cf                   +cmp edi, ecx
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
    // 00482330  7416                   -je 0x482348
    if (cpu.flags.zf)
    {
        goto L_0x00482348;
    }
    // 00482332  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482333  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00482335  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482338  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048233a  740c                   -je 0x482348
    if (cpu.flags.zf)
    {
        goto L_0x00482348;
    }
    // 0048233c  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 00482342  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482343  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482345  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482348:
    // 00482348  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482349  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0048234b  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048234e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482350  0f85b2000000           -jne 0x482408
    if (!cpu.flags.zf)
    {
        goto L_0x00482408;
    }
    // 00482356  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482358  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048235a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048235b  c7036c000000           -mov dword ptr [ebx], 0x6c
    *app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 00482361  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482363  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 00482365  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482366  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482369  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048236b  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00482371  7434                   -je 0x4823a7
    if (cpu.flags.zf)
    {
        goto L_0x004823a7;
    }
    // 00482373  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00482378  e8a3ccffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048237d  e8eea2ffff             -call 0x47c670
    cpu.esp -= 4;
    sub_47c670(app, cpu);
    if (cpu.terminate) return;
    // 00482382  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00482387  e87cccffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048238c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048238e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482390  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482391  c7036c000000           -mov dword ptr [ebx], 0x6c
    *app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 00482397  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482399  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0048239b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048239c  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048239f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004823a1  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
L_0x004823a7:
    // 004823a7  0f8549ffffff           -jne 0x4822f6
    if (!cpu.flags.zf)
    {
        goto L_0x004822f6;
    }
    // 004823ad  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 004823b1  7519                   -jne 0x4823cc
    if (!cpu.flags.zf)
    {
        goto L_0x004823cc;
    }
L_0x004823b3:
    // 004823b3  833d84844c0000         +cmp dword ptr [0x4c8484], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004823ba  0f8436ffffff           -je 0x4822f6
    if (cpu.flags.zf)
    {
        goto L_0x004822f6;
    }
    // 004823c0  ff1584844c00           -call dword ptr [0x4c8484]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004823c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004823c8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823c9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823ca  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004823cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004823cc:
    // 004823cc  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004823cf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004823d0  6800010000             -push 0x100
    *app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004823d5  66c78632040000ffff     -mov word ptr [esi + 0x432], 0xffff
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 004823de  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004823e0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004823e3  66c786300400000001     -mov word ptr [esi + 0x430], 0x100
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004823ec  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004823ee  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004823f0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004823f1  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004823f4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004823f7  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 004823fd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004823fe  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482400  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482401  ff527c                 -call dword ptr [edx + 0x7c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482404  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00482406  ebab                   -jmp 0x4823b3
    goto L_0x004823b3;
L_0x00482408:
    // 00482408  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 0048240d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048240f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482410  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482411  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482412  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482414(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482414  3b0574b55100           +cmp eax, dword ptr [0x51b574]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5354868) /* 0x51b574 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048241a  7401                   -je 0x48241d
    if (cpu.flags.zf)
    {
        goto L_0x0048241d;
    }
    // 0048241c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048241d:
    // 0048241d  a194b55100             -mov eax, dword ptr [0x51b594]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */);
    // 00482422  0102                   -add dword ptr [edx], eax
    (*app->getMemory<x86::reg32>(cpu.edx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482424  a198b55100             -mov eax, dword ptr [0x51b598]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */);
    // 00482429  0103                   -add dword ptr [ebx], eax
    (*app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048242b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48242c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048242c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048242d  3b0574b55100           +cmp eax, dword ptr [0x51b574]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5354868) /* 0x51b574 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482433  7402                   -je 0x482437
    if (cpu.flags.zf)
    {
        goto L_0x00482437;
    }
    // 00482435  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482436  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482437:
    // 00482437  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482438  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482439  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048243a  a194b55100             -mov eax, dword ptr [0x51b594]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */);
    // 0048243f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00482441  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00482444  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00482447  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048244a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048244c  a198b55100             -mov eax, dword ptr [0x51b598]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */);
    // 00482451  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00482453  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482455  a194b55100             -mov eax, dword ptr [0x51b594]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */);
    // 0048245a  897204                 -mov dword ptr [edx + 4], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048245d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048245f  a198b55100             -mov eax, dword ptr [0x51b598]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */);
    // 00482464  897a08                 -mov dword ptr [edx + 8], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00482467  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482469  896a0c                 -mov dword ptr [edx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048246c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048246d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048246e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048246f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482470  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482474  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482475  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482476  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048247a  7410                   -je 0x48248c
    if (cpu.flags.zf)
    {
        goto L_0x0048248c;
    }
L_0x0048247c:
    // 0048247c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048247e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00482480  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00482482  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482484  42                     -inc edx
    (cpu.edx)++;
    // 00482485  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482487  75f3                   -jne 0x48247c
    if (!cpu.flags.zf)
    {
        goto L_0x0048247c;
    }
    // 00482489  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048248c:
    // 0048248c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048248e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048248f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482494  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482495  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482496  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482497  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048249a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048249c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048249e  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 004824a2  0f844a010000           -je 0x4825f2
    if (cpu.flags.zf)
    {
        goto L_0x004825f2;
    }
    // 004824a8  837b5410               +cmp dword ptr [ebx + 0x54], 0x10
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004824ac  0f8440010000           -je 0x4825f2
    if (cpu.flags.zf)
    {
        goto L_0x004825f2;
    }
    // 004824b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004824b4  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004824b7  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004824bb:
    // 004824bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004824bd  0f8cdd000000           -jl 0x4825a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004825a0;
    }
    // 004824c3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004824ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004824cc  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004824cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004824d2  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004824d5  890c28                 -mov dword ptr [eax + ebp], ecx
    *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1) = cpu.ecx;
    // 004824d8  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004824db  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004824dd  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004824e0  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004824e3  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004824e6  894d04                 -mov dword ptr [ebp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004824e9  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004824ec  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004824ee  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004824f1  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 004824f4  8a4b54                 -mov cl, byte ptr [ebx + 0x54]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004824f7  884d12                 -mov byte ptr [ebp + 0x12], cl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.cl;
    // 004824fa  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004824fd  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482501  884c2813               -mov byte ptr [eax + ebp + 0x13], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */ + cpu.ebp * 1) = cpu.cl;
    // 00482505  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482508  66c74401100100         -mov word ptr [ecx + eax + 0x10], 1
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 0048250f  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482512  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482514  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00482517  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048251a  8b0df8904c00           -mov ecx, dword ptr [0x4c90f8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5017848) /* 0x4c90f8 */);
    // 00482520  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00482523  f6430604               +test byte ptr [ebx + 6], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) & 4 /*0x4*/));
    // 00482527  740b                   -je 0x482534
    if (cpu.flags.zf)
    {
        goto L_0x00482534;
    }
    // 00482529  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048252c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048252e  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00482531  894108                 -mov dword ptr [ecx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00482534:
    // 00482534  f6430420               +test byte ptr [ebx + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 00482538  741b                   -je 0x482555
    if (cpu.flags.zf)
    {
        goto L_0x00482555;
    }
    // 0048253a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482541  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00482544  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00482547  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048254a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048254c  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0048254e  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00482551  66014810               -add word ptr [eax + 0x10], cx
    (*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.cx));
L_0x00482555:
    // 00482555  f6430480               +test byte ptr [ebx + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 00482559  7411                   -je 0x48256c
    if (cpu.flags.zf)
    {
        goto L_0x0048256c;
    }
    // 0048255b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482562  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482565  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00482567  804c810c01             -or byte ptr [ecx + eax*4 + 0xc], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048256c:
    // 0048256c  f6430440               +test byte ptr [ebx + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 64 /*0x40*/));
    // 00482570  7411                   -je 0x482583
    if (cpu.flags.zf)
    {
        goto L_0x00482583;
    }
    // 00482572  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482579  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048257c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048257e  804c810c02             -or byte ptr [ecx + eax*4 + 0xc], 2
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00482583:
    // 00482583  f6430401               +test byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 00482587  7417                   -je 0x4825a0
    if (cpu.flags.zf)
    {
        goto L_0x004825a0;
    }
    // 00482589  f6436a20               +test byte ptr [ebx + 0x6a], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(106) /* 0x6a */) & 32 /*0x20*/));
    // 0048258d  7411                   -je 0x4825a0
    if (cpu.flags.zf)
    {
        goto L_0x004825a0;
    }
    // 0048258f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482596  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482599  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048259b  804c810c04             -or byte ptr [ecx + eax*4 + 0xc], 4
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004825a0:
    // 004825a0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004825a2  7447                   -je 0x4825eb
    if (cpu.flags.zf)
    {
        goto L_0x004825eb;
    }
    // 004825a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004825a6  7c1e                   -jl 0x4825c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004825c6;
    }
    // 004825a8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004825af  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004825b1  8a9660040000           -mov dl, byte ptr [esi + 0x460]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
    // 004825b7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004825ba  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004825bc  755b                   -jne 0x482619
    if (!cpu.flags.zf)
    {
        goto L_0x00482619;
    }
    // 004825be  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004825c1  8064020cef             -and byte ptr [edx + eax + 0xc], 0xef
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x004825c6:
    // 004825c6  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004825cd  740c                   -je 0x4825db
    if (cpu.flags.zf)
    {
        goto L_0x004825db;
    }
    // 004825cf  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004825d2  894614                 -mov dword ptr [esi + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004825d5  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004825d8  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004825db:
    // 004825db  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004825de  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004825e1  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004825e5  88865c040000           -mov byte ptr [esi + 0x45c], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */) = cpu.al;
L_0x004825eb:
    // 004825eb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004825ee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825ef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004825f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004825f2:
    // 004825f2  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 004825f5  e87afeffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 004825fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004825fc  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 004825ff  e870feffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00482604  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482606  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 00482609  e866feffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 0048260e  01c1                   +add ecx, eax
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
    // 00482610  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00482614  e9a2feffff             -jmp 0x4824bb
    goto L_0x004824bb;
L_0x00482619:
    // 00482619  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048261c  804c020c10             +or byte ptr [edx + eax + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00482621  eba3                   -jmp 0x4825c6
    goto L_0x004825c6;
}

/* align: skip 0x90 */
void Application::sub_482624(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482624  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482625  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482626  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482627  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048262a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048262c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048262e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00482630  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482631  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00482637  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482638  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048263f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00482643  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00482646  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482648  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048264a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048264e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00482652  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00482654  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00482656  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00482659  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048265c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_482660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482660  a184b55100             -mov eax, dword ptr [0x51b584]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00482665  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482668  a19cb55100             -mov eax, dword ptr [0x51b59c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5354908) /* 0x51b59c */);
    // 0048266d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482670  a130b15100             -mov eax, dword ptr [0x51b130]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
    // 00482675  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_482678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482678  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482679  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048267a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048267c  7414                   -je 0x482692
    if (cpu.flags.zf)
    {
        goto L_0x00482692;
    }
    // 0048267e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482680  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482681  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00482687  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482688  2eff1508544b00         -call dword ptr cs:[0x4b5408]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936712) /* 0x4b5408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048268f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482690  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482691  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482692:
    // 00482692  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00482697  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482698  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0048269e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048269f  2eff1508544b00         -call dword ptr cs:[0x4b5408]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936712) /* 0x4b5408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004826a6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4826ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004826ac  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004826ad  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004826ae  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004826af  68a0404800             -push 0x4840a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4735136 /*0x4840a0*/;
    cpu.esp -= 4;
    // 004826b4  e8eb260300             -call 0x4b4da4
    cpu.esp -= 4;
    sub_4b4da4(app, cpu);
    if (cpu.terminate) return;
    // 004826b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826ba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004826bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4826bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004826bc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004826bd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004826be  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004826bf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004826c0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004826c1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004826c2  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004826c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004826ca  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004826cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004826ce  7505                   -jne 0x4826d5
    if (!cpu.flags.zf)
    {
        goto L_0x004826d5;
    }
    // 004826d0  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x004826d5:
    // 004826d5  833d4c8d4c0000         +cmp dword ptr [0x4c8d4c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004826dc  750a                   -jne 0x4826e8
    if (!cpu.flags.zf)
    {
        goto L_0x004826e8;
    }
    // 004826de  e8d5c8ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 004826e3  a34c8d4c00             -mov dword ptr [0x4c8d4c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */) = cpu.eax;
L_0x004826e8:
    // 004826e8  ba80bb5100             -mov edx, 0x51bb80
    cpu.edx = 5356416 /*0x51bb80*/;
    // 004826ed  a180bb5100             -mov eax, dword ptr [0x51bb80]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356416) /* 0x51bb80 */);
    // 004826f2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004826f5  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004826f8  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004826fa  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004826fd  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 004826ff  8a15f0814c00           -mov dl, byte ptr [0x4c81f0]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 00482705  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482707  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 0048270a  7521                   -jne 0x48272d
    if (!cpu.flags.zf)
    {
        goto L_0x0048272d;
    }
    // 0048270c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048270e  740e                   -je 0x48271e
    if (cpu.flags.zf)
    {
        goto L_0x0048271e;
    }
    // 00482710  ba80bb5100             -mov edx, 0x51bb80
    cpu.edx = 5356416 /*0x51bb80*/;
    // 00482715  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482717  e894faffff             -call 0x4821b0
    cpu.esp -= 4;
    sub_4821b0(app, cpu);
    if (cpu.terminate) return;
    // 0048271c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048271e:
    // 0048271e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482720  750b                   -jne 0x48272d
    if (!cpu.flags.zf)
    {
        goto L_0x0048272d;
    }
    // 00482722  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482724  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00482726  e885faffff             -call 0x4821b0
    cpu.esp -= 4;
    sub_4821b0(app, cpu);
    if (cpu.terminate) return;
    // 0048272b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048272d:
    // 0048272d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048272f  0f8420010000           -je 0x482855
    if (cpu.flags.zf)
    {
        goto L_0x00482855;
    }
L_0x00482735:
    // 00482735  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482736  68b8f64c00             -push 0x4cf6b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5043896 /*0x4cf6b8*/;
    cpu.esp -= 4;
    // 0048273b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0048273d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048273e  ff10                   -call dword ptr [eax]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482740  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482742  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482743  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482745  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048274b  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048274e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482750  0f853e010000           -jne 0x482894
    if (!cpu.flags.zf)
    {
        goto L_0x00482894;
    }
    // 00482756  b86c010000             -mov eax, 0x16c
    cpu.eax = 364 /*0x16c*/;
    // 0048275b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048275d  8984246c010000         -mov dword ptr [esp + 0x16c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.eax;
    // 00482764  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00482767  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482768  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048276f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00482771  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482772  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482774  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482775  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482778  8ab42473010000         -mov dh, byte ptr [esp + 0x173]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */);
    // 0048277f  893df8904c00           -mov dword ptr [0x4c90f8], edi
    *app->getMemory<x86::reg32>(x86::reg32(5017848) /* 0x4c90f8 */) = cpu.edi;
    // 00482785  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00482788  740a                   -je 0x482794
    if (cpu.flags.zf)
    {
        goto L_0x00482794;
    }
    // 0048278a  c705f8904c0008000000   -mov dword ptr [0x4c90f8], 8
    *app->getMemory<x86::reg32>(x86::reg32(5017848) /* 0x4c90f8 */) = 8 /*0x8*/;
L_0x00482794:
    // 00482794  f684247201000008       +test byte ptr [esp + 0x172], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(370) /* 0x172 */) & 8 /*0x8*/));
    // 0048279c  7407                   -je 0x4827a5
    if (cpu.flags.zf)
    {
        goto L_0x004827a5;
    }
    // 0048279e  800df9904c0008         -or byte ptr [0x4c90f9], 8
    *app->getMemory<x86::reg8>(x86::reg32(5017849) /* 0x4c90f9 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x004827a5:
    // 004827a5  f684247001000001       +test byte ptr [esp + 0x170], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 1 /*0x1*/));
    // 004827ad  7407                   -je 0x4827b6
    if (cpu.flags.zf)
    {
        goto L_0x004827b6;
    }
    // 004827af  800df8904c0020         -or byte ptr [0x4c90f8], 0x20
    *app->getMemory<x86::reg8>(x86::reg32(5017848) /* 0x4c90f8 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004827b6:
    // 004827b6  8a942470010000         -mov dl, byte ptr [esp + 0x170]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004827bd  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004827c0  0f85c0000000           -jne 0x482886
    if (!cpu.flags.zf)
    {
        goto L_0x00482886;
    }
L_0x004827c6:
    // 004827c6  f684247001000040       +test byte ptr [esp + 0x170], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 64 /*0x40*/));
    // 004827ce  7407                   -je 0x4827d7
    if (cpu.flags.zf)
    {
        goto L_0x004827d7;
    }
    // 004827d0  800df8904c0040         -or byte ptr [0x4c90f8], 0x40
    *app->getMemory<x86::reg8>(x86::reg32(5017848) /* 0x4c90f8 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004827d7:
    // 004827d7  f684247301000004       +test byte ptr [esp + 0x173], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 4 /*0x4*/));
    // 004827df  7407                   -je 0x4827e8
    if (cpu.flags.zf)
    {
        goto L_0x004827e8;
    }
    // 004827e1  800df8904c0080         -or byte ptr [0x4c90f8], 0x80
    *app->getMemory<x86::reg8>(x86::reg32(5017848) /* 0x4c90f8 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004827e8:
    // 004827e8  f684247101000002       +test byte ptr [esp + 0x171], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(369) /* 0x171 */) & 2 /*0x2*/));
    // 004827f0  7407                   -je 0x4827f9
    if (cpu.flags.zf)
    {
        goto L_0x004827f9;
    }
    // 004827f2  800df9904c0001         -or byte ptr [0x4c90f9], 1
    *app->getMemory<x86::reg8>(x86::reg32(5017849) /* 0x4c90f9 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004827f9:
    // 004827f9  f684247301000080       +test byte ptr [esp + 0x173], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 128 /*0x80*/));
    // 00482801  7407                   -je 0x48280a
    if (cpu.flags.zf)
    {
        goto L_0x0048280a;
    }
    // 00482803  800df9904c0004         -or byte ptr [0x4c90f9], 4
    *app->getMemory<x86::reg8>(x86::reg32(5017849) /* 0x4c90f9 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0048280a:
    // 0048280a  f684247301000001       +test byte ptr [esp + 0x173], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 1 /*0x1*/));
    // 00482812  7411                   -je 0x482825
    if (cpu.flags.zf)
    {
        goto L_0x00482825;
    }
    // 00482814  f684247901000002       +test byte ptr [esp + 0x179], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(377) /* 0x179 */) & 2 /*0x2*/));
    // 0048281c  7407                   -je 0x482825
    if (cpu.flags.zf)
    {
        goto L_0x00482825;
    }
    // 0048281e  800df9904c0002         -or byte ptr [0x4c90f9], 2
    *app->getMemory<x86::reg8>(x86::reg32(5017849) /* 0x4c90f9 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00482825:
    // 00482825  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 0048282d  7407                   -je 0x482836
    if (cpu.flags.zf)
    {
        goto L_0x00482836;
    }
    // 0048282f  800df8904c0010         -or byte ptr [0x4c90f8], 0x10
    *app->getMemory<x86::reg8>(x86::reg32(5017848) /* 0x4c90f8 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00482836:
    // 00482836  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00482838  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
L_0x0048283e:
    // 0048283e  833b00                 +cmp dword ptr [ebx], 0
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
    // 00482841  7463                   -je 0x4828a6
    if (cpu.flags.zf)
    {
        goto L_0x004828a6;
    }
    // 00482843  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00482848:
    // 00482848  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048284e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048284f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482850  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482851  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482852  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482853  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482854  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482855:
    // 00482855  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048285a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048285c  e84ff9ffff             -call 0x4821b0
    cpu.esp -= 4;
    sub_4821b0(app, cpu);
    if (cpu.terminate) return;
    // 00482861  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482863  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482865  0f85cafeffff           -jne 0x482735
    if (!cpu.flags.zf)
    {
        goto L_0x00482735;
    }
    // 0048286b  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048286d  b810e64b00             -mov eax, 0x4be610
    cpu.eax = 4974096 /*0x4be610*/;
    // 00482872  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482874  7509                   -jne 0x48287f
    if (!cpu.flags.zf)
    {
        goto L_0x0048287f;
    }
L_0x00482876:
    // 00482876  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 0048287b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048287d  ebc9                   -jmp 0x482848
    goto L_0x00482848;
L_0x0048287f:
    // 0048287f  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 00482884  ebf0                   -jmp 0x482876
    goto L_0x00482876;
L_0x00482886:
    // 00482886  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00482889  0f8437ffffff           -je 0x4827c6
    if (cpu.flags.zf)
    {
        goto L_0x004827c6;
    }
    // 0048288f  e976ffffff             -jmp 0x48280a
    goto L_0x0048280a;
L_0x00482894:
    // 00482894  b82ce64b00             -mov eax, 0x4be62c
    cpu.eax = 4974124 /*0x4be62c*/;
    // 00482899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048289b  7518                   -jne 0x4828b5
    if (!cpu.flags.zf)
    {
        goto L_0x004828b5;
    }
L_0x0048289d:
    // 0048289d  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 004828a2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004828a4  7498                   -je 0x48283e
    if (cpu.flags.zf)
    {
        goto L_0x0048283e;
    }
L_0x004828a6:
    // 004828a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004828a8  81c4d8020000           +add esp, 0x2d8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(728 /*0x2d8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004828ae  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828af  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004828b5:
    // 004828b5  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 004828ba  ebe1                   -jmp 0x48289d
    goto L_0x0048289d;
}

/* align: skip  */
void Application::sub_4828bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004828bc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004828bd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004828be  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004828bf  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004828c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004828c7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004828c9  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004828cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004828cd  7505                   -jne 0x4828d4
    if (!cpu.flags.zf)
    {
        goto L_0x004828d4;
    }
    // 004828cf  be30b15100             -mov esi, 0x51b130
    cpu.esi = 5353776 /*0x51b130*/;
L_0x004828d4:
    // 004828d4  833e00                 +cmp dword ptr [esi], 0
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
    // 004828d7  750e                   -jne 0x4828e7
    if (!cpu.flags.zf)
    {
        goto L_0x004828e7;
    }
L_0x004828d9:
    // 004828d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004828db  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 004828e1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004828e4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004828e7:
    // 004828e7  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 004828ec  898c246c010000         -mov dword ptr [esp + 0x16c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ecx;
    // 004828f3  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004828f6  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004828f8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004828f9  8d8c2470010000         -lea ecx, [esp + 0x170]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00482900  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482902  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482903  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482905  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482906  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482909  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048290d  75ca                   -jne 0x4828d9
    if (!cpu.flags.zf)
    {
        goto L_0x004828d9;
    }
    // 0048290f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482911  740a                   -je 0x48291d
    if (cpu.flags.zf)
    {
        goto L_0x0048291d;
    }
    // 00482913  8b8424a8010000         -mov eax, dword ptr [esp + 0x1a8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 0048291a  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x0048291d:
    // 0048291d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048291f  7409                   -je 0x48292a
    if (cpu.flags.zf)
    {
        goto L_0x0048292a;
    }
    // 00482921  8b8424ac010000         -mov eax, dword ptr [esp + 0x1ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 00482928  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0048292a:
    // 0048292a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048292c  7411                   -je 0x48293f
    if (cpu.flags.zf)
    {
        goto L_0x0048293f;
    }
    // 0048292e  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00482936  745c                   -je 0x482994
    if (cpu.flags.zf)
    {
        goto L_0x00482994;
    }
    // 00482938  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048293d:
    // 0048293d  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0048293f:
    // 0048293f  83bc24e802000000       +cmp dword ptr [esp + 0x2e8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482947  742d                   -je 0x482976
    if (cpu.flags.zf)
    {
        goto L_0x00482976;
    }
    // 00482949  68d8404800             -push 0x4840d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4735192 /*0x4840d8*/;
    cpu.esp -= 4;
    // 0048294e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482950  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482951  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482952  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482954  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482956  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482958  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482959  890d98bb5100           -mov dword ptr [0x51bb98], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */) = cpu.ecx;
    // 0048295f  890d90bb5100           -mov dword ptr [0x51bb90], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */) = cpu.ecx;
    // 00482965  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482968  8b9424e8020000         -mov edx, dword ptr [esp + 0x2e8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
    // 0048296f  a190bb5100             -mov eax, dword ptr [0x51bb90]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356432) /* 0x51bb90 */);
    // 00482974  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00482976:
    // 00482976  833d98bb510000         +cmp dword ptr [0x51bb98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048297d  0f8e56ffffff           -jle 0x4828d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004828d9;
    }
    // 00482983  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482988  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048298e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048298f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482990  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482991  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00482994:
    // 00482994  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482996  eba5                   -jmp 0x48293d
    goto L_0x0048293d;
}

/* align: skip  */
void Application::sub_482998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482998  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482999  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048299a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048299b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048299c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048299d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048299e  8b3dd0884c00           -mov edi, dword ptr [0x4c88d0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */);
    // 004829a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004829a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004829a8  7505                   -jne 0x4829af
    if (!cpu.flags.zf)
    {
        goto L_0x004829af;
    }
    // 004829aa  be30b15100             -mov esi, 0x51b130
    cpu.esi = 5353776 /*0x51b130*/;
L_0x004829af:
    // 004829af  833e00                 +cmp dword ptr [esi], 0
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
    // 004829b2  7521                   -jne 0x4829d5
    if (!cpu.flags.zf)
    {
        goto L_0x004829d5;
    }
    // 004829b4  b850e64b00             -mov eax, 0x4be650
    cpu.eax = 4974160 /*0x4be650*/;
    // 004829b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004829bb  7511                   -jne 0x4829ce
    if (!cpu.flags.zf)
    {
        goto L_0x004829ce;
    }
L_0x004829bd:
    // 004829bd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004829bf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004829c1  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 004829c7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829c8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829c9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829ca  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829cb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829cc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004829ce:
    // 004829ce  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 004829d3  ebe8                   -jmp 0x4829bd
    goto L_0x004829bd;
L_0x004829d5:
    // 004829d5  83be5404000000         +cmp dword ptr [esi + 0x454], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004829dc  751f                   -jne 0x4829fd
    if (!cpu.flags.zf)
    {
        goto L_0x004829fd;
    }
    // 004829de  b870e64b00             -mov eax, 0x4be670
    cpu.eax = 4974192 /*0x4be670*/;
    // 004829e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004829e5  74d6                   -je 0x4829bd
    if (cpu.flags.zf)
    {
        goto L_0x004829bd;
    }
    // 004829e7  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 004829ec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004829ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004829f0  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 004829f6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829f9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829fa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829fb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004829fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004829fd:
    // 004829fd  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482a04  744f                   -je 0x482a55
    if (cpu.flags.zf)
    {
        goto L_0x00482a55;
    }
    // 00482a06  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00482a0b  8b1dfc904c00           -mov ebx, dword ptr [0x4c90fc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017852) /* 0x4c90fc */);
    // 00482a11  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482a17  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00482a19  7405                   -je 0x482a20
    if (cpu.flags.zf)
    {
        goto L_0x00482a20;
    }
    // 00482a1b  b851000000             -mov eax, 0x51
    cpu.eax = 81 /*0x51*/;
L_0x00482a20:
    // 00482a20  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482a21  8bae54040000           -mov ebp, dword ptr [esi + 0x454]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00482a27  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482a29  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482a2a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00482a2c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482a2d  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482a30  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00482a35  742b                   -je 0x482a62
    if (cpu.flags.zf)
    {
        goto L_0x00482a62;
    }
    // 00482a37  b8e4e64b00             -mov eax, 0x4be6e4
    cpu.eax = 4974308 /*0x4be6e4*/;
    // 00482a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482a3e  0f85ba000000           -jne 0x482afe
    if (!cpu.flags.zf)
    {
        goto L_0x00482afe;
    }
    // 00482a44  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482a46  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482a48  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482a4e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a4f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a50  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a51  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a52  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a53  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482a55:
    // 00482a55  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00482a5a  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482a60  ebbe                   -jmp 0x482a20
    goto L_0x00482a20;
L_0x00482a62:
    // 00482a62  68d8404800             -push 0x4840d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4735192 /*0x4840d8*/;
    cpu.esp -= 4;
    // 00482a67  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482a68  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482a6a  a398bb5100             -mov dword ptr [0x51bb98], eax
    *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */) = cpu.eax;
    // 00482a6f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482a71  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482a73  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482a75  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482a76  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482a79  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00482a7e  7423                   -je 0x482aa3
    if (cpu.flags.zf)
    {
        goto L_0x00482aa3;
    }
    // 00482a80  b88ce64b00             -mov eax, 0x4be68c
    cpu.eax = 4974220 /*0x4be68c*/;
    // 00482a85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482a87  0f8430ffffff           -je 0x4829bd
    if (cpu.flags.zf)
    {
        goto L_0x004829bd;
    }
    // 00482a8d  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 00482a92  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482a94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482a96  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482a9c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a9d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a9e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482a9f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482aa0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482aa1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482aa2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482aa3:
    // 00482aa3  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00482aa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00482aa8  740e                   -je 0x482ab8
    if (cpu.flags.zf)
    {
        goto L_0x00482ab8;
    }
    // 00482aaa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00482aac  e81b60ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00482ab1  c7461000000000         -mov dword ptr [esi + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x00482ab8:
    // 00482ab8  a198bb5100             -mov eax, dword ptr [0x51bb98]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */);
    // 00482abd  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00482ac0  83f810                 +cmp eax, 0x10
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
    // 00482ac3  7d07                   -jge 0x482acc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00482acc;
    }
    // 00482ac5  c7460810000000         -mov dword ptr [esi + 8], 0x10
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 16 /*0x10*/;
L_0x00482acc:
    // 00482acc  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00482acf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00482ad6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 00482adb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00482add  b8b0e64b00             -mov eax, 0x4be6b0
    cpu.eax = 4974256 /*0x4be6b0*/;
    // 00482ae2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00482ae5  e87e5bffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00482aea  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00482aed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482aef  7523                   -jne 0x482b14
    if (!cpu.flags.zf)
    {
        goto L_0x00482b14;
    }
    // 00482af1  b8bce64b00             -mov eax, 0x4be6bc
    cpu.eax = 4974268 /*0x4be6bc*/;
    // 00482af6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482af8  0f84bffeffff           -je 0x4829bd
    if (cpu.flags.zf)
    {
        goto L_0x004829bd;
    }
L_0x00482afe:
    // 00482afe  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 00482b03  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482b05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482b07  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482b0d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b0e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b0f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b10  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b11  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b12  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b14:
    // 00482b14  68d8404800             -push 0x4840d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4735192 /*0x4840d8*/;
    cpu.esp -= 4;
    // 00482b19  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482b1a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00482b1c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b1d  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482b1f  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00482b21  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482b23  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b24  892d94bb5100           -mov dword ptr [0x51bb94], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5356436) /* 0x51bb94 */) = cpu.ebp;
    // 00482b2a  892d98bb5100           -mov dword ptr [0x51bb98], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */) = cpu.ebp;
    // 00482b30  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482b33  c7462800030000         -mov dword ptr [esi + 0x28], 0x300
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 768 /*0x300*/;
    // 00482b3a  c7462c00010000         -mov dword ptr [esi + 0x2c], 0x100
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 256 /*0x100*/;
    // 00482b41  a198bb5100             -mov eax, dword ptr [0x51bb98]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */);
    // 00482b46  8a965d040000           -mov dl, byte ptr [esi + 0x45d]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 00482b4c  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00482b4f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00482b51  7539                   -jne 0x482b8c
    if (!cpu.flags.zf)
    {
        goto L_0x00482b8c;
    }
    // 00482b53  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482b57  7533                   -jne 0x482b8c
    if (!cpu.flags.zf)
    {
        goto L_0x00482b8c;
    }
    // 00482b59  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b5a  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482b5d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482b5e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482b60  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b61  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482b63  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b64  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482b67  8b8e54040000           -mov ecx, dword ptr [esi + 0x454]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 00482b6d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482b6e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482b71  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482b72  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482b74  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482b75  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482b78  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482b7d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00482b7f  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482b85  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b86  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b87  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b88  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b89  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b8a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482b8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482b8c:
    // 00482b8c  c7460400000000         -mov dword ptr [esi + 4], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00482b93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482b98  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00482b9a  893dd0884c00           -mov dword ptr [0x4c88d0], edi
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.edi;
    // 00482ba0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_482ba8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482ba8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482ba9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482baa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482bab  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482bac  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482bad  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482bae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00482bb0  83b84404000000         +cmp dword ptr [eax + 0x444], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482bb7  740c                   -je 0x482bc5
    if (cpu.flags.zf)
    {
        goto L_0x00482bc5;
    }
    // 00482bb9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482bbb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00482bbd  7406                   -je 0x482bc5
    if (cpu.flags.zf)
    {
        goto L_0x00482bc5;
    }
    // 00482bbf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482bc0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00482bc2  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482bc5:
    // 00482bc5  8bb350040000           -mov esi, dword ptr [ebx + 0x450]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */);
    // 00482bcb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00482bcd  7407                   -je 0x482bd6
    if (cpu.flags.zf)
    {
        goto L_0x00482bd6;
    }
    // 00482bcf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482bd1  e872880100             -call 0x49b448
    cpu.esp -= 4;
    sub_49b448(app, cpu);
    if (cpu.terminate) return;
L_0x00482bd6:
    // 00482bd6  8bbb4c040000           -mov edi, dword ptr [ebx + 0x44c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */);
    // 00482bdc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482bde  7407                   -je 0x482be7
    if (cpu.flags.zf)
    {
        goto L_0x00482be7;
    }
    // 00482be0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482be2  e861880100             -call 0x49b448
    cpu.esp -= 4;
    sub_49b448(app, cpu);
    if (cpu.terminate) return;
L_0x00482be7:
    // 00482be7  c7835004000000000000   -mov dword ptr [ebx + 0x450], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */) = 0 /*0x0*/;
    // 00482bf1  8bab48040000           -mov ebp, dword ptr [ebx + 0x448]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */);
    // 00482bf7  c7834c04000000000000   -mov dword ptr [ebx + 0x44c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */) = 0 /*0x0*/;
    // 00482c01  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00482c03  7409                   -je 0x482c0e
    if (cpu.flags.zf)
    {
        goto L_0x00482c0e;
    }
    // 00482c05  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00482c07  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482c09  e87a100000             -call 0x483c88
    cpu.esp -= 4;
    sub_483c88(app, cpu);
    if (cpu.terminate) return;
L_0x00482c0e:
    // 00482c0e  8b8344040000           -mov eax, dword ptr [ebx + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 00482c14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482c16  7520                   -jne 0x482c38
    if (!cpu.flags.zf)
    {
        goto L_0x00482c38;
    }
L_0x00482c18:
    // 00482c18  c7834804000000000000   -mov dword ptr [ebx + 0x448], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */) = 0 /*0x0*/;
    // 00482c22  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00482c27  c7834404000000000000   -mov dword ptr [ebx + 0x444], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */) = 0 /*0x0*/;
    // 00482c31  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c32  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c33  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c34  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c35  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c36  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482c37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482c38:
    // 00482c38  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00482c3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00482c3c  e847100000             -call 0x483c88
    cpu.esp -= 4;
    sub_483c88(app, cpu);
    if (cpu.terminate) return;
    // 00482c41  ebd5                   -jmp 0x482c18
    goto L_0x00482c18;
}

/* align: skip 0x90 */
void Application::sub_482c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00482c44  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00482c45  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482c46  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482c47  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00482c48  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482c49  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00482c4a  81ec44030000           -sub esp, 0x344
    (cpu.esp) -= x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00482c50  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00482c52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00482c54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482c56  7505                   -jne 0x482c5d
    if (!cpu.flags.zf)
    {
        goto L_0x00482c5d;
    }
    // 00482c58  be30b15100             -mov esi, 0x51b130
    cpu.esi = 5353776 /*0x51b130*/;
L_0x00482c5d:
    // 00482c5d  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00482c62  e8a1c3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00482c67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482c69  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 00482c6e  e835ffffff             -call 0x482ba8
    cpu.esp -= 4;
    sub_482ba8(app, cpu);
    if (cpu.terminate) return;
    // 00482c73  8994246c010000         -mov dword ptr [esp + 0x16c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.edx;
    // 00482c7a  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00482c7d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00482c7f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482c80  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00482c87  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482c89  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482c8a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482c8c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482c8d  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482c90  8aa637040000           -mov ah, byte ptr [esi + 0x437]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00482c96  80fc01                 +cmp ah, 1
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
    // 00482c99  0f8340010000           -jae 0x482ddf
    if (!cpu.flags.cf)
    {
        goto L_0x00482ddf;
    }
    // 00482c9f  c6863704000001         -mov byte ptr [esi + 0x437], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 1 /*0x1*/;
L_0x00482ca6:
    // 00482ca6  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 00482cae  0f8462010000           -je 0x482e16
    if (cpu.flags.zf)
    {
        goto L_0x00482e16;
    }
    // 00482cb4  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00482cb6:
    // 00482cb6  888660040000           -mov byte ptr [esi + 0x460], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */) = cpu.al;
    // 00482cbc  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 00482cc4  0f8453010000           -je 0x482e1d
    if (cpu.flags.zf)
    {
        goto L_0x00482e1d;
    }
    // 00482cca  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x00482ccc:
    // 00482ccc  8aae5e040000           -mov ch, byte ptr [esi + 0x45e]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
    // 00482cd2  888662040000           -mov byte ptr [esi + 0x462], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */) = cpu.al;
    // 00482cd8  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00482cda  0f8544010000           -jne 0x482e24
    if (!cpu.flags.zf)
    {
        goto L_0x00482e24;
    }
    // 00482ce0  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482ce7  740e                   -je 0x482cf7
    if (cpu.flags.zf)
    {
        goto L_0x00482cf7;
    }
    // 00482ce9  c6863504000001         -mov byte ptr [esi + 0x435], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 00482cf0  c6863404000001         -mov byte ptr [esi + 0x434], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */) = 1 /*0x1*/;
L_0x00482cf7:
    // 00482cf7  81fe30b15100           +cmp esi, 0x51b130
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5353776 /*0x51b130*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482cfd  7503                   -jne 0x482d02
    if (!cpu.flags.zf)
    {
        goto L_0x00482d02;
    }
    // 00482cff  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00482d02:
    // 00482d02  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482d09  762f                   -jbe 0x482d3a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482d3a;
    }
    // 00482d0b  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482d12  0f8430010000           -je 0x482e48
    if (cpu.flags.zf)
    {
        goto L_0x00482e48;
    }
L_0x00482d18:
    // 00482d18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00482d1d:
    // 00482d1d  80be6004000000         +cmp byte ptr [esi + 0x460], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482d24  0f8532010000           -jne 0x482e5c
    if (!cpu.flags.zf)
    {
        goto L_0x00482e5c;
    }
    // 00482d2a  80be6204000000         +cmp byte ptr [esi + 0x462], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482d31  0f8425010000           -je 0x482e5c
    if (cpu.flags.zf)
    {
        goto L_0x00482e5c;
    }
L_0x00482d37:
    // 00482d37  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00482d3a:
    // 00482d3a  8b7e24                 -mov edi, dword ptr [esi + 0x24]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482d3d  8d4630                 -lea eax, [esi + 0x30]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00482d40  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482d42  0f852e010000           -jne 0x482e76
    if (!cpu.flags.zf)
    {
        goto L_0x00482e76;
    }
    // 00482d48  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482d49  8d7e24                 -lea edi, [esi + 0x24]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00482d4c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482d4d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482d4e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00482d50  6a44                   -push 0x44
    *app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 00482d52  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00482d54  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482d55  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482d58:
    // 00482d58  66c786300400000000     -mov word ptr [esi + 0x430], 0
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 00482d61  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482d63  66c78632040000ff00     -mov word ptr [esi + 0x432], 0xff
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
    // 00482d6c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482d6e  c6865f04000000         -mov byte ptr [esi + 0x45f], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 0 /*0x0*/;
    // 00482d75  e866f4ffff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 00482d7a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00482d7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482d7e  0f8507010000           -jne 0x482e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00482e8b;
    }
    // 00482d84  c6865f04000001         -mov byte ptr [esi + 0x45f], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 1 /*0x1*/;
L_0x00482d8b:
    // 00482d8b  c6863704000002         -mov byte ptr [esi + 0x437], 2
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 00482d92  8a8637040000           -mov al, byte ptr [esi + 0x437]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 00482d98  888663040000           -mov byte ptr [esi + 0x463], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = cpu.al;
    // 00482d9e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482da0  7409                   -je 0x482dab
    if (cpu.flags.zf)
    {
        goto L_0x00482dab;
    }
    // 00482da2  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00482da4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482da6  e8dd0e0000             -call 0x483c88
    cpu.esp -= 4;
    sub_483c88(app, cpu);
    if (cpu.terminate) return;
L_0x00482dab:
    // 00482dab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00482dad  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482daf  e82cf4ffff             -call 0x4821e0
    cpu.esp -= 4;
    sub_4821e0(app, cpu);
    if (cpu.terminate) return;
    // 00482db4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00482db6:
    // 00482db6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00482db8  0f8534010000           -jne 0x482ef2
    if (!cpu.flags.zf)
    {
        goto L_0x00482ef2;
    }
    // 00482dbe  b86ce74b00             -mov eax, 0x4be76c
    cpu.eax = 4974444 /*0x4be76c*/;
    // 00482dc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482dc5  0f850e010000           -jne 0x482ed9
    if (!cpu.flags.zf)
    {
        goto L_0x00482ed9;
    }
    // 00482dcb  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 00482dd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482dd2  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00482dd8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dd9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dda  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ddb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ddc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ddd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ddf:
    // 00482ddf  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482de2  0f86befeffff           -jbe 0x482ca6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482ca6;
    }
    // 00482de8  b848e74b00             -mov eax, 0x4be748
    cpu.eax = 4974408 /*0x4be748*/;
    // 00482ded  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482def  751e                   -jne 0x482e0f
    if (!cpu.flags.zf)
    {
        goto L_0x00482e0f;
    }
L_0x00482df1:
    // 00482df1  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 00482df6  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00482dfb  e820c2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00482e00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482e02  81c444030000           +add esp, 0x344
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(836 /*0x344*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00482e08  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e09  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e0a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e0b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e0c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e0d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482e0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482e0f:
    // 00482e0f  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 00482e14  ebdb                   -jmp 0x482df1
    goto L_0x00482df1;
L_0x00482e16:
    // 00482e16  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00482e18  e999feffff             -jmp 0x482cb6
    goto L_0x00482cb6;
L_0x00482e1d:
    // 00482e1d  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00482e1f  e9a8feffff             -jmp 0x482ccc
    goto L_0x00482ccc;
L_0x00482e24:
    // 00482e24  c6863604000000         -mov byte ptr [esi + 0x436], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */) = 0 /*0x0*/;
    // 00482e2b  c6863504000001         -mov byte ptr [esi + 0x435], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 00482e32  c6863704000002         -mov byte ptr [esi + 0x437], 2
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 00482e39  80cf2a                 +or bh, 0x2a
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(42 /*0x2a*/))));
    // 00482e3c  c6866304000001         -mov byte ptr [esi + 0x463], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 00482e43  e9affeffff             -jmp 0x482cf7
    goto L_0x00482cf7;
L_0x00482e48:
    // 00482e48  80be3404000000         +cmp byte ptr [esi + 0x434], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482e4f  0f85c3feffff           -jne 0x482d18
    if (!cpu.flags.zf)
    {
        goto L_0x00482d18;
    }
    // 00482e55  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00482e57  e9c1feffff             -jmp 0x482d1d
    goto L_0x00482d1d;
L_0x00482e5c:
    // 00482e5c  80be5e04000000         +cmp byte ptr [esi + 0x45e], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482e63  7408                   -je 0x482e6d
    if (cpu.flags.zf)
    {
        goto L_0x00482e6d;
    }
L_0x00482e65:
    // 00482e65  80cf40                 +or bh, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00482e68  e9cdfeffff             -jmp 0x482d3a
    goto L_0x00482d3a;
L_0x00482e6d:
    // 00482e6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00482e6f  74f4                   -je 0x482e65
    if (cpu.flags.zf)
    {
        goto L_0x00482e65;
    }
    // 00482e71  e9c1feffff             -jmp 0x482d37
    goto L_0x00482d37;
L_0x00482e76:
    // 00482e76  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482e77  6800010000             -push 0x100
    *app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00482e7c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482e7e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00482e80  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi);
    // 00482e82  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482e83  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482e86  e9cdfeffff             -jmp 0x482d58
    goto L_0x00482d58;
L_0x00482e8b:
    // 00482e8b  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00482e92  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 00482e97  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482e98  89ac24dc020000         -mov dword ptr [esp + 0x2dc], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ebp;
    // 00482e9f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482ea0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482ea2  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482ea5  f684244203000020       +test byte ptr [esp + 0x342], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(834) /* 0x342 */) & 32 /*0x20*/));
    // 00482ead  7415                   -je 0x482ec4
    if (cpu.flags.zf)
    {
        goto L_0x00482ec4;
    }
    // 00482eaf  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00482eb1  88865f040000           -mov byte ptr [esi + 0x45f], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 00482eb7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00482eb9  0f85ccfeffff           -jne 0x482d8b
    if (!cpu.flags.zf)
    {
        goto L_0x00482d8b;
    }
    // 00482ebf  e9f2feffff             -jmp 0x482db6
    goto L_0x00482db6;
L_0x00482ec4:
    // 00482ec4  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00482ec6  88865f040000           -mov byte ptr [esi + 0x45f], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 00482ecc  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00482ece  0f85b7feffff           -jne 0x482d8b
    if (!cpu.flags.zf)
    {
        goto L_0x00482d8b;
    }
    // 00482ed4  e9ddfeffff             -jmp 0x482db6
    goto L_0x00482db6;
L_0x00482ed9:
    // 00482ed9  b828e64b00             -mov eax, 0x4be628
    cpu.eax = 4974120 /*0x4be628*/;
    // 00482ede  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 00482ee3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00482ee5  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 00482eeb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eec  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eed  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eee  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482eef  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00482ef1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00482ef2:
    // 00482ef2  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482ef6  7413                   -je 0x482f0b
    if (cpu.flags.zf)
    {
        goto L_0x00482f0b;
    }
    // 00482ef8  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482eff  750a                   -jne 0x482f0b
    if (!cpu.flags.zf)
    {
        goto L_0x00482f0b;
    }
    // 00482f01  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00482f04  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f05  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 00482f07  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482f08  ff5070                 -call dword ptr [eax + 0x70]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00482f0b:
    // 00482f0b  8d8424d8020000         -lea eax, [esp + 0x2d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00482f12  b96c000000             -mov ecx, 0x6c
    cpu.ecx = 108 /*0x6c*/;
    // 00482f17  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482f18  898c24dc020000         -mov dword ptr [esp + 0x2dc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ecx;
    // 00482f1f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482f20  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi);
    // 00482f22  8d9c24e0020000         -lea ebx, [esp + 0x2e0]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 00482f29  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482f2c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00482f31  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00482f33  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00482f36  e859f5ffff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 00482f3b  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 00482f41  89be44040000           -mov dword ptr [esi + 0x444], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */) = cpu.edi;
    // 00482f47  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00482f49  0f8602010000           -jbe 0x483051
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483051;
    }
    // 00482f4f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00482f51  e8660d0000             -call 0x483cbc
    cpu.esp -= 4;
    sub_483cbc(app, cpu);
    if (cpu.terminate) return;
L_0x00482f56:
    // 00482f56  898648040000           -mov dword ptr [esi + 0x448], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x00482f5c:
    // 00482f5c  83be4404000000         +cmp dword ptr [esi + 0x444], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482f63  745a                   -je 0x482fbf
    if (cpu.flags.zf)
    {
        goto L_0x00482fbf;
    }
    // 00482f65  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 00482f70  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00482f73  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00482f7a  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 00482f81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00482f82  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00482f88  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482f89  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482f8b  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482f8e  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00482f94  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482f95  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00482f9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00482f9e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482f9f  8b9c24f0020000         -mov ebx, dword ptr [esp + 0x2f0]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(752) /* 0x2f0 */);
    // 00482fa6  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 00482fac  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00482fae  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00482fb1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00482fb4  e86f830100             -call 0x49b328
    cpu.esp -= 4;
    sub_49b328(app, cpu);
    if (cpu.terminate) return;
    // 00482fb9  89864c040000           -mov dword ptr [esi + 0x44c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1100) /* 0x44c */) = cpu.eax;
L_0x00482fbf:
    // 00482fbf  83be4804000000         +cmp dword ptr [esi + 0x448], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00482fc6  0f84f6000000           -je 0x4830c2
    if (cpu.flags.zf)
    {
        goto L_0x004830c2;
    }
    // 00482fcc  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 00482fd7  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00482fda  8d9424d8020000         -lea edx, [esp + 0x2d8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 00482fe1  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 00482fe8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00482fe9  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 00482fef  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00482ff0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00482ff2  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00482ff5  8bbe48040000           -mov edi, dword ptr [esi + 0x448]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 00482ffb  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00482ffc  8bac2400030000         -mov ebp, dword ptr [esp + 0x300]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00483003  8b9c24ec020000         -mov ebx, dword ptr [esp + 0x2ec]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(748) /* 0x2ec */);
    // 0048300a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048300b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048300e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483010  6afe                   -push -2
    *app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 00483012  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00483015  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048301b  e808830100             -call 0x49b328
    cpu.esp -= 4;
    sub_49b328(app, cpu);
    if (cpu.terminate) return;
    // 00483020  898650040000           -mov dword ptr [esi + 0x450], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
L_0x00483026:
    // 00483026  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048302b  e8f0bfffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483030  833d84844c0000         +cmp dword ptr [0x4c8484], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483037  7406                   -je 0x48303f
    if (cpu.flags.zf)
    {
        goto L_0x0048303f;
    }
    // 00483039  ff1584844c00           -call dword ptr [0x4c8484]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048303f:
    // 0048303f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483044  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048304a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048304b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048304c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048304d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048304e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048304f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483050  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483051:
    // 00483051  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483058  0f85fefeffff           -jne 0x482f5c
    if (!cpu.flags.zf)
    {
        goto L_0x00482f5c;
    }
    // 0048305e  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483065  0f86f1feffff           -jbe 0x482f5c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00482f5c;
    }
    // 0048306b  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483072  742b                   -je 0x48309f
    if (cpu.flags.zf)
    {
        goto L_0x0048309f;
    }
L_0x00483074:
    // 00483074  8b9e48040000           -mov ebx, dword ptr [esi + 0x448]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048307a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048307c  0f85dafeffff           -jne 0x482f5c
    if (!cpu.flags.zf)
    {
        goto L_0x00482f5c;
    }
    // 00483082  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483083  6840080000             -push 0x840
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2112 /*0x840*/;
    cpu.esp -= 4;
    // 00483088  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483089  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048308b  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048308e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048308f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00483092  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00483095  e8fa090000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 0048309a  e9b7feffff             -jmp 0x482f56
    goto L_0x00482f56;
L_0x0048309f:
    // 0048309f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004830a1  6840400000             -push 0x4040
    *app->getMemory<x86::reg32>(cpu.esp-4) = 16448 /*0x4040*/;
    cpu.esp -= 4;
    // 004830a6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004830a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004830aa  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004830ad  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004830af  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004830b2  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004830b5  e8da090000             -call 0x483a94
    cpu.esp -= 4;
    sub_483a94(app, cpu);
    if (cpu.terminate) return;
    // 004830ba  898648040000           -mov dword ptr [esi + 0x448], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
    // 004830c0  ebb2                   -jmp 0x483074
    goto L_0x00483074;
L_0x004830c2:
    // 004830c2  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004830c9  0f8657ffffff           -jbe 0x483026
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00483026;
    }
    // 004830cf  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004830d2  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004830d5  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004830d7  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004830da  8a9e5c040000           -mov bl, byte ptr [esi + 0x45c]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 004830e0  bf40854c00             -mov edi, 0x4c8540
    cpu.edi = 5014848 /*0x4c8540*/;
    // 004830e5  e866da0000             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 004830ea  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004830ef  898650040000           -mov dword ptr [esi + 0x450], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
    // 004830f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004830f7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004830f9  e928ffffff             -jmp 0x483026
    goto L_0x00483026;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483100  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483101  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483102  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483103  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483104  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483105  81ec8c040000           -sub esp, 0x48c
    (cpu.esp) -= x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 0048310b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048310d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048310f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00483111  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483113  7505                   -jne 0x48311a
    if (!cpu.flags.zf)
    {
        goto L_0x0048311a;
    }
    // 00483115  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x0048311a:
    // 0048311a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048311f  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00483126  89942400040000         -mov dword ptr [esp + 0x400], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 0048312d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048312e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00483130  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483131  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483133  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483136  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00483138  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048313f  0f84f0010000           -je 0x483335
    if (cpu.flags.zf)
    {
        goto L_0x00483335;
    }
    // 00483145  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483149  0f843f010000           -je 0x48328e
    if (cpu.flags.zf)
    {
        goto L_0x0048328e;
    }
    // 0048314f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483151  0f8c45010000           -jl 0x48329c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048329c;
    }
    // 00483157  3b7308                 +cmp esi, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048315a  7c02                   -jl 0x48315e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048315e;
    }
    // 0048315c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048315e:
    // 0048315e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00483165  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00483167  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048316a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048316d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048316f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00483172  89942488040000         -mov dword ptr [esp + 0x488], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.edx;
    // 00483179  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048317b  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048317d  8a5012                 -mov dl, byte ptr [eax + 0x12]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 00483180  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00483183  89942484040000         -mov dword ptr [esp + 0x484], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 0048318a  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
L_0x00483191:
    // 00483191  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483195  7433                   -je 0x4831ca
    if (cpu.flags.zf)
    {
        goto L_0x004831ca;
    }
    // 00483197  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0048319c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048319e  e839bfffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 004831a3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004831a5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004831a6  6800010000             -push 0x100
    *app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004831ab  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004831ad  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004831b0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004831b2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004831b4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004831b5  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004831b8  66c783300400000000     -mov word ptr [ebx + 0x430], 0
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 004831c1  66c78332040000ff00     -mov word ptr [ebx + 0x432], 0xff
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
L_0x004831ca:
    // 004831ca  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004831cc  8b8c2480040000         -mov ecx, dword ptr [esp + 0x480]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
    // 004831d3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831d4  8b8c248c040000         -mov ecx, dword ptr [esp + 0x48c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1164) /* 0x48c */);
    // 004831db  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831dc  8b8c2494040000         -mov ecx, dword ptr [esp + 0x494]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */);
    // 004831e3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004831e4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004831e6  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004831e7  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004831e9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004831ea  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004831ed  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004831f2  89842480040000         -mov dword ptr [esp + 0x480], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */) = cpu.eax;
    // 004831f9  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 004831fe  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00483205  89842400040000         -mov dword ptr [esp + 0x400], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0048320c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048320d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0048320f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483210  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483212  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483215  8b94240c040000         -mov edx, dword ptr [esp + 0x40c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 0048321c  39d5                   +cmp ebp, edx
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
    // 0048321e  0f82a3000000           -jb 0x4832c7
    if (cpu.flags.cf)
    {
        goto L_0x004832c7;
    }
    // 00483224  895314                 -mov dword ptr [ebx + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00483227:
    // 00483227  8b842488040000         -mov eax, dword ptr [esp + 0x488]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0048322e  8b8c2408040000         -mov ecx, dword ptr [esp + 0x408]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 00483235  39c8                   +cmp eax, ecx
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
    // 00483237  0f82a3000000           -jb 0x4832e0
    if (cpu.flags.cf)
    {
        goto L_0x004832e0;
    }
    // 0048323d  894b18                 -mov dword ptr [ebx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x00483240:
    // 00483240  83bc248004000000       +cmp dword ptr [esp + 0x480], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483248  0f85b2000000           -jne 0x483300
    if (!cpu.flags.zf)
    {
        goto L_0x00483300;
    }
    // 0048324e  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 00483255  3b842454040000         +cmp eax, dword ptr [esp + 0x454]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048325c  0f859e000000           -jne 0x483300
    if (!cpu.flags.zf)
    {
        goto L_0x00483300;
    }
    // 00483262  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00483267:
    // 00483267  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 0048326e  89431c                 -mov dword ptr [ebx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00483271  6800000080             -push 0x80000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00483276  89730c                 -mov dword ptr [ebx + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00483279  2eff156c534b00         -call dword ptr cs:[0x4b536c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936556) /* 0x4b536c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483280  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00483282  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 00483288  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483289  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048328a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048328b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048328c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048328d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048328e:
    // 0048328e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483290  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 00483296  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483297  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483298  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483299  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048329b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048329c:
    // 0048329c  bd80020000             -mov ebp, 0x280
    cpu.ebp = 640 /*0x280*/;
    // 004832a1  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 004832a6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004832ab  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004832ad  89842488040000         -mov dword ptr [esp + 0x488], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.eax;
    // 004832b4  89942484040000         -mov dword ptr [esp + 0x484], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 004832bb  898c247c040000         -mov dword ptr [esp + 0x47c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.ecx;
    // 004832c2  e9cafeffff             -jmp 0x483191
    goto L_0x00483191;
L_0x004832c7:
    // 004832c7  896b14                 -mov dword ptr [ebx + 0x14], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004832ca  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 004832d1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004832d3  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004832d5  898364040000           -mov dword ptr [ebx + 0x464], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004832db  e947ffffff             -jmp 0x483227
    goto L_0x00483227;
L_0x004832e0:
    // 004832e0  894318                 -mov dword ptr [ebx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004832e3  8bac2488040000         -mov ebp, dword ptr [esp + 0x488]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 004832ea  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 004832f1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004832f3  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004832f5  898368040000           -mov dword ptr [ebx + 0x468], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004832fb  e940ffffff             -jmp 0x483240
    goto L_0x00483240;
L_0x00483300:
    // 00483300  81bc2480040000e1000000 +cmp dword ptr [esp + 0x480], 0xe1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048330b  750a                   -jne 0x483317
    if (!cpu.flags.zf)
    {
        goto L_0x00483317;
    }
    // 0048330d  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00483312  e950ffffff             -jmp 0x483267
    goto L_0x00483267;
L_0x00483317:
    // 00483317  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483319  0f8548ffffff           -jne 0x483267
    if (!cpu.flags.zf)
    {
        goto L_0x00483267;
    }
    // 0048331f  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00483326  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00483329  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048332b  804c820f80             +or byte ptr [edx + eax*4 + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 00483330  e932ffffff             -jmp 0x483267
    goto L_0x00483267;
L_0x00483335:
    // 00483335  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048333c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048333d  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00483343  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483344  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048334b  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00483352  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483353  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00483359  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048335a  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483361  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00483368  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483369  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048336f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483370  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483377  81bb6404000078ecffff   +cmp dword ptr [ebx + 0x464], 0xffffec78
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483381  7d1e                   -jge 0x4833a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004833a1;
    }
    // 00483383  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483385  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048338c  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048338f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483391  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483393  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00483396  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483398  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048339a  8984246c040000         -mov dword ptr [esp + 0x46c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */) = cpu.eax;
L_0x004833a1:
    // 004833a1  81bb6804000078ecffff   +cmp dword ptr [ebx + 0x468], 0xffffec78
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004833ab  7d1e                   -jge 0x4833cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004833cb;
    }
    // 004833ad  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004833af  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004833b6  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004833b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004833bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004833bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004833c0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004833c2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004833c4  89842470040000         -mov dword ptr [esp + 0x470], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */) = cpu.eax;
L_0x004833cb:
    // 004833cb  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004833d2  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004833d5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004833d7  89842474040000         -mov dword ptr [esp + 0x474], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */) = cpu.eax;
    // 004833de  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004833e5  034318                 -add eax, dword ptr [ebx + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004833e8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004833ea  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
    // 004833f1  6af0                   -push -0x10
    *app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004833f3  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004833f9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004833fa  2eff15cc534b00         -call dword ptr cs:[0x4b53cc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936652) /* 0x4b53cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483401  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483402  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00483409  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048340a  2eff1584534b00         -call dword ptr cs:[0x4b5384]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936580) /* 0x4b5384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483411  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 00483418  8b942470040000         -mov edx, dword ptr [esp + 0x470]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048341f  6a14                   -push 0x14
    *app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00483421  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483423  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048342a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048342b  8b84247c040000         -mov eax, dword ptr [esp + 0x47c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */);
    // 00483432  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483434  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483435  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483436  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483437  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483439  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048343f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483440  2eff15fc534b00         -call dword ptr cs:[0x4b53fc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936700) /* 0x4b53fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483447  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048344e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048344f  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00483455  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483456  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048345d  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00483464  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483465  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048346b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048346c  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483473  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048347a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048347b  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 00483481  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483482  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483489  8b842474040000         -mov eax, dword ptr [esp + 0x474]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 00483490  8b94246c040000         -mov edx, dword ptr [esp + 0x46c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 00483497  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00483499  894314                 -mov dword ptr [ebx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048349c  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 004834a3  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004834aa  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004834ac  894318                 -mov dword ptr [ebx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004834af  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 004834b6  898364040000           -mov dword ptr [ebx + 0x464], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004834bc  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 004834c3  898368040000           -mov dword ptr [ebx + 0x468], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004834c9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004834cb  7520                   -jne 0x4834ed
    if (!cpu.flags.zf)
    {
        goto L_0x004834ed;
    }
    // 004834cd  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
L_0x004834d4:
    // 004834d4  89431c                 -mov dword ptr [ebx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004834d7  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004834dc  89730c                 -mov dword ptr [ebx + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004834df  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004834e1  81c48c040000           +add esp, 0x48c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1164 /*0x48c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004834e7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834e8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834e9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834ea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004834ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004834ed:
    // 004834ed  a1ec814c00             -mov eax, dword ptr [0x4c81ec]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004834f2  ebe0                   -jmp 0x4834d4
    goto L_0x004834d4;
}

/* align: skip  */
void Application::sub_4834f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004834f4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004834f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004834f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004834f9  7505                   -jne 0x483500
    if (!cpu.flags.zf)
    {
        goto L_0x00483500;
    }
    // 004834fb  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x00483500:
    // 00483500  833b00                 +cmp dword ptr [ebx], 0
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
    // 00483503  7450                   -je 0x483555
    if (cpu.flags.zf)
    {
        goto L_0x00483555;
    }
    // 00483505  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483506  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483507  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048350c  e8f7baffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00483511  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483513  e890f6ffff             -call 0x482ba8
    cpu.esp -= 4;
    sub_482ba8(app, cpu);
    if (cpu.terminate) return;
    // 00483518  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0048351a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048351b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048351d  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483520  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00483523  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483525  7407                   -je 0x48352e
    if (cpu.flags.zf)
    {
        goto L_0x0048352e;
    }
    // 00483527  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00483529  e89e55ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0048352e:
    // 0048352e  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00483535  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048353c  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00483543  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00483548  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0048354e  e8cdbaffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483553  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483554  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00483555:
    // 00483555  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483558(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483558  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483559  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048355a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048355c  7505                   -jne 0x483563
    if (!cpu.flags.zf)
    {
        goto L_0x00483563;
    }
    // 0048355e  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483563:
    // 00483563  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 00483569  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048356a  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483571  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483572  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483573  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483574(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483574  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483575  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483576  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483579  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048357b  7505                   -jne 0x483582
    if (!cpu.flags.zf)
    {
        goto L_0x00483582;
    }
    // 0048357d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483582:
    // 00483582  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483584  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483586  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483587  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483589  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048358a  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048358d  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00483591  7509                   -jne 0x48359c
    if (!cpu.flags.zf)
    {
        goto L_0x0048359c;
    }
    // 00483593  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483596  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483599  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048359a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048359b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048359c:
    // 0048359c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004835a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004835a4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4835a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004835a8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004835a9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004835ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004835ae  7505                   -jne 0x4835b5
    if (!cpu.flags.zf)
    {
        goto L_0x004835b5;
    }
    // 004835b0  b930b15100             -mov ecx, 0x51b130
    cpu.ecx = 5353776 /*0x51b130*/;
L_0x004835b5:
    // 004835b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004835b7  e830030000             -call 0x4838ec
    cpu.esp -= 4;
    sub_4838ec(app, cpu);
    if (cpu.terminate) return;
    // 004835bc  8b9944040000           -mov ebx, dword ptr [ecx + 0x444]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004835c2  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004835c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004835c6  7420                   -je 0x4835e8
    if (cpu.flags.zf)
    {
        goto L_0x004835e8;
    }
    // 004835c8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004835cd:
    // 004835cd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004835ce  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004835d0  8b9144040000           -mov edx, dword ptr [ecx + 0x444]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 004835d6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004835d7  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004835da  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004835de  750c                   -jne 0x4835ec
    if (!cpu.flags.zf)
    {
        goto L_0x004835ec;
    }
    // 004835e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004835e5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835e6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004835e8:
    // 004835e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004835ea  ebe1                   -jmp 0x4835cd
    goto L_0x004835cd;
L_0x004835ec:
    // 004835ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004835ee  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835ef  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004835f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4835f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004835f4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004835f5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004835f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004835f8  7505                   -jne 0x4835ff
    if (!cpu.flags.zf)
    {
        goto L_0x004835ff;
    }
    // 004835fa  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x004835ff:
    // 004835ff  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483601  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 00483607  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483608  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048360a  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048360d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00483612  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483617  7408                   -je 0x483621
    if (cpu.flags.zf)
    {
        goto L_0x00483621;
    }
    // 00483619  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048361e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048361f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483620  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483621:
    // 00483621  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483623  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483624  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483628(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483628  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483629  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048362a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048362d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048362f  7505                   -jne 0x483636
    if (!cpu.flags.zf)
    {
        goto L_0x00483636;
    }
    // 00483631  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483636:
    // 00483636  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483638  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048363a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048363b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0048363d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048363e  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483641  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483644  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483647  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483648  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483649  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48364c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048364c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048364d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048364f  7505                   -jne 0x483656
    if (!cpu.flags.zf)
    {
        goto L_0x00483656;
    }
    // 00483651  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483656:
    // 00483656  83fa02                 +cmp edx, 2
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
    // 00483659  7512                   -jne 0x48366d
    if (!cpu.flags.zf)
    {
        goto L_0x0048366d;
    }
    // 0048365b  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00483660  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483662  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483664  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483665  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483667  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483668  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048366b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048366c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048366d:
    // 0048366d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483672  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483674  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483676  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483677  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483679  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048367a  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048367d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048367e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483680  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483681  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483683  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483685  7505                   -jne 0x48368c
    if (!cpu.flags.zf)
    {
        goto L_0x0048368c;
    }
    // 00483687  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x0048368c:
    // 0048368c  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483690  0f8476000000           -je 0x48370c
    if (cpu.flags.zf)
    {
        goto L_0x0048370c;
    }
    // 00483696  837b1c08               +cmp dword ptr [ebx + 0x1c], 8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048369a  7f70                   -jg 0x48370c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048370c;
    }
    // 0048369c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048369d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048369e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048369f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004836a0  8b832e040000           -mov eax, dword ptr [ebx + 0x42e]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1070) /* 0x42e */);
    // 004836a6  8b9330040000           -mov edx, dword ptr [ebx + 0x430]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1072) /* 0x430 */);
    // 004836ac  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004836af  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004836b2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004836b4  42                     -inc edx
    (cpu.edx)++;
    // 004836b5  3d00010000             +cmp eax, 0x100
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
    // 004836ba  7d3a                   -jge 0x4836f6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004836f6;
    }
    // 004836bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004836be  7e36                   -jle 0x4836f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004836f6;
    }
    // 004836c0  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004836c7  8d4b30                 -lea ecx, [ebx + 0x30]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004836ca  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004836cc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004836cd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004836ce  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004836cf  8b4b24                 -mov ecx, dword ptr [ebx + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004836d2  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004836d4  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004836d6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004836d7  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004836da  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004836e1  7513                   -jne 0x4836f6
    if (!cpu.flags.zf)
    {
        goto L_0x004836f6;
    }
    // 004836e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004836e4  6800010000             -push 0x100
    *app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004836e9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004836eb  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004836ee  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004836f0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004836f2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004836f3  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004836f6:
    // 004836f6  66c783300400000001     -mov word ptr [ebx + 0x430], 0x100
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004836ff  66c78332040000ffff     -mov word ptr [ebx + 0x432], 0xffff
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 00483708  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483709  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048370a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048370b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048370c:
    // 0048370c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048370d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483710  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483711  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483712  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483713  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00483719  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048371b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048371d  7505                   -jne 0x483724
    if (!cpu.flags.zf)
    {
        goto L_0x00483724;
    }
    // 0048371f  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483724:
    // 00483724  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00483727  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483729  7454                   -je 0x48377f
    if (cpu.flags.zf)
    {
        goto L_0x0048377f;
    }
    // 0048372b  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048372d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048372e  6800010000             -push 0x100
    *app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00483733  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483735  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483737  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00483739  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048373b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048373c  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048373f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00483741  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00483743:
    // 00483743  0fb63484               -movzx esi, byte ptr [esp + eax*4]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 4));
    // 00483747  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483749  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0048374c  8a5c8401               -mov bl, byte ptr [esp + eax*4 + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 4);
    // 00483750  81ce000000ff           -or esi, 0xff000000
    cpu.esi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00483756  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00483759  8a548402               -mov dl, byte ptr [esp + eax*4 + 2]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 0048375d  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048375f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00483765  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483768  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0048376a  40                     -inc eax
    (cpu.eax)++;
    // 0048376b  8951fc                 -mov dword ptr [ecx - 4], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048376e  3d00010000             +cmp eax, 0x100
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
    // 00483773  7cce                   -jl 0x483743
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00483743;
    }
    // 00483775  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048377b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048377c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048377d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048377e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048377f:
    // 0048377f  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00483784  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00483786  e851b9ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0048378b  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00483791  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483792  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483793  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483794  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483798(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483798  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483799  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048379a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048379b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048379c  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048379f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004837a1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004837a3  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004837a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004837a7  7505                   -jne 0x4837ae
    if (!cpu.flags.zf)
    {
        goto L_0x004837ae;
    }
    // 004837a9  be30b15100             -mov esi, 0x51b130
    cpu.esi = 5353776 /*0x51b130*/;
L_0x004837ae:
    // 004837ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004837b0  7408                   -je 0x4837ba
    if (cpu.flags.zf)
    {
        goto L_0x004837ba;
    }
    // 004837b2  3bbe3c040000           +cmp edi, dword ptr [esi + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004837b8  7429                   -je 0x4837e3
    if (cpu.flags.zf)
    {
        goto L_0x004837e3;
    }
L_0x004837ba:
    // 004837ba  83be3c04000000         +cmp dword ptr [esi + 0x43c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004837c1  7407                   -je 0x4837ca
    if (cpu.flags.zf)
    {
        goto L_0x004837ca;
    }
    // 004837c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004837c5  e822010000             -call 0x4838ec
    cpu.esp -= 4;
    sub_4838ec(app, cpu);
    if (cpu.terminate) return;
L_0x004837ca:
    // 004837ca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004837cc  751c                   -jne 0x4837ea
    if (!cpu.flags.zf)
    {
        goto L_0x004837ea;
    }
L_0x004837ce:
    // 004837ce  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004837d0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004837d5  892d44824c00           -mov dword ptr [0x4c8244], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5014084) /* 0x4c8244 */) = cpu.ebp;
L_0x004837db:
    // 004837db  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004837de  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837df  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837e0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837e1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004837e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004837e3:
    // 004837e3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004837e8  ebf1                   -jmp 0x4837db
    goto L_0x004837db;
L_0x004837ea:
    // 004837ea  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004837ef  e814b8ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004837f4  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004837fb  756c                   -jne 0x483869
    if (!cpu.flags.zf)
    {
        goto L_0x00483869;
    }
L_0x004837fd:
    // 004837fd  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004837ff  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00483801  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483803  e8c0eaffff             -call 0x4822c8
    cpu.esp -= 4;
    sub_4822c8(app, cpu);
    if (cpu.terminate) return;
    // 00483808  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048380a:
    // 0048380a  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483811  a30c914c00             -mov dword ptr [0x4c910c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017868) /* 0x4c910c */) = cpu.eax;
    // 00483816  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483818  745f                   -je 0x483879
    if (cpu.flags.zf)
    {
        goto L_0x00483879;
    }
    // 0048381a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048381f  8b1508914c00           -mov edx, dword ptr [0x4c9108]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017864) /* 0x4c9108 */);
    // 00483825  a300914c00             -mov dword ptr [0x4c9100], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017856) /* 0x4c9100 */) = cpu.eax;
    // 0048382a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048382c  7408                   -je 0x483836
    if (cpu.flags.zf)
    {
        goto L_0x00483836;
    }
    // 0048382e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483830  890d08914c00           -mov dword ptr [0x4c9108], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5017864) /* 0x4c9108 */) = cpu.ecx;
L_0x00483836:
    // 00483836  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048383b  c7864004000000000000   -mov dword ptr [esi + 0x440], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00483845  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048384a  c7863c04000000000000   -mov dword ptr [esi + 0x43c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 00483854  e8c7b7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483859  891d44824c00           -mov dword ptr [0x4c8244], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014084) /* 0x4c8244 */) = cpu.ebx;
    // 0048385f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483861  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483864  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483865  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483866  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483867  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483869:
    // 00483869  e86a49ffff             -call 0x4781d8
    cpu.esp -= 4;
    sub_4781d8(app, cpu);
    if (cpu.terminate) return;
    // 0048386e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483870  758b                   -jne 0x4837fd
    if (!cpu.flags.zf)
    {
        goto L_0x004837fd;
    }
    // 00483872  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 00483877  eb91                   -jmp 0x48380a
    goto L_0x0048380a;
L_0x00483879:
    // 00483879  833d08914c0000         +cmp dword ptr [0x4c9108], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017864) /* 0x4c9108 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483880  750a                   -jne 0x48388c
    if (!cpu.flags.zf)
    {
        goto L_0x0048388c;
    }
    // 00483882  c70508914c0001000000   -mov dword ptr [0x4c9108], 1
    *app->getMemory<x86::reg32>(x86::reg32(5017864) /* 0x4c9108 */) = 1 /*0x1*/;
L_0x0048388c:
    // 0048388c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483890  898640040000           -mov dword ptr [esi + 0x440], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.eax;
    // 00483896  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 0048389c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048389e  0f842affffff           -je 0x4837ce
    if (cpu.flags.zf)
    {
        goto L_0x004837ce;
    }
    // 004838a4  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004838a8  8a8e5d040000           -mov cl, byte ptr [esi + 0x45d]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 004838ae  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004838b2  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004838b4  7529                   -jne 0x4838df
    if (!cpu.flags.zf)
    {
        goto L_0x004838df;
    }
    // 004838b6  3bbe44040000           +cmp edi, dword ptr [esi + 0x444]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004838bc  7521                   -jne 0x4838df
    if (!cpu.flags.zf)
    {
        goto L_0x004838df;
    }
    // 004838be  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004838c2  8b9e64040000           -mov ebx, dword ptr [esi + 0x464]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1124) /* 0x464 */);
    // 004838c8  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004838cb  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004838ce  8b8668040000           -mov eax, dword ptr [esi + 0x468]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1128) /* 0x468 */);
    // 004838d4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004838d7  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004838db  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004838dd  01fb                   +add ebx, edi
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
L_0x004838df:
    // 004838df  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004838e1  e8ce7a0100             -call 0x49b3b4
    cpu.esp -= 4;
    sub_49b3b4(app, cpu);
    if (cpu.terminate) return;
    // 004838e6  e9e3feffff             -jmp 0x4837ce
    goto L_0x004837ce;
}

/* align: skip 0x90 */
void Application::sub_4838ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004838ec  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004838ed  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004838ee  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004838ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004838f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004838f3  7505                   -jne 0x4838fa
    if (!cpu.flags.zf)
    {
        goto L_0x004838fa;
    }
    // 004838f5  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x004838fa:
    // 004838fa  8b933c040000           -mov edx, dword ptr [ebx + 0x43c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
    // 00483900  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483902  750c                   -jne 0x483910
    if (!cpu.flags.zf)
    {
        goto L_0x00483910;
    }
    // 00483904  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483906  893544824c00           -mov dword ptr [0x4c8244], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014084) /* 0x4c8244 */) = cpu.esi;
    // 0048390c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048390d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048390e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048390f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483910:
    // 00483910  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483911  8b8b40040000           -mov ecx, dword ptr [ebx + 0x440]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */);
    // 00483917  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483918  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048391a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0048391c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048391d  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483923  c7833c04000000000000   -mov dword ptr [ebx + 0x43c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 0048392d  c7834004000000000000   -mov dword ptr [ebx + 0x440], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00483937  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048393e  8b1d0c914c00           -mov ebx, dword ptr [0x4c910c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017868) /* 0x4c910c */);
    // 00483944  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00483946  8b1d04914c00           -mov ebx, dword ptr [0x4c9104]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017860) /* 0x4c9104 */);
    // 0048394c  a300914c00             -mov dword ptr [0x4c9100], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017856) /* 0x4c9100 */) = cpu.eax;
    // 00483951  39d8                   +cmp eax, ebx
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
    // 00483953  7e05                   -jle 0x48395a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048395a;
    }
    // 00483955  a304914c00             -mov dword ptr [0x4c9104], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017860) /* 0x4c9104 */) = cpu.eax;
L_0x0048395a:
    // 0048395a  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0048395f  e8bcb6ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483964  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483965  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00483967  893544824c00           -mov dword ptr [0x4c8244], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014084) /* 0x4c8244 */) = cpu.esi;
    // 0048396d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048396e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048396f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483970  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483974(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483974  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483975  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483976  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483977  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483978  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483979  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048397a  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048397d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048397f  8b903c040000           -mov edx, dword ptr [eax + 0x43c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */);
    // 00483985  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483987  750f                   -jne 0x483998
    if (!cpu.flags.zf)
    {
        goto L_0x00483998;
    }
    // 00483989  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048398e  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483991  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483992  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483993  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483994  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483995  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483996  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483997  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483998:
    // 00483998  8b8e40040000           -mov ecx, dword ptr [esi + 0x440]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */);
    // 0048399e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048399f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004839a1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004839a2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004839a4  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004839aa  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004839b1  8b1d0c914c00           -mov ebx, dword ptr [0x4c910c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017868) /* 0x4c910c */);
    // 004839b7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004839b9  8b1d04914c00           -mov ebx, dword ptr [0x4c9104]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017860) /* 0x4c9104 */);
    // 004839bf  a300914c00             -mov dword ptr [0x4c9100], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017856) /* 0x4c9100 */) = cpu.eax;
    // 004839c4  39d8                   +cmp eax, ebx
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
    // 004839c6  7e05                   -jle 0x4839cd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004839cd;
    }
    // 004839c8  a304914c00             -mov dword ptr [0x4c9104], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017860) /* 0x4c9104 */) = cpu.eax;
L_0x004839cd:
    // 004839cd  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004839d2  e849b6ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004839d7  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004839dc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004839de  e825b6ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004839e3  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004839ea  a30c914c00             -mov dword ptr [0x4c910c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017868) /* 0x4c910c */) = cpu.eax;
    // 004839ef  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004839f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004839f3  e8d0e8ffff             -call 0x4822c8
    cpu.esp -= 4;
    sub_4822c8(app, cpu);
    if (cpu.terminate) return;
    // 004839f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004839fa  7516                   -jne 0x483a12
    if (!cpu.flags.zf)
    {
        goto L_0x00483a12;
    }
    // 004839fc  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483a00  3bae40040000           +cmp ebp, dword ptr [esi + 0x440]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483a06  743e                   -je 0x483a46
    if (cpu.flags.zf)
    {
        goto L_0x00483a46;
    }
    // 00483a08  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483a09  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 00483a0b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483a0c  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00483a12:
    // 00483a12  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483a14  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00483a19  898e40040000           -mov dword ptr [esi + 0x440], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.ecx;
    // 00483a1f  890d00914c00           -mov dword ptr [0x4c9100], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5017856) /* 0x4c9100 */) = cpu.ecx;
    // 00483a25  898e3c040000           -mov dword ptr [esi + 0x43c], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.ecx;
    // 00483a2b  e8f0b5ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483a30  a14c824c00             -mov eax, dword ptr [0x4c824c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */);
    // 00483a35  e80e2affff             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 00483a3a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483a3c  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483a3f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a40  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a41  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a42  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a43  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a44  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483a46:
    // 00483a46  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483a4b  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 00483a51  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483a54  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a55  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a56  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a57  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a58  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a59  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483a5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483a5c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483a5d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483a5e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483a5f  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483a62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00483a64  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00483a66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483a68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483a6a  e859e8ffff             -call 0x4822c8
    cpu.esp -= 4;
    sub_4822c8(app, cpu);
    if (cpu.terminate) return;
    // 00483a6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483a71  7507                   -jne 0x483a7a
    if (!cpu.flags.zf)
    {
        goto L_0x00483a7a;
    }
    // 00483a73  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483a76  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a78  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483a7a:
    // 00483a7a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483a7e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483a7f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00483a81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483a82  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483a88  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483a8d  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483a90  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a91  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a92  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483a93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483a94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483a94  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483a95  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483a96  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483a97  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00483a9a  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00483aa1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483aa3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00483aa5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483aa7  8b9c2494000000         -mov ebx, dword ptr [esp + 0x94]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00483aae  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483ab0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483ab2  89442478               -mov dword ptr [esp + 0x78], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00483ab6  89542474               -mov dword ptr [esp + 0x74], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00483aba  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00483abf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483ac1  e816b6ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00483ac6  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 00483acb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00483ad0  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00483ad3  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00483ad7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483ad9  7e10                   -jle 0x483aeb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00483aeb;
    }
    // 00483adb  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00483ae0  894c2414               -mov dword ptr [esp + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00483ae4  80cb18                 -or bl, 0x18
    cpu.bl |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 00483ae7  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00483aeb:
    // 00483aeb  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00483aee  7443                   -je 0x483b33
    if (cpu.flags.zf)
    {
        goto L_0x00483b33;
    }
L_0x00483af0:
    // 00483af0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483af2  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483af6  895c246c               -mov dword ptr [esp + 0x6c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 00483afa  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483afb  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483aff  8b9c2480000000         -mov ebx, dword ptr [esp + 0x80]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00483b06  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483b07  8bac2484000000         -mov ebp, dword ptr [esp + 0x84]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00483b0e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00483b10  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483b11  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483b14  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00483b19  0f8548010000           -jne 0x483c67
    if (!cpu.flags.zf)
    {
        goto L_0x00483c67;
    }
    // 00483b1f  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483b24  755c                   -jne 0x483b82
    if (!cpu.flags.zf)
    {
        goto L_0x00483b82;
    }
    // 00483b26  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483b2a  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00483b2d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b2f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483b30  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00483b33:
    // 00483b33  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00483b36  75b8                   -jne 0x483af0
    if (!cpu.flags.zf)
    {
        goto L_0x00483af0;
    }
    // 00483b38  8a642404               -mov ah, byte ptr [esp + 4]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483b3c  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00483b43  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00483b47  80cc06                 -or ah, 6
    cpu.ah |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 00483b4a  896c240c               -mov dword ptr [esp + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00483b4e  88642404               -mov byte ptr [esp + 4], ah
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 00483b52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483b54  7f9a                   -jg 0x483af0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00483af0;
    }
    // 00483b56  7598                   -jne 0x483af0
    if (!cpu.flags.zf)
    {
        goto L_0x00483af0;
    }
    // 00483b58  8a542405               -mov dl, byte ptr [esp + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 00483b5c  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 00483b61  8d6c2448               -lea ebp, [esp + 0x48]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00483b65  80ca10                 +or dl, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00483b68  897c2448               -mov dword ptr [esp + 0x48], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 00483b6c  88542405               -mov byte ptr [esp + 5], dl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00483b70  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483b71  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00483b77  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483b78  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483b7a  ff5754                 -call dword ptr [edi + 0x54]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483b7d  e96effffff             -jmp 0x483af0
    goto L_0x00483af0;
L_0x00483b82:
    // 00483b82  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00483b87  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00483b89  e87ab4ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00483b8e  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483b92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483b94  e82fe7ffff             -call 0x4822c8
    cpu.esp -= 4;
    sub_4822c8(app, cpu);
    if (cpu.terminate) return;
    // 00483b99  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00483b9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483b9d  7516                   -jne 0x483bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00483bb5;
    }
    // 00483b9f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483ba3  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483ba7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483ba8  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483bac  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483bae  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483baf  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00483bb5:
    // 00483bb5  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00483bba  e861b4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00483bbf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483bc1  0f8585000000           -jne 0x483c4c
    if (!cpu.flags.zf)
    {
        goto L_0x00483c4c;
    }
L_0x00483bc7:
    // 00483bc7  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00483bcc  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483bd0  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483bd3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483bd5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483bd7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483bd8  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483bdc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483bdd  ff5358                 -call dword ptr [ebx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483be0  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00483be5  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483be9  895c2448               -mov dword ptr [esp + 0x48], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 00483bed  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483bef  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00483bf3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483bf4  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483bf8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483bf9  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483bfc  837c245408             +cmp dword ptr [esp + 0x54], 8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c01  7777                   -ja 0x483c7a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00483c7a;
    }
    // 00483c03  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00483c08  8b9c2498000000         -mov ebx, dword ptr [esp + 0x98]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00483c0f  8954246c               -mov dword ptr [esp + 0x6c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00483c13  89542470               -mov dword ptr [esp + 0x70], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00483c17  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483c19  740f                   -je 0x483c2a
    if (cpu.flags.zf)
    {
        goto L_0x00483c2a;
    }
    // 00483c1b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483c1c  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483c20  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00483c24  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483c25  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483c27  ff507c                 -call dword ptr [eax + 0x7c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00483c2a:
    // 00483c2a  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483c2e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483c30  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00483c34  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483c35  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00483c37  8b6c247c               -mov ebp, dword ptr [esp + 0x7c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00483c3b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483c3c  ff5374                 -call dword ptr [ebx + 0x74]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483c3f  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483c43  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00483c46  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c47  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c48  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c49  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00483c4c:
    // 00483c4c  80be5f04000000         +cmp byte ptr [esi + 0x45f], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00483c53  0f856effffff           -jne 0x483bc7
    if (!cpu.flags.zf)
    {
        goto L_0x00483bc7;
    }
    // 00483c59  8b6c2474               -mov ebp, dword ptr [esp + 0x74]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483c5d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483c61  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483c62  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483c64  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00483c67:
    // 00483c67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483c69  89442474               -mov dword ptr [esp + 0x74], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00483c6d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483c71  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00483c74  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c75  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c76  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483c77  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00483c7a:
    // 00483c7a  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00483c7c  896c246c               -mov dword ptr [esp + 0x6c], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 00483c80  896c2470               -mov dword ptr [esp + 0x70], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 00483c84  eba4                   -jmp 0x483c2a
    goto L_0x00483c2a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483c88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483c88  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483c89  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00483c8b  7505                   -jne 0x483c92
    if (!cpu.flags.zf)
    {
        goto L_0x00483c92;
    }
    // 00483c8d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
L_0x00483c92:
    // 00483c92  3b903c040000           +cmp edx, dword ptr [eax + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483c98  7408                   -je 0x483ca2
    if (cpu.flags.zf)
    {
        goto L_0x00483ca2;
    }
    // 00483c9a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483c9b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00483c9d  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483ca0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ca1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483ca2:
    // 00483ca2  e845fcffff             -call 0x4838ec
    cpu.esp -= 4;
    sub_4838ec(app, cpu);
    if (cpu.terminate) return;
    // 00483ca7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483ca8  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00483caa  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483cad  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483cb0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483cb1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cb2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483cb3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483cb5  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483cb8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cb9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483cba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_483cbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483cbc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483cbd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cbe  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483cc1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483cc3  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483cc6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483cc8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00483ccd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cce  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483cd2  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00483cd6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cd7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483cd9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483cda  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483cdd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483ce0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483ce3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ce4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483ce8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483ce8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483ce9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cea  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483ced  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483cef  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483cf2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483cf4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00483cf9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483cfa  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483cfe  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00483d02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483d03  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483d05  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483d06  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d09  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483d0c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483d0f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d10  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483d14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483d14  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483d15  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483d16  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483d19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00483d1b  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00483d1e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483d20  b900000200             -mov ecx, 0x20000
    cpu.ecx = 131072 /*0x20000*/;
    // 00483d25  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483d26  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483d2a  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00483d2e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483d2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483d31  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483d32  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d35  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483d38  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00483d3b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d3c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_483d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483d40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483d42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483d43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00483d45:
    // 00483d45  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00483d47  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00483d49  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483d4a  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d4d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00483d52  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483d57  74ec                   -je 0x483d45
    if (cpu.flags.zf)
    {
        goto L_0x00483d45;
    }
    // 00483d59  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d5a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d5b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483d5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_483d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483d60  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483d61  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483d62  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483d63  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483d66  8bac2480000000         -mov ebp, dword ptr [esp + 0x80]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00483d6d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00483d6f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483d71  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00483d73  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00483d75  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00483d7a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483d7b  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00483d7f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483d80  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483d82  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483d85  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00483d89  0f8575000000           -jne 0x483e04
    if (!cpu.flags.zf)
    {
        goto L_0x00483e04;
    }
    // 00483d8f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483d91  7406                   -je 0x483d99
    if (cpu.flags.zf)
    {
        goto L_0x00483d99;
    }
    // 00483d93  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00483d97  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00483d99:
    // 00483d99  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483d9b  7406                   -je 0x483da3
    if (cpu.flags.zf)
    {
        goto L_0x00483da3;
    }
    // 00483d9d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00483da1  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00483da3:
    // 00483da3  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00483da7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483da9  7406                   -je 0x483db1
    if (cpu.flags.zf)
    {
        goto L_0x00483db1;
    }
    // 00483dab  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00483daf  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00483db1:
    // 00483db1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483db3  7407                   -je 0x483dbc
    if (cpu.flags.zf)
    {
        goto L_0x00483dbc;
    }
    // 00483db5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00483db9  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00483dbc:
    // 00483dbc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483dbe  740f                   -je 0x483dcf
    if (cpu.flags.zf)
    {
        goto L_0x00483dcf;
    }
    // 00483dc0  837c245410             +cmp dword ptr [esp + 0x54], 0x10
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00483dc5  7411                   -je 0x483dd8
    if (cpu.flags.zf)
    {
        goto L_0x00483dd8;
    }
    // 00483dc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483dc9  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00483dcd  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00483dcf:
    // 00483dcf  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483dd2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dd3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dd4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dd5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00483dd8:
    // 00483dd8  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00483ddc  e893e6ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00483de1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483de3  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00483de7  e888e6ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00483dec  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00483dee  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00483df2  e87de6ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00483df7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00483df9  8933                   -mov dword ptr [ebx], esi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00483dfb  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483dfe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483dff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e00  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e01  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00483e04:
    // 00483e04  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00483e06  7406                   -je 0x483e0e
    if (cpu.flags.zf)
    {
        goto L_0x00483e0e;
    }
    // 00483e08  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x00483e0e:
    // 00483e0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00483e10  7406                   -je 0x483e18
    if (cpu.flags.zf)
    {
        goto L_0x00483e18;
    }
    // 00483e12  c70700000000           -mov dword ptr [edi], 0
    *app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x00483e18:
    // 00483e18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00483e1a  7406                   -je 0x483e22
    if (cpu.flags.zf)
    {
        goto L_0x00483e22;
    }
    // 00483e1c  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00483e22:
    // 00483e22  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00483e26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483e28  7406                   -je 0x483e30
    if (cpu.flags.zf)
    {
        goto L_0x00483e30;
    }
    // 00483e2a  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x00483e30:
    // 00483e30  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00483e32  749b                   -je 0x483dcf
    if (cpu.flags.zf)
    {
        goto L_0x00483dcf;
    }
    // 00483e34  c7450000000000         -mov dword ptr [ebp], 0
    *app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00483e3b  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00483e3e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e3f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e40  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e41  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_483e44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483e44  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e45  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e46  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e49  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483e4b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e4c  68c8f64c00             -push 0x4cf6c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5043912 /*0x4cf6c8*/;
    cpu.esp -= 4;
    // 00483e51  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483e53  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483e54  ff11                   -call dword ptr [ecx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e56  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483e59  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483e5b  7506                   -jne 0x483e63
    if (!cpu.flags.zf)
    {
        goto L_0x00483e63;
    }
    // 00483e5d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e60  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e61  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483e63:
    // 00483e63  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e64  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483e66  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00483e68  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e69  ff9094000000           -call dword ptr [eax + 0x94]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e6f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483e73  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483e77  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483e78  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483e7a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e7d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e7e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e81  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e82  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483e83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483e84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483e84  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00483e85  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e86  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483e89  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00483e8b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483e8c  68c8f64c00             -push 0x4cf6c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5043912 /*0x4cf6c8*/;
    cpu.esp -= 4;
    // 00483e91  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483e93  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483e94  ff11                   -call dword ptr [ecx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483e96  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00483e99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00483e9b  7506                   -jne 0x483ea3
    if (!cpu.flags.zf)
    {
        goto L_0x00483ea3;
    }
    // 00483e9d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483ea0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ea1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ea2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00483ea3:
    // 00483ea3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483ea4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483ea6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00483ea8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00483ea9  ff9098000000           -call dword ptr [eax + 0x98]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483eaf  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483eb3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00483eb7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00483eb8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00483eba  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483ebd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ebe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00483ec1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ec2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483ec3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_483ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483ec4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483ec5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483ec6  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00483ec9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483ecb  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00483ed0  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00483ed7  895c2468               -mov dword ptr [esp + 0x68], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 00483edb  89542464               -mov dword ptr [esp + 0x64], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00483edf  89442450               -mov dword ptr [esp + 0x50], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00483ee3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00483ee5  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00483eec  8954246c               -mov dword ptr [esp + 0x6c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00483ef0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00483ef2  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00483ef6  89442470               -mov dword ptr [esp + 0x70], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00483efa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00483efc  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00483eff  e828e5ffff             -call 0x48242c
    cpu.esp -= 4;
    sub_48242c(app, cpu);
    if (cpu.terminate) return;
    // 00483f04  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483f06  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483f07  6800040001             -push 0x1000400
    *app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 00483f0c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483f0e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00483f10  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00483f14  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00483f15  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00483f17  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483f18  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00483f1b  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00483f1f  750d                   -jne 0x483f2e
    if (!cpu.flags.zf)
    {
        goto L_0x00483f2e;
    }
    // 00483f21  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00483f26  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00483f29  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f2a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f2b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00483f2e:
    // 00483f2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00483f30  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00483f33  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f34  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00483f35  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_483f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00483f38  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00483f39  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00483f3a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00483f3b  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00483f41  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00483f43  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00483f45  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00483f4c  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00483f53  8bac249c000000         -mov ebp, dword ptr [esp + 0x9c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00483f5a  897c2468               -mov dword ptr [esp + 0x68], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 00483f5e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00483f60  8bbc2484000000         -mov edi, dword ptr [esp + 0x84]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00483f67  89542464               -mov dword ptr [esp + 0x64], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00483f6b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00483f6d  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00483f74  897c246c               -mov dword ptr [esp + 0x6c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 00483f78  89542478               -mov dword ptr [esp + 0x78], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00483f7c  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00483f83  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00483f8a  89542474               -mov dword ptr [esp + 0x74], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00483f8e  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00483f95  896c2470               -mov dword ptr [esp + 0x70], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 00483f99  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00483f9b  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00483fa2  89942480000000         -mov dword ptr [esp + 0x80], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 00483fa9  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00483fb0  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00483fb2  bb00000001             -mov ebx, 0x1000000
    cpu.ebx = 16777216 /*0x1000000*/;
    // 00483fb7  8954247c               -mov dword ptr [esp + 0x7c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00483fbb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00483fbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00483fbf  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00483fc2  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 00483fc9  83fa03                 +cmp edx, 3
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
    // 00483fcc  0f859f000000           -jne 0x484071
    if (!cpu.flags.zf)
    {
        goto L_0x00484071;
    }
    // 00483fd2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x00483fd7:
    // 00483fd7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00483fd9  7403                   -je 0x483fde
    if (cpu.flags.zf)
    {
        goto L_0x00483fde;
    }
    // 00483fdb  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00483fde:
    // 00483fde  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00483fe0  7403                   -je 0x483fe5
    if (cpu.flags.zf)
    {
        goto L_0x00483fe5;
    }
    // 00483fe2  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00483fe5:
    // 00483fe5  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00483fe7  7403                   -je 0x483fec
    if (cpu.flags.zf)
    {
        goto L_0x00483fec;
    }
    // 00483fe9  80cf80                 -or bh, 0x80
    cpu.bh |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00483fec:
    // 00483fec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00483fee  7424                   -je 0x484014
    if (cpu.flags.zf)
    {
        goto L_0x00484014;
    }
    // 00483ff0  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00483ff5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00483ff7  e8e0b0ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00483ffc  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00484001  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00484004  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00484007  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00484009  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048400d  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x00484014:
    // 00484014  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00484018  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048401a  e80de4ffff             -call 0x48242c
    cpu.esp -= 4;
    sub_48242c(app, cpu);
    if (cpu.terminate) return;
    // 0048401f  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00484023  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048402a  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00484031  e8f6e3ffff             -call 0x48242c
    cpu.esp -= 4;
    sub_48242c(app, cpu);
    if (cpu.terminate) return;
    // 00484036  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484037  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484038  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048403c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048403d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048403e  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00484045  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048404c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048404d  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00484054  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00484056  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484057  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048405a  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048405e  7531                   -jne 0x484091
    if (!cpu.flags.zf)
    {
        goto L_0x00484091;
    }
    // 00484060  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00484065  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048406b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048406e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00484071:
    // 00484071  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00484073  740a                   -je 0x48407f
    if (cpu.flags.zf)
    {
        goto L_0x0048407f;
    }
    // 00484075  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0048407a  e958ffffff             -jmp 0x483fd7
    goto L_0x00483fd7;
L_0x0048407f:
    // 0048407f  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00484081  0f8450ffffff           -je 0x483fd7
    if (cpu.flags.zf)
    {
        goto L_0x00483fd7;
    }
    // 00484087  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0048408c  e946ffffff             -jmp 0x483fd7
    goto L_0x00483fd7;
L_0x00484091:
    // 00484091  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00484093  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00484099  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048409a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048409b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048409c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4840a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004840a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004840a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004840a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004840a3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004840a6  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004840aa  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004840ae  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004840b0  bea0214800             -mov esi, 0x4821a0
    cpu.esi = 4727200 /*0x4821a0*/;
    // 004840b5  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004840b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004840ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004840bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004840bc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004840bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004840bf  7502                   -jne 0x4840c3
    if (!cpu.flags.zf)
    {
        goto L_0x004840c3;
    }
    // 004840c1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004840c3:
    // 004840c3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004840c7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004840c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004840ce  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004840d1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840d2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840d3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004840d4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4840d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004840d8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004840d9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004840da  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004840de  8b5354                 -mov edx, dword ptr [ebx + 0x54]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004840e1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004840e5  83fa10                 +cmp edx, 0x10
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
    // 004840e8  744a                   -je 0x484134
    if (cpu.flags.zf)
    {
        goto L_0x00484134;
    }
    // 004840ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004840ec  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
L_0x004840ef:
    // 004840ef  83f810                 +cmp eax, 0x10
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
    // 004840f2  7360                   -jae 0x484154
    if (!cpu.flags.cf)
    {
        goto L_0x00484154;
    }
    // 004840f4  83f808                 +cmp eax, 8
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
    // 004840f7  0f8380000000           -jae 0x48417d
    if (!cpu.flags.cf)
    {
        goto L_0x0048417d;
    }
L_0x004840fd:
    // 004840fd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004840ff  7429                   -je 0x48412a
    if (cpu.flags.zf)
    {
        goto L_0x0048412a;
    }
    // 00484101  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484105  0f8495000000           -je 0x4841a0
    if (cpu.flags.zf)
    {
        goto L_0x004841a0;
    }
    // 0048410b  a198bb5100             -mov eax, dword ptr [0x51bb98]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */);
    // 00484110  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484113  0f8d87000000           -jge 0x4841a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004841a0;
    }
    // 00484119  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048411b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048411d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048411f  e870e3ffff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
L_0x00484124:
    // 00484124  ff0598bb5100           -inc dword ptr [0x51bb98]
    (*app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */))++;
L_0x0048412a:
    // 0048412a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048412f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484130  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484131  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00484134:
    // 00484134  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00484137  e838e3ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 0048413c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048413e  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 00484141  e82ee3ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00484146  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00484148  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 0048414b  e824e3ffff             -call 0x482474
    cpu.esp -= 4;
    sub_482474(app, cpu);
    if (cpu.terminate) return;
    // 00484150  01d0                   +add eax, edx
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
    // 00484152  eb9b                   -jmp 0x4840ef
    goto L_0x004840ef;
L_0x00484154:
    // 00484154  7709                   -ja 0x48415f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048415f;
    }
    // 00484156  800d90bb510004         +or byte ptr [0x51bb90], 4
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(5356432) /* 0x51bb90 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0048415d  eb9e                   -jmp 0x4840fd
    goto L_0x004840fd;
L_0x0048415f:
    // 0048415f  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484162  7299                   -jb 0x4840fd
    if (cpu.flags.cf)
    {
        goto L_0x004840fd;
    }
    // 00484164  7709                   -ja 0x48416f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048416f;
    }
    // 00484166  800d90bb510008         +or byte ptr [0x51bb90], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(5356432) /* 0x51bb90 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0048416d  eb8e                   -jmp 0x4840fd
    goto L_0x004840fd;
L_0x0048416f:
    // 0048416f  83f820                 +cmp eax, 0x20
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
    // 00484172  7589                   -jne 0x4840fd
    if (!cpu.flags.zf)
    {
        goto L_0x004840fd;
    }
    // 00484174  800d90bb510010         +or byte ptr [0x51bb90], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(5356432) /* 0x51bb90 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048417b  eb80                   -jmp 0x4840fd
    goto L_0x004840fd;
L_0x0048417d:
    // 0048417d  770c                   -ja 0x48418b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048418b;
    }
    // 0048417f  800d90bb510001         +or byte ptr [0x51bb90], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(5356432) /* 0x51bb90 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00484186  e972ffffff             -jmp 0x4840fd
    goto L_0x004840fd;
L_0x0048418b:
    // 0048418b  83f80f                 +cmp eax, 0xf
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
    // 0048418e  0f8569ffffff           -jne 0x4840fd
    if (!cpu.flags.zf)
    {
        goto L_0x004840fd;
    }
    // 00484194  800d90bb510002         +or byte ptr [0x51bb90], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(5356432) /* 0x51bb90 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048419b  e95dffffff             -jmp 0x4840fd
    goto L_0x004840fd;
L_0x004841a0:
    // 004841a0  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004841a4  0f847affffff           -je 0x484124
    if (cpu.flags.zf)
    {
        goto L_0x00484124;
    }
    // 004841aa  a198bb5100             -mov eax, dword ptr [0x51bb98]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356440) /* 0x51bb98 */);
    // 004841af  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004841b2  0f8c6cffffff           -jl 0x484124
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484124;
    }
    // 004841b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004841ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841bc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4841bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004841bf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004841c0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004841c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004841c3  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004841c5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004841c8  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004841ca  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004841cd  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004841cf  e87c730100             -call 0x49b550
    cpu.esp -= 4;
    sub_49b550(app, cpu);
    if (cpu.terminate) return;
    // 004841d4  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841d5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004841d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4841e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004841e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004841e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004841e2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004841e3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004841e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004841e6  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 004841ed  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004841ef:
    // 004841ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004841f1  8d4b20                 -lea ecx, [ebx + 0x20]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(32) /* 0x20 */);
L_0x004841f4:
    // 004841f4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004841f7  8b15acf84c00           -mov edx, dword ptr [0x4cf8ac]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5044396) /* 0x4cf8ac */);
    // 004841fd  8950fc                 -mov dword ptr [eax - 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00484200  39c8                   +cmp eax, ecx
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
    // 00484202  75f0                   -jne 0x4841f4
    if (!cpu.flags.zf)
    {
        goto L_0x004841f4;
    }
    // 00484204  46                     -inc esi
    (cpu.esi)++;
    // 00484205  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484207  83fe08                 +cmp esi, 8
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
    // 0048420a  7ce3                   -jl 0x4841ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004841ef;
    }
    // 0048420c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048420d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048420e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048420f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484210  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_484214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484214  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484215  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484216  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484217  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00484218  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048421b  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 00484220  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 00484225  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
L_0x0048422a:
    // 0048422a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048422c  83f8c0                 +cmp eax, -0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-64 /*-0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048422f  0f8d2e010000           -jge 0x484363
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00484363;
    }
    // 00484235  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00484237:
    // 00484237  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 00484239  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048423b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00484241  80c340                 -add bl, 0x40
    (cpu.bl) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00484244  40                     -inc eax
    (cpu.eax)++;
    // 00484245  889a9c465200           -mov byte ptr [edx + 0x52469c], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5392028) /* 0x52469c */) = cpu.bl;
    // 0048424b  83f87f                 +cmp eax, 0x7f
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
    // 0048424e  7cda                   -jl 0x48422a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048422a;
    }
    // 00484250  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484252  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00484254:
    // 00484254  668b8310914c00         -mov ax, word ptr [ebx + 0x4c9110]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5017872) /* 0x4c9110 */);
    // 0048425b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048425d  6689442402             -mov word ptr [esp + 2], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00484262  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 00484267  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0048426c  668b8314914c00         -mov ax, word ptr [ebx + 0x4c9114]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5017876) /* 0x4c9114 */);
    // 00484273  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00484275  66890424               -mov word ptr [esp], ax
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 00484279  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048427b  8b831c914c00           -mov eax, dword ptr [ebx + 0x4c911c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5017884) /* 0x4c911c */);
    // 00484281  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484286  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00484289  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048428b  83fe17                 +cmp esi, 0x17
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048428e  7507                   -jne 0x484297
    if (!cpu.flags.zf)
    {
        goto L_0x00484297;
    }
    // 00484290  66c74424022100         -mov word ptr [esp + 2], 0x21
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = 33 /*0x21*/;
L_0x00484297:
    // 00484297  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484299  7e1e                   -jle 0x4842b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004842b9;
    }
    // 0048429b  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004842a2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004842a5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004842a7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004842a9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x004842ac:
    // 004842ac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004842af  898898bd5100           -mov dword ptr [eax + 0x51bd98], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5356952) /* 0x51bd98 */) = cpu.ecx;
    // 004842b5  39d0                   +cmp eax, edx
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
    // 004842b7  7cf3                   -jl 0x4842ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004842ac;
    }
L_0x004842b9:
    // 004842b9  46                     -inc esi
    (cpu.esi)++;
    // 004842ba  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004842bd  83fe60                 +cmp esi, 0x60
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004842c0  7c92                   -jl 0x484254
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484254;
    }
    // 004842c2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004842c3  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 004842c8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004842ca  6689742406             -mov word ptr [esp + 6], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 004842cf  66897c2404             -mov word ptr [esp + 4], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.di;
    // 004842d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004842d6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004842da  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004842db:
    // 004842db  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004842de  899098bd5100           -mov dword ptr [eax + 0x51bd98], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5356952) /* 0x51bd98 */) = cpu.edx;
    // 004842e4  3d80000000             +cmp eax, 0x80
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004842e9  75f0                   -jne 0x4842db
    if (!cpu.flags.zf)
    {
        goto L_0x004842db;
    }
    // 004842eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004842ed:
    // 004842ed  668b8310974c00         -mov ax, word ptr [ebx + 0x4c9710]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5019408) /* 0x4c9710 */);
    // 004842f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004842f6  6689442402             -mov word ptr [esp + 2], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004842fb  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 00484300  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00484305  668b8314974c00         -mov ax, word ptr [ebx + 0x4c9714]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5019412) /* 0x4c9714 */);
    // 0048430c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048430e  66890424               -mov word ptr [esp], ax
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 00484312  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00484314  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00484319  8b831c974c00           -mov eax, dword ptr [ebx + 0x4c971c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5019420) /* 0x4c971c */);
    // 0048431f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00484321  c1e807                 -shr eax, 7
    cpu.eax >>= 7 /*0x7*/ % 32;
    // 00484324  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00484326  7e1e                   -jle 0x484346
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484346;
    }
    // 00484328  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0048432b  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00484332  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00484335  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484337  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00484339:
    // 00484339  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048433c  8988983d5200           -mov dword ptr [eax + 0x523d98], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5389720) /* 0x523d98 */) = cpu.ecx;
    // 00484342  39d0                   +cmp eax, edx
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
    // 00484344  7cf3                   -jl 0x484339
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00484339;
    }
L_0x00484346:
    // 00484346  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00484349  81fb00080000           +cmp ebx, 0x800
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048434f  759c                   -jne 0x4842ed
    if (!cpu.flags.zf)
    {
        goto L_0x004842ed;
    }
    // 00484351  c7059c4b520001000000   -mov dword ptr [0x524b9c], 1
    *app->getMemory<x86::reg32>(x86::reg32(5393308) /* 0x524b9c */) = 1 /*0x1*/;
    // 0048435b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048435e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048435f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484360  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484361  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484362  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484363:
    // 00484363  83f83f                 +cmp eax, 0x3f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63 /*0x3f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00484366  0f8ecbfeffff           -jle 0x484237
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00484237;
    }
    // 0048436c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048436e  e9c4feffff             -jmp 0x484237
    goto L_0x00484237;
}

/* align: skip 0x90 */
void Application::sub_484374(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00484374  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00484375  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00484376  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00484377  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00484379  a1acf94c00             -mov eax, dword ptr [0x4cf9ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5044652) /* 0x4cf9ac */);
    // 0048437e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00484383  a39c455200             -mov dword ptr [0x52459c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5391772) /* 0x52459c */) = cpu.eax;
L_0x00484388:
    // 00484388  8b81109f4c00           -mov eax, dword ptr [ecx + 0x4c9f10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5021456) /* 0x4c9f10 */);
    // 0048438e  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00484391  8b91acf94c00           -mov edx, dword ptr [ecx + 0x4cf9ac]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5044652) /* 0x4cf9ac */);
    // 00484397  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0048439a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048439d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048439f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004843a2  c1e810                 +shr eax, 0x10
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
    // 004843a5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004843a7  898198455200           -mov dword ptr [ecx + 0x524598], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5391768) /* 0x524598 */) = cpu.eax;
    // 004843ad  81f900010000           +cmp ecx, 0x100
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
    // 004843b3  75d3                   -jne 0x484388
    if (!cpu.flags.zf)
    {
        goto L_0x00484388;
    }
    // 004843b5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843b6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843b7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4843bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004843bc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004843bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004843bf  833d9c4b520000         +cmp dword ptr [0x524b9c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5393308) /* 0x524b9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004843c6  7409                   -je 0x4843d1
    if (cpu.flags.zf)
    {
        goto L_0x004843d1;
    }
    // 004843c8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004843ca  e81d760100             -call 0x49b9ec
    cpu.esp -= 4;
    sub_49b9ec(app, cpu);
    if (cpu.terminate) return;
    // 004843cf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004843d1:
    // 004843d1  e83efeffff             -call 0x484214
    cpu.esp -= 4;
    sub_484214(app, cpu);
    if (cpu.terminate) return;
    // 004843d6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004843d8  e80f760100             -call 0x49b9ec
    cpu.esp -= 4;
    sub_49b9ec(app, cpu);
    if (cpu.terminate) return;
    // 004843dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004843de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4843e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004843e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004843e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004843e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004843e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004843e4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004843e7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004843e9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004843eb  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004843ee  833d9c4b520000         +cmp dword ptr [0x524b9c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5393308) /* 0x524b9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004843f5  0f842d020000           -je 0x484628
    if (cpu.flags.zf)
    {
        goto L_0x00484628;
    }
L_0x004843fb:
    // 004843fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004843fd  e8fa760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 00484402  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00484404  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484406  83f802                 +cmp eax, 2
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
    // 00484409  0f8523020000           -jne 0x484632
    if (!cpu.flags.zf)
    {
        goto L_0x00484632;
    }
    // 0048440f  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00484414  b89cbb5100             -mov eax, 0x51bb9c
    cpu.eax = 5356444 /*0x51bb9c*/;
    // 00484419  e8c2fdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048441e:
    // 0048441e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484420  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00484423  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00484425  e8d2760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 0048442a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048442c  83f802                 +cmp eax, 2
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
    // 0048442f  0f8511020000           -jne 0x484646
    if (!cpu.flags.zf)
    {
        goto L_0x00484646;
    }
    // 00484435  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048443a  b89cbc5100             -mov eax, 0x51bc9c
    cpu.eax = 5356700 /*0x51bc9c*/;
    // 0048443f  e89cfdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x00484444:
    // 00484444  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484446  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00484449  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048444b  e8ac760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 00484450  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484452  83f802                 +cmp eax, 2
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
    // 00484455  0f85ff010000           -jne 0x48465a
    if (!cpu.flags.zf)
    {
        goto L_0x0048465a;
    }
    // 0048445b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00484460  b89c475200             -mov eax, 0x52479c
    cpu.eax = 5392284 /*0x52479c*/;
    // 00484465  e876fdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048446a:
    // 0048446a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048446c  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048446f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00484471  e886760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 00484476  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00484478  83f802                 +cmp eax, 2
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
    // 0048447b  0f85ed010000           -jne 0x48466e
    if (!cpu.flags.zf)
    {
        goto L_0x0048466e;
    }
    // 00484481  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00484486  b8bc475200             -mov eax, 0x5247bc
    cpu.eax = 5392316 /*0x5247bc*/;
    // 0048448b  e850fdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x00484490:
    // 00484490  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484492  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00484495  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00484497  e860760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 0048449c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048449e  83f802                 +cmp eax, 2
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
    // 004844a1  0f85db010000           -jne 0x484682
    if (!cpu.flags.zf)
    {
        goto L_0x00484682;
    }
    // 004844a7  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004844ac  b89c495200             -mov eax, 0x52499c
    cpu.eax = 5392796 /*0x52499c*/;
    // 004844b1  e82afdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x004844b6:
    // 004844b6  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004844b8  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004844bb  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004844bd  e83a760100             -call 0x49bafc
    cpu.esp -= 4;
    sub_49bafc(app, cpu);
    if (cpu.terminate) return;
    // 004844c2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004844c4  83f802                 +cmp eax, 2
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
    // 004844c7  0f85c9010000           -jne 0x484696
    if (!cpu.flags.zf)
    {
        goto L_0x00484696;
    }
    // 004844cd  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004844d2  b8bc495200             -mov eax, 0x5249bc
    cpu.eax = 5392828 /*0x5249bc*/;
    // 004844d7  e804fdffff             -call 0x4841e0
    cpu.esp -= 4;
    sub_4841e0(app, cpu);
    if (cpu.terminate) return;
L_0x004844dc:
    // 004844dc  ba9cbb5100             -mov edx, 0x51bb9c
    cpu.edx = 5356444 /*0x51bb9c*/;
    // 004844e1  b89c475200             -mov eax, 0x52479c
    cpu.eax = 5392284 /*0x52479c*/;
    // 004844e6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004844e8  e8a1760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004844ed  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004844f0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004844f2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004844f5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004844f7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004844f9  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004844fb  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 00484502  ba9cbb5100             -mov edx, 0x51bb9c
    cpu.edx = 5356444 /*0x51bb9c*/;
    // 00484507  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484509  b8dc475200             -mov eax, 0x5247dc
    cpu.eax = 5392348 /*0x5247dc*/;
    // 0048450e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484510  e879760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 00484515  babcbb5100             -mov edx, 0x51bbbc
    cpu.edx = 5356476 /*0x51bbbc*/;
    // 0048451a  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048451c  b81c485200             -mov eax, 0x52481c
    cpu.eax = 5392412 /*0x52481c*/;
    // 00484521  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484523  e866760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 00484528  babcbb5100             -mov edx, 0x51bbbc
    cpu.edx = 5356476 /*0x51bbbc*/;
    // 0048452d  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048452f  b85c485200             -mov eax, 0x52485c
    cpu.eax = 5392476 /*0x52485c*/;
    // 00484534  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484536  e853760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 0048453b  badcbb5100             -mov edx, 0x51bbdc
    cpu.edx = 5356508 /*0x51bbdc*/;
    // 00484540  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484542  b89c485200             -mov eax, 0x52489c
    cpu.eax = 5392540 /*0x52489c*/;
    // 00484547  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484549  e840760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 0048454e  badcbb5100             -mov edx, 0x51bbdc
    cpu.edx = 5356508 /*0x51bbdc*/;
    // 00484553  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484555  b8dc485200             -mov eax, 0x5248dc
    cpu.eax = 5392604 /*0x5248dc*/;
    // 0048455a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048455c  e82d760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 00484561  bafcbb5100             -mov edx, 0x51bbfc
    cpu.edx = 5356540 /*0x51bbfc*/;
    // 00484566  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484568  b81c495200             -mov eax, 0x52491c
    cpu.eax = 5392668 /*0x52491c*/;
    // 0048456d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048456f  e81a760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 00484574  bafcbb5100             -mov edx, 0x51bbfc
    cpu.edx = 5356540 /*0x51bbfc*/;
    // 00484579  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048457b  b85c495200             -mov eax, 0x52495c
    cpu.eax = 5392732 /*0x52495c*/;
    // 00484580  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484582  e807760100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 00484587  ba1cbc5100             -mov edx, 0x51bc1c
    cpu.edx = 5356572 /*0x51bc1c*/;
    // 0048458c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048458e  b89c495200             -mov eax, 0x52499c
    cpu.eax = 5392796 /*0x52499c*/;
    // 00484593  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484595  e8f4750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 0048459a  ba1cbc5100             -mov edx, 0x51bc1c
    cpu.edx = 5356572 /*0x51bc1c*/;
    // 0048459f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845a1  b8dc495200             -mov eax, 0x5249dc
    cpu.eax = 5392860 /*0x5249dc*/;
    // 004845a6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004845a8  e8e1750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004845ad  ba3cbc5100             -mov edx, 0x51bc3c
    cpu.edx = 5356604 /*0x51bc3c*/;
    // 004845b2  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845b4  b81c4a5200             -mov eax, 0x524a1c
    cpu.eax = 5392924 /*0x524a1c*/;
    // 004845b9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004845bb  e8ce750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004845c0  ba3cbc5100             -mov edx, 0x51bc3c
    cpu.edx = 5356604 /*0x51bc3c*/;
    // 004845c5  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845c7  b85c4a5200             -mov eax, 0x524a5c
    cpu.eax = 5392988 /*0x524a5c*/;
    // 004845cc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004845ce  e8bb750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004845d3  ba5cbc5100             -mov edx, 0x51bc5c
    cpu.edx = 5356636 /*0x51bc5c*/;
    // 004845d8  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845da  b89c4a5200             -mov eax, 0x524a9c
    cpu.eax = 5393052 /*0x524a9c*/;
    // 004845df  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004845e1  e8a8750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004845e6  ba5cbc5100             -mov edx, 0x51bc5c
    cpu.edx = 5356636 /*0x51bc5c*/;
    // 004845eb  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004845ed  b8dc4a5200             -mov eax, 0x524adc
    cpu.eax = 5393116 /*0x524adc*/;
    // 004845f2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004845f4  e895750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 004845f9  ba7cbc5100             -mov edx, 0x51bc7c
    cpu.edx = 5356668 /*0x51bc7c*/;
    // 004845fe  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00484600  b81c4b5200             -mov eax, 0x524b1c
    cpu.eax = 5393180 /*0x524b1c*/;
    // 00484605  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00484607  e882750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 0048460c  ba7cbc5100             -mov edx, 0x51bc7c
    cpu.edx = 5356668 /*0x51bc7c*/;
    // 00484611  b85c4b5200             -mov eax, 0x524b5c
    cpu.eax = 5393244 /*0x524b5c*/;
    // 00484616  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00484619  e870750100             -call 0x49bb8e
    cpu.esp -= 4;
    sub_49bb8e(app, cpu);
    if (cpu.terminate) return;
    // 0048461e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00484620  83c404                 +add esp, 4
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
    // 00484623  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484624  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484625  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484626  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00484627  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00484628:
    // 00484628  e8e7fbffff             -call 0x484214
    cpu.esp -= 4;
    sub_484214(app, cpu);
    if (cpu.terminate) return;
    // 0048462d  e9c9fdffff             -jmp 0x4843fb
    goto L_0x004843fb;
L_0x00484632:
    // 00484632  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00484637  b89cbb5100             -mov eax, 0x51bb9c
    cpu.eax = 5356444 /*0x51bb9c*/;
    // 0048463c  e820720100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 00484641  e9d8fdffff             -jmp 0x48441e
    goto L_0x0048441e;
L_0x00484646:
    // 00484646  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048464b  b89cbc5100             -mov eax, 0x51bc9c
    cpu.eax = 5356700 /*0x51bc9c*/;
    // 00484650  e80c720100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 00484655  e9eafdffff             -jmp 0x484444
    goto L_0x00484444;
L_0x0048465a:
    // 0048465a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048465f  b89c475200             -mov eax, 0x52479c
    cpu.eax = 5392284 /*0x52479c*/;
    // 00484664  e8f8710100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 00484669  e9fcfdffff             -jmp 0x48446a
    goto L_0x0048446a;
L_0x0048466e:
    // 0048466e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00484673  b8bc475200             -mov eax, 0x5247bc
    cpu.eax = 5392316 /*0x5247bc*/;
    // 00484678  e8e4710100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 0048467d  e90efeffff             -jmp 0x484490
    goto L_0x00484490;
L_0x00484682:
    // 00484682  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00484687  b89c495200             -mov eax, 0x52499c
    cpu.eax = 5392796 /*0x52499c*/;
    // 0048468c  e8d0710100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 00484691  e920feffff             -jmp 0x4844b6
    goto L_0x004844b6;
L_0x00484696:
    // 00484696  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048469b  b8bc495200             -mov eax, 0x5249bc
    cpu.eax = 5392828 /*0x5249bc*/;
    // 004846a0  e8bc710100             -call 0x49b861
    cpu.esp -= 4;
    sub_49b861(app, cpu);
    if (cpu.terminate) return;
    // 004846a5  e932feffff             -jmp 0x4844dc
    goto L_0x004844dc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4846b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004846b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004846b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4846b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004846b4  a310a04c00             -mov dword ptr [0x4ca010], eax
    *app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */) = cpu.eax;
    // 004846b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4846bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004846bc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004846bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004846bf  8b1510a04c00           -mov edx, dword ptr [0x4ca010]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5021712) /* 0x4ca010 */);
    // 004846c5  a328a04c00             -mov dword ptr [0x4ca028], eax
    *app->getMemory<x86::reg32>(x86::reg32(5021736) /* 0x4ca028 */) = cpu.eax;
    // 004846ca  a324a04c00             -mov dword ptr [0x4ca024], eax
    *app->getMemory<x86::reg32>(x86::reg32(5021732) /* 0x4ca024 */) = cpu.eax;
    // 004846cf  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004846d4  e80f210000             -call 0x4867e8
    cpu.esp -= 4;
    sub_4867e8(app, cpu);
    if (cpu.terminate) return;
    // 004846d9  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004846df  89463c                 -mov dword ptr [esi + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004846e2  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004846e8  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004846eb  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004846f1  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004846f7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004846f9  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004846fc  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004846ff  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00484702  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00484705  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00484708  894614                 -mov dword ptr [esi + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048470b  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048470e  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00484711  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00484714  894610                 -mov dword ptr [esi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00484717  c7462800000000         -mov dword ptr [esi + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0048471e  895e40                 -mov dword ptr [esi + 0x40], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 00484721  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00484728  c7467000000000         -mov dword ptr [esi + 0x70], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048472f  c7467800000000         -mov dword ptr [esi + 0x78], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00484736  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00484739  89467c                 -mov dword ptr [esi + 0x7c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0048473c  c7462007000000         -mov dword ptr [esi + 0x20], 7
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00484743  c7462400000000         -mov dword ptr [esi + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048474a  c7463800000000         -mov dword ptr [esi + 0x38], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 00484751  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00484754  894634                 -mov dword ptr [esi + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00484757  c786bc00000000000000   -mov dword ptr [esi + 0xbc], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 00484761  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00484767  8986b8000000           -mov dword ptr [esi + 0xb8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048476d  c7463000000000         -mov dword ptr [esi + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00484774  e853a7ffff             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00484779  8986a4000000           -mov dword ptr [esi + 0xa4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048477f  e834a8ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00484784  8986ac000000           -mov dword ptr [esi + 0xac], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0048478a  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048478f  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00484795  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048479a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048479b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048479d  b868514800             -mov eax, 0x485168
    cpu.eax = 4739432 /*0x485168*/;
    // 004847a2  e8f9a3ffff             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 004847a7  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 004847ad  e86aa7ffff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 004847b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004847b4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4847b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004847b8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004847b9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004847bb  e8fcfeffff             -call 0x4846bc
    cpu.esp -= 4;
    sub_4846bc(app, cpu);
    if (cpu.terminate) return;
    // 004847c0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4847c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004847c4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004847c5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004847ca  e8edfeffff             -call 0x4846bc
    cpu.esp -= 4;
    sub_4846bc(app, cpu);
    if (cpu.terminate) return;
    // 004847cf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004847d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
