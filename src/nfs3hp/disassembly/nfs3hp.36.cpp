#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ed800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed800  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed801  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed802  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed803  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ed805:
    // 004ed805  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ed807  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004ed809  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed80a  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed80d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ed812  3d1c027688             +cmp eax, 0x8876021c
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
    // 004ed817  74ec                   -je 0x4ed805
    if (cpu.flags.zf)
    {
        goto L_0x004ed805;
    }
    // 004ed819  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed81a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed81b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed81c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ed820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed820  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed821  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed822  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ed823  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed826  8bac2480000000         -mov ebp, dword ptr [esp + 0x80]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004ed82d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ed82f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ed831  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ed833  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004ed835  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004ed83a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed83b  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ed83f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed840  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ed842  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed845  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004ed849  0f8575000000           -jne 0x4ed8c4
    if (!cpu.flags.zf)
    {
        goto L_0x004ed8c4;
    }
    // 004ed84f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ed851  7406                   -je 0x4ed859
    if (cpu.flags.zf)
    {
        goto L_0x004ed859;
    }
    // 004ed853  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ed857  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004ed859:
    // 004ed859  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ed85b  7406                   -je 0x4ed863
    if (cpu.flags.zf)
    {
        goto L_0x004ed863;
    }
    // 004ed85d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ed861  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004ed863:
    // 004ed863  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004ed867  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ed869  7406                   -je 0x4ed871
    if (cpu.flags.zf)
    {
        goto L_0x004ed871;
    }
    // 004ed86b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ed86f  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x004ed871:
    // 004ed871  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ed873  7407                   -je 0x4ed87c
    if (cpu.flags.zf)
    {
        goto L_0x004ed87c;
    }
    // 004ed875  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ed879  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x004ed87c:
    // 004ed87c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ed87e  740f                   -je 0x4ed88f
    if (cpu.flags.zf)
    {
        goto L_0x004ed88f;
    }
    // 004ed880  837c245410             +cmp dword ptr [esp + 0x54], 0x10
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
    // 004ed885  7411                   -je 0x4ed898
    if (cpu.flags.zf)
    {
        goto L_0x004ed898;
    }
    // 004ed887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed889  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004ed88d  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004ed88f:
    // 004ed88f  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed892  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed893  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed894  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed895  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ed898:
    // 004ed898  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004ed89c  e8dfdfffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004ed8a1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ed8a3  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004ed8a7  e8d4dfffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004ed8ac  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ed8ae  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004ed8b2  e8c9dfffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004ed8b7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ed8b9  8933                   -mov dword ptr [ebx], esi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004ed8bb  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed8be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed8bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed8c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed8c1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ed8c4:
    // 004ed8c4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ed8c6  7406                   -je 0x4ed8ce
    if (cpu.flags.zf)
    {
        goto L_0x004ed8ce;
    }
    // 004ed8c8  c70600000000           -mov dword ptr [esi], 0
    *app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x004ed8ce:
    // 004ed8ce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ed8d0  7406                   -je 0x4ed8d8
    if (cpu.flags.zf)
    {
        goto L_0x004ed8d8;
    }
    // 004ed8d2  c70700000000           -mov dword ptr [edi], 0
    *app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x004ed8d8:
    // 004ed8d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ed8da  7406                   -je 0x4ed8e2
    if (cpu.flags.zf)
    {
        goto L_0x004ed8e2;
    }
    // 004ed8dc  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x004ed8e2:
    // 004ed8e2  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004ed8e6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ed8e8  7406                   -je 0x4ed8f0
    if (cpu.flags.zf)
    {
        goto L_0x004ed8f0;
    }
    // 004ed8ea  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x004ed8f0:
    // 004ed8f0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ed8f2  749b                   -je 0x4ed88f
    if (cpu.flags.zf)
    {
        goto L_0x004ed88f;
    }
    // 004ed8f4  c7450000000000         -mov dword ptr [ebp], 0
    *app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 004ed8fb  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004ed8fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed8ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed900  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed901  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4ed910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed910  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed911  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed912  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed915  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ed917  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed918  6878b95600             -push 0x56b978
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5683576 /*0x56b978*/;
    cpu.esp -= 4;
    // 004ed91d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ed91f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed920  ff11                   -call dword ptr [ecx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed922  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ed925  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed927  7506                   -jne 0x4ed92f
    if (!cpu.flags.zf)
    {
        goto L_0x004ed92f;
    }
    // 004ed929  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed92c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed92d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed92e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed92f:
    // 004ed92f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed930  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed932  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ed934  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed935  ff9094000000           -call dword ptr [eax + 0x94]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed93b  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed93f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed943  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed944  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ed946  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed949  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed94a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed94d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed94e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed94f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ed950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed950  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ed951  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed952  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed955  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ed957  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed958  6878b95600             -push 0x56b978
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5683576 /*0x56b978*/;
    cpu.esp -= 4;
    // 004ed95d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ed95f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed960  ff11                   -call dword ptr [ecx]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed962  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ed965  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ed967  7506                   -jne 0x4ed96f
    if (!cpu.flags.zf)
    {
        goto L_0x004ed96f;
    }
    // 004ed969  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed96c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed96d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed96e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ed96f:
    // 004ed96f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed970  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed972  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ed974  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ed975  ff9098000000           -call dword ptr [eax + 0x98]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed97b  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed97f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ed983  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ed984  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ed986  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed989  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed98a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ed98d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed98e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed98f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ed990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ed990  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed991  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ed992  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 004ed995  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ed997  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 004ed99c  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004ed9a3  895c2468               -mov dword ptr [esp + 0x68], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 004ed9a7  89542464               -mov dword ptr [esp + 0x64], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004ed9ab  89442450               -mov dword ptr [esp + 0x50], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004ed9af  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ed9b1  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004ed9b8  8954246c               -mov dword ptr [esp + 0x6c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 004ed9bc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ed9be  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004ed9c2  89442470               -mov dword ptr [esp + 0x70], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004ed9c6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ed9c8  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004ed9cb  e860deffff             -call 0x4eb830
    cpu.esp -= 4;
    sub_4eb830(app, cpu);
    if (cpu.terminate) return;
    // 004ed9d0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ed9d2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed9d3  6800040001             -push 0x1000400
    *app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 004ed9d8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed9da  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ed9dc  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ed9e0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ed9e1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 004ed9e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ed9e4  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ed9e7  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004ed9eb  750d                   -jne 0x4ed9fa
    if (!cpu.flags.zf)
    {
        goto L_0x004ed9fa;
    }
    // 004ed9ed  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ed9f2  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 004ed9f5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed9f6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ed9f7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004ed9fa:
    // 004ed9fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ed9fc  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 004ed9ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eda00  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eda01  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4eda10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eda10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eda11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eda12  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eda13  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004eda19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eda1b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004eda1d  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 004eda24  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004eda2b  8bac249c000000         -mov ebp, dword ptr [esp + 0x9c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004eda32  897c2468               -mov dword ptr [esp + 0x68], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 004eda36  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004eda38  8bbc2484000000         -mov edi, dword ptr [esp + 0x84]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004eda3f  89542464               -mov dword ptr [esp + 0x64], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 004eda43  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eda45  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004eda4c  897c246c               -mov dword ptr [esp + 0x6c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 004eda50  89542478               -mov dword ptr [esp + 0x78], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 004eda54  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004eda5b  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004eda62  89542474               -mov dword ptr [esp + 0x74], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004eda66  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004eda6d  896c2470               -mov dword ptr [esp + 0x70], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 004eda71  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004eda73  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 004eda7a  89942480000000         -mov dword ptr [esp + 0x80], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 004eda81  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004eda88  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004eda8a  bb00000001             -mov ebx, 0x1000000
    cpu.ebx = 16777216 /*0x1000000*/;
    // 004eda8f  8954247c               -mov dword ptr [esp + 0x7c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 004eda93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eda95  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eda97  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004eda9a  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 004edaa1  83fa03                 +cmp edx, 3
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
    // 004edaa4  0f859f000000           -jne 0x4edb49
    if (!cpu.flags.zf)
    {
        goto L_0x004edb49;
    }
    // 004edaaa  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x004edaaf:
    // 004edaaf  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004edab1  7403                   -je 0x4edab6
    if (cpu.flags.zf)
    {
        goto L_0x004edab6;
    }
    // 004edab3  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004edab6:
    // 004edab6  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004edab8  7403                   -je 0x4edabd
    if (cpu.flags.zf)
    {
        goto L_0x004edabd;
    }
    // 004edaba  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004edabd:
    // 004edabd  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004edabf  7403                   -je 0x4edac4
    if (cpu.flags.zf)
    {
        goto L_0x004edac4;
    }
    // 004edac1  80cf80                 -or bh, 0x80
    cpu.bh |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004edac4:
    // 004edac4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004edac6  7424                   -je 0x4edaec
    if (cpu.flags.zf)
    {
        goto L_0x004edaec;
    }
    // 004edac8  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004edacd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004edacf  e8382cffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004edad4  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004edad9  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004edadc  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004edadf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004edae1  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004edae5  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x004edaec:
    // 004edaec  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004edaf0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004edaf2  e839ddffff             -call 0x4eb830
    cpu.esp -= 4;
    sub_4eb830(app, cpu);
    if (cpu.terminate) return;
    // 004edaf7  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004edafb  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 004edb02  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004edb09  e822ddffff             -call 0x4eb830
    cpu.esp -= 4;
    sub_4eb830(app, cpu);
    if (cpu.terminate) return;
    // 004edb0e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004edb0f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edb10  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004edb14  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edb15  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edb16  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004edb1d  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004edb24  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edb25  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004edb2c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004edb2e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edb2f  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004edb32  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 004edb36  7531                   -jne 0x4edb69
    if (!cpu.flags.zf)
    {
        goto L_0x004edb69;
    }
    // 004edb38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004edb3d  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004edb43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb44  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb45  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb46  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x004edb49:
    // 004edb49  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004edb4b  740a                   -je 0x4edb57
    if (cpu.flags.zf)
    {
        goto L_0x004edb57;
    }
    // 004edb4d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004edb52  e958ffffff             -jmp 0x4edaaf
    goto L_0x004edaaf;
L_0x004edb57:
    // 004edb57  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004edb59  0f8450ffffff           -je 0x4edaaf
    if (cpu.flags.zf)
    {
        goto L_0x004edaaf;
    }
    // 004edb5f  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004edb64  e946ffffff             -jmp 0x4edaaf
    goto L_0x004edaaf;
L_0x004edb69:
    // 004edb69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004edb6b  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004edb71  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb72  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb73  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edb74  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4edb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edb80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edb81  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edb82  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edb83  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004edb86  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004edb8a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004edb8e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004edb90  be20b44e00             -mov esi, 0x4eb420
    cpu.esi = 5157920 /*0x4eb420*/;
    // 004edb95  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004edb99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004edb9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004edb9b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004edb9c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004edb9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004edb9f  7502                   -jne 0x4edba3
    if (!cpu.flags.zf)
    {
        goto L_0x004edba3;
    }
    // 004edba1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004edba3:
    // 004edba3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004edba7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004edba9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004edbae  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004edbb1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edbb2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edbb3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edbb4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4edbc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edbc0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edbc1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edbc2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edbc3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004edbc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004edbc6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004edbc9  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004edbcc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004edbd1  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004edbd4  8b4e54                 -mov ecx, dword ptr [esi + 0x54]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004edbd7  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004edbda  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004edbdd  83f910                 +cmp ecx, 0x10
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
    // 004edbe0  0f84be000000           -je 0x4edca4
    if (cpu.flags.zf)
    {
        goto L_0x004edca4;
    }
    // 004edbe6  0fb67e54               -movzx edi, byte ptr [esi + 0x54]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(84) /* 0x54 */));
L_0x004edbea:
    // 004edbea  83ff10                 +cmp edi, 0x10
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
    // 004edbed  0f83d4000000           -jae 0x4edcc7
    if (!cpu.flags.cf)
    {
        goto L_0x004edcc7;
    }
    // 004edbf3  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edbf6  0f8305010000           -jae 0x4edd01
    if (!cpu.flags.cf)
    {
        goto L_0x004edd01;
    }
L_0x004edbfc:
    // 004edbfc  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004edbff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004edc01  0f848f000000           -je 0x4edc96
    if (cpu.flags.zf)
    {
        goto L_0x004edc96;
    }
    // 004edc07  837b1000               +cmp dword ptr [ebx + 0x10], 0
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
    // 004edc0b  0f8431010000           -je 0x4edd42
    if (cpu.flags.zf)
    {
        goto L_0x004edd42;
    }
    // 004edc11  a1a0099f00             -mov eax, dword ptr [0x9f09a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004edc16  3b4308                 +cmp eax, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edc19  0f8d23010000           -jge 0x4edd42
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004edd42;
    }
    // 004edc1f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004edc21  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004edc23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004edc25  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004edc28  e873dcffff             -call 0x4eb8a0
    cpu.esp -= 4;
    sub_4eb8a0(app, cpu);
    if (cpu.terminate) return;
    // 004edc2d  8b4650                 -mov eax, dword ptr [esi + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004edc30  8a4e68                 -mov cl, byte ptr [esi + 0x68]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 004edc33  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edc34  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 004edc37  0f84e7000000           -je 0x4edd24
    if (cpu.flags.zf)
    {
        goto L_0x004edd24;
    }
    // 004edc3d  b846000000             -mov eax, 0x46
    cpu.eax = 70 /*0x46*/;
L_0x004edc42:
    // 004edc42  8a6e6a                 -mov ch, byte ptr [esi + 0x6a]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(106) /* 0x6a */);
    // 004edc45  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edc46  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004edc49  0f84df000000           -je 0x4edd2e
    if (cpu.flags.zf)
    {
        goto L_0x004edd2e;
    }
    // 004edc4f  b858000000             -mov eax, 0x58
    cpu.eax = 88 /*0x58*/;
L_0x004edc54:
    // 004edc54  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edc55  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004edc58  40                     -inc eax
    (cpu.eax)++;
    // 004edc59  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edc5a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004edc5d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004edc5e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edc5f  8b4e54                 -mov ecx, dword ptr [esi + 0x54]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 004edc62  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004edc63  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004edc66  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edc67  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004edc6a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004edc6d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edc6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004edc70  0f84c2000000           -je 0x4edd38
    if (cpu.flags.zf)
    {
        goto L_0x004edd38;
    }
    // 004edc76  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
L_0x004edc7b:
    // 004edc7b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edc7c  68b4c15400             -push 0x54c1b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554612 /*0x54c1b4*/;
    cpu.esp -= 4;
    // 004edc81  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004edc83  68d44e5600             -push 0x564ed4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004edc88  e8c3330100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004edc8d  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
L_0x004edc90:
    // 004edc90  ff05a0099f00           -inc dword ptr [0x9f09a0]
    (*app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */))++;
L_0x004edc96:
    // 004edc96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004edc9b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004edc9d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edc9e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edc9f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edca0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edca1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004edca4:
    // 004edca4  8b4658                 -mov eax, dword ptr [esi + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004edca7  e8d4dbffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004edcac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004edcae  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004edcb1  e8cadbffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004edcb6  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004edcb8  8b4660                 -mov eax, dword ptr [esi + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(96) /* 0x60 */);
    // 004edcbb  e8c0dbffff             -call 0x4eb880
    cpu.esp -= 4;
    sub_4eb880(app, cpu);
    if (cpu.terminate) return;
    // 004edcc0  01c7                   +add edi, eax
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
    // 004edcc2  e923ffffff             -jmp 0x4edbea
    goto L_0x004edbea;
L_0x004edcc7:
    // 004edcc7  770c                   -ja 0x4edcd5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004edcd5;
    }
    // 004edcc9  800da4099f0004         +or byte ptr [0x9f09a4], 4
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(10422692) /* 0x9f09a4 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004edcd0  e927ffffff             -jmp 0x4edbfc
    goto L_0x004edbfc;
L_0x004edcd5:
    // 004edcd5  83ff18                 +cmp edi, 0x18
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edcd8  0f821effffff           -jb 0x4edbfc
    if (cpu.flags.cf)
    {
        goto L_0x004edbfc;
    }
    // 004edcde  770c                   -ja 0x4edcec
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004edcec;
    }
    // 004edce0  800da4099f0008         +or byte ptr [0x9f09a4], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(10422692) /* 0x9f09a4 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004edce7  e910ffffff             -jmp 0x4edbfc
    goto L_0x004edbfc;
L_0x004edcec:
    // 004edcec  83ff20                 +cmp edi, 0x20
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
    // 004edcef  0f8507ffffff           -jne 0x4edbfc
    if (!cpu.flags.zf)
    {
        goto L_0x004edbfc;
    }
    // 004edcf5  800da4099f0010         +or byte ptr [0x9f09a4], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(10422692) /* 0x9f09a4 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004edcfc  e9fbfeffff             -jmp 0x4edbfc
    goto L_0x004edbfc;
L_0x004edd01:
    // 004edd01  770c                   -ja 0x4edd0f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004edd0f;
    }
    // 004edd03  800da4099f0001         +or byte ptr [0x9f09a4], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(10422692) /* 0x9f09a4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004edd0a  e9edfeffff             -jmp 0x4edbfc
    goto L_0x004edbfc;
L_0x004edd0f:
    // 004edd0f  83ff0f                 +cmp edi, 0xf
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edd12  0f85e4feffff           -jne 0x4edbfc
    if (!cpu.flags.zf)
    {
        goto L_0x004edbfc;
    }
    // 004edd18  800da4099f0002         +or byte ptr [0x9f09a4], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(x86::reg32(10422692) /* 0x9f09a4 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004edd1f  e9d8feffff             -jmp 0x4edbfc
    goto L_0x004edbfc;
L_0x004edd24:
    // 004edd24  b844000000             -mov eax, 0x44
    cpu.eax = 68 /*0x44*/;
    // 004edd29  e914ffffff             -jmp 0x4edc42
    goto L_0x004edc42;
L_0x004edd2e:
    // 004edd2e  b84e000000             -mov eax, 0x4e
    cpu.eax = 78 /*0x4e*/;
    // 004edd33  e91cffffff             -jmp 0x4edc54
    goto L_0x004edc54;
L_0x004edd38:
    // 004edd38  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004edd3d  e939ffffff             -jmp 0x4edc7b
    goto L_0x004edc7b;
L_0x004edd42:
    // 004edd42  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004edd45  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edd49  0f8441ffffff           -je 0x4edc90
    if (cpu.flags.zf)
    {
        goto L_0x004edc90;
    }
    // 004edd4f  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004edd52  a1a0099f00             -mov eax, dword ptr [0x9f09a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10422688) /* 0x9f09a0 */);
    // 004edd57  3b4208                 +cmp eax, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edd5a  0f8c30ffffff           -jl 0x4edc90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004edc90;
    }
    // 004edd60  68ecc15400             -push 0x54c1ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554668 /*0x54c1ec*/;
    cpu.esp -= 4;
    // 004edd65  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004edd67  68d44e5600             -push 0x564ed4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5656276 /*0x564ed4*/;
    cpu.esp -= 4;
    // 004edd6c  e8df320100             -call 0x501050
    cpu.esp -= 4;
    sub_501050(app, cpu);
    if (cpu.terminate) return;
    // 004edd71  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004edd74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004edd76  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004edd78  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edd79  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edd7a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edd7b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edd7c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4edd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edd80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edd81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004edd82  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edd83  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edd84  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004edd85  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004edd88  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004edd8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004edd8c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004edd91  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004edd93  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004edd95  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004edd97  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004edd9a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004edd9c  740e                   -je 0x4eddac
    if (cpu.flags.zf)
    {
        goto L_0x004eddac;
    }
    // 004edd9e  3b1560825600           +cmp edx, dword ptr [0x568260]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5669472) /* 0x568260 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edda4  7504                   -jne 0x4eddaa
    if (!cpu.flags.zf)
    {
        goto L_0x004eddaa;
    }
    // 004edda6  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004edda8  eb02                   -jmp 0x4eddac
    goto L_0x004eddac;
L_0x004eddaa:
    // 004eddaa  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x004eddac:
    // 004eddac  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004eddae  3c72                   +cmp al, 0x72
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
    // 004eddb0  7208                   -jb 0x4eddba
    if (cpu.flags.cf)
    {
        goto L_0x004eddba;
    }
    // 004eddb2  760c                   -jbe 0x4eddc0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004eddc0;
    }
    // 004eddb4  3c77                   +cmp al, 0x77
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
    // 004eddb6  740d                   -je 0x4eddc5
    if (cpu.flags.zf)
    {
        goto L_0x004eddc5;
    }
    // 004eddb8  eb15                   -jmp 0x4eddcf
    goto L_0x004eddcf;
L_0x004eddba:
    // 004eddba  3c61                   +cmp al, 0x61
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
    // 004eddbc  740c                   -je 0x4eddca
    if (cpu.flags.zf)
    {
        goto L_0x004eddca;
    }
    // 004eddbe  eb0f                   -jmp 0x4eddcf
    goto L_0x004eddcf;
L_0x004eddc0:
    // 004eddc0  80cb01                 +or bl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004eddc3  eb1b                   -jmp 0x4edde0
    goto L_0x004edde0;
L_0x004eddc5:
    // 004eddc5  80cb02                 +or bl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004eddc8  eb16                   -jmp 0x4edde0
    goto L_0x004edde0;
L_0x004eddca:
    // 004eddca  80cb82                 +or bl, 0x82
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 004eddcd  eb11                   -jmp 0x4edde0
    goto L_0x004edde0;
L_0x004eddcf:
    // 004eddcf  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004eddd4  e8a74a0100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004eddd9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004edddb  e9cf000000             -jmp 0x4edeaf
    goto L_0x004edeaf;
L_0x004edde0:
    // 004edde0  8a6101                 -mov ah, byte ptr [ecx + 1]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004edde3  41                     -inc ecx
    (cpu.ecx)++;
    // 004edde4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004edde6  0f84ae000000           -je 0x4ede9a
    if (cpu.flags.zf)
    {
        goto L_0x004ede9a;
    }
L_0x004eddec:
    // 004eddec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eddee  0f84a6000000           -je 0x4ede9a
    if (cpu.flags.zf)
    {
        goto L_0x004ede9a;
    }
    // 004eddf4  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004eddf6  3c63                   +cmp al, 0x63
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
    // 004eddf8  721d                   -jb 0x4ede17
    if (cpu.flags.cf)
    {
        goto L_0x004ede17;
    }
    // 004eddfa  0f8665000000           -jbe 0x4ede65
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ede65;
    }
    // 004ede00  3c6e                   +cmp al, 0x6e
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
    // 004ede02  0f8286000000           -jb 0x4ede8e
    if (cpu.flags.cf)
    {
        goto L_0x004ede8e;
    }
    // 004ede08  0f866c000000           -jbe 0x4ede7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ede7a;
    }
    // 004ede0e  3c74                   +cmp al, 0x74
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
    // 004ede10  7432                   -je 0x4ede44
    if (cpu.flags.zf)
    {
        goto L_0x004ede44;
    }
    // 004ede12  e977000000             -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede17:
    // 004ede17  3c2b                   +cmp al, 0x2b
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
    // 004ede19  0f826f000000           -jb 0x4ede8e
    if (cpu.flags.cf)
    {
        goto L_0x004ede8e;
    }
    // 004ede1f  7609                   -jbe 0x4ede2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ede2a;
    }
    // 004ede21  3c62                   +cmp al, 0x62
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
    // 004ede23  742e                   -je 0x4ede53
    if (cpu.flags.zf)
    {
        goto L_0x004ede53;
    }
    // 004ede25  e964000000             -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede2a:
    // 004ede2a  833c2400               +cmp dword ptr [esp], 0
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
    // 004ede2e  7407                   -je 0x4ede37
    if (cpu.flags.zf)
    {
        goto L_0x004ede37;
    }
    // 004ede30  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ede32  e957000000             -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede37:
    // 004ede37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ede3c  80cb03                 +or bl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004ede3f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ede42  eb4a                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede44:
    // 004ede44  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ede46  7404                   -je 0x4ede4c
    if (cpu.flags.zf)
    {
        goto L_0x004ede4c;
    }
    // 004ede48  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ede4a  eb42                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede4c:
    // 004ede4c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004ede51  eb3b                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede53:
    // 004ede53  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ede55  7404                   -je 0x4ede5b
    if (cpu.flags.zf)
    {
        goto L_0x004ede5b;
    }
    // 004ede57  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ede59  eb33                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede5b:
    // 004ede5b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004ede60  80cb40                 +or bl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 004ede63  eb29                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede65:
    // 004ede65  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ede67  7404                   -je 0x4ede6d
    if (cpu.flags.zf)
    {
        goto L_0x004ede6d;
    }
    // 004ede69  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ede6b  eb21                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede6d:
    // 004ede6d  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004ede6f  0c01                   +or al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004ede71  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004ede76  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004ede78  eb14                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede7a:
    // 004ede7a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ede7c  7404                   -je 0x4ede82
    if (cpu.flags.zf)
    {
        goto L_0x004ede82;
    }
    // 004ede7e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ede80  eb0c                   -jmp 0x4ede8e
    goto L_0x004ede8e;
