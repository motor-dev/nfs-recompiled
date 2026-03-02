#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_a32800(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a32800:
    // 00a32800  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a32801  ebfd                   -jmp 0xa32800
    goto L_0x00a32800;
}

/* align: skip 0x90 */
void sub_a32804(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32804  90                     -nop 
    ;
    // 00a32805  90                     -nop 
    ;
    // 00a32806  90                     -nop 
    ;
    // 00a32807  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a32809  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a3280b  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a3280d  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a3280f  005351                 -add byte ptr [ebx + 0x51], dl
    (*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(81) /* 0x51 */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 00a32812  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32813  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32819  8d842418020000         -lea eax, [esp + 0x218]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00a32820  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00a32827  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 00a3282e  89842400020000         -mov dword ptr [esp + 0x200], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00a32835  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a32837  e8f8190000             -call 0xa34234
    cpu.esp -= 4;
    sub_a34234(app, cpu);
    if (cpu.terminate) return;
    // 00a3283c  833d18c1a30000         +cmp dword ptr [0xa3c118], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731800) /* 0xa3c118 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32843  7513                   -jne 0xa32858
    if (!cpu.flags.zf)
    {
        goto L_0x00a32858;
    }
    // 00a32845  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a32847  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a3284e  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32854  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32855  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32856  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32857  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32858:
    // 00a32858  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3285a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3285b  ff1518c1a300           -call dword ptr [0xa3c118]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731800) /* 0xa3c118 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32861  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a32864  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a32866  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a3286d  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32873  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32874  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32875  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32876  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a32878(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32878  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32879  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3287a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3287b  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32881  8d842418020000         -lea eax, [esp + 0x218]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00a32888  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00a3288f  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 00a32896  89842400020000         -mov dword ptr [esp + 0x200], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00a3289d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3289f  e890190000             -call 0xa34234
    cpu.esp -= 4;
    sub_a34234(app, cpu);
    if (cpu.terminate) return;
    // 00a328a4  833d10c1a30000         +cmp dword ptr [0xa3c110], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731792) /* 0xa3c110 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a328ab  7513                   -jne 0xa328c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a328c0;
    }
    // 00a328ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a328af  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a328b6  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a328bc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328bd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328be  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a328c0:
    // 00a328c0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a328c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a328c3  ff1510c1a300           -call dword ptr [0xa3c110]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731792) /* 0xa3c110 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a328c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a328cc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a328ce  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a328d5  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a328db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328dc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328dd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a328de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a328e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a328e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a328e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a328e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a328e3  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a328e9  8d842418020000         -lea eax, [esp + 0x218]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 00a328f0  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00a328f7  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 00a328fe  89842400020000         -mov dword ptr [esp + 0x200], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 00a32905  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a32907  e828190000             -call 0xa34234
    cpu.esp -= 4;
    sub_a34234(app, cpu);
    if (cpu.terminate) return;
    // 00a3290c  833d0cc1a30000         +cmp dword ptr [0xa3c10c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731788) /* 0xa3c10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32913  7513                   -jne 0xa32928
    if (!cpu.flags.zf)
    {
        goto L_0x00a32928;
    }
    // 00a32915  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a32917  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a3291e  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32924  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32925  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32926  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32927  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32928:
    // 00a32928  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3292a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3292b  ff150cc1a300           -call dword ptr [0xa3c10c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731788) /* 0xa3c10c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32931  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a32934  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a32936  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 00a3293d  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 00a32943  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32944  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32945  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32946  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a32948(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32948  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32949  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3294a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a3294f  8b0dc0c2a300           -mov ecx, dword ptr [0xa3c2c0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10732224) /* 0xa3c2c0 */);
    // 00a32955  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 00a3295a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a3295c  7414                   -je 0xa32972
    if (cpu.flags.zf)
    {
        goto L_0x00a32972;
    }
L_0x00a3295e:
    // 00a3295e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00a32961  42                     -inc edx
    (cpu.edx)++;
    // 00a32962  3d00070000             +cmp eax, 0x700
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1792 /*0x700*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32967  7d0e                   -jge 0xa32977
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a32977;
    }
    // 00a32969  83b8a4c2a30000         +cmp dword ptr [eax + 0xa3c2a4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10732196) /* 0xa3c2a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32970  75ec                   -jne 0xa3295e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3295e;
    }
L_0x00a32972:
    // 00a32972  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a32974  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32975  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32976  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32977:
    // 00a32977  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32979  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3297a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3297b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3297c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3297c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3297d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3297e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3297f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32980  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a32981  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32982  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a32985  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a32987  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a3298a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3298c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a3298f  bea4c2a300             -mov esi, 0xa3c2a4
    cpu.esi = 10732196 /*0xa3c2a4*/;
    // 00a32994  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32996  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a32998  833e00                 +cmp dword ptr [esi], 0
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
    // 00a3299b  0f84d7000000           -je 0xa32a78
    if (cpu.flags.zf)
    {
        goto L_0x00a32a78;
    }
    // 00a329a1  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a329a4  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00a329a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a329aa  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a329ac  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a329b0  807e1800               +cmp byte ptr [esi + 0x18], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a329b4  0f85ca000000           -jne 0xa32a84
    if (!cpu.flags.zf)
    {
        goto L_0x00a32a84;
    }
    // 00a329ba  c744243010000000       -mov dword ptr [esp + 0x30], 0x10
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = 16 /*0x10*/;
L_0x00a329c2:
    // 00a329c2  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a329c5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a329c7  7e06                   -jle 0xa329cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a329cf;
    }
    // 00a329c9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a329cb  2b560c                 -sub edx, dword ptr [esi + 0xc]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 00a329ce  42                     -inc edx
    (cpu.edx)++;
L_0x00a329cf:
    // 00a329cf  8b6e16                 -mov ebp, dword ptr [esi + 0x16]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 00a329d2  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a329d6  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 00a329d9  c1f903                 -sar ecx, 3
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (3 /*0x3*/ % 32));
    // 00a329dc  0fafe9                 -imul ebp, ecx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00a329df  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a329e2  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00a329e7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a329e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a329eb  e859180000             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a329f0  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00a329f5  bab4000000             -mov edx, 0xb4
    cpu.edx = 180 /*0xb4*/;
    // 00a329fa  896c2408               -mov dword ptr [esp + 8], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a329fe  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a32a01  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a32a05  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a32a09  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a32a0e  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a32a12  6689542414             -mov word ptr [esp + 0x14], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 00a32a17  660fbe4619             -movsx ax, byte ptr [esi + 0x19]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(25) /* 0x19 */)));
    // 00a32a1c  6689442416             -mov word ptr [esp + 0x16], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(22) /* 0x16 */) = cpu.ax;
    // 00a32a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32a23  668b4614               -mov ax, word ptr [esi + 0x14]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00a32a27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32a29  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a32a2d  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00a32a30  8b4616                 -mov eax, dword ptr [esi + 0x16]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 00a32a33  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32a36  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a32a39  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00a32a3c  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a32a40  8b4616                 -mov eax, dword ptr [esi + 0x16]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 00a32a43  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32a46  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00a32a49  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32a4b  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a32a4e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32a4f  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a32a53  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a32a55  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32a56  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a32a5a  66895c2430             -mov word ptr [esp + 0x30], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 00a32a5f  668944242e             -mov word ptr [esp + 0x2e], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 00a32a64  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32a69  66894c242c             -mov word ptr [esp + 0x2c], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.cx;
    // 00a32a6e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32a6f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32a71  ff510c                 -call dword ptr [ecx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32a74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32a76  741e                   -je 0xa32a96
    if (cpu.flags.zf)
    {
        goto L_0x00a32a96;
    }
L_0x00a32a78:
    // 00a32a78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32a7a  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a32a7d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a7e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a7f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a80  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a81  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a82  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32a83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32a84:
    // 00a32a84  6804b8a300             -push 0xa3b804
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729476 /*0xa3b804*/;
    cpu.esp -= 4;
    // 00a32a89  e852feffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a32a8e  83c404                 +add esp, 4
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
    // 00a32a91  e92cffffff             -jmp 0xa329c2
    goto L_0x00a329c2;
L_0x00a32a96:
    // 00a32a96  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32a98  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32a9a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32a9c  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a32aa0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32aa1  8d4c2438               -lea ecx, [esp + 0x38]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a32aa5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32aa6  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32aa7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a32aaa  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32aac  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32aae  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32aaf  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32ab2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32ab4  7575                   -jne 0xa32b2b
    if (!cpu.flags.zf)
    {
        goto L_0x00a32b2b;
    }
    // 00a32ab6  8b4616                 -mov eax, dword ptr [esi + 0x16]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 00a32ab9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32abc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32abd  8b4615                 -mov eax, dword ptr [esi + 0x15]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(21) /* 0x15 */);
    // 00a32ac0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32ac3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32ac4  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a32ac8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32ac9  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00a32acd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32ace  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a32ad1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32ad2  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a32ad5  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00a32ad8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32ad9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32adc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32add  8b4613                 -mov eax, dword ptr [esi + 0x13]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 00a32ae0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00a32ae3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32ae4  8b4c2454               -mov ecx, dword ptr [esp + 0x54]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00a32ae8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32ae9  ff1520c1a300           -call dword ptr [0xa3c120]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731808) /* 0xa3c120 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32aef  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32af1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32af3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32af4  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a32af8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a32afb  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32afc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32afe  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32aff  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32b02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32b04  750c                   -jne 0xa32b12
    if (!cpu.flags.zf)
    {
        goto L_0x00a32b12;
    }
    // 00a32b06  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a32b08  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a32b0b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b0c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b0d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b0e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b0f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b10  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32b12:
    // 00a32b12  6830b8a300             -push 0xa3b830
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729520 /*0xa3b830*/;
    cpu.esp -= 4;
    // 00a32b17  e8c4fdffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a32b1c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a32b1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b21  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a32b24  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b25  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b26  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b27  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b28  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b29  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32b2b:
    // 00a32b2b  6860b8a300             -push 0xa3b860
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729568 /*0xa3b860*/;
    cpu.esp -= 4;
    // 00a32b30  e8abfdffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a32b35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a32b38  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a32b3a  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a32b3d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b3e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b3f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b40  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b41  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b42  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a32b44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32b44  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32b45  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00a32b4a:
    // 00a32b4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a32b4c  42                     -inc edx
    (cpu.edx)++;
    // 00a32b4d  e82afeffff             -call 0xa3297c
    cpu.esp -= 4;
    sub_a3297c(app, cpu);
    if (cpu.terminate) return;
    // 00a32b52  83fa40                 +cmp edx, 0x40
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
    // 00a32b55  7cf3                   -jl 0xa32b4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a32b4a;
    }
    // 00a32b57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b59  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a32b5c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32b5c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32b5d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32b5e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32b5f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32b60  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a32b61  bb24c1a300             -mov ebx, 0xa3c124
    cpu.ebx = 10731812 /*0xa3c124*/;
    // 00a32b66  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a32b68  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00a32b6a:
    // 00a32b6a  3b7b04                 +cmp edi, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32b6d  7511                   -jne 0xa32b80
    if (!cpu.flags.zf)
    {
        goto L_0x00a32b80;
    }
L_0x00a32b6f:
    // 00a32b6f  46                     -inc esi
    (cpu.esi)++;
    // 00a32b70  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a32b73  83fe10                 +cmp esi, 0x10
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
    // 00a32b76  7cf2                   -jl 0xa32b6a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a32b6a;
    }
    // 00a32b78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b7a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b7b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b7c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b7d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b7e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32b7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a32b80:
    // 00a32b80  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00a32b83  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00a32b86  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32b87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b89  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00a32b8d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32b8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b90  8a4313                 -mov al, byte ptr [ebx + 0x13]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 00a32b93  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32b94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b96  668b4310               -mov ax, word ptr [ebx + 0x10]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a32b9a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32b9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32b9d  8a4312                 -mov al, byte ptr [ebx + 0x12]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */);
    // 00a32ba0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32ba1  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a32ba4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32ba6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32ba7  8a4314                 -mov al, byte ptr [ebx + 0x14]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a32baa  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00a32bac  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32bad  897b08                 -mov dword ptr [ebx + 8], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a32bb0  e85f140000             -call 0xa34014
    cpu.esp -= 4;
    sub_a34014(app, cpu);
    if (cpu.terminate) return;
    // 00a32bb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32bb7  7db6                   -jge 0xa32b6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a32b6f;
    }
    // 00a32bb9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32bba  ff1508c1a300           -call dword ptr [0xa3c108]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731784) /* 0xa3c108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32bc0  ebad                   -jmp 0xa32b6f
    goto L_0x00a32b6f;
}

/* align: skip 0x8b 0xc0 */
void sub_a32bc4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32bc4  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00a32bc9  b803001000             -mov eax, 0x100003
    cpu.eax = 1048579 /*0x100003*/;
    // 00a32bce  8915fcc0a300           -mov dword ptr [0xa3c0fc], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731772) /* 0xa3c0fc */) = cpu.edx;
    // 00a32bd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a32bd8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32bd8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a32bdc  a304c1a300             -mov dword ptr [0xa3c104], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731780) /* 0xa3c104 */) = cpu.eax;
    // 00a32be1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a32be5  a308c1a300             -mov dword ptr [0xa3c108], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731784) /* 0xa3c108 */) = cpu.eax;
    // 00a32bea  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a32bee  a30cc1a300             -mov dword ptr [0xa3c10c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731788) /* 0xa3c10c */) = cpu.eax;
    // 00a32bf3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a32bf7  a310c1a300             -mov dword ptr [0xa3c110], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731792) /* 0xa3c110 */) = cpu.eax;
    // 00a32bfc  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a32c00  a314c1a300             -mov dword ptr [0xa3c114], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731796) /* 0xa3c114 */) = cpu.eax;
    // 00a32c05  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a32c09  a318c1a300             -mov dword ptr [0xa3c118], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731800) /* 0xa3c118 */) = cpu.eax;
    // 00a32c0e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a32c12  a31cc1a300             -mov dword ptr [0xa3c11c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731804) /* 0xa3c11c */) = cpu.eax;
    // 00a32c17  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a32c1b  a320c1a300             -mov dword ptr [0xa3c120], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731808) /* 0xa3c120 */) = cpu.eax;
    // 00a32c20  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32c22  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a32c28(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a32c28  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32c29  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a32c2f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32c31  89942488000000         -mov dword ptr [esp + 0x88], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 00a32c38  833dfcc0a30000         +cmp dword ptr [0xa3c0fc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731772) /* 0xa3c0fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32c3f  7c0f                   -jl 0xa32c50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a32c50;
    }
    // 00a32c41  a1fcc0a300             -mov eax, dword ptr [0xa3c0fc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731772) /* 0xa3c0fc */);
    // 00a32c46  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a32c4c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32c4d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a32c50:
    // 00a32c50  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a32c51  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32c52  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32c53  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a32c5a  7475                   -je 0xa32cd1
    if (cpu.flags.zf)
    {
        goto L_0x00a32cd1;
    }
L_0x00a32c5c:
    // 00a32c5c  c744240c60000000       -mov dword ptr [esp + 0xc], 0x60
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 96 /*0x60*/;
    // 00a32c64  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32c69  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32c6b  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a32c6f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32c70  8b359cc0a300           -mov esi, dword ptr [0xa3c09c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32c76  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32c77  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32c7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32c7c  0f848b000000           -je 0xa32d0d
    if (cpu.flags.zf)
    {
        goto L_0x00a32d0d;
    }
L_0x00a32c82:
    // 00a32c82  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x00a32c8d:
    // 00a32c8d  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a32c94  7522                   -jne 0xa32cb8
    if (!cpu.flags.zf)
    {
        goto L_0x00a32cb8;
    }
    // 00a32c96  833d9cc0a30000         +cmp dword ptr [0xa3c09c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32c9d  7411                   -je 0xa32cb0
    if (cpu.flags.zf)
    {
        goto L_0x00a32cb0;
    }
    // 00a32c9f  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32ca4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32ca6  8b0d9cc0a300           -mov ecx, dword ptr [0xa3c09c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32cac  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a32cad  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a32cb0:
    // 00a32cb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a32cb2  891d9cc0a300           -mov dword ptr [0xa3c09c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */) = cpu.ebx;
L_0x00a32cb8:
    // 00a32cb8  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00a32cbf  a3fcc0a300             -mov dword ptr [0xa3c0fc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731772) /* 0xa3c0fc */) = cpu.eax;
    // 00a32cc4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32cc5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32cc6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32cc7  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a32ccd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a32cce  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a32cd1:
    // 00a32cd1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32cd2  689cc0a300             -push 0xa3c09c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731676 /*0xa3c09c*/;
    cpu.esp -= 4;
    // 00a32cd7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32cd8  e8916e0000             -call 0xa39b6e
    cpu.esp -= 4;
    sub_a39b6e(app, cpu);
    if (cpu.terminate) return;
    // 00a32cdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32cdf  0f8477ffffff           -je 0xa32c5c
    if (cpu.flags.zf)
    {
        goto L_0x00a32c5c;
    }
    // 00a32ce5  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32cea  7414                   -je 0xa32d00
    if (cpu.flags.zf)
    {
        goto L_0x00a32d00;
    }
    // 00a32cec  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32cf1  758f                   -jne 0xa32c82
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c82;
    }
    // 00a32cf3  c7842494000000f6ffffff -mov dword ptr [esp + 0x94], 0xfffffff6
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967286 /*0xfffffff6*/;
    // 00a32cfe  eb8d                   -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a32d00:
    // 00a32d00  c7842494000000eeffffff -mov dword ptr [esp + 0x94], 0xffffffee
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967278 /*0xffffffee*/;
    // 00a32d0b  eb80                   -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a32d0d:
    // 00a32d0d  f644241020             +test byte ptr [esp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 00a32d12  0f84c6000000           -je 0xa32dde
    if (cpu.flags.zf)
    {
        goto L_0x00a32dde;
    }
    // 00a32d18  c605b5c0a30001         -mov byte ptr [0xa3c0b5], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */) = 1 /*0x1*/;
L_0x00a32d1f:
    // 00a32d1f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a32d24  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a32d29  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a32d2d  6689942482000000       -mov word ptr [esp + 0x82], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.dx;
    // 00a32d35  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00a32d38  66899c248e000000       -mov word ptr [esp + 0x8e], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.bx;
    // 00a32d40  83f805                 +cmp eax, 5
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
    // 00a32d43  7508                   -jne 0xa32d4d
    if (!cpu.flags.zf)
    {
        goto L_0x00a32d4d;
    }
    // 00a32d45  808c249400000001       -or byte ptr [esp + 0x94], 1
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00a32d4d:
    // 00a32d4d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a32d51  83e006                 -and eax, 6
    cpu.eax &= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a32d54  83f806                 +cmp eax, 6
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
    // 00a32d57  7508                   -jne 0xa32d61
    if (!cpu.flags.zf)
    {
        goto L_0x00a32d61;
    }
    // 00a32d59  808c249400000002       -or byte ptr [esp + 0x94], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a32d61:
    // 00a32d61  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a32d65  83e009                 -and eax, 9
    cpu.eax &= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00a32d68  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32d6b  7508                   -jne 0xa32d75
    if (!cpu.flags.zf)
    {
        goto L_0x00a32d75;
    }
    // 00a32d6d  808c249400000004       -or byte ptr [esp + 0x94], 4
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00a32d75:
    // 00a32d75  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a32d79  83e00a                 -and eax, 0xa
    cpu.eax &= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a32d7c  83f80a                 +cmp eax, 0xa
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
    // 00a32d7f  752a                   -jne 0xa32dab
    if (!cpu.flags.zf)
    {
        goto L_0x00a32dab;
    }
    // 00a32d81  8a842494000000         -mov al, byte ptr [esp + 0x94]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00a32d88  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00a32d8d  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a32d92  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a32d94  66898c2482000000       -mov word ptr [esp + 0x82], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.cx;
    // 00a32d9c  6689b4248e000000       -mov word ptr [esp + 0x8e], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.si;
    // 00a32da4  88842494000000         -mov byte ptr [esp + 0x94], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.al;
L_0x00a32dab:
    // 00a32dab  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a32db0  7608                   -jbe 0xa32dba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a32dba;
    }
    // 00a32db2  808c249600000002       -or byte ptr [esp + 0x96], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a32dba:
    // 00a32dba  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32dbf  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a32dc1  8bac24a4000000         -mov ebp, dword ptr [esp + 0xa4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00a32dc8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32dca  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32dcb  8b159cc0a300           -mov edx, dword ptr [0xa3c09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32dd1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32dd2  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32dd5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32dd7  7412                   -je 0xa32deb
    if (cpu.flags.zf)
    {
        goto L_0x00a32deb;
    }
    // 00a32dd9  e9a4feffff             -jmp 0xa32c82
    goto L_0x00a32c82;
L_0x00a32dde:
    // 00a32dde  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 00a32de0  8835b5c0a300           -mov byte ptr [0xa3c0b5], dh
    *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */) = cpu.dh;
    // 00a32de6  e934ffffff             -jmp 0xa32d1f
    goto L_0x00a32d1f;
L_0x00a32deb:
    // 00a32deb  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00a32df0  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00a32df4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32df6  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00a32dfb  e849140000             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a32e00  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a32e05  894c246c               -mov dword ptr [esp + 0x6c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 00a32e09  895c2470               -mov dword ptr [esp + 0x70], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebx;
    // 00a32e0d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a32e0f  8b159cc0a300           -mov edx, dword ptr [0xa3c09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32e15  68a0c0a300             -push 0xa3c0a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731680 /*0xa3c0a0*/;
    cpu.esp -= 4;
    // 00a32e1a  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00a32e1e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a32e20  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32e21  8b359cc0a300           -mov esi, dword ptr [0xa3c09c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a32e27  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a32e28  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32e2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32e2d  0f854ffeffff           -jne 0xa32c82
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c82;
    }
    // 00a32e33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32e35  668b84248e000000       -mov ax, word ptr [esp + 0x8e]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
    // 00a32e3d  668b942482000000       -mov dx, word ptr [esp + 0x82]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
    // 00a32e45  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a32e48  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00a32e4b  668984248c000000       -mov word ptr [esp + 0x8c], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ax;
    // 00a32e53  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32e55  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a32e5d  69c0112b0000           -imul eax, eax, 0x2b11
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(11025 /*0x2b11*/)));
    // 00a32e63  66c78424800000000100   -mov word ptr [esp + 0x80], 1
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(128) /* 0x80 */) = 1 /*0x1*/;
    // 00a32e6d  bf112b0000             -mov edi, 0x2b11
    cpu.edi = 11025 /*0x2b11*/;
    // 00a32e72  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00a32e79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32e7b  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 00a32e82  6689842490000000       -mov word ptr [esp + 0x90], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.ax;
    // 00a32e8a  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32e8f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32e91  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a32e98  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32e99  8b2da0c0a300           -mov ebp, dword ptr [0xa3c0a0]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32e9f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a32ea0  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32ea3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32ea5  7508                   -jne 0xa32eaf
    if (!cpu.flags.zf)
    {
        goto L_0x00a32eaf;
    }
    // 00a32ea7  808c249500000002       -or byte ptr [esp + 0x95], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a32eaf:
    // 00a32eaf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32eb1  b8803e0000             -mov eax, 0x3e80
    cpu.eax = 16000 /*0x3e80*/;
    // 00a32eb6  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a32ebe  89842484000000         -mov dword ptr [esp + 0x84], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00a32ec5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a32ecc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32ece  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a32ed1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a32ed3  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00a32ed6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a32ed8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a32edb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a32edd  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00a32ee4  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32ee9  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a32ef0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32ef2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32ef3  8b15a0c0a300           -mov edx, dword ptr [0xa3c0a0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32ef9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a32efa  ff5038                 -call dword ptr [eax + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32efd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32eff  7508                   -jne 0xa32f09
    if (!cpu.flags.zf)
    {
        goto L_0x00a32f09;
    }
    // 00a32f01  808c249500000004       -or byte ptr [esp + 0x95], 4
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00a32f09:
    // 00a32f09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32f0b  b922560000             -mov ecx, 0x5622
    cpu.ecx = 22050 /*0x5622*/;
    // 00a32f10  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a32f18  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00a32f1b  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 00a32f22  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00a32f29  8b15a0c0a300           -mov edx, dword ptr [0xa3c0a0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32f2f  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a32f36  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a32f38  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32f39  8b1da0c0a300           -mov ebx, dword ptr [0xa3c0a0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32f3f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a32f40  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32f43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32f45  7508                   -jne 0xa32f4f
    if (!cpu.flags.zf)
    {
        goto L_0x00a32f4f;
    }
    // 00a32f47  808c249500000008       -or byte ptr [esp + 0x95], 8
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00a32f4f:
    // 00a32f4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32f51  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a32f59  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a32f60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a32f62  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a32f65  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a32f67  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00a32f6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a32f6c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a32f6f  be007d0000             -mov esi, 0x7d00
    cpu.esi = 32000 /*0x7d00*/;
    // 00a32f74  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a32f76  89b42484000000         -mov dword ptr [esp + 0x84], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.esi;
    // 00a32f7d  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00a32f84  8b15a0c0a300           -mov edx, dword ptr [0xa3c0a0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32f8a  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a32f91  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a32f93  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32f94  8b3da0c0a300           -mov edi, dword ptr [0xa3c0a0]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32f9a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a32f9b  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32f9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32fa0  7508                   -jne 0xa32faa
    if (!cpu.flags.zf)
    {
        goto L_0x00a32faa;
    }
    // 00a32fa2  808c249500000010       -or byte ptr [esp + 0x95], 0x10
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00a32faa:
    // 00a32faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a32fac  bd44ac0000             -mov ebp, 0xac44
    cpu.ebp = 44100 /*0xac44*/;
    // 00a32fb1  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00a32fb9  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00a32fbc  89ac2484000000         -mov dword ptr [esp + 0x84], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebp;
    // 00a32fc3  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00a32fca  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32fcf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a32fd1  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a32fd8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32fd9  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a32fde  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a32fdf  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a32fe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a32fe4  7508                   -jne 0xa32fee
    if (!cpu.flags.zf)
    {
        goto L_0x00a32fee;
    }
    // 00a32fe6  808c249500000020       -or byte ptr [esp + 0x95], 0x20
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a32fee:
    // 00a32fee  f68424940000000f       +test byte ptr [esp + 0x94], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) & 15 /*0xf*/));
    // 00a32ff6  7571                   -jne 0xa33069
    if (!cpu.flags.zf)
    {
        goto L_0x00a33069;
    }
L_0x00a32ff8:
    // 00a32ff8  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x00a33003:
    // 00a33003  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33005  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a3300a  6a12                   -push 0x12
    *app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 00a3300c  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00a33013  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33015  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33016  8b35a0c0a300           -mov esi, dword ptr [0xa3c0a0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a3301c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3301d  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33020  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33022  0f8565fcffff           -jne 0xa32c8d
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c8d;
    }
    // 00a33028  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a33031  754f                   -jne 0xa33082
    if (!cpu.flags.zf)
    {
        goto L_0x00a33082;
    }
    // 00a33033  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3303c  7544                   -jne 0xa33082
    if (!cpu.flags.zf)
    {
        goto L_0x00a33082;
    }
    // 00a3303e  c784249400000001000000 -mov dword ptr [esp + 0x94], 1
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
L_0x00a33049:
    // 00a33049  8b9c2484000000         -mov ebx, dword ptr [esp + 0x84]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00a33050  81fb112b0000           +cmp ebx, 0x2b11
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11025 /*0x2b11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33056  0f859a000000           -jne 0xa330f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a330f6;
    }
    // 00a3305c  808c249500000002       +or byte ptr [esp + 0x95], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a33064  e924fcffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a33069:
    // 00a33069  f68424950000003e       +test byte ptr [esp + 0x95], 0x3e
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) & 62 /*0x3e*/));
    // 00a33071  7485                   -je 0xa32ff8
    if (cpu.flags.zf)
    {
        goto L_0x00a32ff8;
    }
    // 00a33073  83bc249400000000       +cmp dword ptr [esp + 0x94], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3307b  7e86                   -jle 0xa33003
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a33003;
    }
    // 00a3307d  e90bfcffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a33082:
    // 00a33082  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3308b  7518                   -jne 0xa330a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a330a5;
    }
    // 00a3308d  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a33096  750d                   -jne 0xa330a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a330a5;
    }
    // 00a33098  c784249400000002000000 -mov dword ptr [esp + 0x94], 2
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 2 /*0x2*/;
    // 00a330a3  eba4                   -jmp 0xa33049
    goto L_0x00a33049;
L_0x00a330a5:
    // 00a330a5  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a330ae  7518                   -jne 0xa330c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a330c8;
    }
    // 00a330b0  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a330b9  750d                   -jne 0xa330c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a330c8;
    }
    // 00a330bb  c784249400000004000000 -mov dword ptr [esp + 0x94], 4
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4 /*0x4*/;
    // 00a330c6  eb81                   -jmp 0xa33049
    goto L_0x00a33049;
L_0x00a330c8:
    // 00a330c8  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a330d1  0f85abfbffff           -jne 0xa32c82
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c82;
    }
    // 00a330d7  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a330e0  0f859cfbffff           -jne 0xa32c82
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c82;
    }
    // 00a330e6  c784249400000008000000 -mov dword ptr [esp + 0x94], 8
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 8 /*0x8*/;
    // 00a330f1  e953ffffff             -jmp 0xa33049
    goto L_0x00a33049;
L_0x00a330f6:
    // 00a330f6  81fb803e0000           +cmp ebx, 0x3e80
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16000 /*0x3e80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a330fc  750d                   -jne 0xa3310b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3310b;
    }
    // 00a330fe  808c249500000004       +or byte ptr [esp + 0x95], 4
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a33106  e982fbffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a3310b:
    // 00a3310b  81fb22560000           +cmp ebx, 0x5622
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33111  750d                   -jne 0xa33120
    if (!cpu.flags.zf)
    {
        goto L_0x00a33120;
    }
    // 00a33113  808c249500000008       +or byte ptr [esp + 0x95], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a3311b  e96dfbffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a33120:
    // 00a33120  81fb007d0000           +cmp ebx, 0x7d00
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32000 /*0x7d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33126  750d                   -jne 0xa33135
    if (!cpu.flags.zf)
    {
        goto L_0x00a33135;
    }
    // 00a33128  808c249500000010       +or byte ptr [esp + 0x95], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a33130  e958fbffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
L_0x00a33135:
    // 00a33135  81fb44ac0000           +cmp ebx, 0xac44
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44100 /*0xac44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3313b  0f8541fbffff           -jne 0xa32c82
    if (!cpu.flags.zf)
    {
        goto L_0x00a32c82;
    }
    // 00a33141  808c249500000020       +or byte ptr [esp + 0x95], 0x20
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00a33149  e93ffbffff             -jmp 0xa32c8d
    goto L_0x00a32c8d;
}

/* align: skip 0x8b 0xc0 */
void sub_a33150(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33150  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33151  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33152  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33153  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a33154  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a33157  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a33159  c7442440ffffffff       -mov dword ptr [esp + 0x40], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 4294967295 /*0xffffffff*/;
    // 00a33161  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33163  0f8591000000           -jne 0xa331fa
    if (!cpu.flags.zf)
    {
        goto L_0x00a331fa;
    }
    // 00a33169  c744243c03000000       -mov dword ptr [esp + 0x3c], 3
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 3 /*0x3*/;
L_0x00a33171:
    // 00a33171  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a33173  8825b7c0a300           -mov byte ptr [0xa3c0b7], ah
    *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */) = cpu.ah;
    // 00a33179  f7c200000200           +test edx, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 131072 /*0x20000*/));
    // 00a3317f  0f8489000000           -je 0xa3320e
    if (cpu.flags.zf)
    {
        goto L_0x00a3320e;
    }
    // 00a33185  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a33187  0f847a000000           -je 0xa33207
    if (cpu.flags.zf)
    {
        goto L_0x00a33207;
    }
L_0x00a3318d:
    // 00a3318d  803db2c0a30000         +cmp byte ptr [0xa3c0b2], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33194  742a                   -je 0xa331c0
    if (cpu.flags.zf)
    {
        goto L_0x00a331c0;
    }
    // 00a33196  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a33198  8815b2c0a300           -mov byte ptr [0xa3c0b2], dl
    *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */) = cpu.dl;
    // 00a3319e  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a331a3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a331a5  8b3da8c0a300           -mov edi, dword ptr [0xa3c0a8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a331ab  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a331ac  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a331af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a331b1  740d                   -je 0xa331c0
    if (cpu.flags.zf)
    {
        goto L_0x00a331c0;
    }
    // 00a331b3  685cbaa300             -push 0xa3ba5c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730076 /*0xa3ba5c*/;
    cpu.esp -= 4;
    // 00a331b8  e823f7ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a331bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a331c0:
    // 00a331c0  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a331c7  7425                   -je 0xa331ee
    if (cpu.flags.zf)
    {
        goto L_0x00a331ee;
    }
    // 00a331c9  833d9cc0a30000         +cmp dword ptr [0xa3c09c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a331d0  0f8521060000           -jne 0xa337f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a337f7;
    }
L_0x00a331d6:
    // 00a331d6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a331d8  890d9cc0a300           -mov dword ptr [0xa3c09c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */) = cpu.ecx;
    // 00a331de  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a331e0  881db1c0a300           -mov byte ptr [0xa3c0b1], bl
    *app->getMemory<x86::reg8>(x86::reg32(10731697) /* 0xa3c0b1 */) = cpu.bl;
    // 00a331e6  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a331e8  883db0c0a300           -mov byte ptr [0xa3c0b0], bh
    *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */) = cpu.bh;
L_0x00a331ee:
    // 00a331ee  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a331f2  83c444                 +add esp, 0x44
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a331f5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a331f6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a331f7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a331f8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a331f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a331fa:
    // 00a331fa  c744243c04000000       -mov dword ptr [esp + 0x3c], 4
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 4 /*0x4*/;
    // 00a33202  e96affffff             -jmp 0xa33171
    goto L_0x00a33171;
L_0x00a33207:
    // 00a33207  c605b7c0a30001         -mov byte ptr [0xa3c0b7], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */) = 1 /*0x1*/;
L_0x00a3320e:
    // 00a3320e  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00a33211  0f84de010000           -je 0xa333f5
    if (cpu.flags.zf)
    {
        goto L_0x00a333f5;
    }
    // 00a33217  c70500c1a30022560000   -mov dword ptr [0xa3c100], 0x5622
    *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */) = 22050 /*0x5622*/;
