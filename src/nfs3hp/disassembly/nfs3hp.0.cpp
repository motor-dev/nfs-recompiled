#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_401000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00401000:
    // 00401000  cc                     -int3 
    NFS2_ASSERT(false);
    // 00401001  ebfd                   -jmp 0x401000
    goto L_0x00401000;
}

/* align: skip 0x90 */
/* data blob: 909090000000000000000000 */
void Application::sub_401010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401010  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401011  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401012  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401013  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401014  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401015  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401016  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401018  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 0040101e  83ed7a                 -sub ebp, 0x7a
    (cpu.ebp) -= x86::reg32(x86::sreg32(122 /*0x7a*/));
    // 00401021  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00401023  8b0da8215500           -mov ecx, dword ptr [0x5521a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5579176) /* 0x5521a8 */);
    // 00401029  895576                 -mov dword ptr [ebp + 0x76], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edx;
    // 0040102c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040102e  0f85da010000           -jne 0x40120e
    if (!cpu.flags.zf)
    {
        goto L_0x0040120e;
    }
    // 00401034  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00401039  8bb596000000           -mov esi, dword ptr [ebp + 0x96]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(150) /* 0x96 */);
    // 0040103f  891da8215500           -mov dword ptr [0x5521a8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579176) /* 0x5521a8 */) = cpu.ebx;
    // 00401045  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401047  741f                   -je 0x401068
    if (cpu.flags.zf)
    {
        goto L_0x00401068;
    }
    // 00401049  8d859a000000           -lea eax, [ebp + 0x9a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(154) /* 0x9a */);
    // 0040104f  8d5d72                 -lea ebx, [ebp + 0x72]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00401052  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00401054  894572                 -mov dword ptr [ebp + 0x72], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.eax;
    // 00401057  b810e05600             -mov eax, 0x56e010
    cpu.eax = 5693456 /*0x56e010*/;
    // 0040105c  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0040105e  e811e60d00             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 00401063  897d72                 -mov dword ptr [ebp + 0x72], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.edi;
    // 00401066  eb08                   -jmp 0x401070
    goto L_0x00401070;
L_0x00401068:
    // 00401068  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0040106a  882510e05600           -mov byte ptr [0x56e010], ah
    *app->getMemory<x86::reg8>(x86::reg32(5693456) /* 0x56e010 */) = cpu.ah;
L_0x00401070:
    // 00401070  833dfc43560000         +cmp dword ptr [0x5643fc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653500) /* 0x5643fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401077  741c                   -je 0x401095
    if (cpu.flags.zf)
    {
        goto L_0x00401095;
    }
    // 00401079  6810e05600             -push 0x56e010
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5693456 /*0x56e010*/;
    cpu.esp -= 4;
    // 0040107e  2eff159c455300         -call dword ptr cs:[0x53459c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457308) /* 0x53459c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00401085  833dc0e8550000         +cmp dword ptr [0x55e8c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5630144) /* 0x55e8c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040108c  7407                   -je 0x401095
    if (cpu.flags.zf)
    {
        goto L_0x00401095;
    }
    // 0040108e  2eff15a8445300         -call dword ptr cs:[0x5344a8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457064) /* 0x5344a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00401095:
    // 00401095  833d1444560000         +cmp dword ptr [0x564414], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653524) /* 0x564414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040109c  7419                   -je 0x4010b7
    if (cpu.flags.zf)
    {
        goto L_0x004010b7;
    }
    // 0040109e  b810e05600             -mov eax, 0x56e010
    cpu.eax = 5693456 /*0x56e010*/;
    // 004010a3  ff1514445600           -call dword ptr [0x564414]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653524) /* 0x564414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004010a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004010ab  750a                   -jne 0x4010b7
    if (!cpu.flags.zf)
    {
        goto L_0x004010b7;
    }
    // 004010ad  a3a8215500             -mov dword ptr [0x5521a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5579176) /* 0x5521a8 */) = cpu.eax;
    // 004010b2  e957010000             -jmp 0x40120e
    goto L_0x0040120e;
L_0x004010b7:
    // 004010b7  833d0844560000         +cmp dword ptr [0x564408], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653512) /* 0x564408 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004010be  0f84a7000000           -je 0x40116b
    if (cpu.flags.zf)
    {
        goto L_0x0040116b;
    }
    // 004010c4  8b3d90215500           -mov edi, dword ptr [0x552190]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */);
    // 004010ca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004010cc  7449                   -je 0x401117
    if (cpu.flags.zf)
    {
        goto L_0x00401117;
    }
    // 004010ce  a194215500             -mov eax, dword ptr [0x552194]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */);
    // 004010d3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004010d4  8b1598215500           -mov edx, dword ptr [0x552198]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */);
    // 004010da  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004010db  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004010dc  6804605300             -push 0x536004
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5464068 /*0x536004*/;
    cpu.esp -= 4;
    // 004010e1  8d45f2                 -lea eax, [ebp - 0xe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 004010e4  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004010e5  e8a6e50d00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004010ea  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004010ed  8d75f2                 -lea esi, [ebp - 0xe]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 004010f0  bf10e05600             -mov edi, 0x56e010
    cpu.edi = 5693456 /*0x56e010*/;
    // 004010f5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004010f6  2bc9                   +sub ecx, ecx
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
    // 004010f8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004010f9  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004010fb  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004010fd  4f                     -dec edi
    (cpu.edi)--;
L_0x004010fe:
    // 004010fe  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00401100  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00401102  3c00                   +cmp al, 0
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
    // 00401104  7410                   -je 0x401116
    if (cpu.flags.zf)
    {
        goto L_0x00401116;
    }
    // 00401106  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00401109  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0040110c  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0040110f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00401112  3c00                   +cmp al, 0
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
    // 00401114  75e8                   -jne 0x4010fe
    if (!cpu.flags.zf)
    {
        goto L_0x004010fe;
    }
L_0x00401116:
    // 00401116  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00401117:
    // 00401117  8b1d9c215500           -mov ebx, dword ptr [0x55219c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5579164) /* 0x55219c */);
    // 0040111d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040111f  744a                   -je 0x40116b
    if (cpu.flags.zf)
    {
        goto L_0x0040116b;
    }
    // 00401121  8b35a0215500           -mov esi, dword ptr [0x5521a0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5579168) /* 0x5521a0 */);
    // 00401127  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401128  8b3da4215500           -mov edi, dword ptr [0x5521a4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5579172) /* 0x5521a4 */);
    // 0040112e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040112f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401130  6814605300             -push 0x536014
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5464084 /*0x536014*/;
    cpu.esp -= 4;
    // 00401135  8d45f2                 -lea eax, [ebp - 0xe]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00401138  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401139  e852e50d00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0040113e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00401141  8d75f2                 -lea esi, [ebp - 0xe]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-14) /* -0xe */);
    // 00401144  bf10e05600             -mov edi, 0x56e010
    cpu.edi = 5693456 /*0x56e010*/;
    // 00401149  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040114a  2bc9                   +sub ecx, ecx
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
    // 0040114c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0040114d  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0040114f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00401151  4f                     -dec edi
    (cpu.edi)--;
L_0x00401152:
    // 00401152  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00401154  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00401156  3c00                   +cmp al, 0
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
    // 00401158  7410                   -je 0x40116a
    if (cpu.flags.zf)
    {
        goto L_0x0040116a;
    }
    // 0040115a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0040115d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00401160  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00401163  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00401166  3c00                   +cmp al, 0
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
    // 00401168  75e8                   -jne 0x401152
    if (!cpu.flags.zf)
    {
        goto L_0x00401152;
    }
L_0x0040116a:
    // 0040116a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0040116b:
    // 0040116b  833d1844560000         +cmp dword ptr [0x564418], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401172  7409                   -je 0x40117d
    if (cpu.flags.zf)
    {
        goto L_0x0040117d;
    }
    // 00401174  ff1518445600           -call dword ptr [0x564418]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0040117a  894576                 -mov dword ptr [ebp + 0x76], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.eax;
L_0x0040117d:
    // 0040117d  833d1c44560000         +cmp dword ptr [0x56441c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653532) /* 0x56441c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401184  7406                   -je 0x40118c
    if (cpu.flags.zf)
    {
        goto L_0x0040118c;
    }
    // 00401186  ff151c445600           -call dword ptr [0x56441c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653532) /* 0x56441c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0040118c:
    // 0040118c  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040118e  2eff1594475300         -call dword ptr cs:[0x534794]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457812) /* 0x534794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00401195  6831100100             -push 0x11031
    *app->getMemory<x86::reg32>(cpu.esp-4) = 69681 /*0x11031*/;
    cpu.esp -= 4;
    // 0040119a  6830605300             -push 0x536030
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5464112 /*0x536030*/;
    cpu.esp -= 4;
    // 0040119f  6810e05600             -push 0x56e010
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5693456 /*0x56e010*/;
    cpu.esp -= 4;
    // 004011a4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004011a6  2eff1564475300         -call dword ptr cs:[0x534764]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457764) /* 0x534764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004011ad  83f801                 +cmp eax, 1
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
    // 004011b0  752a                   -jne 0x4011dc
    if (!cpu.flags.zf)
    {
        goto L_0x004011dc;
    }
    // 004011b2  833d0044560000         +cmp dword ptr [0x564400], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653504) /* 0x564400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004011b9  7421                   -je 0x4011dc
    if (cpu.flags.zf)
    {
        goto L_0x004011dc;
    }
    // 004011bb  833d0444560000         +cmp dword ptr [0x564404], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5653508) /* 0x564404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004011c2  7418                   -je 0x4011dc
    if (cpu.flags.zf)
    {
        goto L_0x004011dc;
    }
    // 004011c4  6810e05600             -push 0x56e010
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5693456 /*0x56e010*/;
    cpu.esp -= 4;
    // 004011c9  6840605300             -push 0x536040
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5464128 /*0x536040*/;
    cpu.esp -= 4;
    // 004011ce  e8ede40d00             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 004011d3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004011d6  ff1504445600           -call dword ptr [0x564404]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5653508) /* 0x564404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004011dc:
    // 004011dc  8b7d76                 -mov edi, dword ptr [ebp + 0x76]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004011df  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004011e1  7407                   -je 0x4011ea
    if (cpu.flags.zf)
    {
        goto L_0x004011ea;
    }
    // 004011e3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004011e4  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004011ea:
    // 004011ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004011ec  e83fe70d00             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004011f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004011f3  7411                   -je 0x401206
    if (cpu.flags.zf)
    {
        goto L_0x00401206;
    }
    // 004011f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004011f7  e808eb0d00             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 004011fc  8d657a                 -lea esp, [ebp + 0x7a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004011ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401200  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401201  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401202  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401203  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401204  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401205  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401206:
    // 00401206  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401207  2eff15c0445300         -call dword ptr cs:[0x5344c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457088) /* 0x5344c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0040120e:
    // 0040120e  8d657a                 -lea esp, [ebp + 0x7a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401211  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401212  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401213  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401214  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401215  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401216  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401217  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_401220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401220  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401221  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401223  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401224  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_401230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401230  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401231  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401233  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401234  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_401240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401240  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401241  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401242  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401244  8b902c060000           -mov edx, dword ptr [eax + 0x62c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1580) /* 0x62c */);
    // 0040124a  83fa01                 +cmp edx, 1
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
    // 0040124d  7209                   -jb 0x401258
    if (cpu.flags.cf)
    {
        goto L_0x00401258;
    }
    // 0040124f  7613                   -jbe 0x401264
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00401264;
    }
    // 00401251  83fa02                 +cmp edx, 2
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
    // 00401254  743b                   -je 0x401291
    if (cpu.flags.zf)
    {
        goto L_0x00401291;
    }
    // 00401256  eb02                   -jmp 0x40125a
    goto L_0x0040125a;
L_0x00401258:
    // 00401258  85d2                   -test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
L_0x0040125a:
    // 0040125a  c7802c06000001000000   -mov dword ptr [eax + 0x62c], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1580) /* 0x62c */) = 1 /*0x1*/;
L_0x00401264:
    // 00401264  f6802006000001         +test byte ptr [eax + 0x620], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) & 1 /*0x1*/));
    // 0040126b  740f                   -je 0x40127c
    if (cpu.flags.zf)
    {
        goto L_0x0040127c;
    }
    // 0040126d  c7802c06000002000000   -mov dword ptr [eax + 0x62c], 2
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1580) /* 0x62c */) = 2 /*0x2*/;
    // 00401277  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401279  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040127a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040127b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040127c:
    // 0040127c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0040127e  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00401283  e818cf0b00             -call 0x4be1a0
    cpu.esp -= 4;
    sub_4be1a0(app, cpu);
    if (cpu.terminate) return;
    // 00401288  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040128a  741d                   -je 0x4012a9
    if (cpu.flags.zf)
    {
        goto L_0x004012a9;
    }
    // 0040128c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040128e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040128f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401290  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401291:
    // 00401291  f6802006000001         +test byte ptr [eax + 0x620], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) & 1 /*0x1*/));
    // 00401298  7405                   -je 0x40129f
    if (cpu.flags.zf)
    {
        goto L_0x0040129f;
    }
    // 0040129a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040129c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040129d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040129e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040129f:
    // 0040129f  c7802c06000001000000   -mov dword ptr [eax + 0x62c], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1580) /* 0x62c */) = 1 /*0x1*/;
L_0x004012a9:
    // 004012a9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004012ae  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012af  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004012b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4012c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004012c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004012c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004012c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004012c3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004012c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004012c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004012c8:
    // 004012c8  3b0588fd5e00           +cmp eax, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004012ce  7d3a                   -jge 0x40130a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040130a;
    }
    // 004012d0  8b148588fa5e00         -mov edx, dword ptr [eax*4 + 0x5efa88]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.eax * 4);
    // 004012d7  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004012de  bb10ea5600             -mov ebx, 0x56ea10
    cpu.ebx = 5696016 /*0x56ea10*/;
    // 004012e3  898214070000           -mov dword ptr [edx + 0x714], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1812) /* 0x714 */) = cpu.eax;
    // 004012e9  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004012eb  8b8a20020000           -mov ecx, dword ptr [edx + 0x220]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(544) /* 0x220 */);
    // 004012f1  899aac070000           -mov dword ptr [edx + 0x7ac], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1964) /* 0x7ac */) = cpu.ebx;
    // 004012f7  817914f8010000         +cmp dword ptr [ecx + 0x14], 0x1f8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(504 /*0x1f8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004012fe  7507                   -jne 0x401307
    if (!cpu.flags.zf)
    {
        goto L_0x00401307;
    }
    // 00401300  808a1107000001         +or byte ptr [edx + 0x711], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x00401307:
    // 00401307  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401308  ebbe                   -jmp 0x4012c8
    goto L_0x004012c8;
L_0x0040130a:
    // 0040130a  c70550ea5600dfcf3241   -mov dword ptr [0x56ea50], 0x4132cfdf
    *app->getMemory<x86::reg32>(x86::reg32(5696080) /* 0x56ea50 */) = 1093849055 /*0x4132cfdf*/;
    // 00401314  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401315  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401316  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401317  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401318  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_401320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401320  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401321  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401323  c70554ea560001000000   -mov dword ptr [0x56ea54], 1
    *app->getMemory<x86::reg32>(x86::reg32(5696084) /* 0x56ea54 */) = 1 /*0x1*/;
    // 0040132d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040132e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_401330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401330  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401331  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401332  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401333  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401335  8b901c070000           -mov edx, dword ptr [eax + 0x71c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */);
    // 0040133b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040133d  7e09                   -jle 0x401348
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401348;
    }
    // 0040133f  8d4aff                 -lea ecx, [edx - 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00401342  89881c070000           -mov dword ptr [eax + 0x71c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */) = cpu.ecx;
L_0x00401348:
    // 00401348  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401349  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040134a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040134b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_401350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401350  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401351  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401352  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401353  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401355  8b901c070000           -mov edx, dword ptr [eax + 0x71c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */);
    // 0040135b  83fa08                 +cmp edx, 8
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
    // 0040135e  7309                   -jae 0x401369
    if (!cpu.flags.cf)
    {
        goto L_0x00401369;
    }
    // 00401360  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00401363  89881c070000           -mov dword ptr [eax + 0x71c], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */) = cpu.ecx;
L_0x00401369:
    // 00401369  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040136a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040136b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040136c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_401370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401370  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401371  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401373  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401376  f6801107000001         +test byte ptr [eax + 0x711], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1809) /* 0x711 */) & 1 /*0x1*/));
    // 0040137d  7417                   -je 0x401396
    if (cpu.flags.zf)
    {
        goto L_0x00401396;
    }
    // 0040137f  8b8028050000           -mov eax, dword ptr [eax + 0x528]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */);
    // 00401385  d980c8010000           +fld dword ptr [eax + 0x1c8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(456) /* 0x1c8 */)));
    // 0040138b  dc0d44605300           +fmul qword ptr [0x536044]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464132) /* 0x536044 */));
    // 00401391  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401394  eb0f                   -jmp 0x4013a5
    goto L_0x004013a5;
L_0x00401396:
    // 00401396  8b8028050000           -mov eax, dword ptr [eax + 0x528]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */);
    // 0040139c  8b80c8010000           -mov eax, dword ptr [eax + 0x1c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(456) /* 0x1c8 */);
    // 004013a2  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004013a5:
    // 004013a5  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004013a8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004013aa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004013ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4013b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004013b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004013b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004013b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004013b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004013b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004013b5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004013b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004013b8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004013bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004013bd  be10270000             -mov esi, 0x2710
    cpu.esi = 10000 /*0x2710*/;
    // 004013c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004013c4:
    // 004013c4  3b1d88fd5e00           +cmp ebx, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004013ca  7d51                   -jge 0x40141d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040141d;
    }
    // 004013cc  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004013cf  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004013d6  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004013d9  8b8788fa5e00           -mov eax, dword ptr [edi + 0x5efa88]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224520) /* 0x5efa88 */);
    // 004013df  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004013e2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004013e5  e836cd0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004013ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004013ec  7e13                   -jle 0x401401
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401401;
    }
    // 004013ee  8b8788fa5e00           -mov eax, dword ptr [edi + 0x5efa88]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224520) /* 0x5efa88 */);
    // 004013f4  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004013f7  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004013fa  e821cd0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004013ff  eb13                   -jmp 0x401414
    goto L_0x00401414;
L_0x00401401:
    // 00401401  8b8788fa5e00           -mov eax, dword ptr [edi + 0x5efa88]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224520) /* 0x5efa88 */);
    // 00401407  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040140a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040140d  e80ecd0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00401412  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00401414:
    // 00401414  39f0                   +cmp eax, esi
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
    // 00401416  7d02                   -jge 0x40141a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040141a;
    }
    // 00401418  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0040141a:
    // 0040141a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040141b  eba7                   -jmp 0x4013c4
    goto L_0x004013c4;
L_0x0040141d:
    // 0040141d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040141f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401421  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401422  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401423  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401424  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401425  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401426  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401427  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_401430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401430  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401431  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401432  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401433  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401435  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401438  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040143a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040143d  e8fed80000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 00401442  d84d10                 +fmul dword ptr [ebp + 0x10]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 00401445  d84514                 +fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 00401448  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040144a  d99ab0070000           +fstp dword ptr [edx + 0x7b0]
    *app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401450  e81bffffff             -call 0x401370
    cpu.esp -= 4;
    sub_401370(app, cpu);
    if (cpu.terminate) return;
    // 00401455  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401458  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040145e  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 00401461  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401463  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00401464  7609                   -jbe 0x40146f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040146f;
    }
    // 00401466  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00401469  8982b0070000           -mov dword ptr [edx + 0x7b0], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = cpu.eax;
L_0x0040146f:
    // 0040146f  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401476  740f                   -je 0x401487
    if (cpu.flags.zf)
    {
        goto L_0x00401487;
    }
    // 00401478  8aa2b3070000           -mov ah, byte ptr [edx + 0x7b3]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 0040147e  80f480                 -xor ah, 0x80
    cpu.ah ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00401481  88a2b3070000           -mov byte ptr [edx + 0x7b3], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.ah;
L_0x00401487:
    // 00401487  f6822106000010         +test byte ptr [edx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040148e  740f                   -je 0x40149f
    if (cpu.flags.zf)
    {
        goto L_0x0040149f;
    }
    // 00401490  8abab3070000           -mov bh, byte ptr [edx + 0x7b3]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 00401496  80f780                 -xor bh, 0x80
    cpu.bh ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00401499  88bab3070000           -mov byte ptr [edx + 0x7b3], bh
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.bh;
L_0x0040149f:
    // 0040149f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004014a1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014a2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014a3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014a4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4014b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004014b0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004014b1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004014b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004014b4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004014b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004014b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004014bb  7438                   -je 0x4014f5
    if (cpu.flags.zf)
    {
        goto L_0x004014f5;
    }
    // 004014bd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004014c0  e87bd80000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 004014c5  d8aac4070000           +fsubr dword ptr [edx + 0x7c4]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */) - cpu.fpu.st(0);
    // 004014cb  d982f0060000           +fld dword ptr [edx + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1776) /* 0x6f0 */)));
    // 004014d1  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004014d3  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004014d6  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 004014d9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004014db  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004014dc  7608                   -jbe 0x4014e6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004014e6;
    }
    // 004014de  8b82f0060000           -mov eax, dword ptr [edx + 0x6f0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1776) /* 0x6f0 */);
    // 004014e4  eb03                   -jmp 0x4014e9
    goto L_0x004014e9;
L_0x004014e6:
    // 004014e6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004014e9:
    // 004014e9  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004014ec  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004014ef  8982f0060000           -mov dword ptr [edx + 0x6f0], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1776) /* 0x6f0 */) = cpu.eax;
L_0x004014f5:
    // 004014f5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004014f7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014f8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004014f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_401500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401500  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401501  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401503  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00401509  83781c02               +cmp dword ptr [eax + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040150d  7507                   -jne 0x401516
    if (!cpu.flags.zf)
    {
        goto L_0x00401516;
    }
    // 0040150f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401514  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401515  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401516:
    // 00401516  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401518  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401519  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_401520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401520  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401521  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401522  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401524  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401526  f605fcd46f0010         +test byte ptr [0x6fd4fc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) & 16 /*0x10*/));
    // 0040152d  744e                   -je 0x40157d
    if (cpu.flags.zf)
    {
        goto L_0x0040157d;
    }
    // 0040152f  8b8228060000           -mov eax, dword ptr [edx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */);
    // 00401535  83781c02               +cmp dword ptr [eax + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401539  7442                   -je 0x40157d
    if (cpu.flags.zf)
    {
        goto L_0x0040157d;
    }
    // 0040153b  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 00401541  dc1d4c605300           +fcomp qword ptr [0x53604c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464140) /* 0x53604c */));
    cpu.fpu.pop();
    // 00401547  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401549  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040154a  7231                   -jb 0x40157d
    if (cpu.flags.cf)
    {
        goto L_0x0040157d;
    }
    // 0040154c  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401551  3b8124070000           +cmp eax, dword ptr [ecx + 0x724]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1828) /* 0x724 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401557  7e24                   -jle 0x40157d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040157d;
    }
    // 00401559  8b911c070000           -mov edx, dword ptr [ecx + 0x71c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1820) /* 0x71c */);
    // 0040155f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00401561  8b14954c225500         -mov edx, dword ptr [edx*4 + 0x55224c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5579340) /* 0x55224c */ + cpu.edx * 4);
    // 00401568  e853120100             -call 0x4127c0
    cpu.esp -= 4;
    sub_4127c0(app, cpu);
    if (cpu.terminate) return;
    // 0040156d  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401572  0580010000             -add eax, 0x180
    (cpu.eax) += x86::reg32(x86::sreg32(384 /*0x180*/));
    // 00401577  898124070000           -mov dword ptr [ecx + 0x724], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1828) /* 0x724 */) = cpu.eax;
L_0x0040157d:
    // 0040157d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040157e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040157f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_401580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401580  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401581  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401582  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401583  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401585  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00401587  8b15bcd46f00           -mov edx, dword ptr [0x6fd4bc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7328956) /* 0x6fd4bc */);
    // 0040158d  8b99c8020000           -mov ebx, dword ptr [ecx + 0x2c8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 00401593  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00401595  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00401597  8b901c070000           -mov edx, dword ptr [eax + 0x71c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */);
    // 0040159d  8b14954c225500         -mov edx, dword ptr [edx*4 + 0x55224c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5579340) /* 0x55224c */ + cpu.edx * 4);
    // 004015a4  e8d7120100             -call 0x412880
    cpu.esp -= 4;
    sub_412880(app, cpu);
    if (cpu.terminate) return;
    // 004015a9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015aa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015ab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004015ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4015b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004015b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004015b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004015b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004015b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004015b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004015b5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004015b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004015b8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004015ba  8b8828060000           -mov ecx, dword ptr [eax + 0x628]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 004015c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004015c2  0f8474000000           -je 0x40163c
    if (cpu.flags.zf)
    {
        goto L_0x0040163c;
    }
    // 004015c8  83791c00               +cmp dword ptr [ecx + 0x1c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004015cc  0f846a000000           -je 0x40163c
    if (cpu.flags.zf)
    {
        goto L_0x0040163c;
    }
    // 004015d2  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 004015d9  7561                   -jne 0x40163c
    if (!cpu.flags.zf)
    {
        goto L_0x0040163c;
    }
    // 004015db  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004015dd:
    // 004015dd  3b712c                 +cmp esi, dword ptr [ecx + 0x2c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004015e0  7d5a                   -jge 0x40163c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040163c;
    }
    // 004015e2  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004015e9  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004015ec  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 004015ef  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004015f2  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004015f5  e826cb0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004015fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004015fc  7e10                   -jle 0x40160e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040160e;
    }
    // 004015fe  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00401601  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00401604  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00401607  e814cb0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040160c  eb10                   -jmp 0x40161e
    goto L_0x0040161e;
L_0x0040160e:
    // 0040160e  8b4730                 -mov eax, dword ptr [edi + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 00401611  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00401614  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00401617  e804cb0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040161c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040161e:
    // 0040161e  83f80a                 +cmp eax, 0xa
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
    // 00401621  7d16                   -jge 0x401639
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401639;
    }
    // 00401623  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401628  c7411c02000000         -mov dword ptr [ecx + 0x1c], 2
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 0040162f  0540010000             +add eax, 0x140
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401634  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00401637  eb03                   -jmp 0x40163c
    goto L_0x0040163c;
L_0x00401639:
    // 00401639  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040163a  eba1                   -jmp 0x4015dd
    goto L_0x004015dd;
L_0x0040163c:
    // 0040163c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040163d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040163e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040163f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401640  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401641  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401642  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_401650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401650  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401651  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401652  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401653  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401654  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401656  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00401658  8b0c9588fa5e00         -mov ecx, dword ptr [edx*4 + 0x5efa88]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.edx * 4);
    // 0040165f  80a111070000f7         -and byte ptr [ecx + 0x711], 0xf7
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00401666  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 0040166d  0f84fd000000           -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 00401673  8bb328060000           -mov esi, dword ptr [ebx + 0x628]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1576) /* 0x628 */);
    // 00401679  c7461c02000000         -mov dword ptr [esi + 0x1c], 2
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 00401680  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00401687  740d                   -je 0x401696
    if (cpu.flags.zf)
    {
        goto L_0x00401696;
    }
    // 00401689  83bbc402000003         +cmp dword ptr [ebx + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401690  0f84da000000           -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
L_0x00401696:
    // 00401696  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 0040169d  740d                   -je 0x4016ac
    if (cpu.flags.zf)
    {
        goto L_0x004016ac;
    }
    // 0040169f  83bbc402000004         +cmp dword ptr [ebx + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004016a6  0f84c4000000           -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
L_0x004016ac:
    // 004016ac  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004016b3  754b                   -jne 0x401700
    if (!cpu.flags.zf)
    {
        goto L_0x00401700;
    }
    // 004016b5  81bbf006000000000040   +cmp dword ptr [ebx + 0x6f0], 0x40000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1776) /* 0x6f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004016bf  7f10                   -jg 0x4016d1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004016d1;
    }
    // 004016c1  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 004016c5  750a                   -jne 0x4016d1
    if (!cpu.flags.zf)
    {
        goto L_0x004016d1;
    }
    // 004016c7  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004016cb  0f849f000000           -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
L_0x004016d1:
    // 004016d1  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004016d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004016d9  7509                   -jne 0x4016e4
    if (!cpu.flags.zf)
    {
        goto L_0x004016e4;
    }
    // 004016db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004016dd  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004016df  e8cc010000             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
L_0x004016e4:
    // 004016e4  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 004016e8  0f8482000000           -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 004016ee  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004016f3  0540010000             -add eax, 0x140
    (cpu.eax) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004016f8  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004016fb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016fd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016fe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004016ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401700:
    // 00401700  81bbf006000000000040   +cmp dword ptr [ebx + 0x6f0], 0x40000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1776) /* 0x6f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040170a  7f0c                   -jg 0x401718
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00401718;
    }
    // 0040170c  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 00401710  7506                   -jne 0x401718
    if (!cpu.flags.zf)
    {
        goto L_0x00401718;
    }
    // 00401712  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401716  7458                   -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
L_0x00401718:
    // 00401718  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040171f  754f                   -jne 0x401770
    if (!cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 00401721  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00401724  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00401727  e8f4c90000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040172c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040172e  7e0d                   -jle 0x40173d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040173d;
    }
    // 00401730  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00401733  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00401736  e8e5c90000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040173b  eb0d                   -jmp 0x40174a
    goto L_0x0040174a;
L_0x0040173d:
    // 0040173d  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00401740  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00401743  e8d8c90000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00401748  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040174a:
    // 0040174a  83f814                 +cmp eax, 0x14
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
    // 0040174d  7d21                   -jge 0x401770
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401770;
    }
    // 0040174f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00401754  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00401756  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00401758  e853010000             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
    // 0040175d  837e2c00               +cmp dword ptr [esi + 0x2c], 0
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
    // 00401761  740d                   -je 0x401770
    if (cpu.flags.zf)
    {
        goto L_0x00401770;
    }
    // 00401763  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401768  0540010000             -add eax, 0x140
    (cpu.eax) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0040176d  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00401770:
    // 00401770  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401771  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401772  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401773  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401774  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_401780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401780  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401781  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401782  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401783  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401784  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401785  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401787  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401789  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 0040178f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401791  0f8412010000           -je 0x4018a9
    if (cpu.flags.zf)
    {
        goto L_0x004018a9;
    }
    // 00401797  d982f4040000           +fld dword ptr [edx + 0x4f4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 0040179d  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040179f  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004017a1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004017a3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004017a4  7307                   -jae 0x4017ad
    if (!cpu.flags.cf)
    {
        goto L_0x004017ad;
    }
    // 004017a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004017ab  eb02                   -jmp 0x4017af
    goto L_0x004017af;
L_0x004017ad:
    // 004017ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004017af:
    // 004017af  a358ea5600             -mov dword ptr [0x56ea58], eax
    *app->getMemory<x86::reg32>(x86::reg32(5696088) /* 0x56ea58 */) = cpu.eax;
    // 004017b4  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004017ba  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004017c1  7421                   -je 0x4017e4
    if (cpu.flags.zf)
    {
        goto L_0x004017e4;
    }
    // 004017c3  83b8f405000000         +cmp dword ptr [eax + 0x5f4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1524) /* 0x5f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004017ca  7507                   -jne 0x4017d3
    if (!cpu.flags.zf)
    {
        goto L_0x004017d3;
    }
    // 004017cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004017d1  eb02                   -jmp 0x4017d5
    goto L_0x004017d5;
L_0x004017d3:
    // 004017d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004017d5:
    // 004017d5  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 004017db  7426                   -je 0x401803
    if (cpu.flags.zf)
    {
        goto L_0x00401803;
    }
    // 004017dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004017e2  eb1f                   -jmp 0x401803
    goto L_0x00401803;
L_0x004017e4:
    // 004017e4  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 004017eb  7507                   -jne 0x4017f4
    if (!cpu.flags.zf)
    {
        goto L_0x004017f4;
    }
    // 004017ed  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004017f2  eb02                   -jmp 0x4017f6
    goto L_0x004017f6;
L_0x004017f4:
    // 004017f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004017f6:
    // 004017f6  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 004017fc  7405                   -je 0x401803
    if (cpu.flags.zf)
    {
        goto L_0x00401803;
    }
    // 004017fe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00401803:
    // 00401803  a35cea5600             -mov dword ptr [0x56ea5c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5696092) /* 0x56ea5c */) = cpu.eax;
    // 00401808  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040180e  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00401811  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00401814  e807c90000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00401819  8a9921060000           -mov bl, byte ptr [ecx + 0x621]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 0040181f  a360ea5600             -mov dword ptr [0x56ea60], eax
    *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */) = cpu.eax;
    // 00401824  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00401827  7507                   -jne 0x401830
    if (!cpu.flags.zf)
    {
        goto L_0x00401830;
    }
    // 00401829  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040182e  eb02                   -jmp 0x401832
    goto L_0x00401832;
L_0x00401830:
    // 00401830  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00401832:
    // 00401832  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 00401838  7407                   -je 0x401841
    if (cpu.flags.zf)
    {
        goto L_0x00401841;
    }
    // 0040183a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040183f  eb05                   -jmp 0x401846
    goto L_0x00401846;
L_0x00401841:
    // 00401841  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00401846:
    // 00401846  8b1560ea5600           -mov edx, dword ptr [0x56ea60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
    // 0040184c  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0040184f  891560ea5600           -mov dword ptr [0x56ea60], edx
    *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */) = cpu.edx;
    // 00401855  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401857  7c0a                   -jl 0x401863
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00401863;
    }
    // 00401859  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0040185b  893568ea5600           -mov dword ptr [0x56ea68], esi
    *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */) = cpu.esi;
    // 00401861  eb0a                   -jmp 0x40186d
    goto L_0x0040186d;
L_0x00401863:
    // 00401863  c70568ea560001000000   -mov dword ptr [0x56ea68], 1
    *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */) = 1 /*0x1*/;
L_0x0040186d:
    // 0040186d  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00401873  8b9938060000           -mov ebx, dword ptr [ecx + 0x638]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 00401879  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040187f  39da                   +cmp edx, ebx
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
    // 00401881  7d0a                   -jge 0x40188d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040188d;
    }
    // 00401883  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00401885  893564ea5600           -mov dword ptr [0x56ea64], esi
    *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */) = cpu.esi;
    // 0040188b  eb1c                   -jmp 0x4018a9
    goto L_0x004018a9;
L_0x0040188d:
    // 0040188d  7510                   -jne 0x40189f
    if (!cpu.flags.zf)
    {
        goto L_0x0040189f;
    }
    // 0040188f  c70564ea560001000000   -mov dword ptr [0x56ea64], 1
    *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */) = 1 /*0x1*/;
    // 00401899  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040189e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040189f:
    // 0040189f  c70564ea560002000000   -mov dword ptr [0x56ea64], 2
    *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */) = 2 /*0x2*/;
L_0x004018a9:
    // 004018a9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004018ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4018b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004018b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004018b1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004018b2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004018b3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004018b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004018b6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004018b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004018bb  8bb228060000           -mov esi, dword ptr [edx + 0x628]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */);
    // 004018c1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004018c3  0f8543010000           -jne 0x401a0c
    if (!cpu.flags.zf)
    {
        goto L_0x00401a0c;
    }
    // 004018c9  89b228070000           -mov dword ptr [edx + 0x728], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1832) /* 0x728 */) = cpu.esi;
    // 004018cf  8aa200020000           -mov ah, byte ptr [edx + 0x200]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004018d5  89b22c070000           -mov dword ptr [edx + 0x72c], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1836) /* 0x72c */) = cpu.esi;
    // 004018db  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004018de  0f8578000000           -jne 0x40195c
    if (!cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 004018e4  83ba3007000000         +cmp dword ptr [edx + 0x730], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1840) /* 0x730 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004018eb  0f846b000000           -je 0x40195c
    if (cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 004018f1  8a8211070000           -mov al, byte ptr [edx + 0x711]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */);
    // 004018f7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004018f9  740b                   -je 0x401906
    if (cpu.flags.zf)
    {
        goto L_0x00401906;
    }
    // 004018fb  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004018fd  80e4fb                 -and ah, 0xfb
    cpu.ah &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00401900  88a211070000           -mov byte ptr [edx + 0x711], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) = cpu.ah;