L_0x004ede82:
    // 004ede82  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi);
    // 004ede84  80e4fe                 -and ah, 0xfe
    cpu.ah &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004ede87  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004ede8c  8826                   -mov byte ptr [esi], ah
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.ah;
L_0x004ede8e:
    // 004ede8e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ede91  41                     -inc ecx
    (cpu.ecx)++;
    // 004ede92  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004ede94  0f8552ffffff           -jne 0x4eddec
    if (!cpu.flags.zf)
    {
        goto L_0x004eddec;
    }
L_0x004ede9a:
    // 004ede9a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ede9c  750f                   -jne 0x4edead
    if (!cpu.flags.zf)
    {
        goto L_0x004edead;
    }
    // 004ede9e  813d6471560000020000   +cmp dword ptr [0x567164], 0x200
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665124) /* 0x567164 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edea8  7503                   -jne 0x4edead
    if (!cpu.flags.zf)
    {
        goto L_0x004edead;
    }
    // 004edeaa  80cb40                 -or bl, 0x40
    cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004edead:
    // 004edead  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004edeaf:
    // 004edeaf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004edeb1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004edeb4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edeb5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edeb6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edeb7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edeb8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edeb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4edebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edebc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edebd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edebe  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004edebf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004edec1  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004edec3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004edec5  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004edec9  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004edecd  09590c                 -or dword ptr [ecx + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eded0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004eded5  e8062c0000             -call 0x4f0ae0
    cpu.esp -= 4;
    sub_4f0ae0(app, cpu);
    if (cpu.terminate) return;
    // 004ededa  3c72                   +cmp al, 0x72
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
    // 004ededc  7522                   -jne 0x4edf00
    if (!cpu.flags.zf)
    {
        goto L_0x004edf00;
    }
    // 004edede  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004edee0  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004edee3  7405                   -je 0x4edeea
    if (cpu.flags.zf)
    {
        goto L_0x004edeea;
    }
    // 004edee5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004edeea:
    // 004edeea  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004edeed  7405                   -je 0x4edef4
    if (cpu.flags.zf)
    {
        goto L_0x004edef4;
    }
    // 004edeef  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004edef2  eb03                   -jmp 0x4edef7
    goto L_0x004edef7;
L_0x004edef4:
    // 004edef4  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x004edef7:
    // 004edef7  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004edef9  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004edefd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edefe  eb30                   -jmp 0x4edf30
    goto L_0x004edf30;
L_0x004edf00:
    // 004edf00  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004edf03  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004edf06  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004edf0b  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 004edf0e  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004edf11  7404                   -je 0x4edf17
    if (cpu.flags.zf)
    {
        goto L_0x004edf17;
    }
    // 004edf13  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 004edf15  eb02                   -jmp 0x4edf19
    goto L_0x004edf19;
L_0x004edf17:
    // 004edf17  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004edf19:
    // 004edf19  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 004edf1c  7405                   -je 0x4edf23
    if (cpu.flags.zf)
    {
        goto L_0x004edf23;
    }
    // 004edf1e  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004edf21  eb03                   -jmp 0x4edf26
    goto L_0x004edf26;
L_0x004edf23:
    // 004edf23  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004edf26:
    // 004edf26  6880010000             -push 0x180
    *app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 004edf2b  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004edf2f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x004edf30:
    // 004edf30  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edf31  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edf32  e8bdb00100             -call 0x508ff4
    cpu.esp -= 4;
    sub_508ff4(app, cpu);
    if (cpu.terminate) return;
    // 004edf37  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004edf3a  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004edf3d  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004edf41  750b                   -jne 0x4edf4e
    if (!cpu.flags.zf)
    {
        goto L_0x004edf4e;
    }
    // 004edf43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004edf45  e8cab30100             -call 0x509314
    cpu.esp -= 4;
    sub_509314(app, cpu);
    if (cpu.terminate) return;
    // 004edf4a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004edf4c  eb4e                   -jmp 0x4edf9c
    goto L_0x004edf9c;
L_0x004edf4e:
    // 004edf4e  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004edf55  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004edf58  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004edf5f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004edf66  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004edf69  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004edf6c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004edf6f  c7401500000000         -mov dword ptr [eax + 0x15], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004edf76  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004edf79  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004edf80  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004edf83  740e                   -je 0x4edf93
    if (cpu.flags.zf)
    {
        goto L_0x004edf93;
    }
    // 004edf85  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004edf8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004edf8c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004edf8e  e8f5b0ffff             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
L_0x004edf93:
    // 004edf93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004edf95  e8e6b30100             -call 0x509380
    cpu.esp -= 4;
    sub_509380(app, cpu);
    if (cpu.terminate) return;
    // 004edf9a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004edf9c:
    // 004edf9c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edf9d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edf9e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edf9f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4edfa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edfa4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004edfa5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004edfa6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edfa7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004edfaa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004edfac  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004edfae  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004edfb0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004edfb2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004edfb4  e8c7fdffff             -call 0x4edd80
    cpu.esp -= 4;
    sub_4edd80(app, cpu);
    if (cpu.terminate) return;
    // 004edfb9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004edfbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004edfbd  7422                   -je 0x4edfe1
    if (cpu.flags.zf)
    {
        goto L_0x004edfe1;
    }
    // 004edfbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004edfc1  e88ab20100             -call 0x509250
    cpu.esp -= 4;
    sub_509250(app, cpu);
    if (cpu.terminate) return;
    // 004edfc6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004edfc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004edfca  7413                   -je 0x4edfdf
    if (cpu.flags.zf)
    {
        goto L_0x004edfdf;
    }
    // 004edfcc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004edfcd  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004edfcf  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004edfd0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004edfd2  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004edfd4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004edfd8  e8dffeffff             -call 0x4edebc
    cpu.esp -= 4;
    sub_4edebc(app, cpu);
    if (cpu.terminate) return;
    // 004edfdd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004edfdf:
    // 004edfdf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004edfe1:
    // 004edfe1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004edfe4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edfe5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edfe6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edfe7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4edfe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edfe8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edfe9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004edfeb  e8b4ffffff             -call 0x4edfa4
    cpu.esp -= 4;
    sub_4edfa4(app, cpu);
    if (cpu.terminate) return;
    // 004edff0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004edff1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4edff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004edff4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004edff5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004edff6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004edff7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004edff9  ff1578775600           -call dword ptr [0x567778]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004edfff  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 004ee004  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee006  742b                   -je 0x4ee033
    if (cpu.flags.zf)
    {
        goto L_0x004ee033;
    }
L_0x004ee008:
    // 004ee008  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ee00b  39d3                   +cmp ebx, edx
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
    // 004ee00d  751e                   -jne 0x4ee02d
    if (!cpu.flags.zf)
    {
        goto L_0x004ee02d;
    }
    // 004ee00f  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 004ee013  740c                   -je 0x4ee021
    if (cpu.flags.zf)
    {
        goto L_0x004ee021;
    }
    // 004ee015  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ee01a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee01c  e8f3010000             -call 0x4ee214
    cpu.esp -= 4;
    sub_4ee214(app, cpu);
    if (cpu.terminate) return;
L_0x004ee021:
    // 004ee021  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee027  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee029  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee02a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee02b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee02c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee02d:
    // 004ee02d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ee02f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee031  75d5                   -jne 0x4ee008
    if (!cpu.flags.zf)
    {
        goto L_0x004ee008;
    }
L_0x004ee033:
    // 004ee033  baa4389f00             -mov edx, 0x9f38a4
    cpu.edx = 10434724 /*0x9f38a4*/;
L_0x004ee038:
    // 004ee038  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ee03a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee03c  7426                   -je 0x4ee064
    if (cpu.flags.zf)
    {
        goto L_0x004ee064;
    }
    // 004ee03e  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee041  751d                   -jne 0x4ee060
    if (!cpu.flags.zf)
    {
        goto L_0x004ee060;
    }
    // 004ee043  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ee045  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ee047  8b15a0389f00           -mov edx, dword ptr [0x9f38a0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 004ee04d  a3a0389f00             -mov dword ptr [0x9f38a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */) = cpu.eax;
    // 004ee052  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ee054  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee05a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee05c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee05d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee05e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee05f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee060:
    // 004ee060  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ee062  ebd4                   -jmp 0x4ee038
    goto L_0x004ee038;
L_0x004ee064:
    // 004ee064  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004ee069  e812480100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004ee06e  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee074  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee076  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee077  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee078  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ee07c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee07c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee07d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee07e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ee07f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ee080  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ee083  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ee085  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ee087  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ee089  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ee08b  e8f0fcffff             -call 0x4edd80
    cpu.esp -= 4;
    sub_4edd80(app, cpu);
    if (cpu.terminate) return;
    // 004ee090  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ee092  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee094  7455                   -je 0x4ee0eb
    if (cpu.flags.zf)
    {
        goto L_0x004ee0eb;
    }
    // 004ee096  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ee099  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee09b  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee0a1  833db477560000         +cmp dword ptr [0x5677b4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5666740) /* 0x5677b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee0a8  7408                   -je 0x4ee0b2
    if (cpu.flags.zf)
    {
        goto L_0x004ee0b2;
    }
    // 004ee0aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee0ac  ff15b4775600           -call dword ptr [0x5677b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666740) /* 0x5677b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ee0b2:
    // 004ee0b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee0b4  e83bffffff             -call 0x4edff4
    cpu.esp -= 4;
    sub_4edff4(app, cpu);
    if (cpu.terminate) return;
    // 004ee0b9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee0bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee0bd  7422                   -je 0x4ee0e1
    if (cpu.flags.zf)
    {
        goto L_0x004ee0e1;
    }
    // 004ee0bf  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ee0c0  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ee0c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ee0c5  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004ee0cb  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ee0cd  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004ee0d0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004ee0d2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee0d4  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004ee0d6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ee0da  e8ddfdffff             -call 0x4edebc
    cpu.esp -= 4;
    sub_4edebc(app, cpu);
    if (cpu.terminate) return;
    // 004ee0df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ee0e1:
    // 004ee0e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee0e3  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee0e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004ee0eb:
    // 004ee0eb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ee0ee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee0ef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee0f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee0f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee0f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee100  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee101  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ee102  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee104  ff1578775600           -call dword ptr [0x567778]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666680) /* 0x567778 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee10a  a1a0389f00             -mov eax, dword ptr [0x9f38a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10434720) /* 0x9f38a0 */);
    // 004ee10f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee111  750e                   -jne 0x4ee121
    if (!cpu.flags.zf)
    {
        goto L_0x004ee121;
    }
L_0x004ee113:
    // 004ee113  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee119  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ee11e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee11f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee120  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee121:
    // 004ee121  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee124  7408                   -je 0x4ee12e
    if (cpu.flags.zf)
    {
        goto L_0x004ee12e;
    }
    // 004ee126  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ee128  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee12a  74e7                   -je 0x4ee113
    if (cpu.flags.zf)
    {
        goto L_0x004ee113;
    }
    // 004ee12c  ebf3                   -jmp 0x4ee121
    goto L_0x004ee121;
L_0x004ee12e:
    // 004ee12e  ff157c775600           -call dword ptr [0x56777c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666684) /* 0x56777c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee134  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ee139  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee13b  e804000000             -call 0x4ee144
    cpu.esp -= 4;
    sub_4ee144(app, cpu);
    if (cpu.terminate) return;
    // 004ee140  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee141  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee142  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ee144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee144  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee145  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee147  e8c8000000             -call 0x4ee214
    cpu.esp -= 4;
    sub_4ee214(app, cpu);
    if (cpu.terminate) return;
    // 004ee14c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ee14e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee150  e8bfb10100             -call 0x509314
    cpu.esp -= 4;
    sub_509314(app, cpu);
    if (cpu.terminate) return;
    // 004ee155  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ee157  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee158  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ee15c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee15c  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004ee15f  83f839                 +cmp eax, 0x39
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
    // 004ee162  7e03                   -jle 0x4ee167
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee167;
    }
    // 004ee164  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x004ee167:
    // 004ee167  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ee168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee168  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee169  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee16a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee16b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ee16c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ee16d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ee170  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ee172  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ee175  e846b20100             -call 0x5093c0
    cpu.esp -= 4;
    sub_5093c0(app, cpu);
    if (cpu.terminate) return;
    // 004ee17a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee17c  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004ee17f  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ee181  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee183  e858b30100             -call 0x5094e0
    cpu.esp -= 4;
    sub_5094e0(app, cpu);
    if (cpu.terminate) return;
    // 004ee188  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ee18a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004ee18b:
    // 004ee18b  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004ee18d  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004ee18f  3c00                   +cmp al, 0
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
    // 004ee191  7410                   -je 0x4ee1a3
    if (cpu.flags.zf)
    {
        goto L_0x004ee1a3;
    }
    // 004ee193  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ee196  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ee199  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ee19c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ee19f  3c00                   +cmp al, 0
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
    // 004ee1a1  75e8                   -jne 0x4ee18b
    if (!cpu.flags.zf)
    {
        goto L_0x004ee18b;
    }
L_0x004ee1a3:
    // 004ee1a3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee1a4  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ee1a5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004ee1a7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004ee1a9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee1ab  49                     -dec ecx
    (cpu.ecx)--;
    // 004ee1ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004ee1ae  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004ee1b0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ee1b2  49                     -dec ecx
    (cpu.ecx)--;
    // 004ee1b3  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee1b4  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004ee1b7  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ee1ba  c60674                 -mov byte ptr [esi], 0x74
    *app->getMemory<x86::reg8>(cpu.esi) = 116 /*0x74*/;
    // 004ee1bd  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004ee1bf:
    // 004ee1bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee1c1  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ee1c4  4a                     -dec edx
    (cpu.edx)--;
    // 004ee1c5  e892ffffff             -call 0x4ee15c
    cpu.esp -= 4;
    sub_4ee15c(app, cpu);
    if (cpu.terminate) return;
    // 004ee1ca  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 004ee1cd  884201                 -mov byte ptr [edx + 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ee1d0  39ca                   +cmp edx, ecx
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
    // 004ee1d2  75eb                   -jne 0x4ee1bf
    if (!cpu.flags.zf)
    {
        goto L_0x004ee1bf;
    }
    // 004ee1d4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ee1d7  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004ee1da  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ee1dd  c646055f               -mov byte ptr [esi + 5], 0x5f
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 004ee1e1  e876ffffff             -call 0x4ee15c
    cpu.esp -= 4;
    sub_4ee15c(app, cpu);
    if (cpu.terminate) return;
    // 004ee1e6  884606                 -mov byte ptr [esi + 6], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 004ee1e9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ee1ec  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004ee1ef  e868ffffff             -call 0x4ee15c
    cpu.esp -= 4;
    sub_4ee15c(app, cpu);
    if (cpu.terminate) return;
    // 004ee1f4  c646082e               -mov byte ptr [esi + 8], 0x2e
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 004ee1f8  c6460974               -mov byte ptr [esi + 9], 0x74
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 004ee1fc  c6460a6d               -mov byte ptr [esi + 0xa], 0x6d
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 004ee200  c6460b70               -mov byte ptr [esi + 0xb], 0x70
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 004ee204  c6460c00               -mov byte ptr [esi + 0xc], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ee208  884607                 -mov byte ptr [esi + 7], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004ee20b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ee20e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee20f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee210  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee211  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee212  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee213  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ee214(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee214  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee215  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee216  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee217  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ee218  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ee219  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 004ee21f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ee221  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ee223  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 004ee227  750a                   -jne 0x4ee233
    if (!cpu.flags.zf)
    {
        goto L_0x004ee233;
    }
    // 004ee229  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ee22e  e997000000             -jmp 0x4ee2ca
    goto L_0x004ee2ca;
L_0x004ee233:
    // 004ee233  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004ee236  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ee238  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004ee23b  7409                   -je 0x4ee246
    if (cpu.flags.zf)
    {
        goto L_0x004ee246;
    }
    // 004ee23d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ee23f  e81c450100             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
    // 004ee244  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ee246:
    // 004ee246  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ee249  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee24f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ee251  e8ca010000             -call 0x4ee420
    cpu.esp -= 4;
    sub_4ee420(app, cpu);
    if (cpu.terminate) return;
    // 004ee256  83f8ff                 +cmp eax, -1
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
    // 004ee259  740e                   -je 0x4ee269
    if (cpu.flags.zf)
    {
        goto L_0x004ee269;
    }
    // 004ee25b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ee25d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ee260  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ee262  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ee264  e877460100             -call 0x5028e0
    cpu.esp -= 4;
    sub_5028e0(app, cpu);
    if (cpu.terminate) return;
L_0x004ee269:
    // 004ee269  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ee26b  740a                   -je 0x4ee277
    if (cpu.flags.zf)
    {
        goto L_0x004ee277;
    }
    // 004ee26d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ee270  e83bb30100             -call 0x5095b0
    cpu.esp -= 4;
    sub_5095b0(app, cpu);
    if (cpu.terminate) return;
    // 004ee275  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ee277:
    // 004ee277  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 004ee27b  7415                   -je 0x4ee292
    if (cpu.flags.zf)
    {
        goto L_0x004ee292;
    }
    // 004ee27d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ee280  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ee283  e868970000             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 004ee288  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ee28b  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x004ee292:
    // 004ee292  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004ee296  741a                   -je 0x4ee2b2
    if (cpu.flags.zf)
    {
        goto L_0x004ee2b2;
    }
    // 004ee298  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004ee29b  8a5214                 -mov dl, byte ptr [edx + 0x14]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ee29e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ee2a0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ee2a6  e8bdfeffff             -call 0x4ee168
    cpu.esp -= 4;
    sub_4ee168(app, cpu);
    if (cpu.terminate) return;
    // 004ee2ab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ee2ad  e82e000000             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
L_0x004ee2b2:
    // 004ee2b2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ee2b5  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee2bb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ee2bd  7409                   -je 0x4ee2c8
    if (cpu.flags.zf)
    {
        goto L_0x004ee2c8;
    }
    // 004ee2bf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004ee2c2  ff1574775600           -call dword ptr [0x567774]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666676) /* 0x567774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ee2c8:
    // 004ee2c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004ee2ca:
    // 004ee2ca  81c414010000           -add esp, 0x114
    (cpu.esp) += x86::reg32(x86::sreg32(276 /*0x114*/));
    // 004ee2d0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee2d1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee2d2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee2d3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee2d4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee2d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee2e0  e9bb45ffff             -jmp 0x4e28a0
    return sub_4e28a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee2f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee2f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee2f2  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004ee2f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ee2f6:
    // 004ee2f6  3a08                   +cmp cl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ee2f8  7502                   -jne 0x4ee2fc
    if (!cpu.flags.zf)
    {
        goto L_0x004ee2fc;
    }
    // 004ee2fa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ee2fc:
    // 004ee2fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ee2fe  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx);
    // 004ee300  40                     -inc eax
    (cpu.eax)++;
    // 004ee301  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004ee303  75f1                   -jne 0x4ee2f6
    if (!cpu.flags.zf)
    {
        goto L_0x004ee2f6;
    }
    // 004ee305  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee307  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee308  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee309  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee310  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee311  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee312  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee314  39d0                   +cmp eax, edx
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
    // 004ee316  746c                   -je 0x4ee384
    if (cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
L_0x004ee318:
    // 004ee318  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004ee31a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ee31c  39c1                   +cmp ecx, eax
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
    // 004ee31e  7569                   -jne 0x4ee389
    if (!cpu.flags.zf)
    {
        goto L_0x004ee389;
    }
    // 004ee320  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ee322  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004ee327  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee329  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ee32e  7554                   -jne 0x4ee384
    if (!cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee330  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004ee333  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ee336  39c1                   +cmp ecx, eax
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
    // 004ee338  754f                   -jne 0x4ee389
    if (!cpu.flags.zf)
    {
        goto L_0x004ee389;
    }
    // 004ee33a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ee33c  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004ee341  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee343  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ee348  753a                   -jne 0x4ee384
    if (!cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee34a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ee34d  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004ee350  39c1                   +cmp ecx, eax
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
    // 004ee352  7535                   -jne 0x4ee389
    if (!cpu.flags.zf)
    {
        goto L_0x004ee389;
    }
    // 004ee354  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ee356  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004ee35b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee35d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ee362  7520                   -jne 0x4ee384
    if (!cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee364  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004ee367  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004ee36a  39c1                   +cmp ecx, eax
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
    // 004ee36c  751b                   -jne 0x4ee389
    if (!cpu.flags.zf)
    {
        goto L_0x004ee389;
    }
    // 004ee36e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ee371  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ee374  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004ee376  05fffefefe             -add eax, 0xfefefeff
    (cpu.eax) += x86::reg32(x86::sreg32(4278124287 /*0xfefefeff*/));
    // 004ee37b  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee37d  2580808080             +and eax, 0x80808080
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(2155905152 /*0x80808080*/))));
    // 004ee382  7494                   -je 0x4ee318
    if (cpu.flags.zf)
    {
        goto L_0x004ee318;
    }
L_0x004ee384:
    // 004ee384  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee386  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee387  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee388  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee389:
    // 004ee389  38c8                   +cmp al, cl
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
    // 004ee38b  751d                   -jne 0x4ee3aa
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3aa;
    }
    // 004ee38d  3c00                   +cmp al, 0
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
    // 004ee38f  74f3                   -je 0x4ee384
    if (cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee391  38ec                   +cmp ah, ch
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
    // 004ee393  7515                   -jne 0x4ee3aa
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3aa;
    }
    // 004ee395  80fc00                 +cmp ah, 0
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
    // 004ee398  74ea                   -je 0x4ee384
    if (cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee39a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ee39d  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ee3a0  38c8                   +cmp al, cl
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
    // 004ee3a2  7506                   -jne 0x4ee3aa
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3aa;
    }
    // 004ee3a4  3c00                   +cmp al, 0
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
    // 004ee3a6  74dc                   -je 0x4ee384
    if (cpu.flags.zf)
    {
        goto L_0x004ee384;
    }
    // 004ee3a8  38ec                   +cmp ah, ch
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
L_0x004ee3aa:
    // 004ee3aa  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004ee3ac  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004ee3ae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3af  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee3c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee3c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee3c2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee3c4  e877b20100             -call 0x509640
    cpu.esp -= 4;
    sub_509640(app, cpu);
    if (cpu.terminate) return;
    // 004ee3c9  83f8ff                 +cmp eax, -1
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
    // 004ee3cc  7508                   -jne 0x4ee3d6
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3d6;
    }
    // 004ee3ce  e8212c0100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004ee3d3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3d4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee3d6:
    // 004ee3d6  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004ee3d8  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 004ee3db  7502                   -jne 0x4ee3df
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3df;
    }
    // 004ee3dd  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004ee3df:
    // 004ee3df  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ee3e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee3e1  2eff15ec455300         -call dword ptr cs:[0x5345ec]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457388) /* 0x5345ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee3e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee3ea  7508                   -jne 0x4ee3f4
    if (!cpu.flags.zf)
    {
        goto L_0x004ee3f4;
    }
    // 004ee3ec  e8032c0100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004ee3f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3f2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee3f4:
    // 004ee3f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee3f6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3f7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee3f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee400  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee401  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ee402  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ee403  2eff15b4455300         -call dword ptr cs:[0x5345b4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457332) /* 0x5345b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee40a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee40c  7508                   -jne 0x4ee416
    if (!cpu.flags.zf)
    {
        goto L_0x004ee416;
    }
    // 004ee40e  e8e12b0100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004ee413  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee414  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee415  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ee416:
    // 004ee416  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee418  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee419  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee41a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee420  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ee421  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ee422  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ee423  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee424  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ee426  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 004ee42a  740d                   -je 0x4ee439
    if (cpu.flags.zf)
    {
        goto L_0x004ee439;
    }
    // 004ee42c  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004ee430  7407                   -je 0x4ee439
    if (cpu.flags.zf)
    {
        goto L_0x004ee439;
    }
    // 004ee432  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ee434  e837990000             -call 0x4f7d70
    cpu.esp -= 4;
    sub_4f7d70(app, cpu);
    if (cpu.terminate) return;