L_0x00a33221:
    // 00a33221  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00a33224  0f842d020000           -je 0xa33457
    if (cpu.flags.zf)
    {
        goto L_0x00a33457;
    }
    // 00a3322a  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
L_0x00a3322f:
    // 00a3322f  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
L_0x00a33234:
    // 00a33234  803db5c0a30000         +cmp byte ptr [0xa3c0b5], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3323b  0f845f020000           -je 0xa334a0
    if (cpu.flags.zf)
    {
        goto L_0x00a334a0;
    }
    // 00a33241  c705ccc0a30000200000   -mov dword ptr [0xa3c0cc], 0x2000
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = 8192 /*0x2000*/;
    // 00a3324b  83fe08                 +cmp esi, 8
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
    // 00a3324e  750e                   -jne 0xa3325e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3325e;
    }
    // 00a33250  8b15ccc0a300           -mov edx, dword ptr [0xa3c0cc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */);
    // 00a33256  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a33258  8915ccc0a300           -mov dword ptr [0xa3c0cc], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.edx;
L_0x00a3325e:
    // 00a3325e  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33261  750e                   -jne 0xa33271
    if (!cpu.flags.zf)
    {
        goto L_0x00a33271;
    }
    // 00a33263  8b0dccc0a300           -mov ecx, dword ptr [0xa3c0cc]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */);
    // 00a33269  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3326b  890dccc0a300           -mov dword ptr [0xa3c0cc], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.ecx;
L_0x00a33271:
    // 00a33271  8125ccc0a300f0ff0f00   -and dword ptr [0xa3c0cc], 0xffff0
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a3327b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3327d  8915d4c0a300           -mov dword ptr [0xa3c0d4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731732) /* 0xa3c0d4 */) = cpu.edx;
    // 00a33283  8915c8c0a300           -mov dword ptr [0xa3c0c8], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */) = cpu.edx;
    // 00a33289  8915c0c0a300           -mov dword ptr [0xa3c0c0], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */) = cpu.edx;
    // 00a3328f  8915c4c0a300           -mov dword ptr [0xa3c0c4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731716) /* 0xa3c0c4 */) = cpu.edx;
    // 00a33295  8915d4c0a300           -mov dword ptr [0xa3c0d4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731732) /* 0xa3c0d4 */) = cpu.edx;
    // 00a3329b  8915b8c0a300           -mov dword ptr [0xa3c0b8], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */) = cpu.edx;
    // 00a332a1  8915e0c0a300           -mov dword ptr [0xa3c0e0], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731744) /* 0xa3c0e0 */) = cpu.edx;
    // 00a332a7  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 00a332ac  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a332b1  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a332b3  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a332b8  a3bcc0a300             -mov dword ptr [0xa3c0bc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731708) /* 0xa3c0bc */) = cpu.eax;
    // 00a332bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a332bf  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00a332c2  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00a332c5  a2b3c0a300             -mov byte ptr [0xa3c0b3], al
    *app->getMemory<x86::reg8>(x86::reg32(10731699) /* 0xa3c0b3 */) = cpu.al;
    // 00a332ca  0fbe05b3c0a300         -movsx eax, byte ptr [0xa3c0b3]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731699) /* 0xa3c0b3 */)));
    // 00a332d1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a332d3  a2b4c0a300             -mov byte ptr [0xa3c0b4], al
    *app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */) = cpu.al;
    // 00a332d8  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a332df  751d                   -jne 0xa332fe
    if (!cpu.flags.zf)
    {
        goto L_0x00a332fe;
    }
    // 00a332e1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a332e3  689cc0a300             -push 0xa3c09c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731676 /*0xa3c09c*/;
    cpu.esp -= 4;
    // 00a332e8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a332ea  e87f680000             -call 0xa39b6e
    cpu.esp -= 4;
    sub_a39b6e(app, cpu);
    if (cpu.terminate) return;
    // 00a332ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a332f1  0f85d2010000           -jne 0xa334c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a334c9;
    }
    // 00a332f7  c605b0c0a30001         -mov byte ptr [0xa3c0b0], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */) = 1 /*0x1*/;
L_0x00a332fe:
    // 00a332fe  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a33303  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a33307  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33308  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3330a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3330b  8b0d9cc0a300           -mov ecx, dword ptr [0xa3c09c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a33311  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33312  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33317  0f85e1010000           -jne 0xa334fe
    if (!cpu.flags.zf)
    {
        goto L_0x00a334fe;
    }
    // 00a3331d  803db1c0a30000         +cmp byte ptr [0xa3c0b1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731697) /* 0xa3c0b1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33324  755c                   -jne 0xa33382
    if (!cpu.flags.zf)
    {
        goto L_0x00a33382;
    }
    // 00a33326  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00a3332b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3332d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3332f  e8150f0000             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a33334  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00a33339  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a3333e  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a33341  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a33345  803db7c0a30000         +cmp byte ptr [0xa3c0b7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3334c  7408                   -je 0xa33356
    if (cpu.flags.zf)
    {
        goto L_0x00a33356;
    }
    // 00a3334e  c744240411000000       -mov dword ptr [esp + 4], 0x11
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 17 /*0x11*/;
L_0x00a33356:
    // 00a33356  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33358  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a3335d  68a0c0a300             -push 0xa3c0a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731680 /*0xa3c0a0*/;
    cpu.esp -= 4;
    // 00a33362  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33366  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33368  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33369  8b0d9cc0a300           -mov ecx, dword ptr [0xa3c09c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a3336f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33370  ff500c                 -call dword ptr [eax + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33373  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33375  0f8595010000           -jne 0xa33510
    if (!cpu.flags.zf)
    {
        goto L_0x00a33510;
    }
    // 00a3337b  c605b1c0a30001         -mov byte ptr [0xa3c0b1], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731697) /* 0xa3c0b1 */) = 1 /*0x1*/;
L_0x00a33382:
    // 00a33382  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a33387  66897c242a             -mov word ptr [esp + 0x2a], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.di;
    // 00a3338c  6689542428             -mov word ptr [esp + 0x28], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 00a33391  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a33396  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a3339a  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a333a1  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a333a6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00a333a8  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a333ac  660fbe05b3c0a300       -movsx ax, byte ptr [0xa3c0b3]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731699) /* 0xa3c0b3 */)));
    // 00a333b4  6689442434             -mov word ptr [esp + 0x34], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 00a333b9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a333bb  6689742436             -mov word ptr [esp + 0x36], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.si;
    // 00a333c0  66895c2438             -mov word ptr [esp + 0x38], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.bx;
    // 00a333c5  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a333ca  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a333cc  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a333d0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a333d1  8b1da0c0a300           -mov ebx, dword ptr [0xa3c0a0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a333d7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a333d8  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a333db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a333dd  0f843f010000           -je 0xa33522
    if (cpu.flags.zf)
    {
        goto L_0x00a33522;
    }
    // 00a333e3  6850b9a300             -push 0xa3b950
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729808 /*0xa3b950*/;
    cpu.esp -= 4;
    // 00a333e8  e8f3f4ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a333ed  83c404                 +add esp, 4
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
    // 00a333f0  e998fdffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a333f5:
    // 00a333f5  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 00a333f8  740f                   -je 0xa33409
    if (cpu.flags.zf)
    {
        goto L_0x00a33409;
    }
    // 00a333fa  c70500c1a300803e0000   -mov dword ptr [0xa3c100], 0x3e80
    *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */) = 16000 /*0x3e80*/;
    // 00a33404  e918feffff             -jmp 0xa33221
    goto L_0x00a33221;
L_0x00a33409:
    // 00a33409  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 00a3340c  740f                   -je 0xa3341d
    if (cpu.flags.zf)
    {
        goto L_0x00a3341d;
    }
    // 00a3340e  c70500c1a300007d0000   -mov dword ptr [0xa3c100], 0x7d00
    *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */) = 32000 /*0x7d00*/;
    // 00a33418  e904feffff             -jmp 0xa33221
    goto L_0x00a33221;
L_0x00a3341d:
    // 00a3341d  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 00a33420  740f                   -je 0xa33431
    if (cpu.flags.zf)
    {
        goto L_0x00a33431;
    }
    // 00a33422  c70500c1a30044ac0000   -mov dword ptr [0xa3c100], 0xac44
    *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */) = 44100 /*0xac44*/;
    // 00a3342c  e9f0fdffff             -jmp 0xa33221
    goto L_0x00a33221;
L_0x00a33431:
    // 00a33431  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 00a33434  740f                   -je 0xa33445
    if (cpu.flags.zf)
    {
        goto L_0x00a33445;
    }
    // 00a33436  c70500c1a300112b0000   -mov dword ptr [0xa3c100], 0x2b11
    *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */) = 11025 /*0x2b11*/;
    // 00a33440  e9dcfdffff             -jmp 0xa33221
    goto L_0x00a33221;
L_0x00a33445:
    // 00a33445  688cb8a300             -push 0xa3b88c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729612 /*0xa3b88c*/;
    cpu.esp -= 4;
    // 00a3344a  e891f4ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a3344f  83c404                 +add esp, 4
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
    // 00a33452  e936fdffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a33457:
    // 00a33457  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00a3345a  740f                   -je 0xa3346b
    if (cpu.flags.zf)
    {
        goto L_0x00a3346b;
    }
    // 00a3345c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00a33461  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a33466  e9c9fdffff             -jmp 0xa33234
    goto L_0x00a33234;
L_0x00a3346b:
    // 00a3346b  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00a3346e  740a                   -je 0xa3347a
    if (cpu.flags.zf)
    {
        goto L_0x00a3347a;
    }
    // 00a33470  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a33475  e9b5fdffff             -jmp 0xa3322f
    goto L_0x00a3322f;
L_0x00a3347a:
    // 00a3347a  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a3347d  740f                   -je 0xa3348e
    if (cpu.flags.zf)
    {
        goto L_0x00a3348e;
    }
    // 00a3347f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a33484  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a33489  e9a6fdffff             -jmp 0xa33234
    goto L_0x00a33234;
L_0x00a3348e:
    // 00a3348e  68b8b8a300             -push 0xa3b8b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729656 /*0xa3b8b8*/;
    cpu.esp -= 4;
    // 00a33493  e848f4ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a33498  83c404                 +add esp, 4
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
    // 00a3349b  e9edfcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a334a0:
    // 00a334a0  c705ccc0a30014000000   -mov dword ptr [0xa3c0cc], 0x14
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = 20 /*0x14*/;
    // 00a334aa  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a334af  0faf05ccc0a300         -imul eax, dword ptr [0xa3c0cc]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */))));
    // 00a334b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a334b8  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 00a334bd  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a334bf  a3ccc0a300             -mov dword ptr [0xa3c0cc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.eax;
    // 00a334c4  e9a8fdffff             -jmp 0xa33271
    goto L_0x00a33271;
L_0x00a334c9:
    // 00a334c9  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a334ce  750d                   -jne 0xa334dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a334dd;
    }
    // 00a334d0  c7442440eeffffff       -mov dword ptr [esp + 0x40], 0xffffffee
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 4294967278 /*0xffffffee*/;
    // 00a334d8  e9b0fcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a334dd:
    // 00a334dd  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a334e2  750d                   -jne 0xa334f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a334f1;
    }
    // 00a334e4  c7442440f6ffffff       -mov dword ptr [esp + 0x40], 0xfffffff6
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 4294967286 /*0xfffffff6*/;
    // 00a334ec  e99cfcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a334f1:
    // 00a334f1  c7442440ffffffff       -mov dword ptr [esp + 0x40], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 4294967295 /*0xffffffff*/;
    // 00a334f9  e98ffcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a334fe:
    // 00a334fe  68e8b8a300             -push 0xa3b8e8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729704 /*0xa3b8e8*/;
    cpu.esp -= 4;
    // 00a33503  e8d8f3ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a33508  83c404                 +add esp, 4
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
    // 00a3350b  e97dfcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a33510:
    // 00a33510  681cb9a300             -push 0xa3b91c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729756 /*0xa3b91c*/;
    cpu.esp -= 4;
    // 00a33515  e8c6f3ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a3351a  83c404                 +add esp, 4
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
    // 00a3351d  e96bfcffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a33522:
    // 00a33522  c744241414000000       -mov dword ptr [esp + 0x14], 0x14
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 20 /*0x14*/;
    // 00a3352a  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a3352f  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a33533  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33535  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33536  8b15a0c0a300           -mov edx, dword ptr [0xa3c0a0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a3353c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3353d  ff500c                 -call dword ptr [eax + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33540  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33542  0f8538010000           -jne 0xa33680
    if (!cpu.flags.zf)
    {
        goto L_0x00a33680;
    }
    // 00a33548  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a3354a  0f8442010000           -je 0xa33692
    if (cpu.flags.zf)
    {
        goto L_0x00a33692;
    }
    // 00a33550  f644241804             +test byte ptr [esp + 0x18], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) & 4 /*0x4*/));
    // 00a33555  0f8432fcffff           -je 0xa3318d
    if (cpu.flags.zf)
    {
        goto L_0x00a3318d;
    }
    // 00a3355b  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a3355f  a3d8c0a300             -mov dword ptr [0xa3c0d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */) = cpu.eax;
    // 00a33564  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a3356b  a1d8c0a300             -mov eax, dword ptr [0xa3c0d8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a33570  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00a33572  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 00a33574  0f8513fcffff           -jne 0xa3318d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3318d;
    }
L_0x00a3357a:
    // 00a3357a  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33581  a1d8c0a300             -mov eax, dword ptr [0xa3c0d8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a33586  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00a33588  a3f8c0a300             -mov dword ptr [0xa3c0f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */) = cpu.eax;
    // 00a3358d  8b15f8c0a300           -mov edx, dword ptr [0xa3c0f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33593  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00a33596  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00a3359b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a3359d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a335a0  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a335a2  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a335a7  a3d0c0a300             -mov dword ptr [0xa3c0d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731728) /* 0xa3c0d0 */) = cpu.eax;
    // 00a335ac  a1f8c0a300             -mov eax, dword ptr [0xa3c0f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a335b1  a3dcc0a300             -mov dword ptr [0xa3c0dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */) = cpu.eax;
    // 00a335b6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a335b8  890de8c0a300           -mov dword ptr [0xa3c0e8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731752) /* 0xa3c0e8 */) = cpu.ecx;
    // 00a335be  890decc0a300           -mov dword ptr [0xa3c0ec], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731756) /* 0xa3c0ec */) = cpu.ecx;
    // 00a335c4  890de4c0a300           -mov dword ptr [0xa3c0e4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */) = cpu.ecx;
    // 00a335ca  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a335cc  0f8419010000           -je 0xa336eb
    if (cpu.flags.zf)
    {
        goto L_0x00a336eb;
    }
    // 00a335d2  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
L_0x00a335d7:
    // 00a335d7  a3a8c0a300             -mov dword ptr [0xa3c0a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */) = cpu.eax;
    // 00a335dc  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a335de  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a335e0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a335e2  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a335e7  68f4c0a300             -push 0xa3c0f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731764 /*0xa3c0f4*/;
    cpu.esp -= 4;
    // 00a335ec  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a335ee  68f0c0a300             -push 0xa3c0f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731760 /*0xa3c0f0*/;
    cpu.esp -= 4;
    // 00a335f3  8b35d8c0a300           -mov esi, dword ptr [0xa3c0d8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a335f9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a335fa  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a335fc  8b3da8c0a300           -mov edi, dword ptr [0xa3c0a8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33602  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33603  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33606  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33608  0f857ffbffff           -jne 0xa3318d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3318d;
    }
    // 00a3360e  8b1dd8c0a300           -mov ebx, dword ptr [0xa3c0d8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a33614  a1f0c0a300             -mov eax, dword ptr [0xa3c0f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33619  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3361b  e8290c0000             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a33620  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33625  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33627  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33629  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3362b  8b2dd8c0a300           -mov ebp, dword ptr [0xa3c0d8]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a33631  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a33632  8b15f0c0a300           -mov edx, dword ptr [0xa3c0f0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33638  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33639  8b0da8c0a300           -mov ecx, dword ptr [0xa3c0a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a3363f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33640  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33643  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a33645  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a3364a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3364c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3364e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33650  8b1da8c0a300           -mov ebx, dword ptr [0xa3c0a8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33656  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33657  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3365a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3365c  0f8538010000           -jne 0xa3379a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3379a;
    }
    // 00a33662  803db7c0a30000         +cmp byte ptr [0xa3c0b7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33669  0f853d010000           -jne 0xa337ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a337ac;
    }
    // 00a3366f  c605b2c0a30001         -mov byte ptr [0xa3c0b2], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */) = 1 /*0x1*/;
    // 00a33676  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33678  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a3367b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3367c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3367d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3367e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3367f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33680:
    // 00a33680  6888b9a300             -push 0xa3b988
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729864 /*0xa3b988*/;
    cpu.esp -= 4;
    // 00a33685  e856f2ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a3368a  83c404                 +add esp, 4
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
    // 00a3368d  e9fbfaffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a33692:
    // 00a33692  803db5c0a30000         +cmp byte ptr [0xa3c0b5], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33699  7418                   -je 0xa336b3
    if (cpu.flags.zf)
    {
        goto L_0x00a336b3;
    }
    // 00a3369b  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a336a2  b800a00000             -mov eax, 0xa000
    cpu.eax = 40960 /*0xa000*/;
    // 00a336a7  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00a336a9  a3d8c0a300             -mov dword ptr [0xa3c0d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */) = cpu.eax;
    // 00a336ae  e9c7feffff             -jmp 0xa3357a
    goto L_0x00a3357a;
L_0x00a336b3:
    // 00a336b3  8b1500c1a300           -mov edx, dword ptr [0xa3c100]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a336b9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a336c0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a336c2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a336c5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a336c7  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 00a336cc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a336cf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a336d1  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a336d3  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a336d8  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a336df  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00a336e1  a3d8c0a300             -mov dword ptr [0xa3c0d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */) = cpu.eax;
    // 00a336e6  e98ffeffff             -jmp 0xa3357a
    goto L_0x00a3357a;
L_0x00a336eb:
    // 00a336eb  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00a336f0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a336f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a336f4  b908000100             -mov ecx, 0x10008
    cpu.ecx = 65544 /*0x10008*/;
    // 00a336f9  e84b0b0000             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a336fe  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00a33703  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a33707  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a3370a  a1d8c0a300             -mov eax, dword ptr [0xa3c0d8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731736) /* 0xa3c0d8 */);
    // 00a3370f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a33714  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a33718  66897c242a             -mov word ptr [esp + 0x2a], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.di;
    // 00a3371d  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a33721  66894c2428             -mov word ptr [esp + 0x28], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00a33726  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a3372a  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a3372f  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a33733  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a3373a  a100c1a300             -mov eax, dword ptr [0xa3c100]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */);
    // 00a3373f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00a33741  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a33745  660fbe05b3c0a300       -movsx ax, byte ptr [0xa3c0b3]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731699) /* 0xa3c0b3 */)));
    // 00a3374d  6689742436             -mov word ptr [esp + 0x36], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.si;
    // 00a33752  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a33754  6689442434             -mov word ptr [esp + 0x34], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 00a33759  6689742438             -mov word ptr [esp + 0x38], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.si;
    // 00a3375e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3375f  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a33764  68a4c0a300             -push 0xa3c0a4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731684 /*0xa3c0a4*/;
    cpu.esp -= 4;
    // 00a33769  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3376b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a3376f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33770  8b1d9cc0a300           -mov ebx, dword ptr [0xa3c09c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a33776  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33777  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3377a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3377c  750a                   -jne 0xa33788
    if (!cpu.flags.zf)
    {
        goto L_0x00a33788;
    }
    // 00a3377e  a1a4c0a300             -mov eax, dword ptr [0xa3c0a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731684) /* 0xa3c0a4 */);
    // 00a33783  e94ffeffff             -jmp 0xa335d7
    goto L_0x00a335d7;
L_0x00a33788:
    // 00a33788  68c0b9a300             -push 0xa3b9c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729920 /*0xa3b9c0*/;
    cpu.esp -= 4;
    // 00a3378d  e84ef1ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a33792  83c404                 +add esp, 4
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
    // 00a33795  e9f3f9ffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a3379a:
    // 00a3379a  68f8b9a300             -push 0xa3b9f8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10729976 /*0xa3b9f8*/;
    cpu.esp -= 4;
    // 00a3379f  e83cf1ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a337a4  83c404                 +add esp, 4
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
    // 00a337a7  e9e1f9ffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a337ac:
    // 00a337ac  a1a0c0a300             -mov eax, dword ptr [0xa3c0a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a337b1  68acc0a300             -push 0xa3c0ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731692 /*0xa3c0ac*/;
    cpu.esp -= 4;
    // 00a337b6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a337b8  68c0d0a300             -push 0xa3d0c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10735808 /*0xa3d0c0*/;
    cpu.esp -= 4;
    // 00a337bd  8b35a0c0a300           -mov esi, dword ptr [0xa3c0a0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731680) /* 0xa3c0a0 */);
    // 00a337c3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a337c4  ff10                   -call dword ptr [eax]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a337c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a337c8  7412                   -je 0xa337dc
    if (cpu.flags.zf)
    {
        goto L_0x00a337dc;
    }
    // 00a337ca  682cbaa300             -push 0xa3ba2c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730028 /*0xa3ba2c*/;
    cpu.esp -= 4;
    // 00a337cf  e80cf1ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a337d4  83c404                 +add esp, 4
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
    // 00a337d7  e9b1f9ffff             -jmp 0xa3318d
    goto L_0x00a3318d;
L_0x00a337dc:
    // 00a337dc  e863f3ffff             -call 0xa32b44
    cpu.esp -= 4;
    sub_a32b44(app, cpu);
    if (cpu.terminate) return;
    // 00a337e1  e876f3ffff             -call 0xa32b5c
    cpu.esp -= 4;
    sub_a32b5c(app, cpu);
    if (cpu.terminate) return;
    // 00a337e6  c605b2c0a30001         -mov byte ptr [0xa3c0b2], 1
    *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */) = 1 /*0x1*/;
    // 00a337ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a337ef  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a337f2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a337f3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a337f4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a337f5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a337f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a337f7:
    // 00a337f7  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a337fc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a337fe  8b159cc0a300           -mov edx, dword ptr [0xa3c09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a33804  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33805  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33808  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3380a  0f84c6f9ffff           -je 0xa331d6
    if (cpu.flags.zf)
    {
        goto L_0x00a331d6;
    }
    // 00a33810  6888baa300             -push 0xa3ba88
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730120 /*0xa3ba88*/;
    cpu.esp -= 4;
    // 00a33815  e8c6f0ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a3381a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3381f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33822  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a33825  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33826  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33827  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33828  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33829  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a3382c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3382c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3382d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3382e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3382f  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a33833  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a33837  803db2c0a30000         +cmp byte ptr [0xa3c0b2], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3383e  7521                   -jne 0xa33861
    if (!cpu.flags.zf)
    {
        goto L_0x00a33861;
    }
L_0x00a33840:
    // 00a33840  803db5c0a30000         +cmp byte ptr [0xa3c0b5], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33847  751f                   -jne 0xa33868
    if (!cpu.flags.zf)
    {
        goto L_0x00a33868;
    }
    // 00a33849  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a3384e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a33850  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a33852  e8f9f8ffff             -call 0xa33150
    cpu.esp -= 4;
    sub_a33150(app, cpu);
    if (cpu.terminate) return;
    // 00a33857  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33859  750d                   -jne 0xa33868
    if (!cpu.flags.zf)
    {
        goto L_0x00a33868;
    }
    // 00a3385b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3385c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3385d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3385e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a33861:
    // 00a33861  e816000000             -call 0xa3387c
    cpu.esp -= 4;
    sub_a3387c(app, cpu);
    if (cpu.terminate) return;
    // 00a33866  ebd8                   -jmp 0xa33840
    goto L_0x00a33840;
L_0x00a33868:
    // 00a33868  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a3386a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a3386c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3386e  e8ddf8ffff             -call 0xa33150
    cpu.esp -= 4;
    sub_a33150(app, cpu);
    if (cpu.terminate) return;
    // 00a33873  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33874  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33875  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33876  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a3387c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3387c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3387d  803db2c0a30000         +cmp byte ptr [0xa3c0b2], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33884  7530                   -jne 0xa338b6
    if (!cpu.flags.zf)
    {
        goto L_0x00a338b6;
    }
L_0x00a33886:
    // 00a33886  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3388d  7423                   -je 0xa338b2
    if (cpu.flags.zf)
    {
        goto L_0x00a338b2;
    }
    // 00a3388f  833d9cc0a30000         +cmp dword ptr [0xa3c09c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33896  7539                   -jne 0xa338d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a338d1;
    }
L_0x00a33898:
    // 00a33898  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33899  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a3389b  89359cc0a300           -mov dword ptr [0xa3c09c], esi
    *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */) = cpu.esi;
    // 00a338a1  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a338a3  881db1c0a300           -mov byte ptr [0xa3c0b1], bl
    *app->getMemory<x86::reg8>(x86::reg32(10731697) /* 0xa3c0b1 */) = cpu.bl;
    // 00a338a9  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a338ab  883db0c0a300           -mov byte ptr [0xa3c0b0], bh
    *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */) = cpu.bh;
    // 00a338b1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a338b2:
    // 00a338b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a338b4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a338b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a338b6:
    // 00a338b6  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a338b8  8815b2c0a300           -mov byte ptr [0xa3c0b2], dl
    *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */) = cpu.dl;
    // 00a338be  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a338c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a338c5  8b15a8c0a300           -mov edx, dword ptr [0xa3c0a8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a338cb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a338cc  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a338cf  ebb5                   -jmp 0xa33886
    goto L_0x00a33886;
L_0x00a338d1:
    // 00a338d1  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a338d6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a338d8  8b1d9cc0a300           -mov ebx, dword ptr [0xa3c09c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a338de  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a338df  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a338e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a338e4  74b2                   -je 0xa33898
    if (cpu.flags.zf)
    {
        goto L_0x00a33898;
    }
    // 00a338e6  68bcbaa300             -push 0xa3babc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730172 /*0xa3babc*/;
    cpu.esp -= 4;
    // 00a338eb  e8f0efffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a338f0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a338f5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a338f8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a338f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a338fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a338fc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a33901  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void sub_a33904(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33904  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33906  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a3390c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3390c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3390e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a33910(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33910  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33911  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33912  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33913  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33914  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a33916  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a33918  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a3391a  7e41                   -jle 0xa3395d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3395d;
    }
L_0x00a3391c:
    // 00a3391c  833de4c0a30000         +cmp dword ptr [0xa3c0e4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33923  7e46                   -jle 0xa3396b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3396b;
    }
L_0x00a33925:
    // 00a33925  a1e4c0a300             -mov eax, dword ptr [0xa3c0e4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */);
    // 00a3392a  39c6                   +cmp esi, eax
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
    // 00a3392c  0f8e9f000000           -jle 0xa339d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a339d1;
    }
    // 00a33932  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a33934:
    // 00a33934  8b15e4c0a300           -mov edx, dword ptr [0xa3c0e4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */);
    // 00a3393a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3393b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a3393d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3393e  8915e4c0a300           -mov dword ptr [0xa3c0e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */) = cpu.edx;
    // 00a33944  ff1504c1a300           -call dword ptr [0xa3c104]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731780) /* 0xa3c104 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3394a  8b0db1c0a300           -mov ecx, dword ptr [0xa3c0b1]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731697) /* 0xa3c0b1 */);
    // 00a33950  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00a33953  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a33955  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00a33957  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a33959  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a3395b  7fbf                   -jg 0xa3391c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a3391c;
    }
L_0x00a3395d:
    // 00a3395d  803db7c0a30000         +cmp byte ptr [0xa3c0b7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33964  7572                   -jne 0xa339d8
    if (!cpu.flags.zf)
    {
        goto L_0x00a339d8;
    }
    // 00a33966  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33967  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33968  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33969  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3396a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3396b:
    // 00a3396b  ff05e8c0a300           -inc dword ptr [0xa3c0e8]
    (*app->getMemory<x86::reg32>(x86::reg32(10731752) /* 0xa3c0e8 */))++;
    // 00a33971  ff1514c1a300           -call dword ptr [0xa3c114]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731796) /* 0xa3c114 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33977  a1e8c0a300             -mov eax, dword ptr [0xa3c0e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731752) /* 0xa3c0e8 */);
    // 00a3397c  0faf0500c1a300         -imul eax, dword ptr [0xa3c100]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731776) /* 0xa3c100 */))));
    // 00a33983  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a33988  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3398a  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a3398c  8b0decc0a300           -mov ecx, dword ptr [0xa3c0ec]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731756) /* 0xa3c0ec */);
    // 00a33992  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a33994  a3e4c0a300             -mov dword ptr [0xa3c0e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */) = cpu.eax;
    // 00a33999  25f0ffff0f             -and eax, 0xffffff0
    cpu.eax &= x86::reg32(x86::sreg32(268435440 /*0xffffff0*/));
    // 00a3399e  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a339a1  a3e4c0a300             -mov dword ptr [0xa3c0e4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731748) /* 0xa3c0e4 */) = cpu.eax;
    // 00a339a6  8b0de8c0a300           -mov ecx, dword ptr [0xa3c0e8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731752) /* 0xa3c0e8 */);
    // 00a339ac  8915ecc0a300           -mov dword ptr [0xa3c0ec], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731756) /* 0xa3c0ec */) = cpu.edx;
    // 00a339b2  81f930750000           +cmp ecx, 0x7530
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30000 /*0x7530*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a339b8  0f8e67ffffff           -jle 0xa33925
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a33925;
    }
    // 00a339be  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a339c0  891de8c0a300           -mov dword ptr [0xa3c0e8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731752) /* 0xa3c0e8 */) = cpu.ebx;
    // 00a339c6  891decc0a300           -mov dword ptr [0xa3c0ec], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731756) /* 0xa3c0ec */) = cpu.ebx;
    // 00a339cc  e954ffffff             -jmp 0xa33925
    goto L_0x00a33925;
L_0x00a339d1:
    // 00a339d1  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a339d3  e95cffffff             -jmp 0xa33934
    goto L_0x00a33934;
L_0x00a339d8:
    // 00a339d8  e8eb030000             -call 0xa33dc8
    cpu.esp -= 4;
    sub_a33dc8(app, cpu);
    if (cpu.terminate) return;
    // 00a339dd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a339de  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a339df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a339e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a339e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a339e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a339e4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a339e5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a339e6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a339e7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a339e8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a339e9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a339ea  8b15b8c0a300           -mov edx, dword ptr [0xa3c0b8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */);
    // 00a339f0  81fa00000011           +cmp edx, 0x11000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(285212672 /*0x11000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a339f6  0f879f000000           -ja 0xa33a9b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a33a9b;
    }
L_0x00a339fc:
    // 00a339fc  a1b8c0a300             -mov eax, dword ptr [0xa3c0b8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */);
    // 00a33a01  8b35bcc0a300           -mov esi, dword ptr [0xa3c0bc]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731708) /* 0xa3c0bc */);
    // 00a33a07  8b3df8c0a300           -mov edi, dword ptr [0xa3c0f8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33a0d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a33a0f  39f8                   +cmp eax, edi
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
    // 00a33a11  7c10                   -jl 0xa33a23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33a23;
    }
    // 00a33a13  8b2db8c0a300           -mov ebp, dword ptr [0xa3c0b8]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */);
    // 00a33a19  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a33a1b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a33a1d  892db8c0a300           -mov dword ptr [0xa3c0b8], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */) = cpu.ebp;
L_0x00a33a23:
    // 00a33a23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33a25  0f8cab000000           -jl 0xa33ad6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33ad6;
    }
    // 00a33a2b  8b15e0c0a300           -mov edx, dword ptr [0xa3c0e0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731744) /* 0xa3c0e0 */);
    // 00a33a31  42                     -inc edx
    (cpu.edx)++;
    // 00a33a32  8b0ddcc0a300           -mov ecx, dword ptr [0xa3c0dc]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */);
    // 00a33a38  8915e0c0a300           -mov dword ptr [0xa3c0e0], edx
    *app->getMemory<x86::reg32>(x86::reg32(10731744) /* 0xa3c0e0 */) = cpu.edx;
    // 00a33a3e  39c8                   +cmp eax, ecx
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
    // 00a33a40  0f8c78000000           -jl 0xa33abe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33abe;
    }
L_0x00a33a46:
    // 00a33a46  8b1de0c0a300           -mov ebx, dword ptr [0xa3c0e0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731744) /* 0xa3c0e0 */);
    // 00a33a4c  81fbb80b0000           +cmp ebx, 0xbb8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33a52  7c40                   -jl 0xa33a94
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33a94;
    }
    // 00a33a54  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00a33a59  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a33a5b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a33a5d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a33a60  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a33a62  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a33a64  752e                   -jne 0xa33a94
    if (!cpu.flags.zf)
    {
        goto L_0x00a33a94;
    }
    // 00a33a66  833ddcc0a30010         +cmp dword ptr [0xa3c0dc], 0x10
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33a6d  7e56                   -jle 0xa33ac5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a33ac5;
    }
    // 00a33a6f  8b3dccc0a300           -mov edi, dword ptr [0xa3c0cc]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */);
    // 00a33a75  4f                     -dec edi
    (cpu.edi)--;
    // 00a33a76  a1f8c0a300             -mov eax, dword ptr [0xa3c0f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33a7b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00a33a7d  893dccc0a300           -mov dword ptr [0xa3c0cc], edi
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.edi;
    // 00a33a83  81e5f0ff0f00           -and ebp, 0xffff0
    cpu.ebp &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a33a89  a3dcc0a300             -mov dword ptr [0xa3c0dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */) = cpu.eax;
    // 00a33a8e  892dccc0a300           -mov dword ptr [0xa3c0cc], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.ebp;
L_0x00a33a94:
    // 00a33a94  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a95  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a96  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a97  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a98  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a99  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33a9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33a9b:
    // 00a33a9b  8b1dbcc0a300           -mov ebx, dword ptr [0xa3c0bc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731708) /* 0xa3c0bc */);
    // 00a33aa1  8d8a000000f0           -lea ecx, [edx - 0x10000000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-268435456) /* -0x10000000 */);
    // 00a33aa7  81eb00000010           +sub ebx, 0x10000000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a33aad  890db8c0a300           -mov dword ptr [0xa3c0b8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */) = cpu.ecx;
    // 00a33ab3  891dbcc0a300           -mov dword ptr [0xa3c0bc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731708) /* 0xa3c0bc */) = cpu.ebx;
    // 00a33ab9  e93effffff             -jmp 0xa339fc
    goto L_0x00a339fc;
