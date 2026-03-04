#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip 0x90 */
void sub_a8a5a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a5a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a5a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a5a4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a5a6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a5a8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a5aa  2eff156803a900         -call dword ptr cs:[0xa90368]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076456) /* 0xa90368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a5b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a5b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a5b5  750d                   -jne 0xa8a5c4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a5c4;
    }
    // 00a8a5b7  8b151028a900           -mov edx, dword ptr [0xa92810]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085840) /* 0xa92810 */);
    // 00a8a5bd  42                     -inc edx
    (cpu.edx)++;
    // 00a8a5be  89151028a900           -mov dword ptr [0xa92810], edx
    app->getMemory<x86::reg32>(x86::reg32(11085840) /* 0xa92810 */) = cpu.edx;
L_0x00a8a5c4:
    // 00a8a5c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8a5c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a5c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a5c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8a5cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a5cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a5cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a5ce  8b150828a900           -mov edx, dword ptr [0xa92808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a5d4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8a5d6  740f                   -je 0xa8a5e7
    if (cpu.flags.zf)
    {
        goto L_0x00a8a5e7;
    }
    // 00a8a5d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8a5da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8a5dc  e8bfc7ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a5e1  891d0828a900           -mov dword ptr [0xa92808], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */) = cpu.ebx;
L_0x00a8a5e7:
    // 00a8a5e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a5e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a5e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a5f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a5f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a5f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a5f4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8a5f6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8a5f8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8a5fa  2eff15e003a900         -call dword ptr cs:[0xa903e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076576) /* 0xa903e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a601  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a8a604  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8a609  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8a60d  730f                   -jae 0xa8a61e
    if (!cpu.flags.cf)
    {
        goto L_0x00a8a61e;
    }
    // 00a8a60f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a610  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a611  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a612  2eff15cc03a900         -call dword ptr cs:[0xa903cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076556) /* 0xa903cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a619  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a61a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a61b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a61c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a61d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a61e:
    // 00a8a61e  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00a8a623  e888c6ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a628  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8a62a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a62c  7452                   -je 0xa8a680
    if (cpu.flags.zf)
    {
        goto L_0x00a8a680;
    }
    // 00a8a62e  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00a8a633  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a635  2eff15c803a900         -call dword ptr cs:[0xa903c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076552) /* 0xa903c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a63c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a63e  750e                   -jne 0xa8a64e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a64e;
    }
    // 00a8a640  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a642  e859c7ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a647  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8a649  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a64a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a64b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a64c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a64d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a64e:
    // 00a8a64e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a64f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a650  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a8a652  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a653  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8a655  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8a657  2eff15f403a900         -call dword ptr cs:[0xa903f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076596) /* 0xa903f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a65e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8a660  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a662  e839c7ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a667  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8a669  7507                   -jne 0xa8a672
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a672;
    }
    // 00a8a66b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8a66d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a66e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a66f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a670  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a671  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a672:
    // 00a8a672  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a674  66c7447efe0000         -mov word ptr [esi + edi*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.edi * 2) = 0 /*0x0*/;
    // 00a8a67b  e8401a0000             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a680:
    // 00a8a680  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a681  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a682  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a683  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a690  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a691  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a692  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a693  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a694  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8a696  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8a698  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8a699  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8a69b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8a69d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8a69f  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8a6a0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8a6a2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a8a6a4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a8a6a6  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8a6a7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6a8  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8a6a9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a6ab  e800c6ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a6b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a6b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a6b4  7418                   -je 0xa8a6ce
    if (cpu.flags.zf)
    {
        goto L_0x00a8a6ce;
    }
    // 00a8a6b6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8a6b8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8a6b9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8a6bb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8a6bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a6be  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a6c0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8a6c3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8a6c5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8a6c7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8a6ca  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8a6cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6cd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a8a6ce:
    // 00a8a6ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8a6d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a6d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a6e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a6e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a6e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a6e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a6e5  e8d6190000             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a6ea  40                     -inc eax
    (cpu.eax)++;
    // 00a8a6eb  8d1c4500000000         -lea ebx, [eax*2]
    cpu.ebx = x86::reg32(cpu.eax * 2);
    // 00a8a6f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a6f4  e8b7c5ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a6f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8a6fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a6fd  7405                   -je 0xa8a704
    if (cpu.flags.zf)
    {
        goto L_0x00a8a704;
    }
    // 00a8a6ff  e8dc190000             -call 0xa8c0e0
    cpu.esp -= 4;
    sub_a8c0e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a704:
    // 00a8a704  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a706  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a710(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a713  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8a716  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8a718  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8a71a  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00a8a71c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8a720  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a721  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8a725  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a726  2eff153404a900         -call dword ptr cs:[0xa90434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076660) /* 0xa90434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a72d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a730  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a8a734  668b0d8527a900         -mov cx, word ptr [0xa92785]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(11085701) /* 0xa92785 */);
    // 00a8a73b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8a73f  6681f90080             +cmp cx, 0x8000
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
    // 00a8a744  7307                   -jae 0xa8a74d
    if (!cpu.flags.cf)
    {
        goto L_0x00a8a74d;
    }
    // 00a8a746  0500300000             +add eax, 0x3000
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
    // 00a8a74b  eb17                   -jmp 0xa8a764
    goto L_0x00a8a764;
L_0x00a8a74d:
    // 00a8a74d  7210                   -jb 0xa8a75f
    if (cpu.flags.cf)
    {
        goto L_0x00a8a75f;
    }
    // 00a8a74f  803d8327a90004         +cmp byte ptr [0xa92783], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085699) /* 0xa92783 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8a756  7307                   -jae 0xa8a75f
    if (!cpu.flags.cf)
    {
        goto L_0x00a8a75f;
    }
    // 00a8a758  0500200100             +add eax, 0x12000
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
    // 00a8a75d  eb05                   -jmp 0xa8a764
    goto L_0x00a8a764;
L_0x00a8a75f:
    // 00a8a75f  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00a8a764:
    // 00a8a764  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8a766  7402                   -je 0xa8a76a
    if (cpu.flags.zf)
    {
        goto L_0x00a8a76a;
    }
    // 00a8a768  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a8a76a:
    // 00a8a76a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8a76c  7402                   -je 0xa8a770
    if (cpu.flags.zf)
    {
        goto L_0x00a8a770;
    }
    // 00a8a76e  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00a8a770:
    // 00a8a770  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8a773  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a774  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a775  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a783  68c818a900             -push 0xa918c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11081928 /*0xa918c8*/;
    cpu.esp -= 4;
    // 00a8a788  2eff15ec03a900         -call dword ptr cs:[0xa903ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076588) /* 0xa903ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a78f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8a791  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a793  7417                   -je 0xa8a7ac
    if (cpu.flags.zf)
    {
        goto L_0x00a8a7ac;
    }
    // 00a8a795  68d418a900             -push 0xa918d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11081940 /*0xa918d4*/;
    cpu.esp -= 4;
    // 00a8a79a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a79b  2eff15d803a900         -call dword ptr cs:[0xa903d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076568) /* 0xa903d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a7a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a7a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a7a6  7404                   -je 0xa8a7ac
    if (cpu.flags.zf)
    {
        goto L_0x00a8a7ac;
    }
    // 00a8a7a8  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a7aa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a8a7ac:
    // 00a8a7ac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8a7ae  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a8a7b1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8a7b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a7b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a7b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a7b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8a7bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a7bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a7bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a7be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a7bf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8a7c1  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8a7c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8a7c5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a8a7c7  7408                   -je 0xa8a7d1
    if (cpu.flags.zf)
    {
        goto L_0x00a8a7d1;
    }
L_0x00a8a7c9:
    // 00a8a7c9  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8a7cc  40                     -inc eax
    (cpu.eax)++;
    // 00a8a7cd  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00a8a7cf  75f8                   -jne 0xa8a7c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a7c9;
    }
L_0x00a8a7d1:
    // 00a8a7d1  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00a8a7d4:
    // 00a8a7d4  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8a7d6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a8a7d8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a8a7da  7412                   -je 0xa8a7ee
    if (cpu.flags.zf)
    {
        goto L_0x00a8a7ee;
    }
    // 00a8a7dc  80f930                 +cmp cl, 0x30
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
    // 00a8a7df  7508                   -jne 0xa8a7e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a7e9;
    }
    // 00a8a7e1  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8a7e5  7502                   -jne 0xa8a7e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a7e9;
    }
    // 00a8a7e7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00a8a7e9:
    // 00a8a7e9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8a7ea  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8a7eb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8a7ec  ebe6                   -jmp 0xa8a7d4
    goto L_0x00a8a7d4;
L_0x00a8a7ee:
    // 00a8a7ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8a7f0  741c                   -je 0xa8a80e
    if (cpu.flags.zf)
    {
        goto L_0x00a8a80e;
    }
    // 00a8a7f2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8a7f4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8a7f6  7416                   -je 0xa8a80e
    if (cpu.flags.zf)
    {
        goto L_0x00a8a80e;
    }
L_0x00a8a7f8:
    // 00a8a7f8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a7fa  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a8a7fd  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a8a7fe  8a921c28a900           -mov dl, byte ptr [edx + 0xa9281c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085852) /* 0xa9281c */);
    // 00a8a804  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00a8a807  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a8a80a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a80c  75ea                   -jne 0xa8a7f8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a7f8;
    }
L_0x00a8a80e:
    // 00a8a80e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a80f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a810  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8a814(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a814  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a815  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a816  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8a81c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00a8a823  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8a825  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a8a828  e853ffffff             -call 0xa8a780
    cpu.esp -= 4;
    sub_a8a780(app, cpu);
    if (cpu.terminate) return;
    // 00a8a82d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a82f  750a                   -jne 0xa8a83b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a83b;
    }
    // 00a8a831  e87e190000             -call 0xa8c1b4
    cpu.esp -= 4;
    sub_a8c1b4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a836  83f8ff                 +cmp eax, -1
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
    // 00a8a839  7507                   -jne 0xa8a842
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a842;
    }
L_0x00a8a83b:
    // 00a8a83b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8a83d  e98c010000             -jmp 0xa8a9ce
    goto L_0x00a8a9ce;
L_0x00a8a842:
    // 00a8a842  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a8a844  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00a8a847  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8a849  3d900000c0             +cmp eax, 0xc0000090
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
    // 00a8a84e  724d                   -jb 0xa8a89d
    if (cpu.flags.cf)
    {
        goto L_0x00a8a89d;
    }
    // 00a8a850  0f86c2000000           -jbe 0xa8a918
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a918;
    }
    // 00a8a856  3d930000c0             +cmp eax, 0xc0000093
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
    // 00a8a85b  7233                   -jb 0xa8a890
    if (cpu.flags.cf)
    {
        goto L_0x00a8a890;
    }
    // 00a8a85d  0f86ab000000           -jbe 0xa8a90e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a90e;
    }
    // 00a8a863  3d960000c0             +cmp eax, 0xc0000096
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
    // 00a8a868  7216                   -jb 0xa8a880
    if (cpu.flags.cf)
    {
        goto L_0x00a8a880;
    }
    // 00a8a86a  0f86ec000000           -jbe 0xa8a95c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a95c;
    }
    // 00a8a870  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 00a8a875  0f84f6000000           -je 0xa8a971
    if (cpu.flags.zf)
    {
        goto L_0x00a8a971;
    }
    // 00a8a87b  e9f8000000             -jmp 0xa8a978
    goto L_0x00a8a978;
L_0x00a8a880:
    // 00a8a880  3d940000c0             +cmp eax, 0xc0000094
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
    // 00a8a885  0f84df000000           -je 0xa8a96a
    if (cpu.flags.zf)
    {
        goto L_0x00a8a96a;
    }
    // 00a8a88b  e9e8000000             -jmp 0xa8a978
    goto L_0x00a8a978;
L_0x00a8a890:
    // 00a8a890  3d910000c0             +cmp eax, 0xc0000091
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
    // 00a8a895  0f8669000000           -jbe 0xa8a904
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a904;
    }
    // 00a8a89b  eb2f                   -jmp 0xa8a8cc
    goto L_0x00a8a8cc;
L_0x00a8a89d:
    // 00a8a89d  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 00a8a8a2  720b                   -jb 0xa8a8af
    if (cpu.flags.cf)
    {
        goto L_0x00a8a8af;
    }
    // 00a8a8a4  7640                   -jbe 0xa8a8e6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a8e6;
    }
    // 00a8a8a6  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 00a8a8ab  7643                   -jbe 0xa8a8f0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a8f0;
    }
    // 00a8a8ad  eb4b                   -jmp 0xa8a8fa
    goto L_0x00a8a8fa;
L_0x00a8a8af:
    // 00a8a8af  3d050000c0             +cmp eax, 0xc0000005
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
    // 00a8a8b4  0f82be000000           -jb 0xa8a978
    if (cpu.flags.cf)
    {
        goto L_0x00a8a978;
    }
    // 00a8a8ba  7666                   -jbe 0xa8a922
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a922;
    }
    // 00a8a8bc  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 00a8a8c1  0f849c000000           -je 0xa8a963
    if (cpu.flags.zf)
    {
        goto L_0x00a8a963;
    }
    // 00a8a8c7  e9ac000000             -jmp 0xa8a978
    goto L_0x00a8a978;
L_0x00a8a8cc:
    // 00a8a8cc  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a8a8d0  740a                   -je 0xa8a8dc
    if (cpu.flags.zf)
    {
        goto L_0x00a8a8dc;
    }
    // 00a8a8d2  bae418a900             -mov edx, 0xa918e4
    cpu.edx = 11081956 /*0xa918e4*/;
    // 00a8a8d7  e9af000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a8dc:
    // 00a8a8dc  ba3819a900             -mov edx, 0xa91938
    cpu.edx = 11082040 /*0xa91938*/;
    // 00a8a8e1  e9a5000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a8e6:
    // 00a8a8e6  ba8c19a900             -mov edx, 0xa9198c
    cpu.edx = 11082124 /*0xa9198c*/;
    // 00a8a8eb  e99b000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a8f0:
    // 00a8a8f0  bae019a900             -mov edx, 0xa919e0
    cpu.edx = 11082208 /*0xa919e0*/;
    // 00a8a8f5  e991000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a8fa:
    // 00a8a8fa  ba341aa900             -mov edx, 0xa91a34
    cpu.edx = 11082292 /*0xa91a34*/;
    // 00a8a8ff  e987000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a904:
    // 00a8a904  ba881aa900             -mov edx, 0xa91a88
    cpu.edx = 11082376 /*0xa91a88*/;
    // 00a8a909  e97d000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a90e:
    // 00a8a90e  bad41aa900             -mov edx, 0xa91ad4
    cpu.edx = 11082452 /*0xa91ad4*/;
    // 00a8a913  e973000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a918:
    // 00a8a918  ba241ba900             -mov edx, 0xa91b24
    cpu.edx = 11082532 /*0xa91b24*/;
    // 00a8a91d  e969000000             -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a922:
    // 00a8a922  ba7c1ba900             -mov edx, 0xa91b7c
    cpu.edx = 11082620 /*0xa91b7c*/;
    // 00a8a927  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a929  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a8a92c  e88bfeffff             -call 0xa8a7bc
    cpu.esp -= 4;
    sub_a8a7bc(app, cpu);
    if (cpu.terminate) return;
    // 00a8a931  bab01ba900             -mov edx, 0xa91bb0
    cpu.edx = 11082672 /*0xa91bb0*/;
    // 00a8a936  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a938  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a8a93b  e87cfeffff             -call 0xa8a7bc
    cpu.esp -= 4;
    sub_a8a7bc(app, cpu);
    if (cpu.terminate) return;
    // 00a8a940  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a944  750b                   -jne 0xa8a951
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a951;
    }
    // 00a8a946  bad81ba900             -mov edx, 0xa91bd8
    cpu.edx = 11082712 /*0xa91bd8*/;
    // 00a8a94b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a94d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8a94f  eb3f                   -jmp 0xa8a990
    goto L_0x00a8a990;
L_0x00a8a951:
    // 00a8a951  bae01ba900             -mov edx, 0xa91be0
    cpu.edx = 11082720 /*0xa91be0*/;
    // 00a8a956  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a958  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8a95a  eb34                   -jmp 0xa8a990
    goto L_0x00a8a990;
L_0x00a8a95c:
    // 00a8a95c  baec1ba900             -mov edx, 0xa91bec
    cpu.edx = 11082732 /*0xa91bec*/;
    // 00a8a961  eb28                   -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a963:
    // 00a8a963  ba2c1ca900             -mov edx, 0xa91c2c
    cpu.edx = 11082796 /*0xa91c2c*/;
    // 00a8a968  eb21                   -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a96a:
    // 00a8a96a  ba681ca900             -mov edx, 0xa91c68
    cpu.edx = 11082856 /*0xa91c68*/;
    // 00a8a96f  eb1a                   -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a971:
    // 00a8a971  baac1ca900             -mov edx, 0xa91cac
    cpu.edx = 11082924 /*0xa91cac*/;
    // 00a8a976  eb13                   -jmp 0xa8a98b
    goto L_0x00a8a98b;
L_0x00a8a978:
    // 00a8a978  bae81ca900             -mov edx, 0xa91ce8
    cpu.edx = 11082984 /*0xa91ce8*/;
    // 00a8a97d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a97f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8a981  e836feffff             -call 0xa8a7bc
    cpu.esp -= 4;
    sub_a8a7bc(app, cpu);
    if (cpu.terminate) return;
    // 00a8a986  ba1c1da900             -mov edx, 0xa91d1c
    cpu.edx = 11083036 /*0xa91d1c*/;
L_0x00a8a98b:
    // 00a8a98b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a98d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00a8a990:
    // 00a8a990  e827feffff             -call 0xa8a7bc
    cpu.esp -= 4;
    sub_a8a7bc(app, cpu);
    if (cpu.terminate) return;
    // 00a8a995  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a997  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a8a99e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a99f  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8a9a3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8a9a4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8a9a6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8a9a8  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8a9aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8a9ab  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8a9ad  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a8a9af  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a8a9b1  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8a9b2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8a9b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a9b4  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8a9b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a9b9  a10828a900             -mov eax, dword ptr [0xa92808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a9be  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8a9c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a9c2  2eff154004a900         -call dword ptr cs:[0xa90440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076672) /* 0xa90440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a9c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8a9ce:
    // 00a8a9ce  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8a9d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a9d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a9d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8a9f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a8a9f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a9f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a9fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a9fb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8a9fe  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8aa02  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a8aa06  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00a8aa0a  0f85a1010000           -jne 0xa8abb1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8abb1;
    }
    // 00a8aa10  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8aa12  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00a8aa17  83f806                 +cmp eax, 6
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
    // 00a8aa1a  0f871f010000           -ja 0xa8ab3f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8ab3f;
    }
    // 00a8aa20  2eff2485dca9a800       -jmp dword ptr cs:[eax*4 + 0xa8a9dc]
    cpu.ip = app->getMemory<x86::reg32>(11053532 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a8aa28:
    // 00a8aa28  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a8aa2c  740a                   -je 0xa8aa38
    if (cpu.flags.zf)
    {
        goto L_0x00a8aa38;
    }
    // 00a8aa2e  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00a8aa33  e9ca000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
L_0x00a8aa38:
    // 00a8aa38  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00a8aa3d  e9c0000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
  case 0x00a8aa42:
    // 00a8aa42  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00a8aa47  e9b6000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
  case 0x00a8aa4c:
    // 00a8aa4c  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00a8aa51  e9ac000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
  case 0x00a8aa56:
    // 00a8aa56  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00a8aa5b  e9a2000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
  case 0x00a8aa60:
    // 00a8aa60  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00a8aa65  e998000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
  case 0x00a8aa6a:
    // 00a8aa6a  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a8aa6d  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a8aa70  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00a8aa75  6681fad9fa             +cmp dx, 0xfad9
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
    // 00a8aa7a  750a                   -jne 0xa8aa86
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aa86;
    }
    // 00a8aa7c  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00a8aa81  e97c000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