L_0x004ee439:
    // 004ee439  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ee43c  e81f450100             -call 0x502960
    cpu.esp -= 4;
    sub_502960(app, cpu);
    if (cpu.terminate) return;
    // 004ee441  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ee443  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ee445  83f8ff                 +cmp eax, -1
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
    // 004ee448  742a                   -je 0x4ee474
    if (cpu.flags.zf)
    {
        goto L_0x004ee474;
    }
    // 004ee44a  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ee44d  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee453  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ee456  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ee458  740f                   -je 0x4ee469
    if (cpu.flags.zf)
    {
        goto L_0x004ee469;
    }
    // 004ee45a  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004ee45e  7405                   -je 0x4ee465
    if (cpu.flags.zf)
    {
        goto L_0x004ee465;
    }
    // 004ee460  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004ee463  eb04                   -jmp 0x4ee469
    goto L_0x004ee469;
L_0x004ee465:
    // 004ee465  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ee467  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ee469:
    // 004ee469  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ee46c  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee472  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004ee474:
    // 004ee474  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee475  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee476  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee477  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee478  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ee480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee480  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee481  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ee482  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ee483  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004ee485  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004ee487  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ee489  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ee48b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee48d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee48f  7e16                   -jle 0x4ee4a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee4a7;
    }
    // 004ee491  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ee493  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee495  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee497  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee499  7e16                   -jle 0x4ee4b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee4b1;
    }
    // 004ee49b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ee49d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee49f  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee4a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee4a3  7e1a                   -jle 0x4ee4bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee4bf;
    }
    // 004ee4a5  eb1c                   -jmp 0x4ee4c3
    goto L_0x004ee4c3;
L_0x004ee4a7:
    // 004ee4a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ee4a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee4ab  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee4ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee4af  7c04                   -jl 0x4ee4b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ee4b5;
    }
L_0x004ee4b1:
    // 004ee4b1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee4b3  eb10                   -jmp 0x4ee4c5
    goto L_0x004ee4c5;
L_0x004ee4b5:
    // 004ee4b5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ee4b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee4b9  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee4bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee4bd  7e04                   -jle 0x4ee4c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee4c3;
    }
L_0x004ee4bf:
    // 004ee4bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee4c1  eb02                   -jmp 0x4ee4c5
    goto L_0x004ee4c5;
L_0x004ee4c3:
    // 004ee4c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004ee4c5:
    // 004ee4c5  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee4c7  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee4c9  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee4ca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee4cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ee4cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ee4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee4d0  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ee4d1  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004ee4d2  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee4d3  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004ee4d6  c1e902                 +shr ecx, 2
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
    // 004ee4d9  740b                   -je 0x4ee4e6
    if (cpu.flags.zf)
    {
        goto L_0x004ee4e6;
    }
L_0x004ee4db:
    // 004ee4db  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee4dd  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = *app->getMemory<x86::reg32>(cpu.esi);
        *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004ee4df  ab                     -stosd dword ptr es:[edi], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004ee4e0  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee4e3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee4e4  75f5                   -jne 0x4ee4db
    if (!cpu.flags.zf)
    {
        goto L_0x004ee4db;
    }
L_0x004ee4e6:
    // 004ee4e6  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004ee4e9  7409                   -je 0x4ee4f4
    if (cpu.flags.zf)
    {
        goto L_0x004ee4f4;
    }
L_0x004ee4eb:
    // 004ee4eb  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 004ee4ed  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = *app->getMemory<x86::reg8>(cpu.esi);
        *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004ee4ef  aa                     -stosb byte ptr es:[edi], al
    *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004ee4f0  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ee4f1  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee4f2  75f7                   -jne 0x4ee4eb
    if (!cpu.flags.zf)
    {
        goto L_0x004ee4eb;
    }
L_0x004ee4f4:
    // 004ee4f4  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee4f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ee4f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ee4f8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ee4f9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ee4fa  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ee4fb  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004ee4fd  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004ee4ff  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ee500  81ec50010000           -sub esp, 0x150
    (cpu.esp) -= x86::reg32(x86::sreg32(336 /*0x150*/));
    // 004ee506  89942420010000         -mov dword ptr [esp + 0x120], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.edx;
    // 004ee50d  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004ee50f  8984242c010000         -mov dword ptr [esp + 0x12c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 004ee516  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ee518  898c2438010000         -mov dword ptr [esp + 0x138], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */) = cpu.ecx;
    // 004ee51f  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004ee521  7407                   -je 0x4ee52a
    if (cpu.flags.zf)
    {
        goto L_0x004ee52a;
    }
    // 004ee523  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004ee528  eb0b                   -jmp 0x4ee535
    goto L_0x004ee535;
L_0x004ee52a:
    // 004ee52a  83fb04                 +cmp ebx, 4
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
    // 004ee52d  0f97c0                 -seta al
    cpu.al = (!cpu.flags.cf && !cpu.flags.zf);
    // 004ee530  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004ee535:
    // 004ee535  8984243c010000         -mov dword ptr [esp + 0x13c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.eax;
    // 004ee53c  8d442d00               -lea eax, [ebp + ebp]
    cpu.eax = x86::reg32(cpu.ebp + cpu.ebp * 1);
    // 004ee540  8984240c010000         -mov dword ptr [esp + 0x10c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */) = cpu.eax;
    // 004ee547  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004ee54e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ee550  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ee552  89942414010000         -mov dword ptr [esp + 0x114], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.edx;
    // 004ee559  89842408010000         -mov dword ptr [esp + 0x108], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
L_0x004ee560:
    // 004ee560  8b9c2420010000         -mov ebx, dword ptr [esp + 0x120]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004ee567  83fb01                 +cmp ebx, 1
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
    // 004ee56a  0f86f6000000           -jbe 0x4ee666
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee666;
    }
    // 004ee570  83fb10                 +cmp ebx, 0x10
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
    // 004ee573  0f8323010000           -jae 0x4ee69c
    if (!cpu.flags.cf)
    {
        goto L_0x004ee69c;
    }
    // 004ee579  8b842408010000         -mov eax, dword ptr [esp + 0x108]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004ee580  89842434010000         -mov dword ptr [esp + 0x134], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 004ee587  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee589  0f8ed7000000           -jle 0x4ee666
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ee666;
    }
    // 004ee58f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee591  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee594  8b94242c010000         -mov edx, dword ptr [esp + 0x12c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee59b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee59d  89942424010000         -mov dword ptr [esp + 0x124], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.edx;
L_0x004ee5a4:
    // 004ee5a4  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee5ab  03842434010000         -add eax, dword ptr [esp + 0x134]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */)));
    // 004ee5b2  8bb42424010000         -mov esi, dword ptr [esp + 0x124]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004ee5b9  89842428010000         -mov dword ptr [esp + 0x128], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 004ee5c0  39f0                   +cmp eax, esi
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
    // 004ee5c2  0f837f000000           -jae 0x4ee647
    if (!cpu.flags.cf)
    {
        goto L_0x004ee647;
    }
L_0x004ee5c8:
    // 004ee5c8  8b9c2428010000         -mov ebx, dword ptr [esp + 0x128]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004ee5cf  3b9c242c010000         +cmp ebx, dword ptr [esp + 0x12c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee5d6  7733                   -ja 0x4ee60b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ee60b;
    }
    // 004ee5d8  eb4b                   -jmp 0x4ee625
    goto L_0x004ee625;
L_0x004ee5da:
    // 004ee5da  83bc243c01000000       +cmp dword ptr [esp + 0x13c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee5e2  740b                   -je 0x4ee5ef
    if (cpu.flags.zf)
    {
        goto L_0x004ee5ef;
    }
    // 004ee5e4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ee5e6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ee5e8  e8e3feffff             -call 0x4ee4d0
    cpu.esp -= 4;
    sub_4ee4d0(app, cpu);
    if (cpu.terminate) return;
    // 004ee5ed  eb08                   -jmp 0x4ee5f7
    goto L_0x004ee5f7;
L_0x004ee5ef:
    // 004ee5ef  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee5f1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004ee5f3  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ee5f5  8917                   -mov dword ptr [edi], edx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x004ee5f7:
    // 004ee5f7  8bb42434010000         -mov esi, dword ptr [esp + 0x134]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004ee5fe  8bbc242c010000         -mov edi, dword ptr [esp + 0x12c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee605  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ee607  39fb                   +cmp ebx, edi
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
    // 004ee609  761a                   -jbe 0x4ee625
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee625;
    }
L_0x004ee60b:
    // 004ee60b  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004ee612  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ee614  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee616  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ee618  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee61a  ff942438010000         -call dword ptr [esp + 0x138]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee621  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee623  7fb5                   -jg 0x4ee5da
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ee5da;
    }
L_0x004ee625:
    // 004ee625  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004ee62c  8bbc2428010000         -mov edi, dword ptr [esp + 0x128]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004ee633  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee635  8b942424010000         -mov edx, dword ptr [esp + 0x124]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004ee63c  89bc2428010000         -mov dword ptr [esp + 0x128], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.edi;
    // 004ee643  39d7                   +cmp edi, edx
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
    // 004ee645  7281                   -jb 0x4ee5c8
    if (cpu.flags.cf)
    {
        goto L_0x004ee5c8;
    }
L_0x004ee647:
    // 004ee647  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004ee64e  8b942434010000         -mov edx, dword ptr [esp + 0x134]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004ee655  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ee657  89942434010000         -mov dword ptr [esp + 0x134], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.edx;
    // 004ee65e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ee660  0f8f3effffff           -jg 0x4ee5a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ee5a4;
    }
L_0x004ee666:
    // 004ee666  8b9c2414010000         -mov ebx, dword ptr [esp + 0x114]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004ee66d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ee66f  0f8455040000           -je 0x4eeaca
    if (cpu.flags.zf)
    {
        goto L_0x004eeaca;
    }
    // 004ee675  8d4bff                 -lea ecx, [ebx - 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ee678  898c2414010000         -mov dword ptr [esp + 0x114], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.ecx;
    // 004ee67f  8b148c                 -mov edx, dword ptr [esp + ecx*4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 4);
    // 004ee682  8b848c80000000         -mov eax, dword ptr [esp + ecx*4 + 0x80]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */ + cpu.ecx * 4);
    // 004ee689  8994242c010000         -mov dword ptr [esp + 0x12c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.edx;
    // 004ee690  89842420010000         -mov dword ptr [esp + 0x120], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 004ee697  e9c4feffff             -jmp 0x4ee560
    goto L_0x004ee560;
L_0x004ee69c:
    // 004ee69c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee69e  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ee6a0  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee6a3  8bbc242c010000         -mov edi, dword ptr [esp + 0x12c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee6aa  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee6ac  83fb1d                 +cmp ebx, 0x1d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee6af  0f86d4000000           -jbe 0x4ee789
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee789;
    }
    // 004ee6b5  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee6bc  89842410010000         -mov dword ptr [esp + 0x110], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */) = cpu.eax;
    // 004ee6c3  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004ee6c6  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee6c9  8bb4242c010000         -mov esi, dword ptr [esp + 0x12c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee6d0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee6d2  83fb2a                 +cmp ebx, 0x2a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee6d5  0f8695000000           -jbe 0x4ee770
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee770;
    }
    // 004ee6db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee6dd  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ee6e0  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee6e3  8b94242c010000         -mov edx, dword ptr [esp + 0x12c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee6ea  8b9c242c010000         -mov ebx, dword ptr [esp + 0x12c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee6f1  8984241c010000         -mov dword ptr [esp + 0x11c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.eax;
    // 004ee6f8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee6fa  8b8c241c010000         -mov ecx, dword ptr [esp + 0x11c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004ee701  89842404010000         -mov dword ptr [esp + 0x104], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004ee708  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee70a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee70c  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004ee713  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee71a  e861fdffff             -call 0x4ee480
    cpu.esp -= 4;
    sub_4ee480(app, cpu);
    if (cpu.terminate) return;
    // 004ee71f  8b9c241c010000         -mov ebx, dword ptr [esp + 0x11c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004ee726  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004ee72d  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004ee734  89842410010000         -mov dword ptr [esp + 0x110], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */) = cpu.eax;
    // 004ee73b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ee73d  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ee73f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ee741  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ee743  e838fdffff             -call 0x4ee480
    cpu.esp -= 4;
    sub_4ee480(app, cpu);
    if (cpu.terminate) return;
    // 004ee748  8b9c241c010000         -mov ebx, dword ptr [esp + 0x11c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004ee74f  8b8c2404010000         -mov ecx, dword ptr [esp + 0x104]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004ee756  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ee758  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ee75a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ee75c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ee75e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ee760  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee762  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004ee769  e812fdffff             -call 0x4ee480
    cpu.esp -= 4;
    sub_4ee480(app, cpu);
    if (cpu.terminate) return;
    // 004ee76e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ee770:
    // 004ee770  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004ee777  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004ee77e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ee780  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ee782  e8f9fcffff             -call 0x4ee480
    cpu.esp -= 4;
    sub_4ee480(app, cpu);
    if (cpu.terminate) return;
    // 004ee787  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ee789:
    // 004ee789  8bb4243c010000         -mov esi, dword ptr [esp + 0x13c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004ee790  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ee792  742c                   -je 0x4ee7c0
    if (cpu.flags.zf)
    {
        goto L_0x004ee7c0;
    }
    // 004ee794  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee79b  89842430010000         -mov dword ptr [esp + 0x130], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004ee7a2  740b                   -je 0x4ee7af
    if (cpu.flags.zf)
    {
        goto L_0x004ee7af;
    }
    // 004ee7a4  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ee7a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ee7a8  e823fdffff             -call 0x4ee4d0
    cpu.esp -= 4;
    sub_4ee4d0(app, cpu);
    if (cpu.terminate) return;
    // 004ee7ad  eb28                   -jmp 0x4ee7d7
    goto L_0x004ee7d7;
L_0x004ee7af:
    // 004ee7af  8b9c242c010000         -mov ebx, dword ptr [esp + 0x12c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee7b6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ee7b8  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee7ba  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ee7bc  8917                   -mov dword ptr [edi], edx
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004ee7be  eb17                   -jmp 0x4ee7d7
    goto L_0x004ee7d7;
L_0x004ee7c0:
    // 004ee7c0  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004ee7c7  89842430010000         -mov dword ptr [esp + 0x130], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004ee7ce  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee7d0  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
L_0x004ee7d7:
    // 004ee7d7  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004ee7de  48                     -dec eax
    (cpu.eax)--;
    // 004ee7df  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee7e2  8b9c242c010000         -mov ebx, dword ptr [esp + 0x12c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee7e9  899c2440010000         -mov dword ptr [esp + 0x140], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */) = cpu.ebx;
    // 004ee7f0  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004ee7f3  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004ee7fa  89942444010000         -mov dword ptr [esp + 0x144], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */) = cpu.edx;
    // 004ee801  89942448010000         -mov dword ptr [esp + 0x148], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */) = cpu.edx;
L_0x004ee808:
    // 004ee808  8984244c010000         -mov dword ptr [esp + 0x14c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */) = cpu.eax;
L_0x004ee80f:
    // 004ee80f  83bc244c01000000       +cmp dword ptr [esp + 0x14c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee817  745b                   -je 0x4ee874
    if (cpu.flags.zf)
    {
        goto L_0x004ee874;
    }
    // 004ee819  8b942430010000         -mov edx, dword ptr [esp + 0x130]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004ee820  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee822  ff942438010000         -call dword ptr [esp + 0x138]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee829  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee82b  7f47                   -jg 0x4ee874
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ee874;
    }
    // 004ee82d  7539                   -jne 0x4ee868
    if (!cpu.flags.zf)
    {
        goto L_0x004ee868;
    }
    // 004ee82f  83bc243c01000000       +cmp dword ptr [esp + 0x13c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee837  7412                   -je 0x4ee84b
    if (cpu.flags.zf)
    {
        goto L_0x004ee84b;
    }
    // 004ee839  8bb42440010000         -mov esi, dword ptr [esp + 0x140]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004ee840  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ee842  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ee844  e887fcffff             -call 0x4ee4d0
    cpu.esp -= 4;
    sub_4ee4d0(app, cpu);
    if (cpu.terminate) return;
    // 004ee849  eb16                   -jmp 0x4ee861
    goto L_0x004ee861;
L_0x004ee84b:
    // 004ee84b  8bbc2440010000         -mov edi, dword ptr [esp + 0x140]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004ee852  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004ee859  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004ee85b  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee85d  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ee85f  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
L_0x004ee861:
    // 004ee861  01ac2440010000         -add dword ptr [esp + 0x140], ebp
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */)) += x86::reg32(x86::sreg32(cpu.ebp));
L_0x004ee868:
    // 004ee868  8b84244c010000         -mov eax, dword ptr [esp + 0x14c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 004ee86f  48                     -dec eax
    (cpu.eax)--;
    // 004ee870  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee872  eb94                   -jmp 0x4ee808
    goto L_0x004ee808;
L_0x004ee874:
    // 004ee874  83bc244c01000000       +cmp dword ptr [esp + 0x14c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee87c  0f848b000000           -je 0x4ee90d
    if (cpu.flags.zf)
    {
        goto L_0x004ee90d;
    }
    // 004ee882  8b942430010000         -mov edx, dword ptr [esp + 0x130]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004ee889  8b842448010000         -mov eax, dword ptr [esp + 0x148]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee890  ff942438010000         -call dword ptr [esp + 0x138]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ee897  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ee899  7c72                   -jl 0x4ee90d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ee90d;
    }
    // 004ee89b  754c                   -jne 0x4ee8e9
    if (!cpu.flags.zf)
    {
        goto L_0x004ee8e9;
    }
    // 004ee89d  83bc243c01000000       +cmp dword ptr [esp + 0x13c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee8a5  7417                   -je 0x4ee8be
    if (cpu.flags.zf)
    {
        goto L_0x004ee8be;
    }
    // 004ee8a7  8bbc2444010000         -mov edi, dword ptr [esp + 0x144]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 004ee8ae  8bb42448010000         -mov esi, dword ptr [esp + 0x148]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee8b5  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ee8b7  e814fcffff             -call 0x4ee4d0
    cpu.esp -= 4;
    sub_4ee4d0(app, cpu);
    if (cpu.terminate) return;
    // 004ee8bc  eb24                   -jmp 0x4ee8e2
    goto L_0x004ee8e2;
L_0x004ee8be:
    // 004ee8be  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 004ee8c5  8b942448010000         -mov edx, dword ptr [esp + 0x148]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee8cc  8b8c2448010000         -mov ecx, dword ptr [esp + 0x148]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee8d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ee8d5  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ee8d7  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004ee8d9  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 004ee8e0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004ee8e2:
    // 004ee8e2  29ac2444010000         -sub dword ptr [esp + 0x144], ebp
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */)) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004ee8e9:
    // 004ee8e9  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee8f0  8b84244c010000         -mov eax, dword ptr [esp + 0x14c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 004ee8f7  29ef                   +sub edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee8f9  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee8fa  89bc2448010000         -mov dword ptr [esp + 0x148], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */) = cpu.edi;
    // 004ee901  8984244c010000         -mov dword ptr [esp + 0x14c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */) = cpu.eax;
    // 004ee908  e967ffffff             -jmp 0x4ee874
    goto L_0x004ee874;
L_0x004ee90d:
    // 004ee90d  83bc244c01000000       +cmp dword ptr [esp + 0x14c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee915  7464                   -je 0x4ee97b
    if (cpu.flags.zf)
    {
        goto L_0x004ee97b;
    }
    // 004ee917  83bc243c01000000       +cmp dword ptr [esp + 0x13c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ee91f  7412                   -je 0x4ee933
    if (cpu.flags.zf)
    {
        goto L_0x004ee933;
    }
    // 004ee921  8bbc2448010000         -mov edi, dword ptr [esp + 0x148]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee928  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ee92a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ee92c  e89ffbffff             -call 0x4ee4d0
    cpu.esp -= 4;
    sub_4ee4d0(app, cpu);
    if (cpu.terminate) return;
    // 004ee931  eb16                   -jmp 0x4ee949
    goto L_0x004ee949;
L_0x004ee933:
    // 004ee933  8b942448010000         -mov edx, dword ptr [esp + 0x148]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee93a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ee93c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004ee93e  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004ee940  8b942448010000         -mov edx, dword ptr [esp + 0x148]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee947  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004ee949:
    // 004ee949  8bbc244c010000         -mov edi, dword ptr [esp + 0x14c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */);
    // 004ee950  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee952  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee953  89bc244c010000         -mov dword ptr [esp + 0x14c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */) = cpu.edi;
    // 004ee95a  741f                   -je 0x4ee97b
    if (cpu.flags.zf)
    {
        goto L_0x004ee97b;
    }
    // 004ee95c  8b942448010000         -mov edx, dword ptr [esp + 0x148]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee963  8d4fff                 -lea ecx, [edi - 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004ee966  29ea                   +sub edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee968  898c244c010000         -mov dword ptr [esp + 0x14c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(332) /* 0x14c */) = cpu.ecx;
    // 004ee96f  89942448010000         -mov dword ptr [esp + 0x148], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */) = cpu.edx;
    // 004ee976  e994feffff             -jmp 0x4ee80f
    goto L_0x004ee80f;