L_0x00401906:
    // 00401906  8a8211070000           -mov al, byte ptr [edx + 0x711]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */);
    // 0040190c  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0040190e  744c                   -je 0x40195c
    if (cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 00401910  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00401912  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00401915  88a211070000           -mov byte ptr [edx + 0x711], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) = cpu.ah;
    // 0040191b  8b8230070000           -mov eax, dword ptr [edx + 0x730]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1840) /* 0x730 */);
    // 00401921  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401923  7437                   -je 0x40195c
    if (cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 00401925  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 0040192b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040192d  742d                   -je 0x40195c
    if (cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 0040192f  c7405800000000         -mov dword ptr [eax + 0x58], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
    // 00401936  8bb214070000           -mov esi, dword ptr [edx + 0x714]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1812) /* 0x714 */);
    // 0040193c  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00401943  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00401945  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00401948  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040194f  740b                   -je 0x40195c
    if (cpu.flags.zf)
    {
        goto L_0x0040195c;
    }
    // 00401951  8b8214070000           -mov eax, dword ptr [edx + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1812) /* 0x714 */);
    // 00401957  e8f4850c00             -call 0x4c9f50
    cpu.esp -= 4;
    sub_4c9f50(app, cpu);
    if (cpu.terminate) return;
L_0x0040195c:
    // 0040195c  8b8328060000           -mov eax, dword ptr [ebx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1576) /* 0x628 */);
    // 00401962  8b781c                 -mov edi, dword ptr [eax + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00401965  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401967  7528                   -jne 0x401991
    if (!cpu.flags.zf)
    {
        goto L_0x00401991;
    }
    // 00401969  c7401c01000000         -mov dword ptr [eax + 0x1c], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00401970  897828                 -mov dword ptr [eax + 0x28], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00401973  89782c                 -mov dword ptr [eax + 0x2c], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 00401976  897850                 -mov dword ptr [eax + 0x50], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 00401979  897854                 -mov dword ptr [eax + 0x54], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 0040197c  8b3584367d00           -mov esi, dword ptr [0x7d3684]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401982  89785c                 -mov dword ptr [eax + 0x5c], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 00401985  897020                 -mov dword ptr [eax + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00401988  81c680020000           -add esi, 0x280
    (cpu.esi) += x86::reg32(x86::sreg32(640 /*0x280*/));
    // 0040198e  897024                 -mov dword ptr [eax + 0x24], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x00401991:
    // 00401991  c7823407000001000000   -mov dword ptr [edx + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 0040199b  898228060000           -mov dword ptr [edx + 0x628], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */) = cpu.eax;
    // 004019a1  899a24060000           -mov dword ptr [edx + 0x624], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */) = cpu.ebx;
    // 004019a7  808a1007000010         -or byte ptr [edx + 0x710], 0x10
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004019ae  8b702c                 -mov esi, dword ptr [eax + 0x2c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004019b1  8954b030               -mov dword ptr [eax + esi*4 + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */ + cpu.esi * 4) = cpu.edx;
    // 004019b5  ff402c                 -inc dword ptr [eax + 0x2c]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */))++;
    // 004019b8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004019ba  7607                   -jbe 0x4019c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004019c3;
    }
    // 004019bc  83f903                 +cmp ecx, 3
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
    // 004019bf  744b                   -je 0x401a0c
    if (cpu.flags.zf)
    {
        goto L_0x00401a0c;
    }
    // 004019c1  eb3e                   -jmp 0x401a01
    goto L_0x00401a01;
L_0x004019c3:
    // 004019c3  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004019c6  e875d30000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 004019cb  d86d14                 +fsubr dword ptr [ebp + 0x14]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) - cpu.fpu.st(0);
    // 004019ce  d983f0060000           +fld dword ptr [ebx + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx + x86::reg32(1776) /* 0x6f0 */)));
    // 004019d4  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004019d6  d95df8                 +fstp dword ptr [ebp - 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004019d9  d85df8                 +fcomp dword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    cpu.fpu.pop();
    // 004019dc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004019de  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004019df  7608                   -jbe 0x4019e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004019e9;
    }
    // 004019e1  8b83f0060000           -mov eax, dword ptr [ebx + 0x6f0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1776) /* 0x6f0 */);
    // 004019e7  eb03                   -jmp 0x4019ec
    goto L_0x004019ec;
L_0x004019e9:
    // 004019e9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x004019ec:
    // 004019ec  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004019ef  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004019f2  8983f0060000           -mov dword ptr [ebx + 0x6f0], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1776) /* 0x6f0 */) = cpu.eax;
    // 004019f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004019fa  e871260000             -call 0x404070
    cpu.esp -= 4;
    sub_404070(app, cpu);
    if (cpu.terminate) return;
    // 004019ff  eb0b                   -jmp 0x401a0c
    goto L_0x00401a0c;
L_0x00401a01:
    // 00401a01  ff448804               -inc dword ptr [eax + ecx*4 + 4]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ecx * 4))++;
    // 00401a05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401a07  e864260000             -call 0x404070
    cpu.esp -= 4;
    sub_404070(app, cpu);
    if (cpu.terminate) return;
L_0x00401a0c:
    // 00401a0c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401a0e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a0f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a11  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a12  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_401a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401a20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401a21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401a22  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401a23  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401a24  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401a25  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401a26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401a28  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401a2a  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00401a30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401a32  743c                   -je 0x401a70
    if (cpu.flags.zf)
    {
        goto L_0x00401a70;
    }
    // 00401a34  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00401a39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00401a3b:
    // 00401a3b  8b582c                 -mov ebx, dword ptr [eax + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00401a3e  39da                   +cmp edx, ebx
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
    // 00401a40  7d20                   -jge 0x401a62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401a62;
    }
    // 00401a42  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 00401a49  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00401a4b  83fe08                 +cmp esi, 8
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
    // 00401a4e  7408                   -je 0x401a58
    if (cpu.flags.zf)
    {
        goto L_0x00401a58;
    }
    // 00401a50  8b7b30                 -mov edi, dword ptr [ebx + 0x30]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 00401a53  897b2c                 -mov dword ptr [ebx + 0x2c], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 00401a56  eb07                   -jmp 0x401a5f
    goto L_0x00401a5f;
L_0x00401a58:
    // 00401a58  3b4b30                 +cmp ecx, dword ptr [ebx + 0x30]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401a5b  7502                   -jne 0x401a5f
    if (!cpu.flags.zf)
    {
        goto L_0x00401a5f;
    }
    // 00401a5d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00401a5f:
    // 00401a5f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401a60  ebd9                   -jmp 0x401a3b
    goto L_0x00401a3b;
L_0x00401a62:
    // 00401a62  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00401a65  89502c                 -mov dword ptr [eax + 0x2c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00401a68  c744903000000000       -mov dword ptr [eax + edx*4 + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */ + cpu.edx * 4) = 0 /*0x0*/;
L_0x00401a70:
    // 00401a70  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a71  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a72  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a73  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a74  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a75  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401a76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_401a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401a80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401a81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401a82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401a83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401a84  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401a85  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401a86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401a88  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401a8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00401a8d  83b82406000000         +cmp dword ptr [eax + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401a94  0f84ab000000           -je 0x401b45
    if (cpu.flags.zf)
    {
        goto L_0x00401b45;
    }
    // 00401a9a  8b8828060000           -mov ecx, dword ptr [eax + 0x628]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00401aa0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00401aa2  0f849d000000           -je 0x401b45
    if (cpu.flags.zf)
    {
        goto L_0x00401b45;
    }
    // 00401aa8  83791c02               +cmp dword ptr [ecx + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401aac  750d                   -jne 0x401abb
    if (!cpu.flags.zf)
    {
        goto L_0x00401abb;
    }
    // 00401aae  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00401ab5  0f848a000000           -je 0x401b45
    if (cpu.flags.zf)
    {
        goto L_0x00401b45;
    }
L_0x00401abb:
    // 00401abb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401abd  e8ee250000             -call 0x4040b0
    cpu.esp -= 4;
    sub_4040b0(app, cpu);
    if (cpu.terminate) return;
    // 00401ac2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401ac4  e857ffffff             -call 0x401a20
    cpu.esp -= 4;
    sub_401a20(app, cpu);
    if (cpu.terminate) return;
    // 00401ac9  8b712c                 -mov esi, dword ptr [ecx + 0x2c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00401acc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00401ace  7541                   -jne 0x401b11
    if (!cpu.flags.zf)
    {
        goto L_0x00401b11;
    }
    // 00401ad0  8b8224060000           -mov eax, dword ptr [edx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
    // 00401ad6  f6802106000040         +test byte ptr [eax + 0x621], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 64 /*0x40*/));
    // 00401add  7532                   -jne 0x401b11
    if (!cpu.flags.zf)
    {
        goto L_0x00401b11;
    }
    // 00401adf  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00401ae1  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00401ae4  89711c                 -mov dword ptr [ecx + 0x1c], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00401ae7  47                     -inc edi
    (cpu.edi)++;
    // 00401ae8  40                     -inc eax
    (cpu.eax)++;
    // 00401ae9  8939                   -mov dword ptr [ecx], edi
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 00401aeb  894114                 -mov dword ptr [ecx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00401aee  8b8224060000           -mov eax, dword ptr [edx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
    // 00401af4  d980f0060000           -fld dword ptr [eax + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1776) /* 0x6f0 */)));
    // 00401afa  e857e20d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00401aff  db5dfc                 -fistp dword ptr [ebp - 4]
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00401b02  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00401b05  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00401b08  39d8                   +cmp eax, ebx
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
    // 00401b0a  7f02                   -jg 0x401b0e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00401b0e;
    }
    // 00401b0c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00401b0e:
    // 00401b0e  894104                 -mov dword ptr [ecx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00401b11:
    // 00401b11  c7822806000000000000   -mov dword ptr [edx + 0x628], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */) = 0 /*0x0*/;
    // 00401b1b  c7822406000000000000   -mov dword ptr [edx + 0x624], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 00401b25  8aba10070000           -mov bh, byte ptr [edx + 0x710]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */);
    // 00401b2b  c7823407000000000000   -mov dword ptr [edx + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 00401b35  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00401b38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00401b3a  88ba10070000           -mov byte ptr [edx + 0x710], bh
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.bh;
    // 00401b40  e80bf8ffff             -call 0x401350
    cpu.esp -= 4;
    sub_401350(app, cpu);
    if (cpu.terminate) return;
L_0x00401b45:
    // 00401b45  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401b47  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b48  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b49  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b4a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b4b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b4c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401b4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_401b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401b50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401b51  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401b52  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401b53  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401b54  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401b55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401b57  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00401b5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00401b5c  8b8810020000           -mov ecx, dword ptr [eax + 0x210]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(528) /* 0x210 */);
    // 00401b62  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00401b64  7e0e                   -jle 0x401b74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401b74;
    }
    // 00401b66  db8610020000           +fild dword ptr [esi + 0x210]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(528) /* 0x210 */))));
    // 00401b6c  dc0d54605300           +fmul qword ptr [0x536054]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464148) /* 0x536054 */));
    // 00401b72  eb18                   -jmp 0x401b8c
    goto L_0x00401b8c;
L_0x00401b74:
    // 00401b74  8d8100020000           -lea eax, [ecx + 0x200]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(512) /* 0x200 */);
    // 00401b7a  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00401b7d  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00401b80  dc0d5c605300           -fmul qword ptr [0x53605c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464156) /* 0x53605c */));
    // 00401b86  dc0564605300           -fadd qword ptr [0x536064]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(x86::reg32(5464164) /* 0x536064 */));
L_0x00401b8c:
    // 00401b8c  dd5de8                 -fstp qword ptr [ebp - 0x18]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401b8f  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00401b92  d95df0                 -fstp dword ptr [ebp - 0x10]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401b95  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401b97  7412                   -je 0x401bab
    if (cpu.flags.zf)
    {
        goto L_0x00401bab;
    }
    // 00401b99  bfcdcc4cbe             -mov edi, 0xbe4ccccd
    cpu.edi = 3192704205 /*0xbe4ccccd*/;
    // 00401b9e  bb000000c0             -mov ebx, 0xc0000000
    cpu.ebx = 3221225472 /*0xc0000000*/;
    // 00401ba3  897df4                 -mov dword ptr [ebp - 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00401ba6  895df8                 -mov dword ptr [ebp - 8], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00401ba9  eb10                   -jmp 0x401bbb
    goto L_0x00401bbb;
L_0x00401bab:
    // 00401bab  bacdcc4c3e             -mov edx, 0x3e4ccccd
    cpu.edx = 1045220557 /*0x3e4ccccd*/;
    // 00401bb0  b800000040             -mov eax, 0x40000000
    cpu.eax = 1073741824 /*0x40000000*/;
    // 00401bb5  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00401bb8  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00401bbb:
    // 00401bbb  d945f0                 -fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00401bbe  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00401bc1  d845f4                 -fadd dword ptr [ebp - 0xc]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    // 00401bc4  8d86ec080000           -lea eax, [esi + 0x8ec]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(2284) /* 0x8ec */);
    // 00401bca  d91c24                 -fstp dword ptr [esp]
    *app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401bcd  e80ee20d00             -call 0x4dfde0
    cpu.esp -= 4;
    sub_4dfde0(app, cpu);
    if (cpu.terminate) return;
    // 00401bd2  8d45dc                 -lea eax, [ebp - 0x24]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00401bd5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00401bd6  8d5ddc                 -lea ebx, [ebp - 0x24]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00401bd9  8d9690010000           -lea edx, [esi + 0x190]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(400) /* 0x190 */);
    // 00401bdf  ff75f8                 -push dword ptr [ebp - 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 00401be2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401be7  8d8e10090000           -lea ecx, [esi + 0x910]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(2320) /* 0x910 */);
    // 00401bed  e85ee40d00             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 00401bf2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401bf7  8d9698000000           -lea edx, [esi + 0x98]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 00401bfd  e8fee30d00             -call 0x4e0000
    cpu.esp -= 4;
    sub_4e0000(app, cpu);
    if (cpu.terminate) return;
    // 00401c02  d98618010000           -fld dword ptr [esi + 0x118]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(280) /* 0x118 */)));
    // 00401c08  d8ae14090000           -fsubr dword ptr [esi + 0x914]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.esi + x86::reg32(2324) /* 0x914 */) - cpu.fpu.st(0);
    // 00401c0e  d99e14090000           -fstp dword ptr [esi + 0x914]
    *app->getMemory<float>(cpu.esi + x86::reg32(2324) /* 0x914 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401c14  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401c16  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c17  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c18  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c19  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c1a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401c1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_401c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401c20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401c21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401c22  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401c23  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401c24  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401c25  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401c27  81ec30010000           -sub esp, 0x130
    (cpu.esp) -= x86::reg32(x86::sreg32(304 /*0x130*/));
    // 00401c2d  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 00401c33  89557a                 -mov dword ptr [ebp + 0x7a], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.edx;
    // 00401c36  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401c39  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00401c3c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00401c3e  894572                 -mov dword ptr [ebp + 0x72], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.eax;
    // 00401c41  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401c44  895576                 -mov dword ptr [ebp + 0x76], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edx;
    // 00401c47  8b5572                 -mov edx, dword ptr [ebp + 0x72]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00401c4a  8db8ec080000           -lea edi, [eax + 0x8ec]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(2284) /* 0x8ec */);
    // 00401c50  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00401c57  b909000000             -mov ecx, 9
    cpu.ecx = 9 /*0x9*/;
    // 00401c5c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00401c5e  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00401c63  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00401c66  be98445600             -mov esi, 0x564498
    cpu.esi = 5653656 /*0x564498*/;
    // 00401c6b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00401c6d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00401c6f  8b5015                 -mov edx, dword ptr [eax + 0x15]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 00401c72  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401c75  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401c78  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401c7b  dd056c605300           -fld qword ptr [0x53606c]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(x86::reg32(5464172) /* 0x53606c */)));
    // 00401c81  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401c84  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401c86  d95d42                 -fstp dword ptr [ebp + 0x42]
    *app->getMemory<float>(cpu.ebp + x86::reg32(66) /* 0x42 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401c89  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00401c8c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401c8f  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401c92  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401c95  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401c98  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401c9a  d95d46                 -fstp dword ptr [ebp + 0x46]
    *app->getMemory<float>(cpu.ebp + x86::reg32(70) /* 0x46 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401c9d  8b5017                 -mov edx, dword ptr [eax + 0x17]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 00401ca0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401ca3  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401ca6  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401ca9  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401cac  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cae  d95d4a                 -fstp dword ptr [ebp + 0x4a]
    *app->getMemory<float>(cpu.ebp + x86::reg32(74) /* 0x4a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401cb1  8b5011                 -mov edx, dword ptr [eax + 0x11]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 00401cb4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401cb7  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401cba  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401cbd  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401cc0  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cc2  d95d66                 -fstp dword ptr [ebp + 0x66]
    *app->getMemory<float>(cpu.ebp + x86::reg32(102) /* 0x66 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401cc5  8b5012                 -mov edx, dword ptr [eax + 0x12]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 00401cc8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401ccb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401cce  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401cd1  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401cd4  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cd6  d95d6a                 -fstp dword ptr [ebp + 0x6a]
    *app->getMemory<float>(cpu.ebp + x86::reg32(106) /* 0x6a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401cd9  8b5013                 -mov edx, dword ptr [eax + 0x13]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 00401cdc  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00401cdf  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00401ce2  89557e                 -mov dword ptr [ebp + 0x7e], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 00401ce5  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 00401ce8  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cea  d95d6e                 -fstp dword ptr [ebp + 0x6e]
    *app->getMemory<float>(cpu.ebp + x86::reg32(110) /* 0x6e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401ced  db00                   -fild dword ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax))));
    // 00401cef  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cf1  d95d5a                 -fstp dword ptr [ebp + 0x5a]
    *app->getMemory<float>(cpu.ebp + x86::reg32(90) /* 0x5a */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401cf4  db4004                 -fild dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 00401cf7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00401cf9  d95d5e                 -fstp dword ptr [ebp + 0x5e]
    *app->getMemory<float>(cpu.ebp + x86::reg32(94) /* 0x5e */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401cfc  db4008                 -fild dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */))));
    // 00401cff  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00401d01  d95d62                 -fstp dword ptr [ebp + 0x62]
    *app->getMemory<float>(cpu.ebp + x86::reg32(98) /* 0x62 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401d04  8b5d7a                 -mov ebx, dword ptr [ebp + 0x7a]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401d07  8d4d4e                 -lea ecx, [ebp + 0x4e]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 00401d0a  8d555a                 -lea edx, [ebp + 0x5a]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 00401d0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401d12  81c398000000           +add ebx, 0x98
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401d18  e8e3e20d00             -call 0x4e0000
    cpu.esp -= 4;
    sub_4e0000(app, cpu);
    if (cpu.terminate) return;
    // 00401d1d  8d5542                 -lea edx, [ebp + 0x42]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(66) /* 0x42 */);
    // 00401d20  8d454e                 -lea eax, [ebp + 0x4e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(78) /* 0x4e */);
    // 00401d23  e8c8e40d00             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 00401d28  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00401d2a  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00401d2c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401d2e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00401d2f  7307                   -jae 0x401d38
    if (!cpu.flags.cf)
    {
        goto L_0x00401d38;
    }
    // 00401d31  c7457601000000         -mov dword ptr [ebp + 0x76], 1
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = 1 /*0x1*/;
L_0x00401d38:
    // 00401d38  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401d3b  8d5566                 -lea edx, [ebp + 0x66]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00401d3e  05a8010000             +add eax, 0x1a8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(424 /*0x1a8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401d43  e8a8e40d00             -call 0x4e01f0
    cpu.esp -= 4;
    sub_4e01f0(app, cpu);
    if (cpu.terminate) return;
    // 00401d48  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00401d4a  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00401d4c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401d4e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00401d4f  7604                   -jbe 0x401d55
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00401d55;
    }
    // 00401d51  80757601               -xor byte ptr [ebp + 0x76], 1
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(118) /* 0x76 */) ^= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00401d55:
    // 00401d55  8b5576                 -mov edx, dword ptr [ebp + 0x76]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00401d58  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401d5b  8b5d72                 -mov ebx, dword ptr [ebp + 0x72]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00401d5e  8d75ca                 -lea esi, [ebp - 0x36]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-54) /* -0x36 */);
    // 00401d61  e8eafdffff             -call 0x401b50
    cpu.esp -= 4;
    sub_401b50(app, cpu);
    if (cpu.terminate) return;
    // 00401d66  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401d69  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00401d6e  0510090000             -add eax, 0x910
    (cpu.eax) += x86::reg32(x86::sreg32(2320 /*0x910*/));
    // 00401d73  e828e80100             -call 0x4205a0
    cpu.esp -= 4;
    sub_4205a0(app, cpu);
    if (cpu.terminate) return;
    // 00401d78  837d3600               +cmp dword ptr [ebp + 0x36], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(54) /* 0x36 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401d7c  7546                   -jne 0x401dc4
    if (!cpu.flags.zf)
    {
        goto L_0x00401dc4;
    }
    // 00401d7e  837dde00               +cmp dword ptr [ebp - 0x22], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-34) /* -0x22 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401d82  7440                   -je 0x401dc4
    if (cpu.flags.zf)
    {
        goto L_0x00401dc4;
    }
    // 00401d84  8b7de2                 -mov edi, dword ptr [ebp - 0x1e]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */);
    // 00401d87  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00401d89  7439                   -je 0x401dc4
    if (cpu.flags.zf)
    {
        goto L_0x00401dc4;
    }
    // 00401d8b  740c                   -je 0x401d99
    if (cpu.flags.zf)
    {
        goto L_0x00401d99;
    }
    // 00401d8d  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00401d90  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00401d95  a83f                   +test al, 0x3f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 63 /*0x3f*/));
    // 00401d97  742b                   -je 0x401dc4
    if (cpu.flags.zf)
    {
        goto L_0x00401dc4;
    }
L_0x00401d99:
    // 00401d99  8b55e2                 -mov edx, dword ptr [ebp - 0x1e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-30) /* -0x1e */);
    // 00401d9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401d9e  740a                   -je 0x401daa
    if (cpu.flags.zf)
    {
        goto L_0x00401daa;
    }
    // 00401da0  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00401da3  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00401da8  eb05                   -jmp 0x401daf
    goto L_0x00401daf;
L_0x00401daa:
    // 00401daa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00401daf:
    // 00401daf  83e03f                 -and eax, 0x3f
    cpu.eax &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00401db2  83f80e                 +cmp eax, 0xe
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401db5  7407                   -je 0x401dbe
    if (cpu.flags.zf)
    {
        goto L_0x00401dbe;
    }
    // 00401db7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401dbc  eb02                   -jmp 0x401dc0
    goto L_0x00401dc0;
L_0x00401dbe:
    // 00401dbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00401dc0:
    // 00401dc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00401dc2  752f                   -jne 0x401df3
    if (!cpu.flags.zf)
    {
        goto L_0x00401df3;
    }
L_0x00401dc4:
    // 00401dc4  8a5576                 -mov dl, byte ptr [ebp + 0x76]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00401dc7  80f201                 -xor dl, 1
    cpu.dl ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00401dca  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401dcd  885576                 -mov byte ptr [ebp + 0x76], dl
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.dl;
    // 00401dd0  8b5d72                 -mov ebx, dword ptr [ebp + 0x72]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00401dd3  8b5576                 -mov edx, dword ptr [ebp + 0x76]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00401dd6  8db552ffffff           -lea esi, [ebp - 0xae]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-174) /* -0xae */);
    // 00401ddc  e86ffdffff             -call 0x401b50
    cpu.esp -= 4;
    sub_401b50(app, cpu);
    if (cpu.terminate) return;
    // 00401de1  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401de4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00401de9  0510090000             -add eax, 0x910
    (cpu.eax) += x86::reg32(x86::sreg32(2320 /*0x910*/));
    // 00401dee  e8ade70100             -call 0x4205a0
    cpu.esp -= 4;
    sub_4205a0(app, cpu);
    if (cpu.terminate) return;
L_0x00401df3:
    // 00401df3  8b457a                 -mov eax, dword ptr [ebp + 0x7a]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 00401df6  c780e808000001000000   -mov dword ptr [eax + 0x8e8], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2280) /* 0x8e8 */) = 1 /*0x1*/;
    // 00401e00  c780e408000001000000   -mov dword ptr [eax + 0x8e4], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2276) /* 0x8e4 */) = 1 /*0x1*/;
    // 00401e0a  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 00401e10  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e11  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e12  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e13  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e14  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_401e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401e20  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401e21  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401e23  c780e808000000000000   -mov dword ptr [eax + 0x8e8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2280) /* 0x8e8 */) = 0 /*0x0*/;
    // 00401e2d  c780e408000000000000   -mov dword ptr [eax + 0x8e4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2276) /* 0x8e4 */) = 0 /*0x0*/;
    // 00401e37  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401e38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_401e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401e40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401e41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401e42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401e43  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401e44  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401e45  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401e46  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401e48  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00401e4b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00401e4d  8b9828060000           -mov ebx, dword ptr [eax + 0x628]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00401e53  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401e55  8b532c                 -mov edx, dword ptr [ebx + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    // 00401e58  8bb024060000           -mov esi, dword ptr [eax + 0x624]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00401e5e  83fa01                 +cmp edx, 1
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
    // 00401e61  0f8ead000000           -jle 0x401f14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401f14;
    }
    // 00401e67  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00401e6e  0f84a0000000           -je 0x401f14
    if (cpu.flags.zf)
    {
        goto L_0x00401f14;
    }
    // 00401e74  b800401c46             -mov eax, 0x461c4000
    cpu.eax = 1176256512 /*0x461c4000*/;
    // 00401e79  8b5350                 -mov edx, dword ptr [ebx + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 00401e7c  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00401e7f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401e81  7407                   -je 0x401e8a
    if (cpu.flags.zf)
    {
        goto L_0x00401e8a;
    }
    // 00401e83  31f9                   +xor ecx, edi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00401e85  e98a000000             -jmp 0x401f14
    goto L_0x00401f14;
L_0x00401e8a:
    // 00401e8a  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x00401e8d:
    // 00401e8d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00401e90  3b432c                 +cmp eax, dword ptr [ebx + 0x2c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401e93  0f8d7b000000           -jge 0x401f14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00401f14;
    }
    // 00401e99  8d8698000000           -lea eax, [esi + 0x98]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 00401e9f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00401ea2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00401ea5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00401ea8  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00401eab  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00401eae  8b4230                 -mov eax, dword ptr [edx + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00401eb1  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00401eb4  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401eb9  e8f2460900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00401ebe  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00401ec0  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00401ec2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401ec4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00401ec5  7315                   -jae 0x401edc
    if (!cpu.flags.cf)
    {
        goto L_0x00401edc;
    }
    // 00401ec7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00401eca  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00401ecd  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00401ed0  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401ed5  e8d6460900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00401eda  eb15                   -jmp 0x401ef1
    goto L_0x00401ef1;
L_0x00401edc:
    // 00401edc  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00401edf  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00401ee2  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00401ee5  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401eea  e8c1460900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00401eef  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00401ef1:
    // 00401ef1  d95df4                 +fstp dword ptr [ebp - 0xc]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00401ef4  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00401ef7  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    cpu.fpu.pop();
    // 00401efa  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00401efc  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00401efd  730d                   -jae 0x401f0c
    if (!cpu.flags.cf)
    {
        goto L_0x00401f0c;
    }
    // 00401eff  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00401f02  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00401f05  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00401f08  8b4c8330               -mov ecx, dword ptr [ebx + eax*4 + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */ + cpu.eax * 4);
L_0x00401f0c:
    // 00401f0c  ff45fc                 +inc dword ptr [ebp - 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00401f0f  e979ffffff             -jmp 0x401e8d
    goto L_0x00401e8d;
L_0x00401f14:
    // 00401f14  39cf                   +cmp edi, ecx
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
    // 00401f16  740c                   -je 0x401f24
    if (cpu.flags.zf)
    {
        goto L_0x00401f24;
    }
    // 00401f18  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00401f1a  e891230000             -call 0x4042b0
    cpu.esp -= 4;
    sub_4042b0(app, cpu);
    if (cpu.terminate) return;
    // 00401f1f  e97b000000             -jmp 0x401f9f
    goto L_0x00401f9f;
L_0x00401f24:
    // 00401f24  8a9110070000           -mov dl, byte ptr [ecx + 0x710]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 00401f2a  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00401f2d  889110070000           -mov byte ptr [ecx + 0x710], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.dl;
    // 00401f33  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00401f35  80e6ef                 -and dh, 0xef
    cpu.dh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00401f38  88b110070000           -mov byte ptr [ecx + 0x710], dh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.dh;
    // 00401f3e  8b5350                 -mov edx, dword ptr [ebx + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 00401f41  42                     -inc edx
    (cpu.edx)++;
    // 00401f42  895350                 -mov dword ptr [ebx + 0x50], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00401f45  83fa01                 +cmp edx, 1
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
    // 00401f48  7555                   -jne 0x401f9f
    if (!cpu.flags.zf)
    {
        goto L_0x00401f9f;
    }
    // 00401f4a  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00401f51  740c                   -je 0x401f5f
    if (cpu.flags.zf)
    {
        goto L_0x00401f5f;
    }
    // 00401f53  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401f58  05c0000000             +add eax, 0xc0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00401f5d  eb16                   -jmp 0x401f75
    goto L_0x00401f75;
L_0x00401f5f:
    // 00401f5f  8bbec8020000           -mov edi, dword ptr [esi + 0x2c8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(712) /* 0x2c8 */);
    // 00401f65  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00401f68  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401f6d  8b97b8215500           -mov edx, dword ptr [edi + 0x5521b8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5579192) /* 0x5521b8 */);
    // 00401f73  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00401f75:
    // 00401f75  894328                 -mov dword ptr [ebx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00401f78  f6860002000004         +test byte ptr [esi + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00401f7f  7409                   -je 0x401f8a
    if (cpu.flags.zf)
    {
        goto L_0x00401f8a;
    }
    // 00401f81  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00401f83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00401f85  e8f6f5ffff             -call 0x401580
    cpu.esp -= 4;
    sub_401580(app, cpu);
    if (cpu.terminate) return;
L_0x00401f8a:
    // 00401f8a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00401f8c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00401f8e  e88dfcffff             -call 0x401c20
    cpu.esp -= 4;
    sub_401c20(app, cpu);
    if (cpu.terminate) return;
    // 00401f93  898ea4090000           -mov dword ptr [esi + 0x9a4], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2468) /* 0x9a4 */) = cpu.ecx;
    // 00401f99  89b1a4090000           -mov dword ptr [ecx + 0x9a4], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2468) /* 0x9a4 */) = cpu.esi;
L_0x00401f9f:
    // 00401f9f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00401fa1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fa7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_401fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401fb0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401fb1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401fb2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401fb3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401fb5  8b9028060000           -mov edx, dword ptr [eax + 0x628]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00401fbb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00401fbd  7421                   -je 0x401fe0
    if (cpu.flags.zf)
    {
        goto L_0x00401fe0;
    }
    // 00401fbf  83b82406000000         +cmp dword ptr [eax + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401fc6  7418                   -je 0x401fe0
    if (cpu.flags.zf)
    {
        goto L_0x00401fe0;
    }
    // 00401fc8  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00401fce  3b4a28                 +cmp ecx, dword ptr [edx + 0x28]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00401fd1  7e07                   -jle 0x401fda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00401fda;
    }
    // 00401fd3  e818000000             -call 0x401ff0
    cpu.esp -= 4;
    sub_401ff0(app, cpu);
    if (cpu.terminate) return;
    // 00401fd8  eb06                   -jmp 0x401fe0
    goto L_0x00401fe0;
L_0x00401fda:
    // 00401fda  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00401fdc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fdd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fde  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fdf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00401fe0:
    // 00401fe0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00401fe5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fe6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fe7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00401fe8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_401ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00401ff0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00401ff1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00401ff2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00401ff3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00401ff4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00401ff5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00401ff6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00401ff8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00401ffb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00401ffd  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00402003  8b9828060000           -mov ebx, dword ptr [eax + 0x628]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00402009  80a221060000bf         -and byte ptr [edx + 0x621], 0xbf
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 00402010  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00402012  c7431400000000         -mov dword ptr [ebx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00402019  46                     -inc esi
    (cpu.esi)++;
    // 0040201a  8933                   -mov dword ptr [ebx], esi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0040201c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040201f  d982f0060000           -fld dword ptr [edx + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1776) /* 0x6f0 */)));
    // 00402025  e82cdd0d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0040202a  db5dfc                 -fistp dword ptr [ebp - 4]
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040202d  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402030  39f8                   +cmp eax, edi
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
    // 00402032  7f02                   -jg 0x402036
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402036;
    }
    // 00402034  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00402036:
    // 00402036  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00402039  8b81cc020000           -mov eax, dword ptr [ecx + 0x2cc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */);
    // 0040203f  40                     -inc eax
    (cpu.eax)++;
    // 00402040  8b35b8d46f00           -mov esi, dword ptr [0x6fd4b8]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(7328952) /* 0x6fd4b8 */);
    // 00402046  8981cc020000           -mov dword ptr [ecx + 0x2cc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */) = cpu.eax;
    // 0040204c  39f0                   +cmp eax, esi
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
    // 0040204e  7510                   -jne 0x402060
    if (!cpu.flags.zf)
    {
        goto L_0x00402060;
    }
    // 00402050  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402055  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0040205a  8981d4020000           -mov dword ptr [ecx + 0x2d4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(724) /* 0x2d4 */) = cpu.eax;
L_0x00402060:
    // 00402060  d982f0060000           -fld dword ptr [edx + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1776) /* 0x6f0 */)));
    // 00402066  8bbac8020000           -mov edi, dword ptr [edx + 0x2c8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */);
    // 0040206c  e8e5dc0d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00402071  47                     -inc edi
    (cpu.edi)++;
    // 00402072  db5df8                 -fistp dword ptr [ebp - 8]
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00402075  89bac8020000           -mov dword ptr [edx + 0x2c8], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */) = cpu.edi;
    // 0040207b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040207e  0181d0020000           -add dword ptr [ecx + 0x2d0], eax
    (*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402084  8b3dbcd46f00           -mov edi, dword ptr [0x6fd4bc]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(7328956) /* 0x6fd4bc */);
    // 0040208a  8b82c8020000           -mov eax, dword ptr [edx + 0x2c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */);
    // 00402090  c782f006000000000000   -mov dword ptr [edx + 0x6f0], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1776) /* 0x6f0 */) = 0 /*0x0*/;
    // 0040209a  39f8                   +cmp eax, edi
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
    // 0040209c  7c0a                   -jl 0x4020a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004020a8;
    }
    // 0040209e  c782c402000004000000   -mov dword ptr [edx + 0x2c4], 4
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = 4 /*0x4*/;
L_0x004020a8:
    // 004020a8  8bb2c8020000           -mov esi, dword ptr [edx + 0x2c8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(712) /* 0x2c8 */);
    // 004020ae  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004020b1  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004020b6  8bbeb4215500           -mov edi, dword ptr [esi + 0x5521b4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5579188) /* 0x5521b4 */);
    // 004020bc  c782a409000000000000   -mov dword ptr [edx + 0x9a4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2468) /* 0x9a4 */) = 0 /*0x0*/;
    // 004020c6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004020c8  898234060000           -mov dword ptr [edx + 0x634], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1588) /* 0x634 */) = cpu.eax;
    // 004020ce  c781a409000000000000   -mov dword ptr [ecx + 0x9a4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2468) /* 0x9a4 */) = 0 /*0x0*/;
    // 004020d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004020da  c6828a00000000         -mov byte ptr [edx + 0x8a], 0
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(138) /* 0x8a */) = 0 /*0x0*/;
    // 004020e1  e83afdffff             -call 0x401e20
    cpu.esp -= 4;
    sub_401e20(app, cpu);
    if (cpu.terminate) return;
    // 004020e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004020e8  e8f31f0000             -call 0x4040e0
    cpu.esp -= 4;
    sub_4040e0(app, cpu);
    if (cpu.terminate) return;
    // 004020ed  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004020f4  c7435000000000         -mov dword ptr [ebx + 0x50], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 004020fb  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00402102  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00402104  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402105  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402106  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402107  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402108  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402109  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040210a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_402110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402110  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402111  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402112  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402113  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402114  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402115  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402116  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402118  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040211b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040211d  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00402123  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402125  0f840c020000           -je 0x402337
    if (cpu.flags.zf)
    {
        goto L_0x00402337;
    }
    // 0040212b  8bb028060000           -mov esi, dword ptr [eax + 0x628]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00402131  837e1c02               +cmp dword ptr [esi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402135  0f85a7000000           -jne 0x4021e2
    if (!cpu.flags.zf)
    {
        goto L_0x004021e2;
    }
    // 0040213b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040213d  f6820002000004         +test byte ptr [edx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00402144  7414                   -je 0x40215a
    if (cpu.flags.zf)
    {
        goto L_0x0040215a;
    }
    // 00402146  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040214d  7507                   -jne 0x402156
    if (!cpu.flags.zf)
    {
        goto L_0x00402156;
    }
    // 0040214f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402154  eb1d                   -jmp 0x402173
    goto L_0x00402173;