L_0x00a33abe:
    // 00a33abe  a3dcc0a300             -mov dword ptr [0xa3c0dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */) = cpu.eax;
    // 00a33ac3  eb81                   -jmp 0xa33a46
    goto L_0x00a33a46;
L_0x00a33ac5:
    // 00a33ac5  a1f8c0a300             -mov eax, dword ptr [0xa3c0f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33aca  a3dcc0a300             -mov dword ptr [0xa3c0dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731740) /* 0xa3c0dc */) = cpu.eax;
    // 00a33acf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ad5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33ad6:
    // 00a33ad6  833db8c0a30000         +cmp dword ptr [0xa3c0b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33add  74b5                   -je 0xa33a94
    if (cpu.flags.zf)
    {
        goto L_0x00a33a94;
    }
    // 00a33adf  8b1dccc0a300           -mov ebx, dword ptr [0xa3c0cc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */);
    // 00a33ae5  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33ae7  891dccc0a300           -mov dword ptr [0xa3c0cc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.ebx;
    // 00a33aed  8d730f                 -lea esi, [ebx + 0xf]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 00a33af0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a33af2  8935ccc0a300           -mov dword ptr [0xa3c0cc], esi
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.esi;
    // 00a33af8  81e7f0ff0f00           -and edi, 0xffff0
    cpu.edi &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a33afe  8b2dd0c0a300           -mov ebp, dword ptr [0xa3c0d0]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10731728) /* 0xa3c0d0 */);
    // 00a33b04  893dccc0a300           -mov dword ptr [0xa3c0cc], edi
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.edi;
    // 00a33b0a  39ef                   +cmp edi, ebp
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
    // 00a33b0c  7e06                   -jle 0xa33b14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a33b14;
    }
    // 00a33b0e  892dccc0a300           -mov dword ptr [0xa3c0cc], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */) = cpu.ebp;
L_0x00a33b14:
    // 00a33b14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33b16  a3e0c0a300             -mov dword ptr [0xa3c0e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731744) /* 0xa3c0e0 */) = cpu.eax;
    // 00a33b1b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b1c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b1d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b1e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b1f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b20  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a33b24(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33b24  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33b25  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33b26  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33b27  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a33b28  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33b2b  803db2c0a30000         +cmp byte ptr [0xa3c0b2], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731698) /* 0xa3c0b2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33b32  7508                   -jne 0xa33b3c
    if (!cpu.flags.zf)
    {
        goto L_0x00a33b3c;
    }
L_0x00a33b34:
    // 00a33b34  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33b37  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b38  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b39  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b3a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33b3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33b3c:
    // 00a33b3c  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33b41  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33b43  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a33b45  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33b46  8b0da8c0a300           -mov ecx, dword ptr [0xa3c0a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33b4c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33b4d  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33b50  f6042402               +test byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp) & 2 /*0x2*/));
    // 00a33b54  0f85d2000000           -jne 0xa33c2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a33c2c;
    }
    // 00a33b5a  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33b5f  68c0c0a300             -push 0xa3c0c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731712 /*0xa3c0c0*/;
    cpu.esp -= 4;
    // 00a33b64  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33b66  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33b68  8b1da8c0a300           -mov ebx, dword ptr [0xa3c0a8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33b6e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33b6f  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33b72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33b74  75be                   -jne 0xa33b34
    if (!cpu.flags.zf)
    {
        goto L_0x00a33b34;
    }
    // 00a33b76  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33b7d  d32dc0c0a300           -shr dword ptr [0xa3c0c0], cl
    *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */) >>= cpu.cl % 32;
    // 00a33b83  8125c0c0a300f0ffff00   -and dword ptr [0xa3c0c0], 0xfffff0
    *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */) &= x86::reg32(x86::sreg32(16777200 /*0xfffff0*/));
    // 00a33b8d  a1c0c0a300             -mov eax, dword ptr [0xa3c0c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
    // 00a33b92  3b05c4c0a300           +cmp eax, dword ptr [0xa3c0c4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731716) /* 0xa3c0c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33b98  0f82be000000           -jb 0xa33c5c
    if (cpu.flags.cf)
    {
        goto L_0x00a33c5c;
    }
    // 00a33b9e  a1c0c0a300             -mov eax, dword ptr [0xa3c0c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
L_0x00a33ba3:
    // 00a33ba3  2b05c4c0a300           -sub eax, dword ptr [0xa3c0c4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731716) /* 0xa3c0c4 */)));
    // 00a33ba9  0105bcc0a300           -add dword ptr [0xa3c0bc], eax
    (*app->getMemory<x86::reg32>(x86::reg32(10731708) /* 0xa3c0bc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a33baf  a1c0c0a300             -mov eax, dword ptr [0xa3c0c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
    // 00a33bb4  3b05c4c0a300           +cmp eax, dword ptr [0xa3c0c4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731716) /* 0xa3c0c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33bba  0f85ac000000           -jne 0xa33c6c
    if (!cpu.flags.zf)
    {
        goto L_0x00a33c6c;
    }
    // 00a33bc0  8b15c4caa300           -mov edx, dword ptr [0xa3cac4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734276) /* 0xa3cac4 */);
    // 00a33bc6  42                     -inc edx
    (cpu.edx)++;
    // 00a33bc7  8915c4caa300           -mov dword ptr [0xa3cac4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734276) /* 0xa3cac4 */) = cpu.edx;
    // 00a33bcd  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33bd3  0f8f9f000000           -jg 0xa33c78
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a33c78;
    }
L_0x00a33bd9:
    // 00a33bd9  8b1dc0c0a300           -mov ebx, dword ptr [0xa3c0c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
    // 00a33bdf  031dccc0a300           -add ebx, dword ptr [0xa3c0cc]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */)));
    // 00a33be5  81e3f0ff0f00           -and ebx, 0xffff0
    cpu.ebx &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00a33beb  3b1df8c0a300           +cmp ebx, dword ptr [0xa3c0f8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33bf1  7c06                   -jl 0xa33bf9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33bf9;
    }
    // 00a33bf3  2b1df8c0a300           -sub ebx, dword ptr [0xa3c0f8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */)));
L_0x00a33bf9:
    // 00a33bf9  3b1dc8c0a300           +cmp ebx, dword ptr [0xa3c0c8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a33bff  0f8c92000000           -jl 0xa33c97
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33c97;
    }
    // 00a33c05  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a33c07  2b35c8c0a300           -sub esi, dword ptr [0xa3c0c8]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */)));
    // 00a33c0d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00a33c0f:
    // 00a33c0f  8b15f8c0a300           -mov edx, dword ptr [0xa3c0f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33c15  83ea10                 -sub edx, 0x10
    (cpu.edx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a33c18  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 00a33c1b  39d0                   +cmp eax, edx
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
    // 00a33c1d  0f8c88000000           -jl 0xa33cab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33cab;
    }
    // 00a33c23  8305ccc0a30010         +add dword ptr [0xa3c0cc], 0x10
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10731724) /* 0xa3c0cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a33c2a  ebad                   -jmp 0xa33bd9
    goto L_0x00a33bd9;
L_0x00a33c2c:
    // 00a33c2c  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c31  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33c33  8b35a8c0a300           -mov esi, dword ptr [0xa3c0a8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c39  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33c3a  ff5050                 -call dword ptr [eax + 0x50]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33c3d  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a33c3f  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c44  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33c46  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33c48  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33c4a  8b3da8c0a300           -mov edi, dword ptr [0xa3c0a8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c50  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33c51  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33c54  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33c57  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c58  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c59  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c5a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33c5c:
    // 00a33c5c  a1c0c0a300             -mov eax, dword ptr [0xa3c0c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
    // 00a33c61  0305f8c0a300           +add eax, dword ptr [0xa3c0f8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a33c67  e937ffffff             -jmp 0xa33ba3
    goto L_0x00a33ba3;
L_0x00a33c6c:
    // 00a33c6c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a33c6e  a3c4caa300             -mov dword ptr [0xa3cac4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734276) /* 0xa3cac4 */) = cpu.eax;
    // 00a33c73  e961ffffff             -jmp 0xa33bd9
    goto L_0x00a33bd9;
L_0x00a33c78:
    // 00a33c78  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a33c7a  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c7f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33c81  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33c83  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33c85  8b1da8c0a300           -mov ebx, dword ptr [0xa3c0a8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33c8b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33c8c  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33c8f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33c92  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c93  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c94  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c95  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33c96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33c97:
    // 00a33c97  a1f8c0a300             -mov eax, dword ptr [0xa3c0f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731768) /* 0xa3c0f8 */);
    // 00a33c9c  2b05c8c0a300           +sub eax, dword ptr [0xa3c0c8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a33ca2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a33ca4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a33ca6  e964ffffff             -jmp 0xa33c0f
    goto L_0x00a33c0f;
L_0x00a33cab:
    // 00a33cab  803db5c0a30000         +cmp byte ptr [0xa3c0b5], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731701) /* 0xa3c0b5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33cb2  7505                   -jne 0xa33cb9
    if (!cpu.flags.zf)
    {
        goto L_0x00a33cb9;
    }
    // 00a33cb4  e82bfdffff             -call 0xa339e4
    cpu.esp -= 4;
    sub_a339e4(app, cpu);
    if (cpu.terminate) return;
L_0x00a33cb9:
    // 00a33cb9  a1c0c0a300             -mov eax, dword ptr [0xa3c0c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731712) /* 0xa3c0c0 */);
    // 00a33cbe  a3c4c0a300             -mov dword ptr [0xa3c0c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10731716) /* 0xa3c0c4 */) = cpu.eax;
    // 00a33cc3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a33cc5  0f84ee000000           -je 0xa33db9
    if (cpu.flags.zf)
    {
        goto L_0x00a33db9;
    }
    // 00a33ccb  0135b8c0a300           -add dword ptr [0xa3c0b8], esi
    (*app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */)) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a33cd1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33cd3  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33cd8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33cda  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33cdc  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33cde  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33ce5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a33ce7  68f4c0a300             -push 0xa3c0f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731764 /*0xa3c0f4*/;
    cpu.esp -= 4;
    // 00a33cec  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00a33cee  68f0c0a300             -push 0xa3c0f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731760 /*0xa3c0f0*/;
    cpu.esp -= 4;
    // 00a33cf3  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33cfa  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33cfb  a1c8c0a300             -mov eax, dword ptr [0xa3c0c8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */);
    // 00a33d00  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00a33d02  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33d03  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d08  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33d09  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33d0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33d0e  7532                   -jne 0xa33d42
    if (!cpu.flags.zf)
    {
        goto L_0x00a33d42;
    }
    // 00a33d10  a1f0c0a300             -mov eax, dword ptr [0xa3c0f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33d15  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a33d17  e8f4fbffff             -call 0xa33910
    cpu.esp -= 4;
    sub_a33910(app, cpu);
    if (cpu.terminate) return;
    // 00a33d1c  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d21  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33d23  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d25  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33d2c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d2e  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 00a33d30  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33d31  8b15f0c0a300           -mov edx, dword ptr [0xa3c0f0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33d37  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33d38  8b0da8c0a300           -mov ecx, dword ptr [0xa3c0a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d3e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33d3f  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a33d42:
    // 00a33d42  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a33d44  7473                   -je 0xa33db9
    if (cpu.flags.zf)
    {
        goto L_0x00a33db9;
    }
    // 00a33d46  8b35b8c0a300           -mov esi, dword ptr [0xa3c0b8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */);
    // 00a33d4c  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a33d4e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d50  8935b8c0a300           -mov dword ptr [0xa3c0b8], esi
    *app->getMemory<x86::reg32>(x86::reg32(10731704) /* 0xa3c0b8 */) = cpu.esi;
    // 00a33d56  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d58  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d5d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d5f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33d61  68f4c0a300             -push 0xa3c0f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731764 /*0xa3c0f4*/;
    cpu.esp -= 4;
    // 00a33d66  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33d6d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a33d6f  68f0c0a300             -push 0xa3c0f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731760 /*0xa3c0f0*/;
    cpu.esp -= 4;
    // 00a33d74  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00a33d76  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33d77  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d79  8b2da8c0a300           -mov ebp, dword ptr [0xa3c0a8]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d7f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a33d80  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33d83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33d85  750c                   -jne 0xa33d93
    if (!cpu.flags.zf)
    {
        goto L_0x00a33d93;
    }
    // 00a33d87  a1f0c0a300             -mov eax, dword ptr [0xa3c0f0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33d8c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a33d8e  e87dfbffff             -call 0xa33910
    cpu.esp -= 4;
    sub_a33910(app, cpu);
    if (cpu.terminate) return;
L_0x00a33d93:
    // 00a33d93  a1a8c0a300             -mov eax, dword ptr [0xa3c0a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33d98  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33d9a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33d9c  0fbe0db4c0a300         -movsx ecx, byte ptr [0xa3c0b4]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(10731700) /* 0xa3c0b4 */)));
    // 00a33da3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33da5  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 00a33da7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a33da8  8b15f0c0a300           -mov edx, dword ptr [0xa3c0f0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10731760) /* 0xa3c0f0 */);
    // 00a33dae  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33daf  8b0da8c0a300           -mov ecx, dword ptr [0xa3c0a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10731688) /* 0xa3c0a8 */);
    // 00a33db5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33db6  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a33db9:
    // 00a33db9  891dc8c0a300           -mov dword ptr [0xa3c0c8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10731720) /* 0xa3c0c8 */) = cpu.ebx;
    // 00a33dbf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33dc2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dc3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dc4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dc5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a33dc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33dc8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33dc9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33dca  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33dcb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a33dcc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33dcf  ff05c8caa300           -inc dword ptr [0xa3cac8]
    (*app->getMemory<x86::reg32>(x86::reg32(10734280) /* 0xa3cac8 */))++;
    // 00a33dd5  f605c8caa30003         +test byte ptr [0xa3cac8], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(10734280) /* 0xa3cac8 */) & 3 /*0x3*/));
    // 00a33ddc  7516                   -jne 0xa33df4
    if (!cpu.flags.zf)
    {
        goto L_0x00a33df4;
    }
    // 00a33dde  be24c1a300             -mov esi, 0xa3c124
    cpu.esi = 10731812 /*0xa3c124*/;
    // 00a33de3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a33de5:
    // 00a33de5  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a33de7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a33de9  7511                   -jne 0xa33dfc
    if (!cpu.flags.zf)
    {
        goto L_0x00a33dfc;
    }
L_0x00a33deb:
    // 00a33deb  43                     -inc ebx
    (cpu.ebx)++;
    // 00a33dec  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a33def  83fb10                 +cmp ebx, 0x10
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
    // 00a33df2  7cf1                   -jl 0xa33de5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a33de5;
    }
L_0x00a33df4:
    // 00a33df4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a33df7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33df8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33df9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dfa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33dfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a33dfc:
    // 00a33dfc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a33dfe  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a33e00  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a33e02  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33e03  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33e04  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33e07  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 00a33e0b  75de                   -jne 0xa33deb
    if (!cpu.flags.zf)
    {
        goto L_0x00a33deb;
    }
    // 00a33e0d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33e0e  e89d030000             -call 0xa341b0
    cpu.esp -= 4;
    sub_a341b0(app, cpu);
    if (cpu.terminate) return;
    // 00a33e13  ebd6                   -jmp 0xa33deb
    goto L_0x00a33deb;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a33e18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33e18  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a33e1c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a33e23  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a33e25  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a33e28  0524c1a300             -add eax, 0xa3c124
    (cpu.eax) += x86::reg32(x86::sreg32(10731812 /*0xa3c124*/));
    // 00a33e2d  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33e31  885013                 -mov byte ptr [eax + 0x13], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */) = cpu.dl;
    // 00a33e34  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33e3b  7505                   -jne 0xa33e42
    if (!cpu.flags.zf)
    {
        goto L_0x00a33e42;
    }
    // 00a33e3d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a33e3f:
    // 00a33e3f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a33e42:
    // 00a33e42  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33e46  8b1455c2c9a300         -mov edx, dword ptr [edx*2 + 0xa3c9c2]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734018) /* 0xa3c9c2 */ + cpu.edx * 2);
    // 00a33e4d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00a33e50  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33e52  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33e53  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33e55  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33e56  ff513c                 -call dword ptr [ecx + 0x3c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33e59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33e5b  74e2                   -je 0xa33e3f
    if (cpu.flags.zf)
    {
        goto L_0x00a33e3f;
    }
    // 00a33e5d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a33e62  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a33e68(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33e68  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a33e6b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a33e6d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33e6e  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a33e72  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a33e73  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a33e77  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33e78  ff151cc1a300           -call dword ptr [0xa3c11c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731804) /* 0xa3c11c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33e7e  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp)));
    // 00a33e81  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a33e85  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a33e87  dd05ecbaa300           -fld qword ptr [0xa3baec]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(x86::reg32(10730220) /* 0xa3baec */)));
    // 00a33e8d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a33e8f  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00a33e91  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a33e98  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33e9a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a33e9c  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33e9f  d9442404               -fld dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00a33ea3  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a33ea5  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 00a33ea7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a33ea9  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33eab  d95c2404               -fstp dword ptr [esp + 4]
    *app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33eaf  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a33eb3  dcc9                   -fmul st(1), st(0)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    // 00a33eb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a33eb8  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a33ebc  0524c1a300             -add eax, 0xa3c124
    (cpu.eax) += x86::reg32(x86::sreg32(10731812 /*0xa3c124*/));
    // 00a33ec1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00a33ec3  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33ec5  d95c2408               -fstp dword ptr [esp + 8]
    *app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a33ec9  6689500c               -mov word ptr [eax + 0xc], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 00a33ecd  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a33ed1  6689500e               -mov word ptr [eax + 0xe], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 00a33ed5  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33edc  7508                   -jne 0xa33ee6
    if (!cpu.flags.zf)
    {
        goto L_0x00a33ee6;
    }
    // 00a33ede  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a33ee0:
    // 00a33ee0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a33ee3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a33ee6:
    // 00a33ee6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a33ee8  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00a33eec  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a33eef  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00a33ef3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33ef5  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00a33ef9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33efa  ff524c                 -call dword ptr [edx + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33efd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33eff  74df                   -je 0xa33ee0
    if (cpu.flags.zf)
    {
        goto L_0x00a33ee0;
    }
    // 00a33f01  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a33f06  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a33f09  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void sub_a33f0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33f0c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33f10  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a33f14  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a33f1b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a33f1d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a33f20  0524c1a300             -add eax, 0xa3c124
    (cpu.eax) += x86::reg32(x86::sreg32(10731812 /*0xa3c124*/));
    // 00a33f25  66894810               -mov word ptr [eax + 0x10], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.cx;
    // 00a33f29  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33f30  7505                   -jne 0xa33f37
    if (!cpu.flags.zf)
    {
        goto L_0x00a33f37;
    }
    // 00a33f32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a33f34:
    // 00a33f34  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00a33f37:
    // 00a33f37  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a33f38  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33f3a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a33f3b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a33f3d  ff5244                 -call dword ptr [edx + 0x44]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a33f40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33f42  74f0                   -je 0xa33f34
    if (cpu.flags.zf)
    {
        goto L_0x00a33f34;
    }
    // 00a33f44  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a33f49  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void sub_a33f4c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33f4c  803db7c0a30000         +cmp byte ptr [0xa3c0b7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33f53  7409                   -je 0xa33f5e
    if (cpu.flags.zf)
    {
        goto L_0x00a33f5e;
    }
    // 00a33f55  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33f5c  7505                   -jne 0xa33f63
    if (!cpu.flags.zf)
    {
        goto L_0x00a33f63;
    }
L_0x00a33f5e:
    // 00a33f5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33f60  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00a33f63:
    // 00a33f63  e8e0e9ffff             -call 0xa32948
    cpu.esp -= 4;
    sub_a32948(app, cpu);
    if (cpu.terminate) return;
    // 00a33f68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a33f6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a33f6c  7ef0                   -jle 0xa33f5e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a33f5e;
    }
    // 00a33f6e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a33f71  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a33f73  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a33f76  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a33f78  05a4c2a300             -add eax, 0xa3c2a4
    (cpu.eax) += x86::reg32(x86::sreg32(10732196 /*0xa3c2a4*/));
    // 00a33f7d  c6401800               -mov byte ptr [eax + 0x18], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a33f81  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33f85  c6401901               -mov byte ptr [eax + 0x19], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) = 1 /*0x1*/;
    // 00a33f89  884816                 -mov byte ptr [eax + 0x16], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = cpu.cl;
    // 00a33f8c  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a33f90  884817                 -mov byte ptr [eax + 0x17], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */) = cpu.cl;
    // 00a33f93  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a33f97  66894814               -mov word ptr [eax + 0x14], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.cx;
    // 00a33f9b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a33f9f  894808                 -mov dword ptr [eax + 8], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a33fa2  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a33fa6  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a33fa9  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a33fad  894810                 -mov dword ptr [eax + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00a33fb0  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a33fb4  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a33fb6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a33fb8  e8bfe9ffff             -call 0xa3297c
    cpu.esp -= 4;
    sub_a3297c(app, cpu);
    if (cpu.terminate) return;
    // 00a33fbd  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void sub_a33fc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a33fc0  803db7c0a30000         +cmp byte ptr [0xa3c0b7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33fc7  742b                   -je 0xa33ff4
    if (cpu.flags.zf)
    {
        goto L_0x00a33ff4;
    }
    // 00a33fc9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a33fca  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a33fce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a33fd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a33fd3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a33fd6  bba4c2a300             -mov ebx, 0xa3c2a4
    cpu.ebx = 10732196 /*0xa3c2a4*/;
    // 00a33fdb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a33fdd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a33fdf  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a33fe6  7514                   -jne 0xa33ffc
    if (!cpu.flags.zf)
    {
        goto L_0x00a33ffc;
    }
    // 00a33fe8  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00a33fee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a33ff0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a33ff1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a33ff4:
    // 00a33ff4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a33ff9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a33ffc:
    // 00a33ffc  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a33fff  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34000  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34002  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34005  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00a3400b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3400d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3400e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a34014(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34014  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34015  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34016  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a34017  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34018  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00a3401b  8b6c247c               -mov ebp, dword ptr [esp + 0x7c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00a3401f  8a25b7c0a300           -mov ah, byte ptr [0xa3c0b7]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(10731703) /* 0xa3c0b7 */);
    // 00a34025  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a34027  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a34029  7542                   -jne 0xa3406d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3406d;
    }
L_0x00a3402b:
    // 00a3402b  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3402d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a3402f  740b                   -je 0xa3403c
    if (cpu.flags.zf)
    {
        goto L_0x00a3403c;
    }
    // 00a34031  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34034  7406                   -je 0xa3403c
    if (cpu.flags.zf)
    {
        goto L_0x00a3403c;
    }
    // 00a34036  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34037  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a34039  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a3403c:
    // 00a3403c  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a3403f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a34041  7407                   -je 0xa3404a
    if (cpu.flags.zf)
    {
        goto L_0x00a3404a;
    }
    // 00a34043  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34044  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp);
    // 00a34047  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a3404a:
    // 00a3404a  c7460400000000         -mov dword ptr [esi + 4], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a34051  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00a34057  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3405c  c7460800000000         -mov dword ptr [esi + 8], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a34063  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00a34066  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34067  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34068  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34069  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3406a  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00a3406d:
    // 00a3406d  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a34071  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a34074  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a34076  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a34079  bba4c2a300             -mov ebx, 0xa3c2a4
    cpu.ebx = 10732196 /*0xa3c2a4*/;
    // 00a3407e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34080  ba60000000             -mov edx, 0x60
    cpu.edx = 96 /*0x60*/;
    // 00a34085  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a34087  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a3408a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a3408c  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a34091  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34092  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34094  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34095  ff5610                 -call dword ptr [esi + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34098  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a3409f  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a340a1  be24c1a300             -mov esi, 0xa3c124
    cpu.esi = 10731812 /*0xa3c124*/;
    // 00a340a6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a340a9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a340ab  8a442478               -mov al, byte ptr [esp + 0x78]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00a340af  884614                 -mov byte ptr [esi + 0x14], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 00a340b2  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a340b9  8b8c2480000000         -mov ecx, dword ptr [esp + 0x80]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00a340c0  884612                 -mov byte ptr [esi + 0x12], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 00a340c3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a340c5  7553                   -jne 0xa3411a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3411a;
    }
L_0x00a340c7:
    // 00a340c7  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a340ca  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a340cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a340cf:
    // 00a340cf  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a340d2  3b9028c1a300           +cmp edx, dword ptr [eax + 0xa3c128]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10731816) /* 0xa3c128 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a340d8  750b                   -jne 0xa340e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a340e5;
    }
    // 00a340da  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a340dd  3b9024c1a300           +cmp edx, dword ptr [eax + 0xa3c124]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10731812) /* 0xa3c124 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a340e3  743c                   -je 0xa34121
    if (cpu.flags.zf)
    {
        goto L_0x00a34121;
    }
L_0x00a340e5:
    // 00a340e5  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a340e8  3d80010000             +cmp eax, 0x180
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a340ed  7ce0                   -jl 0xa340cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a340cf;
    }
    // 00a340ef  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a340f2  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00a340f4:
    // 00a340f4  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a340f7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a340f8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a340fa  68d0d0a300             -push 0xa3d0d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10735824 /*0xa3d0d0*/;
    cpu.esp -= 4;
    // 00a340ff  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34101  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34102  ff13                   -call dword ptr [ebx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34104  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34106  7433                   -je 0xa3413b
    if (cpu.flags.zf)
    {
        goto L_0x00a3413b;
    }
    // 00a34108  68f4baa300             -push 0xa3baf4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730228 /*0xa3baf4*/;
    cpu.esp -= 4;
    // 00a3410d  e8cee7ffff             -call 0xa328e0
    cpu.esp -= 4;
    sub_a328e0(app, cpu);
    if (cpu.terminate) return;
    // 00a34112  83c404                 +add esp, 4
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
    // 00a34115  e911ffffff             -jmp 0xa3402b
    goto L_0x00a3402b;
L_0x00a3411a:
    // 00a3411a  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a3411f  eba6                   -jmp 0xa340c7
    goto L_0x00a340c7;
L_0x00a34121:
    // 00a34121  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34122  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a34125  a19cc0a300             -mov eax, dword ptr [0xa3c09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731676) /* 0xa3c09c */);
    // 00a3412a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3412b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3412d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3412e  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34131  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34133  0f85f2feffff           -jne 0xa3402b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3402b;
    }
    // 00a34139  ebb9                   -jmp 0xa340f4
    goto L_0x00a340f4;
L_0x00a3413b:
    // 00a3413b  8b9c2484000000         -mov ebx, dword ptr [esp + 0x84]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00a34142  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34143  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34144  e8c3fdffff             -call 0xa33f0c
    cpu.esp -= 4;
    sub_a33f0c(app, cpu);
    if (cpu.terminate) return;
    // 00a34149  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00a34150  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34151  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00a34158  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34159  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3415a  e809fdffff             -call 0xa33e68
    cpu.esp -= 4;
    sub_a33e68(app, cpu);
    if (cpu.terminate) return;
    // 00a3415f  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00a34166  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34167  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34168  e8abfcffff             -call 0xa33e18
    cpu.esp -= 4;
    sub_a33e18(app, cpu);
    if (cpu.terminate) return;
    // 00a3416d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3416f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34171  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34172  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34174  ff5234                 -call dword ptr [edx + 0x34]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34177  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a34178  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3417a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3417c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3417e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34180  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34181  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34184  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34186  0f859ffeffff           -jne 0xa3402b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3402b;
    }
    // 00a3418c  8d5c2460               -lea ebx, [esp + 0x60]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a34190  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34192  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34193  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34195  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34196  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34199  f644246001             +test byte ptr [esp + 0x60], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(96) /* 0x60 */) & 1 /*0x1*/));
    // 00a3419e  0f8487feffff           -je 0xa3402b
    if (cpu.flags.zf)
    {
        goto L_0x00a3402b;
    }
    // 00a341a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a341a6  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00a341a9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341aa  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341ab  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341ac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341ad  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void sub_a341b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a341b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a341b1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a341b2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a341b6  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00a341bd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a341bf  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00a341c2  81c324c1a300           -add ebx, 0xa3c124
    (cpu.ebx) += x86::reg32(x86::sreg32(10731812 /*0xa3c124*/));
    // 00a341c8  803db0c0a30000         +cmp byte ptr [0xa3c0b0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10731696) /* 0xa3c0b0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a341cf  7526                   -jne 0xa341f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a341f7;
    }
L_0x00a341d1:
    // 00a341d1  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a341d8  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a341dc  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00a341e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a341e3  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a341ea  ff1508c1a300           -call dword ptr [0xa3c108]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10731784) /* 0xa3c108 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a341f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a341f2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341f3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a341f4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a341f7:
    // 00a341f7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a341f9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a341fa  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a341fc  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a341ff  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a34202  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a34204  7408                   -je 0xa3420e
    if (cpu.flags.zf)
    {
        goto L_0x00a3420e;
    }
    // 00a34206  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a34208  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a34209  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a3420b  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a3420e:
    // 00a3420e  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a34210  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a34212  74bd                   -je 0xa341d1
    if (cpu.flags.zf)
    {
        goto L_0x00a341d1;
    }
    // 00a34214  3b4b04                 +cmp ecx, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34217  74b8                   -je 0xa341d1
    if (cpu.flags.zf)
    {
        goto L_0x00a341d1;
    }
    // 00a34219  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3421a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a3421c  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3421f  ebb0                   -jmp 0xa341d1
    goto L_0x00a341d1;
}

/* align: skip  */
void sub_a34221(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34221  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34222  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34223  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a34225  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a34227  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a3422a  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a3422c  881a                   -mov byte ptr [edx], bl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a3422e  ff4010                 -inc dword ptr [eax + 0x10]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 00a34231  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34232  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34234(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34234  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34235  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34236  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a34238  b92142a300             -mov ecx, 0xa34221
    cpu.ecx = 10699297 /*0xa34221*/;
    // 00a3423d  e822000000             -call 0xa34264
    cpu.esp -= 4;
    sub_a34264(app, cpu);
    if (cpu.terminate) return;
    // 00a34242  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 00a34246  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34247  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34248  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34249(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34249  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3424a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a3424c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3424d  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00a3424f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a34252  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a34254  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a34257  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a34259  e8920c0000             -call 0xa34ef0
    cpu.esp -= 4;
    sub_a34ef0(app, cpu);
    if (cpu.terminate) return;
    // 00a3425e  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3425f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34260  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a34262(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34263(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34263  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34264(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34264  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34265  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a34266  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a34267  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34268  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a3426b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a3426d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a3426f  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a34274  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a34276  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a34279  885c246c               -mov byte ptr [esp + 0x6c], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 00a3427d  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a3427f  89542468               -mov dword ptr [esp + 0x68], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00a34283  66895c241e             -mov word ptr [esp + 0x1e], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00a34288  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a3428a  66894c241c             -mov word ptr [esp + 0x1c], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00a3428f  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a34293  e978000000             -jmp 0xa34310
    goto L_0x00a34310;
L_0x00a34298:
    // 00a34298  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a3429a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3429c  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a342a0  89442460               -mov dword ptr [esp + 0x60], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00a342a4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a342a6  e87a020000             -call 0xa34525
    cpu.esp -= 4;
    sub_a34525(app, cpu);
    if (cpu.terminate) return;
    // 00a342ab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a342ad  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a342b1  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a342b3  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 00a342b5  47                     -inc edi
    (cpu.edi)++;
    // 00a342b6  88442415               -mov byte ptr [esp + 0x15], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 00a342ba  897c2468               -mov dword ptr [esp + 0x68], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 00a342be  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a342c0  0f8453020000           -je 0xa34519
    if (cpu.flags.zf)
    {
        goto L_0x00a34519;
    }
    // 00a342c6  3c6e                   +cmp al, 0x6e
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
    // 00a342c8  0f85d8000000           -jne 0xa343a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a343a6;
    }
    // 00a342ce  8a74241e               -mov dh, byte ptr [esp + 0x1e]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a342d2  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 00a342d5  7461                   -je 0xa34338
    if (cpu.flags.zf)
    {
        goto L_0x00a34338;
    }
    // 00a342d7  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 00a342da  7413                   -je 0xa342ef
    if (cpu.flags.zf)
    {
        goto L_0x00a342ef;
    }
    // 00a342dc  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a342de  83c208                 +add edx, 8
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
    // 00a342e1  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a342e3  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
L_0x00a342e6:
    // 00a342e6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a342ea  268902                 -mov dword ptr es:[edx], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a342ed  eb21                   -jmp 0xa34310
    goto L_0x00a34310;
L_0x00a342ef:
    // 00a342ef  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 00a342f2  740c                   -je 0xa34300
    if (cpu.flags.zf)
    {
        goto L_0x00a34300;
    }
    // 00a342f4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a342f6  83c004                 +add eax, 4
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
    // 00a342f9  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a342fb  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a342fe  eb0a                   -jmp 0xa3430a
    goto L_0x00a3430a;
L_0x00a34300:
    // 00a34300  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34302  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34305  893e                   -mov dword ptr [esi], edi
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00a34307  8b57fc                 -mov edx, dword ptr [edi - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
L_0x00a3430a:
    // 00a3430a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a3430e  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a34310:
    // 00a34310  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a34314  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a34316  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a34318  0f84fb010000           -je 0xa34519
    if (cpu.flags.zf)
    {
        goto L_0x00a34519;
    }
    // 00a3431e  8d7801                 -lea edi, [eax + 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34321  80ff25                 +cmp bh, 0x25
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34324  0f846effffff           -je 0xa34298
    if (cpu.flags.zf)
    {
        goto L_0x00a34298;
    }
    // 00a3432a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a3432c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3432e  88fa                   -mov dl, bh
    cpu.dl = cpu.bh;
    // 00a34330  897c2468               -mov dword ptr [esp + 0x68], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 00a34334  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34336  ebd8                   -jmp 0xa34310
    goto L_0x00a34310;
L_0x00a34338:
    // 00a34338  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 00a3433b  743d                   -je 0xa3437a
    if (cpu.flags.zf)
    {
        goto L_0x00a3437a;
    }
    // 00a3433d  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 00a34340  7414                   -je 0xa34356
    if (cpu.flags.zf)
    {
        goto L_0x00a34356;
    }
    // 00a34342  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34344  83c108                 +add ecx, 8
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
    // 00a34347  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a34349  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 00a3434c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a34350  66268902               -mov word ptr es:[edx], ax
    *app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 00a34354  ebba                   -jmp 0xa34310
    goto L_0x00a34310;
L_0x00a34356:
    // 00a34356  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 00a34359  7413                   -je 0xa3436e
    if (cpu.flags.zf)
    {
        goto L_0x00a3436e;
    }
    // 00a3435b  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3435d  83c304                 +add ebx, 4
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
    // 00a34360  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a34362  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x00a34365:
    // 00a34365  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a34369  668902                 -mov word ptr [edx], ax
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a3436c  eba2                   -jmp 0xa34310
    goto L_0x00a34310;
L_0x00a3436e:
    // 00a3436e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34370  83c204                 +add edx, 4
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
    // 00a34373  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a34375  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a34378  ebeb                   -jmp 0xa34365
    goto L_0x00a34365;
L_0x00a3437a:
    // 00a3437a  f6c680                 +test dh, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 128 /*0x80*/));
    // 00a3437d  740f                   -je 0xa3438e
    if (cpu.flags.zf)
    {
        goto L_0x00a3438e;
    }
    // 00a3437f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34381  83c008                 +add eax, 8
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
    // 00a34384  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a34386  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 00a34389  e958ffffff             -jmp 0xa342e6
    goto L_0x00a342e6;
L_0x00a3438e:
    // 00a3438e  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 00a34391  0f8569ffffff           -jne 0xa34300
    if (!cpu.flags.zf)
    {
        goto L_0x00a34300;
    }
    // 00a34397  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34399  83c104                 +add ecx, 4
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
    // 00a3439c  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a3439e  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00a343a1  e964ffffff             -jmp 0xa3430a
    goto L_0x00a3430a;
L_0x00a343a6:
    // 00a343a6  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00a343aa  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a343ac  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a343ae  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a343b2  89442464               -mov dword ptr [esp + 0x64], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00a343b6  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a343ba  e878050000             -call 0xa34937
    cpu.esp -= 4;
    sub_a34937(app, cpu);
    if (cpu.terminate) return;
    // 00a343bf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a343c1  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a343c5  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a343c7  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a343c9  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a343cd  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a343d1  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a343d5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a343d7  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a343db  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a343dd  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a343e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a343e3  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a343e7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a343e9  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a343ed  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a343ef  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a343f1  8a64241e               -mov ah, byte ptr [esp + 0x1e]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a343f5  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a343f9  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 00a343fc  751d                   -jne 0xa3441b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3441b;
    }
    // 00a343fe  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34403  7516                   -jne 0xa3441b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3441b;
    }
