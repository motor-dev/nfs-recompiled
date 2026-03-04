#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_40bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040bca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040bca2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040bca3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bca4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bca6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040bca8  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0040bcad  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0040bcb2  e859ecffff             -call 0x40a910
    cpu.esp -= 4;
    sub_40a910(app, cpu);
    if (cpu.terminate) return;
    // 0040bcb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bcb9  743f                   -je 0x40bcfa
    if (cpu.flags.zf)
    {
        goto L_0x0040bcfa;
    }
    // 0040bcbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bcbd  e85eedffff             -call 0x40aa20
    cpu.esp -= 4;
    sub_40aa20(app, cpu);
    if (cpu.terminate) return;
    // 0040bcc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040bcc4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bcc6  bb1d000000             -mov ebx, 0x1d
    cpu.ebx = 29 /*0x1d*/;
    // 0040bccb  e8a0ecffff             -call 0x40a970
    cpu.esp -= 4;
    sub_40a970(app, cpu);
    if (cpu.terminate) return;
    // 0040bcd0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040bcd5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040bcd7  e844eeffff             -call 0x40ab20
    cpu.esp -= 4;
    sub_40ab20(app, cpu);
    if (cpu.terminate) return;
    // 0040bcdc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040bce1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040bce3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040bce5  e896e6ffff             -call 0x40a380
    cpu.esp -= 4;
    sub_40a380(app, cpu);
    if (cpu.terminate) return;
    // 0040bcea  8b8114070000           -mov eax, dword ptr [ecx + 0x714]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1812) /* 0x714 */);
    // 0040bcf0  a3ec245500             -mov dword ptr [0x5524ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5580012) /* 0x5524ec */) = cpu.eax;
    // 0040bcf5  e846ecffff             -call 0x40a940
    cpu.esp -= 4;
    sub_40a940(app, cpu);
    if (cpu.terminate) return;
L_0x0040bcfa:
    // 0040bcfa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bcfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bcfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bcfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bcfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40bd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040bd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040bd02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040bd03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bd04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bd06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040bd08  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0040bd0d  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0040bd12  e8f9ebffff             -call 0x40a910
    cpu.esp -= 4;
    sub_40a910(app, cpu);
    if (cpu.terminate) return;
    // 0040bd17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bd19  743f                   -je 0x40bd5a
    if (cpu.flags.zf)
    {
        goto L_0x0040bd5a;
    }
    // 0040bd1b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bd1d  e8feecffff             -call 0x40aa20
    cpu.esp -= 4;
    sub_40aa20(app, cpu);
    if (cpu.terminate) return;
    // 0040bd22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040bd24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bd26  bb1e000000             -mov ebx, 0x1e
    cpu.ebx = 30 /*0x1e*/;
    // 0040bd2b  e840ecffff             -call 0x40a970
    cpu.esp -= 4;
    sub_40a970(app, cpu);
    if (cpu.terminate) return;
    // 0040bd30  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040bd35  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040bd37  e8e4edffff             -call 0x40ab20
    cpu.esp -= 4;
    sub_40ab20(app, cpu);
    if (cpu.terminate) return;
    // 0040bd3c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040bd41  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040bd43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040bd45  e836e6ffff             -call 0x40a380
    cpu.esp -= 4;
    sub_40a380(app, cpu);
    if (cpu.terminate) return;
    // 0040bd4a  8b8114070000           -mov eax, dword ptr [ecx + 0x714]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1812) /* 0x714 */);
    // 0040bd50  a3ec245500             -mov dword ptr [0x5524ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5580012) /* 0x5524ec */) = cpu.eax;
    // 0040bd55  e8e6ebffff             -call 0x40a940
    cpu.esp -= 4;
    sub_40a940(app, cpu);
    if (cpu.terminate) return;
L_0x0040bd5a:
    // 0040bd5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_40bd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bd60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bd61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bd63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40bd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bd70  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bd71  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bd73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bd74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40bd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040bd81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040bd82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040bd83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040bd84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bd85  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bd87  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040bd8a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040bd8c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040bd8e  833d80367d0000         +cmp dword ptr [0x7d3680], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205952) /* 0x7d3680 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040bd95  0f84ab010000           -je 0x40bf46
    if (cpu.flags.zf)
    {
        goto L_0x0040bf46;
    }
    // 0040bd9b  83b88401000000         +cmp dword ptr [eax + 0x184], 0
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
    // 0040bda2  0f859e010000           -jne 0x40bf46
    if (!cpu.flags.zf)
    {
        goto L_0x0040bf46;
    }
    // 0040bda8  66837b0c00             +cmp word ptr [ebx + 0xc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040bdad  7e08                   -jle 0x40bdb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bdb7;
    }
    // 0040bdaf  8b430a                 -mov eax, dword ptr [ebx + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0040bdb2  c1f810                 +sar eax, 0x10
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
    // 0040bdb5  eb08                   -jmp 0x40bdbf
    goto L_0x0040bdbf;
L_0x0040bdb7:
    // 0040bdb7  8b430a                 -mov eax, dword ptr [ebx + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0040bdba  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040bdbd  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040bdbf:
    // 0040bdbf  3dc8000000             +cmp eax, 0xc8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040bdc4  7c2f                   -jl 0x40bdf5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040bdf5;
    }
    // 0040bdc6  66817b0cc800           +cmp word ptr [ebx + 0xc], 0xc8
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(200 /*0xc8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040bdcc  7e07                   -jle 0x40bdd5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040bdd5;
    }
    // 0040bdce  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 0040bdd3  eb06                   -jmp 0x40bddb
    goto L_0x0040bddb;
L_0x0040bdd5:
    // 0040bdd5  8b430a                 -mov eax, dword ptr [ebx + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0040bdd8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x0040bddb:
    // 0040bddb  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 0040bddf  8b430a                 -mov eax, dword ptr [ebx + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0040bde2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040bde5  3d38ffffff             +cmp eax, 0xffffff38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294967096 /*0xffffff38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040bdea  7f05                   -jg 0x40bdf1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040bdf1;
    }
    // 0040bdec  b838ffffff             -mov eax, 0xffffff38
    cpu.eax = 4294967096 /*0xffffff38*/;
L_0x0040bdf1:
    // 0040bdf1  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
L_0x0040bdf5:
    // 0040bdf5  8b430a                 -mov eax, dword ptr [ebx + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0040bdf8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040bdfb  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040bdfe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040be00  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040be02  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0040be04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040be06  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040be08  7c0e                   -jl 0x40be18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040be18;
    }
    // 0040be0a  8b3d40d95d00           -mov edi, dword ptr [0x5dd940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040be10  39fa                   +cmp edx, edi
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
    // 0040be12  7c11                   -jl 0x40be25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040be25;
    }
    // 0040be14  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040be16  eb0d                   -jmp 0x40be25
    goto L_0x0040be25;
L_0x0040be18:
    // 0040be18  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040be1a  7d09                   -jge 0x40be25
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040be25;
    }
    // 0040be1c  8b3540d95d00           -mov esi, dword ptr [0x5dd940]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040be22  8d0432                 -lea eax, [edx + esi]
    cpu.eax = x86::reg32(cpu.edx + cpu.esi * 1);
L_0x0040be25:
    // 0040be25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040be27  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040be29  e832cf0100             -call 0x428d60
    cpu.esp -= 4;
    sub_428d60(app, cpu);
    if (cpu.terminate) return;
    // 0040be2e  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040be31  a1d0fd5e00             -mov eax, dword ptr [0x5efdd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6225360) /* 0x5efdd0 */);
    // 0040be36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040be37  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040be3a  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0040be40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040be41  8b919c000000           -mov edx, dword ptr [ecx + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0040be47  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040be48  8bb198000000           -mov esi, dword ptr [ecx + 0x98]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 0040be4e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040be4f  e89c4d0100             -call 0x420bf0
    cpu.esp -= 4;
    sub_420bf0(app, cpu);
    if (cpu.terminate) return;
    // 0040be54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040be56  740c                   -je 0x40be64
    if (cpu.flags.zf)
    {
        goto L_0x0040be64;
    }
    // 0040be58  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0040be5b  d80d8c665300           -fmul dword ptr [0x53668c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5465740) /* 0x53668c */));
    // 0040be61  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040be64:
    // 0040be64  d9819c000000           -fld dword ptr [ecx + 0x9c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */)));
    // 0040be6a  d845f8                 -fadd dword ptr [ebp - 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0040be6d  d9999c000000           -fstp dword ptr [ecx + 0x9c]
    app->getMemory<float>(cpu.ecx + x86::reg32(156) /* 0x9c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040be73  668b7b0c               -mov di, word ptr [ebx + 0xc]
    cpu.di = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0040be77  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 0040be7a  7e16                   -jle 0x40be92
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040be92;
    }
    // 0040be7c  8b3d18d56f00           -mov edi, dword ptr [0x6fd518]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7329048) /* 0x6fd518 */);
    // 0040be82  3bb9f0010000           +cmp edi, dword ptr [ecx + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040be88  7e08                   -jle 0x40be92
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040be92;
    }
    // 0040be8a  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0040be8d  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0040be90  eb0b                   -jmp 0x40be9d
    goto L_0x0040be9d;
L_0x0040be92:
    // 0040be92  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040be95  e8e6210000             -call 0x40e080
    cpu.esp -= 4;
    sub_40e080(app, cpu);
    if (cpu.terminate) return;
    // 0040be9a  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040be9d:
    // 0040be9d  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040bea0  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0040bea7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040bea9  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040beaf  8b448211               -mov eax, dword ptr [edx + eax*4 + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(17) /* 0x11 */ + cpu.eax * 4);
    // 0040beb3  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040beb6  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040beb9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040bebc  8b591c                 -mov ebx, dword ptr [ecx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040bebf  dd0594665300           -fld qword ptr [0x536694]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5465748) /* 0x536694 */)));
    // 0040bec5  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040bec8  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040beca  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040bed1  d945f4                 -fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0040bed4  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040bed6  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040bed8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040beda  d999a4000000           -fstp dword ptr [ecx + 0xa4]
    app->getMemory<float>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bee0  8b448212               -mov eax, dword ptr [edx + eax*4 + 0x12]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 4);
    // 0040bee4  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040bee7  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040beea  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040beed  8b591c                 -mov ebx, dword ptr [ecx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040bef0  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040bef3  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040bef5  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040befc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040befe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040bf00  d999a8000000           -fstp dword ptr [ecx + 0xa8]
    app->getMemory<float>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bf06  8b448213               -mov eax, dword ptr [edx + eax*4 + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 4);
    // 0040bf0a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040bf0d  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040bf10  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040bf13  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040bf16  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bf18  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040bf1a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bf1c  d999ac000000           -fstp dword ptr [ecx + 0xac]
    app->getMemory<float>(cpu.ecx + x86::reg32(172) /* 0xac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040bf22  e849ca0100             -call 0x428970
    cpu.esp -= 4;
    sub_428970(app, cpu);
    if (cpu.terminate) return;
    // 0040bf27  c7817401000040000000   -mov dword ptr [ecx + 0x174], 0x40
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(372) /* 0x174 */) = 64 /*0x40*/;
    // 0040bf31  8b81f0010000           -mov eax, dword ptr [ecx + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(496) /* 0x1f0 */);
    // 0040bf37  c7812405000020000000   -mov dword ptr [ecx + 0x524], 0x20
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */) = 32 /*0x20*/;
    // 0040bf41  e88ac00b00             -call 0x4c7fd0
    cpu.esp -= 4;
    sub_4c7fd0(app, cpu);
    if (cpu.terminate) return;
L_0x0040bf46:
    // 0040bf46  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040bf48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bf49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bf4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bf4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bf4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bf4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40bf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bf50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040bf51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040bf52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040bf53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bf54  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bf56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040bf58  e8b31f0000             -call 0x40df10
    cpu.esp -= 4;
    sub_40df10(app, cpu);
    if (cpu.terminate) return;
    // 0040bf5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bf5f  746f                   -je 0x40bfd0
    if (cpu.flags.zf)
    {
        goto L_0x0040bfd0;
    }
    // 0040bf61  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0040bf66  b858ea5600             -mov eax, 0x56ea58
    cpu.eax = 5696088 /*0x56ea58*/;
    // 0040bf6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040bf6d  e8ce460d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0040bf72  668b9120060000         -mov dx, word ptr [ecx + 0x620]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(1568) /* 0x620 */);
    // 0040bf79  81e27fdfffff           -and edx, 0xffffdf7f
    cpu.edx &= x86::reg32(x86::sreg32(4294958975 /*0xffffdf7f*/));
    // 0040bf7f  8b81e0060000           -mov eax, dword ptr [ecx + 0x6e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1760) /* 0x6e0 */);
    // 0040bf85  66899120060000         -mov word ptr [ecx + 0x620], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(1568) /* 0x620 */) = cpu.dx;
    // 0040bf8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040bf8e  7605                   -jbe 0x40bf95
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040bf95;
    }
    // 0040bf90  83f801                 +cmp eax, 1
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
    // 0040bf93  740a                   -je 0x40bf9f
    if (cpu.flags.zf)
    {
        goto L_0x0040bf9f;
    }
L_0x0040bf95:
    // 0040bf95  c781e006000001000000   -mov dword ptr [ecx + 0x6e0], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1760) /* 0x6e0 */) = 1 /*0x1*/;
L_0x0040bf9f:
    // 0040bf9f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfa1  e8ba1d0000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040bfa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfa8  e883d3ffff             -call 0x409330
    cpu.esp -= 4;
    sub_409330(app, cpu);
    if (cpu.terminate) return;
    // 0040bfad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfaf  e86cd9ffff             -call 0x409920
    cpu.esp -= 4;
    sub_409920(app, cpu);
    if (cpu.terminate) return;
    // 0040bfb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfb6  e805d8ffff             -call 0x4097c0
    cpu.esp -= 4;
    sub_4097c0(app, cpu);
    if (cpu.terminate) return;
    // 0040bfbb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfbd  e8eed6ffff             -call 0x4096b0
    cpu.esp -= 4;
    sub_4096b0(app, cpu);
    if (cpu.terminate) return;
    // 0040bfc2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfc4  e8e71d0000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 0040bfc9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040bfcb  e8601e0000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
L_0x0040bfd0:
    // 0040bfd0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfd4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_40bfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bfe0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bfe1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bfe3  dd059c665300           -fld qword ptr [0x53669c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5465756) /* 0x53669c */)));
    // 0040bfe9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040bfea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_40bff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040bff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040bff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040bff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040bff3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040bff4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040bff5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040bff6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040bff8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0040bffb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040bffd  8b0d3cef5600           -mov ecx, dword ptr [0x56ef3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697340) /* 0x56ef3c */);
    // 0040c003  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040c005  0f8423010000           -je 0x40c12e
    if (cpu.flags.zf)
    {
        goto L_0x0040c12e;
    }
    // 0040c00b  d980c0070000           +fld dword ptr [eax + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c011  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c013  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c015  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c017  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c018  7607                   -jbe 0x40c021
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c021;
    }
    // 0040c01a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040c01f  eb02                   -jmp 0x40c023
    goto L_0x0040c023;
L_0x0040c021:
    // 0040c021  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x0040c023:
    // 0040c023  d981c0070000           +fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c029  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c02b  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c02d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c02f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c030  7607                   -jbe 0x40c039
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c039;
    }
    // 0040c032  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c037  eb02                   -jmp 0x40c03b
    goto L_0x0040c03b;
L_0x0040c039:
    // 0040c039  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c03b:
    // 0040c03b  31d8                   +xor eax, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0040c03d  7415                   -je 0x40c054
    if (cpu.flags.zf)
    {
        goto L_0x0040c054;
    }
    // 0040c03f  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c045  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040c047  dc0da4665300           +fmul qword ptr [0x5366a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465764) /* 0x5366a4 */));
    // 0040c04d  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c04f  e9d4000000             -jmp 0x40c128
    goto L_0x0040c128;
L_0x0040c054:
    // 0040c054  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c056  d89ab0070000           +fcomp dword ptr [edx + 0x7b0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    cpu.fpu.pop();
    // 0040c05c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c05e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c05f  730b                   -jae 0x40c06c
    if (!cpu.flags.cf)
    {
        goto L_0x0040c06c;
    }
    // 0040c061  8b82b0070000           -mov eax, dword ptr [edx + 0x7b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */);
    // 0040c067  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0040c06a  eb0b                   -jmp 0x40c077
    goto L_0x0040c077;
L_0x0040c06c:
    // 0040c06c  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c072  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040c074  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c077:
    // 0040c077  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0040c07a  d8a1c4070000           +fsub dword ptr [ecx + 0x7c4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */));
    // 0040c080  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c082  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c084  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c086  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c087  0f83a1000000           -jae 0x40c12e
    if (!cpu.flags.cf)
    {
        goto L_0x0040c12e;
    }
    // 0040c08d  d981c0070000           -fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c093  dc0dac665300           -fmul qword ptr [0x5366ac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465772) /* 0x5366ac */));
    // 0040c099  dc05b4665300           -fadd qword ptr [0x5366b4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5465780) /* 0x5366b4 */));
    // 0040c09f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040c0a2  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040c0a5  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c0a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040c0a8  7f02                   -jg 0x40c0ac
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c0ac;
    }
    // 0040c0aa  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040c0ac:
    // 0040c0ac  83f804                 +cmp eax, 4
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
    // 0040c0af  7d05                   -jge 0x40c0b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c0b6;
    }
    // 0040c0b1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x0040c0b6:
    // 0040c0b6  8b3548ef5600           -mov esi, dword ptr [0x56ef48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */);
    // 0040c0bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040c0be  39f0                   +cmp eax, esi
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
    // 0040c0c0  7c6c                   -jl 0x40c12e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c12e;
    }
    // 0040c0c2  d981c4070000           +fld dword ptr [ecx + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040c0c8  dc1dbc665300           +fcomp qword ptr [0x5366bc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465788) /* 0x5366bc */)));
    cpu.fpu.pop();
    // 0040c0ce  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c0d0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c0d1  725b                   -jb 0x40c12e
    if (cpu.flags.cf)
    {
        goto L_0x0040c12e;
    }
    // 0040c0d3  8b3d48ef5600           -mov edi, dword ptr [0x56ef48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */);
    // 0040c0d9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040c0db  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040c0dd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c0e0  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c0e3  dc0dc4665300           +fmul qword ptr [0x5366c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465796) /* 0x5366c4 */));
    // 0040c0e9  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040c0ec  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c0ef  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040c0f1  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c0f7  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c0f9  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0040c0fb  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c0fe  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040c100  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c102  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c104  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c105  7318                   -jae 0x40c11f
    if (!cpu.flags.cf)
    {
        goto L_0x0040c11f;
    }
    // 0040c107  d981c0070000           -fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c10d  d865f8                 -fsub dword ptr [ebp - 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0040c110  d99ab0070000           -fstp dword ptr [edx + 0x7b0]
    app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c116  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c118  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c119  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c11a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c11b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c11c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c11d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c11e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c11f:
    // 0040c11f  d981c0070000           -fld dword ptr [ecx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c125  d845f8                 -fadd dword ptr [ebp - 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
L_0x0040c128:
    // 0040c128  d99ab0070000           -fstp dword ptr [edx + 0x7b0]
    app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c12e:
    // 0040c12e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c130  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c131  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c132  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c133  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c134  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c136  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40c140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c140  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c141  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c143  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c144  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40c150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c150  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c151  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c153  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c154  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40c160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c162  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c163  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c164  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c165  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c167  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c169  8b90d8060000           -mov edx, dword ptr [eax + 0x6d8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1752) /* 0x6d8 */);
    // 0040c16f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040c174  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040c176  745a                   -je 0x40c1d2
    if (cpu.flags.zf)
    {
        goto L_0x0040c1d2;
    }
    // 0040c178  8bb2f4050000           -mov esi, dword ptr [edx + 0x5f4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1524) /* 0x5f4 */);
    // 0040c17e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040c180  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040c182  7421                   -je 0x40c1a5
    if (cpu.flags.zf)
    {
        goto L_0x0040c1a5;
    }
    // 0040c184  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c18b  7440                   -je 0x40c1cd
    if (cpu.flags.zf)
    {
        goto L_0x0040c1cd;
    }
    // 0040c18d  d982c4070000           +fld dword ptr [edx + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040c193  dc1dcc665300           +fcomp qword ptr [0x5366cc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465804) /* 0x5366cc */)));
    cpu.fpu.pop();
    // 0040c199  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c19b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c19c  772f                   -ja 0x40c1cd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040c1cd;
    }
    // 0040c19e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040c1a3  eb2d                   -jmp 0x40c1d2
    goto L_0x0040c1d2;
L_0x0040c1a5:
    // 0040c1a5  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c1ac  7407                   -je 0x40c1b5
    if (cpu.flags.zf)
    {
        goto L_0x0040c1b5;
    }
    // 0040c1ae  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040c1b3  eb1d                   -jmp 0x40c1d2
    goto L_0x0040c1d2;
L_0x0040c1b5:
    // 0040c1b5  d983c4070000           +fld dword ptr [ebx + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1988) /* 0x7c4 */)));
    // 0040c1bb  dc1dcc665300           +fcomp qword ptr [0x5366cc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465804) /* 0x5366cc */)));
    cpu.fpu.pop();
    // 0040c1c1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c1c3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c1c4  7607                   -jbe 0x40c1cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c1cd;
    }
    // 0040c1c6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040c1cb  eb05                   -jmp 0x40c1d2
    goto L_0x0040c1d2;
L_0x0040c1cd:
    // 0040c1cd  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0040c1d2:
    // 0040c1d2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040c1d4  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0040c1d7  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c1d9  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0040c1dc  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0040c1de:
    // 0040c1de  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040c1e0  8b81d8060000           -mov eax, dword ptr [ecx + 0x6d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1752) /* 0x6d8 */);
    // 0040c1e6  e8751f0000             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 0040c1eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c1ed  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0040c1f4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c1f6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c1f9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040c1fb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c1fd  e87e9affff             -call 0x405c80
    cpu.esp -= 4;
    sub_405c80(app, cpu);
    if (cpu.terminate) return;
    // 0040c202  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040c204  75d8                   -jne 0x40c1de
    if (!cpu.flags.zf)
    {
        goto L_0x0040c1de;
    }
    // 0040c206  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0040c209  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c20e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40c210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c210  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c211  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c212  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c213  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c214  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c216  813d84367d0080070000   +cmp dword ptr [0x7d3684], 0x780
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1920 /*0x780*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c220  7c40                   -jl 0x40c262
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c262;
    }
    // 0040c222  8b8850060000           -mov ecx, dword ptr [eax + 0x650]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1616) /* 0x650 */);
    // 0040c228  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040c22a  7e2c                   -jle 0x40c258
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c258;
    }
    // 0040c22c  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0040c22f  899850060000           -mov dword ptr [eax + 0x650], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1616) /* 0x650 */) = cpu.ebx;
    // 0040c235  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040c237  7529                   -jne 0x40c262
    if (!cpu.flags.zf)
    {
        goto L_0x0040c262;
    }
    // 0040c239  8b158cfd5e00           -mov edx, dword ptr [0x5efd8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6225292) /* 0x5efd8c */);
    // 0040c23f  2b15c0eb5600           -sub edx, dword ptr [0x56ebc0]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5696448) /* 0x56ebc0 */)));
    // 0040c245  e8c62c0000             -call 0x40ef10
    cpu.esp -= 4;
    sub_40ef10(app, cpu);
    if (cpu.terminate) return;
    // 0040c24a  39c2                   +cmp edx, eax
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
    // 0040c24c  7d14                   -jge 0x40c262
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c262;
    }
    // 0040c24e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c253  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c254  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c255  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c256  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c257  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c258:
    // 0040c258  c7805006000002000000   -mov dword ptr [eax + 0x650], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1616) /* 0x650 */) = 2 /*0x2*/;
L_0x0040c262:
    // 0040c262  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c264  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c265  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c266  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c267  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c268  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40c270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c271  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c272  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c273  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c275  83ec04                 +sub esp, 4
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
    // 0040c278  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c27a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c27d  e8be2a0000             -call 0x40ed40
    cpu.esp -= 4;
    sub_40ed40(app, cpu);
    if (cpu.terminate) return;
    // 0040c282  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0040c284  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040c286  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c288  d99ab0070000           +fstp dword ptr [edx + 0x7b0]
    app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c28e  e84dfdffff             -call 0x40bfe0
    cpu.esp -= 4;
    sub_40bfe0(app, cpu);
    if (cpu.terminate) return;
    // 0040c293  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c296  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c29c  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    cpu.fpu.pop();
    // 0040c29f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c2a1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c2a2  7609                   -jbe 0x40c2ad
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c2ad;
    }
    // 0040c2a4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040c2a7  8982b0070000           -mov dword ptr [edx + 0x7b0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = cpu.eax;
L_0x0040c2ad:
    // 0040c2ad  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c2b4  740f                   -je 0x40c2c5
    if (cpu.flags.zf)
    {
        goto L_0x0040c2c5;
    }
    // 0040c2b6  8aa2b3070000           -mov ah, byte ptr [edx + 0x7b3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 0040c2bc  80f480                 -xor ah, 0x80
    cpu.ah ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0040c2bf  88a2b3070000           -mov byte ptr [edx + 0x7b3], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.ah;
L_0x0040c2c5:
    // 0040c2c5  f6822106000010         +test byte ptr [edx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c2cc  740f                   -je 0x40c2dd
    if (cpu.flags.zf)
    {
        goto L_0x0040c2dd;
    }
    // 0040c2ce  8abab3070000           -mov bh, byte ptr [edx + 0x7b3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 0040c2d4  80f780                 -xor bh, 0x80
    cpu.bh ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0040c2d7  88bab3070000           -mov byte ptr [edx + 0x7b3], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.bh;
L_0x0040c2dd:
    // 0040c2dd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c2df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c2e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c2e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c2e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40c2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c2f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c2f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c2f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c2f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c2f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c2f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c2f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c2f8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040c2fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c2fd  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c300  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c307  7507                   -jne 0x40c310
    if (!cpu.flags.zf)
    {
        goto L_0x0040c310;
    }
    // 0040c309  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c30e  eb02                   -jmp 0x40c312
    goto L_0x0040c312;
L_0x0040c310:
    // 0040c310  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c312:
    // 0040c312  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040c318  7409                   -je 0x40c323
    if (cpu.flags.zf)
    {
        goto L_0x0040c323;
    }
    // 0040c31a  833d30f2560001         +cmp dword ptr [0x56f230], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c321  7427                   -je 0x40c34a
    if (cpu.flags.zf)
    {
        goto L_0x0040c34a;
    }
L_0x0040c323:
    // 0040c323  f6822106000010         +test byte ptr [edx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c32a  7407                   -je 0x40c333
    if (cpu.flags.zf)
    {
        goto L_0x0040c333;
    }
    // 0040c32c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c331  eb02                   -jmp 0x40c335
    goto L_0x0040c335;
L_0x0040c333:
    // 0040c333  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c335:
    // 0040c335  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040c33b  0f847a000000           -je 0x40c3bb
    if (cpu.flags.zf)
    {
        goto L_0x0040c3bb;
    }
    // 0040c341  833d30f25600ff         +cmp dword ptr [0x56f230], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c348  7571                   -jne 0x40c3bb
    if (!cpu.flags.zf)
    {
        goto L_0x0040c3bb;
    }
L_0x0040c34a:
    // 0040c34a  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040c351  8b35184f5500           -mov esi, dword ptr [0x554f18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 0040c357  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c359  8b0d104f5500           -mov ecx, dword ptr [0x554f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 0040c35f  0fafce                 -imul ecx, esi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040c362  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040c368  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c36b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040c36d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c36f  8a431b                 -mov al, byte ptr [ebx + 0x1b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 0040c372  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040c375  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c378  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c37b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040c37d  dc0dd4665300           -fmul qword ptr [0x5366d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465812) /* 0x5366d4 */));
    // 0040c383  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040c388  81e100ffff00           -and ecx, 0xffff00
    cpu.ecx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0040c38e  a3104f5500             -mov dword ptr [0x554f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 0040c393  8a4313                 -mov al, byte ptr [ebx + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 0040c396  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0040c399  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040c39b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040c3a0  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040c3a3  c1e810                 +shr eax, 0x10
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
    // 0040c3a6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c3a7  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c3aa  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c3ad  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040c3af  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040c3b1  dc0ddc665300           +fmul qword ptr [0x5366dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465820) /* 0x5366dc */));
    // 0040c3b7  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040c3b9  eb74                   -jmp 0x40c42f
    goto L_0x0040c42f;
L_0x0040c3bb:
    // 0040c3bb  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040c3c2  8b3d184f5500           -mov edi, dword ptr [0x554f18]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 0040c3c8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c3ca  8b0d104f5500           -mov ecx, dword ptr [0x554f10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 0040c3d0  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0040c3d3  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040c3d9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c3dc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040c3de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c3e0  8a4317                 -mov al, byte ptr [ebx + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */);
    // 0040c3e3  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040c3e6  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c3e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040c3eb  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040c3f0  a3104f5500             -mov dword ptr [0x554f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 0040c3f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c3f7  8a4313                 -mov al, byte ptr [ebx + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 0040c3fa  81e100ffff00           -and ecx, 0xffff00
    cpu.ecx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0040c400  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040c403  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0040c406  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040c409  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040c40c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c40f  dc0dd4665300           -fmul qword ptr [0x5366d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465812) /* 0x5366d4 */));
    // 0040c415  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0040c418  40                     -inc eax
    (cpu.eax)++;
    // 0040c419  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040c41b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c41e  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040c420  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040c423  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040c425  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040c427  dc0ddc665300           -fmul qword ptr [0x5366dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465820) /* 0x5366dc */));
    // 0040c42d  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
L_0x0040c42f:
    // 0040c42f  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c435  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 0040c43a  8b0d184f5500           -mov ecx, dword ptr [0x554f18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 0040c440  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0040c443  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040c445  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040c44a  a3104f5500             -mov dword ptr [0x554f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 0040c44f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040c451  2500ffff00             -and eax, 0xffff00
    cpu.eax &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0040c456  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0040c459  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c45c  c1e810                 +shr eax, 0x10
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
    // 0040c45f  890d144f5500           -mov dword ptr [0x554f14], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.ecx;
    // 0040c465  8b0c8548255500         -mov ecx, dword ptr [eax*4 + 0x552548]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5580104) /* 0x552548 */ + cpu.eax * 4);
    // 0040c46c  898a54060000           -mov dword ptr [edx + 0x654], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1620) /* 0x654 */) = cpu.ecx;
    // 0040c472  d98254060000           +fld dword ptr [edx + 0x654]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1620) /* 0x654 */)));
    // 0040c478  d882b4070000           +fadd dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */));
    // 0040c47e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c480  d99ab4070000           +fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c486  e8e5fdffff             -call 0x40c270
    cpu.esp -= 4;
    sub_40c270(app, cpu);
    if (cpu.terminate) return;
    // 0040c48b  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c48d  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c493  8b0d144f5500           -mov ecx, dword ptr [0x554f14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 0040c499  d99ac0070000           +fstp dword ptr [edx + 0x7c0]
    app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c49f  d89ac0070000           +fcomp dword ptr [edx + 0x7c0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    cpu.fpu.pop();
    // 0040c4a5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c4a7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c4a8  730b                   -jae 0x40c4b5
    if (!cpu.flags.cf)
    {
        goto L_0x0040c4b5;
    }
    // 0040c4aa  8b82c0070000           -mov eax, dword ptr [edx + 0x7c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1984) /* 0x7c0 */);
    // 0040c4b0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040c4b3  eb0b                   -jmp 0x40c4c0
    goto L_0x0040c4c0;
L_0x0040c4b5:
    // 0040c4b5  d982c0070000           -fld dword ptr [edx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c4bb  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040c4bd  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c4c0:
    // 0040c4c0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040c4c3  8982c4070000           -mov dword ptr [edx + 0x7c4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1988) /* 0x7c4 */) = cpu.eax;
    // 0040c4c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c4cb  890d144f5500           -mov dword ptr [0x554f14], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.ecx;
    // 0040c4d1  e8aa080000             -call 0x40cd80
    cpu.esp -= 4;
    sub_40cd80(app, cpu);
    if (cpu.terminate) return;
    // 0040c4d6  8b0d144f5500           -mov ecx, dword ptr [0x554f14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 0040c4dc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c4de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4df  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c4e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40c4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c4f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c4f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c4f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c4f8  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0040c4fb  8b3da4fd5e00           -mov edi, dword ptr [0x5efda4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
    // 0040c501  8b1dc8fa5e00           -mov ebx, dword ptr [0x5efac8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */);
    // 0040c507  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c509:
    // 0040c509  39f8                   +cmp eax, edi
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
    // 0040c50b  7d09                   -jge 0x40c516
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c516;
    }
    // 0040c50d  40                     -inc eax
    (cpu.eax)++;
    // 0040c50e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040c510  895485c0               -mov dword ptr [ebp + eax*4 - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */ + cpu.eax * 4) = cpu.edx;
    // 0040c514  ebf3                   -jmp 0x40c509
    goto L_0x0040c509;
L_0x0040c516:
    // 0040c516  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c518:
    // 0040c518  39f8                   +cmp eax, edi
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
    // 0040c51a  7d39                   -jge 0x40c555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c555;
    }
    // 0040c51c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040c51e:
    // 0040c51e  3b158cfd5e00           +cmp edx, dword ptr [0x5efd8c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225292) /* 0x5efd8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c524  7d2c                   -jge 0x40c552
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c552;
    }
    // 0040c526  8b349548fb5e00         -mov esi, dword ptr [edx*4 + 0x5efb48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6224712) /* 0x5efb48 */ + cpu.edx * 4);
    // 0040c52d  f6862006000004         +test byte ptr [esi + 0x620], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1568) /* 0x620 */) & 4 /*0x4*/));
    // 0040c534  7519                   -jne 0x40c54f
    if (!cpu.flags.zf)
    {
        goto L_0x0040c54f;
    }
    // 0040c536  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0040c53d  8bb6d8060000           -mov esi, dword ptr [esi + 0x6d8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1752) /* 0x6d8 */);
    // 0040c543  3bb148fa5e00           +cmp esi, dword ptr [ecx + 0x5efa48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6224456) /* 0x5efa48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c549  7504                   -jne 0x40c54f
    if (!cpu.flags.zf)
    {
        goto L_0x0040c54f;
    }
    // 0040c54b  ff4429c4               +inc dword ptr [ecx + ebp - 0x3c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-60) /* -0x3c */ + cpu.ebp * 1);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040c54f:
    // 0040c54f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c550  ebcc                   -jmp 0x40c51e
    goto L_0x0040c51e;
L_0x0040c552:
    // 0040c552  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c553  ebc3                   -jmp 0x40c518
    goto L_0x0040c518;