L_0x00a8aa86:
    // 00a8aa86  6681fad9f1             +cmp dx, 0xf1d9
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
    // 00a8aa8b  750a                   -jne 0xa8aa97
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aa97;
    }
    // 00a8aa8d  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00a8aa92  e96b000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
L_0x00a8aa97:
    // 00a8aa97  750a                   -jne 0xa8aaa3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aaa3;
    }
    // 00a8aa99  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00a8aa9e  e95f000000             -jmp 0xa8ab02
    goto L_0x00a8ab02;
L_0x00a8aaa3:
    // 00a8aaa3  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8aaa5  80fedb                 +cmp dh, 0xdb
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
    // 00a8aaa8  7405                   -je 0xa8aaaf
    if (cpu.flags.zf)
    {
        goto L_0x00a8aaaf;
    }
    // 00a8aaaa  80fedf                 +cmp dh, 0xdf
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
    // 00a8aaad  7510                   -jne 0xa8aabf
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aabf;
    }
L_0x00a8aaaf:
    // 00a8aaaf  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8aab2  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8aab5  80fa10                 +cmp dl, 0x10
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
    // 00a8aab8  7505                   -jne 0xa8aabf
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aabf;
    }
    // 00a8aaba  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00a8aabf:
    // 00a8aabf  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a8aac2  7539                   -jne 0xa8aafd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aafd;
    }
    // 00a8aac4  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8aac7  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8aac9  3c30                   +cmp al, 0x30
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
    // 00a8aacb  7530                   -jne 0xa8aafd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aafd;
    }
    // 00a8aacd  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a8aad0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8aad5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8aad8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8aada  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00a8aade  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00a8aae1  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00a8aae4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8aaea  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8aaec  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00a8aaee  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00a8aaf1  83fa01                 +cmp edx, 1
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
    // 00a8aaf4  7507                   -jne 0xa8aafd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aafd;
    }
  [[fallthrough]];
  case 0x00a8aaf6:
    // 00a8aaf6  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00a8aafb  eb05                   -jmp 0xa8ab02
    goto L_0x00a8ab02;
L_0x00a8aafd:
    // 00a8aafd  83fbff                 +cmp ebx, -1
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
    // 00a8ab00  743d                   -je 0xa8ab3f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab3f;
    }
L_0x00a8ab02:
    // 00a8ab02  c605244aa90001         -mov byte ptr [0xa94a24], 1
    app->getMemory<x86::reg8>(x86::reg32(11094564) /* 0xa94a24 */) = 1 /*0x1*/;
    // 00a8ab09  e8b2160000             -call 0xa8c1c0
    cpu.esp -= 4;
    sub_a8c1c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ab0e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ab10  e87f180000             -call 0xa8c394
    cpu.esp -= 4;
    sub_a8c394(app, cpu);
    if (cpu.terminate) return;
    // 00a8ab15  83f8ff                 +cmp eax, -1
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
    // 00a8ab18  0f8474000000           -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab1e  803d244aa90000         +cmp byte ptr [0xa94a24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11094564) /* 0xa94a24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ab25  0f8467000000           -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab2b  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a8ab2f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a8ab31  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a8ab34  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8ab36  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00a8ab3a  e977000000             -jmp 0xa8abb6
    goto L_0x00a8abb6;
L_0x00a8ab3f:
    // 00a8ab3f  833d1828a90000         +cmp dword ptr [0xa92818], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085848) /* 0xa92818 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ab46  744a                   -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab48  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8ab4d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00a8ab4f:
    // 00a8ab4f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ab51  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8ab53  ff151428a900           -call dword ptr [0xa92814]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085844) /* 0xa92814 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ab59  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ab5b  742f                   -je 0xa8ab8c
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab8c;
    }
    // 00a8ab5d  83f801                 +cmp eax, 1
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
    // 00a8ab60  7430                   -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab62  83f802                 +cmp eax, 2
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
    // 00a8ab65  742b                   -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab67  83f803                 +cmp eax, 3
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
    // 00a8ab6a  7426                   -je 0xa8ab92
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab92;
    }
    // 00a8ab6c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ab6e  880d244aa900           -mov byte ptr [0xa94a24], cl
    app->getMemory<x86::reg8>(x86::reg32(11094564) /* 0xa94a24 */) = cpu.cl;
    // 00a8ab74  ff151828a900           -call dword ptr [0xa92818]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085848) /* 0xa92818 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ab7a  803d244aa90000         +cmp byte ptr [0xa94a24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11094564) /* 0xa94a24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ab81  7409                   -je 0xa8ab8c
    if (cpu.flags.zf)
    {
        goto L_0x00a8ab8c;
    }
    // 00a8ab83  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ab85  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8ab88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ab89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ab8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ab8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ab8c:
    // 00a8ab8c  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ab8d  83fb0c                 +cmp ebx, 0xc
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
    // 00a8ab90  7ebd                   -jle 0xa8ab4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8ab4f;
    }
L_0x00a8ab92:
    // 00a8ab92  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8ab94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ab95  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a8ab99  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a8ab9d  2eff152804a900         -call dword ptr cs:[0xa90428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076648) /* 0xa90428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8aba4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8aba6  7409                   -je 0xa8abb1
    if (cpu.flags.zf)
    {
        goto L_0x00a8abb1;
    }
    // 00a8aba8  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a8abaa  2eff158003a900         -call dword ptr cs:[0xa90380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076480) /* 0xa90380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8abb1:
    // 00a8abb1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8abb6:
    // 00a8abb6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8abb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8abba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8abbb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8abbc  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8abc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8abc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8abc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8abc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8abc4  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8abca  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00a8abcd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8abcf  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00a8abd2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8abd4  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8abda  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a8abdd  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8abdf  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8abe5  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a8abe8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8abea  c74004f8a9a800         -mov dword ptr [eax + 4], 0xa8a9f8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 11053560 /*0xa8a9f8*/;
    // 00a8abf1  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8abf7  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a8abfa  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00a8abfd  6814a8a800             -push 0xa8a814
    app->getMemory<x86::reg32>(cpu.esp-4) = 11053076 /*0xa8a814*/;
    cpu.esp -= 4;
    // 00a8ac02  2eff151404a900         -call dword ptr cs:[0xa90414]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076628) /* 0xa90414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ac09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ac0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ac0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ac0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ac0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ac0d  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ac13  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a8ac16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ac18  7407                   -je 0xa8ac21
    if (cpu.flags.zf)
    {
        goto L_0x00a8ac21;
    }
    // 00a8ac1a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8ac1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ac1e  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00a8ac21:
    // 00a8ac21  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ac27  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00a8ac2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ac2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ac30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ac30  e97bc0ffff             -jmp 0xa86cb0
    return sub_a86cb0(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8ac38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ac38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ac39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ac3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ac3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ac3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ac3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ac3e  8b3da43ea900           -mov edi, dword ptr [0xa93ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8ac44  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8ac46  0f85c1000000           -jne 0xa8ad0d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ad0d;
    }
    // 00a8ac4c  8b2d7d27a900           -mov ebp, dword ptr [0xa9277d]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11085693) /* 0xa9277d */);
    // 00a8ac52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ac54  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00a8ac57  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8ac59  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a8ac5b  7416                   -je 0xa8ac73
    if (cpu.flags.zf)
    {
        goto L_0x00a8ac73;
    }
L_0x00a8ac5d:
    // 00a8ac5d  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8ac5f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8ac62  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a8ac64  7404                   -je 0xa8ac6a
    if (cpu.flags.zf)
    {
        goto L_0x00a8ac6a;
    }
    // 00a8ac66  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ac68  ebf3                   -jmp 0xa8ac5d
    goto L_0x00a8ac5d;
L_0x00a8ac6a:
    // 00a8ac6a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8ac6b  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a8ac6d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ac6f  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a8ac71  75ea                   -jne 0xa8ac5d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ac5d;
    }
L_0x00a8ac73:
    // 00a8ac73  893da43ea900           -mov dword ptr [0xa93ea4], edi
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.edi;
    // 00a8ac79  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8ac7b  7505                   -jne 0xa8ac82
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ac82;
    }
    // 00a8ac7d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8ac82:
    // 00a8ac82  e829c0ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ac87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8ac89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8ac8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ac8d  0f8475000000           -je 0xa8ad08
    if (cpu.flags.zf)
    {
        goto L_0x00a8ad08;
    }
    // 00a8ac93  a3304aa900             -mov dword ptr [0xa94a30], eax
    app->getMemory<x86::reg32>(x86::reg32(11094576) /* 0xa94a30 */) = cpu.eax;
    // 00a8ac98  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00a8ac9f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8aca2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8aca4  e807c0ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8aca9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8acab  7454                   -je 0xa8ad01
    if (cpu.flags.zf)
    {
        goto L_0x00a8ad01;
    }
    // 00a8acad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8acaf  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00a8acb2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8acb4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8acb6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8acb8  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a8acba  741a                   -je 0xa8acd6
    if (cpu.flags.zf)
    {
        goto L_0x00a8acd6;
    }
L_0x00a8acbc:
    // 00a8acbc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8acbe  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00a8acc1:
    // 00a8acc1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8acc2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8acc4  40                     -inc eax
    (cpu.eax)++;
    // 00a8acc5  8853ff                 -mov byte ptr [ebx - 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a8acc8  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a8acca  75f5                   -jne 0xa8acc1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8acc1;
    }
    // 00a8accc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8accf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8acd1  46                     -inc esi
    (cpu.esi)++;
    // 00a8acd2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a8acd4  75e6                   -jne 0xa8acbc
    if (!cpu.flags.zf)
    {
        goto L_0x00a8acbc;
    }
L_0x00a8acd6:
    // 00a8acd6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8acd8  c7040100000000         -mov dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a8acdf  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ace2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8ace4  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a8ace7  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8ace9  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8acee  893da43ea900           -mov dword ptr [0xa93ea4], edi
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.edi;
    // 00a8acf4  e8b7bdffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8acf9  8b3da43ea900           -mov edi, dword ptr [0xa93ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8acff  eb07                   -jmp 0xa8ad08
    goto L_0x00a8ad08;
L_0x00a8ad01:
    // 00a8ad01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ad03  e898c0ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ad08:
    // 00a8ad08  e883180000             -call 0xa8c590
    cpu.esp -= 4;
    sub_a8c590(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ad0d:
    // 00a8ad0d  8b3da43ea900           -mov edi, dword ptr [0xa93ea4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8ad13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8ad1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ad1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ad1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ad1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ad1f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ad20  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ad21  e88a190000             -call 0xa8c6b0
    cpu.esp -= 4;
    sub_a8c6b0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ad26  8b15a43ea900           -mov edx, dword ptr [0xa93ea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8ad2c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8ad2e  740f                   -je 0xa8ad3f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ad3f;
    }
    // 00a8ad30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ad32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8ad34  e867c0ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ad39  891da43ea900           -mov dword ptr [0xa93ea4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.ebx;
L_0x00a8ad3f:
    // 00a8ad3f  8b0d304aa900           -mov ecx, dword ptr [0xa94a30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11094576) /* 0xa94a30 */);
    // 00a8ad45  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8ad47  740f                   -je 0xa8ad58
    if (cpu.flags.zf)
    {
        goto L_0x00a8ad58;
    }
    // 00a8ad49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ad4b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ad4d  e84ec0ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ad52  8935304aa900           -mov dword ptr [0xa94a30], esi
    app->getMemory<x86::reg32>(x86::reg32(11094576) /* 0xa94a30 */) = cpu.esi;
L_0x00a8ad58:
    // 00a8ad58  8b3d7d27a900           -mov edi, dword ptr [0xa9277d]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085693) /* 0xa9277d */);
    // 00a8ad5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8ad60  7408                   -je 0xa8ad6a
    if (cpu.flags.zf)
    {
        goto L_0x00a8ad6a;
    }
    // 00a8ad62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ad63  2eff158c03a900         -call dword ptr cs:[0xa9038c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076492) /* 0xa9038c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8ad6a:
    // 00a8ad6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ad70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ad70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ad71  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ad74  7507                   -jne 0xa8ad7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ad7d;
    }
    // 00a8ad76  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8ad7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ad7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ad7d:
    // 00a8ad7d  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ad84  7422                   -je 0xa8ada8
    if (cpu.flags.zf)
    {
        goto L_0x00a8ada8;
    }
    // 00a8ad86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ad88  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8ad8a  8a92614aa900           -mov dl, byte ptr [edx + 0xa94a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8ad90  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8ad93  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8ad99  740d                   -je 0xa8ada8
    if (cpu.flags.zf)
    {
        goto L_0x00a8ada8;
    }
    // 00a8ad9b  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ad9f  7507                   -jne 0xa8ada8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ada8;
    }
    // 00a8ada1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8ada6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ada7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ada8:
    // 00a8ada8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8adaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8adab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8adb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8adb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8adb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8adb2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8adb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8adb7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8adb9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8adbb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8adbd  e88e190000             -call 0xa8c750
    cpu.esp -= 4;
    sub_a8c750(app, cpu);
    if (cpu.terminate) return;
    // 00a8adc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8adc4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8adc6  e8c5190000             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8adcb  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a8adce  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8add2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8add4  e877190000             -call 0xa8c750
    cpu.esp -= 4;
    sub_a8c750(app, cpu);
    if (cpu.terminate) return;
    // 00a8add9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8addb  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a8addd  e8ae190000             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8ade2  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00a8ade6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8ade8  e8d3190000             -call 0xa8c7c0
    cpu.esp -= 4;
    sub_a8c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8aded  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8adf1  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8adf5  e8c6190000             -call 0xa8c7c0
    cpu.esp -= 4;
    sub_a8c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8adfa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8adfc  e80f1a0000             -call 0xa8c810
    cpu.esp -= 4;
    sub_a8c810(app, cpu);
    if (cpu.terminate) return;
    // 00a8ae01  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8ae04  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ae10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ae10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ae11  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ae18  7420                   -je 0xa8ae3a
    if (cpu.flags.zf)
    {
        goto L_0x00a8ae3a;
    }
    // 00a8ae1a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ae1c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8ae1e  8a92614aa900           -mov dl, byte ptr [edx + 0xa94a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8ae24  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8ae27  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8ae2d  740b                   -je 0xa8ae3a
    if (cpu.flags.zf)
    {
        goto L_0x00a8ae3a;
    }
    // 00a8ae2f  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ae33  7405                   -je 0xa8ae3a
    if (cpu.flags.zf)
    {
        goto L_0x00a8ae3a;
    }
    // 00a8ae35  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8ae38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ae3a:
    // 00a8ae3a  40                     -inc eax
    (cpu.eax)++;
    // 00a8ae3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8ae40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ae40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ae41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ae42  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8ae44  ff15c426a900           -call dword ptr [0xa926c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ae4a  8b153028a900           -mov edx, dword ptr [0xa92830]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085872) /* 0xa92830 */);
    // 00a8ae50  891d3028a900           -mov dword ptr [0xa92830], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085872) /* 0xa92830 */) = cpu.ebx;
    // 00a8ae56  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ae5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ae5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ae60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ae70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ae70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ae71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ae72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ae73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ae74  ff15c426a900           -call dword ptr [0xa926c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ae7a  a17c26a900             -mov eax, dword ptr [0xa9267c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a8ae7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ae81  741c                   -je 0xa8ae9f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ae9f;
    }
L_0x00a8ae83:
    // 00a8ae83  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8ae85  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a8ae88  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8ae8b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8ae8d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8ae90  39f3                   +cmp ebx, esi
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
    // 00a8ae92  7505                   -jne 0xa8ae99
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ae99;
    }
    // 00a8ae94  e873000000             -call 0xa8af0c
    cpu.esp -= 4;
    sub_a8af0c(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ae99:
    // 00a8ae99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ae9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8ae9d  75e4                   -jne 0xa8ae83
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ae83;
    }
L_0x00a8ae9f:
    // 00a8ae9f  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8aea5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8aea7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8aea8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8aea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8aeaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8aeab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8aeac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8aeac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8aead  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8aeae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8aeaf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8aeb0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8aeb1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8aeb3  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00a8aeb8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8aeba  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8aebb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8aebe  2eff153004a900         -call dword ptr cs:[0xa90430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076656) /* 0xa90430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8aec5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8aec7  7507                   -jne 0xa8aed0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aed0;
    }
    // 00a8aec9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8aece  eb36                   -jmp 0xa8af06
    goto L_0x00a8af06;
L_0x00a8aed0:
    // 00a8aed0  3b1d8026a900           +cmp ebx, dword ptr [0xa92680]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8aed6  751c                   -jne 0xa8aef4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8aef4;
    }
    // 00a8aed8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8aeda  7408                   -je 0xa8aee4
    if (cpu.flags.zf)
    {
        goto L_0x00a8aee4;
    }
    // 00a8aedc  89358026a900           -mov dword ptr [0xa92680], esi
    app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */) = cpu.esi;
    // 00a8aee2  eb10                   -jmp 0xa8aef4
    goto L_0x00a8aef4;
L_0x00a8aee4:
    // 00a8aee4  a17c26a900             -mov eax, dword ptr [0xa9267c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a8aee9  89358426a900           -mov dword ptr [0xa92684], esi
    app->getMemory<x86::reg32>(x86::reg32(11085444) /* 0xa92684 */) = cpu.esi;
    // 00a8aeef  a38026a900             -mov dword ptr [0xa92680], eax
    app->getMemory<x86::reg32>(x86::reg32(11085440) /* 0xa92680 */) = cpu.eax;
L_0x00a8aef4:
    // 00a8aef4  3b1d5038a900           +cmp ebx, dword ptr [0xa93850]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11090000) /* 0xa93850 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8aefa  7508                   -jne 0xa8af04
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af04;
    }
    // 00a8aefc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8aefe  893d5038a900           -mov dword ptr [0xa93850], edi
    app->getMemory<x86::reg32>(x86::reg32(11090000) /* 0xa93850 */) = cpu.edi;
L_0x00a8af04:
    // 00a8af04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8af06:
    // 00a8af06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8af0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8af0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8af0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8af0e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8af11  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8af14  e893ffffff             -call 0xa8aeac
    cpu.esp -= 4;
    sub_a8aeac(app, cpu);
    if (cpu.terminate) return;
    // 00a8af19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8af1b  7516                   -jne 0xa8af33
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af33;
    }
    // 00a8af1d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8af1f  7508                   -jne 0xa8af29
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af29;
    }
    // 00a8af21  89157c26a900           -mov dword ptr [0xa9267c], edx
    app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */) = cpu.edx;
    // 00a8af27  eb03                   -jmp 0xa8af2c
    goto L_0x00a8af2c;
L_0x00a8af29:
    // 00a8af29  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00a8af2c:
    // 00a8af2c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8af2e  7403                   -je 0xa8af33
    if (cpu.flags.zf)
    {
        goto L_0x00a8af33;
    }
    // 00a8af30  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a8af33:
    // 00a8af33  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8af35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8af40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8af40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8af41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8af43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8af44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8af45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8af46  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a8af49  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8af4b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8af4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8af4f  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a8af52  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a8af55  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a8af58  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8af5b  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 00a8af5d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8af62  83f847                 +cmp eax, 0x47
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
    // 00a8af65  7523                   -jne 0xa8af8a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af8a;
    }
    // 00a8af67  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8af69  7505                   -jne 0xa8af70
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af70;
    }
    // 00a8af6b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a8af70:
    // 00a8af70  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 00a8af77  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8af7a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8af7f  83ef02                 +sub edi, 2
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
    // 00a8af82  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00a8af85  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 00a8af88  eb1f                   -jmp 0xa8afa9
    goto L_0x00a8afa9;