L_0x00402156:
    // 00402156  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402158  eb19                   -jmp 0x402173
    goto L_0x00402173;
L_0x0040215a:
    // 0040215a  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402161  750e                   -jne 0x402171
    if (!cpu.flags.zf)
    {
        goto L_0x00402171;
    }
    // 00402163  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402168  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040216a  750b                   -jne 0x402177
    if (!cpu.flags.zf)
    {
        goto L_0x00402177;
    }
    // 0040216c  e971000000             -jmp 0x4021e2
    goto L_0x004021e2;
L_0x00402171:
    // 00402171  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402173:
    // 00402173  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402175  746b                   -je 0x4021e2
    if (cpu.flags.zf)
    {
        goto L_0x004021e2;
    }
L_0x00402177:
    // 00402177  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040217d  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00402183  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402188  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040218a  e821440900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040218f  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00402191  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00402193  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402195  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402196  7314                   -jae 0x4021ac
    if (!cpu.flags.cf)
    {
        goto L_0x004021ac;
    }
    // 00402198  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040219e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004021a0  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004021a5  e806440900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004021aa  eb14                   -jmp 0x4021c0
    goto L_0x004021c0;
L_0x004021ac:
    // 004021ac  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004021b2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004021b4  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004021b9  e8f2430900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004021be  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004021c0:
    // 004021c0  d95df8                 +fstp dword ptr [ebp - 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004021c3  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004021c6  dc1d74605300           +fcomp qword ptr [0x536074]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464180) /* 0x536074 */));
    cpu.fpu.pop();
    // 004021cc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004021ce  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004021cf  0f8235020000           -jb 0x40240a
    if (cpu.flags.cf)
    {
        goto L_0x0040240a;
    }
    // 004021d5  837e5003               +cmp dword ptr [esi + 0x50], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004021d9  7d14                   -jge 0x4021ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004021ef;
    }
    // 004021db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004021e0  eb12                   -jmp 0x4021f4
    goto L_0x004021f4;
L_0x004021e2:
    // 004021e2  837e5003               +cmp dword ptr [esi + 0x50], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004021e6  7d07                   -jge 0x4021ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004021ef;
    }
    // 004021e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004021ed  eb05                   -jmp 0x4021f4
    goto L_0x004021f4;
L_0x004021ef:
    // 004021ef  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x004021f4:
    // 004021f4  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004021f7  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004021fa  dc0d7c605300           -fmul qword ptr [0x53607c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464188) /* 0x53607c */));
    // 00402200  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00402206  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040220c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040220e  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402213  d95df0                 +fstp dword ptr [ebp - 0x10]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402216  e895430900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040221b  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040221d  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040221f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402221  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402222  7314                   -jae 0x402238
    if (!cpu.flags.cf)
    {
        goto L_0x00402238;
    }
    // 00402224  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040222a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040222c  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402231  e87a430900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00402236  eb14                   -jmp 0x40224c
    goto L_0x0040224c;
L_0x00402238:
    // 00402238  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040223e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00402240  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00402245  e866430900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040224a  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x0040224c:
    // 0040224c  d95df4                 +fstp dword ptr [ebp - 0xc]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040224f  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00402252  d85df0                 +fcomp dword ptr [ebp - 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    cpu.fpu.pop();
    // 00402255  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402257  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402258  0f8350010000           -jae 0x4023ae
    if (!cpu.flags.cf)
    {
        goto L_0x004023ae;
    }
    // 0040225e  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402264  d980c4070000           +fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 0040226a  d81d50ea5600           +fcomp dword ptr [0x56ea50]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(x86::reg32(5696080) /* 0x56ea50 */));
    cpu.fpu.pop();
    // 00402270  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402272  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402273  0f8735010000           -ja 0x4023ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004023ae;
    }
    // 00402279  6683b96401000000       +cmp word ptr [ecx + 0x164], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00402281  0f8527010000           -jne 0x4023ae
    if (!cpu.flags.zf)
    {
        goto L_0x004023ae;
    }
    // 00402287  d9810c010000           +fld dword ptr [ecx + 0x10c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(268) /* 0x10c */)));
    // 0040228d  dc1d84605300           +fcomp qword ptr [0x536084]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464196) /* 0x536084 */));
    cpu.fpu.pop();
    // 00402293  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402295  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402296  0f8612010000           -jbe 0x4023ae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004023ae;
    }
    // 0040229c  f6811007000040         +test byte ptr [ecx + 0x710], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) & 64 /*0x40*/));
    // 004022a3  0f8499000000           -je 0x402342
    if (cpu.flags.zf)
    {
        goto L_0x00402342;
    }
    // 004022a9  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004022ae  8bb920070000           -mov edi, dword ptr [ecx + 0x720]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1824) /* 0x720 */);
    // 004022b4  39f8                   +cmp eax, edi
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
    // 004022b6  7e56                   -jle 0x40230e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040230e;
    }
    // 004022b8  0540010000             -add eax, 0x140
    (cpu.eax) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004022bd  c7461c02000000         -mov dword ptr [esi + 0x1c], 2
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 004022c4  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004022c7  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004022cd  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004022d4  7414                   -je 0x4022ea
    if (cpu.flags.zf)
    {
        goto L_0x004022ea;
    }
    // 004022d6  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004022dd  7507                   -jne 0x4022e6
    if (!cpu.flags.zf)
    {
        goto L_0x004022e6;
    }
    // 004022df  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004022e4  eb16                   -jmp 0x4022fc
    goto L_0x004022fc;
L_0x004022e6:
    // 004022e6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004022e8  eb12                   -jmp 0x4022fc
    goto L_0x004022fc;
L_0x004022ea:
    // 004022ea  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004022f1  7507                   -jne 0x4022fa
    if (!cpu.flags.zf)
    {
        goto L_0x004022fa;
    }
    // 004022f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004022f8  eb02                   -jmp 0x4022fc
    goto L_0x004022fc;
L_0x004022fa:
    // 004022fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004022fc:
    // 004022fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004022fe  0f8433000000           -je 0x402337
    if (cpu.flags.zf)
    {
        goto L_0x00402337;
    }
    // 00402304  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402309  e92b000000             -jmp 0x402339
    goto L_0x00402339;
L_0x0040230e:
    // 0040230e  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402314  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040231b  0f8416000000           -je 0x402337
    if (cpu.flags.zf)
    {
        goto L_0x00402337;
    }
    // 00402321  80b8080500000c         +cmp byte ptr [eax + 0x508], 0xc
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1288) /* 0x508 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(12 /*0xc*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00402328  0f8309000000           -jae 0x402337
    if (!cpu.flags.cf)
    {
        goto L_0x00402337;
    }
    // 0040232e  8d5fed                 -lea ebx, [edi - 0x13]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(-19) /* -0x13 */);
    // 00402331  899920070000           -mov dword ptr [ecx + 0x720], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1824) /* 0x720 */) = cpu.ebx;
L_0x00402337:
    // 00402337  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402339:
    // 00402339  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040233b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040233f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402340  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402341  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402342:
    // 00402342  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402348  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040234f  7524                   -jne 0x402375
    if (!cpu.flags.zf)
    {
        goto L_0x00402375;
    }
    // 00402351  8b15b8eb5600           -mov edx, dword ptr [0x56ebb8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5696440) /* 0x56ebb8 */);
    // 00402357  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040235a  2b4208                 -sub eax, dword ptr [edx + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 0040235d  83f83c                 +cmp eax, 0x3c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402360  7e07                   -jle 0x402369
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402369;
    }
    // 00402362  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 00402367  eb11                   -jmp 0x40237a
    goto L_0x0040237a;
L_0x00402369:
    // 00402369  83f8c4                 +cmp eax, -0x3c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-60 /*-0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040236c  7d07                   -jge 0x402375
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402375;
    }
    // 0040236e  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 00402373  eb05                   -jmp 0x40237a
    goto L_0x0040237a;
L_0x00402375:
    // 00402375  bbc0000000             -mov ebx, 0xc0
    cpu.ebx = 192 /*0xc0*/;
L_0x0040237a:
    // 0040237a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040237c  8b9124060000           -mov edx, dword ptr [ecx + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402382  e899f1ffff             -call 0x401520
    cpu.esp -= 4;
    sub_401520(app, cpu);
    if (cpu.terminate) return;
    // 00402387  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040238c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040238e  8a9910070000           -mov bl, byte ptr [ecx + 0x710]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 00402394  898120070000           -mov dword ptr [ecx + 0x720], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1824) /* 0x720 */) = cpu.eax;
    // 0040239a  80cb40                 -or bl, 0x40
    cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0040239d  889910070000           -mov byte ptr [ecx + 0x710], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.bl;
    // 004023a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004023a5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004023a7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023a8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023a9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023aa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023ab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023ac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004023ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004023ae:
    // 004023ae  80a110070000bf         -and byte ptr [ecx + 0x710], 0xbf
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 004023b5  837e1c02               +cmp dword ptr [esi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004023b9  0f8578ffffff           -jne 0x402337
    if (!cpu.flags.zf)
    {
        goto L_0x00402337;
    }
    // 004023bf  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004023c5  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004023cc  7414                   -je 0x4023e2
    if (cpu.flags.zf)
    {
        goto L_0x004023e2;
    }
    // 004023ce  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004023d5  7507                   -jne 0x4023de
    if (!cpu.flags.zf)
    {
        goto L_0x004023de;
    }
    // 004023d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004023dc  eb16                   -jmp 0x4023f4
    goto L_0x004023f4;
L_0x004023de:
    // 004023de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004023e0  eb12                   -jmp 0x4023f4
    goto L_0x004023f4;
L_0x004023e2:
    // 004023e2  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004023e9  7507                   -jne 0x4023f2
    if (!cpu.flags.zf)
    {
        goto L_0x004023f2;
    }
    // 004023eb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004023f0  eb02                   -jmp 0x4023f4
    goto L_0x004023f4;
L_0x004023f2:
    // 004023f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004023f4:
    // 004023f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004023f6  0f843bffffff           -je 0x402337
    if (cpu.flags.zf)
    {
        goto L_0x00402337;
    }
    // 004023fc  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402401  3b4628                 +cmp eax, dword ptr [esi + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402404  0f8e2dffffff           -jle 0x402337
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402337;
    }
L_0x0040240a:
    // 0040240a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040240f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00402411  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402412  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402413  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402414  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402415  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402416  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402417  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_402420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402420  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402421  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402422  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402423  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402424  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402425  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402427  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040242a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040242c  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00402432  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402434  0f8475010000           -je 0x4025af
    if (cpu.flags.zf)
    {
        goto L_0x004025af;
    }
    // 0040243a  83b8d407000001         +cmp dword ptr [eax + 0x7d4], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2004) /* 0x7d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402441  7553                   -jne 0x402496
    if (!cpu.flags.zf)
    {
        goto L_0x00402496;
    }
    // 00402443  833d68ea560000         +cmp dword ptr [0x56ea68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040244a  7417                   -je 0x402463
    if (cpu.flags.zf)
    {
        goto L_0x00402463;
    }
    // 0040244c  db0560ea5600           +fild dword ptr [0x56ea60]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */))));
    // 00402452  dc0d8c605300           +fmul qword ptr [0x53608c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464204) /* 0x53608c */));
    // 00402458  d998b0070000           +fstp dword ptr [eax + 0x7b0]
    *app->getMemory<float>(cpu.eax + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040245e  e91c010000             -jmp 0x40257f
    goto L_0x0040257f;
L_0x00402463:
    // 00402463  db0560ea5600           +fild dword ptr [0x56ea60]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */))));
    // 00402469  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040246b  dc0d94605300           +fmul qword ptr [0x536094]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464212) /* 0x536094 */));
    // 00402471  8b90c0070000           -mov edx, dword ptr [eax + 0x7c0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1984) /* 0x7c0 */);
    // 00402477  8991b0070000           -mov dword ptr [ecx + 0x7b0], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = cpu.edx;
    // 0040247d  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0040247f  d981b0070000           +fld dword ptr [ecx + 0x7b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */)));
    // 00402485  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00402487  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00402489  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040248b  d999b0070000           +fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402491  e9e9000000             -jmp 0x40257f
    goto L_0x0040257f;
L_0x00402496:
    // 00402496  833d68ea560000         +cmp dword ptr [0x56ea68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040249d  0f846f000000           -je 0x402512
    if (cpu.flags.zf)
    {
        goto L_0x00402512;
    }
    // 004024a3  3b1554ef5600           +cmp edx, dword ptr [0x56ef54]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5697364) /* 0x56ef54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004024a9  750e                   -jne 0x4024b9
    if (!cpu.flags.zf)
    {
        goto L_0x004024b9;
    }
    // 004024ab  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 004024b1  dc0d9c605300           +fmul qword ptr [0x53609c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464220) /* 0x53609c */));
    // 004024b7  eb0c                   -jmp 0x4024c5
    goto L_0x004024c5;
L_0x004024b9:
    // 004024b9  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 004024bf  dc0da4605300           +fmul qword ptr [0x5360a4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464228) /* 0x5360a4 */));
L_0x004024c5:
    // 004024c5  d999b0070000           +fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004024cb  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 004024d1  dc1dac605300           +fcomp qword ptr [0x5360ac]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464236) /* 0x5360ac */));
    cpu.fpu.pop();
    // 004024d7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004024d9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004024da  0f839f000000           -jae 0x40257f
    if (!cpu.flags.cf)
    {
        goto L_0x0040257f;
    }
    // 004024e0  8b1d60ea5600           -mov ebx, dword ptr [0x56ea60]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
    // 004024e6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004024e8  7e04                   -jle 0x4024ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004024ee;
    }
    // 004024ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004024ec  eb04                   -jmp 0x4024f2
    goto L_0x004024f2;
L_0x004024ee:
    // 004024ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004024f0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004024f2:
    // 004024f2  83f807                 +cmp eax, 7
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
    // 004024f5  0f8e84000000           -jle 0x40257f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040257f;
    }
    // 004024fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004024fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004024ff  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00402501  e8ca3a0000             -call 0x405fd0
    cpu.esp -= 4;
    sub_405fd0(app, cpu);
    if (cpu.terminate) return;
    // 00402506  c781b0070000c45a1dc1   -mov dword ptr [ecx + 0x7b0], 0xc11d5ac4
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = 3239926468 /*0xc11d5ac4*/;
    // 00402510  eb6d                   -jmp 0x40257f
    goto L_0x0040257f;
L_0x00402512:
    // 00402512  e859eeffff             -call 0x401370
    cpu.esp -= 4;
    sub_401370(app, cpu);
    if (cpu.terminate) return;
    // 00402517  8b3560ea5600           -mov esi, dword ptr [0x56ea60]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
    // 0040251d  d95dfc                 -fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402520  83fe08                 +cmp esi, 8
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
    // 00402523  7f14                   -jg 0x402539
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402539;
    }
    // 00402525  8b9124060000           -mov edx, dword ptr [ecx + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040252b  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 00402531  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 00402534  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402536  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402537  760b                   -jbe 0x402544
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402544;
    }
L_0x00402539:
    // 00402539  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040253c  8981b0070000           -mov dword ptr [ecx + 0x7b0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = cpu.eax;
    // 00402542  eb3b                   -jmp 0x40257f
    goto L_0x0040257f;
L_0x00402544:
    // 00402544  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00402547  d8a2c4070000           -fsub dword ptr [edx + 0x7c4]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */));
    // 0040254d  db0560ea5600           -fild dword ptr [0x56ea60]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */))));
    // 00402553  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00402555  d80db4605300           -fmul dword ptr [0x5360b4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5464244) /* 0x5360b4 */));
    // 0040255b  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402561  d999b0070000           -fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402567  d980c4070000           -fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 0040256d  dc05bc605300           -fadd qword ptr [0x5360bc]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(x86::reg32(5464252) /* 0x5360bc */));
    // 00402573  d881b0070000           -fadd dword ptr [ecx + 0x7b0]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */));
    // 00402579  d999b0070000           -fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040257f:
    // 0040257f  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402586  740f                   -je 0x402597
    if (cpu.flags.zf)
    {
        goto L_0x00402597;
    }
    // 00402588  8aa1b3070000           -mov ah, byte ptr [ecx + 0x7b3]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */);
    // 0040258e  80f480                 -xor ah, 0x80
    cpu.ah ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00402591  88a1b3070000           -mov byte ptr [ecx + 0x7b3], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */) = cpu.ah;
L_0x00402597:
    // 00402597  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040259e  740f                   -je 0x4025af
    if (cpu.flags.zf)
    {
        goto L_0x004025af;
    }
    // 004025a0  8ab1b3070000           -mov dh, byte ptr [ecx + 0x7b3]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */);
    // 004025a6  80f680                 -xor dh, 0x80
    cpu.dh ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004025a9  88b1b3070000           -mov byte ptr [ecx + 0x7b3], dh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */) = cpu.dh;
L_0x004025af:
    // 004025af  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004025b1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004025b2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004025b3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004025b4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004025b5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004025b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4025c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004025c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004025c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004025c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004025c3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004025c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004025c6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004025c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004025cb  8b8024060000           -mov eax, dword ptr [eax + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 004025d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004025d3  0f8453010000           -je 0x40272c
    if (cpu.flags.zf)
    {
        goto L_0x0040272c;
    }
    // 004025d9  8b1560ea5600           -mov edx, dword ptr [0x56ea60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
    // 004025df  8b9928060000           -mov ebx, dword ptr [ecx + 0x628]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 004025e5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004025e7  7f02                   -jg 0x4025eb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004025eb;
    }
    // 004025e9  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x004025eb:
    // 004025eb  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004025f2  7409                   -je 0x4025fd
    if (cpu.flags.zf)
    {
        goto L_0x004025fd;
    }
    // 004025f4  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004025fb  742d                   -je 0x40262a
    if (cpu.flags.zf)
    {
        goto L_0x0040262a;
    }
L_0x004025fd:
    // 004025fd  f6811107000001         +test byte ptr [ecx + 0x711], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) & 1 /*0x1*/));
    // 00402604  7411                   -je 0x402617
    if (cpu.flags.zf)
    {
        goto L_0x00402617;
    }
    // 00402606  8b80c8020000           -mov eax, dword ptr [eax + 0x2c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 0040260c  c1e004                 +shl eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0040260f  8b80b0215500           -mov eax, dword ptr [eax + 0x5521b0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5579184) /* 0x5521b0 */);
    // 00402615  eb0f                   -jmp 0x402626
    goto L_0x00402626;
L_0x00402617:
    // 00402617  8b80c8020000           -mov eax, dword ptr [eax + 0x2c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */);
    // 0040261d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00402620  8b80ac215500           -mov eax, dword ptr [eax + 0x5521ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5579180) /* 0x5521ac */);
L_0x00402626:
    // 00402626  39c2                   +cmp edx, eax
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
    // 00402628  762b                   -jbe 0x402655
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402655;
    }
L_0x0040262a:
    // 0040262a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040262c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00402631  e84af4ffff             -call 0x401a80
    cpu.esp -= 4;
    sub_401a80(app, cpu);
    if (cpu.terminate) return;
    // 00402636  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00402638  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040263a  e891390000             -call 0x405fd0
    cpu.esp -= 4;
    sub_405fd0(app, cpu);
    if (cpu.terminate) return;
    // 0040263f  8aa121060000           -mov ah, byte ptr [ecx + 0x621]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 00402645  80cc10                 +or ah, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00402648  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040264a  88a121060000           -mov byte ptr [ecx + 0x621], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) = cpu.ah;
    // 00402650  e9d9000000             -jmp 0x40272e
    goto L_0x0040272e;
L_0x00402655:
    // 00402655  837b1c02               +cmp dword ptr [ebx + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402659  7405                   -je 0x402660
    if (cpu.flags.zf)
    {
        goto L_0x00402660;
    }
    // 0040265b  83fa0f                 +cmp edx, 0xf
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040265e  7f0c                   -jg 0x40266c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040266c;
    }
L_0x00402660:
    // 00402660  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402662  e8b9fdffff             -call 0x402420
    cpu.esp -= 4;
    sub_402420(app, cpu);
    if (cpu.terminate) return;
    // 00402667  e9ce000000             -jmp 0x40273a
    goto L_0x0040273a;
L_0x0040266c:
    // 0040266c  833d68ea560000         +cmp dword ptr [0x56ea68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402673  7421                   -je 0x402696
    if (cpu.flags.zf)
    {
        goto L_0x00402696;
    }
    // 00402675  833d5cea560000         +cmp dword ptr [0x56ea5c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696092) /* 0x56ea5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040267c  740c                   -je 0x40268a
    if (cpu.flags.zf)
    {
        goto L_0x0040268a;
    }
    // 0040267e  80892106000010         +or byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00402685  e9a2000000             -jmp 0x40272c
    goto L_0x0040272c;
L_0x0040268a:
    // 0040268a  80a121060000ef         +and byte ptr [ecx + 0x621], 0xef
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 00402691  e996000000             -jmp 0x40272c
    goto L_0x0040272c;
L_0x00402696:
    // 00402696  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402698  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040269d  e8ceecffff             -call 0x401370
    cpu.esp -= 4;
    sub_401370(app, cpu);
    if (cpu.terminate) return;
    // 004026a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004026a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004026a6  d999b0070000           -fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004026ac  e81f390000             -call 0x405fd0
    cpu.esp -= 4;
    sub_405fd0(app, cpu);
    if (cpu.terminate) return;
    // 004026b1  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004026b8  740f                   -je 0x4026c9
    if (cpu.flags.zf)
    {
        goto L_0x004026c9;
    }
    // 004026ba  8a99b3070000           -mov bl, byte ptr [ecx + 0x7b3]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */);
    // 004026c0  80f380                 -xor bl, 0x80
    cpu.bl ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004026c3  8899b3070000           -mov byte ptr [ecx + 0x7b3], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */) = cpu.bl;
L_0x004026c9:
    // 004026c9  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 004026d0  740e                   -je 0x4026e0
    if (cpu.flags.zf)
    {
        goto L_0x004026e0;
    }
    // 004026d2  8a81b3070000           -mov al, byte ptr [ecx + 0x7b3]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */);
    // 004026d8  3480                   -xor al, 0x80
    cpu.al ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004026da  8881b3070000           -mov byte ptr [ecx + 0x7b3], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1971) /* 0x7b3 */) = cpu.al;
L_0x004026e0:
    // 004026e0  833dc8d46f0000         +cmp dword ptr [0x6fd4c8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328968) /* 0x6fd4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004026e7  7451                   -je 0x40273a
    if (cpu.flags.zf)
    {
        goto L_0x0040273a;
    }
    // 004026e9  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004026ef  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004026f6  7507                   -jne 0x4026ff
    if (!cpu.flags.zf)
    {
        goto L_0x004026ff;
    }
    // 004026f8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004026fa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004026fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004026ff:
    // 004026ff  83b86006000000         +cmp dword ptr [eax + 0x660], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402706  7407                   -je 0x40270f
    if (cpu.flags.zf)
    {
        goto L_0x0040270f;
    }
    // 00402708  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040270a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040270b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040270c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040270d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040270e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040270f:
    // 0040270f  d981b0070000           -fld dword ptr [ecx + 0x7b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */)));
    // 00402715  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00402717  dc0dc4605300           -fmul qword ptr [0x5360c4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464260) /* 0x5360c4 */));
    // 0040271d  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040271f  d999b0070000           -fstp dword ptr [ecx + 0x7b0]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402725  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00402727  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402728  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402729  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040272a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040272b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040272c:
    // 0040272c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_0x0040272e:
    // 0040272e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402730  68ec51983f             -push 0x3f9851ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1066947052 /*0x3f9851ec*/;
    cpu.esp -= 4;
    // 00402735  e8f6ecffff             -call 0x401430
    cpu.esp -= 4;
    sub_401430(app, cpu);
    if (cpu.terminate) return;
L_0x0040273a:
    // 0040273a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040273c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040273d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040273e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040273f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402740  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_402750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402750  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402751  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402752  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402753  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402754  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402755  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402756  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402758  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040275a  8b8824060000           -mov ecx, dword ptr [eax + 0x624]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00402760  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00402762  0f8462010000           -je 0x4028ca
    if (cpu.flags.zf)
    {
        goto L_0x004028ca;
    }
    // 00402768  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040276e  8b9828060000           -mov ebx, dword ptr [eax + 0x628]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00402774  dc1dcc605300           +fcomp qword ptr [0x5360cc]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464268) /* 0x5360cc */));
    cpu.fpu.pop();
    // 0040277a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040277c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040277d  7310                   -jae 0x40278f
    if (!cpu.flags.cf)
    {
        goto L_0x0040278f;
    }
    // 0040277f  83bad407000000         +cmp dword ptr [edx + 0x7d4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2004) /* 0x7d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402786  7507                   -jne 0x40278f
    if (!cpu.flags.zf)
    {
        goto L_0x0040278f;
    }
    // 00402788  808a1107000002         -or byte ptr [edx + 0x711], 2
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0040278f:
    // 0040278f  833d68ea560000         +cmp dword ptr [0x56ea68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696104) /* 0x56ea68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402796  7412                   -je 0x4027aa
    if (cpu.flags.zf)
    {
        goto L_0x004027aa;
    }
    // 00402798  a164ea5600             -mov eax, dword ptr [0x56ea64]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */);
    // 0040279d  8304852cef56000a       +add dword ptr [eax*4 + 0x56ef2c], 0xa
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004027a5  e920010000             -jmp 0x4028ca
    goto L_0x004028ca;
L_0x004027aa:
    // 004027aa  833d60ea560000         +cmp dword ptr [0x56ea60], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004027b1  750e                   -jne 0x4027c1
    if (!cpu.flags.zf)
    {
        goto L_0x004027c1;
    }
    // 004027b3  808a1107000002         +or byte ptr [edx + 0x711], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004027ba  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027bb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027bc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027bd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027be  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027bf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004027c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004027c1:
    // 004027c1  8b8224060000           -mov eax, dword ptr [edx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
    // 004027c7  d980c0070000           +fld dword ptr [eax + 0x7c0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1984) /* 0x7c0 */)));
    // 004027cd  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004027cf  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004027d1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004027d3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004027d4  7607                   -jbe 0x4027dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004027dd;
    }
    // 004027d6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004027db  eb02                   -jmp 0x4027df
    goto L_0x004027df;
L_0x004027dd:
    // 004027dd  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x004027df:
    // 004027df  d982c0070000           +fld dword ptr [edx + 0x7c0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    // 004027e5  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004027e7  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004027e9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004027eb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004027ec  7607                   -jbe 0x4027f5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004027f5;
    }
    // 004027ee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004027f3  eb02                   -jmp 0x4027f7
    goto L_0x004027f7;
L_0x004027f5:
    // 004027f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004027f7:
    // 004027f7  31c8                   +xor eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004027f9  7414                   -je 0x40280f
    if (cpu.flags.zf)
    {
        goto L_0x0040280f;
    }
    // 004027fb  a164ea5600             -mov eax, dword ptr [0x56ea64]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */);
    // 00402800  830485d8ee560046       -add dword ptr [eax*4 + 0x56eed8], 0x46
    (*app->getMemory<x86::reg32>(x86::reg32(5697240) /* 0x56eed8 */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(70 /*0x46*/));
    // 00402808  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402809  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040280a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040280b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040280c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040280d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040280e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040280f:
    // 0040280f  833d60ea560005         +cmp dword ptr [0x56ea60], 5
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696096) /* 0x56ea60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402816  7f06                   -jg 0x40281e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040281e;
    }
    // 00402818  837b1c02               +cmp dword ptr [ebx + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040281c  7514                   -jne 0x402832
    if (!cpu.flags.zf)
    {
        goto L_0x00402832;
    }
L_0x0040281e:
    // 0040281e  a164ea5600             -mov eax, dword ptr [0x56ea64]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */);
    // 00402823  8304852cef56000a       -add dword ptr [eax*4 + 0x56ef2c], 0xa
    (*app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0040282b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040282c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040282d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040282e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040282f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402830  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402831  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402832:
    // 00402832  a164ea5600             -mov eax, dword ptr [0x56ea64]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5696100) /* 0x56ea64 */);
    // 00402837  83f801                 +cmp eax, 1
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
    // 0040283a  720e                   -jb 0x40284a
    if (cpu.flags.cf)
    {
        goto L_0x0040284a;
    }
    // 0040283c  763c                   -jbe 0x40287a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040287a;
    }
    // 0040283e  83f802                 +cmp eax, 2
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
    // 00402841  7469                   -je 0x4028ac
    if (cpu.flags.zf)
    {
        goto L_0x004028ac;
    }
    // 00402843  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402844  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402845  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402846  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402847  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402848  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402849  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040284a:
    // 0040284a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040284c  7407                   -je 0x402855
    if (cpu.flags.zf)
    {
        goto L_0x00402855;
    }
    // 0040284e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040284f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402850  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402851  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402852  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402853  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402854  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402855:
    // 00402855  8b1d30ef5600           -mov ebx, dword ptr [0x56ef30]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */);
    // 0040285b  8b0d2cef5600           -mov ecx, dword ptr [0x56ef2c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */);
    // 00402861  83c31e                 -add ebx, 0x1e
    (cpu.ebx) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00402864  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00402867  891d30ef5600           -mov dword ptr [0x56ef30], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */) = cpu.ebx;
    // 0040286d  890d2cef5600           -mov dword ptr [0x56ef2c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */) = cpu.ecx;
    // 00402873  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402874  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402875  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402876  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402877  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402878  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402879  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040287a:
    // 0040287a  8b3d30ef5600           -mov edi, dword ptr [0x56ef30]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */);
    // 00402880  a134ef5600             -mov eax, dword ptr [0x56ef34]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5697332) /* 0x56ef34 */);
    // 00402885  8b352cef5600           -mov esi, dword ptr [0x56ef2c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */);
    // 0040288b  83c70a                 -add edi, 0xa
    (cpu.edi) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 0040288e  83c01e                 -add eax, 0x1e
    (cpu.eax) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00402891  83c61e                 -add esi, 0x1e
    (cpu.esi) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 00402894  893d30ef5600           -mov dword ptr [0x56ef30], edi
    *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */) = cpu.edi;
    // 0040289a  a334ef5600             -mov dword ptr [0x56ef34], eax
    *app->getMemory<x86::reg32>(x86::reg32(5697332) /* 0x56ef34 */) = cpu.eax;
    // 0040289f  89352cef5600           -mov dword ptr [0x56ef2c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5697324) /* 0x56ef2c */) = cpu.esi;
    // 004028a5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028a6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028a7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028a8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028a9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028aa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004028ac:
    // 004028ac  8b0d34ef5600           -mov ecx, dword ptr [0x56ef34]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5697332) /* 0x56ef34 */);
    // 004028b2  8b1530ef5600           -mov edx, dword ptr [0x56ef30]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */);
    // 004028b8  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004028bb  83c21e                 -add edx, 0x1e
    (cpu.edx) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 004028be  890d34ef5600           -mov dword ptr [0x56ef34], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5697332) /* 0x56ef34 */) = cpu.ecx;
    // 004028c4  891530ef5600           -mov dword ptr [0x56ef30], edx
    *app->getMemory<x86::reg32>(x86::reg32(5697328) /* 0x56ef30 */) = cpu.edx;
L_0x004028ca:
    // 004028ca  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028cb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028cc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028cd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028ce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028cf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4028e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004028e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004028e1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004028e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004028e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004028e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004028e8  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004028eb  e830b80000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004028f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004028f2  7c0a                   -jl 0x4028fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004028fe;
    }
    // 004028f4  80a121060000ef         -and byte ptr [ecx + 0x621], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004028fb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028fc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004028fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004028fe:
    // 004028fe  80892106000010         -or byte ptr [ecx + 0x621], 0x10
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00402905  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402906  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402907  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_402910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402910  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402911  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402912  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402913  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402914  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402916  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402918  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 0040291e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00402920  0f8494000000           -je 0x4029ba
    if (cpu.flags.zf)
    {
        goto L_0x004029ba;
    }
    // 00402926  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040292c  dc1dd4605300           +fcomp qword ptr [0x5360d4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464276) /* 0x5360d4 */));
    cpu.fpu.pop();
    // 00402932  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402934  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402935  0f827f000000           -jb 0x4029ba
    if (cpu.flags.cf)
    {
        goto L_0x004029ba;
    }
    // 0040293b  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00402941  d980c0070000           +fld dword ptr [eax + 0x7c0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1984) /* 0x7c0 */)));
    // 00402947  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00402949  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040294b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040294d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040294e  7607                   -jbe 0x402957
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402957;
    }
    // 00402950  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00402955  eb02                   -jmp 0x402959
    goto L_0x00402959;
L_0x00402957:
    // 00402957  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
L_0x00402959:
    // 00402959  d981c0070000           +fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040295f  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00402961  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00402963  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402965  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402966  7607                   -jbe 0x40296f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040296f;
    }
    // 00402968  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040296d  eb02                   -jmp 0x402971
    goto L_0x00402971;
L_0x0040296f:
    // 0040296f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402971:
    // 00402971  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00402973  7445                   -je 0x4029ba
    if (cpu.flags.zf)
    {
        goto L_0x004029ba;
    }
    // 00402975  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040297b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040297e  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00402981  e89ab70000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00402986  8b1dc0d46f00           -mov ebx, dword ptr [0x6fd4c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 0040298c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040298e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00402990  7402                   -je 0x402994
    if (cpu.flags.zf)
    {
        goto L_0x00402994;
    }
    // 00402992  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00402994:
    // 00402994  833d5cea560000         +cmp dword ptr [0x56ea5c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5696092) /* 0x56ea5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040299b  7411                   -je 0x4029ae
    if (cpu.flags.zf)
    {
        goto L_0x004029ae;
    }
    // 0040299d  83fa0c                 +cmp edx, 0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004029a0  7d18                   -jge 0x4029ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004029ba;
    }
    // 004029a2  80a121060000ef         -and byte ptr [ecx + 0x621], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004029a9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029aa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029ab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029ac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004029ae:
    // 004029ae  83faf4                 +cmp edx, -0xc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-12 /*-0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004029b1  7e07                   -jle 0x4029ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004029ba;
    }
    // 004029b3  80892106000010         -or byte ptr [ecx + 0x621], 0x10
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004029ba:
    // 004029ba  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029bb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029bd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4029c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004029c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004029c1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004029c2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004029c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004029c5  80a021060000ef         -and byte ptr [eax + 0x621], 0xef
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004029cc  8b159cfd5e00           -mov edx, dword ptr [0x5efd9c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */);
L_0x004029d2:
    // 004029d2  4a                     -dec edx
    (cpu.edx)--;
    // 004029d3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004029d5  7c16                   -jl 0x4029ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004029ed;
    }
    // 004029d7  8b0c95c8fc5e00         -mov ecx, dword ptr [edx*4 + 0x5efcc8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6225096) /* 0x5efcc8 */ + cpu.edx * 4);
    // 004029de  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004029e5  74eb                   -je 0x4029d2
    if (cpu.flags.zf)
    {
        goto L_0x004029d2;
    }
    // 004029e7  8988d8060000           -mov dword ptr [eax + 0x6d8], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1752) /* 0x6d8 */) = cpu.ecx;
L_0x004029ed:
    // 004029ed  e80e000000             -call 0x402a00
    cpu.esp -= 4;
    sub_402a00(app, cpu);
    if (cpu.terminate) return;
    // 004029f2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029f3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029f4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004029f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_402a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402a00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402a01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402a02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402a03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402a04  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402a05  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402a06  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402a08  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00402a0b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402a0d  8b80ac070000           -mov eax, dword ptr [eax + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 00402a13  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00402a15  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00402a18:
    // 00402a18  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402a1a  89411c                 -mov dword ptr [ecx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00402a1d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00402a1f  e85c320000             -call 0x405c80
    cpu.esp -= 4;
    sub_405c80(app, cpu);
    if (cpu.terminate) return;
    // 00402a24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402a26  740e                   -je 0x402a36
    if (cpu.flags.zf)
    {
        goto L_0x00402a36;
    }
    // 00402a28  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00402a2d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402a2f  e82cb70000             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 00402a34  ebe2                   -jmp 0x402a18
    goto L_0x00402a18;