L_0x0040c555:
    // 0040c555  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 0040c55a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c55c:
    // 0040c55c  39f8                   +cmp eax, edi
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
    // 0040c55e  7d1a                   -jge 0x40c57a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c57a;
    }
    // 0040c560  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0040c567  8b742ac4               -mov esi, dword ptr [edx + ebp - 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-60) /* -0x3c */ + cpu.ebp * 1);
    // 0040c56b  39f1                   +cmp ecx, esi
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
    // 0040c56d  7e08                   -jle 0x40c577
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c577;
    }
    // 0040c56f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0040c571  8b9a48fa5e00           -mov ebx, dword ptr [edx + 0x5efa48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6224456) /* 0x5efa48 */);
L_0x0040c577:
    // 0040c577  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c578  ebe2                   -jmp 0x40c55c
    goto L_0x0040c55c;
L_0x0040c57a:
    // 0040c57a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040c57c  893da4fd5e00           -mov dword ptr [0x5efda4], edi
    app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */) = cpu.edi;
    // 0040c582  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c584  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c585  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c586  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c587  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c588  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c589  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_40c590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c591  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c592  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c593  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c595  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c597  8b0d184f5500           -mov ecx, dword ptr [0x554f18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 0040c59d  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 0040c5a2  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040c5a5  a3144f5500             -mov dword ptr [0x554f14], eax
    app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 0040c5aa  8b0d144f5500           -mov ecx, dword ptr [0x554f14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 0040c5b0  81e100ffff00           -and ecx, 0xffff00
    cpu.ecx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0040c5b6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040c5bb  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0040c5be  a3104f5500             -mov dword ptr [0x554f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 0040c5c3  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040c5ca  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c5cc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040c5cf  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c5d1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c5d4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0040c5d7  83f845                 +cmp eax, 0x45
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
    // 0040c5da  7709                   -ja 0x40c5e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040c5e5;
    }
    // 0040c5dc  833d28f2560000         +cmp dword ptr [0x56f228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698088) /* 0x56f228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c5e3  7409                   -je 0x40c5ee
    if (cpu.flags.zf)
    {
        goto L_0x0040c5ee;
    }
L_0x0040c5e5:
    // 0040c5e5  80a221060000ef         +and byte ptr [edx + 0x621], 0xef
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 0040c5ec  eb07                   -jmp 0x40c5f5
    goto L_0x0040c5f5;
L_0x0040c5ee:
    // 0040c5ee  808a2106000010         -or byte ptr [edx + 0x621], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0040c5f5:
    // 0040c5f5  833da4fd5e0001         +cmp dword ptr [0x5efda4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c5fc  7e07                   -jle 0x40c605
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c605;
    }
    // 0040c5fe  e8edfeffff             -call 0x40c4f0
    cpu.esp -= 4;
    sub_40c4f0(app, cpu);
    if (cpu.terminate) return;
    // 0040c603  eb05                   -jmp 0x40c60a
    goto L_0x0040c60a;
L_0x0040c605:
    // 0040c605  a1b8eb5600             -mov eax, dword ptr [0x56ebb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5696440) /* 0x56ebb8 */);
L_0x0040c60a:
    // 0040c60a  8982d8060000           -mov dword ptr [edx + 0x6d8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1752) /* 0x6d8 */) = cpu.eax;
    // 0040c610  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c612  e849fbffff             -call 0x40c160
    cpu.esp -= 4;
    sub_40c160(app, cpu);
    if (cpu.terminate) return;
    // 0040c617  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c619  e8d2fcffff             -call 0x40c2f0
    cpu.esp -= 4;
    sub_40c2f0(app, cpu);
    if (cpu.terminate) return;
    // 0040c61e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c61f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c620  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c621  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40c630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c632  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c633  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c635  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c637  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040c63a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040c63c  f6802006000008         +test byte ptr [eax + 0x620], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) & 8 /*0x8*/));
    // 0040c643  740c                   -je 0x40c651
    if (cpu.flags.zf)
    {
        goto L_0x0040c651;
    }
    // 0040c645  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040c647  e864180000             -call 0x40deb0
    cpu.esp -= 4;
    sub_40deb0(app, cpu);
    if (cpu.terminate) return;
    // 0040c64c  e923010000             -jmp 0x40c774
    goto L_0x0040c774;
L_0x0040c651:
    // 0040c651  f6862106000010         +test byte ptr [esi + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c658  0f8416010000           -je 0x40c774
    if (cpu.flags.zf)
    {
        goto L_0x0040c774;
    }
    // 0040c65e  8b153cef5600           -mov edx, dword ptr [0x56ef3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697340) /* 0x56ef3c */);
    // 0040c664  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040c666  0f84d0000000           -je 0x40c73c
    if (cpu.flags.zf)
    {
        goto L_0x0040c73c;
    }
    // 0040c66c  833d48ef560007         +cmp dword ptr [0x56ef48], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c673  0f85c3000000           -jne 0x40c73c
    if (!cpu.flags.zf)
    {
        goto L_0x0040c73c;
    }
    // 0040c679  d986c0070000           +fld dword ptr [esi + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c67f  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c681  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c683  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c685  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c686  7607                   -jbe 0x40c68f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c68f;
    }
    // 0040c688  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0040c68d  eb02                   -jmp 0x40c691
    goto L_0x0040c691;
L_0x0040c68f:
    // 0040c68f  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x0040c691:
    // 0040c691  d982c0070000           +fld dword ptr [edx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c697  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c699  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040c69b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c69d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c69e  7607                   -jbe 0x40c6a7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c6a7;
    }
    // 0040c6a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c6a5  eb02                   -jmp 0x40c6a9
    goto L_0x0040c6a9;
L_0x0040c6a7:
    // 0040c6a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c6a9:
    // 0040c6a9  31c8                   +xor eax, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040c6ab  0f848b000000           -je 0x40c73c
    if (cpu.flags.zf)
    {
        goto L_0x0040c73c;
    }
    // 0040c6b1  f6820002000004         +test byte ptr [edx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040c6b8  0f847e000000           -je 0x40c73c
    if (cpu.flags.zf)
    {
        goto L_0x0040c73c;
    }
    // 0040c6be  d986c0070000           +fld dword ptr [esi + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(1984) /* 0x7c0 */)));
    // 0040c6c4  d8a2c0070000           +fsub dword ptr [edx + 0x7c0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */));
    // 0040c6ca  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c6cc  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040c6ce  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c6d1  d85df8                 +fcomp dword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 0040c6d4  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c6d6  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c6d7  7308                   -jae 0x40c6e1
    if (!cpu.flags.cf)
    {
        goto L_0x0040c6e1;
    }
    // 0040c6d9  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040c6dc  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0040c6df  eb08                   -jmp 0x40c6e9
    goto L_0x0040c6e9;
L_0x0040c6e1:
    // 0040c6e1  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0040c6e4  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040c6e6  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c6e9:
    // 0040c6e9  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0040c6ec  dc1de4665300           +fcomp qword ptr [0x5366e4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465828) /* 0x5366e4 */)));
    cpu.fpu.pop();
    // 0040c6f2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c6f4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c6f5  7607                   -jbe 0x40c6fe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c6fe;
    }
    // 0040c6f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040c6f9  e852170000             -call 0x40de50
    cpu.esp -= 4;
    sub_40de50(app, cpu);
    if (cpu.terminate) return;
L_0x0040c6fe:
    // 0040c6fe  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040c700  d85df8                 +fcomp dword ptr [ebp - 8]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    cpu.fpu.pop();
    // 0040c703  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c705  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c706  7308                   -jae 0x40c710
    if (!cpu.flags.cf)
    {
        goto L_0x0040c710;
    }
    // 0040c708  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040c70b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040c70e  eb08                   -jmp 0x40c718
    goto L_0x0040c718;
L_0x0040c710:
    // 0040c710  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0040c713  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040c715  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040c718:
    // 0040c718  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040c71b  dc1dec665300           +fcomp qword ptr [0x5366ec]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465836) /* 0x5366ec */)));
    cpu.fpu.pop();
    // 0040c721  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c723  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c724  7616                   -jbe 0x40c73c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c73c;
    }
    // 0040c726  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0040c72b  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0040c730  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040c735  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040c737  e814500000             -call 0x411750
    cpu.esp -= 4;
    sub_411750(app, cpu);
    if (cpu.terminate) return;
L_0x0040c73c:
    // 0040c73c  833d7cef560000         +cmp dword ptr [0x56ef7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697404) /* 0x56ef7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c743  742f                   -je 0x40c774
    if (cpu.flags.zf)
    {
        goto L_0x0040c774;
    }
    // 0040c745  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040c747  eb15                   -jmp 0x40c75e
    goto L_0x0040c75e;
L_0x0040c749:
    // 0040c749  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040c74b  e800170000             -call 0x40de50
    cpu.esp -= 4;
    sub_40de50(app, cpu);
    if (cpu.terminate) return;
    // 0040c750  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c752  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c753  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c754  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c755  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c756  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c757  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c758:
    // 0040c758  40                     -inc eax
    (cpu.eax)++;
    // 0040c759  83f803                 +cmp eax, 3
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
    // 0040c75c  7d16                   -jge 0x40c774
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c774;
    }
L_0x0040c75e:
    // 0040c75e  8b148538ef5600         -mov edx, dword ptr [eax*4 + 0x56ef38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */ + cpu.eax * 4);
    // 0040c765  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040c767  74ef                   -je 0x40c758
    if (cpu.flags.zf)
    {
        goto L_0x0040c758;
    }
    // 0040c769  f6820002000004         +test byte ptr [edx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040c770  75d7                   -jne 0x40c749
    if (!cpu.flags.zf)
    {
        goto L_0x0040c749;
    }
    // 0040c772  ebe4                   -jmp 0x40c758
    goto L_0x0040c758;
L_0x0040c774:
    // 0040c774  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c776  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c777  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c778  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c779  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c77a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c77b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40c780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c781  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c782  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c783  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c785  83ec04                 +sub esp, 4
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
    // 0040c788  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c78a  c780b00700000c93d640   -mov dword ptr [eax + 0x7b0], 0x40d6930c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1968) /* 0x7b0 */) = 1087804172 /*0x40d6930c*/;
    // 0040c794  e847f8ffff             -call 0x40bfe0
    cpu.esp -= 4;
    sub_40bfe0(app, cpu);
    if (cpu.terminate) return;
    // 0040c799  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040c79c  d982b0070000           +fld dword ptr [edx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040c7a2  d85dfc                 +fcomp dword ptr [ebp - 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    cpu.fpu.pop();
    // 0040c7a5  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040c7a7  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040c7a8  7609                   -jbe 0x40c7b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040c7b3;
    }
    // 0040c7aa  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040c7ad  8982b0070000           -mov dword ptr [edx + 0x7b0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1968) /* 0x7b0 */) = cpu.eax;
L_0x0040c7b3:
    // 0040c7b3  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c7ba  740f                   -je 0x40c7cb
    if (cpu.flags.zf)
    {
        goto L_0x0040c7cb;
    }
    // 0040c7bc  8aa2b3070000           -mov ah, byte ptr [edx + 0x7b3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 0040c7c2  80f480                 -xor ah, 0x80
    cpu.ah ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0040c7c5  88a2b3070000           -mov byte ptr [edx + 0x7b3], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.ah;
L_0x0040c7cb:
    // 0040c7cb  f6822106000010         +test byte ptr [edx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040c7d2  740f                   -je 0x40c7e3
    if (cpu.flags.zf)
    {
        goto L_0x0040c7e3;
    }
    // 0040c7d4  8abab3070000           -mov bh, byte ptr [edx + 0x7b3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */);
    // 0040c7da  80f780                 -xor bh, 0x80
    cpu.bh ^= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0040c7dd  88bab3070000           -mov byte ptr [edx + 0x7b3], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1971) /* 0x7b3 */) = cpu.bh;
L_0x0040c7e3:
    // 0040c7e3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c7e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c7e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c7e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c7e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40c7f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c7f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c7f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c7f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c7f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c7f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c7f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040c7f9:
    // 0040c7f9  3b058cfd5e00           +cmp eax, dword ptr [0x5efd8c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225292) /* 0x5efd8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c7ff  7d1d                   -jge 0x40c81e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c81e;
    }
    // 0040c801  8b0c8548fb5e00         -mov ecx, dword ptr [eax*4 + 0x5efb48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6224712) /* 0x5efb48 */ + cpu.eax * 4);
    // 0040c808  f6812006000004         +test byte ptr [ecx + 0x620], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1568) /* 0x620 */) & 4 /*0x4*/));
    // 0040c80f  750a                   -jne 0x40c81b
    if (!cpu.flags.zf)
    {
        goto L_0x0040c81b;
    }
    // 0040c811  83b9dc06000004         +cmp dword ptr [ecx + 0x6dc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c818  7501                   -jne 0x40c81b
    if (!cpu.flags.zf)
    {
        goto L_0x0040c81b;
    }
    // 0040c81a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0040c81b:
    // 0040c81b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c81c  ebdb                   -jmp 0x40c7f9
    goto L_0x0040c7f9;
L_0x0040c81e:
    // 0040c81e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040c820  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c821  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c822  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_40c830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c832  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040c833  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040c834  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c835  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c837  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040c83a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040c83c  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c83f  e8acffffff             -call 0x40c7f0
    cpu.esp -= 4;
    sub_40c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0040c844  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040c846  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c848  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0040c84b:
    // 0040c84b  3b0d88fd5e00           +cmp ecx, dword ptr [0x5efd88]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225288) /* 0x5efd88 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c851  7d3f                   -jge 0x40c892
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c892;
    }
    // 0040c853  8b048d88fa5e00         -mov eax, dword ptr [ecx*4 + 0x5efa88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224520) /* 0x5efa88 */ + cpu.ecx * 4);
    // 0040c85a  83b83407000000         +cmp dword ptr [eax + 0x734], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1844) /* 0x734 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040c861  7509                   -jne 0x40c86c
    if (!cpu.flags.zf)
    {
        goto L_0x0040c86c;
    }
    // 0040c863  f6801007000010         +test byte ptr [eax + 0x710], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) & 16 /*0x10*/));
    // 0040c86a  7423                   -je 0x40c88f
    if (cpu.flags.zf)
    {
        goto L_0x0040c88f;
    }
L_0x0040c86c:
    // 0040c86c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040c86e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c871  e8aa180000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040c876  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040c878  7f02                   -jg 0x40c87c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c87c;
    }
    // 0040c87a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040c87c:
    // 0040c87c  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040c87f  8d5316                 -lea edx, [ebx + 0x16]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(22) /* 0x16 */);
    // 0040c882  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0040c884  39d0                   +cmp eax, edx
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
    // 0040c886  7d07                   -jge 0x40c88f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c88f;
    }
    // 0040c888  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c88d  eb05                   -jmp 0x40c894
    goto L_0x0040c894;
L_0x0040c88f:
    // 0040c88f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040c890  ebb9                   -jmp 0x40c84b
    goto L_0x0040c84b;
L_0x0040c892:
    // 0040c892  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040c894:
    // 0040c894  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040c896  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c897  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c898  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c899  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c89a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c89b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40c8a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c8a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c8a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c8a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c8a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c8a5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040c8a7  eb05                   -jmp 0x40c8ae
    goto L_0x0040c8ae;
L_0x0040c8a9:
    // 0040c8a9  83fa03                 +cmp edx, 3
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
    // 0040c8ac  7d1c                   -jge 0x40c8ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c8ca;
    }
L_0x0040c8ae:
    // 0040c8ae  8b0c9590ee5600         -mov ecx, dword ptr [edx*4 + 0x56ee90]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */ + cpu.edx * 4);
    // 0040c8b5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040c8bc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c8be  42                     -inc edx
    (cpu.edx)++;
    // 0040c8bf  01c0                   +add eax, eax
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
    // 0040c8c1  8904958cee5600         -mov dword ptr [edx*4 + 0x56ee8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697164) /* 0x56ee8c */ + cpu.edx * 4) = cpu.eax;
    // 0040c8c8  ebdf                   -jmp 0x40c8a9
    goto L_0x0040c8a9;
L_0x0040c8ca:
    // 0040c8ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c8cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40c8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c8d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c8d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c8d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c8d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c8d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c8d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c8d8  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c8db  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040c8e2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c8e4  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040c8ea  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c8ed  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c8ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c8f1  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040c8f4  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0040c8f7  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040c8fc  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040c8ff  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c901  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0040c903  8b9a38060000           -mov ebx, dword ptr [edx + 0x638]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040c909  39d9                   +cmp ecx, ebx
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
    // 0040c90b  7f11                   -jg 0x40c91e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040c91e;
    }
    // 0040c90d  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040c910  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040c912  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040c917  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040c91a  39d8                   +cmp eax, ebx
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
    // 0040c91c  7d0c                   -jge 0x40c92a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c92a;
    }
L_0x0040c91e:
    // 0040c91e  8305b8ee560064         -add dword ptr [0x56eeb8], 0x64
    (app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0040c925  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c926  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c927  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c928  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c929  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c92a:
    // 0040c92a  83fb07                 +cmp ebx, 7
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
    // 0040c92d  7d0c                   -jge 0x40c93b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040c93b;
    }
    // 0040c92f  8305b4ee560064         -add dword ptr [0x56eeb4], 0x64
    (app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0040c936  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c937  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c938  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c939  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c93a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c93b:
    // 0040c93b  8305bcee560064         -add dword ptr [0x56eebc], 0x64
    (app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */)) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0040c942  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c943  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c944  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c945  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c946  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40c950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040c950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040c951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c953  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c954  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c956  d980b8070000           -fld dword ptr [eax + 0x7b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1976) /* 0x7b8 */)));
    // 0040c95c  dc0df4665300           -fmul qword ptr [0x5366f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465844) /* 0x5366f4 */));
    // 0040c962  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040c965  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040c968  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040c96b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c96c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040c96e  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040c975  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c977  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040c97d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040c980  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c982  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c984  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040c986  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040c989  8a5817                 -mov bl, byte ptr [eax + 0x17]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0040c98c  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0040c98f  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 0040c992  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040c995  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0040c998  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0040c99a  81c100000100           -add ecx, 0x10000
    (cpu.ecx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0040c9a0  39ca                   +cmp edx, ecx
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
    // 0040c9a2  7c1e                   -jl 0x40c9c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040c9c2;
    }
    // 0040c9a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040c9a6  8a481b                 -mov cl, byte ptr [eax + 0x1b]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0040c9a9  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040c9ac  c1e10f                 -shl ecx, 0xf
    cpu.ecx <<= 15 /*0xf*/ % 32;
    // 0040c9af  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040c9b1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040c9b6  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0040c9b9  2d00000100             -sub eax, 0x10000
    (cpu.eax) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0040c9be  39c2                   +cmp edx, eax
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
    // 0040c9c0  7e0a                   -jle 0x40c9cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040c9cc;
    }
L_0x0040c9c2:
    // 0040c9c2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040c9c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040c9cc:
    // 0040c9cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040c9ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040c9d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40c9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040c9f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040c9f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040c9f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040c9f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040c9f5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040c9f7  e814150000             -call 0x40df10
    cpu.esp -= 4;
    sub_40df10(app, cpu);
    if (cpu.terminate) return;
    // 0040c9fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040c9fe  0f84f1000000           -je 0x40caf5
    if (cpu.flags.zf)
    {
        goto L_0x0040caf5;
    }
    // 0040ca04  8b81dc060000           -mov eax, dword ptr [ecx + 0x6dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */);
    // 0040ca0a  83f805                 +cmp eax, 5
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
    // 0040ca0d  7707                   -ja 0x40ca16
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040ca16;
    }
    // 0040ca0f  ff2485d4c94000         -jmp dword ptr [eax*4 + 0x40c9d4]
    cpu.ip = app->getMemory<x86::reg32>(4245972 + cpu.eax * 4); goto dynamic_jump;
  case 0x0040ca16:
L_0x0040ca16:
    // 0040ca16  c781dc06000001000000   -mov dword ptr [ecx + 0x6dc], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */) = 1 /*0x1*/;
  [[fallthrough]];
  case 0x0040ca20:
    // 0040ca20  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca22  e849f8ffff             -call 0x40c270
    cpu.esp -= 4;
    sub_40c270(app, cpu);
    if (cpu.terminate) return;
    // 0040ca27  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca29  e832130000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040ca2e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca30  e86bfeffff             -call 0x40c8a0
    cpu.esp -= 4;
    sub_40c8a0(app, cpu);
    if (cpu.terminate) return;
    // 0040ca35  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca37  e8f4fbffff             -call 0x40c630
    cpu.esp -= 4;
    sub_40c630(app, cpu);
    if (cpu.terminate) return;
    // 0040ca3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca3e  e8adf5ffff             -call 0x40bff0
    cpu.esp -= 4;
    sub_40bff0(app, cpu);
    if (cpu.terminate) return;
    // 0040ca43  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca45  e866130000             -call 0x40ddb0
    cpu.esp -= 4;
    sub_40ddb0(app, cpu);
    if (cpu.terminate) return;
    // 0040ca4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca4c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ca4e  e8dd130000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 0040ca53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca55  e8d6fdffff             -call 0x40c830
    cpu.esp -= 4;
    sub_40c830(app, cpu);
    if (cpu.terminate) return;
    // 0040ca5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ca5c  0f8493000000           -je 0x40caf5
    if (cpu.flags.zf)
    {
        goto L_0x0040caf5;
    }
    // 0040ca62  c781dc06000003000000   -mov dword ptr [ecx + 0x6dc], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */) = 3 /*0x3*/;
    // 0040ca6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ca6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ca6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ca6f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ca70:
    // 0040ca70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca72  e8e9120000             -call 0x40dd60
    cpu.esp -= 4;
    sub_40dd60(app, cpu);
    if (cpu.terminate) return;
    // 0040ca77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca79  e802fdffff             -call 0x40c780
    cpu.esp -= 4;
    sub_40c780(app, cpu);
    if (cpu.terminate) return;
    // 0040ca7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca80  e84bfeffff             -call 0x40c8d0
    cpu.esp -= 4;
    sub_40c8d0(app, cpu);
    if (cpu.terminate) return;
    // 0040ca85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca87  e8940c0000             -call 0x40d720
    cpu.esp -= 4;
    sub_40d720(app, cpu);
    if (cpu.terminate) return;
    // 0040ca8c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca8e  e86d0d0000             -call 0x40d800
    cpu.esp -= 4;
    sub_40d800(app, cpu);
    if (cpu.terminate) return;
    // 0040ca93  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca95  e8560f0000             -call 0x40d9f0
    cpu.esp -= 4;
    sub_40d9f0(app, cpu);
    if (cpu.terminate) return;
    // 0040ca9a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ca9c  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0040caa1  e88a130000             -call 0x40de30
    cpu.esp -= 4;
    sub_40de30(app, cpu);
    if (cpu.terminate) return;
    // 0040caa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040caa8  e883fdffff             -call 0x40c830
    cpu.esp -= 4;
    sub_40c830(app, cpu);
    if (cpu.terminate) return;
    // 0040caad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040caaf  743a                   -je 0x40caeb
    if (cpu.flags.zf)
    {
        goto L_0x0040caeb;
    }
    // 0040cab1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040cab3  e898feffff             -call 0x40c950
    cpu.esp -= 4;
    sub_40c950(app, cpu);
    if (cpu.terminate) return;
    // 0040cab8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040caba  7439                   -je 0x40caf5
    if (cpu.flags.zf)
    {
        goto L_0x0040caf5;
    }
    // 0040cabc  c781dc06000004000000   -mov dword ptr [ecx + 0x6dc], 4
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */) = 4 /*0x4*/;
    // 0040cac6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cac7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cac8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cac9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040caca:
    // 0040caca  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0040cacf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040cad1  c781b007000000000000   -mov dword ptr [ecx + 0x7b0], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 0040cadb  e890030000             -call 0x40ce70
    cpu.esp -= 4;
    sub_40ce70(app, cpu);
    if (cpu.terminate) return;
    // 0040cae0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040cae2  e849fdffff             -call 0x40c830
    cpu.esp -= 4;
    sub_40c830(app, cpu);
    if (cpu.terminate) return;
    // 0040cae7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040cae9  750a                   -jne 0x40caf5
    if (!cpu.flags.zf)
    {
        goto L_0x0040caf5;
    }
L_0x0040caeb:
    // 0040caeb  c781dc06000001000000   -mov dword ptr [ecx + 0x6dc], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1756) /* 0x6dc */) = 1 /*0x1*/;
  [[fallthrough]];
  case 0x0040caf5:
L_0x0040caf5:
    // 0040caf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caf6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040caf8  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 0000000000000000000000000000000000006400000000008d80000000008bd2 */
void Application::sub_40cb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cb20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cb21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cb22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cb23  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cb25  bb48000000             -mov ebx, 0x48
    cpu.ebx = 72 /*0x48*/;
    // 0040cb2a  b838ef5600             -mov eax, 0x56ef38
    cpu.eax = 5697336 /*0x56ef38*/;
    // 0040cb2f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040cb31  e80a3b0d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0040cb36  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040cb38  8915c0eb5600           -mov dword ptr [0x56ebc0], edx
    app->getMemory<x86::reg32>(x86::reg32(5696448) /* 0x56ebc0 */) = cpu.edx;
    // 0040cb3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40cb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cb50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cb51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cb52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cb54  e817210000             -call 0x40ec70
    cpu.esp -= 4;
    sub_40ec70(app, cpu);
    if (cpu.terminate) return;
    // 0040cb59  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040cb5b  a330f25600             -mov dword ptr [0x56f230], eax
    app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */) = cpu.eax;
    // 0040cb60  8915c0eb5600           -mov dword ptr [0x56ebc0], edx
    app->getMemory<x86::reg32>(x86::reg32(5696448) /* 0x56ebc0 */) = cpu.edx;
    // 0040cb66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40cb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cb70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cb71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cb72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cb74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040cb76  e815000000             -call 0x40cb90
    cpu.esp -= 4;
    sub_40cb90(app, cpu);
    if (cpu.terminate) return;
    // 0040cb7b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040cb7d  e80e7bffff             -call 0x404690
    cpu.esp -= 4;
    sub_404690(app, cpu);
    if (cpu.terminate) return;
    // 0040cb82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cb84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40cb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cb90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040cb91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cb92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cb93  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cb95  c7803006000000000000   -mov dword ptr [eax + 0x630], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */) = 0 /*0x0*/;
    // 0040cb9f  c780d806000000000000   -mov dword ptr [eax + 0x6d8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1752) /* 0x6d8 */) = 0 /*0x0*/;
    // 0040cba9  c7804c06000000000000   -mov dword ptr [eax + 0x64c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1612) /* 0x64c */) = 0 /*0x0*/;
    // 0040cbb3  c7805006000000000000   -mov dword ptr [eax + 0x650], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1616) /* 0x650 */) = 0 /*0x0*/;
    // 0040cbbd  c7805406000000000000   -mov dword ptr [eax + 0x654], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1620) /* 0x654 */) = 0 /*0x0*/;
    // 0040cbc7  c7805806000000000000   -mov dword ptr [eax + 0x658], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1624) /* 0x658 */) = 0 /*0x0*/;
    // 0040cbd1  c7805c06000000000000   -mov dword ptr [eax + 0x65c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1628) /* 0x65c */) = 0 /*0x0*/;
    // 0040cbdb  c780dc06000000000000   -mov dword ptr [eax + 0x6dc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1756) /* 0x6dc */) = 0 /*0x0*/;
    // 0040cbe5  c780e006000000000000   -mov dword ptr [eax + 0x6e0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1760) /* 0x6e0 */) = 0 /*0x0*/;
    // 0040cbef  c780e406000000000000   -mov dword ptr [eax + 0x6e4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1764) /* 0x6e4 */) = 0 /*0x0*/;
    // 0040cbf9  c780e806000000000000   -mov dword ptr [eax + 0x6e8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1768) /* 0x6e8 */) = 0 /*0x0*/;
    // 0040cc03  c780c802000000000000   -mov dword ptr [eax + 0x2c8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(712) /* 0x2c8 */) = 0 /*0x0*/;
    // 0040cc0d  c780f006000000000000   -mov dword ptr [eax + 0x6f0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1776) /* 0x6f0 */) = 0 /*0x0*/;
    // 0040cc17  c7800407000000000000   -mov dword ptr [eax + 0x704], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1796) /* 0x704 */) = 0 /*0x0*/;
    // 0040cc21  c7800807000000000000   -mov dword ptr [eax + 0x708], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1800) /* 0x708 */) = 0 /*0x0*/;
    // 0040cc2b  c7800c07000000000000   -mov dword ptr [eax + 0x70c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1804) /* 0x70c */) = 0 /*0x0*/;
    // 0040cc35  c7801007000000000000   -mov dword ptr [eax + 0x710], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0040cc3f  c7801407000000000000   -mov dword ptr [eax + 0x714], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1812) /* 0x714 */) = 0 /*0x0*/;
    // 0040cc49  c7801807000000000000   -mov dword ptr [eax + 0x718], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1816) /* 0x718 */) = 0 /*0x0*/;
    // 0040cc53  c7803007000000000000   -mov dword ptr [eax + 0x730], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1840) /* 0x730 */) = 0 /*0x0*/;
    // 0040cc5d  c7801c07000000000000   -mov dword ptr [eax + 0x71c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1820) /* 0x71c */) = 0 /*0x0*/;
    // 0040cc67  c7802007000000000000   -mov dword ptr [eax + 0x720], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1824) /* 0x720 */) = 0 /*0x0*/;
    // 0040cc71  c7802407000000000000   -mov dword ptr [eax + 0x724], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1828) /* 0x724 */) = 0 /*0x0*/;
    // 0040cc7b  c7803407000000000000   -mov dword ptr [eax + 0x734], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1844) /* 0x734 */) = 0 /*0x0*/;
    // 0040cc85  c780ac07000000000000   -mov dword ptr [eax + 0x7ac], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1964) /* 0x7ac */) = 0 /*0x0*/;
    // 0040cc8f  c780b407000000000000   -mov dword ptr [eax + 0x7b4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1972) /* 0x7b4 */) = 0 /*0x0*/;
    // 0040cc99  c780b007000000000000   -mov dword ptr [eax + 0x7b0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1968) /* 0x7b0 */) = 0 /*0x0*/;
    // 0040cca3  c780c007000000000000   -mov dword ptr [eax + 0x7c0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1984) /* 0x7c0 */) = 0 /*0x0*/;
    // 0040ccad  c780c407000000000000   -mov dword ptr [eax + 0x7c4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1988) /* 0x7c4 */) = 0 /*0x0*/;
    // 0040ccb7  c780bc0700000000803f   -mov dword ptr [eax + 0x7bc], 0x3f800000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1980) /* 0x7bc */) = 1065353216 /*0x3f800000*/;
    // 0040ccc1  c780b807000000000000   -mov dword ptr [eax + 0x7b8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1976) /* 0x7b8 */) = 0 /*0x0*/;
    // 0040cccb  c7801c02000000000000   -mov dword ptr [eax + 0x21c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */) = 0 /*0x0*/;
    // 0040ccd5  c780c807000000000000   -mov dword ptr [eax + 0x7c8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1992) /* 0x7c8 */) = 0 /*0x0*/;
    // 0040ccdf  c7802406000000000000   -mov dword ptr [eax + 0x624], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1572) /* 0x624 */) = 0 /*0x0*/;
    // 0040cce9  c7802806000000000000   -mov dword ptr [eax + 0x628], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1576) /* 0x628 */) = 0 /*0x0*/;
    // 0040ccf3  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040ccf9  c780d407000000000000   -mov dword ptr [eax + 0x7d4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2004) /* 0x7d4 */) = 0 /*0x0*/;
    // 0040cd03  81c200050000           -add edx, 0x500
    (cpu.edx) += x86::reg32(x86::sreg32(1280 /*0x500*/));
    // 0040cd09  899034060000           -mov dword ptr [eax + 0x634], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1588) /* 0x634 */) = cpu.edx;
    // 0040cd0f  8a9010070000           -mov dl, byte ptr [eax + 0x710]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */);
    // 0040cd15  c7802c06000000000000   -mov dword ptr [eax + 0x62c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1580) /* 0x62c */) = 0 /*0x0*/;
    // 0040cd1f  80e2ef                 -and dl, 0xef
    cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0040cd22  889010070000           -mov byte ptr [eax + 0x710], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1808) /* 0x710 */) = cpu.dl;
    // 0040cd28  c7802006000000000000   -mov dword ptr [eax + 0x620], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1568) /* 0x620 */) = 0 /*0x0*/;
    // 0040cd32  8ab000020000           -mov dh, byte ptr [eax + 0x200]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 0040cd38  c780d007000000000000   -mov dword ptr [eax + 0x7d0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2000) /* 0x7d0 */) = 0 /*0x0*/;
    // 0040cd42  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0040cd45  7407                   -je 0x40cd4e
    if (cpu.flags.zf)
    {
        goto L_0x0040cd4e;
    }
    // 0040cd47  80882006000002         -or byte ptr [eax + 0x620], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0040cd4e:
    // 0040cd4e  f6800002000020         +test byte ptr [eax + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0040cd55  7407                   -je 0x40cd5e
    if (cpu.flags.zf)
    {
        goto L_0x0040cd5e;
    }
    // 0040cd57  80882006000002         -or byte ptr [eax + 0x620], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0040cd5e:
    // 0040cd5e  8aa800020000           -mov ch, byte ptr [eax + 0x200]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 0040cd64  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0040cd67  740b                   -je 0x40cd74
    if (cpu.flags.zf)
    {
        goto L_0x0040cd74;
    }
    // 0040cd69  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 0040cd6b  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0040cd6e  889000020000           -mov byte ptr [eax + 0x200], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) = cpu.dl;
L_0x0040cd74:
    // 0040cd74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cd77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_40cd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cd81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040cd82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cd83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040cd84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040cd85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cd86  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cd88  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0040cd8b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040cd8e  8d7df0                 -lea edi, [ebp - 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040cd91  be00cb4000             -mov esi, 0x40cb00
    cpu.esi = 4246272 /*0x40cb00*/;
    // 0040cd96  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cd97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cd98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cd99  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040cda0  7407                   -je 0x40cda9
    if (cpu.flags.zf)
    {
        goto L_0x0040cda9;
    }
    // 0040cda2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040cda7  eb02                   -jmp 0x40cdab
    goto L_0x0040cdab;
