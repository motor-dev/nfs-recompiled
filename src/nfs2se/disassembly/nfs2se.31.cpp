#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4a961c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a961c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a961d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a961e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a961f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a9622  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9624  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9626  6a1c                   -push 0x1c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004a9628  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a962c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a962d  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9631  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9632  2eff159c554b00         -call dword ptr cs:[0x4b559c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937116) /* 0x4b559c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9639  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004a963c  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a9640  668b0d05ac4c00         -mov cx, word ptr [0x4cac05]
    cpu.cx = *app->getMemory<x86::reg16>(x86::reg32(5024773) /* 0x4cac05 */);
    // 004a9647  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a964b  6681f90080             +cmp cx, 0x8000
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9650  7307                   -jae 0x4a9659
    if (!cpu.flags.cf)
    {
        goto L_0x004a9659;
    }
    // 004a9652  0500300000             +add eax, 0x3000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12288 /*0x3000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9657  eb17                   -jmp 0x4a9670
    goto L_0x004a9670;
L_0x004a9659:
    // 004a9659  7210                   -jb 0x4a966b
    if (cpu.flags.cf)
    {
        goto L_0x004a966b;
    }
    // 004a965b  803d03ac4c0004         +cmp byte ptr [0x4cac03], 4
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5024771) /* 0x4cac03 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9662  7307                   -jae 0x4a966b
    if (!cpu.flags.cf)
    {
        goto L_0x004a966b;
    }
    // 004a9664  0500200100             +add eax, 0x12000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73728 /*0x12000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9669  eb05                   -jmp 0x4a9670
    goto L_0x004a9670;
L_0x004a966b:
    // 004a966b  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x004a9670:
    // 004a9670  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9672  7402                   -je 0x4a9676
    if (cpu.flags.zf)
    {
        goto L_0x004a9676;
    }
    // 004a9674  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004a9676:
    // 004a9676  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9678  7402                   -je 0x4a967c
    if (cpu.flags.zf)
    {
        goto L_0x004a967c;
    }
    // 004a967a  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x004a967c:
    // 004a967c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a967f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9680  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9681  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9682  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9683(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9683  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9684  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9685  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9686  68a8f64b00             -push 0x4bf6a8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4978344 /*0x4bf6a8*/;
    cpu.esp -= 4;
    // 004a968b  2eff1514554b00         -call dword ptr cs:[0x4b5514]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936980) /* 0x4b5514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9692  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9694  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9696  7417                   -je 0x4a96af
    if (cpu.flags.zf)
    {
        goto L_0x004a96af;
    }
    // 004a9698  68b3f64b00             -push 0x4bf6b3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4978355 /*0x4bf6b3*/;
    cpu.esp -= 4;
    // 004a969d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a969e  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a96a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a96a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a96a9  7404                   -je 0x4a96af
    if (cpu.flags.zf)
    {
        goto L_0x004a96af;
    }
    // 004a96ab  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a96ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a96af:
    // 004a96af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a96b1  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004a96b4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a96b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96ba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a96bd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a96bd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a96be  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a96bf  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a96c0  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a96c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a96c4:
    // 004a96c4  803800                 +cmp byte ptr [eax], 0
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
    // 004a96c7  7403                   -je 0x4a96cc
    if (cpu.flags.zf)
    {
        goto L_0x004a96cc;
    }
    // 004a96c9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a96ca  ebf8                   -jmp 0x4a96c4
    goto L_0x004a96c4;
L_0x004a96cc:
    // 004a96cc  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x004a96cf:
    // 004a96cf  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 004a96d1  8808                   -mov byte ptr [eax], cl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a96d3  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a96d5  7412                   -je 0x4a96e9
    if (cpu.flags.zf)
    {
        goto L_0x004a96e9;
    }
    // 004a96d7  80f930                 +cmp cl, 0x30
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a96da  7508                   -jne 0x4a96e4
    if (!cpu.flags.zf)
    {
        goto L_0x004a96e4;
    }
    // 004a96dc  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a96e0  7502                   -jne 0x4a96e4
    if (!cpu.flags.zf)
    {
        goto L_0x004a96e4;
    }
    // 004a96e2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004a96e4:
    // 004a96e4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a96e5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a96e6  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a96e7  ebe6                   -jmp 0x4a96cf
    goto L_0x004a96cf;
L_0x004a96e9:
    // 004a96e9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a96eb  7419                   -je 0x4a9706
    if (cpu.flags.zf)
    {
        goto L_0x004a9706;
    }
    // 004a96ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a96ef:
    // 004a96ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a96f1  7413                   -je 0x4a9706
    if (cpu.flags.zf)
    {
        goto L_0x004a9706;
    }
    // 004a96f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a96f5  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004a96f8  8a9274d64c00           -mov dl, byte ptr [edx + 0x4cd674]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5035636) /* 0x4cd674 */);
    // 004a96fe  c1e804                 +shr eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a9701  8813                   -mov byte ptr [ebx], dl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004a9703  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9704  ebe9                   -jmp 0x4a96ef
    goto L_0x004a96ef;
L_0x004a9706:
    // 004a9706  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9707  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9708  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a970a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a970a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a970b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a970c  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004a9712  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004a9719  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004a971b  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a971e  e860ffffff             -call 0x4a9683
    cpu.esp -= 4;
    sub_4a9683(app, cpu);
    if (cpu.terminate) return;
    // 004a9723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9725  750a                   -jne 0x4a9731
    if (!cpu.flags.zf)
    {
        goto L_0x004a9731;
    }
    // 004a9727  e822610000             -call 0x4af84e
    cpu.esp -= 4;
    sub_4af84e(app, cpu);
    if (cpu.terminate) return;
    // 004a972c  83f8ff                 +cmp eax, -1
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
    // 004a972f  7507                   -jne 0x4a9738
    if (!cpu.flags.zf)
    {
        goto L_0x004a9738;
    }
L_0x004a9731:
    // 004a9731  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9733  e97e010000             -jmp 0x4a98b6
    goto L_0x004a98b6;
L_0x004a9738:
    // 004a9738  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a973a  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004a973d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004a973f  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9744  724d                   -jb 0x4a9793
    if (cpu.flags.cf)
    {
        goto L_0x004a9793;
    }
    // 004a9746  0f86b5000000           -jbe 0x4a9801
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9801;
    }
    // 004a974c  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9751  7233                   -jb 0x4a9786
    if (cpu.flags.cf)
    {
        goto L_0x004a9786;
    }
    // 004a9753  0f86a1000000           -jbe 0x4a97fa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a97fa;
    }
    // 004a9759  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a975e  7216                   -jb 0x4a9776
    if (cpu.flags.cf)
    {
        goto L_0x004a9776;
    }
    // 004a9760  0f86d8000000           -jbe 0x4a983e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a983e;
    }
    // 004a9766  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a976b  0f84e5000000           -je 0x4a9856
    if (cpu.flags.zf)
    {
        goto L_0x004a9856;
    }
    // 004a9771  e9ea000000             -jmp 0x4a9860
    goto L_0x004a9860;
L_0x004a9776:
    // 004a9776  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a977b  0f84cb000000           -je 0x4a984c
    if (cpu.flags.zf)
    {
        goto L_0x004a984c;
    }
    // 004a9781  e9da000000             -jmp 0x4a9860
    goto L_0x004a9860;
L_0x004a9786:
    // 004a9786  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a978b  0f8662000000           -jbe 0x4a97f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a97f3;
    }
    // 004a9791  eb2f                   -jmp 0x4a97c2
    goto L_0x004a97c2;