L_0x00402a36:
    // 00402a36  833d28f2560000         +cmp dword ptr [0x56f228], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5698088) /* 0x56f228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402a3d  7407                   -je 0x402a46
    if (cpu.flags.zf)
    {
        goto L_0x00402a46;
    }
    // 00402a3f  80a121060000ef         -and byte ptr [ecx + 0x621], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00402a46:
    // 00402a46  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 00402a4d  7507                   -jne 0x402a56
    if (!cpu.flags.zf)
    {
        goto L_0x00402a56;
    }
    // 00402a4f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402a54  eb02                   -jmp 0x402a58
    goto L_0x00402a58;
L_0x00402a56:
    // 00402a56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402a58:
    // 00402a58  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 00402a5e  7409                   -je 0x402a69
    if (cpu.flags.zf)
    {
        goto L_0x00402a69;
    }
    // 00402a60  833d30f2560001         +cmp dword ptr [0x56f230], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402a67  7427                   -je 0x402a90
    if (cpu.flags.zf)
    {
        goto L_0x00402a90;
    }
L_0x00402a69:
    // 00402a69  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 00402a70  7407                   -je 0x402a79
    if (cpu.flags.zf)
    {
        goto L_0x00402a79;
    }
    // 00402a72  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402a77  eb02                   -jmp 0x402a7b
    goto L_0x00402a7b;
L_0x00402a79:
    // 00402a79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00402a7b:
    // 00402a7b  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 00402a81  0f8484000000           -je 0x402b0b
    if (cpu.flags.zf)
    {
        goto L_0x00402b0b;
    }
    // 00402a87  833d30f25600ff         +cmp dword ptr [0x56f230], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402a8e  757b                   -jne 0x402b0b
    if (!cpu.flags.zf)
    {
        goto L_0x00402b0b;
    }
L_0x00402a90:
    // 00402a90  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00402a97  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402a99  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00402a9e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00402aa1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402aa3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402aa5  8a421b                 -mov al, byte ptr [edx + 0x1b]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(27) /* 0x1b */);
    // 00402aa8  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00402aab  8b3d184f5500           -mov edi, dword ptr [0x554f18]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 00402ab1  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00402ab4  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 00402ab9  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00402abc  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00402abf  dc0ddc605300           -fmul qword ptr [0x5360dc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464284) /* 0x5360dc */));
    // 00402ac5  a3144f5500             -mov dword ptr [0x554f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 00402aca  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00402acf  8b1d144f5500           -mov ebx, dword ptr [0x554f14]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 00402ad5  a3104f5500             -mov dword ptr [0x554f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 00402ada  81e300ffff00           -and ebx, 0xffff00
    cpu.ebx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 00402ae0  8a4213                 -mov al, byte ptr [edx + 0x13]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00402ae3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00402ae6  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00402ae8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00402aed  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00402af0  c1e810                 +shr eax, 0x10
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
    // 00402af3  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00402af4  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00402af7  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00402afa  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 00402afc  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00402afe  dc0de4605300           +fmul qword ptr [0x5360e4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464292) /* 0x5360e4 */));
    // 00402b04  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00402b06  e97e000000             -jmp 0x402b89
    goto L_0x00402b89;
L_0x00402b0b:
    // 00402b0b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00402b12  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00402b14  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00402b1a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00402b1d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00402b1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402b21  8a4217                 -mov al, byte ptr [edx + 0x17]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(23) /* 0x17 */);
    // 00402b24  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00402b27  8b1d184f5500           -mov ebx, dword ptr [0x554f18]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 00402b2d  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00402b30  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 00402b35  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00402b38  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00402b3b  dc0ddc605300           -fmul qword ptr [0x5360dc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464284) /* 0x5360dc */));
    // 00402b41  a3144f5500             -mov dword ptr [0x554f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 00402b46  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00402b4b  a3104f5500             -mov dword ptr [0x554f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 00402b50  a1144f5500             -mov eax, dword ptr [0x554f14]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 00402b55  2500ffff00             -and eax, 0xffff00
    cpu.eax &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 00402b5a  8a5213                 -mov dl, byte ptr [edx + 0x13]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 00402b5d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00402b60  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00402b66  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00402b69  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00402b6c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00402b6f  c1e810                 +shr eax, 0x10
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
    // 00402b72  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00402b73  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00402b75  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00402b78  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00402b7a  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00402b7d  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00402b7f  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00402b81  dc0de4605300           +fmul qword ptr [0x5360e4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464292) /* 0x5360e4 */));
    // 00402b87  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
L_0x00402b89:
    // 00402b89  d999b4070000           +fstp dword ptr [ecx + 0x7b4]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402b8f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402b91  c781540600000000803f   -mov dword ptr [ecx + 0x654], 0x3f800000
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1620) /* 0x654 */) = 1065353216 /*0x3f800000*/;
    // 00402b9b  68ec51983f             -push 0x3f9851ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1066947052 /*0x3f9851ec*/;
    cpu.esp -= 4;
    // 00402ba0  d98154060000           +fld dword ptr [ecx + 0x654]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1620) /* 0x654 */)));
    // 00402ba6  d881b4070000           +fadd dword ptr [ecx + 0x7b4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1972) /* 0x7b4 */));
    // 00402bac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402bae  d999b4070000           +fstp dword ptr [ecx + 0x7b4]
    *app->getMemory<float>(cpu.ecx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00402bb4  e877e8ffff             -call 0x401430
    cpu.esp -= 4;
    sub_401430(app, cpu);
    if (cpu.terminate) return;
    // 00402bb9  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00402bbb  8b81b0070000           -mov eax, dword ptr [ecx + 0x7b0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */);
    // 00402bc1  8981c0070000           -mov dword ptr [ecx + 0x7c0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */) = cpu.eax;
    // 00402bc7  d899c0070000           +fcomp dword ptr [ecx + 0x7c0]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */));
    cpu.fpu.pop();
    // 00402bcd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402bcf  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402bd0  730b                   -jae 0x402bdd
    if (!cpu.flags.cf)
    {
        goto L_0x00402bdd;
    }
    // 00402bd2  8b81c0070000           -mov eax, dword ptr [ecx + 0x7c0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */);
    // 00402bd8  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00402bdb  eb0b                   -jmp 0x402be8
    goto L_0x00402be8;
L_0x00402bdd:
    // 00402bdd  d981c0070000           -fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 00402be3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00402be5  d95df8                 -fstp dword ptr [ebp - 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00402be8:
    // 00402be8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00402beb  8981c4070000           -mov dword ptr [ecx + 0x7c4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */) = cpu.eax;
    // 00402bf1  8a8110070000           -mov al, byte ptr [ecx + 0x710]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 00402bf7  c7812406000000000000   -mov dword ptr [ecx + 0x624], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 00402c01  24ef                   -and al, 0xef
    cpu.al &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00402c03  888110070000           -mov byte ptr [ecx + 0x710], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.al;
    // 00402c09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402c0b  c7813407000000000000   -mov dword ptr [ecx + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 00402c15  e866a10000             -call 0x40cd80
    cpu.esp -= 4;
    sub_40cd80(app, cpu);
    if (cpu.terminate) return;
    // 00402c1a  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 00402c1f  8b35184f5500           -mov esi, dword ptr [0x554f18]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 00402c25  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00402c28  a3144f5500             -mov dword ptr [0x554f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 00402c2d  8b15144f5500           -mov edx, dword ptr [0x554f14]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 00402c33  81e200ffff00           -and edx, 0xffff00
    cpu.edx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 00402c39  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00402c3e  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00402c41  a3104f5500             -mov dword ptr [0x554f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 00402c46  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00402c4d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00402c4f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00402c52  89811c070000           -mov dword ptr [ecx + 0x71c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1820) /* 0x71c */) = cpu.eax;
    // 00402c58  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00402c5a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c5f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_402c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402c70  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402c71  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402c73  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402c78  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402c79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_402c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402c80  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402c81  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402c82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402c84  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402c86  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00402c88  d8980c010000           +fcomp dword ptr [eax + 0x10c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.eax + x86::reg32(268) /* 0x10c */));
    cpu.fpu.pop();
    // 00402c8e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402c90  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402c91  7612                   -jbe 0x402ca5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402ca5;
    }
    // 00402c93  6683ba6401000000       +cmp word ptr [edx + 0x164], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00402c9b  7508                   -jne 0x402ca5
    if (!cpu.flags.zf)
    {
        goto L_0x00402ca5;
    }
    // 00402c9d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402ca2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ca3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ca4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402ca5:
    // 00402ca5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402ca7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ca8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ca9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_402cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402cb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402cb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402cb2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402cb3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402cb5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402cb7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00402cb9  f6820002000001         +test byte ptr [edx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00402cc0  0f84bf000000           -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402cc6  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00402ccd  0f85b2000000           -jne 0x402d85
    if (!cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402cd3  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 00402cd9  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00402cdb  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00402cdd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402cdf  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402ce0  771b                   -ja 0x402cfd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00402cfd;
    }
    // 00402ce2  d983c4070000           +fld dword ptr [ebx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx + x86::reg32(1988) /* 0x7c4 */)));
    // 00402ce8  d8b1c4070000           +fdiv dword ptr [ecx + 0x7c4]
    cpu.fpu.st(0) /= x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */));
    // 00402cee  dc1dec605300           +fcomp qword ptr [0x5360ec]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464300) /* 0x5360ec */));
    cpu.fpu.pop();
    // 00402cf4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00402cf6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00402cf7  0f8688000000           -jbe 0x402d85
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
L_0x00402cfd:
    // 00402cfd  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402d02  3b8334060000           +cmp eax, dword ptr [ebx + 0x634]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1588) /* 0x634 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d08  0f8e77000000           -jle 0x402d85
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402d85;
    }
    // 00402d0e  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d15  744c                   -je 0x402d63
    if (cpu.flags.zf)
    {
        goto L_0x00402d63;
    }
    // 00402d17  8b8128060000           -mov eax, dword ptr [ecx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00402d1d  83781c02               +cmp dword ptr [eax + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d21  750f                   -jne 0x402d32
    if (!cpu.flags.zf)
    {
        goto L_0x00402d32;
    }
    // 00402d23  83b90c07000006         +cmp dword ptr [ecx + 0x70c], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d2a  7459                   -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402d2c  83782c00               +cmp dword ptr [eax + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d30  7453                   -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
L_0x00402d32:
    // 00402d32  3b9924060000           +cmp ebx, dword ptr [ecx + 0x624]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402d38  744b                   -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402d3a  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00402d41  7442                   -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402d43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402d45  e836edffff             -call 0x401a80
    cpu.esp -= 4;
    sub_401a80(app, cpu);
    if (cpu.terminate) return;
    // 00402d4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402d4c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00402d4e  e8fde5ffff             -call 0x401350
    cpu.esp -= 4;
    sub_401350(app, cpu);
    if (cpu.terminate) return;
    // 00402d53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402d58  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402d5a  e851ebffff             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
    // 00402d5f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d60  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d61  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402d63:
    // 00402d63  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00402d65  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402d67  e814120000             -call 0x403f80
    cpu.esp -= 4;
    sub_403f80(app, cpu);
    if (cpu.terminate) return;
    // 00402d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402d6e  7415                   -je 0x402d85
    if (cpu.flags.zf)
    {
        goto L_0x00402d85;
    }
    // 00402d70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402d72  e8d9e5ffff             -call 0x401350
    cpu.esp -= 4;
    sub_401350(app, cpu);
    if (cpu.terminate) return;
    // 00402d77  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00402d79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402d7e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402d80  e82bebffff             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
L_0x00402d85:
    // 00402d85  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d86  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d87  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402d88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_402d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402d90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402d91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402d92  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402d93  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402d94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402d96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402d98  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00402d9b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00402da2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402da4  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00402daa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00402dad  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402daf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402db1  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 00402db4  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00402db7  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00402dbc  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00402dbf  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402dc1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402dc3  8b9a38060000           -mov ebx, dword ptr [edx + 0x638]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 00402dc9  39d9                   +cmp ecx, ebx
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
    // 00402dcb  7f11                   -jg 0x402dde
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402dde;
    }
    // 00402dcd  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 00402dd0  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00402dd2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00402dd7  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00402dda  39d8                   +cmp eax, ebx
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
    // 00402ddc  7d0c                   -jge 0x402dea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402dea;
    }
L_0x00402dde:
    // 00402dde  8305b8ee560064         -add dword ptr [0x56eeb8], 0x64
    (*app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00402de5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402de6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402de7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402de8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402de9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402dea:
    // 00402dea  83fb07                 +cmp ebx, 7
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
    // 00402ded  7d0c                   -jge 0x402dfb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402dfb;
    }
    // 00402def  8305b4ee560064         -add dword ptr [0x56eeb4], 0x64
    (*app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00402df6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402df7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402df8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402df9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402dfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402dfb:
    // 00402dfb  8305bcee560064         -add dword ptr [0x56eebc], 0x64
    (*app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00402e02  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e03  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e04  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e05  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402e06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_402e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402e10  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402e11  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402e12  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402e13  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00402e14  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00402e15  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402e16  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402e18  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00402e1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00402e1d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00402e20  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00402e22  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00402e24  8975f8                 -mov dword ptr [ebp - 8], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00402e27  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00402e2a:
    // 00402e2a  3b3da0fd5e00           +cmp edi, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402e30  0f8d7b000000           -jge 0x402eb1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402eb1;
    }
    // 00402e36  8b1cbd48fc5e00         -mov ebx, dword ptr [edi*4 + 0x5efc48]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.edi * 4);
    // 00402e3d  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402e42  3b8334060000           +cmp eax, dword ptr [ebx + 0x634]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1588) /* 0x634 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402e48  0f8e5d000000           -jle 0x402eab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402eab;
    }
    // 00402e4e  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00402e55  7409                   -je 0x402e60
    if (cpu.flags.zf)
    {
        goto L_0x00402e60;
    }
    // 00402e57  83bbc402000003         +cmp dword ptr [ebx + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402e5e  744b                   -je 0x402eab
    if (cpu.flags.zf)
    {
        goto L_0x00402eab;
    }
L_0x00402e60:
    // 00402e60  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00402e67  7409                   -je 0x402e72
    if (cpu.flags.zf)
    {
        goto L_0x00402e72;
    }
    // 00402e69  83bbc402000004         +cmp dword ptr [ebx + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402e70  7439                   -je 0x402eab
    if (cpu.flags.zf)
    {
        goto L_0x00402eab;
    }
L_0x00402e72:
    // 00402e72  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00402e75  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00402e78  e8a3b20000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00402e7d  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00402e80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00402e82  7f02                   -jg 0x402e86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402e86;
    }
    // 00402e84  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00402e86:
    // 00402e86  83f80f                 +cmp eax, 0xf
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
    // 00402e89  7f20                   -jg 0x402eab
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402eab;
    }
    // 00402e8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00402e8d  e81ee6ffff             -call 0x4014b0
    cpu.esp -= 4;
    sub_4014b0(app, cpu);
    if (cpu.terminate) return;
    // 00402e92  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00402e94  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00402e96  e8e5100000             -call 0x403f80
    cpu.esp -= 4;
    sub_403f80(app, cpu);
    if (cpu.terminate) return;
    // 00402e9b  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402e9e  7e0b                   -jle 0x402eab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402eab;
    }
    // 00402ea0  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00402ea3  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00402ea6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00402ea8  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x00402eab:
    // 00402eab  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00402eac  e979ffffff             -jmp 0x402e2a
    goto L_0x00402e2a;
L_0x00402eb1:
    // 00402eb1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00402eb3  0f849f000000           -je 0x402f58
    if (cpu.flags.zf)
    {
        goto L_0x00402f58;
    }
    // 00402eb9  8b9914070000           -mov ebx, dword ptr [ecx + 0x714]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1812) /* 0x714 */);
    // 00402ebf  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00402ec6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00402ec8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00402ecb  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402ed2  750d                   -jne 0x402ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00402ee1;
    }
    // 00402ed4  f6811107000004         +test byte ptr [ecx + 0x711], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) & 4 /*0x4*/));
    // 00402edb  0f8468000000           -je 0x402f49
    if (cpu.flags.zf)
    {
        goto L_0x00402f49;
    }
L_0x00402ee1:
    // 00402ee1  83b92c07000000         +cmp dword ptr [ecx + 0x72c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1836) /* 0x72c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402ee8  750b                   -jne 0x402ef5
    if (!cpu.flags.zf)
    {
        goto L_0x00402ef5;
    }
    // 00402eea  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402eef  89812c070000           -mov dword ptr [ecx + 0x72c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1836) /* 0x72c */) = cpu.eax;
L_0x00402ef5:
    // 00402ef5  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402efa  2b812c070000           -sub eax, dword ptr [ecx + 0x72c]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1836) /* 0x72c */)));
    // 00402f00  3dc0030000             +cmp eax, 0x3c0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(960 /*0x3c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f05  7f42                   -jg 0x402f49
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402f49;
    }
    // 00402f07  3bb130070000           +cmp esi, dword ptr [ecx + 0x730]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1840) /* 0x730 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f0d  7555                   -jne 0x402f64
    if (!cpu.flags.zf)
    {
        goto L_0x00402f64;
    }
    // 00402f0f  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00402f12  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00402f14  7e04                   -jle 0x402f1a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402f1a;
    }
    // 00402f16  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00402f18  eb04                   -jmp 0x402f1e
    goto L_0x00402f1e;
L_0x00402f1a:
    // 00402f1a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00402f1c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00402f1e:
    // 00402f1e  83f805                 +cmp eax, 5
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
    // 00402f21  7d41                   -jge 0x402f64
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00402f64;
    }
    // 00402f23  83b92807000000         +cmp dword ptr [ecx + 0x728], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1832) /* 0x728 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00402f2a  750b                   -jne 0x402f37
    if (!cpu.flags.zf)
    {
        goto L_0x00402f37;
    }
    // 00402f2c  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402f31  898128070000           -mov dword ptr [ecx + 0x728], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1832) /* 0x728 */) = cpu.eax;
L_0x00402f37:
    // 00402f37  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00402f3c  2b8128070000           -sub eax, dword ptr [ecx + 0x728]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1832) /* 0x728 */)));
    // 00402f42  3d00010000             +cmp eax, 0x100
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
    // 00402f47  7e1b                   -jle 0x402f64
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00402f64;
    }
L_0x00402f49:
    // 00402f49  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00402f4b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00402f4d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00402f4f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00402f51  e85ae9ffff             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
    // 00402f56  eb0c                   -jmp 0x402f64
    goto L_0x00402f64;
L_0x00402f58:
    // 00402f58  89b128070000           -mov dword ptr [ecx + 0x728], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1832) /* 0x728 */) = cpu.esi;
    // 00402f5e  89b12c070000           -mov dword ptr [ecx + 0x72c], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1836) /* 0x72c */) = cpu.esi;
L_0x00402f64:
    // 00402f64  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00402f66  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f67  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f68  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f69  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f6a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f6b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402f6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_402f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402f70  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402f71  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00402f72  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402f73  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402f74  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402f76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00402f78  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00402f7b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00402f82  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f84  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00402f8a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00402f8d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f8f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402f91  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 00402f94  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00402f97  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00402f9c  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00402f9f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00402fa1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00402fa3  8b9a38060000           -mov ebx, dword ptr [edx + 0x638]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 00402fa9  39d9                   +cmp ecx, ebx
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
    // 00402fab  7f18                   -jg 0x402fc5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00402fc5;
    }
    // 00402fad  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 00402fb0  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00402fb2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00402fb7  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00402fba  39d8                   +cmp eax, ebx
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
    // 00402fbc  7c07                   -jl 0x402fc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00402fc5;
    }
    // 00402fbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00402fc0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fc1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fc2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fc3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fc4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00402fc5:
    // 00402fc5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00402fca  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fcb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fcc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fcd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_402fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00402fd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00402fd1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00402fd2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00402fd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00402fd5  8b90ac070000           -mov edx, dword ptr [eax + 0x7ac]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 00402fdb  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00402fde  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00402fe1  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00402fe3  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00402fe6  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00402fe9  e812c00000             -call 0x40f000
    cpu.esp -= 4;
    sub_40f000(app, cpu);
    if (cpu.terminate) return;
    // 00402fee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402fef  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ff0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00402ff1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_403000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403000  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403001  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403002  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403004  8b90ac070000           -mov edx, dword ptr [eax + 0x7ac]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 0040300a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0040300c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0040300f  e8ccf8ffff             -call 0x4028e0
    cpu.esp -= 4;
    sub_4028e0(app, cpu);
    if (cpu.terminate) return;
    // 00403014  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403015  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403016  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_403030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00403030  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403031  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403032  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403033  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403034  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403036  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403038  8b80ac070000           -mov eax, dword ptr [eax + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 0040303e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00403040  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00403042  83f904                 +cmp ecx, 4
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
    // 00403045  7707                   -ja 0x40304e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040304e;
    }
    // 00403047  ff248d18304000         -jmp dword ptr [ecx*4 + 0x403018]
    cpu.ip = *app->getMemory<x86::reg32>(4206616 + cpu.ecx * 4); goto dynamic_jump;
  case 0x0040304e:
L_0x0040304e:
    // 0040304e  80780600               +cmp byte ptr [eax + 6], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00403052  7509                   -jne 0x40305d
    if (!cpu.flags.zf)
    {
        goto L_0x0040305d;
    }
    // 00403054  80a221060000ef         +and byte ptr [edx + 0x621], 0xef
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 0040305b  eb07                   -jmp 0x403064
    goto L_0x00403064;
L_0x0040305d:
    // 0040305d  808a2106000010         -or byte ptr [edx + 0x621], 0x10
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00403064:
    // 00403064  c7820c07000001000000   -mov dword ptr [edx + 0x70c], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 1 /*0x1*/;
    // 0040306e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403070  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403071  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403072  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403073  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403074  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403075:
    // 00403075  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403077  e854ffffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 0040307c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040307e  7518                   -jne 0x403098
    if (!cpu.flags.zf)
    {
        goto L_0x00403098;
    }
    // 00403080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403082  e879ffffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403087  c7820c07000001000000   -mov dword ptr [edx + 0x70c], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 1 /*0x1*/;
    // 00403091  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403093  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403094  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403095  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403096  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403097  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403098:
    // 00403098  c7820c07000003000000   -mov dword ptr [edx + 0x70c], 3
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 3 /*0x3*/;
    // 004030a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004030a4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030a5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030a6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030a7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030a8  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004030a9:
    // 004030a9  c7820c07000002000000   -mov dword ptr [edx + 0x70c], 2
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 2 /*0x2*/;
    // 004030b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004030b5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030b6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030b7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030b8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004030b9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004030ba:
    // 004030ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004030bc  e80fffffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 004030c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004030c3  0f85ad000000           -jne 0x403176
    if (!cpu.flags.zf)
    {
        goto L_0x00403176;
    }
    // 004030c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004030cb  e830ffffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 004030d0  83ba0c07000007         +cmp dword ptr [edx + 0x70c], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004030d7  0f8499000000           -je 0x403176
    if (cpu.flags.zf)
    {
        goto L_0x00403176;
    }
    // 004030dd  8aa210070000           -mov ah, byte ptr [edx + 0x710]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */);
    // 004030e3  c7820c07000007000000   -mov dword ptr [edx + 0x70c], 7
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 7 /*0x7*/;
    // 004030ed  80cc10                 -or ah, 0x10
    cpu.ah |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004030f0  88a210070000           -mov byte ptr [edx + 0x710], ah
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.ah;
    // 004030f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004030f8  c7823407000001000000   -mov dword ptr [edx + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 00403102  e8e9860000             -call 0x40b7f0
    cpu.esp -= 4;
    sub_40b7f0(app, cpu);
    if (cpu.terminate) return;
    // 00403107  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403109  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040310a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040310b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040310c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040310d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040310e:
    // 0040310e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403110  e8bbfeffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 00403115  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403117  753a                   -jne 0x403153
    if (!cpu.flags.zf)
    {
        goto L_0x00403153;
    }
    // 00403119  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040311b  e8e0feffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403120  83ba0c07000008         +cmp dword ptr [edx + 0x70c], 8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403127  744d                   -je 0x403176
    if (cpu.flags.zf)
    {
        goto L_0x00403176;
    }
    // 00403129  c7823407000001000000   -mov dword ptr [edx + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 00403133  8a9a10070000           -mov bl, byte ptr [edx + 0x710]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */);
    // 00403139  c7820c07000008000000   -mov dword ptr [edx + 0x70c], 8
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 8 /*0x8*/;
    // 00403143  80cb10                 -or bl, 0x10
    cpu.bl |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00403146  889a10070000           -mov byte ptr [edx + 0x710], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.bl;
    // 0040314c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040314e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040314f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403150  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403151  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403152  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403153:
    // 00403153  c7823407000001000000   -mov dword ptr [edx + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 0040315d  8aba10070000           -mov bh, byte ptr [edx + 0x710]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */);
    // 00403163  c7820c0700000a000000   -mov dword ptr [edx + 0x70c], 0xa
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1804) /* 0x70c */) = 10 /*0xa*/;
    // 0040316d  80cf10                 -or bh, 0x10
    cpu.bh |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00403170  88ba10070000           -mov byte ptr [edx + 0x710], bh
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.bh;
L_0x00403176:
    // 00403176  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403178  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403179  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040317a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040317b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040317c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_403180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403180  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403181  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403182  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403183  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403184  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403185  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403186  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403188  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040318b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040318d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0040318f:
    // 0040318f  3b35a0fd5e00           +cmp esi, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403195  7d67                   -jge 0x4031fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004031fe;
    }
    // 00403197  8d3cb500000000         -lea edi, [esi*4]
    cpu.edi = x86::reg32(cpu.esi * 4);
    // 0040319e  8b8748fc5e00           -mov eax, dword ptr [edi + 0x5efc48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224968) /* 0x5efc48 */);
    // 004031a4  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 004031aa  8d9098000000           -lea edx, [eax + 0x98]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004031b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004031b2  e8f9330900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004031b7  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004031b9  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004031bb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004031bd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004031be  7315                   -jae 0x4031d5
    if (!cpu.flags.cf)
    {
        goto L_0x004031d5;
    }
    // 004031c0  8b8748fc5e00           -mov eax, dword ptr [edi + 0x5efc48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224968) /* 0x5efc48 */);
    // 004031c6  8d9098000000           -lea edx, [eax + 0x98]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004031cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004031ce  e8dd330900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004031d3  eb15                   -jmp 0x4031ea
    goto L_0x004031ea;
L_0x004031d5:
    // 004031d5  8b8748fc5e00           -mov eax, dword ptr [edi + 0x5efc48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6224968) /* 0x5efc48 */);
    // 004031db  8d9098000000           -lea edx, [eax + 0x98]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 004031e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004031e3  e8c8330900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004031e8  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004031ea:
    // 004031ea  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004031ed  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004031f0  dc1df4605300           +fcomp qword ptr [0x5360f4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464308) /* 0x5360f4 */));
    cpu.fpu.pop();
    // 004031f6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004031f8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004031f9  726a                   -jb 0x403265
    if (cpu.flags.cf)
    {
        goto L_0x00403265;
    }
    // 004031fb  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004031fc  eb91                   -jmp 0x40318f
    goto L_0x0040318f;
L_0x004031fe:
    // 004031fe  8b15c0d46f00           -mov edx, dword ptr [0x6fd4c0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 00403204  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403206  e875d70900             -call 0x4a0980
    cpu.esp -= 4;
    sub_4a0980(app, cpu);
    if (cpu.terminate) return;
    // 0040320b  8b81ac070000           -mov eax, dword ptr [ecx + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1964) /* 0x7ac */);
    // 00403211  80780700               +cmp byte ptr [eax + 7], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00403215  740a                   -je 0x403221
    if (cpu.flags.zf)
    {
        goto L_0x00403221;
    }
    // 00403217  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0040321a  680000803e             -push 0x3e800000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1048576000 /*0x3e800000*/;
    cpu.esp -= 4;
    // 0040321f  eb08                   -jmp 0x403229
    goto L_0x00403229;
L_0x00403221:
    // 00403221  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00403224  680000403f             -push 0x3f400000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1061158912 /*0x3f400000*/;
    cpu.esp -= 4;
L_0x00403229:
    // 00403229  e8b2cb0d00             -call 0x4dfde0
    cpu.esp -= 4;
    sub_4dfde0(app, cpu);
    if (cpu.terminate) return;
    // 0040322e  8d81c0000000           -lea eax, [ecx + 0xc0]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(192) /* 0xc0 */);
    // 00403234  8d55d8                 -lea edx, [ebp - 0x28]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00403237  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00403239  e842d00d00             -call 0x4e0280
    cpu.esp -= 4;
    sub_4e0280(app, cpu);
    if (cpu.terminate) return;
    // 0040323e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403240  e84bf40900             -call 0x4a2690
    cpu.esp -= 4;
    sub_4a2690(app, cpu);
    if (cpu.terminate) return;
    // 00403245  8ab121060000           -mov dh, byte ptr [ecx + 0x621]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 0040324b  c781b007000000000000   -mov dword ptr [ecx + 0x7b0], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 00403255  80e6f7                 -and dh, 0xf7
    cpu.dh &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00403258  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040325a  88b121060000           -mov byte ptr [ecx + 0x621], dh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) = cpu.dh;
    // 00403260  e80b9c0000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
L_0x00403265:
    // 00403265  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00403267  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403268  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403269  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040326a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040326b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040326c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040326d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_403270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403270  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403271  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403272  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403274  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403276  e8e5aa0000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040327b  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0040327e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403280  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00403283  e8a8e1ffff             -call 0x401430
    cpu.esp -= 4;
    sub_401430(app, cpu);
    if (cpu.terminate) return;
    // 00403288  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040328a  e8618d0000             -call 0x40bff0
    cpu.esp -= 4;
    sub_40bff0(app, cpu);
    if (cpu.terminate) return;
    // 0040328f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403291  e81aab0000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 00403296  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403298  e893ab0000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 0040329d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040329e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040329f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4032e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004032e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004032e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004032e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004032e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004032e4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004032e5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004032e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004032e8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004032ea  e821ac0000             -call 0x40df10
    cpu.esp -= 4;
    sub_40df10(app, cpu);
    if (cpu.terminate) return;
    // 004032ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004032f1  0f8423050000           -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004032f7  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004032fc  b858ea5600             -mov eax, 0x56ea58
    cpu.eax = 5696088 /*0x56ea58*/;
    // 00403301  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403303  e838d30d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00403308  80a111070000fd         -and byte ptr [ecx + 0x711], 0xfd
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0040330f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403311  e86af9ffff             -call 0x402c80
    cpu.esp -= 4;
    sub_402c80(app, cpu);
    if (cpu.terminate) return;
    // 00403316  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403318  7409                   -je 0x403323
    if (cpu.flags.zf)
    {
        goto L_0x00403323;
    }
    // 0040331a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040331c  e82f060000             -call 0x403950
    cpu.esp -= 4;
    sub_403950(app, cpu);
    if (cpu.terminate) return;
    // 00403321  eb07                   -jmp 0x40332a
    goto L_0x0040332a;
L_0x00403323:
    // 00403323  80a111070000ef         -and byte ptr [ecx + 0x711], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x0040332a:
    // 0040332a  8b9114070000           -mov edx, dword ptr [ecx + 0x714]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1812) /* 0x714 */);
    // 00403330  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00403337  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403339  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0040333c  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403343  7407                   -je 0x40334c
    if (cpu.flags.zf)
    {
        goto L_0x0040334c;
    }
    // 00403345  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403347  e8a40a0000             -call 0x403df0
    cpu.esp -= 4;
    sub_403df0(app, cpu);
    if (cpu.terminate) return;
L_0x0040334c:
    // 0040334c  f6811107000004         +test byte ptr [ecx + 0x711], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) & 4 /*0x4*/));
    // 00403353  7407                   -je 0x40335c
    if (cpu.flags.zf)
    {
        goto L_0x0040335c;
    }
    // 00403355  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403357  e8740b0000             -call 0x403ed0
    cpu.esp -= 4;
    sub_403ed0(app, cpu);
    if (cpu.terminate) return;
L_0x0040335c:
    // 0040335c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040335e  e8fd110000             -call 0x404560
    cpu.esp -= 4;
    sub_404560(app, cpu);
    if (cpu.terminate) return;
    // 00403363  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403365  7407                   -je 0x40336e
    if (cpu.flags.zf)
    {
        goto L_0x0040336e;
    }
    // 00403367  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403369  e8c2fcffff             -call 0x403030
    cpu.esp -= 4;
    sub_403030(app, cpu);
    if (cpu.terminate) return;
L_0x0040336e:
    // 0040336e  8b810c070000           -mov eax, dword ptr [ecx + 0x70c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */);
    // 00403374  83f80b                 +cmp eax, 0xb
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403377  7707                   -ja 0x403380
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00403380;
    }
    // 00403379  ff2485a4324000         -jmp dword ptr [eax*4 + 0x4032a4]
    cpu.ip = *app->getMemory<x86::reg32>(4207268 + cpu.eax * 4); goto dynamic_jump;
  case 0x00403380:
L_0x00403380:
    // 00403380  c7810c07000001000000   -mov dword ptr [ecx + 0x70c], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 1 /*0x1*/;
  [[fallthrough]];
  case 0x0040338a:
    // 0040338a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040338c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040338e  68ec51983f             -push 0x3f9851ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1066947052 /*0x3f9851ec*/;
    cpu.esp -= 4;
    // 00403393  e8d8feffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
    // 00403398  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040339a  e871faffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 0040339f  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004033a6  740f                   -je 0x4033b7
    if (cpu.flags.zf)
    {
        goto L_0x004033b7;
    }
    // 004033a8  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 004033b2  e963040000             -jmp 0x40381a
    goto L_0x0040381a;
L_0x004033b7:
    // 004033b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004033b9  e872fcffff             -call 0x403030
    cpu.esp -= 4;
    sub_403030(app, cpu);
    if (cpu.terminate) return;
    // 004033be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033c4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004033c5:
    // 004033c5  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004033c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004033c9  6800000040             -push 0x40000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 004033ce  e89dfeffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
    // 004033d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004033d5  e836faffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 004033da  8bb124060000           -mov esi, dword ptr [ecx + 0x624]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004033e0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004033e2  7411                   -je 0x4033f5
    if (cpu.flags.zf)
    {
        goto L_0x004033f5;
    }
    // 004033e4  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 004033ee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033ef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033f1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033f2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033f3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004033f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004033f5:
    // 004033f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004033f7  e8d4fbffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 004033fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004033fe  742f                   -je 0x40342f
    if (cpu.flags.zf)
    {
        goto L_0x0040342f;
    }
    // 00403400  8b81ac070000           -mov eax, dword ptr [ecx + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1964) /* 0x7ac */);
    // 00403406  c60002                 -mov byte ptr [eax], 2
    *app->getMemory<x86::reg8>(cpu.eax) = 2 /*0x2*/;
    // 00403409  c7810c07000001000000   -mov dword ptr [ecx + 0x70c], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 1 /*0x1*/;
    // 00403413  8a9910070000           -mov bl, byte ptr [ecx + 0x710]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 00403419  89b134070000           -mov dword ptr [ecx + 0x734], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1844) /* 0x734 */) = cpu.esi;
    // 0040341f  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00403422  889910070000           -mov byte ptr [ecx + 0x710], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.bl;
    // 00403428  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403429  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040342e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040342f:
    // 0040342f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403431  e8cafbffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403436  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403437  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403438  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403439  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040343a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040343b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040343c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040343d:
    // 0040343d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040343f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403441  6800000040             -push 0x40000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00403446  e825feffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
    // 0040344b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040344d  e8bef9ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 00403452  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403459  7411                   -je 0x40346c
    if (cpu.flags.zf)
    {
        goto L_0x0040346c;
    }
    // 0040345b  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 00403465  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403466  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403467  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403468  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403469  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040346a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040346b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040346c:
    // 0040346c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040346e  e85dfbffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 00403473  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403475  7411                   -je 0x403488
    if (cpu.flags.zf)
    {
        goto L_0x00403488;
    }
    // 00403477  c7810c07000009000000   -mov dword ptr [ecx + 0x70c], 9
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 9 /*0x9*/;
    // 00403481  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403482  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403483  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403484  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403485  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403486  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403487  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403488:
    // 00403488  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040348a  e871fbffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 0040348f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403490  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403491  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403492  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403493  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403494  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403495  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403496:
    // 00403496  680000c040             -push 0x40c00000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1086324736 /*0x40c00000*/;
    cpu.esp -= 4;
    // 0040349b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040349d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040349f  e8ccfdffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
    // 004034a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004034a6  e865f9ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 004034ab  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004034b2  7411                   -je 0x4034c5
    if (cpu.flags.zf)
    {
        goto L_0x004034c5;
    }
    // 004034b4  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 004034be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034bf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004034c5:
    // 004034c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004034c7  e804fbffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 004034cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004034ce  742d                   -je 0x4034fd
    if (cpu.flags.zf)
    {
        goto L_0x004034fd;
    }
    // 004034d0  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 004034d6  dc1dfc605300           +fcomp qword ptr [0x5360fc]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464316) /* 0x5360fc */));
    cpu.fpu.pop();
    // 004034dc  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004034de  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004034df  0f8735030000           -ja 0x40381a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004034e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004034e7  c7810c0700000a000000   -mov dword ptr [ecx + 0x70c], 0xa
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 10 /*0xa*/;
    // 004034f1  e8ca850000             -call 0x40bac0
    cpu.esp -= 4;
    sub_40bac0(app, cpu);
    if (cpu.terminate) return;
    // 004034f6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034f9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034fa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034fb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004034fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004034fd:
    // 004034fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004034ff  e8fcfaffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403504  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403505  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403506  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403507  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403508  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403509  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040350a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040350b:
    // 0040350b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040350d  e8befaffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 00403512  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403514  7442                   -je 0x403558
    if (cpu.flags.zf)
    {
        goto L_0x00403558;
    }
    // 00403516  8ab921060000           -mov bh, byte ptr [ecx + 0x621]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 0040351c  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0040351f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403521  88b921060000           -mov byte ptr [ecx + 0x621], bh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) = cpu.bh;
    // 00403527  e854fcffff             -call 0x403180
    cpu.esp -= 4;
    sub_403180(app, cpu);
    if (cpu.terminate) return;
    // 0040352c  f6812106000008         +test byte ptr [ecx + 0x621], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 8 /*0x8*/));
    // 00403533  7417                   -je 0x40354c
    if (cpu.flags.zf)
    {
        goto L_0x0040354c;
    }
    // 00403535  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403537  e824a80000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040353c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040353e  e86da80000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 00403543  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403545  e8e6a80000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 0040354a  eb28                   -jmp 0x403574
    goto L_0x00403574;