L_0x004ee97b:
    // 004ee97b  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004ee982  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004ee985  8b94242c010000         -mov edx, dword ptr [esp + 0x12c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee98c  8b8c2440010000         -mov ecx, dword ptr [esp + 0x140]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004ee993  8bb4242c010000         -mov esi, dword ptr [esp + 0x12c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee99a  8bbc2440010000         -mov edi, dword ptr [esp + 0x140]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004ee9a1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ee9a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ee9a5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ee9a7  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ee9a9  89942418010000         -mov dword ptr [esp + 0x118], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */) = cpu.edx;
    // 004ee9b0  39c1                   +cmp ecx, eax
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
    // 004ee9b2  7c02                   -jl 0x4ee9b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ee9b6;
    }
    // 004ee9b4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004ee9b6:
    // 004ee9b6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ee9b8  7630                   -jbe 0x4ee9ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee9ea;
    }
    // 004ee9ba  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ee9bc  8bb4242c010000         -mov esi, dword ptr [esp + 0x12c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004ee9c3  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ee9c5  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004ee9c6  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004ee9c7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004ee9c8  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004ee9cb  c1e902                 +shr ecx, 2
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
    // 004ee9ce  740b                   -je 0x4ee9db
    if (cpu.flags.zf)
    {
        goto L_0x004ee9db;
    }
L_0x004ee9d0:
    // 004ee9d0  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004ee9d2  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = *app->getMemory<x86::reg32>(cpu.esi);
        *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004ee9d4  ab                     -stosd dword ptr es:[edi], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004ee9d5  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ee9d8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee9d9  75f5                   -jne 0x4ee9d0
    if (!cpu.flags.zf)
    {
        goto L_0x004ee9d0;
    }
L_0x004ee9db:
    // 004ee9db  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004ee9de  7409                   -je 0x4ee9e9
    if (cpu.flags.zf)
    {
        goto L_0x004ee9e9;
    }
L_0x004ee9e0:
    // 004ee9e0  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 004ee9e2  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = *app->getMemory<x86::reg8>(cpu.esi);
        *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004ee9e4  aa                     -stosb byte ptr es:[edi], al
    *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004ee9e5  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ee9e6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ee9e7  75f7                   -jne 0x4ee9e0
    if (!cpu.flags.zf)
    {
        goto L_0x004ee9e0;
    }
L_0x004ee9e9:
    // 004ee9e9  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004ee9ea:
    // 004ee9ea  8b842418010000         -mov eax, dword ptr [esp + 0x118]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004ee9f1  8b942444010000         -mov edx, dword ptr [esp + 0x144]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 004ee9f8  8bb42448010000         -mov esi, dword ptr [esp + 0x148]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004ee9ff  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004eea01  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004eea03  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004eea05  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004eea07  39c1                   +cmp ecx, eax
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
    // 004eea09  7202                   -jb 0x4eea0d
    if (cpu.flags.cf)
    {
        goto L_0x004eea0d;
    }
    // 004eea0b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004eea0d:
    // 004eea0d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004eea0f  7630                   -jbe 0x4eea41
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004eea41;
    }
    // 004eea11  8bbc2418010000         -mov edi, dword ptr [esp + 0x118]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004eea18  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004eea1a  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eea1c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004eea1d  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004eea1e  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eea1f  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004eea22  c1e902                 +shr ecx, 2
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
    // 004eea25  740b                   -je 0x4eea32
    if (cpu.flags.zf)
    {
        goto L_0x004eea32;
    }
L_0x004eea27:
    // 004eea27  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 004eea29  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = *app->getMemory<x86::reg32>(cpu.esi);
        *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004eea2b  ab                     -stosd dword ptr es:[edi], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004eea2c  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004eea2f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004eea30  75f5                   -jne 0x4eea27
    if (!cpu.flags.zf)
    {
        goto L_0x004eea27;
    }
L_0x004eea32:
    // 004eea32  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004eea35  7409                   -je 0x4eea40
    if (cpu.flags.zf)
    {
        goto L_0x004eea40;
    }
L_0x004eea37:
    // 004eea37  8a07                   -mov al, byte ptr [edi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi);
    // 004eea39  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = *app->getMemory<x86::reg8>(cpu.esi);
        *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004eea3b  aa                     -stosb byte ptr es:[edi], al
    *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004eea3c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eea3d  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004eea3e  75f7                   -jne 0x4eea37
    if (!cpu.flags.zf)
    {
        goto L_0x004eea37;
    }
L_0x004eea40:
    // 004eea40  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004eea41:
    // 004eea41  8bbc2440010000         -mov edi, dword ptr [esp + 0x140]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004eea48  8b842448010000         -mov eax, dword ptr [esp + 0x148]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(328) /* 0x148 */);
    // 004eea4f  8b8c2414010000         -mov ecx, dword ptr [esp + 0x114]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004eea56  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004eea58  8b9c2444010000         -mov ebx, dword ptr [esp + 0x144]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 004eea5f  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004eea61  8bbc2418010000         -mov edi, dword ptr [esp + 0x118]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004eea68  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004eea6a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004eea6d  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eea6f  39f3                   +cmp ebx, esi
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
    // 004eea71  7218                   -jb 0x4eea8b
    if (cpu.flags.cf)
    {
        goto L_0x004eea8b;
    }
    // 004eea73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eea75  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eea77  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004eea79  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eea7b  89840c80000000         -mov dword ptr [esp + ecx + 0x80], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */ + cpu.ecx * 1) = cpu.eax;
    // 004eea82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eea84  f7f5                   +div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004eea86  893c0c                 -mov dword ptr [esp + ecx], edi
    *app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1) = cpu.edi;
    // 004eea89  eb2c                   -jmp 0x4eeab7
    goto L_0x004eeab7;
L_0x004eea8b:
    // 004eea8b  39ee                   +cmp esi, ebp
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
    // 004eea8d  0f86d3fbffff           -jbe 0x4ee666
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ee666;
    }
    // 004eea93  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004eea9a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eea9c  89040c                 -mov dword ptr [esp + ecx], eax
    *app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1) = cpu.eax;
    // 004eea9f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eeaa1  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004eeaa3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eeaa5  89840c80000000         -mov dword ptr [esp + ecx + 0x80], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */ + cpu.ecx * 1) = cpu.eax;
    // 004eeaac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eeaae  f7f5                   +div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004eeab0  89bc242c010000         -mov dword ptr [esp + 0x12c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.edi;
L_0x004eeab7:
    // 004eeab7  89842420010000         -mov dword ptr [esp + 0x120], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 004eeabe  ff842414010000         +inc dword ptr [esp + 0x114]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eeac5  e996faffff             -jmp 0x4ee560
    goto L_0x004ee560;
L_0x004eeaca:
    // 004eeaca  81c450010000           -add esp, 0x150
    (cpu.esp) += x86::reg32(x86::sreg32(336 /*0x150*/));
    // 004eead0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eead1  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eead3  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eead5  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eead6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eead7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eead8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eeae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eeae0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eeae1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eeae2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eeae3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eeae4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eeae7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eeae9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004eeaeb  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004eeaed  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eeaf1  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eeaf5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004eeaf7  e8e43fffff             -call 0x4e2ae0
    cpu.esp -= 4;
    sub_4e2ae0(app, cpu);
    if (cpu.terminate) return;
    // 004eeafc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eeafe  7544                   -jne 0x4eeb44
    if (!cpu.flags.zf)
    {
        goto L_0x004eeb44;
    }
    // 004eeb00  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eeb07  750a                   -jne 0x4eeb13
    if (!cpu.flags.zf)
    {
        goto L_0x004eeb13;
    }
L_0x004eeb09:
    // 004eeb09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eeb0b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eeb0e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb0f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb11  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eeb13:
    // 004eeb13  ba40c25400             -mov edx, 0x54c240
    cpu.edx = 5554752 /*0x54c240*/;
    // 004eeb18  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eeb19  b950c25400             -mov ecx, 0x54c250
    cpu.ecx = 5554768 /*0x54c250*/;
    // 004eeb1e  bb60000000             -mov ebx, 0x60
    cpu.ebx = 96 /*0x60*/;
    // 004eeb23  685cc25400             -push 0x54c25c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554780 /*0x54c25c*/;
    cpu.esp -= 4;
    // 004eeb28  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004eeb2e  890d94215500           -mov dword ptr [0x552194], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004eeb34  891d98215500           -mov dword ptr [0x552198], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004eeb3a  e8d124f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004eeb3f  83c408                 +add esp, 8
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
    // 004eeb42  ebc5                   -jmp 0x4eeb09
    goto L_0x004eeb09;
L_0x004eeb44:
    // 004eeb44  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004eeb47  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004eeb49  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004eeb4b  e8d042ffff             -call 0x4e2e20
    cpu.esp -= 4;
    sub_4e2e20(app, cpu);
    if (cpu.terminate) return;
    // 004eeb50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eeb52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eeb54  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004eeb57  e84442ffff             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 004eeb5c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eeb5e  7538                   -jne 0x4eeb98
    if (!cpu.flags.zf)
    {
        goto L_0x004eeb98;
    }
    // 004eeb60  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eeb67  742f                   -je 0x4eeb98
    if (cpu.flags.zf)
    {
        goto L_0x004eeb98;
    }
    // 004eeb69  bb40c25400             -mov ebx, 0x54c240
    cpu.ebx = 5554752 /*0x54c240*/;
    // 004eeb6e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eeb6f  bf50c25400             -mov edi, 0x54c250
    cpu.edi = 5554768 /*0x54c250*/;
    // 004eeb74  bd6a000000             -mov ebp, 0x6a
    cpu.ebp = 106 /*0x6a*/;
    // 004eeb79  6888c25400             -push 0x54c288
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554824 /*0x54c288*/;
    cpu.esp -= 4;
    // 004eeb7e  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 004eeb84  893d94215500           -mov dword ptr [0x552194], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004eeb8a  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004eeb90  e87b24f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004eeb95  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004eeb98:
    // 004eeb98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004eeb9a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004eeb9d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb9e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeb9f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeba0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeba1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4eebb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eebb0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eebb1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eebb2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004eebb4  8b0d0c445600           -mov ecx, dword ptr [0x56440c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004eebba  89350c445600           -mov dword ptr [0x56440c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.esi;
    // 004eebc0  e81bffffff             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 004eebc5  890d0c445600           -mov dword ptr [0x56440c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */) = cpu.ecx;
    // 004eebcb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eebcc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eebcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4eebd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eebd0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eebd1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eebd2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eebd3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004eebd6  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004eebda  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004eebde  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004eebe0  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004eebe2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004eebe5  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eebeb  f6410c02               +test byte ptr [ecx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 004eebef  751e                   -jne 0x4eec0f
    if (!cpu.flags.zf)
    {
        goto L_0x004eec0f;
    }
    // 004eebf1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004eebf6  e8853c0100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004eebfb  80490c20               -or byte ptr [ecx + 0xc], 0x20
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004eebff  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004eec02  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eec08  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004eec0a  e9c7010000             -jmp 0x4eedd6
    goto L_0x004eedd6;
L_0x004eec0f:
    // 004eec0f  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004eec12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004eec14  7512                   -jne 0x4eec28
    if (!cpu.flags.zf)
    {
        goto L_0x004eec28;
    }
    // 004eec16  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004eec19  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eec1f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004eec21  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004eec24  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eec25  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eec26  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eec27  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eec28:
    // 004eec28  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004eec2b  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004eec2f  7507                   -jne 0x4eec38
    if (!cpu.flags.zf)
    {
        goto L_0x004eec38;
    }
    // 004eec31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004eec33  e8883d0100             -call 0x5029c0
    cpu.esp -= 4;
    sub_5029c0(app, cpu);
    if (cpu.terminate) return;
L_0x004eec38:
    // 004eec38  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004eec3b  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004eec3e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eec40  83e030                 -and eax, 0x30
    cpu.eax &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004eec43  80e2cf                 -and dl, 0xcf
    cpu.dl &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 004eec46  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004eec4a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004eec4d  88550c                 -mov byte ptr [ebp + 0xc], dl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004eec50  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 004eec53  0f84e1000000           -je 0x4eed3a
    if (cpu.flags.zf)
    {
        goto L_0x004eed3a;
    }
    // 004eec59  897c2410               -mov dword ptr [esp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x004eec5d:
    // 004eec5d  837d0400               +cmp dword ptr [ebp + 4], 0
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
    // 004eec61  7544                   -jne 0x4eeca7
    if (!cpu.flags.zf)
    {
        goto L_0x004eeca7;
    }
    // 004eec63  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004eec67  3b4514                 +cmp eax, dword ptr [ebp + 0x14]
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
    // 004eec6a  723b                   -jb 0x4eeca7
    if (cpu.flags.cf)
    {
        goto L_0x004eeca7;
    }
    // 004eec6c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eec6e  30c3                   -xor bl, al
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.al));
    // 004eec70  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004eec73  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eec75  7502                   -jne 0x4eec79
    if (!cpu.flags.zf)
    {
        goto L_0x004eec79;
    }
    // 004eec77  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004eec79:
    // 004eec79  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eec7d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004eec80  e83baa0100             -call 0x5096c0
    cpu.esp -= 4;
    sub_5096c0(app, cpu);
    if (cpu.terminate) return;
    // 004eec85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eec87  83f8ff                 +cmp eax, -1
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
    // 004eec8a  7415                   -je 0x4eeca1
    if (cpu.flags.zf)
    {
        goto L_0x004eeca1;
    }
    // 004eec8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eec8e  0f8573000000           -jne 0x4eed07
    if (!cpu.flags.zf)
    {
        goto L_0x004eed07;
    }
    // 004eec94  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eec9a  c740040c000000         -mov dword ptr [eax + 4], 0xc
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
L_0x004eeca1:
    // 004eeca1  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004eeca5  eb60                   -jmp 0x4eed07
    goto L_0x004eed07;
L_0x004eeca7:
    // 004eeca7  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004eecaa  8b7504                 -mov esi, dword ptr [ebp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004eecad  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004eecb1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004eecb3  39fa                   +cmp edx, edi
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
    // 004eecb5  7602                   -jbe 0x4eecb9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004eecb9;
    }
    // 004eecb7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004eecb9:
    // 004eecb9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eecbd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004eecbf  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004eecc2  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004eecc3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004eecc5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004eecc7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eecc8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004eecca  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004eeccd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004eeccf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004eecd1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004eecd4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004eecd6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eecd7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eecd8  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004eecdb  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp);
    // 004eecde  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eece0  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004eece3  895d04                 -mov dword ptr [ebp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004eece6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eece8  8a7d0d                 -mov bh, byte ptr [ebp + 0xd]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004eeceb  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004eecee  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004eecf1  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004eecf4  887d0d                 -mov byte ptr [ebp + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004eecf7  39c8                   +cmp eax, ecx
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
    // 004eecf9  7405                   -je 0x4eed00
    if (cpu.flags.zf)
    {
        goto L_0x004eed00;
    }
    // 004eecfb  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 004eecfe  7407                   -je 0x4eed07
    if (cpu.flags.zf)
    {
        goto L_0x004eed07;
    }
L_0x004eed00:
    // 004eed00  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eed02  e8593a0100             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
L_0x004eed07:
    // 004eed07  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eed0b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004eed0f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004eed13  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eed15  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004eed17  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004eed1b  897c240c               -mov dword ptr [esp + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004eed1f  29d0                   +sub eax, edx
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
    // 004eed21  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004eed25  0f847f000000           -je 0x4eedaa
    if (cpu.flags.zf)
    {
        goto L_0x004eedaa;
    }
    // 004eed2b  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004eed2f  0f8428ffffff           -je 0x4eec5d
    if (cpu.flags.zf)
    {
        goto L_0x004eec5d;
    }
    // 004eed35  e970000000             -jmp 0x4eedaa
    goto L_0x004eedaa;
L_0x004eed3a:
    // 004eed3a  8a5d0d                 -mov bl, byte ptr [ebp + 0xd]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004eed3d  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 004eed40  7414                   -je 0x4eed56
    if (cpu.flags.zf)
    {
        goto L_0x004eed56;
    }
    // 004eed42  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 004eed44  80e7fa                 -and bh, 0xfa
    cpu.bh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004eed47  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 004eed49  887d0d                 -mov byte ptr [ebp + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004eed4c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004eed4e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004eed53  88450d                 -mov byte ptr [ebp + 0xd], al
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x004eed56:
    // 004eed56  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004eed59  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004eed5d  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004eed60  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004eed67:
    // 004eed67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eed69  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004eed6b  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 004eed6d  e83eaa0100             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 004eed72  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004eed75  43                     -inc ebx
    (cpu.ebx)++;
    // 004eed76  f6c230                 +test dl, 0x30
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 48 /*0x30*/));
    // 004eed79  750d                   -jne 0x4eed88
    if (!cpu.flags.zf)
    {
        goto L_0x004eed88;
    }
    // 004eed7b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004eed7f  40                     -inc eax
    (cpu.eax)++;
    // 004eed80  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004eed84  39c7                   +cmp edi, eax
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
    // 004eed86  75df                   -jne 0x4eed67
    if (!cpu.flags.zf)
    {
        goto L_0x004eed67;
    }
L_0x004eed88:
    // 004eed88  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004eed8b  89700c                 -mov dword ptr [eax + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004eed8e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004eed90  7418                   -je 0x4eedaa
    if (cpu.flags.zf)
    {
        goto L_0x004eedaa;
    }
    // 004eed92  8a750d                 -mov dh, byte ptr [ebp + 0xd]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 004eed95  80e6fa                 -and dh, 0xfa
    cpu.dh &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004eed98  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004eed9a  88750d                 -mov byte ptr [ebp + 0xd], dh
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.dh;
    // 004eed9d  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004eeda0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eeda2  885d0d                 -mov byte ptr [ebp + 0xd], bl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004eeda5  e8b6390100             -call 0x502760
    cpu.esp -= 4;
    sub_502760(app, cpu);
    if (cpu.terminate) return;
L_0x004eedaa:
    // 004eedaa  f6450c20               +test byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004eedae  7406                   -je 0x4eedb6
    if (cpu.flags.zf)
    {
        goto L_0x004eedb6;
    }
    // 004eedb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004eedb2  895c240c               -mov dword ptr [esp + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004eedb6:
    // 004eedb6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004eedb9  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004eedbd  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004eedc0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004eedc2  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004eedc4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004eedc7  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004eedca  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eedd0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004eedd4  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004eedd6:
    // 004eedd6  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004eedd9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eedda  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeddb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeddc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4eede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eede0  83f861                 +cmp eax, 0x61
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
    // 004eede3  7c08                   -jl 0x4eeded
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eeded;
    }
    // 004eede5  83f87a                 +cmp eax, 0x7a
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
    // 004eede8  7f03                   -jg 0x4eeded
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004eeded;
    }
    // 004eedea  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004eeded:
    // 004eeded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4eedf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eedf0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eedf1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eedf2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eedf3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eedf4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004eedf6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004eedf8  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004eedfd  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004eedff  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004eee01  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004eee02  e30b                   -jecxz 0x4eee0f
    if (cpu.ecx == 0)
    {
        goto L_0x004eee0f;
    }
    // 004eee04  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004eee06  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004eee08  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004eee0a  7503                   -jne 0x4eee0f
    if (!cpu.flags.zf)
    {
        goto L_0x004eee0f;
    }
    // 004eee0c  4f                     -dec edi
    (cpu.edi)--;
    // 004eee0d  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x004eee11;
L_0x004eee0f:
    // 004eee0f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x004eee11:
    // 004eee11  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004eee12  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004eee14  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eee16  740d                   -je 0x4eee25
    if (cpu.flags.zf)
    {
        goto L_0x004eee25;
    }
L_0x004eee18:
    // 004eee18  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi);
    // 004eee1a  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004eee1c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004eee1e  7405                   -je 0x4eee25
    if (cpu.flags.zf)
    {
        goto L_0x004eee25;
    }
    // 004eee20  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eee21  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004eee22  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004eee23  75f3                   -jne 0x4eee18
    if (!cpu.flags.zf)
    {
        goto L_0x004eee18;
    }
L_0x004eee25:
    // 004eee25  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004eee28  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004eee2a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eee2b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eee2c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eee2d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eee2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4eee30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eee30  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eee31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eee32  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004eee33  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004eee36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004eee38  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004eee3c  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004eee40  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eee42  0f8478000000           -je 0x4eeec0
    if (cpu.flags.zf)
    {
        goto L_0x004eeec0;
    }
L_0x004eee48:
    // 004eee48  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eee4c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eee4e  0f857a000000           -jne 0x4eeece
    if (!cpu.flags.zf)
    {
        goto L_0x004eeece;
    }
    // 004eee54  c744242408000000       -mov dword ptr [esp + 0x24], 8
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 8 /*0x8*/;
L_0x004eee5c:
    // 004eee5c  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
L_0x004eee60:
    // 004eee60  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004eee62  7c08                   -jl 0x4eee6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eee6c;
    }
    // 004eee64  81ff00400000           +cmp edi, 0x4000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eee6a  7e6e                   -jle 0x4eeeda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004eeeda;
    }
L_0x004eee6c:
    // 004eee6c  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 004eee71  7442                   -je 0x4eeeb5
    if (cpu.flags.zf)
    {
        goto L_0x004eeeb5;
    }
    // 004eee73  6800200000             -push 0x2000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8192 /*0x2000*/;
    cpu.esp -= 4;
    // 004eee78  6800400000             -push 0x4000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 16384 /*0x4000*/;
    cpu.esp -= 4;
    // 004eee7d  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004eee81  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eee82  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004eee86  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eee87  beb4c25400             -mov esi, 0x54c2b4
    cpu.esi = 5554868 /*0x54c2b4*/;
    // 004eee8c  bdc4c25400             -mov ebp, 0x54c2c4
    cpu.ebp = 5554884 /*0x54c2c4*/;
    // 004eee91  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eee92  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004eee97  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004eee9d  68d8c25400             -push 0x54c2d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554904 /*0x54c2d8*/;
    cpu.esp -= 4;
    // 004eeea2  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004eeea8  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004eeead  e85e21f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004eeeb2  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x004eeeb5:
    // 004eeeb5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eeeb7  83c428                 +add esp, 0x28
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
    // 004eeeba  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeebb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeebc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eeebd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004eeec0:
    // 004eeec0  a18c435600             -mov eax, dword ptr [0x56438c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 004eeec5  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004eeec9  e97affffff             -jmp 0x4eee48
    goto L_0x004eee48;
L_0x004eeece:
    // 004eeece  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eeed1  7589                   -jne 0x4eee5c
    if (!cpu.flags.zf)
    {
        goto L_0x004eee5c;
    }
    // 004eeed3  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 004eeed8  eb86                   -jmp 0x4eee60
    goto L_0x004eee60;