L_0x00a34405:
    // 00a34405  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a3440a  7e0f                   -jle 0xa3441b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3441b;
    }
    // 00a3440c  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a34411  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a34413  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34415  ff4c2404               +dec dword ptr [esp + 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34419  ebea                   -jmp 0xa34405
    goto L_0x00a34405;
L_0x00a3441b:
    // 00a3441b  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
L_0x00a3441f:
    // 00a3441f  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34424  7e14                   -jle 0xa3443a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3443a;
    }
    // 00a34426  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a34428  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3442a  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 00a3442c  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3442e  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a34432  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34433  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34434  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a34438  ebe5                   -jmp 0xa3441f
    goto L_0x00a3441f;
L_0x00a3443a:
    // 00a3443a  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3443f  7e0f                   -jle 0xa34450
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a34450;
    }
    // 00a34441  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a34446  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a34448  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3444a  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a3444e  ebea                   -jmp 0xa3443a
    goto L_0x00a3443a;
L_0x00a34450:
    // 00a34450  8a742415               -mov dh, byte ptr [esp + 0x15]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 00a34454  80fe73                 +cmp dh, 0x73
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34457  7532                   -jne 0xa3448b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3448b;
    }
    // 00a34459  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a3445e  740f                   -je 0xa3446f
    if (cpu.flags.zf)
    {
        goto L_0x00a3446f;
    }
L_0x00a34460:
    // 00a34460  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a34462  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00a34464  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34466  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34468  e872040000             -call 0xa348df
    cpu.esp -= 4;
    sub_a348df(app, cpu);
    if (cpu.terminate) return;
    // 00a3446d  eb3d                   -jmp 0xa344ac
    goto L_0x00a344ac;
L_0x00a3446f:
    // 00a3446f  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34474  7e36                   -jle 0xa344ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a344ac;
    }
    // 00a34476  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a34478  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3447a  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 00a3447d  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3447f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a34483  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34484  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34485  894c2428               -mov dword ptr [esp + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00a34489  ebe4                   -jmp 0xa3446f
    goto L_0x00a3446f;
L_0x00a3448b:
    // 00a3448b  80fe53                 +cmp dh, 0x53
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3448e  74d0                   -je 0xa34460
    if (cpu.flags.zf)
    {
        goto L_0x00a34460;
    }
L_0x00a34490:
    // 00a34490  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34495  7e15                   -jle 0xa344ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a344ac;
    }
    // 00a34497  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a34499  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3449b  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 00a3449e  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a344a0  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a344a4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a344a5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a344a6  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a344aa  ebe4                   -jmp 0xa34490
    goto L_0x00a34490;
L_0x00a344ac:
    // 00a344ac  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a344b1  7e0f                   -jle 0xa344c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a344c2;
    }
    // 00a344b3  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a344b8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a344ba  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a344bc  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a344c0  ebea                   -jmp 0xa344ac
    goto L_0x00a344ac;
L_0x00a344c2:
    // 00a344c2  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00a344c7  7e15                   -jle 0xa344de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a344de;
    }
    // 00a344c9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a344cb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a344cd  268a17                 -mov dl, byte ptr es:[edi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.edi);
    // 00a344d0  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a344d2  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a344d6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a344d7  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a344d8  894c2430               -mov dword ptr [esp + 0x30], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 00a344dc  ebe4                   -jmp 0xa344c2
    goto L_0x00a344c2;
L_0x00a344de:
    // 00a344de  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a344e3  7e0f                   -jle 0xa344f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a344f4;
    }
    // 00a344e5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a344ea  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a344ec  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a344ee  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a344f2  ebea                   -jmp 0xa344de
    goto L_0x00a344de;
L_0x00a344f4:
    // 00a344f4  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a344f9  0f8411feffff           -je 0xa34310
    if (cpu.flags.zf)
    {
        goto L_0x00a34310;
    }
L_0x00a344ff:
    // 00a344ff  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a34504  0f8e06feffff           -jle 0xa34310
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a34310;
    }
    // 00a3450a  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a3450f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a34511  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a34513  ff4c2404               +dec dword ptr [esp + 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34517  ebe6                   -jmp 0xa344ff
    goto L_0x00a344ff;
L_0x00a34519:
    // 00a34519  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a3451d  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a34520  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34521  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a34522  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34523  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34524  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34525(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34525  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34526  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34527  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a34528  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a3452a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a3452c  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 00a34530  e83d010000             -call 0xa34672
    cpu.esp -= 4;
    sub_a34672(app, cpu);
    if (cpu.terminate) return;
    // 00a34535  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a3453c  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3453f  7524                   -jne 0xa34565
    if (!cpu.flags.zf)
    {
        goto L_0x00a34565;
    }
    // 00a34541  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a34543  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34546  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a34548  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a3454b  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a3454e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a34550  7d10                   -jge 0xa34562
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a34562;
    }
    // 00a34552  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a34554  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a34557  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a34559  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a3455c  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a3455f  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x00a34562:
    // 00a34562  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34563  eb1f                   -jmp 0xa34584
    goto L_0x00a34584;
L_0x00a34565:
    // 00a34565  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a34567  80fa30                 +cmp dl, 0x30
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
    // 00a3456a  7218                   -jb 0xa34584
    if (cpu.flags.cf)
    {
        goto L_0x00a34584;
    }
    // 00a3456c  80fa39                 +cmp dl, 0x39
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
    // 00a3456f  7713                   -ja 0xa34584
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a34584;
    }
    // 00a34571  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a34575  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34577  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a34579  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a3457c  01d1                   +add ecx, edx
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
    // 00a3457e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a3457f  894b04                 -mov dword ptr [ebx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a34582  ebe1                   -jmp 0xa34565
    goto L_0x00a34565;
L_0x00a34584:
    // 00a34584  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00a3458b  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3458e  7551                   -jne 0xa345e1
    if (!cpu.flags.zf)
    {
        goto L_0x00a345e1;
    }
    // 00a34590  40                     -inc eax
    (cpu.eax)++;
    // 00a34591  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a34598  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3459b  751b                   -jne 0xa345b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a345b8;
    }
    // 00a3459d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3459f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a345a2  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a345a4  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a345a7  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a345aa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a345ac  7d07                   -jge 0xa345b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a345b5;
    }
    // 00a345ae  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x00a345b5:
    // 00a345b5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a345b6  eb1f                   -jmp 0xa345d7
    goto L_0x00a345d7;
L_0x00a345b8:
    // 00a345b8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a345ba  80fa30                 +cmp dl, 0x30
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
    // 00a345bd  7218                   -jb 0xa345d7
    if (cpu.flags.cf)
    {
        goto L_0x00a345d7;
    }
    // 00a345bf  80fa39                 +cmp dl, 0x39
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
    // 00a345c2  7713                   -ja 0xa345d7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a345d7;
    }
    // 00a345c4  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a345c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a345ca  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a345cc  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a345cf  01d1                   +add ecx, edx
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
    // 00a345d1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a345d2  894b08                 -mov dword ptr [ebx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a345d5  ebe1                   -jmp 0xa345b8
    goto L_0x00a345b8;
L_0x00a345d7:
    // 00a345d7  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a345db  7404                   -je 0xa345e1
    if (cpu.flags.zf)
    {
        goto L_0x00a345e1;
    }
    // 00a345dd  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x00a345e1:
    // 00a345e1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a345e3  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a345e6  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a345e9  721f                   -jb 0xa3460a
    if (cpu.flags.cf)
    {
        goto L_0x00a3460a;
    }
    // 00a345eb  0f8677000000           -jbe 0xa34668
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34668;
    }
    // 00a345f1  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a345f4  720b                   -jb 0xa34601
    if (cpu.flags.cf)
    {
        goto L_0x00a34601;
    }
    // 00a345f6  762b                   -jbe 0xa34623
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34623;
    }
    // 00a345f8  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a345fb  7426                   -je 0xa34623
    if (cpu.flags.zf)
    {
        goto L_0x00a34623;
    }
    // 00a345fd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a345fe  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a345ff  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34600  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a34601:
    // 00a34601  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34604  742b                   -je 0xa34631
    if (cpu.flags.zf)
    {
        goto L_0x00a34631;
    }
    // 00a34606  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34607  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34608  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34609  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3460a:
    // 00a3460a  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3460d  720b                   -jb 0xa3461a
    if (cpu.flags.cf)
    {
        goto L_0x00a3461a;
    }
    // 00a3460f  7626                   -jbe 0xa34637
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34637;
    }
    // 00a34611  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34614  743d                   -je 0xa34653
    if (cpu.flags.zf)
    {
        goto L_0x00a34653;
    }
    // 00a34616  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34617  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34618  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34619  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3461a:
    // 00a3461a  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3461d  7443                   -je 0xa34662
    if (cpu.flags.zf)
    {
        goto L_0x00a34662;
    }
    // 00a3461f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34620  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34621  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34622  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a34623:
    // 00a34623  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a34626  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a34629  40                     -inc eax
    (cpu.eax)++;
    // 00a3462a  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a3462d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3462e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3462f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34630  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a34631:
    // 00a34631  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a34635  eb35                   -jmp 0xa3466c
    goto L_0x00a3466c;
L_0x00a34637:
    // 00a34637  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3463b  7531                   -jne 0xa3466e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3466e;
    }
    // 00a3463d  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34641  752b                   -jne 0xa3466e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3466e;
    }
    // 00a34643  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a34646  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a34649  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a3464c  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 00a3464f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34650  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34651  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34652  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a34653:
    // 00a34653  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a34656  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a34659  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a3465b  88531f                 -mov byte ptr [ebx + 0x1f], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 00a3465e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3465f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34660  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34661  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a34662:
    // 00a34662  804b1e80               +or byte ptr [ebx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 00a34666  eb04                   -jmp 0xa3466c
    goto L_0x00a3466c;
L_0x00a34668:
    // 00a34668  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a3466c:
    // 00a3466c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a3466e:
    // 00a3466e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3466f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34670  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34671  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34672(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34672  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34673  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34674  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
L_0x00a3467a:
    // 00a3467a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3467c  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3467f  7506                   -jne 0xa34687
    if (!cpu.flags.zf)
    {
        goto L_0x00a34687;
    }
    // 00a34681  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a34685  eb42                   -jmp 0xa346c9
    goto L_0x00a346c9;
L_0x00a34687:
    // 00a34687  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3468a  7506                   -jne 0xa34692
    if (!cpu.flags.zf)
    {
        goto L_0x00a34692;
    }
    // 00a3468c  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a34690  eb37                   -jmp 0xa346c9
    goto L_0x00a346c9;
L_0x00a34692:
    // 00a34692  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34695  7513                   -jne 0xa346aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a346aa;
    }
    // 00a34697  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a3469a  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a3469d  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 00a3469f  886a1e                 -mov byte ptr [edx + 0x1e], ch
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 00a346a2  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00a346a5  885a1e                 -mov byte ptr [edx + 0x1e], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00a346a8  eb1f                   -jmp 0xa346c9
    goto L_0x00a346c9;
L_0x00a346aa:
    // 00a346aa  80fb20                 +cmp bl, 0x20
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
    // 00a346ad  7512                   -jne 0xa346c1
    if (!cpu.flags.zf)
    {
        goto L_0x00a346c1;
    }
    // 00a346af  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a346b2  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00a346b5  7512                   -jne 0xa346c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a346c9;
    }
    // 00a346b7  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00a346b9  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a346bc  884a1e                 -mov byte ptr [edx + 0x1e], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a346bf  eb08                   -jmp 0xa346c9
    goto L_0x00a346c9;
L_0x00a346c1:
    // 00a346c1  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a346c4  7506                   -jne 0xa346cc
    if (!cpu.flags.zf)
    {
        goto L_0x00a346cc;
    }
    // 00a346c6  885a16                 -mov byte ptr [edx + 0x16], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x00a346c9:
    // 00a346c9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a346ca  ebae                   -jmp 0xa3467a
    goto L_0x00a3467a;
L_0x00a346cc:
    // 00a346cc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a346cd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a346ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a346cf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a346cf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a346d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a346d1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a346d2  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a346d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a346d5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a346d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a346d9  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00a346db  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a346dd:
    // 00a346dd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a346df  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 00a346e2  42                     -inc edx
    (cpu.edx)++;
    // 00a346e3  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a346e5  7407                   -je 0xa346ee
    if (cpu.flags.zf)
    {
        goto L_0x00a346ee;
    }
    // 00a346e7  39f8                   +cmp eax, edi
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
    // 00a346e9  7403                   -je 0xa346ee
    if (cpu.flags.zf)
    {
        goto L_0x00a346ee;
    }
    // 00a346eb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a346ec  ebef                   -jmp 0xa346dd
    goto L_0x00a346dd;
L_0x00a346ee:
    // 00a346ee  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a346ef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a346f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a346f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a346f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a346f3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a346f3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a346f4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a346f5  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a346f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a346f9  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a346fb  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a346fd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a346ff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a34701  83feff                 +cmp esi, -1
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
    // 00a34704  7525                   -jne 0xa3472b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3472b;
    }
L_0x00a34706:
    // 00a34706  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a3470a  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a3470d  7418                   -je 0xa34727
    if (cpu.flags.zf)
    {
        goto L_0x00a34727;
    }
    // 00a3470f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34711  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a34713  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 00a34716  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a34719  e819090000             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a3471e  83f8ff                 +cmp eax, -1
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
    // 00a34721  74e3                   -je 0xa34706
    if (cpu.flags.zf)
    {
        goto L_0x00a34706;
    }
    // 00a34723  01c1                   +add ecx, eax
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
    // 00a34725  ebdf                   -jmp 0xa34706
    goto L_0x00a34706;
L_0x00a34727:
    // 00a34727  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a34729  eb2a                   -jmp 0xa34755
    goto L_0x00a34755;
L_0x00a3472b:
    // 00a3472b  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a34730  741d                   -je 0xa3474f
    if (cpu.flags.zf)
    {
        goto L_0x00a3474f;
    }
    // 00a34732  39f1                   +cmp ecx, esi
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
    // 00a34734  7f19                   -jg 0xa3474f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a3474f;
    }
    // 00a34736  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34738  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3473a  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a3473e  e8f4080000             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a34743  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a34746  83f8ff                 +cmp eax, -1
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
    // 00a34749  74e0                   -je 0xa3472b
    if (cpu.flags.zf)
    {
        goto L_0x00a3472b;
    }
    // 00a3474b  01c1                   +add ecx, eax
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
    // 00a3474d  ebdc                   -jmp 0xa3472b
    goto L_0x00a3472b;
L_0x00a3474f:
    // 00a3474f  39f1                   +cmp ecx, esi
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
    // 00a34751  7ed4                   -jle 0xa34727
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a34727;
    }
    // 00a34753  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a34755:
    // 00a34755  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34758  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a34759  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3475a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3475b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3475c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3475c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3475d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3475e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3475f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a34760  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34763  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a34765  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a34768  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a3476d  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a3476f  e841090000             -call 0xa350b5
    cpu.esp -= 4;
    sub_a350b5(app, cpu);
    if (cpu.terminate) return;
    // 00a34774  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a34775  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a34777  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a34779  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3477b  49                     -dec ecx
    (cpu.ecx)--;
    // 00a3477c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a3477e  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00a34780  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a34782  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34783  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a34784  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a34787  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a34789  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a3478a  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00a3478d  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a34790  eb07                   -jmp 0xa34799
    goto L_0x00a34799;
L_0x00a34792:
    // 00a34792  4a                     -dec edx
    (cpu.edx)--;
    // 00a34793  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a34795  48                     -dec eax
    (cpu.eax)--;
    // 00a34796  880b                   -mov byte ptr [ebx], cl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 00a34798  4b                     -dec ebx
    (cpu.ebx)--;
L_0x00a34799:
    // 00a34799  39f2                   +cmp edx, esi
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
    // 00a3479b  75f5                   -jne 0xa34792
    if (!cpu.flags.zf)
    {
        goto L_0x00a34792;
    }
    // 00a3479d  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a347a0:
    // 00a347a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a347a2  7c07                   -jl 0xa347ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a347ab;
    }
    // 00a347a4  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a347a5  c60230                 -mov byte ptr [edx], 0x30
    *app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a347a8  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a347a9  ebf5                   -jmp 0xa347a0
    goto L_0x00a347a0;
L_0x00a347ab:
    // 00a347ab  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 00a347ae  c6450000               -mov byte ptr [ebp], 0
    *app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00a347b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a347b5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a347b6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a347b7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a347b8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a347b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a347ba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a347ba  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a347bb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a347bc  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a347bd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a347c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a347c2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a347c4  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a347c7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a347c9  7d0b                   -jge 0xa347d6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a347d6;
    }
    // 00a347cb  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a347cd  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a347d0  c6002d                 -mov byte ptr [eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 00a347d3  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00a347d6:
    // 00a347d6  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a347da  7507                   -jne 0xa347e3
    if (!cpu.flags.zf)
    {
        goto L_0x00a347e3;
    }
    // 00a347dc  c7460804000000         -mov dword ptr [esi + 8], 4
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x00a347e3:
    // 00a347e3  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a347e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a347ea  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a347ec  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a347f1  e8bf080000             -call 0xa350b5
    cpu.esp -= 4;
    sub_a350b5(app, cpu);
    if (cpu.terminate) return;
    // 00a347f6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a347f8:
    // 00a347f8  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a347fa  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a347fd  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a347ff  7404                   -je 0xa34805
    if (cpu.flags.zf)
    {
        goto L_0x00a34805;
    }
    // 00a34801  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a34803  ebf3                   -jmp 0xa347f8
    goto L_0x00a347f8;
L_0x00a34805:
    // 00a34805  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34809  742c                   -je 0xa34837
    if (cpu.flags.zf)
    {
        goto L_0x00a34837;
    }
    // 00a3480b  c6012e                 -mov byte ptr [ecx], 0x2e
    *app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 00a3480e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a34810  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a34812  eb1b                   -jmp 0xa3482f
    goto L_0x00a3482f;
L_0x00a34814:
    // 00a34814  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34816  6689542402             -mov word ptr [esp + 2], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00a3481b  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3481e  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a34821  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a34824  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a34828  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a3482b  40                     -inc eax
    (cpu.eax)++;
    // 00a3482c  8811                   -mov byte ptr [ecx], dl
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00a3482e  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a3482f:
    // 00a3482f  3b4608                 +cmp eax, dword ptr [esi + 8]
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
    // 00a34832  7ce0                   -jl 0xa34814
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a34814;
    }
    // 00a34834  c60100                 -mov byte ptr [ecx], 0
    *app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00a34837:
    // 00a34837  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 00a3483c  7450                   -je 0xa3488e
    if (cpu.flags.zf)
    {
        goto L_0x00a3488e;
    }
L_0x00a3483e:
    // 00a3483e  39d9                   +cmp ecx, ebx
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
    // 00a34840  7532                   -jne 0xa34874
    if (!cpu.flags.zf)
    {
        goto L_0x00a34874;
    }
    // 00a34842  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a34845  c60331                 -mov byte ptr [ebx], 0x31
    *app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
L_0x00a34848:
    // 00a34848  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a3484a  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a3484d  80fa30                 +cmp dl, 0x30
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
    // 00a34850  7504                   -jne 0xa34856
    if (!cpu.flags.zf)
    {
        goto L_0x00a34856;
    }
    // 00a34852  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a34854  ebf2                   -jmp 0xa34848
    goto L_0x00a34848;
L_0x00a34856:
    // 00a34856  80fa2e                 +cmp dl, 0x2e
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
    // 00a34859  7510                   -jne 0xa3486b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3486b;
    }
    // 00a3485b  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a3485e  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34861  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a34863:
    // 00a34863  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34866  7503                   -jne 0xa3486b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3486b;
    }
    // 00a34868  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34869  ebf8                   -jmp 0xa34863
    goto L_0x00a34863;
L_0x00a3486b:
    // 00a3486b  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a3486e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a3486f  c60100                 -mov byte ptr [ecx], 0
    *app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00a34872  eb1a                   -jmp 0xa3488e
    goto L_0x00a3488e;
L_0x00a34874:
    // 00a34874  49                     -dec ecx
    (cpu.ecx)--;
    // 00a34875  80392e                 +cmp byte ptr [ecx], 0x2e
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34878  7501                   -jne 0xa3487b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3487b;
    }
    // 00a3487a  49                     -dec ecx
    (cpu.ecx)--;
L_0x00a3487b:
    // 00a3487b  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a3487d  3c39                   +cmp al, 0x39
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
    // 00a3487f  7408                   -je 0xa34889
    if (cpu.flags.zf)
    {
        goto L_0x00a34889;
    }
    // 00a34881  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00a34883  fec4                   +inc ah
    {
        x86::reg8& tmp = cpu.ah;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00a34885  8821                   -mov byte ptr [ecx], ah
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 00a34887  eb05                   -jmp 0xa3488e
    goto L_0x00a3488e;
L_0x00a34889:
    // 00a34889  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a3488c  ebb0                   -jmp 0xa3483e
    goto L_0x00a3483e;
L_0x00a3488e:
    // 00a3488e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34891  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34892  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34893  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34895(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34895  ff1560cba300           -call dword ptr [0xa3cb60]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734432) /* 0xa3cb60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3489b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3489c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3489c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3489d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3489e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3489f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a348a0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a348a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a348a2  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a348a6  7530                   -jne 0xa348d8
    if (!cpu.flags.zf)
    {
        goto L_0x00a348d8;
    }
    // 00a348a8  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a348ac  752a                   -jne 0xa348d8
    if (!cpu.flags.zf)
    {
        goto L_0x00a348d8;
    }
    // 00a348ae  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a348b1  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a348b4  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a348b7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a348b9  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00a348bc  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a348be  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00a348c1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a348c3  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00a348c6  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a348c8  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00a348cb  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a348cd  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a348cf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a348d1  7e05                   -jle 0xa348d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a348d8;
    }
    // 00a348d3  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a348d5  894824                 -mov dword ptr [eax + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x00a348d8:
    // 00a348d8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348d9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348da  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348dc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348dd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a348de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a348df(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a348df  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a348e0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a348e1  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a348e2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a348e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a348e6  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a348e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a348ea  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
L_0x00a348ec:
    // 00a348ec  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a348f0  7e3d                   -jle 0xa3492f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3492f;
    }
    // 00a348f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a348f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a348f6  66268b16               -mov dx, word ptr es:[esi]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ees + cpu.esi);
    // 00a348fa  e838070000             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a348ff  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a34902  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a34904  83f8ff                 +cmp eax, -1
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
    // 00a34907  74e3                   -je 0xa348ec
    if (cpu.flags.zf)
    {
        goto L_0x00a348ec;
    }
    // 00a34909  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3490c  7f1a                   -jg 0xa34928
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a34928;
    }
    // 00a3490e  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
L_0x00a34910:
    // 00a34910  4f                     -dec edi
    (cpu.edi)--;
    // 00a34911  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34914  74d6                   -je 0xa348ec
    if (cpu.flags.zf)
    {
        goto L_0x00a348ec;
    }
    // 00a34916  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a34918  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a3491a  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a3491c  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3491e  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a34921  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34922  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34923  894328                 -mov dword ptr [ebx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a34926  ebe8                   -jmp 0xa34910
    goto L_0x00a34910;
L_0x00a34928:
    // 00a34928  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00a3492f:
    // 00a3492f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34932  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34933  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a34934  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34935  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34936  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34937(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34937  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a34938  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a34939  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3493a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3493b  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a3493e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a34940  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a34942  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a34944  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a34946  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a3494d  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a34954  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a3495b  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00a34962  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00a34969  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a3496b  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a3496e  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00a34975  3c69                   +cmp al, 0x69
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
    // 00a34977  7219                   -jb 0xa34992
    if (cpu.flags.cf)
    {
        goto L_0x00a34992;
    }
    // 00a34979  0f8686000000           -jbe 0xa34a05
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34a05;
    }
    // 00a3497f  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34981  720b                   -jb 0xa3498e
    if (cpu.flags.cf)
    {
        goto L_0x00a3498e;
    }
    // 00a34983  7620                   -jbe 0xa349a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a349a5;
    }
    // 00a34985  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a34987:
    // 00a34987  741c                   -je 0xa349a5
    if (cpu.flags.zf)
    {
        goto L_0x00a349a5;
    }
    // 00a34989  e956010000             -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a3498e:
    // 00a3498e  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34990  ebf5                   -jmp 0xa34987
    goto L_0x00a34987;
L_0x00a34992:
    // 00a34992  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34994  0f824a010000           -jb 0xa34ae4
    if (cpu.flags.cf)
    {
        goto L_0x00a34ae4;
    }
    // 00a3499a  7609                   -jbe 0xa349a5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a349a5;
    }
    // 00a3499c  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3499e  7465                   -je 0xa34a05
    if (cpu.flags.zf)
    {
        goto L_0x00a34a05;
    }
    // 00a349a0  e93f010000             -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a349a5:
    // 00a349a5  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a349a9  7420                   -je 0xa349cb
    if (cpu.flags.zf)
    {
        goto L_0x00a349cb;
    }
    // 00a349ab  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a349ad  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a349b0  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a349b2  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a349b5  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a349b8  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a349ba  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a349bd  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a349bf  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00a349c2:
    // 00a349c2  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a349c6  e919010000             -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a349cb:
    // 00a349cb  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a349cf  7413                   -je 0xa349e4
    if (cpu.flags.zf)
    {
        goto L_0x00a349e4;
    }
    // 00a349d1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a349d3  83c004                 +add eax, 4
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
    // 00a349d6  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a349d8  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
L_0x00a349db:
    // 00a349db  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a349df  e900010000             -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a349e4:
    // 00a349e4  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a349e6  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a349e9  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a349eb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a349ee  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a349f2  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a349f6  0f84e8000000           -je 0xa34ae4
    if (cpu.flags.zf)
    {
        goto L_0x00a34ae4;
    }
    // 00a349fc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a349fe  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a34a03  ebd6                   -jmp 0xa349db
    goto L_0x00a349db;
L_0x00a34a05:
    // 00a34a05  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a34a09  741d                   -je 0xa34a28
    if (cpu.flags.zf)
    {
        goto L_0x00a34a28;
    }
    // 00a34a0b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34a0d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34a10  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a34a12  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a34a15  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a34a18  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34a1a  83c304                 +add ebx, 4
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
    // 00a34a1d  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a34a1f  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a34a22  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a34a26  eb33                   -jmp 0xa34a5b
    goto L_0x00a34a5b;
L_0x00a34a28:
    // 00a34a28  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a34a2c  740c                   -je 0xa34a3a
    if (cpu.flags.zf)
    {
        goto L_0x00a34a3a;
    }
    // 00a34a2e  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34a30  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a34a33  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a34a35  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a34a38  eb1d                   -jmp 0xa34a57
    goto L_0x00a34a57;
L_0x00a34a3a:
    // 00a34a3a  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34a3c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34a3f  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a34a41  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a34a44  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34a47  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a34a4b  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00a34a4e  740b                   -je 0xa34a5b
    if (cpu.flags.zf)
    {
        goto L_0x00a34a5b;
    }
    // 00a34a50  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a34a54  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00a34a57:
    // 00a34a57  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00a34a5b:
    // 00a34a5b  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a34a5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a34a60  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a34a63  7409                   -je 0xa34a6e
    if (cpu.flags.zf)
    {
        goto L_0x00a34a6e;
    }
    // 00a34a65  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a34a6a  7409                   -je 0xa34a75
    if (cpu.flags.zf)
    {
        goto L_0x00a34a75;
    }
    // 00a34a6c  eb0b                   -jmp 0xa34a79
    goto L_0x00a34a79;
L_0x00a34a6e:
    // 00a34a6e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a34a73  7c04                   -jl 0xa34a79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a34a79;
    }
L_0x00a34a75:
    // 00a34a75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34a77  7444                   -je 0xa34abd
    if (cpu.flags.zf)
    {
        goto L_0x00a34abd;
    }
L_0x00a34a79:
    // 00a34a79  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34a7c  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34a7f  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a34a82  c604062d               -mov byte ptr [esi + eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a34a86  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a34a8a  742b                   -je 0xa34ab7
    if (cpu.flags.zf)
    {
        goto L_0x00a34ab7;
    }
    // 00a34a8c  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a34a8f  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a34a93  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00a34a95  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 00a34a97  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a34a9a  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a34a9d  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a34aa1  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a34aa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34aa6  7508                   -jne 0xa34ab0
    if (!cpu.flags.zf)
    {
        goto L_0x00a34ab0;
    }
    // 00a34aa8  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a34aab  e912ffffff             -jmp 0xa349c2
    goto L_0x00a349c2;
L_0x00a34ab0:
    // 00a34ab0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a34ab2  e90bffffff             -jmp 0xa349c2
    goto L_0x00a349c2;
L_0x00a34ab7:
    // 00a34ab7  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a34abb  eb27                   -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a34abd:
    // 00a34abd  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34ac0  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a34ac2  740f                   -je 0xa34ad3
    if (cpu.flags.zf)
    {
        goto L_0x00a34ad3;
    }
    // 00a34ac4  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34ac7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34aca  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a34acd  c604062b               -mov byte ptr [esi + eax], 0x2b
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a34ad1  eb11                   -jmp 0xa34ae4
    goto L_0x00a34ae4;
L_0x00a34ad3:
    // 00a34ad3  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a34ad5  740d                   -je 0xa34ae4
    if (cpu.flags.zf)
    {
        goto L_0x00a34ae4;
    }
    // 00a34ad7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34ada  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34add  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a34ae0  c6040620               -mov byte ptr [esi + eax], 0x20
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a34ae4:
    // 00a34ae4  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a34ae7  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a34aec  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34aee  7261                   -jb 0xa34b51
    if (cpu.flags.cf)
    {
        goto L_0x00a34b51;
    }
    // 00a34af0  0f86f0010000           -jbe 0xa34ce6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34ce6;
    }
    // 00a34af6  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34af8  7238                   -jb 0xa34b32
    if (cpu.flags.cf)
    {
        goto L_0x00a34b32;
    }
    // 00a34afa  0f86c6010000           -jbe 0xa34cc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34cc6;
    }
    // 00a34b00  3c73                   +cmp al, 0x73
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
    // 00a34b02  7221                   -jb 0xa34b25
    if (cpu.flags.cf)
    {
        goto L_0x00a34b25;
    }
    // 00a34b04  0f86e0000000           -jbe 0xa34bea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34bea;
    }
    // 00a34b0a  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b0c  0f82a2030000           -jb 0xa34eb4
    if (cpu.flags.cf)
    {
        goto L_0x00a34eb4;
    }
    // 00a34b12  0f86ce010000           -jbe 0xa34ce6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34ce6;
    }
    // 00a34b18  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b1a  0f8463010000           -je 0xa34c83
    if (cpu.flags.zf)
    {
        goto L_0x00a34c83;
    }
    // 00a34b20  e98f030000             -jmp 0xa34eb4
    goto L_0x00a34eb4;
L_0x00a34b25:
    // 00a34b25  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a34b27:
    // 00a34b27  0f845f020000           -je 0xa34d8c
    if (cpu.flags.zf)
    {
        goto L_0x00a34d8c;
    }
    // 00a34b2d  e982030000             -jmp 0xa34eb4
    goto L_0x00a34eb4;
L_0x00a34b32:
    // 00a34b32  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b34  0f8294000000           -jb 0xa34bce
    if (cpu.flags.cf)
    {
        goto L_0x00a34bce;
    }
    // 00a34b3a  765d                   -jbe 0xa34b99
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34b99;
    }
    // 00a34b3c  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b3e  0f868a000000           -jbe 0xa34bce
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34bce;
    }
    // 00a34b44  3c69                   +cmp al, 0x69
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
    // 00a34b46  0f849a010000           -je 0xa34ce6
    if (cpu.flags.zf)
    {
        goto L_0x00a34ce6;
    }
    // 00a34b4c  e963030000             -jmp 0xa34eb4
    goto L_0x00a34eb4;