L_0x004a9793:
    // 004a9793  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9798  720b                   -jb 0x4a97a5
    if (cpu.flags.cf)
    {
        goto L_0x004a97a5;
    }
    // 004a979a  7642                   -jbe 0x4a97de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a97de;
    }
    // 004a979c  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a97a1  7642                   -jbe 0x4a97e5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a97e5;
    }
    // 004a97a3  eb47                   -jmp 0x4a97ec
    goto L_0x004a97ec;
L_0x004a97a5:
    // 004a97a5  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a97aa  0f82b0000000           -jb 0x4a9860
    if (cpu.flags.cf)
    {
        goto L_0x004a9860;
    }
    // 004a97b0  7656                   -jbe 0x4a9808
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9808;
    }
    // 004a97b2  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a97b7  0f8488000000           -je 0x4a9845
    if (cpu.flags.zf)
    {
        goto L_0x004a9845;
    }
    // 004a97bd  e99e000000             -jmp 0x4a9860
    goto L_0x004a9860;
L_0x004a97c2:
    // 004a97c2  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004a97c6  740f                   -je 0x4a97d7
    if (cpu.flags.zf)
    {
        goto L_0x004a97d7;
    }
    // 004a97c8  bac3f64b00             -mov edx, 0x4bf6c3
    cpu.edx = 4978371 /*0x4bf6c3*/;
L_0x004a97cd:
    // 004a97cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a97cf  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a97d2  e9a1000000             -jmp 0x4a9878
    goto L_0x004a9878;
L_0x004a97d7:
    // 004a97d7  ba14f74b00             -mov edx, 0x4bf714
    cpu.edx = 4978452 /*0x4bf714*/;
    // 004a97dc  ebef                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a97de:
    // 004a97de  ba66f74b00             -mov edx, 0x4bf766
    cpu.edx = 4978534 /*0x4bf766*/;
    // 004a97e3  ebe8                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a97e5:
    // 004a97e5  bab9f74b00             -mov edx, 0x4bf7b9
    cpu.edx = 4978617 /*0x4bf7b9*/;
    // 004a97ea  ebe1                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a97ec:
    // 004a97ec  ba0cf84b00             -mov edx, 0x4bf80c
    cpu.edx = 4978700 /*0x4bf80c*/;
    // 004a97f1  ebda                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a97f3:
    // 004a97f3  ba5df84b00             -mov edx, 0x4bf85d
    cpu.edx = 4978781 /*0x4bf85d*/;
    // 004a97f8  ebd3                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a97fa:
    // 004a97fa  baa9f84b00             -mov edx, 0x4bf8a9
    cpu.edx = 4978857 /*0x4bf8a9*/;
    // 004a97ff  ebcc                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a9801:
    // 004a9801  baf6f84b00             -mov edx, 0x4bf8f6
    cpu.edx = 4978934 /*0x4bf8f6*/;
    // 004a9806  ebc5                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a9808:
    // 004a9808  ba4bf94b00             -mov edx, 0x4bf94b
    cpu.edx = 4979019 /*0x4bf94b*/;
    // 004a980d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a980f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a9812  e8a6feffff             -call 0x4a96bd
    cpu.esp -= 4;
    sub_4a96bd(app, cpu);
    if (cpu.terminate) return;
    // 004a9817  ba7cf94b00             -mov edx, 0x4bf97c
    cpu.edx = 4979068 /*0x4bf97c*/;
    // 004a981c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a981e  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a9821  e897feffff             -call 0x4a96bd
    cpu.esp -= 4;
    sub_4a96bd(app, cpu);
    if (cpu.terminate) return;
    // 004a9826  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a982a  750b                   -jne 0x4a9837
    if (!cpu.flags.zf)
    {
        goto L_0x004a9837;
    }
    // 004a982c  baa4f94b00             -mov edx, 0x4bf9a4
    cpu.edx = 4979108 /*0x4bf9a4*/;
L_0x004a9831:
    // 004a9831  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9833  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a9835  eb41                   -jmp 0x4a9878
    goto L_0x004a9878;
L_0x004a9837:
    // 004a9837  baabf94b00             -mov edx, 0x4bf9ab
    cpu.edx = 4979115 /*0x4bf9ab*/;
    // 004a983c  ebf3                   -jmp 0x4a9831
    goto L_0x004a9831;
L_0x004a983e:
    // 004a983e  bab5f94b00             -mov edx, 0x4bf9b5
    cpu.edx = 4979125 /*0x4bf9b5*/;
    // 004a9843  eb88                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a9845:
    // 004a9845  baf3f94b00             -mov edx, 0x4bf9f3
    cpu.edx = 4979187 /*0x4bf9f3*/;
    // 004a984a  eb81                   -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a984c:
    // 004a984c  ba2ffa4b00             -mov edx, 0x4bfa2f
    cpu.edx = 4979247 /*0x4bfa2f*/;
    // 004a9851  e977ffffff             -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a9856:
    // 004a9856  ba71fa4b00             -mov edx, 0x4bfa71
    cpu.edx = 4979313 /*0x4bfa71*/;
    // 004a985b  e96dffffff             -jmp 0x4a97cd
    goto L_0x004a97cd;
L_0x004a9860:
    // 004a9860  baaafa4b00             -mov edx, 0x4bfaaa
    cpu.edx = 4979370 /*0x4bfaaa*/;
    // 004a9865  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9867  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004a9869  e84ffeffff             -call 0x4a96bd
    cpu.esp -= 4;
    sub_4a96bd(app, cpu);
    if (cpu.terminate) return;
    // 004a986e  badbfa4b00             -mov edx, 0x4bfadb
    cpu.edx = 4979419 /*0x4bfadb*/;
    // 004a9873  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9875  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x004a9878:
    // 004a9878  e840feffff             -call 0x4a96bd
    cpu.esp -= 4;
    sub_4a96bd(app, cpu);
    if (cpu.terminate) return;
    // 004a987d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a987f  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004a9886  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9887  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a988b  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a988c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a988e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a9890  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9892  49                     -dec ecx
    (cpu.ecx)--;
    // 004a9893  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9895  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004a9897  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a9899  49                     -dec ecx
    (cpu.ecx)--;
    // 004a989a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a989b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a989c  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a98a0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a98a1  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a98a6  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a98a9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a98aa  2eff15b0554b00         -call dword ptr cs:[0x4b55b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937136) /* 0x4b55b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a98b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a98b6:
    // 004a98b6  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004a98bc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98bd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98be  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a98c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004a98c1  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a98c3  29994a003399           -sub dword ptr [ecx - 0x66ccffb6], ebx
    (*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-1724710838) /* -0x66ccffb6 */)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a98c9  4a                     -dec edx
    (cpu.edx)--;
    // 004a98ca  003d994a005b           -add byte ptr [0x5b004a99], bh
    (*app->getMemory<x86::reg8>(x86::reg32(1526745753) /* 0x5b004a99 */)) += x86::reg8(x86::sreg8(cpu.bh));
    // 004a98d0  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004a98d1  4a                     -dec edx
    (cpu.edx)--;
    // 004a98d2  004799                 -add byte ptr [edi - 0x67], al
    (*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-103) /* -0x67 */)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a98d5  4a                     -dec edx
    (cpu.edx)--;
    // 004a98d6  000f                   -add byte ptr [edi], cl
    (*app->getMemory<x86::reg8>(cpu.edi)) += x86::reg8(x86::sreg8(cpu.cl));
    // 004a98d8  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004a98d9  4a                     -dec edx
    (cpu.edx)--;
    // 004a98da  005199                 -add byte ptr [ecx - 0x67], dl
    (*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-103) /* -0x67 */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004a98dd  4a                     -dec edx
    (cpu.edx)--;
    // 004a98de  005356                 -add byte ptr [ebx + 0x56], dl
    (*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(86) /* 0x56 */)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004a98e1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a98e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a98e5  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a98e9  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a98ed  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004a98f1  0f85a0010000           -jne 0x4a9a97
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a97;
    }
    // 004a98f7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 004a98f9  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 004a98fe  83f806                 +cmp eax, 6
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
    // 004a9901  0f8723010000           -ja 0x4a9a2a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9a2a;
    }
    // 004a9907  2eff2485c3984a00       -jmp dword ptr cs:[eax*4 + 0x4a98c3]
    cpu.ip = *app->getMemory<x86::reg32>(4888771 + cpu.eax * 4); goto dynamic_jump;
  case 0x004a990f:
    // 004a990f  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004a9913  740a                   -je 0x4a991f
    if (cpu.flags.zf)
    {
        goto L_0x004a991f;
    }
    // 004a9915  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 004a991a  e9ce000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