L_0x004eeeda:
    // 004eeeda  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004eeede  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eeee0  7c8a                   -jl 0x4eee6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004eee6c;
    }
    // 004eeee2  3d00200000             +cmp eax, 0x2000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004eeee7  7f83                   -jg 0x4eee6c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004eee6c;
    }
    // 004eeee9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eeeed  e8dea90100             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 004eeef2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eeef4  754a                   -jne 0x4eef40
    if (!cpu.flags.zf)
    {
        goto L_0x004eef40;
    }
    // 004eeef6  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 004eeefb  74b8                   -je 0x4eeeb5
    if (cpu.flags.zf)
    {
        goto L_0x004eeeb5;
    }
    // 004eeefd  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eef01  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eef02  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eef06  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eef07  beb4c25400             -mov esi, 0x54c2b4
    cpu.esi = 5554868 /*0x54c2b4*/;
    // 004eef0c  bdc4c25400             -mov ebp, 0x54c2c4
    cpu.ebp = 5554884 /*0x54c2c4*/;
    // 004eef11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eef12  b85f000000             -mov eax, 0x5f
    cpu.eax = 95 /*0x5f*/;
    // 004eef17  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004eef1d  6828c35400             -push 0x54c328
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5554984 /*0x54c328*/;
    cpu.esp -= 4;
    // 004eef22  892d94215500           -mov dword ptr [0x552194], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 004eef28  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004eef2d  e8de20f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004eef32  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004eef35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004eef37  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004eef3a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eef3b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eef3c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eef3d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004eef40:
    // 004eef40  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004eef42  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004eef45  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004eef48  80e2f8                 -and dl, 0xf8
    cpu.dl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004eef4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004eef4d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004eef50  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004eef52  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004eef55  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004eef58  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004eef5c  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004eef60  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004eef63  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004eef67  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eef68  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eef69  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004eef6a  83c048                 -add eax, 0x48
    (cpu.eax) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 004eef6d  687cc35400             -push 0x54c37c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555068 /*0x54c37c*/;
    cpu.esp -= 4;
    // 004eef72  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004eef76  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004eef7a  be6a000000             -mov esi, 0x6a
    cpu.esi = 106 /*0x6a*/;
    // 004eef7f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eef80  bab4c25400             -mov edx, 0x54c2b4
    cpu.edx = 5554868 /*0x54c2b4*/;
    // 004eef85  bbc4c25400             -mov ebx, 0x54c2c4
    cpu.ebx = 5554884 /*0x54c2c4*/;
    // 004eef8a  e80107ffff             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004eef8f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004eef93  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004eef96  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004eef9c  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004eefa2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004eefa6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004eefa8  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004eefae  e86d26ffff             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004eefb3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004eefb5  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004eefb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eefbb  7567                   -jne 0x4ef024
    if (!cpu.flags.zf)
    {
        goto L_0x004ef024;
    }
    // 004eefbd  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 004eefc2  0f84edfeffff           -je 0x4eeeb5
    if (cpu.flags.zf)
    {
        goto L_0x004eeeb5;
    }
    // 004eefc8  b9b4c25400             -mov ecx, 0x54c2b4
    cpu.ecx = 5554868 /*0x54c2b4*/;
    // 004eefcd  bbc4c25400             -mov ebx, 0x54c2c4
    cpu.ebx = 5554884 /*0x54c2c4*/;
    // 004eefd2  be70000000             -mov esi, 0x70
    cpu.esi = 112 /*0x70*/;
    // 004eefd7  8b2d00445600           -mov ebp, dword ptr [0x564400]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5653504) /* 0x564400 */);
    // 004eefdd  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004eefe3  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004eefe9  45                     -inc ebp
    (cpu.ebp)++;
    // 004eefea  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004eeff0  892d00445600           -mov dword ptr [0x564400], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5653504) /* 0x564400 */) = cpu.ebp;
    // 004eeff6  e88525ffff             -call 0x4e1580
    cpu.esp -= 4;
    sub_4e1580(app, cpu);
    if (cpu.terminate) return;
    // 004eeffb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004eeffc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ef000  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ef001  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004ef005  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef006  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004ef00a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef00b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef00c  6888c35400             -push 0x54c388
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555080 /*0x54c388*/;
    cpu.esp -= 4;
    // 004ef011  e8fa1ff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef016  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004ef019  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef01b  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ef01e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef01f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef020  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef021  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ef024:
    // 004ef024  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 004ef029  e8de16ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004ef02e  89742418               -mov dword ptr [esp + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004ef032  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef036  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004ef039  e892a80100             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 004ef03e  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004ef041  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef046  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ef048  66897a04               -mov word ptr [edx + 4], di
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.di;
    // 004ef04c  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef04e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ef052  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ef054  66894206               -mov word ptr [edx + 6], ax
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004ef058  c706444e4957           -mov dword ptr [esi], 0x57494e44
    *app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 004ef05e  897e04                 -mov dword ptr [esi + 4], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004ef061  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ef065  897e14                 -mov dword ptr [esi + 0x14], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004ef068  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ef06b  894618                 -mov dword ptr [esi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ef06e  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef072  88461c                 -mov byte ptr [esi + 0x1c], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 004ef075  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ef077  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef07c  895620                 -mov dword ptr [esi + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004ef07f  8b1d80835600           -mov ebx, dword ptr [0x568380]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5669760) /* 0x568380 */);
    // 004ef085  88461d                 -mov byte ptr [esi + 0x1d], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 004ef088  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ef08a  7557                   -jne 0x4ef0e3
    if (!cpu.flags.zf)
    {
        goto L_0x004ef0e3;
    }
    // 004ef08c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef08e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ef092  e8f927ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004ef097  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ef099  0f8416feffff           -je 0x4eeeb5
    if (cpu.flags.zf)
    {
        goto L_0x004eeeb5;
    }
    // 004ef09f  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef0a3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef0a4  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef0a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ef0a9  b9b4c25400             -mov ecx, 0x54c2b4
    cpu.ecx = 5554868 /*0x54c2b4*/;
    // 004ef0ae  bbc4c25400             -mov ebx, 0x54c2c4
    cpu.ebx = 5554884 /*0x54c2c4*/;
    // 004ef0b3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef0b4  be8b000000             -mov esi, 0x8b
    cpu.esi = 139 /*0x8b*/;
    // 004ef0b9  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ef0bf  68d8c35400             -push 0x54c3d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555160 /*0x54c3d8*/;
    cpu.esp -= 4;
    // 004ef0c4  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ef0ca  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004ef0d0  e83b1ff1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef0d5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ef0d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef0da  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ef0dd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef0de  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef0df  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef0e0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ef0e3:
    // 004ef0e3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ef0e7  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ef0eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef0ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef0ef  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004ef0f2  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004ef0f7  e834a90100             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 004ef0fc  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004ef101  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ef103  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ef105  89462c                 -mov dword ptr [esi + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004ef108  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef10a  e821a90100             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 004ef10f  8b6e2c                 -mov ebp, dword ptr [esi + 0x2c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004ef112  894630                 -mov dword ptr [esi + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004ef115  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ef117  7558                   -jne 0x4ef171
    if (!cpu.flags.zf)
    {
        goto L_0x004ef171;
    }
L_0x004ef119:
    // 004ef119  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ef11d  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ef121  e86a27ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004ef126  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ef128  7434                   -je 0x4ef15e
    if (cpu.flags.zf)
    {
        goto L_0x004ef15e;
    }
    // 004ef12a  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ef12e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef12f  b9b4c25400             -mov ecx, 0x54c2b4
    cpu.ecx = 5554868 /*0x54c2b4*/;
    // 004ef134  bbc4c25400             -mov ebx, 0x54c2c4
    cpu.ebx = 5554884 /*0x54c2c4*/;
    // 004ef139  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef13a  be99000000             -mov esi, 0x99
    cpu.esi = 153 /*0x99*/;
    // 004ef13f  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ef145  6844c45400             -push 0x54c444
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555268 /*0x54c444*/;
    cpu.esp -= 4;
    // 004ef14a  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ef150  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004ef156  e8b51ef1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef15b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004ef15e:
    // 004ef15e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef160  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ef164  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ef168  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ef16b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef16c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef16d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef16e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ef171:
    // 004ef171  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ef173  74a4                   -je 0x4ef119
    if (cpu.flags.zf)
    {
        goto L_0x004ef119;
    }
    // 004ef175  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ef179  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ef17c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef17d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef17e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef17f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4ef190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef190  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef191  8b350c445600           -mov esi, dword ptr [0x56440c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
    // 004ef197  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef198  e893fcffff             -call 0x4eee30
    cpu.esp -= 4;
    sub_4eee30(app, cpu);
    if (cpu.terminate) return;
    // 004ef19d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef19e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ef1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef1a0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ef1a2  e889fcffff             -call 0x4eee30
    cpu.esp -= 4;
    sub_4eee30(app, cpu);
    if (cpu.terminate) return;
    // 004ef1a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ef1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef1b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef1b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef1b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef1b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef1b4  8b0d0c505600           -mov ecx, dword ptr [0x56500c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */);
    // 004ef1ba  8b1504505600           -mov edx, dword ptr [0x565004]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */);
    // 004ef1c0  8b1d00505600           -mov ebx, dword ptr [0x565000]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */);
    // 004ef1c6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ef1c7  a108505600             -mov eax, dword ptr [0x565008]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */);
    // 004ef1cc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ef1ce  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef1d0  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ef1d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ef1d4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef1d6  e865e30000             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 004ef1db  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef1dc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef1dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef1de  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef1df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ef1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef1e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef1e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef1e2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef1e3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ef1e5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ef1e7  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ef1ea  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ef1ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ef1ee  741e                   -je 0x4ef20e
    if (cpu.flags.zf)
    {
        goto L_0x004ef20e;
    }
    // 004ef1f0  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004ef1f7  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ef1f9:
    // 004ef1f9  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ef1fc  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef1fd  7405                   -je 0x4ef204
    if (cpu.flags.zf)
    {
        goto L_0x004ef204;
    }
    // 004ef1ff  3b4a10                 +cmp ecx, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef202  75f5                   -jne 0x4ef1f9
    if (!cpu.flags.zf)
    {
        goto L_0x004ef1f9;
    }
L_0x004ef204:
    // 004ef204  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ef207  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef209  3b4810                 +cmp ecx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef20c  7458                   -je 0x4ef266
    if (cpu.flags.zf)
    {
        goto L_0x004ef266;
    }
L_0x004ef20e:
    // 004ef20e  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef215  7449                   -je 0x4ef260
    if (cpu.flags.zf)
    {
        goto L_0x004ef260;
    }
    // 004ef217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef219  e8e2a90100             -call 0x509c00
    cpu.esp -= 4;
    sub_509c00(app, cpu);
    if (cpu.terminate) return;
    // 004ef21e  e8bd23ffff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 004ef223  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ef227  7505                   -jne 0x4ef22e
    if (!cpu.flags.zf)
    {
        goto L_0x004ef22e;
    }
    // 004ef229  ba7cc45400             -mov edx, 0x54c47c
    cpu.edx = 5555324 /*0x54c47c*/;
L_0x004ef22e:
    // 004ef22e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef22f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef230  b980c45400             -mov ecx, 0x54c480
    cpu.ecx = 5555328 /*0x54c480*/;
    // 004ef235  bb90c45400             -mov ebx, 0x54c490
    cpu.ebx = 5555344 /*0x54c490*/;
    // 004ef23a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef23b  bf4f000000             -mov edi, 0x4f
    cpu.edi = 79 /*0x4f*/;
    // 004ef240  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ef246  689cc45400             -push 0x54c49c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555356 /*0x54c49c*/;
    cpu.esp -= 4;
    // 004ef24b  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ef251  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004ef257  e8b41df1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef25c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ef25f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ef260:
    // 004ef260  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef262  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef263  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef264  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef265  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef266:
    // 004ef266  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ef269  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef26b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef26c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef26d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef26e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ef270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef270  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef271  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef272  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ef274  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ef277  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004ef279  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ef27b  7426                   -je 0x4ef2a3
    if (cpu.flags.zf)
    {
        goto L_0x004ef2a3;
    }
    // 004ef27d  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004ef284  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ef286:
    // 004ef286  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ef289  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef28a  7405                   -je 0x4ef291
    if (cpu.flags.zf)
    {
        goto L_0x004ef291;
    }
    // 004ef28c  3b4a10                 +cmp ecx, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef28f  75f5                   -jne 0x4ef286
    if (!cpu.flags.zf)
    {
        goto L_0x004ef286;
    }
L_0x004ef291:
    // 004ef291  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ef294  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef296  3b4810                 +cmp ecx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef299  7508                   -jne 0x4ef2a3
    if (!cpu.flags.zf)
    {
        goto L_0x004ef2a3;
    }
    // 004ef29b  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ef29e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef2a0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef2a1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef2a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef2a3:
    // 004ef2a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef2a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef2a6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef2a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ef2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef2b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef2b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef2b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef2b3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ef2b5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ef2b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef2b9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ef2bb  7e41                   -jle 0x4ef2fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ef2fe;
    }
L_0x004ef2bd:
    // 004ef2bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef2bf  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004ef2c1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ef2c3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004ef2c5  743b                   -je 0x4ef302
    if (cpu.flags.zf)
    {
        goto L_0x004ef302;
    }
    // 004ef2c7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef2c9  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 004ef2cb  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
L_0x004ef2ce:
    // 004ef2ce  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004ef2d0  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004ef2d2  7425                   -je 0x4ef2f9
    if (cpu.flags.zf)
    {
        goto L_0x004ef2f9;
    }
    // 004ef2d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef2d6  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004ef2d8  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ef2da  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004ef2dc  742f                   -je 0x4ef30d
    if (cpu.flags.zf)
    {
        goto L_0x004ef30d;
    }
    // 004ef2de  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004ef2e0  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004ef2e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef2e5  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004ef2e7  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef2ed  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x004ef2f0:
    // 004ef2f0  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef2f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef2f4  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004ef2f6  881431                 -mov byte ptr [ecx + esi], dl
    *app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.dl;
L_0x004ef2f9:
    // 004ef2f9  40                     -inc eax
    (cpu.eax)++;
    // 004ef2fa  39d8                   +cmp eax, ebx
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
    // 004ef2fc  7cbf                   -jl 0x4ef2bd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ef2bd;
    }
L_0x004ef2fe:
    // 004ef2fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef2ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef300  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef301  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef302:
    // 004ef302  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx);
    // 004ef304  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef306  80e20f                 +and dl, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/))));
    // 004ef309  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004ef30b  ebc1                   -jmp 0x4ef2ce
    goto L_0x004ef2ce;
L_0x004ef30d:
    // 004ef30d  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx);
    // 004ef30f  80e6f0                 -and dh, 0xf0
    cpu.dh &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004ef312  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef314  88f1                   -mov cl, dh
    cpu.cl = cpu.dh;
    // 004ef316  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004ef31c  ebd2                   -jmp 0x4ef2f0
    goto L_0x004ef2f0;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ef320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef320  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x004ef321:
    // 004ef321  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004ef323  40                     -inc eax
    (cpu.eax)++;
    // 004ef324  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ef327  7506                   -jne 0x4ef32f
    if (!cpu.flags.zf)
    {
        goto L_0x004ef32f;
    }
    // 004ef329  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ef32a  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef32b  75f4                   -jne 0x4ef321
    if (!cpu.flags.zf)
    {
        goto L_0x004ef321;
    }
    // 004ef32d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef32e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef32f:
    // 004ef32f  880a                   -mov byte ptr [edx], cl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004ef331  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ef332  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef333  75ec                   -jne 0x4ef321
    if (!cpu.flags.zf)
    {
        goto L_0x004ef321;
    }
    // 004ef335  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef336  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ef340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef340  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
L_0x004ef341:
    // 004ef341  668b08                 -mov cx, word ptr [eax]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax);
    // 004ef344  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004ef347  750b                   -jne 0x4ef354
    if (!cpu.flags.zf)
    {
        goto L_0x004ef354;
    }
    // 004ef349  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ef34c  83c002                 +add eax, 2
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
    // 004ef34f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef350  75ef                   -jne 0x4ef341
    if (!cpu.flags.zf)
    {
        goto L_0x004ef341;
    }
    // 004ef352  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef353  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef354:
    // 004ef354  66890a                 -mov word ptr [edx], cx
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ef357  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ef35a  83c002                 +add eax, 2
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
    // 004ef35d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef35e  75e1                   -jne 0x4ef341
    if (!cpu.flags.zf)
    {
        goto L_0x004ef341;
    }
    // 004ef360  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef361  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4ef370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef370  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef371  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef372  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef373  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 004ef378  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ef37a:
    // 004ef37a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004ef37c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef37e  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004ef382  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ef384  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ef38b  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ef38d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ef38f  750d                   -jne 0x4ef39e
    if (!cpu.flags.zf)
    {
        goto L_0x004ef39e;
    }
    // 004ef391  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ef394  83c603                 +add esi, 3
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ef397  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef398  75e0                   -jne 0x4ef37a
    if (!cpu.flags.zf)
    {
        goto L_0x004ef37a;
    }
    // 004ef39a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef39b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef39c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef39d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef39e:
    // 004ef39e  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004ef3a0  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004ef3a2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ef3a5  884201                 -mov byte ptr [edx + 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004ef3a8  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004ef3ab  884202                 -mov byte ptr [edx + 2], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004ef3ae  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ef3b1  83c603                 +add esi, 3
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ef3b4  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef3b5  75c3                   -jne 0x4ef37a
    if (!cpu.flags.zf)
    {
        goto L_0x004ef37a;
    }
    // 004ef3b7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3b8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ef3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef3c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef3c1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
L_0x004ef3c2:
    // 004ef3c2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ef3c4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004ef3c6  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004ef3c9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ef3cb  750c                   -jne 0x4ef3d9
    if (!cpu.flags.zf)
    {
        goto L_0x004ef3d9;
    }
    // 004ef3cd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ef3d0  83c004                 +add eax, 4
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
    // 004ef3d3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef3d4  75ec                   -jne 0x4ef3c2
    if (!cpu.flags.zf)
    {
        goto L_0x004ef3c2;
    }
    // 004ef3d6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3d7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef3d9:
    // 004ef3d9  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ef3db  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ef3de  83c004                 +add eax, 4
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
    // 004ef3e1  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ef3e2  75de                   -jne 0x4ef3c2
    if (!cpu.flags.zf)
    {
        goto L_0x004ef3c2;
    }
    // 004ef3e4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3e5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef3e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ef3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef3f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef3f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef3f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef3f3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef3f4  81ec04040000           -sub esp, 0x404
    (cpu.esp) -= x86::reg32(x86::sreg32(1028 /*0x404*/));
    // 004ef3fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ef3fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ef3fe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ef400  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004ef403  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004ef409  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef40b  83f804                 +cmp eax, 4
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
    // 004ef40e  0f8580000000           -jne 0x4ef494
    if (!cpu.flags.zf)
    {
        goto L_0x004ef494;
    }
    // 004ef414  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004ef416:
    // 004ef416  8b0cad14a8a000         -mov ecx, dword ptr [ebp*4 + 0xa0a814]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.ebp * 4);
    // 004ef41d  898c2400040000         -mov dword ptr [esp + 0x400], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.ecx;
    // 004ef424  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef426  890db4505600           -mov dword ptr [0x5650b4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5656756) /* 0x5650b4 */) = cpu.ecx;
    // 004ef42c  890cad14a8a000         -mov dword ptr [ebp*4 + 0xa0a814], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.ebp * 4) = cpu.ecx;
    // 004ef433  83fa08                 +cmp edx, 8
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
    // 004ef436  752d                   -jne 0x4ef465
    if (!cpu.flags.zf)
    {
        goto L_0x004ef465;
    }
    // 004ef438  803d1050560010         +cmp byte ptr [0x565010], 0x10
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ef43f  7524                   -jne 0x4ef465
    if (!cpu.flags.zf)
    {
        goto L_0x004ef465;
    }
    // 004ef441  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ef443  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef445  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 004ef44a  e8e1b30100             -call 0x50a830
    cpu.esp -= 4;
    sub_50a830(app, cpu);
    if (cpu.terminate) return;
    // 004ef44f  bac0af5000             -mov edx, 0x50afc0
    cpu.edx = 5287872 /*0x50afc0*/;
    // 004ef454  a3b0099f00             -mov dword ptr [0x9f09b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10422704) /* 0x9f09b0 */) = cpu.eax;
    // 004ef459  890dbc505600           -mov dword ptr [0x5650bc], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5656764) /* 0x5650bc */) = cpu.ecx;
    // 004ef45f  8915b4505600           -mov dword ptr [0x5650b4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5656756) /* 0x5650b4 */) = cpu.edx;
L_0x004ef465:
    // 004ef465  b99c505600             -mov ecx, 0x56509c
    cpu.ecx = 5656732 /*0x56509c*/;
    // 004ef46a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ef46c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef46e  e83dbc0100             -call 0x50b0b0
    cpu.esp -= 4;
    sub_50b0b0(app, cpu);
    if (cpu.terminate) return;
    // 004ef473  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef475  8b842400040000         -mov eax, dword ptr [esp + 0x400]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 004ef47c  891dbc505600           -mov dword ptr [0x5650bc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5656764) /* 0x5650bc */) = cpu.ebx;
    // 004ef482  8904ad14a8a000         -mov dword ptr [ebp*4 + 0xa0a814], eax
    *app->getMemory<x86::reg32>(x86::reg32(10528788) /* 0xa0a814 */ + cpu.ebp * 4) = cpu.eax;
    // 004ef489  81c404040000           +add esp, 0x404
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
    // 004ef48f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef490  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef491  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef492  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef493  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef494:
    // 004ef494  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004ef499  e978ffffff             -jmp 0x4ef416
    goto L_0x004ef416;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ef4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef4a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef4a1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef4a2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ef4a5  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ef4a8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004ef4ab  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004ef4ae  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004ef4b1  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004ef4b4  e837ffffff             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004ef4b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef4ba  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef4bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ef4c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef4c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef4c1  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ef4c4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ef4c7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef4c9  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004ef4cc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ef4cf  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef4d1  e81affffff             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004ef4d6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef4d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ef4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef4e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef4e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef4e2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ef4e5  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ef4e8  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004ef4eb  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 004ef4ee  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004ef4f1  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004ef4f4  e8f7feffff             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004ef4f9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef4fa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef4fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ef500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef500  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef501  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ef504  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ef507  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef509  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004ef50c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ef50f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef511  e8dafeffff             -call 0x4ef3f0
    cpu.esp -= 4;
    sub_4ef3f0(app, cpu);
    if (cpu.terminate) return;
    // 004ef516  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef517  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ef520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef520  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef521  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef522  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef523  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef524  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef525  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef527  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004ef52c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ef52e  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004ef530  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ef532  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ef539  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ef53b  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004ef53d  3d00544e46             +cmp eax, 0x464e5400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1179538432 /*0x464e5400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef542  7431                   -je 0x4ef575
    if (cpu.flags.zf)
    {
        goto L_0x004ef575;
    }
    // 004ef544  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef545  b9ccc45400             -mov ecx, 0x54c4cc
    cpu.ecx = 5555404 /*0x54c4cc*/;
    // 004ef54a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef54b  bbdcc45400             -mov ebx, 0x54c4dc
    cpu.ebx = 5555420 /*0x54c4dc*/;
    // 004ef550  be54000000             -mov esi, 0x54
    cpu.esi = 84 /*0x54*/;
    // 004ef555  68e4c45400             -push 0x54c4e4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555428 /*0x54c4e4*/;
    cpu.esp -= 4;
    // 004ef55a  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004ef560  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004ef566  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 004ef56c  e89f1af1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef571  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ef574  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ef575:
    // 004ef575  8b420d                 -mov eax, dword ptr [edx + 0xd]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004ef578  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ef57b  a300725600             -mov dword ptr [0x567200], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665280) /* 0x567200 */) = cpu.eax;
    // 004ef580  8b420e                 -mov eax, dword ptr [edx + 0xe]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */);
    // 004ef583  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ef586  a304725600             -mov dword ptr [0x567204], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665284) /* 0x567204 */) = cpu.eax;
    // 004ef58b  8b420f                 -mov eax, dword ptr [edx + 0xf]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004ef58e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ef591  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 004ef596  a310725600             -mov dword ptr [0x567210], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665296) /* 0x567210 */) = cpu.eax;
    // 004ef59b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004ef59e  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004ef5a3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004ef5a6  891574725600           -mov dword ptr [0x567274], edx
    *app->getMemory<x86::reg32>(x86::reg32(5665396) /* 0x567274 */) = cpu.edx;
    // 004ef5ac  a314725600             -mov dword ptr [0x567214], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665300) /* 0x567214 */) = cpu.eax;
    // 004ef5b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ef5b3  a110725600             -mov eax, dword ptr [0x567210]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665296) /* 0x567210 */);
    // 004ef5b8  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004ef5bb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ef5bd  893d70725600           -mov dword ptr [0x567270], edi
    *app->getMemory<x86::reg32>(x86::reg32(5665392) /* 0x567270 */) = cpu.edi;
    // 004ef5c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef5c5  892d0c725600           -mov dword ptr [0x56720c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */) = cpu.ebp;
    // 004ef5cb  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef5cd  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ef5cf  668b420a               -mov ax, word ptr [edx + 0xa]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004ef5d3  890d7c725600           -mov dword ptr [0x56727c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665404) /* 0x56727c */) = cpu.ecx;
    // 004ef5d9  a368725600             -mov dword ptr [0x567268], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665384) /* 0x567268 */) = cpu.eax;
    // 004ef5de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef5e0  891d18725600           -mov dword ptr [0x567218], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5665304) /* 0x567218 */) = cpu.ebx;
    // 004ef5e6  a3a4725600             -mov dword ptr [0x5672a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665444) /* 0x5672a4 */) = cpu.eax;
    // 004ef5eb  a3a0725600             -mov dword ptr [0x5672a0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665440) /* 0x5672a0 */) = cpu.eax;
    // 004ef5f0  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004ef5f3  891d1c725600           -mov dword ptr [0x56721c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5665308) /* 0x56721c */) = cpu.ebx;
    // 004ef5f9  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004ef5fc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ef5fe  891d78725600           -mov dword ptr [0x567278], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5665400) /* 0x567278 */) = cpu.ebx;
    // 004ef604  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ef606  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004ef609  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004ef60f  a308725600             -mov dword ptr [0x567208], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665288) /* 0x567208 */) = cpu.eax;
    // 004ef614  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004ef617  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ef619  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004ef61c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004ef61e  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004ef621  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 004ef627  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004ef62a  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004ef62d  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004ef62f  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004ef632  a36c725600             -mov dword ptr [0x56726c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665388) /* 0x56726c */) = cpu.eax;
    // 004ef637  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004ef63a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ef63d  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004ef640  83f802                 +cmp eax, 2
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
    // 004ef643  740c                   -je 0x4ef651
    if (cpu.flags.zf)
    {
        goto L_0x004ef651;
    }
    // 004ef645  813d68725600ff000000   +cmp dword ptr [0x567268], 0xff
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665384) /* 0x567268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef64f  7e3e                   -jle 0x4ef68f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ef68f;
    }
L_0x004ef651:
    // 004ef651  c7059472560080b55000   -mov dword ptr [0x567294], 0x50b580
    *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */) = 5289344 /*0x50b580*/;