L_0x0040cda9:
    // 0040cda9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040cdab:
    // 0040cdab  8b0dc0d46f00           -mov ecx, dword ptr [0x6fd4c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 0040cdb1  31c1                   -xor ecx, eax
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040cdb3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040cdb6  d980b4070000           -fld dword ptr [eax + 0x7b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1972) /* 0x7b4 */)));
    // 0040cdbc  dc0dfc665300           -fmul qword ptr [0x5366fc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465852) /* 0x5366fc */));
    // 0040cdc2  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0040cdc7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040cdca  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040cdcd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cdce  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0040cdd1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040cdd4  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0040cdd7  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040cdda  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040cddd  e8be3c0900             -call 0x4a0aa0
    cpu.esp -= 4;
    sub_4a0aa0(app, cpu);
    if (cpu.terminate) return;
    // 0040cde2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040cde5  8db0d8000000           -lea esi, [eax + 0xd8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(216) /* 0xd8 */);
    // 0040cdeb  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040cdee  8d7de4                 -lea edi, [ebp - 0x1c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040cdf1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040cdf2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040cdf5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cdf6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cdf7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040cdf8  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040cdfb  ffb0c4070000           -push dword ptr [eax + 0x7c4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1988) /* 0x7c4 */);
    cpu.esp -= 4;
    // 0040ce01  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040ce06  e845320d00             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 0040ce0b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040ce0e  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040ce11  8db8a4000000           -lea edi, [eax + 0xa4]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0040ce17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040ce18  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040ce19  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040ce1a  c780e400000000000000   -mov dword ptr [eax + 0xe4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(228) /* 0xe4 */) = 0 /*0x0*/;
    // 0040ce24  c780e800000000000000   -mov dword ptr [eax + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 0040ce2e  c780ec00000000000000   -mov dword ptr [eax + 0xec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 0040ce38  66c780640100000000     -mov word ptr [eax + 0x164], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(356) /* 0x164 */) = 0 /*0x0*/;
    // 0040ce41  c780c005000000000000   -mov dword ptr [eax + 0x5c0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1472) /* 0x5c0 */) = 0 /*0x0*/;
    // 0040ce4b  c780c405000000000000   -mov dword ptr [eax + 0x5c4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1476) /* 0x5c4 */) = 0 /*0x0*/;
    // 0040ce55  c7804c06000000000000   -mov dword ptr [eax + 0x64c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1612) /* 0x64c */) = 0 /*0x0*/;
    // 0040ce5f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ce61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce64  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce66  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ce67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_40ce70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ce70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ce71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ce72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ce73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ce75  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040ce77  6683b86401000000       +cmp word ptr [eax + 0x164], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(356) /* 0x164 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040ce7f  7555                   -jne 0x40ced6
    if (!cpu.flags.zf)
    {
        goto L_0x0040ced6;
    }
    // 0040ce81  d9800c010000           +fld dword ptr [eax + 0x10c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(268) /* 0x10c */)));
    // 0040ce87  dc1d04675300           +fcomp qword ptr [0x536704]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465860) /* 0x536704 */)));
    cpu.fpu.pop();
    // 0040ce8d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ce8f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040ce90  7644                   -jbe 0x40ced6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ced6;
    }
    // 0040ce92  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ce94  c7814c06000000000000   -mov dword ptr [ecx + 0x64c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1612) /* 0x64c */) = 0 /*0x0*/;
    // 0040ce9e  8d91e4000000           -lea edx, [ecx + 0xe4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 0040cea4  e8f6d80900             -call 0x4aa79f
    cpu.esp -= 4;
    sub_4aa79f(app, cpu);
    if (cpu.terminate) return;
    // 0040cea9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ceaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040ceaf  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 0040ceb4  e897310d00             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 0040ceb9  8d91a4000000           -lea edx, [ecx + 0xa4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0040cebf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cec0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040cec5  680000003f             -push 0x3f000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1056964608 /*0x3f000000*/;
    cpu.esp -= 4;
    // 0040ceca  e881310d00             -call 0x4e0050
    cpu.esp -= 4;
    sub_4e0050(app, cpu);
    if (cpu.terminate) return;
    // 0040cecf  c68109050000ff         -mov byte ptr [ecx + 0x509], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1289) /* 0x509 */) = 255 /*0xff*/;
L_0x0040ced6:
    // 0040ced6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ced7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ced8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ced9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_40cee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cee0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cee1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cee2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cee4  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040ceeb  7507                   -jne 0x40cef4
    if (!cpu.flags.zf)
    {
        goto L_0x0040cef4;
    }
    // 0040ceed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040cef2  eb02                   -jmp 0x40cef6
    goto L_0x0040cef6;
L_0x0040cef4:
    // 0040cef4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040cef6:
    // 0040cef6  3315c0d46f00           +xor edx, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040cefc  7409                   -je 0x40cf07
    if (cpu.flags.zf)
    {
        goto L_0x0040cf07;
    }
    // 0040cefe  833d30f2560001         +cmp dword ptr [0x56f230], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cf05  7423                   -je 0x40cf2a
    if (cpu.flags.zf)
    {
        goto L_0x0040cf2a;
    }
L_0x0040cf07:
    // 0040cf07  f6802106000010         +test byte ptr [eax + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040cf0e  7407                   -je 0x40cf17
    if (cpu.flags.zf)
    {
        goto L_0x0040cf17;
    }
    // 0040cf10  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040cf15  eb02                   -jmp 0x40cf19
    goto L_0x0040cf19;
L_0x0040cf17:
    // 0040cf17  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040cf19:
    // 0040cf19  3315c0d46f00           +xor edx, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040cf1f  7451                   -je 0x40cf72
    if (cpu.flags.zf)
    {
        goto L_0x0040cf72;
    }
    // 0040cf21  833d30f25600ff         +cmp dword ptr [0x56f230], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cf28  7548                   -jne 0x40cf72
    if (!cpu.flags.zf)
    {
        goto L_0x0040cf72;
    }
L_0x0040cf2a:
    // 0040cf2a  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040cf30  4a                     -dec edx
    (cpu.edx)--;
    // 0040cf31  83fa07                 +cmp edx, 7
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
    // 0040cf34  7c08                   -jl 0x40cf3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040cf3e;
    }
    // 0040cf36  ff0590ee5600           +inc dword ptr [0x56ee90]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040cf3c  eb07                   -jmp 0x40cf45
    goto L_0x0040cf45;
L_0x0040cf3e:
    // 0040cf3e  832d90ee560003         -sub dword ptr [0x56ee90], 3
    (app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */)) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0040cf45:
    // 0040cf45  83b83806000007         +cmp dword ptr [eax + 0x638], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cf4c  7c08                   -jl 0x40cf56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040cf56;
    }
    // 0040cf4e  ff0594ee5600           +inc dword ptr [0x56ee94]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040cf54  eb07                   -jmp 0x40cf5d
    goto L_0x0040cf5d;
L_0x0040cf56:
    // 0040cf56  832d94ee560003         -sub dword ptr [0x56ee94], 3
    (app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */)) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0040cf5d:
    // 0040cf5d  8b8038060000           -mov eax, dword ptr [eax + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040cf63  40                     -inc eax
    (cpu.eax)++;
    // 0040cf64  83f807                 +cmp eax, 7
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
    // 0040cf67  7c51                   -jl 0x40cfba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040cfba;
    }
    // 0040cf69  ff0598ee5600           -inc dword ptr [0x56ee98]
    (app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */))++;
    // 0040cf6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cf70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cf71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cf72:
    // 0040cf72  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040cf78  4a                     -dec edx
    (cpu.edx)--;
    // 0040cf79  83fa07                 +cmp edx, 7
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
    // 0040cf7c  7d08                   -jge 0x40cf86
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040cf86;
    }
    // 0040cf7e  ff0590ee5600           +inc dword ptr [0x56ee90]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040cf84  eb18                   -jmp 0x40cf9e
    goto L_0x0040cf9e;
L_0x0040cf86:
    // 0040cf86  83b83806000007         +cmp dword ptr [eax + 0x638], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040cf8d  7d08                   -jge 0x40cf97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040cf97;
    }
    // 0040cf8f  ff0594ee5600           +inc dword ptr [0x56ee94]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040cf95  eb07                   -jmp 0x40cf9e
    goto L_0x0040cf9e;
L_0x0040cf97:
    // 0040cf97  832d94ee560003         -sub dword ptr [0x56ee94], 3
    (app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */)) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0040cf9e:
    // 0040cf9e  8b8038060000           -mov eax, dword ptr [eax + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040cfa4  40                     -inc eax
    (cpu.eax)++;
    // 0040cfa5  83f807                 +cmp eax, 7
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
    // 0040cfa8  7d09                   -jge 0x40cfb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040cfb3;
    }
    // 0040cfaa  ff0598ee5600           -inc dword ptr [0x56ee98]
    (app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */))++;
    // 0040cfb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cfb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cfb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040cfb3:
    // 0040cfb3  832d98ee560003         -sub dword ptr [0x56ee98], 3
    (app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */)) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0040cfba:
    // 0040cfba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cfbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040cfbc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_40cfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040cfc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040cfc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040cfc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040cfc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040cfc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040cfc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040cfc6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040cfc8  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0040cfce  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040cfd0  d980c4070000           -fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 0040cfd6  dc0d0c675300           -fmul qword ptr [0x53670c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465868) /* 0x53670c */));
    // 0040cfdc  dc0d14675300           -fmul qword ptr [0x536714]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465876) /* 0x536714 */));
    // 0040cfe2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040cfe4  e86d2d0d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0040cfe9  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040cfec  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040cfef  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0040cff2  83fb0a                 +cmp ebx, 0xa
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
    // 0040cff5  7d07                   -jge 0x40cffe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040cffe;
    }
    // 0040cff7  c745fc0a000000         -mov dword ptr [ebp - 4], 0xa
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 10 /*0xa*/;
L_0x0040cffe:
    // 0040cffe  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040d005  7507                   -jne 0x40d00e
    if (!cpu.flags.zf)
    {
        goto L_0x0040d00e;
    }
    // 0040d007  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040d00c  eb02                   -jmp 0x40d010
    goto L_0x0040d010;
L_0x0040d00e:
    // 0040d00e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040d010:
    // 0040d010  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040d016  7407                   -je 0x40d01f
    if (cpu.flags.zf)
    {
        goto L_0x0040d01f;
    }
    // 0040d018  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040d01d  eb05                   -jmp 0x40d024
    goto L_0x0040d024;
L_0x0040d01f:
    // 0040d01f  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040d024:
    // 0040d024  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0040d027  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040d02a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0040d02c:
    // 0040d02c  3b1d9cfd5e00           +cmp ebx, dword ptr [0x5efd9c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225308) /* 0x5efd9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d032  0f8d5b000000           -jge 0x40d093
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d093;
    }
    // 0040d038  3b99f0010000           +cmp ebx, dword ptr [ecx + 0x1f0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(496) /* 0x1f0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d03e  7450                   -je 0x40d090
    if (cpu.flags.zf)
    {
        goto L_0x0040d090;
    }
    // 0040d040  8b349dc8fa5e00         -mov esi, dword ptr [ebx*4 + 0x5efac8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */ + cpu.ebx * 4);
    // 0040d047  80be8900000000         +cmp byte ptr [esi + 0x89], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(137) /* 0x89 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0040d04e  7440                   -je 0x40d090
    if (cpu.flags.zf)
    {
        goto L_0x0040d090;
    }
    // 0040d050  f6860002000040         +test byte ptr [esi + 0x200], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(512) /* 0x200 */) & 64 /*0x40*/));
    // 0040d057  7537                   -jne 0x40d090
    if (!cpu.flags.zf)
    {
        goto L_0x0040d090;
    }
    // 0040d059  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0040d05b  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040d05e  e8bd100000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040d063  0faf45ec               -imul eax, dword ptr [ebp - 0x14]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */))));
    // 0040d067  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d069  7e04                   -jle 0x40d06f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d06f;
    }
    // 0040d06b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040d06d  eb04                   -jmp 0x40d073
    goto L_0x0040d073;
L_0x0040d06f:
    // 0040d06f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040d071  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0040d073:
    // 0040d073  3b55fc                 +cmp edx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d076  7f18                   -jg 0x40d090
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d090;
    }
    // 0040d078  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040d07b  c1e202                 +shl edx, 2
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
    // 0040d07e  89b42a6cffffff         -mov dword ptr [edx + ebp - 0x94], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-148) /* -0x94 */ + cpu.ebp * 1) = cpu.esi;
    // 0040d085  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040d088  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d089  89442aac               -mov dword ptr [edx + ebp - 0x54], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-84) /* -0x54 */ + cpu.ebp * 1) = cpu.eax;
    // 0040d08d  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x0040d090:
    // 0040d090  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d091  eb99                   -jmp 0x40d02c
    goto L_0x0040d02c;
L_0x0040d093:
    // 0040d093  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040d096  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040d098  a348ef5600             -mov dword ptr [0x56ef48], eax
    app->getMemory<x86::reg32>(x86::reg32(5697352) /* 0x56ef48 */) = cpu.eax;
    // 0040d09d  a34cef5600             -mov dword ptr [0x56ef4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697356) /* 0x56ef4c */) = cpu.eax;
    // 0040d0a2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040d0a4  a35cef5600             -mov dword ptr [0x56ef5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5697372) /* 0x56ef5c */) = cpu.eax;
    // 0040d0a9  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0040d0ab  a344ef5600             -mov dword ptr [0x56ef44], eax
    app->getMemory<x86::reg32>(x86::reg32(5697348) /* 0x56ef44 */) = cpu.eax;
    // 0040d0b0  893d5cef5600           -mov dword ptr [0x56ef5c], edi
    app->getMemory<x86::reg32>(x86::reg32(5697372) /* 0x56ef5c */) = cpu.edi;
    // 0040d0b6  893d60ef5600           -mov dword ptr [0x56ef60], edi
    app->getMemory<x86::reg32>(x86::reg32(5697376) /* 0x56ef60 */) = cpu.edi;
    // 0040d0bc  893d64ef5600           -mov dword ptr [0x56ef64], edi
    app->getMemory<x86::reg32>(x86::reg32(5697380) /* 0x56ef64 */) = cpu.edi;
L_0x0040d0c2:
    // 0040d0c2  3b75f4                 +cmp esi, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d0c5  0f8d13010000           -jge 0x40d1de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d1de;
    }
    // 0040d0cb  8b84b56cffffff         -mov eax, dword ptr [ebp + esi*4 - 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-148) /* -0x94 */ + cpu.esi * 4);
    // 0040d0d2  8b903c060000           -mov edx, dword ptr [eax + 0x63c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1596) /* 0x63c */);
    // 0040d0d8  3b9040060000           +cmp edx, dword ptr [eax + 0x640]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1600) /* 0x640 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d0de  7425                   -je 0x40d105
    if (cpu.flags.zf)
    {
        goto L_0x0040d105;
    }
    // 0040d0e0  8bb938060000           -mov edi, dword ptr [ecx + 0x638]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040d0e6  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040d0e8  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0040d0eb  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040d0f1  8b8040060000           -mov eax, dword ptr [eax + 0x640]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1600) /* 0x640 */);
    // 0040d0f7  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040d0f9  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040d0fb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d0fc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d0fd  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 0040d100  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040d103  eb17                   -jmp 0x40d11c
    goto L_0x0040d11c;
L_0x0040d105:
    // 0040d105  8b9938060000           -mov ebx, dword ptr [ecx + 0x638]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040d10b  8b8038060000           -mov eax, dword ptr [eax + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040d111  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d113  40                     -inc eax
    (cpu.eax)++;
    // 0040d114  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040d117  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0040d11a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0040d11c:
    // 0040d11c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0040d11e:
    // 0040d11e  3b45f8                 +cmp eax, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d121  0f8fb1000000           -jg 0x40d1d8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d1d8;
    }
    // 0040d127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d129  0f8ca3000000           -jl 0x40d1d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d1d2;
    }
    // 0040d12f  83f802                 +cmp eax, 2
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
    // 0040d132  0f8f9a000000           -jg 0x40d1d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d1d2;
    }
    // 0040d138  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 0040d13f  8b7c2aac               -mov edi, dword ptr [edx + ebp - 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-84) /* -0x54 */ + cpu.ebp * 1);
    // 0040d143  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0040d14a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040d14c  7c39                   -jl 0x40d187
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d187;
    }
    // 0040d14e  3bbb44ef5600           +cmp edi, dword ptr [ebx + 0x56ef44]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697348) /* 0x56ef44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d154  0f8d78000000           -jge 0x40d1d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d1d2;
    }
    // 0040d15a  8b942a6cffffff         -mov edx, dword ptr [edx + ebp - 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-148) /* -0x94 */ + cpu.ebp * 1);
    // 0040d161  899338ef5600           -mov dword ptr [ebx + 0x56ef38], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697336) /* 0x56ef38 */) = cpu.edx;
    // 0040d167  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040d16a  89bb44ef5600           -mov dword ptr [ebx + 0x56ef44], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697348) /* 0x56ef44 */) = cpu.edi;
    // 0040d170  39d0                   +cmp eax, edx
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
    // 0040d172  7507                   -jne 0x40d17b
    if (!cpu.flags.zf)
    {
        goto L_0x0040d17b;
    }
    // 0040d174  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040d179  eb02                   -jmp 0x40d17d
    goto L_0x0040d17d;
L_0x0040d17b:
    // 0040d17b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
L_0x0040d17d:
    // 0040d17d  6689144568ef5600       -mov word ptr [eax*2 + 0x56ef68], dx
    app->getMemory<x86::reg16>(x86::reg32(5697384) /* 0x56ef68 */ + cpu.eax * 2) = cpu.dx;
    // 0040d185  eb4b                   -jmp 0x40d1d2
    goto L_0x0040d1d2;
L_0x0040d187:
    // 0040d187  3bbb5cef5600           +cmp edi, dword ptr [ebx + 0x56ef5c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697372) /* 0x56ef5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d18d  7e43                   -jle 0x40d1d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d1d2;
    }
    // 0040d18f  8b942a6cffffff         -mov edx, dword ptr [edx + ebp - 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-148) /* -0x94 */ + cpu.ebp * 1);
    // 0040d196  89bb5cef5600           -mov dword ptr [ebx + 0x56ef5c], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697372) /* 0x56ef5c */) = cpu.edi;
    // 0040d19c  899350ef5600           -mov dword ptr [ebx + 0x56ef50], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5697360) /* 0x56ef50 */) = cpu.edx;
    // 0040d1a2  3b45f0                 +cmp eax, dword ptr [ebp - 0x10]
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
    // 0040d1a5  7507                   -jne 0x40d1ae
    if (!cpu.flags.zf)
    {
        goto L_0x0040d1ae;
    }
    // 0040d1a7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040d1ac  eb02                   -jmp 0x40d1b0
    goto L_0x0040d1b0;
L_0x0040d1ae:
    // 0040d1ae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040d1b0:
    // 0040d1b0  668914456eef5600       -mov word ptr [eax*2 + 0x56ef6e], dx
    app->getMemory<x86::reg16>(x86::reg32(5697390) /* 0x56ef6e */ + cpu.eax * 2) = cpu.dx;
    // 0040d1b8  8b148550ef5600         -mov edx, dword ptr [eax*4 + 0x56ef50]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697360) /* 0x56ef50 */ + cpu.eax * 4);
    // 0040d1bf  f6820002000020         +test byte ptr [edx + 0x200], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 32 /*0x20*/));
    // 0040d1c6  740a                   -je 0x40d1d2
    if (cpu.flags.zf)
    {
        goto L_0x0040d1d2;
    }
    // 0040d1c8  c7057cef560001000000   -mov dword ptr [0x56ef7c], 1
    app->getMemory<x86::reg32>(x86::reg32(5697404) /* 0x56ef7c */) = 1 /*0x1*/;
L_0x0040d1d2:
    // 0040d1d2  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d1d3  e946ffffff             -jmp 0x40d11e
    goto L_0x0040d11e;
L_0x0040d1d8:
    // 0040d1d8  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d1d9  e9e4feffff             -jmp 0x40d0c2
    goto L_0x0040d0c2;
L_0x0040d1de:
    // 0040d1de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040d1e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d1e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40d1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d1f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d1f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d1f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d1f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d1f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d1f7  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0040d1fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040d1fc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040d1fe  8b8038060000           -mov eax, dword ptr [eax + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040d204  48                     -dec eax
    (cpu.eax)--;
    // 0040d205  e866100000             -call 0x40e270
    cpu.esp -= 4;
    sub_40e270(app, cpu);
    if (cpu.terminate) return;
    // 0040d20a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0040d20d  8b8138060000           -mov eax, dword ptr [ecx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040d213  e858100000             -call 0x40e270
    cpu.esp -= 4;
    sub_40e270(app, cpu);
    if (cpu.terminate) return;
    // 0040d218  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0040d21b  8b8138060000           -mov eax, dword ptr [ecx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040d221  40                     -inc eax
    (cpu.eax)++;
    // 0040d222  e849100000             -call 0x40e270
    cpu.esp -= 4;
    sub_40e270(app, cpu);
    if (cpu.terminate) return;
    // 0040d227  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040d22a  8b411c                 -mov eax, dword ptr [ecx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040d22d  8945a0                 -mov dword ptr [ebp - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = cpu.eax;
    // 0040d230  39c2                   +cmp edx, eax
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
    // 0040d232  0f8498000000           -je 0x40d2d0
    if (cpu.flags.zf)
    {
        goto L_0x0040d2d0;
    }
    // 0040d238  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040d23d  eb06                   -jmp 0x40d245
    goto L_0x0040d245;
L_0x0040d23f:
    // 0040d23f  43                     -inc ebx
    (cpu.ebx)++;
    // 0040d240  83fb14                 +cmp ebx, 0x14
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
    // 0040d243  7d11                   -jge 0x40d256
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d256;
    }
L_0x0040d245:
    // 0040d245  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040d247  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040d249  e8120f0000             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 0040d24e  89449da0               -mov dword ptr [ebp + ebx*4 - 0x60], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */ + cpu.ebx * 4) = cpu.eax;
    // 0040d252  39c6                   +cmp esi, eax
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
    // 0040d254  75e9                   -jne 0x40d23f
    if (!cpu.flags.zf)
    {
        goto L_0x0040d23f;
    }
L_0x0040d256:
    // 0040d256  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040d258  eb2f                   -jmp 0x40d289
    goto L_0x0040d289;
L_0x0040d25a:
    // 0040d25a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d25b  eb48                   -jmp 0x40d2a5
    goto L_0x0040d2a5;
L_0x0040d25d:
    // 0040d25d  81aec0ee5600e8030000   -sub dword ptr [esi + 0x56eec0], 0x3e8
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5697216) /* 0x56eec0 */)) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
    // 0040d267  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040d269  7507                   -jne 0x40d272
    if (!cpu.flags.zf)
    {
        goto L_0x0040d272;
    }
    // 0040d26b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040d270  eb0a                   -jmp 0x40d27c
    goto L_0x0040d27c;
L_0x0040d272:
    // 0040d272  83f902                 +cmp ecx, 2
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
    // 0040d275  7505                   -jne 0x40d27c
    if (!cpu.flags.zf)
    {
        goto L_0x0040d27c;
    }
    // 0040d277  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0040d27c:
    // 0040d27c  a378ef5600             -mov dword ptr [0x56ef78], eax
    app->getMemory<x86::reg32>(x86::reg32(5697400) /* 0x56ef78 */) = cpu.eax;
    // 0040d281  eb4d                   -jmp 0x40d2d0
    goto L_0x0040d2d0;
L_0x0040d283:
    // 0040d283  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d284  83f903                 +cmp ecx, 3
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
    // 0040d287  7d47                   -jge 0x40d2d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d2d0;
    }
L_0x0040d289:
    // 0040d289  8d348d00000000         -lea esi, [ecx*4]
    cpu.esi = x86::reg32(cpu.ecx * 4);
    // 0040d290  8b45a0                 -mov eax, dword ptr [ebp - 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */);
    // 0040d293  8b542ef0               -mov edx, dword ptr [esi + ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ebp * 1);
    // 0040d297  e8640f0000             -call 0x40e200
    cpu.esp -= 4;
    sub_40e200(app, cpu);
    if (cpu.terminate) return;
    // 0040d29c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d29e  74bd                   -je 0x40d25d
    if (cpu.flags.zf)
    {
        goto L_0x0040d25d;
    }
    // 0040d2a0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0040d2a5:
    // 0040d2a5  39de                   +cmp esi, ebx
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
    // 0040d2a7  7dda                   -jge 0x40d283
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d283;
    }
    // 0040d2a9  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 0040d2b0  8b442ff0               -mov eax, dword ptr [edi + ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-16) /* -0x10 */ + cpu.ebp * 1);
    // 0040d2b4  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040d2b7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040d2ba  8b44b5a0               -mov eax, dword ptr [ebp + esi*4 - 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-96) /* -0x60 */ + cpu.esi * 4);
    // 0040d2be  e83d0f0000             -call 0x40e200
    cpu.esp -= 4;
    sub_40e200(app, cpu);
    if (cpu.terminate) return;
    // 0040d2c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d2c5  7593                   -jne 0x40d25a
    if (!cpu.flags.zf)
    {
        goto L_0x0040d25a;
    }
    // 0040d2c7  83afc0ee560041         +sub dword ptr [edi + 0x56eec0], 0x41
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5697216) /* 0x56eec0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040d2ce  ebb3                   -jmp 0x40d283
    goto L_0x0040d283;
L_0x0040d2d0:
    // 0040d2d0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040d2d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d2d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d2d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d2d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d2d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d2d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_40d2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d2e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d2e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d2e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d2e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d2e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d2e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d2e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040d2e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040d2eb  8a9900020000           -mov bl, byte ptr [ecx + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */);
    // 0040d2f1  8b9138060000           -mov edx, dword ptr [ecx + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040d2f7  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0040d2fa  7431                   -je 0x40d32d
    if (cpu.flags.zf)
    {
        goto L_0x0040d32d;
    }
    // 0040d2fc  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d303  7528                   -jne 0x40d32d
    if (!cpu.flags.zf)
    {
        goto L_0x0040d32d;
    }
    // 0040d305  833dacd46f0006         +cmp dword ptr [0x6fd4ac], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d30c  751f                   -jne 0x40d32d
    if (!cpu.flags.zf)
    {
        goto L_0x0040d32d;
    }
    // 0040d30e  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040d311  81ff26010000           +cmp edi, 0x126
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(294 /*0x126*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d317  7e14                   -jle 0x40d32d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d32d;
    }
    // 0040d319  81ff69010000           +cmp edi, 0x169
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(361 /*0x169*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d31f  7d0c                   -jge 0x40d32d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d32d;
    }
    // 0040d321  832da8ee560028         +sub dword ptr [0x56eea8], 0x28
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697192) /* 0x56eea8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040d328  e996000000             -jmp 0x40d3c3
    goto L_0x0040d3c3;
L_0x0040d32d:
    // 0040d32d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d32f  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040d332  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d334  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d33a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d33d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d33f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d341  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d344  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0040d347  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 0040d34c  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d34f  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d351  39f2                   +cmp edx, esi
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
    // 0040d353  7c11                   -jl 0x40d366
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d366;
    }
    // 0040d355  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d358  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d35a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d35f  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0040d362  39c2                   +cmp edx, eax
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
    // 0040d364  7e5d                   -jle 0x40d3c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d3c3;
    }
L_0x0040d366:
    // 0040d366  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0040d369  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040d370  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d372  8b0d48d95d00           -mov ecx, dword ptr [0x5dd948]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d378  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d37b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d37d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d37f  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d382  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0040d385  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0040d38a  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d38d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d38f  39da                   +cmp edx, ebx
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
    // 0040d391  7c30                   -jl 0x40d3c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d3c3;
    }
    // 0040d393  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d396  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d398  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d39d  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0040d3a0  39c2                   +cmp edx, eax
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
    // 0040d3a2  7e06                   -jle 0x40d3aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d3aa;
    }
    // 0040d3a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d3aa:
    // 0040d3aa  83fa07                 +cmp edx, 7
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
    // 0040d3ad  7d0d                   -jge 0x40d3bc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d3bc;
    }
    // 0040d3af  8305b0ee560028         -add dword ptr [0x56eeb0], 0x28
    (app->getMemory<x86::reg32>(x86::reg32(5697200) /* 0x56eeb0 */)) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0040d3b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040d3bc:
    // 0040d3bc  8305a8ee560028         -add dword ptr [0x56eea8], 0x28
    (app->getMemory<x86::reg32>(x86::reg32(5697192) /* 0x56eea8 */)) += x86::reg32(x86::sreg32(40 /*0x28*/));
L_0x0040d3c3:
    // 0040d3c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d3c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40d3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d3d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d3d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d3d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040d3d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d3d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d3d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d3d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040d3d9  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040d3dc  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040d3e3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d3e5  8b3548d95d00           -mov esi, dword ptr [0x5dd948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d3eb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d3ee  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d3f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d3f2  8a4613                 -mov al, byte ptr [esi + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d3f5  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040d3f8  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040d3fd  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d400  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d402  8b8238060000           -mov eax, dword ptr [edx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d408  48                     -dec eax
    (cpu.eax)--;
    // 0040d409  39d8                   +cmp eax, ebx
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
    // 0040d40b  7413                   -je 0x40d420
    if (cpu.flags.zf)
    {
        goto L_0x0040d420;
    }
    // 0040d40d  8a5e13                 -mov bl, byte ptr [esi + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d410  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d413  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d419  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d41c  39d8                   +cmp eax, ebx
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
    // 0040d41e  7563                   -jne 0x40d483
    if (!cpu.flags.zf)
    {
        goto L_0x0040d483;
    }
L_0x0040d420:
    // 0040d420  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0040d423  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040d42a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d42c  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d432  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d435  8b35b4ee5600           -mov esi, dword ptr [0x56eeb4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */);
    // 0040d43b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d43d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d43f  83ee1e                 -sub esi, 0x1e
    (cpu.esi) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 0040d442  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d445  8935b4ee5600           -mov dword ptr [0x56eeb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */) = cpu.esi;
    // 0040d44b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040d44d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d44f  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0040d452  8a5817                 -mov bl, byte ptr [eax + 0x17]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0040d455  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d458  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 0040d45b  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040d45e  d98214010000           -fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040d464  dc0d1c675300           -fmul qword ptr [0x53671c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465884) /* 0x53671c */));
    // 0040d46a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040d46d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d46f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d471  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d474  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d477  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d478  39c3                   +cmp ebx, eax
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
    // 0040d47a  7d07                   -jge 0x40d483
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d483;
    }
    // 0040d47c  832db4ee560032         -sub dword ptr [0x56eeb4], 0x32
    (app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */)) -= x86::reg32(x86::sreg32(50 /*0x32*/));
L_0x0040d483:
    // 0040d483  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040d48a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d48c  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d492  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d495  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d497  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d499  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d49c  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0040d49f  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0040d4a4  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d4a7  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d4a9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040d4ab  8bb238060000           -mov esi, dword ptr [edx + 0x638]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d4b1  39f3                   +cmp ebx, esi
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
    // 0040d4b3  7415                   -je 0x40d4ca
    if (cpu.flags.zf)
    {
        goto L_0x0040d4ca;
    }
    // 0040d4b5  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d4b8  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d4ba  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d4bf  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d4c2  39f0                   +cmp eax, esi
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
    // 0040d4c4  0f85c3000000           -jne 0x40d58d
    if (!cpu.flags.zf)
    {
        goto L_0x0040d58d;
    }
L_0x0040d4ca:
    // 0040d4ca  a1b8ee5600             -mov eax, dword ptr [0x56eeb8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */);
    // 0040d4cf  83e81e                 -sub eax, 0x1e
    (cpu.eax) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 0040d4d2  8b9a38060000           -mov ebx, dword ptr [edx + 0x638]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d4d8  a3b8ee5600             -mov dword ptr [0x56eeb8], eax
    app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */) = cpu.eax;
    // 0040d4dd  83fb07                 +cmp ebx, 7
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
    // 0040d4e0  7d4d                   -jge 0x40d52f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d52f;
    }
    // 0040d4e2  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0040d4e5  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040d4ec  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d4ee  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d4f4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d4f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d4f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d4fb  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d4fe  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040d500  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d502  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 0040d505  8a5817                 -mov bl, byte ptr [eax + 0x17]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0040d508  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d50b  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 0040d50e  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040d511  d98214010000           -fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040d517  dc0d1c675300           -fmul qword ptr [0x53671c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465884) /* 0x53671c */));
    // 0040d51d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040d520  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d522  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d524  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d527  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d52a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d52b  39c3                   +cmp ebx, eax
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
    // 0040d52d  7c57                   -jl 0x40d586
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d586;
    }
L_0x0040d52f:
    // 0040d52f  83ba3806000007         +cmp dword ptr [edx + 0x638], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d536  7c55                   -jl 0x40d58d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d58d;
    }
    // 0040d538  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0040d53b  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040d542  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d544  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d54a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d54d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d54f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d551  8a581b                 -mov bl, byte ptr [eax + 0x1b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0040d554  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040d556  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d559  c1e60f                 -shl esi, 0xf
    cpu.esi <<= 15 /*0xf*/ % 32;
    // 0040d55c  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d55f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d565  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040d568  d98214010000           -fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040d56e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0040d571  dc0d1c675300           -fmul qword ptr [0x53671c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465884) /* 0x53671c */));
    // 0040d577  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d579  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d57b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d57e  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d581  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d582  39c3                   +cmp ebx, eax
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
    // 0040d584  7d07                   -jge 0x40d58d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d58d;
    }
L_0x0040d586:
    // 0040d586  832db8ee560032         -sub dword ptr [0x56eeb8], 0x32
    (app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */)) -= x86::reg32(x86::sreg32(50 /*0x32*/));
L_0x0040d58d:
    // 0040d58d  8d34cd00000000         -lea esi, [ecx*8]
    cpu.esi = x86::reg32(cpu.ecx * 8);
    // 0040d594  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d596  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d59b  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0040d59e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d5a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d5a2  8a4613                 -mov al, byte ptr [esi + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d5a5  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040d5a8  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040d5ad  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d5b0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d5b2  8b8238060000           -mov eax, dword ptr [edx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d5b8  40                     -inc eax
    (cpu.eax)++;
    // 0040d5b9  39d8                   +cmp eax, ebx
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
    // 0040d5bb  7413                   -je 0x40d5d0
    if (cpu.flags.zf)
    {
        goto L_0x0040d5d0;
    }
    // 0040d5bd  8a5e13                 -mov bl, byte ptr [esi + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d5c0  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d5c3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d5c9  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d5cc  39d8                   +cmp eax, ebx
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
    // 0040d5ce  7563                   -jne 0x40d633
    if (!cpu.flags.zf)
    {
        goto L_0x0040d633;
    }
L_0x0040d5d0:
    // 0040d5d0  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0040d5d3  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0040d5da  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d5dc  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d5e1  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0040d5e4  8b35bcee5600           -mov esi, dword ptr [0x56eebc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */);
    // 0040d5ea  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d5ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d5ee  83ee1e                 -sub esi, 0x1e
    (cpu.esi) -= x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 0040d5f1  8a581b                 -mov bl, byte ptr [eax + 0x1b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0040d5f4  8935bcee5600           -mov dword ptr [0x56eebc], esi
    app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */) = cpu.esi;
    // 0040d5fa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040d5fc  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d5ff  c1e60f                 -shl esi, 0xf
    cpu.esi <<= 15 /*0xf*/ % 32;
    // 0040d602  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d605  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d60b  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0040d60e  d98214010000           -fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040d614  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0040d617  dc0d1c675300           -fmul qword ptr [0x53671c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465884) /* 0x53671c */));
    // 0040d61d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d61f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d621  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d624  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d627  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d628  39c3                   +cmp ebx, eax
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
    // 0040d62a  7d07                   -jge 0x40d633
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d633;
    }
    // 0040d62c  832dbcee560032         -sub dword ptr [0x56eebc], 0x32
    (app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */)) -= x86::reg32(x86::sreg32(50 /*0x32*/));
