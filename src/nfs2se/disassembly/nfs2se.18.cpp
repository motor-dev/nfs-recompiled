#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_47b70e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b70e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b70f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b710  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047b711  2eff1544544b00         -call dword ptr cs:[0x4b5444]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936772) /* 0x4b5444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047b718  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b71a  7508                   -jne 0x47b724
    if (!cpu.flags.zf)
    {
        goto L_0x0047b724;
    }
    // 0047b71c  e821a40100             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 0047b721  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b722  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b723  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b724:
    // 0047b724  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b726  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b727  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b728  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47b730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b730  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b731  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b732  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b734  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b735  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b736  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b739  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b73b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047b73d  8915a8884c00           -mov dword ptr [0x4c88a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5015720) /* 0x4c88a8 */) = cpu.edx;
    // 0047b743  8915a4884c00           -mov dword ptr [0x4c88a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5015716) /* 0x4c88a4 */) = cpu.edx;
    // 0047b749  8915a0884c00           -mov dword ptr [0x4c88a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5015712) /* 0x4c88a0 */) = cpu.edx;
    // 0047b74f  891528824c00           -mov dword ptr [0x4c8228], edx
    app->getMemory<x86::reg32>(x86::reg32(5014056) /* 0x4c8228 */) = cpu.edx;
    // 0047b755  891524824c00           -mov dword ptr [0x4c8224], edx
    app->getMemory<x86::reg32>(x86::reg32(5014052) /* 0x4c8224 */) = cpu.edx;
    // 0047b75b  891520824c00           -mov dword ptr [0x4c8220], edx
    app->getMemory<x86::reg32>(x86::reg32(5014048) /* 0x4c8220 */) = cpu.edx;
    // 0047b761  89151c824c00           -mov dword ptr [0x4c821c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014044) /* 0x4c821c */) = cpu.edx;
    // 0047b767  891518824c00           -mov dword ptr [0x4c8218], edx
    app->getMemory<x86::reg32>(x86::reg32(5014040) /* 0x4c8218 */) = cpu.edx;
    // 0047b76d  891514824c00           -mov dword ptr [0x4c8214], edx
    app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */) = cpu.edx;
    // 0047b773  891510824c00           -mov dword ptr [0x4c8210], edx
    app->getMemory<x86::reg32>(x86::reg32(5014032) /* 0x4c8210 */) = cpu.edx;
    // 0047b779  89150c824c00           -mov dword ptr [0x4c820c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014028) /* 0x4c820c */) = cpu.edx;
    // 0047b77f  882590884c00           -mov byte ptr [0x4c8890], ah
    app->getMemory<x86::reg8>(x86::reg32(5015696) /* 0x4c8890 */) = cpu.ah;
    // 0047b785  e85aac0100             -call 0x4963e4
    cpu.esp -= 4;
    sub_4963e4(app, cpu);
    if (cpu.terminate) return;
    // 0047b78a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b78c  0f8461010000           -je 0x47b8f3
    if (cpu.flags.zf)
    {
        goto L_0x0047b8f3;
    }
    // 0047b792  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b794  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0047b799  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b79d  bf90884c00             -mov edi, 0x4c8890
    cpu.edi = 5015696 /*0x4c8890*/;
    // 0047b7a2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047b7a6  e856ac0100             -call 0x496401
    cpu.esp -= 4;
    sub_496401(app, cpu);
    if (cpu.terminate) return;
    // 0047b7ab  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0047b7ad  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b7b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b7b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b7b3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047b7b6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047b7b8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047b7ba  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047b7bd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047b7bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7c0  881d9c884c00           -mov byte ptr [0x4c889c], bl
    app->getMemory<x86::reg8>(x86::reg32(5015708) /* 0x4c889c */) = cpu.bl;
    // 0047b7c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b7c8  7f0a                   -jg 0x47b7d4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047b7d4;
    }
    // 0047b7ca  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b7cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b7d4:
    // 0047b7d4  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047b7d9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b7db  e821ac0100             -call 0x496401
    cpu.esp -= 4;
    sub_496401(app, cpu);
    if (cpu.terminate) return;
    // 0047b7e0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b7e3  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047b7e8  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047b7eb  a3a0884c00             -mov dword ptr [0x4c88a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015712) /* 0x4c88a0 */) = cpu.eax;
    // 0047b7f0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b7f3  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0047b7f8  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047b7fb  a3a4884c00             -mov dword ptr [0x4c88a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015716) /* 0x4c88a4 */) = cpu.eax;
    // 0047b800  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b803  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047b806  8b2da0884c00           -mov ebp, dword ptr [0x4c88a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5015712) /* 0x4c88a0 */);
    // 0047b80c  a3a8884c00             -mov dword ptr [0x4c88a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015720) /* 0x4c88a8 */) = cpu.eax;
    // 0047b811  83fd05                 +cmp ebp, 5
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b814  7c0a                   -jl 0x47b820
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047b820;
    }
    // 0047b816  c7050c824c0001000000   -mov dword ptr [0x4c820c], 1
    app->getMemory<x86::reg32>(x86::reg32(5014028) /* 0x4c820c */) = 1 /*0x1*/;
L_0x0047b820:
    // 0047b820  833da0884c0006         +cmp dword ptr [0x4c88a0], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015712) /* 0x4c88a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b827  7c0a                   -jl 0x47b833
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047b833;
    }
    // 0047b829  c70510824c0001000000   -mov dword ptr [0x4c8210], 1
    app->getMemory<x86::reg32>(x86::reg32(5014032) /* 0x4c8210 */) = 1 /*0x1*/;
L_0x0047b833:
    // 0047b833  bafcdf4b00             -mov edx, 0x4bdffc
    cpu.edx = 4972540 /*0x4bdffc*/;
    // 0047b838  b890884c00             -mov eax, 0x4c8890
    cpu.eax = 5015696 /*0x4c8890*/;
    // 0047b83d  e8aec0ffff             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b844  7553                   -jne 0x47b899
    if (!cpu.flags.zf)
    {
        goto L_0x0047b899;
    }
    // 0047b846  c70520824c0001000000   -mov dword ptr [0x4c8220], 1
    app->getMemory<x86::reg32>(x86::reg32(5014048) /* 0x4c8220 */) = 1 /*0x1*/;
L_0x0047b850:
    // 0047b850  f644240a80             +test byte ptr [esp + 0xa], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(10) /* 0xa */) & 128 /*0x80*/));
    // 0047b855  0f847f000000           -je 0x47b8da
    if (cpu.flags.zf)
    {
        goto L_0x0047b8da;
    }
    // 0047b85b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047b860:
    // 0047b860  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047b864  a314824c00             -mov dword ptr [0x4c8214], eax
    app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */) = cpu.eax;
    // 0047b869  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0047b86c  0f846c000000           -je 0x47b8de
    if (cpu.flags.zf)
    {
        goto L_0x0047b8de;
    }
    // 0047b872  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047b877:
    // 0047b877  8a6c2409               -mov ch, byte ptr [esp + 9]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */);
    // 0047b87b  a318824c00             -mov dword ptr [0x4c8218], eax
    app->getMemory<x86::reg32>(x86::reg32(5014040) /* 0x4c8218 */) = cpu.eax;
    // 0047b880  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 0047b883  745d                   -je 0x47b8e2
    if (cpu.flags.zf)
    {
        goto L_0x0047b8e2;
    }
    // 0047b885  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047b88a  a31c824c00             -mov dword ptr [0x4c821c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014044) /* 0x4c821c */) = cpu.eax;
    // 0047b88f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b892  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b893  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b894  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b895  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b896  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b897  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b898  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b899:
    // 0047b899  ba0ce04b00             -mov edx, 0x4be00c
    cpu.edx = 4972556 /*0x4be00c*/;
    // 0047b89e  b890884c00             -mov eax, 0x4c8890
    cpu.eax = 5015696 /*0x4c8890*/;
    // 0047b8a3  e848c0ffff             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b8a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b8aa  750c                   -jne 0x47b8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0047b8b8;
    }
    // 0047b8ac  c70528824c0001000000   -mov dword ptr [0x4c8228], 1
    app->getMemory<x86::reg32>(x86::reg32(5014056) /* 0x4c8228 */) = 1 /*0x1*/;
    // 0047b8b6  eb98                   -jmp 0x47b850
    goto L_0x0047b850;
L_0x0047b8b8:
    // 0047b8b8  ba1ce04b00             -mov edx, 0x4be01c
    cpu.edx = 4972572 /*0x4be01c*/;
    // 0047b8bd  b890884c00             -mov eax, 0x4c8890
    cpu.eax = 5015696 /*0x4c8890*/;
    // 0047b8c2  e829c0ffff             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b8c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b8c9  7585                   -jne 0x47b850
    if (!cpu.flags.zf)
    {
        goto L_0x0047b850;
    }
    // 0047b8cb  c70524824c0001000000   -mov dword ptr [0x4c8224], 1
    app->getMemory<x86::reg32>(x86::reg32(5014052) /* 0x4c8224 */) = 1 /*0x1*/;
    // 0047b8d5  e976ffffff             -jmp 0x47b850
    goto L_0x0047b850;
L_0x0047b8da:
    // 0047b8da  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b8dc  eb82                   -jmp 0x47b860
    goto L_0x0047b860;
L_0x0047b8de:
    // 0047b8de  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b8e0  eb95                   -jmp 0x47b877
    goto L_0x0047b877;
L_0x0047b8e2:
    // 0047b8e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b8e4  a31c824c00             -mov dword ptr [0x4c821c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014044) /* 0x4c821c */) = cpu.eax;
    // 0047b8e9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b8ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b8f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b8f3:
    // 0047b8f3  e825ab0100             -call 0x49641d
    cpu.esp -= 4;
    sub_49641d(app, cpu);
    if (cpu.terminate) return;
    // 0047b8f8  a324824c00             -mov dword ptr [0x4c8224], eax
    app->getMemory<x86::reg32>(x86::reg32(5014052) /* 0x4c8224 */) = cpu.eax;
    // 0047b8fd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047b900  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b901  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b902  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b903  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b904  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b905  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b906  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47b910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b910  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b913  29d0                   +sub eax, edx
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
    // 0047b915  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047b919  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047b91d  d84c2414               +fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0047b921  d9542408               +fst dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    // 0047b925  dd1c24                 +fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047b928  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0047b92a  dc1c24                 +fcomp qword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(cpu.esp));
    cpu.fpu.pop();
    // 0047b92d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047b92f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047b930  770a                   -ja 0x47b93c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047b93c;
    }
    // 0047b932  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0047b936  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b939  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047b93c:
    // 0047b93c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 0047b93f  dc0d2ce04b00           -fmul qword ptr [0x4be02c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972588) /* 0x4be02c */));
    // 0047b945  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047b949  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0047b94d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047b950  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47b954(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b954  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b955  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b956  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b957  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047b95a  833d18824c0000         +cmp dword ptr [0x4c8218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014040) /* 0x4c8218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b961  0f8492010000           -je 0x47baf9
    if (cpu.flags.zf)
    {
        goto L_0x0047baf9;
    }
L_0x0047b967:
    // 0047b967  833d0c824c0000         +cmp dword ptr [0x4c820c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014028) /* 0x4c820c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b96e  0f848f010000           -je 0x47bb03
    if (cpu.flags.zf)
    {
        goto L_0x0047bb03;
    }
    // 0047b974  833db0884c0000         +cmp dword ptr [0x4c88b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015728) /* 0x4c88b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b97b  0f8582010000           -jne 0x47bb03
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb03;
    }
    // 0047b981  e88a010000             -call 0x47bb10
    cpu.esp -= 4;
    sub_47bb10(app, cpu);
    if (cpu.terminate) return;
L_0x0047b986:
    // 0047b986  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b988  b940420f00             -mov ecx, 0xf4240
    cpu.ecx = 1000000 /*0xf4240*/;
    // 0047b98d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b98f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047b992  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047b994  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047b998  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047b99c  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0047b99e  dc0534e04b00           +fadd qword ptr [0x4be034]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4972596) /* 0x4be034 */));
    // 0047b9a4  dc0d3ce04b00           +fmul qword ptr [0x4be03c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972604) /* 0x4be03c */));
    // 0047b9aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b9ac  e89feaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047b9b1  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047b9b5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047b9b9  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047b9bd  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047b9c1  dc0d44e04b00           +fmul qword ptr [0x4be044]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972612) /* 0x4be044 */));
    // 0047b9c7  dd054ce04b00           +fld qword ptr [0x4be04c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4972620) /* 0x4be04c */)));
    // 0047b9cd  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047b9cf  d8c1                   +fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0047b9d1  e87aeaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047b9d6  db5c2410               +fistp dword ptr [esp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047b9da  d9c1                   +fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 0047b9dc  dc0554e04b00           +fadd qword ptr [0x4be054]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4972628) /* 0x4be054 */));
    // 0047b9e2  dc0d5ce04b00           +fmul qword ptr [0x4be05c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972636) /* 0x4be05c */));
    // 0047b9e8  e863eaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047b9ed  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047b9f1  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047b9f5  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047b9f9  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047b9fd  dc0d64e04b00           +fmul qword ptr [0x4be064]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972644) /* 0x4be064 */));
    // 0047ba03  dc056ce04b00           +fadd qword ptr [0x4be06c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4972652) /* 0x4be06c */));
    // 0047ba09  e842eaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047ba0e  db5c2408               +fistp dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047ba12  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0047ba14  dc0574e04b00           +fadd qword ptr [0x4be074]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4972660) /* 0x4be074 */));
    // 0047ba1a  dc0d7ce04b00           +fmul qword ptr [0x4be07c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972668) /* 0x4be07c */));
    // 0047ba20  e82beaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047ba25  db5c2414               +fistp dword ptr [esp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047ba29  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ba2d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047ba31  db442414               +fild dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */))));
    // 0047ba35  dc0d84e04b00           +fmul qword ptr [0x4be084]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972676) /* 0x4be084 */));
    // 0047ba3b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba3d  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0047ba3f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ba43  e808eaffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047ba48  db5c240c               +fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047ba4c  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047ba51  e8bafeffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047ba56  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ba5a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ba5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba60  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 0047ba65  e8a6feffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047ba6a  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ba6e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ba72  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba74  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 0047ba79  e892feffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047ba7e  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ba82  68cdcc8c3f             -push 0x3f8ccccd
    app->getMemory<x86::reg32>(cpu.esp-4) = 1066192077 /*0x3f8ccccd*/;
    cpu.esp -= 4;
    // 0047ba87  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ba8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba8d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ba91  e87afeffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047ba96  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047ba9a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ba9c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ba9e  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047baa3  e868feffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047baa8  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    cpu.fpu.pop();
    // 0047baac  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047baae  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047baaf  7604                   -jbe 0x47bab5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047bab5;
    }
    // 0047bab1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
L_0x0047bab5:
    // 0047bab5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047bab9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047babb  689a99993f             -push 0x3f99999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1067030938 /*0x3f99999a*/;
    cpu.esp -= 4;
    // 0047bac0  e84bfeffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047bac5  d95c2414               +fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047bac9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047bacb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bacd  680000803f             -push 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1065353216 /*0x3f800000*/;
    cpu.esp -= 4;
    // 0047bad2  e839feffff             -call 0x47b910
    cpu.esp -= 4;
    sub_47b910(app, cpu);
    if (cpu.terminate) return;
    // 0047bad7  d85c2414               +fcomp dword ptr [esp + 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    cpu.fpu.pop();
    // 0047badb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0047badd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0047bade  7604                   -jbe 0x47bae4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047bae4;
    }
    // 0047bae0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x0047bae4:
    // 0047bae4  69db40420f00           -imul ebx, ebx, 0xf4240
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(1000000 /*0xf4240*/)));
    // 0047baea  891dac884c00           -mov dword ptr [0x4c88ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5015724) /* 0x4c88ac */) = cpu.ebx;
    // 0047baf0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047baf2  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047baf5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047baf6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047baf7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047baf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047baf9:
    // 0047baf9  e832fcffff             -call 0x47b730
    cpu.esp -= 4;
    sub_47b730(app, cpu);
    if (cpu.terminate) return;
    // 0047bafe  e964feffff             -jmp 0x47b967
    goto L_0x0047b967;
L_0x0047bb03:
    // 0047bb03  e888000000             -call 0x47bb90
    cpu.esp -= 4;
    sub_47bb90(app, cpu);
    if (cpu.terminate) return;
    // 0047bb08  e979feffff             -jmp 0x47b986
    goto L_0x0047b986;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47bb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bb10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bb11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bb12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bb13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bb14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bb15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bb16  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 0047bb1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047bb1d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bb1f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047bb21:
    // 0047bb21  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047bb26  e8d5b7ffff             -call 0x477300
    cpu.esp -= 4;
    sub_477300(app, cpu);
    if (cpu.terminate) return;
    // 0047bb2b  833d18824c0000         +cmp dword ptr [0x4c8218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014040) /* 0x4c8218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bb32  7402                   -je 0x47bb36
    if (cpu.flags.zf)
    {
        goto L_0x0047bb36;
    }
    // 0047bb34  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x0047bb36:
    // 0047bb36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047bb38  a134824c00             -mov eax, dword ptr [0x4c8234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0047bb3d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bb3f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047bb42  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047bb44  e8b7b7ffff             -call 0x477300
    cpu.esp -= 4;
    sub_477300(app, cpu);
    if (cpu.terminate) return;
    // 0047bb49  833d18824c0000         +cmp dword ptr [0x4c8218], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014040) /* 0x4c8218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bb50  7402                   -je 0x47bb54
    if (cpu.flags.zf)
    {
        goto L_0x0047bb54;
    }
    // 0047bb52  0f31                   -rdtsc 
    cpu.rdtsc();
L_0x0047bb54:
    // 0047bb54  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047bb56  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047bb58  7408                   -je 0x47bb62
    if (cpu.flags.zf)
    {
        goto L_0x0047bb62;
    }
    // 0047bb5a  39d8                   +cmp eax, ebx
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
    // 0047bb5c  7d20                   -jge 0x47bb7e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bb7e;
    }
L_0x0047bb5e:
    // 0047bb5e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047bb60  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047bb62:
    // 0047bb62  46                     -inc esi
    (cpu.esi)++;
    // 0047bb63  83fe05                 +cmp esi, 5
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bb66  7cb9                   -jl 0x47bb21
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bb21;
    }
    // 0047bb68  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bb6a  7502                   -jne 0x47bb6e
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb6e;
    }
    // 0047bb6c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x0047bb6e:
    // 0047bb6e  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047bb75  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bb77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bb7e:
    // 0047bb7e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bb80  74dc                   -je 0x47bb5e
    if (cpu.flags.zf)
    {
        goto L_0x0047bb5e;
    }
    // 0047bb82  39c8                   +cmp eax, ecx
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
    // 0047bb84  7d04                   -jge 0x47bb8a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bb8a;
    }
L_0x0047bb86:
    // 0047bb86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047bb88  ebd8                   -jmp 0x47bb62
    goto L_0x0047bb62;
L_0x0047bb8a:
    // 0047bb8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bb8c  74f8                   -je 0x47bb86
    if (cpu.flags.zf)
    {
        goto L_0x0047bb86;
    }
    // 0047bb8e  ebd2                   -jmp 0x47bb62
    goto L_0x0047bb62;
}

/* align: skip  */
void Application::sub_47bb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bb90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bb91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bb92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bb93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bb94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bb95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bb96  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047bb99  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bb9b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047bb9d  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047bba1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0047bba5:
    // 0047bba5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047bbaa  e851b7ffff             -call 0x477300
    cpu.esp -= 4;
    sub_477300(app, cpu);
    if (cpu.terminate) return;
    // 0047bbaf  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047bbb4  8b3d34824c00           -mov edi, dword ptr [0x4c8234]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0047bbba  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0047bbbd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bbbf  8b3524b05100           -mov esi, dword ptr [0x51b024]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
L_0x0047bbc5:
    // 0047bbc5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bbc7  b8aaaa5555             -mov eax, 0x5555aaaa
    cpu.eax = 1431677610 /*0x5555aaaa*/;
    // 0047bbcc  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 0047bbd1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047bbd3  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047bbd8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bbda  41                     -inc ecx
    (cpu.ecx)++;
    // 0047bbdb  39f8                   +cmp eax, edi
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
    app->unlockContext(cpu);
    win32::Thread::sleep(0);
    app->lockContext(cpu);
    // 0047bbdd  7ce6                   -jl 0x47bbc5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bbc5;
    }
    // 0047bbdf  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047bbe3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047bbe5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bbe7  7414                   -je 0x47bbfd
    if (cpu.flags.zf)
    {
        goto L_0x0047bbfd;
    }
    // 0047bbe9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047bbed  39f1                   +cmp ecx, esi
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
    // 0047bbef  0f8d7c000000           -jge 0x47bc71
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bc71;
    }
L_0x0047bbf5:
    // 0047bbf5  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047bbf9  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
L_0x0047bbfd:
    // 0047bbfd  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047bc01  42                     -inc edx
    (cpu.edx)++;
    // 0047bc02  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047bc06  83fa05                 +cmp edx, 5
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
    // 0047bc09  7c9a                   -jl 0x47bba5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bba5;
    }
    // 0047bc0b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047bc0d  7504                   -jne 0x47bc13
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc13;
    }
    // 0047bc0f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0047bc13:
    // 0047bc13  8b1d10824c00           -mov ebx, dword ptr [0x4c8210]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014032) /* 0x4c8210 */);
    // 0047bc19  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047bc1c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bc1e  7566                   -jne 0x47bc86
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc86;
    }
    // 0047bc20  833d0c824c0000         +cmp dword ptr [0x4c820c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014028) /* 0x4c820c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc27  0f856f000000           -jne 0x47bc9c
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc9c;
    }
    // 0047bc2d  833d24824c0000         +cmp dword ptr [0x4c8224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014052) /* 0x4c8224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc34  0f8478000000           -je 0x47bcb2
    if (cpu.flags.zf)
    {
        goto L_0x0047bcb2;
    }
    // 0047bc3a  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047bc3e  db44240c               -fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047bc42  dc0ddce04b00           -fmul qword ptr [0x4be0dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972764) /* 0x4be0dc */));
    // 0047bc48  dc0de4e04b00           -fmul qword ptr [0x4be0e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972772) /* 0x4be0e4 */));
L_0x0047bc4e:
    // 0047bc4e  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047bc51  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0047bc54  d80d0ce14b00           -fmul dword ptr [0x4be10c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4972812) /* 0x4be10c */));
    // 0047bc5a  e8f1e7ffff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 0047bc5f  db5c240c               -fistp dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 0047bc63  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047bc67  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047bc6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bc71:
    // 0047bc71  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047bc73  7480                   -je 0x47bbf5
    if (cpu.flags.zf)
    {
        goto L_0x0047bbf5;
    }
    // 0047bc75  39e9                   +cmp ecx, ebp
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
    // 0047bc77  7d04                   -jge 0x47bc7d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bc7d;
    }
L_0x0047bc79:
    // 0047bc79  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0047bc7b  eb80                   -jmp 0x47bbfd
    goto L_0x0047bbfd;
L_0x0047bc7d:
    // 0047bc7d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047bc7f  74f8                   -je 0x47bc79
    if (cpu.flags.zf)
    {
        goto L_0x0047bc79;
    }
    // 0047bc81  e977ffffff             -jmp 0x47bbfd
    goto L_0x0047bbfd;
L_0x0047bc86:
    // 0047bc86  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047bc8a  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047bc8e  dc0dfce04b00           +fmul qword ptr [0x4be0fc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972796) /* 0x4be0fc */));
    // 0047bc94  dc0d04e14b00           +fmul qword ptr [0x4be104]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972804) /* 0x4be104 */));
    // 0047bc9a  ebb2                   -jmp 0x47bc4e
    goto L_0x0047bc4e;
L_0x0047bc9c:
    // 0047bc9c  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047bca0  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047bca4  dc0dece04b00           +fmul qword ptr [0x4be0ec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972780) /* 0x4be0ec */));
    // 0047bcaa  dc0df4e04b00           +fmul qword ptr [0x4be0f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972788) /* 0x4be0f4 */));
    // 0047bcb0  eb9c                   -jmp 0x47bc4e
    goto L_0x0047bc4e;
L_0x0047bcb2:
    // 0047bcb2  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047bcb6  db44240c               +fild dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */))));
    // 0047bcba  dc0dcce04b00           +fmul qword ptr [0x4be0cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972748) /* 0x4be0cc */));
    // 0047bcc0  dc0dd4e04b00           +fmul qword ptr [0x4be0d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4972756) /* 0x4be0d4 */));
    // 0047bcc6  eb86                   -jmp 0x47bc4e
    goto L_0x0047bc4e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47bcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bcd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bcd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bcd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bcd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bcd4  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047bcda  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047bcdc  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047bcde  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047bce0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047bce1:
    // 0047bce1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047bce3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047bce5  3c00                   +cmp al, 0
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
    // 0047bce7  7410                   -je 0x47bcf9
    if (cpu.flags.zf)
    {
        goto L_0x0047bcf9;
    }
    // 0047bce9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047bcec  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047bcef  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047bcf2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047bcf5  3c00                   +cmp al, 0
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
    // 0047bcf7  75e8                   -jne 0x47bce1
    if (!cpu.flags.zf)
    {
        goto L_0x0047bce1;
    }
L_0x0047bcf9:
    // 0047bcf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bcfa  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047bcfc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bcfe  49                     -dec ecx
    (cpu.ecx)--;
    // 0047bcff  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047bd01  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047bd03  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047bd05  49                     -dec ecx
    (cpu.ecx)--;
    // 0047bd06  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047bd08  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bd0a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047bd0c  48                     -dec eax
    (cpu.eax)--;
    // 0047bd0d  39d0                   +cmp eax, edx
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
    // 0047bd0f  7607                   -jbe 0x47bd18
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047bd18;
    }
L_0x0047bd11:
    // 0047bd11  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047bd13  80fa2e                 +cmp dl, 0x2e
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
    // 0047bd16  7545                   -jne 0x47bd5d
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd5d;
    }