L_0x00a8af8a:
    // 00a8af8a  83f845                 +cmp eax, 0x45
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
    // 00a8af8d  750d                   -jne 0xa8af9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8af9c;
    }
    // 00a8af8f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8af94  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a8af97  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 00a8af9a  eb0d                   -jmp 0xa8afa9
    goto L_0x00a8afa9;
L_0x00a8af9c:
    // 00a8af9c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00a8afa1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8afa3  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a8afa6  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x00a8afa9:
    // 00a8afa9  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a8afad  7404                   -je 0xa8afb3
    if (cpu.flags.zf)
    {
        goto L_0x00a8afb3;
    }
    // 00a8afaf  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00a8afb3:
    // 00a8afb3  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8afb5  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8afb8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8afba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8afbc  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00a8afbf  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a8afc2  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a8afc5  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8afc8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8afcb  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8afce  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 00a8afd0  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8afd2  83fbff                 +cmp ebx, -1
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
    // 00a8afd5  7505                   -jne 0xa8afdc
    if (!cpu.flags.zf)
    {
        goto L_0x00a8afdc;
    }
    // 00a8afd7  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x00a8afdc:
    // 00a8afdc  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8afdf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8afe1  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 00a8afe4  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 00a8afe7  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a8afea  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8afed  e8ae190000             -call 0xa8c9a0
    cpu.esp -= 4;
    sub_a8c9a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8aff2  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a8aff5  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a8aff8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8affb  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a8affe  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a8b001  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a8b004  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8b007  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a8b00a  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b00e  7d0f                   -jge 0xa8b01f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8b01f;
    }
    // 00a8b010  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a8b013  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8b016  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a8b019  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a8b01d  eb29                   -jmp 0xa8b048
    goto L_0x00a8b048;
L_0x00a8b01f:
    // 00a8b01f  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a8b022  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8b025  740f                   -je 0xa8b036
    if (cpu.flags.zf)
    {
        goto L_0x00a8b036;
    }
    // 00a8b027  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a8b02a  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8b02d  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a8b030  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a8b034  eb12                   -jmp 0xa8b048
    goto L_0x00a8b048;
L_0x00a8b036:
    // 00a8b036  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a8b039  740d                   -je 0xa8b048
    if (cpu.flags.zf)
    {
        goto L_0x00a8b048;
    }
    // 00a8b03b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a8b03e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8b041  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a8b044  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a8b048:
    // 00a8b048  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8b04a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8b04c  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8b04f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b050  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b052  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b054(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b054  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b055  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8b057  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b059  e88c240000             -call 0xa8d4ea
    cpu.esp -= 4;
    sub_a8d4ea(app, cpu);
    if (cpu.terminate) return;
    // 00a8b05e  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8b060  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b061  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b070(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b070  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b071  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8b076  b8481da900             -mov eax, 0xa91d48
    cpu.eax = 11083080 /*0xa91d48*/;
    // 00a8b07b  e87cedffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
    // 00a8b080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b081  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b090(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b090  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b0a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b0a0  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 00a8b0a2  9b                     -wait 
    /*nothing*/;
    // 00a8b0a3  dbe3                   +fninit 
    cpu.fpu.init();
    // 00a8b0a5  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00a8b0a7  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a8b0a9  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8b0ab  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a8b0ad  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a8b0af  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00a8b0b1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a8b0b3  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00a8b0b5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a8b0b6  7402                   -je 0xa8b0ba
    if (cpu.flags.zf)
    {
        goto L_0x00a8b0ba;
    }
    // 00a8b0b8  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x00a8b0ba:
    // 00a8b0ba  9b                     -wait 
    /*nothing*/;
    // 00a8b0bb  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a8b0bd  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8b0c0  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 00a8b0c4  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8b0c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b0d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b0d1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a8b0d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b0d6  e8d5bbffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b0db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b0dd  7407                   -je 0xa8b0e6
    if (cpu.flags.zf)
    {
        goto L_0x00a8b0e6;
    }
    // 00a8b0df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b0e1  e8cab9ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b0e6:
    // 00a8b0e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b0e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b0f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b0f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b0f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b0f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b0f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b0f7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8b0f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b0fb  7509                   -jne 0xa8b106
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b106;
    }
    // 00a8b0fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b0ff  e8acbbffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b104  eb62                   -jmp 0xa8b168
    goto L_0x00a8b168;
L_0x00a8b106:
    // 00a8b106  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8b108  750d                   -jne 0xa8b117
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b117;
    }
    // 00a8b10a  e891bcffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b10f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b111  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b112  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b113  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b115  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b117:
    // 00a8b117  e8b4240000             -call 0xa8d5d0
    cpu.esp -= 4;
    sub_a8d5d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b11c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8b11e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b120  e8bb240000             -call 0xa8d5e0
    cpu.esp -= 4;
    sub_a8d5e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b125  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8b127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b129  753b                   -jne 0xa8b166
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b166;
    }
    // 00a8b12b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b12d  e87ebbffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b132  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8b134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b136  7425                   -je 0xa8b15d
    if (cpu.flags.zf)
    {
        goto L_0x00a8b15d;
    }
    // 00a8b138  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8b13a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8b13c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a8b13e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8b13f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8b141  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8b143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b144  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b146  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8b149  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8b14b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8b14d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8b150  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8b152  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b153  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8b154  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b156  e845bcffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b15b  eb09                   -jmp 0xa8b166
    goto L_0x00a8b166;
L_0x00a8b15d:
    // 00a8b15d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8b15f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b161  e87a240000             -call 0xa8d5e0
    cpu.esp -= 4;
    sub_a8d5e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b166:
    // 00a8b166  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a8b168:
    // 00a8b168  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b169  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b16a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b16b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b16c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b16d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a8b170(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b171  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b172  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b173  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b175  e81ed7ffff             -call 0xa88898
    cpu.esp -= 4;
    sub_a88898(app, cpu);
    if (cpu.terminate) return;
    // 00a8b17a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b17c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b17e  7410                   -je 0xa8b190
    if (cpu.flags.zf)
    {
        goto L_0x00a8b190;
    }
    // 00a8b180  8b15a426a900           -mov edx, dword ptr [0xa926a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a8b186  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b187  2eff152004a900         -call dword ptr cs:[0xa90420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076640) /* 0xa90420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b18e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a8b190:
    // 00a8b190  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8b192  750f                   -jne 0xa8b1a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b1a3;
    }
    // 00a8b194  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8b199  b86c1da900             -mov eax, 0xa91d6c
    cpu.eax = 11083116 /*0xa91d6c*/;
    // 00a8b19e  e859ecffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b1a3:
    // 00a8b1a3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b1a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b1a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b1a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8b1ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b1ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b1ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b1ae  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b1af  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b1b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b1b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b1b2  ff15d426a900           -call dword ptr [0xa926d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b1b8  2eff15ac03a900         -call dword ptr cs:[0xa903ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076524) /* 0xa903ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b1bf  8b1d404aa900           -mov ebx, dword ptr [0xa94a40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */);
    // 00a8b1c5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8b1c7  740b                   -je 0xa8b1d4
    if (cpu.flags.zf)
    {
        goto L_0x00a8b1d4;
    }
L_0x00a8b1c9:
    // 00a8b1c9  3b4304                 +cmp eax, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b1cc  7406                   -je 0xa8b1d4
    if (cpu.flags.zf)
    {
        goto L_0x00a8b1d4;
    }
    // 00a8b1ce  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8b1d0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8b1d2  75f5                   -jne 0xa8b1c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b1c9;
    }
L_0x00a8b1d4:
    // 00a8b1d4  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b1d8  7425                   -je 0xa8b1ff
    if (cpu.flags.zf)
    {
        goto L_0x00a8b1ff;
    }
    // 00a8b1da  8b154c28a900           -mov edx, dword ptr [0xa9284c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8b1e0  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8b1e3  e808ffffff             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b1e8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8b1ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b1ec  755e                   -jne 0xa8b24c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b24c;
    }
    // 00a8b1ee  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8b1f3  b8941da900             -mov eax, 0xa91d94
    cpu.eax = 11083156 /*0xa91d94*/;
    // 00a8b1f8  e8ffebffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
    // 00a8b1fd  eb4d                   -jmp 0xa8b24c
    goto L_0x00a8b24c;
L_0x00a8b1ff:
    // 00a8b1ff  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8b204  8b154c28a900           -mov edx, dword ptr [0xa9284c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8b20a  e8c1feffff             -call 0xa8b0d0
    cpu.esp -= 4;
    sub_a8b0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b20f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8b211  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b213  750f                   -jne 0xa8b224
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b224;
    }
    // 00a8b215  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8b21a  b8bc1da900             -mov eax, 0xa91dbc
    cpu.eax = 11083196 /*0xa91dbc*/;
    // 00a8b21f  e8d8ebffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b224:
    // 00a8b224  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8b227  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a8b229  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00a8b22f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8b230  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8b232  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8b234  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b235  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b237  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8b23a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8b23c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8b23e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8b241  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8b243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b244  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8b245  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a8b24c:
    // 00a8b24c  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a8b24f  a14c28a900             -mov eax, dword ptr [0xa9284c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8b254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b255  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a8b259  8b35a426a900           -mov esi, dword ptr [0xa926a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a8b25f  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00a8b263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b264  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a8b26a  2eff152404a900         -call dword ptr cs:[0xa90424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076644) /* 0xa90424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b271  ff15d826a900           -call dword ptr [0xa926d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b277  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8b279  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b27f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b280(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b282  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b283  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8b285  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8b287  ff15d426a900           -call dword ptr [0xa926d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b28d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a8b292  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00a8b297  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b299  e832feffff             -call 0xa8b0d0
    cpu.esp -= 4;
    sub_a8b0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b29e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8b2a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b2a2  742f                   -je 0xa8b2d3
    if (cpu.flags.zf)
    {
        goto L_0x00a8b2d3;
    }
    // 00a8b2a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b2a6  e849250000             -call 0xa8d7f4
    cpu.esp -= 4;
    sub_a8d7f4(app, cpu);
    if (cpu.terminate) return;
    // 00a8b2ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b2ad  7409                   -je 0xa8b2b8
    if (cpu.flags.zf)
    {
        goto L_0x00a8b2b8;
    }
    // 00a8b2af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b2b1  e8eabaffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b2b6  eb1b                   -jmp 0xa8b2d3
    goto L_0x00a8b2d3;
L_0x00a8b2b8:
    // 00a8b2b8  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a8b2bb  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a8b2be  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00a8b2c1  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8b2c4  a1404aa900             -mov eax, dword ptr [0xa94a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */);
    // 00a8b2c9  8915404aa900           -mov dword ptr [0xa94a40], edx
    app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */) = cpu.edx;
    // 00a8b2cf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8b2d1  eb02                   -jmp 0xa8b2d5
    goto L_0x00a8b2d5;
L_0x00a8b2d3:
    // 00a8b2d3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a8b2d5:
    // 00a8b2d5  ff15d826a900           -call dword ptr [0xa926d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b2db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b2dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b2de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b2df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b2e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8b2e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b2e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b2e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b2e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b2e7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b2e9  ff15d426a900           -call dword ptr [0xa926d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b2ef  8b15404aa900           -mov edx, dword ptr [0xa94a40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */);
    // 00a8b2f5  b9404aa900             -mov ecx, 0xa94a40
    cpu.ecx = 11094592 /*0xa94a40*/;
    // 00a8b2fa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8b2fc  7428                   -je 0xa8b326
    if (cpu.flags.zf)
    {
        goto L_0x00a8b326;
    }
L_0x00a8b2fe:
    // 00a8b2fe  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b301  751b                   -jne 0xa8b31e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b31e;
    }
    // 00a8b303  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00a8b307  7408                   -je 0xa8b311
    if (cpu.flags.zf)
    {
        goto L_0x00a8b311;
    }
    // 00a8b309  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8b30c  e88fbaffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b311:
    // 00a8b311  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8b313  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8b315  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b317  e884baffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b31c  eb08                   -jmp 0xa8b326
    goto L_0x00a8b326;
L_0x00a8b31e:
    // 00a8b31e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8b320  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8b322  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8b324  75d8                   -jne 0xa8b2fe
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b2fe;
    }
L_0x00a8b326:
    // 00a8b326  ff15d826a900           -call dword ptr [0xa926d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b32c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b32d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b32e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b32f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b330(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b330  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b331  ff15d426a900           -call dword ptr [0xa926d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b337  a1404aa900             -mov eax, dword ptr [0xa94a40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */);
    // 00a8b33c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b33e  740d                   -je 0xa8b34d
    if (cpu.flags.zf)
    {
        goto L_0x00a8b34d;
    }
L_0x00a8b340:
    // 00a8b340  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8b343  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00a8b347  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8b349  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b34b  75f3                   -jne 0xa8b340
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b340;
    }
L_0x00a8b34d:
    // 00a8b34d  ff15d826a900           -call dword ptr [0xa926d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b353  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b354  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8b358(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b358  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b35a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b35b  8b15404aa900           -mov edx, dword ptr [0xa94a40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11094592) /* 0xa94a40 */);
    // 00a8b361  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8b363  741e                   -je 0xa8b383
    if (cpu.flags.zf)
    {
        goto L_0x00a8b383;
    }
L_0x00a8b365:
    // 00a8b365  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8b368  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8b36a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8b36c  7408                   -je 0xa8b376
    if (cpu.flags.zf)
    {
        goto L_0x00a8b376;
    }
    // 00a8b36e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8b371  e82abaffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8b376:
    // 00a8b376  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b378  e823baffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b37d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8b37f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8b381  75e2                   -jne 0xa8b365
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b365;
    }
L_0x00a8b383:
    // 00a8b383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b386  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b391  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b392  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b394  ff15d426a900           -call dword ptr [0xa926d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b39a  8b154c28a900           -mov edx, dword ptr [0xa9284c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8b3a0  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a8b3a3  a34c28a900             -mov dword ptr [0xa9284c], eax
    app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */) = cpu.eax;
    // 00a8b3a8  e883ffffff             -call 0xa8b330
    cpu.esp -= 4;
    sub_a8b330(app, cpu);
    if (cpu.terminate) return;
    // 00a8b3ad  ff15d826a900           -call dword ptr [0xa926d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b3b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b3b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b3b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b3c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b3c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b3c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b3c3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b3c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b3c7  741b                   -je 0xa8b3e4
    if (cpu.flags.zf)
    {
        goto L_0x00a8b3e4;
    }
    // 00a8b3c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b3cb  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00a8b3d2  e839f3ffff             -call 0xa8a710
    cpu.esp -= 4;
    sub_a8a710(app, cpu);
    if (cpu.terminate) return;
    // 00a8b3d7  2eff15ac03a900         -call dword ptr cs:[0xa903ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076524) /* 0xa903ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b3de  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00a8b3e4:
    // 00a8b3e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b3e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b3e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b3e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8b3f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b3f0  e963ffffff             -jmp 0xa8b358
    return sub_a8b358(app, cpu);
}

/* align: skip 0x00 */
void sub_a8b3f6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b3f6  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8b3f8  750b                   -jne 0xa8b405
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b405;
    }
    // 00a8b3fa  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b3fc  7505                   -jne 0xa8b403
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b403;
    }
    // 00a8b3fe  e94a240000             -jmp 0xa8d84d
    return sub_a8d84d(app, cpu);
L_0x00a8b403:
    // 00a8b403  d1d9                   -rcr ecx, 1
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
L_0x00a8b405:
    // 00a8b405  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b407  7507                   -jne 0xa8b410
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b410;
    }
    // 00a8b409  01d2                   +add edx, edx
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
    // 00a8b40b  7501                   -jne 0xa8b40e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b40e;
    }
    // 00a8b40d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b40e:
    // 00a8b40e  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
L_0x00a8b410:
    // 00a8b410  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b417  7430                   -je 0xa8b449
    if (cpu.flags.zf)
    {
        goto L_0x00a8b449;
    }
    // 00a8b419  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b41a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b41b  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00a8b41e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b41f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b420  f6059026a90001         +test byte ptr [0xa92690], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(11085456) /* 0xa92690 */) & 1 /*0x1*/));
    // 00a8b427  7407                   -je 0xa8b430
    if (cpu.flags.zf)
    {
        goto L_0x00a8b430;
    }
    // 00a8b429  e872c3ffff             -call 0xa877a0
    cpu.esp -= 4;
    sub_a877a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b42e  eb06                   -jmp 0xa8b436
    goto L_0x00a8b436;
L_0x00a8b430:
    // 00a8b430  dc3424                 -fdiv qword ptr [esp]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<double>(cpu.esp));
    // 00a8b433  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00a8b436:
    // 00a8b436  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8b439  9b                     -wait 
    /*nothing*/;
    // 00a8b43a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b43b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b43c  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b442  7504                   -jne 0xa8b448
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b448;
    }
    // 00a8b444  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b446  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8b448:
    // 00a8b448  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b449:
    // 00a8b449  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b44a  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8b44c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b44d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b44e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b450  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b452  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00a8b455  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00a8b458  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b45e  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b464  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b467  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b46a  6601cf                 -add di, cx
    (cpu.di) += x86::reg16(x86::sreg16(cpu.cx));
    // 00a8b46d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b470  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b473  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b479  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b47f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00a8b482  7408                   -je 0xa8b48c
    if (cpu.flags.zf)
    {
        goto L_0x00a8b48c;
    }
    // 00a8b484  81ca00001000           +or edx, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 00a8b48a  eb0e                   -jmp 0xa8b49a
    goto L_0x00a8b49a;
L_0x00a8b48c:
    // 00a8b48c  01c0                   +add eax, eax
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
    // 00a8b48e  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8b490  664f                   -dec di
    (cpu.di)--;
    // 00a8b492  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 00a8b498  74f2                   -je 0xa8b48c
    if (cpu.flags.zf)
    {
        goto L_0x00a8b48c;
    }
L_0x00a8b49a:
    // 00a8b49a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00a8b49d  7408                   -je 0xa8b4a7
    if (cpu.flags.zf)
    {
        goto L_0x00a8b4a7;
    }
    // 00a8b49f  81ce00001000           +or esi, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 00a8b4a5  eb0e                   -jmp 0xa8b4b5
    goto L_0x00a8b4b5;
L_0x00a8b4a7:
    // 00a8b4a7  01db                   +add ebx, ebx
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
    // 00a8b4a9  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00a8b4ab  6649                   -dec cx
    (cpu.cx)--;
    // 00a8b4ad  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 00a8b4b3  74f2                   -je 0xa8b4a7
    if (cpu.flags.zf)
    {
        goto L_0x00a8b4a7;
    }
L_0x00a8b4b5:
    // 00a8b4b5  6629cf                 -sub di, cx
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.cx));
    // 00a8b4b8  6681c7ff03             +add di, 0x3ff
    {
        x86::reg16& tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) == (1 & (tmp2 >> 15));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b4bd  7811                   -js 0xa8b4d0
    if (cpu.flags.sf)
    {
        goto L_0x00a8b4d0;
    }
    // 00a8b4bf  6681ffff07             +cmp di, 0x7ff
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b4c4  720a                   -jb 0xa8b4d0
    if (cpu.flags.cf)
    {
        goto L_0x00a8b4d0;
    }
    // 00a8b4c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b4c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4cb  e989230000             -jmp 0xa8d859
    return sub_a8d859(app, cpu);