L_0x0040d633:
    // 0040d633  8d34cd00000000         -lea esi, [ecx*8]
    cpu.esi = x86::reg32(cpu.ecx * 8);
    // 0040d63a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d63c  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d641  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0040d644  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d646  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d648  8a4613                 -mov al, byte ptr [esi + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d64b  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040d64e  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040d653  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d656  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d658  8b8238060000           -mov eax, dword ptr [edx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d65e  48                     -dec eax
    (cpu.eax)--;
    // 0040d65f  39d8                   +cmp eax, ebx
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
    // 0040d661  7c13                   -jl 0x40d676
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d676;
    }
    // 0040d663  8a5e13                 -mov bl, byte ptr [esi + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040d666  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d669  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d66f  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d672  39d8                   +cmp eax, ebx
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
    // 0040d674  7e0a                   -jle 0x40d680
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d680;
    }
L_0x0040d676:
    // 0040d676  812db4ee5600e8030000   -sub dword ptr [0x56eeb4], 0x3e8
    (app->getMemory<x86::reg32>(x86::reg32(5697204) /* 0x56eeb4 */)) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
L_0x0040d680:
    // 0040d680  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040d687  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d689  8b1d48d95d00           -mov ebx, dword ptr [0x5dd948]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d68f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040d692  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d694  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d696  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d699  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0040d69c  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0040d6a1  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d6a4  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040d6a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040d6a8  8bb238060000           -mov esi, dword ptr [edx + 0x638]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d6ae  39f3                   +cmp ebx, esi
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
    // 0040d6b0  7f11                   -jg 0x40d6c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d6c3;
    }
    // 0040d6b2  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d6b5  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d6b7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d6bc  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d6bf  39f0                   +cmp eax, esi
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
    // 0040d6c1  7d0a                   -jge 0x40d6cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d6cd;
    }
L_0x0040d6c3:
    // 0040d6c3  812db8ee5600e8030000   -sub dword ptr [0x56eeb8], 0x3e8
    (app->getMemory<x86::reg32>(x86::reg32(5697208) /* 0x56eeb8 */)) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
L_0x0040d6cd:
    // 0040d6cd  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040d6d4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d6d6  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040d6db  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0040d6de  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d6e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d6e2  8a4813                 -mov cl, byte ptr [eax + 0x13]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d6e5  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040d6ea  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0040d6ed  8b9238060000           -mov edx, dword ptr [edx + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */);
    // 0040d6f3  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040d6f6  42                     -inc edx
    (cpu.edx)++;
    // 0040d6f7  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d6f9  39da                   +cmp edx, ebx
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
    // 0040d6fb  7c11                   -jl 0x40d70e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040d70e;
    }
    // 0040d6fd  8a4013                 -mov al, byte ptr [eax + 0x13]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040d700  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040d702  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040d707  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040d70a  39c2                   +cmp edx, eax
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
    // 0040d70c  7e0a                   -jle 0x40d718
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d718;
    }
L_0x0040d70e:
    // 0040d70e  812dbcee5600e8030000   -sub dword ptr [0x56eebc], 0x3e8
    (app->getMemory<x86::reg32>(x86::reg32(5697212) /* 0x56eebc */)) -= x86::reg32(x86::sreg32(1000 /*0x3e8*/));
L_0x0040d718:
    // 0040d718  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d719  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d71a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d71b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d71c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d71d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40d720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d720  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d721  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d722  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040d723  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d724  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d725  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d726  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d728  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040d72b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d72d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040d72f  e991000000             -jmp 0x40d7c5
    goto L_0x0040d7c5;
L_0x0040d734:
    // 0040d734  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040d736:
    // 0040d736  3305c0d46f00           +xor eax, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040d73c  7407                   -je 0x40d745
    if (cpu.flags.zf)
    {
        goto L_0x0040d745;
    }
    // 0040d73e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0040d743  eb05                   -jmp 0x40d74a
    goto L_0x0040d74a;
L_0x0040d745:
    // 0040d745  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
L_0x0040d74a:
    // 0040d74a  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040d751  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d753  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0040d756  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0040d759  8b8084d87d00           -mov eax, dword ptr [eax + 0x7dd884]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247428) /* 0x7dd884 */);
    // 0040d75f  e8bc090000             -call 0x40e120
    cpu.esp -= 4;
    sub_40e120(app, cpu);
    if (cpu.terminate) return;
    // 0040d764  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0040d767  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d769  7e54                   -jle 0x40d7bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040d7bf;
    }
    // 0040d76b  83f805                 +cmp eax, 5
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
    // 0040d76e  7f4f                   -jg 0x40d7bf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d7bf;
    }
    // 0040d770  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040d772  eb05                   -jmp 0x40d779
    goto L_0x0040d779;
L_0x0040d774:
    // 0040d774  83fa03                 +cmp edx, 3
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
    // 0040d777  7d46                   -jge 0x40d7bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d7bf;
    }
L_0x0040d779:
    // 0040d779  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040d780  8bbb38060000           -mov edi, dword ptr [ebx + 0x638]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1592) /* 0x638 */);
    // 0040d786  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0040d789  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040d78b  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0040d78e  8d47ff                 -lea eax, [edi - 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 0040d791  3b8688d87d00           +cmp eax, dword ptr [esi + 0x7dd888]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8247432) /* 0x7dd888 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d797  7523                   -jne 0x40d7bc
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7bc;
    }
    // 0040d799  832c95ccee560032       -sub dword ptr [edx*4 + 0x56eecc], 0x32
    (app->getMemory<x86::reg32>(x86::reg32(5697228) /* 0x56eecc */ + cpu.edx * 4)) -= x86::reg32(x86::sreg32(50 /*0x32*/));
    // 0040d7a1  83fa01                 +cmp edx, 1
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
    // 0040d7a4  7516                   -jne 0x40d7bc
    if (!cpu.flags.zf)
    {
        goto L_0x0040d7bc;
    }
    // 0040d7a6  d983b0070000           +fld dword ptr [ebx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040d7ac  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0040d7ae  dc0d24675300           +fmul qword ptr [0x536724]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465892) /* 0x536724 */));
    // 0040d7b4  ddd9                   +fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d7b6  d99bb0070000           +fstp dword ptr [ebx + 0x7b0]
    app->getMemory<float>(cpu.ebx + x86::reg32(1968) /* 0x7b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040d7bc:
    // 0040d7bc  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040d7bd  ebb5                   -jmp 0x40d774
    goto L_0x0040d774;
L_0x0040d7bf:
    // 0040d7bf  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d7c0  83f908                 +cmp ecx, 8
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
    // 0040d7c3  7d2c                   -jge 0x40d7f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d7f1;
    }
L_0x0040d7c5:
    // 0040d7c5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040d7cc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040d7ce  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0040d7d1  83b850d87d0000         +cmp dword ptr [eax + 0x7dd850], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8247376) /* 0x7dd850 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d7d8  74e5                   -je 0x40d7bf
    if (cpu.flags.zf)
    {
        goto L_0x0040d7bf;
    }
    // 0040d7da  f6832106000010         +test byte ptr [ebx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040d7e1  0f854dffffff           -jne 0x40d734
    if (!cpu.flags.zf)
    {
        goto L_0x0040d734;
    }
    // 0040d7e7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040d7ec  e945ffffff             -jmp 0x40d736
    goto L_0x0040d736;
L_0x0040d7f1:
    // 0040d7f1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040d7f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d7f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_40d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040d801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040d802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040d803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040d804  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040d805  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d806  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d808  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0040d80b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040d80d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040d80f  e9a9010000             -jmp 0x40d9bd
    goto L_0x0040d9bd;
L_0x0040d814:
    // 0040d814  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
L_0x0040d816:
    // 0040d816  d982c0070000           +fld dword ptr [edx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040d81c  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d81e  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040d820  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d822  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d823  7607                   -jbe 0x40d82c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040d82c;
    }
    // 0040d825  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040d82a  eb02                   -jmp 0x40d82e
    goto L_0x0040d82e;
L_0x0040d82c:
    // 0040d82c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040d82e:
    // 0040d82e  31f0                   +xor eax, esi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0040d830  0f84b4000000           -je 0x40d8ea
    if (cpu.flags.zf)
    {
        goto L_0x0040d8ea;
    }
    // 0040d836  d983c0070000           +fld dword ptr [ebx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040d83c  d8a2c0070000           +fsub dword ptr [edx + 0x7c0]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */));
    // 0040d842  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d844  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040d846  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d849  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 0040d84c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d84e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d84f  7308                   -jae 0x40d859
    if (!cpu.flags.cf)
    {
        goto L_0x0040d859;
    }
    // 0040d851  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040d854  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0040d857  eb08                   -jmp 0x40d861
    goto L_0x0040d861;
L_0x0040d859:
    // 0040d859  d945f4                 +fld dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0040d85c  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040d85e  d95dec                 +fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040d861:
    // 0040d861  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0040d864  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0040d866  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040d868  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d86a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d86b  0f8346010000           -jae 0x40d9b7
    if (!cpu.flags.cf)
    {
        goto L_0x0040d9b7;
    }
    // 0040d871  db048d44ef5600         -fild dword ptr [ecx*4 + 0x56ef44]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5697348) /* 0x56ef44 */ + cpu.ecx * 4))));
    // 0040d878  dc0d2c675300           -fmul qword ptr [0x53672c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465900) /* 0x53672c */));
    // 0040d87e  dc0d34675300           -fmul qword ptr [0x536734]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465908) /* 0x536734 */));
    // 0040d884  e8cd240d00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 0040d889  db5de8                 -fistp dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d88c  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0040d88f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040d892  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040d895  dc0d3c675300           -fmul qword ptr [0x53673c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465916) /* 0x53673c */));
    // 0040d89b  d875f4                 -fdiv dword ptr [ebp - 0xc]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    // 0040d89e  d80d44675300           -fmul dword ptr [0x536744]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5465924) /* 0x536744 */));
    // 0040d8a4  dc0d4c675300           -fmul qword ptr [0x53674c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465932) /* 0x53674c */));
    // 0040d8aa  dc0554675300           -fadd qword ptr [0x536754]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5465940) /* 0x536754 */));
    // 0040d8b0  baddffffff             -mov edx, 0xffffffdd
    cpu.edx = 4294967261 /*0xffffffdd*/;
    // 0040d8b5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d8b8  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d8bb  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d8bc  668b344d68ef5600       -mov si, word ptr [ecx*2 + 0x56ef68]
    cpu.si = app->getMemory<x86::reg16>(x86::reg32(5697384) /* 0x56ef68 */ + cpu.ecx * 2);
    // 0040d8c4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040d8c6  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0040d8c9  750b                   -jne 0x40d8d6
    if (!cpu.flags.zf)
    {
        goto L_0x0040d8d6;
    }
    // 0040d8cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040d8cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040d8d0  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040d8d2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0040d8d4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0040d8d6:
    // 0040d8d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040d8d8  0f8dd9000000           -jge 0x40d9b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d9b7;
    }
    // 0040d8de  01148dd8ee5600         +add dword ptr [ecx*4 + 0x56eed8], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697240) /* 0x56eed8 */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040d8e5  e9cd000000             -jmp 0x40d9b7
    goto L_0x0040d9b7;
L_0x0040d8ea:
    // 0040d8ea  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d8ec  d89bb0070000           +fcomp dword ptr [ebx + 0x7b0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1968) /* 0x7b0 */)));
    cpu.fpu.pop();
    // 0040d8f2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d8f4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d8f5  730b                   -jae 0x40d902
    if (!cpu.flags.cf)
    {
        goto L_0x0040d902;
    }
    // 0040d8f7  8b83b0070000           -mov eax, dword ptr [ebx + 0x7b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1968) /* 0x7b0 */);
    // 0040d8fd  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0040d900  eb0b                   -jmp 0x40d90d
    goto L_0x0040d90d;
L_0x0040d902:
    // 0040d902  d983b0070000           +fld dword ptr [ebx + 0x7b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1968) /* 0x7b0 */)));
    // 0040d908  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040d90a  d95df0                 +fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040d90d:
    // 0040d90d  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d90f  d89ac0070000           +fcomp dword ptr [edx + 0x7c0]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    cpu.fpu.pop();
    // 0040d915  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d917  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d918  730b                   -jae 0x40d925
    if (!cpu.flags.cf)
    {
        goto L_0x0040d925;
    }
    // 0040d91a  8b82c0070000           -mov eax, dword ptr [edx + 0x7c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1984) /* 0x7c0 */);
    // 0040d920  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040d923  eb0b                   -jmp 0x40d930
    goto L_0x0040d930;
L_0x0040d925:
    // 0040d925  d982c0070000           +fld dword ptr [edx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040d92b  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040d92d  d95df8                 +fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040d930:
    // 0040d930  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0040d933  d865f8                 +fsub dword ptr [ebp - 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */));
    // 0040d936  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d938  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040d93a  dd5de0                 +fstp qword ptr [ebp - 0x20]
    app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040d93d  dc5de0                 +fcomp qword ptr [ebp - 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    cpu.fpu.pop();
    // 0040d940  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d942  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d943  0f836e000000           -jae 0x40d9b7
    if (!cpu.flags.cf)
    {
        goto L_0x0040d9b7;
    }
    // 0040d949  8b348d44ef5600         -mov esi, dword ptr [ecx*4 + 0x56ef44]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5697348) /* 0x56ef44 */ + cpu.ecx * 4);
    // 0040d950  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d953  7d62                   -jge 0x40d9b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d9b7;
    }
    // 0040d955  dd45e0                 +fld qword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 0040d958  dc1d5c675300           +fcomp qword ptr [0x53675c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(x86::reg32(5465948) /* 0x53675c */)));
    cpu.fpu.pop();
    // 0040d95e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d960  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d961  7207                   -jb 0x40d96a
    if (cpu.flags.cf)
    {
        goto L_0x0040d96a;
    }
    // 0040d963  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0040d968  eb1f                   -jmp 0x40d989
    goto L_0x0040d989;
L_0x0040d96a:
    // 0040d96a  dd45e0                 -fld qword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 0040d96d  dc0d64675300           -fmul qword ptr [0x536764]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465956) /* 0x536764 */));
    // 0040d973  dc0d6c675300           -fmul qword ptr [0x53676c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465964) /* 0x53676c */));
    // 0040d979  dc0554675300           -fadd qword ptr [0x536754]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5465940) /* 0x536754 */));
    // 0040d97f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040d982  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040d985  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d986  8d50fd                 -lea edx, [eax - 3]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-3) /* -0x3 */);
L_0x0040d989:
    // 0040d989  8d46fb                 -lea eax, [esi - 5]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-5) /* -0x5 */);
    // 0040d98c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040d98e  7f02                   -jg 0x40d992
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040d992;
    }
    // 0040d990  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040d992:
    // 0040d992  668b3c4d68ef5600       -mov di, word ptr [ecx*2 + 0x56ef68]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5697384) /* 0x56ef68 */ + cpu.ecx * 2);
    // 0040d99a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040d99c  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 0040d99f  750b                   -jne 0x40d9ac
    if (!cpu.flags.zf)
    {
        goto L_0x0040d9ac;
    }
    // 0040d9a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040d9a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040d9a6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040d9a8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0040d9aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0040d9ac:
    // 0040d9ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040d9ae  7d07                   -jge 0x40d9b7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d9b7;
    }
    // 0040d9b0  01148de4ee5600         -add dword ptr [ecx*4 + 0x56eee4], edx
    (app->getMemory<x86::reg32>(x86::reg32(5697252) /* 0x56eee4 */ + cpu.ecx * 4)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0040d9b7:
    // 0040d9b7  41                     -inc ecx
    (cpu.ecx)++;
    // 0040d9b8  83f903                 +cmp ecx, 3
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
    // 0040d9bb  7d28                   -jge 0x40d9e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040d9e5;
    }
L_0x0040d9bd:
    // 0040d9bd  8b148d38ef5600         -mov edx, dword ptr [ecx*4 + 0x56ef38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */ + cpu.ecx * 4);
    // 0040d9c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040d9c6  74ef                   -je 0x40d9b7
    if (cpu.flags.zf)
    {
        goto L_0x0040d9b7;
    }
    // 0040d9c8  d983c0070000           +fld dword ptr [ebx + 0x7c0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(1984) /* 0x7c0 */)));
    // 0040d9ce  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0040d9d0  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0040d9d2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040d9d4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040d9d5  0f8639feffff           -jbe 0x40d814
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040d814;
    }
    // 0040d9db  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0040d9e0  e931feffff             -jmp 0x40d816
    goto L_0x0040d816;
L_0x0040d9e5:
    // 0040d9e5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040d9e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040d9ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40d9f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040d9f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040d9f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040d9f3  833d38ef560000         +cmp dword ptr [0x56ef38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697336) /* 0x56ef38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040d9fa  7410                   -je 0x40da0c
    if (cpu.flags.zf)
    {
        goto L_0x0040da0c;
    }
    // 0040d9fc  833d44ef560002         +cmp dword ptr [0x56ef44], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697348) /* 0x56ef44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040da03  7d07                   -jge 0x40da0c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040da0c;
    }
    // 0040da05  832d9cee560004         -sub dword ptr [0x56ee9c], 4
    (app->getMemory<x86::reg32>(x86::reg32(5697180) /* 0x56ee9c */)) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040da0c:
    // 0040da0c  833d40ef560000         +cmp dword ptr [0x56ef40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697344) /* 0x56ef40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040da13  7410                   -je 0x40da25
    if (cpu.flags.zf)
    {
        goto L_0x0040da25;
    }
    // 0040da15  833d4cef560002         +cmp dword ptr [0x56ef4c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697356) /* 0x56ef4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040da1c  7d07                   -jge 0x40da25
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040da25;
    }
    // 0040da1e  832da4ee560004         -sub dword ptr [0x56eea4], 4
    (app->getMemory<x86::reg32>(x86::reg32(5697188) /* 0x56eea4 */)) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0040da25:
    // 0040da25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040da26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40da30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040da30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040da31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040da32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040da33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040da34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040da35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040da36  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040da38  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040da3b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040da3d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040da3f  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 0040da42  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0040da45  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0040da48  eb05                   -jmp 0x40da4f
    goto L_0x0040da4f;
L_0x0040da4a:
    // 0040da4a  83fa0e                 +cmp edx, 0xe
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
    // 0040da4d  7d39                   -jge 0x40da88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040da88;
    }
L_0x0040da4f:
    // 0040da4f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040da56  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040da58  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040da5b  8b1c8590ee5600         -mov ebx, dword ptr [eax*4 + 0x56ee90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697168) /* 0x56ee90 */ + cpu.eax * 4);
    // 0040da62  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040da65  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040da67  42                     -inc edx
    (cpu.edx)++;
    // 0040da68  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 0040da6b  8b1c8594ee5600         -mov ebx, dword ptr [eax*4 + 0x56ee94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697172) /* 0x56ee94 */ + cpu.eax * 4);
    // 0040da72  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040da75  8b048598ee5600         -mov eax, dword ptr [eax*4 + 0x56ee98]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697176) /* 0x56ee98 */ + cpu.eax * 4);
    // 0040da7c  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040da7e  01c7                   +add edi, eax
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
    // 0040da80  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 0040da83  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 0040da86  ebc2                   -jmp 0x40da4a
    goto L_0x0040da4a;
L_0x0040da88:
    // 0040da88  8b8138060000           -mov eax, dword ptr [ecx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040da8e  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040da91  a374ef5600             -mov dword ptr [0x56ef74], eax
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = cpu.eax;
    // 0040da96  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040da99  39c2                   +cmp edx, eax
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
    // 0040da9b  7e0e                   -jle 0x40daab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040daab;
    }
    // 0040da9d  8b8138060000           -mov eax, dword ptr [ecx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040daa3  48                     -dec eax
    (cpu.eax)--;
    // 0040daa4  a374ef5600             -mov dword ptr [0x56ef74], eax
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = cpu.eax;
    // 0040daa9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0040daab:
    // 0040daab  3b45fc                 +cmp eax, dword ptr [ebp - 4]
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
    // 0040daae  7d0c                   -jge 0x40dabc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040dabc;
    }
    // 0040dab0  8b8138060000           -mov eax, dword ptr [ecx + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1592) /* 0x638 */);
    // 0040dab6  40                     -inc eax
    (cpu.eax)++;
    // 0040dab7  a374ef5600             -mov dword ptr [0x56ef74], eax
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = cpu.eax;
L_0x0040dabc:
    // 0040dabc  8b3d74ef5600           -mov edi, dword ptr [0x56ef74]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */);
    // 0040dac2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040dac4  7d09                   -jge 0x40dacf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040dacf;
    }
    // 0040dac6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040dac8  a374ef5600             -mov dword ptr [0x56ef74], eax
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = cpu.eax;
    // 0040dacd  eb0f                   -jmp 0x40dade
    goto L_0x0040dade;
L_0x0040dacf:
    // 0040dacf  83ff0e                 +cmp edi, 0xe
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040dad2  7c0a                   -jl 0x40dade
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040dade;
    }
    // 0040dad4  c70574ef56000d000000   -mov dword ptr [0x56ef74], 0xd
    app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */) = 13 /*0xd*/;
L_0x0040dade:
    // 0040dade  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dae0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40daf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040daf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040daf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040daf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040daf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040daf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040daf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040daf6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040daf8  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0040dafb  8b3548d95d00           -mov esi, dword ptr [0x5dd948]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040db01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040db03  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040db06  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040db0d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040db0f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040db12  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040db14  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0040db16  31f3                   -xor ebx, esi
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040db18  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040db1b  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0040db1e  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 0040db23  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040db26  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040db28  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0040db2a  8b3d74ef5600           -mov edi, dword ptr [0x56ef74]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */);
    // 0040db30  39fb                   +cmp ebx, edi
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
    // 0040db32  7417                   -je 0x40db4b
    if (cpu.flags.zf)
    {
        goto L_0x0040db4b;
    }
    // 0040db34  8a5813                 -mov bl, byte ptr [eax + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */);
    // 0040db37  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040db3a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040db40  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040db43  39fb                   +cmp ebx, edi
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
    // 0040db45  0f85a8000000           -jne 0x40dbf3
    if (!cpu.flags.zf)
    {
        goto L_0x0040dbf3;
    }
L_0x0040db4b:
    // 0040db4b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040db52  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040db54  8b1d74ef5600           -mov ebx, dword ptr [0x56ef74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */);
    // 0040db5a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040db5d  83fb07                 +cmp ebx, 7
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
    // 0040db60  7d48                   -jge 0x40dbaa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040dbaa;
    }
    // 0040db62  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040db64  8a440317               -mov al, byte ptr [ebx + eax + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */ + cpu.eax * 1);
    // 0040db68  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040db6d  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040db70  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040db73  8b3d74ef5600           -mov edi, dword ptr [0x56ef74]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */);
    // 0040db79  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040db7c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0040db81  dc0d74675300           -fmul qword ptr [0x536774]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */));
    // 0040db87  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040db89  48                     -dec eax
    (cpu.eax)--;
    // 0040db8a  f7d8                   +neg eax
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
    // 0040db8c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040db8f  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040db92  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040db94  d98214010000           +fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040db9a  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040db9c  d99ab4070000           +fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dba2  d8aab4070000           +fsubr dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) - cpu.fpu.st(0);
    // 0040dba8  eb3e                   -jmp 0x40dbe8
    goto L_0x0040dbe8;
L_0x0040dbaa:
    // 0040dbaa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040dbac  8a44031b               -mov al, byte ptr [ebx + eax + 0x1b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(27) /* 0x1b */ + cpu.eax * 1);
    // 0040dbb0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040dbb5  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040dbb8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040dbbb  a174ef5600             -mov eax, dword ptr [0x56ef74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697396) /* 0x56ef74 */);
    // 0040dbc0  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dbc3  83e807                 +sub eax, 7
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040dbc6  dc0d74675300           +fmul qword ptr [0x536774]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */));
    // 0040dbcc  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040dbcf  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dbd2  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040dbd4  d98214010000           +fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040dbda  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dbdc  d99ab4070000           +fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dbe2  d882b4070000           +fadd dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */));
L_0x0040dbe8:
    // 0040dbe8  d99ab4070000           +fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dbee  e9a4000000             -jmp 0x40dc97
    goto L_0x0040dc97;
L_0x0040dbf3:
    // 0040dbf3  83ff07                 +cmp edi, 7
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040dbf6  7d51                   -jge 0x40dc49
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040dc49;
    }
    // 0040dbf8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040dbfa  8a5817                 -mov bl, byte ptr [eax + 0x17]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0040dbfd  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 0040dc00  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040dc03  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc06  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0040dc0b  dd0574675300           -fld qword ptr [0x536774]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */)));
    // 0040dc11  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dc13  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040dc15  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040dc17  4b                     -dec ebx
    (cpu.ebx)--;
    // 0040dc18  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0040dc1a  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040dc1d  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc20  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040dc22  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dc28  8a4017                 -mov al, byte ptr [eax + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(23) /* 0x17 */);
    // 0040dc2b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040dc30  c1e00f                 +shl eax, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0040dc33  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040dc36  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc39  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040dc3b  dc0d7c675300           +fmul qword ptr [0x53677c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465980) /* 0x53677c */));
    // 0040dc41  d8aab4070000           +fsubr dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) - cpu.fpu.st(0);
    // 0040dc47  eb48                   -jmp 0x40dc91
    goto L_0x0040dc91;
L_0x0040dc49:
    // 0040dc49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040dc4b  8a581b                 -mov bl, byte ptr [eax + 0x1b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0040dc4e  c1e30f                 -shl ebx, 0xf
    cpu.ebx <<= 15 /*0xf*/ % 32;
    // 0040dc51  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040dc54  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc57  8d5ff9                 -lea ebx, [edi - 7]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(-7) /* -0x7 */);
    // 0040dc5a  dd0574675300           -fld qword ptr [0x536774]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */)));
    // 0040dc60  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dc62  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040dc64  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040dc67  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc6a  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040dc6c  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dc72  8a401b                 -mov al, byte ptr [eax + 0x1b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(27) /* 0x1b */);
    // 0040dc75  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040dc7a  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040dc7d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040dc80  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dc83  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040dc85  dc0d7c675300           -fmul qword ptr [0x53677c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465980) /* 0x53677c */));
    // 0040dc8b  d882b4070000           -fadd dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */));
L_0x0040dc91:
    // 0040dc91  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040dc97:
    // 0040dc97  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040dc9e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040dca0  01c8                   +add eax, ecx
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
    // 0040dca2  db448320               +fild dword ptr [ebx + eax*4 + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */ + cpu.eax * 4))));
    // 0040dca6  dc0d74675300           +fmul qword ptr [0x536774]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */));
    // 0040dcac  d98214010000           +fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040dcb2  dd5de4                 +fstp qword ptr [ebp - 0x1c]
    app->getMemory<double>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcb5  dc65e4                 +fsub qword ptr [ebp - 0x1c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    // 0040dcb8  d982b4070000           +fld dword ptr [edx + 0x7b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */)));
    // 0040dcbe  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dcc0  dd5df4                 +fstp qword ptr [ebp - 0xc]
    app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcc3  dc5df4                 +fcomp qword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 0040dcc6  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dcc8  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040dcc9  7609                   -jbe 0x40dcd4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040dcd4;
    }
    // 0040dccb  dd45f4                 -fld qword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    // 0040dcce  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040dcd4:
    // 0040dcd4  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0040dcdb  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040dcdd  c1e102                 +shl ecx, 2
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
    // 0040dce0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040dce2  db44011c               +fild dword ptr [ecx + eax + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */ + cpu.eax * 1))));
    // 0040dce6  dc0d74675300           +fmul qword ptr [0x536774]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465972) /* 0x536774 */));
    // 0040dcec  d98214010000           +fld dword ptr [edx + 0x114]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */)));
    // 0040dcf2  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dcf4  dd5dd4                 +fstp qword ptr [ebp - 0x2c]
    app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dcf7  dc65d4                 +fsub qword ptr [ebp - 0x2c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-44) /* -0x2c */));
    // 0040dcfa  d982b4070000           +fld dword ptr [edx + 0x7b4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */)));
    // 0040dd00  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040dd02  dd5dec                 +fstp qword ptr [ebp - 0x14]
    app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040dd05  dc5dec                 +fcomp qword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    cpu.fpu.pop();
    // 0040dd08  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040dd0a  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040dd0b  7309                   -jae 0x40dd16
    if (!cpu.flags.cf)
    {
        goto L_0x0040dd16;
    }
    // 0040dd0d  dd45ec                 -fld qword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0040dd10  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040dd16:
    // 0040dd16  833d78ef560000         +cmp dword ptr [0x56ef78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5697400) /* 0x56ef78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040dd1d  7430                   -je 0x40dd4f
    if (cpu.flags.zf)
    {
        goto L_0x0040dd4f;
    }
    // 0040dd1f  f6822106000010         +test byte ptr [edx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040dd26  740f                   -je 0x40dd37
    if (cpu.flags.zf)
    {
        goto L_0x0040dd37;
    }
    // 0040dd28  a178ef5600             -mov eax, dword ptr [0x56ef78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5697400) /* 0x56ef78 */);
    // 0040dd2d  f7d8                   +neg eax
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
    // 0040dd2f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040dd32  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040dd35  eb06                   -jmp 0x40dd3d
    goto L_0x0040dd3d;
L_0x0040dd37:
    // 0040dd37  db0578ef5600           -fild dword ptr [0x56ef78]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5697400) /* 0x56ef78 */))));
L_0x0040dd3d:
    // 0040dd3d  d88a14010000           -fmul dword ptr [edx + 0x114]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(276) /* 0x114 */));
    // 0040dd43  d882b4070000           -fadd dword ptr [edx + 0x7b4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */));
    // 0040dd49  d99ab4070000           -fstp dword ptr [edx + 0x7b4]
    app->getMemory<float>(cpu.edx + x86::reg32(1972) /* 0x7b4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040dd4f:
    // 0040dd4f  893548d95d00           -mov dword ptr [0x5dd948], esi
    app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */) = cpu.esi;
    // 0040dd55  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dd57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dd5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40dd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040dd60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040dd61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040dd62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040dd63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040dd64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040dd66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040dd68  bba8000000             -mov ebx, 0xa8
    cpu.ebx = 168 /*0xa8*/;
    // 0040dd6d  b890ee5600             -mov eax, 0x56ee90
    cpu.eax = 5697168 /*0x56ee90*/;
    // 0040dd72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040dd74  e8c7280d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0040dd79  bb48000000             -mov ebx, 0x48
    cpu.ebx = 72 /*0x48*/;
    // 0040dd7e  b838ef5600             -mov eax, 0x56ef38
    cpu.eax = 5697336 /*0x56ef38*/;
    // 0040dd83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040dd85  e8b6280d00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0040dd8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040dd8c  e8bf050000             -call 0x40e350
    cpu.esp -= 4;
    sub_40e350(app, cpu);
    if (cpu.terminate) return;
    // 0040dd91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040dd93  e848f1ffff             -call 0x40cee0
    cpu.esp -= 4;
    sub_40cee0(app, cpu);
    if (cpu.terminate) return;
    // 0040dd98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040dd9a  e821f2ffff             -call 0x40cfc0
    cpu.esp -= 4;
    sub_40cfc0(app, cpu);
    if (cpu.terminate) return;
    // 0040dd9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dda0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dda1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dda2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dda3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_40ddb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ddb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ddb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ddb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ddb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ddb4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ddb6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040ddb8  d980c4070000           -fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 0040ddbe  dc0d84675300           -fmul qword ptr [0x536784]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465988) /* 0x536784 */));
    // 0040ddc4  dc0d8c675300           -fmul qword ptr [0x53678c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5465996) /* 0x53678c */));
    // 0040ddca  dc0594675300           -fadd qword ptr [0x536794]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466004) /* 0x536794 */));
    // 0040ddd0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ddd3  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040ddd6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ddd7  83f809                 +cmp eax, 9
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
    // 0040ddda  7e04                   -jle 0x40dde0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040dde0;
    }
    // 0040dddc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040ddde  eb05                   -jmp 0x40dde5
    goto L_0x0040dde5;
L_0x0040dde0:
    // 0040dde0  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
L_0x0040dde5:
    // 0040dde5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040dde7  e874030000             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 0040ddec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040ddee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040ddf0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ddf2  e8e9f4ffff             -call 0x40d2e0
    cpu.esp -= 4;
    sub_40d2e0(app, cpu);
    if (cpu.terminate) return;
    // 0040ddf7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040ddf9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ddfb  e8f0f3ffff             -call 0x40d1f0
    cpu.esp -= 4;
    sub_40d1f0(app, cpu);
    if (cpu.terminate) return;
    // 0040de00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040de02  e8c9f5ffff             -call 0x40d3d0
    cpu.esp -= 4;
    sub_40d3d0(app, cpu);
    if (cpu.terminate) return;
    // 0040de07  f6810002000004         +test byte ptr [ecx + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 0040de0e  7515                   -jne 0x40de25
    if (!cpu.flags.zf)
    {
        goto L_0x0040de25;
    }
    // 0040de10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040de12  e809f9ffff             -call 0x40d720
    cpu.esp -= 4;
    sub_40d720(app, cpu);
    if (cpu.terminate) return;
    // 0040de17  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040de19  e8e2f9ffff             -call 0x40d800
    cpu.esp -= 4;
    sub_40d800(app, cpu);
    if (cpu.terminate) return;
    // 0040de1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040de20  e8cbfbffff             -call 0x40d9f0
    cpu.esp -= 4;
    sub_40d9f0(app, cpu);
    if (cpu.terminate) return;
L_0x0040de25:
    // 0040de25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_40de30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040de30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040de31  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040de32  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040de34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040de36  e8f5fbffff             -call 0x40da30
    cpu.esp -= 4;
    sub_40da30(app, cpu);
    if (cpu.terminate) return;
    // 0040de3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040de3d  e8aefcffff             -call 0x40daf0
    cpu.esp -= 4;
    sub_40daf0(app, cpu);
    if (cpu.terminate) return;
    // 0040de42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40de50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040de50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040de51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040de52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040de54  80882006000008         -or byte ptr [eax + 0x620], 8
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0040de5b  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040de61  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0040de64  899044060000           -mov dword ptr [eax + 0x644], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1604) /* 0x644 */) = cpu.edx;
    // 0040de6a  8b9060060000           -mov edx, dword ptr [eax + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */);
    // 0040de70  83fa01                 +cmp edx, 1
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
    // 0040de73  7209                   -jb 0x40de7e
    if (cpu.flags.cf)
    {
        goto L_0x0040de7e;
    }
    // 0040de75  7618                   -jbe 0x40de8f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040de8f;
    }
    // 0040de77  83fa02                 +cmp edx, 2
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
    // 0040de7a  7420                   -je 0x40de9c
    if (cpu.flags.zf)
    {
        goto L_0x0040de9c;
    }
    // 0040de7c  eb1e                   -jmp 0x40de9c
    goto L_0x0040de9c;