L_0x0047bd18:
    // 0047bd18  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bd1b  742a                   -je 0x47bd47
    if (cpu.flags.zf)
    {
        goto L_0x0047bd47;
    }
    // 0047bd1d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047bd1f  8b35b4884c00           -mov esi, dword ptr [0x4c88b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5015732) /* 0x4c88b4 */);
    // 0047bd25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bd26  2bc9                   +sub ecx, ecx
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
    // 0047bd28  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047bd29  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047bd2b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047bd2d  4f                     -dec edi
    (cpu.edi)--;
L_0x0047bd2e:
    // 0047bd2e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047bd30  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047bd32  3c00                   +cmp al, 0
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
    // 0047bd34  7410                   -je 0x47bd46
    if (cpu.flags.zf)
    {
        goto L_0x0047bd46;
    }
    // 0047bd36  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047bd39  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047bd3c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047bd3f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047bd42  3c00                   +cmp al, 0
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
    // 0047bd44  75e8                   -jne 0x47bd2e
    if (!cpu.flags.zf)
    {
        goto L_0x0047bd2e;
    }
L_0x0047bd46:
    // 0047bd46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047bd47:
    // 0047bd47  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047bd49  e8667e0100             -call 0x493bb4
    cpu.esp -= 4;
    sub_493bb4(app, cpu);
    if (cpu.terminate) return;
    // 0047bd4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bd50  7423                   -je 0x47bd75
    if (cpu.flags.zf)
    {
        goto L_0x0047bd75;
    }
    // 0047bd52  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047bd58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bd5d:
    // 0047bd5d  80fa3a                 +cmp dl, 0x3a
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
    // 0047bd60  74b6                   -je 0x47bd18
    if (cpu.flags.zf)
    {
        goto L_0x0047bd18;
    }
    // 0047bd62  80fa2f                 +cmp dl, 0x2f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bd65  74b1                   -je 0x47bd18
    if (cpu.flags.zf)
    {
        goto L_0x0047bd18;
    }
    // 0047bd67  80fa5c                 +cmp dl, 0x5c
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
    // 0047bd6a  74ac                   -je 0x47bd18
    if (cpu.flags.zf)
    {
        goto L_0x0047bd18;
    }
    // 0047bd6c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047bd6e  48                     -dec eax
    (cpu.eax)--;
    // 0047bd6f  39d0                   +cmp eax, edx
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
    // 0047bd71  779e                   -ja 0x47bd11
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047bd11;
    }
    // 0047bd73  eba3                   -jmp 0x47bd18
    goto L_0x0047bd18;
L_0x0047bd75:
    // 0047bd75  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047bd77  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047bd79  e82ad40000             -call 0x4891a8
    cpu.esp -= 4;
    sub_4891a8(app, cpu);
    if (cpu.terminate) return;
    // 0047bd7e  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0047bd84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47bd8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bd8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bd8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047bd8f  e83cffffff             -call 0x47bcd0
    cpu.esp -= 4;
    sub_47bcd0(app, cpu);
    if (cpu.terminate) return;
    // 0047bd94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bd95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bd98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bd98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bd99  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047bd9e  e82dffffff             -call 0x47bcd0
    cpu.esp -= 4;
    sub_47bcd0(app, cpu);
    if (cpu.terminate) return;
    // 0047bda3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bda4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47bda8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bda8  e823ffffff             -call 0x47bcd0
    cpu.esp -= 4;
    sub_47bcd0(app, cpu);
    if (cpu.terminate) return;
    // 0047bdad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bdaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bdb1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047bdb3  7402                   -je 0x47bdb7
    if (cpu.flags.zf)
    {
        goto L_0x0047bdb7;
    }
    // 0047bdb5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x0047bdb7:
    // 0047bdb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bdb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bdb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bdb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047bdbb  e8e8ffffff             -call 0x47bda8
    cpu.esp -= 4;
    sub_47bda8(app, cpu);
    if (cpu.terminate) return;
    // 0047bdc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bdc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bdc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bdc5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047bdca  e8d9ffffff             -call 0x47bda8
    cpu.esp -= 4;
    sub_47bda8(app, cpu);
    if (cpu.terminate) return;
    // 0047bdcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47bde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bde2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047bde4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bde6  83fb3a                 +cmp ebx, 0x3a
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
    // 0047bde9  0f8486000000           -je 0x47be75
    if (cpu.flags.zf)
    {
        goto L_0x0047be75;
    }
    // 0047bdef  803dbc854c0000         +cmp byte ptr [0x4c85bc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014972) /* 0x4c85bc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bdf6  7426                   -je 0x47be1e
    if (cpu.flags.zf)
    {
        goto L_0x0047be1e;
    }
    // 0047bdf8  b970874c00             -mov ecx, 0x4c8770
    cpu.ecx = 5015408 /*0x4c8770*/;
L_0x0047bdfd:
    // 0047bdfd  8d0419                 -lea eax, [ecx + ebx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebx * 1);
    // 0047be00  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0047be02  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047be07  3d80000000             +cmp eax, 0x80
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
    // 0047be0c  7c0d                   -jl 0x47be1b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047be1b;
    }
    // 0047be0e  3d90000000             +cmp eax, 0x90
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
    // 0047be13  7c03                   -jl 0x47be18
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047be18;
    }
    // 0047be15  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x0047be18:
    // 0047be18  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
L_0x0047be1b:
    // 0047be1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047be1e:
    // 0047be1e  803da1854c0000         +cmp byte ptr [0x4c85a1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014945) /* 0x4c85a1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047be25  741e                   -je 0x47be45
    if (cpu.flags.zf)
    {
        goto L_0x0047be45;
    }
    // 0047be27  833d7c854c0000         +cmp dword ptr [0x4c857c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014908) /* 0x4c857c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be2e  7405                   -je 0x47be35
    if (cpu.flags.zf)
    {
        goto L_0x0047be35;
    }
    // 0047be30  83fb01                 +cmp ebx, 1
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
    // 0047be33  7407                   -je 0x47be3c
    if (cpu.flags.zf)
    {
        goto L_0x0047be3c;
    }
L_0x0047be35:
    // 0047be35  b915874c00             -mov ecx, 0x4c8715
    cpu.ecx = 5015317 /*0x4c8715*/;
    // 0047be3a  ebc1                   -jmp 0x47bdfd
    goto L_0x0047bdfd;
L_0x0047be3c:
    // 0047be3c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047be3e  e8a2f50000             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0047be43  ebb8                   -jmp 0x47bdfd
    goto L_0x0047bdfd;
L_0x0047be45:
    // 0047be45  803dae854c0000         +cmp byte ptr [0x4c85ae], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014958) /* 0x4c85ae */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047be4c  7407                   -je 0x47be55
    if (cpu.flags.zf)
    {
        goto L_0x0047be55;
    }
L_0x0047be4e:
    // 0047be4e  b95f864c00             -mov ecx, 0x4c865f
    cpu.ecx = 5015135 /*0x4c865f*/;
    // 0047be53  eba8                   -jmp 0x47bdfd
    goto L_0x0047bdfd;
L_0x0047be55:
    // 0047be55  803dba854c0000         +cmp byte ptr [0x4c85ba], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014970) /* 0x4c85ba */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047be5c  75f0                   -jne 0x47be4e
    if (!cpu.flags.zf)
    {
        goto L_0x0047be4e;
    }
    // 0047be5e  833d80854c0000         +cmp dword ptr [0x4c8580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014912) /* 0x4c8580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be65  7407                   -je 0x47be6e
    if (cpu.flags.zf)
    {
        goto L_0x0047be6e;
    }
    // 0047be67  b9ba864c00             -mov ecx, 0x4c86ba
    cpu.ecx = 5015226 /*0x4c86ba*/;
    // 0047be6c  eb8f                   -jmp 0x47bdfd
    goto L_0x0047bdfd;
L_0x0047be6e:
    // 0047be6e  b904864c00             -mov ecx, 0x4c8604
    cpu.ecx = 5015044 /*0x4c8604*/;
    // 0047be73  eb88                   -jmp 0x47bdfd
    goto L_0x0047bdfd;
L_0x0047be75:
    // 0047be75  833d80854c0000         +cmp dword ptr [0x4c8580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014912) /* 0x4c8580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be7c  750e                   -jne 0x47be8c
    if (!cpu.flags.zf)
    {
        goto L_0x0047be8c;
    }
    // 0047be7e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047be83  890d80854c00           -mov dword ptr [0x4c8580], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014912) /* 0x4c8580 */) = cpu.ecx;
    // 0047be89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047be8c:
    // 0047be8c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047be8e  890d80854c00           -mov dword ptr [0x4c8580], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014912) /* 0x4c8580 */) = cpu.ecx;
    // 0047be94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47be98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047be98  e883a0ffff             -call 0x475f20
    cpu.esp -= 4;
    sub_475f20(app, cpu);
    if (cpu.terminate) return;
    // 0047be9d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047bea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47bea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bea4  e877a0ffff             -call 0x475f20
    cpu.esp -= 4;
    sub_475f20(app, cpu);
    if (cpu.terminate) return;
    // 0047bea9  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0047beae  e991a50100             -jmp 0x496444
    return sub_496444(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47beb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047beb4  a3b8884c00             -mov dword ptr [0x4c88b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015736) /* 0x4c88b8 */) = cpu.eax;
    // 0047beb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bebc  833db8884c0000         +cmp dword ptr [0x4c88b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015736) /* 0x4c88b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bec3  7503                   -jne 0x47bec8
    if (!cpu.flags.zf)
    {
        goto L_0x0047bec8;
    }
    // 0047bec5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bec7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bec8:
    // 0047bec8  ff15b8884c00           -call dword ptr [0x4c88b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5015736) /* 0x4c88b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047bece  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47bed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0047bed0:
    // 0047bed0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bed2  e8a9c1ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0047bed7  e8e0ffffff             -call 0x47bebc
    cpu.esp -= 4;
    sub_47bebc(app, cpu);
    if (cpu.terminate) return;
    // 0047bedc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bede  74f0                   -je 0x47bed0
    if (cpu.flags.zf)
    {
        goto L_0x0047bed0;
    }
    // 0047bee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47bee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bee4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bee5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bee7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047bee9:
    // 0047bee9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047beeb  e890c1ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0047bef0  e8c7ffffff             -call 0x47bebc
    cpu.esp -= 4;
    sub_47bebc(app, cpu);
    if (cpu.terminate) return;
    // 0047bef5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bef7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047bef9  e8f3b3ffff             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0047befe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bf00  7508                   -jne 0x47bf0a
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf0a;
    }
    // 0047bf02  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bf04  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bf06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf0a:
    // 0047bf0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047bf0c  74db                   -je 0x47bee9
    if (cpu.flags.zf)
    {
        goto L_0x0047bee9;
    }
    // 0047bf0e  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047bf10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bf12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bf18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bf19  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bf1a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bf1c  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047bf21  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047bf23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047bf25:
    // 0047bf25  e892ffffff             -call 0x47bebc
    cpu.esp -= 4;
    sub_47bebc(app, cpu);
    if (cpu.terminate) return;
    // 0047bf2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bf2c  7403                   -je 0x47bf31
    if (cpu.flags.zf)
    {
        goto L_0x0047bf31;
    }
    // 0047bf2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf31:
    // 0047bf31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bf33  e848c1ffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0047bf38  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047bf3d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bf3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bf41  7ce2                   -jl 0x47bf25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bf25;
    }
    // 0047bf43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bf45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bf48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bf49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bf4a  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bf51  741d                   -je 0x47bf70
    if (cpu.flags.zf)
    {
        goto L_0x0047bf70;
    }
L_0x0047bf53:
    // 0047bf53  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047bf58  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 0047bf5d  b884854c00             -mov eax, 0x4c8584
    cpu.eax = 5014916 /*0x4c8584*/;
    // 0047bf62  890d98ae5100           -mov dword ptr [0x51ae98], ecx
    app->getMemory<x86::reg32>(x86::reg32(5353112) /* 0x51ae98 */) = cpu.ecx;
    // 0047bf68  e86f310000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047bf6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf70:
    // 0047bf70  e843300000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0047bf75  a3a0814c00             -mov dword ptr [0x4c81a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */) = cpu.eax;
    // 0047bf7a  ebd7                   -jmp 0x47bf53
    goto L_0x0047bf53;
}

/* align: skip  */
void Application::sub_47bf7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bf7d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bf7f  891598ae5100           -mov dword ptr [0x51ae98], edx
    app->getMemory<x86::reg32>(x86::reg32(5353112) /* 0x51ae98 */) = cpu.edx;
    // 0047bf85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47bf88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x0047bf88:
    // 0047bf88  e8939fffff             -call 0x475f20
    cpu.esp -= 4;
    sub_475f20(app, cpu);
    if (cpu.terminate) return;
    // 0047bf8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bf8f  75f7                   -jne 0x47bf88
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf88;
    }
    // 0047bf91  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bf94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf94  e8d79effff             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0047bf99  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047bf9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47bfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bfa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bfa1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047bfa5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047bfa9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047bfaf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bfb1  7505                   -jne 0x47bfb8
    if (!cpu.flags.zf)
    {
        goto L_0x0047bfb8;
    }
    // 0047bfb3  bb30b15100             -mov ebx, 0x51b130
    cpu.ebx = 5353776 /*0x51b130*/;
L_0x0047bfb8:
    // 0047bfb8  e81bc2ffff             -call 0x4781d8
    cpu.esp -= 4;
    sub_4781d8(app, cpu);
    if (cpu.terminate) return;
    // 0047bfbd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bfbf  743a                   -je 0x47bffb
    if (cpu.flags.zf)
    {
        goto L_0x0047bffb;
    }
    // 0047bfc1  833b00                 +cmp dword ptr [ebx], 0
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
    // 0047bfc4  7407                   -je 0x47bfcd
    if (cpu.flags.zf)
    {
        goto L_0x0047bfcd;
    }
    // 0047bfc6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bfc8  e827750000             -call 0x4834f4
    cpu.esp -= 4;
    sub_4834f4(app, cpu);
    if (cpu.terminate) return;
L_0x0047bfcd:
    // 0047bfcd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bfcf  e8e8660000             -call 0x4826bc
    cpu.esp -= 4;
    sub_4826bc(app, cpu);
    if (cpu.terminate) return;
    // 0047bfd4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bfd6  7412                   -je 0x47bfea
    if (cpu.flags.zf)
    {
        goto L_0x0047bfea;
    }
    // 0047bfd8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bfda  e8b9690000             -call 0x482998
    cpu.esp -= 4;
    sub_482998(app, cpu);
    if (cpu.terminate) return;
    // 0047bfdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bfe1  7407                   -je 0x47bfea
    if (cpu.flags.zf)
    {
        goto L_0x0047bfea;
    }
    // 0047bfe3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bfe5  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
L_0x0047bfea:
    // 0047bfea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bfec  8915cc884c00           -mov dword ptr [0x4c88cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.edx;
    // 0047bff2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047bff7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bff8  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047bffb:
    // 0047bffb  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047c001  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c003  741a                   -je 0x47c01f
    if (cpu.flags.zf)
    {
        goto L_0x0047c01f;
    }
    // 0047c005  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c006  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047c008  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c009  2eff1508544b00         -call dword ptr cs:[0x4b5408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936712) /* 0x4b5408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c010  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047c016  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c017  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c01e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c01f:
    // 0047c01f  c705cc884c00ffffffff   -mov dword ptr [0x4c88cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = 4294967295 /*0xffffffff*/;
    // 0047c029  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c02e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c02f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c034  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c035  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c039  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047c03d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047c041  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047c047  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c049  7505                   -jne 0x47c050
    if (!cpu.flags.zf)
    {
        goto L_0x0047c050;
    }
    // 0047c04b  b930b15100             -mov ecx, 0x51b130
    cpu.ecx = 5353776 /*0x51b130*/;
L_0x0047c050:
    // 0047c050  e883c1ffff             -call 0x4781d8
    cpu.esp -= 4;
    sub_4781d8(app, cpu);
    if (cpu.terminate) return;
    // 0047c055  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c057  7513                   -jne 0x47c06c
    if (!cpu.flags.zf)
    {
        goto L_0x0047c06c;
    }
    // 0047c059  c705cc884c00ffffffff   -mov dword ptr [0x4c88cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = 4294967295 /*0xffffffff*/;
    // 0047c063  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c069  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047c06c:
    // 0047c06c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c06e  e8356b0000             -call 0x482ba8
    cpu.esp -= 4;
    sub_482ba8(app, cpu);
    if (cpu.terminate) return;
    // 0047c073  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c075  e886700000             -call 0x483100
    cpu.esp -= 4;
    sub_483100(app, cpu);
    if (cpu.terminate) return;
    // 0047c07a  83f8ff                 +cmp eax, -1
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
    // 0047c07d  7c54                   -jl 0x47c0d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c0d3;
    }
    // 0047c07f  7f24                   -jg 0x47c0a5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047c0a5;
    }
    // 0047c081  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c082  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047c087  b818e14b00             -mov eax, 0x4be118
    cpu.eax = 4972824 /*0x4be118*/;
    // 0047c08c  891dcc884c00           -mov dword ptr [0x4c88cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.ebx;
    // 0047c092  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c094  752f                   -jne 0x47c0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0047c0c5;
    }
L_0x0047c096:
    // 0047c096  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 0047c09b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c09c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c0a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0a2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047c0a5:
    // 0047c0a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c0a7  752a                   -jne 0x47c0d3
    if (!cpu.flags.zf)
    {
        goto L_0x0047c0d3;
    }
    // 0047c0a9  a3cc884c00             -mov dword ptr [0x4c88cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.eax;
    // 0047c0ae  b824e14b00             -mov eax, 0x4be124
    cpu.eax = 4972836 /*0x4be124*/;
    // 0047c0b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c0b5  7515                   -jne 0x47c0cc
    if (!cpu.flags.zf)
    {
        goto L_0x0047c0cc;
    }
L_0x0047c0b7:
    // 0047c0b7  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 0047c0bc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c0c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c0c2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047c0c5:
    // 0047c0c5  b820e14b00             -mov eax, 0x4be120
    cpu.eax = 4972832 /*0x4be120*/;
    // 0047c0ca  ebca                   -jmp 0x47c096
    goto L_0x0047c096;
L_0x0047c0cc:
    // 0047c0cc  b820e14b00             -mov eax, 0x4be120
    cpu.eax = 4972832 /*0x4be120*/;
    // 0047c0d1  ebe4                   -jmp 0x47c0b7
    goto L_0x0047c0b7;
L_0x0047c0d3:
    // 0047c0d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c0d5  e86a6b0000             -call 0x482c44
    cpu.esp -= 4;
    sub_482c44(app, cpu);
    if (cpu.terminate) return;
    // 0047c0da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c0dc  752b                   -jne 0x47c109
    if (!cpu.flags.zf)
    {
        goto L_0x0047c109;
    }
    // 0047c0de  833dd0884c0000         +cmp dword ptr [0x4c88d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c0e5  7529                   -jne 0x47c110
    if (!cpu.flags.zf)
    {
        goto L_0x0047c110;
    }
    // 0047c0e7  b818e14b00             -mov eax, 0x4be118
    cpu.eax = 4972824 /*0x4be118*/;
    // 0047c0ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c0ee  752e                   -jne 0x47c11e
    if (!cpu.flags.zf)
    {
        goto L_0x0047c11e;
    }
L_0x0047c0f0:
    // 0047c0f0  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0047c0f5  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 0047c0fa  892dcc884c00           -mov dword ptr [0x4c88cc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.ebp;
    // 0047c100  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c105  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c106  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047c109:
    // 0047c109  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c10b  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
L_0x0047c110:
    // 0047c110  a3cc884c00             -mov dword ptr [0x4c88cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.eax;
    // 0047c115  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c11a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c11b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047c11e:
    // 0047c11e  b820e14b00             -mov eax, 0x4be120
    cpu.eax = 4972832 /*0x4be120*/;
    // 0047c123  ebcb                   -jmp 0x47c0f0
    goto L_0x0047c0f0;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c128  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c129  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c12a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c12b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c12c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c12d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c12f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047c131  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047c136  b82ce14b00             -mov eax, 0x4be12c
    cpu.eax = 4972844 /*0x4be12c*/;
    // 0047c13b  8915cc884c00           -mov dword ptr [0x4c88cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.edx;
    // 0047c141  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c143  7530                   -jne 0x47c175
    if (!cpu.flags.zf)
    {
        goto L_0x0047c175;
    }
L_0x0047c145:
    // 0047c145  a3d0884c00             -mov dword ptr [0x4c88d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */) = cpu.eax;
    // 0047c14a  e80da2ffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047c14f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047c151  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c153  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c155  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c157  e8749fffff             -call 0x4760d0
    cpu.esp -= 4;
    sub_4760d0(app, cpu);
    if (cpu.terminate) return;
    // 0047c15c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c15e  740a                   -je 0x47c16a
    if (cpu.flags.zf)
    {
        goto L_0x0047c16a;
    }
    // 0047c160  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047c162:
    // 0047c162  3b2dcc884c00           +cmp ebp, dword ptr [0x4c88cc]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c168  7512                   -jne 0x47c17c
    if (!cpu.flags.zf)
    {
        goto L_0x0047c17c;
    }
L_0x0047c16a:
    // 0047c16a  a1d0884c00             -mov eax, dword ptr [0x4c88d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015760) /* 0x4c88d0 */);
    // 0047c16f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c170  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c171  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c172  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c173  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c174  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c175:
    // 0047c175  b820e14b00             -mov eax, 0x4be120
    cpu.eax = 4972832 /*0x4be120*/;
    // 0047c17a  ebc9                   -jmp 0x47c145
    goto L_0x0047c145;
L_0x0047c17c:
    // 0047c17c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c181  e8d62a0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0047c186  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047c188  e81b2b0000             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 0047c18d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c18f  7407                   -je 0x47c198
    if (cpu.flags.zf)
    {
        goto L_0x0047c198;
    }
    // 0047c191  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047c193  e8e8beffff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
L_0x0047c198:
    // 0047c198  3b2dcc884c00           +cmp ebp, dword ptr [0x4c88cc]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c19e  7ec2                   -jle 0x47c162
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c162;
    }
    // 0047c1a0  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0047c1a5  e8b22a0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0047c1aa  e829c0ffff             -call 0x4781d8
    cpu.esp -= 4;
    sub_4781d8(app, cpu);
    if (cpu.terminate) return;
    // 0047c1af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c1b1  74af                   -je 0x47c162
    if (cpu.flags.zf)
    {
        goto L_0x0047c162;
    }
    // 0047c1b3  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0047c1b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c1be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c1bf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047c1c1  a3cc884c00             -mov dword ptr [0x4c88cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5015756) /* 0x4c88cc */) = cpu.eax;
    // 0047c1c6  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c1cd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047c1cf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047c1d1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047c1d3  e8f89effff             -call 0x4760d0
    cpu.esp -= 4;
    sub_4760d0(app, cpu);
    if (cpu.terminate) return;
    // 0047c1d8  eb88                   -jmp 0x47c162
    goto L_0x0047c162;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c1dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c1dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c1dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c1de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c1df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c1e1  e8c22a0000             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 0047c1e6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c1e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c1ea  7527                   -jne 0x47c213
    if (!cpu.flags.zf)
    {
        goto L_0x0047c213;
    }
    // 0047c1ec  8b154c8d4c00           -mov edx, dword ptr [0x4c8d4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0047c1f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c1f4  740d                   -je 0x47c203
    if (cpu.flags.zf)
    {
        goto L_0x0047c203;
    }
    // 0047c1f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047c1f8  e80b2e0000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047c1fd  8b1d4c8d4c00           -mov ebx, dword ptr [0x4c8d4c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
L_0x0047c203:
    // 0047c203  8b0d84b55100           -mov ecx, dword ptr [0x51b584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0047c209  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c20b  751b                   -jne 0x47c228
    if (!cpu.flags.zf)
    {
        goto L_0x0047c228;
    }
    // 0047c20d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c20f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c210  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c211  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c212  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c213:
    // 0047c213  e844a1ffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047c218  8b0d84b55100           -mov ecx, dword ptr [0x51b584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0047c21e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c220  7506                   -jne 0x47c228
    if (!cpu.flags.zf)
    {
        goto L_0x0047c228;
    }
    // 0047c222  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c224  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c225  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c226  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c227  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c228:
    // 0047c228  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047c22a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c22b  2eff1508544b00         -call dword ptr cs:[0x4b5408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936712) /* 0x4b5408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c232  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c234  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c235  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c236  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c237  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c238(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c238  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c239  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c23a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c23b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c23c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c23d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c23e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c241  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c243  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c245  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x0047c249:
    // 0047c249  80bf5d04000000         +cmp byte ptr [edi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c250  0f8413010000           -je 0x47c369
    if (cpu.flags.zf)
    {
        goto L_0x0047c369;
    }
    // 0047c256  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047c259  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c25d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c261  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 0047c264  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047c267  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047c26a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c26c  0f8579000000           -jne 0x47c2eb
    if (!cpu.flags.zf)
    {
        goto L_0x0047c2eb;
    }