L_0x00a34b51:
    // 00a34b51  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b53  722f                   -jb 0xa34b84
    if (cpu.flags.cf)
    {
        goto L_0x00a34b84;
    }
    // 00a34b55  0f8673000000           -jbe 0xa34bce
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34bce;
    }
    // 00a34b5b  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b5d  7221                   -jb 0xa34b80
    if (cpu.flags.cf)
    {
        goto L_0x00a34b80;
    }
    // 00a34b5f  0f8685000000           -jbe 0xa34bea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34bea;
    }
    // 00a34b65  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b67  0f8247030000           -jb 0xa34eb4
    if (cpu.flags.cf)
    {
        goto L_0x00a34eb4;
    }
    // 00a34b6d  0f8610010000           -jbe 0xa34c83
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34c83;
    }
    // 00a34b73  3c63                   +cmp al, 0x63
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
    // 00a34b75  0f849d020000           -je 0xa34e18
    if (cpu.flags.zf)
    {
        goto L_0x00a34e18;
    }
    // 00a34b7b  e934030000             -jmp 0xa34eb4
    goto L_0x00a34eb4;
L_0x00a34b80:
    // 00a34b80  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b82  eba3                   -jmp 0xa34b27
    goto L_0x00a34b27;
L_0x00a34b84:
    // 00a34b84  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b86  7204                   -jb 0xa34b8c
    if (cpu.flags.cf)
    {
        goto L_0x00a34b8c;
    }
    // 00a34b88  7644                   -jbe 0xa34bce
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a34bce;
    }
    // 00a34b8a  eb0d                   -jmp 0xa34b99
    goto L_0x00a34b99;
L_0x00a34b8c:
    // 00a34b8c  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34b8e  0f84f4020000           -je 0xa34e88
    if (cpu.flags.zf)
    {
        goto L_0x00a34e88;
    }
    // 00a34b94  e91b030000             -jmp 0xa34eb4
    goto L_0x00a34eb4;
L_0x00a34b99:
    // 00a34b99  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a34b9d  742f                   -je 0xa34bce
    if (cpu.flags.zf)
    {
        goto L_0x00a34bce;
    }
    // 00a34b9f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34ba1  83c304                 +add ebx, 4
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
    // 00a34ba4  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a34ba6  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a34ba9  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a34bad  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a34baf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a34bb1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34bb3  e802fcffff             -call 0xa347ba
    cpu.esp -= 4;
    sub_a347ba(app, cpu);
    if (cpu.terminate) return;
    // 00a34bb8  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a34bbd  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a34bbf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34bc1  e809fbffff             -call 0xa346cf
    cpu.esp -= 4;
    sub_a346cf(app, cpu);
    if (cpu.terminate) return;
    // 00a34bc6  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a34bc9  e9f9020000             -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34bce:
    // 00a34bce  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a34bd0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34bd2  e8befcffff             -call 0xa34895
    cpu.esp -= 4;
    sub_a34895(app, cpu);
    if (cpu.terminate) return;
    // 00a34bd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a34bd9  e8befcffff             -call 0xa3489c
    cpu.esp -= 4;
    sub_a3489c(app, cpu);
    if (cpu.terminate) return;
    // 00a34bde  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a34be0  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a34be3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a34be5  e9dd020000             -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34bea:
    // 00a34bea  c60600                 -mov byte ptr [esi], 0
    *app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00a34bed  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34bf0  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a34bf2  741d                   -je 0xa34c11
    if (cpu.flags.zf)
    {
        goto L_0x00a34c11;
    }
    // 00a34bf4  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34bf6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a34bf9  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a34bfb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a34bfe  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a34c02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34c04  7505                   -jne 0xa34c0b
    if (!cpu.flags.zf)
    {
        goto L_0x00a34c0b;
    }
    // 00a34c06  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a34c09  742e                   -je 0xa34c39
    if (cpu.flags.zf)
    {
        goto L_0x00a34c39;
    }
L_0x00a34c0b:
    // 00a34c0b  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a34c0d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a34c0f  eb28                   -jmp 0xa34c39
    goto L_0x00a34c39;
L_0x00a34c11:
    // 00a34c11  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a34c13  7410                   -je 0xa34c25
    if (cpu.flags.zf)
    {
        goto L_0x00a34c25;
    }
    // 00a34c15  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34c17  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34c1a  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a34c1c  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00a34c1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34c21  7416                   -je 0xa34c39
    if (cpu.flags.zf)
    {
        goto L_0x00a34c39;
    }
    // 00a34c23  eb0e                   -jmp 0xa34c33
    goto L_0x00a34c33;
L_0x00a34c25:
    // 00a34c25  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34c27  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34c2a  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a34c2c  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a34c2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a34c31  7406                   -je 0xa34c39
    if (cpu.flags.zf)
    {
        goto L_0x00a34c39;
    }
L_0x00a34c33:
    // 00a34c33  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a34c35  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a34c37  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x00a34c39:
    // 00a34c39  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34c3d  7514                   -jne 0xa34c53
    if (!cpu.flags.zf)
    {
        goto L_0x00a34c53;
    }
    // 00a34c3f  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a34c43  7514                   -jne 0xa34c59
    if (!cpu.flags.zf)
    {
        goto L_0x00a34c59;
    }
L_0x00a34c45:
    // 00a34c45  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34c47  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34c49  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a34c4c  e8a2faffff             -call 0xa346f3
    cpu.esp -= 4;
    sub_a346f3(app, cpu);
    if (cpu.terminate) return;
    // 00a34c51  eb12                   -jmp 0xa34c65
    goto L_0x00a34c65;
L_0x00a34c53:
    // 00a34c53  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a34c57  75ec                   -jne 0xa34c45
    if (!cpu.flags.zf)
    {
        goto L_0x00a34c45;
    }
L_0x00a34c59:
    // 00a34c59  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34c5b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34c5d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a34c60  e86afaffff             -call 0xa346cf
    cpu.esp -= 4;
    sub_a346cf(app, cpu);
    if (cpu.terminate) return;
L_0x00a34c65:
    // 00a34c65  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a34c68  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a34c6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a34c6d  0f8c54020000           -jl 0xa34ec7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a34ec7;
    }
    // 00a34c73  39d0                   +cmp eax, edx
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
    // 00a34c75  0f8e4c020000           -jle 0xa34ec7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a34ec7;
    }
    // 00a34c7b  895128                 -mov dword ptr [ecx + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a34c7e  e944020000             -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34c83:
    // 00a34c83  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a34c87  7438                   -je 0xa34cc1
    if (cpu.flags.zf)
    {
        goto L_0x00a34cc1;
    }
    // 00a34c89  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a34c8d  740f                   -je 0xa34c9e
    if (cpu.flags.zf)
    {
        goto L_0x00a34c9e;
    }
    // 00a34c8f  833c2400               +cmp dword ptr [esp], 0
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
    // 00a34c93  7510                   -jne 0xa34ca5
    if (!cpu.flags.zf)
    {
        goto L_0x00a34ca5;
    }
    // 00a34c95  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a34c9a  7425                   -je 0xa34cc1
    if (cpu.flags.zf)
    {
        goto L_0x00a34cc1;
    }
    // 00a34c9c  eb07                   -jmp 0xa34ca5
    goto L_0x00a34ca5;
L_0x00a34c9e:
    // 00a34c9e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a34ca3  741c                   -je 0xa34cc1
    if (cpu.flags.zf)
    {
        goto L_0x00a34cc1;
    }
L_0x00a34ca5:
    // 00a34ca5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34ca8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34cab  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a34cae  c6040630               -mov byte ptr [esi + eax], 0x30
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 00a34cb2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34cb5  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34cb8  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a34cbb  8a5115                 -mov dl, byte ptr [ecx + 0x15]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a34cbe  881406                 -mov byte ptr [esi + eax], dl
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dl;
L_0x00a34cc1:
    // 00a34cc1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00a34cc6:
    // 00a34cc6  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34cca  751a                   -jne 0xa34ce6
    if (!cpu.flags.zf)
    {
        goto L_0x00a34ce6;
    }
    // 00a34ccc  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34ccf  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a34cd4  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a34cd7  740d                   -je 0xa34ce6
    if (cpu.flags.zf)
    {
        goto L_0x00a34ce6;
    }
    // 00a34cd9  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34cdc  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a34cdf  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a34ce2  c6040630               -mov byte ptr [esi + eax], 0x30
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x00a34ce6:
    // 00a34ce6  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a34ce8  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34ceb  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a34ced  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a34cef  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a34cf2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a34cf4  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00a34cf7  7436                   -je 0xa34d2f
    if (cpu.flags.zf)
    {
        goto L_0x00a34d2f;
    }
    // 00a34cf9  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34cfd  7515                   -jne 0xa34d14
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d14;
    }
    // 00a34cff  833c2400               +cmp dword ptr [esp], 0
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
    // 00a34d03  750f                   -jne 0xa34d14
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d14;
    }
    // 00a34d05  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a34d0a  7508                   -jne 0xa34d14
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d14;
    }
L_0x00a34d0c:
    // 00a34d0c  26c60000               -mov byte ptr es:[eax], 0
    *app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a34d10  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a34d12  eb51                   -jmp 0xa34d65
    goto L_0x00a34d65;
L_0x00a34d14:
    // 00a34d14  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34d17  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a34d19  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a34d1b  e8c2030000             -call 0xa350e2
    cpu.esp -= 4;
    sub_a350e2(app, cpu);
    if (cpu.terminate) return;
    // 00a34d20  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34d24  7531                   -jne 0xa34d57
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d57;
    }
    // 00a34d26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34d28  e8a6010000             -call 0xa34ed3
    cpu.esp -= 4;
    sub_a34ed3(app, cpu);
    if (cpu.terminate) return;
    // 00a34d2d  eb28                   -jmp 0xa34d57
    goto L_0x00a34d57;
L_0x00a34d2f:
    // 00a34d2f  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34d33  7507                   -jne 0xa34d3c
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d3c;
    }
    // 00a34d35  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a34d3a  74d0                   -je 0xa34d0c
    if (cpu.flags.zf)
    {
        goto L_0x00a34d0c;
    }
L_0x00a34d3c:
    // 00a34d3c  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a34d3f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a34d43  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a34d45  e885040000             -call 0xa351cf
    cpu.esp -= 4;
    sub_a351cf(app, cpu);
    if (cpu.terminate) return;
    // 00a34d4a  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34d4e  7507                   -jne 0xa34d57
    if (!cpu.flags.zf)
    {
        goto L_0x00a34d57;
    }
    // 00a34d50  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34d52  e87c010000             -call 0xa34ed3
    cpu.esp -= 4;
    sub_a34ed3(app, cpu);
    if (cpu.terminate) return;
L_0x00a34d57:
    // 00a34d57  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a34d5c  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34d5e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34d60  e86af9ffff             -call 0xa346cf
    cpu.esp -= 4;
    sub_a346cf(app, cpu);
    if (cpu.terminate) return;
L_0x00a34d65:
    // 00a34d65  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a34d68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a34d6a  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a34d6d  39c2                   +cmp edx, eax
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
    // 00a34d6f  7d05                   -jge 0xa34d76
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a34d76;
    }
    // 00a34d71  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34d73  894124                 -mov dword ptr [ecx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00a34d76:
    // 00a34d76  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34d7a  0f8547010000           -jne 0xa34ec7
    if (!cpu.flags.zf)
    {
        goto L_0x00a34ec7;
    }
    // 00a34d80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a34d82  e815fbffff             -call 0xa3489c
    cpu.esp -= 4;
    sub_a3489c(app, cpu);
    if (cpu.terminate) return;
    // 00a34d87  e93b010000             -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34d8c:
    // 00a34d8c  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a34d90  7516                   -jne 0xa34da8
    if (!cpu.flags.zf)
    {
        goto L_0x00a34da8;
    }
    // 00a34d92  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 00a34d96  7409                   -je 0xa34da1
    if (cpu.flags.zf)
    {
        goto L_0x00a34da1;
    }
    // 00a34d98  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 00a34d9f  eb07                   -jmp 0xa34da8
    goto L_0x00a34da8;
L_0x00a34da1:
    // 00a34da1  c7410408000000         -mov dword ptr [ecx + 4], 8
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x00a34da8:
    // 00a34da8  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a34dac  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34dae  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34db1  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a34db3  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34db6  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a34db9  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a34dbc  7429                   -je 0xa34de7
    if (cpu.flags.zf)
    {
        goto L_0x00a34de7;
    }
    // 00a34dbe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34dc1  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a34dc3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00a34dc8  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a34dcb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a34dcd  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a34dd2  e885f9ffff             -call 0xa3475c
    cpu.esp -= 4;
    sub_a3475c(app, cpu);
    if (cpu.terminate) return;
    // 00a34dd7  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a34ddc  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00a34ddf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a34de1  c646043a               -mov byte ptr [esi + 4], 0x3a
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 00a34de5  eb09                   -jmp 0xa34df0
    goto L_0x00a34df0;
L_0x00a34de7:
    // 00a34de7  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a34dec  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a34dee  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a34df0:
    // 00a34df0  e867f9ffff             -call 0xa3475c
    cpu.esp -= 4;
    sub_a3475c(app, cpu);
    if (cpu.terminate) return;
    // 00a34df5  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34df9  7507                   -jne 0xa34e02
    if (!cpu.flags.zf)
    {
        goto L_0x00a34e02;
    }
    // 00a34dfb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34dfd  e8d1000000             -call 0xa34ed3
    cpu.esp -= 4;
    sub_a34ed3(app, cpu);
    if (cpu.terminate) return;
L_0x00a34e02:
    // 00a34e02  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a34e07  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34e09  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34e0b  e8bff8ffff             -call 0xa346cf
    cpu.esp -= 4;
    sub_a346cf(app, cpu);
    if (cpu.terminate) return;
L_0x00a34e10:
    // 00a34e10  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a34e13  e9af000000             -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34e18:
    // 00a34e18  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a34e1b  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00a34e22  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a34e25  7453                   -je 0xa34e7a
    if (cpu.flags.zf)
    {
        goto L_0x00a34e7a;
    }
    // 00a34e27  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34e29  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34e2c  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a34e2e  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a34e32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a34e34  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00a34e37  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a34e3b  e8f7010000             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a34e40  83f8ff                 +cmp eax, -1
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
    // 00a34e43  0f847e000000           -je 0xa34ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a34ec7;
    }
    // 00a34e49  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a34e4d  8b2d10d8a300           -mov ebp, dword ptr [0xa3d810]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
    // 00a34e53  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a34e55  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a34e57  746e                   -je 0xa34ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a34ec7;
    }
    // 00a34e59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a34e5b  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a34e5f  8a8015d8a300           -mov al, byte ptr [eax + 0xa3d815]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a34e65  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a34e67  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a34e6c  7459                   -je 0xa34ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a34ec7;
    }
    // 00a34e6e  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 00a34e72  884601                 -mov byte ptr [esi + 1], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a34e75  ff4120                 +inc dword ptr [ecx + 0x20]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34e78  eb4d                   -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34e7a:
    // 00a34e7a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34e7c  83c004                 +add eax, 4
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
    // 00a34e7f  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a34e81  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a34e84  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a34e86  eb3f                   -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34e88:
    // 00a34e88  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a34e8a  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a34e8d  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a34e8f  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a34e93  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a34e99  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a34e9b  e897010000             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a34ea0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a34ea2  83f8ff                 +cmp eax, -1
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
    // 00a34ea5  0f8565ffffff           -jne 0xa34e10
    if (!cpu.flags.zf)
    {
        goto L_0x00a34e10;
    }
    // 00a34eab  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a34eb2  eb13                   -jmp 0xa34ec7
    goto L_0x00a34ec7;
L_0x00a34eb4:
    // 00a34eb4  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a34ebb  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a34ebe  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a34ec0  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x00a34ec7:
    // 00a34ec7  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a34ec9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a34ecb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a34ece  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34ecf  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a34ed0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34ed1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34ed2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34ed3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34ed3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34ed4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a34ed6:
    // 00a34ed6  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34ed9  740e                   -je 0xa34ee9
    if (cpu.flags.zf)
    {
        goto L_0x00a34ee9;
    }
    // 00a34edb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a34edd  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a34edf  e864030000             -call 0xa35248
    cpu.esp -= 4;
    sub_a35248(app, cpu);
    if (cpu.terminate) return;
    // 00a34ee4  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00a34ee6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34ee7  ebed                   -jmp 0xa34ed6
    goto L_0x00a34ed6;
L_0x00a34ee9:
    // 00a34ee9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34eea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a34ef0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34ef0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a34ef2  742c                   -je 0xa34f20
    if (cpu.flags.zf)
    {
        goto L_0x00a34f20;
    }
    // 00a34ef4  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a34ef6:
    // 00a34ef6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00a34ef8  7409                   -je 0xa34f03
    if (cpu.flags.zf)
    {
        goto L_0x00a34f03;
    }
    // 00a34efa  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a34efc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a34efd  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 00a34f00  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f01  75f3                   -jne 0xa34ef6
    if (!cpu.flags.zf)
    {
        goto L_0x00a34ef6;
    }
L_0x00a34f03:
    // 00a34f03  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34f04  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a34f07  e81b000000             -call 0xa34f27
    cpu.esp -= 4;
    sub_a34f27(app, cpu);
    if (cpu.terminate) return;
    // 00a34f0c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34f0d  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a34f10  740e                   -je 0xa34f20
    if (cpu.flags.zf)
    {
        goto L_0x00a34f20;
    }
    // 00a34f12  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a34f14  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f15  7409                   -je 0xa34f20
    if (cpu.flags.zf)
    {
        goto L_0x00a34f20;
    }
    // 00a34f17  887001                 -mov byte ptr [eax + 1], dh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 00a34f1a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f1b  7403                   -je 0xa34f20
    if (cpu.flags.zf)
    {
        goto L_0x00a34f20;
    }
    // 00a34f1d  885002                 -mov byte ptr [eax + 2], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00a34f20:
    // 00a34f20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a34f22(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34f22  90                     -nop 
    ;
    // 00a34f23  90                     -nop 
    ;
    // 00a34f24  90                     -nop 
    ;
    // 00a34f25  90                     -nop 
    ;
    // 00a34f26  90                     -nop 
    ;
    // 00a34f27  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a34f29  7467                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
L_0x00a34f2b:
    // 00a34f2b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a34f2d  7408                   -je 0xa34f37
    if (cpu.flags.zf)
    {
        goto L_0x00a34f37;
    }
    // 00a34f2f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f31  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f34  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f35  75f4                   -jne 0xa34f2b
    if (!cpu.flags.zf)
    {
        goto L_0x00a34f2b;
    }
L_0x00a34f37:
    // 00a34f37  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34f38  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a34f3b  743a                   -je 0xa34f77
    if (cpu.flags.zf)
    {
        goto L_0x00a34f77;
    }
    // 00a34f3d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f3e  7429                   -je 0xa34f69
    if (cpu.flags.zf)
    {
        goto L_0x00a34f69;
    }
L_0x00a34f40:
    // 00a34f40  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f42  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a34f45  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f46  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a34f49  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a34f4c  7418                   -je 0xa34f66
    if (cpu.flags.zf)
    {
        goto L_0x00a34f66;
    }
    // 00a34f4e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34f51  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a34f54  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a34f57  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f58  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a34f5b  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a34f5e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a34f61  75dd                   -jne 0xa34f40
    if (!cpu.flags.zf)
    {
        goto L_0x00a34f40;
    }
    // 00a34f63  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a34f66:
    // 00a34f66  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a34f69:
    // 00a34f69  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f6b  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a34f6e  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a34f71  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a34f74  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a34f77:
    // 00a34f77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34f78  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a34f7b  7415                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f7d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f7f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f82  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f83  740d                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f85  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f87  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f8a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f8b  7405                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f8d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f8f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a34f92:
    // 00a34f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34f27(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a34f27;
    // 00a34f22  90                     -nop 
    ;
    // 00a34f23  90                     -nop 
    ;
    // 00a34f24  90                     -nop 
    ;
    // 00a34f25  90                     -nop 
    ;
    // 00a34f26  90                     -nop 
    ;
L_entry_0x00a34f27:
    // 00a34f27  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a34f29  7467                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
L_0x00a34f2b:
    // 00a34f2b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a34f2d  7408                   -je 0xa34f37
    if (cpu.flags.zf)
    {
        goto L_0x00a34f37;
    }
    // 00a34f2f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f31  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f34  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f35  75f4                   -jne 0xa34f2b
    if (!cpu.flags.zf)
    {
        goto L_0x00a34f2b;
    }
L_0x00a34f37:
    // 00a34f37  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a34f38  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a34f3b  743a                   -je 0xa34f77
    if (cpu.flags.zf)
    {
        goto L_0x00a34f77;
    }
    // 00a34f3d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f3e  7429                   -je 0xa34f69
    if (cpu.flags.zf)
    {
        goto L_0x00a34f69;
    }
L_0x00a34f40:
    // 00a34f40  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f42  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a34f45  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f46  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a34f49  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a34f4c  7418                   -je 0xa34f66
    if (cpu.flags.zf)
    {
        goto L_0x00a34f66;
    }
    // 00a34f4e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34f51  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a34f54  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a34f57  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f58  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a34f5b  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a34f5e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a34f61  75dd                   -jne 0xa34f40
    if (!cpu.flags.zf)
    {
        goto L_0x00a34f40;
    }
    // 00a34f63  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a34f66:
    // 00a34f66  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a34f69:
    // 00a34f69  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f6b  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a34f6e  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a34f71  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a34f74  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a34f77:
    // 00a34f77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34f78  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a34f7b  7415                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f7d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f7f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f82  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f83  740d                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f85  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f87  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a34f8a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a34f8b  7405                   -je 0xa34f92
    if (cpu.flags.zf)
    {
        goto L_0x00a34f92;
    }
    // 00a34f8d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a34f8f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a34f92:
    // 00a34f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34f93(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34f93  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34f94  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34f95  ba5652a300             -mov edx, 0xa35256
    cpu.edx = 10703446 /*0xa35256*/;
    // 00a34f9a  bb6a53a300             -mov ebx, 0xa3536a
    cpu.ebx = 10703722 /*0xa3536a*/;
    // 00a34f9f  891560cba300           -mov dword ptr [0xa3cb60], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734432) /* 0xa3cb60 */) = cpu.edx;
    // 00a34fa5  891d64cba300           -mov dword ptr [0xa3cb64], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10734436) /* 0xa3cb64 */) = cpu.ebx;
    // 00a34fab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34fac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34fad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34fae(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34fae  9b                     -wait 
    /*nothing*/;
    // 00a34faf  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a34fb1  9b                     -wait 
    /*nothing*/;
    // 00a34fb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34fb3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34fb3  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a34fb5  9b                     -wait 
    /*nothing*/;
    // 00a34fb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34fb7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a34fb7:
    // 00a34fb7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a34fb8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34fb9  803dd1caa30000         +cmp byte ptr [0xa3cad1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734289) /* 0xa3cad1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34fc0  7416                   -je 0xa34fd8
    if (cpu.flags.zf)
    {
        goto L_0x00a34fd8;
    }
    // 00a34fc2  baae4fa300             -mov edx, 0xa34fae
    cpu.edx = 10702766 /*0xa34fae*/;
    // 00a34fc7  bbb34fa300             -mov ebx, 0xa34fb3
    cpu.ebx = 10702771 /*0xa34fb3*/;
    // 00a34fcc  8915b8cba300           -mov dword ptr [0xa3cbb8], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734520) /* 0xa3cbb8 */) = cpu.edx;
    // 00a34fd2  891dbccba300           -mov dword ptr [0xa3cbbc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10734524) /* 0xa3cbbc */) = cpu.ebx;
L_0x00a34fd8:
    // 00a34fd8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a34fda  66a1c0cba300           -mov ax, word ptr [0xa3cbc0]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(10734528) /* 0xa3cbc0 */);
    // 00a34fe0  e895030000             -call 0xa3537a
    cpu.esp -= 4;
    sub_a3537a(app, cpu);
    if (cpu.terminate) return;
    // 00a34fe5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34fe6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a34fe7  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a34fe8  803dd1caa30000         +cmp byte ptr [0xa3cad1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734289) /* 0xa3cad1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a34fef  75c6                   -jne 0xa34fb7
    if (!cpu.flags.zf)
    {
        goto L_0x00a34fb7;
    }
    // 00a34ff1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a34ff2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a34ff2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a34ff3  8a25d0caa300           -mov ah, byte ptr [0xa3cad0]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(10734288) /* 0xa3cad0 */);
    // 00a34ff9  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a34ffb  7537                   -jne 0xa35034
    if (!cpu.flags.zf)
    {
        goto L_0x00a35034;
    }
    // 00a34ffd  8825d1caa300           -mov byte ptr [0xa3cad1], ah
    *app->getMemory<x86::reg8>(x86::reg32(10734289) /* 0xa3cad1 */) = cpu.ah;
    // 00a35003  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a35005  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35007  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35008  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a3500a  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a3500d  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3500e  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a35010  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a35012  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35014  7509                   -jne 0xa3501f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3501f;
    }
    // 00a35016  e89cffffff             -call 0xa34fb7
    cpu.esp -= 4;
    sub_a34fb7(app, cpu);
    if (cpu.terminate) return;
    // 00a3501b  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00a3501d  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00a3501f:
    // 00a3501f  803d14cba30000         +cmp byte ptr [0xa3cb14], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734356) /* 0xa3cb14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35026  750c                   -jne 0xa35034
    if (!cpu.flags.zf)
    {
        goto L_0x00a35034;
    }
    // 00a35028  8835d0caa300           -mov byte ptr [0xa3cad0], dh
    *app->getMemory<x86::reg8>(x86::reg32(10734288) /* 0xa3cad0 */) = cpu.dh;
    // 00a3502e  8815d1caa300           -mov byte ptr [0xa3cad1], dl
    *app->getMemory<x86::reg8>(x86::reg32(10734289) /* 0xa3cad1 */) = cpu.dl;
L_0x00a35034:
    // 00a35034  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35035  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35036(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35036  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35037(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35037  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35038  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3503b  742a                   -je 0xa35067
    if (cpu.flags.zf)
    {
        goto L_0x00a35067;
    }
    // 00a3503d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3503f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a35041  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a35043  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35044  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a35046  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a3504a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3504b  6800020000             -push 0x200
    *app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00a35050  8b15c4cba300           -mov edx, dword ptr [0xa3cbc4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */);
    // 00a35056  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35057  2eff15d4a9a300         -call dword ptr cs:[0xa3a9d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725844) /* 0xa3a9d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3505e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35060  7505                   -jne 0xa35067
    if (!cpu.flags.zf)
    {
        goto L_0x00a35067;
    }
    // 00a35062  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a35067:
    // 00a35067  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3506a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3506b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3506c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3506c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3506d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3506e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3506f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35070  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a35073  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a35075  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a35077  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a35079  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a3507b  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a3507f  881424                 -mov byte ptr [esp], dl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a35082:
    // 00a35082  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a35086  897c2424               -mov dword ptr [esp + 0x24], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a3508a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3508c  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = *app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a3508e  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a35090  8a8238cba300           -mov al, byte ptr [edx + 0xa3cb38]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734392) /* 0xa3cb38 */);
    // 00a35096  8801                   -mov byte ptr [ecx], al
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00a35098  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a3509c  41                     -inc ecx
    (cpu.ecx)++;
    // 00a3509d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3509f  75e1                   -jne 0xa35082
    if (!cpu.flags.zf)
    {
        goto L_0x00a35082;
    }
L_0x00a350a1:
    // 00a350a1  49                     -dec ecx
    (cpu.ecx)--;
    // 00a350a2  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a350a4  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a350a6  46                     -inc esi
    (cpu.esi)++;
    // 00a350a7  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a350a9  75f6                   -jne 0xa350a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a350a1;
    }
    // 00a350ab  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a350ad  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a350b0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350b1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350b2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350b3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a350b5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a350b5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a350b6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a350b8  83fb0a                 +cmp ebx, 0xa
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
    // 00a350bb  750a                   -jne 0xa350c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a350c7;
    }
    // 00a350bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a350bf  7d06                   -jge 0xa350c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a350c7;
    }
    // 00a350c1  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a350c3  c6022d                 -mov byte ptr [edx], 0x2d
    *app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a350c6  42                     -inc edx
    (cpu.edx)++;
L_0x00a350c7:
    // 00a350c7  e8a0ffffff             -call 0xa3506c
    cpu.esp -= 4;
    sub_a3506c(app, cpu);
    if (cpu.terminate) return;
    // 00a350cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a350ce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a350d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a350d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a350d1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a350d6  b824bba300             -mov eax, 0xa3bb24
    cpu.eax = 10730276 /*0xa3bb24*/;
    // 00a350db  e846040000             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
    // 00a350e0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a350e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a350e2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a350e2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a350e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a350e4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a350e5  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a350e6  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a350e7  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a350ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a350ec  8954243c               -mov dword ptr [esp + 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00a350f0  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a350f4  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a350f8  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a350fa  89542440               -mov dword ptr [esp + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00a350fe  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35100  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35102  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a35104  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35105  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35106  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a3510a  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a3510e  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a35111:
    // 00a35111  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a35115  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a35119  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a3511d  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a35121  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a35124  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a35126  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a35129  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a3512b  e869040000             -call 0xa35599
    cpu.esp -= 4;
    sub_a35599(app, cpu);
    if (cpu.terminate) return;
    // 00a35130  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a35133  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a35135  894f04                 -mov dword ptr [edi + 4], ecx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a35138  891f                   -mov dword ptr [edi], ebx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a3513a  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a3513e  8a8368cba300           -mov al, byte ptr [ebx + 0xa3cb68]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10734440) /* 0xa3cb68 */);
    // 00a35144  884500                 -mov byte ptr [ebp], al
    *app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00a35147  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a3514b  45                     -inc ebp
    (cpu.ebp)++;
    // 00a3514c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a3514e  75c1                   -jne 0xa35111
    if (!cpu.flags.zf)
    {
        goto L_0x00a35111;
    }
    // 00a35150  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35155  75ba                   -jne 0xa35111
    if (!cpu.flags.zf)
    {
        goto L_0x00a35111;
    }
L_0x00a35157:
    // 00a35157  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a3515b  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a3515c  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a3515f  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp);
    // 00a35162  89742440               -mov dword ptr [esp + 0x40], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00a35166  8803                   -mov byte ptr [ebx], al
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a35168  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a3516a  75eb                   -jne 0xa35157
    if (!cpu.flags.zf)
    {
        goto L_0x00a35157;
    }
    // 00a3516c  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a35170  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a35173  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35174  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35175  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35176  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35177  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35179(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35179  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3517a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3517b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3517c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3517d  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a35180  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a35182  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a35184  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35186  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a35188  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a3518a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3518b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3518c  83fb0a                 +cmp ebx, 0xa
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
    // 00a3518f  752d                   -jne 0xa351be
    if (!cpu.flags.zf)
    {
        goto L_0x00a351be;
    }
    // 00a35191  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a35196  7426                   -je 0xa351be
    if (cpu.flags.zf)
    {
        goto L_0x00a351be;
    }
    // 00a35198  c6022d                 -mov byte ptr [edx], 0x2d
    *app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a3519b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3519e  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a351a2  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00a351a4  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 00a351a6  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a351a9  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a351ad  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a351b0  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a351b3  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a351b4  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a351b7  7501                   -jne 0xa351ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a351ba;
    }
    // 00a351b9  46                     -inc esi
    (cpu.esi)++;
L_0x00a351ba:
    // 00a351ba  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00a351be:
    // 00a351be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a351c0  e81dffffff             -call 0xa350e2
    cpu.esp -= 4;
    sub_a350e2(app, cpu);
    if (cpu.terminate) return;
    // 00a351c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a351c7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a351ca  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a351cb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a351cc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a351cd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a351ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a351cf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a351cf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a351d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a351d1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a351d2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a351d3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a351d6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a351d8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a351da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a351dc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a351de  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a351e2  881424                 -mov byte ptr [esp], dl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a351e5:
    // 00a351e5  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a351e9  897c2424               -mov dword ptr [esp + 0x24], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a351ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a351ef  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = *app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a351f1  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a351f3  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a351f7  8a9290cba300           -mov dl, byte ptr [edx + 0xa3cb90]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734480) /* 0xa3cb90 */);
    // 00a351fd  8811                   -mov byte ptr [ecx], dl
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00a351ff  41                     -inc ecx
    (cpu.ecx)++;
    // 00a35200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35202  75e1                   -jne 0xa351e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a351e5;
    }
L_0x00a35204:
    // 00a35204  49                     -dec ecx
    (cpu.ecx)--;
    // 00a35205  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a35207  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a35209  46                     -inc esi
    (cpu.esi)++;
    // 00a3520a  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a3520c  75f6                   -jne 0xa35204
    if (!cpu.flags.zf)
    {
        goto L_0x00a35204;
    }
    // 00a3520e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a35210  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a35213  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35214  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35215  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35216  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35217  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35218(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35218  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35219  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a3521b  83fb0a                 +cmp ebx, 0xa
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
    // 00a3521e  750a                   -jne 0xa3522a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3522a;
    }
    // 00a35220  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35222  7d06                   -jge 0xa3522a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3522a;
    }
    // 00a35224  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a35226  c6022d                 -mov byte ptr [edx], 0x2d
    *app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a35229  42                     -inc edx
    (cpu.edx)++;
L_0x00a3522a:
    // 00a3522a  e8a0ffffff             -call 0xa351cf
    cpu.esp -= 4;
    sub_a351cf(app, cpu);
    if (cpu.terminate) return;
    // 00a3522f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35231  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35232  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35233(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35233  8a8015d8a300           -mov al, byte ptr [eax + 0xa3d815]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a35239  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a3523b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a35240  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35241(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35241  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a35243  e959010000             -jmp 0xa353a1
    return sub_a353a1(app, cpu);
}