L_0x0040de7e:
    // 0040de7e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040de80  751a                   -jne 0x40de9c
    if (!cpu.flags.zf)
    {
        goto L_0x0040de9c;
    }
    // 0040de82  c7806006000001000000   -mov dword ptr [eax + 0x660], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */) = 1 /*0x1*/;
    // 0040de8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040de8f:
    // 0040de8f  c7806006000002000000   -mov dword ptr [eax + 0x660], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */) = 2 /*0x2*/;
    // 0040de99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040de9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040de9c:
    // 0040de9c  c7806006000000000000   -mov dword ptr [eax + 0x660], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */) = 0 /*0x0*/;
    // 0040dea6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dea7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dea8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40deb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040deb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040deb1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040deb2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040deb4  f6802006000008         +test byte ptr [eax + 0x620], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) & 8 /*0x8*/));
    // 0040debb  7446                   -je 0x40df03
    if (cpu.flags.zf)
    {
        goto L_0x0040df03;
    }
    // 0040debd  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040dec3  3b9044060000           +cmp edx, dword ptr [eax + 0x644]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1604) /* 0x644 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040dec9  7e38                   -jle 0x40df03
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040df03;
    }
    // 0040decb  80a020060000f7         -and byte ptr [eax + 0x620], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0040ded2  8b9060060000           -mov edx, dword ptr [eax + 0x660]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */);
    // 0040ded8  83fa01                 +cmp edx, 1
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
    // 0040dedb  720a                   -jb 0x40dee7
    if (cpu.flags.cf)
    {
        goto L_0x0040dee7;
    }
    // 0040dedd  760d                   -jbe 0x40deec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040deec;
    }
    // 0040dedf  83fa02                 +cmp edx, 2
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
    // 0040dee2  7415                   -je 0x40def9
    if (cpu.flags.zf)
    {
        goto L_0x0040def9;
    }
    // 0040dee4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dee5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dee6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040dee7:
    // 0040dee7  85d2                   -test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040dee9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040deea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040deeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040deec:
    // 0040deec  c7806006000000000000   -mov dword ptr [eax + 0x660], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */) = 0 /*0x0*/;
    // 0040def6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040def7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040def8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040def9:
    // 0040def9  c7806006000001000000   -mov dword ptr [eax + 0x660], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1632) /* 0x660 */) = 1 /*0x1*/;
L_0x0040df03:
    // 0040df03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040df04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040df05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_40df10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040df10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040df11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040df12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040df13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040df14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040df15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040df16  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040df18  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040df1b  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040df1e  e81d33ffff             -call 0x401240
    cpu.esp -= 4;
    sub_401240(app, cpu);
    if (cpu.terminate) return;
    // 0040df23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040df25  0f84c9000000           -je 0x40dff4
    if (cpu.flags.zf)
    {
        goto L_0x0040dff4;
    }
    // 0040df2b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040df2e  8b8030060000           -mov eax, dword ptr [eax + 0x630]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */);
    // 0040df34  83f801                 +cmp eax, 1
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
    // 0040df37  720d                   -jb 0x40df46
    if (cpu.flags.cf)
    {
        goto L_0x0040df46;
    }
    // 0040df39  7659                   -jbe 0x40df94
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040df94;
    }
    // 0040df3b  83f802                 +cmp eax, 2
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
    // 0040df3e  0f847f000000           -je 0x40dfc3
    if (cpu.flags.zf)
    {
        goto L_0x0040dfc3;
    }
    // 0040df44  eb02                   -jmp 0x40df48
    goto L_0x0040df48;
L_0x0040df46:
    // 0040df46  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
L_0x0040df48:
    // 0040df48  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040df4b  8a9020060000           -mov dl, byte ptr [eax + 0x620]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1568) /* 0x620 */);
    // 0040df51  c7803006000002000000   -mov dword ptr [eax + 0x630], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */) = 2 /*0x2*/;
    // 0040df5b  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0040df5e  7430                   -je 0x40df90
    if (cpu.flags.zf)
    {
        goto L_0x0040df90;
    }
    // 0040df60  8d7df0                 -lea edi, [ebp - 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040df63  8d5df0                 -lea ebx, [ebp - 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040df66  be0ccb4000             -mov esi, 0x40cb0c
    cpu.esi = 4246284 /*0x40cb0c*/;
    // 0040df6b  8b0dc0d46f00           -mov ecx, dword ptr [0x6fd4c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 0040df71  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040df73  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040df74  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040df75  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040df76  e8252b0900             -call 0x4a0aa0
    cpu.esp -= 4;
    sub_4a0aa0(app, cpu);
    if (cpu.terminate) return;
    // 0040df7b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040df7e  e8bd7dffff             -call 0x405d40
    cpu.esp -= 4;
    sub_405d40(app, cpu);
    if (cpu.terminate) return;
    // 0040df83  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040df86  c7803006000001000000   -mov dword ptr [eax + 0x630], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */) = 1 /*0x1*/;
L_0x0040df90:
    // 0040df90  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040df92  eb60                   -jmp 0x40dff4
    goto L_0x0040dff4;
L_0x0040df94:
    // 0040df94  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040df97  e8847effff             -call 0x405e20
    cpu.esp -= 4;
    sub_405e20(app, cpu);
    if (cpu.terminate) return;
    // 0040df9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040df9e  7454                   -je 0x40dff4
    if (cpu.flags.zf)
    {
        goto L_0x0040dff4;
    }
    // 0040dfa0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040dfa3  e8187effff             -call 0x405dc0
    cpu.esp -= 4;
    sub_405dc0(app, cpu);
    if (cpu.terminate) return;
    // 0040dfa8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040dfab  c7803006000002000000   -mov dword ptr [eax + 0x630], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */) = 2 /*0x2*/;
    // 0040dfb5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040dfba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dfbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040dfc3:
    // 0040dfc3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040dfc6  e8057dffff             -call 0x405cd0
    cpu.esp -= 4;
    sub_405cd0(app, cpu);
    if (cpu.terminate) return;
    // 0040dfcb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040dfcd  7420                   -je 0x40dfef
    if (cpu.flags.zf)
    {
        goto L_0x0040dfef;
    }
    // 0040dfcf  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040dfd2  e8697dffff             -call 0x405d40
    cpu.esp -= 4;
    sub_405d40(app, cpu);
    if (cpu.terminate) return;
    // 0040dfd7  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040dfda  c7803006000001000000   -mov dword ptr [eax + 0x630], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1584) /* 0x630 */) = 1 /*0x1*/;
    // 0040dfe4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040dfe6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dfe8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfe9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dfee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040dfef:
    // 0040dfef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0040dff4:
    // 0040dff4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040dff6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dff7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dff8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dff9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dffa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dffb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040dffc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_40e000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e002  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e005  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e007  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e00e  7407                   -je 0x40e017
    if (cpu.flags.zf)
    {
        goto L_0x0040e017;
    }
    // 0040e010  b89c675300             -mov eax, 0x53679c
    cpu.eax = 5466012 /*0x53679c*/;
    // 0040e015  eb05                   -jmp 0x40e01c
    goto L_0x0040e01c;
L_0x0040e017:
    // 0040e017  b8a8675300             -mov eax, 0x5367a8
    cpu.eax = 5466024 /*0x5367a8*/;
L_0x0040e01c:
    // 0040e01c  e8aff80000             -call 0x41d8d0
    cpu.esp -= 4;
    sub_41d8d0(app, cpu);
    if (cpu.terminate) return;
    // 0040e021  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e023  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e025  e8362e0d00             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0040e02a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e02c  7439                   -je 0x40e067
    if (cpu.flags.zf)
    {
        goto L_0x0040e067;
    }
    // 0040e02e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0040e033  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e035  e8862e0d00             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0040e03a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e03c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e03e  7427                   -je 0x40e067
    if (cpu.flags.zf)
    {
        goto L_0x0040e067;
    }
    // 0040e040  8b1540d95d00           -mov edx, dword ptr [0x5dd940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040e046  42                     -inc edx
    (cpu.edx)++;
    // 0040e047  a358255500             -mov dword ptr [0x552558], eax
    app->getMemory<x86::reg32>(x86::reg32(5580120) /* 0x552558 */) = cpu.eax;
    // 0040e04c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e04e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040e051  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e053  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0040e055  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040e057  890d5c255500           -mov dword ptr [0x55255c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5580124) /* 0x55255c */) = cpu.ecx;
    // 0040e05d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040e05f  890d2cf25600           -mov dword ptr [0x56f22c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5698092) /* 0x56f22c */) = cpu.ecx;
    // 0040e065  eb13                   -jmp 0x40e07a
    goto L_0x0040e07a;
L_0x0040e067:
    // 0040e067  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040e069  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0040e06e  893558255500           -mov dword ptr [0x552558], esi
    app->getMemory<x86::reg32>(x86::reg32(5580120) /* 0x552558 */) = cpu.esi;
    // 0040e074  891d2cf25600           -mov dword ptr [0x56f22c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698092) /* 0x56f22c */) = cpu.ebx;
L_0x0040e07a:
    // 0040e07a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e07b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e07c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e07d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e07e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e07f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_40e080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e080  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e081  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e082  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e084  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e087  833d2cf2560000         +cmp dword ptr [0x56f22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698092) /* 0x56f22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e08e  7409                   -je 0x40e099
    if (cpu.flags.zf)
    {
        goto L_0x0040e099;
    }
    // 0040e090  c745f800008042         -mov dword ptr [ebp - 8], 0x42800000
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 1115684864 /*0x42800000*/;
    // 0040e097  eb18                   -jmp 0x40e0b1
    goto L_0x0040e0b1;
L_0x0040e099:
    // 0040e099  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e09b  a158255500             -mov eax, dword ptr [0x552558]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5580120) /* 0x552558 */);
    // 0040e0a0  d1ea                   -shr edx, 1
    cpu.edx >>= 1 /*0x1*/ % 32;
    // 0040e0a2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040e0a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e0a6  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0040e0a8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040e0ab  df45fc                 -fild word ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040e0ae  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040e0b1:
    // 0040e0b1  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0040e0b4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040e0b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40e0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e0c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e0c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e0c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e0c4  833d2cf2560000         +cmp dword ptr [0x56f22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698092) /* 0x56f22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e0cb  7408                   -je 0x40e0d5
    if (cpu.flags.zf)
    {
        goto L_0x0040e0d5;
    }
    // 0040e0cd  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0040e0d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040e0d5:
    // 0040e0d5  8b155c255500           -mov edx, dword ptr [0x55255c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5580124) /* 0x55255c */);
    // 0040e0db  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 0040e0de  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040e0e3  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040e0e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e0e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40e0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e0f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e0f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e0f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e0f4  e8a70b0000             -call 0x40eca0
    cpu.esp -= 4;
    sub_40eca0(app, cpu);
    if (cpu.terminate) return;
    // 0040e0f9  a328f25600             -mov dword ptr [0x56f228], eax
    app->getMemory<x86::reg32>(x86::reg32(5698088) /* 0x56f228 */) = cpu.eax;
    // 0040e0fe  e86d0b0000             -call 0x40ec70
    cpu.esp -= 4;
    sub_40ec70(app, cpu);
    if (cpu.terminate) return;
    // 0040e103  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e105  a330f25600             -mov dword ptr [0x56f230], eax
    app->getMemory<x86::reg32>(x86::reg32(5698096) /* 0x56f230 */) = cpu.eax;
    // 0040e10a  891520f25600           -mov dword ptr [0x56f220], edx
    app->getMemory<x86::reg32>(x86::reg32(5698080) /* 0x56f220 */) = cpu.edx;
    // 0040e110  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e111  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e112  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40e120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e122  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e123  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e124  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e126  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040e12c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040e12e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0040e130  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040e132  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e134  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040e137  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e139  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0040e13b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e13d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0040e13f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e141  39d0                   +cmp eax, edx
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
    // 0040e143  7e04                   -jle 0x40e149
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040e149;
    }
    // 0040e145  29c8                   +sub eax, ecx
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
    // 0040e147  eb08                   -jmp 0x40e151
    goto L_0x0040e151;
L_0x0040e149:
    // 0040e149  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0040e14b  39d0                   +cmp eax, edx
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
    // 0040e14d  7d02                   -jge 0x40e151
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e151;
    }
    // 0040e14f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040e151:
    // 0040e151  890d40d95d00           -mov dword ptr [0x5dd940], ecx
    app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */) = cpu.ecx;
    // 0040e157  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e158  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e159  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e15a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e15b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40e160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e162  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e163  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e165  8b1d40d95d00           -mov ebx, dword ptr [0x5dd940]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040e16b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e16d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e16f  f6812106000010         +test byte ptr [ecx + 0x621], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1569) /* 0x621 */) & 16 /*0x10*/));
    // 0040e176  7507                   -jne 0x40e17f
    if (!cpu.flags.zf)
    {
        goto L_0x0040e17f;
    }
    // 0040e178  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040e17d  eb02                   -jmp 0x40e181
    goto L_0x0040e181;
L_0x0040e17f:
    // 0040e17f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040e181:
    // 0040e181  3315c0d46f00           +xor edx, dword ptr [0x6fd4c0]
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */)))));
    // 0040e187  7502                   -jne 0x40e18b
    if (!cpu.flags.zf)
    {
        goto L_0x0040e18b;
    }
    // 0040e189  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0040e18b:
    // 0040e18b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e18d  7c0b                   -jl 0x40e19a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040e19a;
    }
    // 0040e18f  03411c                 -add eax, dword ptr [ecx + 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 0040e192  39d8                   +cmp eax, ebx
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
    // 0040e194  7c0d                   -jl 0x40e1a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040e1a3;
    }
    // 0040e196  29d8                   +sub eax, ebx
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
    // 0040e198  eb09                   -jmp 0x40e1a3
    goto L_0x0040e1a3;
L_0x0040e19a:
    // 0040e19a  03411c                 -add eax, dword ptr [ecx + 0x1c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */)));
    // 0040e19d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040e19f  7d02                   -jge 0x40e1a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e1a3;
    }
    // 0040e1a1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x0040e1a3:
    // 0040e1a3  891d40d95d00           -mov dword ptr [0x5dd940], ebx
    app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */) = cpu.ebx;
    // 0040e1a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_40e1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e1b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e1b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e1b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e1b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e1b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e1b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e1b7  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0040e1ba  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0040e1bd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040e1bf  d980c4070000           -fld dword ptr [eax + 0x7c4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(1988) /* 0x7c4 */)));
    // 0040e1c5  d84d18                 -fmul dword ptr [ebp + 0x18]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 0040e1c8  dc0db4675300           -fmul qword ptr [0x5367b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5466036) /* 0x5367b4 */));
    // 0040e1ce  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e1d1  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040e1d4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e1d7  39d8                   +cmp eax, ebx
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
    // 0040e1d9  7d02                   -jge 0x40e1dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e1dd;
    }
    // 0040e1db  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0040e1dd:
    // 0040e1dd  39f2                   +cmp edx, esi
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
    // 0040e1df  7e02                   -jle 0x40e1e3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040e1e3;
    }
    // 0040e1e1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0040e1e3:
    // 0040e1e3  83b9d407000001         +cmp dword ptr [ecx + 0x7d4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2004) /* 0x7d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e1ea  7502                   -jne 0x40e1ee
    if (!cpu.flags.zf)
    {
        goto L_0x0040e1ee;
    }
    // 0040e1ec  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0040e1ee:
    // 0040e1ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e1f0  e86bffffff             -call 0x40e160
    cpu.esp -= 4;
    sub_40e160(app, cpu);
    if (cpu.terminate) return;
    // 0040e1f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e1fa  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_40e200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e201  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e202  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e204  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040e206  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e208  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040e20b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040e20d  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040e213  8b44820a               -mov eax, dword ptr [edx + eax*4 + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */ + cpu.eax * 4);
    // 0040e217  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040e21a  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e21c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e21d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e21e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40e220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e223  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e225  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040e227  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0040e22c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e22e  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0040e233  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e235  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e237  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040e239  7d04                   -jge 0x40e23f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e23f;
    }
    // 0040e23b  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040e23d  eb0a                   -jmp 0x40e249
    goto L_0x0040e249;
L_0x0040e23f:
    // 0040e23f  83fa10                 +cmp edx, 0x10
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
    // 0040e242  7c05                   -jl 0x40e249
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040e249;
    }
    // 0040e244  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
L_0x0040e249:
    // 0040e249  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0040e24e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e250  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0040e252  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040e257  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040e259  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0040e25b  e8a0ffffff             -call 0x40e200
    cpu.esp -= 4;
    sub_40e200(app, cpu);
    if (cpu.terminate) return;
    // 0040e260  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e261  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e262  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e263  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_40e270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e271  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e272  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e273  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e275  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0040e27a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e27c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e27e  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0040e283  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e285  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040e287  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040e289  7d04                   -jge 0x40e28f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e28f;
    }
    // 0040e28b  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040e28d  eb0a                   -jmp 0x40e299
    goto L_0x0040e299;
L_0x0040e28f:
    // 0040e28f  83fa10                 +cmp edx, 0x10
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
    // 0040e292  7c05                   -jl 0x40e299
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040e299;
    }
    // 0040e294  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
L_0x0040e299:
    // 0040e299  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0040e29e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040e2a0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040e2a5  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0040e2a7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0040e2a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e2aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e2ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e2ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_40e2b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e2b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e2b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e2b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e2b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e2b5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040e2b8  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0040e2bf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040e2c1  d9ee                   -fldz 
    cpu.fpu.push(0.0);
    // 0040e2c3  c1e102                 +shl ecx, 2
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
    // 0040e2c6  d85d10                 +fcomp dword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    cpu.fpu.pop();
    // 0040e2c9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040e2cb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040e2cc  7610                   -jbe 0x40e2de
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040e2de;
    }
    // 0040e2ce  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040e2d3  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0040e2d8  8a440117               -mov al, byte ptr [ecx + eax + 0x17]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(23) /* 0x17 */ + cpu.eax * 1);
    // 0040e2dc  eb0e                   -jmp 0x40e2ec
    goto L_0x0040e2ec;
L_0x0040e2de:
    // 0040e2de  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040e2e3  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0040e2e8  8a44011b               -mov al, byte ptr [ecx + eax + 0x1b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(27) /* 0x1b */ + cpu.eax * 1);
L_0x0040e2ec:
    // 0040e2ec  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040e2f1  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 0040e2f4  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040e2f7  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040e2fa  dc0dbc675300           -fmul qword ptr [0x5367bc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5466044) /* 0x5367bc */));
    // 0040e300  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e303  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0040e306  d80dc4675300           -fmul dword ptr [0x5367c4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5466052) /* 0x5367c4 */));
    // 0040e30c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e30f  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040e312  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e313  d90485e0f05600         -fld dword ptr [eax*4 + 0x56f0e0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5697760) /* 0x56f0e0 */ + cpu.eax * 4)));
    // 0040e31a  d84d10                 -fmul dword ptr [ebp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 0040e31d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e320  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0040e323  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e324  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040e326  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040e328  7d04                   -jge 0x40e32e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e32e;
    }
    // 0040e32a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040e32c  eb02                   -jmp 0x40e330
    goto L_0x0040e330;
L_0x0040e32e:
    // 0040e32e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0040e330:
    // 0040e330  83f80d                 +cmp eax, 0xd
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
    // 0040e333  7e05                   -jle 0x40e33a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040e33a;
    }
    // 0040e335  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
L_0x0040e33a:
    // 0040e33a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040e33c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e33d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e33e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e33f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40e350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e352  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e353  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e355  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040e357  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040e35a  ffb0b8070000           -push dword ptr [eax + 0x7b8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1976) /* 0x7b8 */);
    cpu.esp -= 4;
    // 0040e360  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e362  e849ffffff             -call 0x40e2b0
    cpu.esp -= 4;
    sub_40e2b0(app, cpu);
    if (cpu.terminate) return;
    // 0040e367  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e36a  d982b8070000           -fld dword ptr [edx + 0x7b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1976) /* 0x7b8 */)));
    // 0040e370  d8a21c020000           -fsub dword ptr [edx + 0x21c]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(540) /* 0x21c */));
    // 0040e376  898238060000           -mov dword ptr [edx + 0x638], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1592) /* 0x638 */) = cpu.eax;
    // 0040e37c  dc05cc675300           -fadd qword ptr [0x5367cc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466060) /* 0x5367cc */));
    // 0040e382  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e384  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e387  e824ffffff             -call 0x40e2b0
    cpu.esp -= 4;
    sub_40e2b0(app, cpu);
    if (cpu.terminate) return;
    // 0040e38c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040e38f  d982b8070000           -fld dword ptr [edx + 0x7b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1976) /* 0x7b8 */)));
    // 0040e395  d8821c020000           -fadd dword ptr [edx + 0x21c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(540) /* 0x21c */));
    // 0040e39b  89823c060000           -mov dword ptr [edx + 0x63c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1596) /* 0x63c */) = cpu.eax;
    // 0040e3a1  dc05d4675300           -fadd qword ptr [0x5367d4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466068) /* 0x5367d4 */));
    // 0040e3a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040e3a9  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e3ac  e8fffeffff             -call 0x40e2b0
    cpu.esp -= 4;
    sub_40e2b0(app, cpu);
    if (cpu.terminate) return;
    // 0040e3b1  898240060000           -mov dword ptr [edx + 0x640], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1600) /* 0x640 */) = cpu.eax;
    // 0040e3b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e3b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e3b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e3ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_40e3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040e3c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e3c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e3c3  f605fcd46f0008         +test byte ptr [0x6fd4fc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7329020) /* 0x6fd4fc */) & 8 /*0x8*/));
    // 0040e3ca  740f                   -je 0x40e3db
    if (cpu.flags.zf)
    {
        goto L_0x0040e3db;
    }
    // 0040e3cc  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0040e3d3  c7000f000000           -mov dword ptr [eax], 0xf
    app->getMemory<x86::reg32>(cpu.eax) = 15 /*0xf*/;
    // 0040e3d9  eb05                   -jmp 0x40e3e0
    goto L_0x0040e3e0;
L_0x0040e3db:
    // 0040e3db  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0040e3de  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0040e3e0:
    // 0040e3e0  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0040e3e3  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0040e3e6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0040e3e9  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0040e3ec  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040e3ef  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040e3f2  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040e3f5  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0040e3f8  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0040e3fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040e3fc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_40e410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040e410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e412  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040e413  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040e414  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040e415  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040e417  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0040e41a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e41c  8b0dc8d46f00           -mov ecx, dword ptr [0x6fd4c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328968) /* 0x6fd4c8 */);
    // 0040e422  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0040e425  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040e427  7407                   -je 0x40e430
    if (cpu.flags.zf)
    {
        goto L_0x0040e430;
    }
    // 0040e429  c745e80ad7a3bb         -mov dword ptr [ebp - 0x18], 0xbba3d70a
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = 3148076810 /*0xbba3d70a*/;
L_0x0040e430:
    // 0040e430  833dccd46f0000         +cmp dword ptr [0x6fd4cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328972) /* 0x6fd4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e437  740c                   -je 0x40e445
    if (cpu.flags.zf)
    {
        goto L_0x0040e445;
    }
    // 0040e439  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0040e43c  d805dc675300           -fadd dword ptr [0x5367dc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5466076) /* 0x5367dc */));
    // 0040e442  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040e445:
    // 0040e445  833dc4d46f0000         +cmp dword ptr [0x6fd4c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328964) /* 0x6fd4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e44c  740c                   -je 0x40e45a
    if (cpu.flags.zf)
    {
        goto L_0x0040e45a;
    }
    // 0040e44e  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0040e451  d805dc675300           -fadd dword ptr [0x5367dc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5466076) /* 0x5367dc */));
    // 0040e457  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040e45a:
    // 0040e45a  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040e461  740c                   -je 0x40e46f
    if (cpu.flags.zf)
    {
        goto L_0x0040e46f;
    }
    // 0040e463  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0040e466  d805dc675300           -fadd dword ptr [0x5367dc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5466076) /* 0x5367dc */));
    // 0040e46c  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040e46f:
    // 0040e46f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040e471  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040e476  8915e0f05600           -mov dword ptr [0x56f0e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5697760) /* 0x56f0e0 */) = cpu.edx;
    // 0040e47c  eb05                   -jmp 0x40e483
    goto L_0x0040e483;
L_0x0040e47e:
    // 0040e47e  83f850                 +cmp eax, 0x50
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
    // 0040e481  7d1a                   -jge 0x40e49d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040e49d;
    }
L_0x0040e483:
    // 0040e483  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040e486  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040e489  d80de0675300           +fmul dword ptr [0x5367e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5466080) /* 0x5367e0 */));
    // 0040e48f  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 0040e491  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 0040e493  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040e494  d91c85dcf05600         +fstp dword ptr [eax*4 + 0x56f0dc]
    app->getMemory<float>(x86::reg32(5697756) /* 0x56f0dc */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e49b  ebe1                   -jmp 0x40e47e
    goto L_0x0040e47e;
L_0x0040e49d:
    // 0040e49d  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0040e4a2  83f803                 +cmp eax, 3
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
    // 0040e4a5  0f8722070000           -ja 0x40ebcd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040ebcd;
    }
    // 0040e4ab  ff248500e44000         -jmp dword ptr [eax*4 + 0x40e400]
    cpu.ip = app->getMemory<x86::reg32>(4252672 + cpu.eax * 4); goto dynamic_jump;
  case 0x0040e4b2:
    // 0040e4b2  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e4b7  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e4bc  bb28000000             -mov ebx, 0x28
    cpu.ebx = 40 /*0x28*/;
    // 0040e4c1  6885eb513f             -push 0x3f51eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062333317 /*0x3f51eb85*/;
    cpu.esp -= 4;
    // 0040e4c6  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0040e4cb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e4cd  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040e4d2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e4d4  e8e7feffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e4d9  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e4de  688fc2753f             -push 0x3f75c28f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064682127 /*0x3f75c28f*/;
    cpu.esp -= 4;
    // 0040e4e3  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0040e4e8  683d0a573f             -push 0x3f570a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062668861 /*0x3f570a3d*/;
    cpu.esp -= 4;
    // 0040e4ed  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0040e4f2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e4f4  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040e4f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e4fb  e8c0feffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e500  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e505  688fc2753f             -push 0x3f75c28f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064682127 /*0x3f75c28f*/;
    cpu.esp -= 4;
    // 0040e50a  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e50f  683d0a573f             -push 0x3f570a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062668861 /*0x3f570a3d*/;
    cpu.esp -= 4;
    // 0040e514  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0040e519  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e51b  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040e520  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e522  e899feffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e527  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e52c  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e531  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0040e536  6885eb513f             -push 0x3f51eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062333317 /*0x3f51eb85*/;
    cpu.esp -= 4;
    // 0040e53b  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e540  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e542  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040e547  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e549  e872feffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e54e  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e553  688fc2753f             -push 0x3f75c28f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064682127 /*0x3f75c28f*/;
    cpu.esp -= 4;
    // 0040e558  bb28000000             -mov ebx, 0x28
    cpu.ebx = 40 /*0x28*/;
    // 0040e55d  683d0a573f             -push 0x3f570a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062668861 /*0x3f570a3d*/;
    cpu.esp -= 4;
    // 0040e562  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0040e567  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e569  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040e56e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e570  e84bfeffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e575  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e57a  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e57f  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0040e584  6885eb513f             -push 0x3f51eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062333317 /*0x3f51eb85*/;
    cpu.esp -= 4;
    // 0040e589  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0040e58e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e590  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040e595  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e597  e824feffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e59c  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e5a1  688fc2753f             -push 0x3f75c28f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064682127 /*0x3f75c28f*/;
    cpu.esp -= 4;
    // 0040e5a6  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e5ab  683d0a573f             -push 0x3f570a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062668861 /*0x3f570a3d*/;
    cpu.esp -= 4;
    // 0040e5b0  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e5b5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e5b7  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040e5bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e5be  e8fdfdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e5c3  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e5c8  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e5cd  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e5d2  6885eb513f             -push 0x3f51eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062333317 /*0x3f51eb85*/;
    cpu.esp -= 4;
    // 0040e5d7  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e5dc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e5de  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040e5e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e5e5  e8d6fdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e5ea  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e5ef  688fc2753f             -push 0x3f75c28f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064682127 /*0x3f75c28f*/;
    cpu.esp -= 4;
    // 0040e5f4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0040e5f9  683d0a573f             -push 0x3f570a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062668861 /*0x3f570a3d*/;
    cpu.esp -= 4;
    // 0040e5fe  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0040e603  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e605  b880f05600             -mov eax, 0x56f080
    cpu.eax = 5697664 /*0x56f080*/;
    // 0040e60a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040e60c  e9b7050000             -jmp 0x40ebc8
    goto L_0x0040ebc8;
  case 0x0040e611:
    // 0040e611  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e616  68ae47613f             -push 0x3f6147ae
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063339950 /*0x3f6147ae*/;
    cpu.esp -= 4;
    // 0040e61b  bb28000000             -mov ebx, 0x28
    cpu.ebx = 40 /*0x28*/;
    // 0040e620  6814ae473f             -push 0x3f47ae14
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061662228 /*0x3f47ae14*/;
    cpu.esp -= 4;
    // 0040e625  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0040e62a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e62c  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040e631  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e633  e888fdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e638  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e63d  686666663f             -push 0x3f666666
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063675494 /*0x3f666666*/;
    cpu.esp -= 4;
    // 0040e642  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0040e647  6885eb513f             -push 0x3f51eb85
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062333317 /*0x3f51eb85*/;
    cpu.esp -= 4;
    // 0040e64c  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0040e651  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e653  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040e658  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e65a  e861fdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e65f  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e664  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e669  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e66e  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e673  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 0040e678  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e67a  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040e67f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e681  e83afdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e686  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e68b  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e690  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0040e695  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e69a  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e69f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e6a1  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040e6a6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e6a8  e813fdffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e6ad  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e6b2  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e6b7  bb28000000             -mov ebx, 0x28
    cpu.ebx = 40 /*0x28*/;
    // 0040e6bc  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e6c1  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 0040e6c6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e6c8  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040e6cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e6cf  e8ecfcffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e6d4  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e6d9  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e6de  bb78000000             -mov ebx, 0x78
    cpu.ebx = 120 /*0x78*/;
    // 0040e6e3  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e6e8  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0040e6ed  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e6ef  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040e6f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e6f6  e8c5fcffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e6fb  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e700  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e705  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e70a  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e70f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e714  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e716  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040e71b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e71d  e89efcffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e722  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e727  689a99593f             -push 0x3f59999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062836634 /*0x3f59999a*/;
    cpu.esp -= 4;
    // 0040e72c  bb50000000             -mov ebx, 0x50
    cpu.ebx = 80 /*0x50*/;
    // 0040e731  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e736  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0040e73b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e73d  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040e742  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e744  e877fcffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e749  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e74e  68e17a543f             -push 0x3f547ae1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1062501089 /*0x3f547ae1*/;
    cpu.esp -= 4;
    // 0040e753  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0040e758  68cdcc4c3f             -push 0x3f4ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1061997773 /*0x3f4ccccd*/;
    cpu.esp -= 4;
    // 0040e75d  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0040e762  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e764  b880f05600             -mov eax, 0x56f080
    cpu.eax = 5697664 /*0x56f080*/;
    // 0040e769  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040e76b  e958040000             -jmp 0x40ebc8
    goto L_0x0040ebc8;
  case 0x0040e770:
    // 0040e770  8b0d70d46f00           -mov ecx, dword ptr [0x6fd470]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
    // 0040e776  83f901                 +cmp ecx, 1
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
    // 0040e779  0f850f010000           -jne 0x40e88e
    if (!cpu.flags.zf)
    {
        goto L_0x0040e88e;
    }
    // 0040e77f  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e784  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0040e787  dd55c0                 -fst qword ptr [ebp - 0x40]
    app->getMemory<double>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = double(cpu.fpu.st(0));
    // 0040e78a  dc05e4675300           -fadd qword ptr [0x5367e4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466084) /* 0x5367e4 */));
    // 0040e790  d95de0                 -fstp dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e793  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0040e796  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040e79b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e79d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e79f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040e7a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e7a2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e7a4  e817fcffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e7a9  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e7ae  dd45c0                 -fld qword ptr [ebp - 0x40]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
    // 0040e7b1  dc05ec675300           -fadd qword ptr [0x5367ec]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466092) /* 0x5367ec */));
    // 0040e7b7  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e7ba  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0040e7bd  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040e7c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e7c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e7c6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e7c8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e7ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e7cc  e8effbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e7d1  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0040e7d3  dc45c0                 -fadd qword ptr [ebp - 0x40]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-64) /* -0x40 */));
    // 0040e7d6  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e7db  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e7de  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0040e7e1  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040e7e6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e7e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e7ea  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e7ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e7ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e7f0  e8cbfbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e7f5  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e7fa  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0040e7fd  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040e802  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e804  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e806  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e808  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e80a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e80c  e8affbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e811  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e816  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0040e819  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040e81e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e820  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e822  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e824  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e826  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e828  e893fbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e82d  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e832  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0040e835  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040e83a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e83c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e83e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e840  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e842  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e844  e877fbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e849  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e84e  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 0040e851  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040e856  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e858  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e85a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e85c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e85e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e860  e85bfbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e865  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e86a  ff75e0                 -push dword ptr [ebp - 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    cpu.esp -= 4;
    // 0040e86d  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040e872  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e874  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e876  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e878  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e87a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040e87c  e83ffbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e881  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e886  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0040e889  e9fa000000             -jmp 0x40e988
    goto L_0x0040e988;
L_0x0040e88e:
    // 0040e88e  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e893  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040e898  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040e89d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e89f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e8a1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e8a3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e8a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e8a7  e814fbffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e8ac  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e8b1  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e8b6  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040e8bb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e8bd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e8bf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e8c1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e8c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e8c5  e8f6faffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e8ca  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e8cf  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e8d4  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040e8d9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e8db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e8dd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e8df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e8e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e8e3  e8d8faffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e8e8  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e8ed  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040e8f2  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040e8f7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e8f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e8fb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e8fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e8ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e901  e8bafaffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e906  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e90b  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e910  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040e915  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e917  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e919  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e91b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e91d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e91f  e89cfaffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e924  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e929  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040e92e  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040e933  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e935  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e937  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e939  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e93b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e93d  e87efaffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e942  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e947  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e94c  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040e951  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e953  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e955  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e957  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e959  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e95b  e860faffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e960  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e965  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040e96a  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040e96f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e971  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e973  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e975  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e977  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e979  e842faffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e97e  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e983  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