L_0x0047c272:
    // 0047c272  bea0860100             -mov esi, 0x186a0
    cpu.esi = 100000 /*0x186a0*/;
    // 0047c277  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c27a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c27c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047c27e  7e37                   -jle 0x47c2b7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c2b7;
    }
    // 0047c280  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x0047c283:
    // 0047c283  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c285  8a4812                 -mov cl, byte ptr [eax + 0x12]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0047c288  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c28b  751f                   -jne 0x47c2ac
    if (!cpu.flags.zf)
    {
        goto L_0x0047c2ac;
    }
    // 0047c28d  f6400f80               +test byte ptr [eax + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) & 128 /*0x80*/));
    // 0047c291  7519                   -jne 0x47c2ac
    if (!cpu.flags.zf)
    {
        goto L_0x0047c2ac;
    }
    // 0047c293  3b18                   +cmp ebx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c295  7715                   -ja 0x47c2ac
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047c2ac;
    }
    // 0047c297  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c29b  3b4804                 +cmp ecx, dword ptr [eax + 4]
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
    // 0047c29e  770c                   -ja 0x47c2ac
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047c2ac;
    }
    // 0047c2a0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047c2a2  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c2a4  39f1                   +cmp ecx, esi
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
    // 0047c2a6  7304                   -jae 0x47c2ac
    if (!cpu.flags.cf)
    {
        goto L_0x0047c2ac;
    }
    // 0047c2a8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047c2aa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x0047c2ac:
    // 0047c2ac  42                     -inc edx
    (cpu.edx)++;
    // 0047c2ad  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047c2b0  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047c2b3  39ca                   +cmp edx, ecx
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
    // 0047c2b5  7ccc                   -jl 0x47c283
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c283;
    }
L_0x0047c2b7:
    // 0047c2b7  3b6f08                 +cmp ebp, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2ba  7d4f                   -jge 0x47c30b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c30b;
    }
    // 0047c2bc  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047c2c1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047c2c3  e860feffff             -call 0x47c128
    cpu.esp -= 4;
    sub_47c128(app, cpu);
    if (cpu.terminate) return;
    // 0047c2c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c2ca  753b                   -jne 0x47c307
    if (!cpu.flags.zf)
    {
        goto L_0x0047c307;
    }
    // 0047c2cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047c2d1:
    // 0047c2d1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c2d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c2d7  750b                   -jne 0x47c2e4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c2e4;
    }
    // 0047c2d9  6bed14                 -imul ebp, ebp, 0x14
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 0047c2dc  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047c2df  804c280f80             -or byte ptr [eax + ebp + 0xf], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */ + cpu.ebp * 1) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0047c2e4:
    // 0047c2e4  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c2e9  7487                   -je 0x47c272
    if (cpu.flags.zf)
    {
        goto L_0x0047c272;
    }
L_0x0047c2eb:
    // 0047c2eb  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c2ef  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c2f1  7406                   -je 0x47c2f9
    if (cpu.flags.zf)
    {
        goto L_0x0047c2f9;
    }
    // 0047c2f3  0f8450ffffff           -je 0x47c249
    if (cpu.flags.zf)
    {
        goto L_0x0047c249;
    }
L_0x0047c2f9:
    // 0047c2f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c2fd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047c300  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c301  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c302  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c303  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c304  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c305  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c306  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c307:
    // 0047c307  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c309  ebc6                   -jmp 0x47c2d1
    goto L_0x0047c2d1;
L_0x0047c30b:
    // 0047c30b  81fb40010000           +cmp ebx, 0x140
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c311  7616                   -jbe 0x47c329
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047c329;
    }
    // 0047c313  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c317  81eac8000000           -sub edx, 0xc8
    (cpu.edx) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 0047c31d  81ebc8000000           +sub ebx, 0xc8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c323  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047c327  ebbb                   -jmp 0x47c2e4
    goto L_0x0047c2e4;
L_0x0047c329:
    // 0047c329  833c2408               +cmp dword ptr [esp], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c32d  7414                   -je 0x47c343
    if (cpu.flags.zf)
    {
        goto L_0x0047c343;
    }
    // 0047c32f  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047c332  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c336  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047c33b  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047c33e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047c341  eba1                   -jmp 0x47c2e4
    goto L_0x0047c2e4;
L_0x0047c343:
    // 0047c343  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047c348  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047c34d  e8d6fdffff             -call 0x47c128
    cpu.esp -= 4;
    sub_47c128(app, cpu);
    if (cpu.terminate) return;
    // 0047c352  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c354  750b                   -jne 0x47c361
    if (!cpu.flags.zf)
    {
        goto L_0x0047c361;
    }
    // 0047c356  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c35b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c35f  eb8a                   -jmp 0x47c2eb
    goto L_0x0047c2eb;
L_0x0047c361:
    // 0047c361  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c363  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c367  eb82                   -jmp 0x47c2eb
    goto L_0x0047c2eb;
L_0x0047c369:
    // 0047c369  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047c36e  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047c373  e8b0fdffff             -call 0x47c128
    cpu.esp -= 4;
    sub_47c128(app, cpu);
    if (cpu.terminate) return;
    // 0047c378  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c37a  750e                   -jne 0x47c38a
    if (!cpu.flags.zf)
    {
        goto L_0x0047c38a;
    }
    // 0047c37c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c381  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c385  e961ffffff             -jmp 0x47c2eb
    goto L_0x0047c2eb;
L_0x0047c38a:
    // 0047c38a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c38c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047c390  e956ffffff             -jmp 0x47c2eb
    goto L_0x0047c2eb;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c398  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c399  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c39a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c39b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c39d  8a25f0814c00           -mov ah, byte ptr [0x4c81f0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047c3a3  8a158db55100           -mov dl, byte ptr [0x51b58d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 0047c3a9  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 0047c3ac  0f8499000000           -je 0x47c44b
    if (cpu.flags.zf)
    {
        goto L_0x0047c44b;
    }
    // 0047c3b2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047c3b4:
    // 0047c3b4  8a1df0814c00           -mov bl, byte ptr [0x4c81f0]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047c3ba  a28db55100             -mov byte ptr [0x51b58d], al
    app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */) = cpu.al;
    // 0047c3bf  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0047c3c2  0f848a000000           -je 0x47c452
    if (cpu.flags.zf)
    {
        goto L_0x0047c452;
    }
    // 0047c3c8  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0047c3ca  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047c3cc  b302                   -mov bl, 2
    cpu.bl = 2 /*0x2*/;
    // 0047c3ce  880d66b55100           -mov byte ptr [0x51b566], cl
    app->getMemory<x86::reg8>(x86::reg32(5354854) /* 0x51b566 */) = cpu.cl;
    // 0047c3d4  880d65b55100           -mov byte ptr [0x51b565], cl
    app->getMemory<x86::reg8>(x86::reg32(5354853) /* 0x51b565 */) = cpu.cl;
    // 0047c3da  880d64b55100           -mov byte ptr [0x51b564], cl
    app->getMemory<x86::reg8>(x86::reg32(5354852) /* 0x51b564 */) = cpu.cl;
    // 0047c3e0  88258eb55100           -mov byte ptr [0x51b58e], ah
    app->getMemory<x86::reg8>(x86::reg32(5354894) /* 0x51b58e */) = cpu.ah;
    // 0047c3e6  881d67b55100           -mov byte ptr [0x51b567], bl
    app->getMemory<x86::reg8>(x86::reg32(5354855) /* 0x51b567 */) = cpu.bl;
    // 0047c3ec  881d93b55100           -mov byte ptr [0x51b593], bl
    app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */) = cpu.bl;
L_0x0047c3f2:
    // 0047c3f2  a150824c00             -mov eax, dword ptr [0x4c8250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 0047c3f7  8b0dc4814c00           -mov ecx, dword ptr [0x4c81c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
    // 0047c3fd  a350b15100             -mov dword ptr [0x51b150], eax
    app->getMemory<x86::reg32>(x86::reg32(5353808) /* 0x51b150 */) = cpu.eax;
    // 0047c402  83f907                 +cmp ecx, 7
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
    // 0047c405  7427                   -je 0x47c42e
    if (cpu.flags.zf)
    {
        goto L_0x0047c42e;
    }
    // 0047c407  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c408  e8336c0100             -call 0x493040
    cpu.esp -= 4;
    sub_493040(app, cpu);
    if (cpu.terminate) return;
    // 0047c40d  b890c64700             -mov eax, 0x47c690
    cpu.eax = 4703888 /*0x47c690*/;
    // 0047c412  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0047c417  bedcc14700             -mov esi, 0x47c1dc
    cpu.esi = 4702684 /*0x47c1dc*/;
    // 0047c41c  e8fbf10000             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 0047c421  891dc4814c00           -mov dword ptr [0x4c81c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */) = cpu.ebx;
    // 0047c427  89356c824c00           -mov dword ptr [0x4c826c], esi
    app->getMemory<x86::reg32>(x86::reg32(5014124) /* 0x4c826c */) = cpu.esi;
    // 0047c42d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c42e:
    // 0047c42e  e8299fffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047c433  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c435  a08db55100             -mov al, byte ptr [0x51b58d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 0047c43a  39c2                   +cmp edx, eax
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
    // 0047c43c  0f8485000000           -je 0x47c4c7
    if (cpu.flags.zf)
    {
        goto L_0x0047c4c7;
    }
    // 0047c442  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c447  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c448  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c449  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c44a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c44b:
    // 0047c44b  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047c44d  e962ffffff             -jmp 0x47c3b4
    goto L_0x0047c3b4;
L_0x0047c452:
    // 0047c452  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0047c455  7451                   -je 0x47c4a8
    if (cpu.flags.zf)
    {
        goto L_0x0047c4a8;
    }
    // 0047c457  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047c459:
    // 0047c459  8a0df0814c00           -mov cl, byte ptr [0x4c81f0]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047c45f  a266b55100             -mov byte ptr [0x51b566], al
    app->getMemory<x86::reg8>(x86::reg32(5354854) /* 0x51b566 */) = cpu.al;
    // 0047c464  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0047c467  7443                   -je 0x47c4ac
    if (cpu.flags.zf)
    {
        goto L_0x0047c4ac;
    }
    // 0047c469  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047c46b:
    // 0047c46b  8a2df0814c00           -mov ch, byte ptr [0x4c81f0]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047c471  a265b55100             -mov byte ptr [0x51b565], al
    app->getMemory<x86::reg8>(x86::reg32(5354853) /* 0x51b565 */) = cpu.al;
    // 0047c476  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047c479  7435                   -je 0x47c4b0
    if (cpu.flags.zf)
    {
        goto L_0x0047c4b0;
    }
    // 0047c47b  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0047c47d:
    // 0047c47d  a264b55100             -mov byte ptr [0x51b564], al
    app->getMemory<x86::reg8>(x86::reg32(5354852) /* 0x51b564 */) = cpu.al;
    // 0047c482  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0047c484  a28eb55100             -mov byte ptr [0x51b58e], al
    app->getMemory<x86::reg8>(x86::reg32(5354894) /* 0x51b58e */) = cpu.al;
    // 0047c489  a0f4814c00             -mov al, byte ptr [0x4c81f4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014004) /* 0x4c81f4 */);
    // 0047c48e  a267b55100             -mov byte ptr [0x51b567], al
    app->getMemory<x86::reg8>(x86::reg32(5354855) /* 0x51b567 */) = cpu.al;
    // 0047c493  f605f0814c0040         +test byte ptr [0x4c81f0], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */) & 64 /*0x40*/));
    // 0047c49a  7418                   -je 0x47c4b4
    if (cpu.flags.zf)
    {
        goto L_0x0047c4b4;
    }
L_0x0047c49c:
    // 0047c49c  c60593b5510001         -mov byte ptr [0x51b593], 1
    app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */) = 1 /*0x1*/;
    // 0047c4a3  e94affffff             -jmp 0x47c3f2
    goto L_0x0047c3f2;
L_0x0047c4a8:
    // 0047c4a8  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047c4aa  ebad                   -jmp 0x47c459
    goto L_0x0047c459;
L_0x0047c4ac:
    // 0047c4ac  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047c4ae  ebbb                   -jmp 0x47c46b
    goto L_0x0047c46b;
L_0x0047c4b0:
    // 0047c4b0  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0047c4b2  ebc9                   -jmp 0x47c47d
    goto L_0x0047c47d;
L_0x0047c4b4:
    // 0047c4b4  803d66b5510000         +cmp byte ptr [0x51b566], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354854) /* 0x51b566 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c4bb  75df                   -jne 0x47c49c
    if (!cpu.flags.zf)
    {
        goto L_0x0047c49c;
    }
    // 0047c4bd  a293b55100             -mov byte ptr [0x51b593], al
    app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */) = cpu.al;
    // 0047c4c2  e92bffffff             -jmp 0x47c3f2
    goto L_0x0047c3f2;
L_0x0047c4c7:
    // 0047c4c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c4c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c4ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c4cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c4cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c4d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c4d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c4d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c4d5  a08cb55100             -mov al, byte ptr [0x51b58c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354892) /* 0x51b58c */);
    // 0047c4da  8b157cb55100           -mov edx, dword ptr [0x51b57c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5354876) /* 0x51b57c */);
    // 0047c4e0  a3ec814c00             -mov dword ptr [0x4c81ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */) = cpu.eax;
    // 0047c4e5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c4e7  7405                   -je 0x47c4ee
    if (cpu.flags.zf)
    {
        goto L_0x0047c4ee;
    }
    // 0047c4e9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c4ee:
    // 0047c4ee  833d80b5510000         +cmp dword ptr [0x51b580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354880) /* 0x51b580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c4f5  7470                   -je 0x47c567
    if (cpu.flags.zf)
    {
        goto L_0x0047c567;
    }
    // 0047c4f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047c4fc:
    // 0047c4fc  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c4fe  a144b15100             -mov eax, dword ptr [0x51b144]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */);
    // 0047c503  a3e4814c00             -mov dword ptr [0x4c81e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */) = cpu.eax;
    // 0047c508  a148b15100             -mov eax, dword ptr [0x51b148]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */);
    // 0047c50d  a3e8814c00             -mov dword ptr [0x4c81e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */) = cpu.eax;
    // 0047c512  a13cb15100             -mov eax, dword ptr [0x51b13c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353788) /* 0x51b13c */);
    // 0047c517  8b1dfc814c00           -mov ebx, dword ptr [0x4c81fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014012) /* 0x4c81fc */);
    // 0047c51d  a3f8814c00             -mov dword ptr [0x4c81f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5014008) /* 0x4c81f8 */) = cpu.eax;
    // 0047c522  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 0047c527  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c529  8b3500824c00           -mov esi, dword ptr [0x4c8200]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014016) /* 0x4c8200 */);
    // 0047c52f  a304824c00             -mov dword ptr [0x4c8204], eax
    app->getMemory<x86::reg32>(x86::reg32(5014020) /* 0x4c8204 */) = cpu.eax;
    // 0047c534  a1e8814c00             -mov eax, dword ptr [0x4c81e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 0047c539  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c53b  a308824c00             -mov dword ptr [0x4c8208], eax
    app->getMemory<x86::reg32>(x86::reg32(5014024) /* 0x4c8208 */) = cpu.eax;
    // 0047c540  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c542  a093b55100             -mov al, byte ptr [0x51b593]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */);
    // 0047c547  a3c4884c00             -mov dword ptr [0x4c88c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015748) /* 0x4c88c4 */) = cpu.eax;
    // 0047c54c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c54e  a092b55100             -mov al, byte ptr [0x51b592]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354898) /* 0x51b592 */);
    // 0047c553  8915f4814c00           -mov dword ptr [0x4c81f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014004) /* 0x4c81f4 */) = cpu.edx;
    // 0047c559  a3c8884c00             -mov dword ptr [0x4c88c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015752) /* 0x4c88c8 */) = cpu.eax;
    // 0047c55e  e8f99dffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047c563  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c564  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c566  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c567:
    // 0047c567  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c569  eb91                   -jmp 0x47c4fc
    goto L_0x0047c4fc;
}

/* align: skip 0x90 */
void Application::sub_47c56c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c56c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c56d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c56e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c56f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c570  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c571  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c573  8b1530b15100           -mov edx, dword ptr [0x51b130]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
    // 0047c579  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047c57b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c57d  0f85c7000000           -jne 0x47c64a
    if (!cpu.flags.zf)
    {
        goto L_0x0047c64a;
    }
    // 0047c583  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047c588:
    // 0047c588  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c58a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c58c  0f84bf000000           -je 0x47c651
    if (cpu.flags.zf)
    {
        goto L_0x0047c651;
    }
L_0x0047c592:
    // 0047c592  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047c597:
    // 0047c597  68a0bf4700             -push 0x47bfa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4702112 /*0x47bfa0*/;
    cpu.esp -= 4;
    // 0047c59c  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 0047c5a1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c5a3  e8b89bffff             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 0047c5a8  6834c04700             -push 0x47c034
    app->getMemory<x86::reg32>(cpu.esp-4) = 4702260 /*0x47c034*/;
    cpu.esp -= 4;
    // 0047c5ad  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 0047c5b2  e8a99bffff             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 0047c5b7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047c5b9  742f                   -je 0x47c5ea
    if (cpu.flags.zf)
    {
        goto L_0x0047c5ea;
    }
    // 0047c5bb  803d8db5510000         +cmp byte ptr [0x51b58d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047c5c2  7426                   -je 0x47c5ea
    if (cpu.flags.zf)
    {
        goto L_0x0047c5ea;
    }
    // 0047c5c4  833d44b1510000         +cmp dword ptr [0x51b144], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c5cb  750a                   -jne 0x47c5d7
    if (!cpu.flags.zf)
    {
        goto L_0x0047c5d7;
    }
    // 0047c5cd  c70544b1510080020000   -mov dword ptr [0x51b144], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */) = 640 /*0x280*/;
L_0x0047c5d7:
    // 0047c5d7  833d48b1510000         +cmp dword ptr [0x51b148], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c5de  750a                   -jne 0x47c5ea
    if (!cpu.flags.zf)
    {
        goto L_0x0047c5ea;
    }
    // 0047c5e0  c70548b15100e0010000   -mov dword ptr [0x51b148], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */) = 480 /*0x1e0*/;
L_0x0047c5ea:
    // 0047c5ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c5ec  7438                   -je 0x47c626
    if (cpu.flags.zf)
    {
        goto L_0x0047c626;
    }
    // 0047c5ee  8b1548b15100           -mov edx, dword ptr [0x51b148]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */);
    // 0047c5f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c5f6  a144b15100             -mov eax, dword ptr [0x51b144]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */);
    // 0047c5fb  8a1d8db55100           -mov bl, byte ptr [0x51b58d]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 0047c601  e86a85ffff             -call 0x474b70
    cpu.esp -= 4;
    sub_474b70(app, cpu);
    if (cpu.terminate) return;
    // 0047c606  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c608  7454                   -je 0x47c65e
    if (cpu.flags.zf)
    {
        goto L_0x0047c65e;
    }
    // 0047c60a  b864040000             -mov eax, 0x464
    cpu.eax = 1124 /*0x464*/;
    // 0047c60f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c611  e812fbffff             -call 0x47c128
    cpu.esp -= 4;
    sub_47c128(app, cpu);
    if (cpu.terminate) return;
    // 0047c616  8b0d84b55100           -mov ecx, dword ptr [0x51b584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0047c61c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c61d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c61f  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047c626:
    // 0047c626  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047c628  7411                   -je 0x47c63b
    if (cpu.flags.zf)
    {
        goto L_0x0047c63b;
    }
    // 0047c62a  bb0caf4c00             -mov ebx, 0x4caf0c
    cpu.ebx = 5025548 /*0x4caf0c*/;
    // 0047c62f  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047c634  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c636  e85d120100             -call 0x48d898
    cpu.esp -= 4;
    sub_48d898(app, cpu);
    if (cpu.terminate) return;
L_0x0047c63b:
    // 0047c63b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047c63d  7526                   -jne 0x47c665
    if (!cpu.flags.zf)
    {
        goto L_0x0047c665;
    }
    // 0047c63f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c644  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c645  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c646  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c647  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c648  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c649  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c64a:
    // 0047c64a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c64c  e937ffffff             -jmp 0x47c588
    goto L_0x0047c588;
L_0x0047c651:
    // 0047c651  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c653  0f8539ffffff           -jne 0x47c592
    if (!cpu.flags.zf)
    {
        goto L_0x0047c592;
    }
    // 0047c659  e939ffffff             -jmp 0x47c597
    goto L_0x0047c597;
L_0x0047c65e:
    // 0047c65e  bea8e14b00             -mov esi, 0x4be1a8
    cpu.esi = 4972968 /*0x4be1a8*/;
    // 0047c663  ebc1                   -jmp 0x47c626
    goto L_0x0047c626;
L_0x0047c665:
    // 0047c665  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c667  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c668  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c669  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c66a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c66b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c66c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c670  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c671  8b153cb15100           -mov edx, dword ptr [0x51b13c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353788) /* 0x51b13c */);
    // 0047c677  e83484ffff             -call 0x474ab0
    cpu.esp -= 4;
    sub_474ab0(app, cpu);
    if (cpu.terminate) return;
    // 0047c67c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047c67e  e835040000             -call 0x47cab8
    cpu.esp -= 4;
    sub_47cab8(app, cpu);
    if (cpu.terminate) return;
    // 0047c683  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c688(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c688  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c68d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c690  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c691  e8c69cffff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0047c696  833d7ca84c0000         +cmp dword ptr [0x4ca87c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023868) /* 0x4ca87c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c69d  7544                   -jne 0x47c6e3
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6e3;
    }
    // 0047c69f  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c6a6  7543                   -jne 0x47c6eb
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6eb;
    }
L_0x0047c6a8:
    // 0047c6a8  833dc4814c0007         +cmp dword ptr [0x4c81c4], 7
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
    // 0047c6af  7530                   -jne 0x47c6e1
    if (!cpu.flags.zf)
    {
        goto L_0x0047c6e1;
    }
    // 0047c6b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c6b2  8b354c824c00           -mov esi, dword ptr [0x4c824c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */);
    // 0047c6b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047c6ba  7411                   -je 0x47c6cd
    if (cpu.flags.zf)
    {
        goto L_0x0047c6cd;
    }
    // 0047c6bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c6bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c6bf  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047c6c1  e8caa5ffff             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 0047c6c6  893d4c824c00           -mov dword ptr [0x4c824c], edi
    app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */) = cpu.edi;
    // 0047c6cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c6cd:
    // 0047c6cd  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047c6cf  e8c4690100             -call 0x493098
    cpu.esp -= 4;
    sub_493098(app, cpu);
    if (cpu.terminate) return;
    // 0047c6d4  892dc4814c00           -mov dword ptr [0x4c81c4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */) = cpu.ebp;
    // 0047c6da  892d6c824c00           -mov dword ptr [0x4c826c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014124) /* 0x4c826c */) = cpu.ebp;
    // 0047c6e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c6e1:
    // 0047c6e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c6e3:
    // 0047c6e3  ff157ca84c00           -call dword ptr [0x4ca87c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023868) /* 0x4ca87c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c6e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c6ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c6eb:
    // 0047c6eb  e8c083ffff             -call 0x474ab0
    cpu.esp -= 4;
    sub_474ab0(app, cpu);
    if (cpu.terminate) return;
    // 0047c6f0  ebb6                   -jmp 0x47c6a8
    goto L_0x0047c6a8;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47c6f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c6f4  833d30b1510000         +cmp dword ptr [0x51b130], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c6fb  7406                   -je 0x47c703
    if (cpu.flags.zf)
    {
        goto L_0x0047c703;
    }
    // 0047c6fd  a138b15100             -mov eax, dword ptr [0x51b138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353784) /* 0x51b138 */);
    // 0047c702  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c703:
    // 0047c703  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047c708  e8ab030000             -call 0x47cab8
    cpu.esp -= 4;
    sub_47cab8(app, cpu);
    if (cpu.terminate) return;
    // 0047c70d  a138b15100             -mov eax, dword ptr [0x51b138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353784) /* 0x51b138 */);
    // 0047c712  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47c714(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c714  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c715  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c716  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c717  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c718  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c71a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047c71c  833d30b1510000         +cmp dword ptr [0x51b130], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c723  750a                   -jne 0x47c72f
    if (!cpu.flags.zf)
    {
        goto L_0x0047c72f;
    }
    // 0047c725  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047c72a  e889030000             -call 0x47cab8
    cpu.esp -= 4;
    sub_47cab8(app, cpu);
    if (cpu.terminate) return;