L_0x0040354c:
    // 0040354c  c7810c0700000b000000   -mov dword ptr [ecx + 0x70c], 0xb
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 11 /*0xb*/;
    // 00403556  eb1c                   -jmp 0x403574
    goto L_0x00403574;
L_0x00403558:
    // 00403558  80a121060000f7         -and byte ptr [ecx + 0x621], 0xf7
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0040355f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403561  e89afaffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403566  680000c040             -push 0x40c00000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1086324736 /*0x40c00000*/;
    cpu.esp -= 4;
    // 0040356b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040356d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040356f  e8fcfcffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
L_0x00403574:
    // 00403574  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403576  e895f8ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 0040357b  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403582  0f8492020000           -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 00403588  8a9121060000           -mov dl, byte ptr [ecx + 0x621]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 0040358e  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 00403598  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0040359b  889121060000           -mov byte ptr [ecx + 0x621], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) = cpu.dl;
    // 004035a1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035a7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004035a8:
    // 004035a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004035aa  e861f8ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 004035af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004035b1  e8ba980000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004035b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004035b8  e8b3980000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004035bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004035bf  e8ac980000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004035c4  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004035cb  0f8449020000           -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004035d1  8ab121060000           -mov dh, byte ptr [ecx + 0x621]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */);
    // 004035d7  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 004035e1  80e6f7                 -and dh, 0xf7
    cpu.dh &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004035e4  88b121060000           -mov byte ptr [ecx + 0x621], dh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) = cpu.dh;
    // 004035ea  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035eb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035ec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035ed  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035ee  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035ef  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004035f0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004035f1:
    // 004035f1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004035f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004035f5  68ec51983f             -push 0x3f9851ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1066947052 /*0x3f9851ec*/;
    cpu.esp -= 4;
    // 004035fa  e871fcffff             -call 0x403270
    cpu.esp -= 4;
    sub_403270(app, cpu);
    if (cpu.terminate) return;
    // 004035ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403601  e80af8ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 00403606  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040360d  740a                   -je 0x403619
    if (cpu.flags.zf)
    {
        goto L_0x00403619;
    }
    // 0040360f  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
L_0x00403619:
    // 00403619  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040361b  e8b0f9ffff             -call 0x402fd0
    cpu.esp -= 4;
    sub_402fd0(app, cpu);
    if (cpu.terminate) return;
    // 00403620  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403622  740e                   -je 0x403632
    if (cpu.flags.zf)
    {
        goto L_0x00403632;
    }
    // 00403624  80a110070000df         -and byte ptr [ecx + 0x710], 0xdf
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0040362b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040362c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040362d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040362e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040362f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403630  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403631  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403632:
    // 00403632  f6811007000020         +test byte ptr [ecx + 0x710], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) & 32 /*0x20*/));
    // 00403639  0f85db010000           -jne 0x40381a
    if (!cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 0040363f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403641  e8baf9ffff             -call 0x403000
    cpu.esp -= 4;
    sub_403000(app, cpu);
    if (cpu.terminate) return;
    // 00403646  80891007000020         -or byte ptr [ecx + 0x710], 0x20
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 0040364d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040364e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040364f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403650  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403651  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403652  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403653  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403654:
    // 00403654  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403656  e805a70000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040365b  680000d040             -push 0x40d00000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1087373312 /*0x40d00000*/;
    cpu.esp -= 4;
    // 00403660  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403662  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403664  e8c7ddffff             -call 0x401430
    cpu.esp -= 4;
    sub_401430(app, cpu);
    if (cpu.terminate) return;
    // 00403669  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040366b  e820f7ffff             -call 0x402d90
    cpu.esp -= 4;
    sub_402d90(app, cpu);
    if (cpu.terminate) return;
    // 00403670  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403672  e8a9a00000             -call 0x40d720
    cpu.esp -= 4;
    sub_40d720(app, cpu);
    if (cpu.terminate) return;
    // 00403677  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403679  e882a10000             -call 0x40d800
    cpu.esp -= 4;
    sub_40d800(app, cpu);
    if (cpu.terminate) return;
    // 0040367e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403680  e86ba30000             -call 0x40d9f0
    cpu.esp -= 4;
    sub_40d9f0(app, cpu);
    if (cpu.terminate) return;
    // 00403685  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403687  e8a4a70000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 0040368c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040368e  e8ddf8ffff             -call 0x402f70
    cpu.esp -= 4;
    sub_402f70(app, cpu);
    if (cpu.terminate) return;
    // 00403693  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403695  741c                   -je 0x4036b3
    if (cpu.flags.zf)
    {
        goto L_0x004036b3;
    }
    // 00403697  8aa111070000           -mov ah, byte ptr [ecx + 0x711]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */);
    // 0040369d  c7810c07000004000000   -mov dword ptr [ecx + 0x70c], 4
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 4 /*0x4*/;
    // 004036a7  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004036aa  7407                   -je 0x4036b3
    if (cpu.flags.zf)
    {
        goto L_0x004036b3;
    }
    // 004036ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004036ae  e87d060000             -call 0x403d30
    cpu.esp -= 4;
    sub_403d30(app, cpu);
    if (cpu.terminate) return;
L_0x004036b3:
    // 004036b3  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004036ba  0f845a010000           -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004036c0  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 004036ca  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036cb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036cc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036cd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036ce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036cf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004036d0  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004036d1:
    // 004036d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004036d3  c781b007000000000000   -mov dword ptr [ecx + 0x7b0], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 004036dd  e88e970000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004036e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004036e4  e827f7ffff             -call 0x402e10
    cpu.esp -= 4;
    sub_402e10(app, cpu);
    if (cpu.terminate) return;
    // 004036e9  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004036f0  0f8424010000           -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004036f6  c7810c07000005000000   -mov dword ptr [ecx + 0x70c], 5
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 5 /*0x5*/;
    // 00403700  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403701  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403702  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403703  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403704  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403705  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403706  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00403707:
    // 00403707  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403709  e852a60000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040370e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403710  e86be0ffff             -call 0x401780
    cpu.esp -= 4;
    sub_401780(app, cpu);
    if (cpu.terminate) return;
    // 00403715  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403717  e8f4f1ffff             -call 0x402910
    cpu.esp -= 4;
    sub_402910(app, cpu);
    if (cpu.terminate) return;
    // 0040371c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040371e  e89deeffff             -call 0x4025c0
    cpu.esp -= 4;
    sub_4025c0(app, cpu);
    if (cpu.terminate) return;
    // 00403723  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00403729  e882ddffff             -call 0x4014b0
    cpu.esp -= 4;
    sub_4014b0(app, cpu);
    if (cpu.terminate) return;
    // 0040372e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403730  e87ba60000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 00403735  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403737  e814f0ffff             -call 0x402750
    cpu.esp -= 4;
    sub_402750(app, cpu);
    if (cpu.terminate) return;
    // 0040373c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040373e  e8eda60000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 00403743  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403745  e8c6e9ffff             -call 0x402110
    cpu.esp -= 4;
    sub_402110(app, cpu);
    if (cpu.terminate) return;
    // 0040374a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040374c  7418                   -je 0x403766
    if (cpu.flags.zf)
    {
        goto L_0x00403766;
    }
    // 0040374e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403750  c7810c07000006000000   -mov dword ptr [ecx + 0x70c], 6
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 6 /*0x6*/;
    // 0040375a  e8e1e6ffff             -call 0x401e40
    cpu.esp -= 4;
    sub_401e40(app, cpu);
    if (cpu.terminate) return;
    // 0040375f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403760  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403761  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403762  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403763  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403764  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403765  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403766:
    // 00403766  8b9124060000           -mov edx, dword ptr [ecx + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040376c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040376e  0f849c000000           -je 0x403810
    if (cpu.flags.zf)
    {
        goto L_0x00403810;
    }
    // 00403774  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403776  e805f5ffff             -call 0x402c80
    cpu.esp -= 4;
    sub_402c80(app, cpu);
    if (cpu.terminate) return;
    // 0040377b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040377d  740e                   -je 0x40378d
    if (cpu.flags.zf)
    {
        goto L_0x0040378d;
    }
    // 0040377f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403781  e88a010000             -call 0x403910
    cpu.esp -= 4;
    sub_403910(app, cpu);
    if (cpu.terminate) return;
    // 00403786  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403787  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403788  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403789  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040378a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040378b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040378c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040378d:
    // 0040378d  8b1d1cd56f00           -mov ebx, dword ptr [0x6fd51c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(7329052) /* 0x6fd51c */);
    // 00403793  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00403795  0f857f000000           -jne 0x40381a
    if (!cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 0040379b  8b8128060000           -mov eax, dword ptr [ecx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 004037a1  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004037a7  2b5024                 -sub edx, dword ptr [eax + 0x24]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 004037aa  81fa40010000           +cmp edx, 0x140
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004037b0  7e68                   -jle 0x40381a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040381a;
    }
    // 004037b2  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004037b8  8b785c                 -mov edi, dword ptr [eax + 0x5c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004037bb  895024                 -mov dword ptr [eax + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004037be  39f9                   +cmp ecx, edi
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
    // 004037c0  7507                   -jne 0x4037c9
    if (!cpu.flags.zf)
    {
        goto L_0x004037c9;
    }
    // 004037c2  89585c                 -mov dword ptr [eax + 0x5c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.ebx;
    // 004037c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004037c7  eb1f                   -jmp 0x4037e8
    goto L_0x004037e8;
L_0x004037c9:
    // 004037c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004037cb  e8f0010000             -call 0x4039c0
    cpu.esp -= 4;
    sub_4039c0(app, cpu);
    if (cpu.terminate) return;
    // 004037d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004037d2  7546                   -jne 0x40381a
    if (!cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
    // 004037d4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004037d6  e845030000             -call 0x403b20
    cpu.esp -= 4;
    sub_403b20(app, cpu);
    if (cpu.terminate) return;
    // 004037db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004037dd  7407                   -je 0x4037e6
    if (cpu.flags.zf)
    {
        goto L_0x004037e6;
    }
    // 004037df  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004037e6:
    // 004037e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004037e8:
    // 004037e8  e8b30b0000             -call 0x4043a0
    cpu.esp -= 4;
    sub_4043a0(app, cpu);
    if (cpu.terminate) return;
    // 004037ed  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ee  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037ef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037f0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037f2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004037f3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004037f4:
    // 004037f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004037f6  c781b007000000000000   -mov dword ptr [ecx + 0x7b0], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 00403800  e86b960000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 00403805  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403807  e8a4e7ffff             -call 0x401fb0
    cpu.esp -= 4;
    sub_401fb0(app, cpu);
    if (cpu.terminate) return;
    // 0040380c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040380e  740a                   -je 0x40381a
    if (cpu.flags.zf)
    {
        goto L_0x0040381a;
    }
L_0x00403810:
    // 00403810  c7810c07000001000000   -mov dword ptr [ecx + 0x70c], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 1 /*0x1*/;
L_0x0040381a:
    // 0040381a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040381b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040381c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040381d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040381e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040381f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403820  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_403830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403830  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403831  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403832  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403834  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403836  8b80ac070000           -mov eax, dword ptr [eax + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 0040383c  f6860002000004         +test byte ptr [esi + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00403843  7523                   -jne 0x403868
    if (!cpu.flags.zf)
    {
        goto L_0x00403868;
    }
    // 00403845  899630070000           -mov dword ptr [esi + 0x730], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */) = cpu.edx;
    // 0040384b  c6400100               -mov byte ptr [eax + 1], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 0040384f  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00403851  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00403854  66894802               -mov word ptr [eax + 2], cx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 00403858  66895004               -mov word ptr [eax + 4], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0040385c  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040385f  885006                 -mov byte ptr [eax + 6], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00403862  8a5514                 -mov dl, byte ptr [ebp + 0x14]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00403865  885007                 -mov byte ptr [eax + 7], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = cpu.dl;
L_0x00403868:
    // 00403868  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403869  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040386a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_403870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403870  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403871  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403872  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403873  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403874  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403875  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403876  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403878  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040387b  a140d95d00             -mov eax, dword ptr [0x5dd940]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00403880  8b3588fd5e00           -mov esi, dword ptr [0x5efd88]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */);
    // 00403886  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403888  46                     -inc esi
    (cpu.esi)++;
    // 00403889  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040388c  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040388e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00403890  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00403893  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00403895:
    // 00403895  3b3588fd5e00           +cmp esi, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040389b  7d5f                   -jge 0x4038fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004038fc;
    }
    // 0040389d  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 004038a2  8b0d184f5500           -mov ecx, dword ptr [0x554f18]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 004038a8  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004038ab  a3144f5500             -mov dword ptr [0x554f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 004038b0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004038b5  a3104f5500             -mov dword ptr [0x554f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 004038ba  a1144f5500             -mov eax, dword ptr [0x554f14]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 004038bf  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004038c2  2500ffff00             -and eax, 0xffff00
    cpu.eax &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 004038c7  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 004038ca  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004038cd  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004038d0  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004038d3  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004038d6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004038d8  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004038da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004038dc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004038e1  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004038e4  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004038e6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004038e7  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004038e9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004038eb  6a05                   -push 5
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004038ed  8b04b588fa5e00         -mov eax, dword ptr [esi*4 + 0x5efa88]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.esi * 4);
    // 004038f4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004038f5  e836ffffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 004038fa  eb99                   -jmp 0x403895
    goto L_0x00403895;
L_0x004038fc:
    // 004038fc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004038fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004038ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403900  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403901  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403902  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403903  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403904  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_403910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403910  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403911  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403912  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403914  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403916  8b8024060000           -mov eax, dword ptr [eax + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 0040391c  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00403922  f6405408               +test byte ptr [eax + 0x54], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(84) /* 0x54 */) & 8 /*0x8*/));
    // 00403926  7517                   -jne 0x40393f
    if (!cpu.flags.zf)
    {
        goto L_0x0040393f;
    }
    // 00403928  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040392a  e801830000             -call 0x40bc30
    cpu.esp -= 4;
    sub_40bc30(app, cpu);
    if (cpu.terminate) return;
    // 0040392f  8b8224060000           -mov eax, dword ptr [edx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
    // 00403935  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 0040393b  80485408               -or byte ptr [eax + 0x54], 8
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(84) /* 0x54 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0040393f:
    // 0040393f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403940  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_403950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403950  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403951  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403952  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403954  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403956  f6801107000010         +test byte ptr [eax + 0x711], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1809) /* 0x711 */) & 16 /*0x10*/));
    // 0040395d  750e                   -jne 0x40396d
    if (!cpu.flags.zf)
    {
        goto L_0x0040396d;
    }
    // 0040395f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00403961  e83a820000             -call 0x40bba0
    cpu.esp -= 4;
    sub_40bba0(app, cpu);
    if (cpu.terminate) return;
    // 00403966  808a1107000010         -or byte ptr [edx + 0x711], 0x10
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1809) /* 0x711 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0040396d:
    // 0040396d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040396e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040396f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_403970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403970  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403971  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403972  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403973  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403974  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403976  bb00060000             -mov ebx, 0x600
    cpu.ebx = 1536 /*0x600*/;
    // 0040397b  b810e45600             -mov eax, 0x56e410
    cpu.eax = 5694480 /*0x56e410*/;
    // 00403980  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403982  e8b9cc0d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00403987  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00403989:
    // 00403989  3b15a0fd5e00           +cmp edx, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040398f  7d21                   -jge 0x4039b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004039b2;
    }
    // 00403991  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00403998  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040399a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040399d  8b0c9548fc5e00         -mov ecx, dword ptr [edx*4 + 0x5efc48]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.edx * 4);
    // 004039a4  0510e45600             +add eax, 0x56e410
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5694480 /*0x56e410*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004039a9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004039aa  898128060000           -mov dword ptr [ecx + 0x628], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */) = cpu.eax;
    // 004039b0  ebd7                   -jmp 0x403989
    goto L_0x00403989;
L_0x004039b2:
    // 004039b2  e8b9feffff             -call 0x403870
    cpu.esp -= 4;
    sub_403870(app, cpu);
    if (cpu.terminate) return;
    // 004039b7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004039b8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004039b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004039ba  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004039bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4039c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004039c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004039c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004039c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004039c3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004039c4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004039c5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004039c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004039c8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004039cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004039cd  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004039d3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004039da  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004039dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004039de  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004039e1  c1e202                 +shl edx, 2
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
    // 004039e4  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004039e6  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004039e9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004039eb  8b151cd56f00           -mov edx, dword ptr [0x6fd51c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7329052) /* 0x6fd51c */);
    // 004039f1  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004039f4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004039f6  0f8511010000           -jne 0x403b0d
    if (!cpu.flags.zf)
    {
        goto L_0x00403b0d;
    }
    // 004039fc  8b9924060000           -mov ebx, dword ptr [ecx + 0x624]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00403a02  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00403a04  0f8403010000           -je 0x403b0d
    if (cpu.flags.zf)
    {
        goto L_0x00403b0d;
    }
    // 00403a0a  8bb928060000           -mov edi, dword ptr [ecx + 0x628]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00403a10  837f5800               +cmp dword ptr [edi + 0x58], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403a14  0f85f3000000           -jne 0x403b0d
    if (!cpu.flags.zf)
    {
        goto L_0x00403b0d;
    }
    // 00403a1a  8b572c                 -mov edx, dword ptr [edi + 0x2c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */);
    // 00403a1d  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00403a20  4a                     -dec edx
    (cpu.edx)--;
    // 00403a21  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403a23  8b93c8020000           -mov edx, dword ptr [ebx + 0x2c8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00403a29  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00403a2c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403a2e  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00403a34  2b5720                 -sub edx, dword ptr [edi + 0x20]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */)));
    // 00403a37  c1fa0b                 -sar edx, 0xb
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (11 /*0xb*/ % 32));
    // 00403a3a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403a3c  83f804                 +cmp eax, 4
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
    // 00403a3f  0f8cc8000000           -jl 0x403b0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403b0d;
    }
    // 00403a45  f6475402               +test byte ptr [edi + 0x54], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(84) /* 0x54 */) & 2 /*0x2*/));
    // 00403a49  751b                   -jne 0x403a66
    if (!cpu.flags.zf)
    {
        goto L_0x00403a66;
    }
    // 00403a4b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00403a4d  e8be7e0000             -call 0x40b910
    cpu.esp -= 4;
    sub_40b910(app, cpu);
    if (cpu.terminate) return;
    // 00403a52  8b8128060000           -mov eax, dword ptr [ecx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00403a58  80485402               -or byte ptr [eax + 0x54], 2
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(84) /* 0x54 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00403a5c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00403a5e  894f5c                 -mov dword ptr [edi + 0x5c], ecx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(92) /* 0x5c */) = cpu.ecx;
    // 00403a61  e9a9000000             -jmp 0x403b0f
    goto L_0x00403b0f;
L_0x00403a66:
    // 00403a66  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00403a69  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00403a6c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00403a6e:
    // 00403a6e  3b1d88fd5e00           +cmp ebx, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403a74  7d45                   -jge 0x403abb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403abb;
    }
    // 00403a76  8b049d88fa5e00         -mov eax, dword ptr [ebx*4 + 0x5efa88]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.ebx * 4);
    // 00403a7d  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00403a84  7532                   -jne 0x403ab8
    if (!cpu.flags.zf)
    {
        goto L_0x00403ab8;
    }
    // 00403a86  83b82406000000         +cmp dword ptr [eax + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403a8d  7529                   -jne 0x403ab8
    if (!cpu.flags.zf)
    {
        goto L_0x00403ab8;
    }
    // 00403a8f  f6801107000008         +test byte ptr [eax + 0x711], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1809) /* 0x711 */) & 8 /*0x8*/));
    // 00403a96  7520                   -jne 0x403ab8
    if (!cpu.flags.zf)
    {
        goto L_0x00403ab8;
    }
    // 00403a98  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00403a9b  2b55f8                 -sub edx, dword ptr [ebp - 8]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00403a9e  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403aa5  7402                   -je 0x403aa9
    if (cpu.flags.zf)
    {
        goto L_0x00403aa9;
    }
    // 00403aa7  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x00403aa9:
    // 00403aa9  83fa32                 +cmp edx, 0x32
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403aac  7e0a                   -jle 0x403ab8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403ab8;
    }
    // 00403aae  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403ab1  7d05                   -jge 0x403ab8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403ab8;
    }
    // 00403ab3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403ab5  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x00403ab8:
    // 00403ab8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00403ab9  ebb3                   -jmp 0x403a6e
    goto L_0x00403a6e;
L_0x00403abb:
    // 00403abb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00403abd  744e                   -je 0x403b0d
    if (cpu.flags.zf)
    {
        goto L_0x00403b0d;
    }
    // 00403abf  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00403ac2  83e806                 -sub eax, 6
    (cpu.eax) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00403ac5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403ac7  7d06                   -jge 0x403acf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403acf;
    }
    // 00403ac9  030540d95d00           -add eax, dword ptr [0x5dd940]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
L_0x00403acf:
    // 00403acf  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ad1  8ab611070000           -mov dh, byte ptr [esi + 0x711]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */);
    // 00403ad7  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ad9  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00403adc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00403ade  88b611070000           -mov byte ptr [esi + 0x711], dh
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) = cpu.dh;
    // 00403ae4  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00403ae6  8b9124060000           -mov edx, dword ptr [ecx + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00403aec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00403aee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403af0  e83bfdffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 00403af5  808e1107000008         -or byte ptr [esi + 0x711], 8
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00403afc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403b01  897758                 -mov dword ptr [edi + 0x58], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(88) /* 0x58 */) = cpu.esi;
    // 00403b04  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00403b06  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b07  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b08  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b09  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b0a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b0b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403b0d:
    // 00403b0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00403b0f:
    // 00403b0f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00403b11  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b12  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b13  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b14  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b15  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b16  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403b17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_403b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403b20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403b21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403b22  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403b23  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403b24  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403b25  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403b26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403b28  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00403b2b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00403b2d  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00403b33  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00403b3a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00403b3c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403b3e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00403b41  c1e202                 +shl edx, 2
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
    // 00403b44  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00403b46  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00403b49  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00403b4b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00403b4e  8a252eeb5500           -mov ah, byte ptr [0x55eb2e]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 00403b54  8975fc                 -mov dword ptr [ebp - 4], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00403b57  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00403b5a  0f85c5010000           -jne 0x403d25
    if (!cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403b60  833d1cd56f0000         +cmp dword ptr [0x6fd51c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7329052) /* 0x6fd51c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403b67  0f85b8010000           -jne 0x403d25
    if (!cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403b6d  8b9f24060000           -mov ebx, dword ptr [edi + 0x624]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1572) /* 0x624 */);
    // 00403b73  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00403b75  0f84aa010000           -je 0x403d25
    if (cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403b7b  8a9300020000           -mov dl, byte ptr [ebx + 0x200]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */);
    // 00403b81  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00403b83  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00403b86  0f8499010000           -je 0x403d25
    if (cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403b8c  8b9728060000           -mov edx, dword ptr [edi + 0x628]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1576) /* 0x628 */);
    // 00403b92  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 00403b95  4b                     -dec ebx
    (cpu.ebx)--;
    // 00403b96  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00403b99  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00403b9b  8b99c8020000           -mov ebx, dword ptr [ecx + 0x2c8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 00403ba1  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00403ba7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00403ba9  2b4a20                 -sub ecx, dword ptr [edx + 0x20]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */)));
    // 00403bac  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 00403baf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00403bb1  83f803                 +cmp eax, 3
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
    // 00403bb4  0f8c6b010000           -jl 0x403d25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403d25;
    }
    // 00403bba  f6425404               +test byte ptr [edx + 0x54], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(84) /* 0x54 */) & 4 /*0x4*/));
    // 00403bbe  7514                   -jne 0x403bd4
    if (!cpu.flags.zf)
    {
        goto L_0x00403bd4;
    }
    // 00403bc0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00403bc2  e8997c0000             -call 0x40b860
    cpu.esp -= 4;
    sub_40b860(app, cpu);
    if (cpu.terminate) return;
    // 00403bc7  8b8728060000           -mov eax, dword ptr [edi + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1576) /* 0x628 */);
    // 00403bcd  80485404               -or byte ptr [eax + 0x54], 4
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(84) /* 0x54 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00403bd1  897a5c                 -mov dword ptr [edx + 0x5c], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */) = cpu.edi;
L_0x00403bd4:
    // 00403bd4  8b8724060000           -mov eax, dword ptr [edi + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1572) /* 0x624 */);
    // 00403bda  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00403bdd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00403bdf  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x00403be2:
    // 00403be2  3b1d88fd5e00           +cmp ebx, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403be8  0f8d5a000000           -jge 0x403c48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403c48;
    }
    // 00403bee  8b0c9d88fa5e00         -mov ecx, dword ptr [ebx*4 + 0x5efa88]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.ebx * 4);
    // 00403bf5  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00403bfc  7547                   -jne 0x403c45
    if (!cpu.flags.zf)
    {
        goto L_0x00403c45;
    }
    // 00403bfe  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403c05  753e                   -jne 0x403c45
    if (!cpu.flags.zf)
    {
        goto L_0x00403c45;
    }
    // 00403c07  8aa111070000           -mov ah, byte ptr [ecx + 0x711]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */);
    // 00403c0d  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 00403c10  7533                   -jne 0x403c45
    if (!cpu.flags.zf)
    {
        goto L_0x00403c45;
    }
    // 00403c12  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00403c15  752e                   -jne 0x403c45
    if (!cpu.flags.zf)
    {
        goto L_0x00403c45;
    }
    // 00403c17  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00403c1a  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00403c1d  e8fea40000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00403c22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403c24  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403c2b  7402                   -je 0x403c2f
    if (cpu.flags.zf)
    {
        goto L_0x00403c2f;
    }
    // 00403c2d  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00403c2f:
    // 00403c2f  83f832                 +cmp eax, 0x32
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403c32  7e11                   -jle 0x403c45
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403c45;
    }
    // 00403c34  3b45f4                 +cmp eax, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403c37  7d0c                   -jge 0x403c45
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403c45;
    }
    // 00403c39  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00403c3b  7403                   -je 0x403c40
    if (cpu.flags.zf)
    {
        goto L_0x00403c40;
    }
    // 00403c3d  8975fc                 -mov dword ptr [ebp - 4], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
L_0x00403c40:
    // 00403c40  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00403c42  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00403c45:
    // 00403c45  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00403c46  eb9a                   -jmp 0x403be2
    goto L_0x00403be2;
L_0x00403c48:
    // 00403c48  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00403c4a  0f84d5000000           -je 0x403d25
    if (cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403c50  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00403c53  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403c55  0f84ca000000           -je 0x403d25
    if (cpu.flags.zf)
    {
        goto L_0x00403d25;
    }
    // 00403c5b  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00403c5e  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00403c61  e8baa40000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00403c66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403c68  3d90010000             +cmp eax, 0x190
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(400 /*0x190*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403c6d  0f8db2000000           -jge 0x403d25
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403d25;
    }
    // 00403c73  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00403c76  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00403c78  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00403c7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403c7c  7c13                   -jl 0x403c91
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403c91;
    }
    // 00403c7e  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00403c81  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00403c87  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00403c89  39d0                   +cmp eax, edx
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
    // 00403c8b  7c11                   -jl 0x403c9e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403c9e;
    }
    // 00403c8d  29d0                   +sub eax, edx
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
    // 00403c8f  eb0d                   -jmp 0x403c9e
    goto L_0x00403c9e;
L_0x00403c91:
    // 00403c91  03461c                 -add eax, dword ptr [esi + 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 00403c94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00403c96  7d06                   -jge 0x403c9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403c9e;
    }
    // 00403c98  030540d95d00           -add eax, dword ptr [0x5dd940]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
L_0x00403c9e:
    // 00403c9e  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00403ca1  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00403ca3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ca5  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00403ca8  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00403cad  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403caf  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00403cb2  8b9724060000           -mov edx, dword ptr [edi + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1572) /* 0x624 */);
    // 00403cb8  e873fbffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 00403cbd  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00403cc0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403cc2  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00403cc5  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00403cca  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ccc  668b9010070000         -mov dx, word ptr [eax + 0x710]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(1808) /* 0x710 */);
    // 00403cd3  c7803407000001000000   -mov dword ptr [eax + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 00403cdd  81ca10040000           -or edx, 0x410
    cpu.edx |= x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 00403ce3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ce5  66899010070000         -mov word ptr [eax + 0x710], dx
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(1808) /* 0x710 */) = cpu.dx;
    // 00403cec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403cee  8b9724060000           -mov edx, dword ptr [edi + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1572) /* 0x624 */);
    // 00403cf4  e837fbffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 00403cf9  668b9e10070000         -mov bx, word ptr [esi + 0x710]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1808) /* 0x710 */);
    // 00403d00  c7863407000001000000   -mov dword ptr [esi + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 00403d0a  81cb10040000           -or ebx, 0x410
    cpu.ebx |= x86::reg32(x86::sreg32(1040 /*0x410*/));
    // 00403d10  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00403d15  66899e10070000         -mov word ptr [esi + 0x710], bx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1808) /* 0x710 */) = cpu.bx;
    // 00403d1c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00403d1e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d1f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d20  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d21  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d22  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d23  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00403d25:
    // 00403d25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00403d27  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00403d29  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403d2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_403d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403d30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403d31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403d32  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403d33  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403d34  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403d35  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403d36  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403d38  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403d3a  8b9014070000           -mov edx, dword ptr [eax + 0x714]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1812) /* 0x714 */);
    // 00403d40  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00403d47  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00403d49  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00403d4c  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403d53  0f8582000000           -jne 0x403ddb
    if (!cpu.flags.zf)
    {
        goto L_0x00403ddb;
    }
    // 00403d59  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00403d5f  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00403d61  7407                   -je 0x403d6a
    if (cpu.flags.zf)
    {
        goto L_0x00403d6a;
    }
    // 00403d63  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00403d68  eb13                   -jmp 0x403d7d
    goto L_0x00403d7d;
L_0x00403d6a:
    // 00403d6a  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00403d6f  eb05                   -jmp 0x403d76
    goto L_0x00403d76;
    // 00403d71  83fb07                 +cmp ebx, 7
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
    // 00403d74  7c07                   -jl 0x403d7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403d7d;
    }
L_0x00403d76:
    // 00403d76  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00403d7b  eb02                   -jmp 0x403d7f
    goto L_0x00403d7f;
L_0x00403d7d:
    // 00403d7d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00403d7f:
    // 00403d7f  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00403d81  7405                   -je 0x403d88
    if (cpu.flags.zf)
    {
        goto L_0x00403d88;
    }
    // 00403d83  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00403d88:
    // 00403d88  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403d8f  7412                   -je 0x403da3
    if (cpu.flags.zf)
    {
        goto L_0x00403da3;
    }
    // 00403d91  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00403d96  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00403d98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00403d9a  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00403d9f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00403da1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00403da3:
    // 00403da3  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00403da9  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00403dac  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00403db2  e819600c00             -call 0x4c9dd0
    cpu.esp -= 4;
    sub_4c9dd0(app, cpu);
    if (cpu.terminate) return;
    // 00403db7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00403db9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403dbb  e8007c0000             -call 0x40b9c0
    cpu.esp -= 4;
    sub_40b9c0(app, cpu);
    if (cpu.terminate) return;
    // 00403dc0  8b8610070000           -mov eax, dword ptr [esi + 0x710]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */);
    // 00403dc6  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00403dc9  83f80f                 +cmp eax, 0xf
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
    // 00403dcc  7d06                   -jge 0x403dd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403dd4;
    }
    // 00403dce  ff8610070000           -inc dword ptr [esi + 0x710]
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */))++;
L_0x00403dd4:
    // 00403dd4  80a611070000df         -and byte ptr [esi + 0x711], 0xdf
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
L_0x00403ddb:
    // 00403ddb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ddc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ddd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403dde  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ddf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403de0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403de1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_403df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403df0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403df1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403df2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403df3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403df4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403df5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403df7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403df9  8b9814070000           -mov ebx, dword ptr [eax + 0x714]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1812) /* 0x714 */);
    // 00403dff  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00403e06  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00403e08  8b9630070000           -mov edx, dword ptr [esi + 0x730]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00403e0e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00403e11  8b521c                 -mov edx, dword ptr [edx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00403e14  8b8084d87d00           -mov eax, dword ptr [eax + 0x7dd884]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247428) /* 0x7dd884 */);
    // 00403e1a  e801a30000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00403e1f  8b15c0d46f00           -mov edx, dword ptr [0x6fd4c0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 00403e25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00403e27  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00403e29  7402                   -je 0x403e2d
    if (cpu.flags.zf)
    {
        goto L_0x00403e2d;
    }
    // 00403e2b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x00403e2d:
    // 00403e2d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403e2f  7d22                   -jge 0x403e53
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403e53;
    }
    // 00403e31  83f9e2                 +cmp ecx, -0x1e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-30 /*-0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403e34  7e1d                   -jle 0x403e53
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403e53;
    }
    // 00403e36  8aa611070000           -mov ah, byte ptr [esi + 0x711]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */);
    // 00403e3c  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00403e3f  7512                   -jne 0x403e53
    if (!cpu.flags.zf)
    {
        goto L_0x00403e53;
    }
    // 00403e41  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00403e43  80ca20                 -or dl, 0x20
    cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00403e46  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403e48  889611070000           -mov byte ptr [esi + 0x711], dl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) = cpu.dl;
    // 00403e4e  e84d7e0000             -call 0x40bca0
    cpu.esp -= 4;
    sub_40bca0(app, cpu);
    if (cpu.terminate) return;