L_0x004a991f:
    // 004a991f  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 004a9924  e9c4000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a9929:
    // 004a9929  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 004a992e  e9ba000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a9933:
L_0x004a9933:
    // 004a9933  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 004a9938  e9b0000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a993d:
    // 004a993d  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 004a9942  e9a6000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a9947:
    // 004a9947  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 004a994c  e99c000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a9951:
    // 004a9951  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 004a9956  e992000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
  case 0x004a995b:
    // 004a995b  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004a995e  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 004a9961  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 004a9966  6681fad9fa             +cmp dx, 0xfad9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64217 /*0xfad9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a996b  750a                   -jne 0x4a9977
    if (!cpu.flags.zf)
    {
        goto L_0x004a9977;
    }
    // 004a996d  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 004a9972  e976000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
L_0x004a9977:
    // 004a9977  6681fad9f1             +cmp dx, 0xf1d9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61913 /*0xf1d9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a997c  750a                   -jne 0x4a9988
    if (!cpu.flags.zf)
    {
        goto L_0x004a9988;
    }
    // 004a997e  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 004a9983  e965000000             -jmp 0x4a99ed
    goto L_0x004a99ed;
L_0x004a9988:
    // 004a9988  7507                   -jne 0x4a9991
    if (!cpu.flags.zf)
    {
        goto L_0x004a9991;
    }
    // 004a998a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 004a998f  eb5c                   -jmp 0x4a99ed
    goto L_0x004a99ed;
L_0x004a9991:
    // 004a9991  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.eax);
    // 004a9993  80fedb                 +cmp dh, 0xdb
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(219 /*0xdb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9996  7405                   -je 0x4a999d
    if (cpu.flags.zf)
    {
        goto L_0x004a999d;
    }
    // 004a9998  80fedf                 +cmp dh, 0xdf
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(223 /*0xdf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a999b  7510                   -jne 0x4a99ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a99ad;
    }
L_0x004a999d:
    // 004a999d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a99a0  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004a99a3  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a99a6  7505                   -jne 0x4a99ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a99ad;
    }
    // 004a99a8  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x004a99ad:
    // 004a99ad  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004a99b0  7536                   -jne 0x4a99e8
    if (!cpu.flags.zf)
    {
        goto L_0x004a99e8;
    }
    // 004a99b2  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a99b5  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004a99b7  3c30                   +cmp al, 0x30
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
    // 004a99b9  752d                   -jne 0x4a99e8
    if (!cpu.flags.zf)
    {
        goto L_0x004a99e8;
    }
    // 004a99bb  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004a99be  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a99c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a99c6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a99c8  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 004a99cc  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004a99cf  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 004a99d2  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a99d8  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a99da  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004a99dc  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a99df  83fa01                 +cmp edx, 1
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
    // 004a99e2  0f844bffffff           -je 0x4a9933
    if (cpu.flags.zf)
    {
        goto L_0x004a9933;
    }
L_0x004a99e8:
    // 004a99e8  83fbff                 +cmp ebx, -1
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
    // 004a99eb  743d                   -je 0x4a9a2a
    if (cpu.flags.zf)
    {
        goto L_0x004a9a2a;
    }
L_0x004a99ed:
    // 004a99ed  c6058870540001         -mov byte ptr [0x547088], 1
    *app->getMemory<x86::reg8>(x86::reg32(5533832) /* 0x547088 */) = 1 /*0x1*/;
    // 004a99f4  e8605e0000             -call 0x4af859
    cpu.esp -= 4;
    sub_4af859(app, cpu);
    if (cpu.terminate) return;
    // 004a99f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a99fb  e826600000             -call 0x4afa26
    cpu.esp -= 4;
    sub_4afa26(app, cpu);
    if (cpu.terminate) return;
    // 004a9a00  83f8ff                 +cmp eax, -1
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
    // 004a9a03  0f846f000000           -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a09  803d8870540000         +cmp byte ptr [0x547088], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5533832) /* 0x547088 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9a10  0f8462000000           -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a16  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004a9a1a  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004a9a1c  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004a9a1f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9a21  66895f20               -mov word ptr [edi + 0x20], bx
    *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 004a9a25  e972000000             -jmp 0x4a9a9c
    goto L_0x004a9a9c;
L_0x004a9a2a:
    // 004a9a2a  833d70d64c0000         +cmp dword ptr [0x4cd670], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5035632) /* 0x4cd670 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9a31  7445                   -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a33  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a9a38:
    // 004a9a38  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9a3a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 004a9a3c  ff156cd64c00           -call dword ptr [0x4cd66c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035628) /* 0x4cd66c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9a42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9a44  742c                   -je 0x4a9a72
    if (cpu.flags.zf)
    {
        goto L_0x004a9a72;
    }
    // 004a9a46  83f801                 +cmp eax, 1
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
    // 004a9a49  742d                   -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a4b  83f802                 +cmp eax, 2
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
    // 004a9a4e  7428                   -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a50  83f803                 +cmp eax, 3
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
    // 004a9a53  7423                   -je 0x4a9a78
    if (cpu.flags.zf)
    {
        goto L_0x004a9a78;
    }
    // 004a9a55  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004a9a57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9a59  881588705400           -mov byte ptr [0x547088], dl
    *app->getMemory<x86::reg8>(x86::reg32(5533832) /* 0x547088 */) = cpu.dl;
    // 004a9a5f  ff1570d64c00           -call dword ptr [0x4cd670]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5035632) /* 0x4cd670 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9a65  803d8870540000         +cmp byte ptr [0x547088], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5533832) /* 0x547088 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9a6c  7404                   -je 0x4a9a72
    if (cpu.flags.zf)
    {
        goto L_0x004a9a72;
    }
    // 004a9a6e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9a70  eb2a                   -jmp 0x4a9a9c
    goto L_0x004a9a9c;
L_0x004a9a72:
    // 004a9a72  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9a73  83fb0c                 +cmp ebx, 0xc
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
    // 004a9a76  7ec0                   -jle 0x4a9a38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9a38;
    }