L_0x0047c72f:
    // 0047c72f  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0047c734  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c736  e8a1290000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047c73b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c73d  0f8cbe020000           -jl 0x47ca01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ca01;
    }
    // 0047c743  3b1d38b15100           +cmp ebx, dword ptr [0x51b138]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353784) /* 0x51b138 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c749  0f8db2020000           -jge 0x47ca01
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ca01;
    }
    // 0047c74f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c750  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c757  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047c75a  a140b15100             -mov eax, dword ptr [0x51b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c75f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c762  8b3402                 -mov esi, dword ptr [edx + eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 0047c765  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 0047c767  8b740204               -mov esi, dword ptr [edx + eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 0047c76b  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0047c76e  0fb6740213             -movzx esi, byte ptr [edx + eax + 0x13]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 1));
    // 0047c773  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047c776  8a440212               -mov al, byte ptr [edx + eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 1);
    // 0047c77a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c77f  e87c9d0100             -call 0x496500
    cpu.esp -= 4;
    sub_496500(app, cpu);
    if (cpu.terminate) return;
    // 0047c784  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047c787  a140b15100             -mov eax, dword ptr [0x51b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c78c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c78e  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c791  f6420c08               +test byte ptr [edx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 0047c795  0f841c020000           -je 0x47c9b7
    if (cpu.flags.zf)
    {
        goto L_0x0047c9b7;
    }
    // 0047c79b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c7a0:
    // 0047c7a0  8020fd                 -and byte ptr [eax], 0xfd
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047c7a3  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c7a6  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047c7a8  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c7aa  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c7ac  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0047c7ae  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c7b5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c7b7  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c7bd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c7c0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c7c2  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c7c5  f6420c04               +test byte ptr [edx + 0xc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 4 /*0x4*/));
    // 0047c7c9  0f84ef010000           -je 0x47c9be
    if (cpu.flags.zf)
    {
        goto L_0x0047c9be;
    }
    // 0047c7cf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c7d4:
    // 0047c7d4  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c7d7  8020fb                 -and byte ptr [eax], 0xfb
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047c7da  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c7dd  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c7df  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c7e6  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047c7e9  a140b15100             -mov eax, dword ptr [0x51b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c7ee  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c7f1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c7f3  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c7f6  f6420c10               +test byte ptr [edx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 0047c7fa  0f84c5010000           -je 0x47c9c5
    if (cpu.flags.zf)
    {
        goto L_0x0047c9c5;
    }
    // 0047c800  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c805:
    // 0047c805  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c808  8020f7                 -and byte ptr [eax], 0xf7
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047c80b  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047c80e  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c810  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c817  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c819  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c81f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c822  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c824  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c827  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 0047c82b  0f849b010000           -je 0x47c9cc
    if (cpu.flags.zf)
    {
        goto L_0x0047c9cc;
    }
    // 0047c831  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c836:
    // 0047c836  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c839  8020ef                 -and byte ptr [eax], 0xef
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0047c83c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047c83f  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c841  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c848  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c84a  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c850  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c853  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c855  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c858  f6420d08               +test byte ptr [edx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0047c85c  0f8471010000           -je 0x47c9d3
    if (cpu.flags.zf)
    {
        goto L_0x0047c9d3;
    }
    // 0047c862  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c867:
    // 0047c867  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c86a  806001f7               -and byte ptr [eax + 1], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047c86e  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 0047c871  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c873  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c876  c1e01d                 -shl eax, 0x1d
    cpu.eax <<= 29 /*0x1d*/ % 32;
    // 0047c879  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 0047c87c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c87e  0f8528010000           -jne 0x47c9ac
    if (!cpu.flags.zf)
    {
        goto L_0x0047c9ac;
    }
    // 0047c884  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c88b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c88d  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c893  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c896  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c898  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c89b  f6420d04               +test byte ptr [edx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 0047c89f  0f8435010000           -je 0x47c9da
    if (cpu.flags.zf)
    {
        goto L_0x0047c9da;
    }
    // 0047c8a5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c8aa:
    // 0047c8aa  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c8ad  8020df                 -and byte ptr [eax], 0xdf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0047c8b0  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047c8b3  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c8b5  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c8bc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c8be  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c8c4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c8c7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c8c9  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c8cc  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 0047c8d0  0f840b010000           -je 0x47c9e1
    if (cpu.flags.zf)
    {
        goto L_0x0047c9e1;
    }
    // 0047c8d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c8db:
    // 0047c8db  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c8de  8020bf                 -and byte ptr [eax], 0xbf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 0047c8e1  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0047c8e4  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c8e6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c8ed  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047c8f0  a140b15100             -mov eax, dword ptr [0x51b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c8f5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c8f8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c8fa  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c8fd  f6420c80               +test byte ptr [edx + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 0047c901  0f84e1000000           -je 0x47c9e8
    if (cpu.flags.zf)
    {
        goto L_0x0047c9e8;
    }
    // 0047c907  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c90c:
    // 0047c90c  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c90f  80207f                 -and byte ptr [eax], 0x7f
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 0047c912  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 0047c915  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c917  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c91e  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0047c921  a140b15100             -mov eax, dword ptr [0x51b140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c926  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047c929  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c92b  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c92e  f6420d01               +test byte ptr [edx + 0xd], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 1 /*0x1*/));
    // 0047c932  0f84b7000000           -je 0x47c9ef
    if (cpu.flags.zf)
    {
        goto L_0x0047c9ef;
    }
    // 0047c938  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c93d:
    // 0047c93d  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c940  806001fe               -and byte ptr [eax + 1], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0047c944  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0047c947  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c949  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c950  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c952  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c958  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c95b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c95d  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047c960  f6420d02               +test byte ptr [edx + 0xd], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 2 /*0x2*/));
    // 0047c964  0f848c000000           -je 0x47c9f6
    if (cpu.flags.zf)
    {
        goto L_0x0047c9f6;
    }
    // 0047c96a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047c96f:
    // 0047c96f  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c972  806001fd               -and byte ptr [eax + 1], 0xfd
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047c976  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0047c979  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c97b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047c982  8b1540b15100           -mov edx, dword ptr [0x51b140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
    // 0047c988  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c98a  8a5c820c               -mov bl, byte ptr [edx + eax*4 + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 0047c98e  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047c991  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0047c994  7467                   -je 0x47c9fd
    if (cpu.flags.zf)
    {
        goto L_0x0047c9fd;
    }
    // 0047c996  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047c99b:
    // 0047c99b  8a7901                 -mov bh, byte ptr [ecx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047c99e  80e7fb                 -and bh, 0xfb
    cpu.bh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047c9a1  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047c9a4  887901                 -mov byte ptr [ecx + 1], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bh;
    // 0047c9a7  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0047c9aa  0901                   -or dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c9ac:
    // 0047c9ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047c9b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c9b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c9b7:
    // 0047c9b7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9b9  e9e2fdffff             -jmp 0x47c7a0
    goto L_0x0047c7a0;
L_0x0047c9be:
    // 0047c9be  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9c0  e90ffeffff             -jmp 0x47c7d4
    goto L_0x0047c7d4;
L_0x0047c9c5:
    // 0047c9c5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9c7  e939feffff             -jmp 0x47c805
    goto L_0x0047c805;
L_0x0047c9cc:
    // 0047c9cc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9ce  e963feffff             -jmp 0x47c836
    goto L_0x0047c836;
L_0x0047c9d3:
    // 0047c9d3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9d5  e98dfeffff             -jmp 0x47c867
    goto L_0x0047c867;
L_0x0047c9da:
    // 0047c9da  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9dc  e9c9feffff             -jmp 0x47c8aa
    goto L_0x0047c8aa;
L_0x0047c9e1:
    // 0047c9e1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9e3  e9f3feffff             -jmp 0x47c8db
    goto L_0x0047c8db;
L_0x0047c9e8:
    // 0047c9e8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9ea  e91dffffff             -jmp 0x47c90c
    goto L_0x0047c90c;
L_0x0047c9ef:
    // 0047c9ef  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9f1  e947ffffff             -jmp 0x47c93d
    goto L_0x0047c93d;
L_0x0047c9f6:
    // 0047c9f6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047c9f8  e972ffffff             -jmp 0x47c96f
    goto L_0x0047c96f;
L_0x0047c9fd:
    // 0047c9fd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047c9ff  eb9a                   -jmp 0x47c99b
    goto L_0x0047c99b;
L_0x0047ca01:
    // 0047ca01  83fbff                 +cmp ebx, -1
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
    // 0047ca04  0f85a7000000           -jne 0x47cab1
    if (!cpu.flags.zf)
    {
        goto L_0x0047cab1;
    }
    // 0047ca0a  803d8db5510000         +cmp byte ptr [0x51b58d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ca11  0f859a000000           -jne 0x47cab1
    if (!cpu.flags.zf)
    {
        goto L_0x0047cab1;
    }
    // 0047ca17  a144b15100             -mov eax, dword ptr [0x51b144]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */);
    // 0047ca1c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047ca1e  a148b15100             -mov eax, dword ptr [0x51b148]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */);
    // 0047ca23  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047ca26  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca28  a08cb55100             -mov al, byte ptr [0x51b58c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354892) /* 0x51b58c */);
    // 0047ca2d  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047ca30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca32  a025854c00             -mov al, byte ptr [0x4c8525]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014821) /* 0x4c8525 */);
    // 0047ca37  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047ca3a  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047ca3d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca3f  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0047ca42  a092b55100             -mov al, byte ptr [0x51b592]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354898) /* 0x51b592 */);
    // 0047ca47  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 0047ca4a  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047ca4d  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047ca50  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca52  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca54  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0047ca57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca59  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047ca5c  a08fb55100             -mov al, byte ptr [0x51b58f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354895) /* 0x51b58f */);
    // 0047ca61  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 0047ca64  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047ca67  887110                 -mov byte ptr [ecx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 0047ca6a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ca6d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047ca70  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047ca73  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ca75  8a1d93b55100           -mov bl, byte ptr [0x51b593]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5354899) /* 0x51b593 */);
    // 0047ca7b  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 0047ca7d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ca80  762b                   -jbe 0x47caad
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047caad;
    }
    // 0047ca82  803d90b5510000         +cmp byte ptr [0x51b590], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5354896) /* 0x51b590 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ca89  7422                   -je 0x47caad
    if (cpu.flags.zf)
    {
        goto L_0x0047caad;
    }
    // 0047ca8b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047ca90:
    // 0047ca90  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ca92  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 0047ca95  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0047ca98  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 0047ca9a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047ca9d  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047ca9f  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047caa1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047caa6  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047caa8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caa9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047caac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047caad:
    // 0047caad  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047caaf  ebdf                   -jmp 0x47ca90
    goto L_0x0047ca90;
L_0x0047cab1:
    // 0047cab1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cab3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cab5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cab6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cab7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cab8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cab8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cab9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cabb  e8d8f8ffff             -call 0x47c398
    cpu.esp -= 4;
    sub_47c398(app, cpu);
    if (cpu.terminate) return;
    // 0047cac0  e8a7faffff             -call 0x47c56c
    cpu.esp -= 4;
    sub_47c56c(app, cpu);
    if (cpu.terminate) return;
    // 0047cac5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cac7  7441                   -je 0x47cb0a
    if (cpu.flags.zf)
    {
        goto L_0x0047cb0a;
    }
    // 0047cac9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047cacb  7c08                   -jl 0x47cad5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cad5;
    }
    // 0047cacd  3b1538b15100           +cmp edx, dword ptr [0x51b138]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353784) /* 0x51b138 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cad3  7c05                   -jl 0x47cada
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cada;
    }
L_0x0047cad5:
    // 0047cad5  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x0047cada:
    // 0047cada  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 0047cadf  e844f6ffff             -call 0x47c128
    cpu.esp -= 4;
    sub_47c128(app, cpu);
    if (cpu.terminate) return;
    // 0047cae4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cae6  751e                   -jne 0x47cb06
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb06;
    }
    // 0047cae8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0047caed:
    // 0047caed  e8def9ffff             -call 0x47c4d0
    cpu.esp -= 4;
    sub_47c4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047caf2  833dc4814c0007         +cmp dword ptr [0x4c81c4], 7
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
    // 0047caf9  7514                   -jne 0x47cb0f
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb0f;
    }
    // 0047cafb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047cafd  7410                   -je 0x47cb0f
    if (cpu.flags.zf)
    {
        goto L_0x0047cb0f;
    }
    // 0047caff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047cb04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cb06:
    // 0047cb06  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047cb08  ebe3                   -jmp 0x47caed
    goto L_0x0047caed;
L_0x0047cb0a:
    // 0047cb0a  a3c4814c00             -mov dword ptr [0x4c81c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */) = cpu.eax;
L_0x0047cb0f:
    // 0047cb0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cb11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47cb14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cb14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cb15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cb16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cb17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cb18  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cb1e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cb20  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047cb22  8b2d80a84c00           -mov ebp, dword ptr [0x4ca880]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023872) /* 0x4ca880 */);
    // 0047cb28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cb2a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047cb2c  7530                   -jne 0x47cb5e
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb5e;
    }
    // 0047cb2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cb30  7536                   -jne 0x47cb68
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb68;
    }
    // 0047cb32  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x0047cb37:
    // 0047cb37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047cb39  7539                   -jne 0x47cb74
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb74;
    }
    // 0047cb3b  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
L_0x0047cb40:
    // 0047cb40  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047cb42  753c                   -jne 0x47cb80
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb80;
    }
L_0x0047cb44:
    // 0047cb44  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x0047cb49:
    // 0047cb49  893df0814c00           -mov dword ptr [0x4c81f0], edi
    app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */) = cpu.edi;
    // 0047cb4f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047cb51  7439                   -je 0x47cb8c
    if (cpu.flags.zf)
    {
        goto L_0x0047cb8c;
    }
L_0x0047cb53:
    // 0047cb53  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cb59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cb5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cb5e:
    // 0047cb5e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047cb60  ff1580a84c00           -call dword ptr [0x4ca880]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023872) /* 0x4ca880 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047cb66  ebeb                   -jmp 0x47cb53
    goto L_0x0047cb53;
L_0x0047cb68:
    // 0047cb68  83f8ff                 +cmp eax, -1
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
    // 0047cb6b  75ca                   -jne 0x47cb37
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb37;
    }
    // 0047cb6d  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 0047cb72  ebc3                   -jmp 0x47cb37
    goto L_0x0047cb37;
L_0x0047cb74:
    // 0047cb74  83feff                 +cmp esi, -1
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
    // 0047cb77  75c7                   -jne 0x47cb40
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb40;
    }
    // 0047cb79  be00030000             -mov esi, 0x300
    cpu.esi = 768 /*0x300*/;
    // 0047cb7e  ebc0                   -jmp 0x47cb40
    goto L_0x0047cb40;
L_0x0047cb80:
    // 0047cb80  83fbff                 +cmp ebx, -1
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
    // 0047cb83  74bf                   -je 0x47cb44
    if (cpu.flags.zf)
    {
        goto L_0x0047cb44;
    }
    // 0047cb85  83fb0f                 +cmp ebx, 0xf
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
    // 0047cb88  75bf                   -jne 0x47cb49
    if (!cpu.flags.zf)
    {
        goto L_0x0047cb49;
    }
    // 0047cb8a  ebb8                   -jmp 0x47cb44
    goto L_0x0047cb44;
L_0x0047cb8c:
    // 0047cb8c  e807f8ffff             -call 0x47c398
    cpu.esp -= 4;
    sub_47c398(app, cpu);
    if (cpu.terminate) return;
    // 0047cb91  890d44b15100           -mov dword ptr [0x51b144], ecx
    app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */) = cpu.ecx;
    // 0047cb97  893548b15100           -mov dword ptr [0x51b148], esi
    app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */) = cpu.esi;
    // 0047cb9d  891d4cb15100           -mov dword ptr [0x51b14c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5353804) /* 0x51b14c */) = cpu.ebx;
    // 0047cba3  881d8cb55100           -mov byte ptr [0x51b58c], bl
    app->getMemory<x86::reg8>(x86::reg32(5354892) /* 0x51b58c */) = cpu.bl;
    // 0047cba9  e8bef9ffff             -call 0x47c56c
    cpu.esp -= 4;
    sub_47c56c(app, cpu);
    if (cpu.terminate) return;
    // 0047cbae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cbb0  7511                   -jne 0x47cbc3
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbc3;
    }
    // 0047cbb2  8915c4814c00           -mov dword ptr [0x4c81c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */) = cpu.edx;
    // 0047cbb8  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cbbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cbc3:
    // 0047cbc3  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0047cbc8  e86bf6ffff             -call 0x47c238
    cpu.esp -= 4;
    sub_47c238(app, cpu);
    if (cpu.terminate) return;
    // 0047cbcd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cbcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cbd1  7527                   -jne 0x47cbfa
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbfa;
    }
    // 0047cbd3  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cbd9  66f7c78000             +test di, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 128 /*0x80*/));
    // 0047cbde  750a                   -jne 0x47cbea
    if (!cpu.flags.zf)
    {
        goto L_0x0047cbea;
    }
    // 0047cbe0  6681cf8000             +or di, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(128 /*0x80*/))));
    // 0047cbe5  e95fffffff             -jmp 0x47cb49
    goto L_0x0047cb49;
L_0x0047cbea:
    // 0047cbea  a3c4814c00             -mov dword ptr [0x4c81c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */) = cpu.eax;
    // 0047cbef  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cbf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbf8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cbf9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cbfa:
    // 0047cbfa  e8d1f8ffff             -call 0x47c4d0
    cpu.esp -= 4;
    sub_47c4d0(app, cpu);
    if (cpu.terminate) return;
    // 0047cbff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047cc01  7489                   -je 0x47cb8c
    if (cpu.flags.zf)
    {
        goto L_0x0047cb8c;
    }
    // 0047cc03  8b3df0814c00           -mov edi, dword ptr [0x4c81f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 0047cc09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cc10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cc10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cc11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cc12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cc13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cc14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cc17  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cc19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cc1b  8b3530b15100           -mov esi, dword ptr [0x51b130]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
    // 0047cc21  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047cc24  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047cc26  7419                   -je 0x47cc41
    if (cpu.flags.zf)
    {
        goto L_0x0047cc41;
    }
L_0x0047cc28:
    // 0047cc28  833dc4814c0000         +cmp dword ptr [0x4c81c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cc2f  751c                   -jne 0x47cc4d
    if (!cpu.flags.zf)
    {
        goto L_0x0047cc4d;
    }
L_0x0047cc31:
    // 0047cc31  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047cc33  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047cc36  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cc39  83c404                 +add esp, 4
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
    // 0047cc3c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cc41:
    // 0047cc41  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047cc46  e86dfeffff             -call 0x47cab8
    cpu.esp -= 4;
    sub_47cab8(app, cpu);
    if (cpu.terminate) return;
    // 0047cc4b  ebdb                   -jmp 0x47cc28
    goto L_0x0047cc28;
L_0x0047cc4d:
    // 0047cc4d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 0047cc52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cc53  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cc55  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047cc57  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047cc5b  e85c5c0000             -call 0x4828bc
    cpu.esp -= 4;
    sub_4828bc(app, cpu);
    if (cpu.terminate) return;
    // 0047cc60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cc62  74cd                   -je 0x47cc31
    if (cpu.flags.zf)
    {
        goto L_0x0047cc31;
    }
    // 0047cc64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cc67  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047cc6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cc6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47cc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cc70  a1e8884c00             -mov eax, dword ptr [0x4c88e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015784) /* 0x4c88e8 */);
    // 0047cc75  0305e4884c00           +add eax, dword ptr [0x4c88e4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015780) /* 0x4c88e4 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cc7b  a3e4884c00             -mov dword ptr [0x4c88e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015780) /* 0x4c88e4 */) = cpu.eax;
    // 0047cc80  1305e0884c00           +adc eax, dword ptr [0x4c88e0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015776) /* 0x4c88e0 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cc86  a3e0884c00             -mov dword ptr [0x4c88e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015776) /* 0x4c88e0 */) = cpu.eax;
    // 0047cc8b  1305dc884c00           +adc eax, dword ptr [0x4c88dc]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015772) /* 0x4c88dc */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cc91  a3dc884c00             -mov dword ptr [0x4c88dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5015772) /* 0x4c88dc */) = cpu.eax;
    // 0047cc96  1305d8884c00           +adc eax, dword ptr [0x4c88d8]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015768) /* 0x4c88d8 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cc9c  a3d8884c00             -mov dword ptr [0x4c88d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015768) /* 0x4c88d8 */) = cpu.eax;
    // 0047cca1  1305d4884c00           +adc eax, dword ptr [0x4c88d4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5015764) /* 0x4c88d4 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047cca7  ff05e8884c00           +inc dword ptr [0x4c88e8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5015784) /* 0x4c88e8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ccad  7521                   -jne 0x47ccd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ccd0;
    }
    // 0047ccaf  ff05e4884c00           +inc dword ptr [0x4c88e4]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5015780) /* 0x4c88e4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ccb5  7519                   -jne 0x47ccd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ccd0;
    }
    // 0047ccb7  ff05e0884c00           +inc dword ptr [0x4c88e0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5015776) /* 0x4c88e0 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ccbd  7511                   -jne 0x47ccd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ccd0;
    }
    // 0047ccbf  ff05dc884c00           +inc dword ptr [0x4c88dc]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5015772) /* 0x4c88dc */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ccc5  7509                   -jne 0x47ccd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ccd0;
    }
    // 0047ccc7  ff05d8884c00           +inc dword ptr [0x4c88d8]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5015768) /* 0x4c88d8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047cccd  7501                   -jne 0x47ccd0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ccd0;
    }
    // 0047cccf  40                     -inc eax
    (cpu.eax)++;
L_0x0047ccd0:
    // 0047ccd0  a3d4884c00             -mov dword ptr [0x4c88d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015764) /* 0x4c88d4 */) = cpu.eax;
    // 0047ccd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ccd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ccd6  05560e2df2             -add eax, 0xf22d0e56
    (cpu.eax) += x86::reg32(x86::sreg32(4063039062 /*0xf22d0e56*/));
    // 0047ccdb  a3d4884c00             -mov dword ptr [0x4c88d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015764) /* 0x4c88d4 */) = cpu.eax;
    // 0047cce0  0593180496             -add eax, 0x96041893
    (cpu.eax) += x86::reg32(x86::sreg32(2516850835 /*0x96041893*/));
    // 0047cce5  a3d8884c00             -mov dword ptr [0x4c88d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015768) /* 0x4c88d8 */) = cpu.eax;
    // 0047ccea  0546b6f33d             -add eax, 0x3df3b646
    (cpu.eax) += x86::reg32(x86::sreg32(1039382086 /*0x3df3b646*/));
    // 0047ccef  a3dc884c00             -mov dword ptr [0x4c88dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5015772) /* 0x4c88dc */) = cpu.eax;
    // 0047ccf4  056de7dd40             -add eax, 0x40dde76d
    (cpu.eax) += x86::reg32(x86::sreg32(1088284525 /*0x40dde76d*/));
    // 0047ccf9  a3e0884c00             -mov dword ptr [0x4c88e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5015776) /* 0x4c88e0 */) = cpu.eax;
    // 0047ccfe  05e17a3297             -add eax, 0x97327ae1
    (cpu.eax) += x86::reg32(x86::sreg32(2536667873 /*0x97327ae1*/));
    // 0047cd03  a3e4884c00             -mov dword ptr [0x4c88e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5015780) /* 0x4c88e4 */) = cpu.eax;
    // 0047cd08  05e7fba9d1             -add eax, 0xd1a9fbe7
    (cpu.eax) += x86::reg32(x86::sreg32(3517578215 /*0xd1a9fbe7*/));
    // 0047cd0d  a3e8884c00             -mov dword ptr [0x4c88e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5015784) /* 0x4c88e8 */) = cpu.eax;
    // 0047cd12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd20  e897bdffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 0047cd25  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047cd28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cd29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cd2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cd2c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cd31  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047cd35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cd37  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047cd3a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047cd3f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047cd42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047cd46  83f803                 +cmp eax, 3
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
    // 0047cd49  0f8591000000           -jne 0x47cde0
    if (!cpu.flags.zf)
    {
        return sub_47cde0(app, cpu);
    }
    // 0047cd4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cd51  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cd54  7f50                   -jg 0x47cda6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47cda6(app, cpu);
    }
    // 0047cd56  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cd5a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047cd5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cd5d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047cd5d;
    // 0047cd20  e897bdffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 0047cd25  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047cd28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cd29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cd2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cd2c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cd31  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047cd35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cd37  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047cd3a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047cd3f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047cd42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047cd46  83f803                 +cmp eax, 3
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
    // 0047cd49  0f8591000000           -jne 0x47cde0
    if (!cpu.flags.zf)
    {
        return sub_47cde0(app, cpu);
    }
    // 0047cd4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cd51  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cd54  7f50                   -jg 0x47cda6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47cda6(app, cpu);
    }
    // 0047cd56  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cd5a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_entry_0x0047cd5d:
    // 0047cd5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cd28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047cd28;
    // 0047cd20  e897bdffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 0047cd25  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0047cd28:
    // 0047cd28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cd29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cd2a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cd2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047cd2c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cd31  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047cd35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047cd37  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047cd3a  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047cd3f  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0047cd42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047cd46  83f803                 +cmp eax, 3
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
    // 0047cd49  0f8591000000           -jne 0x47cde0
    if (!cpu.flags.zf)
    {
        return sub_47cde0(app, cpu);
    }
    // 0047cd4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047cd51  3b4110                 +cmp eax, dword ptr [ecx + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047cd54  7f50                   -jg 0x47cda6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        return sub_47cda6(app, cpu);
    }
    // 0047cd56  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cd5a  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047cd5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cd60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cd68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd68  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cd69  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cd6e  e849bdffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 0047cd73  e8b0ffffff             -call 0x47cd28
    cpu.esp -= 4;
    sub_47cd28(app, cpu);
    if (cpu.terminate) return;
    // 0047cd78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47cd7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cd7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cd7f  e838bdffff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 0047cd84  e89fffffff             -call 0x47cd28
    cpu.esp -= 4;
    sub_47cd28(app, cpu);
    if (cpu.terminate) return;
    // 0047cd89  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47cd8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cd8d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047cd92  e891ffffff             -call 0x47cd28
    cpu.esp -= 4;
    sub_47cd28(app, cpu);
    if (cpu.terminate) return;
    // 0047cd97  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cd98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47cd9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cd9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cd9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047cd9f  e884ffffff             -call 0x47cd28
    cpu.esp -= 4;
    sub_47cd28(app, cpu);
    if (cpu.terminate) return;
    // 0047cda4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cda5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cda6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cda6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047cda9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047cdab  e8d4420100             -call 0x491084
    cpu.esp -= 4;
    sub_491084(app, cpu);
    if (cpu.terminate) return;
    // 0047cdb0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047cdb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cdb4  74a7                   -je 0x47cd5d
    if (cpu.flags.zf)
    {
        return sub_47cd5d(app, cpu);
    }
    // 0047cdb6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047cdb8  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047cdbb  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047cdbd  e88e390000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0047cdc2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047cdc4  e81f430100             -call 0x4910e8
    cpu.esp -= 4;
    sub_4910e8(app, cpu);
    if (cpu.terminate) return;
    // 0047cdc9  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0047cdcb  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047cdce  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047cdd1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cdd5  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047cdd8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cddb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cddc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cdde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cde0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cde2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047cde5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047cde7  bbb0b55100             -mov ebx, 0x51b5b0
    cpu.ebx = 5354928 /*0x51b5b0*/;
    // 0047cdec  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047cdef  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047cdf1  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0047cdf6  e855680100             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 0047cdfb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047cdfe  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047ce00  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047ce03  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ce05  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ce08  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ce0a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ce0d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ce0f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ce13  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047ce15  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047ce17  21cf                   -and edi, ecx
    cpu.edi &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ce19  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047ce1b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ce1f  21c1                   -and ecx, eax
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ce21  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047ce23  7c37                   -jl 0x47ce5c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ce5c;
    }