L_0x004ef65b:
    // 004ef65b  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 004ef660  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef662  b828725600             -mov eax, 0x567228
    cpu.eax = 5665320 /*0x567228*/;
    // 004ef667  890d20725600           -mov dword ptr [0x567220], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */) = cpu.ecx;
    // 004ef66d  890d24725600           -mov dword ptr [0x567224], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */) = cpu.ecx;
    // 004ef673  890da8725600           -mov dword ptr [0x5672a8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665448) /* 0x5672a8 */) = cpu.ecx;
    // 004ef679  e88e10ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004ef67e  e84dca0100             -call 0x50c0d0
    cpu.esp -= 4;
    sub_50c0d0(app, cpu);
    if (cpu.terminate) return;
    // 004ef683  890d98725600           -mov dword ptr [0x567298], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665432) /* 0x567298 */) = cpu.ecx;
    // 004ef689  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef68a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef68b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef68c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef68d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef68e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef68f:
    // 004ef68f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004ef694  8d4220                 -lea eax, [edx + 0x20]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004ef697  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004ef69b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004ef69d  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004ef6a4  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004ef6a6  3dff000000             +cmp eax, 0xff
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
    // 004ef6ab  77a4                   -ja 0x4ef651
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ef651;
    }
    // 004ef6ad  c7059472560040b55000   -mov dword ptr [0x567294], 0x50b540
    *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */) = 5289280 /*0x50b540*/;
    // 004ef6b7  eba2                   -jmp 0x4ef65b
    goto L_0x004ef65b;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ef6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef6c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef6c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef6c2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef6c3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef6c4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef6c5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ef6c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ef6ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef6cc  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ef6cf  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef6d5  bb9f860100             -mov ebx, 0x1869f
    cpu.ebx = 99999 /*0x1869f*/;
    // 004ef6da  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ef6de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef6e0  ba14a8a000             -mov edx, 0xa0a814
    cpu.edx = 10528788 /*0xa0a814*/;
    // 004ef6e5  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004ef6e8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef6ed  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef6f3  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ef6f6  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004ef6fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef6fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef6fe  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004ef702:
    // 004ef702  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ef705  0fb67afd               -movzx edi, byte ptr [edx - 3]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */));
    // 004ef709  0fb66afc               -movzx ebp, byte ptr [edx - 4]
    cpu.ebp = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */));
    // 004ef70d  8a88c4505600           -mov cl, byte ptr [eax + 0x5650c4]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5656772) /* 0x5650c4 */);
    // 004ef713  0fb672fe               -movzx esi, byte ptr [edx - 2]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */));
    // 004ef717  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004ef719  742b                   -je 0x4ef746
    if (cpu.flags.zf)
    {
        goto L_0x004ef746;
    }
    // 004ef71b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ef71f  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ef721  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004ef723  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ef726  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ef72a  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ef72c  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ef72f  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004ef732  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ef735  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ef737  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ef73a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ef73c  39d9                   +cmp ecx, ebx
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
    // 004ef73e  7d06                   -jge 0x4ef746
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ef746;
    }
    // 004ef740  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ef744  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x004ef746:
    // 004ef746  40                     -inc eax
    (cpu.eax)++;
    // 004ef747  3d00010000             +cmp eax, 0x100
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
    // 004ef74c  7cb4                   -jl 0x4ef702
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ef702;
    }
    // 004ef74e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ef752  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ef755  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef756  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef757  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef758  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef759  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef75a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4ef760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef760  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef761  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef762  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ef764  8a2510505600           -mov ah, byte ptr [0x565010]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004ef76a  80fc08                 +cmp ah, 8
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
    // 004ef76d  761c                   -jbe 0x4ef78b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ef78b;
    }
    // 004ef76f  80fc0f                 +cmp ah, 0xf
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
    // 004ef772  745e                   -je 0x4ef7d2
    if (cpu.flags.zf)
    {
        goto L_0x004ef7d2;
    }
    // 004ef774  80fc10                 +cmp ah, 0x10
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
    // 004ef777  0f8483000000           -je 0x4ef800
    if (cpu.flags.zf)
    {
        goto L_0x004ef800;
    }
    // 004ef77d  80fc18                 +cmp ah, 0x18
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ef780  0f829f000000           -jb 0x4ef825
    if (cpu.flags.cf)
    {
        goto L_0x004ef825;
    }
    // 004ef786  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef788  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef789  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef78a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef78b:
    // 004ef78b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef78c  8b0dc0505600           -mov ecx, dword ptr [0x5650c0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5656768) /* 0x5650c0 */);
    // 004ef792  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ef794  7427                   -je 0x4ef7bd
    if (cpu.flags.zf)
    {
        goto L_0x004ef7bd;
    }
    // 004ef796  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef798  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004ef79e  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004ef7a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef7a3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ef7a6  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004ef7ac  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004ef7af  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ef7b2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef7b4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ef7b6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004ef7b8  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 004ef7bb  eb0f                   -jmp 0x4ef7cc
    goto L_0x004ef7cc;
L_0x004ef7bd:
    // 004ef7bd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ef7bf  8d0514a8a000           -lea eax, [0xa0a814]
    cpu.eax = x86::reg32(x86::reg32(10528788) /* 0xa0a814 */);
    // 004ef7c5  e8f6feffff             -call 0x4ef6c0
    cpu.esp -= 4;
    sub_4ef6c0(app, cpu);
    if (cpu.terminate) return;
    // 004ef7ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004ef7cc:
    // 004ef7cc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef7cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef7cf  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef7d0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef7d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef7d2:
    // 004ef7d2  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004ef7d4  7425                   -je 0x4ef7fb
    if (cpu.flags.zf)
    {
        goto L_0x004ef7fb;
    }
    // 004ef7d6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef7d8  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004ef7de  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004ef7e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef7e3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ef7e6  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004ef7ec  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004ef7ef  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ef7f2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ef7f4  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x004ef7fb:
    // 004ef7fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef7fd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef7fe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef7ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef800:
    // 004ef800  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef802  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004ef808  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004ef80b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef80d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ef810  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004ef816  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004ef819  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ef81c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ef81e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ef820  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef822  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef823  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef824  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef825:
    // 004ef825  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef827  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef829  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef82a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef82b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4ef830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ef830  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ef831  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef832  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ef833  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ef834  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ef835  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004ef838  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef83a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ef83c  8a2510505600           -mov ah, byte ptr [0x565010]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004ef842  891da4725600           -mov dword ptr [0x5672a4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5665444) /* 0x5672a4 */) = cpu.ebx;
    // 004ef848  80fc08                 +cmp ah, 8
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
    // 004ef84b  7540                   -jne 0x4ef88d
    if (!cpu.flags.zf)
    {
        goto L_0x004ef88d;
    }
    // 004ef84d  81f900010000           +cmp ecx, 0x100
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
    // 004ef853  7238                   -jb 0x4ef88d
    if (cpu.flags.cf)
    {
        goto L_0x004ef88d;
    }
    // 004ef855  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ef856  be34c55400             -mov esi, 0x54c534
    cpu.esi = 5555508 /*0x54c534*/;
    // 004ef85b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef85d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ef85e  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 004ef863  bf44c55400             -mov edi, 0x54c544
    cpu.edi = 5555524 /*0x54c544*/;
    // 004ef868  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ef869  bd3c000000             -mov ebp, 0x3c
    cpu.ebp = 60 /*0x3c*/;
    // 004ef86e  893590215500           -mov dword ptr [0x552190], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 004ef874  6850c55400             -push 0x54c550
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555536 /*0x54c550*/;
    cpu.esp -= 4;
    // 004ef879  893d94215500           -mov dword ptr [0x552194], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 004ef87f  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004ef885  e88617f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004ef88a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004ef88d:
    // 004ef88d  3b0d20725600           +cmp ecx, dword ptr [0x567220]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef893  750c                   -jne 0x4ef8a1
    if (!cpu.flags.zf)
    {
        goto L_0x004ef8a1;
    }
    // 004ef895  3b1524725600           +cmp edx, dword ptr [0x567224]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ef89b  0f8458010000           -je 0x4ef9f9
    if (cpu.flags.zf)
    {
        goto L_0x004ef9f9;
    }
L_0x004ef8a1:
    // 004ef8a1  890d20725600           -mov dword ptr [0x567220], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5665312) /* 0x567220 */) = cpu.ecx;
    // 004ef8a7  891524725600           -mov dword ptr [0x567224], edx
    *app->getMemory<x86::reg32>(x86::reg32(5665316) /* 0x567224 */) = cpu.edx;
    // 004ef8ad  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ef8af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ef8b1  893da8725600           -mov dword ptr [0x5672a8], edi
    *app->getMemory<x86::reg32>(x86::reg32(5665448) /* 0x5672a8 */) = cpu.edi;
    // 004ef8b7  e8e4ca0100             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 004ef8bc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef8be  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004ef8c1  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef8c7  894c2418               -mov dword ptr [esp + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004ef8cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ef8cd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef8d2  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ef8d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ef8d8  e8c3ca0100             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 004ef8dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef8df  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004ef8e2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef8e8  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004ef8ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ef8ee  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef8f3  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004ef8f6  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004ef8fa  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ef8fe  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef904  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004ef90b  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004ef90f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ef911  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 004ef918  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ef91a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004ef91d  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ef91f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef921  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ef923  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004ef926  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef928  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef92c  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ef930  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ef932  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ef936  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ef939  897c242c               -mov dword ptr [esp + 0x2c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 004ef93d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ef93f  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004ef942  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ef946  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ef94c  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ef950  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ef953  894c2414               -mov dword ptr [esp + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ef957  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ef959  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef95b  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004ef95f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ef961:
    // 004ef961  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004ef964  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004ef967  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ef96a  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004ef96d  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004ef970  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ef974  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004ef978  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ef97a  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 004ef97d  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ef981  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004ef985  037c2414               -add edi, dword ptr [esp + 0x14]
    (cpu.edi) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004ef989  034c241c               -add ecx, dword ptr [esp + 0x1c]
    (cpu.ecx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    // 004ef98d  2b5c2420               -sub ebx, dword ptr [esp + 0x20]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004ef991  2b742428               -sub esi, dword ptr [esp + 0x28]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 004ef995  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ef999  29442430               -sub dword ptr [esp + 0x30], eax
    (*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ef99d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004ef9a0  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ef9a3  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ef9a7  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004ef9ab  0b44240c               -or eax, dword ptr [esp + 0xc]
    cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004ef9af  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ef9b3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ef9b7  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004ef9ba  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ef9be  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ef9c2  0b442410               -or eax, dword ptr [esp + 0x10]
    cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004ef9c6  0b442408               -or eax, dword ptr [esp + 8]
    cpu.eax |= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004ef9ca  e891fdffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004ef9cf  898228725600           -mov dword ptr [edx + 0x567228], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5665320) /* 0x567228 */) = cpu.eax;
    // 004ef9d5  8a44242f               -mov al, byte ptr [esp + 0x2f]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(47) /* 0x2f */);
    // 004ef9d9  0410                   -add al, 0x10
    (cpu.al) += x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004ef9db  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ef9de  8844242f               -mov byte ptr [esp + 0x2f], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(47) /* 0x2f */) = cpu.al;
    // 004ef9e2  83fa40                 +cmp edx, 0x40
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
    // 004ef9e5  0f8576ffffff           -jne 0x4ef961
    if (!cpu.flags.zf)
    {
        goto L_0x004ef961;
    }
    // 004ef9eb  e890c70100             -call 0x50c180
    cpu.esp -= 4;
    sub_50c180(app, cpu);
    if (cpu.terminate) return;
    // 004ef9f0  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004ef9f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef9f4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef9f5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef9f6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef9f7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ef9f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ef9f9:
    // 004ef9f9  833da872560000         +cmp dword ptr [0x5672a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665448) /* 0x5672a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efa00  0f849bfeffff           -je 0x4ef8a1
    if (cpu.flags.zf)
    {
        goto L_0x004ef8a1;
    }
    // 004efa06  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004efa09  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa0a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa0b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa0c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa0d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4efa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efa10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004efa11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004efa12  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004efa13  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004efa15  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004efa17  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004efa19  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004efa1b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004efa1d  7436                   -je 0x4efa55
    if (cpu.flags.zf)
    {
        goto L_0x004efa55;
    }
L_0x004efa1f:
    // 004efa1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004efa21  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004efa23  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004efa26  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004efa29  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004efa2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004efa30  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004efa34  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004efa36  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004efa3d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004efa3f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004efa41  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004efa43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004efa45  7414                   -je 0x4efa5b
    if (cpu.flags.zf)
    {
        goto L_0x004efa5b;
    }
    // 004efa47  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004efa49  7e04                   -jle 0x4efa4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004efa4f;
    }
    // 004efa4b  4a                     -dec edx
    (cpu.edx)--;
    // 004efa4c  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x004efa4f:
    // 004efa4f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004efa51  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004efa53  75ca                   -jne 0x4efa1f
    if (!cpu.flags.zf)
    {
        goto L_0x004efa1f;
    }
L_0x004efa55:
    // 004efa55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004efa57  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa58  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa59  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004efa5b:
    // 004efa5b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004efa5d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa5e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa5f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efa60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4efa70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efa70  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004efa71  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004efa72  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004efa73  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004efa74  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004efa75  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004efa76  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004efa78  8b1570725600           -mov edx, dword ptr [0x567270]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665392) /* 0x567270 */);
    // 004efa7e  8b3d78725600           -mov edi, dword ptr [0x567278]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5665400) /* 0x567278 */);
    // 004efa84  83fa64                 +cmp edx, 0x64
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efa87  7d2e                   -jge 0x4efab7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004efab7;
    }
    // 004efa89  b9acc55400             -mov ecx, 0x54c5ac
    cpu.ecx = 5555628 /*0x54c5ac*/;
    // 004efa8e  bbbcc55400             -mov ebx, 0x54c5bc
    cpu.ebx = 5555644 /*0x54c5bc*/;
    // 004efa93  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
    // 004efa98  68ccc55400             -push 0x54c5cc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555660 /*0x54c5cc*/;
    cpu.esp -= 4;
    // 004efa9d  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004efaa3  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004efaa9  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 004efaaf  e85c15f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004efab4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004efab7:
    // 004efab7  8d56e0                 -lea edx, [esi - 0x20]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-32) /* -0x20 */);
    // 004efaba  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004efac1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004efac3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004efac6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004efac8  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004efacb  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004efad0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004efad2  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004efad6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004efad8  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004efadf  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004efae1  39f0                   +cmp eax, esi
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
    // 004efae3  7509                   -jne 0x4efaee
    if (!cpu.flags.zf)
    {
        goto L_0x004efaee;
    }
    // 004efae5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004efae7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efae8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efae9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efaea  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efaeb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efaec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efaed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004efaee:
    // 004efaee  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004efaf3  8b1d68725600           -mov ebx, dword ptr [0x567268]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5665384) /* 0x567268 */);
    // 004efaf9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004efafb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004efafd  e80effffff             -call 0x4efa10
    cpu.esp -= 4;
    sub_4efa10(app, cpu);
    if (cpu.terminate) return;
    // 004efb02  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb03  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb04  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb05  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb06  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb07  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4efb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efb10  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004efb11  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004efb12  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004efb13  8b0d9c725600           -mov ecx, dword ptr [0x56729c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5665436) /* 0x56729c */);
    // 004efb19  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004efb1b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004efb1d  a1a0725600             -mov eax, dword ptr [0x5672a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665440) /* 0x5672a0 */);
    // 004efb22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004efb24  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004efb26  7e13                   -jle 0x4efb3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004efb3b;
    }
L_0x004efb28:
    // 004efb28  663b7002               +cmp si, word ptr [eax + 2]
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004efb2c  7505                   -jne 0x4efb33
    if (!cpu.flags.zf)
    {
        goto L_0x004efb33;
    }
    // 004efb2e  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004efb31  740e                   -je 0x4efb41
    if (cpu.flags.zf)
    {
        goto L_0x004efb41;
    }
L_0x004efb33:
    // 004efb33  42                     -inc edx
    (cpu.edx)++;
    // 004efb34  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004efb37  39ca                   +cmp edx, ecx
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
    // 004efb39  7ced                   -jl 0x4efb28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004efb28;
    }
L_0x004efb3b:
    // 004efb3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004efb3d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb3e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb3f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004efb41:
    // 004efb41  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004efb44  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004efb47  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb48  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb49  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efb4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4efb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efb50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004efb51  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004efb52  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004efb53  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004efb54  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004efb55  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004efb56  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004efb59  89442420               -mov dword ptr [esp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004efb5d  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 004efb62  8b35f8715600           -mov esi, dword ptr [0x5671f8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 004efb68  8b1500725600           -mov edx, dword ptr [0x567200]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665280) /* 0x567200 */);
    // 004efb6e  8b2dfc715600           -mov ebp, dword ptr [0x5671fc]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 004efb74  8b0d04725600           -mov ecx, dword ptr [0x567204]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5665284) /* 0x567204 */);
    // 004efb7a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004efb7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004efb7f  a188725600             -mov eax, dword ptr [0x567288]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665416) /* 0x567288 */);
    // 004efb84  895c241c               -mov dword ptr [esp + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004efb88  897c2440               -mov dword ptr [esp + 0x40], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edi;
    // 004efb8c  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004efb90  a194725600             -mov eax, dword ptr [0x567294]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
    // 004efb95  895c243c               -mov dword ptr [esp + 0x3c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 004efb99  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004efb9d  a198725600             -mov eax, dword ptr [0x567298]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665432) /* 0x567298 */);
    // 004efba2  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004efba4  89442438               -mov dword ptr [esp + 0x38], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004efba8  a1a0725600             -mov eax, dword ptr [0x5672a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665440) /* 0x5672a0 */);
    // 004efbad  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004efbaf  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004efbb3  a1f8715600             -mov eax, dword ptr [0x5671f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 004efbb8  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004efbbc  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004efbc0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004efbc2  0f8419010000           -je 0x4efce1
    if (cpu.flags.zf)
    {
        goto L_0x004efce1;
    }
L_0x004efbc8:
    // 004efbc8  833d8c72560000         +cmp dword ptr [0x56728c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efbcf  7406                   -je 0x4efbd7
    if (cpu.flags.zf)
    {
        goto L_0x004efbd7;
    }
    // 004efbd1  ff158c725600           -call dword ptr [0x56728c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5665420) /* 0x56728c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004efbd7:
    // 004efbd7  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004efbdc  e88ffeffff             -call 0x4efa70
    cpu.esp -= 4;
    sub_4efa70(app, cpu);
    if (cpu.terminate) return;
    // 004efbe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efbe3  0f852b010000           -jne 0x4efd14
    if (!cpu.flags.zf)
    {
        goto L_0x004efd14;
    }
L_0x004efbe9:
    // 004efbe9  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004efbed  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004efbf1  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004efbf5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004efbf7  42                     -inc edx
    (cpu.edx)++;
    // 004efbf8  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efbfc  89542440               -mov dword ptr [esp + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 004efc00  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004efc02  8944243c               -mov dword ptr [esp + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004efc06  83f820                 +cmp eax, 0x20
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
    // 004efc09  0f8e73010000           -jle 0x4efd82
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004efd82;
    }
    // 004efc0f  e85cfeffff             -call 0x4efa70
    cpu.esp -= 4;
    sub_4efa70(app, cpu);
    if (cpu.terminate) return;
    // 004efc14  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004efc16  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004efc18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efc1a  0f841c010000           -je 0x4efd3c
    if (cpu.flags.zf)
    {
        goto L_0x004efd3c;
    }
    // 004efc20  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004efc25  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004efc28  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004efc2c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004efc2e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004efc35  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004efc37  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004efc3c  89442424               -mov dword ptr [esp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004efc40  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004efc43  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004efc47  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004efc49  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 004efc50  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 004efc52  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004efc56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004efc58  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004efc5c  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004efc60  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004efc64  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004efc66  740d                   -je 0x4efc75
    if (cpu.flags.zf)
    {
        goto L_0x004efc75;
    }
    // 004efc68  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004efc6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004efc6e  e89dfeffff             -call 0x4efb10
    cpu.esp -= 4;
    sub_4efb10(app, cpu);
    if (cpu.terminate) return;
    // 004efc73  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004efc75:
    // 004efc75  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004efc78  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004efc7b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004efc7e  8b4707                 -mov eax, dword ptr [edi + 7]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 004efc81  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004efc84  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004efc88  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004efc8b  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004efc8f  89542430               -mov dword ptr [esp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004efc93  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004efc95  0f8588000000           -jne 0x4efd23
    if (!cpu.flags.zf)
    {
        goto L_0x004efd23;
    }