/* align: skip  */
void sub_a35248(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35248  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3524b  7c08                   -jl 0xa35255
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35255;
    }
    // 00a3524d  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35250  7f03                   -jg 0xa35255
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35255;
    }
    // 00a35252  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a35255:
    // 00a35255  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35256(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35256  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35257  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35259  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3525a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3525b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3525c  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a3525f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a35261  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35263  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35265  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a35268  8945c0                 -mov dword ptr [ebp - 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a3526b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a3526e  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a35271  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 00a35273  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a35278  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3527b  7523                   -jne 0xa352a0
    if (!cpu.flags.zf)
    {
        goto L_0x00a352a0;
    }
    // 00a3527d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a3527f  7505                   -jne 0xa35286
    if (!cpu.flags.zf)
    {
        goto L_0x00a35286;
    }
    // 00a35281  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a35286:
    // 00a35286  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 00a3528d  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a35290  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a35295  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a35298  8945b8                 -mov dword ptr [ebp - 0x48], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00a3529b  897dc0                 -mov dword ptr [ebp - 0x40], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 00a3529e  eb1f                   -jmp 0xa352bf
    goto L_0x00a352bf;
L_0x00a352a0:
    // 00a352a0  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a352a3  750d                   -jne 0xa352b2
    if (!cpu.flags.zf)
    {
        goto L_0x00a352b2;
    }
    // 00a352a5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a352aa  897dbc                 -mov dword ptr [ebp - 0x44], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a352ad  897db8                 -mov dword ptr [ebp - 0x48], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 00a352b0  eb0d                   -jmp 0xa352bf
    goto L_0x00a352bf;
L_0x00a352b2:
    // 00a352b2  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00a352b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a352b9  897dbc                 -mov dword ptr [ebp - 0x44], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a352bc  8945b8                 -mov dword ptr [ebp - 0x48], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x00a352bf:
    // 00a352bf  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a352c3  7404                   -je 0xa352c9
    if (cpu.flags.zf)
    {
        goto L_0x00a352c9;
    }
    // 00a352c5  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00a352c9:
    // 00a352c9  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a352cb  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a352ce  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a352d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a352d2  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00a352d5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a352d8  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a352db  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a352de  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a352e1  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a352e4  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.eax)));
    // 00a352e6  db3a                   -fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a352e8  83fbff                 +cmp ebx, -1
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
    // 00a352eb  7505                   -jne 0xa352f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a352f2;
    }
    // 00a352ed  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x00a352f2:
    // 00a352f2  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a352f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a352f7  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 00a352fa  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 00a352fd  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a35300  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a35303  e857040000             -call 0xa3575f
    cpu.esp -= 4;
    sub_a3575f(app, cpu);
    if (cpu.terminate) return;
    // 00a35308  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a3530b  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a3530e  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a35311  89412c                 -mov dword ptr [ecx + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a35314  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a35317  894130                 -mov dword ptr [ecx + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a3531a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a3531d  894134                 -mov dword ptr [ecx + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a35320  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35324  7d0f                   -jge 0xa35335
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35335;
    }
    // 00a35326  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a35329  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3532c  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a3532f  c604062d               -mov byte ptr [esi + eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a35333  eb29                   -jmp 0xa3535e
    goto L_0x00a3535e;
L_0x00a35335:
    // 00a35335  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a35338  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a3533b  740f                   -je 0xa3534c
    if (cpu.flags.zf)
    {
        goto L_0x00a3534c;
    }
    // 00a3533d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a35340  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a35343  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a35346  c604062b               -mov byte ptr [esi + eax], 0x2b
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a3534a  eb12                   -jmp 0xa3535e
    goto L_0x00a3535e;
L_0x00a3534c:
    // 00a3534c  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a3534f  740d                   -je 0xa3535e
    if (cpu.flags.zf)
    {
        goto L_0x00a3535e;
    }
    // 00a35351  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a35354  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a35357  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a3535a  c6040620               -mov byte ptr [esi + eax], 0x20
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a3535e:
    // 00a3535e  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a35360  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35362  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35365  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35366  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35367  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35368  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35369  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3536a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3536a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3536b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a3536d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3536f  e8350f0000             -call 0xa362a9
    cpu.esp -= 4;
    sub_a362a9(app, cpu);
    if (cpu.terminate) return;
    // 00a35374  dd1b                   -fstp qword ptr [ebx]
    *app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a35376  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35377  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35378(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35378  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a3537a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3537a  6650                   -push ax
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 00a3537c  9b                     -wait 
    /*nothing*/;
    // 00a3537d  dbe3                   +fninit 
    cpu.fpu.init();
    // 00a3537f  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00a35381  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a35383  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35385  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a35387  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a35389  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00a3538b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a3538d  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00a3538f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a35390  7402                   -je 0xa35394
    if (cpu.flags.zf)
    {
        goto L_0x00a35394;
    }
    // 00a35392  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x00a35394:
    // 00a35394  9b                     -wait 
    /*nothing*/;
    // 00a35395  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a35397  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a3539a  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = *app->getMemory<x86::reg16>(cpu.esp);
        *app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 00a3539e  6658                   -pop ax
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a353a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a353a1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a353a1  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a353a2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a353a3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a353a4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a353a5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a353a6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a353a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a353ab  83f8ff                 +cmp eax, -1
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
    // 00a353ae  750e                   -jne 0xa353be
    if (!cpu.flags.zf)
    {
        goto L_0x00a353be;
    }
    // 00a353b0  2eff1544a9a300         -call dword ptr cs:[0xa3a944]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725700) /* 0xa3a944 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a353b7:
    // 00a353b7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a353b9  e98e000000             -jmp 0xa3544c
    goto L_0x00a3544c;
L_0x00a353be:
    // 00a353be  83f8fe                 +cmp eax, -2
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
    // 00a353c1  7509                   -jne 0xa353cc
    if (!cpu.flags.zf)
    {
        goto L_0x00a353cc;
    }
    // 00a353c3  2eff1574a9a300         -call dword ptr cs:[0xa3a974]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725748) /* 0xa3a974 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a353ca  ebeb                   -jmp 0xa353b7
    goto L_0x00a353b7;
L_0x00a353cc:
    // 00a353cc  83f8fd                 +cmp eax, -3
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
    // 00a353cf  7526                   -jne 0xa353f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a353f7;
    }
    // 00a353d1  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a353d6  b814d8a300             -mov eax, 0xa3d814
    cpu.eax = 10737684 /*0xa3d814*/;
    // 00a353db  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a353dd  e867eeffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a353e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a353e4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a353e6  891510d8a300           -mov dword ptr [0xa3d810], edx
    *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */) = cpu.edx;
    // 00a353ec  8915c4cba300           -mov dword ptr [0xa3cbc4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */) = cpu.edx;
    // 00a353f2  e9ed000000             -jmp 0xa354e4
    goto L_0x00a354e4;
L_0x00a353f7:
    // 00a353f7  83f8fc                 +cmp eax, -4
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
    // 00a353fa  7550                   -jne 0xa3544c
    if (!cpu.flags.zf)
    {
        goto L_0x00a3544c;
    }
    // 00a353fc  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a35401  b814d8a300             -mov eax, 0xa3d814
    cpu.eax = 10737684 /*0xa3d814*/;
    // 00a35406  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35408  e83ceeffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a3540d  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 00a35412  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x00a35414:
    // 00a35414  40                     -inc eax
    (cpu.eax)++;
    // 00a35415  889014d8a300           -mov byte ptr [eax + 0xa3d814], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737684) /* 0xa3d814 */) = cpu.dl;
    // 00a3541b  3d9f000000             +cmp eax, 0x9f
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
    // 00a35420  7ef2                   -jle 0xa35414
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35414;
    }
    // 00a35422  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00a35427  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x00a35429:
    // 00a35429  40                     -inc eax
    (cpu.eax)++;
    // 00a3542a  88b014d8a300           -mov byte ptr [eax + 0xa3d814], dh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737684) /* 0xa3d814 */) = cpu.dh;
    // 00a35430  3dfc000000             +cmp eax, 0xfc
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
    // 00a35435  7ef2                   -jle 0xa35429
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35429;
    }
    // 00a35437  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a3543c  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 00a35441  892d10d8a300           -mov dword ptr [0xa3d810], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */) = cpu.ebp;
    // 00a35447  e989000000             -jmp 0xa354d5
    goto L_0x00a354d5;
L_0x00a3544c:
    // 00a3544c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a3544e  7505                   -jne 0xa35455
    if (!cpu.flags.zf)
    {
        goto L_0x00a35455;
    }
    // 00a35450  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00a35455:
    // 00a35455  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a35457  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35458  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35459  2eff1548a9a300         -call dword ptr cs:[0xa3a948]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725704) /* 0xa3a948 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a35460  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35462  750a                   -jne 0xa3546e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3546e;
    }
    // 00a35464  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a35469  e976000000             -jmp 0xa354e4
    goto L_0x00a354e4;
L_0x00a3546e:
    // 00a3546e  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a35473  b814d8a300             -mov eax, 0xa3d814
    cpu.eax = 10737684 /*0xa3d814*/;
    // 00a35478  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3547a  e8caedffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a3547f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35481  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a35485  890d10d8a300           -mov dword ptr [0xa3d810], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */) = cpu.ecx;
    // 00a3548b  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a3548d  740a                   -je 0xa35499
    if (cpu.flags.zf)
    {
        goto L_0x00a35499;
    }
    // 00a3548f  c70510d8a30001000000   -mov dword ptr [0xa3d810], 1
    *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */) = 1 /*0x1*/;
L_0x00a35499:
    // 00a35499  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a3549b  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a3549d  eb1c                   -jmp 0xa354bb
    goto L_0x00a354bb;
L_0x00a3549f:
    // 00a3549f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a354a1  8a441406               -mov al, byte ptr [esp + edx + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
    // 00a354a5  eb07                   -jmp 0xa354ae
    goto L_0x00a354ae;
L_0x00a354a7:
    // 00a354a7  40                     -inc eax
    (cpu.eax)++;
    // 00a354a8  888814d8a300           -mov byte ptr [eax + 0xa3d814], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737684) /* 0xa3d814 */) = cpu.cl;
L_0x00a354ae:
    // 00a354ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a354b0  8a5c1407               -mov bl, byte ptr [esp + edx + 7]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
    // 00a354b4  39d8                   +cmp eax, ebx
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
    // 00a354b6  7eef                   -jle 0xa354a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a354a7;
    }
    // 00a354b8  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a354bb:
    // 00a354bb  807c140600             +cmp byte ptr [esp + edx + 6], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a354c0  75dd                   -jne 0xa3549f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3549f;
    }
    // 00a354c2  807c140700             +cmp byte ptr [esp + edx + 7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a354c7  75d6                   -jne 0xa3549f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3549f;
    }
    // 00a354c9  83fe01                 +cmp esi, 1
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
    // 00a354cc  750e                   -jne 0xa354dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a354dc;
    }
    // 00a354ce  2eff1574a9a300         -call dword ptr cs:[0xa3a974]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725748) /* 0xa3a974 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a354d5:
    // 00a354d5  a3c4cba300             -mov dword ptr [0xa3cbc4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */) = cpu.eax;
    // 00a354da  eb06                   -jmp 0xa354e2
    goto L_0x00a354e2;
L_0x00a354dc:
    // 00a354dc  8935c4cba300           -mov dword ptr [0xa3cbc4], esi
    *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */) = cpu.esi;
L_0x00a354e2:
    // 00a354e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a354e4:
    // 00a354e4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a354e7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a354e8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a354e9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a354ea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a354eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a354ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a354ed(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a354ed  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a354ee  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a354ef  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a354f0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a354f1  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a354f4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a354f6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a354f8  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a354fa  eb01                   -jmp 0xa354fd
    goto L_0x00a354fd;
L_0x00a354fc:
    // 00a354fc  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a354fd:
    // 00a354fd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a354ff  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a35501  40                     -inc eax
    (cpu.eax)++;
    // 00a35502  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a35504  75f6                   -jne 0xa354fc
    if (!cpu.flags.zf)
    {
        goto L_0x00a354fc;
    }
    // 00a35506  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a35508  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a3550c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3550d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3550e  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a35513  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35514  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a35517  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35518  2eff15d8a9a300         -call dword ptr cs:[0xa3a9d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725848) /* 0xa3a9d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3551f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35521  e9b2120000             -jmp 0xa367d8
    return sub_a367d8(app, cpu);
}

/* align: skip  */
void sub_a35526(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35526  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35527  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35528  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a3552a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a3552c  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a3552e  e8e7120000             -call 0xa3681a
    cpu.esp -= 4;
    sub_a3681a(app, cpu);
    if (cpu.terminate) return;
    // 00a35533  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35535  7509                   -jne 0xa35540
    if (!cpu.flags.zf)
    {
        goto L_0x00a35540;
    }
    // 00a35537  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a35539  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a3553b  e8adffffff             -call 0xa354ed
    cpu.esp -= 4;
    sub_a354ed(app, cpu);
    if (cpu.terminate) return;
L_0x00a35540:
    // 00a35540  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35541  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35542  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a35544(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35544  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a35546  781e                   -js 0xa35566
    if (cpu.flags.sf)
    {
        goto L_0x00a35566;
    }
    // 00a35548  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a3554a  7806                   -js 0xa35552
    if (cpu.flags.sf)
    {
        goto L_0x00a35552;
    }
    // 00a3554c  e848000000             -call 0xa35599
    cpu.esp -= 4;
    sub_a35599(app, cpu);
    if (cpu.terminate) return;
    // 00a35551  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a35552:
    // 00a35552  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a35554  f7db                   +neg ebx
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
    // 00a35556  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35559  e83b000000             -call 0xa35599
    cpu.esp -= 4;
    sub_a35599(app, cpu);
    if (cpu.terminate) return;
    // 00a3555e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a35560  f7d8                   +neg eax
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
    // 00a35562  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35565  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a35566:
    // 00a35566  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a35568  f7d8                   +neg eax
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
    // 00a3556a  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a3556d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a3556f  7914                   -jns 0xa35585
    if (!cpu.flags.sf)
    {
        goto L_0x00a35585;
    }
    // 00a35571  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a35573  f7db                   +neg ebx
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
    // 00a35575  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35578  e81c000000             -call 0xa35599
    cpu.esp -= 4;
    sub_a35599(app, cpu);
    if (cpu.terminate) return;
    // 00a3557d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a3557f  f7db                   +neg ebx
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
    // 00a35581  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35584  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a35585:
    // 00a35585  e80f000000             -call 0xa35599
    cpu.esp -= 4;
    sub_a35599(app, cpu);
    if (cpu.terminate) return;
    // 00a3558a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a3558c  f7db                   +neg ebx
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
    // 00a3558e  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35591  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a35593  f7d8                   +neg eax
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
    // 00a35595  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a35598  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35599(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35599  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a3559b  751a                   -jne 0xa355b7
    if (!cpu.flags.zf)
    {
        goto L_0x00a355b7;
    }
    // 00a3559d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a3559e  7416                   -je 0xa355b6
    if (cpu.flags.zf)
    {
        goto L_0x00a355b6;
    }
    // 00a355a0  43                     -inc ebx
    (cpu.ebx)++;
    // 00a355a1  39d3                   +cmp ebx, edx
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
    // 00a355a3  7709                   -ja 0xa355ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a355ae;
    }
    // 00a355a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a355a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a355a9  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a355ab  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a355ad  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x00a355ae:
    // 00a355ae  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a355b0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a355b2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a355b4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a355b6:
    // 00a355b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a355b7:
    // 00a355b7  39d1                   +cmp ecx, edx
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
    // 00a355b9  721c                   -jb 0xa355d7
    if (cpu.flags.cf)
    {
        goto L_0x00a355d7;
    }
    // 00a355bb  7512                   -jne 0xa355cf
    if (!cpu.flags.zf)
    {
        goto L_0x00a355cf;
    }
    // 00a355bd  39c3                   +cmp ebx, eax
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
    // 00a355bf  770e                   -ja 0xa355cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a355cf;
    }
    // 00a355c1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a355c3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a355c5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a355c7  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a355c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a355ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a355cf:
    // 00a355cf  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a355d1  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a355d3  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a355d4  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 00a355d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a355d7:
    // 00a355d7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a355d8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a355d9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a355da  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a355dc  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a355de  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00a355e0:
    // 00a355e0  01db                   +add ebx, ebx
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
    // 00a355e2  11c9                   +adc ecx, ecx
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
    // 00a355e4  7213                   -jb 0xa355f9
    if (cpu.flags.cf)
    {
        goto L_0x00a355f9;
    }
    // 00a355e6  45                     -inc ebp
    (cpu.ebp)++;
    // 00a355e7  39d1                   +cmp ecx, edx
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
    // 00a355e9  72f5                   -jb 0xa355e0
    if (cpu.flags.cf)
    {
        goto L_0x00a355e0;
    }
    // 00a355eb  7704                   -ja 0xa355f1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a355f1;
    }
    // 00a355ed  39c3                   +cmp ebx, eax
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
    // 00a355ef  76ef                   -jbe 0xa355e0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a355e0;
    }
L_0x00a355f1:
    // 00a355f1  f8                     +clc 
    cpu.flags.cf = 0;
L_0x00a355f2:
    // 00a355f2  11f6                   +adc esi, esi
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
    // 00a355f4  11ff                   +adc edi, edi
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
    // 00a355f6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a355f7  7822                   -js 0xa3561b
    if (cpu.flags.sf)
    {
        goto L_0x00a3561b;
    }
L_0x00a355f9:
    // 00a355f9  d1d9                   +rcr ecx, 1
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
    // 00a355fb  d1db                   -rcr ebx, 1
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
    // 00a355fd  29d8                   +sub eax, ebx
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
    // 00a355ff  19ca                   +sbb edx, ecx
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
    // 00a35601  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 00a35602  72ee                   -jb 0xa355f2
    if (cpu.flags.cf)
    {
        goto L_0x00a355f2;
    }
L_0x00a35604:
    // 00a35604  01f6                   +add esi, esi
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
    // 00a35606  11ff                   +adc edi, edi
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
    // 00a35608  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35609  780c                   -js 0xa35617
    if (cpu.flags.sf)
    {
        goto L_0x00a35617;
    }
    // 00a3560b  d1e9                   +shr ecx, 1
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
    // 00a3560d  d1db                   -rcr ebx, 1
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
    // 00a3560f  01d8                   +add eax, ebx
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
    // 00a35611  11ca                   +adc edx, ecx
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
    // 00a35613  73ef                   -jae 0xa35604
    if (!cpu.flags.cf)
    {
        goto L_0x00a35604;
    }
    // 00a35615  ebdb                   -jmp 0xa355f2
    goto L_0x00a355f2;
L_0x00a35617:
    // 00a35617  01d8                   +add eax, ebx
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
    // 00a35619  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x00a3561b:
    // 00a3561b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a3561d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a3561f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35621  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a35623  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35624  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35625  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35626  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35627(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35627  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35628  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a3562a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3562b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3562c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3562d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3562e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a35631  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a35633  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a35635  81fa00200000           +cmp edx, 0x2000
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
    // 00a3563b  7c05                   -jl 0xa35642
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35642;
    }
    // 00a3563d  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a35642:
    // 00a35642  b9c8cba300             -mov ecx, 0xa3cbc8
    cpu.ecx = 10734536 /*0xa3cbc8*/;
    // 00a35647  eb2e                   -jmp 0xa35677
    goto L_0x00a35677;
L_0x00a35649:
    // 00a35649  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a3564e  7422                   -je 0xa35672
    if (cpu.flags.zf)
    {
        goto L_0x00a35672;
    }
    // 00a35650  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a35654  668945ec               -mov word ptr [ebp - 0x14], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a35658  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a3565b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a3565e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35661  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a35663  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35665  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a35668  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a3566a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a3566c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a3566e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35670  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a35672:
    // 00a35672  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a35674  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a35677:
    // 00a35677  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a35679  7fce                   -jg 0xa35649
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35649;
    }
    // 00a3567b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a3567e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3567f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35680  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35681  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35682  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3567b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a3567b;
    // 00a35627  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35628  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a3562a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3562b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3562c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3562d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3562e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a35631  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a35633  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a35635  81fa00200000           +cmp edx, 0x2000
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
    // 00a3563b  7c05                   -jl 0xa35642
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35642;
    }
    // 00a3563d  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a35642:
    // 00a35642  b9c8cba300             -mov ecx, 0xa3cbc8
    cpu.ecx = 10734536 /*0xa3cbc8*/;
    // 00a35647  eb2e                   -jmp 0xa35677
    goto L_0x00a35677;
L_0x00a35649:
    // 00a35649  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a3564e  7422                   -je 0xa35672
    if (cpu.flags.zf)
    {
        goto L_0x00a35672;
    }
    // 00a35650  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a35654  668945ec               -mov word ptr [ebp - 0x14], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a35658  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a3565b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a3565e  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35661  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a35663  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35665  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a35668  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a3566a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a3566c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a3566e  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35670  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a35672:
    // 00a35672  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a35674  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a35677:
    // 00a35677  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a35679  7fce                   -jg 0xa35649
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35649;
    }
L_entry_0x00a3567b:
    // 00a3567b  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a3567e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3567f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35680  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35681  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35682  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35684(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35684  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35685  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35687  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35688  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35689  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3568a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3568b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a3568e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a35690  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a35692  74e7                   -je 0xa3567b
    if (cpu.flags.zf)
    {
        return sub_a3567b(app, cpu);
    }
    // 00a35694  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a35696  9b                     -wait 
    /*nothing*/;
    // 00a35697  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a3569a  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3569b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a3569d  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a356a0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a356a5  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 00a356aa  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a356ab  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a356ae  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a356af  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a356b1  66895dec               -mov word ptr [ebp - 0x14], bx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 00a356b5  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00a356ba  897de4                 -mov dword ptr [ebp - 0x1c], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a356bd  895de8                 -mov dword ptr [ebp - 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a356c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a356c2  7d1b                   -jge 0xa356df
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a356df;
    }
    // 00a356c4  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a356c7  f7da                   +neg edx
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
    // 00a356c9  e859ffffff             -call 0xa35627
    cpu.esp -= 4;
    sub_a35627(app, cpu);
    if (cpu.terminate) return;
    // 00a356ce  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a356d0  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a356d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a356d5  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a356d7  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a356d9  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a356db  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a356dd  eb17                   -jmp 0xa356f6
    goto L_0x00a356f6;
L_0x00a356df:
    // 00a356df  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a356e2  e840ffffff             -call 0xa35627
    cpu.esp -= 4;
    sub_a35627(app, cpu);
    if (cpu.terminate) return;
    // 00a356e7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a356e9  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a356ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a356ee  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a356f0  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a356f2  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a356f4  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a356f6:
    // 00a356f6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a356f8  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 00a356fb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a356fc  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a356ff  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35700  e976ffffff             -jmp 0xa3567b
    return sub_a3567b(app, cpu);
}

/* align: skip  */
void sub_a35705(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35705  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35706  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35707  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a35709  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a3570b  81fa00100000           +cmp edx, 0x1000
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
    // 00a35711  7e12                   -jle 0xa35725
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35725;
    }
    // 00a35713  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 00a35718  e867ffffff             -call 0xa35684
    cpu.esp -= 4;
    sub_a35684(app, cpu);
    if (cpu.terminate) return;
    // 00a3571d  81eb00100000           +sub ebx, 0x1000
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
    // 00a35723  eb18                   -jmp 0xa3573d
    goto L_0x00a3573d;
L_0x00a35725:
    // 00a35725  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 00a3572b  7d10                   -jge 0xa3573d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3573d;
    }
    // 00a3572d  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 00a35732  e84dffffff             -call 0xa35684
    cpu.esp -= 4;
    sub_a35684(app, cpu);
    if (cpu.terminate) return;
    // 00a35737  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x00a3573d:
    // 00a3573d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a3573f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35741  e83effffff             -call 0xa35684
    cpu.esp -= 4;
    sub_a35684(app, cpu);
    if (cpu.terminate) return;
    // 00a35746  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35747  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35748  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: 8bc0f257a3002e58a3000058a3001e58a300f257a300 */
void sub_a3575f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a3575f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35760  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35762  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35763  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35764  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35765  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a3576b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3576d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a3576f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a35772  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a35774  9b                     -wait 
    /*nothing*/;
    // 00a35775  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a35778  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35779  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a3577c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a3577f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a35784  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35785  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a35788  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35789  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a35790  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a35794  668945d4               -mov word ptr [ebp - 0x2c], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a35798  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a3579b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a3579e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 00a357a0  8945cc                 -mov dword ptr [ebp - 0x34], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a357a3  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a357a7  7407                   -je 0xa357b0
    if (cpu.flags.zf)
    {
        goto L_0x00a357b0;
    }
    // 00a357a9  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a357b0:
    // 00a357b0  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a357b4  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a357bb  c7462000000000         -mov dword ptr [esi + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a357c2  c7462400000000         -mov dword ptr [esi + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a357c9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a357cc  c7462800000000         -mov dword ptr [esi + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a357d3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a357d5  c7461800000000         -mov dword ptr [esi + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a357dc  e85f100000             -call 0xa36840
    cpu.esp -= 4;
    sub_a36840(app, cpu);
    if (cpu.terminate) return;
    // 00a357e1  83f804                 +cmp eax, 4
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
    // 00a357e4  0f8749010000           -ja 0xa35933
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a35933;
    }
    // 00a357ea  2eff24854b57a300       -jmp dword ptr cs:[eax*4 + 0xa3574b]
    cpu.ip = *app->getMemory<x86::reg32>(10704715 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a357f2:
    // 00a357f2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a357f9:
    // 00a357f9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a357fb  e933010000             -jmp 0xa35933
    goto L_0x00a35933;
  case 0x00a35800:
    // 00a35800  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35803  c6006e                 -mov byte ptr [eax], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a35806  c6400161               -mov byte ptr [eax + 1], 0x61
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a3580a  c640026e               -mov byte ptr [eax + 2], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a3580e:
    // 00a3580e  c6400300               -mov byte ptr [eax + 3], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a35812  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a35819  e970030000             -jmp 0xa35b8e
    return sub_a35b8e(app, cpu);
  case 0x00a3581e:
    // 00a3581e  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35821  c60069                 -mov byte ptr [eax], 0x69
    *app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a35824  c640016e               -mov byte ptr [eax + 1], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a35828  c6400266               -mov byte ptr [eax + 2], 0x66
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a3582c  ebe0                   -jmp 0xa3580e
    goto L_0x00a3580e;
  case 0x00a3582e:
    // 00a3582e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35830  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a35834  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a3583a  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a35840  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a35845  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a35847  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a3584a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a3584c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a3584f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a35851  0f84dc000000           -je 0xa35933
    if (cpu.flags.zf)
    {
        goto L_0x00a35933;
    }
    // 00a35857  7d0f                   -jge 0xa35868
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35868;
    }
    // 00a35859  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a3585b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a3585e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a35861  f7d9                   +neg ecx
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
    // 00a35863  e9bf000000             -jmp 0xa35927
    goto L_0x00a35927;
L_0x00a35868:
    // 00a35868  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a3586b  6681fa1940             +cmp dx, 0x4019
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
    // 00a35870  7287                   -jb 0xa357f9
    if (cpu.flags.cf)
    {
        goto L_0x00a357f9;
    }
    // 00a35872  750d                   -jne 0xa35881
    if (!cpu.flags.zf)
    {
        goto L_0x00a35881;
    }
    // 00a35874  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3587b  0f8278ffffff           -jb 0xa357f9
    if (cpu.flags.cf)
    {
        goto L_0x00a357f9;
    }
L_0x00a35881:
    // 00a35881  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a35884  663d3440               +cmp ax, 0x4034
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
    // 00a35888  7220                   -jb 0xa358aa
    if (cpu.flags.cf)
    {
        goto L_0x00a358aa;
    }
    // 00a3588a  0f8594000000           -jne 0xa35924
    if (!cpu.flags.zf)
    {
        goto L_0x00a35924;
    }
    // 00a35890  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a35893  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a35899  720f                   -jb 0xa358aa
    if (cpu.flags.cf)
    {
        goto L_0x00a358aa;
    }
    // 00a3589b  0f8583000000           -jne 0xa35924
    if (!cpu.flags.zf)
    {
        goto L_0x00a35924;
    }
    // 00a358a1  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a358a8  737a                   -jae 0xa35924
    if (!cpu.flags.cf)
    {
        goto L_0x00a35924;
    }
L_0x00a358aa:
    // 00a358aa  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a358af  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a358b2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a358b5  66895dbc               -mov word ptr [ebp - 0x44], bx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a358b9  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a358be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a358c0  895db8                 -mov dword ptr [ebp - 0x48], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a358c3  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358c6  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a358c9  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a358cb  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a358cd  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a358cf  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a358d1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358d4  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358d7  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a358da  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a358dc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358dd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358de  9b                     -wait 
    /*nothing*/;
    // 00a358df  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a358e2  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358e3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358e4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a358e7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358e8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a358eb  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358ec  db5c2404               +fistp dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a358f0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a358f3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358f4  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a358f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358f8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a358fb  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358fc  db3a                   +fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a358fe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a35901  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a35904  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a35906  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a35908  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a3590a  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a3590c  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a3590f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a35912  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35915  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a3591a  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a3591c  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a3591e  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35920  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a35922  eb0f                   -jmp 0xa35933
    goto L_0x00a35933;
L_0x00a35924:
    // 00a35924  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a35927:
    // 00a35927  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a35929  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a3592c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a3592e  e8d2fdffff             -call 0xa35705
    cpu.esp -= 4;
    sub_a35705(app, cpu);
    if (cpu.terminate) return;
L_0x00a35933:
    // 00a35933  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a35937  7416                   -je 0xa3594f
    if (cpu.flags.zf)
    {
        goto L_0x00a3594f;
    }
    // 00a35939  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3593b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3593d  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a35940  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a35943  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a35946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35948  7e0d                   -jle 0xa35957
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35957;
    }
    // 00a3594a  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3594d  eb08                   -jmp 0xa35957
    goto L_0x00a35957;
L_0x00a3594f:
    // 00a3594f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a35951  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a35954  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a35957:
    // 00a35957  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a3595a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a3595f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a35962  7405                   -je 0xa35969
    if (cpu.flags.zf)
    {
        goto L_0x00a35969;
    }
    // 00a35964  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a35969:
    // 00a35969  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a3596d  7402                   -je 0xa35971
    if (cpu.flags.zf)
    {
        goto L_0x00a35971;
    }
    // 00a3596f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a35971:
    // 00a35971  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35974  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a35977  39d8                   +cmp eax, ebx
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
    // 00a35979  7d03                   -jge 0xa3597e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3597e;
    }
    // 00a3597b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a3597e:
    // 00a3597e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a35985  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a35987  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a3598d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a35993  8945d8                 -mov dword ptr [ebp - 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a35996  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35998  8945dc                 -mov dword ptr [ebp - 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00a3599b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a3599e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a359a0  0f8ee8000000           -jle 0xa35a8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a35a8e(app, cpu);
    }
    // 00a359a6  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a359a9  895de8                 -mov dword ptr [ebp - 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a359ac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a359ae  7572                   -jne 0xa35a22
    if (!cpu.flags.zf)
    {
        goto L_0x00a35a22;
    }
    // 00a359b0  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a359b6  0f84d2000000           -je 0xa35a8e
    if (cpu.flags.zf)
    {
        return sub_a35a8e(app, cpu);
    }
    // 00a359bc  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359bf  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a359c1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c3  9b                     -wait 
    /*nothing*/;
    // 00a359c4  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a359c7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359c8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c9  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a359cc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359cd  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a359d0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359d1  db5c2404               -fistp dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a359d5  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a359d8  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359d9  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359da  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a359dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a359de  7e42                   -jle 0xa35a22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35a22;
    }
    // 00a359e0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a359e3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359e6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359e7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a359ea  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359eb  db3a                   -fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a359ed  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a359f0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359f3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a359f5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a359f7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a359f9  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a359fb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a35a00  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a35a05  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a35a08  668945c8               -mov word ptr [ebp - 0x38], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a35a0c  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a35a0f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a35a11  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35a14  8945c0                 -mov dword ptr [ebp - 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a35a17  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35a1a  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a35a1c  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a35a1e  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35a20  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a35a22:
    // 00a35a22  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a35a25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a35a27  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a35a2a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35a2b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a2c  e802000000             -call 0xa35a33
    cpu.esp -= 4;
    sub_a35a33(app, cpu);
    if (cpu.terminate) return;
    // 00a35a31  eb45                   -jmp 0xa35a78
    return sub_a35a78(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a3599b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x00a3599b;
    // 00a3575f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35760  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35762  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35763  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35764  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35765  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a3576b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3576d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a3576f  895de0                 -mov dword ptr [ebp - 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a35772  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a35774  9b                     -wait 
    /*nothing*/;
    // 00a35775  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a35778  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35779  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a3577c  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a3577f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a35784  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35785  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a35788  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35789  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a35790  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a35794  668945d4               -mov word ptr [ebp - 0x2c], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a35798  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a3579b  8945d0                 -mov dword ptr [ebp - 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a3579e  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 00a357a0  8945cc                 -mov dword ptr [ebp - 0x34], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a357a3  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a357a7  7407                   -je 0xa357b0
    if (cpu.flags.zf)
    {
        goto L_0x00a357b0;
    }
    // 00a357a9  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a357b0:
    // 00a357b0  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a357b4  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a357bb  c7462000000000         -mov dword ptr [esi + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a357c2  c7462400000000         -mov dword ptr [esi + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a357c9  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a357cc  c7462800000000         -mov dword ptr [esi + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a357d3  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a357d5  c7461800000000         -mov dword ptr [esi + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a357dc  e85f100000             -call 0xa36840
    cpu.esp -= 4;
    sub_a36840(app, cpu);
    if (cpu.terminate) return;
    // 00a357e1  83f804                 +cmp eax, 4
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
    // 00a357e4  0f8749010000           -ja 0xa35933
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a35933;
    }
    // 00a357ea  2eff24854b57a300       -jmp dword ptr cs:[eax*4 + 0xa3574b]
    cpu.ip = *app->getMemory<x86::reg32>(10704715 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a357f2:
    // 00a357f2  c7461400000000         -mov dword ptr [esi + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a357f9:
    // 00a357f9  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a357fb  e933010000             -jmp 0xa35933
    goto L_0x00a35933;
  case 0x00a35800:
    // 00a35800  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35803  c6006e                 -mov byte ptr [eax], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a35806  c6400161               -mov byte ptr [eax + 1], 0x61
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a3580a  c640026e               -mov byte ptr [eax + 2], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a3580e:
    // 00a3580e  c6400300               -mov byte ptr [eax + 3], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a35812  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a35819  e970030000             -jmp 0xa35b8e
    return sub_a35b8e(app, cpu);
  case 0x00a3581e:
    // 00a3581e  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35821  c60069                 -mov byte ptr [eax], 0x69
    *app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a35824  c640016e               -mov byte ptr [eax + 1], 0x6e
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a35828  c6400266               -mov byte ptr [eax + 2], 0x66
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a3582c  ebe0                   -jmp 0xa3580e
    goto L_0x00a3580e;
  case 0x00a3582e:
    // 00a3582e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35830  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a35834  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a3583a  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a35840  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a35845  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a35847  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a3584a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a3584c  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a3584f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a35851  0f84dc000000           -je 0xa35933
    if (cpu.flags.zf)
    {
        goto L_0x00a35933;
    }
    // 00a35857  7d0f                   -jge 0xa35868
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35868;
    }
    // 00a35859  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a3585b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a3585e  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a35861  f7d9                   +neg ecx
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
    // 00a35863  e9bf000000             -jmp 0xa35927
    goto L_0x00a35927;