L_0x00403e53:
    // 00403e53  83f9ce                 +cmp ecx, -0x32
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-50 /*-0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403e56  0f8f68000000           -jg 0x403ec4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403ec4;
    }
    // 00403e5c  a140d95d00             -mov eax, dword ptr [0x5dd940]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00403e61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403e63  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00403e66  c1e202                 +shl edx, 2
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
    // 00403e69  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00403e6b  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00403e6e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00403e70  39c1                   +cmp ecx, eax
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
    // 00403e72  7c50                   -jl 0x403ec4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403ec4;
    }
    // 00403e74  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00403e76  e8d5600c00             -call 0x4c9f50
    cpu.esp -= 4;
    sub_4c9f50(app, cpu);
    if (cpu.terminate) return;
    // 00403e7b  8ab611070000           -mov dh, byte ptr [esi + 0x711]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */);
    // 00403e81  80e6f7                 -and dh, 0xf7
    cpu.dh &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00403e84  8b8e30070000           -mov ecx, dword ptr [esi + 0x730]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00403e8a  88b611070000           -mov byte ptr [esi + 0x711], dh
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) = cpu.dh;
    // 00403e90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403e92  7412                   -je 0x403ea6
    if (cpu.flags.zf)
    {
        goto L_0x00403ea6;
    }
    // 00403e94  8b8128060000           -mov eax, dword ptr [ecx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00403e9a  3b7058                 +cmp esi, dword ptr [eax + 0x58]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403e9d  7507                   -jne 0x403ea6
    if (!cpu.flags.zf)
    {
        goto L_0x00403ea6;
    }
    // 00403e9f  c7405800000000         -mov dword ptr [eax + 0x58], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
L_0x00403ea6:
    // 00403ea6  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00403eac  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403eae  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00403eb1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403eb2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00403eb7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00403eb9  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403ebb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403ebd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403ebf  e86cf9ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
L_0x00403ec4:
    // 00403ec4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ec5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ec6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ec7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ec8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403ec9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_403ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403ed0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403ed1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403ed2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00403ed3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403ed4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403ed5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403ed7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403ed9  8b9630070000           -mov edx, dword ptr [esi + 0x730]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00403edf  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00403ee2  8b521c                 -mov edx, dword ptr [edx + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00403ee5  e836a20000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00403eea  8b15c0d46f00           -mov edx, dword ptr [0x6fd4c0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 00403ef0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00403ef2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00403ef4  7402                   -je 0x403ef8
    if (cpu.flags.zf)
    {
        goto L_0x00403ef8;
    }
    // 00403ef6  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x00403ef8:
    // 00403ef8  83f9fb                 +cmp ecx, -5
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-5 /*-0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403efb  0f8f6d000000           -jg 0x403f6e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403f6e;
    }
    // 00403f01  a140d95d00             -mov eax, dword ptr [0x5dd940]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00403f06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403f08  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00403f0b  c1e202                 +shl edx, 2
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
    // 00403f0e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00403f10  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00403f13  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00403f15  39c1                   +cmp ecx, eax
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
    // 00403f17  7c55                   -jl 0x403f6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00403f6e;
    }
    // 00403f19  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00403f1b  7d15                   -jge 0x403f32
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00403f32;
    }
    // 00403f1d  83f9ec                 +cmp ecx, -0x14
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-20 /*-0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403f20  7e10                   -jle 0x403f32
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00403f32;
    }
    // 00403f22  83be0c0700000a         +cmp dword ptr [esi + 0x70c], 0xa
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403f29  7507                   -jne 0x403f32
    if (!cpu.flags.zf)
    {
        goto L_0x00403f32;
    }
    // 00403f2b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403f2d  e8ce7d0000             -call 0x40bd00
    cpu.esp -= 4;
    sub_40bd00(app, cpu);
    if (cpu.terminate) return;
L_0x00403f32:
    // 00403f32  8aa611070000           -mov ah, byte ptr [esi + 0x711]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */);
    // 00403f38  80e4fb                 -and ah, 0xfb
    cpu.ah &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00403f3b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403f3d  88a611070000           -mov byte ptr [esi + 0x711], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) = cpu.ah;
    // 00403f43  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00403f48  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00403f4e  8a9621060000           -mov dl, byte ptr [esi + 0x621]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1569) /* 0x621 */);
    // 00403f54  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00403f57  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00403f5a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00403f5b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00403f5d  889621060000           -mov byte ptr [esi + 0x621], dl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1569) /* 0x621 */) = cpu.dl;
    // 00403f63  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00403f65  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00403f67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00403f69  e8c2f8ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
L_0x00403f6e:
    // 00403f6e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403f6f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403f70  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403f71  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403f72  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00403f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_403f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00403f80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00403f81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00403f82  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00403f83  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00403f84  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00403f85  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00403f87  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403f8a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00403f8c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00403f8e  a188fd5e00             -mov eax, dword ptr [0x5efd88]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */);
    // 00403f93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00403f95  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 00403f9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00403f9d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00403f9f  83f801                 +cmp eax, 1
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
    // 00403fa2  7f05                   -jg 0x403fa9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403fa9;
    }
    // 00403fa4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00403fa9:
    // 00403fa9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00403fab  a188fd5e00             -mov eax, dword ptr [0x5efd88]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */);
    // 00403fb0  48                     -dec eax
    (cpu.eax)--;
    // 00403fb1  83f801                 +cmp eax, 1
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
    // 00403fb4  7f05                   -jg 0x403fbb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00403fbb;
    }
    // 00403fb6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00403fbb:
    // 00403fbb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00403fbd  8b8100020000           -mov eax, dword ptr [ecx + 0x200]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(512) /* 0x200 */);
    // 00403fc3  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00403fc6  8b91c4020000           -mov edx, dword ptr [ecx + 0x2c4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */);
    // 00403fcc  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00403fcf  83fa04                 +cmp edx, 4
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
    // 00403fd2  0f8485000000           -je 0x40405d
    if (cpu.flags.zf)
    {
        goto L_0x0040405d;
    }
    // 00403fd8  8b9128060000           -mov edx, dword ptr [ecx + 0x628]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00403fde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00403fe0  7412                   -je 0x403ff4
    if (cpu.flags.zf)
    {
        goto L_0x00403ff4;
    }
    // 00403fe2  3b8b30070000           +cmp ecx, dword ptr [ebx + 0x730]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1840) /* 0x730 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403fe8  750a                   -jne 0x403ff4
    if (!cpu.flags.zf)
    {
        goto L_0x00403ff4;
    }
    // 00403fea  a188fd5e00             -mov eax, dword ptr [0x5efd88]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */);
    // 00403fef  e96b000000             -jmp 0x40405f
    goto L_0x0040405f;
L_0x00403ff4:
    // 00403ff4  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00403ff8  7527                   -jne 0x404021
    if (!cpu.flags.zf)
    {
        goto L_0x00404021;
    }
    // 00403ffa  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00403ffd  e83ead0000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 00404002  dc0504615300           +fadd qword ptr [0x536104]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(x86::reg32(5464324) /* 0x536104 */));
    // 00404008  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040400e  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00404010  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00404012  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00404013  770c                   -ja 0x404021
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00404021;
    }
    // 00404015  81b9f006000000000040   +cmp dword ptr [ecx + 0x6f0], 0x40000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1776) /* 0x6f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040401f  7e3c                   -jle 0x40405d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040405d;
    }
L_0x00404021:
    // 00404021  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404025  741b                   -je 0x404042
    if (cpu.flags.zf)
    {
        goto L_0x00404042;
    }
    // 00404027  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00404029  2b422c                 -sub eax, dword ptr [edx + 0x2c]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 0040402c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040402e  7e08                   -jle 0x404038
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00404038;
    }
    // 00404030  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404032  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404033  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404034  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404035  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404036  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404037  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404038:
    // 00404038  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040403a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040403c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040403d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040403e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040403f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404040  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404041  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404042:
    // 00404042  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00404044  2b422c                 -sub eax, dword ptr [edx + 0x2c]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 00404047  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404049  7e08                   -jle 0x404053
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00404053;
    }
    // 0040404b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040404d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040404e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040404f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404050  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404051  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404052  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404053:
    // 00404053  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404055  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404057  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404058  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404059  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040405a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040405b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040405c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040405d:
    // 0040405d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040405f:
    // 0040405f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404061  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404062  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404063  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404064  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404065  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404066  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_404070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404070  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404071  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404072  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404074  8b9028060000           -mov edx, dword ptr [eax + 0x628]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 0040407a  837a2c01               +cmp dword ptr [edx + 0x2c], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040407e  751f                   -jne 0x40409f
    if (!cpu.flags.zf)
    {
        goto L_0x0040409f;
    }
    // 00404080  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404084  7411                   -je 0x404097
    if (cpu.flags.zf)
    {
        goto L_0x00404097;
    }
    // 00404086  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040408d  7508                   -jne 0x404097
    if (!cpu.flags.zf)
    {
        goto L_0x00404097;
    }
    // 0040408f  e89c740000             -call 0x40b530
    cpu.esp -= 4;
    sub_40b530(app, cpu);
    if (cpu.terminate) return;
    // 00404094  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404095  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404096  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404097:
    // 00404097  e884710000             -call 0x40b220
    cpu.esp -= 4;
    sub_40b220(app, cpu);
    if (cpu.terminate) return;
    // 0040409c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040409d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040409e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040409f:
    // 0040409f  e88c720000             -call 0x40b330
    cpu.esp -= 4;
    sub_40b330(app, cpu);
    if (cpu.terminate) return;
    // 004040a4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040a5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4040b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004040b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004040b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004040b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004040b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004040b4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004040b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004040b7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004040b9  e8c2730000             -call 0x40b480
    cpu.esp -= 4;
    sub_40b480(app, cpu);
    if (cpu.terminate) return;
    // 004040be  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004040c0  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004040c2  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004040c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004040c9  6a06                   -push 6
    *app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004040cb  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004040ce  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004040d0  e85bf7ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 004040d5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040d6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040d7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040d8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040d9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004040da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4040e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004040e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004040e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004040e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004040e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004040e4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004040e5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004040e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004040e8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004040eb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004040ed  8b8028060000           -mov eax, dword ptr [eax + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 004040f3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004040f5  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004040f8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004040fa  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004040fd  e86e750000             -call 0x40b670
    cpu.esp -= 4;
    sub_40b670(app, cpu);
    if (cpu.terminate) return;
L_0x00404102:
    // 00404102  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00404105  3b0588fd5e00           +cmp eax, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040410b  0f8dc1000000           -jge 0x4041d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004041d2;
    }
    // 00404111  8b348588fa5e00         -mov esi, dword ptr [eax*4 + 0x5efa88]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.eax * 4);
    // 00404118  8aa600020000           -mov ah, byte ptr [esi + 0x200]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */);
    // 0040411e  c6868a00000000         -mov byte ptr [esi + 0x8a], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(138) /* 0x8a */) = 0 /*0x0*/;
    // 00404125  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00404128  0f859c000000           -jne 0x4041ca
    if (!cpu.flags.zf)
    {
        goto L_0x004041ca;
    }
    // 0040412e  8b8630070000           -mov eax, dword ptr [esi + 0x730]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00404134  8b9f24060000           -mov ebx, dword ptr [edi + 0x624]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1572) /* 0x624 */);
    // 0040413a  8b9614070000           -mov edx, dword ptr [esi + 0x714]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00404140  39d8                   +cmp eax, ebx
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
    // 00404142  0f8582000000           -jne 0x4041ca
    if (!cpu.flags.zf)
    {
        goto L_0x004041ca;
    }
    // 00404148  8a9e11070000           -mov bl, byte ptr [esi + 0x711]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */);
    // 0040414e  c7863007000000000000   -mov dword ptr [esi + 0x730], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */) = 0 /*0x0*/;
    // 00404158  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0040415b  7431                   -je 0x40418e
    if (cpu.flags.zf)
    {
        goto L_0x0040418e;
    }
    // 0040415d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00404164  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00404166  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00404168  80e7f7                 -and bh, 0xf7
    cpu.bh &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0040416b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0040416e  88be11070000           -mov byte ptr [esi + 0x711], bh
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1809) /* 0x711 */) = cpu.bh;
    // 00404174  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040417b  7407                   -je 0x404184
    if (cpu.flags.zf)
    {
        goto L_0x00404184;
    }
    // 0040417d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040417f  e8cc5d0c00             -call 0x4c9f50
    cpu.esp -= 4;
    sub_4c9f50(app, cpu);
    if (cpu.terminate) return;
L_0x00404184:
    // 00404184  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00404187  c7405800000000         -mov dword ptr [eax + 0x58], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = 0 /*0x0*/;
L_0x0040418e:
    // 0040418e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404190  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00404195  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 0040419b  668b9610070000         -mov dx, word ptr [esi + 0x710]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1808) /* 0x710 */);
    // 004041a2  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004041a5  81e2effbffff           -and edx, 0xfffffbef
    cpu.edx &= x86::reg32(x86::sreg32(4294966255 /*0xfffffbef*/));
    // 004041ab  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004041ac  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004041ae  66899610070000         -mov word ptr [esi + 0x710], dx
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1808) /* 0x710 */) = cpu.dx;
    // 004041b5  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004041b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004041b9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004041bb  c7863407000000000000   -mov dword ptr [esi + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 004041c5  e866f6ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
L_0x004041ca:
    // 004041ca  ff45fc                 +inc dword ptr [ebp - 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004041cd  e930ffffff             -jmp 0x404102
    goto L_0x00404102;
L_0x004041d2:
    // 004041d2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004041d4:
    // 004041d4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004041d7  3b782c                 +cmp edi, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004041da  0f8db9000000           -jge 0x404299
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404299;
    }
    // 004041e0  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004041e3  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004041ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004041ec  8b7030                 -mov esi, dword ptr [eax + 0x30]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004041ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004041f1  0f8489000000           -je 0x404280
    if (cpu.flags.zf)
    {
        goto L_0x00404280;
    }
    // 004041f7  c7862806000000000000   -mov dword ptr [esi + 0x628], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1576) /* 0x628 */) = 0 /*0x0*/;
    // 00404201  c7862406000000000000   -mov dword ptr [esi + 0x624], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 0040420b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00404210  c7863007000000000000   -mov dword ptr [esi + 0x730], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */) = 0 /*0x0*/;
    // 0040421a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040421c  8a8e10070000           -mov cl, byte ptr [esi + 0x710]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1808) /* 0x710 */);
    // 00404222  c7863407000000000000   -mov dword ptr [esi + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 0040422c  80e16f                 -and cl, 0x6f
    cpu.cl &= x86::reg8(x86::sreg8(111 /*0x6f*/));
    // 0040422f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00404231  888e10070000           -mov byte ptr [esi + 0x710], cl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1808) /* 0x710 */) = cpu.cl;
    // 00404237  e8941d0000             -call 0x405fd0
    cpu.esp -= 4;
    sub_405fd0(app, cpu);
    if (cpu.terminate) return;
    // 0040423c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040423e  e8edd0ffff             -call 0x401330
    cpu.esp -= 4;
    sub_401330(app, cpu);
    if (cpu.terminate) return;
    // 00404243  f6860002000004         +test byte ptr [esi + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040424a  7416                   -je 0x404262
    if (cpu.flags.zf)
    {
        goto L_0x00404262;
    }
    // 0040424c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040424e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00404250  e8cb0f0000             -call 0x405220
    cpu.esp -= 4;
    sub_405220(app, cpu);
    if (cpu.terminate) return;
    // 00404255  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 0040425b  e8f05c0c00             -call 0x4c9f50
    cpu.esp -= 4;
    sub_4c9f50(app, cpu);
    if (cpu.terminate) return;
    // 00404260  eb1e                   -jmp 0x404280
    goto L_0x00404280;
L_0x00404262:
    // 00404262  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00404268  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040426a  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0040426d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040426e  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00404273  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00404275  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404277  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00404279  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040427b  e8b0f5ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
L_0x00404280:
    // 00404280  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00404283  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 0040428a  01c8                   +add eax, ecx
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
    // 0040428c  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040428d  c7403000000000         -mov dword ptr [eax + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00404294  e93bffffff             -jmp 0x4041d4
    goto L_0x004041d4;
L_0x00404299:
    // 00404299  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040429b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040429c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040429d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040429e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040429f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042a0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4042b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004042b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004042b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004042b2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004042b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004042b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004042b7  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004042be  743e                   -je 0x4042fe
    if (cpu.flags.zf)
    {
        goto L_0x004042fe;
    }
    // 004042c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004042c2  e859d7ffff             -call 0x401a20
    cpu.esp -= 4;
    sub_401a20(app, cpu);
    if (cpu.terminate) return;
    // 004042c7  c7822806000000000000   -mov dword ptr [edx + 0x628], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */) = 0 /*0x0*/;
    // 004042d1  c7822406000000000000   -mov dword ptr [edx + 0x624], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 004042db  c7823007000000000000   -mov dword ptr [edx + 0x730], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1840) /* 0x730 */) = 0 /*0x0*/;
    // 004042e5  8a9a10070000           -mov bl, byte ptr [edx + 0x710]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */);
    // 004042eb  c7823407000000000000   -mov dword ptr [edx + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 004042f5  80e36f                 -and bl, 0x6f
    cpu.bl &= x86::reg8(x86::sreg8(111 /*0x6f*/));
    // 004042f8  889a10070000           -mov byte ptr [edx + 0x710], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.bl;
L_0x004042fe:
    // 004042fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004042ff  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404300  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404301  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_404310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404310  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404311  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404312  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404313  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404314  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404316  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404318  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040431a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0040431f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404321  8b9030070000           -mov edx, dword ptr [eax + 0x730]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1840) /* 0x730 */);
    // 00404327  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00404329  e802f5ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 0040432e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040432f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404330  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404331  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404332  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_404340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404340  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404341  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404342  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404343  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404344  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404345  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404347  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00404349  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040434b  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040434e  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00404351  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00404353  e8c89d0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00404358  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040435a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040435d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040435f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00404361  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00404363  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00404365  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00404367  7c0e                   -jl 0x404377
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404377;
    }
    // 00404369  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040436f  39d0                   +cmp eax, edx
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
    // 00404371  7c0e                   -jl 0x404381
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404381;
    }
    // 00404373  29d0                   +sub eax, edx
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
    // 00404375  eb0a                   -jmp 0x404381
    goto L_0x00404381;
L_0x00404377:
    // 00404377  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404379  7d06                   -jge 0x404381
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404381;
    }
    // 0040437b  030540d95d00           -add eax, dword ptr [0x5dd940]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
L_0x00404381:
    // 00404381  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404383  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00404385  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0040438a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040438c  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0040438e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00404390  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00404392  e899f4ffff             -call 0x403830
    cpu.esp -= 4;
    sub_403830(app, cpu);
    if (cpu.terminate) return;
    // 00404397  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404398  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404399  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040439a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040439b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040439c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4043a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004043a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004043a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004043a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004043a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004043a4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004043a5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004043a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004043a8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004043ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004043ad  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 004043b2  8b9824060000           -mov ebx, dword ptr [eax + 0x624]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 004043b8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004043ba  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004043bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004043bf  0f8489010000           -je 0x40454e
    if (cpu.flags.zf)
    {
        goto L_0x0040454e;
    }
    // 004043c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004043c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004043c9  e8b2fbffff             -call 0x403f80
    cpu.esp -= 4;
    sub_403f80(app, cpu);
    if (cpu.terminate) return;
    // 004043ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004043d0  0f8478010000           -je 0x40454e
    if (cpu.flags.zf)
    {
        goto L_0x0040454e;
    }
    // 004043d6  8b8e28060000           -mov ecx, dword ptr [esi + 0x628]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1576) /* 0x628 */);
    // 004043dc  8a6154                 -mov ah, byte ptr [ecx + 0x54]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 004043df  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004043e2  752a                   -jne 0x40440e
    if (!cpu.flags.zf)
    {
        goto L_0x0040440e;
    }
    // 004043e4  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004043e7  7525                   -jne 0x40440e
    if (!cpu.flags.zf)
    {
        goto L_0x0040440e;
    }
    // 004043e9  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004043ec  7520                   -jne 0x40440e
    if (!cpu.flags.zf)
    {
        goto L_0x0040440e;
    }
    // 004043ee  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004043f3  2b4120                 -sub eax, dword ptr [ecx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */)));
    // 004043f6  3d80020000             +cmp eax, 0x280
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004043fb  7e11                   -jle 0x40440e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040440e;
    }
    // 004043fd  83792c01               +cmp dword ptr [ecx + 0x2c], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404401  750b                   -jne 0x40440e
    if (!cpu.flags.zf)
    {
        goto L_0x0040440e;
    }
    // 00404403  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00404405  e816730000             -call 0x40b720
    cpu.esp -= 4;
    sub_40b720(app, cpu);
    if (cpu.terminate) return;
    // 0040440a  80495401               -or byte ptr [ecx + 0x54], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(84) /* 0x54 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0040440e:
    // 0040440e  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00404411  8b731c                 -mov esi, dword ptr [ebx + 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 00404414  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00404416  e8059d0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040441b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040441d  8945ec                 -mov dword ptr [ebp - 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00404420  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
L_0x00404423:
    // 00404423  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00404426  3b0588fd5e00           +cmp eax, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040442c  0f8d06010000           -jge 0x404538
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404538;
    }
    // 00404432  8b0c8588fa5e00         -mov ecx, dword ptr [eax*4 + 0x5efa88]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.eax * 4);
    // 00404439  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00404440  0f85ea000000           -jne 0x404530
    if (!cpu.flags.zf)
    {
        goto L_0x00404530;
    }
    // 00404446  83b92406000000         +cmp dword ptr [ecx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040444d  0f85dd000000           -jne 0x404530
    if (!cpu.flags.zf)
    {
        goto L_0x00404530;
    }
    // 00404453  8a9111070000           -mov dl, byte ptr [ecx + 0x711]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */);
    // 00404459  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0040445c  0f85ce000000           -jne 0x404530
    if (!cpu.flags.zf)
    {
        goto L_0x00404530;
    }
    // 00404462  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00404465  0f85c5000000           -jne 0x404530
    if (!cpu.flags.zf)
    {
        goto L_0x00404530;
    }
    // 0040446b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040446d  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00404470  e8ab9c0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00404475  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00404477  f6811107000001         +test byte ptr [ecx + 0x711], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1809) /* 0x711 */) & 1 /*0x1*/));
    // 0040447e  0f8472000000           -je 0x4044f6
    if (cpu.flags.zf)
    {
        goto L_0x004044f6;
    }
    // 00404484  83b90c07000007         +cmp dword ptr [ecx + 0x70c], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040448b  0f849f000000           -je 0x404530
    if (cpu.flags.zf)
    {
        goto L_0x00404530;
    }
    // 00404491  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404498  7408                   -je 0x4044a2
    if (cpu.flags.zf)
    {
        goto L_0x004044a2;
    }
    // 0040449a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040449c  0f8d8e000000           -jge 0x404530
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404530;
    }
L_0x004044a2:
    // 004044a2  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004044a9  7508                   -jne 0x4044b3
    if (!cpu.flags.zf)
    {
        goto L_0x004044b3;
    }
    // 004044ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004044ad  0f8c7d000000           -jl 0x404530
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404530;
    }
L_0x004044b3:
    // 004044b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004044b5  7e04                   -jle 0x4044bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004044bb;
    }
    // 004044b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004044b9  eb04                   -jmp 0x4044bf
    goto L_0x004044bf;
L_0x004044bb:
    // 004044bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004044bd  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004044bf:
    // 004044bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004044c1  7e05                   -jle 0x4044c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004044c8;
    }
    // 004044c3  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004044c6  eb0a                   -jmp 0x4044d2
    goto L_0x004044d2;
L_0x004044c8:
    // 004044c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004044ca  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004044cd  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004044cf  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x004044d2:
    // 004044d2  8b83c8020000           -mov eax, dword ptr [ebx + 0x2c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 004044d8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004044db  8b80ac215500           -mov eax, dword ptr [eax + 0x5521ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5579180) /* 0x5521ac */);
    // 004044e1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004044e4  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004044e7  39d0                   +cmp eax, edx
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
    // 004044e9  7245                   -jb 0x404530
    if (cpu.flags.cf)
    {
        goto L_0x00404530;
    }
    // 004044eb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004044ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004044ef  e84cfeffff             -call 0x404340
    cpu.esp -= 4;
    sub_404340(app, cpu);
    if (cpu.terminate) return;
    // 004044f4  eb3a                   -jmp 0x404530
    goto L_0x00404530;
L_0x004044f6:
    // 004044f6  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004044f9  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004044fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004044fd  7d31                   -jge 0x404530
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404530;
    }
    // 004044ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404501  7f05                   -jg 0x404508
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404508;
    }
    // 00404503  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00404506  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x00404508:
    // 00404508  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040450b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040450e  3b45f0                 +cmp eax, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404511  7d1d                   -jge 0x404530
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404530;
    }
    // 00404513  8b83c8020000           -mov eax, dword ptr [ebx + 0x2c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(712) /* 0x2c8 */);
    // 00404519  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0040451c  8b80ac215500           -mov eax, dword ptr [eax + 0x5521ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5579180) /* 0x5521ac */);
    // 00404522  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00404525  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00404527  39d0                   +cmp eax, edx
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
    // 00404529  7205                   -jb 0x404530
    if (cpu.flags.cf)
    {
        goto L_0x00404530;
    }
    // 0040452b  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040452d  8955f0                 -mov dword ptr [ebp - 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x00404530:
    // 00404530  ff45f8                 +inc dword ptr [ebp - 8]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00404533  e9ebfeffff             -jmp 0x404423
    goto L_0x00404423;
L_0x00404538:
    // 00404538  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040453a  7412                   -je 0x40454e
    if (cpu.flags.zf)
    {
        goto L_0x0040454e;
    }
    // 0040453c  83bf0c07000007         +cmp dword ptr [edi + 0x70c], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1804) /* 0x70c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404543  7409                   -je 0x40454e
    if (cpu.flags.zf)
    {
        goto L_0x0040454e;
    }
    // 00404545  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00404547  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00404549  e8f2fdffff             -call 0x404340
    cpu.esp -= 4;
    sub_404340(app, cpu);
    if (cpu.terminate) return;
L_0x0040454e:
    // 0040454e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404550  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404551  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404552  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404553  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404554  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404555  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_404560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404560  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404561  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404563  8b80ac070000           -mov eax, dword ptr [eax + 0x7ac]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */);
    // 00404569  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040456d  7404                   -je 0x404573
    if (cpu.flags.zf)
    {
        goto L_0x00404573;
    }
    // 0040456f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404571  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404572  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404573:
    // 00404573  c6400101               -mov byte ptr [eax + 1], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 1 /*0x1*/;
    // 00404577  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040457c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040457d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_404580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404580  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404581  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404583  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404584  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_404590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404590  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404591  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404593  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404594  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045a0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045a3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045b0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045b3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045c0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045c3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045d0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045d3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045e0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045e3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4045f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004045f0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004045f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004045f3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004045f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_404600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404600  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404601  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404603  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404604  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_404610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404610  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404611  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404612  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404614  8b8020020000           -mov eax, dword ptr [eax + 0x220]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 0040461a  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 0040461d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00404624  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00404626  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0040462c  8b04c574225500         -mov eax, dword ptr [eax*8 + 0x552274]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5579380) /* 0x552274 */ + cpu.eax * 8);
    // 00404633  83fa01                 +cmp edx, 1
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
    // 00404636  7405                   -je 0x40463d
    if (cpu.flags.zf)
    {
        goto L_0x0040463d;
    }
    // 00404638  83fa02                 +cmp edx, 2
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
    // 0040463b  7509                   -jne 0x404646
    if (!cpu.flags.zf)
    {
        goto L_0x00404646;
    }
L_0x0040463d:
    // 0040463d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040463f  7505                   -jne 0x404646
    if (!cpu.flags.zf)
    {
        goto L_0x00404646;
    }
    // 00404641  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00404646:
    // 00404646  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404647  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404648  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_404650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404650  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404651  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404653  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404654  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_404660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404660  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404661  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404663  e8e8ffffff             -call 0x404650
    cpu.esp -= 4;
    sub_404650(app, cpu);
    if (cpu.terminate) return;
    // 00404668  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404669  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_404690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00404690  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404691  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404692  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404693  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404694  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404695  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404696  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404698  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040469b  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004046a2  0f853c010000           -jne 0x4047e4
    if (!cpu.flags.zf)
    {
        goto L_0x004047e4;
    }
    // 004046a8  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004046ae  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004046b5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004046b7  c7049570ea5600d7a3703f -mov dword ptr [edx*4 + 0x56ea70], 0x3f70a3d7
    *app->getMemory<x86::reg32>(x86::reg32(5696112) /* 0x56ea70 */ + cpu.edx * 4) = 1064346583 /*0x3f70a3d7*/;
    // 004046c2  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004046c8  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004046cf  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004046d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004046d3  891c9574ea5600         -mov dword ptr [edx*4 + 0x56ea74], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5696116) /* 0x56ea74 */ + cpu.edx * 4) = cpu.ebx;
    // 004046da  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004046e0  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 004046e7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004046e9  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 004046ee  89349578ea5600         -mov dword ptr [edx*4 + 0x56ea78], esi
    *app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */ + cpu.edx * 4) = cpu.esi;
    // 004046f5  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004046fb  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 00404702  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00404704  c704957cea56003c000000 -mov dword ptr [edx*4 + 0x56ea7c], 0x3c
    *app->getMemory<x86::reg32>(x86::reg32(5696124) /* 0x56ea7c */ + cpu.edx * 4) = 60 /*0x3c*/;
    // 0040470f  8b8820020000           -mov ecx, dword ptr [eax + 0x220]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00404715  8b4930                 -mov ecx, dword ptr [ecx + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00404718  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0040471f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00404721  8b14d57c225500         -mov edx, dword ptr [edx*8 + 0x55227c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5579388) /* 0x55227c */ + cpu.edx * 8);
    // 00404728  83fa05                 +cmp edx, 5
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
    // 0040472b  7729                   -ja 0x404756
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00404756;
    }
    // 0040472d  ff24956c464000         -jmp dword ptr [edx*4 + 0x40466c]
    cpu.ip = *app->getMemory<x86::reg32>(4212332 + cpu.edx * 4); goto dynamic_jump;
  case 0x00404734:
    // 00404734  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00404739  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040473e  be6e000000             -mov esi, 0x6e
    cpu.esi = 110 /*0x6e*/;
    // 00404743  eb4e                   -jmp 0x404793
    goto L_0x00404793;
  case 0x00404745:
    // 00404745  bb60000000             -mov ebx, 0x60
    cpu.ebx = 96 /*0x60*/;
    // 0040474a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0040474f  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
    // 00404754  eb3d                   -jmp 0x404793
    goto L_0x00404793;
  case 0x00404756:
L_0x00404756:
    // 00404756  bb60000000             -mov ebx, 0x60
    cpu.ebx = 96 /*0x60*/;
    // 0040475b  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00404760  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 00404765  eb2c                   -jmp 0x404793
    goto L_0x00404793;
  case 0x00404767:
    // 00404767  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0040476c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00404771  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 00404776  eb1b                   -jmp 0x404793
    goto L_0x00404793;
  case 0x00404778:
    // 00404778  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0040477d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00404782  eb0f                   -jmp 0x404793
    goto L_0x00404793;
  case 0x00404784:
    // 00404784  bbc0000000             -mov ebx, 0xc0
    cpu.ebx = 192 /*0xc0*/;
    // 00404789  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040478e  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
L_0x00404793:
    // 00404793  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00404799  894dfc                 -mov dword ptr [ebp - 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0040479c  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040479f  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004047a2  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004047a4  89348d78ea5600         -mov dword ptr [ecx*4 + 0x56ea78], esi
    *app->getMemory<x86::reg32>(x86::reg32(5696120) /* 0x56ea78 */ + cpu.ecx * 4) = cpu.esi;
    // 004047ab  8bb0f0010000           -mov esi, dword ptr [eax + 0x1f0]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004047b1  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 004047b8  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004047ba  891c8d7cea5600         -mov dword ptr [ecx*4 + 0x56ea7c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5696124) /* 0x56ea7c */ + cpu.ecx * 4) = cpu.ebx;
    // 004047c1  8b0df0d46f00           -mov ecx, dword ptr [0x6fd4f0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(7329008) /* 0x6fd4f0 */);
    // 004047c7  83f901                 +cmp ecx, 1
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
    // 004047ca  7502                   -jne 0x4047ce
    if (!cpu.flags.zf)
    {
        goto L_0x004047ce;
    }
    // 004047cc  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004047ce:
    // 004047ce  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004047d4  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004047db  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004047dd  89148580ea5600         -mov dword ptr [eax*4 + 0x56ea80], edx
    *app->getMemory<x86::reg32>(x86::reg32(5696128) /* 0x56ea80 */ + cpu.eax * 4) = cpu.edx;
L_0x004047e4:
    // 004047e4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004047e6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047e7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047e8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047e9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047ea  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047eb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004047ec  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4047f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004047f0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004047f1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004047f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004047f4  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004047f7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004047fe  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00404800  8b04c56c225500         -mov eax, dword ptr [eax*8 + 0x55226c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5579372) /* 0x55226c */ + cpu.eax * 8);
    // 00404807  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404808  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404809  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_404810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404810  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404811  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404812  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404814  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00404817  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040481e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00404820  8b04c580225500         -mov eax, dword ptr [eax*8 + 0x552280]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5579392) /* 0x552280 */ + cpu.eax * 8);
    // 00404827  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404828  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404829  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_404840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00404840  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404841  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404842  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404843  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404844  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404845  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404846  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404848  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040484b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040484d  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00404853  81fa80040000           +cmp edx, 0x480
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404859  7e43                   -jle 0x40489e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040489e;
    }
    // 0040485b  81fac0040000           +cmp edx, 0x4c0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1216 /*0x4c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404861  7d3b                   -jge 0x40489e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040489e;
    }
    // 00404863  a1c8fa5e00             -mov eax, dword ptr [0x5efac8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */);
    // 00404868  80b80d05000000         +cmp byte ptr [eax + 0x50d], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1293) /* 0x50d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040486f  742d                   -je 0x40489e
    if (cpu.flags.zf)
    {
        goto L_0x0040489e;
    }
    // 00404871  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 00404877  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040487a  83ea03                 -sub edx, 3
    (cpu.edx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040487d  39da                   +cmp edx, ebx
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
    // 0040487f  7d1d                   -jge 0x40489e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040489e;
    }
    // 00404881  3b1d40d95d00           +cmp ebx, dword ptr [0x5dd940]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404887  7d15                   -jge 0x40489e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040489e;
    }
    // 00404889  a148fa5e00             -mov eax, dword ptr [0x5efa48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */);
    // 0040488e  c786e406000050c30000   -mov dword ptr [esi + 0x6e4], 0xc350
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1764) /* 0x6e4 */) = 50000 /*0xc350*/;
    // 00404898  898624060000           -mov dword ptr [esi + 0x624], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1572) /* 0x624 */) = cpu.eax;
L_0x0040489e:
    // 0040489e  f6860002000008         +test byte ptr [esi + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 004048a5  0f8444010000           -je 0x4049ef
    if (cpu.flags.zf)
    {
        goto L_0x004049ef;
    }
    // 004048ab  8b86e4060000           -mov eax, dword ptr [esi + 0x6e4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1764) /* 0x6e4 */);
    // 004048b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004048b3  7e09                   -jle 0x4048be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004048be;
    }
    // 004048b5  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004048b8  8996e4060000           -mov dword ptr [esi + 0x6e4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1764) /* 0x6e4 */) = cpu.edx;
L_0x004048be:
    // 004048be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004048c0  e8eb950000             -call 0x40deb0
    cpu.esp -= 4;
    sub_40deb0(app, cpu);
    if (cpu.terminate) return;
    // 004048c5  833d3cef560000         +cmp dword ptr [0x56ef3c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5697340) /* 0x56ef3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004048cc  0f841d010000           -je 0x4049ef
    if (cpu.flags.zf)
    {
        goto L_0x004049ef;
    }
    // 004048d2  833d48ef560001         +cmp dword ptr [0x56ef48], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004048d9  0f8f10010000           -jg 0x4049ef
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004049ef;
    }
    // 004048df  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004048e1  d89eb0070000           +fcomp dword ptr [esi + 0x7b0]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.esi + x86::reg32(1968) /* 0x7b0 */));
    cpu.fpu.pop();
    // 004048e7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004048e9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004048ea  730b                   -jae 0x4048f7
    if (!cpu.flags.cf)
    {
        goto L_0x004048f7;
    }
    // 004048ec  8b86b0070000           -mov eax, dword ptr [esi + 0x7b0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1968) /* 0x7b0 */);
    // 004048f2  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004048f5  eb0b                   -jmp 0x404902
    goto L_0x00404902;