L_0x004efc9b:
    // 004efc9b  a16c725600             -mov eax, dword ptr [0x56726c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665388) /* 0x56726c */);
    // 004efca0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004efca1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004efca3  8a4703                 -mov al, byte ptr [edi + 3]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 004efca6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004efca7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004efca9  8a4702                 -mov al, byte ptr [edi + 2]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004efcac  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004efcad  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004efcb1  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004efcb5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004efcb6  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004efcba  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004efcbe  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004efcc0  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004efcc4  8b1d7c725600           -mov ebx, dword ptr [0x56727c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5665404) /* 0x56727c */);
    // 004efcca  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004efccc  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004efcd0  ff542424               -call dword ptr [esp + 0x24]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efcd4  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 004efcd7  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004efcda  01c6                   +add esi, eax
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
    // 004efcdc  e908ffffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efce1:
    // 004efce1  b9acc55400             -mov ecx, 0x54c5ac
    cpu.ecx = 5555628 /*0x54c5ac*/;
    // 004efce6  bb00c65400             -mov ebx, 0x54c600
    cpu.ebx = 5555712 /*0x54c600*/;
    // 004efceb  bf9e000000             -mov edi, 0x9e
    cpu.edi = 158 /*0x9e*/;
    // 004efcf0  6808c65400             -push 0x54c608
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555720 /*0x54c608*/;
    cpu.esp -= 4;
    // 004efcf5  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004efcfb  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004efd01  893d98215500           -mov dword ptr [0x552198], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edi;
    // 004efd07  e80413f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004efd0c  83c404                 +add esp, 4
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
    // 004efd0f  e9b4feffff             -jmp 0x4efbc8
    goto L_0x004efbc8;
L_0x004efd14:
    // 004efd14  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004efd17  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004efd1a  8944241c               -mov dword ptr [esp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004efd1e  e9c6feffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efd23:
    // 004efd23  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004efd27  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004efd2b  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004efd2f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004efd33  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efd37  e95fffffff             -jmp 0x4efc9b
    goto L_0x004efc9b;
L_0x004efd3c:
    // 004efd3c  833dcc51560000         +cmp dword ptr [0x5651cc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5657036) /* 0x5651cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efd43  0f84a0feffff           -je 0x4efbe9
    if (cpu.flags.zf)
    {
        goto L_0x004efbe9;
    }
    // 004efd49  a118725600             -mov eax, dword ptr [0x567218]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665304) /* 0x567218 */);
    // 004efd4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004efd50  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004efd53  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004efd55  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004efd57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004efd59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004efd5c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004efd5e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004efd60  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004efd62  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004efd64  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 004efd69  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004efd6b  e8f0f9ffff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 004efd70  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004efd71  8d5ffe                 -lea ebx, [edi - 2]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004efd74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004efd76  e8c5d70000             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 004efd7b  01fe                   +add esi, edi
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
    // 004efd7d  e967feffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efd82:
    // 004efd82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efd84  7531                   -jne 0x4efdb7
    if (!cpu.flags.zf)
    {
        goto L_0x004efdb7;
    }
    // 004efd86  833d9072560000         +cmp dword ptr [0x567290], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efd8d  0f858e000000           -jne 0x4efe21
    if (!cpu.flags.zf)
    {
        goto L_0x004efe21;
    }
L_0x004efd93:
    // 004efd93  a100725600             -mov eax, dword ptr [0x567200]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665280) /* 0x567200 */);
    // 004efd98  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004efd9a  a104725600             -mov eax, dword ptr [0x567204]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665284) /* 0x567204 */);
    // 004efd9f  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004efda1  8935f8715600           -mov dword ptr [0x5671f8], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */) = cpu.esi;
    // 004efda7  892dfc715600           -mov dword ptr [0x5671fc], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */) = cpu.ebp;
    // 004efdad  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004efdb0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efdb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004efdb7:
    // 004efdb7  83f80a                 +cmp eax, 0xa
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
    // 004efdba  7517                   -jne 0x4efdd3
    if (!cpu.flags.zf)
    {
        goto L_0x004efdd3;
    }
    // 004efdbc  8b1510725600           -mov edx, dword ptr [0x567210]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665296) /* 0x567210 */);
    // 004efdc2  031514725600           -add edx, dword ptr [0x567214]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5665300) /* 0x567214 */)));
    // 004efdc8  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004efdcc  01d5                   +add ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004efdce  e916feffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efdd3:
    // 004efdd3  833dc851560000         +cmp dword ptr [0x5651c8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5657032) /* 0x5651c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efdda  7509                   -jne 0x4efde5
    if (!cpu.flags.zf)
    {
        goto L_0x004efde5;
    }
L_0x004efddc:
    // 004efddc  0374241c               +add esi, dword ptr [esp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004efde0  e904feffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efde5:
    // 004efde5  83f809                 +cmp eax, 9
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
    // 004efde8  75f2                   -jne 0x4efddc
    if (!cpu.flags.zf)
    {
        goto L_0x004efddc;
    }
    // 004efdea  8b3dc4515600           -mov edi, dword ptr [0x5651c4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5657028) /* 0x5651c4 */);
    // 004efdf0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004efdf2  0f8ef1fdffff           -jle 0x4efbe9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004efbe9;
    }
    // 004efdf8  8d0cbd00000000         -lea ecx, [edi*4]
    cpu.ecx = x86::reg32(cpu.edi * 4);
    // 004efdff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004efe01:
    // 004efe01  a1c8515600             -mov eax, dword ptr [0x5651c8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5657032) /* 0x5651c8 */);
    // 004efe06  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004efe08  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004efe0a  39de                   +cmp esi, ebx
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
    // 004efe0c  7d07                   -jge 0x4efe15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004efe15;
    }
    // 004efe0e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004efe10  e9d4fdffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efe15:
    // 004efe15  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004efe18  39ca                   +cmp edx, ecx
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
    // 004efe1a  7ce5                   -jl 0x4efe01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004efe01;
    }
    // 004efe1c  e9c8fdffff             -jmp 0x4efbe9
    goto L_0x004efbe9;
L_0x004efe21:
    // 004efe21  ff1590725600           -call dword ptr [0x567290]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5665424) /* 0x567290 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efe27  e967ffffff             -jmp 0x4efd93
    goto L_0x004efd93;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4efe30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efe30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004efe31  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004efe33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004efe35  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004efe37  e8140a0000             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 004efe3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004efe3e  e80dfdffff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
    // 004efe43  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4efe50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efe50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004efe51  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004efe52  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004efe53  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004efe54  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004efe55  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004efe58  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004efe5b  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004efe5f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004efe62  a1a0725600             -mov eax, dword ptr [0x5672a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665440) /* 0x5672a0 */);
    // 004efe67  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004efe69  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004efe6b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004efe6d  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004efe71  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004efe73  7411                   -je 0x4efe86
    if (cpu.flags.zf)
    {
        goto L_0x004efe86;
    }
L_0x004efe75:
    // 004efe75  3b742404               +cmp esi, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004efe79  7c3a                   -jl 0x4efeb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004efeb5;
    }
L_0x004efe7b:
    // 004efe7b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004efe7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004efe80  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe81  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe82  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe83  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe84  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efe85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004efe86:
    // 004efe86  b924c65400             -mov ecx, 0x54c624
    cpu.ecx = 5555748 /*0x54c624*/;
    // 004efe8b  bb34c65400             -mov ebx, 0x54c634
    cpu.ebx = 5555764 /*0x54c634*/;
    // 004efe90  b847000000             -mov eax, 0x47
    cpu.eax = 71 /*0x47*/;
    // 004efe95  6840c65400             -push 0x54c640
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5555776 /*0x54c640*/;
    cpu.esp -= 4;
    // 004efe9a  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 004efea0  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 004efea6  a398215500             -mov dword ptr [0x552198], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.eax;
    // 004efeab  e86011f1ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004efeb0  83c404                 +add esp, 4
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
    // 004efeb3  ebc0                   -jmp 0x4efe75
    goto L_0x004efe75;
L_0x004efeb5:
    // 004efeb5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004efeb7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004efeb9  ff1594725600           -call dword ptr [0x567294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efebf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004efec1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004efec3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efec5  74b4                   -je 0x4efe7b
    if (cpu.flags.zf)
    {
        goto L_0x004efe7b;
    }
    // 004efec7  e8a4fbffff             -call 0x4efa70
    cpu.esp -= 4;
    sub_4efa70(app, cpu);
    if (cpu.terminate) return;
    // 004efecc  46                     -inc esi
    (cpu.esi)++;
    // 004efecd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efecf  74a4                   -je 0x4efe75
    if (cpu.flags.zf)
    {
        goto L_0x004efe75;
    }
    // 004efed1  8b5805                 -mov ebx, dword ptr [eax + 5]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004efed4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004efed8  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004efedb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004efedd  7504                   -jne 0x4efee3
    if (!cpu.flags.zf)
    {
        goto L_0x004efee3;
    }
    // 004efedf  01df                   +add edi, ebx
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
    // 004efee1  eb92                   -jmp 0x4efe75
    goto L_0x004efe75;
L_0x004efee3:
    // 004efee3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004efee5  e826fcffff             -call 0x4efb10
    cpu.esp -= 4;
    sub_4efb10(app, cpu);
    if (cpu.terminate) return;
    // 004efeea  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004efeec  01df                   +add edi, ebx
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
    // 004efeee  eb85                   -jmp 0x4efe75
    goto L_0x004efe75;
}

/* align: skip  */
void Application::sub_4efef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004efef0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004efef1  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004efef6  e855ffffff             -call 0x4efe50
    cpu.esp -= 4;
    sub_4efe50(app, cpu);
    if (cpu.terminate) return;
    // 004efefb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004efefc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4eff00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eff00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eff01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eff02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004eff03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004eff04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004eff06  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004eff09  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004eff0b  752f                   -jne 0x4eff3c
    if (!cpu.flags.zf)
    {
        goto L_0x004eff3c;
    }
L_0x004eff0d:
    // 004eff0d  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004eff10  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eff12  7407                   -je 0x4eff1b
    if (cpu.flags.zf)
    {
        goto L_0x004eff1b;
    }
    // 004eff14  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004eff16  e8f59b0100             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
L_0x004eff1b:
    // 004eff1b  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 004eff1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004eff20  7526                   -jne 0x4eff48
    if (!cpu.flags.zf)
    {
        goto L_0x004eff48;
    }
L_0x004eff22:
    // 004eff22  c6411d00               -mov byte ptr [ecx + 0x1d], 0
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004eff26  c6411c00               -mov byte ptr [ecx + 0x1c], 0
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004eff2a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004eff2c  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    *app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 004eff32  e85919ffff             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004eff37  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eff38  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eff39  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eff3a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004eff3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004eff3c:
    // 004eff3c  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004eff41  e8ead7ffff             -call 0x4ed730
    cpu.esp -= 4;
    sub_4ed730(app, cpu);
    if (cpu.terminate) return;
    // 004eff46  ebc5                   -jmp 0x4eff0d
    goto L_0x004eff0d;
L_0x004eff48:
    // 004eff48  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004eff4a  e8c19b0100             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 004eff4f  ebd1                   -jmp 0x4eff22
    goto L_0x004eff22;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4eff60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004eff60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004eff61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004eff62  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004eff65  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004eff67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004eff69  7514                   -jne 0x4eff7f
    if (!cpu.flags.zf)
    {
        goto L_0x004eff7f;
    }
    // 004eff6b  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004eff71  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004eff74  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004eff76  7507                   -jne 0x4eff7f
    if (!cpu.flags.zf)
    {
        goto L_0x004eff7f;
    }
    // 004eff78  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004eff7a  e980000000             -jmp 0x4effff
    goto L_0x004effff;
L_0x004eff7f:
    // 004eff7f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004eff81  e8bac50100             -call 0x50c540
    cpu.esp -= 4;
    sub_50c540(app, cpu);
    if (cpu.terminate) return;
    // 004eff86  eb20                   -jmp 0x4effa8
    goto L_0x004effa8;
L_0x004eff88:
    // 004eff88  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eff8a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004eff8d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004eff8f  8a0c14                 -mov cl, byte ptr [esp + edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 004eff92  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004eff94  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004eff97  8a9240215500           -mov dl, byte ptr [edx + 0x552140]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5579072) /* 0x552140 */);
    // 004eff9d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004effa3  85d1                   +test ecx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.edx));
    // 004effa5  7409                   -je 0x4effb0
    if (cpu.flags.zf)
    {
        goto L_0x004effb0;
    }
    // 004effa7  43                     -inc ebx
    (cpu.ebx)++;
L_0x004effa8:
    // 004effa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004effaa  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 004effac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004effae  75d8                   -jne 0x4eff88
    if (!cpu.flags.zf)
    {
        goto L_0x004eff88;
    }
L_0x004effb0:
    // 004effb0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004effb2  744b                   -je 0x4effff
    if (cpu.flags.zf)
    {
        goto L_0x004effff;
    }
    // 004effb4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004effb6  eb30                   -jmp 0x4effe8
    goto L_0x004effe8;
L_0x004effb8:
    // 004effb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004effba  c1e903                 -shr ecx, 3
    cpu.ecx >>= 3 /*0x3*/ % 32;
    // 004effbd  8a0c0c                 -mov cl, byte ptr [esp + ecx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1);
    // 004effc0  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004effc3  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004effc9  8a8040215500           -mov al, byte ptr [eax + 0x552140]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5579072) /* 0x552140 */);
    // 004effcf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004effd4  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 004effd6  740f                   -je 0x4effe7
    if (cpu.flags.zf)
    {
        goto L_0x004effe7;
    }
    // 004effd8  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004effdb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004effdc  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004effe2  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004effe5  eb16                   -jmp 0x4efffd
    goto L_0x004efffd;
L_0x004effe7:
    // 004effe7  42                     -inc edx
    (cpu.edx)++;
L_0x004effe8:
    // 004effe8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004effea  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 004effec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004effee  75c8                   -jne 0x4effb8
    if (!cpu.flags.zf)
    {
        goto L_0x004effb8;
    }
    // 004efff0  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004efff6  c7401000000000         -mov dword ptr [eax + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x004efffd:
    // 004efffd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004effff:
    // 004effff  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004f0002  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0003  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0004  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0010  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0011  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0012  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f0014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0016  83fb3a                 +cmp ebx, 0x3a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0019  0f8486000000           -je 0x4f00a5
    if (cpu.flags.zf)
    {
        goto L_0x004f00a5;
    }
    // 004f001f  803d5048560000         +cmp byte ptr [0x564850], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5654608) /* 0x564850 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f0026  7426                   -je 0x4f004e
    if (cpu.flags.zf)
    {
        goto L_0x004f004e;
    }
    // 004f0028  b9044a5600             -mov ecx, 0x564a04
    cpu.ecx = 5655044 /*0x564a04*/;
L_0x004f002d:
    // 004f002d  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 004f0030  8a00                   -mov al, byte ptr [eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f0032  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f0037  3d80000000             +cmp eax, 0x80
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
    // 004f003c  7c0d                   -jl 0x4f004b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f004b;
    }
    // 004f003e  3d90000000             +cmp eax, 0x90
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(144 /*0x90*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0043  7c03                   -jl 0x4f0048
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f0048;
    }
    // 004f0045  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x004f0048:
    // 004f0048  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
L_0x004f004b:
    // 004f004b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f004c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f004d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f004e:
    // 004f004e  803d3548560000         +cmp byte ptr [0x564835], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5654581) /* 0x564835 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f0055  741e                   -je 0x4f0075
    if (cpu.flags.zf)
    {
        goto L_0x004f0075;
    }
    // 004f0057  833d1048560000         +cmp dword ptr [0x564810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5654544) /* 0x564810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f005e  7405                   -je 0x4f0065
    if (cpu.flags.zf)
    {
        goto L_0x004f0065;
    }
    // 004f0060  83fb01                 +cmp ebx, 1
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
    // 004f0063  7407                   -je 0x4f006c
    if (cpu.flags.zf)
    {
        goto L_0x004f006c;
    }
L_0x004f0065:
    // 004f0065  b9a9495600             -mov ecx, 0x5649a9
    cpu.ecx = 5654953 /*0x5649a9*/;
    // 004f006a  ebc1                   -jmp 0x4f002d
    goto L_0x004f002d;
L_0x004f006c:
    // 004f006c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f006e  e891fcfeff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004f0073  ebb8                   -jmp 0x4f002d
    goto L_0x004f002d;
L_0x004f0075:
    // 004f0075  803d4248560000         +cmp byte ptr [0x564842], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5654594) /* 0x564842 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f007c  7407                   -je 0x4f0085
    if (cpu.flags.zf)
    {
        goto L_0x004f0085;
    }
L_0x004f007e:
    // 004f007e  b9f3485600             -mov ecx, 0x5648f3
    cpu.ecx = 5654771 /*0x5648f3*/;
    // 004f0083  eba8                   -jmp 0x4f002d
    goto L_0x004f002d;
L_0x004f0085:
    // 004f0085  803d4e48560000         +cmp byte ptr [0x56484e], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5654606) /* 0x56484e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f008c  75f0                   -jne 0x4f007e
    if (!cpu.flags.zf)
    {
        goto L_0x004f007e;
    }
    // 004f008e  833d1448560000         +cmp dword ptr [0x564814], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5654548) /* 0x564814 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0095  7407                   -je 0x4f009e
    if (cpu.flags.zf)
    {
        goto L_0x004f009e;
    }
    // 004f0097  b94e495600             -mov ecx, 0x56494e
    cpu.ecx = 5654862 /*0x56494e*/;
    // 004f009c  eb8f                   -jmp 0x4f002d
    goto L_0x004f002d;
L_0x004f009e:
    // 004f009e  b998485600             -mov ecx, 0x564898
    cpu.ecx = 5654680 /*0x564898*/;
    // 004f00a3  eb88                   -jmp 0x4f002d
    goto L_0x004f002d;
L_0x004f00a5:
    // 004f00a5  833d1448560000         +cmp dword ptr [0x564814], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5654548) /* 0x564814 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f00ac  750e                   -jne 0x4f00bc
    if (!cpu.flags.zf)
    {
        goto L_0x004f00bc;
    }
    // 004f00ae  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f00b3  890d14485600           -mov dword ptr [0x564814], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5654548) /* 0x564814 */) = cpu.ecx;
    // 004f00b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f00ba  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f00bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f00bc:
    // 004f00bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f00be  890d14485600           -mov dword ptr [0x564814], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5654548) /* 0x564814 */) = cpu.ecx;
    // 004f00c4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f00c5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f00c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4f00d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f00d0  e89bc8fdff             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 004f00d5  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f00da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f00e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f00e0  e88bc8fdff             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 004f00e5  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 004f00ea  e995c40100             -jmp 0x50c584
    return sub_50c584(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_4f00f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f00f0  a3d0515600             -mov dword ptr [0x5651d0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657040) /* 0x5651d0 */) = cpu.eax;
    // 004f00f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f0100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0100  833dd051560000         +cmp dword ptr [0x5651d0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5657040) /* 0x5651d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f0107  7503                   -jne 0x4f010c
    if (!cpu.flags.zf)
    {
        goto L_0x004f010c;
    }
    // 004f0109  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f010b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f010c:
    // 004f010c  ff15d0515600           -call dword ptr [0x5651d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5657040) /* 0x5651d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0112  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4f0120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0120  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0121  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0122  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0123  ba60c65400             -mov edx, 0x54c660
    cpu.edx = 5555808 /*0x54c660*/;
    // 004f0128  b96cc65400             -mov ecx, 0x54c66c
    cpu.ecx = 5555820 /*0x54c66c*/;
    // 004f012d  bbda010000             -mov ebx, 0x1da
    cpu.ebx = 474 /*0x1da*/;
    // 004f0132  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f0138  890d94215500           -mov dword ptr [0x552194], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f013e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f0140  891d98215500           -mov dword ptr [0x552198], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f0146  e8c50e0100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004f014b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f014c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f014d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004f014e:
    // 004f014e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0150  e8db74ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f0155  e8a6ffffff             -call 0x4f0100
    cpu.esp -= 4;
    sub_4f0100(app, cpu);
    if (cpu.terminate) return;
    // 004f015a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f015c  74f0                   -je 0x4f014e
    if (cpu.flags.zf)
    {
        goto L_0x004f014e;
    }
    // 004f015e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f0160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0160  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0161  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0162  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0163  ba60c65400             -mov edx, 0x54c660
    cpu.edx = 5555808 /*0x54c660*/;
    // 004f0168  b974c65400             -mov ecx, 0x54c674
    cpu.ecx = 5555828 /*0x54c674*/;
    // 004f016d  bb24020000             -mov ebx, 0x224
    cpu.ebx = 548 /*0x224*/;
    // 004f0172  891590215500           -mov dword ptr [0x552190], edx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 004f0178  890d94215500           -mov dword ptr [0x552194], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 004f017e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f0180  891d98215500           -mov dword ptr [0x552198], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 004f0186  e8850e0100             -call 0x501010
    cpu.esp -= 4;
    sub_501010(app, cpu);
    if (cpu.terminate) return;
    // 004f018b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004f018d:
    // 004f018d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f018f  e89c74ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f0194  e867ffffff             -call 0x4f0100
    cpu.esp -= 4;
    sub_4f0100(app, cpu);
    if (cpu.terminate) return;
    // 004f0199  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f019b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f019d  e81e050000             -call 0x4f06c0
    cpu.esp -= 4;
    sub_4f06c0(app, cpu);
    if (cpu.terminate) return;
    // 004f01a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f01a4  7508                   -jne 0x4f01ae
    if (!cpu.flags.zf)
    {
        goto L_0x004f01ae;
    }
    // 004f01a6  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f01a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f01aa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01ab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01ac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f01ae:
    // 004f01ae  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f01b0  74db                   -je 0x4f018d
    if (cpu.flags.zf)
    {
        goto L_0x004f018d;
    }
    // 004f01b2  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f01b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f01b6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01b7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01b8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f01c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f01c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f01c1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f01c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f01c4  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f01c9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f01cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004f01cd:
    // 004f01cd  e82effffff             -call 0x4f0100
    cpu.esp -= 4;
    sub_4f0100(app, cpu);
    if (cpu.terminate) return;
    // 004f01d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f01d4  7403                   -je 0x4f01d9
    if (cpu.flags.zf)
    {
        goto L_0x004f01d9;
    }
    // 004f01d6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01d7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f01d9:
    // 004f01d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f01db  e85074ffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f01e0  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f01e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f01e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f01e9  7ce2                   -jl 0x4f01cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f01cd;
    }
    // 004f01eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f01ed  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01ee  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f01ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f01f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f01f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f01f1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f01f2  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f01f9  741d                   -je 0x4f0218
    if (cpu.flags.zf)
    {
        goto L_0x004f0218;
    }
L_0x004f01fb:
    // 004f01fb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004f0200  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 004f0205  b818485600             -mov eax, 0x564818
    cpu.eax = 5654552 /*0x564818*/;
    // 004f020a  890d88747f00           -mov dword ptr [0x7f7488], ecx
    *app->getMemory<x86::reg32>(x86::reg32(8352904) /* 0x7f7488 */) = cpu.ecx;
    // 004f0210  e8f704ffff             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004f0215  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0216  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0217  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0218:
    // 004f0218  e8c3b0ffff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004f021d  a390125600             -mov dword ptr [0x561290], eax
    *app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */) = cpu.eax;
    // 004f0222  ebd7                   -jmp 0x4f01fb
    goto L_0x004f01fb;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4f0230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0230  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0231  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0233  891588747f00           -mov dword ptr [0x7f7488], edx
    *app->getMemory<x86::reg32>(x86::reg32(8352904) /* 0x7f7488 */) = cpu.edx;
    // 004f0239  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f023a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4f0240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004f0240:
    // 004f0240  e82bc7fdff             -call 0x4cc970
    cpu.esp -= 4;
    sub_4cc970(app, cpu);
    if (cpu.terminate) return;
    // 004f0245  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0247  75f7                   -jne 0x4f0240
    if (!cpu.flags.zf)
    {
        goto L_0x004f0240;
    }
    // 004f0249  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f0250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0250  e8abc7fdff             -call 0x4cca00
    cpu.esp -= 4;
    sub_4cca00(app, cpu);
    if (cpu.terminate) return;
    // 004f0255  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004f025a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0260  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0261  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0262  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f0263  2eff15d4455300         -call dword ptr cs:[0x5345d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457364) /* 0x5345d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f026a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f026c  7508                   -jne 0x4f0276
    if (!cpu.flags.zf)
    {
        goto L_0x004f0276;
    }
    // 004f026e  e8810d0100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004f0273  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0274  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0275  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0276:
    // 004f0276  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0278  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0279  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f027a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0280  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0281  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0282  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0283  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0284  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0285  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f028b  8b15d4515600           -mov edx, dword ptr [0x5651d4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */);
    // 004f0291  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004f0293  83faff                 +cmp edx, -1
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
    // 004f0296  7409                   -je 0x4f02a1
    if (cpu.flags.zf)
    {
        goto L_0x004f02a1;
    }
    // 004f0298  bfc90a9f00             -mov edi, 0x9f0ac9
    cpu.edi = 10422985 /*0x9f0ac9*/;