L_0x004a9a78:
    // 004a9a78  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9a7a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9a7b  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a9a7f  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a9a83  2eff158c554b00         -call dword ptr cs:[0x4b558c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937100) /* 0x4b558c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9a8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9a8c  7409                   -je 0x4a9a97
    if (cpu.flags.zf)
    {
        goto L_0x004a9a97;
    }
    // 004a9a8e  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a9a90  2eff1554544b00         -call dword ptr cs:[0x4b5454]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936788) /* 0x4b5454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a9a97:
    // 004a9a97  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a9a9c:
    // 004a9a9c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9a9f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9aa0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9aa1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9aa2  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4a9aa3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9aa3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9aa4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9aa5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9aa7  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9aad  895054                 -mov dword ptr [eax + 0x54], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004a9ab0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9ab2  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 004a9ab5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9ab7  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9abd  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a9ac0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a9ac2  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9ac8  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a9acb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9acd  c74004df984a00         -mov dword ptr [eax + 4], 0x4a98df
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4888799 /*0x4a98df*/;
    // 004a9ad4  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9ada  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a9add  648902                 -mov dword ptr fs:[edx], eax
    *app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 004a9ae0  680a974a00             -push 0x4a970a
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4888330 /*0x4a970a*/;
    cpu.esp -= 4;
    // 004a9ae5  2eff1570554b00         -call dword ptr cs:[0x4b5570]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937072) /* 0x4b5570 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9aec  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9aed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9aee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9aef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9aef  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9af0  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9af6  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004a9af9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9afb  7407                   -je 0x4a9b04
    if (cpu.flags.zf)
    {
        goto L_0x004a9b04;
    }
    // 004a9afd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a9aff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9b01  648902                 -mov dword ptr fs:[edx], eax
    *app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x004a9b04:
    // 004a9b04  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9b0a  c7405400000000         -mov dword ptr [eax + 0x54], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004a9b11  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b13(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b13  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9b18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9b1a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9b1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9b1d  ff1558c14c00           -call dword ptr [0x4cc158]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9b23  8b15f42b5400           -mov edx, dword ptr [0x542bf4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 004a9b29  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a9b2b  eb16                   -jmp 0x4a9b43
    goto L_0x004a9b43;
L_0x004a9b2d:
    // 004a9b2d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9b30  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004a9b33  740c                   -je 0x4a9b41
    if (cpu.flags.zf)
    {
        goto L_0x004a9b41;
    }
    // 004a9b35  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9b36  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a9b3a  7405                   -je 0x4a9b41
    if (cpu.flags.zf)
    {
        goto L_0x004a9b41;
    }
    // 004a9b3c  e89f0effff             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
L_0x004a9b41:
    // 004a9b41  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
L_0x004a9b43:
    // 004a9b43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a9b45  75e6                   -jne 0x4a9b2d
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b2d;
    }
    // 004a9b47  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9b4d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9b4f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b50  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b51  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a9b18;
    // 004a9b13  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_entry_0x004a9b18:
    // 004a9b18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9b1a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9b1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9b1d  ff1558c14c00           -call dword ptr [0x4cc158]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9b23  8b15f42b5400           -mov edx, dword ptr [0x542bf4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 004a9b29  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a9b2b  eb16                   -jmp 0x4a9b43
    goto L_0x004a9b43;
L_0x004a9b2d:
    // 004a9b2d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a9b30  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004a9b33  740c                   -je 0x4a9b41
    if (cpu.flags.zf)
    {
        goto L_0x004a9b41;
    }
    // 004a9b35  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9b36  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a9b3a  7405                   -je 0x4a9b41
    if (cpu.flags.zf)
    {
        goto L_0x004a9b41;
    }
    // 004a9b3c  e89f0effff             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
L_0x004a9b41:
    // 004a9b41  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
L_0x004a9b43:
    // 004a9b43  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a9b45  75e6                   -jne 0x4a9b2d
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b2d;
    }
    // 004a9b47  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9b4d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9b4f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b50  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b51  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b53(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b53  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b54  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9b55  8b1decab4c00           -mov ebx, dword ptr [0x4cabec]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5024748) /* 0x4cabec */);
    // 004a9b5b  e879610000             -call 0x4afcd9
    cpu.esp -= 4;
    sub_4afcd9(app, cpu);
    if (cpu.terminate) return;
    // 004a9b60  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9b62  83f8ff                 +cmp eax, -1
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
    // 004a9b65  7409                   -je 0x4a9b70
    if (cpu.flags.zf)
    {
        goto L_0x004a9b70;
    }
    // 004a9b67  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9b69  7505                   -jne 0x4a9b70
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b70;
    }
    // 004a9b6b  e8e5610000             -call 0x4afd55
    cpu.esp -= 4;
    sub_4afd55(app, cpu);
    if (cpu.terminate) return;
L_0x004a9b70:
    // 004a9b70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9b72  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b73  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b75(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b75  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 004a9b7b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a9b7d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9b82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9b83(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b83  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9b85  e92f620000             -jmp 0x4afdb9
    return sub_4afdb9(app, cpu);
}

/* align: skip  */
void Application::sub_4a9b8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b8a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9b8b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9b8c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9b8d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9b8e  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9b90  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9b93  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9b95  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a9b97  7507                   -jne 0x4a9ba0
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ba0;
    }
L_0x004a9b99:
    // 004a9b99  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9b9b  e977000000             -jmp 0x4a9c17
    goto L_0x004a9c17;
L_0x004a9ba0:
    // 004a9ba0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9ba2  0f866a000000           -jbe 0x4a9c12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9c12;
    }
    // 004a9ba8  803a00                 +cmp byte ptr [edx], 0
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
    // 004a9bab  750b                   -jne 0x4a9bb8
    if (!cpu.flags.zf)
    {
        goto L_0x004a9bb8;
    }
    // 004a9bad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9baf  74e8                   -je 0x4a9b99
    if (cpu.flags.zf)
    {
        goto L_0x004a9b99;
    }
    // 004a9bb1  66c7060000             -mov word ptr [esi], 0
    *app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004a9bb6  ebe1                   -jmp 0x4a9b99
    goto L_0x004a9b99;
L_0x004a9bb8:
    // 004a9bb8  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9bbf  7419                   -je 0x4a9bda
    if (cpu.flags.zf)
    {
        goto L_0x004a9bda;
    }
    // 004a9bc1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9bc3  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 004a9bc5  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 004a9bcb  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a9bcd  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a9bd2  7406                   -je 0x4a9bda
    if (cpu.flags.zf)
    {
        goto L_0x004a9bda;
    }
    // 004a9bd4  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9bd8  7438                   -je 0x4a9c12
    if (cpu.flags.zf)
    {
        goto L_0x004a9c12;
    }
L_0x004a9bda:
    // 004a9bda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9bdc  e824630000             -call 0x4aff05
    cpu.esp -= 4;
    sub_4aff05(app, cpu);
    if (cpu.terminate) return;
    // 004a9be1  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a9be3  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a9be6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9be8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9be9  39c3                   +cmp ebx, eax
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
    // 004a9beb  7302                   -jae 0x4a9bef
    if (!cpu.flags.cf)
    {
        goto L_0x004a9bef;
    }
    // 004a9bed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a9bef:
    // 004a9bef  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9bf0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9bf1  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004a9bf3  a1acd94c00             -mov eax, dword ptr [0x4cd9ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */);
    // 004a9bf8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9bf9  2eff1520554b00         -call dword ptr cs:[0x4b5520]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936992) /* 0x4b5520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9c00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9c02  740e                   -je 0x4a9c12
    if (cpu.flags.zf)
    {
        goto L_0x004a9c12;
    }
    // 004a9c04  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9c06  7406                   -je 0x4a9c0e
    if (cpu.flags.zf)
    {
        goto L_0x004a9c0e;
    }
    // 004a9c08  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a9c0b  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004a9c0e:
    // 004a9c0e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9c10  eb05                   -jmp 0x4a9c17
    goto L_0x004a9c17;