L_0x004048f7:
    // 004048f7  d986b0070000           +fld dword ptr [esi + 0x7b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(1968) /* 0x7b0 */)));
    // 004048fd  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004048ff  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00404902:
    // 00404902  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00404905  d986c4070000           +fld dword ptr [esi + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.esi + x86::reg32(1988) /* 0x7c4 */)));
    // 0040490b  dc0594615300           +fadd qword ptr [0x536194]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<double>(x86::reg32(5464468) /* 0x536194 */));
    // 00404911  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00404913  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00404915  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00404916  0f83d3000000           -jae 0x4049ef
    if (!cpu.flags.cf)
    {
        goto L_0x004049ef;
    }
    // 0040491c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040491e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00404920  e82ba70000             -call 0x40f050
    cpu.esp -= 4;
    sub_40f050(app, cpu);
    if (cpu.terminate) return;
    // 00404925  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404927  0f85c2000000           -jne 0x4049ef
    if (!cpu.flags.zf)
    {
        goto L_0x004049ef;
    }
    // 0040492d  f6862006000008         +test byte ptr [esi + 0x620], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1568) /* 0x620 */) & 8 /*0x8*/));
    // 00404934  7507                   -jne 0x40493d
    if (!cpu.flags.zf)
    {
        goto L_0x0040493d;
    }
    // 00404936  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00404938  e813950000             -call 0x40de50
    cpu.esp -= 4;
    sub_40de50(app, cpu);
    if (cpu.terminate) return;
L_0x0040493d:
    // 0040493d  a13cef5600             -mov eax, dword ptr [0x56ef3c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5697340) /* 0x56ef3c */);
    // 00404942  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00404949  0f84a0000000           -je 0x4049ef
    if (cpu.flags.zf)
    {
        goto L_0x004049ef;
    }
    // 0040494f  f60584367d00c0         +test byte ptr [0x7d3684], 0xc0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(8205956) /* 0x7d3684 */) & 192 /*0xc0*/));
    // 00404956  0f8593000000           -jne 0x4049ef
    if (!cpu.flags.zf)
    {
        goto L_0x004049ef;
    }
    // 0040495c  8b3d184f5500           -mov edi, dword ptr [0x554f18]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 00404962  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 00404967  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0040496a  a3144f5500             -mov dword ptr [0x554f14], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 0040496f  8b15144f5500           -mov edx, dword ptr [0x554f14]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 00404975  81e200ffff00           -and edx, 0xffff00
    cpu.edx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0040497b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00404980  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00404983  a3104f5500             -mov dword ptr [0x554f10], eax
    *app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 00404988  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040498f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00404991  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00404994  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00404997  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040499a  83f803                 +cmp eax, 3
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
    // 0040499d  773a                   -ja 0x4049d9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004049d9;
    }
    // 0040499f  ff24852c484000         -jmp dword ptr [eax*4 + 0x40482c]
    cpu.ip = *app->getMemory<x86::reg32>(4212780 + cpu.eax * 4); goto dynamic_jump;
  case 0x004049a6:
    // 004049a6  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004049ab  bb18000000             -mov ebx, 0x18
    cpu.ebx = 24 /*0x18*/;
    // 004049b0  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004049b5  eb31                   -jmp 0x4049e8
    goto L_0x004049e8;
  case 0x004049b7:
    // 004049b7  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 004049bc  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004049c1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004049c6  eb20                   -jmp 0x4049e8
    goto L_0x004049e8;
  case 0x004049c8:
    // 004049c8  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004049cd  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 004049d2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004049d7  eb0f                   -jmp 0x4049e8
    goto L_0x004049e8;
  case 0x004049d9:
L_0x004049d9:
    // 004049d9  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004049de  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004049e3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004049e8:
    // 004049e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004049ea  e861cd0000             -call 0x411750
    cpu.esp -= 4;
    sub_411750(app, cpu);
    if (cpu.terminate) return;
L_0x004049ef:
    // 004049ef  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004049f1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004049f7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_404a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404a00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404a01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404a02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404a03  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404a04  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404a05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404a07  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00404a09  8b986c010000           -mov ebx, dword ptr [eax + 0x16c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */);
    // 00404a0f  f6830002000001         +test byte ptr [ebx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00404a16  741e                   -je 0x404a36
    if (cpu.flags.zf)
    {
        goto L_0x00404a36;
    }
    // 00404a18  f6810002000020         +test byte ptr [ecx + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 00404a1f  7415                   -je 0x404a36
    if (cpu.flags.zf)
    {
        goto L_0x00404a36;
    }
    // 00404a21  81b96801000000000040   +cmp dword ptr [ecx + 0x168], 0x40000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(360) /* 0x168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404a2b  7e09                   -jle 0x404a36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00404a36;
    }
    // 00404a2d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00404a2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00404a31  e87ae2ffff             -call 0x402cb0
    cpu.esp -= 4;
    sub_402cb0(app, cpu);
    if (cpu.terminate) return;
L_0x00404a36:
    // 00404a36  f6052eeb550020         +test byte ptr [0x55eb2e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 32 /*0x20*/));
    // 00404a3d  0f85ce000000           -jne 0x404b11
    if (!cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a43  83b9e406000000         +cmp dword ptr [ecx + 0x6e4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1764) /* 0x6e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404a4a  0f8fc1000000           -jg 0x404b11
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404b11;
    }
    // 00404a50  8a8300020000           -mov al, byte ptr [ebx + 0x200]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */);
    // 00404a56  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00404a58  0f84b3000000           -je 0x404b11
    if (cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a5e  f6810002000008         +test byte ptr [ecx + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 00404a65  0f84a6000000           -je 0x404b11
    if (cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a6b  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00404a6d  0f859e000000           -jne 0x404b11
    if (!cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a73  833df0d46f0001         +cmp dword ptr [0x6fd4f0], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7329008) /* 0x6fd4f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404a7a  0f8591000000           -jne 0x404b11
    if (!cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a80  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00404a85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00404a87  e8c4a50000             -call 0x40f050
    cpu.esp -= 4;
    sub_40f050(app, cpu);
    if (cpu.terminate) return;
    // 00404a8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404a8e  0f857d000000           -jne 0x404b11
    if (!cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404a94  8981e4060000           -mov dword ptr [ecx + 0x6e4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1764) /* 0x6e4 */) = cpu.eax;
    // 00404a9a  3b9924060000           +cmp ebx, dword ptr [ecx + 0x624]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404aa0  7410                   -je 0x404ab2
    if (cpu.flags.zf)
    {
        goto L_0x00404ab2;
    }
    // 00404aa2  c781e806000000000000   -mov dword ptr [ecx + 0x6e8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1768) /* 0x6e8 */) = 0 /*0x0*/;
    // 00404aac  899924060000           -mov dword ptr [ecx + 0x624], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */) = cpu.ebx;
L_0x00404ab2:
    // 00404ab2  ff81e8060000           -inc dword ptr [ecx + 0x6e8]
    (*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1768) /* 0x6e8 */))++;
    // 00404ab8  8b91f0010000           -mov edx, dword ptr [ecx + 0x1f0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(496) /* 0x1f0 */);
    // 00404abe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00404ac5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00404ac7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00404aca  8b91e8060000           -mov edx, dword ptr [ecx + 0x6e8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1768) /* 0x6e8 */);
    // 00404ad0  3b9078ea5600           +cmp edx, dword ptr [eax + 0x56ea78]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5696120) /* 0x56ea78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ad6  7e16                   -jle 0x404aee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00404aee;
    }
    // 00404ad8  8b807cea5600           -mov eax, dword ptr [eax + 0x56ea7c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5696124) /* 0x56ea7c */);
    // 00404ade  c781e806000000000000   -mov dword ptr [ecx + 0x6e8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1768) /* 0x6e8 */) = 0 /*0x0*/;
    // 00404ae8  8981e4060000           -mov dword ptr [ecx + 0x6e4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1764) /* 0x6e4 */) = cpu.eax;
L_0x00404aee:
    // 00404aee  f6830002000008         +test byte ptr [ebx + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 00404af5  741a                   -je 0x404b11
    if (cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
    // 00404af7  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00404afd  83ff01                 +cmp edi, 1
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
    // 00404b00  7405                   -je 0x404b07
    if (cpu.flags.zf)
    {
        goto L_0x00404b07;
    }
    // 00404b02  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404b05  750a                   -jne 0x404b11
    if (!cpu.flags.zf)
    {
        goto L_0x00404b11;
    }
L_0x00404b07:
    // 00404b07  c781e406000000000000   -mov dword ptr [ecx + 0x6e4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1764) /* 0x6e4 */) = 0 /*0x0*/;
L_0x00404b11:
    // 00404b11  f6810002000002         +test byte ptr [ecx + 0x200], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 2 /*0x2*/));
    // 00404b18  7466                   -je 0x404b80
    if (cpu.flags.zf)
    {
        goto L_0x00404b80;
    }
    // 00404b1a  8aa300020000           -mov ah, byte ptr [ebx + 0x200]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */);
    // 00404b20  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00404b23  741e                   -je 0x404b43
    if (cpu.flags.zf)
    {
        goto L_0x00404b43;
    }
    // 00404b25  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00404b28  7419                   -je 0x404b43
    if (cpu.flags.zf)
    {
        goto L_0x00404b43;
    }
    // 00404b2a  d98168010000           -fld dword ptr [ecx + 0x168]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(360) /* 0x168 */)));
    // 00404b30  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404b33  db1c24                 -fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00404b36  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00404b39  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00404b3e  c1e204                 +shl edx, 4
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
    // 00404b41  eb35                   -jmp 0x404b78
    goto L_0x00404b78;
L_0x00404b43:
    // 00404b43  f6830002000004         +test byte ptr [ebx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00404b4a  7411                   -je 0x404b5d
    if (cpu.flags.zf)
    {
        goto L_0x00404b5d;
    }
    // 00404b4c  d98168010000           -fld dword ptr [ecx + 0x168]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(360) /* 0x168 */)));
    // 00404b52  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404b55  db1c24                 -fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00404b58  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b59  01c0                   +add eax, eax
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
    // 00404b5b  eb0d                   -jmp 0x404b6a
    goto L_0x00404b6a;
L_0x00404b5d:
    // 00404b5d  d98168010000           -fld dword ptr [ecx + 0x168]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(360) /* 0x168 */)));
    // 00404b63  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404b66  db1c24                 -fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00404b69  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00404b6a:
    // 00404b6a  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00404b71  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00404b73  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
L_0x00404b78:
    // 00404b78  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00404b7a  89815c060000           -mov dword ptr [ecx + 0x65c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1628) /* 0x65c */) = cpu.eax;
L_0x00404b80:
    // 00404b80  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b81  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b82  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b83  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b84  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404b85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_404b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404b90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404b91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404b92  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404b93  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404b94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404b96  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00404b99  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00404b9b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00404b9d  8b986c010000           -mov ebx, dword ptr [eax + 0x16c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */);
    // 00404ba3  894dfc                 -mov dword ptr [ebp - 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00404ba6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00404ba8  0f847b000000           -je 0x404c29
    if (cpu.flags.zf)
    {
        goto L_0x00404c29;
    }
    // 00404bae  833df0d46f0001         +cmp dword ptr [0x6fd4f0], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7329008) /* 0x6fd4f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404bb5  750c                   -jne 0x404bc3
    if (!cpu.flags.zf)
    {
        goto L_0x00404bc3;
    }
    // 00404bb7  81b86801000000007041   +cmp dword ptr [eax + 0x168], 0x41700000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(360) /* 0x168 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1097859072 /*0x41700000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404bc1  7c66                   -jl 0x404c29
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404c29;
    }
L_0x00404bc3:
    // 00404bc3  d98268010000           +fld dword ptr [edx + 0x168]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(360) /* 0x168 */)));
    // 00404bc9  dc1d9c615300           +fcomp qword ptr [0x53619c]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464476) /* 0x53619c */));
    cpu.fpu.pop();
    // 00404bcf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00404bd1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00404bd2  760e                   -jbe 0x404be2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00404be2;
    }
    // 00404bd4  d98268010000           -fld dword ptr [edx + 0x168]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(360) /* 0x168 */)));
    // 00404bda  e877b10d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00404bdf  db5dfc                 -fistp dword ptr [ebp - 4]
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00404be2:
    // 00404be2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00404be4  e827faffff             -call 0x404610
    cpu.esp -= 4;
    sub_404610(app, cpu);
    if (cpu.terminate) return;
    // 00404be9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404beb  7519                   -jne 0x404c06
    if (!cpu.flags.zf)
    {
        goto L_0x00404c06;
    }
    // 00404bed  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00404bf2  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00404bf5  83e007                 +and eax, 7
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/))));
    // 00404bf8  7507                   -jne 0x404c01
    if (!cpu.flags.zf)
    {
        goto L_0x00404c01;
    }
    // 00404bfa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00404bff  eb02                   -jmp 0x404c03
    goto L_0x00404c03;
L_0x00404c01:
    // 00404c01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00404c03:
    // 00404c03  0945fc                 -or dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00404c06:
    // 00404c06  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404c0a  741d                   -je 0x404c29
    if (cpu.flags.zf)
    {
        goto L_0x00404c29;
    }
    // 00404c0c  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 00404c12  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00404c14  dc0da4615300           +fmul qword ptr [0x5361a4]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<double>(x86::reg32(5464484) /* 0x5361a4 */));
    // 00404c1a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00404c1f  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00404c21  d99ab0070000           +fstp dword ptr [edx + 0x7b0]
    *app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00404c27  eb02                   -jmp 0x404c2b
    goto L_0x00404c2b;
L_0x00404c29:
    // 00404c29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00404c2b:
    // 00404c2b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404c2d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c2e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c2f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c30  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_404c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404c40  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404c41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404c43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_404c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404c50  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404c51  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404c52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404c54  8b1518d56f00           -mov edx, dword ptr [0x6fd518]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7329048) /* 0x6fd518 */);
    // 00404c5a  3b1520d56f00           +cmp edx, dword ptr [0x6fd520]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(7329056) /* 0x6fd520 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404c60  7d0d                   -jge 0x404c6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404c6f;
    }
    // 00404c62  c705b0eb560049eea041   -mov dword ptr [0x56ebb0], 0x41a0ee49
    *app->getMemory<x86::reg32>(x86::reg32(5696432) /* 0x56ebb0 */) = 1101065801 /*0x41a0ee49*/;
    // 00404c6c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c6d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404c6f:
    // 00404c6f  c705b0eb5600dfcf3241   -mov dword ptr [0x56ebb0], 0x4132cfdf
    *app->getMemory<x86::reg32>(x86::reg32(5696432) /* 0x56ebb0 */) = 1093849055 /*0x4132cfdf*/;
    // 00404c79  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c7a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404c7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_404c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404c80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404c81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404c82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404c83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404c84  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404c85  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404c86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404c88  8b3d94fd5e00           -mov edi, dword ptr [0x5efd94]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */);
    // 00404c8e  8b15a4fd5e00           -mov edx, dword ptr [0x5efda4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
    // 00404c94  8b98f4010000           -mov ebx, dword ptr [eax + 0x1f4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(500) /* 0x1f4 */);
    // 00404c9a  4a                     -dec edx
    (cpu.edx)--;
    // 00404c9b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00404c9d  39da                   +cmp edx, ebx
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
    // 00404c9f  7532                   -jne 0x404cd3
    if (!cpu.flags.zf)
    {
        goto L_0x00404cd3;
    }
    // 00404ca1  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00404ca3:
    // 00404ca3  3b15a4fd5e00           +cmp edx, dword ptr [0x5efda4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ca9  7d28                   -jge 0x404cd3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404cd3;
    }
    // 00404cab  8b049548fa5e00         -mov eax, dword ptr [edx*4 + 0x5efa48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.edx * 4);
    // 00404cb2  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 00404cb9  7407                   -je 0x404cc2
    if (cpu.flags.zf)
    {
        goto L_0x00404cc2;
    }
    // 00404cbb  c7400801000000         -mov dword ptr [eax + 8], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x00404cc2:
    // 00404cc2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00404cc5  39d9                   +cmp ecx, ebx
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
    // 00404cc7  7f07                   -jg 0x404cd0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404cd0;
    }
    // 00404cc9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00404ccb  a3b8eb5600             -mov dword ptr [0x56ebb8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5696440) /* 0x56ebb8 */) = cpu.eax;
L_0x00404cd0:
    // 00404cd0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00404cd1  ebd0                   -jmp 0x404ca3
    goto L_0x00404ca3;
L_0x00404cd3:
    // 00404cd3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00404cd5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00404cd7  7427                   -je 0x404d00
    if (cpu.flags.zf)
    {
        goto L_0x00404d00;
    }
    // 00404cd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00404cdb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00404cdd:
    // 00404cdd  39f8                   +cmp eax, edi
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
    // 00404cdf  7d16                   -jge 0x404cf7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404cf7;
    }
    // 00404ce1  8b1c8588fb5e00         -mov ebx, dword ptr [eax*4 + 0x5efb88]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(6224776) /* 0x5efb88 */ + cpu.eax * 4);
    // 00404ce8  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ceb  7d07                   -jge 0x404cf4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404cf4;
    }
    // 00404ced  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00404cf2  01f2                   +add edx, esi
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
L_0x00404cf4:
    // 00404cf4  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00404cf5  ebe6                   -jmp 0x404cdd
    goto L_0x00404cdd;
L_0x00404cf7:
    // 00404cf7  39fa                   +cmp edx, edi
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
    // 00404cf9  7505                   -jne 0x404d00
    if (!cpu.flags.zf)
    {
        goto L_0x00404d00;
    }
    // 00404cfb  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00404d00:
    // 00404d00  893d94fd5e00           -mov dword ptr [0x5efd94], edi
    *app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */) = cpu.edi;
    // 00404d06  8935b4eb5600           -mov dword ptr [0x56ebb4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5696436) /* 0x56ebb4 */) = cpu.esi;
    // 00404d0c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d0d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d0e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d0f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d10  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d11  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404d12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_404d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00404d30  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404d31  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404d32  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404d33  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404d34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404d36  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00404d39  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00404d3b  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00404d3e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00404d40  c70300000000           -mov dword ptr [ebx], 0
    *app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00404d46  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00404d48:
    // 00404d48  3b0d78305500           +cmp ecx, dword ptr [0x553078]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5582968) /* 0x553078 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404d4e  0f8db5000000           -jge 0x404e09
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404e09;
    }
    // 00404d54  8b1c8d08fc5e00         -mov ebx, dword ptr [ecx*4 + 0x5efc08]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(6224904) /* 0x5efc08 */ + cpu.ecx * 4);
    // 00404d5b  39df                   +cmp edi, ebx
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
    // 00404d5d  0f85cd000000           -jne 0x404e30
    if (!cpu.flags.zf)
    {
        goto L_0x00404e30;
    }
    // 00404d63  a1c0d46f00             -mov eax, dword ptr [0x6fd4c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 00404d68  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00404d6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00404d71  7415                   -je 0x404d88
    if (cpu.flags.zf)
    {
        goto L_0x00404d88;
    }
    // 00404d73  8d5dec                 -lea ebx, [ebp - 0x14]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00404d76  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00404d79  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00404d7b  e8f06e0200             -call 0x42bc70
    cpu.esp -= 4;
    sub_42bc70(app, cpu);
    if (cpu.terminate) return;
    // 00404d80  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00404d83  89471c                 -mov dword ptr [edi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00404d86  eb03                   -jmp 0x404d8b
    goto L_0x00404d8b;
L_0x00404d88:
    // 00404d88  89431c                 -mov dword ptr [ebx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00404d8b:
    // 00404d8b  83f904                 +cmp ecx, 4
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
    // 00404d8e  7d07                   -jge 0x404d97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404d97;
    }
    // 00404d90  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 00404d95  eb05                   -jmp 0x404d9c
    goto L_0x00404d9c;
L_0x00404d97:
    // 00404d97  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
L_0x00404d9c:
    // 00404d9c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00404d9e  e8bd930000             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 00404da3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00404da6  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00404da8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00404daa  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00404dad  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00404daf  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 00404db5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00404db7  8a5c821b               -mov bl, byte ptr [edx + eax*4 + 0x1b]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(27) /* 0x1b */ + cpu.eax * 4);
    // 00404dbb  8a448213               -mov al, byte ptr [edx + eax*4 + 0x13]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 4);
    // 00404dbf  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 00404dc2  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00404dc4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00404dc9  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00404dcc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00404dce  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 00404dd3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00404dd6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00404dd8  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00404dda  83fa03                 +cmp edx, 3
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
    // 00404ddd  771b                   -ja 0x404dfa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00404dfa;
    }
    // 00404ddf  ff2495144d4000         -jmp dword ptr [edx*4 + 0x404d14]
    cpu.ip = *app->getMemory<x86::reg32>(4214036 + cpu.edx * 4); goto dynamic_jump;
  case 0x00404de6:
    // 00404de6  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00404de8  eb1f                   -jmp 0x404e09
    goto L_0x00404e09;
  case 0x00404dea:
    // 00404dea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00404dec  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00404dee  f7da                   +neg edx
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
    // 00404df0  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00404df2  eb15                   -jmp 0x404e09
    goto L_0x00404e09;
  case 0x00404df4:
    // 00404df4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00404df6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00404df8  eb06                   -jmp 0x404e00
    goto L_0x00404e00;
  case 0x00404dfa:
L_0x00404dfa:
    // 00404dfa  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00404dfc  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00404dfe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00404e00:
    // 00404e00  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00404e03  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00404e05  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00404e07  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00404e09:
    // 00404e09  d905ac615300           -fld dword ptr [0x5361ac]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5464492) /* 0x5361ac */)));
    // 00404e0f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00404e12  db1c24                 -fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00404e15  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e16  d905b0615300           -fld dword ptr [0x5361b0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5464496) /* 0x5361b0 */)));
    // 00404e1c  894608                 -mov dword ptr [esi + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00404e1f  83ec04                 +sub esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00404e22  db1c24                 +fistp dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00404e25  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e26  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00404e29  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00404e2b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e2c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e2d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e2e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404e2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404e30:
    // 00404e30  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00404e31  e912ffffff             -jmp 0x404d48
    goto L_0x00404d48;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_404e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404e40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404e41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404e42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404e43  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404e44  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404e45  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404e46  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404e48  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00404e4a  8aa012050000           -mov ah, byte ptr [eax + 0x512]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1298) /* 0x512 */);
    // 00404e50  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00404e52  0f8415010000           -je 0x404f6d
    if (cpu.flags.zf)
    {
        goto L_0x00404f6d;
    }
    // 00404e58  80be1305000000         +cmp byte ptr [esi + 0x513], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1299) /* 0x513 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00404e5f  0f850e010000           -jne 0x404f73
    if (!cpu.flags.zf)
    {
        goto L_0x00404f73;
    }
    // 00404e65  8b9e14070000           -mov ebx, dword ptr [esi + 0x714]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00404e6b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00404e72  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00404e74  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00404e77  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404e7e  7469                   -je 0x404ee9
    if (cpu.flags.zf)
    {
        goto L_0x00404ee9;
    }
    // 00404e80  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00404e86  3b909cd87d00           +cmp edx, dword ptr [eax + 0x7dd89c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247452) /* 0x7dd89c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404e8c  7c31                   -jl 0x404ebf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00404ebf;
    }
    // 00404e8e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00404e90  e8bb500c00             -call 0x4c9f50
    cpu.esp -= 4;
    sub_4c9f50(app, cpu);
    if (cpu.terminate) return;
    // 00404e95  8b1df4d46f00           -mov ebx, dword ptr [0x6fd4f4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 00404e9b  3b9ef0010000           +cmp ebx, dword ptr [esi + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ea1  740d                   -je 0x404eb0
    if (cpu.flags.zf)
    {
        goto L_0x00404eb0;
    }
    // 00404ea3  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404eaa  0f8faf000000           -jg 0x404f5f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404f5f;
    }
L_0x00404eb0:
    // 00404eb0  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00404eb5  e8763d0100             -call 0x418c30
    cpu.esp -= 4;
    sub_418c30(app, cpu);
    if (cpu.terminate) return;
    // 00404eba  e9a0000000             -jmp 0x404f5f
    goto L_0x00404f5f;
L_0x00404ebf:
    // 00404ebf  8b15f4d46f00           -mov edx, dword ptr [0x6fd4f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 00404ec5  3b96f0010000           +cmp edx, dword ptr [esi + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ecb  740d                   -je 0x404eda
    if (cpu.flags.zf)
    {
        goto L_0x00404eda;
    }
    // 00404ecd  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404ed4  0f8f85000000           -jg 0x404f5f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404f5f;
    }
L_0x00404eda:
    // 00404eda  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00404edf  e84c3d0100             -call 0x418c30
    cpu.esp -= 4;
    sub_418c30(app, cpu);
    if (cpu.terminate) return;
    // 00404ee4  e976000000             -jmp 0x404f5f
    goto L_0x00404f5f;
L_0x00404ee9:
    // 00404ee9  8b9e38060000           -mov ebx, dword ptr [esi + 0x638]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1592) /* 0x638 */);
    // 00404eef  83fb06                 +cmp ebx, 6
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
    // 00404ef2  7d04                   -jge 0x404ef8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00404ef8;
    }
    // 00404ef4  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00404ef6  eb11                   -jmp 0x404f09
    goto L_0x00404f09;
L_0x00404ef8:
    // 00404ef8  83fb07                 +cmp ebx, 7
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
    // 00404efb  7e07                   -jle 0x404f04
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00404f04;
    }
    // 00404efd  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00404f02  eb05                   -jmp 0x404f09
    goto L_0x00404f09;
L_0x00404f04:
    // 00404f04  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00404f09:
    // 00404f09  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404f10  7409                   -je 0x404f1b
    if (cpu.flags.zf)
    {
        goto L_0x00404f1b;
    }
    // 00404f12  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00404f17  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00404f19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00404f1b:
    // 00404f1b  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00404f21  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00404f24  8b8614070000           -mov eax, dword ptr [esi + 0x714]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1812) /* 0x714 */);
    // 00404f2a  81c1c0000000           -add ecx, 0xc0
    (cpu.ecx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00404f30  e89b4e0c00             -call 0x4c9dd0
    cpu.esp -= 4;
    sub_4c9dd0(app, cpu);
    if (cpu.terminate) return;
    // 00404f35  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00404f37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00404f39  e8826a0000             -call 0x40b9c0
    cpu.esp -= 4;
    sub_40b9c0(app, cpu);
    if (cpu.terminate) return;
    // 00404f3e  8b15f4d46f00           -mov edx, dword ptr [0x6fd4f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 00404f44  3b96f0010000           +cmp edx, dword ptr [esi + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404f4a  7409                   -je 0x404f55
    if (cpu.flags.zf)
    {
        goto L_0x00404f55;
    }
    // 00404f4c  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00404f53  7f0a                   -jg 0x404f5f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00404f5f;
    }
L_0x00404f55:
    // 00404f55  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00404f5a  e8d13c0100             -call 0x418c30
    cpu.esp -= 4;
    sub_418c30(app, cpu);
    if (cpu.terminate) return;
L_0x00404f5f:
    // 00404f5f  c6861305000001         -mov byte ptr [esi + 0x513], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1299) /* 0x513 */) = 1 /*0x1*/;
    // 00404f66  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f67  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f68  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f69  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f6a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f6b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404f6d:
    // 00404f6d  88a613050000           -mov byte ptr [esi + 0x513], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1299) /* 0x513 */) = cpu.ah;
L_0x00404f73:
    // 00404f73  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f74  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f75  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f76  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f78  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404f79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_404f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404f80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404f81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404f82  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404f83  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404f85  80b80e05000000         +cmp byte ptr [eax + 0x50e], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1294) /* 0x50e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00404f8c  744b                   -je 0x404fd9
    if (cpu.flags.zf)
    {
        goto L_0x00404fd9;
    }
    // 00404f8e  f6802006000010         +test byte ptr [eax + 0x620], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) & 16 /*0x10*/));
    // 00404f95  7549                   -jne 0x404fe0
    if (!cpu.flags.zf)
    {
        goto L_0x00404fe0;
    }
    // 00404f97  8a9810070000           -mov bl, byte ptr [eax + 0x710]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */);
    // 00404f9d  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00404fa0  7417                   -je 0x404fb9
    if (cpu.flags.zf)
    {
        goto L_0x00404fb9;
    }
    // 00404fa2  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00404fa4  c7803407000000000000   -mov dword ptr [eax + 0x734], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 00404fae  80e7ef                 +and bh, 0xef
    cpu.clear_co();
    cpu.set_szp((cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 00404fb1  88b810070000           -mov byte ptr [eax + 0x710], bh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) = cpu.bh;
    // 00404fb7  eb15                   -jmp 0x404fce
    goto L_0x00404fce;
L_0x00404fb9:
    // 00404fb9  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00404fbb  c7803407000001000000   -mov dword ptr [eax + 0x734], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1844) /* 0x734 */) = 1 /*0x1*/;
    // 00404fc5  80c910                 -or cl, 0x10
    cpu.cl |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00404fc8  888810070000           -mov byte ptr [eax + 0x710], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) = cpu.cl;
L_0x00404fce:
    // 00404fce  80882006000010         -or byte ptr [eax + 0x620], 0x10
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00404fd5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fd6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fd7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00404fd9:
    // 00404fd9  80a020060000ef         -and byte ptr [eax + 0x620], 0xef
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00404fe0:
    // 00404fe0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fe1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fe2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00404fe3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_404ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00404ff0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00404ff1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00404ff2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00404ff3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00404ff4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00404ff5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00404ff6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00404ff8  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00404ffb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00404ffd  baa0860100             -mov edx, 0x186a0
    cpu.edx = 100000 /*0x186a0*/;
    // 00405002  8b0db0d36f00           -mov ecx, dword ptr [0x6fd3b0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 00405008  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0040500b  83f901                 +cmp ecx, 1
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
    // 0040500e  7508                   -jne 0x405018
    if (!cpu.flags.zf)
    {
        goto L_0x00405018;
    }
    // 00405010  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 00405016  eb02                   -jmp 0x40501a
    goto L_0x0040501a;
L_0x00405018:
    // 00405018  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040501a:
    // 0040501a  8b1db0d36f00           -mov ebx, dword ptr [0x6fd3b0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
    // 00405020  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00405023  83fb01                 +cmp ebx, 1
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
    // 00405026  740b                   -je 0x405033
    if (cpu.flags.zf)
    {
        goto L_0x00405033;
    }
    // 00405028  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040502a  e8a1db0100             -call 0x422bd0
    cpu.esp -= 4;
    sub_422bd0(app, cpu);
    if (cpu.terminate) return;
    // 0040502f  39c6                   +cmp esi, eax
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
    // 00405031  7507                   -jne 0x40503a
    if (!cpu.flags.zf)
    {
        goto L_0x0040503a;
    }
L_0x00405033:
    // 00405033  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405038  eb02                   -jmp 0x40503c
    goto L_0x0040503c;
L_0x0040503a:
    // 0040503a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040503c:
    // 0040503c  c7863007000000000000   -mov dword ptr [esi + 0x730], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */) = 0 /*0x0*/;
    // 00405046  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00405049  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040504c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040504e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x00405051:
    // 00405051  3b3da0fd5e00           +cmp edi, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405057  0f8d84010000           -jge 0x4051e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004051e1;
    }
    // 0040505d  8b0cbd48fc5e00         -mov ecx, dword ptr [edi*4 + 0x5efc48]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.edi * 4);
    // 00405064  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00405069  8aa100020000           -mov ah, byte ptr [ecx + 0x200]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */);
    // 0040506f  8955ec                 -mov dword ptr [ebp - 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00405072  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 00405075  7426                   -je 0x40509d
    if (cpu.flags.zf)
    {
        goto L_0x0040509d;
    }
    // 00405077  3b91c4020000           +cmp edx, dword ptr [ecx + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040507d  751e                   -jne 0x40509d
    if (!cpu.flags.zf)
    {
        goto L_0x0040509d;
    }
    // 0040507f  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405083  0f8452010000           -je 0x4051db
    if (cpu.flags.zf)
    {
        goto L_0x004051db;
    }
    // 00405089  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0040508e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00405091  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00405093  e8e8000800             -call 0x485180
    cpu.esp -= 4;
    sub_485180(app, cpu);
    if (cpu.terminate) return;
    // 00405098  e93e010000             -jmp 0x4051db
    goto L_0x004051db;
L_0x0040509d:
    // 0040509d  f6810002000001         +test byte ptr [ecx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004050a4  7425                   -je 0x4050cb
    if (cpu.flags.zf)
    {
        goto L_0x004050cb;
    }
    // 004050a6  83b9c402000004         +cmp dword ptr [ecx + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004050ad  751c                   -jne 0x4050cb
    if (!cpu.flags.zf)
    {
        goto L_0x004050cb;
    }
    // 004050af  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004050b3  0f8422010000           -je 0x4051db
    if (cpu.flags.zf)
    {
        goto L_0x004051db;
    }
    // 004050b9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004050be  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004050c1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004050c3  e8b8000800             -call 0x485180
    cpu.esp -= 4;
    sub_485180(app, cpu);
    if (cpu.terminate) return;
    // 004050c8  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004050c9  eb86                   -jmp 0x405051
    goto L_0x00405051;
L_0x004050cb:
    // 004050cb  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004050ce  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004050d1  e84a900000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004050d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004050d8  7e0d                   -jle 0x4050e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004050e7;
    }
    // 004050da  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004050dd  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004050e0  e83b900000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004050e5  eb0d                   -jmp 0x4050f4
    goto L_0x004050f4;
L_0x004050e7:
    // 004050e7  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004050ea  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004050ed  e82e900000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 004050f2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004050f4:
    // 004050f4  83f832                 +cmp eax, 0x32
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004050f7  0f8fbc000000           -jg 0x4051b9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004051b9;
    }
    // 004050fd  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00405102  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00405105  8955ec                 -mov dword ptr [ebp - 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00405108  39d8                   +cmp eax, ebx
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
    // 0040510a  7d0b                   -jge 0x405117
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00405117;
    }
    // 0040510c  897de4                 -mov dword ptr [ebp - 0x1c], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 0040510f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00405112  e99c000000             -jmp 0x4051b3
    goto L_0x004051b3;
L_0x00405117:
    // 00405117  0f859c000000           -jne 0x4051b9
    if (!cpu.flags.zf)
    {
        goto L_0x004051b9;
    }
    // 0040511d  8d8698000000           -lea eax, [esi + 0x98]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 00405123  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00405129  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0040512c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040512e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00405130  e87b140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00405135  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00405137  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00405139  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040513b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040513c  730c                   -jae 0x40514a
    if (!cpu.flags.cf)
    {
        goto L_0x0040514a;
    }
    // 0040513e  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00405141  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00405143  e868140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00405148  eb0c                   -jmp 0x405156
    goto L_0x00405156;
L_0x0040514a:
    // 0040514a  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0040514d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040514f  e85c140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00405154  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00405156:
    // 00405156  d95ddc                 -fstp dword ptr [ebp - 0x24]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00405159  8b8630070000           -mov eax, dword ptr [esi + 0x730]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 0040515f  8d9e98000000           -lea ebx, [esi + 0x98]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 00405165  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040516a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040516c  e83f140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00405171  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00405173  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00405175  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405177  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405178  7314                   -jae 0x40518e
    if (!cpu.flags.cf)
    {
        goto L_0x0040518e;
    }
    // 0040517a  8b8630070000           -mov eax, dword ptr [esi + 0x730]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00405180  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00405182  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00405187  e824140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040518c  eb14                   -jmp 0x4051a2
    goto L_0x004051a2;
L_0x0040518e:
    // 0040518e  8b8630070000           -mov eax, dword ptr [esi + 0x730]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 00405194  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00405196  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040519b  e810140900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004051a0  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004051a2:
    // 004051a2  d95de0                 +fstp dword ptr [ebp - 0x20]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004051a5  d945dc                 +fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004051a8  d85de0                 +fcomp dword ptr [ebp - 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */));
    cpu.fpu.pop();
    // 004051ab  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004051ad  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004051ae  7309                   -jae 0x4051b9
    if (!cpu.flags.cf)
    {
        goto L_0x004051b9;
    }
    // 004051b0  897de4                 -mov dword ptr [ebp - 0x1c], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
L_0x004051b3:
    // 004051b3  898e30070000           -mov dword ptr [esi + 0x730], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */) = cpu.ecx;
L_0x004051b9:
    // 004051b9  3b8e24060000           +cmp ecx, dword ptr [esi + 0x624]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1572) /* 0x624 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004051bf  7507                   -jne 0x4051c8
    if (!cpu.flags.zf)
    {
        goto L_0x004051c8;
    }
    // 004051c1  c745ec07000000         -mov dword ptr [ebp - 0x14], 7
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 7 /*0x7*/;
L_0x004051c8:
    // 004051c8  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004051cc  740d                   -je 0x4051db
    if (cpu.flags.zf)
    {
        goto L_0x004051db;
    }
    // 004051ce  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004051d1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004051d4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004051d6  e8a5ff0700             -call 0x485180
    cpu.esp -= 4;
    sub_485180(app, cpu);
    if (cpu.terminate) return;