L_0x004f029d:
    // 004f029d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004f029f  740e                   -je 0x4f02af
    if (cpu.flags.zf)
    {
        goto L_0x004f02af;
    }
L_0x004f02a1:
    // 004f02a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f02a3  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f02a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f02aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f02ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f02ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f02ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f02ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f02af:
    // 004f02af  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f02b1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f02b2  8b0dd4515600           -mov ecx, dword ptr [0x5651d4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */);
    // 004f02b8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f02b9  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f02c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f02c2  743f                   -je 0x4f0303
    if (cpu.flags.zf)
    {
        goto L_0x004f0303;
    }
    // 004f02c4  8b1dc0099f00           -mov ebx, dword ptr [0x9f09c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10422720) /* 0x9f09c0 */);
    // 004f02ca  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004f02cc  bac4099f00             -mov edx, 0x9f09c4
    cpu.edx = 10422724 /*0x9f09c4*/;
    // 004f02d1  88a3c90a9f00           -mov byte ptr [ebx + 0x9f0ac9], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10422985) /* 0x9f0ac9 */) = cpu.ah;
    // 004f02d7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f02d9  e8520bffff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f02de  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004f02e3  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f02e7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004f02e9  e802ebffff             -call 0x4eedf0
    cpu.esp -= 4;
    sub_4eedf0(app, cpu);
    if (cpu.terminate) return;
    // 004f02ee  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f02ef  2eff1520455300         -call dword ptr cs:[0x534520]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457184) /* 0x534520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f02f6  83f8ff                 +cmp eax, -1
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
    // 004f02f9  74a2                   -je 0x4f029d
    if (cpu.flags.zf)
    {
        goto L_0x004f029d;
    }
    // 004f02fb  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004f02fd  759e                   -jne 0x4f029d
    if (!cpu.flags.zf)
    {
        goto L_0x004f029d;
    }
    // 004f02ff  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004f0301  eb9a                   -jmp 0x4f029d
    goto L_0x004f029d;
L_0x004f0303:
    // 004f0303  8b1dd4515600           -mov ebx, dword ptr [0x5651d4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */);
    // 004f0309  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f030a  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004f030f  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0316  8935d4515600           -mov dword ptr [0x5651d4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */) = cpu.esi;
    // 004f031c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f031e  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f0324  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0325  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0326  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0327  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0328  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0329  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f0330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0330  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0331  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0332  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0333  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0334  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0335  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f033b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f033d  8b15d4515600           -mov edx, dword ptr [0x5651d4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */);
    // 004f0343  83faff                 +cmp edx, -1
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
    // 004f0346  0f856b000000           -jne 0x4f03b7
    if (!cpu.flags.zf)
    {
        goto L_0x004f03b7;
    }
L_0x004f034c:
    // 004f034c  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004f0351  b8c4099f00             -mov eax, 0x9f09c4
    cpu.eax = 10422724 /*0x9f09c4*/;
    // 004f0356  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f0358  bfc4099f00             -mov edi, 0x9f09c4
    cpu.edi = 10422724 /*0x9f09c4*/;
    // 004f035d  e8ce0affff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f0362  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004f0364  49                     -dec ecx
    (cpu.ecx)--;
    // 004f0365  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f0367  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004f0369  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004f036b  49                     -dec ecx
    (cpu.ecx)--;
    // 004f036c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f036e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f0370  7e15                   -jle 0x4f0387
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f0387;
    }
L_0x004f0372:
    // 004f0372  8a90c4099f00           -mov dl, byte ptr [eax + 0x9f09c4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10422724) /* 0x9f09c4 */);
    // 004f0378  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f037b  740a                   -je 0x4f0387
    if (cpu.flags.zf)
    {
        goto L_0x004f0387;
    }
    // 004f037d  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f0380  7405                   -je 0x4f0387
    if (cpu.flags.zf)
    {
        goto L_0x004f0387;
    }
    // 004f0382  48                     -dec eax
    (cpu.eax)--;
    // 004f0383  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0385  7feb                   -jg 0x4f0372
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004f0372;
    }
L_0x004f0387:
    // 004f0387  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0389  7536                   -jne 0x4f03c1
    if (!cpu.flags.zf)
    {
        goto L_0x004f03c1;
    }
L_0x004f038b:
    // 004f038b  a3c0099f00             -mov dword ptr [0x9f09c0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10422720) /* 0x9f09c0 */) = cpu.eax;
    // 004f0390  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f0392  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f0393  68c4099f00             -push 0x9f09c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10422724 /*0x9f09c4*/;
    cpu.esp -= 4;
    // 004f0398  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f039f  a3d4515600             -mov dword ptr [0x5651d4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657044) /* 0x5651d4 */) = cpu.eax;
    // 004f03a4  83f8ff                 +cmp eax, -1
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
    // 004f03a7  751b                   -jne 0x4f03c4
    if (!cpu.flags.zf)
    {
        goto L_0x004f03c4;
    }
    // 004f03a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f03ab  81c440010000           +add esp, 0x140
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f03b1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f03b2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f03b3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f03b4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f03b5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f03b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f03b7:
    // 004f03b7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f03b8  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f03bf  eb8b                   -jmp 0x4f034c
    goto L_0x004f034c;
L_0x004f03c1:
    // 004f03c1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f03c2  ebc7                   -jmp 0x4f038b
    goto L_0x004f038b;
L_0x004f03c4:
    // 004f03c4  bac4099f00             -mov edx, 0x9f09c4
    cpu.edx = 10422724 /*0x9f09c4*/;
    // 004f03c9  8b1dc0099f00           -mov ebx, dword ptr [0x9f09c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10422720) /* 0x9f09c0 */);
    // 004f03cf  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004f03d1  b8c90a9f00             -mov eax, 0x9f0ac9
    cpu.eax = 10422985 /*0x9f0ac9*/;
    // 004f03d6  888bc90a9f00           -mov byte ptr [ebx + 0x9f0ac9], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10422985) /* 0x9f0ac9 */) = cpu.cl;
    // 004f03dc  e84f0affff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004f03e1  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004f03e6  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004f03ea  b8c90a9f00             -mov eax, 0x9f0ac9
    cpu.eax = 10422985 /*0x9f0ac9*/;
    // 004f03ef  e8fce9ffff             -call 0x4eedf0
    cpu.esp -= 4;
    sub_4eedf0(app, cpu);
    if (cpu.terminate) return;
    // 004f03f4  68c90a9f00             -push 0x9f0ac9
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10422985 /*0x9f0ac9*/;
    cpu.esp -= 4;
    // 004f03f9  2eff1520455300         -call dword ptr cs:[0x534520]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457184) /* 0x534520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0400  83f8ff                 +cmp eax, -1
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
    // 004f0403  7415                   -je 0x4f041a
    if (cpu.flags.zf)
    {
        goto L_0x004f041a;
    }
    // 004f0405  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004f0407  7511                   -jne 0x4f041a
    if (!cpu.flags.zf)
    {
        goto L_0x004f041a;
    }
    // 004f0409  b8c90a9f00             -mov eax, 0x9f0ac9
    cpu.eax = 10422985 /*0x9f0ac9*/;
    // 004f040e  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f0414  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0415  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0416  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0417  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0418  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0419  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f041a:
    // 004f041a  e861feffff             -call 0x4f0280
    cpu.esp -= 4;
    sub_4f0280(app, cpu);
    if (cpu.terminate) return;
    // 004f041f  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004f0425  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0426  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0427  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0428  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0429  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f042a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0430  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0431  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0432  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004f0433:
    // 004f0433  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f0435  fec2                   -inc dl
    (cpu.dl)++;
    // 004f0437  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f043d  f682f04e560002         +test byte ptr [edx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 004f0444  7403                   -je 0x4f0449
    if (cpu.flags.zf)
    {
        goto L_0x004f0449;
    }
    // 004f0446  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f0447  ebea                   -jmp 0x4f0433
    goto L_0x004f0433;
L_0x004f0449:
    // 004f0449  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f044b  80f92b                 +cmp cl, 0x2b
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
    // 004f044e  7405                   -je 0x4f0455
    if (cpu.flags.zf)
    {
        goto L_0x004f0455;
    }
    // 004f0450  80f92d                 +cmp cl, 0x2d
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
    // 004f0453  7501                   -jne 0x4f0456
    if (!cpu.flags.zf)
    {
        goto L_0x004f0456;
    }
L_0x004f0455:
    // 004f0455  40                     -inc eax
    (cpu.eax)++;
L_0x004f0456:
    // 004f0456  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f0458:
    // 004f0458  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f045a  fec3                   -inc bl
    (cpu.bl)++;
    // 004f045c  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f0462  f683f04e560020         +test byte ptr [ebx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 004f0469  740f                   -je 0x4f047a
    if (cpu.flags.zf)
    {
        goto L_0x004f047a;
    }
    // 004f046b  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004f046e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0470  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f0472  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f0474  40                     -inc eax
    (cpu.eax)++;
    // 004f0475  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f0478  ebde                   -jmp 0x4f0458
    goto L_0x004f0458;
L_0x004f047a:
    // 004f047a  80f92d                 +cmp cl, 0x2d
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
    // 004f047d  7502                   -jne 0x4f0481
    if (!cpu.flags.zf)
    {
        goto L_0x004f0481;
    }
    // 004f047f  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004f0481:
    // 004f0481  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f0483  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0484  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0485  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0486  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0490  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0491  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0492  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x004f0493:
    // 004f0493  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f0495  fec2                   -inc dl
    (cpu.dl)++;
    // 004f0497  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f049d  f682f04e560002         +test byte ptr [edx + 0x564ef0], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 2 /*0x2*/));
    // 004f04a4  7403                   -je 0x4f04a9
    if (cpu.flags.zf)
    {
        goto L_0x004f04a9;
    }
    // 004f04a6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004f04a7  ebea                   -jmp 0x4f0493
    goto L_0x004f0493;
L_0x004f04a9:
    // 004f04a9  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f04ab  80f92b                 +cmp cl, 0x2b
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
    // 004f04ae  7405                   -je 0x4f04b5
    if (cpu.flags.zf)
    {
        goto L_0x004f04b5;
    }
    // 004f04b0  80f92d                 +cmp cl, 0x2d
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
    // 004f04b3  7501                   -jne 0x4f04b6
    if (!cpu.flags.zf)
    {
        goto L_0x004f04b6;
    }
L_0x004f04b5:
    // 004f04b5  40                     -inc eax
    (cpu.eax)++;
L_0x004f04b6:
    // 004f04b6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004f04b8:
    // 004f04b8  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f04ba  fec3                   -inc bl
    (cpu.bl)++;
    // 004f04bc  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004f04c2  f683f04e560020         +test byte ptr [ebx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 004f04c9  740f                   -je 0x4f04da
    if (cpu.flags.zf)
    {
        goto L_0x004f04da;
    }
    // 004f04cb  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004f04ce  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004f04d0  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 004f04d2  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004f04d4  40                     -inc eax
    (cpu.eax)++;
    // 004f04d5  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004f04d8  ebde                   -jmp 0x4f04b8
    goto L_0x004f04b8;
L_0x004f04da:
    // 004f04da  80f92d                 +cmp cl, 0x2d
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
    // 004f04dd  7502                   -jne 0x4f04e1
    if (!cpu.flags.zf)
    {
        goto L_0x004f04e1;
    }
    // 004f04df  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004f04e1:
    // 004f04e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f04e3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f04e4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f04e5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f04e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f04f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f04f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f04f1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f04f2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004f04f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f04f7  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 004f04f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004f04fb  7409                   -je 0x4f0506
    if (cpu.flags.zf)
    {
        goto L_0x004f0506;
    }
    // 004f04fd  43                     -inc ebx
    (cpu.ebx)++;
    // 004f04fe  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004f0501  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f0503  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0504  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0505  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0506:
    // 004f0506  8a5810                 -mov bl, byte ptr [eax + 0x10]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004f0509  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004f050c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004f0511  885810                 -mov byte ptr [eax + 0x10], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.bl;
    // 004f0514  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004f0516  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0517  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0518  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4f051c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f051c  ff4a08                 -dec dword ptr [edx + 8]
    (*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))--;
    // 004f051f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f0520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0520  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0521  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0522  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f0525  b9f0044f00             -mov ecx, 0x4f04f0
    cpu.ecx = 5178608 /*0x4f04f0*/;
    // 004f052a  be1c054f00             -mov esi, 0x4f051c
    cpu.esi = 5178652 /*0x4f051c*/;
    // 004f052f  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f0533  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f0535  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004f0538  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004f053c  e80fc10100             -call 0x50c650
    cpu.esp -= 4;
    sub_50c650(app, cpu);
    if (cpu.terminate) return;
    // 004f0541  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f0544  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0545  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0546  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4f0548(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0548  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0549  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f054a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f054d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004f0551  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004f0553  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f0557  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f055a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f055e  e8bdffffff             -call 0x4f0520
    cpu.esp -= 4;
    sub_4f0520(app, cpu);
    if (cpu.terminate) return;
    // 004f0563  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f0566  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0567  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0570  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0571  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0572  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0573  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004f0574  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f0577  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004f0579  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004f057b  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004f057e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004f0580  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0586  8a630c                 -mov ah, byte ptr [ebx + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004f0589  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004f058c  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 004f058f  83e730                 -and edi, 0x30
    cpu.edi &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004f0592  88630c                 -mov byte ptr [ebx + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x004f0595:
    // 004f0595  49                     -dec ecx
    (cpu.ecx)--;
    // 004f0596  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004f0598  7e1a                   -jle 0x4f05b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004f05b4;
    }
    // 004f059a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004f059c  e84f250100             -call 0x502af0
    cpu.esp -= 4;
    sub_502af0(app, cpu);
    if (cpu.terminate) return;
    // 004f05a1  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004f05a4  83f8ff                 +cmp eax, -1
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
    // 004f05a7  740b                   -je 0x4f05b4
    if (cpu.flags.zf)
    {
        goto L_0x004f05b4;
    }
    // 004f05a9  42                     -inc edx
    (cpu.edx)++;
    // 004f05aa  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 004f05ad  8842ff                 -mov byte ptr [edx - 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004f05b0  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004f05b2  75e1                   -jne 0x4f0595
    if (!cpu.flags.zf)
    {
        goto L_0x004f0595;
    }
L_0x004f05b4:
    // 004f05b4  833c24ff               +cmp dword ptr [esp], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004f05b8  750e                   -jne 0x4f05c8
    if (!cpu.flags.zf)
    {
        goto L_0x004f05c8;
    }
    // 004f05ba  39f2                   +cmp edx, esi
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
    // 004f05bc  7406                   -je 0x4f05c4
    if (cpu.flags.zf)
    {
        goto L_0x004f05c4;
    }
    // 004f05be  f6430c20               +test byte ptr [ebx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004f05c2  7404                   -je 0x4f05c8
    if (cpu.flags.zf)
    {
        goto L_0x004f05c8;
    }
L_0x004f05c4:
    // 004f05c4  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004f05c6  eb03                   -jmp 0x4f05cb
    goto L_0x004f05cb;
L_0x004f05c8:
    // 004f05c8  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x004f05cb:
    // 004f05cb  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004f05ce  09fd                   -or ebp, edi
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edi));
    // 004f05d0  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004f05d3  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004f05d6  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f05dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004f05de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004f05e1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f05e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f05e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f05e4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f05e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f05f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f05f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f05f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f05f2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f05f4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f05f5  2eff1520455300         -call dword ptr cs:[0x534520]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457184) /* 0x534520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f05fc  83f8ff                 +cmp eax, -1
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
    // 004f05ff  7508                   -jne 0x4f0609
    if (!cpu.flags.zf)
    {
        goto L_0x004f0609;
    }
    // 004f0601  e8ee090100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004f0606  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0607  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0608  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0609:
    // 004f0609  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004f060c  7411                   -je 0x4f061f
    if (cpu.flags.zf)
    {
        goto L_0x004f061f;
    }
    // 004f060e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004f0610  740d                   -je 0x4f061f
    if (cpu.flags.zf)
    {
        goto L_0x004f061f;
    }
    // 004f0612  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f0617  e870090100             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 004f061c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f061d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f061e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f061f:
    // 004f061f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0621  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0622  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0623  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0630  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f0635  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f0640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0640  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0641  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f0643  e8e8ffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f0648  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f064a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f064b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f0650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0650  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0651  8b15dc515600           -mov edx, dword ptr [0x5651dc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5657052) /* 0x5651dc */);
    // 004f0657  e8d4ffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f065c  a3dc515600             -mov dword ptr [0x5651dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657052) /* 0x5651dc */) = cpu.eax;
    // 004f0661  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0663  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4f0670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0670  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0671  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0673  8915a4c17900           -mov dword ptr [0x79c1a4], edx
    *app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */) = cpu.edx;
    // 004f0679  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 004f067e  a3dc515600             -mov dword ptr [0x5651dc], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657052) /* 0x5651dc */) = cpu.eax;
    // 004f0683  a3d8515600             -mov dword ptr [0x5651d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657048) /* 0x5651d8 */) = cpu.eax;
    // 004f0688  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0689  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f0690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0690  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0691  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f0693  e898ffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f0698  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f069a  a3d8515600             -mov dword ptr [0x5651d8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5657048) /* 0x5651d8 */) = cpu.eax;
    // 004f069f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f06a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4f06a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x004f06a1:
    // 004f06a1  e88a6fffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f06a6  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004f06ac  8d542200               -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 004f06b0  e80b000000             -call 0x4f06c0
    cpu.esp -= 4;
    sub_4f06c0(app, cpu);
    if (cpu.terminate) return;
    // 004f06b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f06b7  74e8                   -je 0x4f06a1
    if (cpu.flags.zf)
    {
        goto L_0x004f06a1;
    }
    // 004f06b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f06c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f06c0  e86bffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f06c5  2b05d8515600           -sub eax, dword ptr [0x5651d8]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5657048) /* 0x5651d8 */)));
    // 004f06cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f06cd  7c06                   -jl 0x4f06d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f06d5;
    }
    // 004f06cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004f06d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f06d5:
    // 004f06d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f06d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4f06e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f06e0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f06e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f06e3  e848ffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f06e8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004f06ea  e841ffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f06ef  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f06f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f06f3  7c02                   -jl 0x4f06f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f06f7;
    }
    // 004f06f5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f06f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f06f7:
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 004f06f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f06f9  e8326fffff             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004f06fe  e82dffffff             -call 0x4f0630
    cpu.esp -= 4;
    sub_4f0630(app, cpu);
    if (cpu.terminate) return;
    // 004f0703  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0705  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0707  7cee                   -jl 0x4f06f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004f06f7;
    }
    // 004f0709  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f070a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4f0710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0710  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0711  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0712  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004f0714  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004f0717  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004f0719  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004f071c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004f071e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004f0720  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004f0723  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f0724  2eff1504465300         -call dword ptr cs:[0x534604]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457412) /* 0x534604 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f072b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f072c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f072d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f0730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0730  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f0731  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f0732  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004f0733  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f0734  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004f073a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f073c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004f073e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004f0740  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f0741  6804010000             -push 0x104
    *app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004f0746  2eff1500455300         -call dword ptr cs:[0x534500]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457152) /* 0x534500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f074d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004f074f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0751  7509                   -jne 0x4f075c
    if (!cpu.flags.zf)
    {
        goto L_0x004f075c;
    }
    // 004f0753  e89c080100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004f0758  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004f075a  eb65                   -jmp 0x4f07c1
    goto L_0x004f07c1;
L_0x004f075c:
    // 004f075c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004f075e  7529                   -jne 0x4f0789
    if (!cpu.flags.zf)
    {
        goto L_0x004f0789;
    }
    // 004f0760  40                     -inc eax
    (cpu.eax)++;
    // 004f0761  39c6                   +cmp esi, eax
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
    // 004f0763  7602                   -jbe 0x4f0767
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f0767;
    }
    // 004f0765  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004f0767:
    // 004f0767  e894710000             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 004f076c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004f076e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0770  7532                   -jne 0x4f07a4
    if (!cpu.flags.zf)
    {
        goto L_0x004f07a4;
    }
    // 004f0772  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004f0777  e804210100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004f077c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f077e  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004f0784  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0785  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0786  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0787  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f0788  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f0789:
    // 004f0789  39f0                   +cmp eax, esi
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
    // 004f078b  7617                   -jbe 0x4f07a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004f07a4;
    }
    // 004f078d  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004f0792  e8e9200100             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 004f0797  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004f0799  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004f079f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07a0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07a2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004f07a4:
    // 004f07a4  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004f07a6  41                     -inc ecx
    (cpu.ecx)++;
    // 004f07a7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004f07a9  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004f07aa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004f07ac  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004f07ae  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004f07af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004f07b1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004f07b4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004f07b6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004f07b8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004f07bb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004f07bd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07be  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004f07bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004f07c1:
    // 004f07c1  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004f07c7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07c8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07c9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07ca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f07cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4f07d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f07d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004f07d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004f07d2  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f07d5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004f07d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f07d9  7419                   -je 0x4f07f4
    if (cpu.flags.zf)
    {
        goto L_0x004f07f4;
    }
    // 004f07db  0440                   -add al, 0x40
    (cpu.al) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004f07dd  b25c                   -mov dl, 0x5c
    cpu.dl = 92 /*0x5c*/;
    // 004f07df  880424                 -mov byte ptr [esp], al
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 004f07e2  88542402               -mov byte ptr [esp + 2], dl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dl;
    // 004f07e6  b43a                   -mov ah, 0x3a
    cpu.ah = 58 /*0x3a*/;
    // 004f07e8  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004f07ea  88642401               -mov byte ptr [esp + 1], ah
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.ah;
    // 004f07ee  88742403               -mov byte ptr [esp + 3], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 004f07f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004f07f4:
    // 004f07f4  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f07f8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f07f9  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f07fd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f07fe  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004f0802  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0803  8d54241c               -lea edx, [esp + 0x1c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004f0807  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004f0808  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004f0809  2eff1514455300         -call dword ptr cs:[0x534514]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457172) /* 0x534514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004f0810  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004f0812  7507                   -jne 0x4f081b
    if (!cpu.flags.zf)
    {
        goto L_0x004f081b;
    }
    // 004f0814  e8db070100             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 004f0819  eb1d                   -jmp 0x4f0838
    goto L_0x004f0838;
L_0x004f081b:
    // 004f081b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004f081f  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004f0821  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004f0825  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004f0828  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004f082c  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004f082f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004f0833  89430c                 -mov dword ptr [ebx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004f0836  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004f0838:
    // 004f0838  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004f083b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f083c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004f083d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4f0840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0840  a118725600             -mov eax, dword ptr [0x567218]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665304) /* 0x567218 */);
    // 004f0845  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4f0850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0850  8915fc715600           -mov dword ptr [0x5671fc], edx
    *app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */) = cpu.edx;
    // 004f0856  a3f8715600             -mov dword ptr [0x5671f8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */) = cpu.eax;
    // 004f085b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4f0860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0860  a30c725600             -mov dword ptr [0x56720c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */) = cpu.eax;
    // 004f0865  e966b80100             -jmp 0x50c0d0
    return sub_50c0d0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4f0870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004f0870  a10c725600             -mov eax, dword ptr [0x56720c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665292) /* 0x56720c */);
    // 004f0875  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