L_0x0047ce25:
    // 0047ce25  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047ce27:
    // 0047ce27  39f9                   +cmp ecx, edi
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
    // 0047ce29  7f4c                   -jg 0x47ce77
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ce77;
    }
    // 0047ce2b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ce2d  7c48                   -jl 0x47ce77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ce77;
    }
    // 0047ce2f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ce33  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047ce36  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047ce39  837b1400               +cmp dword ptr [ebx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ce3d  7407                   -je 0x47ce46
    if (cpu.flags.zf)
    {
        goto L_0x0047ce46;
    }
    // 0047ce3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ce41  e85a680100             -call 0x4936a0
    cpu.esp -= 4;
    sub_4936a0(app, cpu);
    if (cpu.terminate) return;
L_0x0047ce46:
    // 0047ce46  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0047ce4b  e808680100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0047ce50  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ce54  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ce57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ce5c:
    // 0047ce5c  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047ce5e  83fdff                 +cmp ebp, -1
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
    // 0047ce61  74c2                   -je 0x47ce25
    if (cpu.flags.zf)
    {
        goto L_0x0047ce25;
    }
    // 0047ce63  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0047ce68  e8eb670100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0047ce6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ce6f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ce72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ce76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ce77:
    // 0047ce77  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ce7e  740d                   -je 0x47ce8d
    if (cpu.flags.zf)
    {
        goto L_0x0047ce8d;
    }
    // 0047ce80  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047ce83  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0047ce87  7404                   -je 0x47ce8d
    if (cpu.flags.zf)
    {
        goto L_0x0047ce8d;
    }
    // 0047ce89  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047ce8b  742f                   -je 0x47cebc
    if (cpu.flags.zf)
    {
        goto L_0x0047cebc;
    }
L_0x0047ce8d:
    // 0047ce8d  833db8844c0000         +cmp dword ptr [0x4c84b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014712) /* 0x4c84b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ce94  7406                   -je 0x47ce9c
    if (cpu.flags.zf)
    {
        goto L_0x0047ce9c;
    }
    // 0047ce96  f6461810               +test byte ptr [esi + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0047ce9a  754d                   -jne 0x47cee9
    if (!cpu.flags.zf)
    {
        goto L_0x0047cee9;
    }
L_0x0047ce9c:
    // 0047ce9c  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0047cea1  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cea5  e8ae670100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0047ceaa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ceac  0f8cda000000           -jl 0x47cf8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047cf8c;
    }
    // 0047ceb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ceb4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ceb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ceba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cebb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cebc:
    // 0047cebc  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047cebe  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047cec1  e812690100             -call 0x4937d8
    cpu.esp -= 4;
    sub_4937d8(app, cpu);
    if (cpu.terminate) return;
    // 0047cec6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cec8  7415                   -je 0x47cedf
    if (cpu.flags.zf)
    {
        goto L_0x0047cedf;
    }
    // 0047ceca  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047cecd  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047cecf  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047ced2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ced4  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047ced6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ced8  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ceda  e948ffffff             -jmp 0x47ce27
    goto L_0x0047ce27;
L_0x0047cedf:
    // 0047cedf  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0047cee4  e93effffff             -jmp 0x47ce27
    goto L_0x0047ce27;
L_0x0047cee9:
    // 0047cee9  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047ceec  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047ceee  e8f5690100             -call 0x4938e8
    cpu.esp -= 4;
    sub_4938e8(app, cpu);
    if (cpu.terminate) return;
    // 0047cef3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cef5  7415                   -je 0x47cf0c
    if (cpu.flags.zf)
    {
        goto L_0x0047cf0c;
    }
    // 0047cef7  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047cefa  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047cefc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047cefe  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047cf00  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047cf03  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047cf05  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047cf07  e91bffffff             -jmp 0x47ce27
    goto L_0x0047ce27;
L_0x0047cf0c:
    // 0047cf0c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047cf10  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cf14  b8b0e14b00             -mov eax, 0x4be1b0
    cpu.eax = 4972976 /*0x4be1b0*/;
    // 0047cf19  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047cf1b  e8c0b7ffff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 0047cf20  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047cf22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cf24  0f8472ffffff           -je 0x47ce9c
    if (cpu.flags.zf)
    {
        goto L_0x0047ce9c;
    }
    // 0047cf2a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047cf2d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047cf2f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047cf31  e81a380000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0047cf36  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047cf39  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047cf3c  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047cf3f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047cf41  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047cf44  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047cf47  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0047cf4a  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047cf4d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047cf50  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0047cf53  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047cf55  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0047cf57  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047cf5a  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047cf5d  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 0047cf60  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047cf63  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047cf66  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047cf69  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047cf6c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047cf6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047cf71  e8c6bfffff             -call 0x478f3c
    cpu.esp -= 4;
    sub_478f3c(app, cpu);
    if (cpu.terminate) return;
    // 0047cf76  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0047cf7b  e8d8660100             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0047cf80  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047cf84  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cf87  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cf8c:
    // 0047cf8c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047cf8e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047cf91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cf95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47cf96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cf96  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cf97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cf98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cf99  2eff1548554b00         -call dword ptr cs:[0x4b5548]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937032) /* 0x4b5548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047cfa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047cfa2  7508                   -jne 0x47cfac
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfac;
    }
    // 0047cfa4  e8998b0100             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 0047cfa9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cfac:
    // 0047cfac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047cfae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfaf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47cfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047cfc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047cfc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cfc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047cfc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047cfc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047cfc5  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047cfcb  8b15ec884c00           -mov edx, dword ptr [0x4c88ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */);
    // 0047cfd1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047cfd3  83faff                 +cmp edx, -1
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
    // 0047cfd6  7409                   -je 0x47cfe1
    if (cpu.flags.zf)
    {
        goto L_0x0047cfe1;
    }
    // 0047cfd8  bf69b85100             -mov edi, 0x51b869
    cpu.edi = 5355625 /*0x51b869*/;
L_0x0047cfdd:
    // 0047cfdd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047cfdf  740e                   -je 0x47cfef
    if (cpu.flags.zf)
    {
        goto L_0x0047cfef;
    }
L_0x0047cfe1:
    // 0047cfe1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047cfe3  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047cfe9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfeb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047cfee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047cfef:
    // 0047cfef  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047cff1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047cff2  8b0dec884c00           -mov ecx, dword ptr [0x4c88ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */);
    // 0047cff8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047cff9  2eff1564544b00         -call dword ptr cs:[0x4b5464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936804) /* 0x4b5464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d002  743f                   -je 0x47d043
    if (cpu.flags.zf)
    {
        goto L_0x0047d043;
    }
    // 0047d004  8b1d60b75100           -mov ebx, dword ptr [0x51b760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355360) /* 0x51b760 */);
    // 0047d00a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047d00c  ba64b75100             -mov edx, 0x51b764
    cpu.edx = 5355364 /*0x51b764*/;
    // 0047d011  88a369b85100           -mov byte ptr [ebx + 0x51b869], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5355625) /* 0x51b869 */) = cpu.ah;
    // 0047d017  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047d019  e8ded3ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 0047d01e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047d023  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047d027  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047d029  e83d950100             -call 0x49656b
    cpu.esp -= 4;
    sub_49656b(app, cpu);
    if (cpu.terminate) return;
    // 0047d02e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d02f  2eff15b0544b00         -call dword ptr cs:[0x4b54b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936880) /* 0x4b54b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d036  83f8ff                 +cmp eax, -1
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
    // 0047d039  74a2                   -je 0x47cfdd
    if (cpu.flags.zf)
    {
        goto L_0x0047cfdd;
    }
    // 0047d03b  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047d03d  759e                   -jne 0x47cfdd
    if (!cpu.flags.zf)
    {
        goto L_0x0047cfdd;
    }
    // 0047d03f  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047d041  eb9a                   -jmp 0x47cfdd
    goto L_0x0047cfdd;
L_0x0047d043:
    // 0047d043  8b1dec884c00           -mov ebx, dword ptr [0x4c88ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */);
    // 0047d049  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d04a  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0047d04f  2eff155c544b00         -call dword ptr cs:[0x4b545c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936796) /* 0x4b545c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d056  8935ec884c00           -mov dword ptr [0x4c88ec], esi
    app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */) = cpu.esi;
    // 0047d05c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d05e  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047d064  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d065  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d066  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d06c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d06c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d06d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d06e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d06f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d070  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d071  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047d077  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d079  8b15ec884c00           -mov edx, dword ptr [0x4c88ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */);
    // 0047d07f  83faff                 +cmp edx, -1
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
    // 0047d082  0f856b000000           -jne 0x47d0f3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0f3;
    }
L_0x0047d088:
    // 0047d088  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047d08d  b864b75100             -mov eax, 0x51b764
    cpu.eax = 5355364 /*0x51b764*/;
    // 0047d092  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047d094  bf64b75100             -mov edi, 0x51b764
    cpu.edi = 5355364 /*0x51b764*/;
    // 0047d099  e85ed3ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 0047d09e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047d0a0  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d0a1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047d0a3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047d0a5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047d0a7  49                     -dec ecx
    (cpu.ecx)--;
    // 0047d0a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d0aa  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d0ac  7e15                   -jle 0x47d0c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d0c3;
    }
L_0x0047d0ae:
    // 0047d0ae  8a9064b75100           -mov dl, byte ptr [eax + 0x51b764]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355364) /* 0x51b764 */);
    // 0047d0b4  80fa5c                 +cmp dl, 0x5c
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
    // 0047d0b7  740a                   -je 0x47d0c3
    if (cpu.flags.zf)
    {
        goto L_0x0047d0c3;
    }
    // 0047d0b9  80fa3a                 +cmp dl, 0x3a
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
    // 0047d0bc  7405                   -je 0x47d0c3
    if (cpu.flags.zf)
    {
        goto L_0x0047d0c3;
    }
    // 0047d0be  48                     -dec eax
    (cpu.eax)--;
    // 0047d0bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0c1  7feb                   -jg 0x47d0ae
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047d0ae;
    }
L_0x0047d0c3:
    // 0047d0c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d0c5  7536                   -jne 0x47d0fd
    if (!cpu.flags.zf)
    {
        goto L_0x0047d0fd;
    }
L_0x0047d0c7:
    // 0047d0c7  a360b75100             -mov dword ptr [0x51b760], eax
    app->getMemory<x86::reg32>(x86::reg32(5355360) /* 0x51b760 */) = cpu.eax;
    // 0047d0cc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d0ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d0cf  6864b75100             -push 0x51b764
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355364 /*0x51b764*/;
    cpu.esp -= 4;
    // 0047d0d4  2eff1560544b00         -call dword ptr cs:[0x4b5460]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936800) /* 0x4b5460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d0db  a3ec884c00             -mov dword ptr [0x4c88ec], eax
    app->getMemory<x86::reg32>(x86::reg32(5015788) /* 0x4c88ec */) = cpu.eax;
    // 0047d0e0  83f8ff                 +cmp eax, -1
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
    // 0047d0e3  751b                   -jne 0x47d100
    if (!cpu.flags.zf)
    {
        goto L_0x0047d100;
    }
    // 0047d0e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d0e7  81c440010000           +add esp, 0x140
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
    // 0047d0ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d0f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d0f3:
    // 0047d0f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d0f4  2eff155c544b00         -call dword ptr cs:[0x4b545c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936796) /* 0x4b545c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d0fb  eb8b                   -jmp 0x47d088
    goto L_0x0047d088;
L_0x0047d0fd:
    // 0047d0fd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047d0fe  ebc7                   -jmp 0x47d0c7
    goto L_0x0047d0c7;
L_0x0047d100:
    // 0047d100  ba64b75100             -mov edx, 0x51b764
    cpu.edx = 5355364 /*0x51b764*/;
    // 0047d105  8b1d60b75100           -mov ebx, dword ptr [0x51b760]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355360) /* 0x51b760 */);
    // 0047d10b  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047d10d  b869b85100             -mov eax, 0x51b869
    cpu.eax = 5355625 /*0x51b869*/;
    // 0047d112  888b69b85100           -mov byte ptr [ebx + 0x51b869], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5355625) /* 0x51b869 */) = cpu.cl;
    // 0047d118  e8dfd2ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 0047d11d  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047d122  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047d126  b869b85100             -mov eax, 0x51b869
    cpu.eax = 5355625 /*0x51b869*/;
    // 0047d12b  e83b940100             -call 0x49656b
    cpu.esp -= 4;
    sub_49656b(app, cpu);
    if (cpu.terminate) return;
    // 0047d130  6869b85100             -push 0x51b869
    app->getMemory<x86::reg32>(cpu.esp-4) = 5355625 /*0x51b869*/;
    cpu.esp -= 4;
    // 0047d135  2eff15b0544b00         -call dword ptr cs:[0x4b54b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936880) /* 0x4b54b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d13c  83f8ff                 +cmp eax, -1
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
    // 0047d13f  7415                   -je 0x47d156
    if (cpu.flags.zf)
    {
        goto L_0x0047d156;
    }
    // 0047d141  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047d143  7511                   -jne 0x47d156
    if (!cpu.flags.zf)
    {
        goto L_0x0047d156;
    }
    // 0047d145  b869b85100             -mov eax, 0x51b869
    cpu.eax = 5355625 /*0x51b869*/;
    // 0047d14a  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047d150  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d151  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d152  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d153  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d154  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d155  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d156:
    // 0047d156  e865feffff             -call 0x47cfc0
    cpu.esp -= 4;
    sub_47cfc0(app, cpu);
    if (cpu.terminate) return;
    // 0047d15b  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047d161  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d162  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d165  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d166  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d173  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d176  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047d17a  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d17e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047d180  e897e3ffff             -call 0x47b51c
    cpu.esp -= 4;
    sub_47b51c(app, cpu);
    if (cpu.terminate) return;
    // 0047d185  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d188  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d18a  750a                   -jne 0x47d196
    if (!cpu.flags.zf)
    {
        goto L_0x0047d196;
    }
    // 0047d18c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d18f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d192  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d193  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d194  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d195  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d196:
    // 0047d196  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d198  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047d19d  e80ee5ffff             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0047d1a2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047d1a5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d1a8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d1ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d1ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47d1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d1b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d1b2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047d1b4  8b1d70b95100           -mov ebx, dword ptr [0x51b970]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */);
    // 0047d1ba  d1fa                   +sar edx, 1
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
    // 0047d1bc  e9301f0000             -jmp 0x47f0f1
    return sub_47f0f1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d1c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d1c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d1c6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047d1c8  8b1d70b95100           -mov ebx, dword ptr [0x51b970]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */);
    // 0047d1ce  e91e1f0000             -jmp 0x47f0f1
    return sub_47f0f1(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47d1d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d1d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d1d6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047d1d8  8b1d70b95100           -mov ebx, dword ptr [0x51b970]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */);
    // 0047d1de  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d1e0  e90c1f0000             -jmp 0x47f0f1
    return sub_47f0f1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d1e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d1e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d1e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d1ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047d1ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0047d1ee:
    // 0047d1ee  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047d1f3  8b1570b95100           -mov edx, dword ptr [0x51b970]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */);
    // 0047d1f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d1fb  e8ab8c0100             -call 0x495eab
    cpu.esp -= 4;
    sub_495eab(app, cpu);
    if (cpu.terminate) return;
    // 0047d200  83c103                 +add ecx, 3
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
    // 0047d203  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047d204  75e8                   -jne 0x47d1ee
    if (!cpu.flags.zf)
    {
        goto L_0x0047d1ee;
    }
    // 0047d206  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d207  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d208  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d20c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d20c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d20e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047d210  8b1d70b95100           -mov ebx, dword ptr [0x51b970]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */);
    // 0047d216  c1e202                 +shl edx, 2
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
    // 0047d219  e9d31e0000             -jmp 0x47f0f1
    return sub_47f0f1(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d220  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d221  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d222  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d223  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047d226  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d228  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047d22a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047d22e  8a15ec844c00           -mov dl, byte ptr [0x4c84ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 0047d234  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d237  735b                   -jae 0x47d294
    if (!cpu.flags.cf)
    {
        goto L_0x0047d294;
    }
    // 0047d239  80fa04                 +cmp dl, 4
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d23c  750a                   -jne 0x47d248
    if (!cpu.flags.zf)
    {
        goto L_0x0047d248;
    }
    // 0047d23e  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047d241  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d243  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x0047d246:
    // 0047d246  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047d248:
    // 0047d248  a370b95100             -mov dword ptr [0x51b970], eax
    app->getMemory<x86::reg32>(x86::reg32(5355888) /* 0x51b970 */) = cpu.eax;
    // 0047d24d  66895c2404             -mov word ptr [esp + 4], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 0047d252  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 0047d257  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047d259  b9f0884c00             -mov ecx, 0x4c88f0
    cpu.ecx = 5015792 /*0x4c88f0*/;
    // 0047d25e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d260  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 0047d263  a0ed844c00             -mov al, byte ptr [0x4c84ed]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0047d268  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d26b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d270  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047d272  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d274  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047d276  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047d278  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047d27b  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d281  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047d283  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047d286  e891590100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 0047d28b  83c414                 +add esp, 0x14
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
    // 0047d28e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d28f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d290  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d291  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d294:
    // 0047d294  7618                   -jbe 0x47d2ae
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d2ae;
    }
    // 0047d296  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d299  72ad                   -jb 0x47d248
    if (cpu.flags.cf)
    {
        goto L_0x0047d248;
    }
    // 0047d29b  7605                   -jbe 0x47d2a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d2a2;
    }
    // 0047d29d  80fa10                 +cmp dl, 0x10
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
    // 0047d2a0  75a6                   -jne 0x47d248
    if (!cpu.flags.zf)
    {
        goto L_0x0047d248;
    }
L_0x0047d2a2:
    // 0047d2a2  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047d2a7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d2a9  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047d2ac  eb98                   -jmp 0x47d246
    goto L_0x0047d246;
L_0x0047d2ae:
    // 0047d2ae  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d2b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d2b5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0047d2b8  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d2ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d2bc  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047d2bf  eb85                   -jmp 0x47d246
    goto L_0x0047d246;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d2d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d2d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d2d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d2d3  81ec24020000           -sub esp, 0x224
    (cpu.esp) -= x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047d2d9  8bb42434020000         -mov esi, dword ptr [esp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(564) /* 0x234 */);
    // 0047d2e0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0047d2e7  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 0047d2ee  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047d2f0  898c2420020000         -mov dword ptr [esp + 0x220], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ecx;
    // 0047d2f7  8bbc2410020000         -mov edi, dword ptr [esp + 0x210]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d2fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d300  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047d303  8994241c020000         -mov dword ptr [esp + 0x21c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.edx;
    // 0047d30a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d30d  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047d310  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 0047d317  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0047d31a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d31c  7457                   -je 0x47d375
    if (cpu.flags.zf)
    {
        goto L_0x0047d375;
    }
    // 0047d31e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d320  7453                   -je 0x47d375
    if (cpu.flags.zf)
    {
        goto L_0x0047d375;
    }
    // 0047d322  89942404020000         -mov dword ptr [esp + 0x204], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.edx;
    // 0047d329  8b942410020000         -mov edx, dword ptr [esp + 0x210]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d330  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d332  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047d334  a0ed844c00             -mov al, byte ptr [0x4c84ed]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0047d339  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047d33f  39c2                   +cmp edx, eax
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
    // 0047d341  753e                   -jne 0x47d381
    if (!cpu.flags.zf)
    {
        goto L_0x0047d381;
    }
L_0x0047d343:
    // 0047d343  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d34a  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 0047d350  0f8ca6000000           -jl 0x47d3fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d3fc;
    }
L_0x0047d356:
    // 0047d356  8b942404020000         -mov edx, dword ptr [esp + 0x204]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0047d35d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d35f  7407                   -je 0x47d368
    if (cpu.flags.zf)
    {
        goto L_0x0047d368;
    }
    // 0047d361  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d363  e864b7ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0047d368:
    // 0047d368  833d14824c0000         +cmp dword ptr [0x4c8214], 0
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
    // 0047d36f  0f85cb020000           -jne 0x47d640
    if (!cpu.flags.zf)
    {
        goto L_0x0047d640;
    }
L_0x0047d375:
    // 0047d375  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047d37b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d37c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d37d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d37e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d381:
    // 0047d381  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d388  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d38a  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047d38d  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0047d393  83f808                 +cmp eax, 8
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
    // 0047d396  7536                   -jne 0x47d3ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047d3ce;
    }
    // 0047d398  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
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
    // 0047d39f  752d                   -jne 0x47d3ce
    if (!cpu.flags.zf)
    {
        goto L_0x0047d3ce;
    }
    // 0047d3a1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047d3a3  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d3aa  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0047d3af  e86c510100             -call 0x492520
    cpu.esp -= 4;
    sub_492520(app, cpu);
    if (cpu.terminate) return;
    // 0047d3b4  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 0047d3b9  e892330000             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0047d3be  c784241c020000d0c54800 -mov dword ptr [esp + 0x21c], 0x48c5d0
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4769232 /*0x48c5d0*/;
    // 0047d3c9  e975ffffff             -jmp 0x47d343
    goto L_0x0047d343;
L_0x0047d3ce:
    // 0047d3ce  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047d3d3  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d3da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d3dc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047d3de  8a15ed844c00           -mov dl, byte ptr [0x4c84ed]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */);
    // 0047d3e4  e87f540100             -call 0x492868
    cpu.esp -= 4;
    sub_492868(app, cpu);
    if (cpu.terminate) return;
    // 0047d3e9  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 0047d3f0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0047d3f7  e947ffffff             -jmp 0x47d343
    goto L_0x0047d343;
L_0x0047d3fc:
    // 0047d3fc  3b2de8844c00           +cmp ebp, dword ptr [0x4c84e8]
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
    // 0047d402  0f8d4effffff           -jge 0x47d356
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d356;
    }
    // 0047d408  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d40f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d411  0f8ef2010000           -jle 0x47d609
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d609;
    }
    // 0047d417  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047d419:
    // 0047d419  8b94240c020000         -mov edx, dword ptr [esp + 0x20c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d420  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047d426  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047d428  39c8                   +cmp eax, ecx
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
    // 0047d42a  0f8e26ffffff           -jle 0x47d356
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d356;
    }
    // 0047d430  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d432  0f8eda010000           -jle 0x47d612
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d612;
    }
    // 0047d438  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047d43a:
    // 0047d43a  8b1de0844c00           -mov ebx, dword ptr [0x4c84e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047d440  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d442  39d8                   +cmp eax, ebx
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
    // 0047d444  0f8e0cffffff           -jle 0x47d356
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d356;
    }
    // 0047d44a  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d451  8b942408020000         -mov edx, dword ptr [esp + 0x208]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0047d458  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d45f  e84c910100             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0047d464  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d467  89842414020000         -mov dword ptr [esp + 0x214], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.eax;
    // 0047d46e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d470  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d473  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d475  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0047d478  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d47a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047d47c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047d47e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d481  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d483  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d485  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d488  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 0047d48f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d491  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047d493  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047d495  0f8c80010000           -jl 0x47d61b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d61b;
    }
    // 0047d49b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047d49d:
    // 0047d49d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d49f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d4a1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d4a4  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d4a6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047d4a8  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d4af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d4b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d4b3  0f8c6b010000           -jl 0x47d624
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d624;
    }
L_0x0047d4b9:
    // 0047d4b9  8b1de0844c00           -mov ebx, dword ptr [0x4c84e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 0047d4bf  39dd                   +cmp ebp, ebx
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
    // 0047d4c1  7d14                   -jge 0x47d4d7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d4d7;
    }
    // 0047d4c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d4c5  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d4c7  8bac2418020000         -mov ebp, dword ptr [esp + 0x218]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0047d4ce  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047d4d1  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d4d3  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d4d5  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0047d4d7:
    // 0047d4d7  8b1de8844c00           -mov ebx, dword ptr [0x4c84e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0047d4dd  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0047d4e0  39d8                   +cmp eax, ebx
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
    // 0047d4e2  7e04                   -jle 0x47d4e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d4e8;
    }
    // 0047d4e4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047d4e6  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047d4e8:
    // 0047d4e8  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d4ef  8b1ddc844c00           -mov ebx, dword ptr [0x4c84dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047d4f5  39d8                   +cmp eax, ebx
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
    // 0047d4f7  7d2c                   -jge 0x47d525
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d525;
    }
    // 0047d4f9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d4fb  2b84240c020000         -sub eax, dword ptr [esp + 0x20c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */)));
    // 0047d502  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047d504  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047d507  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d509  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d510  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d512  a1dc844c00             -mov eax, dword ptr [0x4c84dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 0047d517  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 0047d51e  8984240c020000         -mov dword ptr [esp + 0x20c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.eax;
L_0x0047d525:
    // 0047d525  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d52c  03842420020000         -add eax, dword ptr [esp + 0x220]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */)));
    // 0047d533  8b1de4844c00           -mov ebx, dword ptr [0x4c84e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0047d539  39d8                   +cmp eax, ebx
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
    // 0047d53b  7e12                   -jle 0x47d54f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d54f;
    }
    // 0047d53d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d53f  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d546  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d548  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0047d54f:
    // 0047d54f  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0047d554  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047d557  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d559  8bac240c020000         -mov ebp, dword ptr [esp + 0x20c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d560  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0047d567  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0047d56c  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047d56f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047d571  8bac2400020000         -mov ebp, dword ptr [esp + 0x200]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0047d578  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047d57a  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047d57d  8b84241c020000         -mov eax, dword ptr [esp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 0047d584  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d586  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d588  750b                   -jne 0x47d595
    if (!cpu.flags.zf)
    {
        goto L_0x0047d595;
    }
    // 0047d58a  c784241c02000022c14800 -mov dword ptr [esp + 0x21c], 0x48c122
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4768034 /*0x48c122*/;
L_0x0047d595:
    // 0047d595  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d597  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d59e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d59f  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047d5a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d5a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047d5a9  b86c8a5200             -mov eax, 0x528a6c
    cpu.eax = 5409388 /*0x528a6c*/;
    // 0047d5ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d5b0  e85b9b0100             -call 0x497110
    cpu.esp -= 4;
    sub_497110(app, cpu);
    if (cpu.terminate) return;
    // 0047d5b5  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047d5bc  ba6c8a5200             -mov edx, 0x528a6c
    cpu.edx = 5409388 /*0x528a6c*/;
    // 0047d5c1  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047d5c4  e847eb0000             -call 0x48c110
    cpu.esp -= 4;
    sub_48c110(app, cpu);
    if (cpu.terminate) return;