L_0x0040e988:
    // 0040e988  b880f05600             -mov eax, 0x56f080
    cpu.eax = 5697664 /*0x56f080*/;
    // 0040e98d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e98f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e991  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e993  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e995  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040e997  e824faffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e99c  e92c020000             -jmp 0x40ebcd
    goto L_0x0040ebcd;
  case 0x0040e9a1:
    // 0040e9a1  8b1d70d46f00           -mov ebx, dword ptr [0x6fd470]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328880) /* 0x6fd470 */);
    // 0040e9a7  83fb01                 +cmp ebx, 1
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
    // 0040e9aa  0f850f010000           -jne 0x40eabf
    if (!cpu.flags.zf)
    {
        goto L_0x0040eabf;
    }
    // 0040e9b0  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e9b5  d945e8                 -fld dword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0040e9b8  dd55b0                 -fst qword ptr [ebp - 0x50]
    app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */) = double(cpu.fpu.st(0));
    // 0040e9bb  dc05e4675300           -fadd qword ptr [0x5367e4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466084) /* 0x5367e4 */));
    // 0040e9c1  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e9c4  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0040e9c7  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040e9cc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e9ce  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e9d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040e9d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e9d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e9d5  e8e6f9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040e9da  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040e9df  dd45b0                 -fld qword ptr [ebp - 0x50]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */)));
    // 0040e9e2  dc05ec675300           -fadd qword ptr [0x5367ec]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466092) /* 0x5367ec */));
    // 0040e9e8  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040e9eb  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040e9ee  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040e9f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040e9f5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040e9f7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040e9f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040e9fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040e9fd  e8bef9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea02  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea07  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 0040ea09  dc45b0                 -fadd qword ptr [ebp - 0x50]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-80) /* -0x50 */));
    // 0040ea0c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ea0f  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040ea12  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040ea17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ea19  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea1b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ea1d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ea1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ea21  e89af9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea26  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea2b  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0040ea2e  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040ea33  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ea35  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea37  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ea39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ea3b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ea3d  e87ef9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea42  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea47  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040ea4a  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040ea4f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ea51  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea53  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ea55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ea57  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ea59  e862f9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea5e  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea63  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0040ea66  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040ea6b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ea6d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea6f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ea71  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ea73  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ea75  e846f9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea7a  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea7f  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040ea82  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040ea87  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ea89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ea8b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ea8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ea8f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ea91  e82af9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ea96  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ea9b  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 0040ea9e  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040eaa3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eaa5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eaa7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eaa9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eaab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040eaad  e80ef9ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eab2  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eab7  ff75e4                 -push dword ptr [ebp - 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    cpu.esp -= 4;
    // 0040eaba  e9fa000000             -jmp 0x40ebb9
    goto L_0x0040ebb9;
L_0x0040eabf:
    // 0040eabf  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eac4  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040eac9  b880ef5600             -mov eax, 0x56ef80
    cpu.eax = 5697408 /*0x56ef80*/;
    // 0040eace  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ead0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ead2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ead4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ead6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ead8  e8e3f8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eadd  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eae2  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040eae7  b8a0ef5600             -mov eax, 0x56efa0
    cpu.eax = 5697440 /*0x56efa0*/;
    // 0040eaec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eaee  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eaf0  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eaf2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eaf4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eaf6  e8c5f8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eafb  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb00  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040eb05  b8c0ef5600             -mov eax, 0x56efc0
    cpu.eax = 5697472 /*0x56efc0*/;
    // 0040eb0a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eb0c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eb0e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eb10  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eb12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb14  e8a7f8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eb19  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb1e  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040eb23  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040eb28  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eb2a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eb2c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eb2e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eb30  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb32  e889f8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eb37  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb3c  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040eb41  b800f05600             -mov eax, 0x56f000
    cpu.eax = 5697536 /*0x56f000*/;
    // 0040eb46  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eb48  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eb4a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eb4c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eb4e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb50  e86bf8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eb55  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb5a  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040eb5f  b820f05600             -mov eax, 0x56f020
    cpu.eax = 5697568 /*0x56f020*/;
    // 0040eb64  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eb66  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eb68  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eb6a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eb6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb6e  e84df8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eb73  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb78  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
    // 0040eb7d  b840f05600             -mov eax, 0x56f040
    cpu.eax = 5697600 /*0x56f040*/;
    // 0040eb82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eb84  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eb86  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eb88  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eb8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040eb8c  e82ff8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040eb91  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040eb96  681f856b3f             -push 0x3f6b851f
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064011039 /*0x3f6b851f*/;
    cpu.esp -= 4;
    // 0040eb9b  b860f05600             -mov eax, 0x56f060
    cpu.eax = 5697632 /*0x56f060*/;
    // 0040eba0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040eba2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040eba4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040eba6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040eba8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ebaa  e811f8ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
    // 0040ebaf  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ebb4  68d7a3703f             -push 0x3f70a3d7
    app->getMemory<x86::reg32>(cpu.esp-4) = 1064346583 /*0x3f70a3d7*/;
    cpu.esp -= 4;
L_0x0040ebb9:
    // 0040ebb9  b880f05600             -mov eax, 0x56f080
    cpu.eax = 5697664 /*0x56f080*/;
    // 0040ebbe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0040ebc0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ebc2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ebc4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040ebc6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040ebc8:
    // 0040ebc8  e8f3f7ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
L_0x0040ebcd:
    // 0040ebcd  f6052eeb550020         +test byte ptr [0x55eb2e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 32 /*0x20*/));
    // 0040ebd4  7427                   -je 0x40ebfd
    if (cpu.flags.zf)
    {
        goto L_0x0040ebfd;
    }
    // 0040ebd6  680c935641             -push 0x4156930c
    app->getMemory<x86::reg32>(cpu.esp-4) = 1096192780 /*0x4156930c*/;
    cpu.esp -= 4;
    // 0040ebdb  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0040ebe0  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0040ebe5  686666663f             -push 0x3f666666
    app->getMemory<x86::reg32>(cpu.esp-4) = 1063675494 /*0x3f666666*/;
    cpu.esp -= 4;
    // 0040ebea  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040ebef  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040ebf1  b8e0ef5600             -mov eax, 0x56efe0
    cpu.eax = 5697504 /*0x56efe0*/;
    // 0040ebf6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ebf8  e8c3f7ffff             -call 0x40e3c0
    cpu.esp -= 4;
    sub_40e3c0(app, cpu);
    if (cpu.terminate) return;
L_0x0040ebfd:
    // 0040ebfd  e8fef3ffff             -call 0x40e000
    cpu.esp -= 4;
    sub_40e000(app, cpu);
    if (cpu.terminate) return;
    // 0040ec02  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040ec08  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0040ec0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ec0c  893524f25600           -mov dword ptr [0x56f224], esi
    app->getMemory<x86::reg32>(x86::reg32(5698084) /* 0x56f224 */) = cpu.esi;
L_0x0040ec12:
    // 0040ec12  39ca                   +cmp edx, ecx
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
    // 0040ec14  7d20                   -jge 0x40ec36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040ec36;
    }
    // 0040ec16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ec18  e863f4ffff             -call 0x40e080
    cpu.esp -= 4;
    sub_40e080(app, cpu);
    if (cpu.terminate) return;
    // 0040ec1d  d955ec                 +fst dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    // 0040ec20  d81d24f25600           +fcomp dword ptr [0x56f224]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(x86::reg32(5698084) /* 0x56f224 */)));
    cpu.fpu.pop();
    // 0040ec26  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0040ec28  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0040ec29  7608                   -jbe 0x40ec33
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ec33;
    }
    // 0040ec2b  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0040ec2e  a324f25600             -mov dword ptr [0x56f224], eax
    app->getMemory<x86::reg32>(x86::reg32(5698084) /* 0x56f224 */) = cpu.eax;
L_0x0040ec33:
    // 0040ec33  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040ec34  ebdc                   -jmp 0x40ec12
    goto L_0x0040ec12;
L_0x0040ec36:
    // 0040ec36  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ec38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec3d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40ec40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ec40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ec41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ec43  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ec45  8b1558255500           -mov edx, dword ptr [0x552558]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5580120) /* 0x552558 */);
    // 0040ec4b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040ec4d  740f                   -je 0x40ec5e
    if (cpu.flags.zf)
    {
        goto L_0x0040ec5e;
    }
    // 0040ec4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ec51  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040ec53  e8382c0d00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0040ec58  890d58255500           -mov dword ptr [0x552558], ecx
    app->getMemory<x86::reg32>(x86::reg32(5580120) /* 0x552558 */) = cpu.ecx;
L_0x0040ec5e:
    // 0040ec5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40ec70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ec70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ec71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ec72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ec74  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ec7a  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ec7d  7d0e                   -jge 0x40ec8d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040ec8d;
    }
    // 0040ec7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ec81  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040ec84  8b808cef5600           -mov eax, dword ptr [eax + 0x56ef8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697420) /* 0x56ef8c */);
    // 0040ec8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ec8d:
    // 0040ec8d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040ec92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ec94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40eca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040eca0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040eca1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040eca2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040eca4  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ecaa  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ecad  7d0e                   -jge 0x40ecbd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040ecbd;
    }
    // 0040ecaf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ecb1  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040ecb4  8b8088ef5600           -mov eax, dword ptr [eax + 0x56ef88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697416) /* 0x56ef88 */);
    // 0040ecba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecbb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ecbd:
    // 0040ecbd  a148d95d00             -mov eax, dword ptr [0x5dd948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040ecc2  8a4037                 -mov al, byte ptr [eax + 0x37]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(55) /* 0x37 */);
    // 0040ecc5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040ecca  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0040eccd  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 0040eccf  7508                   -jne 0x40ecd9
    if (!cpu.flags.zf)
    {
        goto L_0x0040ecd9;
    }
    // 0040ecd1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040ecd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ecd9:
    // 0040ecd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ecdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ecdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40ece0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ece0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ece1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ece2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ece3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ece5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ece8  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ecee  83fa0b                 +cmp edx, 0xb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ecf1  7d10                   -jge 0x40ed03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040ed03;
    }
    // 0040ecf3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ecf5  c1e005                 +shl eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0040ecf8  8b809cef5600           -mov eax, dword ptr [eax + 0x56ef9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697436) /* 0x56ef9c */);
    // 0040ecfe  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040ed01  eb07                   -jmp 0x40ed0a
    goto L_0x0040ed0a;
L_0x0040ed03:
    // 0040ed03  c745fc0c93d641         -mov dword ptr [ebp - 4], 0x41d6930c
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1104581388 /*0x41d6930c*/;
L_0x0040ed0a:
    // 0040ed0a  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ed0d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ed0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed11  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40ed40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040ed40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ed41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ed42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ed44  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ed47  8b15acd46f00           -mov edx, dword ptr [0x6fd4ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ed4d  83fa0a                 +cmp edx, 0xa
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
    // 0040ed50  0f871b010000           -ja 0x40ee71
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040ee71;
    }
    // 0040ed56  ff249514ed4000         -jmp dword ptr [edx*4 + 0x40ed14]
    cpu.ip = app->getMemory<x86::reg32>(4254996 + cpu.edx * 4); goto dynamic_jump;
  case 0x0040ed5d:
    // 0040ed5d  3d76020000             +cmp eax, 0x276
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(630 /*0x276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ed62  760c                   -jbe 0x40ed70
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ed70;
    }
  [[fallthrough]];
  case 0x0040ed64:
L_0x0040ed64:
    // 0040ed64  c745fcdfcfb241         -mov dword ptr [ebp - 4], 0x41b2cfdf
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1102237663 /*0x41b2cfdf*/;
    // 0040ed6b  e908010000             -jmp 0x40ee78
    goto L_0x0040ee78;
L_0x0040ed70:
    // 0040ed70  3de8010000             +cmp eax, 0x1e8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(488 /*0x1e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ed75  76ed                   -jbe 0x40ed64
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ed64;
    }
    // 0040ed77  c745fc0c935641         -mov dword ptr [ebp - 4], 0x4156930c
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1096192780 /*0x4156930c*/;
    // 0040ed7e  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ed81  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ed83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed85  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ed86:
    // 0040ed86  3de8030000             +cmp eax, 0x3e8
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
    // 0040ed8b  760f                   -jbe 0x40ed9c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ed9c;
    }
L_0x0040ed8d:
    // 0040ed8d  c745fc76b1c441         -mov dword ptr [ebp - 4], 0x41c4b176
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1103409526 /*0x41c4b176*/;
    // 0040ed94  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ed97  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ed99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ed9b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ed9c:
    // 0040ed9c  3d16030000             +cmp eax, 0x316
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(790 /*0x316*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040eda1  760f                   -jbe 0x40edb2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040edb2;
    }
    // 0040eda3  c745fc3956fa41         -mov dword ptr [ebp - 4], 0x41fa5639
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1106925113 /*0x41fa5639*/;
    // 0040edaa  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040edad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040edaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edb0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edb1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040edb2:
    // 0040edb2  3daa000000             +cmp eax, 0xaa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(170 /*0xaa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040edb7  76d4                   -jbe 0x40ed8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ed8d;
    }
    // 0040edb9  c745fca274e841         -mov dword ptr [ebp - 4], 0x41e874a2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1105753250 /*0x41e874a2*/;
    // 0040edc0  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040edc3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040edc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edc7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040edc8:
    // 0040edc8  3de8030000             +cmp eax, 0x3e8
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
    // 0040edcd  0f879e000000           -ja 0x40ee71
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040ee71;
    }
    // 0040edd3  3d90010000             +cmp eax, 0x190
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
    // 0040edd8  0f8693000000           -jbe 0x40ee71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee71;
    }
    // 0040edde  c745fc39567a41         -mov dword ptr [ebp - 4], 0x417a5639
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1098536505 /*0x417a5639*/;
    // 0040ede5  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ede8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040edea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040edec  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040eded:
    // 0040eded  3d6e050000             +cmp eax, 0x56e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1390 /*0x56e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040edf2  760f                   -jbe 0x40ee03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee03;
    }
L_0x0040edf4:
    // 0040edf4  c745fc7ac7b141         -mov dword ptr [ebp - 4], 0x41b1c77a
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1102169978 /*0x41b1c77a*/;
    // 0040edfb  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040edfe  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ee03:
    // 0040ee03  3d28050000             +cmp eax, 0x528
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1320 /*0x528*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ee08  76ea                   -jbe 0x40edf4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040edf4;
    }
    // 0040ee0a  c745fc58395e41         -mov dword ptr [ebp - 4], 0x415e3958
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1096694104 /*0x415e3958*/;
    // 0040ee11  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee14  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee16  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee18  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ee19:
    // 0040ee19  3d53010000             +cmp eax, 0x153
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(339 /*0x153*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ee1e  760f                   -jbe 0x40ee2f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee2f;
    }
  [[fallthrough]];
  case 0x0040ee20:
L_0x0040ee20:
    // 0040ee20  c745fcdfcfb241         -mov dword ptr [ebp - 4], 0x41b2cfdf
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1102237663 /*0x41b2cfdf*/;
    // 0040ee27  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee2a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ee2f:
    // 0040ee2f  3d27010000             +cmp eax, 0x127
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(295 /*0x127*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ee34  76ea                   -jbe 0x40ee20
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee20;
    }
    // 0040ee36  c745fcb30c0f41         -mov dword ptr [ebp - 4], 0x410f0cb3
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1091505331 /*0x410f0cb3*/;
    // 0040ee3d  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee40  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee44  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ee45:
    // 0040ee45  3d5e060000             +cmp eax, 0x65e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1630 /*0x65e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ee4a  760f                   -jbe 0x40ee5b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee5b;
    }
L_0x0040ee4c:
    // 0040ee4c  c745fc7ac7b141         -mov dword ptr [ebp - 4], 0x41b1c77a
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1102169978 /*0x41b1c77a*/;
    // 0040ee53  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee56  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040ee5b:
    // 0040ee5b  3d0d060000             +cmp eax, 0x60d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1549 /*0x60d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ee60  76ea                   -jbe 0x40ee4c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040ee4c;
    }
    // 0040ee62  c745fc58395e41         -mov dword ptr [ebp - 4], 0x415e3958
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1096694104 /*0x415e3958*/;
    // 0040ee69  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee6c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee70  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ee71:
L_0x0040ee71:
    // 0040ee71  c745fc49eea041         -mov dword ptr [ebp - 4], 0x41a0ee49
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1101065801 /*0x41a0ee49*/;
L_0x0040ee78:
    // 0040ee78  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040ee7b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ee7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ee7f  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_40ee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ee80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ee81  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ee82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ee83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ee84  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ee86  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ee89  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0040ee8f  83fa01                 +cmp edx, 1
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
    // 0040ee92  7405                   -je 0x40ee99
    if (cpu.flags.zf)
    {
        goto L_0x0040ee99;
    }
    // 0040ee94  83fa02                 +cmp edx, 2
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
    // 0040ee97  750a                   -jne 0x40eea3
    if (!cpu.flags.zf)
    {
        goto L_0x0040eea3;
    }
L_0x0040ee99:
    // 0040ee99  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ee9e  c1e005                 +shl eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0040eea1  eb1a                   -jmp 0x40eebd
    goto L_0x0040eebd;
L_0x0040eea3:
    // 0040eea3  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040eea8  8b1df0d46f00           -mov ebx, dword ptr [0x6fd4f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7329008) /* 0x6fd4f0 */);
    // 0040eeae  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040eeb1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040eeb3  7508                   -jne 0x40eebd
    if (!cpu.flags.zf)
    {
        goto L_0x0040eebd;
    }
    // 0040eeb5  8b8094ef5600           -mov eax, dword ptr [eax + 0x56ef94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697428) /* 0x56ef94 */);
    // 0040eebb  eb06                   -jmp 0x40eec3
    goto L_0x0040eec3;
L_0x0040eebd:
    // 0040eebd  8b8098ef5600           -mov eax, dword ptr [eax + 0x56ef98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697432) /* 0x56ef98 */);
L_0x0040eec3:
    // 0040eec3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040eec6  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040eec9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040eecb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eecc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eecd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eece  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eecf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_40eed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040eed0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040eed1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040eed2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040eed4  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040eed9  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040eedc  8b15ccd46f00           -mov edx, dword ptr [0x6fd4cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328972) /* 0x6fd4cc */);
    // 0040eee2  8b8084ef5600           -mov eax, dword ptr [eax + 0x56ef84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697412) /* 0x56ef84 */);
    // 0040eee8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040eeea  7405                   -je 0x40eef1
    if (cpu.flags.zf)
    {
        goto L_0x0040eef1;
    }
    // 0040eeec  05c8000000             -add eax, 0xc8
    (cpu.eax) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x0040eef1:
    // 0040eef1  833dc8d46f0000         +cmp dword ptr [0x6fd4c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328968) /* 0x6fd4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040eef8  7405                   -je 0x40eeff
    if (cpu.flags.zf)
    {
        goto L_0x0040eeff;
    }
    // 0040eefa  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
L_0x0040eeff:
    // 0040eeff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40ef10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ef10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ef11  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ef13  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0040ef18  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0040ef1b  8b8080ef5600           -mov eax, dword ptr [eax + 0x56ef80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5697408) /* 0x56ef80 */);
    // 0040ef21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ef30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ef31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ef32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ef33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ef35  8b9054010000           -mov edx, dword ptr [eax + 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(340) /* 0x154 */);
    // 0040ef3b  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040ef3e  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040ef44  40                     -inc eax
    (cpu.eax)++;
    // 0040ef45  39c8                   +cmp eax, ecx
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
    // 0040ef47  7c02                   -jl 0x40ef4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040ef4b;
    }
    // 0040ef49  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040ef4b:
    // 0040ef4b  e8900f0900             -call 0x49fee0
    cpu.esp -= 4;
    sub_49fee0(app, cpu);
    if (cpu.terminate) return;
    // 0040ef50  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040ef52  3d00020000             +cmp eax, 0x200
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ef57  7e05                   -jle 0x40ef5e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040ef5e;
    }
    // 0040ef59  2d00040000             -sub eax, 0x400
    (cpu.eax) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0040ef5e:
    // 0040ef5e  3d00feffff             +cmp eax, 0xfffffe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966784 /*0xfffffe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040ef63  7d05                   -jge 0x40ef6a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040ef6a;
    }
    // 0040ef65  0500040000             -add eax, 0x400
    (cpu.eax) += x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0040ef6a:
    // 0040ef6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ef6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40ef70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ef70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ef71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ef72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ef73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ef75  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040ef78  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040ef7a  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0040ef81  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040ef83  8b1548d95d00           -mov edx, dword ptr [0x5dd948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040ef89  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040ef8c  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0040ef8f  8b4311                 -mov eax, dword ptr [ebx + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(17) /* 0x11 */);
    // 0040ef92  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040ef95  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040ef98  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040ef9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040ef9d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040efa0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040efa2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040efa5  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040efa8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040efaa  dd05f4675300           -fld qword ptr [0x5367f4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5466100) /* 0x5367f4 */)));
    // 0040efb0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040efb2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040efb4  8b4211                 -mov eax, dword ptr [edx + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 0040efb7  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040efba  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040efbd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040efc0  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 0040efc3  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040efc6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040efc9  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040efcb  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040efce  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040efd0  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040efd3  8b4213                 -mov eax, dword ptr [edx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0040efd6  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040efd9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0040efdc  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040efde  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0040efe1  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040efe4  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040efe7  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040efe9  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040efeb  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040efed  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040efef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eff0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eff1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040eff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40f000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f002  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f003  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f005  8b3540d95d00           -mov esi, dword ptr [0x5dd940]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 0040f00b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f00d  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0040f010  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040f012  7c08                   -jl 0x40f01c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f01c;
    }
    // 0040f014  39f0                   +cmp eax, esi
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
    // 0040f016  7c0a                   -jl 0x40f022
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f022;
    }
    // 0040f018  29f0                   +sub eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0040f01a  eb06                   -jmp 0x40f022
    goto L_0x0040f022;
L_0x0040f01c:
    // 0040f01c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040f01e  7d02                   -jge 0x40f022
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f022;
    }
    // 0040f020  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0040f022:
    // 0040f022  39d0                   +cmp eax, edx
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
    // 0040f024  730f                   -jae 0x40f035
    if (!cpu.flags.cf)
    {
        goto L_0x0040f035;
    }
    // 0040f026  39d1                   +cmp ecx, edx
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
    // 0040f028  7304                   -jae 0x40f02e
    if (!cpu.flags.cf)
    {
        goto L_0x0040f02e;
    }
    // 0040f02a  39c1                   +cmp ecx, eax
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
    // 0040f02c  770f                   -ja 0x40f03d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040f03d;
    }
L_0x0040f02e:
    // 0040f02e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040f033  eb0a                   -jmp 0x40f03f
    goto L_0x0040f03f;
L_0x0040f035:
    // 0040f035  39d1                   +cmp ecx, edx
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
    // 0040f037  7204                   -jb 0x40f03d
    if (cpu.flags.cf)
    {
        goto L_0x0040f03d;
    }
    // 0040f039  39c1                   +cmp ecx, eax
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
    // 0040f03b  76f1                   -jbe 0x40f02e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0040f02e;
    }
L_0x0040f03d:
    // 0040f03d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040f03f:
    // 0040f03f  893540d95d00           -mov dword ptr [0x5dd940], esi
    app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */) = cpu.esi;
    // 0040f045  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f047  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f048  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40f050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f050  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f051  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f052  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f053  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f054  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f056  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040f058  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040f05a  8b0d94fd5e00           -mov ecx, dword ptr [0x5efd94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */);
    // 0040f060  ba90010000             -mov edx, 0x190
    cpu.edx = 400 /*0x190*/;
    // 0040f065  83f905                 +cmp ecx, 5
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
    // 0040f068  7d05                   -jge 0x40f06f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f06f;
    }
    // 0040f06a  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
L_0x0040f06f:
    // 0040f06f  833d94fd5e0002         +cmp dword ptr [0x5efd94], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f076  7d05                   -jge 0x40f07d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f07d;
    }
    // 0040f078  ba32000000             -mov edx, 0x32
    cpu.edx = 50 /*0x32*/;
L_0x0040f07d:
    // 0040f07d  833dc0d46f0000         +cmp dword ptr [0x6fd4c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f084  7403                   -je 0x40f089
    if (cpu.flags.zf)
    {
        goto L_0x0040f089;
    }
    // 0040f086  83ea1a                 -sub edx, 0x1a
    (cpu.edx) -= x86::reg32(x86::sreg32(26 /*0x1a*/));
L_0x0040f089:
    // 0040f089  8b83fc010000           -mov eax, dword ptr [ebx + 0x1fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(508) /* 0x1fc */);
    // 0040f08f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040f091  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f093  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040f096  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f098  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0040f09b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0040f09d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f09f  39d0                   +cmp eax, edx
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
    // 0040f0a1  7e07                   -jle 0x40f0aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0040f0aa;
    }
    // 0040f0a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f0a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040f0aa:
    // 0040f0aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040f0af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_40f0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f0c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f0c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f0c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f0c4  8b1520f25600           -mov edx, dword ptr [0x56f220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5698080) /* 0x56f220 */);
    // 0040f0ca  83fa0a                 +cmp edx, 0xa
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
    // 0040f0cd  7d0a                   -jge 0x40f0d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f0d9;
    }
    // 0040f0cf  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040f0d0  8b04955c255500         -mov eax, dword ptr [edx*4 + 0x55255c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5580124) /* 0x55255c */ + cpu.edx * 4);
    // 0040f0d7  eb0a                   -jmp 0x40f0e3
    goto L_0x0040f0e3;
L_0x0040f0d9:
    // 0040f0d9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040f0de  a160255500             -mov eax, dword ptr [0x552560]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5580128) /* 0x552560 */);
L_0x0040f0e3:
    // 0040f0e3  3b0540d95d00           +cmp eax, dword ptr [0x5dd940]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f0e9  7c05                   -jl 0x40f0f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f0f0;
    }
    // 0040f0eb  a160255500             -mov eax, dword ptr [0x552560]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5580128) /* 0x552560 */);
L_0x0040f0f0:
    // 0040f0f0  891520f25600           -mov dword ptr [0x56f220], edx
    app->getMemory<x86::reg32>(x86::reg32(5698080) /* 0x56f220 */) = cpu.edx;
    // 0040f0f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f0f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40f100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f100  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f101  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f103  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040f108  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f109  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_40f110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f114  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f115  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f116  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f118  8b3d48d95d00           -mov edi, dword ptr [0x5dd948]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */);
    // 0040f11e  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040f124  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0040f127  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040f129  0f8cdf000000           -jl 0x40f20e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f20e;
    }
    // 0040f12f  83fa0e                 +cmp edx, 0xe
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
    // 0040f132  0f8dd6000000           -jge 0x40f20e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f20e;
    }
    // 0040f138  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0040f13f  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f141  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0040f144  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0040f146  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0040f148  31fb                   -xor ebx, edi
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040f14a  8a5a13                 -mov bl, byte ptr [edx + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0040f14d  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0040f150  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0040f155  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040f158  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040f15a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0040f15c  8bb038060000           -mov esi, dword ptr [eax + 0x638]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040f162  39f3                   +cmp ebx, esi
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
    // 0040f164  7f17                   -jg 0x40f17d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040f17d;
    }
    // 0040f166  8a5213                 -mov dl, byte ptr [edx + 0x13]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0040f169  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040f16c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040f172  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040f175  39f2                   +cmp edx, esi
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
    // 0040f177  0f8d98000000           -jge 0x40f215
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f215;
    }
L_0x0040f17d:
    // 0040f17d  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0040f184  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f186  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0040f189  8d3417                 -lea esi, [edi + edx]
    cpu.esi = x86::reg32(cpu.edi + cpu.edx * 1);
    // 0040f18c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f18e  8a5613                 -mov dl, byte ptr [esi + 0x13]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040f191  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 0040f194  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040f199  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040f19c  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f19e  8b9038060000           -mov edx, dword ptr [eax + 0x638]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040f1a4  4a                     -dec edx
    (cpu.edx)--;
    // 0040f1a5  39da                   +cmp edx, ebx
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
    // 0040f1a7  7c1c                   -jl 0x40f1c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f1c5;
    }
    // 0040f1a9  8a5e13                 -mov bl, byte ptr [esi + 0x13]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(19) /* 0x13 */);
    // 0040f1ac  80e30f                 -and bl, 0xf
    cpu.bl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040f1af  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040f1b5  83c307                 -add ebx, 7
    (cpu.ebx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040f1b8  39da                   +cmp edx, ebx
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
    // 0040f1ba  7f09                   -jg 0x40f1c5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040f1c5;
    }
    // 0040f1bc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040f1be  7c05                   -jl 0x40f1c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f1c5;
    }
    // 0040f1c0  83fa0e                 +cmp edx, 0xe
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
    // 0040f1c3  7c50                   -jl 0x40f215
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f215;
    }
L_0x0040f1c5:
    // 0040f1c5  8d14cd00000000         -lea edx, [ecx*8]
    cpu.edx = x86::reg32(cpu.ecx * 8);
    // 0040f1cc  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f1ce  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0040f1d1  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0040f1d3  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0040f1d5  31f9                   -xor ecx, edi
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040f1d7  8a4a13                 -mov cl, byte ptr [edx + 0x13]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0040f1da  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 0040f1df  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0040f1e2  8b8038060000           -mov eax, dword ptr [eax + 0x638]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1592) /* 0x638 */);
    // 0040f1e8  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0040f1eb  40                     -inc eax
    (cpu.eax)++;
    // 0040f1ec  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f1ee  39d8                   +cmp eax, ebx
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
    // 0040f1f0  7c1c                   -jl 0x40f20e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f20e;
    }
    // 0040f1f2  8a5213                 -mov dl, byte ptr [edx + 0x13]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 0040f1f5  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0040f1f8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0040f1fe  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0040f201  39d0                   +cmp eax, edx
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
    // 0040f203  7f09                   -jg 0x40f20e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0040f20e;
    }
    // 0040f205  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040f207  7c05                   -jl 0x40f20e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f20e;
    }
    // 0040f209  83f80e                 +cmp eax, 0xe
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
    // 0040f20c  7c07                   -jl 0x40f215
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f215;
    }
L_0x0040f20e:
    // 0040f20e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0040f213  eb02                   -jmp 0x40f217
    goto L_0x0040f217;
L_0x0040f215:
    // 0040f215  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0040f217:
    // 0040f217  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f219  893d48d95d00           -mov dword ptr [0x5dd948], edi
    app->getMemory<x86::reg32>(x86::reg32(6150472) /* 0x5dd948 */) = cpu.edi;
    // 0040f21f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f220  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f221  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f222  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f223  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f224  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f225  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_40f230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f231  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f232  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f233  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f234  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f235  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f237  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f239  eb08                   -jmp 0x40f243
    goto L_0x0040f243;
L_0x0040f23b:
    // 0040f23b  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f241  7d31                   -jge 0x40f274
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f274;
    }
L_0x0040f243:
    // 0040f243  e888410900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 0040f248  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040f24a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040f251  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f253  31d1                   -xor ecx, edx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f255  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0040f25a  890cc534f25600         -mov dword ptr [eax*8 + 0x56f234], ecx
    app->getMemory<x86::reg32>(x86::reg32(5698100) /* 0x56f234 */ + cpu.eax * 8) = cpu.ecx;
    // 0040f261  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0040f263  891cc538f25600         -mov dword ptr [eax*8 + 0x56f238], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698104) /* 0x56f238 */ + cpu.eax * 8) = cpu.ebx;
    // 0040f26a  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040f26b  8934c53cf25600         -mov dword ptr [eax*8 + 0x56f23c], esi
    app->getMemory<x86::reg32>(x86::reg32(5698108) /* 0x56f23c */ + cpu.eax * 8) = cpu.esi;
    // 0040f272  ebc7                   -jmp 0x40f23b
    goto L_0x0040f23b;
L_0x0040f274:
    // 0040f274  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f275  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f276  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f277  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f278  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f279  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_40f280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f284  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f285  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f287  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0040f28d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040f28f  e89cffffff             -call 0x40f230
    cpu.esp -= 4;
    sub_40f230(app, cpu);
    if (cpu.terminate) return;
    // 0040f294  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f296  41                     -inc ecx
    (cpu.ecx)++;
    // 0040f297  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f299  e832410900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 0040f29e  89148d300a5700         -mov dword ptr [ecx*4 + 0x570a30], edx
    app->getMemory<x86::reg32>(x86::reg32(5704240) /* 0x570a30 */ + cpu.ecx * 4) = cpu.edx;
L_0x0040f2a5:
    // 0040f2a5  83f907                 +cmp ecx, 7
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
    // 0040f2a8  7d11                   -jge 0x40f2bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f2bb;
    }
    // 0040f2aa  41                     -inc ecx
    (cpu.ecx)++;
    // 0040f2ab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f2ad  e81e410900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 0040f2b2  89148d300a5700         -mov dword ptr [ecx*4 + 0x570a30], edx
    app->getMemory<x86::reg32>(x86::reg32(5704240) /* 0x570a30 */ + cpu.ecx * 4) = cpu.edx;
    // 0040f2b9  ebea                   -jmp 0x40f2a5
    goto L_0x0040f2a5;
L_0x0040f2bb:
    // 0040f2bb  8b358ce85500           -mov esi, dword ptr [0x55e88c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5630092) /* 0x55e88c */);
    // 0040f2c1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f2c3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040f2c5  7404                   -je 0x40f2cb
    if (cpu.flags.zf)
    {
        goto L_0x0040f2cb;
    }
    // 0040f2c7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040f2c9  eb4f                   -jmp 0x40f31a
    goto L_0x0040f31a;
L_0x0040f2cb:
    // 0040f2cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f2cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f2cd  68fc675300             -push 0x5367fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466108 /*0x5367fc*/;
    cpu.esp -= 4;
L_0x0040f2d2:
    // 0040f2d2  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0040f2d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040f2d9  e8b2030d00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0040f2de  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0040f2e1  83f907                 +cmp ecx, 7
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
    // 0040f2e4  7d32                   -jge 0x40f318
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f318;
    }
    // 0040f2e6  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0040f2ec  e86f1b0d00             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0040f2f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040f2f3  7423                   -je 0x40f318
    if (cpu.flags.zf)
    {
        goto L_0x0040f318;
    }
    // 0040f2f5  e8d6400900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 0040f2fa  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0040f300  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f302  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040f303  e8b81b0d00             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 0040f308  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f309  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f30a  6808685300             -push 0x536808
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466120 /*0x536808*/;
    cpu.esp -= 4;
    // 0040f30f  89048d300a5700         -mov dword ptr [ecx*4 + 0x570a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5704240) /* 0x570a30 */ + cpu.ecx * 4) = cpu.eax;
    // 0040f316  ebba                   -jmp 0x40f2d2
    goto L_0x0040f2d2;
L_0x0040f318:
    // 0040f318  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0040f31a:
    // 0040f31a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f31c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f31d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f31e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f31f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f320  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f321  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_40f330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f332  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f333  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f334  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f335  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f337  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f339  eb05                   -jmp 0x40f340
    goto L_0x0040f340;
L_0x0040f33b:
    // 0040f33b  83fa07                 +cmp edx, 7
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
    // 0040f33e  7d23                   -jge 0x40f363
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f363;
    }
L_0x0040f340:
    // 0040f340  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0040f347  8b99340a5700           -mov ebx, dword ptr [ecx + 0x570a34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5704244) /* 0x570a34 */);
    // 0040f34d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0040f34f  740f                   -je 0x40f360
    if (cpu.flags.zf)
    {
        goto L_0x0040f360;
    }
    // 0040f351  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040f353  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0040f355  e836250d00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0040f35a  89b1340a5700           -mov dword ptr [ecx + 0x570a34], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5704244) /* 0x570a34 */) = cpu.esi;