L_0x004a9c12:
    // 004a9c12  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004a9c17:
    // 004a9c17  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a9c19  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9c1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9c1e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9c1f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a9c24  b804fb4b00             -mov eax, 0x4bfb04
    cpu.eax = 4979460 /*0x4bfb04*/;
    // 004a9c29  e803040000             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
    // 004a9c2e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9c30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9c31  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 004a9c37  743f                   -je 0x4a9c78
    if (cpu.flags.zf)
    {
        goto L_0x004a9c78;
    }
    // 004a9c39  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9c3b  01c0                   +add eax, eax
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
    // 004a9c3d  11d2                   +adc edx, edx
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
    // 004a9c3f  d1db                   -rcr ebx, 1
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
    // 004a9c41  0500000020             +add eax, 0x20000000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(536870912 /*0x20000000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9c46  83d200                 +adc edx, 0
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
    // 004a9c49  7424                   -je 0x4a9c6f
    if (cpu.flags.zf)
    {
        goto L_0x004a9c6f;
    }
    // 004a9c4b  81fa0000e08f           +cmp edx, 0x8fe00000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2413821952 /*0x8fe00000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9c51  731c                   -jae 0x4a9c6f
    if (!cpu.flags.cf)
    {
        goto L_0x004a9c6f;
    }
    // 004a9c53  81fa00002070           +cmp edx, 0x70200000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1881145344 /*0x70200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9c59  721d                   -jb 0x4a9c78
    if (cpu.flags.cf)
    {
        goto L_0x004a9c78;
    }
    // 004a9c5b  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 004a9c61  01c0                   +add eax, eax
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
    // 004a9c63  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a9c65  01c0                   +add eax, eax
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
    // 004a9c67  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004a9c69  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9c6b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9c6d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9c6f:
    // 004a9c6f  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 004a9c74  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9c76  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9c78:
    // 004a9c78  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c7a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9c7c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a9c7e  7507                   -jne 0x4a9c87
    if (!cpu.flags.zf)
    {
        goto L_0x004a9c87;
    }
    // 004a9c80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a9c82  7503                   -jne 0x4a9c87
    if (!cpu.flags.zf)
    {
        goto L_0x004a9c87;
    }
    // 004a9c84  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004a9c86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9c87:
    // 004a9c87  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9c88  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9c89  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004a9c8b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9c8d  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c8e  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004a9c90  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c92  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c93  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004a9c95  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9c97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9c98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9c98  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9c99  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9c9a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a9c9c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9c9d  2eff15b0544b00         -call dword ptr cs:[0x4b54b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936880) /* 0x4b54b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9ca4  83f8ff                 +cmp eax, -1
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
    // 004a9ca7  7508                   -jne 0x4a9cb1
    if (!cpu.flags.zf)
    {
        goto L_0x004a9cb1;
    }
    // 004a9ca9  e894befeff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 004a9cae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9caf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9cb1:
    // 004a9cb1  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004a9cb4  7411                   -je 0x4a9cc7
    if (cpu.flags.zf)
    {
        goto L_0x004a9cc7;
    }
    // 004a9cb6  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004a9cb8  740d                   -je 0x4a9cc7
    if (cpu.flags.zf)
    {
        goto L_0x004a9cc7;
    }
    // 004a9cba  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a9cbf  e82dbefeff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 004a9cc4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cc5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9cc7:
    // 004a9cc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9cc9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ccb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9ccc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9ccc  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9cd2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9cd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cd6  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9cdc  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9cdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9ce0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9ce1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9ce2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9ce3  2eff151c554b00         -call dword ptr cs:[0x4b551c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936988) /* 0x4b551c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9cea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9cec  7507                   -jne 0x4a9cf5
    if (!cpu.flags.zf)
    {
        goto L_0x004a9cf5;
    }
    // 004a9cee  e84fbefeff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 004a9cf3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cf4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9cf5:
    // 004a9cf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9cf7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9cf9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cf9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9cfa  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9cfb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9cfc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9cfd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9cfe  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9cff  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9d01  8b357c705400           -mov esi, dword ptr [0x54707c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004a9d07  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a9d09  743f                   -je 0x4a9d4a
    if (cpu.flags.zf)
    {
        goto L_0x004a9d4a;
    }
    // 004a9d0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9d0d  743b                   -je 0x4a9d4a
    if (cpu.flags.zf)
    {
        goto L_0x004a9d4a;
    }
    // 004a9d0f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9d11  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a9d12  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a9d14  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a9d16  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9d18  49                     -dec ecx
    (cpu.ecx)--;
    // 004a9d19  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9d1b  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 004a9d1d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a9d1f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9d20  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a9d21  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a9d23  eb1f                   -jmp 0x4a9d44
    goto L_0x004a9d44;
L_0x004a9d25:
    // 004a9d25  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a9d27  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a9d29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9d2b  e800620000             -call 0x4aff30
    cpu.esp -= 4;
    sub_4aff30(app, cpu);
    if (cpu.terminate) return;
    // 004a9d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9d32  750d                   -jne 0x4a9d41
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d41;
    }
    // 004a9d34  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9d38  7507                   -jne 0x4a9d41
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d41;
    }
    // 004a9d3a  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a9d3d  01c8                   +add eax, ecx
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
    // 004a9d3f  eb0b                   -jmp 0x4a9d4c
    goto L_0x004a9d4c;
L_0x004a9d41:
    // 004a9d41  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a9d44:
    // 004a9d44  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 004a9d46  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a9d48  75db                   -jne 0x4a9d25
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d25;
    }
L_0x004a9d4a:
    // 004a9d4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a9d4c:
    // 004a9d4c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d4d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d4e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d4f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d50  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d51  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9d53(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9d53  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9d54  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9d55  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9d56  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9d59  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9d5b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9d5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9d5f  7522                   -jne 0x4a9d83
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d83;
    }
    // 004a9d61  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004a9d66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9d68  e8e6bdfeff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004a9d6d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9d6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9d71  750e                   -jne 0x4a9d81
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d81;
    }
    // 004a9d73  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x004a9d78:
    // 004a9d78  e8c3befeff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
L_0x004a9d7d:
    // 004a9d7d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a9d7f  eb5c                   -jmp 0x4a9ddd
    goto L_0x004a9ddd;
L_0x004a9d81:
    // 004a9d81  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004a9d83:
    // 004a9d83  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a9d85  7405                   -je 0x4a9d8c
    if (cpu.flags.zf)
    {
        goto L_0x004a9d8c;
    }
    // 004a9d87  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9d8a  750b                   -jne 0x4a9d97
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d97;
    }
L_0x004a9d8c:
    // 004a9d8c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a9d8e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9d90  e8d00bfdff             -call 0x47a965
    cpu.esp -= 4;
    sub_47a965(app, cpu);
    if (cpu.terminate) return;
    // 004a9d95  eb46                   -jmp 0x4a9ddd
    goto L_0x004a9ddd;
L_0x004a9d97:
    // 004a9d97  ba28fb4b00             -mov edx, 0x4bfb28
    cpu.edx = 4979496 /*0x4bfb28*/;
    // 004a9d9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9d9e  e8800bfeff             -call 0x48a923
    cpu.esp -= 4;
    sub_48a923(app, cpu);
    if (cpu.terminate) return;
    // 004a9da3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9da5  751c                   -jne 0x4a9dc3
    if (!cpu.flags.zf)
    {
        goto L_0x004a9dc3;
    }
    // 004a9da7  83fb04                 +cmp ebx, 4
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
    // 004a9daa  730e                   -jae 0x4a9dba
    if (!cpu.flags.cf)
    {
        goto L_0x004a9dba;
    }
    // 004a9dac  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9dae  e8960effff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004a9db3  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004a9db8  ebbe                   -jmp 0x4a9d78
    goto L_0x004a9d78;
L_0x004a9dba:
    // 004a9dba  a128fb4b00             -mov eax, dword ptr [0x4bfb28]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(4979496) /* 0x4bfb28 */);
    // 004a9dbf  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a9dc1  eb18                   -jmp 0x4a9ddb
    goto L_0x004a9ddb;
L_0x004a9dc3:
    // 004a9dc3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9dc5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9dc6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9dc7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9dc8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9dc9  2eff15bc544b00         -call dword ptr cs:[0x4b54bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936892) /* 0x4b54bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9dd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9dd2  7507                   -jne 0x4a9ddb
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ddb;
    }
    // 004a9dd4  e869bdfeff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 004a9dd9  eba2                   -jmp 0x4a9d7d
    goto L_0x004a9d7d;