L_0x00a35868:
    // 00a35868  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a3586b  6681fa1940             +cmp dx, 0x4019
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
    // 00a35870  7287                   -jb 0xa357f9
    if (cpu.flags.cf)
    {
        goto L_0x00a357f9;
    }
    // 00a35872  750d                   -jne 0xa35881
    if (!cpu.flags.zf)
    {
        goto L_0x00a35881;
    }
    // 00a35874  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3587b  0f8278ffffff           -jb 0xa357f9
    if (cpu.flags.cf)
    {
        goto L_0x00a357f9;
    }
L_0x00a35881:
    // 00a35881  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a35884  663d3440               +cmp ax, 0x4034
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
    // 00a35888  7220                   -jb 0xa358aa
    if (cpu.flags.cf)
    {
        goto L_0x00a358aa;
    }
    // 00a3588a  0f8594000000           -jne 0xa35924
    if (!cpu.flags.zf)
    {
        goto L_0x00a35924;
    }
    // 00a35890  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a35893  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a35899  720f                   -jb 0xa358aa
    if (cpu.flags.cf)
    {
        goto L_0x00a358aa;
    }
    // 00a3589b  0f8583000000           -jne 0xa35924
    if (!cpu.flags.zf)
    {
        goto L_0x00a35924;
    }
    // 00a358a1  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a358a8  737a                   -jae 0xa35924
    if (!cpu.flags.cf)
    {
        goto L_0x00a35924;
    }
L_0x00a358aa:
    // 00a358aa  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a358af  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a358b2  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a358b5  66895dbc               -mov word ptr [ebp - 0x44], bx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a358b9  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a358be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a358c0  895db8                 -mov dword ptr [ebp - 0x48], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a358c3  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358c6  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a358c9  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a358cb  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a358cd  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a358cf  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a358d1  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358d4  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a358d7  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a358da  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a358dc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358dd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358de  9b                     -wait 
    /*nothing*/;
    // 00a358df  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a358e2  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358e3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358e4  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a358e7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358e8  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a358eb  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358ec  db5c2404               +fistp dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a358f0  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a358f3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358f4  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a358f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a358f8  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a358fb  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a358fc  db3a                   +fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a358fe  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a35901  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a35904  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a35906  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a35908  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a3590a  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a3590c  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a3590f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a35912  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35915  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a3591a  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a3591c  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a3591e  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35920  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a35922  eb0f                   -jmp 0xa35933
    goto L_0x00a35933;
L_0x00a35924:
    // 00a35924  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a35927:
    // 00a35927  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a35929  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a3592c  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a3592e  e8d2fdffff             -call 0xa35705
    cpu.esp -= 4;
    sub_a35705(app, cpu);
    if (cpu.terminate) return;
L_0x00a35933:
    // 00a35933  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a35937  7416                   -je 0xa3594f
    if (cpu.flags.zf)
    {
        goto L_0x00a3594f;
    }
    // 00a35939  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3593b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3593d  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a35940  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a35943  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a35946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35948  7e0d                   -jle 0xa35957
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35957;
    }
    // 00a3594a  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3594d  eb08                   -jmp 0xa35957
    goto L_0x00a35957;
L_0x00a3594f:
    // 00a3594f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a35951  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a35954  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a35957:
    // 00a35957  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a3595a  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a3595f  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a35962  7405                   -je 0xa35969
    if (cpu.flags.zf)
    {
        goto L_0x00a35969;
    }
    // 00a35964  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a35969:
    // 00a35969  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a3596d  7402                   -je 0xa35971
    if (cpu.flags.zf)
    {
        goto L_0x00a35971;
    }
    // 00a3596f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a35971:
    // 00a35971  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35974  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a35977  39d8                   +cmp eax, ebx
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
    // 00a35979  7d03                   -jge 0xa3597e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3597e;
    }
    // 00a3597b  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a3597e:
    // 00a3597e  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a35985  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a35987  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a3598d  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a35993  8945d8                 -mov dword ptr [ebp - 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a35996  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35998  8945dc                 -mov dword ptr [ebp - 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x00a3599b:
    // 00a3599b  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a3599e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a359a0  0f8ee8000000           -jle 0xa35a8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a35a8e(app, cpu);
    }
    // 00a359a6  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a359a9  895de8                 -mov dword ptr [ebp - 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a359ac  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a359ae  7572                   -jne 0xa35a22
    if (!cpu.flags.zf)
    {
        goto L_0x00a35a22;
    }
    // 00a359b0  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(*app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a359b6  0f84d2000000           -je 0xa35a8e
    if (cpu.flags.zf)
    {
        return sub_a35a8e(app, cpu);
    }
    // 00a359bc  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359bf  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a359c1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c3  9b                     -wait 
    /*nothing*/;
    // 00a359c4  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a359c7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359c8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359c9  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a359cc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359cd  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a359d0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359d1  db5c2404               -fistp dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a359d5  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a359d8  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359d9  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359da  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a359dc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a359de  7e42                   -jle 0xa35a22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35a22;
    }
    // 00a359e0  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a359e3  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359e6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a359e7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a359ea  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a359eb  db3a                   -fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a359ed  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a359f0  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a359f3  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a359f5  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a359f7  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a359f9  db3b                   -fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a359fb  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a35a00  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a35a05  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a35a08  668945c8               -mov word ptr [ebp - 0x38], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a35a0c  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a35a0f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a35a11  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35a14  8945c0                 -mov dword ptr [ebp - 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a35a17  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a35a1a  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a35a1c  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a35a1e  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a35a20  db3b                   +fstp xword ptr [ebx]
    *app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a35a22:
    // 00a35a22  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a35a25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a35a27  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a35a2a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35a2b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a2c  e802000000             -call 0xa35a33
    cpu.esp -= 4;
    sub_a35a33(app, cpu);
    if (cpu.terminate) return;
    // 00a35a31  eb45                   -jmp 0xa35a78
    return sub_a35a78(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a35a33(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35a33  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a35a38  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a3a  39c8                   +cmp eax, ecx
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
    // 00a35a3c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a3d  7203                   -jb 0xa35a42
    if (cpu.flags.cf)
    {
        goto L_0x00a35a42;
    }
    // 00a35a3f  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a40  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a42:
    // 00a35a42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a43  e801000000             -call 0xa35a49
    cpu.esp -= 4;
    sub_a35a49(app, cpu);
    if (cpu.terminate) return;
    // 00a35a48  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a49  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a35a4e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a50  39c8                   +cmp eax, ecx
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
    // 00a35a52  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a53  7204                   -jb 0xa35a59
    if (cpu.flags.cf)
    {
        goto L_0x00a35a59;
    }
    // 00a35a55  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a56  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a59:
    // 00a35a59  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a5a  e801000000             -call 0xa35a60
    cpu.esp -= 4;
    sub_a35a60(app, cpu);
    if (cpu.terminate) return;
    // 00a35a5f  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a60  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a35a62  38c8                   +cmp al, cl
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
    // 00a35a64  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a66  7204                   -jb 0xa35a6c
    if (cpu.flags.cf)
    {
        goto L_0x00a35a6c;
    }
    // 00a35a68  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a6a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a35a6c:
    // 00a35a6c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a6f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a71  8803                   -mov byte ptr [ebx], al
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a35a73  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a74  8823                   -mov byte ptr [ebx], ah
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a35a76  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35a60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a35a60;
    // 00a35a33  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a35a38  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a3a  39c8                   +cmp eax, ecx
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
    // 00a35a3c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a3d  7203                   -jb 0xa35a42
    if (cpu.flags.cf)
    {
        goto L_0x00a35a42;
    }
    // 00a35a3f  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a40  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a42:
    // 00a35a42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a43  e801000000             -call 0xa35a49
    cpu.esp -= 4;
    sub_a35a49(app, cpu);
    if (cpu.terminate) return;
    // 00a35a48  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a49  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a35a4e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a50  39c8                   +cmp eax, ecx
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
    // 00a35a52  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a53  7204                   -jb 0xa35a59
    if (cpu.flags.cf)
    {
        goto L_0x00a35a59;
    }
    // 00a35a55  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a56  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a59:
    // 00a35a59  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a5a  e801000000             -call 0xa35a60
    cpu.esp -= 4;
    sub_a35a60(app, cpu);
    if (cpu.terminate) return;
    // 00a35a5f  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a35a60:
    // 00a35a60  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a35a62  38c8                   +cmp al, cl
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
    // 00a35a64  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a66  7204                   -jb 0xa35a6c
    if (cpu.flags.cf)
    {
        goto L_0x00a35a6c;
    }
    // 00a35a68  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a6a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a35a6c:
    // 00a35a6c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a6f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a71  8803                   -mov byte ptr [ebx], al
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a35a73  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a74  8823                   -mov byte ptr [ebx], ah
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a35a76  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35a49(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a35a49;
    // 00a35a33  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a35a38  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a3a  39c8                   +cmp eax, ecx
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
    // 00a35a3c  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a3d  7203                   -jb 0xa35a42
    if (cpu.flags.cf)
    {
        goto L_0x00a35a42;
    }
    // 00a35a3f  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a40  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a42:
    // 00a35a42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a43  e801000000             -call 0xa35a49
    cpu.esp -= 4;
    sub_a35a49(app, cpu);
    if (cpu.terminate) return;
    // 00a35a48  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a35a49:
    // 00a35a49  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a35a4e  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35a50  39c8                   +cmp eax, ecx
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
    // 00a35a52  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a53  7204                   -jb 0xa35a59
    if (cpu.flags.cf)
    {
        goto L_0x00a35a59;
    }
    // 00a35a55  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a35a56  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a35a59:
    // 00a35a59  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35a5a  e801000000             -call 0xa35a60
    cpu.esp -= 4;
    sub_a35a60(app, cpu);
    if (cpu.terminate) return;
    // 00a35a5f  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a60  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a35a62  38c8                   +cmp al, cl
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
    // 00a35a64  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a66  7204                   -jb 0xa35a6c
    if (cpu.flags.cf)
    {
        goto L_0x00a35a6c;
    }
    // 00a35a68  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a35a6a  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a35a6c:
    // 00a35a6c  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a6f  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a35a71  8803                   -mov byte ptr [ebx], al
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a35a73  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a74  8823                   -mov byte ptr [ebx], ah
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a35a76  43                     -inc ebx
    (cpu.ebx)++;
    // 00a35a77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35a78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35a78  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a79  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35a7a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a35a7c  8803                   -mov byte ptr [ebx], al
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a35a7e  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 00a35a81  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a35a84  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a35a86  8955dc                 -mov dword ptr [ebp - 0x24], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00a35a89  e90dffffff             -jmp 0xa3599b
    return sub_a3599b(app, cpu);
}

/* align: skip  */
void sub_a35a8e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35a8e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a35a91  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a35a97  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a35a9a:
    // 00a35a9a  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35a9d  7505                   -jne 0xa35aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00a35aa4;
    }
    // 00a35a9f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35aa0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35aa1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35aa2  ebf6                   -jmp 0xa35a9a
    goto L_0x00a35a9a;
L_0x00a35aa4:
    // 00a35aa4  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35aa7  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a35aa9  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a35aac  740a                   -je 0xa35ab8
    if (cpu.flags.zf)
    {
        goto L_0x00a35ab8;
    }
    // 00a35aae  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a35ab1  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a35ab4  01df                   +add edi, ebx
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
    // 00a35ab6  eb15                   -jmp 0xa35acd
    goto L_0x00a35acd;
L_0x00a35ab8:
    // 00a35ab8  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a35abb  7410                   -je 0xa35acd
    if (cpu.flags.zf)
    {
        goto L_0x00a35acd;
    }
    // 00a35abd  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a35ac0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a35ac2  7e03                   -jle 0xa35ac7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35ac7;
    }
    // 00a35ac4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35ac5  eb02                   -jmp 0xa35ac9
    goto L_0x00a35ac9;
L_0x00a35ac7:
    // 00a35ac7  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a35ac9:
    // 00a35ac9  41                     -inc ecx
    (cpu.ecx)++;
    // 00a35aca  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a35acd:
    // 00a35acd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35acf  0f8c65000000           -jl 0xa35b3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b3a;
    }
    // 00a35ad5  39c7                   +cmp edi, eax
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
    // 00a35ad7  7e02                   -jle 0xa35adb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35adb;
    }
    // 00a35ad9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a35adb:
    // 00a35adb  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a35ae0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a35ae4  7405                   -je 0xa35aeb
    if (cpu.flags.zf)
    {
        goto L_0x00a35aeb;
    }
    // 00a35ae6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a35aeb:
    // 00a35aeb  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a35aef  7402                   -je 0xa35af3
    if (cpu.flags.zf)
    {
        goto L_0x00a35af3;
    }
    // 00a35af1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a35af3:
    // 00a35af3  39df                   +cmp edi, ebx
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
    // 00a35af5  7e03                   -jle 0xa35afa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35afa;
    }
    // 00a35af7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a35afa:
    // 00a35afa  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a35afe  39f8                   +cmp eax, edi
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
    // 00a35b00  7e0a                   -jle 0xa35b0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35b0c;
    }
    // 00a35b02  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35b06  7204                   -jb 0xa35b0c
    if (cpu.flags.cf)
    {
        goto L_0x00a35b0c;
    }
    // 00a35b08  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a35b0c:
    // 00a35b0c  897de4                 -mov dword ptr [ebp - 0x1c], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a35b0f  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a35b12:
    // 00a35b12  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35b15  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a35b16  48                     -dec eax
    (cpu.eax)--;
    // 00a35b17  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a35b1a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a35b1c  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35b1f  38fb                   +cmp bl, bh
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
    // 00a35b21  7503                   -jne 0xa35b26
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b26;
    }
    // 00a35b23  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35b24  ebec                   -jmp 0xa35b12
    goto L_0x00a35b12;
L_0x00a35b26:
    // 00a35b26  80ff39                 +cmp bh, 0x39
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
    // 00a35b29  7506                   -jne 0xa35b31
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b31;
    }
    // 00a35b2b  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a35b2d  fec7                   -inc bh
    (cpu.bh)++;
    // 00a35b2f  8838                   -mov byte ptr [eax], bh
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a35b31:
    // 00a35b31  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35b35  7d03                   -jge 0xa35b3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35b3a;
    }
    // 00a35b37  4a                     -dec edx
    (cpu.edx)--;
    // 00a35b38  47                     -inc edi
    (cpu.edi)++;
    // 00a35b39  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a35b3a:
    // 00a35b3a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35b3c  7f18                   -jg 0xa35b56
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35b56;
    }
    // 00a35b3e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a35b43  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a35b45  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35b47  888568ffffff           -mov byte ptr [ebp - 0x98], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a35b4d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a35b53  894e14                 -mov dword ptr [esi + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a35b56:
    // 00a35b56  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35b59  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a35b5c  7514                   -jne 0xa35b72
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b72;
    }
    // 00a35b5e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a35b61  741e                   -je 0xa35b81
    if (cpu.flags.zf)
    {
        goto L_0x00a35b81;
    }
    // 00a35b63  83f9fc                 +cmp ecx, -4
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
    // 00a35b66  7c04                   -jl 0xa35b6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b6c;
    }
    // 00a35b68  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35b6a  7c06                   -jl 0xa35b72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b72;
    }
L_0x00a35b6c:
    // 00a35b6c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a35b70  740f                   -je 0xa35b81
    if (cpu.flags.zf)
    {
        goto L_0x00a35b81;
    }
L_0x00a35b72:
    // 00a35b72  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35b75  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35b76  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35b78  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35b7a  e822000000             -call 0xa35ba1
    cpu.esp -= 4;
    sub_a35ba1(app, cpu);
    if (cpu.terminate) return;
    // 00a35b7f  eb0d                   -jmp 0xa35b8e
    goto L_0x00a35b8e;
L_0x00a35b81:
    // 00a35b81  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35b84  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35b85  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35b87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35b89  e831020000             -call 0xa35dbf
    cpu.esp -= 4;
    sub_a35dbf(app, cpu);
    if (cpu.terminate) return;
L_0x00a35b8e:
    // 00a35b8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35b90  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35b94  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35b95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a35b98  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b99  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35b9c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35ba0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35b8e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a35b8e;
    // 00a35a8e  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a35a91  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a35a97  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a35a9a:
    // 00a35a9a  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35a9d  7505                   -jne 0xa35aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00a35aa4;
    }
    // 00a35a9f  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35aa0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35aa1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35aa2  ebf6                   -jmp 0xa35a9a
    goto L_0x00a35a9a;
L_0x00a35aa4:
    // 00a35aa4  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35aa7  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a35aa9  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a35aac  740a                   -je 0xa35ab8
    if (cpu.flags.zf)
    {
        goto L_0x00a35ab8;
    }
    // 00a35aae  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a35ab1  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a35ab4  01df                   +add edi, ebx
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
    // 00a35ab6  eb15                   -jmp 0xa35acd
    goto L_0x00a35acd;
L_0x00a35ab8:
    // 00a35ab8  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a35abb  7410                   -je 0xa35acd
    if (cpu.flags.zf)
    {
        goto L_0x00a35acd;
    }
    // 00a35abd  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a35ac0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a35ac2  7e03                   -jle 0xa35ac7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35ac7;
    }
    // 00a35ac4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35ac5  eb02                   -jmp 0xa35ac9
    goto L_0x00a35ac9;
L_0x00a35ac7:
    // 00a35ac7  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a35ac9:
    // 00a35ac9  41                     -inc ecx
    (cpu.ecx)++;
    // 00a35aca  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a35acd:
    // 00a35acd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35acf  0f8c65000000           -jl 0xa35b3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b3a;
    }
    // 00a35ad5  39c7                   +cmp edi, eax
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
    // 00a35ad7  7e02                   -jle 0xa35adb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35adb;
    }
    // 00a35ad9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a35adb:
    // 00a35adb  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a35ae0  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a35ae4  7405                   -je 0xa35aeb
    if (cpu.flags.zf)
    {
        goto L_0x00a35aeb;
    }
    // 00a35ae6  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a35aeb:
    // 00a35aeb  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a35aef  7402                   -je 0xa35af3
    if (cpu.flags.zf)
    {
        goto L_0x00a35af3;
    }
    // 00a35af1  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a35af3:
    // 00a35af3  39df                   +cmp edi, ebx
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
    // 00a35af5  7e03                   -jle 0xa35afa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35afa;
    }
    // 00a35af7  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a35afa:
    // 00a35afa  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a35afe  39f8                   +cmp eax, edi
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
    // 00a35b00  7e0a                   -jle 0xa35b0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35b0c;
    }
    // 00a35b02  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35b06  7204                   -jb 0xa35b0c
    if (cpu.flags.cf)
    {
        goto L_0x00a35b0c;
    }
    // 00a35b08  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a35b0c:
    // 00a35b0c  897de4                 -mov dword ptr [ebp - 0x1c], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a35b0f  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a35b12:
    // 00a35b12  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35b15  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a35b16  48                     -dec eax
    (cpu.eax)--;
    // 00a35b17  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a35b1a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a35b1c  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35b1f  38fb                   +cmp bl, bh
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
    // 00a35b21  7503                   -jne 0xa35b26
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b26;
    }
    // 00a35b23  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a35b24  ebec                   -jmp 0xa35b12
    goto L_0x00a35b12;
L_0x00a35b26:
    // 00a35b26  80ff39                 +cmp bh, 0x39
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
    // 00a35b29  7506                   -jne 0xa35b31
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b31;
    }
    // 00a35b2b  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a35b2d  fec7                   -inc bh
    (cpu.bh)++;
    // 00a35b2f  8838                   -mov byte ptr [eax], bh
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a35b31:
    // 00a35b31  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35b35  7d03                   -jge 0xa35b3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35b3a;
    }
    // 00a35b37  4a                     -dec edx
    (cpu.edx)--;
    // 00a35b38  47                     -inc edi
    (cpu.edi)++;
    // 00a35b39  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a35b3a:
    // 00a35b3a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35b3c  7f18                   -jg 0xa35b56
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35b56;
    }
    // 00a35b3e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a35b43  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a35b45  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35b47  888568ffffff           -mov byte ptr [ebp - 0x98], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a35b4d  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a35b53  894e14                 -mov dword ptr [esi + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a35b56:
    // 00a35b56  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35b59  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a35b5c  7514                   -jne 0xa35b72
    if (!cpu.flags.zf)
    {
        goto L_0x00a35b72;
    }
    // 00a35b5e  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a35b61  741e                   -je 0xa35b81
    if (cpu.flags.zf)
    {
        goto L_0x00a35b81;
    }
    // 00a35b63  83f9fc                 +cmp ecx, -4
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
    // 00a35b66  7c04                   -jl 0xa35b6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b6c;
    }
    // 00a35b68  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35b6a  7c06                   -jl 0xa35b72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35b72;
    }
L_0x00a35b6c:
    // 00a35b6c  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a35b70  740f                   -je 0xa35b81
    if (cpu.flags.zf)
    {
        goto L_0x00a35b81;
    }
L_0x00a35b72:
    // 00a35b72  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35b75  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35b76  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35b78  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35b7a  e822000000             -call 0xa35ba1
    cpu.esp -= 4;
    sub_a35ba1(app, cpu);
    if (cpu.terminate) return;
    // 00a35b7f  eb0d                   -jmp 0xa35b8e
    goto L_0x00a35b8e;
L_0x00a35b81:
    // 00a35b81  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35b84  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35b85  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a35b87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a35b89  e831020000             -call 0xa35dbf
    cpu.esp -= 4;
    sub_a35dbf(app, cpu);
    if (cpu.terminate) return;
L_0x00a35b8e:
L_entry_0x00a35b8e:
    // 00a35b8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35b90  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35b94  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35b95  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a35b98  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b99  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35b9c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35b9f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35ba0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a35ba1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a35ba1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35ba2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35ba4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35ba5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35ba6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a35ba9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35baa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35bab  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35bac  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a35bae  41                     -inc ecx
    (cpu.ecx)++;
    // 00a35baf  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a35bb2  894de8                 -mov dword ptr [ebp - 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a35bb5  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a35bb8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35bba  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a35bbd  7425                   -je 0xa35be4
    if (cpu.flags.zf)
    {
        goto L_0x00a35be4;
    }
    // 00a35bbf  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35bc2  7d0c                   -jge 0xa35bd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35bd0;
    }
    // 00a35bc4  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35bc7  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a35bcb  7503                   -jne 0xa35bd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a35bd0;
    }
    // 00a35bcd  895df4                 -mov dword ptr [ebp - 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a35bd0:
    // 00a35bd0  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35bd3  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35bd6  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a35bd8  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a35bdb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35bdd  7d05                   -jge 0xa35be4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35be4;
    }
    // 00a35bdf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35be1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a35be4:
    // 00a35be4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35be7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a35be9  0f8fa4000000           -jg 0xa35c93
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35c93;
    }
    // 00a35bef  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35bf2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a35bf6  7526                   -jne 0xa35c1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a35c1e;
    }
    // 00a35bf8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35bfb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a35bfd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a35bff  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c02  42                     -inc edx
    (cpu.edx)++;
    // 00a35c03  c60630                 -mov byte ptr [esi], 0x30
    *app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a35c06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35c08  7f09                   -jg 0xa35c13
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35c13;
    }
    // 00a35c0a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c0d  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a35c11  740b                   -je 0xa35c1e
    if (cpu.flags.zf)
    {
        goto L_0x00a35c1e;
    }
L_0x00a35c13:
    // 00a35c13  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c16  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a35c18  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35c1a  42                     -inc edx
    (cpu.edx)++;
    // 00a35c1b  c6072e                 -mov byte ptr [edi], 0x2e
    *app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a35c1e:
    // 00a35c1e  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c21  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a35c24  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35c27  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c2a  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a35c2c  39fe                   +cmp esi, edi
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
    // 00a35c2e  7e0a                   -jle 0xa35c3a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35c3a;
    }
    // 00a35c30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a35c32  897de8                 -mov dword ptr [ebp - 0x18], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a35c35  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a35c37  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a35c3a:
    // 00a35c3a  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c3d  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35c40  897718                 -mov dword ptr [edi + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a35c43  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a35c45  897720                 -mov dword ptr [edi + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a35c48  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a35c4a  894f20                 -mov dword ptr [edi + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a35c4d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c50  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a35c52  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a35c55  39fb                   +cmp ebx, edi
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
    // 00a35c57  7e02                   -jle 0xa35c5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35c5b;
    }
    // 00a35c59  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a35c5b:
    // 00a35c5b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c5e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35c61  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35c63  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a35c65  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35c66  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35c68  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35c6a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35c6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35c6d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35c70  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35c72  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35c74  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35c77  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35c79  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35c7a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35c7b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c7e  895e24                 -mov dword ptr [esi + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a35c81  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c84  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35c86  29de                   +sub esi, ebx
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
    // 00a35c88  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c8b  897328                 -mov dword ptr [ebx + 0x28], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a35c8e  e90d010000             -jmp 0xa35da0
    goto L_0x00a35da0;
L_0x00a35c93:
    // 00a35c93  39f3                   +cmp ebx, esi
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
    // 00a35c95  7d70                   -jge 0xa35d07
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35d07;
    }
    // 00a35c97  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35c9a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c9d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35c9f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35ca0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35ca2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35ca4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35ca5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35ca7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35caa  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35cac  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35cae  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35cb1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35cb3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35cb4  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35cb5  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cb8  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a35cbb  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35cbe  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35cc0  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35cc2  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cc5  897320                 -mov dword ptr [ebx + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a35cc8  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35ccb  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35cce  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35cd1  895e18                 -mov dword ptr [esi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a35cd4  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a35cd7  7520                   -jne 0xa35cf9
    if (!cpu.flags.zf)
    {
        goto L_0x00a35cf9;
    }
    // 00a35cd9  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35cdd  7f05                   -jg 0xa35ce4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35ce4;
    }
    // 00a35cdf  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a35ce2  7415                   -je 0xa35cf9
    if (cpu.flags.zf)
    {
        goto L_0x00a35cf9;
    }
L_0x00a35ce4:
    // 00a35ce4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35ce7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a35ce9  01cb                   +add ebx, ecx
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
    // 00a35ceb  c6032e                 -mov byte ptr [ebx], 0x2e
    *app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a35cee  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cf1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35cf2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a35cf9:
    // 00a35cf9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cfc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35cff  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a35d02  e999000000             -jmp 0xa35da0
    goto L_0x00a35da0;
L_0x00a35d07:
    // 00a35d07  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d0a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a35d0c  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35d0f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35d10  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35d12  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35d14  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35d15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35d17  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35d1a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35d1c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35d1e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35d21  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35d23  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35d24  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35d25  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d28  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35d2b  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a35d2e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a35d30  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a35d32  897718                 -mov dword ptr [edi + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a35d35  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a35d38  7518                   -jne 0xa35d52
    if (!cpu.flags.zf)
    {
        goto L_0x00a35d52;
    }
    // 00a35d3a  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35d3e  7f05                   -jg 0xa35d45
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35d45;
    }
    // 00a35d40  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a35d43  741c                   -je 0xa35d61
    if (cpu.flags.zf)
    {
        goto L_0x00a35d61;
    }
L_0x00a35d45:
    // 00a35d45  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d48  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a35d4a  01c7                   +add edi, eax
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
    // 00a35d4c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35d4d  c6072e                 -mov byte ptr [edi], 0x2e
    *app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a35d50  eb0f                   -jmp 0xa35d61
    goto L_0x00a35d61;
L_0x00a35d52:
    // 00a35d52  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d55  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35d58  7507                   -jne 0xa35d61
    if (!cpu.flags.zf)
    {
        goto L_0x00a35d61;
    }
    // 00a35d5a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a35d61:
    // 00a35d61  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35d64  39cb                   +cmp ebx, ecx
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
    // 00a35d66  7e02                   -jle 0xa35d6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35d6a;
    }
    // 00a35d68  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a35d6a:
    // 00a35d6a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35d6d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a35d70  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d73  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35d75  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a35d77  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35d78  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35d7a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35d7c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35d7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35d7f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35d82  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35d84  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35d86  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35d89  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35d8b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35d8c  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35d8d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d90  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35d92  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a35d95  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35d98  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35d9a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d9d  897320                 -mov dword ptr [ebx + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a35da0:
    // 00a35da0  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a35da3  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00a35da6  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a35da9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35daa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35dab  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35dac  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a35da6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a35da6;
    // 00a35ba1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35ba2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35ba4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35ba5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35ba6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a35ba9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35baa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35bab  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35bac  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a35bae  41                     -inc ecx
    (cpu.ecx)++;
    // 00a35baf  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a35bb2  894de8                 -mov dword ptr [ebp - 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a35bb5  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a35bb8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35bba  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a35bbd  7425                   -je 0xa35be4
    if (cpu.flags.zf)
    {
        goto L_0x00a35be4;
    }
    // 00a35bbf  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35bc2  7d0c                   -jge 0xa35bd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35bd0;
    }
    // 00a35bc4  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35bc7  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a35bcb  7503                   -jne 0xa35bd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a35bd0;
    }
    // 00a35bcd  895df4                 -mov dword ptr [ebp - 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a35bd0:
    // 00a35bd0  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35bd3  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35bd6  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a35bd8  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a35bdb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35bdd  7d05                   -jge 0xa35be4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35be4;
    }
    // 00a35bdf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35be1  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a35be4:
    // 00a35be4  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35be7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a35be9  0f8fa4000000           -jg 0xa35c93
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35c93;
    }
    // 00a35bef  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35bf2  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a35bf6  7526                   -jne 0xa35c1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a35c1e;
    }
    // 00a35bf8  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35bfb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a35bfd  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a35bff  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c02  42                     -inc edx
    (cpu.edx)++;
    // 00a35c03  c60630                 -mov byte ptr [esi], 0x30
    *app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a35c06  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a35c08  7f09                   -jg 0xa35c13
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35c13;
    }
    // 00a35c0a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c0d  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a35c11  740b                   -je 0xa35c1e
    if (cpu.flags.zf)
    {
        goto L_0x00a35c1e;
    }
L_0x00a35c13:
    // 00a35c13  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c16  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a35c18  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35c1a  42                     -inc edx
    (cpu.edx)++;
    // 00a35c1b  c6072e                 -mov byte ptr [edi], 0x2e
    *app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a35c1e:
    // 00a35c1e  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c21  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a35c24  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35c27  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c2a  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a35c2c  39fe                   +cmp esi, edi
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
    // 00a35c2e  7e0a                   -jle 0xa35c3a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35c3a;
    }
    // 00a35c30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a35c32  897de8                 -mov dword ptr [ebp - 0x18], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a35c35  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a35c37  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a35c3a:
    // 00a35c3a  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c3d  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35c40  897718                 -mov dword ptr [edi + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a35c43  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a35c45  897720                 -mov dword ptr [edi + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a35c48  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a35c4a  894f20                 -mov dword ptr [edi + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a35c4d  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c50  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a35c52  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a35c55  39fb                   +cmp ebx, edi
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
    // 00a35c57  7e02                   -jle 0xa35c5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35c5b;
    }
    // 00a35c59  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a35c5b:
    // 00a35c5b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c5e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35c61  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35c63  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a35c65  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35c66  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35c68  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35c6a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35c6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35c6d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35c70  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35c72  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35c74  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35c77  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35c79  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35c7a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35c7b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c7e  895e24                 -mov dword ptr [esi + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a35c81  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35c84  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35c86  29de                   +sub esi, ebx
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
    // 00a35c88  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35c8b  897328                 -mov dword ptr [ebx + 0x28], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a35c8e  e90d010000             -jmp 0xa35da0
    goto L_0x00a35da0;
L_0x00a35c93:
    // 00a35c93  39f3                   +cmp ebx, esi
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
    // 00a35c95  7d70                   -jge 0xa35d07
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35d07;
    }
    // 00a35c97  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35c9a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35c9d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35c9f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35ca0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35ca2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35ca4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35ca5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35ca7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35caa  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35cac  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35cae  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35cb1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35cb3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35cb4  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35cb5  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cb8  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a35cbb  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35cbe  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35cc0  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35cc2  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cc5  897320                 -mov dword ptr [ebx + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a35cc8  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35ccb  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35cce  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a35cd1  895e18                 -mov dword ptr [esi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a35cd4  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a35cd7  7520                   -jne 0xa35cf9
    if (!cpu.flags.zf)
    {
        goto L_0x00a35cf9;
    }
    // 00a35cd9  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35cdd  7f05                   -jg 0xa35ce4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35ce4;
    }
    // 00a35cdf  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a35ce2  7415                   -je 0xa35cf9
    if (cpu.flags.zf)
    {
        goto L_0x00a35cf9;
    }
L_0x00a35ce4:
    // 00a35ce4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35ce7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a35ce9  01cb                   +add ebx, ecx
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
    // 00a35ceb  c6032e                 -mov byte ptr [ebx], 0x2e
    *app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a35cee  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cf1  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35cf2  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a35cf9:
    // 00a35cf9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35cfc  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35cff  895e28                 -mov dword ptr [esi + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a35d02  e999000000             -jmp 0xa35da0
    goto L_0x00a35da0;
L_0x00a35d07:
    // 00a35d07  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d0a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a35d0c  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35d0f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35d10  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35d12  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35d14  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35d15  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35d17  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35d1a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35d1c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35d1e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35d21  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35d23  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35d24  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35d25  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d28  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35d2b  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a35d2e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a35d30  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a35d32  897718                 -mov dword ptr [edi + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a35d35  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a35d38  7518                   -jne 0xa35d52
    if (!cpu.flags.zf)
    {
        goto L_0x00a35d52;
    }
    // 00a35d3a  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35d3e  7f05                   -jg 0xa35d45
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35d45;
    }
    // 00a35d40  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a35d43  741c                   -je 0xa35d61
    if (cpu.flags.zf)
    {
        goto L_0x00a35d61;
    }