L_0x0047d5c9:
    // 0047d5c9  4e                     -dec esi
    (cpu.esi)--;
    // 0047d5ca  83feff                 +cmp esi, -1
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
    // 0047d5cd  0f8483fdffff           -je 0x47d356
    if (cpu.flags.zf)
    {
        goto L_0x0047d356;
    }
    // 0047d5d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047d5d5  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0047d5dc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d5df  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047d5e2  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047d5e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d5ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d5eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d5ec  ff942428020000         -call dword ptr [esp + 0x228]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d5f3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047d5f6  8b1df8844c00           -mov ebx, dword ptr [0x4c84f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 0047d5fc  8b842418020000         -mov eax, dword ptr [esp + 0x218]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0047d603  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d605  01c7                   +add edi, eax
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
    // 0047d607  ebc0                   -jmp 0x47d5c9
    goto L_0x0047d5c9;
L_0x0047d609:
    // 0047d609  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d60b  f7d8                   +neg eax
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
    // 0047d60d  e907feffff             -jmp 0x47d419
    goto L_0x0047d419;
L_0x0047d612:
    // 0047d612  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d614  f7d8                   +neg eax
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
    // 0047d616  e91ffeffff             -jmp 0x47d43a
    goto L_0x0047d43a;
L_0x0047d61b:
    // 0047d61b  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0047d61d  01c7                   +add edi, eax
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
    // 0047d61f  e979feffff             -jmp 0x47d49d
    goto L_0x0047d49d;
L_0x0047d624:
    // 0047d624  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d626  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047d628  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
    // 0047d62f  8b842408020000         -mov eax, dword ptr [esp + 0x208]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0047d636  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047d639  01c2                   +add edx, eax
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
    // 0047d63b  e979feffff             -jmp 0x47d4b9
    goto L_0x0047d4b9;
L_0x0047d640:
    // 0047d640  0f77                   -emms 
    cpu.mmx.init();
    // 0047d642  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047d648  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d649  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d64b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d650  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d651  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d652  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d653  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047d656  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d658  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047d65a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047d65d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047d65f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047d662  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d665  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d667  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047d66b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d66e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d672  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d674  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d677  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d679  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047d67c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047d680  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047d683  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d686  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d688  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d68a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047d68d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047d68f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047d691  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d693  7d50                   -jge 0x47d6e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d6e5;
    }
    // 0047d695  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047d698  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047d69c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047d69f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d6a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d6a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d6a5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047d6a7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d6aa  c1e810                 +shr eax, 0x10
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
    // 0047d6ad  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047d6af  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047d6b1:
    // 0047d6b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047d6b3  7c46                   -jl 0x47d6fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047d6fb;
    }
    // 0047d6b5  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047d6b8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d6ba  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047d6bd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d6c0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047d6c2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d6c5  c1e810                 +shr eax, 0x10
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
    // 0047d6c8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047d6ca  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047d6cc:
    // 0047d6cc  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047d6d0  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047d6d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d6d3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047d6d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d6d7  e8f4fbffff             -call 0x47d2d0
    cpu.esp -= 4;
    sub_47d2d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d6dc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047d6df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d6e2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047d6e5:
    // 0047d6e5  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047d6e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d6ea  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047d6ed  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047d6ef  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d6f2  c1e810                 +shr eax, 0x10
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
    // 0047d6f5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047d6f7  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047d6f9  ebb6                   -jmp 0x47d6b1
    goto L_0x0047d6b1;
L_0x0047d6fb:
    // 0047d6fb  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047d6fe  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047d701  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047d704  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047d707  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d709  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047d70b  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047d70e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047d710  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047d713  c1e810                 +shr eax, 0x10
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
    // 0047d716  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047d718  01c3                   +add ebx, eax
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
    // 0047d71a  ebb0                   -jmp 0x47d6cc
    goto L_0x0047d6cc;
}

/* align: skip  */
void Application::sub_47d71c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d71c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d71d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d71e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d71f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047d721  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047d724  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047d727  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0047d72a  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047d72d  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0047d730  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047d733  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047d735  e896fbffff             -call 0x47d2d0
    cpu.esp -= 4;
    sub_47d2d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d73a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d73c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d740  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d741  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d742  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047d744  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047d746  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d74a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d74c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d74d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d74f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d751  e87afbffff             -call 0x47d2d0
    cpu.esp -= 4;
    sub_47d2d0(app, cpu);
    if (cpu.terminate) return;
    // 0047d756  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d757  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d758  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d75c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d75c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d75d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d75e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047d760  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047d762  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047d766  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047d768  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d769  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d76b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047d76d  e8defeffff             -call 0x47d650
    cpu.esp -= 4;
    sub_47d650(app, cpu);
    if (cpu.terminate) return;
    // 0047d772  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d774  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d778  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d779  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047d77b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047d77d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d77f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d781  e896ffffff             -call 0x47d71c
    cpu.esp -= 4;
    sub_47d71c(app, cpu);
    if (cpu.terminate) return;
    // 0047d786  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47d790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d790  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d791  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047d793  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d798  e86b180000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047d79d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047d79f  7423                   -je 0x47d7c4
    if (cpu.flags.zf)
    {
        goto L_0x0047d7c4;
    }
    // 0047d7a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d7a2  e8b94e0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047d7a7  8b0d84ba5100           -mov ecx, dword ptr [0x51ba84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356164) /* 0x51ba84 */);
    // 0047d7ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d7af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d7b1  ff15408d4c00           -call dword ptr [0x4c8d40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016896) /* 0x4c8d40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d7b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7b8  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d7bd  e85e180000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047d7c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d7c4:
    // 0047d7c4  ff15448d4c00           -call dword ptr [0x4c8d44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016900) /* 0x4c8d44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d7ca  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d7cf  e84c180000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047d7d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d7d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d7d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d7d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d7da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d7db  833d288d4c0000         +cmp dword ptr [0x4c8d28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d7e2  7406                   -je 0x47d7ea
    if (cpu.flags.zf)
    {
        goto L_0x0047d7ea;
    }
    // 0047d7e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d7e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d7e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d7ea:
    // 0047d7ea  68b8e14b00             -push 0x4be1b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972984 /*0x4be1b8*/;
    cpu.esp -= 4;
    // 0047d7ef  2eff1514554b00         -call dword ptr cs:[0x4b5514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936980) /* 0x4b5514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d7f6  a3288d4c00             -mov dword ptr [0x4c8d28], eax
    app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */) = cpu.eax;
    // 0047d7fb  83f820                 +cmp eax, 0x20
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
    // 0047d7fe  7d10                   -jge 0x47d810
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047d810;
    }
    // 0047d800  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d802  a3288d4c00             -mov dword ptr [0x4c8d28], eax
    app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */) = cpu.eax;
    // 0047d807  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047d80c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d80d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d80e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d80f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d810:
    // 0047d810  68c4e14b00             -push 0x4be1c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4972996 /*0x4be1c4*/;
    cpu.esp -= 4;
    // 0047d815  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047d816  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d81d  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d81f  3d02000600             +cmp eax, 0x60002
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(393218 /*0x60002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d824  7409                   -je 0x47d82f
    if (cpu.flags.zf)
    {
        goto L_0x0047d82f;
    }
    // 0047d826  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047d82b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d82e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d82f:
    // 0047d82f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d830  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d831  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d832  68d4e14b00             -push 0x4be1d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973012 /*0x4be1d4*/;
    cpu.esp -= 4;
    // 0047d837  8b0d288d4c00           -mov ecx, dword ptr [0x4c8d28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d83d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d83e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d840  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d847  68e1354900             -push 0x4935e1
    app->getMemory<x86::reg32>(cpu.esp-4) = 4797921 /*0x4935e1*/;
    cpu.esp -= 4;
    // 0047d84c  8b0d80ab4c00           -mov ecx, dword ptr [0x4cab80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024640) /* 0x4cab80 */);
    // 0047d852  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d854  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047d856  b85c7f4900             -mov eax, 0x497f5c
    cpu.eax = 4816732 /*0x497f5c*/;
    // 0047d85b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d85d  68ece14b00             -push 0x4be1ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973036 /*0x4be1ec*/;
    cpu.esp -= 4;
    // 0047d862  8b1d288d4c00           -mov ebx, dword ptr [0x4c8d28]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d868  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d869  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d870  68fce14b00             -push 0x4be1fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973052 /*0x4be1fc*/;
    cpu.esp -= 4;
    // 0047d875  8b35288d4c00           -mov esi, dword ptr [0x4c8d28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d87b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d87c  a33c8d4c00             -mov dword ptr [0x4c8d3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5016892) /* 0x4c8d3c */) = cpu.eax;
    // 0047d881  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d888  6810e24b00             -push 0x4be210
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973072 /*0x4be210*/;
    cpu.esp -= 4;
    // 0047d88d  8b3d288d4c00           -mov edi, dword ptr [0x4c8d28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d893  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d894  a3408d4c00             -mov dword ptr [0x4c8d40], eax
    app->getMemory<x86::reg32>(x86::reg32(5016896) /* 0x4c8d40 */) = cpu.eax;
    // 0047d899  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d8a0  6820e24b00             -push 0x4be220
    app->getMemory<x86::reg32>(cpu.esp-4) = 4973088 /*0x4be220*/;
    cpu.esp -= 4;
    // 0047d8a5  8b2d288d4c00           -mov ebp, dword ptr [0x4c8d28]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d8ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047d8ac  a3448d4c00             -mov dword ptr [0x4c8d44], eax
    app->getMemory<x86::reg32>(x86::reg32(5016900) /* 0x4c8d44 */) = cpu.eax;
    // 0047d8b1  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d8b8  a3488d4c00             -mov dword ptr [0x4c8d48], eax
    app->getMemory<x86::reg32>(x86::reg32(5016904) /* 0x4c8d48 */) = cpu.eax;
    // 0047d8bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d8c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d8c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d8c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d8c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d8ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d8cb  8b15288d4c00           -mov edx, dword ptr [0x4c8d28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */);
    // 0047d8d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047d8d3  750e                   -jne 0x47d8e3
    if (!cpu.flags.zf)
    {
        goto L_0x0047d8e3;
    }
    // 0047d8d5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d8d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d8d9  891d288d4c00           -mov dword ptr [0x4c8d28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */) = cpu.ebx;
    // 0047d8df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d8e3:
    // 0047d8e3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d8e4  2eff156c544b00         -call dword ptr cs:[0x4b546c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936812) /* 0x4b546c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d8eb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047d8ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d8ef  891d288d4c00           -mov dword ptr [0x4c8d28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5016872) /* 0x4c8d28 */) = cpu.ebx;
    // 0047d8f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d8f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47d8fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d8fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d8fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d8fe  e8d5feffff             -call 0x47d7d8
    cpu.esp -= 4;
    sub_47d7d8(app, cpu);
    if (cpu.terminate) return;
    // 0047d903  e8584d0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047d908  ff153c8d4c00           -call dword ptr [0x4c8d3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016892) /* 0x4c8d3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d90e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d910  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047d912  7e06                   -jle 0x47d91a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047d91a;
    }
    // 0047d914  81ca00000100           -or edx, 0x10000
    cpu.edx |= x86::reg32(x86::sreg32(65536 /*0x10000*/));
L_0x0047d91a:
    // 0047d91a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047d91c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d91d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d91e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d920  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d922  be2c8d4c00             -mov esi, 0x4c8d2c
    cpu.esi = 5016876 /*0x4c8d2c*/;
    // 0047d927  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047d929  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d92b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d92c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d92d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d92e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d92f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d930  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d931  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d934  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047d935  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047d936  bf2c8d4c00             -mov edi, 0x4c8d2c
    cpu.edi = 5016876 /*0x4c8d2c*/;
    // 0047d93b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047d93d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d93e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d93f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d940  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047d941  803d328d4c0010         +cmp byte ptr [0x4c8d32], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016882) /* 0x4c8d32 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d948  7608                   -jbe 0x47d952
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047d952;
    }
    // 0047d94a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047d94f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d950  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d951  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d952:
    // 0047d952  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d955  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d956  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d958  a3248d4c00             -mov dword ptr [0x4c8d24], eax
    app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */) = cpu.eax;
    // 0047d95d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d95f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d960  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d967  7506                   -jne 0x47d96f
    if (!cpu.flags.zf)
    {
        goto L_0x0047d96f;
    }
    // 0047d969  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047d96e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d96f:
    // 0047d96f  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d974  e88f160000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047d979  ff15448d4c00           -call dword ptr [0x4c8d44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016900) /* 0x4c8d44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d97f  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d984  e897160000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047d989  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d98b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47d98c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d98c  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d993  7506                   -jne 0x47d99b
    if (!cpu.flags.zf)
    {
        goto L_0x0047d99b;
    }
    // 0047d995  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047d99a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047d99b:
    // 0047d99b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047d99c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047d99d  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d9a2  e861160000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047d9a7  e8b44c0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047d9ac  8b0d84ba5100           -mov ecx, dword ptr [0x51ba84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5356164) /* 0x51ba84 */);
    // 0047d9b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047d9b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047d9b6  ff15408d4c00           -call dword ptr [0x4c8d40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016896) /* 0x4c8d40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d9bc  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d9c1  e85a160000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047d9c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047d9c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047d9ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47d9cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d9cc  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d9d1  e832160000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047d9d6  ff15488d4c00           -call dword ptr [0x4c8d48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016904) /* 0x4c8d48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047d9dc  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0047d9e1  e93a160000             -jmp 0x47f020
    return sub_47f020(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47d9e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047d9e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047d9e9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047d9ec  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047d9f1  7443                   -je 0x47da36
    if (cpu.flags.zf)
    {
        goto L_0x0047da36;
    }
    // 0047d9f3  803d188d4c0000         +cmp byte ptr [0x4c8d18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047d9fa  0f8588010000           -jne 0x47db88
    if (!cpu.flags.zf)
    {
        goto L_0x0047db88;
    }
L_0x0047da00:
    // 0047da00  803d198d4c0000         +cmp byte ptr [0x4c8d19], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047da07  740f                   -je 0x47da18
    if (cpu.flags.zf)
    {
        goto L_0x0047da18;
    }
    // 0047da09  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047da0b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0047da0d  e8ae86ffff             -call 0x4760c0
    cpu.esp -= 4;
    sub_4760c0(app, cpu);
    if (cpu.terminate) return;
    // 0047da12  881d198d4c00           -mov byte ptr [0x4c8d19], bl
    app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */) = cpu.bl;
L_0x0047da18:
    // 0047da18  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047da1a  ff15448d4c00           -call dword ptr [0x4c8d44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016900) /* 0x4c8d44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047da20:
    // 0047da20  890d1c8d4c00           -mov dword ptr [0x4c8d1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */) = cpu.ecx;
L_0x0047da26:
    // 0047da26  c6051b8d4c0001         -mov byte ptr [0x4c8d1b], 1
    app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */) = 1 /*0x1*/;
    // 0047da2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047da2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047da32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047da33  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047da36:
    // 0047da36  a180ba5100             -mov eax, dword ptr [0x51ba80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356160) /* 0x51ba80 */);
    // 0047da3b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047da3e  e81d4c0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047da43  ff153c8d4c00           -call dword ptr [0x4c8d3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016892) /* 0x4c8d3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047da49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047da4b  0f8eb8000000           -jle 0x47db09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047db09;
    }
    // 0047da51  8a7c2401               -mov bh, byte ptr [esp + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0047da55  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0047da58  0f84c0000000           -je 0x47db1e
    if (cpu.flags.zf)
    {
        goto L_0x0047db1e;
    }
    // 0047da5e  c705208d4c0022560000   -mov dword ptr [0x4c8d20], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 22050 /*0x5622*/;
L_0x0047da68:
    // 0047da68  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047da6b  8a151a8d4c00           -mov dl, byte ptr [0x4c8d1a]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5016858) /* 0x4c8d1a */);
    // 0047da71  a384ba5100             -mov dword ptr [0x51ba84], eax
    app->getMemory<x86::reg32>(x86::reg32(5356164) /* 0x51ba84 */) = cpu.eax;
    // 0047da76  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047da78  7512                   -jne 0x47da8c
    if (!cpu.flags.zf)
    {
        goto L_0x0047da8c;
    }
    // 0047da7a  b880b64800             -mov eax, 0x48b680
    cpu.eax = 4765312 /*0x48b680*/;
    // 0047da7f  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 0047da81  e896db0000             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 0047da86  88351a8d4c00           -mov byte ptr [0x4c8d1a], dh
    app->getMemory<x86::reg8>(x86::reg32(5016858) /* 0x4c8d1a */) = cpu.dh;
L_0x0047da8c:
    // 0047da8c  ba084c4900             -mov edx, 0x494c08
    cpu.edx = 4803592 /*0x494c08*/;
    // 0047da91  a184ba5100             -mov eax, dword ptr [0x51ba84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356164) /* 0x51ba84 */);
    // 0047da96  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0047da9b  e828980100             -call 0x4972c8
    cpu.esp -= 4;
    sub_4972c8(app, cpu);
    if (cpu.terminate) return;
    // 0047daa0  8b15f0835200           -mov edx, dword ptr [0x5283f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407728) /* 0x5283f0 */);
    // 0047daa6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047daa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047daaa  e8ed000000             -call 0x47db9c
    cpu.esp -= 4;
    sub_47db9c(app, cpu);
    if (cpu.terminate) return;
    // 0047daaf  e8ac4b0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047dab4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047dab6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047dab9  ff15408d4c00           -call dword ptr [0x4c8d40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5016896) /* 0x4c8d40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047dabf  a31c8d4c00             -mov dword ptr [0x4c8d1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */) = cpu.eax;
    // 0047dac4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dac6  0f8c5affffff           -jl 0x47da26
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047da26;
    }
    // 0047dacc  803d188d4c0000         +cmp byte ptr [0x4c8d18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dad3  7512                   -jne 0x47dae7
    if (!cpu.flags.zf)
    {
        goto L_0x0047dae7;
    }
    // 0047dad5  b8ccd94700             -mov eax, 0x47d9cc
    cpu.eax = 4708812 /*0x47d9cc*/;
    // 0047dada  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 0047dadc  e8bb9fffff             -call 0x477a9c
    cpu.esp -= 4;
    sub_477a9c(app, cpu);
    if (cpu.terminate) return;
    // 0047dae1  883d188d4c00           -mov byte ptr [0x4c8d18], bh
    app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */) = cpu.bh;
L_0x0047dae7:
    // 0047dae7  803d198d4c0000         +cmp byte ptr [0x4c8d19], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047daee  7512                   -jne 0x47db02
    if (!cpu.flags.zf)
    {
        goto L_0x0047db02;
    }
    // 0047daf0  b890d74700             -mov eax, 0x47d790
    cpu.eax = 4708240 /*0x47d790*/;
    // 0047daf5  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0047daf7  e8c485ffff             -call 0x4760c0
    cpu.esp -= 4;
    sub_4760c0(app, cpu);
    if (cpu.terminate) return;
    // 0047dafc  882d198d4c00           -mov byte ptr [0x4c8d19], ch
    app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */) = cpu.ch;
L_0x0047db02:
    // 0047db02  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047db04  e917ffffff             -jmp 0x47da20
    goto L_0x0047da20;
L_0x0047db09:
    // 0047db09  a31c8d4c00             -mov dword ptr [0x4c8d1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */) = cpu.eax;
    // 0047db0e  c6051b8d4c0001         -mov byte ptr [0x4c8d1b], 1
    app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */) = 1 /*0x1*/;
    // 0047db15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047db17  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047db1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db1b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047db1e:
    // 0047db1e  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0047db21  740f                   -je 0x47db32
    if (cpu.flags.zf)
    {
        goto L_0x0047db32;
    }
    // 0047db23  c705208d4c00803e0000   -mov dword ptr [0x4c8d20], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 16000 /*0x3e80*/;
    // 0047db2d  e936ffffff             -jmp 0x47da68
    goto L_0x0047da68;
L_0x0047db32:
    // 0047db32  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 0047db35  740f                   -je 0x47db46
    if (cpu.flags.zf)
    {
        goto L_0x0047db46;
    }
    // 0047db37  c705208d4c00007d0000   -mov dword ptr [0x4c8d20], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 32000 /*0x7d00*/;
    // 0047db41  e922ffffff             -jmp 0x47da68
    goto L_0x0047da68;
L_0x0047db46:
    // 0047db46  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 0047db49  740f                   -je 0x47db5a
    if (cpu.flags.zf)
    {
        goto L_0x0047db5a;
    }
    // 0047db4b  c705208d4c0044ac0000   -mov dword ptr [0x4c8d20], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 44100 /*0xac44*/;
    // 0047db55  e90effffff             -jmp 0x47da68
    goto L_0x0047da68;
L_0x0047db5a:
    // 0047db5a  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 0047db5d  740f                   -je 0x47db6e
    if (cpu.flags.zf)
    {
        goto L_0x0047db6e;
    }
    // 0047db5f  c705208d4c00112b0000   -mov dword ptr [0x4c8d20], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 11025 /*0x2b11*/;
    // 0047db69  e9fafeffff             -jmp 0x47da68
    goto L_0x0047da68;
L_0x0047db6e:
    // 0047db6e  c7051c8d4c00f8ffffff   -mov dword ptr [0x4c8d1c], 0xfffffff8
    app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */) = 4294967288 /*0xfffffff8*/;
    // 0047db78  c6051b8d4c0001         -mov byte ptr [0x4c8d1b], 1
    app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */) = 1 /*0x1*/;
    // 0047db7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047db81  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047db84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047db85  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047db88:
    // 0047db88  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047db8a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047db8c  8815188d4c00           -mov byte ptr [0x4c8d18], dl
    app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */) = cpu.dl;
    // 0047db92  e8059fffff             -call 0x477a9c
    cpu.esp -= 4;
    sub_477a9c(app, cpu);
    if (cpu.terminate) return;
    // 0047db97  e964feffff             -jmp 0x47da00
    goto L_0x0047da00;
}

/* align: skip  */
void Application::sub_47db9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047db9c  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047db9f  7316                   -jae 0x47dbb7
    if (!cpu.flags.cf)
    {
        goto L_0x0047dbb7;
    }
    // 0047dba1  83fa0a                 +cmp edx, 0xa
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
    // 0047dba4  720e                   -jb 0x47dbb4
    if (cpu.flags.cf)
    {
        goto L_0x0047dbb4;
    }
    // 0047dba6  761b                   -jbe 0x47dbc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dba8  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbab  7207                   -jb 0x47dbb4
    if (cpu.flags.cf)
    {
        goto L_0x0047dbb4;
    }
    // 0047dbad  7614                   -jbe 0x47dbc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dbaf  83fa1e                 +cmp edx, 0x1e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbb2  740f                   -je 0x47dbc3
    if (cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
L_0x0047dbb4:
    // 0047dbb4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047dbb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dbb7:
    // 0047dbb7  760a                   -jbe 0x47dbc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dbb9  83fa64                 +cmp edx, 0x64
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
    // 0047dbbc  7312                   -jae 0x47dbd0
    if (!cpu.flags.cf)
    {
        goto L_0x0047dbd0;
    }
    // 0047dbbe  83fa32                 +cmp edx, 0x32
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
    // 0047dbc1  75f1                   -jne 0x47dbb4
    if (!cpu.flags.zf)
    {
        goto L_0x0047dbb4;
    }
L_0x0047dbc3:
    // 0047dbc3  a1208d4c00             -mov eax, dword ptr [0x4c8d20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */);
    // 0047dbc8  e82fa40100             -call 0x497ffc
    cpu.esp -= 4;
    sub_497ffc(app, cpu);
    if (cpu.terminate) return;
    // 0047dbcd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047dbcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dbd0:
    // 0047dbd0  76f1                   -jbe 0x47dbc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dbd2  83fa6e                 +cmp edx, 0x6e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbd5  72dd                   -jb 0x47dbb4
    if (cpu.flags.cf)
    {
        goto L_0x0047dbb4;
    }
    // 0047dbd7  76ea                   -jbe 0x47dbc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dbd9  83fa78                 +cmp edx, 0x78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dbdc  74e5                   -je 0x47dbc3
    if (cpu.flags.zf)
    {
        goto L_0x0047dbc3;
    }
    // 0047dbde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbe0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47dbe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dbe4  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dbeb  75af                   -jne 0x47db9c
    if (!cpu.flags.zf)
    {
        return sub_47db9c(app, cpu);
    }
    // 0047dbed  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047dbf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047dbf0;
    // 0047dbe4  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dbeb  75af                   -jne 0x47db9c
    if (!cpu.flags.zf)
    {
        return sub_47db9c(app, cpu);
    }
    // 0047dbed  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0047dbf0:
    // 0047dbf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dbf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47dbf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dbf4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dbf5  a380ba5100             -mov dword ptr [0x51ba80], eax
    app->getMemory<x86::reg32>(x86::reg32(5356160) /* 0x51ba80 */) = cpu.eax;
    // 0047dbfa  e8d9fbffff             -call 0x47d7d8
    cpu.esp -= 4;
    sub_47d7d8(app, cpu);
    if (cpu.terminate) return;
    // 0047dbff  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dc06  7507                   -jne 0x47dc0f
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc0f;
    }