L_0x004051db:
    // 004051db  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004051dc  e970feffff             -jmp 0x405051
    goto L_0x00405051;
L_0x004051e1:
    // 004051e1  8b8e30070000           -mov ecx, dword ptr [esi + 0x730]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1840) /* 0x730 */);
    // 004051e7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004051e9  741f                   -je 0x40520a
    if (cpu.flags.zf)
    {
        goto L_0x0040520a;
    }
    // 004051eb  83be2406000000         +cmp dword ptr [esi + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004051f2  7516                   -jne 0x40520a
    if (!cpu.flags.zf)
    {
        goto L_0x0040520a;
    }
    // 004051f4  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004051f8  7410                   -je 0x40520a
    if (cpu.flags.zf)
    {
        goto L_0x0040520a;
    }
    // 004051fa  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 004051ff  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00405202  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00405205  e876ff0700             -call 0x485180
    cpu.esp -= 4;
    sub_485180(app, cpu);
    if (cpu.terminate) return;
L_0x0040520a:
    // 0040520a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040520c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040520d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040520e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040520f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405210  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405211  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405212  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_405220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00405220  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00405221  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00405222  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00405223  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00405224  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00405225  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00405227  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040522a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040522c  8955fc                 -mov dword ptr [ebp - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0040522f  be10270000             -mov esi, 0x2710
    cpu.esi = 10000 /*0x2710*/;
    // 00405234  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00405239  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040523b:
    // 0040523b  3b15a0fd5e00           +cmp edx, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405241  7d3c                   -jge 0x40527f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040527f;
    }
    // 00405243  8b049548fc5e00         -mov eax, dword ptr [edx*4 + 0x5efc48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.edx * 4);
    // 0040524a  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00405251  7409                   -je 0x40525c
    if (cpu.flags.zf)
    {
        goto L_0x0040525c;
    }
    // 00405253  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040525a  7420                   -je 0x40527c
    if (cpu.flags.zf)
    {
        goto L_0x0040527c;
    }
L_0x0040525c:
    // 0040525c  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00405263  7409                   -je 0x40526e
    if (cpu.flags.zf)
    {
        goto L_0x0040526e;
    }
    // 00405265  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040526c  740e                   -je 0x40527c
    if (cpu.flags.zf)
    {
        goto L_0x0040527c;
    }
L_0x0040526e:
    // 0040526e  8bb8bc020000           -mov edi, dword ptr [eax + 0x2bc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */);
    // 00405274  39fe                   +cmp esi, edi
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
    // 00405276  7e04                   -jle 0x40527c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040527c;
    }
    // 00405278  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0040527a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0040527c:
    // 0040527c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040527d  ebbc                   -jmp 0x40523b
    goto L_0x0040523b;
L_0x0040527f:
    // 0040527f  833db0d36f0000         +cmp dword ptr [0x6fd3b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405286  7532                   -jne 0x4052ba
    if (!cpu.flags.zf)
    {
        goto L_0x004052ba;
    }
    // 00405288  833da8d46f0000         +cmp dword ptr [0x6fd4a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328936) /* 0x6fd4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040528f  7429                   -je 0x4052ba
    if (cpu.flags.zf)
    {
        goto L_0x004052ba;
    }
    // 00405291  813d84367d0080040000   +cmp dword ptr [0x7d3684], 0x480
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040529b  7e1d                   -jle 0x4052ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004052ba;
    }
    // 0040529d  83fbff                 +cmp ebx, -1
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
    // 004052a0  7e18                   -jle 0x4052ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004052ba;
    }
    // 004052a2  8b049d48fc5e00         -mov eax, dword ptr [ebx*4 + 0x5efc48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.ebx * 4);
    // 004052a9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004052ac  48                     -dec eax
    (cpu.eax)--;
    // 004052ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004052af  7d06                   -jge 0x4052b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004052b7;
    }
    // 004052b1  030540d95d00           -add eax, dword ptr [0x5dd940]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
L_0x004052b7:
    // 004052b7  89411c                 -mov dword ptr [ecx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004052ba:
    // 004052ba  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004052be  7505                   -jne 0x4052c5
    if (!cpu.flags.zf)
    {
        goto L_0x004052c5;
    }
    // 004052c0  83fbff                 +cmp ebx, -1
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
    // 004052c3  7e07                   -jle 0x4052cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004052cc;
    }
L_0x004052c5:
    // 004052c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004052c7  e8343e0200             -call 0x429100
    cpu.esp -= 4;
    sub_429100(app, cpu);
    if (cpu.terminate) return;
L_0x004052cc:
    // 004052cc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004052ce  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004052cf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004052d0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004052d1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004052d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004052d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4052e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004052e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004052e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004052e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004052e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004052e4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004052e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004052e7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004052ea  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004052ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004052ef:
    // 004052ef  3b1da0fd5e00           +cmp ebx, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004052f5  0f8da0000000           -jge 0x40539b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040539b;
    }
    // 004052fb  8b0c9d48fc5e00         -mov ecx, dword ptr [ebx*4 + 0x5efc48]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.ebx * 4);
    // 00405302  f6810002000001         +test byte ptr [ecx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00405309  740d                   -je 0x405318
    if (cpu.flags.zf)
    {
        goto L_0x00405318;
    }
    // 0040530b  83b9c402000003         +cmp dword ptr [ecx + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405312  0f847d000000           -je 0x405395
    if (cpu.flags.zf)
    {
        goto L_0x00405395;
    }
L_0x00405318:
    // 00405318  f6810002000001         +test byte ptr [ecx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 0040531f  740d                   -je 0x40532e
    if (cpu.flags.zf)
    {
        goto L_0x0040532e;
    }
    // 00405321  83b9c402000004         +cmp dword ptr [ecx + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405328  0f8467000000           -je 0x405395
    if (cpu.flags.zf)
    {
        goto L_0x00405395;
    }
L_0x0040532e:
    // 0040532e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00405330  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00405333  e8e88d0000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 00405338  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040533a  7f02                   -jg 0x40533e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040533e;
    }
    // 0040533c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040533e:
    // 0040533e  83f832                 +cmp eax, 0x32
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405341  7f52                   -jg 0x405395
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00405395;
    }
    // 00405343  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00405346  e8f5990000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 0040534b  d8a9c4070000           +fsubr dword ptr [ecx + 0x7c4]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */) - cpu.fpu.st(0);
    // 00405351  d981f0060000           +fld dword ptr [ecx + 0x6f0]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(1776) /* 0x6f0 */)));
    // 00405357  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00405359  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040535c  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */));
    cpu.fpu.pop();
    // 0040535f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405361  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405362  7608                   -jbe 0x40536c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040536c;
    }
    // 00405364  8b81f0060000           -mov eax, dword ptr [ecx + 0x6f0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1776) /* 0x6f0 */);
    // 0040536a  eb03                   -jmp 0x40536f
    goto L_0x0040536f;
L_0x0040536c:
    // 0040536c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0040536f:
    // 0040536f  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00405372  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00405375  8981f0060000           -mov dword ptr [ecx + 0x6f0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1776) /* 0x6f0 */) = cpu.eax;
    // 0040537b  3d00000040             +cmp eax, 0x40000000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405380  7e13                   -jle 0x405395
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00405395;
    }
    // 00405382  8b8128060000           -mov eax, dword ptr [ecx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1576) /* 0x628 */);
    // 00405388  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040538c  7507                   -jne 0x405395
    if (!cpu.flags.zf)
    {
        goto L_0x00405395;
    }
    // 0040538e  c7401401000000         -mov dword ptr [eax + 0x14], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
L_0x00405395:
    // 00405395  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00405396  e954ffffff             -jmp 0x4052ef
    goto L_0x004052ef;
L_0x0040539b:
    // 0040539b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040539d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040539e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040539f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004053a0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004053a1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004053a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4053b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004053b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004053b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004053b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004053b3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004053b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004053b6  f6801007000010         +test byte ptr [eax + 0x710], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) & 16 /*0x10*/));
    // 004053bd  0f8461000000           -je 0x405424
    if (cpu.flags.zf)
    {
        goto L_0x00405424;
    }
    // 004053c3  83b82406000000         +cmp dword ptr [eax + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004053ca  7558                   -jne 0x405424
    if (!cpu.flags.zf)
    {
        goto L_0x00405424;
    }
    // 004053cc  8b8830070000           -mov ecx, dword ptr [eax + 0x730]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1840) /* 0x730 */);
    // 004053d2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004053d4  744e                   -je 0x405424
    if (cpu.flags.zf)
    {
        goto L_0x00405424;
    }
    // 004053d6  8b99f0060000           -mov ebx, dword ptr [ecx + 0x6f0]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1776) /* 0x6f0 */);
    // 004053dc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004053de  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004053e4  7e3e                   -jle 0x405424
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00405424;
    }
    // 004053e6  f6810002000001         +test byte ptr [ecx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004053ed  7409                   -je 0x4053f8
    if (cpu.flags.zf)
    {
        goto L_0x004053f8;
    }
    // 004053ef  83b9c402000003         +cmp dword ptr [ecx + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004053f6  742c                   -je 0x405424
    if (cpu.flags.zf)
    {
        goto L_0x00405424;
    }
L_0x004053f8:
    // 004053f8  8b9030070000           -mov edx, dword ptr [eax + 0x730]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1840) /* 0x730 */);
    // 004053fe  f6820002000001         +test byte ptr [edx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 00405405  7409                   -je 0x405410
    if (cpu.flags.zf)
    {
        goto L_0x00405410;
    }
    // 00405407  83bac402000004         +cmp dword ptr [edx + 0x2c4], 4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040540e  7414                   -je 0x405424
    if (cpu.flags.zf)
    {
        goto L_0x00405424;
    }
L_0x00405410:
    // 00405410  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00405412  8b9830070000           -mov ebx, dword ptr [eax + 0x730]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1840) /* 0x730 */);
    // 00405418  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0040541d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040541f  e88cc4ffff             -call 0x4018b0
    cpu.esp -= 4;
    sub_4018b0(app, cpu);
    if (cpu.terminate) return;
L_0x00405424:
    // 00405424  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405425  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405426  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405427  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405428  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_405430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00405430  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00405431  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00405432  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00405433  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00405434  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00405435  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00405437  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040543a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040543c  8b9024060000           -mov edx, dword ptr [eax + 0x624]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */);
    // 00405442  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00405444  0f8475010000           -je 0x4055bf
    if (cpu.flags.zf)
    {
        goto L_0x004055bf;
    }
    // 0040544a  8bb028060000           -mov esi, dword ptr [eax + 0x628]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 00405450  837e1c02               +cmp dword ptr [esi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405454  7539                   -jne 0x40548f
    if (!cpu.flags.zf)
    {
        goto L_0x0040548f;
    }
    // 00405456  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405458  f6820002000004         +test byte ptr [edx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040545f  7414                   -je 0x405475
    if (cpu.flags.zf)
    {
        goto L_0x00405475;
    }
    // 00405461  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405468  7507                   -jne 0x405471
    if (!cpu.flags.zf)
    {
        goto L_0x00405471;
    }
    // 0040546a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040546f  eb16                   -jmp 0x405487
    goto L_0x00405487;
L_0x00405471:
    // 00405471  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00405473  eb12                   -jmp 0x405487
    goto L_0x00405487;
L_0x00405475:
    // 00405475  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040547c  7507                   -jne 0x405485
    if (!cpu.flags.zf)
    {
        goto L_0x00405485;
    }
    // 0040547e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405483  eb02                   -jmp 0x405487
    goto L_0x00405487;
L_0x00405485:
    // 00405485  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00405487:
    // 00405487  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00405489  0f858a010000           -jne 0x405619
    if (!cpu.flags.zf)
    {
        goto L_0x00405619;
    }
L_0x0040548f:
    // 0040548f  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00405495  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 0040549b  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004054a0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004054a2  e809110900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004054a7  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004054a9  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004054ab  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004054ad  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004054ae  7314                   -jae 0x4054c4
    if (!cpu.flags.cf)
    {
        goto L_0x004054c4;
    }
    // 004054b0  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004054b6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004054b8  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004054bd  e8ee100900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004054c2  eb14                   -jmp 0x4054d8
    goto L_0x004054d8;
L_0x004054c4:
    // 004054c4  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004054ca  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004054cc  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004054d1  e8da100900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 004054d6  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x004054d8:
    // 004054d8  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004054db  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004054de  dc1db4615300           +fcomp qword ptr [0x5361b4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464500) /* 0x5361b4 */));
    cpu.fpu.pop();
    // 004054e4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004054e6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004054e7  0f83dc000000           -jae 0x4055c9
    if (!cpu.flags.cf)
    {
        goto L_0x004055c9;
    }
    // 004054ed  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004054f3  d980c4070000           +fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 004054f9  d81db0eb5600           +fcomp dword ptr [0x56ebb0]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(x86::reg32(5696432) /* 0x56ebb0 */));
    cpu.fpu.pop();
    // 004054ff  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405501  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405502  0f87c1000000           -ja 0x4055c9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004055c9;
    }
    // 00405508  6683b96401000000       +cmp word ptr [ecx + 0x164], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00405510  0f85b3000000           -jne 0x4055c9
    if (!cpu.flags.zf)
    {
        goto L_0x004055c9;
    }
    // 00405516  d9810c010000           +fld dword ptr [ecx + 0x10c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(268) /* 0x10c */)));
    // 0040551c  dc1dbc615300           +fcomp qword ptr [0x5361bc]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464508) /* 0x5361bc */));
    cpu.fpu.pop();
    // 00405522  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405524  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405525  0f869e000000           -jbe 0x4055c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004055c9;
    }
    // 0040552b  f6811007000040         +test byte ptr [ecx + 0x710], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) & 64 /*0x40*/));
    // 00405532  7467                   -je 0x40559b
    if (cpu.flags.zf)
    {
        goto L_0x0040559b;
    }
    // 00405534  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00405539  3b8120070000           +cmp eax, dword ptr [ecx + 0x720]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1824) /* 0x720 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040553f  0f8e7a000000           -jle 0x4055bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004055bf;
    }
    // 00405545  0580020000             -add eax, 0x280
    (cpu.eax) += x86::reg32(x86::sreg32(640 /*0x280*/));
    // 0040554a  c7461c02000000         -mov dword ptr [esi + 0x1c], 2
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 00405551  894628                 -mov dword ptr [esi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00405554  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040555a  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 00405561  7414                   -je 0x405577
    if (cpu.flags.zf)
    {
        goto L_0x00405577;
    }
    // 00405563  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040556a  7507                   -jne 0x405573
    if (!cpu.flags.zf)
    {
        goto L_0x00405573;
    }
    // 0040556c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405571  eb16                   -jmp 0x405589
    goto L_0x00405589;
L_0x00405573:
    // 00405573  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00405575  eb12                   -jmp 0x405589
    goto L_0x00405589;
L_0x00405577:
    // 00405577  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040557e  7507                   -jne 0x405587
    if (!cpu.flags.zf)
    {
        goto L_0x00405587;
    }
    // 00405580  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405585  eb02                   -jmp 0x405589
    goto L_0x00405589;
L_0x00405587:
    // 00405587  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00405589:
    // 00405589  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040558b  0f842e000000           -je 0x4055bf
    if (cpu.flags.zf)
    {
        goto L_0x004055bf;
    }
    // 00405591  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405596  e926000000             -jmp 0x4055c1
    goto L_0x004055c1;
L_0x0040559b:
    // 0040559b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040559d  e80ed20000             -call 0x4127b0
    cpu.esp -= 4;
    sub_4127b0(app, cpu);
    if (cpu.terminate) return;
    // 004055a2  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004055a7  8ab910070000           -mov bh, byte ptr [ecx + 0x710]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 004055ad  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004055b0  80cf40                 -or bh, 0x40
    cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004055b3  898120070000           -mov dword ptr [ecx + 0x720], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1824) /* 0x720 */) = cpu.eax;
    // 004055b9  88b910070000           -mov byte ptr [ecx + 0x710], bh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) = cpu.bh;
L_0x004055bf:
    // 004055bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004055c1:
    // 004055c1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004055c3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004055c4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004055c5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004055c6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004055c7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004055c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004055c9:
    // 004055c9  80a110070000bf         -and byte ptr [ecx + 0x710], 0xbf
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1808) /* 0x710 */) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 004055d0  837e1c02               +cmp dword ptr [esi + 0x1c], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004055d4  75e9                   -jne 0x4055bf
    if (!cpu.flags.zf)
    {
        goto L_0x004055bf;
    }
    // 004055d6  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004055dc  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004055e3  7414                   -je 0x4055f9
    if (cpu.flags.zf)
    {
        goto L_0x004055f9;
    }
    // 004055e5  83b8e006000007         +cmp dword ptr [eax + 0x6e0], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004055ec  7507                   -jne 0x4055f5
    if (!cpu.flags.zf)
    {
        goto L_0x004055f5;
    }
    // 004055ee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004055f3  eb16                   -jmp 0x40560b
    goto L_0x0040560b;
L_0x004055f5:
    // 004055f5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004055f7  eb12                   -jmp 0x40560b
    goto L_0x0040560b;
L_0x004055f9:
    // 004055f9  83b8e006000006         +cmp dword ptr [eax + 0x6e0], 6
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405600  7507                   -jne 0x405609
    if (!cpu.flags.zf)
    {
        goto L_0x00405609;
    }
    // 00405602  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405607  eb02                   -jmp 0x40560b
    goto L_0x0040560b;
L_0x00405609:
    // 00405609  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040560b:
    // 0040560b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040560d  74b0                   -je 0x4055bf
    if (cpu.flags.zf)
    {
        goto L_0x004055bf;
    }
    // 0040560f  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00405614  3b4628                 +cmp eax, dword ptr [esi + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405617  7ea6                   -jle 0x4055bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004055bf;
    }
L_0x00405619:
    // 00405619  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040561e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00405620  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405621  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405622  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405623  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405624  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405625  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_405630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00405630  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00405631  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00405632  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00405633  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00405634  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00405636  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00405639  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040563b  f6801007000010         +test byte ptr [eax + 0x710], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) & 16 /*0x10*/));
    // 00405642  0f8472000000           -je 0x4056ba
    if (cpu.flags.zf)
    {
        goto L_0x004056ba;
    }
    // 00405648  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040564e  8d9998000000           -lea ebx, [ecx + 0x98]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 00405654  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00405659  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040565b  e8500f0900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00405660  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00405662  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00405664  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405666  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405667  7314                   -jae 0x40567d
    if (!cpu.flags.cf)
    {
        goto L_0x0040567d;
    }
    // 00405669  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 0040566f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00405671  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00405676  e8350f0900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040567b  eb14                   -jmp 0x405691
    goto L_0x00405691;
L_0x0040567d:
    // 0040567d  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 00405683  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00405685  0598000000             +add eax, 0x98
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(152 /*0x98*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040568a  e8210f0900             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0040568f  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
L_0x00405691:
    // 00405691  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00405694  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00405697  dc1dc4615300           +fcomp qword ptr [0x5361c4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464516) /* 0x5361c4 */));
    cpu.fpu.pop();
    // 0040569d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040569f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004056a0  7718                   -ja 0x4056ba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004056ba;
    }
    // 004056a2  8b8124060000           -mov eax, dword ptr [ecx + 0x624]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1572) /* 0x624 */);
    // 004056a8  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004056af  7414                   -je 0x4056c5
    if (cpu.flags.zf)
    {
        goto L_0x004056c5;
    }
    // 004056b1  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004056b8  750b                   -jne 0x4056c5
    if (!cpu.flags.zf)
    {
        goto L_0x004056c5;
    }
L_0x004056ba:
    // 004056ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004056bc  e8bfc3ffff             -call 0x401a80
    cpu.esp -= 4;
    sub_401a80(app, cpu);
    if (cpu.terminate) return;
    // 004056c1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004056c3  eb07                   -jmp 0x4056cc
    goto L_0x004056cc;
L_0x004056c5:
    // 004056c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004056c7  e864fdffff             -call 0x405430
    cpu.esp -= 4;
    sub_405430(app, cpu);
    if (cpu.terminate) return;
L_0x004056cc:
    // 004056cc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004056ce  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004056cf  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004056d0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004056d1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004056d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4056e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004056e0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004056e1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004056e2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004056e4  80a000020000fd         -and byte ptr [eax + 0x200], 0xfd
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004056eb  8b9028060000           -mov edx, dword ptr [eax + 0x628]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */);
    // 004056f1  c780e006000002000000   -mov dword ptr [eax + 0x6e0], 2
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */) = 2 /*0x2*/;
    // 004056fb  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00405702  f6802106000040         +test byte ptr [eax + 0x621], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 64 /*0x40*/));
    // 00405709  7405                   -je 0x405710
    if (cpu.flags.zf)
    {
        goto L_0x00405710;
    }
    // 0040570b  e8f0390200             -call 0x429100
    cpu.esp -= 4;
    sub_429100(app, cpu);
    if (cpu.terminate) return;
L_0x00405710:
    // 00405710  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405711  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405712  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
/* data blob: 8d80000000008d9200000000 */
void Application::sub_405740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00405740  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00405741  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00405742  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00405743  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00405744  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00405746  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00405748  8b80e0060000           -mov eax, dword ptr [eax + 0x6e0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */);
    // 0040574e  83f807                 +cmp eax, 7
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
    // 00405751  7707                   -ja 0x40575a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040575a;
    }
    // 00405753  ff248514574000         -jmp dword ptr [eax*4 + 0x405714]
    cpu.ip = *app->getMemory<x86::reg32>(4216596 + cpu.eax * 4); goto dynamic_jump;
  case 0x0040575a:
L_0x0040575a:
    // 0040575a  8b0df4d46f00           -mov ecx, dword ptr [0x6fd4f4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(7329012) /* 0x6fd4f4 */);
    // 00405760  3b8af0010000           +cmp ecx, dword ptr [edx + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405766  7407                   -je 0x40576f
    if (cpu.flags.zf)
    {
        goto L_0x0040576f;
    }
    // 00405768  833db0d36f0002         -cmp dword ptr [0x6fd3b0], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x0040576f:
    // 0040576f  f6820002000020         +test byte ptr [edx + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 00405776  7428                   -je 0x4057a0
    if (cpu.flags.zf)
    {
        goto L_0x004057a0;
    }
    // 00405778  c7822406000000000000   -mov dword ptr [edx + 0x624], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 00405782  c782e006000003000000   -mov dword ptr [edx + 0x6e0], 3
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 3 /*0x3*/;
    // 0040578c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040578d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040578e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040578f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405790  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00405791  c780e006000001000000   -mov dword ptr [eax + 0x6e0], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */) = 1 /*0x1*/;
    // 0040579b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040579c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040579d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040579e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040579f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004057a0:
    // 004057a0  c782e006000002000000   -mov dword ptr [edx + 0x6e0], 2
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 2 /*0x2*/;
    // 004057aa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057ab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057ad  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057ae  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004057af:
    // 004057af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057b1  e8caf4ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 004057b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057b8  e8938b0000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
    // 004057bd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057be  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057bf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057c0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004057c1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004057c2:
    // 004057c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057c4  e8b7f4ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 004057c9  833d94d46f0000         +cmp dword ptr [0x6fd494], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(7328916) /* 0x6fd494 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004057d0  7425                   -je 0x4057f7
    if (cpu.flags.zf)
    {
        goto L_0x004057f7;
    }
    // 004057d2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057d4  e887850000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 004057d9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057db  e8d03e0000             -call 0x4096b0
    cpu.esp -= 4;
    sub_4096b0(app, cpu);
    if (cpu.terminate) return;
    // 004057e0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057e2  e8c9850000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 004057e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057e9  e8723e0000             -call 0x409660
    cpu.esp -= 4;
    sub_409660(app, cpu);
    if (cpu.terminate) return;
    // 004057ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057f0  e83b860000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 004057f5  eb07                   -jmp 0x4057fe
    goto L_0x004057fe;
L_0x004057f7:
    // 004057f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004057f9  e8528b0000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
L_0x004057fe:
    // 004057fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405800  e8fbbcffff             -call 0x401500
    cpu.esp -= 4;
    sub_401500(app, cpu);
    if (cpu.terminate) return;
    // 00405805  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00405807  0f8400020000           -je 0x405a0d
    if (cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 0040580d  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 00405812  8a9a00020000           -mov bl, byte ptr [edx + 0x200]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 00405818  c782e006000006000000   -mov dword ptr [edx + 0x6e0], 6
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 6 /*0x6*/;
    // 00405822  0540010000             -add eax, 0x140
    (cpu.eax) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 00405827  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0040582a  8982ec060000           -mov dword ptr [edx + 0x6ec], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1772) /* 0x6ec */) = cpu.eax;
    // 00405830  889a00020000           -mov byte ptr [edx + 0x200], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) = cpu.bl;
    // 00405836  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405837  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405838  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405839  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040583a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040583b:
    // 0040583b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040583d  e83ef4ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 00405842  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405844  e8078b0000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
    // 00405849  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040584b  e890faffff             -call 0x4052e0
    cpu.esp -= 4;
    sub_4052e0(app, cpu);
    if (cpu.terminate) return;
    // 00405850  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405852  e899f7ffff             -call 0x404ff0
    cpu.esp -= 4;
    sub_404ff0(app, cpu);
    if (cpu.terminate) return;
    // 00405857  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405859  e822f7ffff             -call 0x404f80
    cpu.esp -= 4;
    sub_404f80(app, cpu);
    if (cpu.terminate) return;
    // 0040585e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405860  e8dbf5ffff             -call 0x404e40
    cpu.esp -= 4;
    sub_404e40(app, cpu);
    if (cpu.terminate) return;
    // 00405865  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405867  e844fbffff             -call 0x4053b0
    cpu.esp -= 4;
    sub_4053b0(app, cpu);
    if (cpu.terminate) return;
    // 0040586c  83ba2406000000         +cmp dword ptr [edx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405873  0f8494010000           -je 0x405a0d
    if (cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 00405879  c782e006000004000000   -mov dword ptr [edx + 0x6e0], 4
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 4 /*0x4*/;
    // 00405883  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405884  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405885  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405886  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405887  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00405888:
    // 00405888  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040588a  e8f1f3ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 0040588f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405891  e8ba8a0000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
    // 00405896  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405898  e843faffff             -call 0x4052e0
    cpu.esp -= 4;
    sub_4052e0(app, cpu);
    if (cpu.terminate) return;
    // 0040589d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040589f  e84cf7ffff             -call 0x404ff0
    cpu.esp -= 4;
    sub_404ff0(app, cpu);
    if (cpu.terminate) return;
    // 004058a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058a6  e8d5f6ffff             -call 0x404f80
    cpu.esp -= 4;
    sub_404f80(app, cpu);
    if (cpu.terminate) return;
    // 004058ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058ad  e88ef5ffff             -call 0x404e40
    cpu.esp -= 4;
    sub_404e40(app, cpu);
    if (cpu.terminate) return;
    // 004058b2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058b4  e877fdffff             -call 0x405630
    cpu.esp -= 4;
    sub_405630(app, cpu);
    if (cpu.terminate) return;
    // 004058b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004058bb  7411                   -je 0x4058ce
    if (cpu.flags.zf)
    {
        goto L_0x004058ce;
    }
    // 004058bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058bf  c782e006000005000000   -mov dword ptr [edx + 0x6e0], 5
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 5 /*0x5*/;
    // 004058c9  e872c5ffff             -call 0x401e40
    cpu.esp -= 4;
    sub_401e40(app, cpu);
    if (cpu.terminate) return;
L_0x004058ce:
    // 004058ce  83ba2406000000         +cmp dword ptr [edx + 0x624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1572) /* 0x624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004058d5  0f8532010000           -jne 0x405a0d
    if (!cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 004058db  c782e006000003000000   -mov dword ptr [edx + 0x6e0], 3
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 3 /*0x3*/;
    // 004058e5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004058e6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004058e7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004058e8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004058e9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004058ea:
    // 004058ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058ec  e88ff3ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 004058f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004058f3  c782b007000000000000   -mov dword ptr [edx + 0x7b0], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 004058fd  e86e750000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 00405902  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405904  e8a7c6ffff             -call 0x401fb0
    cpu.esp -= 4;
    sub_401fb0(app, cpu);
    if (cpu.terminate) return;
    // 00405909  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040590b  0f84fc000000           -je 0x405a0d
    if (cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 00405911  c782e006000003000000   -mov dword ptr [edx + 0x6e0], 3
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 3 /*0x3*/;
    // 0040591b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040591c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040591d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040591e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040591f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00405920:
    // 00405920  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405922  e859f3ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 00405927  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405929  e8228a0000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
    // 0040592e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405930  e8fb310000             -call 0x408b30
    cpu.esp -= 4;
    sub_408b30(app, cpu);
    if (cpu.terminate) return;
    // 00405935  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405937  e894320000             -call 0x408bd0
    cpu.esp -= 4;
    sub_408bd0(app, cpu);
    if (cpu.terminate) return;
    // 0040593c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040593e  e8ed840000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 00405943  6683ba6401000000       +cmp word ptr [edx + 0x164], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040594b  0f85bc000000           -jne 0x405a0d
    if (!cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 00405951  d9820c010000           +fld dword ptr [edx + 0x10c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(268) /* 0x10c */)));
    // 00405957  dc1dcc615300           +fcomp qword ptr [0x5361cc]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464524) /* 0x5361cc */));
    cpu.fpu.pop();
    // 0040595d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040595f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405960  7705                   -ja 0x405967
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00405967;
    }
    // 00405962  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405963  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405964  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405965  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405966  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00405967:
    // 00405967  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040596d  dc1dd4615300           +fcomp qword ptr [0x5361d4]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(x86::reg32(5464532) /* 0x5361d4 */));
    cpu.fpu.pop();
    // 00405973  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405975  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405976  7211                   -jb 0x405989
    if (cpu.flags.cf)
    {
        goto L_0x00405989;
    }
    // 00405978  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040597d  3b82ec060000           +cmp eax, dword ptr [edx + 0x6ec]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1772) /* 0x6ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405983  0f8e84000000           -jle 0x405a0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00405a0d;
    }
L_0x00405989:
    // 00405989  8b8228060000           -mov eax, dword ptr [edx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */);
    // 0040598f  83782c00               +cmp dword ptr [eax + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405993  740f                   -je 0x4059a4
    if (cpu.flags.zf)
    {
        goto L_0x004059a4;
    }
    // 00405995  c782e006000007000000   -mov dword ptr [edx + 0x6e0], 7
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 7 /*0x7*/;
    // 0040599f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059a0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059a2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004059a4:
    // 004059a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059a6  e835fdffff             -call 0x4056e0
    cpu.esp -= 4;
    sub_4056e0(app, cpu);
    if (cpu.terminate) return;
    // 004059ab  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059ac  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059ad  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059ae  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004059af  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004059b0:
    // 004059b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059b2  e8c9f2ffff             -call 0x404c80
    cpu.esp -= 4;
    sub_404c80(app, cpu);
    if (cpu.terminate) return;
    // 004059b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059b9  c782b007000000000000   -mov dword ptr [edx + 0x7b0], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 004059c3  e8a8740000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004059c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059ca  e8a1740000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 004059cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059d1  e82abbffff             -call 0x401500
    cpu.esp -= 4;
    sub_401500(app, cpu);
    if (cpu.terminate) return;
    // 004059d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004059d8  7520                   -jne 0x4059fa
    if (!cpu.flags.zf)
    {
        goto L_0x004059fa;
    }
    // 004059da  8aba00020000           -mov bh, byte ptr [edx + 0x200]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004059e0  c782e006000002000000   -mov dword ptr [edx + 0x6e0], 2
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1760) /* 0x6e0 */) = 2 /*0x2*/;
    // 004059ea  80e7fd                 -and bh, 0xfd
    cpu.bh &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004059ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004059ef  88ba00020000           -mov byte ptr [edx + 0x200], bh
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) = cpu.bh;
    // 004059f5  e806370200             -call 0x429100
    cpu.esp -= 4;
    sub_429100(app, cpu);
    if (cpu.terminate) return;
L_0x004059fa:
    // 004059fa  8b8228060000           -mov eax, dword ptr [edx + 0x628]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1576) /* 0x628 */);
    // 00405a00  83782c00               +cmp dword ptr [eax + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00405a04  7507                   -jne 0x405a0d
    if (!cpu.flags.zf)
    {
        goto L_0x00405a0d;
    }
    // 00405a06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00405a08  e8d3fcffff             -call 0x4056e0
    cpu.esp -= 4;
    sub_4056e0(app, cpu);
    if (cpu.terminate) return;
L_0x00405a0d:
    // 00405a0d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a0e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a0f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a10  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a11  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_405a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00405a20  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00405a21  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00405a22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00405a24  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00405a27  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00405a29  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00405a2b  7507                   -jne 0x405a34
    if (!cpu.flags.zf)
    {
        goto L_0x00405a34;
    }
    // 00405a2d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00405a2f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00405a31  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a32  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405a33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00405a34:
    // 00405a34  8b8298000000           -mov eax, dword ptr [edx + 0x98]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 00405a3a  8945dc                 -mov dword ptr [ebp - 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00405a3d  8b829c000000           -mov eax, dword ptr [edx + 0x9c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 00405a43  8945e0                 -mov dword ptr [ebp - 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00405a46  8b82a0000000           -mov eax, dword ptr [edx + 0xa0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
    // 00405a4c  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00405a4f  d94108                 +fld dword ptr [ecx + 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 00405a52  d865e4                 +fsub dword ptr [ebp - 0x1c]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 00405a55  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00405a57  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00405a59  d95dec                 +fstp dword ptr [ebp - 0x14]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00405a5c  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
    cpu.fpu.pop();
    // 00405a5f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405a61  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405a62  7308                   -jae 0x405a6c
    if (!cpu.flags.cf)
    {
        goto L_0x00405a6c;
    }
    // 00405a64  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00405a67  8945e8                 -mov dword ptr [ebp - 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00405a6a  eb08                   -jmp 0x405a74
    goto L_0x00405a74;
L_0x00405a6c:
    // 00405a6c  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00405a6f  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00405a71  d95de8                 +fstp dword ptr [ebp - 0x18]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00405a74:
    // 00405a74  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00405a76  d901                   +fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 00405a78  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00405a7b  d865dc                 +fsub dword ptr [ebp - 0x24]
    cpu.fpu.st(0) -= x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */));
    // 00405a7e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00405a81  d95df4                 +fstp dword ptr [ebp - 0xc]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00405a84  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    cpu.fpu.pop();
    // 00405a87  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405a89  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405a8a  7308                   -jae 0x405a94
    if (!cpu.flags.cf)
    {
        goto L_0x00405a94;
    }
    // 00405a8c  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00405a8f  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00405a92  eb08                   -jmp 0x405a9c
    goto L_0x00405a9c;
L_0x00405a94:
    // 00405a94  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 00405a97  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00405a99  d95df8                 +fstp dword ptr [ebp - 8]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00405a9c:
    // 00405a9c  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00405a9f  d85df0                 +fcomp dword ptr [ebp - 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    cpu.fpu.pop();
    // 00405aa2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405aa4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405aa5  760e                   -jbe 0x405ab5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00405ab5;
    }
    // 00405aa7  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 00405aaa  d80ddc615300           +fmul dword ptr [0x5361dc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5464540) /* 0x5361dc */));
    // 00405ab0  d845f8                 +fadd dword ptr [ebp - 8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 00405ab3  eb0c                   -jmp 0x405ac1
    goto L_0x00405ac1;
L_0x00405ab5:
    // 00405ab5  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00405ab8  d80ddc615300           +fmul dword ptr [0x5361dc]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5464540) /* 0x5361dc */));
    // 00405abe  d845f0                 +fadd dword ptr [ebp - 0x10]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
L_0x00405ac1:
    // 00405ac1  d95dfc                 +fstp dword ptr [ebp - 4]
    *app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00405ac4  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00405ac7  d81de0615300           +fcomp dword ptr [0x5361e0]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<float>(x86::reg32(5464544) /* 0x5361e0 */));
    cpu.fpu.pop();
    // 00405acd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00405acf  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00405ad0  7607                   -jbe 0x405ad9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00405ad9;
    }
    // 00405ad2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00405ad4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00405ad6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405ad7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405ad8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00405ad9:
    // 00405ad9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00405ade  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00405ae0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405ae1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00405ae2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