L_0x00a8b4d0:
    // 00a8b4d0  6683ffcc               +cmp di, -0x34
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-52 /*-0x34*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b4d4  7d08                   -jge 0xa8b4de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8b4de;
    }
    // 00a8b4d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b4d9  e95e230000             -jmp 0xa8d83c
    return sub_a8d83c(app, cpu);
L_0x00a8b4de:
    // 00a8b4de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b4df  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00a8b4e1  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 00a8b4e4  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00a8b4e7  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00a8b4ec  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 00a8b4ef  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00a8b4f2  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00a8b4f8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b4f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b4fa  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8b4fc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b4fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8b500  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b502  39d1                   +cmp ecx, edx
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
    // 00a8b504  7703                   -ja 0xa8b509
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8b509;
    }
    // 00a8b506  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8b508  40                     -inc eax
    (cpu.eax)++;
L_0x00a8b509:
    // 00a8b509  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b50a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8b50c  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8b50e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b50f  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b510  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00a8b512  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b513  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 00a8b515  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00a8b517  01d8                   +add eax, ebx
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
    // 00a8b519  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b51c  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8b51f  f645e801               +test byte ptr [ebp - 0x18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */) & 1 /*0x1*/));
    // 00a8b523  7405                   -je 0xa8b52a
    if (cpu.flags.zf)
    {
        goto L_0x00a8b52a;
    }
    // 00a8b525  01d8                   +add eax, ebx
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
    // 00a8b527  1355f0                 -adc edx, dword ptr [ebp - 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) + cpu.flags.cf);
L_0x00a8b52a:
    // 00a8b52a  f7d9                   +neg ecx
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
    // 00a8b52c  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b52e  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b530  7412                   -je 0xa8b544
    if (cpu.flags.zf)
    {
        goto L_0x00a8b544;
    }
L_0x00a8b532:
    // 00a8b532  836de401               +sub dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b536  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b53a  01d9                   +add ecx, ebx
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
    // 00a8b53c  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b53f  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b542  75ee                   -jne 0xa8b532
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b532;
    }
L_0x00a8b544:
    // 00a8b544  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8b546  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b548  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8b54b  39f9                   +cmp ecx, edi
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
    // 00a8b54d  770a                   -ja 0xa8b559
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8b559;
    }
    // 00a8b54f  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8b551  8345e401               +add dword ptr [ebp - 0x1c], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b555  8355e800               -adc dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00a8b559:
    // 00a8b559  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8b55b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8b55d  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8b55f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b560  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b562  742c                   -je 0xa8b590
    if (cpu.flags.zf)
    {
        goto L_0x00a8b590;
    }
    // 00a8b564  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b565  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00a8b567  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b568  87d3                   -xchg ebx, edx
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.edx;
        cpu.edx = tmp;
    }
    // 00a8b56a  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00a8b56c  01d8                   +add eax, ebx
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
    // 00a8b56e  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b571  f7d9                   +neg ecx
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
    // 00a8b573  19c6                   +sbb esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b575  19d7                   +sbb edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b577  7417                   -je 0xa8b590
    if (cpu.flags.zf)
    {
        goto L_0x00a8b590;
    }
L_0x00a8b579:
    // 00a8b579  836de001               +sub dword ptr [ebp - 0x20], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b57d  835de400               +sbb dword ptr [ebp - 0x1c], 0
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b581  835de800               -sbb dword ptr [ebp - 0x18], 0
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b585  034dec                 +add ecx, dword ptr [ebp - 0x14]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b588  1375f0                 +adc esi, dword ptr [ebp - 0x10]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b58b  83d700                 +adc edi, 0
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b58e  75e9                   -jne 0xa8b579
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b579;
    }
L_0x00a8b590:
    // 00a8b590  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b591  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b592  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b593  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8b596  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b597  664f                   -dec di
    (cpu.di)--;
    // 00a8b599  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b59b  7305                   -jae 0xa8b5a2
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b5a2;
    }
    // 00a8b59d  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 00a8b59f  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b5a1  47                     -inc edi
    (cpu.edi)++;
L_0x00a8b5a2:
    // 00a8b5a2  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8b5a4  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00a8b5a6  0fadd0                 +shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        cpu.flags.cf = 1 & (destination >> (cpu.cl - 1));
        cpu.flags.of = 1 & (destination >> (32 - 1));
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
        cpu.flags.of ^= 1 & (destination >> (32 - 1));
        cpu.set_szp(destination);
    }
    // 00a8b5a9  d1de                   -rcr esi, 1
    {
        x86::reg32& op = cpu.esi;
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
    // 00a8b5ab  0fadf2                 -shrd edx, esi, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.esi  << (32 - (cpu.cl % 32));
    }
    // 00a8b5ae  81ca0000f0ff           -or edx, 0xfff00000
    cpu.edx |= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00a8b5b4  01f6                   +add esi, esi
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
    // 00a8b5b6  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b5b9  83d200                 +adc edx, 0
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
    // 00a8b5bc  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b5bf  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00a8b5c2  7f1d                   -jg 0xa8b5e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8b5e1;
    }
    // 00a8b5c4  7504                   -jne 0xa8b5ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b5ca;
    }
    // 00a8b5c6  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a8b5c8  eb06                   -jmp 0xa8b5d0
    goto L_0x00a8b5d0;
L_0x00a8b5ca:
    // 00a8b5ca  66f7df                 -neg di
    cpu.di = ~cpu.di + 1;
    // 00a8b5cd  6689f9                 -mov cx, di
    cpu.cx = cpu.di;
L_0x00a8b5d0:
    // 00a8b5d0  81e2ffff1f00           -and edx, 0x1fffff
    cpu.edx &= x86::reg32(x86::sreg32(2097151 /*0x1fffff*/));
    // 00a8b5d6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b5d8  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00a8b5db  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00a8b5de  6629ff                 -sub di, di
    (cpu.di) -= x86::reg16(x86::sreg16(cpu.di));
L_0x00a8b5e1:
    // 00a8b5e1  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b5e7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00a8b5e9  c1cf0b                 -ror edi, 0xb
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00a8b5ec  01f6                   +add esi, esi
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
    // 00a8b5ee  d1df                   -rcr edi, 1
    {
        x86::reg32& op = cpu.edi;
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
    // 00a8b5f0  81e70000f0ff           -and edi, 0xfff00000
    cpu.edi &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00a8b5f6  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8b5f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b5f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b5fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b5fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b5fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b5fc  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8b602  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8b604  7506                   -jne 0xa8b60c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b60c;
    }
    // 00a8b606  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b608  740e                   -je 0xa8b618
    if (cpu.flags.zf)
    {
        goto L_0x00a8b618;
    }
    // 00a8b60a  d1d9                   -rcr ecx, 1
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
L_0x00a8b60c:
    // 00a8b60c  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b60e  750b                   -jne 0xa8b61b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b61b;
    }
    // 00a8b610  01d2                   +add edx, edx
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
    // 00a8b612  7505                   -jne 0xa8b619
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b619;
    }
    // 00a8b614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8b616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8b618:
    // 00a8b618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b619:
    // 00a8b619  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
L_0x00a8b61b:
    // 00a8b61b  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b622  7421                   -je 0xa8b645
    if (cpu.flags.zf)
    {
        goto L_0x00a8b645;
    }
    // 00a8b624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b626  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00a8b629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b62a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b62b  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
    // 00a8b62e  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8b632  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8b635  9b                     -wait 
    /*nothing*/;
    // 00a8b636  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b637  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b638  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b63e  7504                   -jne 0xa8b644
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b644;
    }
    // 00a8b640  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b642  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8b644:
    // 00a8b644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b645:
    // 00a8b645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b647  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b648  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b64a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b64c  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00a8b64f  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00a8b652  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b658  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b65e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a8b660  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b663  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b666  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00a8b669  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b66c  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b66f  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b675  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b67b  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00a8b67e  7406                   -je 0xa8b686
    if (cpu.flags.zf)
    {
        goto L_0x00a8b686;
    }
    // 00a8b680  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00a8b686:
    // 00a8b686  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00a8b689  7406                   -je 0xa8b691
    if (cpu.flags.zf)
    {
        goto L_0x00a8b691;
    }
    // 00a8b68b  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00a8b691:
    // 00a8b691  01c0                   +add eax, eax
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
    // 00a8b693  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8b695  01db                   +add ebx, ebx
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
    // 00a8b697  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00a8b699  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b69c  742f                   -je 0xa8b6cd
    if (cpu.flags.zf)
    {
        goto L_0x00a8b6cd;
    }
    // 00a8b69e  7308                   -jae 0xa8b6a8
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b6a8;
    }
    // 00a8b6a0  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00a8b6a2  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00a8b6a5  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b6a6  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x00a8b6a8:
    // 00a8b6a8  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b6ac  761f                   -jbe 0xa8b6cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8b6cd;
    }
    // 00a8b6ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8b6b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b6b2  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b6b4  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 00a8b6b6  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b6b8  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00a8b6be  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00a8b6c1  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a8b6c7  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8b6c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b6cd:
    // 00a8b6cd  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8b6cf  790d                   -jns 0xa8b6de
    if (!cpu.flags.sf)
    {
        goto L_0x00a8b6de;
    }
    // 00a8b6d1  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a8b6d3  f7db                   +neg ebx
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
    // 00a8b6d5  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b6d8  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00a8b6de:
    // 00a8b6de  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8b6e0  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b6e3  7423                   -je 0xa8b708
    if (cpu.flags.zf)
    {
        goto L_0x00a8b708;
    }
    // 00a8b6e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b6e6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6e8  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b6eb  720d                   -jb 0xa8b6fa
    if (cpu.flags.cf)
    {
        goto L_0x00a8b6fa;
    }
    // 00a8b6ed  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b6ef  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b6f2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8b6f4  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b6f8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a8b6fa:
    // 00a8b6fa  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00a8b6fd  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6ff  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b701  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00a8b704  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00a8b707  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8b708:
    // 00a8b708  01d8                   +add eax, ebx
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
    // 00a8b70a  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b70c  7923                   -jns 0xa8b731
    if (!cpu.flags.sf)
    {
        goto L_0x00a8b731;
    }
    // 00a8b70e  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b711  7211                   -jb 0xa8b724
    if (cpu.flags.cf)
    {
        goto L_0x00a8b724;
    }
    // 00a8b713  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 00a8b719  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b71c  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b71e  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b721  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00a8b724:
    // 00a8b724  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8b726  f7d8                   +neg eax
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
    // 00a8b728  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b72b  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00a8b731:
    // 00a8b731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b733  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8b735  746a                   -je 0xa8b7a1
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a1;
    }
    // 00a8b737  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00a8b73a  7469                   -je 0xa8b7a5
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a5;
    }
L_0x00a8b73c:
    // 00a8b73c  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00a8b742  750a                   -jne 0xa8b74e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b74e;
    }
    // 00a8b744  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 00a8b746  745d                   -je 0xa8b7a5
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a5;
    }
    // 00a8b748  01c0                   +add eax, eax
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
    // 00a8b74a  11d2                   +adc edx, edx
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
    // 00a8b74c  ebee                   -jmp 0xa8b73c
    goto L_0x00a8b73c;
L_0x00a8b74e:
    // 00a8b74e  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 00a8b754  7410                   -je 0xa8b766
    if (cpu.flags.zf)
    {
        goto L_0x00a8b766;
    }
    // 00a8b756  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b758  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b75a  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b75d  6645                   -inc bp
    (cpu.bp)++;
    // 00a8b75f  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b764  7449                   -je 0xa8b7af
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7af;
    }
L_0x00a8b766:
    // 00a8b766  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b768  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b76a  7324                   -jae 0xa8b790
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b790;
    }
    // 00a8b76c  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a8b76e  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b771  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b773  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b775  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b778  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b77b  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00a8b781  740d                   -je 0xa8b790
    if (cpu.flags.zf)
    {
        goto L_0x00a8b790;
    }
    // 00a8b783  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b785  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b787  6645                   -inc bp
    (cpu.bp)++;
    // 00a8b789  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b78e  741f                   -je 0xa8b7af
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7af;
    }
L_0x00a8b790:
    // 00a8b790  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b796  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00a8b798  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 00a8b79b  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b79d  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 00a8b79f  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a8b7a1:
    // 00a8b7a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7a5:
    // 00a8b7a5  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b7a7  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 00a8b7a9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7af:
    // 00a8b7af  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8b7b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b4  e9a0200000             -jmp 0xa8d859
    return sub_a8d859(app, cpu);
}

/* align: skip  */
void sub_a8b62e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8b62e;
    // 00a8b5fc  81f100000080           -xor ecx, 0x80000000
    cpu.ecx ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8b602  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8b604  7506                   -jne 0xa8b60c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b60c;
    }
    // 00a8b606  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b608  740e                   -je 0xa8b618
    if (cpu.flags.zf)
    {
        goto L_0x00a8b618;
    }
    // 00a8b60a  d1d9                   -rcr ecx, 1
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
L_0x00a8b60c:
    // 00a8b60c  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b60e  750b                   -jne 0xa8b61b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b61b;
    }
    // 00a8b610  01d2                   +add edx, edx
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
    // 00a8b612  7505                   -jne 0xa8b619
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b619;
    }
    // 00a8b614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8b616  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8b618:
    // 00a8b618  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b619:
    // 00a8b619  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
L_0x00a8b61b:
    // 00a8b61b  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b622  7421                   -je 0xa8b645
    if (cpu.flags.zf)
    {
        goto L_0x00a8b645;
    }
    // 00a8b624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b625  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b626  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00a8b629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b62a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b62b  dc0424                 -fadd qword ptr [esp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(cpu.esp));
L_entry_0x00a8b62e:
    // 00a8b62e  dd5c2408               -fstp qword ptr [esp + 8]
    app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8b632  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8b635  9b                     -wait 
    /*nothing*/;
    // 00a8b636  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b637  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b638  81fa00000080           +cmp edx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b63e  7504                   -jne 0xa8b644
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b644;
    }
    // 00a8b640  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8b642  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8b644:
    // 00a8b644  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b645:
    // 00a8b645  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b646  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b647  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b648  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b64a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b64c  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00a8b64f  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00a8b652  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b658  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b65e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a8b660  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b663  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b666  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00a8b669  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b66c  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b66f  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b675  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b67b  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00a8b67e  7406                   -je 0xa8b686
    if (cpu.flags.zf)
    {
        goto L_0x00a8b686;
    }
    // 00a8b680  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00a8b686:
    // 00a8b686  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00a8b689  7406                   -je 0xa8b691
    if (cpu.flags.zf)
    {
        goto L_0x00a8b691;
    }
    // 00a8b68b  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
L_0x00a8b691:
    // 00a8b691  01c0                   +add eax, eax
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
    // 00a8b693  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8b695  01db                   +add ebx, ebx
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
    // 00a8b697  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00a8b699  6629f9                 +sub cx, di
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b69c  742f                   -je 0xa8b6cd
    if (cpu.flags.zf)
    {
        goto L_0x00a8b6cd;
    }
    // 00a8b69e  7308                   -jae 0xa8b6a8
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b6a8;
    }
    // 00a8b6a0  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 00a8b6a2  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00a8b6a5  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b6a6  87f2                   -xchg edx, esi
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.esi;
        cpu.esi = tmp;
    }
L_0x00a8b6a8:
    // 00a8b6a8  6683f936               +cmp cx, 0x36
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(54 /*0x36*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b6ac  761f                   -jbe 0xa8b6cd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8b6cd;
    }
    // 00a8b6ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8b6b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b6b2  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b6b4  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 00a8b6b6  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b6b8  81e2ffff0f80           -and edx, 0x800fffff
    cpu.edx &= x86::reg32(x86::sreg32(2148532223 /*0x800fffff*/));
    // 00a8b6be  c1cd0d                 -ror ebp, 0xd
    {
        x86::reg32& op = cpu.ebp;
        x86::reg32 shift = 13 /*0xd*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00a8b6c1  81e50000f07f           -and ebp, 0x7ff00000
    cpu.ebp &= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a8b6c7  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8b6c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b6cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b6cd:
    // 00a8b6cd  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8b6cf  790d                   -jns 0xa8b6de
    if (!cpu.flags.sf)
    {
        goto L_0x00a8b6de;
    }
    // 00a8b6d1  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a8b6d3  f7db                   +neg ebx
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
    // 00a8b6d5  83de00                 -sbb esi, 0
    (cpu.esi) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b6d8  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00a8b6de:
    // 00a8b6de  29ff                   -sub edi, edi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8b6e0  80f900                 +cmp cl, 0
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b6e3  7423                   -je 0xa8b708
    if (cpu.flags.zf)
    {
        goto L_0x00a8b708;
    }
    // 00a8b6e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b6e6  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6e8  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b6eb  720d                   -jb 0xa8b6fa
    if (cpu.flags.cf)
    {
        goto L_0x00a8b6fa;
    }
    // 00a8b6ed  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b6ef  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b6f2  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8b6f4  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8b6f8  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a8b6fa:
    // 00a8b6fa  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00a8b6fd  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b6ff  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b701  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00a8b704  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00a8b707  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8b708:
    // 00a8b708  01d8                   +add eax, ebx
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
    // 00a8b70a  11f2                   +adc edx, esi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b70c  7923                   -jns 0xa8b731
    if (!cpu.flags.sf)
    {
        goto L_0x00a8b731;
    }
    // 00a8b70e  80f935                 +cmp cl, 0x35
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b711  7211                   -jb 0xa8b724
    if (cpu.flags.cf)
    {
        goto L_0x00a8b724;
    }
    // 00a8b713  f7c7ffffff7f           +test edi, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2147483647 /*0x7fffffff*/));
    // 00a8b719  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b71c  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b71e  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b721  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
L_0x00a8b724:
    // 00a8b724  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8b726  f7d8                   +neg eax
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
    // 00a8b728  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b72b  81f500000080           -xor ebp, 0x80000000
    cpu.ebp ^= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
L_0x00a8b731:
    // 00a8b731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b733  09d3                   +or ebx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8b735  746a                   -je 0xa8b7a1
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a1;
    }
    // 00a8b737  6609ed                 +or bp, bp
    cpu.clear_co();
    cpu.set_szp((cpu.bp |= x86::reg16(x86::sreg16(cpu.bp))));
    // 00a8b73a  7469                   -je 0xa8b7a5
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a5;
    }
L_0x00a8b73c:
    // 00a8b73c  f7c20000e07f           +test edx, 0x7fe00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2145386496 /*0x7fe00000*/));
    // 00a8b742  750a                   -jne 0xa8b74e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b74e;
    }
    // 00a8b744  664d                   +dec bp
    {
        x86::reg16& tmp = cpu.bp;
        cpu.flags.of = 1 & (tmp >> 15);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 15));
        cpu.set_szp(tmp);
    }
    // 00a8b746  745d                   -je 0xa8b7a5
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7a5;
    }
    // 00a8b748  01c0                   +add eax, eax
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
    // 00a8b74a  11d2                   +adc edx, edx
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
    // 00a8b74c  ebee                   -jmp 0xa8b73c
    goto L_0x00a8b73c;
L_0x00a8b74e:
    // 00a8b74e  f7c200004000           +test edx, 0x400000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4194304 /*0x400000*/));
    // 00a8b754  7410                   -je 0xa8b766
    if (cpu.flags.zf)
    {
        goto L_0x00a8b766;
    }
    // 00a8b756  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b758  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b75a  83d700                 -adc edi, 0
    (cpu.edi) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b75d  6645                   -inc bp
    (cpu.bp)++;
    // 00a8b75f  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b764  7449                   -je 0xa8b7af
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7af;
    }
L_0x00a8b766:
    // 00a8b766  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b768  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b76a  7324                   -jae 0xa8b790
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b790;
    }
    // 00a8b76c  09ff                   +or edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi |= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a8b76e  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b771  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b773  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b775  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b778  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b77b  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00a8b781  740d                   -je 0xa8b790
    if (cpu.flags.zf)
    {
        goto L_0x00a8b790;
    }
    // 00a8b783  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b785  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b787  6645                   -inc bp
    (cpu.bp)++;
    // 00a8b789  6681fdff07             +cmp bp, 0x7ff
    {
        x86::reg16 tmp1 = cpu.bp;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b78e  741f                   -je 0xa8b7af
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7af;
    }