L_0x0047dc08:
    // 0047dc08  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0047dc0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dc0f:
    // 0047dc0f  e84c4a0000             -call 0x482660
    cpu.esp -= 4;
    sub_482660(app, cpu);
    if (cpu.terminate) return;
    // 0047dc14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc16  74f0                   -je 0x47dc08
    if (cpu.flags.zf)
    {
        goto L_0x0047dc08;
    }
    // 0047dc18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dc19  68e8d94700             -push 0x47d9e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4708840 /*0x47d9e8*/;
    cpu.esp -= 4;
    // 0047dc1e  6800820000             -push 0x8200
    app->getMemory<x86::reg32>(cpu.esp-4) = 33280 /*0x8200*/;
    cpu.esp -= 4;
    // 0047dc23  e83885ffff             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 0047dc28  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047dc2a  88251b8d4c00           -mov byte ptr [0x4c8d1b], ah
    app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */) = cpu.ah;
    // 0047dc30  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 0047dc35  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dc37  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dc39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dc3b  e89084ffff             -call 0x4760d0
    cpu.esp -= 4;
    sub_4760d0(app, cpu);
    if (cpu.terminate) return;
    // 0047dc40  803d1b8d4c0000         +cmp byte ptr [0x4c8d1b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc47  7513                   -jne 0x47dc5c
    if (!cpu.flags.zf)
    {
        goto L_0x0047dc5c;
    }
    // 0047dc49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047dc4b:
    // 0047dc4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047dc4d  e80a100000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0047dc52  3a151b8d4c00           +cmp dl, byte ptr [0x4c8d1b]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc58  74f1                   -je 0x47dc4b
    if (cpu.flags.zf)
    {
        goto L_0x0047dc4b;
    }
    // 0047dc5a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047dc5c:
    // 0047dc5c  a11c8d4c00             -mov eax, dword ptr [0x4c8d1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */);
    // 0047dc61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47dc64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dc64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dc65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dc66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dc67  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047dc69  88251b8d4c00           -mov byte ptr [0x4c8d1b], ah
    app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */) = cpu.ah;
    // 0047dc6f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047dc74  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 0047dc79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047dc7b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dc7d  e84e84ffff             -call 0x4760d0
    cpu.esp -= 4;
    sub_4760d0(app, cpu);
    if (cpu.terminate) return;
    // 0047dc82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dc84  7420                   -je 0x47dca6
    if (cpu.flags.zf)
    {
        goto L_0x0047dca6;
    }
L_0x0047dc86:
    // 0047dc86  803d1b8d4c0000         +cmp byte ptr [0x4c8d1b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016859) /* 0x4c8d1b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dc8d  740e                   -je 0x47dc9d
    if (cpu.flags.zf)
    {
        goto L_0x0047dc9d;
    }
    // 0047dc8f  e834fcffff             -call 0x47d8c8
    cpu.esp -= 4;
    sub_47d8c8(app, cpu);
    if (cpu.terminate) return;
    // 0047dc94  a11c8d4c00             -mov eax, dword ptr [0x4c8d1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */);
    // 0047dc99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dc9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dc9d:
    // 0047dc9d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047dc9f  e8b80f0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0047dca4  ebe0                   -jmp 0x47dc86
    goto L_0x0047dc86;
L_0x0047dca6:
    // 0047dca6  803d188d4c0000         +cmp byte ptr [0x4c8d18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dcad  740d                   -je 0x47dcbc
    if (cpu.flags.zf)
    {
        goto L_0x0047dcbc;
    }
    // 0047dcaf  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047dcb1  8835188d4c00           -mov byte ptr [0x4c8d18], dh
    app->getMemory<x86::reg8>(x86::reg32(5016856) /* 0x4c8d18 */) = cpu.dh;
    // 0047dcb7  e8e09dffff             -call 0x477a9c
    cpu.esp -= 4;
    sub_477a9c(app, cpu);
    if (cpu.terminate) return;
L_0x0047dcbc:
    // 0047dcbc  803d198d4c0000         +cmp byte ptr [0x4c8d19], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dcc3  740f                   -je 0x47dcd4
    if (cpu.flags.zf)
    {
        goto L_0x0047dcd4;
    }
    // 0047dcc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047dcc7  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0047dcc9  e8f283ffff             -call 0x4760c0
    cpu.esp -= 4;
    sub_4760c0(app, cpu);
    if (cpu.terminate) return;
    // 0047dcce  883d198d4c00           -mov byte ptr [0x4c8d19], bh
    app->getMemory<x86::reg8>(x86::reg32(5016857) /* 0x4c8d19 */) = cpu.bh;
L_0x0047dcd4:
    // 0047dcd4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047dcd6  89151c8d4c00           -mov dword ptr [0x4c8d1c], edx
    app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */) = cpu.edx;
    // 0047dcdc  e8e7fbffff             -call 0x47d8c8
    cpu.esp -= 4;
    sub_47d8c8(app, cpu);
    if (cpu.terminate) return;
    // 0047dce1  a11c8d4c00             -mov eax, dword ptr [0x4c8d1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016860) /* 0x4c8d1c */);
    // 0047dce6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dce7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dce8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dce9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47dcec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dcec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dced  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047dcef  e86cfcffff             -call 0x47d960
    cpu.esp -= 4;
    sub_47d960(app, cpu);
    if (cpu.terminate) return;
    // 0047dcf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dcf6  7c5b                   -jl 0x47dd53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dd53;
    }
    // 0047dcf8  890d84ba5100           -mov dword ptr [0x51ba84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5356164) /* 0x51ba84 */) = cpu.ecx;
    // 0047dcfe  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 0047dd01  7552                   -jne 0x47dd55
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd55;
    }
    // 0047dd03  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047dd06  7459                   -je 0x47dd61
    if (cpu.flags.zf)
    {
        goto L_0x0047dd61;
    }
    // 0047dd08  c705208d4c00803e0000   -mov dword ptr [0x4c8d20], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 16000 /*0x3e80*/;
L_0x0047dd12:
    // 0047dd12  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047dd14  e807980100             -call 0x497520
    cpu.esp -= 4;
    sub_497520(app, cpu);
    if (cpu.terminate) return;
    // 0047dd19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047dd1b  7c36                   -jl 0x47dd53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dd53;
    }
    // 0047dd1d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047dd1e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dd20  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047dd22:
    // 0047dd22  80b90c84520001         +cmp byte ptr [ecx + 0x52840c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5407756) /* 0x52840c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047dd29  7519                   -jne 0x47dd44
    if (!cpu.flags.zf)
    {
        goto L_0x0047dd44;
    }
    // 0047dd2b  83b90084520000         +cmp dword ptr [ecx + 0x528400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5407744) /* 0x528400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dd32  7c10                   -jl 0x47dd44
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dd44;
    }
    // 0047dd34  8b9110845200           -mov edx, dword ptr [ecx + 0x528410]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5407760) /* 0x528410 */);
    // 0047dd3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047dd3c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047dd3f  e80c0a0000             -call 0x47e750
    cpu.esp -= 4;
    sub_47e750(app, cpu);
    if (cpu.terminate) return;
L_0x0047dd44:
    // 0047dd44  43                     -inc ebx
    (cpu.ebx)++;
    // 0047dd45  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047dd48  83fb10                 +cmp ebx, 0x10
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
    // 0047dd4b  7cd5                   -jl 0x47dd22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047dd22;
    }
    // 0047dd4d  e83afcffff             -call 0x47d98c
    cpu.esp -= 4;
    sub_47d98c(app, cpu);
    if (cpu.terminate) return;
    // 0047dd52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047dd53:
    // 0047dd53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd54  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047dd55:
    // 0047dd55  c705208d4c0022560000   -mov dword ptr [0x4c8d20], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 22050 /*0x5622*/;
    // 0047dd5f  ebb1                   -jmp 0x47dd12
    goto L_0x0047dd12;
L_0x0047dd61:
    // 0047dd61  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0047dd64  740c                   -je 0x47dd72
    if (cpu.flags.zf)
    {
        goto L_0x0047dd72;
    }
    // 0047dd66  c705208d4c00007d0000   -mov dword ptr [0x4c8d20], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 32000 /*0x7d00*/;
    // 0047dd70  eba0                   -jmp 0x47dd12
    goto L_0x0047dd12;
L_0x0047dd72:
    // 0047dd72  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0047dd75  740c                   -je 0x47dd83
    if (cpu.flags.zf)
    {
        goto L_0x0047dd83;
    }
    // 0047dd77  c705208d4c0044ac0000   -mov dword ptr [0x4c8d20], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 44100 /*0xac44*/;
    // 0047dd81  eb8f                   -jmp 0x47dd12
    goto L_0x0047dd12;
L_0x0047dd83:
    // 0047dd83  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 0047dd86  740f                   -je 0x47dd97
    if (cpu.flags.zf)
    {
        goto L_0x0047dd97;
    }
    // 0047dd88  c705208d4c00112b0000   -mov dword ptr [0x4c8d20], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */) = 11025 /*0x2b11*/;
    // 0047dd92  e97bffffff             -jmp 0x47dd12
    goto L_0x0047dd12;
L_0x0047dd97:
    // 0047dd97  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047dd9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047dd9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47dda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047dda0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047dda2  7409                   -je 0x47ddad
    if (cpu.flags.zf)
    {
        goto L_0x0047ddad;
    }
    // 0047dda4  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047dda7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047ddac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ddad:
    // 0047ddad  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047ddb0  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047ddb3  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047ddb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ddbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ddbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ddbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ddbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ddbf  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047ddc2  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047ddc6  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047ddc8  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047ddcc  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047ddd0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047ddd2  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047ddd5  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047ddd7  888a85b95100           -mov byte ptr [edx + 0x51b985], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5355909) /* 0x51b985 */) = cpu.cl;
    // 0047dddd  c68286b9510001         -mov byte ptr [edx + 0x51b986], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5355910) /* 0x51b986 */) = 1 /*0x1*/;
    // 0047dde4  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0047dde6  66898a8ab95100         -mov word ptr [edx + 0x51b98a], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5355914) /* 0x51b98a */) = cpu.cx;
    // 0047dded  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ddef  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ddf1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ddf3  81fa544d706c           +cmp edx, 0x6c704d54
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1819299156 /*0x6c704d54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ddf9  0f85fa000000           -jne 0x47def9
    if (!cpu.flags.zf)
    {
        goto L_0x0047def9;
    }
    // 0047ddff  80780400               +cmp byte ptr [eax + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047de03  0f85fe000000           -jne 0x47df07
    if (!cpu.flags.zf)
    {
        goto L_0x0047df07;
    }
    // 0047de09  80780510               +cmp byte ptr [eax + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047de0d  0f8502010000           -jne 0x47df15
    if (!cpu.flags.zf)
    {
        goto L_0x0047df15;
    }
    // 0047de13  80780601               +cmp byte ptr [eax + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047de17  0f85f8000000           -jne 0x47df15
    if (!cpu.flags.zf)
    {
        goto L_0x0047df15;
    }
    // 0047de1d  c744241c04000000       -mov dword ptr [esp + 0x1c], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 4 /*0x4*/;
L_0x0047de25:
    // 0047de25  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047de2a  0f8530010000           -jne 0x47df60
    if (!cpu.flags.zf)
    {
        goto L_0x0047df60;
    }
    // 0047de30  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047de32  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047de37  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0047de3b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047de3f  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047de43:
    // 0047de43  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047de45  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047de48  668b560a               -mov dx, word ptr [esi + 0xa]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0047de4c  66899080b95100         -mov word ptr [eax + 0x51b980], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5355904) /* 0x51b980 */) = cpu.dx;
    // 0047de53  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0047de56  889082b95100           -mov byte ptr [eax + 0x51b982], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355906) /* 0x51b982 */) = cpu.dl;
    // 0047de5c  8a5606                 -mov dl, byte ptr [esi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047de5f  889083b95100           -mov byte ptr [eax + 0x51b983], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355907) /* 0x51b983 */) = cpu.dl;
    // 0047de65  8a5607                 -mov dl, byte ptr [esi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 0047de68  889084b95100           -mov byte ptr [eax + 0x51b984], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355908) /* 0x51b984 */) = cpu.dl;
    // 0047de6e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047de72  89908cb95100           -mov dword ptr [eax + 0x51b98c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5355916) /* 0x51b98c */) = cpu.edx;
    // 0047de78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047de7a  8b15208d4c00           -mov edx, dword ptr [0x4c8d20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */);
    // 0047de80  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0047de84  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047de88  e833a20100             -call 0x4980c0
    cpu.esp -= 4;
    sub_4980c0(app, cpu);
    if (cpu.terminate) return;
    // 0047de8d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047de8f  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047de93  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047de97  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047de9b  e860a20100             -call 0x498100
    cpu.esp -= 4;
    sub_498100(app, cpu);
    if (cpu.terminate) return;
    // 0047dea0  033d248d4c00           -add edi, dword ptr [0x4c8d24]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */)));
    // 0047dea6  83ff64                 +cmp edi, 0x64
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047dea9  0f8eef000000           -jle 0x47df9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047df9e;
    }
    // 0047deaf  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x0047deb4:
    // 0047deb4  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047deb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047deb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047deba  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047debe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047debf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047dec3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047dec4  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047dec8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047dec9  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047decd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047dece  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047ded2  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ded6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ded7  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0047deda  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047dede  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dedf  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047dee3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047dee5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047dee6  8a5e07                 -mov bl, byte ptr [esi + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 0047dee9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047deeb  e8fc960100             -call 0x4975ec
    cpu.esp -= 4;
    sub_4975ec(app, cpu);
    if (cpu.terminate) return;
    // 0047def0  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047def3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047def4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047def5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047def6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047def9:
    // 0047def9  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047defe  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047df01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df04  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047df07:
    // 0047df07  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047df0c  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047df0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047df12  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047df15:
    // 0047df15  807e0510               +cmp byte ptr [esi + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df19  7513                   -jne 0x47df2e
    if (!cpu.flags.zf)
    {
        goto L_0x0047df2e;
    }
    // 0047df1b  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df1f  750d                   -jne 0x47df2e
    if (!cpu.flags.zf)
    {
        goto L_0x0047df2e;
    }
    // 0047df21  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
    // 0047df29  e9f7feffff             -jmp 0x47de25
    goto L_0x0047de25;
L_0x0047df2e:
    // 0047df2e  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df32  7513                   -jne 0x47df47
    if (!cpu.flags.zf)
    {
        goto L_0x0047df47;
    }
    // 0047df34  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df38  750d                   -jne 0x47df47
    if (!cpu.flags.zf)
    {
        goto L_0x0047df47;
    }
    // 0047df3a  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 0047df42  e9defeffff             -jmp 0x47de25
    goto L_0x0047de25;
L_0x0047df47:
    // 0047df47  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df4b  75ac                   -jne 0x47def9
    if (!cpu.flags.zf)
    {
        goto L_0x0047def9;
    }
    // 0047df4d  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047df51  75a6                   -jne 0x47def9
    if (!cpu.flags.zf)
    {
        goto L_0x0047def9;
    }
    // 0047df53  c744241c02000000       -mov dword ptr [esp + 0x1c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 0047df5b  e9c5feffff             -jmp 0x47de25
    goto L_0x0047de25;
L_0x0047df60:
    // 0047df60  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047df63  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047df67  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047df6a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047df6e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047df71  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047df75  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047df79  83faff                 +cmp edx, -1
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
    // 0047df7c  7d08                   -jge 0x47df86
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047df86;
    }
    // 0047df7e  c7442418ffffffff       -mov dword ptr [esp + 0x18], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 4294967295 /*0xffffffff*/;
L_0x0047df86:
    // 0047df86  837c2420ff             +cmp dword ptr [esp + 0x20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047df8b  0f8db2feffff           -jge 0x47de43
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047de43;
    }
    // 0047df91  c7442420ffffffff       -mov dword ptr [esp + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 0047df99  e9a5feffff             -jmp 0x47de43
    goto L_0x0047de43;
L_0x0047df9e:
    // 0047df9e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047dfa0  0f8d0effffff           -jge 0x47deb4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047deb4;
    }
    // 0047dfa6  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047dfa8  e907ffffff             -jmp 0x47deb4
    goto L_0x0047deb4;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47dff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047dff8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047dff9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047dffa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047dffb  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047dffe  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047e000  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047e004  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047e008  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047e00d  bd22560000             -mov ebp, 0x5622
    cpu.ebp = 22050 /*0x5622*/;
    // 0047e012  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047e017  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e019  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e01d  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047e021  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047e025  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047e029  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0047e02d  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0047e031  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0047e035  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0047e038  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047e03d  81c780b95100           -add edi, 0x51b980
    (cpu.edi) += x86::reg32(x86::sreg32(5355904 /*0x51b980*/));
    // 0047e043  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e045  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047e049  c6470500               -mov byte ptr [edi + 5], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 0047e04d  8a542458               -mov dl, byte ptr [esp + 0x58]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047e051  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e053  885706                 -mov byte ptr [edi + 6], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047e056  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047e05a  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047e05e  6689570a               -mov word ptr [edi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0047e062  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e064  754f                   -jne 0x47e0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0b5;
    }
L_0x0047e066:
    // 0047e066  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 0047e068  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e06b  0f840f010000           -je 0x47e180
    if (cpu.flags.zf)
    {
        goto L_0x0047e180;
    }
    // 0047e071  80fcfe                 +cmp ah, 0xfe
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e074  0f8406010000           -je 0x47e180
    if (cpu.flags.zf)
    {
        goto L_0x0047e180;
    }
    // 0047e07a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e07c  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0047e07e  46                     -inc esi
    (cpu.esi)++;
    // 0047e07f  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e085  74df                   -je 0x47e066
    if (cpu.flags.zf)
    {
        goto L_0x0047e066;
    }
    // 0047e087  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e089  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0047e08b  81f9ff000000           +cmp ecx, 0xff
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
    // 0047e091  7512                   -jne 0x47e0a5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0a5;
    }
    // 0047e093  46                     -inc esi
    (cpu.esi)++;
    // 0047e094  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047e099  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e09b  e890a00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e0a0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e0a2  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047e0a5:
    // 0047e0a5  8d837fffffff           -lea eax, [ebx - 0x81]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-129) /* -0x81 */);
    // 0047e0ab  46                     -inc esi
    (cpu.esi)++;
    // 0047e0ac  83f811                 +cmp eax, 0x11
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e0af  7612                   -jbe 0x47e0c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047e0c3;
    }
  [[fallthrough]];
  case 0x0047e0b1:
    // 0047e0b1  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0b3  ebb1                   -jmp 0x47e066
    goto L_0x0047e066;
L_0x0047e0b5:
    // 0047e0b5  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e0ba  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e0c0  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0047e0c3:
    // 0047e0c3  ff2485b0df4700         -jmp dword ptr [eax*4 + 0x47dfb0]
    cpu.ip = app->getMemory<x86::reg32>(4710320 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047e0ca:
    // 0047e0ca  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e0cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e0ce  e85da00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e0d3  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0047e0d7  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0d9  eb8b                   -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e0db:
    // 0047e0db  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0047e0df  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0e1  eb83                   -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e0e3:
    // 0047e0e3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e0e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e0e7  e844a00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e0ec  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047e0f0  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e0f2  e96fffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e0f7:
    // 0047e0f7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e0f9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e0fb  e830a00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e100  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047e104  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e106  e95bffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e10b:
    // 0047e10b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e10d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e10f  e81ca00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e114  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047e118  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e11a  e947ffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e11f:
    // 0047e11f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e121  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e123  e808a00100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e128  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047e12c  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e12e  e933ffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e133:
    // 0047e133  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e135  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e137  e8f49f0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e13c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047e140  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e142  e91fffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e147:
    // 0047e147  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e149  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e14b  e8e09f0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e150  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047e154  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e156  e90bffffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e15b:
    // 0047e15b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e15d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e15f  e8cc9f0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e164  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047e166  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e168  e9f9feffff             -jmp 0x47e066
    goto L_0x0047e066;
  case 0x0047e16d:
    // 0047e16d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e16f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e171  e8ba9f0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e176  884705                 -mov byte ptr [edi + 5], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 0047e179  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e17b  e9e6feffff             -jmp 0x47e066
    goto L_0x0047e066;
L_0x0047e180:
    // 0047e180  837c241402             +cmp dword ptr [esp + 0x14], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e185  0f85e4000000           -jne 0x47e26f
    if (!cpu.flags.zf)
    {
        goto L_0x0047e26f;
    }
    // 0047e18b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e18d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047e192  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047e196  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047e19a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0047e19e:
    // 0047e19e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e1a2  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0047e1a5  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047e1a9  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047e1ac  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e1b0  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047e1b3  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047e1b7  884704                 -mov byte ptr [edi + 4], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0047e1ba  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047e1be  8a7705                 -mov dh, byte ptr [edi + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047e1c1  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047e1c4  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0047e1c6  0f85e2000000           -jne 0x47e2ae
    if (!cpu.flags.zf)
    {
        goto L_0x0047e2ae;
    }
    // 0047e1cc  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e1d1  0f84bf000000           -je 0x47e296
    if (cpu.flags.zf)
    {
        goto L_0x0047e296;
    }
    // 0047e1d7  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e1db  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e1dd  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047e1e1  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047e1e5  e8169f0100             -call 0x498100
    cpu.esp -= 4;
    sub_498100(app, cpu);
    if (cpu.terminate) return;
L_0x0047e1ea:
    // 0047e1ea  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e1ef  0f851d010000           -jne 0x47e312
    if (!cpu.flags.zf)
    {
        goto L_0x0047e312;
    }
    // 0047e1f5  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e1fa  0f8512010000           -jne 0x47e312
    if (!cpu.flags.zf)
    {
        goto L_0x0047e312;
    }
    // 0047e200  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
L_0x0047e205:
    // 0047e205  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047e209  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e20d  8b15208d4c00           -mov edx, dword ptr [0x4c8d20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */);
    // 0047e213  e8a89e0100             -call 0x4980c0
    cpu.esp -= 4;
    sub_4980c0(app, cpu);
    if (cpu.terminate) return;
    // 0047e218  032d248d4c00           -add ebp, dword ptr [0x4c8d24]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */)));
    // 0047e21e  83fd64                 +cmp ebp, 0x64
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e221  0f8e39010000           -jle 0x47e360
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e360;
    }
    // 0047e227  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
L_0x0047e22c:
    // 0047e22c  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047e230  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e231  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e232  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e233  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047e237  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e238  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047e23c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e23d  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047e241  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e242  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047e246  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e247  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047e24b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047e24f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e250  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047e252  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047e254  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047e258  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e259  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047e25d  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047e261  e886930100             -call 0x4975ec
    cpu.esp -= 4;
    sub_4975ec(app, cpu);
    if (cpu.terminate) return;
    // 0047e266  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047e269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e26a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e26b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e26c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0047e26f:
    // 0047e26f  837c2424ff             +cmp dword ptr [esp + 0x24], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e274  7d08                   -jge 0x47e27e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e27e;
    }
    // 0047e276  c7442424ffffffff       -mov dword ptr [esp + 0x24], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 4294967295 /*0xffffffff*/;
L_0x0047e27e:
    // 0047e27e  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e283  0f8d15ffffff           -jge 0x47e19e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e19e;
    }
    // 0047e289  c7442428ffffffff       -mov dword ptr [esp + 0x28], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4294967295 /*0xffffffff*/;
    // 0047e291  e908ffffff             -jmp 0x47e19e
    goto L_0x0047e19e;
L_0x0047e296:
    // 0047e296  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e29a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e29c  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047e2a0  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047e2a4  e827aa0100             -call 0x498cd0
    cpu.esp -= 4;
    sub_498cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047e2a9  e93cffffff             -jmp 0x47e1ea
    goto L_0x0047e1ea;
L_0x0047e2ae:
    // 0047e2ae  80fe01                 +cmp dh, 1
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e2b1  0f85fefdffff           -jne 0x47e0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0b5;
    }
    // 0047e2b7  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e2bc  0f85f3fdffff           -jne 0x47e0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0b5;
    }
    // 0047e2c2  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e2c7  7414                   -je 0x47e2dd
    if (cpu.flags.zf)
    {
        goto L_0x0047e2dd;
    }
    // 0047e2c9  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047e2cd  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047e2d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e2d2  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0047e2d6  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0047e2d9  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
L_0x0047e2dd:
    // 0047e2dd  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0047e2e0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047e2e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e2e4  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047e2e7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e2eb  c1f818                 +sar eax, 0x18
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
    // 0047e2ee  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e2f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e2f3  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047e2f7  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047e2fb  e800aa0100             -call 0x498d00
    cpu.esp -= 4;
    sub_498d00(app, cpu);
    if (cpu.terminate) return;
    // 0047e300  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047e303  884708                 -mov byte ptr [edi + 8], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0047e306  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e30a  884709                 -mov byte ptr [edi + 9], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0047e30d  e9d8feffff             -jmp 0x47e1ea
    goto L_0x0047e1ea;
L_0x0047e312:
    // 0047e312  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e317  7511                   -jne 0x47e32a
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32a;
    }
    // 0047e319  837c240c02             +cmp dword ptr [esp + 0xc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e31e  750a                   -jne 0x47e32a
    if (!cpu.flags.zf)
    {
        goto L_0x0047e32a;
    }
    // 0047e320  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0047e325  e9dbfeffff             -jmp 0x47e205
    goto L_0x0047e205;
L_0x0047e32a:
    // 0047e32a  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e32f  7510                   -jne 0x47e341
    if (!cpu.flags.zf)
    {
        goto L_0x0047e341;
    }
    // 0047e331  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e335  83ff01                 +cmp edi, 1
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
    // 0047e338  7507                   -jne 0x47e341
    if (!cpu.flags.zf)
    {
        goto L_0x0047e341;
    }
    // 0047e33a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047e33c  e9c4feffff             -jmp 0x47e205
    goto L_0x0047e205;
L_0x0047e341:
    // 0047e341  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e346  0f8569fdffff           -jne 0x47e0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0b5;
    }
    // 0047e34c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e350  83fa02                 +cmp edx, 2
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
    // 0047e353  0f855cfdffff           -jne 0x47e0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047e0b5;
    }
    // 0047e359  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047e35b  e9a5feffff             -jmp 0x47e205
    goto L_0x0047e205;