L_0x004a9ddb:
    // 004a9ddb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a9ddd:
    // 004a9ddd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9de0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9de4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9de4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9de5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9de6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9de7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9de8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9dea  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a9dec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9dee  7c08                   -jl 0x4a9df8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9df8;
    }
    // 004a9df0  3b0508d64c00           +cmp eax, dword ptr [0x4cd608]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9df6  7614                   -jbe 0x4a9e0c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9e0c;
    }
L_0x004a9df8:
    // 004a9df8  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a9dfd  e83ebefeff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 004a9e02  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9e07  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e08  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e09  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e0a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9e0c:
    // 004a9e0c  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9e12  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004a9e17  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a9e19  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a9e1c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9e1d  2eff1568544b00         -call dword ptr cs:[0x4b5468]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936808) /* 0x4b5468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9e24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9e26  750a                   -jne 0x4a9e32
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e32;
    }
    // 004a9e28  e815bdfeff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 004a9e2d  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x004a9e32:
    // 004a9e32  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9e34  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9e3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9e3c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e3d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e3e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e3f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9e41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9e41  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9e42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9e44  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9e45  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9e46  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9e47  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a9e4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9e4c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a9e4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9e50  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004a9e53  8945c0                 -mov dword ptr [ebp - 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004a9e56  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004a9e59  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9e5c  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 004a9e5e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a9e63  83f847                 +cmp eax, 0x47
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
    // 004a9e66  7523                   -jne 0x4a9e8b
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e8b;
    }
    // 004a9e68  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a9e6a  7505                   -jne 0x4a9e71
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e71;
    }
    // 004a9e6c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a9e71:
    // 004a9e71  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 004a9e78  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004a9e7b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a9e80  83ef02                 +sub edi, 2
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
    // 004a9e83  8945b8                 -mov dword ptr [ebp - 0x48], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004a9e86  897dc0                 -mov dword ptr [ebp - 0x40], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 004a9e89  eb1f                   -jmp 0x4a9eaa
    goto L_0x004a9eaa;
L_0x004a9e8b:
    // 004a9e8b  83f845                 +cmp eax, 0x45
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
    // 004a9e8e  750d                   -jne 0x4a9e9d
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e9d;
    }
    // 004a9e90  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a9e95  897dbc                 -mov dword ptr [ebp - 0x44], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004a9e98  897db8                 -mov dword ptr [ebp - 0x48], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 004a9e9b  eb0d                   -jmp 0x4a9eaa
    goto L_0x004a9eaa;
L_0x004a9e9d:
    // 004a9e9d  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004a9ea2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9ea4  897dbc                 -mov dword ptr [ebp - 0x44], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004a9ea7  8945b8                 -mov dword ptr [ebp - 0x48], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x004a9eaa:
    // 004a9eaa  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004a9eae  7404                   -je 0x4a9eb4
    if (cpu.flags.zf)
    {
        goto L_0x004a9eb4;
    }
    // 004a9eb0  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004a9eb4:
    // 004a9eb4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 004a9eb6  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9eb9  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a9ebb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9ebd  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004a9ec0  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004a9ec3  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a9ec6  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a9ec9  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004a9ecc  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a9ecf  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.eax)));
    // 004a9ed1  db3a                   -fstp xword ptr [edx]
    *app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a9ed3  83fbff                 +cmp ebx, -1
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
    // 004a9ed6  7505                   -jne 0x4a9edd
    if (!cpu.flags.zf)
    {
        goto L_0x004a9edd;
    }
    // 004a9ed8  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004a9edd:
    // 004a9edd  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a9ee0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9ee2  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 004a9ee5  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 004a9ee8  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a9eeb  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004a9eee  e8e7610000             -call 0x4b00da
    cpu.esp -= 4;
    sub_4b00da(app, cpu);
    if (cpu.terminate) return;
    // 004a9ef3  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a9ef6  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a9ef9  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004a9efc  89412c                 -mov dword ptr [ecx + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a9eff  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a9f02  894130                 -mov dword ptr [ecx + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004a9f05  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004a9f08  894134                 -mov dword ptr [ecx + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004a9f0b  837dc800               +cmp dword ptr [ebp - 0x38], 0
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
    // 004a9f0f  7d0f                   -jge 0x4a9f20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9f20;
    }
    // 004a9f11  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a9f14  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a9f17  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a9f1a  c604062d               -mov byte ptr [esi + eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004a9f1e  eb29                   -jmp 0x4a9f49
    goto L_0x004a9f49;
L_0x004a9f20:
    // 004a9f20  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004a9f23  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004a9f26  740f                   -je 0x4a9f37
    if (cpu.flags.zf)
    {
        goto L_0x004a9f37;
    }
    // 004a9f28  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a9f2b  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a9f2e  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a9f31  c604062b               -mov byte ptr [esi + eax], 0x2b
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004a9f35  eb12                   -jmp 0x4a9f49
    goto L_0x004a9f49;
L_0x004a9f37:
    // 004a9f37  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004a9f3a  740d                   -je 0x4a9f49
    if (cpu.flags.zf)
    {
        goto L_0x004a9f49;
    }
    // 004a9f3c  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a9f3f  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a9f42  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a9f45  c6040620               -mov byte ptr [esi + eax], 0x20
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004a9f49:
    // 004a9f49  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a9f4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9f4d  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004a9f50  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f51  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f52  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f53  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9f55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f55  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9f56  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a9f58  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9f5a  e8c56c0000             -call 0x4b0c24
    cpu.esp -= 4;
    sub_4b0c24(app, cpu);
    if (cpu.terminate) return;
    // 004a9f5f  dd1b                   -fstp qword ptr [ebx]
    *app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a9f61  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a9f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f70  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9f71  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9f72  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a9f75  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a9f78  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a9f7a  e8316d0000             -call 0x4b0cb0
    cpu.esp -= 4;
    sub_4b0cb0(app, cpu);
    if (cpu.terminate) return;
    // 004a9f7f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a9f81  e82a6d0000             -call 0x4b0cb0
    cpu.esp -= 4;
    sub_4b0cb0(app, cpu);
    if (cpu.terminate) return;
    // 004a9f86  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f87  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9f88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9f89(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f89  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9f8a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9f8b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9f8c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9f8e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 004a9f90  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a9f93  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9f96  730c                   -jae 0x4a9fa4
    if (!cpu.flags.cf)
    {
        goto L_0x004a9fa4;
    }
    // 004a9f98  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004a9f9a  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a9f9d  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004a9f9f  880b                   -mov byte ptr [ebx], cl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004a9fa1  ff4010                 -inc dword ptr [eax + 0x10]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
L_0x004a9fa4:
    // 004a9fa4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9fa5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9fa6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9fa7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9fa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9fa8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9fa9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9fac  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9fae  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9fb0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a9fb2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a9fb4  48                     -dec eax
    (cpu.eax)--;
    // 004a9fb5  b9899f4a00             -mov ecx, 0x4a9f89
    cpu.ecx = 4890505 /*0x4a9f89*/;
    // 004a9fba  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9fbe  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a9fc0  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a9fc3  e88f9fffff             -call 0x4a3f57
    cpu.esp -= 4;
    sub_4a3f57(app, cpu);
    if (cpu.terminate) return;
    // 004a9fc8  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004a9fcc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9fcf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9fd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9fd1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9fd1  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9fd2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9fd3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9fd4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9fd7  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9fdb  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004a9fdd  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9fe1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9fe5  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a9fe8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9fec  e8b7ffffff             -call 0x4a9fa8
    cpu.esp -= 4;
    sub_4a9fa8(app, cpu);
    if (cpu.terminate) return;
    // 004a9ff1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9ff4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ff5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ff6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ff7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9ff8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9ff9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9ffa  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9ffb  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9ffc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9fff  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aa001  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa003  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004aa005  eb01                   -jmp 0x4aa008
    goto L_0x004aa008;