L_0x00a8b790:
    // 00a8b790  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b796  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00a8b798  c1e515                 -shl ebp, 0x15
    cpu.ebp <<= 21 /*0x15*/ % 32;
    // 00a8b79b  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b79d  d1dd                   -rcr ebp, 1
    {
        x86::reg32& op = cpu.ebp;
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
    // 00a8b79f  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a8b7a1:
    // 00a8b7a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7a5:
    // 00a8b7a5  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b7a7  d1da                   +rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
    // 00a8b7a9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b7ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ac  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7af:
    // 00a8b7af  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8b7b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b7b4  e9a0200000             -jmp 0xa8d859
    return sub_a8d859(app, cpu);
}

/* align: skip  */
void sub_a8b7b9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b7b9  09c0                   +or eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8b7bb  7507                   -jne 0xa8b7c4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b7c4;
    }
    // 00a8b7bd  01d2                   +add edx, edx
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
    // 00a8b7bf  7501                   -jne 0xa8b7c2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b7c2;
    }
    // 00a8b7c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7c2:
    // 00a8b7c2  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
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
L_0x00a8b7c4:
    // 00a8b7c4  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8b7c6  750b                   -jne 0xa8b7d3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b7d3;
    }
    // 00a8b7c8  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b7ca  7505                   -jne 0xa8b7d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b7d1;
    }
    // 00a8b7cc  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8b7ce  29d2                   +sub edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b7d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b7d1:
    // 00a8b7d1  d1d9                   -rcr ecx, 1
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
L_0x00a8b7d3:
    // 00a8b7d3  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8b7da  740f                   -je 0xa8b7eb
    if (cpu.flags.zf)
    {
        goto L_0x00a8b7eb;
    }
    // 00a8b7dc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b7dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b7de  dd0424                 +fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00a8b7e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b7e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b7e3  dc0c24                 +fmul qword ptr [esp]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(cpu.esp));
    // 00a8b7e6  e943feffff             -jmp 0xa8b62e
    return sub_a8b62e(app, cpu);
L_0x00a8b7eb:
    // 00a8b7eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b7ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8b7ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b7ee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b7f0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b7f2  c1ff14                 -sar edi, 0x14
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (20 /*0x14*/ % 32));
    // 00a8b7f5  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00a8b7f8  81e7ff070080           -and edi, 0x800007ff
    cpu.edi &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b7fe  81e1ff070080           -and ecx, 0x800007ff
    cpu.ecx &= x86::reg32(x86::sreg32(2147485695 /*0x800007ff*/));
    // 00a8b804  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b807  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b80a  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00a8b80d  c1c710                 -rol edi, 0x10
    {
        x86::reg32& op = cpu.edi;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b810  c1c110                 -rol ecx, 0x10
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = (op & 0x80000000);
            op = op << 1 | cf >> 31;
            shift--;
        }
    }
    // 00a8b813  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b819  81e6ffff0f00           -and esi, 0xfffff
    cpu.esi &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b81f  6609ff                 +or di, di
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(cpu.di))));
    // 00a8b822  7510                   -jne 0xa8b834
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b834;
    }
    // 00a8b824  6647                   -inc di
    (cpu.di)++;
L_0x00a8b826:
    // 00a8b826  664f                   -dec di
    (cpu.di)--;
    // 00a8b828  01c0                   +add eax, eax
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
    // 00a8b82a  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8b82c  f7c200001000           +test edx, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1048576 /*0x100000*/));
    // 00a8b832  74f2                   -je 0xa8b826
    if (cpu.flags.zf)
    {
        goto L_0x00a8b826;
    }
L_0x00a8b834:
    // 00a8b834  81ca00001000           -or edx, 0x100000
    cpu.edx |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 00a8b83a  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00a8b83d  7510                   -jne 0xa8b84f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b84f;
    }
    // 00a8b83f  6641                   -inc cx
    (cpu.cx)++;
L_0x00a8b841:
    // 00a8b841  6649                   -dec cx
    (cpu.cx)--;
    // 00a8b843  01db                   +add ebx, ebx
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
    // 00a8b845  11f6                   -adc esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi) + cpu.flags.cf);
    // 00a8b847  f7c600001000           +test esi, 0x100000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & 1048576 /*0x100000*/));
    // 00a8b84d  74f2                   -je 0xa8b841
    if (cpu.flags.zf)
    {
        goto L_0x00a8b841;
    }
L_0x00a8b84f:
    // 00a8b84f  81ce00001000           -or esi, 0x100000
    cpu.esi |= x86::reg32(x86::sreg32(1048576 /*0x100000*/));
    // 00a8b855  6601f9                 -add cx, di
    (cpu.cx) += x86::reg16(x86::sreg16(cpu.di));
    // 00a8b858  6681e9ff03             +sub cx, 0x3ff
    {
        x86::reg16& tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1023 /*0x3ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b85d  7811                   -js 0xa8b870
    if (cpu.flags.sf)
    {
        goto L_0x00a8b870;
    }
    // 00a8b85f  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b864  720a                   -jb 0xa8b870
    if (cpu.flags.cf)
    {
        goto L_0x00a8b870;
    }
    // 00a8b866  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b868  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b869  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b86a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b86b  e9e91f0000             -jmp 0xa8d859
    return sub_a8d859(app, cpu);
L_0x00a8b870:
    // 00a8b870  6683f9cb               +cmp cx, -0x35
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(-53 /*-0x35*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b874  7d08                   -jge 0xa8b87e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8b87e;
    }
    // 00a8b876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b877  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b878  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b879  e9be1f0000             -jmp 0xa8d83c
    return sub_a8d83c(app, cpu);
L_0x00a8b87e:
    // 00a8b87e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b87f  b10b                   -mov cl, 0xb
    cpu.cl = 11 /*0xb*/;
    // 00a8b881  0fa5c2                 -shld edx, eax, cl
    {
        x86::reg32& destination = cpu.edx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.eax >> (32 - (cpu.cl % 32));
    }
    // 00a8b884  0fa5e8                 -shld eax, ebp, cl
    {
        x86::reg32& destination = cpu.eax;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00a8b887  2500f8ffff             -and eax, 0xfffff800
    cpu.eax &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00a8b88c  0fa5de                 -shld esi, ebx, cl
    {
        x86::reg32& destination = cpu.esi;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebx >> (32 - (cpu.cl % 32));
    }
    // 00a8b88f  0fa5eb                 -shld ebx, ebp, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination <<= (cpu.cl % 32);
        destination |= cpu.ebp >> (32 - (cpu.cl % 32));
    }
    // 00a8b892  81e300f8ffff           -and ebx, 0xfffff800
    cpu.ebx &= x86::reg32(x86::sreg32(4294965248 /*0xfffff800*/));
    // 00a8b898  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8b89a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b89b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b89c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8b89d  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00a8b89f  96                     -xchg esi, eax
    {
        x86::reg32 tmp = cpu.esi;
        cpu.esi = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b8a0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8b8a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b8a3  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00a8b8a5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8b8a7  01c1                   +add ecx, eax
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
    // 00a8b8a9  11ef                   +adc edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b8ab  11ed                   -adc ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 00a8b8ad  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b8ae  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8b8af  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00a8b8b1  01c1                   +add ecx, eax
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
    // 00a8b8b3  11d7                   +adc edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b8b5  83d500                 -adc ebp, 0
    (cpu.ebp) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b8b8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8b8ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b8bb  f7e2                   -mul edx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.edx);
    // 00a8b8bd  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b8bf  11ea                   -adc edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp) + cpu.flags.cf);
    // 00a8b8c1  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b8c3  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a8b8c5  0fadc3                 -shrd ebx, eax, cl
    {
        x86::reg32& destination = cpu.ebx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.eax  << (32 - (cpu.cl % 32));
    }
    // 00a8b8c8  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00a8b8cb  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00a8b8ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8b8cf:
    // 00a8b8cf  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00a8b8d5  7411                   -je 0xa8b8e8
    if (cpu.flags.zf)
    {
        goto L_0x00a8b8e8;
    }
    // 00a8b8d7  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b8d9  d1d8                   +rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b8db  d1db                   -rcr ebx, 1
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
    // 00a8b8dd  6641                   -inc cx
    (cpu.cx)++;
    // 00a8b8df  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b8e4  7466                   -je 0xa8b94c
    if (cpu.flags.zf)
    {
        goto L_0x00a8b94c;
    }
    // 00a8b8e6  ebe7                   -jmp 0xa8b8cf
    goto L_0x00a8b8cf;
L_0x00a8b8e8:
    // 00a8b8e8  01db                   +add ebx, ebx
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
    // 00a8b8ea  732a                   -jae 0xa8b916
    if (!cpu.flags.cf)
    {
        goto L_0x00a8b916;
    }
    // 00a8b8ec  750d                   -jne 0xa8b8fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b8fb;
    }
    // 00a8b8ee  09f6                   +or esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a8b8f0  0f95c3                 -setne bl
    cpu.bl = !cpu.flags.zf;
    // 00a8b8f3  d1eb                   +shr ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b8f5  7204                   -jb 0xa8b8fb
    if (cpu.flags.cf)
    {
        goto L_0x00a8b8fb;
    }
    // 00a8b8f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8b8f9  d1ee                   +shr esi, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
L_0x00a8b8fb:
    // 00a8b8fb  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8b8fe  83d200                 -adc edx, 0
    (cpu.edx) += x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b901  f7c200002000           +test edx, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2097152 /*0x200000*/));
    // 00a8b907  740d                   -je 0xa8b916
    if (cpu.flags.zf)
    {
        goto L_0x00a8b916;
    }
    // 00a8b909  d1ea                   +shr edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8b90b  d1d8                   -rcr eax, 1
    {
        x86::reg32& op = cpu.eax;
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
    // 00a8b90d  6641                   -inc cx
    (cpu.cx)++;
    // 00a8b90f  6681f9ff07             +cmp cx, 0x7ff
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2047 /*0x7ff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8b914  7436                   -je 0xa8b94c
    if (cpu.flags.zf)
    {
        goto L_0x00a8b94c;
    }
L_0x00a8b916:
    // 00a8b916  6609c9                 +or cx, cx
    cpu.clear_co();
    cpu.set_szp((cpu.cx |= x86::reg16(x86::sreg16(cpu.cx))));
    // 00a8b919  7f16                   -jg 0xa8b931
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8b931;
    }
    // 00a8b91b  7504                   -jne 0xa8b921
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b921;
    }
    // 00a8b91d  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a8b91f  eb05                   -jmp 0xa8b926
    goto L_0x00a8b926;
L_0x00a8b921:
    // 00a8b921  66f7d9                 -neg cx
    cpu.cx = ~cpu.cx + 1;
    // 00a8b924  6649                   -dec cx
    (cpu.cx)--;
L_0x00a8b926:
    // 00a8b926  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8b928  0fadd0                 -shrd eax, edx, cl
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (cpu.cl % 32);
        destination |= cpu.edx  << (32 - (cpu.cl % 32));
    }
    // 00a8b92b  0fadda                 -shrd edx, ebx, cl
    {
        x86::reg32& destination = cpu.edx;
        destination >>= (cpu.cl % 32);
        destination |= cpu.ebx  << (32 - (cpu.cl % 32));
    }
    // 00a8b92e  6629c9                 -sub cx, cx
    (cpu.cx) -= x86::reg16(x86::sreg16(cpu.cx));
L_0x00a8b931:
    // 00a8b931  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00a8b937  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8b939  c1c90b                 -ror ecx, 0xb
    {
        x86::reg32& op = cpu.ecx;
        x86::reg32 shift = 11 /*0xb*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 00a8b93c  01f6                   +add esi, esi
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
    // 00a8b93e  d1d9                   -rcr ecx, 1
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
    // 00a8b940  81e10000f0ff           -and ecx, 0xfff00000
    cpu.ecx &= x86::reg32(x86::sreg32(4293918720 /*0xfff00000*/));
    // 00a8b946  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8b948  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b949  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b94a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b94b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8b94c:
    // 00a8b94c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b94e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b94f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b950  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b951  e9031f0000             -jmp 0xa8d859
    return sub_a8d859(app, cpu);
}

/* align: skip  */
void sub_a8b956(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b956  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8b957  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 00a8b95d  7502                   -jne 0xa8b961
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b961;
    }
    // 00a8b95f  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a8b961:
    // 00a8b961  f7c10000f07f           +test ecx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & 2146435072 /*0x7ff00000*/));
    // 00a8b967  7502                   -jne 0xa8b96b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b96b;
    }
    // 00a8b969  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a8b96b:
    // 00a8b96b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a8b96d  31d5                   +xor ebp, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8b96f  bd00000000             -mov ebp, 0
    cpu.ebp = 0 /*0x0*/;
    // 00a8b974  780c                   -js 0xa8b982
    if (cpu.flags.sf)
    {
        goto L_0x00a8b982;
    }
    // 00a8b976  39ca                   +cmp edx, ecx
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
    // 00a8b978  7502                   -jne 0xa8b97c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8b97c;
    }
    // 00a8b97a  39d8                   +cmp eax, ebx
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
L_0x00a8b97c:
    // 00a8b97c  740c                   -je 0xa8b98a
    if (cpu.flags.zf)
    {
        goto L_0x00a8b98a;
    }
    // 00a8b97e  d1d9                   -rcr ecx, 1
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
    // 00a8b980  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a8b982:
    // 00a8b982  01d2                   +add edx, edx
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
    // 00a8b984  83dd00                 -sbb ebp, 0
    (cpu.ebp) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8b987  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8b989  45                     -inc ebp
    (cpu.ebp)++;
L_0x00a8b98a:
    // 00a8b98a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8b98c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b98d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a8b990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b990  a36c28a900             -mov dword ptr [0xa9286c], eax
    app->getMemory<x86::reg32>(x86::reg32(11085932) /* 0xa9286c */) = cpu.eax;
    // 00a8b995  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b996(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b996  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b997  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8b998  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8b999  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8b99b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8b99d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8b9a2  e8091f0000             -call 0xa8d8b0
    cpu.esp -= 4;
    sub_a8d8b0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b9a9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8b9ab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8b9ad  8b04855028a900         -mov eax, dword ptr [eax*4 + 0xa92850]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085904) /* 0xa92850 */ + cpu.eax * 4);
    // 00a8b9b4  e8171f0000             -call 0xa8d8d0
    cpu.esp -= 4;
    sub_a8d8d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9b9  b8691ea900             -mov eax, 0xa91e69
    cpu.eax = 11083369 /*0xa91e69*/;
    // 00a8b9be  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8b9c0  e80b1f0000             -call 0xa8d8d0
    cpu.esp -= 4;
    sub_a8d8d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8b9c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8b9c9  e8021f0000             -call 0xa8d8d0
    cpu.esp -= 4;
    sub_a8d8d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9ce  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00a8b9d3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8b9d5  e806d4ffff             -call 0xa88de0
    cpu.esp -= 4;
    sub_a88de0(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8b9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8b9de(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8b9de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8b9df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8b9e0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8b9e2  ff156c28a900           -call dword ptr [0xa9286c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085932) /* 0xa9286c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8b9e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8b9ea  751b                   -jne 0xa8ba07
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ba07;
    }
    // 00a8b9ec  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a8b9ef  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8b9f1  e8a0ffffff             -call 0xa8b996
    cpu.esp -= 4;
    sub_a8b996(app, cpu);
    if (cpu.terminate) return;
    // 00a8b9f6  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8b9f9  7507                   -jne 0xa8ba02
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ba02;
    }
    // 00a8b9fb  e830e8ffff             -call 0xa8a230
    cpu.esp -= 4;
    sub_a8a230(app, cpu);
    if (cpu.terminate) return;
    // 00a8ba00  eb05                   -jmp 0xa8ba07
    goto L_0x00a8ba07;
L_0x00a8ba02:
    // 00a8ba02  e83de8ffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ba07:
    // 00a8ba07  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 00a8ba0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8ba10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ba10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ba11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ba12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ba13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8ba15  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a8ba19  7522                   -jne 0xa8ba3d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ba3d;
    }
    // 00a8ba1b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8ba1e  e84d1f0000             -call 0xa8d970
    cpu.esp -= 4;
    sub_a8d970(app, cpu);
    if (cpu.terminate) return;
    // 00a8ba23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ba25  7416                   -je 0xa8ba3d
    if (cpu.flags.zf)
    {
        goto L_0x00a8ba3d;
    }
    // 00a8ba27  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a8ba2a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a8ba2d  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a8ba30  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 00a8ba33  7508                   -jne 0xa8ba3d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ba3d;
    }
    // 00a8ba35  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00a8ba37  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a8ba3a  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x00a8ba3d:
    // 00a8ba3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ba50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ba50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ba51  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ba54  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8ba57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ba59  742a                   -je 0xa8ba85
    if (cpu.flags.zf)
    {
        goto L_0x00a8ba85;
    }
    // 00a8ba5b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ba5d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ba5f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a8ba61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ba62  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8ba64  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8ba68  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ba69  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00a8ba6e  8b157c2ba900           -mov edx, dword ptr [0xa92b7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */);
    // 00a8ba74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ba75  2eff153c04a900         -call dword ptr cs:[0xa9043c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076668) /* 0xa9043c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ba7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ba7e  7505                   -jne 0xa8ba85
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ba85;
    }
    // 00a8ba80  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a8ba85:
    // 00a8ba85  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ba88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ba89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ba90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ba90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ba91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ba92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ba93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ba94  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a8ba97  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8ba99  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8ba9b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8ba9d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8ba9f  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a8baa3  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a8baa6:
    // 00a8baa6  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8baaa  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a8baae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8bab0  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8bab2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a8bab4  8a827028a900           -mov al, byte ptr [edx + 0xa92870]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085936) /* 0xa92870 */);
    // 00a8baba  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00a8babc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8bac0  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8bac1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bac3  75e1                   -jne 0xa8baa6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8baa6;
    }
L_0x00a8bac5:
    // 00a8bac5  46                     -inc esi
    (cpu.esi)++;
    // 00a8bac6  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a8bac9  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8baca  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a8bacd  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a8bacf  75f4                   -jne 0xa8bac5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bac5;
    }
    // 00a8bad1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8bad3  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a8bad6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bad7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bad8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bad9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8badc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8badc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8badd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8badf  83fb0a                 +cmp ebx, 0xa
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
    // 00a8bae2  750a                   -jne 0xa8baee
    if (!cpu.flags.zf)
    {
        goto L_0x00a8baee;
    }
    // 00a8bae4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bae6  7d06                   -jge 0xa8baee
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8baee;
    }
    // 00a8bae8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a8baea  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a8baed  42                     -inc edx
    (cpu.edx)++;
L_0x00a8baee:
    // 00a8baee  e89dffffff             -call 0xa8ba90
    cpu.esp -= 4;
    sub_a8ba90(app, cpu);
    if (cpu.terminate) return;
    // 00a8baf3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8baf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8baf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bb00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bb01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bb02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bb03  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8bb04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8bb05  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a8bb08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8bb0a  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00a8bb0e  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8bb12  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a8bb16  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8bb18  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00a8bb1c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8bb1e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8bb20  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a8bb22  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8bb23  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8bb24  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a8bb28  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a8bb2c  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a8bb2f:
    // 00a8bb2f  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a8bb33  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8bb37  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8bb3b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8bb3f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8bb42  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8bb44  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a8bb47  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8bb49  e84b200000             -call 0xa8db99
    cpu.esp -= 4;
    sub_a8db99(app, cpu);
    if (cpu.terminate) return;
    // 00a8bb4e  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8bb51  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a8bb53  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a8bb56  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a8bb58  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a8bb5c  8a809828a900           -mov al, byte ptr [eax + 0xa92898]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11085976) /* 0xa92898 */);
    // 00a8bb62  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00a8bb65  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8bb69  45                     -inc ebp
    (cpu.ebp)++;
    // 00a8bb6a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8bb6c  75c1                   -jne 0xa8bb2f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bb2f;
    }
    // 00a8bb6e  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bb73  75ba                   -jne 0xa8bb2f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bb2f;
    }