L_0x0040f360:
    // 0040f360  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040f361  ebd8                   -jmp 0x40f33b
    goto L_0x0040f33b;
L_0x0040f363:
    // 0040f363  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f365  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f366  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f367  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f368  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40f370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f370  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f371  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f372  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f374  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f376  eb09                   -jmp 0x40f381
    goto L_0x0040f381;
L_0x0040f378:
    // 0040f378  42                     -inc edx
    (cpu.edx)++;
    // 0040f379  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f37f  7d13                   -jge 0x40f394
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040f394;
    }
L_0x0040f381:
    // 0040f381  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040f388  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f38a  833cc534f2560000       +cmp dword ptr [eax*8 + 0x56f234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698100) /* 0x56f234 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f392  75e4                   -jne 0x40f378
    if (!cpu.flags.zf)
    {
        goto L_0x0040f378;
    }
L_0x0040f394:
    // 0040f394  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f39a  7508                   -jne 0x40f3a4
    if (!cpu.flags.zf)
    {
        goto L_0x0040f3a4;
    }
    // 0040f39c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040f3a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f3a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040f3a4:
    // 0040f3a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f3a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f3a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f3a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40f3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f3b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f3b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f3b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f3b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f3b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f3b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f3b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f3b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f3ba  e8b1ffffff             -call 0x40f370
    cpu.esp -= 4;
    sub_40f370(app, cpu);
    if (cpu.terminate) return;
    // 0040f3bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f3c1  83f8ff                 +cmp eax, -1
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
    // 0040f3c4  7461                   -je 0x40f427
    if (cpu.flags.zf)
    {
        goto L_0x0040f427;
    }
    // 0040f3c6  81f900010000           +cmp ecx, 0x100
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
    // 0040f3cc  7c07                   -jl 0x40f3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f3d5;
    }
    // 0040f3ce  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040f3d3  eb52                   -jmp 0x40f427
    goto L_0x0040f427;
L_0x0040f3d5:
    // 0040f3d5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f3d8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f3da  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0040f3e1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040f3e4  8b8b340a5700           -mov ecx, dword ptr [ebx + 0x570a34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5704244) /* 0x570a34 */);
    // 0040f3ea  898834f25600           -mov dword ptr [eax + 0x56f234], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698100) /* 0x56f234 */) = cpu.ecx;
    // 0040f3f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040f3f2  7507                   -jne 0x40f3fb
    if (!cpu.flags.zf)
    {
        goto L_0x0040f3fb;
    }
    // 0040f3f4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040f3f9  eb2c                   -jmp 0x40f427
    goto L_0x0040f427;
L_0x0040f3fb:
    // 0040f3fb  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040f401  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0040f406  898838f25600           -mov dword ptr [eax + 0x56f238], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698104) /* 0x56f238 */) = cpu.ecx;
    // 0040f40c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0040f411  899840f25600           -mov dword ptr [eax + 0x56f240], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698112) /* 0x56f240 */) = cpu.ebx;
    // 0040f417  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0040f419  89b044f25600           -mov dword ptr [eax + 0x56f244], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698116) /* 0x56f244 */) = cpu.esi;
    // 0040f41f  89b848f25600           -mov dword ptr [eax + 0x56f248], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698120) /* 0x56f248 */) = cpu.edi;
    // 0040f425  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0040f427:
    // 0040f427  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f428  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f42a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f42b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f42c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f42d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40f430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f430  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f431  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f432  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f434  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040f436  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f438  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f43b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f43d  8934c540f25600         -mov dword ptr [eax*8 + 0x56f240], esi
    app->getMemory<x86::reg32>(x86::reg32(5698112) /* 0x56f240 */ + cpu.eax * 8) = cpu.esi;
    // 0040f444  891cc544f25600         -mov dword ptr [eax*8 + 0x56f244], ebx
    app->getMemory<x86::reg32>(x86::reg32(5698116) /* 0x56f244 */ + cpu.eax * 8) = cpu.ebx;
    // 0040f44b  890cc548f25600         -mov dword ptr [eax*8 + 0x56f248], ecx
    app->getMemory<x86::reg32>(x86::reg32(5698120) /* 0x56f248 */ + cpu.eax * 8) = cpu.ecx;
    // 0040f452  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f453  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f454  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40f460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f460  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f461  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f462  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f463  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f464  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f466  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f468  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f46b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040f46d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0040f470  83b834f2560000         +cmp dword ptr [eax + 0x56f234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698100) /* 0x56f234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040f477  750a                   -jne 0x40f483
    if (!cpu.flags.zf)
    {
        goto L_0x0040f483;
    }
    // 0040f479  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040f47e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f47f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f480  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f481  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f482  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040f483:
    // 0040f483  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0040f488  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f48a  899838f25600           -mov dword ptr [eax + 0x56f238], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698104) /* 0x56f238 */) = cpu.ebx;
    // 0040f490  89883cf25600           -mov dword ptr [eax + 0x56f23c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698108) /* 0x56f23c */) = cpu.ecx;
    // 0040f496  898834f25600           -mov dword ptr [eax + 0x56f234], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5698100) /* 0x56f234 */) = cpu.ecx;
    // 0040f49c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040f4a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f4a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f4a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f4a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f4a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_40f4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f4b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f4b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f4b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f4b5  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0040f4b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040f4ba  8955e4                 -mov dword ptr [ebp - 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edx;
    // 0040f4bd  894de0                 -mov dword ptr [ebp - 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ecx;
    // 0040f4c0  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040f4c3  668b5606               -mov dx, word ptr [esi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0040f4c7  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0040f4ca  6683fa01               +cmp dx, 1
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
    // 0040f4ce  720e                   -jb 0x40f4de
    if (cpu.flags.cf)
    {
        goto L_0x0040f4de;
    }
    // 0040f4d0  6681fa9001             +cmp dx, 0x190
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(400 /*0x190*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040f4d5  7707                   -ja 0x40f4de
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040f4de;
    }
    // 0040f4d7  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0040f4d9  6689d7                 -mov di, dx
    cpu.di = cpu.dx;
    // 0040f4dc  eb05                   -jmp 0x40f4e3
    goto L_0x0040f4e3;
L_0x0040f4de:
    // 0040f4de  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
L_0x0040f4e3:
    // 0040f4e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040f4e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040f4e7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f4ea  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f4ec  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040f4ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f4f1  83fa02                 +cmp edx, 2
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
    // 0040f4f4  7512                   -jne 0x40f508
    if (!cpu.flags.zf)
    {
        goto L_0x0040f508;
    }
    // 0040f4f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f4f8  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040f4fc  48                     -dec eax
    (cpu.eax)--;
    // 0040f4fd  39c1                   +cmp ecx, eax
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
    // 0040f4ff  7c07                   -jl 0x40f508
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f508;
    }
    // 0040f501  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040f503  e9b5010000             -jmp 0x40f6bd
    goto L_0x0040f6bd;
L_0x0040f508:
    // 0040f508  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f50a  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0040f50e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040f510  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0040f513  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f516  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040f518  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f51a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040f51c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0040f51f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0040f522  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040f524  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040f526  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f529  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f52b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040f52d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f530  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f532  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040f535  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f538  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040f53a  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 0040f53d  8d7dd8                 -lea edi, [ebp - 0x28]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0040f540  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0040f543  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f544  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f545  8b45d6                 -mov eax, dword ptr [ebp - 0x2a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 0040f548  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f54b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f54e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f551  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0040f554  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f557  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f55a  dd0514685300           -fld qword ptr [0x536814]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5466132) /* 0x536814 */)));
    // 0040f560  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f562  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040f564  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f567  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f56a  8b45da                 -mov eax, dword ptr [ebp - 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-38) /* -0x26 */);
    // 0040f56d  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f570  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f573  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040f575  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f578  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f57b  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0040f57e  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f581  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f584  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040f586  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f589  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f58c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f58f  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0040f591  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040f594  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 0040f597  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0040f59a  8d7dd8                 -lea edi, [ebp - 0x28]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0040f59d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040f5a4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0040f5a6  d95da4                 -fstp dword ptr [ebp - 0x5c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f5a9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040f5ab  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f5ad  d95da8                 -fstp dword ptr [ebp - 0x58]
    app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f5b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f5b3  d95dac                 -fstp dword ptr [ebp - 0x54]
    app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f5b6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0040f5b8  d95db0                 -fstp dword ptr [ebp - 0x50]
    app->getMemory<float>(cpu.ebp + x86::reg32(-80) /* -0x50 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f5bb  8d730c                 -lea esi, [ebx + 0xc]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0040f5be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f5bf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f5c0  8b45d6                 -mov eax, dword ptr [ebp - 0x2a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 0040f5c3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f5c6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f5c9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f5cc  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f5cf  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040f5d1  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 0040f5d4  db45f4                 -fild dword ptr [ebp - 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))));
    // 0040f5d7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f5da  db45f8                 -fild dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 0040f5dd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f5e0  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040f5e2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f5e5  8b45da                 -mov eax, dword ptr [ebp - 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-38) /* -0x26 */);
    // 0040f5e8  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f5eb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f5ee  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040f5f0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f5f3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f5f6  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0040f5f9  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f5fc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0040f5ff  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 0040f601  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f604  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f607  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f60a  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 0040f60c  8d7dc0                 -lea edi, [ebp - 0x40]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0040f60f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0040f611  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 0040f613  d95d94                 -fstp dword ptr [ebp - 0x6c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-108) /* -0x6c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f616  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f618  d95d98                 -fstp dword ptr [ebp - 0x68]
    app->getMemory<float>(cpu.ebp + x86::reg32(-104) /* -0x68 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f61b  d95d9c                 -fstp dword ptr [ebp - 0x64]
    app->getMemory<float>(cpu.ebp + x86::reg32(-100) /* -0x64 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f61e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f620  d95da0                 -fstp dword ptr [ebp - 0x60]
    app->getMemory<float>(cpu.ebp + x86::reg32(-96) /* -0x60 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f623  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f624  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f625  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f626  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0040f629  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f62c  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f62f  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0040f632  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040f634  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f637  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0040f63a  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f63d  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f640  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 0040f642  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f645  decc                   -fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040f647  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0040f649  d95de8                 -fstp dword ptr [ebp - 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f64c  d95db4                 -fstp dword ptr [ebp - 0x4c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f64f  d95db8                 -fstp dword ptr [ebp - 0x48]
    app->getMemory<float>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f652  d95dbc                 -fstp dword ptr [ebp - 0x44]
    app->getMemory<float>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f655  8d7dc0                 -lea edi, [ebp - 0x40]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0040f658  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040f65a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f65b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f65c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f65d  8b45c0                 -mov eax, dword ptr [ebp - 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 0040f660  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f663  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f666  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0040f669  dd0514685300           -fld qword ptr [0x536814]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5466132) /* 0x536814 */)));
    // 0040f66f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f671  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 0040f673  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f676  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0040f679  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f67c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f67f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 0040f681  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0040f684  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0040f686  8b4de0                 -mov ecx, dword ptr [ebp - 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0040f689  8d5594                 -lea edx, [ebp - 0x6c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-108) /* -0x6c */);
    // 0040f68c  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 0040f68f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f690  8d4dcc                 -lea ecx, [ebp - 0x34]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 0040f693  8d4584                 -lea eax, [ebp - 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 0040f696  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0040f698  d95dcc                 -fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f69b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040f69c  d95dd0                 -fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f69f  ff75e8                 -push dword ptr [ebp - 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    // 0040f6a2  8d45a4                 -lea eax, [ebp - 0x5c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-92) /* -0x5c */);
    // 0040f6a5  d95dd4                 -fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f6a8  e8437a0a00             -call 0x4b70f0
    cpu.esp -= 4;
    sub_4b70f0(app, cpu);
    if (cpu.terminate) return;
    // 0040f6ad  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040f6b0  8d4584                 -lea eax, [ebp - 0x7c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-124) /* -0x7c */);
    // 0040f6b3  e8d87e0a00             -call 0x4b7590
    cpu.esp -= 4;
    sub_4b7590(app, cpu);
    if (cpu.terminate) return;
    // 0040f6b8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0040f6bd:
    // 0040f6bd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f6bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f6c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f6c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f6c2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_40f6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f6d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f6d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f6d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f6d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f6d5  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0040f6d8  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f6db  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0040f6dd  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0040f6e0  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 0040f6e3  668b5006               -mov dx, word ptr [eax + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0040f6e7  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040f6ea  6683fa01               +cmp dx, 1
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
    // 0040f6ee  7215                   -jb 0x40f705
    if (cpu.flags.cf)
    {
        goto L_0x0040f705;
    }
    // 0040f6f0  6681fa9001             +cmp dx, 0x190
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(400 /*0x190*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040f6f5  770e                   -ja 0x40f705
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040f705;
    }
    // 0040f6f7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f6fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040f6fc  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0040f700  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0040f703  eb07                   -jmp 0x40f70c
    goto L_0x0040f70c;
L_0x0040f705:
    // 0040f705  c745f806000000         -mov dword ptr [ebp - 8], 6
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 6 /*0x6*/;
L_0x0040f70c:
    // 0040f70c  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040f70f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f711  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f714  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f717  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f719  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f71b  83e602                 +and esi, 2
    cpu.clear_co();
    cpu.set_szp((cpu.esi &= x86::reg32(x86::sreg32(2 /*0x2*/))));
    // 0040f71e  7415                   -je 0x40f735
    if (cpu.flags.zf)
    {
        goto L_0x0040f735;
    }
    // 0040f720  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f723  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f725  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040f729  48                     -dec eax
    (cpu.eax)--;
    // 0040f72a  39c1                   +cmp ecx, eax
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
    // 0040f72c  7c07                   -jl 0x40f735
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0040f735;
    }
    // 0040f72e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0040f730  e9b2000000             -jmp 0x40f7e7
    goto L_0x0040f7e7;
L_0x0040f735:
    // 0040f735  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f738  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f73a  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040f73e  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0040f741  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040f743  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0040f745  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f748  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f74a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040f74c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0040f74f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0040f752  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040f755  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f757  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f75a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f75d  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f75f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0040f762  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f764  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f767  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f769  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040f76b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0040f76e  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040f770  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0040f773  8d7dbc                 -lea edi, [ebp - 0x44]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0040f776  8d340b                 -lea esi, [ebx + ecx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0040f779  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0040f77c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f77d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f77e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f77f  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0040f786  8d7dc8                 -lea edi, [ebp - 0x38]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0040f789  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040f78b  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0040f78e  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0040f791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f792  8d340b                 -lea esi, [ebx + ecx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0040f795  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 0040f798  8d4dc8                 -lea ecx, [ebp - 0x38]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 0040f79b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040f79c  8d5dbc                 -lea ebx, [ebp - 0x44]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0040f79f  8d55dc                 -lea edx, [ebp - 0x24]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 0040f7a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040f7a3  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0040f7a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f7a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f7a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f7a9  e882720a00             -call 0x4b6a30
    cpu.esp -= 4;
    sub_4b6a30(app, cpu);
    if (cpu.terminate) return;
    // 0040f7ae  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f7b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f7b3  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040f7b7  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f7ba  48                     -dec eax
    (cpu.eax)--;
    // 0040f7bb  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0040f7be  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0040f7c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f7c3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f7c6  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f7c8  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040f7cb  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0040f7cd  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f7d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f7d2  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0040f7d6  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f7d9  48                     -dec eax
    (cpu.eax)--;
    // 0040f7da  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0040f7dd  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0040f7e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0040f7e2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0040f7e7:
    // 0040f7e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f7e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f7eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f7ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f7ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f7ee  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_40f800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f800  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f803  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f804  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f806  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040f809  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040f80b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040f80d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0040f814  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f816  8d1cd500000000         -lea ebx, [edx*8]
    cpu.ebx = x86::reg32(cpu.edx * 8);
    // 0040f81d  8b1584367d00           -mov edx, dword ptr [0x7d3684]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040f823  8bbb38f25600           -mov edi, dword ptr [ebx + 0x56f238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5698104) /* 0x56f238 */);
    // 0040f829  8b9b34f25600           -mov ebx, dword ptr [ebx + 0x56f234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5698100) /* 0x56f234 */);
    // 0040f82f  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040f831  668b7b06               -mov di, word ptr [ebx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0040f835  6683ff01               +cmp di, 1
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040f839  720f                   -jb 0x40f84a
    if (cpu.flags.cf)
    {
        goto L_0x0040f84a;
    }
    // 0040f83b  6681ff9001             +cmp di, 0x190
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(400 /*0x190*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0040f840  7708                   -ja 0x40f84a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0040f84a;
    }
    // 0040f842  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0040f844  668b7b06               -mov di, word ptr [ebx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 0040f848  eb05                   -jmp 0x40f84f
    goto L_0x0040f84f;
L_0x0040f84a:
    // 0040f84a  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
L_0x0040f84f:
    // 0040f84f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f851  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f854  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f856  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f858  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f85a  668b4304               -mov ax, word ptr [ebx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040f85e  48                     -dec eax
    (cpu.eax)--;
    // 0040f85f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f862  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0040f865  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040f867  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040f86a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040f86c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040f86e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0040f870  668b4304               -mov ax, word ptr [ebx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0040f874  48                     -dec eax
    (cpu.eax)--;
    // 0040f875  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0040f877  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f87a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f87b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f87c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f87d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_40f880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f880  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f881  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f882  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f883  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f885  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040f888  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040f88b  668b4004               -mov ax, word ptr [eax + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040f88f  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040f894  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0040f897  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040f89e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040f8a0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f8a3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0040f8a5  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f8a8  8d700c                 -lea esi, [eax + 0xc]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0040f8ab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f8ac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f8ad  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0040f8af  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040f8b1  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0040f8b4  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f8b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f8b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f8b9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040f8ba  e8e1730a00             -call 0x4b6ca0
    cpu.esp -= 4;
    sub_4b6ca0(app, cpu);
    if (cpu.terminate) return;
    // 0040f8bf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f8c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f8c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f8c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f8c4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_40f8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f8d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f8d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f8d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f8d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0040f8d7  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0040f8da  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0040f8dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f8de  8b1da4c17900           -mov ebx, dword ptr [0x79c1a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 0040f8e4  8b0485340a5700         -mov eax, dword ptr [eax*4 + 0x570a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5704244) /* 0x570a34 */ + cpu.eax * 4);
    // 0040f8eb  e890ffffff             -call 0x40f880
    cpu.esp -= 4;
    sub_40f880(app, cpu);
    if (cpu.terminate) return;
    // 0040f8f0  f645fc01               +test byte ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 1 /*0x1*/));
    // 0040f8f4  7439                   -je 0x40f92f
    if (cpu.flags.zf)
    {
        goto L_0x0040f92f;
    }
    // 0040f8f6  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0040f8f9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040f8fc  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0040f8ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040f901  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0040f904  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0040f906  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040f909  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0040f90c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0040f90f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040f911  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0040f914  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0040f916  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040f919  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0040f91c  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0040f91f  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0040f922  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040f925  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040f927  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0040f92a  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0040f92c  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
L_0x0040f92f:
    // 0040f92f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040f934  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f936  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f937  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f938  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_40f940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040f940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040f941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040f942  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040f943  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040f944  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040f946  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040f949  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0040f94b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0040f94d  e86e010000             -call 0x40fac0
    cpu.esp -= 4;
    sub_40fac0(app, cpu);
    if (cpu.terminate) return;
    // 0040f952  83f801                 +cmp eax, 1
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
    // 0040f955  740a                   -je 0x40f961
    if (cpu.flags.zf)
    {
        goto L_0x0040f961;
    }
    // 0040f957  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040f95c  e9a5000000             -jmp 0x40fa06
    goto L_0x0040fa06;
L_0x0040f961:
    // 0040f961  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0040f963  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040f966  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0040f968  8d3cc500000000         -lea edi, [eax*8]
    cpu.edi = x86::reg32(cpu.eax * 8);
    // 0040f96f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040f970  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 0040f975  8b9f40f25600           -mov ebx, dword ptr [edi + 0x56f240]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5698112) /* 0x56f240 */);
    // 0040f97b  8b8f38f25600           -mov ecx, dword ptr [edi + 0x56f238]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5698104) /* 0x56f238 */);
    // 0040f981  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0040f984  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040f986  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0040f988  8b9f34f25600           -mov ebx, dword ptr [edi + 0x56f234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5698100) /* 0x56f234 */);
    // 0040f98e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f991  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0040f994  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040f996  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040f999  e812fbffff             -call 0x40f4b0
    cpu.esp -= 4;
    sub_40f4b0(app, cpu);
    if (cpu.terminate) return;
    // 0040f99e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040f9a0  7518                   -jne 0x40f9ba
    if (!cpu.flags.zf)
    {
        goto L_0x0040f9ba;
    }
    // 0040f9a2  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0040f9a7  898734f25600           -mov dword ptr [edi + 0x56f234], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5698100) /* 0x56f234 */) = cpu.eax;
    // 0040f9ad  899f38f25600           -mov dword ptr [edi + 0x56f238], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5698104) /* 0x56f238 */) = cpu.ebx;
    // 0040f9b3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040f9b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f9b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f9b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f9b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040f9b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040f9ba:
    // 0040f9ba  f68744f2560001         +test byte ptr [edi + 0x56f244], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5698116) /* 0x56f244 */) & 1 /*0x1*/));
    // 0040f9c1  743e                   -je 0x40fa01
    if (cpu.flags.zf)
    {
        goto L_0x0040fa01;
    }
    // 0040f9c3  d94618                 -fld dword ptr [esi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 0040f9c6  d9461c                 -fld dword ptr [esi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 0040f9c9  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0040f9cc  d94620                 -fld dword ptr [esi + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(32) /* 0x20 */)));
    // 0040f9cf  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f9d2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 0040f9d4  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f9d7  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040f9da  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040f9dc  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0040f9df  d95e18                 -fstp dword ptr [esi + 0x18]
    app->getMemory<float>(cpu.esi + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f9e2  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f9e5  d95e10                 -fstp dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f9e8  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040f9eb  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040f9ed  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0040f9f0  d95e1c                 -fstp dword ptr [esi + 0x1c]
    app->getMemory<float>(cpu.esi + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f9f3  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0040f9f6  d95e14                 -fstp dword ptr [esi + 0x14]
    app->getMemory<float>(cpu.esi + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0040f9f9  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0040f9fc  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 0040f9fe  d95e20                 -fstp dword ptr [esi + 0x20]
    app->getMemory<float>(cpu.esi + x86::reg32(32) /* 0x20 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0040fa01:
    // 0040fa01  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0040fa06:
    // 0040fa06  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040fa08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fa09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fa0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fa0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fa0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_40fa10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040fa10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040fa11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040fa12  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040fa13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040fa14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040fa16  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0040fa19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040fa1b  e8a0000000             -call 0x40fac0
    cpu.esp -= 4;
    sub_40fac0(app, cpu);
    if (cpu.terminate) return;
    // 0040fa20  83f801                 +cmp eax, 1
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
    // 0040fa23  7407                   -je 0x40fa2c
    if (cpu.flags.zf)
    {
        goto L_0x0040fa2c;
    }
    // 0040fa25  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040fa27  e986000000             -jmp 0x40fab2
    goto L_0x0040fab2;
L_0x0040fa2c:
    // 0040fa2c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0040fa2e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0040fa31  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040fa33  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0040fa36  8b8234f25600           -mov eax, dword ptr [edx + 0x56f234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5698100) /* 0x56f234 */);
    // 0040fa3c  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0040fa3f  668b4004               -mov ax, word ptr [eax + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0040fa43  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0040fa48  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0040fa4b  8b823cf25600           -mov eax, dword ptr [edx + 0x56f23c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5698108) /* 0x56f23c */);
    // 0040fa51  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fa53  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0040fa56  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0040fa58  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0040fa5f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0040fa61  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040fa64  8d74860c               -lea esi, [esi + eax*4 + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 0040fa68  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0040fa6a  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0040fa6d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040fa6e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0040fa6f  e82c720a00             -call 0x4b6ca0
    cpu.esp -= 4;
    sub_4b6ca0(app, cpu);
    if (cpu.terminate) return;
    // 0040fa74  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0040fa77  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0040fa7a  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0040fa7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fa7f  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0040fa82  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0040fa84  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0040fa87  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0040fa8a  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0040fa8d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040fa8f  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0040fa92  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0040fa94  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0040fa97  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0040fa9a  8b5320                 -mov edx, dword ptr [ebx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 0040fa9d  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0040faa0  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0040faa3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0040faa5  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0040faa8  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0040faaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040faaf  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x0040fab2:
    // 0040fab2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040fab4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fab5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fab6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fab7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40fac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040fac0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040fac1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040fac2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040fac4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fac6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0040fac9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0040facb  833cc534f2560000       +cmp dword ptr [eax*8 + 0x56f234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5698100) /* 0x56f234 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fad3  7505                   -jne 0x40fada
    if (!cpu.flags.zf)
    {
        goto L_0x0040fada;
    }
    // 0040fad5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040fad7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fad8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fad9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040fada:
    // 0040fada  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040fadf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fae0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fae1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_40faf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040faf0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040faf1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040faf3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040faf8  e8b3260d00             -call 0x4e21b0
    cpu.esp -= 4;
    sub_4e21b0(app, cpu);
    if (cpu.terminate) return;
    // 0040fafd  a900000200             +test eax, 0x20000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 131072 /*0x20000*/));
    // 0040fb02  7407                   -je 0x40fb0b
    if (cpu.flags.zf)
    {
        goto L_0x0040fb0b;
    }
    // 0040fb04  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040fb09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fb0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0040fb0b:
    // 0040fb0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040fb0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fb0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40fb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040fb10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040fb11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040fb12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040fb13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040fb14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040fb15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040fb16  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040fb18  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040fb1a  eb05                   -jmp 0x40fb21
    goto L_0x0040fb21;
L_0x0040fb1c:
    // 0040fb1c  83f917                 +cmp ecx, 0x17
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(23 /*0x17*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fb1f  7d17                   -jge 0x40fb38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040fb38;
    }
L_0x0040fb21:
    // 0040fb21  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0040fb23  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0040fb2a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0040fb2c  31cb                   +xor ebx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040fb2e  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0040fb2f  891c8524115700         -mov dword ptr [eax*4 + 0x571124], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */ + cpu.eax * 4) = cpu.ebx;
    // 0040fb36  ebe4                   -jmp 0x40fb1c
    goto L_0x0040fb1c;
L_0x0040fb38:
    // 0040fb38  8b0d00bc6f00           -mov ecx, dword ptr [0x6fbc00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 0040fb3e  8b35dcbb6f00           -mov esi, dword ptr [0x6fbbdc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322588) /* 0x6fbbdc */);
    // 0040fb44  83f902                 +cmp ecx, 2
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
    // 0040fb47  7502                   -jne 0x40fb4b
    if (!cpu.flags.zf)
    {
        goto L_0x0040fb4b;
    }
    // 0040fb49  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0040fb4b:
    // 0040fb4b  8b3de0bb6f00           -mov edi, dword ptr [0x6fbbe0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322592) /* 0x6fbbe0 */);
    // 0040fb51  83f903                 +cmp ecx, 3
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
    // 0040fb54  750e                   -jne 0x40fb64
    if (!cpu.flags.zf)
    {
        goto L_0x0040fb64;
    }
    // 0040fb56  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040fb5b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040fb5d  a3a4255500             -mov dword ptr [0x5525a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */) = cpu.eax;
    // 0040fb62  eb08                   -jmp 0x40fb6c
    goto L_0x0040fb6c;
L_0x0040fb64:
    // 0040fb64  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040fb66  891da4255500           -mov dword ptr [0x5525a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */) = cpu.ebx;
L_0x0040fb6c:
    // 0040fb6c  833d0c29550000         +cmp dword ptr [0x55290c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581068) /* 0x55290c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fb73  750d                   -jne 0x40fb82
    if (!cpu.flags.zf)
    {
        goto L_0x0040fb82;
    }
    // 0040fb75  833d1029550000         +cmp dword ptr [0x552910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fb7c  0f8466010000           -je 0x40fce8
    if (cpu.flags.zf)
    {
        goto L_0x0040fce8;
    }
L_0x0040fb82:
    // 0040fb82  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040fb87  e824260d00             -call 0x4e21b0
    cpu.esp -= 4;
    sub_4e21b0(app, cpu);
    if (cpu.terminate) return;
    // 0040fb8c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040fb8e  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fb95  7411                   -je 0x40fba8
    if (cpu.flags.zf)
    {
        goto L_0x0040fba8;
    }
    // 0040fb97  684c685300             -push 0x53684c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466188 /*0x53684c*/;
    cpu.esp -= 4;
    // 0040fb9c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040fb9e  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 0040fba0  e86bd90100             -call 0x42d510
    cpu.esp -= 4;
    sub_42d510(app, cpu);
    if (cpu.terminate) return;
    // 0040fba5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0040fba8:
    // 0040fba8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040fbaa  7541                   -jne 0x40fbed
    if (!cpu.flags.zf)
    {
        goto L_0x0040fbed;
    }
    // 0040fbac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040fbae  753d                   -jne 0x40fbed
    if (!cpu.flags.zf)
    {
        goto L_0x0040fbed;
    }
    // 0040fbb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fbb2  2508080000             -and eax, 0x808
    cpu.eax &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 0040fbb7  3d08080000             +cmp eax, 0x808
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fbbc  7409                   -je 0x40fbc7
    if (cpu.flags.zf)
    {
        goto L_0x0040fbc7;
    }
    // 0040fbbe  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fbc3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fbc5  eb1a                   -jmp 0x40fbe1
    goto L_0x0040fbe1;
L_0x0040fbc7:
    // 0040fbc7  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fbce  740c                   -je 0x40fbdc
    if (cpu.flags.zf)
    {
        goto L_0x0040fbdc;
    }
    // 0040fbd0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fbd5  b808080200             -mov eax, 0x20808
    cpu.eax = 133128 /*0x20808*/;
    // 0040fbda  eb05                   -jmp 0x40fbe1
    goto L_0x0040fbe1;
L_0x0040fbdc:
    // 0040fbdc  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fbe1:
    // 0040fbe1  e84a2a0d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fbe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fbe8  e9ca000000             -jmp 0x40fcb7
    goto L_0x0040fcb7;
L_0x0040fbed:
    // 0040fbed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040fbef  7542                   -jne 0x40fc33
    if (!cpu.flags.zf)
    {
        goto L_0x0040fc33;
    }
    // 0040fbf1  83f901                 +cmp ecx, 1
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
    // 0040fbf4  753d                   -jne 0x40fc33
    if (!cpu.flags.zf)
    {
        goto L_0x0040fc33;
    }
    // 0040fbf6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fbf8  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 0040fbfd  3d04080000             +cmp eax, 0x804
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc02  7409                   -je 0x40fc0d
    if (cpu.flags.zf)
    {
        goto L_0x0040fc0d;
    }
    // 0040fc04  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fc09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fc0b  eb1a                   -jmp 0x40fc27
    goto L_0x0040fc27;
L_0x0040fc0d:
    // 0040fc0d  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc14  740c                   -je 0x40fc22
    if (cpu.flags.zf)
    {
        goto L_0x0040fc22;
    }
    // 0040fc16  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fc1b  b804080200             -mov eax, 0x20804
    cpu.eax = 133124 /*0x20804*/;
    // 0040fc20  eb05                   -jmp 0x40fc27
    goto L_0x0040fc27;
L_0x0040fc22:
    // 0040fc22  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fc27:
    // 0040fc27  e8042a0d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fc2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fc2e  e984000000             -jmp 0x40fcb7
    goto L_0x0040fcb7;
L_0x0040fc33:
    // 0040fc33  83fe01                 +cmp esi, 1
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
    // 0040fc36  753e                   -jne 0x40fc76
    if (!cpu.flags.zf)
    {
        goto L_0x0040fc76;
    }
    // 0040fc38  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040fc3a  753a                   -jne 0x40fc76
    if (!cpu.flags.zf)
    {
        goto L_0x0040fc76;
    }
    // 0040fc3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fc3e  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 0040fc43  3d02080000             +cmp eax, 0x802
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc48  7409                   -je 0x40fc53
    if (cpu.flags.zf)
    {
        goto L_0x0040fc53;
    }
    // 0040fc4a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fc4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fc51  eb1a                   -jmp 0x40fc6d
    goto L_0x0040fc6d;
L_0x0040fc53:
    // 0040fc53  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc5a  740c                   -je 0x40fc68
    if (cpu.flags.zf)
    {
        goto L_0x0040fc68;
    }
    // 0040fc5c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fc61  b802080200             -mov eax, 0x20802
    cpu.eax = 133122 /*0x20802*/;
    // 0040fc66  eb05                   -jmp 0x40fc6d
    goto L_0x0040fc6d;
L_0x0040fc68:
    // 0040fc68  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fc6d:
    // 0040fc6d  e8be290d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fc72  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fc74  eb41                   -jmp 0x40fcb7
    goto L_0x0040fcb7;
L_0x0040fc76:
    // 0040fc76  83fe01                 +cmp esi, 1
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
    // 0040fc79  753c                   -jne 0x40fcb7
    if (!cpu.flags.zf)
    {
        goto L_0x0040fcb7;
    }
    // 0040fc7b  39f1                   +cmp ecx, esi
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
    // 0040fc7d  7538                   -jne 0x40fcb7
    if (!cpu.flags.zf)
    {
        goto L_0x0040fcb7;
    }
    // 0040fc7f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fc81  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 0040fc86  3d01080000             +cmp eax, 0x801
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc8b  7409                   -je 0x40fc96
    if (cpu.flags.zf)
    {
        goto L_0x0040fc96;
    }
    // 0040fc8d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fc92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fc94  eb1a                   -jmp 0x40fcb0
    goto L_0x0040fcb0;
L_0x0040fc96:
    // 0040fc96  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fc9d  740c                   -je 0x40fcab
    if (cpu.flags.zf)
    {
        goto L_0x0040fcab;
    }
    // 0040fc9f  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fca4  b801080200             -mov eax, 0x20801
    cpu.eax = 133121 /*0x20801*/;
    // 0040fca9  eb05                   -jmp 0x40fcb0
    goto L_0x0040fcb0;
L_0x0040fcab:
    // 0040fcab  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fcb0:
    // 0040fcb0  e87b290d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fcb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0040fcb7:
    // 0040fcb7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040fcb9  7d16                   -jge 0x40fcd1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040fcd1;
    }
    // 0040fcbb  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0040fcbd  893d10295500           -mov dword ptr [0x552910], edi
    app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */) = cpu.edi;
    // 0040fcc3  893d18295500           -mov dword ptr [0x552918], edi
    app->getMemory<x86::reg32>(x86::reg32(5581080) /* 0x552918 */) = cpu.edi;
    // 0040fcc9  893d0c295500           -mov dword ptr [0x55290c], edi
    app->getMemory<x86::reg32>(x86::reg32(5581068) /* 0x55290c */) = cpu.edi;
    // 0040fccf  eb17                   -jmp 0x40fce8
    goto L_0x0040fce8;
L_0x0040fcd1:
    // 0040fcd1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040fcd3  7404                   -je 0x40fcd9
    if (cpu.flags.zf)
    {
        goto L_0x0040fcd9;
    }
    // 0040fcd5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0040fcd7  eb05                   -jmp 0x40fcde
    goto L_0x0040fcde;
L_0x0040fcd9:
    // 0040fcd9  b8ceffffff             -mov eax, 0xffffffce
    cpu.eax = 4294967246 /*0xffffffce*/;
L_0x0040fcde:
    // 0040fcde  e845250d00             -call 0x4e2228
    cpu.esp -= 4;
    sub_4e2228(app, cpu);
    if (cpu.terminate) return;
    // 0040fce3  e8588a0000             -call 0x418740
    cpu.esp -= 4;
    sub_418740(app, cpu);
    if (cpu.terminate) return;
L_0x0040fce8:
    // 0040fce8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fce9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fcea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fceb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fcec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fced  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fcee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_40fcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040fcf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040fcf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040fcf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040fcf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040fcf4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0040fcf5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040fcf6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040fcf8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0040fcfa  83f802                 +cmp eax, 2
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
    // 0040fcfd  7502                   -jne 0x40fd01
    if (!cpu.flags.zf)
    {
        goto L_0x0040fd01;
    }
    // 0040fcff  31c1                   -xor ecx, eax
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0040fd01:
    // 0040fd01  8b35dcbb6f00           -mov esi, dword ptr [0x6fbbdc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322588) /* 0x6fbbdc */);
    // 0040fd07  83f903                 +cmp ecx, 3
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
    // 0040fd0a  750e                   -jne 0x40fd1a
    if (!cpu.flags.zf)
    {
        goto L_0x0040fd1a;
    }
    // 0040fd0c  c705a425550001000000   -mov dword ptr [0x5525a4], 1
    app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */) = 1 /*0x1*/;
    // 0040fd16  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0040fd18  eb08                   -jmp 0x40fd22
    goto L_0x0040fd22;