L_0x0047e360:
    // 0047e360  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047e362  0f8dc4feffff           -jge 0x47e22c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e22c;
    }
    // 0047e368  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047e36a  e9bdfeffff             -jmp 0x47e22c
    goto L_0x0047e22c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_47e370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e371  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e372  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e373  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e374  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e377  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e379  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047e37d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047e382  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 0047e384  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047e386  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e388  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047e38b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e38e  7418                   -je 0x47e3a8
    if (cpu.flags.zf)
    {
        goto L_0x0047e3a8;
    }
L_0x0047e390:
    // 0047e390  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e392  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e395  7411                   -je 0x47e3a8
    if (cpu.flags.zf)
    {
        goto L_0x0047e3a8;
    }
    // 0047e397  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0047e39a  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e39b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3a1  751a                   -jne 0x47e3bd
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3bd;
    }
L_0x0047e3a3:
    // 0047e3a3  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e3a6  75e8                   -jne 0x47e390
    if (!cpu.flags.zf)
    {
        goto L_0x0047e390;
    }
L_0x0047e3a8:
    // 0047e3a8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e3ac  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047e3ae  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047e3b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e3b4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e3b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3bb  90                     -nop 
    ;
    // 0047e3bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e3bd:
    // 0047e3bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3bf  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e3c1  81fbff000000           +cmp ebx, 0xff
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
    // 0047e3c7  7512                   -jne 0x47e3db
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3db;
    }
    // 0047e3c9  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e3ca  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047e3cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e3d1  e85a9d0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e3d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e3d8  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047e3db:
    // 0047e3db  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e3dc  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3e2  7c13                   -jl 0x47e3f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e3f7;
    }
    // 0047e3e4  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3ea  750f                   -jne 0x47e3fb
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3fb;
    }
    // 0047e3ec  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047e3ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e3f0  e83b9d0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e3f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047e3f7:
    // 0047e3f7  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e3f9  eba8                   -jmp 0x47e3a3
    goto L_0x0047e3a3;
L_0x0047e3fb:
    // 0047e3fb  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e401  75f4                   -jne 0x47e3f7
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3f7;
    }
    // 0047e403  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047e405  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e407  eb9a                   -jmp 0x47e3a3
    goto L_0x0047e3a3;
}

/* align: skip  */
void Application::sub_47e3bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047e3bc;
    // 0047e370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e371  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e372  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e373  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e374  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e377  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e379  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047e37d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047e382  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 0047e384  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047e386  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e388  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047e38b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e38e  7418                   -je 0x47e3a8
    if (cpu.flags.zf)
    {
        goto L_0x0047e3a8;
    }
L_0x0047e390:
    // 0047e390  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e392  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e395  7411                   -je 0x47e3a8
    if (cpu.flags.zf)
    {
        goto L_0x0047e3a8;
    }
    // 0047e397  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0047e39a  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e39b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3a1  751a                   -jne 0x47e3bd
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3bd;
    }
L_0x0047e3a3:
    // 0047e3a3  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e3a6  75e8                   -jne 0x47e390
    if (!cpu.flags.zf)
    {
        goto L_0x0047e390;
    }
L_0x0047e3a8:
    // 0047e3a8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e3ac  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047e3ae  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047e3b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e3b4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e3b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e3bb  90                     -nop 
    ;
L_entry_0x0047e3bc:
    // 0047e3bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e3bd:
    // 0047e3bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e3bf  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047e3c1  81fbff000000           +cmp ebx, 0xff
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
    // 0047e3c7  7512                   -jne 0x47e3db
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3db;
    }
    // 0047e3c9  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e3ca  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047e3cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e3d1  e85a9d0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e3d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047e3d8  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047e3db:
    // 0047e3db  41                     -inc ecx
    (cpu.ecx)++;
    // 0047e3dc  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3e2  7c13                   -jl 0x47e3f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e3f7;
    }
    // 0047e3e4  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e3ea  750f                   -jne 0x47e3fb
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3fb;
    }
    // 0047e3ec  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047e3ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e3f0  e83b9d0100             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 0047e3f5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047e3f7:
    // 0047e3f7  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e3f9  eba8                   -jmp 0x47e3a3
    goto L_0x0047e3a3;
L_0x0047e3fb:
    // 0047e3fb  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e401  75f4                   -jne 0x47e3f7
    if (!cpu.flags.zf)
    {
        goto L_0x0047e3f7;
    }
    // 0047e403  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047e405  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047e407  eb9a                   -jmp 0x47e3a3
    goto L_0x0047e3a3;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e40c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e40c  e93f970100             -jmp 0x497b50
    return sub_497b50(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e414(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e414  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e415  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e416  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e417  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e418  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e41b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047e41d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e41f  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047e421  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0047e423  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0047e426  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047e428  889686b95100           -mov byte ptr [esi + 0x51b986], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5355910) /* 0x51b986 */) = cpu.dl;
    // 0047e42e  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0047e435  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e437  8a9e85b95100           -mov bl, byte ptr [esi + 0x51b985]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e43d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047e440  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047e442  745c                   -je 0x47e4a0
    if (cpu.flags.zf)
    {
        goto L_0x0047e4a0;
    }
    // 0047e444  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e447  756d                   -jne 0x47e4b6
    if (!cpu.flags.zf)
    {
        goto L_0x0047e4b6;
    }
    // 0047e449  8b8e86b95100           -mov ecx, dword ptr [esi + 0x51b986]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5355910) /* 0x51b986 */);
    // 0047e44f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e451  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0047e454  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047e457  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e458  8b8e85b95100           -mov ecx, dword ptr [esi + 0x51b985]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e45e  8b922e845200           -mov edx, dword ptr [edx + 0x52842e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407790) /* 0x52842e */);
    // 0047e464  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0047e467  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047e46a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e46b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047e46e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e472  e889a80100             -call 0x498d00
    cpu.esp -= 4;
    sub_498d00(app, cpu);
    if (cpu.terminate) return;
    // 0047e477  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047e47a  888688b95100           -mov byte ptr [esi + 0x51b988], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5355912) /* 0x51b988 */) = cpu.al;
    // 0047e480  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e484  888689b95100           -mov byte ptr [esi + 0x51b989], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5355913) /* 0x51b989 */) = cpu.al;
L_0x0047e48a:
    // 0047e48a  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e48e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e491  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e493  e858960100             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 0047e498  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e49b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e49c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e49d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e49e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e49f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e4a0:
    // 0047e4a0  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e4a4  8b922e845200           -mov edx, dword ptr [edx + 0x52842e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407790) /* 0x52842e */);
    // 0047e4aa  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e4ac  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047e4af  e84c9c0100             -call 0x498100
    cpu.esp -= 4;
    sub_498100(app, cpu);
    if (cpu.terminate) return;
    // 0047e4b4  ebd4                   -jmp 0x47e48a
    goto L_0x0047e48a;
L_0x0047e4b6:
    // 0047e4b6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e4bb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e4be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e4c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47e4c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e4c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e4c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e4c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e4c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e4c8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e4cb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047e4cd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047e4cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e4d1  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0047e4d4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e4d7  81c680b95100           -add esi, 0x51b980
    (cpu.esi) += x86::reg32(x86::sreg32(5355904 /*0x51b980*/));
    // 0047e4dd  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047e4df  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0047e4e3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047e4e6  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0047e4e9  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0047e4ed  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e4f0  7430                   -je 0x47e522
    if (cpu.flags.zf)
    {
        goto L_0x0047e522;
    }
    // 0047e4f2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047e4f4  7561                   -jne 0x47e557
    if (!cpu.flags.zf)
    {
        goto L_0x0047e557;
    }
    // 0047e4f6  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e4fa  8b902e845200           -mov edx, dword ptr [eax + 0x52842e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407790) /* 0x52842e */);
    // 0047e500  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e502  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047e505  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e507  e8c4a70100             -call 0x498cd0
    cpu.esp -= 4;
    sub_498cd0(app, cpu);
    if (cpu.terminate) return;
L_0x0047e50c:
    // 0047e50c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e510  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e513  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047e515  e8d6950100             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 0047e51a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e51d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e51e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e51f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e520  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e521  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e522:
    // 0047e522  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047e525  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047e528  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e529  8b5605                 -mov edx, dword ptr [esi + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0047e52c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047e52f  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e533  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e534  8b902e845200           -mov edx, dword ptr [eax + 0x52842e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407790) /* 0x52842e */);
    // 0047e53a  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e53e  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047e541  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e543  e8b8a70100             -call 0x498d00
    cpu.esp -= 4;
    sub_498d00(app, cpu);
    if (cpu.terminate) return;
    // 0047e548  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047e54b  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0047e54e  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e552  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0047e555  ebb5                   -jmp 0x47e50c
    goto L_0x0047e50c;
L_0x0047e557:
    // 0047e557  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e55c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e55f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e560  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e561  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e562  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e563  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47e564(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e564  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e565  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e566  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e567  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047e568  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e56b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047e56d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e56f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e572  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0047e575  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e577  8a9985b95100           -mov bl, byte ptr [ecx + 0x51b985]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e57d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047e580  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047e582  7549                   -jne 0x47e5cd
    if (!cpu.flags.zf)
    {
        goto L_0x0047e5cd;
    }
    // 0047e584  80b986b9510000         +cmp byte ptr [ecx + 0x51b986], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5355910) /* 0x51b986 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e58b  742a                   -je 0x47e5b7
    if (cpu.flags.zf)
    {
        goto L_0x0047e5b7;
    }
    // 0047e58d  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e591  8b800c845200           -mov eax, dword ptr [eax + 0x52840c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407756) /* 0x52840c */);
    // 0047e597  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e599  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047e59c  e85f9b0100             -call 0x498100
    cpu.esp -= 4;
    sub_498100(app, cpu);
    if (cpu.terminate) return;
L_0x0047e5a1:
    // 0047e5a1  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e5a5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047e5a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e5aa  e841950100             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 0047e5af  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e5b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e5b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e5b7:
    // 0047e5b7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047e5b9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047e5bb  668b818ab95100         -mov ax, word ptr [ecx + 0x51b98a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5355914) /* 0x51b98a */);
    // 0047e5c2  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e5c6  e805a70100             -call 0x498cd0
    cpu.esp -= 4;
    sub_498cd0(app, cpu);
    if (cpu.terminate) return;
    // 0047e5cb  ebd4                   -jmp 0x47e5a1
    goto L_0x0047e5a1;
L_0x0047e5cd:
    // 0047e5cd  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e5d0  755b                   -jne 0x47e62d
    if (!cpu.flags.zf)
    {
        goto L_0x0047e62d;
    }
    // 0047e5d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e5d3  80b986b9510000         +cmp byte ptr [ecx + 0x51b986], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5355910) /* 0x51b986 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e5da  740f                   -je 0x47e5eb
    if (cpu.flags.zf)
    {
        goto L_0x0047e5eb;
    }
    // 0047e5dc  8bb80c845200           -mov edi, dword ptr [eax + 0x52840c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407756) /* 0x52840c */);
    // 0047e5e2  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 0047e5e5  83ef40                 -sub edi, 0x40
    (cpu.edi) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047e5e8  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
L_0x0047e5eb:
    // 0047e5eb  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047e5ed  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 0047e5f0  8b8586b95100           -mov eax, dword ptr [ebp + 0x51b986]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5355910) /* 0x51b986 */);
    // 0047e5f6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047e5f9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e5fa  8b8585b95100           -mov eax, dword ptr [ebp + 0x51b985]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e600  c1f818                 +sar eax, 0x18
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
    // 0047e603  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e607  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047e608  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047e60c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047e60e  e8eda60100             -call 0x498d00
    cpu.esp -= 4;
    sub_498d00(app, cpu);
    if (cpu.terminate) return;
    // 0047e613  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047e617  888588b95100           -mov byte ptr [ebp + 0x51b988], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5355912) /* 0x51b988 */) = cpu.al;
    // 0047e61d  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047e621  888589b95100           -mov byte ptr [ebp + 0x51b989], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5355913) /* 0x51b989 */) = cpu.al;
    // 0047e627  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e628  e974ffffff             -jmp 0x47e5a1
    goto L_0x0047e5a1;
L_0x0047e62d:
    // 0047e62d  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e632  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047e635  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e636  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e638  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e639  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e63c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e63c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e63d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e63e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e640  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e643  8a9a85b95100           -mov bl, byte ptr [edx + 0x51b985]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e649  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047e64b  740d                   -je 0x47e65a
    if (cpu.flags.zf)
    {
        goto L_0x0047e65a;
    }
    // 0047e64d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e650  7408                   -je 0x47e65a
    if (cpu.flags.zf)
    {
        goto L_0x0047e65a;
    }
    // 0047e652  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e657  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e658  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e659  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e65a:
    // 0047e65a  e899930100             -call 0x4979f8
    cpu.esp -= 4;
    sub_4979f8(app, cpu);
    if (cpu.terminate) return;
    // 0047e65f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e660  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e661  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e664  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e665  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e666  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e667  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e669  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047e66c  8a9085b95100           -mov dl, byte ptr [eax + 0x51b985]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e672  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047e674  740e                   -je 0x47e684
    if (cpu.flags.zf)
    {
        goto L_0x0047e684;
    }
    // 0047e676  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e679  7409                   -je 0x47e684
    if (cpu.flags.zf)
    {
        goto L_0x0047e684;
    }
    // 0047e67b  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x0047e680:
    // 0047e680  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e682  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e683  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e684:
    // 0047e684  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e686  e8f1940100             -call 0x497b7c
    cpu.esp -= 4;
    sub_497b7c(app, cpu);
    if (cpu.terminate) return;
    // 0047e68b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e68d  7cf1                   -jl 0x47e680
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e680;
    }
    // 0047e68f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e691  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e694  8b9a8cb95100           -mov ebx, dword ptr [edx + 0x51b98c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5355916) /* 0x51b98c */);
    // 0047e69a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e69c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047e69e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e6a0  7cde                   -jl 0x47e680
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e680;
    }
    // 0047e6a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e6a4  668b9a80b95100         -mov bx, word ptr [edx + 0x51b980]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5355904) /* 0x51b980 */);
    // 0047e6ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e6ad  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e6b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e6b2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047e6b5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e6b7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047e6ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e6bc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047e6bf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047e6c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e6c3  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047e6ca  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047e6cc  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047e6cf  6683b81284520000       +cmp word ptr [eax + 0x528412], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5407762) /* 0x528412 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047e6d7  7c2b                   -jl 0x47e704
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e704;
    }
    // 0047e6d9  8b8810845200           -mov ecx, dword ptr [eax + 0x528410]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407760) /* 0x528410 */);
    // 0047e6df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e6e1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e6e4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047e6e6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047e6e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e6eb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047e6ee  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e6f0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047e6f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e6f5  81c1b0040000           -add ecx, 0x4b0
    (cpu.ecx) += x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 0047e6fb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047e6fe  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047e700  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e702  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e704:
    // 0047e704  8b8010845200           -mov eax, dword ptr [eax + 0x528410]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407760) /* 0x528410 */);
    // 0047e70a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047e70d  2db0040000             -sub eax, 0x4b0
    (cpu.eax) -= x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 0047e712  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047e715  b950fbffff             -mov ecx, 0xfffffb50
    cpu.ecx = 4294966096 /*0xfffffb50*/;
    // 0047e71a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e71c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047e71f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047e721  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e722  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e723  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47e728(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e728  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e729  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e72a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e72c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047e72f  8a9a85b95100           -mov bl, byte ptr [edx + 0x51b985]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e735  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047e737  740d                   -je 0x47e746
    if (cpu.flags.zf)
    {
        goto L_0x0047e746;
    }
    // 0047e739  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e73c  7408                   -je 0x47e746
    if (cpu.flags.zf)
    {
        goto L_0x0047e746;
    }
    // 0047e73e  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e743  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e744  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e745  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e746:
    // 0047e746  e831940100             -call 0x497b7c
    cpu.esp -= 4;
    sub_497b7c(app, cpu);
    if (cpu.terminate) return;
    // 0047e74b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e74c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e74d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e752  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e754  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047e757  8a9885b95100           -mov bl, byte ptr [eax + 0x51b985]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5355909) /* 0x51b985 */);
    // 0047e75d  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0047e75f  740d                   -je 0x47e76e
    if (cpu.flags.zf)
    {
        goto L_0x0047e76e;
    }
    // 0047e761  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e764  7408                   -je 0x47e76e
    if (cpu.flags.zf)
    {
        goto L_0x0047e76e;
    }
    // 0047e766  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047e76b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e76c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e76d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e76e:
    // 0047e76e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e76f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047e771  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0047e774  a1208d4c00             -mov eax, dword ptr [0x4c8d20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016864) /* 0x4c8d20 */);
    // 0047e779  668bb680b95100         -mov si, word ptr [esi + 0x51b980]
    cpu.si = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5355904) /* 0x51b980 */);
    // 0047e780  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047e786  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047e788  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e78a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e78c  e82f990100             -call 0x4980c0
    cpu.esp -= 4;
    sub_4980c0(app, cpu);
    if (cpu.terminate) return;
    // 0047e791  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e793  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e795  e8be920100             -call 0x497a58
    cpu.esp -= 4;
    sub_497a58(app, cpu);
    if (cpu.terminate) return;
    // 0047e79a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e79b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e79c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e79d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47e7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e7a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e7a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e7a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e7a3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047e7a5  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047e7a8  81c380b95100           -add ebx, 0x51b980
    (cpu.ebx) += x86::reg32(x86::sreg32(5355904 /*0x51b980*/));
    // 0047e7ae  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047e7b1  807b0407               +cmp byte ptr [ebx + 4], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e7b5  7461                   -je 0x47e818
    if (cpu.flags.zf)
    {
        goto L_0x0047e818;
    }
    // 0047e7b7  807b0409               +cmp byte ptr [ebx + 4], 9
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e7bb  7457                   -je 0x47e814
    if (cpu.flags.zf)
    {
        goto L_0x0047e814;
    }
    // 0047e7bd  807b0408               +cmp byte ptr [ebx + 4], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e7c1  7451                   -je 0x47e814
    if (cpu.flags.zf)
    {
        goto L_0x0047e814;
    }
    // 0047e7c3  807b0402               +cmp byte ptr [ebx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e7c7  0f85a2000000           -jne 0x47e86f
    if (!cpu.flags.zf)
    {
        goto L_0x0047e86f;
    }
    // 0047e7cd  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0047e7d2  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0047e7d8  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0047e7de  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0047e7e4  8a4303                 -mov al, byte ptr [ebx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0047e7e7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047e7e9  3c01                   +cmp al, 1
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
    // 0047e7eb  7515                   -jne 0x47e802
    if (!cpu.flags.zf)
    {
        goto L_0x0047e802;
    }
    // 0047e7ed  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047e7f2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e7f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e7f6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047e7f9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047e7fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047e7fd  7401                   -je 0x47e800
    if (cpu.flags.zf)
    {
        goto L_0x0047e800;
    }
    // 0047e7ff  41                     -inc ecx
    (cpu.ecx)++;
L_0x0047e800:
    // 0047e800  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
L_0x0047e802:
    // 0047e802  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e804  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e806  7e0c                   -jle 0x47e814
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e814;
    }
    // 0047e808  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0047e80a:
    // 0047e80a  40                     -inc eax
    (cpu.eax)++;
    // 0047e80b  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0047e80e  42                     -inc edx
    (cpu.edx)++;
    // 0047e80f  39c8                   +cmp eax, ecx
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
    // 0047e811  7cf7                   -jl 0x47e80a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e80a;
    }
    // 0047e813  90                     -nop 
    ;
L_0x0047e814:
    // 0047e814  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e815  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e816  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e817  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e818:
    // 0047e818  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0047e81d  be1c000000             -mov esi, 0x1c
    cpu.esi = 28 /*0x1c*/;
    // 0047e822  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0047e828  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047e82a  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0047e830  83c11b                 -add ecx, 0x1b
    (cpu.ecx) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0047e833  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0047e839  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047e83b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e83d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047e840  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047e842  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0047e849  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047e84b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e84d  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0047e850  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e852  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e856  7502                   -jne 0x47e85a
    if (!cpu.flags.zf)
    {
        goto L_0x0047e85a;
    }
    // 0047e858  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047e85a:
    // 0047e85a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e85c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e85e  7eb4                   -jle 0x47e814
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e814;
    }
    // 0047e860  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0047e862:
    // 0047e862  40                     -inc eax
    (cpu.eax)++;
    // 0047e863  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0047e866  42                     -inc edx
    (cpu.edx)++;
    // 0047e867  39c8                   +cmp eax, ecx
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
    // 0047e869  7cf7                   -jl 0x47e862
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e862;
    }
    // 0047e86b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e86c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e86d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e86e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e86f:
    // 0047e86f  807b0400               +cmp byte ptr [ebx + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e873  759f                   -jne 0x47e814
    if (!cpu.flags.zf)
    {
        goto L_0x0047e814;
    }
    // 0047e875  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e879  7502                   -jne 0x47e87d
    if (!cpu.flags.zf)
    {
        goto L_0x0047e87d;
    }
    // 0047e87b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047e87d:
    // 0047e87d  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0047e880  80fa10                 +cmp dl, 0x10
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
    // 0047e883  7517                   -jne 0x47e89c
    if (!cpu.flags.zf)
    {
        goto L_0x0047e89c;
    }
    // 0047e885  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e887  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e889  7e89                   -jle 0x47e814
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e814;
    }
L_0x0047e88b:
    // 0047e88b  42                     -inc edx
    (cpu.edx)++;
    // 0047e88c  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 0047e891  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047e894  39ca                   +cmp edx, ecx
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
    // 0047e896  7cf3                   -jl 0x47e88b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e88b;
    }
    // 0047e898  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e899  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e89a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e89b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e89c:
    // 0047e89c  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e89f  0f856fffffff           -jne 0x47e814
    if (!cpu.flags.zf)
    {
        goto L_0x0047e814;
    }
    // 0047e8a5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e8a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047e8a9  0f8e65ffffff           -jle 0x47e814
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047e814;
    }
L_0x0047e8af:
    // 0047e8af  42                     -inc edx
    (cpu.edx)++;
    // 0047e8b0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0047e8b3  40                     -inc eax
    (cpu.eax)++;
    // 0047e8b4  39ca                   +cmp edx, ecx
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
    // 0047e8b6  7cf7                   -jl 0x47e8af
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e8af;
    }
    // 0047e8b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47e8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e8c0  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e8c7  740f                   -je 0x47e8d8
    if (cpu.flags.zf)
    {
        goto L_0x0047e8d8;
    }
    // 0047e8c9  83f87f                 +cmp eax, 0x7f
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
    // 0047e8cc  7f04                   -jg 0x47e8d2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047e8d2;
    }
    // 0047e8ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e8d0  7d0c                   -jge 0x47e8de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047e8de;
    }
L_0x0047e8d2:
    // 0047e8d2  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047e8d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e8d8:
    // 0047e8d8  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047e8dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e8de:
    // 0047e8de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e8df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e8e0  a2b6a04c00             -mov byte ptr [0x4ca0b6], al
    app->getMemory<x86::reg8>(x86::reg32(5021878) /* 0x4ca0b6 */) = cpu.al;
    // 0047e8e5  8b0d44a04c00           -mov ecx, dword ptr [0x4ca044]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5021764) /* 0x4ca044 */);
    // 0047e8eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e8ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047e8ef  e868010000             -call 0x47ea5c
    cpu.esp -= 4;
    sub_47ea5c(app, cpu);
    if (cpu.terminate) return;
    // 0047e8f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e8f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e8f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e900  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047e901  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e902  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e904  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 0047e90a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047e90c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047e90e  750a                   -jne 0x47e91a
    if (!cpu.flags.zf)
    {
        goto L_0x0047e91a;
    }
    // 0047e910  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0047e915  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e917  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e918  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e919  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e91a:
    // 0047e91a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e91b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e91c  e8cf5f0100             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 0047e921  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e923  e8d4630100             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0047e928  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047e92a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e92c  7c56                   -jl 0x47e984
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e984;
    }
    // 0047e92e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047e931  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e933  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047e936  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047e938  8a983b845200           -mov bl, byte ptr [eax + 0x52843b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407803) /* 0x52843b */);
    // 0047e93e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047e940  7439                   -je 0x47e97b
    if (cpu.flags.zf)
    {
        goto L_0x0047e97b;
    }
    // 0047e942  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 0047e947  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047e949:
    // 0047e949  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e94b  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0047e94e  39d8                   +cmp eax, ebx
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
    // 0047e950  7512                   -jne 0x47e964
    if (!cpu.flags.zf)
    {
        goto L_0x0047e964;
    }
    // 0047e952  80790c01               +cmp byte ptr [ecx + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e956  750c                   -jne 0x47e964
    if (!cpu.flags.zf)
    {
        goto L_0x0047e964;
    }
    // 0047e958  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047e95b  7c07                   -jl 0x47e964
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e964;
    }
    // 0047e95d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e95f  e8d8fcffff             -call 0x47e63c
    cpu.esp -= 4;
    sub_47e63c(app, cpu);
    if (cpu.terminate) return;
L_0x0047e964:
    // 0047e964  42                     -inc edx
    (cpu.edx)++;
    // 0047e965  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047e968  83fa10                 +cmp edx, 0x10
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
    // 0047e96b  7cdc                   -jl 0x47e949
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e949;
    }
L_0x0047e96d:
    // 0047e96d  e8925f0100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047e972  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047e974  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e975  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e976  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e978  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e979  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e97a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047e97b:
    // 0047e97b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e97d  e8bafcffff             -call 0x47e63c
    cpu.esp -= 4;
    sub_47e63c(app, cpu);
    if (cpu.terminate) return;
    // 0047e982  ebe9                   -jmp 0x47e96d
    goto L_0x0047e96d;
L_0x0047e984:
    // 0047e984  bef8ffffff             -mov esi, 0xfffffff8
    cpu.esi = 4294967288 /*0xfffffff8*/;
    // 0047e989  e8765f0100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047e98e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047e990  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e991  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e992  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047e994  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e995  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047e996  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