L_0x00a8bb75:
    // 00a8bb75  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a8bb79  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a8bb7c  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a8bb7d  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a8bb80  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a8bb82  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00a8bb86  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a8bb88  75eb                   -jne 0xa8bb75
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bb75;
    }
    // 00a8bb8a  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a8bb8e  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a8bb91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bb92  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8bb93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bb94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bb95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bb96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8bb98(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bb98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bb99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bb9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bb9b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8bb9c  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8bb9f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8bba1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8bba3  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8bba5  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a8bba7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8bba9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8bbaa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8bbab  83fb0a                 +cmp ebx, 0xa
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
    // 00a8bbae  752d                   -jne 0xa8bbdd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bbdd;
    }
    // 00a8bbb0  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a8bbb5  7426                   -je 0xa8bbdd
    if (cpu.flags.zf)
    {
        goto L_0x00a8bbdd;
    }
    // 00a8bbb7  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a8bbba  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8bbbd  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8bbc1  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00a8bbc3  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 00a8bbc5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8bbc8  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a8bbcc  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8bbcf  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8bbd2  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8bbd3  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a8bbd6  7501                   -jne 0xa8bbd9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bbd9;
    }
    // 00a8bbd8  46                     -inc esi
    (cpu.esi)++;
L_0x00a8bbd9:
    // 00a8bbd9  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00a8bbdd:
    // 00a8bbdd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8bbdf  e81cffffff             -call 0xa8bb00
    cpu.esp -= 4;
    sub_a8bb00(app, cpu);
    if (cpu.terminate) return;
    // 00a8bbe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8bbe6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8bbe9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8bbea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bbeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bbec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bbed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a8bbf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bbf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bbf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bbf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bbf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8bbf4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a8bbf7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8bbf9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8bbfb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8bbfd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8bbff  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a8bc03  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a8bc06:
    // 00a8bc06  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8bc0a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a8bc0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8bc10  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8bc12  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a8bc14  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8bc18  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8bc19  8a9bc028a900           -mov bl, byte ptr [ebx + 0xa928c0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11086016) /* 0xa928c0 */);
    // 00a8bc1f  8859ff                 -mov byte ptr [ecx - 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00a8bc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bc24  75e0                   -jne 0xa8bc06
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bc06;
    }
L_0x00a8bc26:
    // 00a8bc26  46                     -inc esi
    (cpu.esi)++;
    // 00a8bc27  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a8bc2a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8bc2b  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a8bc2e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a8bc30  75f4                   -jne 0xa8bc26
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bc26;
    }
    // 00a8bc32  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8bc34  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a8bc37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bc38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bc39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bc3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bc3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8bc3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bc3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bc3d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8bc3f  83fb0a                 +cmp ebx, 0xa
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
    // 00a8bc42  750a                   -jne 0xa8bc4e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bc4e;
    }
    // 00a8bc44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bc46  7d06                   -jge 0xa8bc4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8bc4e;
    }
    // 00a8bc48  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a8bc4a  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a8bc4d  42                     -inc edx
    (cpu.edx)++;
L_0x00a8bc4e:
    // 00a8bc4e  e89dffffff             -call 0xa8bbf0
    cpu.esp -= 4;
    sub_a8bbf0(app, cpu);
    if (cpu.terminate) return;
    // 00a8bc53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8bc55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bc56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bc60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bc60  8a80614aa900           -mov al, byte ptr [eax + 0xa94a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8bc66  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8bc68  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8bc6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8bc70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bc70  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8bc72  e9691d0000             -jmp 0xa8d9e0
    return sub_a8d9e0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bc80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bc80  83f861                 +cmp eax, 0x61
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
    // 00a8bc83  7c08                   -jl 0xa8bc8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8bc8d;
    }
    // 00a8bc85  83f87a                 +cmp eax, 0x7a
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
    // 00a8bc88  7f03                   -jg 0xa8bc8d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8bc8d;
    }
    // 00a8bc8a  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a8bc8d:
    // 00a8bc8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a8bc90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bc90  803de828a90000         +cmp byte ptr [0xa928e8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11086056) /* 0xa928e8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8bc97  741a                   -je 0xa8bcb3
    if (cpu.flags.zf)
    {
        goto L_0x00a8bcb3;
    }
    // 00a8bc99  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a8bc9f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bca0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8bca1  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a8bca2  eb06                   -jmp 0xa8bcaa
    goto L_0x00a8bcaa;
    // 00a8bca4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bca5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bca6  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8bca7  44                     -inc esp
    (cpu.esp)++;
    // 00a8bca8  45                     -inc ebp
    (cpu.ebp)++;
    // 00a8bca9  4f                     -dec edi
    (cpu.edi)--;
L_0x00a8bcaa:
    // 00a8bcaa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8bcaf  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8bcb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8bcb3:
    // 00a8bcb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8bcb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bcc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bcc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bcc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bcc2  2eff15a803a900         -call dword ptr cs:[0xa903a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076520) /* 0xa903a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bcc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bcca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bccb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8bcd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bcd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8bcd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bcd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bcd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bcd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8bcd5  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a8bcdb  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bce1  bd901ea900             -mov ebp, 0xa91e90
    cpu.ebp = 11083408 /*0xa91e90*/;
    // 00a8bce6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8bce9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a8bceb:
    // 00a8bceb  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a8bcf2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8bcf4  e8bfe2ffff             -call 0xa89fb8
    cpu.esp -= 4;
    sub_a89fb8(app, cpu);
    if (cpu.terminate) return;
    // 00a8bcf9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8bcfe  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a8bd05  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8bd06  e8251f0000             -call 0xa8dc30
    cpu.esp -= 4;
    sub_a8dc30(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bd0d  74dc                   -je 0xa8bceb
    if (cpu.flags.zf)
    {
        goto L_0x00a8bceb;
    }
    // 00a8bd0f  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a8bd16  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8bd18  e8bb210000             -call 0xa8ded8
    cpu.esp -= 4;
    sub_a8ded8(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bd1f  751b                   -jne 0xa8bd3c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bd3c;
    }
    // 00a8bd21  e8ca220000             -call 0xa8dff0
    cpu.esp -= 4;
    sub_a8dff0(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd26  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bd29  740a                   -je 0xa8bd35
    if (cpu.flags.zf)
    {
        goto L_0x00a8bd35;
    }
    // 00a8bd2b  e8c0220000             -call 0xa8dff0
    cpu.esp -= 4;
    sub_a8dff0(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd30  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bd33  75b6                   -jne 0xa8bceb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bceb;
    }
L_0x00a8bd35:
    // 00a8bd35  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8bd37  e998000000             -jmp 0xa8bdd4
    goto L_0x00a8bdd4;
L_0x00a8bd3c:
    // 00a8bd3c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8bd3e  e80de2ffff             -call 0xa89f50
    cpu.esp -= 4;
    sub_a89f50(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd43  8a1d6825a900           -mov bl, byte ptr [0xa92568]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(11085160) /* 0xa92568 */);
L_0x00a8bd49:
    // 00a8bd49  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8bd4b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8bd4d  e866e2ffff             -call 0xa89fb8
    cpu.esp -= 4;
    sub_a89fb8(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd52  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8bd54  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a8bd5b  e8b0220000             -call 0xa8e010
    cpu.esp -= 4;
    sub_a8e010(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bd62  7551                   -jne 0xa8bdb5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bdb5;
    }
    // 00a8bd64  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8bd66  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8bd68  e86b210000             -call 0xa8ded8
    cpu.esp -= 4;
    sub_a8ded8(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8bd6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bd71  742a                   -je 0xa8bd9d
    if (cpu.flags.zf)
    {
        goto L_0x00a8bd9d;
    }
    // 00a8bd73  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a8bd76  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a8bd79  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a8bd7c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8bd7f  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 00a8bd82  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8bd84  881d6825a900           -mov byte ptr [0xa92568], bl
    app->getMemory<x86::reg8>(x86::reg32(11085160) /* 0xa92568 */) = cpu.bl;
    // 00a8bd8a  e891e4ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8bd8f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8bd91  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a8bd97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bd98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bd99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bd9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bd9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bd9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8bd9d:
    // 00a8bd9d  e84e220000             -call 0xa8dff0
    cpu.esp -= 4;
    sub_a8dff0(app, cpu);
    if (cpu.terminate) return;
    // 00a8bda2  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bda5  750e                   -jne 0xa8bdb5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bdb5;
    }
    // 00a8bda7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8bda9  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a8bdaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdb0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8bdb5:
    // 00a8bdb5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8bdba  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a8bdc1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8bdc2  e8691e0000             -call 0xa8dc30
    cpu.esp -= 4;
    sub_a8dc30(app, cpu);
    if (cpu.terminate) return;
    // 00a8bdc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bdc9  0f851cffffff           -jne 0xa8bceb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bceb;
    }
    // 00a8bdcf  e975ffffff             -jmp 0xa8bd49
    goto L_0x00a8bd49;
L_0x00a8bdd4:
    // 00a8bdd4  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a8bdda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bddb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bddc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bddd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bdde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bddf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8bde0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8bde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bde2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bde3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bde4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bde5  803d0029a90000         +cmp byte ptr [0xa92900], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11086080) /* 0xa92900 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8bdec  0f85ab000000           -jne 0xa8be9d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8be9d;
    }
    // 00a8bdf2  bbec28a900             -mov ebx, 0xa928ec
    cpu.ebx = 11086060 /*0xa928ec*/;
    // 00a8bdf7  eb39                   -jmp 0xa8be32
    goto L_0x00a8be32;
L_0x00a8bdf9:
    // 00a8bdf9  e8d2acffff             -call 0xa86ad0
    cpu.esp -= 4;
    sub_a86ad0(app, cpu);
    if (cpu.terminate) return;
    // 00a8bdfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8be00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8be02  742b                   -je 0xa8be2f
    if (cpu.flags.zf)
    {
        goto L_0x00a8be2f;
    }
    // 00a8be04  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8be06  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8be07  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8be09  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8be0b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8be0d  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8be0e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8be10  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a8be12  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a8be14  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8be15  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8be16  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8be1c  7711                   -ja 0xa8be2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8be2f;
    }
    // 00a8be1e  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 00a8be23  b80029a900             -mov eax, 0xa92900
    cpu.eax = 11086080 /*0xa92900*/;
    // 00a8be28  e803220000             -call 0xa8e030
    cpu.esp -= 4;
    sub_a8e030(app, cpu);
    if (cpu.terminate) return;
    // 00a8be2d  eb0a                   -jmp 0xa8be39
    goto L_0x00a8be39;
L_0x00a8be2f:
    // 00a8be2f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a8be32:
    // 00a8be32  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8be34  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8be37  75c0                   -jne 0xa8bdf9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bdf9;
    }
L_0x00a8be39:
    // 00a8be39  803d0029a90000         +cmp byte ptr [0xa92900], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11086080) /* 0xa92900 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8be40  752a                   -jne 0xa8be6c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8be6c;
    }
    // 00a8be42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8be44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8be46  bf0029a900             -mov edi, 0xa92900
    cpu.edi = 11086080 /*0xa92900*/;
    // 00a8be4b  e890220000             -call 0xa8e0e0
    cpu.esp -= 4;
    sub_a8e0e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8be50  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8be52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a8be53:
    // 00a8be53  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8be55  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a8be57  3c00                   +cmp al, 0
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
    // 00a8be59  7410                   -je 0xa8be6b
    if (cpu.flags.zf)
    {
        goto L_0x00a8be6b;
    }
    // 00a8be5b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a8be5e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8be61  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a8be64  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8be67  3c00                   +cmp al, 0
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
    // 00a8be69  75e8                   -jne 0xa8be53
    if (!cpu.flags.zf)
    {
        goto L_0x00a8be53;
    }
L_0x00a8be6b:
    // 00a8be6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8be6c:
    // 00a8be6c  bf0029a900             -mov edi, 0xa92900
    cpu.edi = 11086080 /*0xa92900*/;
    // 00a8be71  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8be72  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8be74  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8be76  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8be78  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8be79  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8be7b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a8be7d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a8be7f  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8be80  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8be81  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a8be84  050029a900             -add eax, 0xa92900
    (cpu.eax) += x86::reg32(x86::sreg32(11086080 /*0xa92900*/));
    // 00a8be89  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8be8b  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8be8e  740d                   -je 0xa8be9d
    if (cpu.flags.zf)
    {
        goto L_0x00a8be9d;
    }
    // 00a8be90  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8be93  7408                   -je 0xa8be9d
    if (cpu.flags.zf)
    {
        goto L_0x00a8be9d;
    }
    // 00a8be95  40                     -inc eax
    (cpu.eax)++;
    // 00a8be96  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 00a8be99  40                     -inc eax
    (cpu.eax)++;
    // 00a8be9a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a8be9d:
    // 00a8be9d  b80029a900             -mov eax, 0xa92900
    cpu.eax = 11086080 /*0xa92900*/;
    // 00a8bea2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bea3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bea4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bea5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bea6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bea7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8beb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8beb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8beb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8beb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8beb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8beb4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8beb6  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 00a8beba  740d                   -je 0xa8bec9
    if (cpu.flags.zf)
    {
        goto L_0x00a8bec9;
    }
    // 00a8bebc  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a8bec0  7407                   -je 0xa8bec9
    if (cpu.flags.zf)
    {
        goto L_0x00a8bec9;
    }
    // 00a8bec2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8bec4  e877abffff             -call 0xa86a40
    cpu.esp -= 4;
    sub_a86a40(app, cpu);
    if (cpu.terminate) return;
L_0x00a8bec9:
    // 00a8bec9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8becc  e8af220000             -call 0xa8e180
    cpu.esp -= 4;
    sub_a8e180(app, cpu);
    if (cpu.terminate) return;
    // 00a8bed1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8bed3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8bed5  83f8ff                 +cmp eax, -1
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
    // 00a8bed8  742a                   -je 0xa8bf04
    if (cpu.flags.zf)
    {
        goto L_0x00a8bf04;
    }
    // 00a8beda  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8bedd  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bee3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a8bee6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8bee8  740f                   -je 0xa8bef9
    if (cpu.flags.zf)
    {
        goto L_0x00a8bef9;
    }
    // 00a8beea  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a8beee  7405                   -je 0xa8bef5
    if (cpu.flags.zf)
    {
        goto L_0x00a8bef5;
    }
    // 00a8bef0  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 00a8bef3  eb04                   -jmp 0xa8bef9
    goto L_0x00a8bef9;
L_0x00a8bef5:
    // 00a8bef5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8bef7  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a8bef9:
    // 00a8bef9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8befc  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bf02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a8bf04:
    // 00a8bf04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bf10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bf10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8bf11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bf12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bf13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8bf14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bf15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8bf16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8bf18  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bf1a  7c08                   -jl 0xa8bf24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8bf24;
    }
    // 00a8bf1c  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bf22  7611                   -jbe 0xa8bf35
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8bf35;
    }
L_0x00a8bf24:
    // 00a8bf24  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8bf29  e8f2e2ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8bf2e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8bf33  eb61                   -jmp 0xa8bf96
    goto L_0x00a8bf96;
L_0x00a8bf35:
    // 00a8bf35  8b150828a900           -mov edx, dword ptr [0xa92808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8bf3b  8b2d0027a900           -mov ebp, dword ptr [0xa92700]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11085568) /* 0xa92700 */);
    // 00a8bf41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8bf43  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8bf45  8b3c9a                 -mov edi, dword ptr [edx + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a8bf48  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8bf4a  741e                   -je 0xa8bf6a
    if (cpu.flags.zf)
    {
        goto L_0x00a8bf6a;
    }
    // 00a8bf4c  ff15f426a900           -call dword ptr [0xa926f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085556) /* 0xa926f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bf52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8bf54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bf56  7412                   -je 0xa8bf6a
    if (cpu.flags.zf)
    {
        goto L_0x00a8bf6a;
    }
    // 00a8bf58  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8bf5a  ff15f826a900           -call dword ptr [0xa926f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085560) /* 0xa926f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bf60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8bf62  ff150027a900           -call dword ptr [0xa92700]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085568) /* 0xa92700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bf68  eb21                   -jmp 0xa8bf8b
    goto L_0x00a8bf8b;
L_0x00a8bf6a:
    // 00a8bf6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8bf6c  751d                   -jne 0xa8bf8b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bf8b;
    }
    // 00a8bf6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8bf6f  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8bf76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bf78  7511                   -jne 0xa8bf8b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bf8b;
    }
    // 00a8bf7a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8bf7f  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00a8bf84  e897e2ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8bf89  eb09                   -jmp 0xa8bf94
    goto L_0x00a8bf94;
L_0x00a8bf8b:
    // 00a8bf8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8bf8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8bf8f  e874000000             -call 0xa8c008
    cpu.esp -= 4;
    sub_a8c008(app, cpu);
    if (cpu.terminate) return;
L_0x00a8bf94:
    // 00a8bf94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a8bf96:
    // 00a8bf96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bf9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8bfa0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bfa0  e93b220000             -jmp 0xa8e1e0
    return sub_a8e1e0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8bfb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8bfb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8bfb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8bfb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8bfb3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8bfb5  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8bfbb  7206                   -jb 0xa8bfc3
    if (cpu.flags.cf)
    {
        goto L_0x00a8bfc3;
    }
    // 00a8bfbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8bfbf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bfc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bfc1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8bfc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8bfc3:
    // 00a8bfc3  83f803                 +cmp eax, 3
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
    // 00a8bfc6  7d33                   -jge 0xa8bffb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8bffb;
    }
    // 00a8bfc8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00a8bfcf  a1582aa900             -mov eax, dword ptr [0xa92a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086424) /* 0xa92a58 */);
    // 00a8bfd4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8bfd6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8bfd9  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a8bfdc  751d                   -jne 0xa8bffb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8bffb;
    }
    // 00a8bfde  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a8bfe0  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a8bfe3  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00a8bfe6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8bfe8  e883190000             -call 0xa8d970
    cpu.esp -= 4;
    sub_a8d970(app, cpu);
    if (cpu.terminate) return;
    // 00a8bfed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8bfef  740a                   -je 0xa8bffb
    if (cpu.flags.zf)
    {
        goto L_0x00a8bffb;
    }
    // 00a8bff1  a1582aa900             -mov eax, dword ptr [0xa92a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086424) /* 0xa92a58 */);
    // 00a8bff6  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a8bffb:
    // 00a8bffb  a1582aa900             -mov eax, dword ptr [0xa92a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086424) /* 0xa92a58 */);
    // 00a8c000  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a8c003  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c004  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c005  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c006  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8c008(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c008  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c009  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8c00c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c00e  740e                   -je 0xa8c01e
    if (cpu.flags.zf)
    {
        goto L_0x00a8c01e;
    }
    // 00a8c010  8b1d582aa900           -mov ebx, dword ptr [0xa92a58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11086424) /* 0xa92a58 */);
    // 00a8c016  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a8c019  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a8c01c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c01d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c01e:
    // 00a8c01e  8b1d582aa900           -mov ebx, dword ptr [0xa92a58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11086424) /* 0xa92a58 */);
    // 00a8c024  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a8c027  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c030(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c030  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c032  7504                   -jne 0xa8c038
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c038;
    }
    // 00a8c034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8c036:
    // 00a8c036  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a8c037  90                     -nop 
    ;