L_0x004aa007:
    // 004aa007  43                     -inc ebx
    (cpu.ebx)++;
L_0x004aa008:
    // 004aa008  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa00a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 004aa00c  40                     -inc eax
    (cpu.eax)++;
    // 004aa00d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004aa00f  75f6                   -jne 0x4aa007
    if (!cpu.flags.zf)
    {
        goto L_0x004aa007;
    }
    // 004aa011  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004aa013  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa017  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aa018  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa019  a1f8d54c00             -mov eax, dword ptr [0x4cd5f8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5035512) /* 0x4cd5f8 */);
    // 004aa01e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa01f  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa022  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa023  2eff15b0554b00         -call dword ptr cs:[0x4b55b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937136) /* 0x4b55b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aa02a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa02c  e99df6feff             -jmp 0x4996ce
    return sub_4996ce(app, cpu);
}

/* align: skip  */
void Application::sub_4aa031(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa031  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa032  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa033  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa035  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aa037  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004aa039  e81945ffff             -call 0x49e557
    cpu.esp -= 4;
    sub_49e557(app, cpu);
    if (cpu.terminate) return;
    // 004aa03e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aa040  7509                   -jne 0x4aa04b
    if (!cpu.flags.zf)
    {
        goto L_0x004aa04b;
    }
    // 004aa042  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aa044  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa046  e8adffffff             -call 0x4a9ff8
    cpu.esp -= 4;
    sub_4a9ff8(app, cpu);
    if (cpu.terminate) return;
L_0x004aa04b:
    // 004aa04b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa04c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa04d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa04e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa04e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa04f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa050  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004aa052  8b15e4ab4c00           -mov edx, dword ptr [0x4cabe4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5024740) /* 0x4cabe4 */);
    // 004aa058  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa05b  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004aa05e  e81a45ffff             -call 0x49e57d
    cpu.esp -= 4;
    sub_49e57d(app, cpu);
    if (cpu.terminate) return;
    // 004aa063  39c2                   +cmp edx, eax
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
    // 004aa065  7316                   -jae 0x4aa07d
    if (!cpu.flags.cf)
    {
        goto L_0x004aa07d;
    }
    // 004aa067  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa068  e85f45ffff             -call 0x49e5cc
    cpu.esp -= 4;
    sub_49e5cc(app, cpu);
    if (cpu.terminate) return;
    // 004aa06d  a1e4ab4c00             -mov eax, dword ptr [0x4cabe4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5024740) /* 0x4cabe4 */);
    // 004aa072  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa075  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004aa077  29c4                   +sub esp, eax
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
    // 004aa079  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004aa07b  eb02                   -jmp 0x4aa07f
    goto L_0x004aa07f;
L_0x004aa07d:
    // 004aa07d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004aa07f:
    // 004aa07f  8b15e4ab4c00           -mov edx, dword ptr [0x4cabe4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5024740) /* 0x4cabe4 */);
    // 004aa085  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa087  a3e8ab4c00             -mov dword ptr [0x4cabe8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5024744) /* 0x4cabe8 */) = cpu.eax;
    // 004aa08c  e8c76c0000             -call 0x4b0d58
    cpu.esp -= 4;
    sub_4b0d58(app, cpu);
    if (cpu.terminate) return;
    // 004aa091  8b1598715400           -mov edx, dword ptr [0x547198]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5534104) /* 0x547198 */);
    // 004aa097  a194715400             -mov eax, dword ptr [0x547194]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5534100) /* 0x547194 */);
    // 004aa09c  e82f50faff             -call 0x44f0d0
    cpu.esp -= 4;
    sub_44f0d0(app, cpu);
    if (cpu.terminate) return;
    // 004aa0a1  e83f13feff             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 004aa0a6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004aa0a8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0a9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4aa0ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa0ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa0af  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa0b2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa0b8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa0ba  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa0bd  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa0c0  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa0c6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa0c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa0c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa0cb  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa0cd  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa0d3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa0d6  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa0db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa0dd  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa0e0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa0e3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa0e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa0eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa0ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa0ee  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa0f0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa0f6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa0f9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa0fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa100  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa103  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa105  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa108  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa10e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa111  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa117  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa119  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa11b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa11c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa11c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa11e  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa123  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa126  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa128  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa12e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa130  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa131(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa131  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa133  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa136  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa13c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa13f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa144  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa146  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa149  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa14b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa14d  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa153  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa156  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa15c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa15e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa160  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa161(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa161  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa164  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa169  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa16c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa16e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa170  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa176  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aa179  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa17f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa181  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa183  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa184(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa184  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa187  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa18c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa18f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa191  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa194  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa19a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa19c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa19e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa19f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa19f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa1a1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa1a4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa1aa  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa1ac  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa1af  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa1b2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa1b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa1ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa1bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa1bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa1bd  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa1bf  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa1c5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa1c8  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa1cd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa1cf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa1d2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa1d5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa1db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa1dd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa1e0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa1e3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa1e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa1eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa1ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa1ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa1ee  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa1f0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa1f6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa1f9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa1fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa200  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa203  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa206  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa20c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa20e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa211  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa214  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa21a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa21c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa21d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa21d  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa21f  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa224  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa227  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa229  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa22c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa232  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa235  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa23b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa23d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa23f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa242  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa245  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa24b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa24d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa24e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa24e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa250  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa253  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa259  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa25c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa261  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa263  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa266  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa268  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa26e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa270  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa274  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa277  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa27d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa27f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa280  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa283  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa288  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa28b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa28d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa28f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa295  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa298  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa29e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa2a0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2a2  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa2a6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa2a9  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa2af  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa2b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa2b2  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa2b5  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa2ba  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa2bd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa2bf  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa2c1  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa2c7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aa2ca  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa2d0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa2d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2d4  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa2d8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa2db  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa2e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa2e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa2e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa2e6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa2e8  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa2ee  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa2f1  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa2f6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa2f8  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa2fb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa2fe  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa304  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa306  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa307(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa307  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa309  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa30b  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa311  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa314  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa319  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa31b  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa31e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa321  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa327  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa329  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa32c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa32f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa335  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa337  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa338(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa338  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa33a  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa33f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa342  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa345  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa34b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa34d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa350  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa353  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa359  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa35b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa35c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa35c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa35e  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa363  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa366  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa369  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa36f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa371  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa374  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa377  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa37d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa37f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa383  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa386  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa38c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa38e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa38f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa38f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa391  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa394  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa39a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa39d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa3a2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa3a4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa3a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa3a9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa3ac  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa3b2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa3b5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa3bb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa3bd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa3bf  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa3c2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa3c5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa3cb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa3cd  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa3d1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa3d4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa3da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa3dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa3dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa3dd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa3e0  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa3e5  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa3e8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa3ea  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa3f0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa3f2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa3f5  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa3f8  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa3fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa400  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa404  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa407  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa40d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa40f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa410  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa413  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa418  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa41b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa41d  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa423  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa425  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa429  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa42c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa432  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa435(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa435  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa438  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa43d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa440  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa442  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa444  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa44a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa44d  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa453  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa455  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa457  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa45b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa45e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa464  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa466  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa467(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa467  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa469  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa46b  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa471  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa474  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa479  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa47b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa47e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa480  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa483  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa489  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa48c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa492  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa494  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa496  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa497(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa497  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa499  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa49e  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa4a1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa4a4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa4aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4ac  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa4af  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa4b1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa4b4  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa4ba  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa4bd  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa4c3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa4c5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa4c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa4c8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa4ca  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa4cf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa4d2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa4d5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa4db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4dd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa4e0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa4e3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa4e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4eb  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa4ef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa4f2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa4f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa4fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa4fb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa4fd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa500  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa506  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa509  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa50e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa510  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa513  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa516  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa51c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa51e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa521  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa524  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa52a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa52c  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa530  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa533  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa539  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa53b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa53c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa53c  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa53f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa544  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa547  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa54a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa550  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa552  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa555  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa558  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa55e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa560  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa564  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa567  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa56d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa56f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa570  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa573  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa578  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa57b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa57d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa580  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa586  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa589  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa58f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa591  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa593  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa596  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa599  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa59f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5a1  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa5a5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa5a8  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa5ae  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa5b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa5b1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa5b4  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa5b9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa5bc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa5be  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa5c4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5c6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa5c9  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa5cc  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa5d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5d4  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa5d8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa5db  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa5e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa5e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa5e4  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa5e7  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa5ec  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa5ef  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa5f1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa5f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa5f9  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa5fd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa5ff  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa602  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa608  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa60b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa611  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa613  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa616(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa616  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aa618  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa61d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa620  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa622  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa628  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa62a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa62b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa62b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa62d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa630  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa636  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa639  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa63e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa640  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa643  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa646  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa64c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa64e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa651  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa653  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa656  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa65c  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa65f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa665  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa667  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa669  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa66d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa670  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa676  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa678  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa679(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa679  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa67c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa681  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa684  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa686  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa689  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa68f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa692  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa698  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa69a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa69c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa69f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa6a2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa6a8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa6aa  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa6ae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa6b0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa6b3  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa6b9  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa6bc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa6c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa6c4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa6c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa6c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa6c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa6c9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa6cc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa6ce  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa6d4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa6d6  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa6da  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa6dc  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa6e2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa6e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa6e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa6e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa6e7  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa6ea  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa6f0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa6f3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa6f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa6fa  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa6fd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa6ff  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa701  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa707  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa70a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa710  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa712  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa714  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa715(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa715  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa717  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa71a  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa720  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa723  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa728  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa72a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa72d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa72f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa735  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa737  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa73b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa73e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa744  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa746  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa747(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa747  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa74a  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa74f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa752  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa755  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa75b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa75d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa760  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa762  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa768  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa76a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa76e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa771  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa777  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa779  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa77a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa77a  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa77d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa782  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa785  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa788  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa78e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa790  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa793  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa795  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa798  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa79e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa7a1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa7a7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa7a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa7ab  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa7af  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa7b2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa7b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa7ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa7bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa7bb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa7be  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa7c3  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa7c6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa7c9  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa7cf  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa7d1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa7d4  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa7d7  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa7dd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa7df  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa7e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa7e5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa7e8  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa7ee  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa7f1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa7f7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa7f9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa7fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa7fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa7fc  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa7ff  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa804  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa807  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa80a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa810  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa812  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa815  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa818  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa81e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa820  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa824  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa826  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa82c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa82e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa82f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa82f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa831  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa834  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa836  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa839  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa83f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa842  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa848  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa84a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa84c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa84f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa852  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa858  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa85a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa85e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa860  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa866  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa868  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa869(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa869  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa86c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa871  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa874  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa876  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa878  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aa87e  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aa881  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa887  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa889  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa88b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa88c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa88c  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa88f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa894  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa897  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa899  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa89b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa8a1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa8a4  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa8aa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa8ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa8ae  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa8b2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa8b5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa8bb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa8bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa8be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa8be  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aa8c1  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa8c6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa8c9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa8cb  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa8d1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa8d3  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa8d7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa8da  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa8e0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa8e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa8e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa8e3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa8e6  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa8eb  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa8ee  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa8f1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa8f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa8f9  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa8fc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa8fe  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa904  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa906  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa90a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa90d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa913  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa915  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa916(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa916  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa919  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa91e  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa921  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa924  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa92a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa92c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa92f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa931  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa934  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa93a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa93d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa943  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa945  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa947  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa94b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa94d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa950  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa956  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa959  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa95f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa961  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa963  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa964(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa964  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aa967  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa96c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa96f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa972  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa978  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa97a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa97d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa980  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa986  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa988  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa98c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa98e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa994  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa996  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa997(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa997  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa999  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa99c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa99f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa9a5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9a7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa9aa  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa9ad  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa9b3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9b5  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa9b9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa9bb  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa9c1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa9c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa9c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa9c6  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aa9c9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aa9cc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aa9d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9d4  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aa9d7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aa9da  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aa9e0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9e2  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aa9e6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aa9e8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aa9ea  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aa9f0  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aa9f3  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aa9f9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa9fb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa9fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa9fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa9fe  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aaa01  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa06  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaa09  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaa0b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaa0e  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa14  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aaa16  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaa19(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa19  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aaa1c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa21  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaa24  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaa26  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaa28  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aaa2e  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aaa31  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaa37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaa39  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa3b  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aaa3f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaa42  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa48  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaa4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa4b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aaa4e  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa53  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaa56  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaa58  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaa5a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aaa60  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaa63  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaa69  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaa6b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa6d  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aaa71  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaa74  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaa7a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaa7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa7d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aaa80  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaa85  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaa88  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaa8a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaa90  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa92  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aaa96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaa98  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaa9b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aaaa1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaaa4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaaaa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaaae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaaaf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaaaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaab1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaab4  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaab6  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaabc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaabe  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aaac2  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaac4  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aaaca  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaacc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaacd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaacd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaacf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aaad2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aaad5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaadb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaadd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aaae0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaae2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aaae5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aaaeb  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaaee  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aaaf4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaf6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaaf8  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aaafc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aaafe  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aab04  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aab07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aab07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aab09  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aab0c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aab0f  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aab15  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab17  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aab1a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aab1d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aab23  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab25  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aab29  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aab2b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aab2d  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aab33  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aab36  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aab3c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aab3e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aab41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aab41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aab43  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004aab46  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aab49  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aab4f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab51  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aab54  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aab57  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aab5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab5f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004aab63  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aab65  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aab67  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aab6d  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aab70  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aab76  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aab78  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4aab7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aab7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aab7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aab7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aab7f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aab82  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aab88  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab8a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aab8d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aab93  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aab96  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aab99  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aab9f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaba1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aaba2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaba2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaba4  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aaba6  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aabac  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aabaf  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aabb4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aabb6  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aabb9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aabbf  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aabc2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aabc5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aabcb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aabcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aabce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aabce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aabd0  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aabd2  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aabd8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aabdb  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aabe0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aabe2  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aabe5  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aabeb  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aabee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aabf0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aabf3  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aabf9  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aabfc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aac02  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aac04  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aac07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac07  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aac09  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aac0e  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aac11  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aac17  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aac1a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aac1c  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aac22  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aac25(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac25  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aac27  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aac2a  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aac30  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aac33  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aac38  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac3a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aac3d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aac43  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aac46  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aac48  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aac4a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004aac50  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aac53  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aac59  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aac5b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aac5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac5e  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004aac61  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004aac66  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aac69  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aac6f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aac72  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aac74  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004aac76  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aac7c  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004aac7f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aac85  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aac87  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aac8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aac8a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aac8d  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aac92  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aac95  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aac9b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aac9e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aaca0  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004aaca3  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aaca9  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aacab  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aacad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aacae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aacae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aacb0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aacb3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aacb9  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aacbb  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aacbe  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aacc4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aacc7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aacca  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aacd0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aacd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aacd3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aacd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aacd5  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004aacd7  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004aacdd  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004aace0  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004aace5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aace7  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004aacea  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aacf0  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aacf3  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aacf6  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aacfc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aacfe  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004aad01  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aad07  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004aad0a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004aad0d  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004aad13  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad15  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