L_0x00a35d45:
    // 00a35d45  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d48  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a35d4a  01c7                   +add edi, eax
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
    // 00a35d4c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a35d4d  c6072e                 -mov byte ptr [edi], 0x2e
    *app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a35d50  eb0f                   -jmp 0xa35d61
    goto L_0x00a35d61;
L_0x00a35d52:
    // 00a35d52  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d55  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a35d58  7507                   -jne 0xa35d61
    if (!cpu.flags.zf)
    {
        goto L_0x00a35d61;
    }
    // 00a35d5a  c7471800000000         -mov dword ptr [edi + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a35d61:
    // 00a35d61  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35d64  39cb                   +cmp ebx, ecx
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
    // 00a35d66  7e02                   -jle 0xa35d6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35d6a;
    }
    // 00a35d68  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a35d6a:
    // 00a35d6a  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35d6d  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a35d70  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35d73  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35d75  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a35d77  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35d78  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35d7a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35d7c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35d7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35d7f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35d82  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35d84  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35d86  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35d89  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35d8b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35d8c  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35d8d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d90  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35d92  89561c                 -mov dword ptr [esi + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a35d95  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35d98  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35d9a  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35d9d  897320                 -mov dword ptr [ebx + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a35da0:
    // 00a35da0  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a35da3  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x00a35da6:
    // 00a35da6  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a35da9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35daa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35dab  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35dac  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a35dbf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a35dbf  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a35dc0  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a35dc2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a35dc3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35dc4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a35dc7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a35dc8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a35dc9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a35dca  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a35dcb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a35dcd  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a35dd0  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35dd3  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a35dd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a35dd8  7f05                   -jg 0xa35ddf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35ddf;
    }
    // 00a35dda  0155ec                 +add dword ptr [ebp - 0x14], edx
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a35ddd  eb0e                   -jmp 0xa35ded
    goto L_0x00a35ded;
L_0x00a35ddf:
    // 00a35ddf  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35de2  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a35de4  895dec                 -mov dword ptr [ebp - 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a35de7  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a35dea  894dec                 -mov dword ptr [ebp - 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x00a35ded:
    // 00a35ded  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35df0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a35df2  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a35df5  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a35df8  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00a35dfb  741b                   -je 0xa35e18
    if (cpu.flags.zf)
    {
        goto L_0x00a35e18;
    }
    // 00a35dfd  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35e00  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35e03  7d03                   -jge 0xa35e08
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35e08;
    }
    // 00a35e05  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x00a35e08:
    // 00a35e08  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35e0b  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a35e0c  895dec                 -mov dword ptr [ebp - 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a35e0f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a35e11  7d05                   -jge 0xa35e18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35e18;
    }
    // 00a35e13  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a35e15  8975ec                 -mov dword ptr [ebp - 0x14], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x00a35e18:
    // 00a35e18  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35e1b  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a35e1e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35e20  7f16                   -jg 0xa35e38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35e38;
    }
    // 00a35e22  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35e25  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35e28  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a35e2b  01d8                   +add eax, ebx
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
    // 00a35e2d  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a35e30  c60030                 -mov byte ptr [eax], 0x30
    *app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00a35e33  e97c000000             -jmp 0xa35eb4
    goto L_0x00a35eb4;
L_0x00a35e38:
    // 00a35e38  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35e3b  897df0                 -mov dword ptr [ebp - 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a35e3e  39d7                   +cmp edi, edx
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
    // 00a35e40  7e03                   -jle 0xa35e45
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35e45;
    }
    // 00a35e42  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x00a35e45:
    // 00a35e45  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35e48  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35e4b  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35e4e  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35e51  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a35e53  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35e56  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35e57  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35e59  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35e5b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35e5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35e5e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35e61  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35e63  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35e65  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35e68  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35e6a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35e6b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35e6c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35e6f  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35e72  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35e75  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00a35e78  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a35e7a  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a35e7c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a35e7f  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00a35e82  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a35e85  897de0                 -mov dword ptr [ebp - 0x20], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00a35e88  39d8                   +cmp eax, ebx
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
    // 00a35e8a  7d28                   -jge 0xa35eb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35eb4;
    }
    // 00a35e8c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35e8f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a35e91  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35e94  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35e96  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a35e9b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a35e9e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35ea1  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35ea4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a35ea6  e89ee3ffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a35eab  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35eae  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a35eb1  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x00a35eb4:
    // 00a35eb4  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35eb7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35eba  894218                 -mov dword ptr [edx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a35ebd  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a35ec1  7520                   -jne 0xa35ee3
    if (!cpu.flags.zf)
    {
        goto L_0x00a35ee3;
    }
    // 00a35ec3  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35ec7  7f09                   -jg 0xa35ed2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a35ed2;
    }
    // 00a35ec9  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35ecc  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a35ed0  7411                   -je 0xa35ee3
    if (cpu.flags.zf)
    {
        goto L_0x00a35ee3;
    }
L_0x00a35ed2:
    // 00a35ed2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35ed5  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35ed8  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a35edb  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a35edd  8975f4                 -mov dword ptr [ebp - 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a35ee0  c6002e                 -mov byte ptr [eax], 0x2e
    *app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x00a35ee3:
    // 00a35ee3  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35ee6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a35ee9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a35eeb  7d25                   -jge 0xa35f12
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35f12;
    }
    // 00a35eed  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35ef0  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35ef3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a35ef5  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a35ef8  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a35efd  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00a35eff  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35f01  895df0                 -mov dword ptr [ebp - 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00a35f04  e840e3ffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a35f09  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a35f0c  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a35f0f  8975f4                 -mov dword ptr [ebp - 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x00a35f12:
    // 00a35f12  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35f15  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a35f17  7e49                   -jle 0xa35f62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a35f62;
    }
    // 00a35f19  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35f1c  7d03                   -jge 0xa35f21
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35f21;
    }
    // 00a35f1e  897de0                 -mov dword ptr [ebp - 0x20], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x00a35f21:
    // 00a35f21  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35f24  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a35f26  7426                   -je 0xa35f4e
    if (cpu.flags.zf)
    {
        goto L_0x00a35f4e;
    }
    // 00a35f28  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35f2b  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f2e  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a35f31  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35f33  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a35f35  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a35f36  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a35f38  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a35f3a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a35f3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a35f3d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a35f40  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a35f42  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a35f44  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a35f47  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a35f49  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a35f4a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a35f4b  015df4                 -add dword ptr [ebp - 0xc], ebx
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a35f4e:
    // 00a35f4e  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35f51  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f54  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a35f57  89421c                 -mov dword ptr [edx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a35f5a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a35f5d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a35f5f  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00a35f62:
    // 00a35f62  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35f65  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00a35f69  7416                   -je 0xa35f81
    if (cpu.flags.zf)
    {
        goto L_0x00a35f81;
    }
    // 00a35f6b  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f6e  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35f71  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a35f74  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35f77  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a35f79  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a35f7c  895df4                 -mov dword ptr [ebp - 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a35f7f  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a35f81:
    // 00a35f81  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f84  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a35f87  40                     -inc eax
    (cpu.eax)++;
    // 00a35f88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a35f8a  7c0f                   -jl 0xa35f9b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35f9b;
    }
    // 00a35f8c  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f8f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a35f92  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35f95  c604022b               -mov byte ptr [edx + eax], 0x2b
    *app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a35f99  eb14                   -jmp 0xa35faf
    goto L_0x00a35faf;
L_0x00a35f9b:
    // 00a35f9b  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a35f9e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a35fa0  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a35fa3  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a35fa5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a35fa8  897ddc                 -mov dword ptr [ebp - 0x24], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00a35fab  c604022d               -mov byte ptr [edx + eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x00a35faf:
    // 00a35faf  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35fb2  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a35fb5  83fb03                 +cmp ebx, 3
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
    // 00a35fb8  773e                   -ja 0xa35ff8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a35ff8;
    }
    // 00a35fba  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a35fbc  2eff2485af5da300       -jmp dword ptr cs:[eax*4 + 0xa35daf]
    cpu.ip = *app->getMemory<x86::reg32>(10706351 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a35fc4:
    // 00a35fc4  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35fcb  7d26                   -jge 0xa35ff3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a35ff3;
    }
    // 00a35fcd  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00a35fd2  eb24                   -jmp 0xa35ff8
    goto L_0x00a35ff8;
  case 0x00a35fd4:
    // 00a35fd4  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35fd8  7c05                   -jl 0xa35fdf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35fdf;
    }
    // 00a35fda  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x00a35fdf:
L_0x00a35fdf:
    // 00a35fdf  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35fe3  7c05                   -jl 0xa35fea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35fea;
    }
    // 00a35fe5  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x00a35fea:
L_0x00a35fea:
    // 00a35fea  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a35ff1  7c05                   -jl 0xa35ff8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a35ff8;
    }
L_0x00a35ff3:
    // 00a35ff3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x00a35ff8:
    // 00a35ff8  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a35ffb  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a35ffe  83fb04                 +cmp ebx, 4
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
    // 00a36001  7c4b                   -jl 0xa3604e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a3604e;
    }
    // 00a36003  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a36005  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a36008  897df0                 -mov dword ptr [ebp - 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a3600b  3de8030000             +cmp eax, 0x3e8
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
    // 00a36010  7c26                   -jl 0xa36038
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a36038;
    }
    // 00a36012  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36014  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 00a36019  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a3601c  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a3601e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a36021  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36023  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00a36026  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a36028  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a3602b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a3602d  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a36030  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a36033  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36035  8955dc                 -mov dword ptr [ebp - 0x24], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a36038:
    // 00a36038  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a3603b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a3603e  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a36041  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a36044  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a36046  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a36049  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a3604c  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a3604e:
    // 00a3604e  83fb03                 +cmp ebx, 3
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
    // 00a36051  7c49                   -jl 0xa3609c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a3609c;
    }
    // 00a36053  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a36055  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a36058  897df0                 -mov dword ptr [ebp - 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a3605b  83f864                 +cmp eax, 0x64
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
    // 00a3605e  7c26                   -jl 0xa36086
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a36086;
    }
    // 00a36060  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36062  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00a36067  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a3606a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a3606c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a3606f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36071  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a36074  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a36076  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a36079  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a3607b  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a3607e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a36081  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36083  8955dc                 -mov dword ptr [ebp - 0x24], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a36086:
    // 00a36086  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a36089  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a3608c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3608f  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a36092  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a36094  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a36097  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a3609a  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a3609c:
    // 00a3609c  83fb02                 +cmp ebx, 2
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
    // 00a3609f  7c43                   -jl 0xa360e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a360e4;
    }
    // 00a360a1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a360a3  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a360a6  897df0                 -mov dword ptr [ebp - 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a360a9  83f80a                 +cmp eax, 0xa
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
    // 00a360ac  7c20                   -jl 0xa360ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a360ce;
    }
    // 00a360ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a360b0  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a360b5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a360b8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a360ba  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a360bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a360bf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a360c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a360c4  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a360c7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a360c9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a360cb  8955dc                 -mov dword ptr [ebp - 0x24], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a360ce:
    // 00a360ce  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a360d1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a360d4  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a360d7  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a360da  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a360dc  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a360df  895df4                 -mov dword ptr [ebp - 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a360e2  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a360e4:
    // 00a360e4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a360e7  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a360ea  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a360ed  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a360f0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a360f2  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a360f5  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a360f7  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a360fa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a360fc  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00a360ff  29c2                   +sub edx, eax
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
    // 00a36101  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a36104  895024                 -mov dword ptr [eax + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00a36107  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00a3610a  8975f4                 -mov dword ptr [ebp - 0xc], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a3610d  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a36110  e991fcffff             -jmp 0xa35da6
    return sub_a35da6(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a36115(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36115  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36116  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a36118  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36119  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3611a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3611b  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00a3611e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a36120  895de8                 -mov dword ptr [ebp - 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a36123  8945e0                 -mov dword ptr [ebp - 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a36126:
    // 00a36126  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a36128  80fa20                 +cmp dl, 0x20
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
    // 00a3612b  740a                   -je 0xa36137
    if (cpu.flags.zf)
    {
        goto L_0x00a36137;
    }
    // 00a3612d  80fa09                 +cmp dl, 9
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
    // 00a36130  7208                   -jb 0xa3613a
    if (cpu.flags.cf)
    {
        goto L_0x00a3613a;
    }
    // 00a36132  80fa0d                 +cmp dl, 0xd
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
    // 00a36135  7703                   -ja 0xa3613a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3613a;
    }
L_0x00a36137:
    // 00a36137  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a36138  ebec                   -jmp 0xa36126
    goto L_0x00a36126;
L_0x00a3613a:
    // 00a3613a  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3613d  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a3613f  80fa2b                 +cmp dl, 0x2b
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
    // 00a36142  7407                   -je 0xa3614b
    if (cpu.flags.zf)
    {
        goto L_0x00a3614b;
    }
    // 00a36144  80fa2d                 +cmp dl, 0x2d
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
    // 00a36147  7504                   -jne 0xa3614d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3614d;
    }
    // 00a36149  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a3614b:
    // 00a3614b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a3614d:
    // 00a3614d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a3614f  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 00a36151  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x00a36154:
    // 00a36154  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a36156  40                     -inc eax
    (cpu.eax)++;
    // 00a36157  80fa2e                 +cmp dl, 0x2e
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
    // 00a3615a  750a                   -jne 0xa36166
    if (!cpu.flags.zf)
    {
        goto L_0x00a36166;
    }
    // 00a3615c  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a3615f  752d                   -jne 0xa3618e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3618e;
    }
    // 00a36161  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a36164  ebee                   -jmp 0xa36154
    goto L_0x00a36154;
L_0x00a36166:
    // 00a36166  80fa30                 +cmp dl, 0x30
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
    // 00a36169  7223                   -jb 0xa3618e
    if (cpu.flags.cf)
    {
        goto L_0x00a3618e;
    }
    // 00a3616b  80fa39                 +cmp dl, 0x39
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
    // 00a3616e  771e                   -ja 0xa3618e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3618e;
    }
    // 00a36170  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a36173  7403                   -je 0xa36178
    if (cpu.flags.zf)
    {
        goto L_0x00a36178;
    }
    // 00a36175  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x00a36178:
    // 00a36178  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 00a3617a  80fe30                 +cmp dh, 0x30
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
    // 00a3617d  740a                   -je 0xa36189
    if (cpu.flags.zf)
    {
        goto L_0x00a36189;
    }
    // 00a3617f  83fb13                 +cmp ebx, 0x13
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
    // 00a36182  7d04                   -jge 0xa36188
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a36188;
    }
    // 00a36184  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x00a36188:
    // 00a36188  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a36189:
    // 00a36189  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a3618c  ebc6                   -jmp 0xa36154
    goto L_0x00a36154;
L_0x00a3618e:
    // 00a3618e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a36190  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a36193  0f8465000000           -je 0xa361fe
    if (cpu.flags.zf)
    {
        goto L_0x00a361fe;
    }
    // 00a36199  80fa65                 +cmp dl, 0x65
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
    // 00a3619c  7405                   -je 0xa361a3
    if (cpu.flags.zf)
    {
        goto L_0x00a361a3;
    }
    // 00a3619e  80fa45                 +cmp dl, 0x45
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
    // 00a361a1  7557                   -jne 0xa361fa
    if (!cpu.flags.zf)
    {
        goto L_0x00a361fa;
    }
L_0x00a361a3:
    // 00a361a3  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00a361a6  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a361a8  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a361ab  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a361ae  80fd2b                 +cmp ch, 0x2b
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
    // 00a361b1  7408                   -je 0xa361bb
    if (cpu.flags.zf)
    {
        goto L_0x00a361bb;
    }
    // 00a361b3  80fd2d                 +cmp ch, 0x2d
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
    // 00a361b6  7505                   -jne 0xa361bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a361bd;
    }
    // 00a361b8  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a361bb:
    // 00a361bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a361bd:
    // 00a361bd  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00a361c0:
    // 00a361c0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a361c2  80fa30                 +cmp dl, 0x30
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
    // 00a361c5  7222                   -jb 0xa361e9
    if (cpu.flags.cf)
    {
        goto L_0x00a361e9;
    }
    // 00a361c7  80fa39                 +cmp dl, 0x39
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
    // 00a361ca  771d                   -ja 0xa361e9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a361e9;
    }
    // 00a361cc  81fee8030000           +cmp esi, 0x3e8
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
    // 00a361d2  7d0f                   -jge 0xa361e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a361e3;
    }
    // 00a361d4  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a361d7  8975ec                 -mov dword ptr [ebp - 0x14], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00a361da  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 00a361dd  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00a361e0  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00a361e3:
    // 00a361e3  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a361e6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a361e7  ebd7                   -jmp 0xa361c0
    goto L_0x00a361c0;
L_0x00a361e9:
    // 00a361e9  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00a361ec  7402                   -je 0xa361f0
    if (cpu.flags.zf)
    {
        goto L_0x00a361f0;
    }
    // 00a361ee  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x00a361f0:
    // 00a361f0  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a361f3  7506                   -jne 0xa361fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a361fb;
    }
    // 00a361f5  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a361f8  eb01                   -jmp 0xa361fb
    goto L_0x00a361fb;
L_0x00a361fa:
    // 00a361fa  48                     -dec eax
    (cpu.eax)--;
L_0x00a361fb:
    // 00a361fb  8945e0                 -mov dword ptr [ebp - 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a361fe:
    // 00a361fe  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36202  7408                   -je 0xa3620c
    if (cpu.flags.zf)
    {
        goto L_0x00a3620c;
    }
    // 00a36204  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a36207  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a3620a  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a3620c:
    // 00a3620c  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00a3620f  83fb13                 +cmp ebx, 0x13
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
    // 00a36212  7e0a                   -jle 0xa3621e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3621e;
    }
    // 00a36214  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 00a36217  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a36219  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x00a3621e:
    // 00a3621e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a36220  7e0b                   -jle 0xa3622d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3622d;
    }
    // 00a36222  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a36227  7504                   -jne 0xa3622d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3622d;
    }
    // 00a36229  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a3622a  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a3622b  ebf1                   -jmp 0xa3621e
    goto L_0x00a3621e;
L_0x00a3622d:
    // 00a3622d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a3622f  7511                   -jne 0xa36242
    if (!cpu.flags.zf)
    {
        goto L_0x00a36242;
    }
    // 00a36231  66c747080000           -mov word ptr [edi + 8], 0
    *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a36237  895f04                 -mov dword ptr [edi + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a3623a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a3623c  891f                   -mov dword ptr [edi], ebx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a3623e  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a36240  eb5f                   -jmp 0xa362a1
    goto L_0x00a362a1;
L_0x00a36242:
    // 00a36242  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a36244  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a36247  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 00a3624b  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a3624e  e83d060000             -call 0xa36890
    cpu.esp -= 4;
    sub_a36890(app, cpu);
    if (cpu.terminate) return;
    // 00a36253  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a36255  740a                   -je 0xa36261
    if (cpu.flags.zf)
    {
        goto L_0x00a36261;
    }
    // 00a36257  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a3625a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a3625c  e8a4f4ffff             -call 0xa35705
    cpu.esp -= 4;
    sub_a35705(app, cpu);
    if (cpu.terminate) return;
L_0x00a36261:
    // 00a36261  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00a36264  7404                   -je 0xa3626a
    if (cpu.flags.zf)
    {
        goto L_0x00a3626a;
    }
    // 00a36266  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a3626a:
    // 00a3626a  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a3626d  66894708               -mov word ptr [edi + 8], ax
    *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00a36271  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a36274  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a36277  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a3627a  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00a3627c  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 00a36280  3d34010000             +cmp eax, 0x134
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
    // 00a36285  7e07                   -jle 0xa3628e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a3628e;
    }
    // 00a36287  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a3628c  eb13                   -jmp 0xa362a1
    goto L_0x00a362a1;
L_0x00a3628e:
    // 00a3628e  3dccfeffff             +cmp eax, 0xfffffecc
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
    // 00a36293  7d07                   -jge 0xa3629c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3629c;
    }
    // 00a36295  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a3629a  eb05                   -jmp 0xa362a1
    goto L_0x00a362a1;
L_0x00a3629c:
    // 00a3629c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a362a1:
    // 00a362a1  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a362a4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a362a5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a362a6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a362a7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a362a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a362a9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a362a9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a362aa  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a362ac  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a362ad  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a362b0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a362b2  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a362b5  e85bfeffff             -call 0xa36115
    cpu.esp -= 4;
    sub_a36115(app, cpu);
    if (cpu.terminate) return;
    // 00a362ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a362bc  7508                   -jne 0xa362c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a362c6;
    }
    // 00a362be  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00a362c1:
    // 00a362c1  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a362c4  eb59                   -jmp 0xa3631f
    goto L_0x00a3631f;
L_0x00a362c6:
    // 00a362c6  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a362c9  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a362cc  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a362d1  3dff430000             +cmp eax, 0x43ff
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
    // 00a362d6  7c27                   -jl 0xa362ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a362ff;
    }
    // 00a362d8  e86b060000             -call 0xa36948
    cpu.esp -= 4;
    sub_a36948(app, cpu);
    if (cpu.terminate) return;
    // 00a362dd  f645f180               +test byte ptr [ebp - 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-15) /* -0xf */) & 128 /*0x80*/));
    // 00a362e1  740d                   -je 0xa362f0
    if (cpu.flags.zf)
    {
        goto L_0x00a362f0;
    }
    // 00a362e3  dd0594c0a300           +fld qword ptr [0xa3c094]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(x86::reg32(10731668) /* 0xa3c094 */)));
    // 00a362e9  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a362eb  dd5df4                 +fstp qword ptr [ebp - 0xc]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a362ee  eb2f                   -jmp 0xa3631f
    goto L_0x00a3631f;
L_0x00a362f0:
    // 00a362f0  a194c0a300             -mov eax, dword ptr [0xa3c094]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731668) /* 0xa3c094 */);
    // 00a362f5  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a362f8  a198c0a300             -mov eax, dword ptr [0xa3c098]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10731672) /* 0xa3c098 */);
    // 00a362fd  ebc2                   -jmp 0xa362c1
    goto L_0x00a362c1;
L_0x00a362ff:
    // 00a362ff  3dcd3b0000             +cmp eax, 0x3bcd
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
    // 00a36304  7d0f                   -jge 0xa36315
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a36315;
    }
    // 00a36306  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a36308  e83b060000             -call 0xa36948
    cpu.esp -= 4;
    sub_a36948(app, cpu);
    if (cpu.terminate) return;
    // 00a3630d  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a36310  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00a36313  eb0a                   -jmp 0xa3631f
    goto L_0x00a3631f;
L_0x00a36315:
    // 00a36315  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a36318  8d45e8                 -lea eax, [ebp - 0x18]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a3631b  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a3631d  dd1a                   -fstp qword ptr [edx]
    *app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a3631f:
    // 00a3631f  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00a36322  8d65fc                 -lea esp, [ebp - 4]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a36325  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36326  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36327  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36328(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36328  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36329  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3632a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3632b  8b0d54cca300           -mov ecx, dword ptr [0xa3cc54]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a36331  a158cca300             -mov eax, dword ptr [0xa3cc58]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a36336  3b05b4cca300           +cmp eax, dword ptr [0xa3ccb4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10734772) /* 0xa3ccb4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3633c  7304                   -jae 0xa36342
    if (!cpu.flags.cf)
    {
        goto L_0x00a36342;
    }
L_0x00a3633e:
    // 00a3633e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a36340  eb21                   -jmp 0xa36363
    goto L_0x00a36363;
L_0x00a36342:
    // 00a36342  8b1d58cca300           -mov ebx, dword ptr [0xa3cc58]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a36348  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a3634a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3634c  c1e302                 +shl ebx, 2
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
    // 00a3634f  eb09                   -jmp 0xa3635a
    goto L_0x00a3635a;
L_0x00a36351:
    // 00a36351  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36355  74e7                   -je 0xa3633e
    if (cpu.flags.zf)
    {
        goto L_0x00a3633e;
    }
    // 00a36357  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a3635a:
    // 00a3635a  39d8                   +cmp eax, ebx
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
    // 00a3635c  7cf3                   -jl 0xa36351
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a36351;
    }
    // 00a3635e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a36363:
    // 00a36363  890d54cca300           -mov dword ptr [0xa3cc54], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */) = cpu.ecx;
    // 00a36369  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3636a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3636b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3636c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3636d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3636d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3636e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3636f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36370  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36371  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36373  ff1598cca300           -call dword ptr [0xa3cc98]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734744) /* 0xa3cc98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36379  8b0d58cca300           -mov ecx, dword ptr [0xa3cc58]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a3637f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a36381  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36383  c1e102                 +shl ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00a36386  eb20                   -jmp 0xa363a8
    goto L_0x00a363a8;
L_0x00a36388:
    // 00a36388  8b1554cca300           -mov edx, dword ptr [0xa3cc54]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a3638e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a36390  833a00                 +cmp dword ptr [edx], 0
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
    // 00a36393  750f                   -jne 0xa363a4
    if (!cpu.flags.zf)
    {
        goto L_0x00a363a4;
    }
    // 00a36395  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a36397  ff159ccca300           -call dword ptr [0xa3cc9c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734748) /* 0xa3cc9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3639d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a3639f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363a0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363a2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a363a4:
    // 00a363a4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a363a7  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a363a8:
    // 00a363a8  39c8                   +cmp eax, ecx
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
    // 00a363aa  7cdc                   -jl 0xa36388
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a36388;
    }
    // 00a363ac  8b1558cca300           -mov edx, dword ptr [0xa3cc58]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a363b2  42                     -inc edx
    (cpu.edx)++;
    // 00a363b3  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a363b8  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a363bb  e823060000             -call 0xa369e3
    cpu.esp -= 4;
    sub_a369e3(app, cpu);
    if (cpu.terminate) return;
    // 00a363c0  8b1558cca300           -mov edx, dword ptr [0xa3cc58]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a363c6  a354cca300             -mov dword ptr [0xa3cc54], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */) = cpu.eax;
    // 00a363cb  893490                 -mov dword ptr [eax + edx*4], esi
    *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 00a363ce  42                     -inc edx
    (cpu.edx)++;
    // 00a363cf  891558cca300           -mov dword ptr [0xa3cc58], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */) = cpu.edx;
    // 00a363d5  ff159ccca300           -call dword ptr [0xa3cc9c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734748) /* 0xa3cc9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a363db  a158cca300             -mov eax, dword ptr [0xa3cc58]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a363e0  48                     -dec eax
    (cpu.eax)--;
    // 00a363e1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a363e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a363e6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a363e6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a363e7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a363e8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a363e9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a363ea  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a363ec  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a363ee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a363f0  0f8c90000000           -jl 0xa36486
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a36486;
    }
    // 00a363f6  ff1598cca300           -call dword ptr [0xa3cc98]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734744) /* 0xa3cc98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a363fc  83fa01                 +cmp edx, 1
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
    // 00a363ff  7209                   -jb 0xa3640a
    if (cpu.flags.cf)
    {
        goto L_0x00a3640a;
    }
    // 00a36401  7610                   -jbe 0xa36413
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a36413;
    }
    // 00a36403  83fa02                 +cmp edx, 2
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
    // 00a36406  7410                   -je 0xa36418
    if (cpu.flags.zf)
    {
        goto L_0x00a36418;
    }
    // 00a36408  eb18                   -jmp 0xa36422
    goto L_0x00a36422;
L_0x00a3640a:
    // 00a3640a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a3640c  7514                   -jne 0xa36422
    if (!cpu.flags.zf)
    {
        goto L_0x00a36422;
    }
    // 00a3640e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3640f  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a36411  eb08                   -jmp 0xa3641b
    goto L_0x00a3641b;
L_0x00a36413:
    // 00a36413  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36414  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a36416  eb03                   -jmp 0xa3641b
    goto L_0x00a3641b;
L_0x00a36418:
    // 00a36418  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36419  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x00a3641b:
    // 00a3641b  2eff15a8a9a300         -call dword ptr cs:[0xa3a9a8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725800) /* 0xa3a9a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36422:
    // 00a36422  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a36424  8b1558cca300           -mov edx, dword ptr [0xa3cc58]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a3642a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00a3642d  39d6                   +cmp esi, edx
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
    // 00a3642f  7d0a                   -jge 0xa3643b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a3643b;
    }
    // 00a36431  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a36436  893c01                 -mov dword ptr [ecx + eax], edi
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edi;
    // 00a36439  eb45                   -jmp 0xa36480
    goto L_0x00a36480;
L_0x00a3643b:
    // 00a3643b  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a36440  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a36443  e89b050000             -call 0xa369e3
    cpu.esp -= 4;
    sub_a369e3(app, cpu);
    if (cpu.terminate) return;
    // 00a36448  8b1d58cca300           -mov ebx, dword ptr [0xa3cc58]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */);
    // 00a3644e  a354cca300             -mov dword ptr [0xa3cc54], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */) = cpu.eax;
    // 00a36453  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36455  c1e002                 +shl eax, 2
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
    // 00a36458  eb11                   -jmp 0xa3646b
    goto L_0x00a3646b;
L_0x00a3645a:
    // 00a3645a  8b1554cca300           -mov edx, dword ptr [0xa3cc54]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a36460  43                     -inc ebx
    (cpu.ebx)++;
    // 00a36461  c7040200000000         -mov dword ptr [edx + eax], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a36468  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a3646b:
    // 00a3646b  39c8                   +cmp eax, ecx
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
    // 00a3646d  7ceb                   -jl 0xa3645a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a3645a;
    }
    // 00a3646f  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a36474  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a36476  46                     -inc esi
    (cpu.esi)++;
    // 00a36477  893c90                 -mov dword ptr [eax + edx*4], edi
    *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.edi;
    // 00a3647a  893558cca300           -mov dword ptr [0xa3cc58], esi
    *app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */) = cpu.esi;
L_0x00a36480:
    // 00a36480  ff159ccca300           -call dword ptr [0xa3cc9c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734748) /* 0xa3cc9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36486:
    // 00a36486  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36487  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36488  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36489  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3648a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3648b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3648b  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3648c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3648e  ff1598cca300           -call dword ptr [0xa3cc98]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734744) /* 0xa3cc98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36494  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a36496  7e17                   -jle 0xa364af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a364af;
    }
    // 00a36498  3b1558cca300           +cmp edx, dword ptr [0xa3cc58]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10734680) /* 0xa3cc58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3649e  7d0f                   -jge 0xa364af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a364af;
    }
    // 00a364a0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a364a2  8b1554cca300           -mov edx, dword ptr [0xa3cc54]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a364a8  c7048200000000         -mov dword ptr [edx + eax*4], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
L_0x00a364af:
    // 00a364af  ff159ccca300           -call dword ptr [0xa3cc9c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734748) /* 0xa3cc9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a364b5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a364b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a364b7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a364b7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a364b8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a364b9  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a364bb  2eff157ca9a300         -call dword ptr cs:[0xa3a97c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725756) /* 0xa3a97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a364c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a364c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a364c6  7405                   -je 0xa364cd
    if (cpu.flags.zf)
    {
        goto L_0x00a364cd;
    }
    // 00a364c8  83f8ff                 +cmp eax, -1
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
    // 00a364cb  7505                   -jne 0xa364d2
    if (!cpu.flags.zf)
    {
        goto L_0x00a364d2;
    }
L_0x00a364cd:
    // 00a364cd  e844000000             -call 0xa36516
    cpu.esp -= 4;
    sub_a36516(app, cpu);
    if (cpu.terminate) return;
L_0x00a364d2:
    // 00a364d2  e896feffff             -call 0xa3636d
    cpu.esp -= 4;
    sub_a3636d(app, cpu);
    if (cpu.terminate) return;
    // 00a364d7  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a364d9  2eff157ca9a300         -call dword ptr cs:[0xa3a97c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725756) /* 0xa3a97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a364e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a364e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a364e4  7405                   -je 0xa364eb
    if (cpu.flags.zf)
    {
        goto L_0x00a364eb;
    }
    // 00a364e6  83f8ff                 +cmp eax, -1
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
    // 00a364e9  7505                   -jne 0xa364f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a364f0;
    }
L_0x00a364eb:
    // 00a364eb  e826000000             -call 0xa36516
    cpu.esp -= 4;
    sub_a36516(app, cpu);
    if (cpu.terminate) return;
L_0x00a364f0:
    // 00a364f0  e878feffff             -call 0xa3636d
    cpu.esp -= 4;
    sub_a3636d(app, cpu);
    if (cpu.terminate) return;
    // 00a364f5  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00a364f7  2eff157ca9a300         -call dword ptr cs:[0xa3a97c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725756) /* 0xa3a97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a364fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36500  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36502  7405                   -je 0xa36509
    if (cpu.flags.zf)
    {
        goto L_0x00a36509;
    }
    // 00a36504  83f8ff                 +cmp eax, -1
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
    // 00a36507  7505                   -jne 0xa3650e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3650e;
    }
L_0x00a36509:
    // 00a36509  e808000000             -call 0xa36516
    cpu.esp -= 4;
    sub_a36516(app, cpu);
    if (cpu.terminate) return;
L_0x00a3650e:
    // 00a3650e  e85afeffff             -call 0xa3636d
    cpu.esp -= 4;
    sub_a3636d(app, cpu);
    if (cpu.terminate) return;
    // 00a36513  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36514  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36516(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36516  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36517  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36518  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3651a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3651c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3651e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a36520  2eff1528a9a300         -call dword ptr cs:[0xa3a928]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725672) /* 0xa3a928 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36527  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36529  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3652b  750d                   -jne 0xa3653a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3653a;
    }
    // 00a3652d  8b155ccca300           -mov edx, dword ptr [0xa3cc5c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734684) /* 0xa3cc5c */);
    // 00a36533  42                     -inc edx
    (cpu.edx)++;
    // 00a36534  89155ccca300           -mov dword ptr [0xa3cc5c], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734684) /* 0xa3cc5c */) = cpu.edx;
L_0x00a3653a:
    // 00a3653a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a3653c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3653d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3653e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3653f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3653f  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36545  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00a3654a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3654b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3654b  a11cd9a300             -mov eax, dword ptr [0xa3d91c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10737948) /* 0xa3d91c */);
    // 00a36550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a36550;
    // 00a3654b  a11cd9a300             -mov eax, dword ptr [0xa3d91c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10737948) /* 0xa3d91c */);
L_entry_0x00a36550:
    // 00a36550  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