L_0x00a8c038:
    // 00a8c038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c03a  74fa                   -je 0xa8c036
    if (cpu.flags.zf)
    {
        goto L_0x00a8c036;
    }
    // 00a8c03c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c03d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c03f  e824e2ffff             -call 0xa8a268
    cpu.esp -= 4;
    sub_a8a268(app, cpu);
    if (cpu.terminate) return;
    // 00a8c044  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c047  7507                   -jne 0xa8c050
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c050;
    }
    // 00a8c049  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c04e  eb45                   -jmp 0xa8c095
    goto L_0x00a8c095;
L_0x00a8c050:
    // 00a8c050  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c056  7511                   -jne 0xa8c069
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c069;
    }
    // 00a8c058  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8c05d  e8bee1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c062  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c067  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c068  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c069:
    // 00a8c069  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c06f  7511                   -jne 0xa8c082
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c082;
    }
    // 00a8c071  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c076  e8a5e1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c07b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c082:
    // 00a8c082  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c085  7605                   -jbe 0xa8c08c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8c08c;
    }
    // 00a8c087  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a8c08c:
    // 00a8c08c  8b82592aa900           -mov eax, dword ptr [edx + 0xa92a59]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11086425) /* 0xa92a59 */);
    // 00a8c092  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a8c095:
    // 00a8c095  e886e1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c09a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c09f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c03c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8c03c;
    // 00a8c030  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c032  7504                   -jne 0xa8c038
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c038;
    }
    // 00a8c034  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8c036:
    // 00a8c036  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a8c037  90                     -nop 
    ;
L_0x00a8c038:
    // 00a8c038  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c03a  74fa                   -je 0xa8c036
    if (cpu.flags.zf)
    {
        goto L_0x00a8c036;
    }
L_entry_0x00a8c03c:
    // 00a8c03c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c03d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c03f  e824e2ffff             -call 0xa8a268
    cpu.esp -= 4;
    sub_a8a268(app, cpu);
    if (cpu.terminate) return;
    // 00a8c044  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c047  7507                   -jne 0xa8c050
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c050;
    }
    // 00a8c049  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c04e  eb45                   -jmp 0xa8c095
    goto L_0x00a8c095;
L_0x00a8c050:
    // 00a8c050  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c056  7511                   -jne 0xa8c069
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c069;
    }
    // 00a8c058  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8c05d  e8bee1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c062  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c067  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c068  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c069:
    // 00a8c069  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c06f  7511                   -jne 0xa8c082
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c082;
    }
    // 00a8c071  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c076  e8a5e1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c07b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c081  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c082:
    // 00a8c082  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c085  7605                   -jbe 0xa8c08c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8c08c;
    }
    // 00a8c087  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a8c08c:
    // 00a8c08c  8b82592aa900           -mov eax, dword ptr [edx + 0xa92a59]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(11086425) /* 0xa92a59 */);
    // 00a8c092  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a8c095:
    // 00a8c095  e886e1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c09a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c09f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c0a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c0a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c0a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c0a6  2eff15c403a900         -call dword ptr cs:[0xa903c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076548) /* 0xa903c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c0ad  e88affffff             -call 0xa8c03c
    cpu.esp -= 4;
    sub_a8c03c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c0b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c0c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c0c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c0c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c0c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c0c4  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8c0c8  740c                   -je 0xa8c0d6
    if (cpu.flags.zf)
    {
        goto L_0x00a8c0d6;
    }
L_0x00a8c0ca:
    // 00a8c0ca  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a8c0ce  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8c0d1  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a8c0d4  75f4                   -jne 0xa8c0ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c0ca;
    }
L_0x00a8c0d6:
    // 00a8c0d6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8c0d8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a8c0da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8c0e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c0e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c0e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c0e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c0e3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8c0e5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8c0e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c0e9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8c0ea  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8c0ec  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8c0ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c0ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8c0f1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8c0f4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8c0f6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8c0f8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8c0fb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8c0fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0fe  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8c0ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8c101  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c102  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c103  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c104  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c110(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c110  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8c114  751c                   -jne 0xa8c132
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c132;
    }
    // 00a8c116  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a8c11a  7416                   -je 0xa8c132
    if (cpu.flags.zf)
    {
        goto L_0x00a8c132;
    }
    // 00a8c11c  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00a8c120  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8c124  7206                   -jb 0xa8c12c
    if (cpu.flags.cf)
    {
        goto L_0x00a8c12c;
    }
    // 00a8c126  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8c12a  7606                   -jbe 0xa8c132
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8c132;
    }
L_0x00a8c12c:
    // 00a8c12c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c131  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c132:
    // 00a8c132  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c134  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c138(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c138  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c139  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c13a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c13c  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c142  833d702aa900ff         +cmp dword ptr [0xa92a70], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11086448) /* 0xa92a70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c149  7523                   -jne 0xa8c16e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c16e;
    }
    // 00a8c14b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c14d  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a8c152  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a8c154  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c156  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8c158  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00a8c15d  68941ea900             -push 0xa91e94
    app->getMemory<x86::reg32>(cpu.esp-4) = 11083412 /*0xa91e94*/;
    cpu.esp -= 4;
    // 00a8c162  2eff156c03a900         -call dword ptr cs:[0xa9036c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076460) /* 0xa9036c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c169  a3702aa900             -mov dword ptr [0xa92a70], eax
    app->getMemory<x86::reg32>(x86::reg32(11086448) /* 0xa92a70 */) = cpu.eax;
L_0x00a8c16e:
    // 00a8c16e  833d742aa900ff         +cmp dword ptr [0xa92a74], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11086452) /* 0xa92a74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c175  7523                   -jne 0xa8c19a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c19a;
    }
    // 00a8c177  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c179  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a8c17e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a8c180  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c182  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a8c184  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00a8c189  689c1ea900             -push 0xa91e9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11083420 /*0xa91e9c*/;
    cpu.esp -= 4;
    // 00a8c18e  2eff156c03a900         -call dword ptr cs:[0xa9036c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076460) /* 0xa9036c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c195  a3742aa900             -mov dword ptr [0xa92a74], eax
    app->getMemory<x86::reg32>(x86::reg32(11086452) /* 0xa92a74 */) = cpu.eax;
L_0x00a8c19a:
    // 00a8c19a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c19c  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c1a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c1a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c1a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c1a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c1a8  e88bffffff             -call 0xa8c138
    cpu.esp -= 4;
    sub_a8c138(app, cpu);
    if (cpu.terminate) return;
    // 00a8c1ad  a1702aa900             -mov eax, dword ptr [0xa92a70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086448) /* 0xa92a70 */);
    // 00a8c1b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8c1b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c1b4  e87fffffff             -call 0xa8c138
    cpu.esp -= 4;
    sub_a8c138(app, cpu);
    if (cpu.terminate) return;
    // 00a8c1b9  a1742aa900             -mov eax, dword ptr [0xa92a74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086452) /* 0xa92a74 */);
    // 00a8c1be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8c1c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c1c0  dbe2                   -fnclex 
    /*nothing*/;
    // 00a8c1c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c1d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c1d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c1d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c1d2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c1d4  83f807                 +cmp eax, 7
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
    // 00a8c1d7  7405                   -je 0xa8c1de
    if (cpu.flags.zf)
    {
        goto L_0x00a8c1de;
    }
    // 00a8c1d9  83f804                 +cmp eax, 4
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
    // 00a8c1dc  7518                   -jne 0xa8c1f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c1f6;
    }
L_0x00a8c1de:
    // 00a8c1de  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00a8c1e5  8b98782aa900           -mov ebx, dword ptr [eax + 0xa92a78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11086456) /* 0xa92a78 */);
    // 00a8c1eb  8990782aa900           -mov dword ptr [eax + 0xa92a78], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(11086456) /* 0xa92a78 */) = cpu.edx;
    // 00a8c1f1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c1f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c1f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c1f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c1f6:
    // 00a8c1f6  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00a8c1fd  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c203  8b5c0158               -mov ebx, dword ptr [ecx + eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1);
    // 00a8c207  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c20d  89540158               -mov dword ptr [ecx + eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1) = cpu.edx;
    // 00a8c211  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c215  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c218(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c218  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c219  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c21b  83f807                 +cmp eax, 7
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
    // 00a8c21e  7405                   -je 0xa8c225
    if (cpu.flags.zf)
    {
        goto L_0x00a8c225;
    }
    // 00a8c220  83f804                 +cmp eax, 4
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
    // 00a8c223  7509                   -jne 0xa8c22e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c22e;
    }
L_0x00a8c225:
    // 00a8c225  8b04d5782aa900         -mov eax, dword ptr [edx*8 + 0xa92a78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086456) /* 0xa92a78 */ + cpu.edx * 8);
    // 00a8c22c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c22d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c22e:
    // 00a8c22e  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c234  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00a8c238  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c239  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c23c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c23c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c23d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c23f  83f807                 +cmp eax, 7
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
    // 00a8c242  7405                   -je 0xa8c249
    if (cpu.flags.zf)
    {
        goto L_0x00a8c249;
    }
    // 00a8c244  83f804                 +cmp eax, 4
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
    // 00a8c247  7509                   -jne 0xa8c252
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c252;
    }
L_0x00a8c249:
    // 00a8c249  8b04d57c2aa900         -mov eax, dword ptr [edx*8 + 0xa92a7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086460) /* 0xa92a7c */ + cpu.edx * 8);
    // 00a8c250  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c251  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c252:
    // 00a8c252  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c258  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00a8c25c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c25d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c260(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c261  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c263  e8d4ffffff             -call 0xa8c23c
    cpu.esp -= 4;
    sub_a8c23c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c268  39c2                   +cmp edx, eax
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
    // 00a8c26a  7509                   -jne 0xa8c275
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c275;
    }
    // 00a8c26c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c26e  e8a5ffffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c273  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c274  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c275:
    // 00a8c275  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c278  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c27c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c27c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8c280  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c282  760a                   -jbe 0xa8c28e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8c28e;
    }
    // 00a8c284  83f801                 +cmp eax, 1
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
    // 00a8c287  7424                   -je 0xa8c2ad
    if (cpu.flags.zf)
    {
        goto L_0x00a8c2ad;
    }
    // 00a8c289  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c28b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8c28e:
    // 00a8c28e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8c293  e880ffffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c298  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c29a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c29c  7503                   -jne 0xa8c2a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c2a1;
    }
    // 00a8c29e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8c2a1:
    // 00a8c2a1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8c2a6  e8dd010000             -call 0xa8c488
    cpu.esp -= 4;
    sub_a8c488(app, cpu);
    if (cpu.terminate) return;
    // 00a8c2ab  eb1d                   -jmp 0xa8c2ca
    goto L_0x00a8c2ca;
L_0x00a8c2ad:
    // 00a8c2ad  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c2b2  e861ffffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c2b7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c2b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c2bb  7503                   -jne 0xa8c2c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c2c0;
    }
    // 00a8c2bd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8c2c0:
    // 00a8c2c0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c2c5  e8be010000             -call 0xa8c488
    cpu.esp -= 4;
    sub_a8c488(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c2ca:
    // 00a8c2ca  83fa02                 +cmp edx, 2
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
    // 00a8c2cd  7405                   -je 0xa8c2d4
    if (cpu.flags.zf)
    {
        goto L_0x00a8c2d4;
    }
    // 00a8c2cf  83fa03                 +cmp edx, 3
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
    // 00a8c2d2  7505                   -jne 0xa8c2d9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c2d9;
    }
L_0x00a8c2d4:
    // 00a8c2d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c2d6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a8c2d9:
    // 00a8c2d9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c2de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c2e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c2e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c2e5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8c2ea  e829ffffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c2ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8c2f1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c2f6  e81dffffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c2fb  83fa02                 +cmp edx, 2
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
    // 00a8c2fe  7405                   -je 0xa8c305
    if (cpu.flags.zf)
    {
        goto L_0x00a8c305;
    }
    // 00a8c300  83fa03                 +cmp edx, 3
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
    // 00a8c303  750a                   -jne 0xa8c30f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c30f;
    }
L_0x00a8c305:
    // 00a8c305  83f802                 +cmp eax, 2
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
    // 00a8c308  740c                   -je 0xa8c316
    if (cpu.flags.zf)
    {
        goto L_0x00a8c316;
    }
    // 00a8c30a  83f803                 +cmp eax, 3
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
    // 00a8c30d  7407                   -je 0xa8c316
    if (cpu.flags.zf)
    {
        goto L_0x00a8c316;
    }
L_0x00a8c30f:
    // 00a8c30f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c314  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c316:
    // 00a8c316  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c318  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c31c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c31c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c31d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c31e  803de02aa90000         +cmp byte ptr [0xa92ae0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c325  7519                   -jne 0xa8c340
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c340;
    }
    // 00a8c327  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8c329  687cc2a800             -push 0xa8c27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11059836 /*0xa8c27c*/;
    cpu.esp -= 4;
    // 00a8c32e  2eff15f803a900         -call dword ptr cs:[0xa903f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076600) /* 0xa903f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c335  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c337  7407                   -je 0xa8c340
    if (cpu.flags.zf)
    {
        goto L_0x00a8c340;
    }
    // 00a8c339  c605e02aa90001         -mov byte ptr [0xa92ae0], 1
    app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */) = 1 /*0x1*/;
L_0x00a8c340:
    // 00a8c340  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c342  a0e02aa900             -mov al, byte ptr [0xa92ae0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */);
    // 00a8c347  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c348  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c34c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c34c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c34d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c34e  803de02aa90000         +cmp byte ptr [0xa92ae0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c355  741a                   -je 0xa8c371
    if (cpu.flags.zf)
    {
        goto L_0x00a8c371;
    }
    // 00a8c357  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c359  687cc2a800             -push 0xa8c27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11059836 /*0xa8c27c*/;
    cpu.esp -= 4;
    // 00a8c35e  2eff15f803a900         -call dword ptr cs:[0xa903f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076600) /* 0xa903f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c365  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c367  7408                   -je 0xa8c371
    if (cpu.flags.zf)
    {
        goto L_0x00a8c371;
    }
    // 00a8c369  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8c36b  8815e02aa900           -mov byte ptr [0xa92ae0], dl
    app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */) = cpu.dl;
L_0x00a8c371:
    // 00a8c371  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c373  a0e02aa900             -mov al, byte ptr [0xa92ae0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(11086560) /* 0xa92ae0 */);
    // 00a8c378  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c37a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a8c37d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8c382  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c383  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8c388(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c388  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c38d  e9f6000000             -jmp 0xa8c488
    return sub_a8c488(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a8c394(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c394  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c395  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c396  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c397  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c399  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8c39e  e875feffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c3a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c3a5  83f801                 +cmp eax, 1
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
    // 00a8c3a8  7425                   -je 0xa8c3cf
    if (cpu.flags.zf)
    {
        goto L_0x00a8c3cf;
    }
    // 00a8c3aa  83f802                 +cmp eax, 2
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
    // 00a8c3ad  7420                   -je 0xa8c3cf
    if (cpu.flags.zf)
    {
        goto L_0x00a8c3cf;
    }
    // 00a8c3af  83f803                 +cmp eax, 3
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
    // 00a8c3b2  741b                   -je 0xa8c3cf
    if (cpu.flags.zf)
    {
        goto L_0x00a8c3cf;
    }
    // 00a8c3b4  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8c3b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8c3bb  e810feffff             -call 0xa8c1d0
    cpu.esp -= 4;
    sub_a8c1d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c3c0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8c3c5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8c3c7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c3c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c3cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c3cf:
    // 00a8c3cf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c3d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c3d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c3d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c3d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c3da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c3db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c3dd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8c3df  83f801                 +cmp eax, 1
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
    // 00a8c3e2  7c05                   -jl 0xa8c3e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8c3e9;
    }
    // 00a8c3e4  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c3e7  7e13                   -jle 0xa8c3fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8c3fc;
    }
L_0x00a8c3e9:
    // 00a8c3e9  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8c3ee  e82ddeffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8c3f3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a8c3f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c3fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c3fc:
    // 00a8c3fc  c705802ba90088c3a800   -mov dword ptr [0xa92b80], 0xa8c388
    app->getMemory<x86::reg32>(x86::reg32(11086720) /* 0xa92b80 */) = 11060104 /*0xa8c388*/;
    // 00a8c406  83f902                 +cmp ecx, 2
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
    // 00a8c409  741f                   -je 0xa8c42a
    if (cpu.flags.zf)
    {
        goto L_0x00a8c42a;
    }
    // 00a8c40b  83f903                 +cmp ecx, 3
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
    // 00a8c40e  741a                   -je 0xa8c42a
    if (cpu.flags.zf)
    {
        goto L_0x00a8c42a;
    }
    // 00a8c410  e827feffff             -call 0xa8c23c
    cpu.esp -= 4;
    sub_a8c23c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c417  7411                   -je 0xa8c42a
    if (cpu.flags.zf)
    {
        goto L_0x00a8c42a;
    }
    // 00a8c419  83fb02                 +cmp ebx, 2
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
    // 00a8c41c  750c                   -jne 0xa8c42a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c42a;
    }
    // 00a8c41e  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00a8c423  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c425  e8f61d0000             -call 0xa8e220
    cpu.esp -= 4;
    sub_a8e220(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c42a:
    // 00a8c42a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c42c  e8e7fdffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c431  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8c433  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8c435  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c437  e894fdffff             -call 0xa8c1d0
    cpu.esp -= 4;
    sub_a8c1d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c43c  e8a3feffff             -call 0xa8c2e4
    cpu.esp -= 4;
    sub_a8c2e4(app, cpu);
    if (cpu.terminate) return;
    // 00a8c441  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c443  7407                   -je 0xa8c44c
    if (cpu.flags.zf)
    {
        goto L_0x00a8c44c;
    }
    // 00a8c445  e8d2feffff             -call 0xa8c31c
    cpu.esp -= 4;
    sub_a8c31c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c44a  eb05                   -jmp 0xa8c451
    goto L_0x00a8c451;
L_0x00a8c44c:
    // 00a8c44c  e8fbfeffff             -call 0xa8c34c
    cpu.esp -= 4;
    sub_a8c34c(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c451:
    // 00a8c451  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8c453  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c454  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c455  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c456  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8c488(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a8c488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c489  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c48a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c48b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c48d  e886fdffff             -call 0xa8c218
    cpu.esp -= 4;
    sub_a8c218(app, cpu);
    if (cpu.terminate) return;
    // 00a8c492  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00a8c495  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c497  83fa0b                 +cmp edx, 0xb
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
    // 00a8c49a  774d                   -ja 0xa8c4e9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8c4e9;
    }
    // 00a8c49c  2eff249558c4a800       -jmp dword ptr cs:[edx*4 + 0xa8c458]
    cpu.ip = app->getMemory<x86::reg32>(11060312 + cpu.edx * 4); goto dynamic_jump;
  case 0x00a8c4a4:
    // 00a8c4a4  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a8c4a9  e8e6feffff             -call 0xa8c394
    cpu.esp -= 4;
    sub_a8c394(app, cpu);
    if (cpu.terminate) return;
    // 00a8c4ae  eb42                   -jmp 0xa8c4f2
    goto L_0x00a8c4f2;
  case 0x00a8c4b0:
    // 00a8c4b0  83f802                 +cmp eax, 2
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
    // 00a8c4b3  7505                   -jne 0xa8c4ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c4ba;
    }
    // 00a8c4b5  e84e1d0000             -call 0xa8e208
    cpu.esp -= 4;
    sub_a8e208(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x00a8c4ba:
L_0x00a8c4ba:
    // 00a8c4ba  83f901                 +cmp ecx, 1
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
    // 00a8c4bd  741a                   -je 0xa8c4d9
    if (cpu.flags.zf)
    {
        goto L_0x00a8c4d9;
    }
    // 00a8c4bf  83f902                 +cmp ecx, 2
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
    // 00a8c4c2  7415                   -je 0xa8c4d9
    if (cpu.flags.zf)
    {
        goto L_0x00a8c4d9;
    }
    // 00a8c4c4  83f903                 +cmp ecx, 3
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
    // 00a8c4c7  7410                   -je 0xa8c4d9
    if (cpu.flags.zf)
    {
        goto L_0x00a8c4d9;
    }
    // 00a8c4c9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8c4ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c4d0  e8fbfcffff             -call 0xa8c1d0
    cpu.esp -= 4;
    sub_a8c1d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c4d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c4d7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8c4d9:
    // 00a8c4d9  e806feffff             -call 0xa8c2e4
    cpu.esp -= 4;
    sub_a8c2e4(app, cpu);
    if (cpu.terminate) return;
    // 00a8c4de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c4e0  7510                   -jne 0xa8c4f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c4f2;
    }
    // 00a8c4e2  e865feffff             -call 0xa8c34c
    cpu.esp -= 4;
    sub_a8c34c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c4e7  eb09                   -jmp 0xa8c4f2
    goto L_0x00a8c4f2;