L_0x0040fd1a:
    // 0040fd1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0040fd1c  891da4255500           -mov dword ptr [0x5525a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */) = cpu.ebx;
L_0x0040fd22:
    // 0040fd22  833d0c29550000         +cmp dword ptr [0x55290c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581068) /* 0x55290c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fd29  750d                   -jne 0x40fd38
    if (!cpu.flags.zf)
    {
        goto L_0x0040fd38;
    }
    // 0040fd2b  833d1029550000         +cmp dword ptr [0x552910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fd32  0f8464010000           -je 0x40fe9c
    if (cpu.flags.zf)
    {
        goto L_0x0040fe9c;
    }
L_0x0040fd38:
    // 0040fd38  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040fd3d  e86e240d00             -call 0x4e21b0
    cpu.esp -= 4;
    sub_4e21b0(app, cpu);
    if (cpu.terminate) return;
    // 0040fd42  8b3da4255500           -mov edi, dword ptr [0x5525a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
    // 0040fd48  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0040fd4a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0040fd4c  7411                   -je 0x40fd5f
    if (cpu.flags.zf)
    {
        goto L_0x0040fd5f;
    }
    // 0040fd4e  684c685300             -push 0x53684c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466188 /*0x53684c*/;
    cpu.esp -= 4;
    // 0040fd53  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0040fd55  6a64                   -push 0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = 100 /*0x64*/;
    cpu.esp -= 4;
    // 0040fd57  e8b4d70100             -call 0x42d510
    cpu.esp -= 4;
    sub_42d510(app, cpu);
    if (cpu.terminate) return;
    // 0040fd5c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x0040fd5f:
    // 0040fd5f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040fd61  7546                   -jne 0x40fda9
    if (!cpu.flags.zf)
    {
        goto L_0x0040fda9;
    }
    // 0040fd63  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040fd65  7542                   -jne 0x40fda9
    if (!cpu.flags.zf)
    {
        goto L_0x0040fda9;
    }
    // 0040fd67  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fd69  2508080000             -and eax, 0x808
    cpu.eax &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 0040fd6e  3d08080000             +cmp eax, 0x808
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fd73  7409                   -je 0x40fd7e
    if (cpu.flags.zf)
    {
        goto L_0x0040fd7e;
    }
    // 0040fd75  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fd7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fd7c  eb1f                   -jmp 0x40fd9d
    goto L_0x0040fd9d;
L_0x0040fd7e:
    // 0040fd7e  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fd85  740c                   -je 0x40fd93
    if (cpu.flags.zf)
    {
        goto L_0x0040fd93;
    }
    // 0040fd87  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fd8c  b808080200             -mov eax, 0x20808
    cpu.eax = 133128 /*0x20808*/;
    // 0040fd91  eb0a                   -jmp 0x40fd9d
    goto L_0x0040fd9d;
L_0x0040fd93:
    // 0040fd93  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fd98  b808080000             -mov eax, 0x808
    cpu.eax = 2056 /*0x808*/;
L_0x0040fd9d:
    // 0040fd9d  e88e280d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fda2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fda4  e9ca000000             -jmp 0x40fe73
    goto L_0x0040fe73;
L_0x0040fda9:
    // 0040fda9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0040fdab  7542                   -jne 0x40fdef
    if (!cpu.flags.zf)
    {
        goto L_0x0040fdef;
    }
    // 0040fdad  83f901                 +cmp ecx, 1
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
    // 0040fdb0  753d                   -jne 0x40fdef
    if (!cpu.flags.zf)
    {
        goto L_0x0040fdef;
    }
    // 0040fdb2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fdb4  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 0040fdb9  3d04080000             +cmp eax, 0x804
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fdbe  7409                   -je 0x40fdc9
    if (cpu.flags.zf)
    {
        goto L_0x0040fdc9;
    }
    // 0040fdc0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fdc5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fdc7  eb1a                   -jmp 0x40fde3
    goto L_0x0040fde3;
L_0x0040fdc9:
    // 0040fdc9  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fdd0  740c                   -je 0x40fdde
    if (cpu.flags.zf)
    {
        goto L_0x0040fdde;
    }
    // 0040fdd2  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fdd7  b804080200             -mov eax, 0x20804
    cpu.eax = 133124 /*0x20804*/;
    // 0040fddc  eb05                   -jmp 0x40fde3
    goto L_0x0040fde3;
L_0x0040fdde:
    // 0040fdde  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fde3:
    // 0040fde3  e848280d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fde8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fdea  e984000000             -jmp 0x40fe73
    goto L_0x0040fe73;
L_0x0040fdef:
    // 0040fdef  83fe01                 +cmp esi, 1
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
    // 0040fdf2  753e                   -jne 0x40fe32
    if (!cpu.flags.zf)
    {
        goto L_0x0040fe32;
    }
    // 0040fdf4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0040fdf6  753a                   -jne 0x40fe32
    if (!cpu.flags.zf)
    {
        goto L_0x0040fe32;
    }
    // 0040fdf8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fdfa  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 0040fdff  3d02080000             +cmp eax, 0x802
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fe04  7409                   -je 0x40fe0f
    if (cpu.flags.zf)
    {
        goto L_0x0040fe0f;
    }
    // 0040fe06  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fe0b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fe0d  eb1a                   -jmp 0x40fe29
    goto L_0x0040fe29;
L_0x0040fe0f:
    // 0040fe0f  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fe16  740c                   -je 0x40fe24
    if (cpu.flags.zf)
    {
        goto L_0x0040fe24;
    }
    // 0040fe18  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fe1d  b802080200             -mov eax, 0x20802
    cpu.eax = 133122 /*0x20802*/;
    // 0040fe22  eb05                   -jmp 0x40fe29
    goto L_0x0040fe29;
L_0x0040fe24:
    // 0040fe24  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fe29:
    // 0040fe29  e802280d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fe2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040fe30  eb41                   -jmp 0x40fe73
    goto L_0x0040fe73;
L_0x0040fe32:
    // 0040fe32  83fe01                 +cmp esi, 1
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
    // 0040fe35  753c                   -jne 0x40fe73
    if (!cpu.flags.zf)
    {
        goto L_0x0040fe73;
    }
    // 0040fe37  39f1                   +cmp ecx, esi
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
    // 0040fe39  7538                   -jne 0x40fe73
    if (!cpu.flags.zf)
    {
        goto L_0x0040fe73;
    }
    // 0040fe3b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0040fe3d  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 0040fe42  3d01080000             +cmp eax, 0x801
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fe47  7409                   -je 0x40fe52
    if (cpu.flags.zf)
    {
        goto L_0x0040fe52;
    }
    // 0040fe49  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fe4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040fe50  eb1a                   -jmp 0x40fe6c
    goto L_0x0040fe6c;
L_0x0040fe52:
    // 0040fe52  833da425550000         +cmp dword ptr [0x5525a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580196) /* 0x5525a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fe59  740c                   -je 0x40fe67
    if (cpu.flags.zf)
    {
        goto L_0x0040fe67;
    }
    // 0040fe5b  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0040fe60  b801080200             -mov eax, 0x20801
    cpu.eax = 133121 /*0x20801*/;
    // 0040fe65  eb05                   -jmp 0x40fe6c
    goto L_0x0040fe6c;
L_0x0040fe67:
    // 0040fe67  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0040fe6c:
    // 0040fe6c  e8bf270d00             -call 0x4e2630
    cpu.esp -= 4;
    sub_4e2630(app, cpu);
    if (cpu.terminate) return;
    // 0040fe71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0040fe73:
    // 0040fe73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0040fe75  7d16                   -jge 0x40fe8d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0040fe8d;
    }
    // 0040fe77  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0040fe79  893510295500           -mov dword ptr [0x552910], esi
    app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */) = cpu.esi;
    // 0040fe7f  893518295500           -mov dword ptr [0x552918], esi
    app->getMemory<x86::reg32>(x86::reg32(5581080) /* 0x552918 */) = cpu.esi;
    // 0040fe85  89350c295500           -mov dword ptr [0x55290c], esi
    app->getMemory<x86::reg32>(x86::reg32(5581068) /* 0x55290c */) = cpu.esi;
    // 0040fe8b  eb0f                   -jmp 0x40fe9c
    goto L_0x0040fe9c;
L_0x0040fe8d:
    // 0040fe8d  e8ae880000             -call 0x418740
    cpu.esp -= 4;
    sub_418740(app, cpu);
    if (cpu.terminate) return;
    // 0040fe92  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0040fe97  e814230d00             -call 0x4e21b0
    cpu.esp -= 4;
    sub_4e21b0(app, cpu);
    if (cpu.terminate) return;
L_0x0040fe9c:
    // 0040fe9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fe9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fe9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fe9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fea0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fea1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_40feb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040feb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040feb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040feb3  833d0c29550000         +cmp dword ptr [0x55290c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581068) /* 0x55290c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040feba  7509                   -jne 0x40fec5
    if (!cpu.flags.zf)
    {
        goto L_0x0040fec5;
    }
    // 0040febc  833d1029550000         +cmp dword ptr [0x552910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0040fec3  7405                   -je 0x40feca
    if (cpu.flags.zf)
    {
        goto L_0x0040feca;
    }
L_0x0040fec5:
    // 0040fec5  e8ea270d00             -call 0x4e26b4
    cpu.esp -= 4;
    sub_4e26b4(app, cpu);
    if (cpu.terminate) return;
L_0x0040feca:
    // 0040feca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fecb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40fed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040fed0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040fed1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040fed2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040fed3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040fed5  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0040fedb  6834277a00             -push 0x7a2734
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005428 /*0x7a2734*/;
    cpu.esp -= 4;
    // 0040fee0  6880685300             -push 0x536880
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466240 /*0x536880*/;
    cpu.esp -= 4;
    // 0040fee5  8d4580                 -lea eax, [ebp - 0x80]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 0040fee8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040fee9  e8a2f70c00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0040feee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040fef1  8d4580                 -lea eax, [ebp - 0x80]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 0040fef4  e8670f0d00             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0040fef9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040fefb  7415                   -je 0x40ff12
    if (cpu.flags.zf)
    {
        goto L_0x0040ff12;
    }
    // 0040fefd  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0040feff  8d4580                 -lea eax, [ebp - 0x80]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 0040ff02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ff03  2eff15ec455300         -call dword ptr cs:[0x5345ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457388) /* 0x5345ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0040ff0a  8d4580                 -lea eax, [ebp - 0x80]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-128) /* -0x80 */);
    // 0040ff0d  e88e290d00             -call 0x4e28a0
    cpu.esp -= 4;
    sub_4e28a0(app, cpu);
    if (cpu.terminate) return;
L_0x0040ff12:
    // 0040ff12  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0040ff14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_40ff20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0040ff20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0040ff21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ff22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ff23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0040ff24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ff25  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ff27  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0040ff2d  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 0040ff33  6834277a00             -push 0x7a2734
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005428 /*0x7a2734*/;
    cpu.esp -= 4;
    // 0040ff38  6880685300             -push 0x536880
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466240 /*0x536880*/;
    cpu.esp -= 4;
    // 0040ff3d  8d45f6                 -lea eax, [ebp - 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0040ff40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ff41  e84af70c00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0040ff46  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0040ff49  8d45f6                 -lea eax, [ebp - 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0040ff4c  be0000f000             -mov esi, 0xf00000
    cpu.esi = 15728640 /*0xf00000*/;
    // 0040ff51  e80a0f0d00             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0040ff56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0040ff58  7415                   -je 0x40ff6f
    if (cpu.flags.zf)
    {
        goto L_0x0040ff6f;
    }
    // 0040ff5a  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0040ff5c  8d45f6                 -lea eax, [ebp - 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0040ff5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0040ff60  2eff15ec455300         -call dword ptr cs:[0x5345ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457388) /* 0x5345ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0040ff67  8d45f6                 -lea eax, [ebp - 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0040ff6a  e831290d00             -call 0x4e28a0
    cpu.esp -= 4;
    sub_4e28a0(app, cpu);
    if (cpu.terminate) return;
L_0x0040ff6f:
    // 0040ff6f  8d4d7a                 -lea ecx, [ebp + 0x7a]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0040ff72  8d5d7e                 -lea ebx, [ebp + 0x7e]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0040ff75  8d5576                 -lea edx, [ebp + 0x76]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0040ff78  8d45f6                 -lea eax, [ebp - 0xa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0040ff7b  e8602b0d00             -call 0x4e2ae0
    cpu.esp -= 4;
    sub_4e2ae0(app, cpu);
    if (cpu.terminate) return;
    // 0040ff80  8b4576                 -mov eax, dword ptr [ebp + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0040ff83  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0040ff85  e8a6420d00             -call 0x4e4230
    cpu.esp -= 4;
    sub_4e4230(app, cpu);
    if (cpu.terminate) return;
    // 0040ff8a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0040ff8c  8b4576                 -mov eax, dword ptr [ebp + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0040ff8f  e80c2e0d00             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 0040ff94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0040ff96  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 0040ff9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ff9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffa0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffa1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_40ffd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0040ffd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0040ffd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0040ffd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0040ffd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0040ffd5  a1e4bb6f00             -mov eax, dword ptr [0x6fbbe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 0040ffda  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0040ffdd  83f809                 +cmp eax, 9
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
    // 0040ffe0  7731                   -ja 0x410013
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00410013;
    }
    // 0040ffe2  ff2485a4ff4000         -jmp dword ptr [eax*4 + 0x40ffa4]
    cpu.ip = app->getMemory<x86::reg32>(4259748 + cpu.eax * 4); goto dynamic_jump;
  case 0x0040ffe9:
    // 0040ffe9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0040ffeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffee  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040ffef:
    // 0040ffef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0040fff4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fff5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fff6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fff7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0040fff8:
    // 0040fff8  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0040fffd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040fffe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0040ffff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410000  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00410001:
    // 00410001  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00410006  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410007  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410008  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410009  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0041000a:
    // 0041000a  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0041000f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410011  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410012  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00410013:
    // 00410013  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 00410018  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041001a  e8690d0d00             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 0041001f  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00410021  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00410023  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410024  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410025  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410026  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_410030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00410030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00410031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00410032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00410033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00410034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00410035  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00410036  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00410038  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0041003e  81ed82000000           -sub ebp, 0x82
    (cpu.ebp) -= x86::reg32(x86::sreg32(130 /*0x82*/));
    // 00410044  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00410046  ba00000800             -mov edx, 0x80000
    cpu.edx = 524288 /*0x80000*/;
    // 0041004b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0041004d  8b3d54bb6f00           -mov edi, dword ptr [0x6fbb54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322452) /* 0x6fbb54 */);
    // 00410053  895d72                 -mov dword ptr [ebp + 0x72], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.ebx;
    // 00410056  895d6e                 -mov dword ptr [ebp + 0x6e], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.ebx;
    // 00410059  895576                 -mov dword ptr [ebp + 0x76], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.edx;
    // 0041005c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0041005e  0f85b8020000           -jne 0x41031c
    if (!cpu.flags.zf)
    {
        goto L_0x0041031c;
    }
    // 00410064  83f80a                 +cmp eax, 0xa
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
    // 00410067  0f8daf020000           -jge 0x41031c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041031c;
    }
    // 0041006d  e85e330900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 00410072  833d8ce8550000         +cmp dword ptr [0x55e88c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630092) /* 0x55e88c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00410079  0f859d020000           -jne 0x41031c
    if (!cpu.flags.zf)
    {
        goto L_0x0041031c;
    }
    // 0041007f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00410084  b88c685300             -mov eax, 0x53688c
    cpu.eax = 5466252 /*0x53688c*/;
    // 00410089  e892150d00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0041008e  8b15e4bb6f00           -mov edx, dword ptr [0x6fbbe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 00410094  89457a                 -mov dword ptr [ebp + 0x7a], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */) = cpu.eax;
    // 00410097  83fa03                 +cmp edx, 3
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
    // 0041009a  0f8d92000000           -jge 0x410132
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00410132;
    }
    // 004100a0  8b1c8da8255500         -mov ebx, dword ptr [ecx*4 + 0x5525a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5580200) /* 0x5525a8 */ + cpu.ecx * 4);
    // 004100a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004100a8  68342a7a00             -push 0x7a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8006196 /*0x7a2a34*/;
    cpu.esp -= 4;
    // 004100ad  6890685300             -push 0x536890
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466256 /*0x536890*/;
    cpu.esp -= 4;
    // 004100b2  8d8556ffffff           -lea eax, [ebp - 0xaa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 004100b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004100b9  e8d2f50c00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004100be  8a252eeb5500           -mov ah, byte ptr [0x55eb2e]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 004100c4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004100c7  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004100ca  7534                   -jne 0x410100
    if (!cpu.flags.zf)
    {
        goto L_0x00410100;
    }
    // 004100cc  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 004100cf  752f                   -jne 0x410100
    if (!cpu.flags.zf)
    {
        goto L_0x00410100;
    }
    // 004100d1  f6052feb550001         +test byte ptr [0x55eb2f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */) & 1 /*0x1*/));
    // 004100d8  7526                   -jne 0x410100
    if (!cpu.flags.zf)
    {
        goto L_0x00410100;
    }
    // 004100da  8b35e4bb6f00           -mov esi, dword ptr [0x6fbbe4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 004100e0  83fe01                 +cmp esi, 1
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
    // 004100e3  7507                   -jne 0x4100ec
    if (!cpu.flags.zf)
    {
        goto L_0x004100ec;
    }
    // 004100e5  bea4685300             -mov esi, 0x5368a4
    cpu.esi = 5466276 /*0x5368a4*/;
    // 004100ea  eb19                   -jmp 0x410105
    goto L_0x00410105;
L_0x004100ec:
    // 004100ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004100ee  7410                   -je 0x410100
    if (cpu.flags.zf)
    {
        goto L_0x00410100;
    }
    // 004100f0  833d5428550001         +cmp dword ptr [0x552854], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580884) /* 0x552854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004100f7  7507                   -jne 0x410100
    if (!cpu.flags.zf)
    {
        goto L_0x00410100;
    }
    // 004100f9  bea4685300             -mov esi, 0x5368a4
    cpu.esi = 5466276 /*0x5368a4*/;
    // 004100fe  eb05                   -jmp 0x410105
    goto L_0x00410105;
L_0x00410100:
    // 00410100  be98685300             -mov esi, 0x536898
    cpu.esi = 5466264 /*0x536898*/;
L_0x00410105:
    // 00410105  8dbd56ffffff           -lea edi, [ebp - 0xaa]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 0041010b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0041010c  2bc9                   +sub ecx, ecx
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
    // 0041010e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0041010f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00410111  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00410113  4f                     -dec edi
    (cpu.edi)--;
L_0x00410114:
    // 00410114  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00410116  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00410118  3c00                   +cmp al, 0
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
    // 0041011a  7410                   -je 0x41012c
    if (cpu.flags.zf)
    {
        goto L_0x0041012c;
    }
    // 0041011c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0041011f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00410122  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00410125  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00410128  3c00                   +cmp al, 0
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
    // 0041012a  75e8                   -jne 0x410114
    if (!cpu.flags.zf)
    {
        goto L_0x00410114;
    }
L_0x0041012c:
    // 0041012c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041012d  e9e2000000             -jmp 0x410214
    goto L_0x00410214;
L_0x00410132:
    // 00410132  e899feffff             -call 0x40ffd0
    cpu.esp -= 4;
    sub_40ffd0(app, cpu);
    if (cpu.terminate) return;
    // 00410137  8b1485a8255500         -mov edx, dword ptr [eax*4 + 0x5525a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5580200) /* 0x5525a8 */ + cpu.eax * 4);
    // 0041013e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0041013f  68342a7a00             -push 0x7a2a34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8006196 /*0x7a2a34*/;
    cpu.esp -= 4;
    // 00410144  6890685300             -push 0x536890
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466256 /*0x536890*/;
    cpu.esp -= 4;
    // 00410149  a3f8255500             -mov dword ptr [0x5525f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5580280) /* 0x5525f8 */) = cpu.eax;
    // 0041014e  8d8556ffffff           -lea eax, [ebp - 0xaa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 00410154  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00410155  e836f50c00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0041015a  8b0de4bb6f00           -mov ecx, dword ptr [0x6fbbe4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 00410160  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00410163  83f90b                 +cmp ecx, 0xb
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
    // 00410166  7523                   -jne 0x41018b
    if (!cpu.flags.zf)
    {
        goto L_0x0041018b;
    }
    // 00410168  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 0041016d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0041016f  e8140c0d00             -call 0x4e0d88
    cpu.esp -= 4;
    sub_4e0d88(app, cpu);
    if (cpu.terminate) return;
    // 00410174  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00410176  83fa32                 +cmp edx, 0x32
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
    // 00410179  7604                   -jbe 0x41017f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0041017f;
    }
    // 0041017b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0041017d  eb05                   -jmp 0x410184
    goto L_0x00410184;
L_0x0041017f:
    // 0041017f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00410184:
    // 00410184  a354285500             -mov dword ptr [0x552854], eax
    app->getMemory<x86::reg32>(x86::reg32(5580884) /* 0x552854 */) = cpu.eax;
    // 00410189  eb1d                   -jmp 0x4101a8
    goto L_0x004101a8;
L_0x0041018b:
    // 0041018b  f605e4bb6f0001         +test byte ptr [0x6fbbe4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7322596) /* 0x6fbbe4 */) & 1 /*0x1*/));
    // 00410192  740a                   -je 0x41019e
    if (cpu.flags.zf)
    {
        goto L_0x0041019e;
    }
    // 00410194  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00410196  891d54285500           -mov dword ptr [0x552854], ebx
    app->getMemory<x86::reg32>(x86::reg32(5580884) /* 0x552854 */) = cpu.ebx;
    // 0041019c  eb0a                   -jmp 0x4101a8
    goto L_0x004101a8;
L_0x0041019e:
    // 0041019e  c7055428550001000000   -mov dword ptr [0x552854], 1
    app->getMemory<x86::reg32>(x86::reg32(5580884) /* 0x552854 */) = 1 /*0x1*/;
L_0x004101a8:
    // 004101a8  8a3d2eeb5500           -mov bh, byte ptr [0x55eb2e]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 004101ae  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 004101b1  7534                   -jne 0x4101e7
    if (!cpu.flags.zf)
    {
        goto L_0x004101e7;
    }
    // 004101b3  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 004101b6  752f                   -jne 0x4101e7
    if (!cpu.flags.zf)
    {
        goto L_0x004101e7;
    }
    // 004101b8  f6052feb550001         +test byte ptr [0x55eb2f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630767) /* 0x55eb2f */) & 1 /*0x1*/));
    // 004101bf  7526                   -jne 0x4101e7
    if (!cpu.flags.zf)
    {
        goto L_0x004101e7;
    }
    // 004101c1  8b3de4bb6f00           -mov edi, dword ptr [0x6fbbe4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 004101c7  83ff01                 +cmp edi, 1
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
    // 004101ca  7507                   -jne 0x4101d3
    if (!cpu.flags.zf)
    {
        goto L_0x004101d3;
    }
    // 004101cc  bea4685300             -mov esi, 0x5368a4
    cpu.esi = 5466276 /*0x5368a4*/;
    // 004101d1  eb19                   -jmp 0x4101ec
    goto L_0x004101ec;
L_0x004101d3:
    // 004101d3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004101d5  7410                   -je 0x4101e7
    if (cpu.flags.zf)
    {
        goto L_0x004101e7;
    }
    // 004101d7  833d5428550001         +cmp dword ptr [0x552854], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5580884) /* 0x552854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004101de  7507                   -jne 0x4101e7
    if (!cpu.flags.zf)
    {
        goto L_0x004101e7;
    }
    // 004101e0  bea4685300             -mov esi, 0x5368a4
    cpu.esi = 5466276 /*0x5368a4*/;
    // 004101e5  eb05                   -jmp 0x4101ec
    goto L_0x004101ec;
L_0x004101e7:
    // 004101e7  be98685300             -mov esi, 0x536898
    cpu.esi = 5466264 /*0x536898*/;
L_0x004101ec:
    // 004101ec  8dbd56ffffff           -lea edi, [ebp - 0xaa]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 004101f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004101f3  2bc9                   +sub ecx, ecx
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
    // 004101f5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004101f6  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004101f8  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004101fa  4f                     -dec edi
    (cpu.edi)--;
L_0x004101fb:
    // 004101fb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004101fd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004101ff  3c00                   +cmp al, 0
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
    // 00410201  7410                   -je 0x410213
    if (cpu.flags.zf)
    {
        goto L_0x00410213;
    }
    // 00410203  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00410206  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00410209  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0041020c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0041020f  3c00                   +cmp al, 0
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
    // 00410211  75e8                   -jne 0x4101fb
    if (!cpu.flags.zf)
    {
        goto L_0x004101fb;
    }
L_0x00410213:
    // 00410213  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00410214:
    // 00410214  6834277a00             -push 0x7a2734
    app->getMemory<x86::reg32>(cpu.esp-4) = 8005428 /*0x7a2734*/;
    cpu.esp -= 4;
    // 00410219  6880685300             -push 0x536880
    app->getMemory<x86::reg32>(cpu.esp-4) = 5466240 /*0x536880*/;
    cpu.esp -= 4;
    // 0041021e  8d45d6                 -lea eax, [ebp - 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 00410221  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00410222  e869f40c00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00410227  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0041022a  8d8556ffffff           -lea eax, [ebp - 0xaa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 00410230  e86b410d00             -call 0x4e43a0
    cpu.esp -= 4;
    sub_4e43a0(app, cpu);
    if (cpu.terminate) return;
    // 00410235  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00410237  8d45d6                 -lea eax, [ebp - 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 0041023a  e8210c0d00             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0041023f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00410241  740d                   -je 0x410250
    if (cpu.flags.zf)
    {
        goto L_0x00410250;
    }
    // 00410243  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00410245  8d45d6                 -lea eax, [ebp - 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 00410248  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00410249  2eff15ec455300         -call dword ptr cs:[0x5345ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457388) /* 0x5345ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00410250:
    // 00410250  8d4d5e                 -lea ecx, [ebp + 0x5e]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(94) /* 0x5e */);
    // 00410253  8d5d56                 -lea ebx, [ebp + 0x56]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(86) /* 0x56 */);
    // 00410256  8d5566                 -lea edx, [ebp + 0x66]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00410259  8d8556ffffff           -lea eax, [ebp - 0xaa]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-170) /* -0xaa */);
    // 0041025f  e86c260d00             -call 0x4e28d0
    cpu.esp -= 4;
    sub_4e28d0(app, cpu);
    if (cpu.terminate) return;
    // 00410264  8d4d62                 -lea ecx, [ebp + 0x62]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(98) /* 0x62 */);
    // 00410267  8d5d5a                 -lea ebx, [ebp + 0x5a]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(90) /* 0x5a */);
    // 0041026a  8d556a                 -lea edx, [ebp + 0x6a]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 0041026d  8d45d6                 -lea eax, [ebp - 0x2a]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-42) /* -0x2a */);
    // 00410270  e86b280d00             -call 0x4e2ae0
    cpu.esp -= 4;
    sub_4e2ae0(app, cpu);
    if (cpu.terminate) return;
L_0x00410275:
    // 00410275  8b4d72                 -mov ecx, dword ptr [ebp + 0x72]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00410278  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0041027a  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 0041027d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0041027f  39d8                   +cmp eax, ebx
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
    // 00410281  7d0b                   -jge 0x41028e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0041028e;
    }
    // 00410283  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00410288  894576                 -mov dword ptr [ebp + 0x76], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */) = cpu.eax;
    // 0041028b  89756e                 -mov dword ptr [ebp + 0x6e], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.esi;
L_0x0041028e:
    // 0041028e  8b5572                 -mov edx, dword ptr [ebp + 0x72]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 00410291  8b4566                 -mov eax, dword ptr [ebp + 0x66]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00410294  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 00410297  e8c42b0d00             -call 0x4e2e60
    cpu.esp -= 4;
    sub_4e2e60(app, cpu);
    if (cpu.terminate) return;
    // 0041029c  8b557a                 -mov edx, dword ptr [ebp + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0041029f  8b4566                 -mov eax, dword ptr [ebp + 0x66]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 004102a2  e8392b0d00             -call 0x4e2de0
    cpu.esp -= 4;
    sub_4e2de0(app, cpu);
    if (cpu.terminate) return;
    // 004102a7  8b5d76                 -mov ebx, dword ptr [ebp + 0x76]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004102aa  8b557a                 -mov edx, dword ptr [ebp + 0x7a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 004102ad  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 004102b0  e86b2b0d00             -call 0x4e2e20
    cpu.esp -= 4;
    sub_4e2e20(app, cpu);
    if (cpu.terminate) return;
    // 004102b5  8b4576                 -mov eax, dword ptr [ebp + 0x76]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(118) /* 0x76 */);
    // 004102b8  8b5572                 -mov edx, dword ptr [ebp + 0x72]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */);
    // 004102bb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004102bd  89557e                 -mov dword ptr [ebp + 0x7e], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edx;
    // 004102c0  e80b310900             -call 0x4a33d0
    cpu.esp -= 4;
    sub_4a33d0(app, cpu);
    if (cpu.terminate) return;
    // 004102c5  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 004102c8  dc0db4685300           -fmul qword ptr [0x5368b4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5466292) /* 0x5368b4 */));
    // 004102ce  897d7e                 -mov dword ptr [ebp + 0x7e], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.edi;
    // 004102d1  db457e                 -fild dword ptr [ebp + 0x7e]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(126) /* 0x7e */))));
    // 004102d4  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004102d6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004102d9  dc05bc685300           -fadd qword ptr [0x5368bc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5466300) /* 0x5368bc */));
    // 004102df  8b4d6e                 -mov ecx, dword ptr [ebp + 0x6e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(110) /* 0x6e */);
    // 004102e2  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004102e5  895572                 -mov dword ptr [ebp + 0x72], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(114) /* 0x72 */) = cpu.edx;
    // 004102e8  e8434f0800             -call 0x495230
    cpu.esp -= 4;
    sub_495230(app, cpu);
    if (cpu.terminate) return;
    // 004102ed  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004102ef  750d                   -jne 0x4102fe
    if (!cpu.flags.zf)
    {
        goto L_0x004102fe;
    }
    // 004102f1  833d8ce8550000         +cmp dword ptr [0x55e88c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5630092) /* 0x55e88c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004102f8  0f8477ffffff           -je 0x410275
    if (cpu.flags.zf)
    {
        goto L_0x00410275;
    }
L_0x004102fe:
    // 004102fe  8b4566                 -mov eax, dword ptr [ebp + 0x66]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(102) /* 0x66 */);
    // 00410301  e89a2a0d00             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 00410306  8b456a                 -mov eax, dword ptr [ebp + 0x6a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(106) /* 0x6a */);
    // 00410309  8b757a                 -mov esi, dword ptr [ebp + 0x7a]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(122) /* 0x7a */);
    // 0041030c  e88f2a0d00             -call 0x4e2da0
    cpu.esp -= 4;
    sub_4e2da0(app, cpu);
    if (cpu.terminate) return;
    // 00410311  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00410313  7407                   -je 0x41031c
    if (cpu.flags.zf)
    {
        goto L_0x0041031c;
    }
    // 00410315  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00410317  e874150d00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0041031c:
    // 0041031c  8da582000000           -lea esp, [ebp + 0x82]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(130) /* 0x82 */);
    // 00410322  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410323  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410324  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410325  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410326  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410327  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410328  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_410330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00410330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00410331  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00410332  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00410333  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00410335  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
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
    // 0041033c  751f                   -jne 0x41035d
    if (!cpu.flags.zf)
    {
        goto L_0x0041035d;
    }
    // 0041033e  833d1029550000         +cmp dword ptr [0x552910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00410345  7416                   -je 0x41035d
    if (cpu.flags.zf)
    {
        goto L_0x0041035d;
    }
    // 00410347  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 0041034c  b800b00400             -mov eax, 0x4b000
    cpu.eax = 307200 /*0x4b000*/;
    // 00410351  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00410353  e838440d00             -call 0x4e4790
    cpu.esp -= 4;
    sub_4e4790(app, cpu);
    if (cpu.terminate) return;
    // 00410358  a398255500             -mov dword ptr [0x552598], eax
    app->getMemory<x86::reg32>(x86::reg32(5580184) /* 0x552598 */) = cpu.eax;
L_0x0041035d:
    // 0041035d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041035e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041035f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00410360  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_410370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00410370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00410371  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00410372  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00410373  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00410375  833d54bb6f0000         +cmp dword ptr [0x6fbb54], 0
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
    // 0041037c  751d                   -jne 0x41039b
    if (!cpu.flags.zf)
    {
        goto L_0x0041039b;
    }
    // 0041037e  833d1029550000         +cmp dword ptr [0x552910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5581072) /* 0x552910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00410385  7414                   -je 0x41039b
    if (cpu.flags.zf)
    {
        goto L_0x0041039b;
    }
    // 00410387  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 0041038c  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0041038f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00410391  e8fa430d00             -call 0x4e4790
    cpu.esp -= 4;
    sub_4e4790(app, cpu);
    if (cpu.terminate) return;
    // 00410396  a398255500             -mov dword ptr [0x552598], eax
    app->getMemory<x86::reg32>(x86::reg32(5580184) /* 0x552598 */) = cpu.eax;
L_0x0041039b:
    // 0041039b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041039c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041039d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0041039e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