L_0x00a8c4e9:
    // 00a8c4e9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c4ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c4f2:
    // 00a8c4f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c4f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c4f7  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a8c4f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c4f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c4f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c4fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c4fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c4fc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8c4fd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00a8c502:
    // 00a8c502  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8c508  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00a8c50b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8c50d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8c50f  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00a8c512  8db2782aa900           -lea esi, [edx + 0xa92a78]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(11086456) /* 0xa92a78 */);
    // 00a8c518  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8c51b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8c51c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8c51d  83fa68                 +cmp edx, 0x68
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c520  75e0                   -jne 0xa8c502
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c502;
    }
    // 00a8c522  ba60c2a800             -mov edx, 0xa8c260
    cpu.edx = 11059808 /*0xa8c260*/;
    // 00a8c527  bb88c4a800             -mov ebx, 0xa8c488
    cpu.ebx = 11060360 /*0xa8c488*/;
    // 00a8c52c  89151428a900           -mov dword ptr [0xa92814], edx
    app->getMemory<x86::reg32>(x86::reg32(11085844) /* 0xa92814 */) = cpu.edx;
    // 00a8c532  891d1828a900           -mov dword ptr [0xa92818], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085848) /* 0xa92818 */) = cpu.ebx;
    // 00a8c538  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8c539  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c53a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c53b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c53c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c53d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c540  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c541  e89efdffff             -call 0xa8c2e4
    cpu.esp -= 4;
    sub_a8c2e4(app, cpu);
    if (cpu.terminate) return;
    // 00a8c546  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c548  7423                   -je 0xa8c56d
    if (cpu.flags.zf)
    {
        goto L_0x00a8c56d;
    }
    // 00a8c54a  e8fdfdffff             -call 0xa8c34c
    cpu.esp -= 4;
    sub_a8c34c(app, cpu);
    if (cpu.terminate) return;
    // 00a8c54f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8c554  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8c559  e872fcffff             -call 0xa8c1d0
    cpu.esp -= 4;
    sub_a8c1d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c55e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8c563  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a8c568  e863fcffff             -call 0xa8c1d0
    cpu.esp -= 4;
    sub_a8c1d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c56d:
    // 00a8c56d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c56e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8c570(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c572  baf8c4a800             -mov edx, 0xa8c4f8
    cpu.edx = 11060472 /*0xa8c4f8*/;
    // 00a8c577  bb40c5a800             -mov ebx, 0xa8c540
    cpu.ebx = 11060544 /*0xa8c540*/;
    // 00a8c57c  8915e826a900           -mov dword ptr [0xa926e8], edx
    app->getMemory<x86::reg32>(x86::reg32(11085544) /* 0xa926e8 */) = cpu.edx;
    // 00a8c582  891dec26a900           -mov dword ptr [0xa926ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085548) /* 0xa926ec */) = cpu.ebx;
    // 00a8c588  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c589  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c590(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c594  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c595  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c596  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8c599  b8a41ea900             -mov eax, 0xa91ea4
    cpu.eax = 11083428 /*0xa91ea4*/;
    // 00a8c59e  e82da5ffff             -call 0xa86ad0
    cpu.esp -= 4;
    sub_a86ad0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c5a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c5a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c5a7  0f84f9000000           -je 0xa8c6a6
    if (cpu.flags.zf)
    {
        goto L_0x00a8c6a6;
    }
L_0x00a8c5ad:
    // 00a8c5ad  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c5b0  0f84e6000000           -je 0xa8c69c
    if (cpu.flags.zf)
    {
        goto L_0x00a8c69c;
    }
    // 00a8c5b6  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a8c5b8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00a8c5ba:
    // 00a8c5ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c5bc  3ac2                   +cmp al, dl
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
    // 00a8c5be  7412                   -je 0xa8c5d2
    if (cpu.flags.zf)
    {
        goto L_0x00a8c5d2;
    }
    // 00a8c5c0  3c00                   +cmp al, 0
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
    // 00a8c5c2  740c                   -je 0xa8c5d0
    if (cpu.flags.zf)
    {
        goto L_0x00a8c5d0;
    }
    // 00a8c5c4  46                     -inc esi
    (cpu.esi)++;
    // 00a8c5c5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c5c7  3ac2                   +cmp al, dl
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
    // 00a8c5c9  7407                   -je 0xa8c5d2
    if (cpu.flags.zf)
    {
        goto L_0x00a8c5d2;
    }
    // 00a8c5cb  46                     -inc esi
    (cpu.esi)++;
    // 00a8c5cc  3c00                   +cmp al, 0
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
    // 00a8c5ce  75ea                   -jne 0xa8c5ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c5ba;
    }
L_0x00a8c5d0:
    // 00a8c5d0  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a8c5d2:
    // 00a8c5d2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c5d4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a8c5d6  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8c5d8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8c5da  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8c5dc  e88f1c0000             -call 0xa8e270
    cpu.esp -= 4;
    sub_a8e270(app, cpu);
    if (cpu.terminate) return;
    // 00a8c5e1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a8c5e6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8c5e8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c5ea  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00a8c5ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8c5ef  e80c1e0000             -call 0xa8e400
    cpu.esp -= 4;
    sub_a8e400(app, cpu);
    if (cpu.terminate) return;
    // 00a8c5f4  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a8c5f7  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a8c5f9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c5fb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a8c5fd:
    // 00a8c5fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c5ff  3ac2                   +cmp al, dl
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
    // 00a8c601  7412                   -je 0xa8c615
    if (cpu.flags.zf)
    {
        goto L_0x00a8c615;
    }
    // 00a8c603  3c00                   +cmp al, 0
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
    // 00a8c605  740c                   -je 0xa8c613
    if (cpu.flags.zf)
    {
        goto L_0x00a8c613;
    }
    // 00a8c607  46                     -inc esi
    (cpu.esi)++;
    // 00a8c608  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c60a  3ac2                   +cmp al, dl
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
    // 00a8c60c  7407                   -je 0xa8c615
    if (cpu.flags.zf)
    {
        goto L_0x00a8c615;
    }
    // 00a8c60e  46                     -inc esi
    (cpu.esi)++;
    // 00a8c60f  3c00                   +cmp al, 0
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
    // 00a8c611  75ea                   -jne 0xa8c5fd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c5fd;
    }
L_0x00a8c613:
    // 00a8c613  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a8c615:
    // 00a8c615  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c617  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a8c619  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8c61b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8c61d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8c61f  e84c1c0000             -call 0xa8e270
    cpu.esp -= 4;
    sub_a8e270(app, cpu);
    if (cpu.terminate) return;
    // 00a8c624  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a8c629  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a8c62b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c62d  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00a8c630  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8c632  e8c91d0000             -call 0xa8e400
    cpu.esp -= 4;
    sub_a8e400(app, cpu);
    if (cpu.terminate) return;
    // 00a8c637  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a8c63a  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00a8c63c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8c640  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a8c642:
    // 00a8c642  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c644  3ac2                   +cmp al, dl
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
    // 00a8c646  7412                   -je 0xa8c65a
    if (cpu.flags.zf)
    {
        goto L_0x00a8c65a;
    }
    // 00a8c648  3c00                   +cmp al, 0
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
    // 00a8c64a  740c                   -je 0xa8c658
    if (cpu.flags.zf)
    {
        goto L_0x00a8c658;
    }
    // 00a8c64c  46                     -inc esi
    (cpu.esi)++;
    // 00a8c64d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8c64f  3ac2                   +cmp al, dl
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
    // 00a8c651  7407                   -je 0xa8c65a
    if (cpu.flags.zf)
    {
        goto L_0x00a8c65a;
    }
    // 00a8c653  46                     -inc esi
    (cpu.esi)++;
    // 00a8c654  3c00                   +cmp al, 0
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
    // 00a8c656  75ea                   -jne 0xa8c642
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c642;
    }
L_0x00a8c658:
    // 00a8c658  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a8c65a:
    // 00a8c65a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c65c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a8c65e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8c660  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8c662  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8c664  e8071c0000             -call 0xa8e270
    cpu.esp -= 4;
    sub_a8e270(app, cpu);
    if (cpu.terminate) return;
    // 00a8c669  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c66b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a8c66d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8c66f  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00a8c672  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a8c677  e8841d0000             -call 0xa8e400
    cpu.esp -= 4;
    sub_a8e400(app, cpu);
    if (cpu.terminate) return;
    // 00a8c67c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c67e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8c680  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8c684  e8afddffff             -call 0xa8a438
    cpu.esp -= 4;
    sub_a8a438(app, cpu);
    if (cpu.terminate) return;
    // 00a8c689  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8c68b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8c68d  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a8c690  e873f9ffff             -call 0xa8c008
    cpu.esp -= 4;
    sub_a8c008(app, cpu);
    if (cpu.terminate) return;
    // 00a8c695  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8c697  e911ffffff             -jmp 0xa8c5ad
    goto L_0x00a8c5ad;
L_0x00a8c69c:
    // 00a8c69c  b8b01ea900             -mov eax, 0xa91eb0
    cpu.eax = 11083440 /*0xa91eb0*/;
    // 00a8c6a1  e8ca1d0000             -call 0xa8e470
    cpu.esp -= 4;
    sub_a8e470(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c6a6:
    // 00a8c6a6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8c6a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c6af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c6b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c6b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c6b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c6b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c6b4  8b15a43ea900           -mov edx, dword ptr [0xa93ea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8c6ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c6bc  0f8480000000           -je 0xa8c742
    if (cpu.flags.zf)
    {
        goto L_0x00a8c742;
    }
    // 00a8c6c2  eb30                   -jmp 0xa8c6f4
    goto L_0x00a8c6f4;
L_0x00a8c6c4:
    // 00a8c6c4  833da03ea90000         +cmp dword ptr [0xa93ea0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c6cb  7424                   -je 0xa8c6f1
    if (cpu.flags.zf)
    {
        goto L_0x00a8c6f1;
    }
    // 00a8c6cd  8b35a43ea900           -mov esi, dword ptr [0xa93ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8c6d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8c6d5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8c6d7  8b1da03ea900           -mov ebx, dword ptr [0xa93ea0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8c6dd  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00a8c6e0  803c1900               +cmp byte ptr [ecx + ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c6e4  7405                   -je 0xa8c6eb
    if (cpu.flags.zf)
    {
        goto L_0x00a8c6eb;
    }
    // 00a8c6e6  e8b5a6ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c6eb:
    // 00a8c6eb  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x00a8c6f1:
    // 00a8c6f1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a8c6f4:
    // 00a8c6f4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8c6f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c6f8  75ca                   -jne 0xa8c6c4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c6c4;
    }
    // 00a8c6fa  833da03ea90000         +cmp dword ptr [0xa93ea0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c701  750c                   -jne 0xa8c70f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c70f;
    }
    // 00a8c703  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8c708  e8a3a5ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c70d  eb0f                   -jmp 0xa8c71e
    goto L_0x00a8c71e;
L_0x00a8c70f:
    // 00a8c70f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00a8c714  a1a43ea900             -mov eax, dword ptr [0xa93ea4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8c719  e8d2e9ffff             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8c71e:
    // 00a8c71e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c720  750a                   -jne 0xa8c72c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c72c;
    }
    // 00a8c722  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8c727  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c728  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c729  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c72a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c72b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c72c:
    // 00a8c72c  a3a43ea900             -mov dword ptr [0xa93ea4], eax
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.eax;
    // 00a8c731  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00a8c737  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8c73a  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8c73f  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a8c742:
    // 00a8c742  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c744  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c745  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c746  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c747  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c748  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c750(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c751  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c758  7421                   -je 0xa8c77b
    if (cpu.flags.zf)
    {
        goto L_0x00a8c77b;
    }
    // 00a8c75a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8c75c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8c75e  8a9b614aa900           -mov bl, byte ptr [ebx + 0xa94a61]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8c764  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8c767  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8c76d  740c                   -je 0xa8c77b
    if (cpu.flags.zf)
    {
        goto L_0x00a8c77b;
    }
    // 00a8c76f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8c771  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a8c773  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8c776  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a8c779  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c77a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c77b:
    // 00a8c77b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8c77d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a8c77f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c780  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c790  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c797  741c                   -je 0xa8c7b5
    if (cpu.flags.zf)
    {
        goto L_0x00a8c7b5;
    }
    // 00a8c799  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8c79b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8c7a0  8a80614aa900           -mov al, byte ptr [eax + 0xa94a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8c7a6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8c7a8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8c7ad  7406                   -je 0xa8c7b5
    if (cpu.flags.zf)
    {
        goto L_0x00a8c7b5;
    }
    // 00a8c7af  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8c7b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c7b5:
    // 00a8c7b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8c7ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8c7c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c7c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c7c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c7c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8c7c3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8c7c6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a8c7c8:
    // 00a8c7c8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8c7ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c7cc  e89fe5ffff             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8c7d3  7531                   -jne 0xa8c806
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c806;
    }
    // 00a8c7d5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c7d7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8c7d9  e802210000             -call 0xa8e8e0
    cpu.esp -= 4;
    sub_a8e8e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7de  e83d210000             -call 0xa8e920
    cpu.esp -= 4;
    sub_a8e920(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7e3  e8a8210000             -call 0xa8e990
    cpu.esp -= 4;
    sub_a8e990(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7e8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8c7ea  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a8c7ec  e89fffffff             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7f1  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a8c7f4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8c7f6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c7f8  e853ffffff             -call 0xa8c750
    cpu.esp -= 4;
    sub_a8c750(app, cpu);
    if (cpu.terminate) return;
    // 00a8c7fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c7ff  e80ce6ffff             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a8c804  ebc2                   -jmp 0xa8c7c8
    goto L_0x00a8c7c8;
L_0x00a8c806:
    // 00a8c806  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8c808  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8c80b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c80c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c80d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c80e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8c810(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c812  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8c814  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c816  7541                   -jne 0xa8c859
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c859;
    }
    // 00a8c818  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8c81f  741f                   -je 0xa8c840
    if (cpu.flags.zf)
    {
        goto L_0x00a8c840;
    }
    // 00a8c821  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8c823  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8c825  8a9b614aa900           -mov bl, byte ptr [ebx + 0xa94a61]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8c82b  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8c82e  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8c834  740a                   -je 0xa8c840
    if (cpu.flags.zf)
    {
        goto L_0x00a8c840;
    }
    // 00a8c836  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8c839  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8c83c  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8c83e  7505                   -jne 0xa8c845
    if (!cpu.flags.zf)
    {
        goto L_0x00a8c845;
    }
L_0x00a8c840:
    // 00a8c840  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c842  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c843  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c844  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c845:
    // 00a8c845  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a8c847  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8c84c  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a8c84e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8c854  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8c856  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c857  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c858  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8c859:
    // 00a8c859  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8c85b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8c85d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c85f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8c861  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8c863  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8c865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c866  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c868(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c868  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c869  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8c86b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c86d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c86e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c86f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8c872  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c874  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8c876  81fa00200000           +cmp edx, 0x2000
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
    // 00a8c87c  7c05                   -jl 0xa8c883
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8c883;
    }
    // 00a8c87e  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a8c883:
    // 00a8c883  b9e42aa900             -mov ecx, 0xa92ae4
    cpu.ecx = 11086564 /*0xa92ae4*/;
    // 00a8c888  eb2e                   -jmp 0xa8c8b8
    goto L_0x00a8c8b8;
L_0x00a8c88a:
    // 00a8c88a  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a8c88f  7422                   -je 0xa8c8b3
    if (cpu.flags.zf)
    {
        goto L_0x00a8c8b3;
    }
    // 00a8c891  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8c895  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a8c899  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8c89c  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a8c89f  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c8a2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8c8a4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8c8a6  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a8c8a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8c8ab  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8c8ad  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8c8af  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8c8b1  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a8c8b3:
    // 00a8c8b3  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a8c8b5  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a8c8b8:
    // 00a8c8b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8c8ba  7fce                   -jg 0xa8c88a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8c88a;
    }
    // 00a8c8bc  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8c8bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c8bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8c8bc;
    // 00a8c868  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c869  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8c86b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c86d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c86e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c86f  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8c872  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c874  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8c876  81fa00200000           +cmp edx, 0x2000
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
    // 00a8c87c  7c05                   -jl 0xa8c883
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8c883;
    }
    // 00a8c87e  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x00a8c883:
    // 00a8c883  b9e42aa900             -mov ecx, 0xa92ae4
    cpu.ecx = 11086564 /*0xa92ae4*/;
    // 00a8c888  eb2e                   -jmp 0xa8c8b8
    goto L_0x00a8c8b8;
L_0x00a8c88a:
    // 00a8c88a  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 00a8c88f  7422                   -je 0xa8c8b3
    if (cpu.flags.zf)
    {
        goto L_0x00a8c8b3;
    }
    // 00a8c891  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8c895  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 00a8c899  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8c89c  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a8c89f  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c8a2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8c8a4  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8c8a6  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a8c8a9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8c8ab  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8c8ad  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8c8af  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8c8b1  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a8c8b3:
    // 00a8c8b3  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00a8c8b5  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x00a8c8b8:
    // 00a8c8b8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8c8ba  7fce                   -jg 0xa8c88a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8c88a;
    }
L_entry_0x00a8c8bc:
    // 00a8c8bc  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8c8bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8c8c5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c8c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c8c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8c8c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c8c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c8ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c8cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c8cc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8c8cf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c8d1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c8d3  74e7                   -je 0xa8c8bc
    if (cpu.flags.zf)
    {
        return sub_a8c8bc(app, cpu);
    }
    // 00a8c8d5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c8d7  9b                     -wait 
    /*nothing*/;
    // 00a8c8d8  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8c8db  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8dc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8c8de  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a8c8e1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8c8e6  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 00a8c8eb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8c8ec  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8c8ef  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c8f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8c8f2  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 00a8c8f6  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 00a8c8fb  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a8c8fe  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a8c901  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8c903  7d1b                   -jge 0xa8c920
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8c920;
    }
    // 00a8c905  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c908  f7da                   +neg edx
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
    // 00a8c90a  e859ffffff             -call 0xa8c868
    cpu.esp -= 4;
    sub_a8c868(app, cpu);
    if (cpu.terminate) return;
    // 00a8c90f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a8c911  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c914  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8c916  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8c918  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8c91a  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8c91c  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8c91e  eb17                   -jmp 0xa8c937
    goto L_0x00a8c937;
L_0x00a8c920:
    // 00a8c920  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c923  e840ffffff             -call 0xa8c868
    cpu.esp -= 4;
    sub_a8c868(app, cpu);
    if (cpu.terminate) return;
    // 00a8c928  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a8c92a  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8c92d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8c92f  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8c931  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8c933  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8c935  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a8c937:
    // 00a8c937  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8c939  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 00a8c93c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8c93d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8c940  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c941  e976ffffff             -jmp 0xa8c8bc
    return sub_a8c8bc(app, cpu);
}

}
