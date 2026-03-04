#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_4ccbfa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccbfa  b800520000             -mov eax, 0x5200
    cpu.eax = 20992 /*0x5200*/;
    // 004ccbff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc01  b800530000             -mov eax, 0x5300
    cpu.eax = 21248 /*0x5300*/;
    // 004ccc06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc08  b8004c0000             -mov eax, 0x4c00
    cpu.eax = 19456 /*0x4c00*/;
    // 004ccc0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc0f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc0f  b8003b0000             -mov eax, 0x3b00
    cpu.eax = 15104 /*0x3b00*/;
    // 004ccc14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc16  b8003c0000             -mov eax, 0x3c00
    cpu.eax = 15360 /*0x3c00*/;
    // 004ccc1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc1d  b8003d0000             -mov eax, 0x3d00
    cpu.eax = 15616 /*0x3d00*/;
    // 004ccc22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc23  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc24  b8003e0000             -mov eax, 0x3e00
    cpu.eax = 15872 /*0x3e00*/;
    // 004ccc29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc2b  b8003f0000             -mov eax, 0x3f00
    cpu.eax = 16128 /*0x3f00*/;
    // 004ccc30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc32  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 004ccc37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc39  b800410000             -mov eax, 0x4100
    cpu.eax = 16640 /*0x4100*/;
    // 004ccc3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc40  b800420000             -mov eax, 0x4200
    cpu.eax = 16896 /*0x4200*/;
    // 004ccc45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc47(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc47  b800430000             -mov eax, 0x4300
    cpu.eax = 17152 /*0x4300*/;
    // 004ccc4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc4e  b800440000             -mov eax, 0x4400
    cpu.eax = 17408 /*0x4400*/;
    // 004ccc53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc55  b800870000             -mov eax, 0x8700
    cpu.eax = 34560 /*0x8700*/;
    // 004ccc5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc5c  b800880000             -mov eax, 0x8800
    cpu.eax = 34816 /*0x8800*/;
    // 004ccc61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ccc63(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ccc65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccc66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ccc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccc70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccc71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccc72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccc73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ccc74  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ccc76  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ccc79  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ccc7c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ccc7f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ccc81  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ccc83  0f85a7000000           -jne 0x4ccd30
    if (!cpu.flags.zf)
    {
        goto L_0x004ccd30;
    }
    // 004ccc89  833d4c3d9f0000         +cmp dword ptr [0x9f3d4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccc90  0f849a000000           -je 0x4ccd30
    if (cpu.flags.zf)
    {
        goto L_0x004ccd30;
    }
    // 004ccc96  a184125600             -mov eax, dword ptr [0x561284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640836) /* 0x561284 */);
    // 004ccc9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ccc9d  7434                   -je 0x4cccd3
    if (cpu.flags.zf)
    {
        goto L_0x004cccd3;
    }
    // 004ccc9f  f6451f20               +test byte ptr [ebp + 0x1f], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(31) /* 0x1f */) & 32 /*0x20*/));
    // 004ccca3  742e                   -je 0x4cccd3
    if (cpu.flags.zf)
    {
        goto L_0x004cccd3;
    }
    // 004ccca5  c745fc38000000         -mov dword ptr [ebp - 4], 0x38
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 56 /*0x38*/;
    // 004cccac  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cccaf  7514                   -jne 0x4cccc5
    if (!cpu.flags.zf)
    {
        goto L_0x004cccc5;
    }
    // 004cccb1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004cccb6  890d48945500           -mov dword ptr [0x559448], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608520) /* 0x559448 */) = cpu.ecx;
    // 004cccbc  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 004cccc1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004cccc3  eb51                   -jmp 0x4ccd16
    goto L_0x004ccd16;
L_0x004cccc5:
    // 004cccc5  83fb1b                 +cmp ebx, 0x1b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cccc8  754c                   -jne 0x4ccd16
    if (!cpu.flags.zf)
    {
        goto L_0x004ccd16;
    }
    // 004cccca  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004ccccf  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004cccd1  eb43                   -jmp 0x4ccd16
    goto L_0x004ccd16;
L_0x004cccd3:
    // 004cccd3  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004cccd5  2eff1538475300         -call dword ptr cs:[0x534738]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457720) /* 0x534738 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cccdc  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004cccdf  7d15                   -jge 0x4cccf6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cccf6;
    }
    // 004ccce1  c745fc1d000000         -mov dword ptr [ebp - 4], 0x1d
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 29 /*0x1d*/;
    // 004ccce8  83fb1b                 +cmp ebx, 0x1b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccceb  7529                   -jne 0x4ccd16
    if (!cpu.flags.zf)
    {
        goto L_0x004ccd16;
    }
    // 004ccced  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004cccf2  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004cccf4  eb20                   -jmp 0x4ccd16
    goto L_0x004ccd16;
L_0x004cccf6:
    // 004cccf6  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cccf9  740f                   -je 0x4ccd0a
    if (cpu.flags.zf)
    {
        goto L_0x004ccd0a;
    }
    // 004cccfb  83fb5c                 +cmp ebx, 0x5c
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cccfe  740a                   -je 0x4ccd0a
    if (cpu.flags.zf)
    {
        goto L_0x004ccd0a;
    }
    // 004ccd00  83fb5d                 +cmp ebx, 0x5d
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccd03  7405                   -je 0x4ccd0a
    if (cpu.flags.zf)
    {
        goto L_0x004ccd0a;
    }
    // 004ccd05  83fb2c                 +cmp ebx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccd08  750c                   -jne 0x4ccd16
    if (!cpu.flags.zf)
    {
        goto L_0x004ccd16;
    }
L_0x004ccd0a:
    // 004ccd0a  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004ccd0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ccd11  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ccd13  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x004ccd16:
    // 004ccd16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ccd18  7416                   -je 0x4ccd30
    if (cpu.flags.zf)
    {
        goto L_0x004ccd30;
    }
    // 004ccd1a  833d8812560000         +cmp dword ptr [0x561288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640840) /* 0x561288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccd21  740d                   -je 0x4ccd30
    if (cpu.flags.zf)
    {
        goto L_0x004ccd30;
    }
    // 004ccd23  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ccd26  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ccd28  ff1588125600           -call dword ptr [0x561288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5640840) /* 0x561288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccd2e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004ccd30:
    // 004ccd30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ccd32  7407                   -je 0x4ccd3b
    if (cpu.flags.zf)
    {
        goto L_0x004ccd3b;
    }
    // 004ccd34  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ccd39  eb16                   -jmp 0x4ccd51
    goto L_0x004ccd51;
L_0x004ccd3b:
    // 004ccd3b  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ccd3e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccd3f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccd40  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ccd43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccd44  a17c125600             -mov eax, dword ptr [0x56127c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */);
    // 004ccd49  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ccd4a  2eff15f4465300         -call dword ptr cs:[0x5346f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457652) /* 0x5346f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ccd51:
    // 004ccd51  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ccd53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccd54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccd55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccd56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccd57  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4ccd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccd60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccd61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccd62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccd63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ccd64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ccd66  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccd6a  7453                   -je 0x4ccdbf
    if (cpu.flags.zf)
    {
        goto L_0x004ccdbf;
    }
    // 004ccd6c  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004ccd6f  3b0d243d9f00           +cmp ecx, dword ptr [0x9f3d24]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccd75  7548                   -jne 0x4ccdbf
    if (!cpu.flags.zf)
    {
        goto L_0x004ccdbf;
    }
    // 004ccd77  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004ccd7c  8b3580125600           -mov esi, dword ptr [0x561280]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640832) /* 0x561280 */);
    // 004ccd82  891d4c3d9f00           -mov dword ptr [0x9f3d4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */) = cpu.ebx;
    // 004ccd88  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ccd8a  741f                   -je 0x4ccdab
    if (cpu.flags.zf)
    {
        goto L_0x004ccdab;
    }
    // 004ccd8c  8b3d7c125600           -mov edi, dword ptr [0x56127c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */);
    // 004ccd92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ccd94  7515                   -jne 0x4ccdab
    if (!cpu.flags.zf)
    {
        goto L_0x004ccdab;
    }
    // 004ccd96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccd97  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccd98  6870cc4c00             -push 0x4ccc70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033072 /*0x4ccc70*/;
    cpu.esp -= 4;
    // 004ccd9d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ccd9f  2eff1590475300         -call dword ptr cs:[0x534790]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457808) /* 0x534790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccda6  a37c125600             -mov dword ptr [0x56127c], eax
    app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */) = cpu.eax;
L_0x004ccdab:
    // 004ccdab  833d84747f0000         +cmp dword ptr [0x7f7484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8352900) /* 0x7f7484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccdb2  740b                   -je 0x4ccdbf
    if (cpu.flags.zf)
    {
        goto L_0x004ccdbf;
    }
    // 004ccdb4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ccdb9  ff1584747f00           -call dword ptr [0x7f7484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(8352900) /* 0x7f7484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ccdbf:
    // 004ccdbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ccdc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccdc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccdc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccdc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccdc5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4ccdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccdd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccdd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccdd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ccdd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ccdd5  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004ccdd8  3b15243d9f00           +cmp edx, dword ptr [0x9f3d24]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccdde  7554                   -jne 0x4cce34
    if (!cpu.flags.zf)
    {
        goto L_0x004cce34;
    }
    // 004ccde0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ccde2  8b1d80125600           -mov ebx, dword ptr [0x561280]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640832) /* 0x561280 */);
    // 004ccde8  890d4c3d9f00           -mov dword ptr [0x9f3d4c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */) = cpu.ecx;
    // 004ccdee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ccdf0  7419                   -je 0x4cce0b
    if (cpu.flags.zf)
    {
        goto L_0x004cce0b;
    }
    // 004ccdf2  8b357c125600           -mov esi, dword ptr [0x56127c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */);
    // 004ccdf8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ccdfa  740f                   -je 0x4cce0b
    if (cpu.flags.zf)
    {
        goto L_0x004cce0b;
    }
    // 004ccdfc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccdfd  2eff15a8475300         -call dword ptr cs:[0x5347a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457832) /* 0x5347a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cce04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cce06  a37c125600             -mov dword ptr [0x56127c], eax
    app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */) = cpu.eax;
L_0x004cce0b:
    // 004cce0b  833d84747f0000         +cmp dword ptr [0x7f7484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8352900) /* 0x7f7484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cce12  7408                   -je 0x4cce1c
    if (cpu.flags.zf)
    {
        goto L_0x004cce1c;
    }
    // 004cce14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cce16  ff1584747f00           -call dword ptr [0x7f7484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(8352900) /* 0x7f7484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cce1c:
    // 004cce1c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004cce1e  2eff1594475300         -call dword ptr cs:[0x534794]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457812) /* 0x534794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cce25  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 004cce2a  b818485600             -mov eax, 0x564818
    cpu.eax = 5654552 /*0x564818*/;
    // 004cce2f  e8d8380100             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
L_0x004cce34:
    // 004cce34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cce36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce39  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cce40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cce40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cce41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cce43  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004cce47  7409                   -je 0x4cce52
    if (cpu.flags.zf)
    {
        goto L_0x004cce52;
    }
    // 004cce49  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cce4b  2eff156c475300         -call dword ptr cs:[0x53476c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457772) /* 0x53476c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cce52:
    // 004cce52  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cce57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce58  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4cce60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cce60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cce61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cce63  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004cce67  740a                   -je 0x4cce73
    if (cpu.flags.zf)
    {
        goto L_0x004cce73;
    }
    // 004cce69  c7057012560001000000   -mov dword ptr [0x561270], 1
    app->getMemory<x86::reg32>(x86::reg32(5640816) /* 0x561270 */) = 1 /*0x1*/;
L_0x004cce73:
    // 004cce73  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cce78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce79  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cce80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cce80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cce81  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cce83  837d0800               -cmp dword ptr [ebp + 8], 0
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
    // 004cce87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cce89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cce8a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4cce90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cce90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cce91  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cce93  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004cce96  3d60f00000             +cmp eax, 0xf060
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61536 /*0xf060*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cce9b  7424                   -je 0x4ccec1
    if (cpu.flags.zf)
    {
        goto L_0x004ccec1;
    }
    // 004cce9d  3d20f00000             +cmp eax, 0xf020
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61472 /*0xf020*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccea2  741d                   -je 0x4ccec1
    if (cpu.flags.zf)
    {
        goto L_0x004ccec1;
    }
    // 004ccea4  3d30f00000             +cmp eax, 0xf030
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61488 /*0xf030*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccea9  7416                   -je 0x4ccec1
    if (cpu.flags.zf)
    {
        goto L_0x004ccec1;
    }
    // 004cceab  3d20f10000             +cmp eax, 0xf120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61728 /*0xf120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cceb0  740f                   -je 0x4ccec1
    if (cpu.flags.zf)
    {
        goto L_0x004ccec1;
    }
    // 004cceb2  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004cceb5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cceb7  8a825d040000           -mov al, byte ptr [edx + 0x45d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
    // 004ccebd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccebe  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004ccec1:
    // 004ccec1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ccec3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccec4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4cced0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cced0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cced1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cced3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004cced6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cced8  745d                   -je 0x4ccf37
    if (cpu.flags.zf)
    {
        goto L_0x004ccf37;
    }
    // 004cceda  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ccee1  7454                   -je 0x4ccf37
    if (cpu.flags.zf)
    {
        goto L_0x004ccf37;
    }
    // 004ccee3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccee5  6874125600             -push 0x561274
    app->getMemory<x86::reg32>(cpu.esp-4) = 5640820 /*0x561274*/;
    cpu.esp -= 4;
    // 004cceea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cceec  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004cceee  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccef5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccef7  6878125600             -push 0x561278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5640824 /*0x561278*/;
    cpu.esp -= 4;
    // 004ccefc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccefe  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 004ccf00  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccf07  833d7412560000         +cmp dword ptr [0x561274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640820) /* 0x561274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccf0e  740f                   -je 0x4ccf1f
    if (cpu.flags.zf)
    {
        goto L_0x004ccf1f;
    }
    // 004ccf10  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ccf12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccf14  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccf16  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004ccf18  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ccf1f:
    // 004ccf1f  833d7812560000         +cmp dword ptr [0x561278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640824) /* 0x561278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccf26  740f                   -je 0x4ccf37
    if (cpu.flags.zf)
    {
        goto L_0x004ccf37;
    }
    // 004ccf28  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004ccf2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccf2c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ccf2e  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 004ccf30  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ccf37:
    // 004ccf37  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004ccf3a  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ccf40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ccf42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccf43  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ccf50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccf50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccf51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ccf52  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ccf54  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ccf57  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004ccf5a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ccf5c  744f                   -je 0x4ccfad
    if (cpu.flags.zf)
    {
        goto L_0x004ccfad;
    }
    // 004ccf5e  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004ccf65  7546                   -jne 0x4ccfad
    if (!cpu.flags.zf)
    {
        goto L_0x004ccfad;
    }
    // 004ccf67  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004ccf6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ccf6b  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ccf71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ccf72  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccf79  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004ccf7c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ccf7d  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004ccf83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ccf84  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ccf8b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004ccf8e  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004ccf94  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ccf97  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004ccf9d  8b1d84715600           -mov ebx, dword ptr [0x567184]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    // 004ccfa3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ccfa5  7406                   -je 0x4ccfad
    if (cpu.flags.zf)
    {
        goto L_0x004ccfad;
    }
    // 004ccfa7  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004ccfad:
    // 004ccfad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ccfaf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ccfb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccfb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ccfb3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4ccfc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ccfc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ccfc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ccfc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ccfc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ccfc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ccfc6  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004ccfc9  8b7524                 -mov esi, dword ptr [ebp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004ccfcc  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccfd0  7433                   -je 0x4cd005
    if (cpu.flags.zf)
    {
        goto L_0x004cd005;
    }
    // 004ccfd2  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004ccfd4  8b1d80747f00           -mov ebx, dword ptr [0x7f7480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8352896) /* 0x7f7480 */);
    // 004ccfda  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ccfe0  39d9                   +cmp ecx, ebx
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
    // 004ccfe2  7e02                   -jle 0x4ccfe6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ccfe6;
    }
    // 004ccfe4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x004ccfe6:
    // 004ccfe6  49                     -dec ecx
    (cpu.ecx)--;
    // 004ccfe7  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ccfea  7419                   -je 0x4cd005
    if (cpu.flags.zf)
    {
        goto L_0x004cd005;
    }
    // 004ccfec  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ccfee  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ccff0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ccff2  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004ccff5  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004ccff8  83e301                 -and ebx, 1
    cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004ccffb  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 004ccffe  e8ddf8ffff             -call 0x4cc8e0
    cpu.esp -= 4;
    sub_4cc8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd003  ebe1                   -jmp 0x4ccfe6
    goto L_0x004ccfe6;
L_0x004cd005:
    // 004cd005  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cd00a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd00b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd00c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd00d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd00e  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4cd020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd022  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd026  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004cd029  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004cd02c  8b7d24                 -mov edi, dword ptr [ebp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 004cd02f  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd033  0f8498000000           -je 0x4cd0d1
    if (cpu.flags.zf)
    {
        goto L_0x004cd0d1;
    }
    // 004cd039  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004cd03b  8b3580747f00           -mov esi, dword ptr [0x7f7480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8352896) /* 0x7f7480 */);
    // 004cd041  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004cd047  39f1                   +cmp ecx, esi
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
    // 004cd049  7e02                   -jle 0x4cd04d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cd04d;
    }
    // 004cd04b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004cd04d:
    // 004cd04d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004cd04f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004cd052  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004cd055  a38c747f00             -mov dword ptr [0x7f748c], eax
    app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */) = cpu.eax;
    // 004cd05a  a198125600             -mov eax, dword ptr [0x561298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640856) /* 0x561298 */);
    // 004cd05f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd061  7412                   -je 0x4cd075
    if (cpu.flags.zf)
    {
        goto L_0x004cd075;
    }
    // 004cd063  03058c747f00           -add eax, dword ptr [0x7f748c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */)));
    // 004cd069  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004cd06b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004cd070  a38c747f00             -mov dword ptr [0x7f748c], eax
    app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */) = cpu.eax;
L_0x004cd075:
    // 004cd075  a18c747f00             -mov eax, dword ptr [0x7f748c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */);
    // 004cd07a  c6801848560001         -mov byte ptr [eax + 0x564818], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5654552) /* 0x564818 */) = 1 /*0x1*/;
    // 004cd081  833d88747f0000         +cmp dword ptr [0x7f7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8352904) /* 0x7f7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd088  741d                   -je 0x4cd0a7
    if (cpu.flags.zf)
    {
        goto L_0x004cd0a7;
    }
L_0x004cd08a:
    // 004cd08a  49                     -dec ecx
    (cpu.ecx)--;
    // 004cd08b  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd08e  7441                   -je 0x4cd0d1
    if (cpu.flags.zf)
    {
        goto L_0x004cd0d1;
    }
    // 004cd090  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004cd092  8b158c747f00           -mov edx, dword ptr [0x7f748c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */);
    // 004cd098  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004cd09b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd09d  83e301                 +and ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004cd0a0  e83bf8ffff             -call 0x4cc8e0
    cpu.esp -= 4;
    sub_4cc8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd0a5  ebe3                   -jmp 0x4cd08a
    goto L_0x004cd08a;
L_0x004cd0a7:
    // 004cd0a7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cd0a9  e8f2f9ffff             -call 0x4ccaa0
    cpu.esp -= 4;
    sub_4ccaa0(app, cpu);
    if (cpu.terminate) return;
    // 004cd0ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004cd0b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd0b2  7422                   -je 0x4cd0d6
    if (cpu.flags.zf)
    {
        goto L_0x004cd0d6;
    }
L_0x004cd0b4:
    // 004cd0b4  49                     -dec ecx
    (cpu.ecx)--;
    // 004cd0b5  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd0b8  7417                   -je 0x4cd0d1
    if (cpu.flags.zf)
    {
        goto L_0x004cd0d1;
    }
    // 004cd0ba  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004cd0bc  8b158c747f00           -mov edx, dword ptr [0x7f748c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(8352908) /* 0x7f748c */);
    // 004cd0c2  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 004cd0c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cd0c7  83e301                 +and ebx, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/))));
    // 004cd0ca  e811f8ffff             -call 0x4cc8e0
    cpu.esp -= 4;
    sub_4cc8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd0cf  ebe3                   -jmp 0x4cd0b4
    goto L_0x004cd0b4;
L_0x004cd0d1:
    // 004cd0d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cd0d6:
    // 004cd0d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd0d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd0d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd0d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd0da  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4cd0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd0e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd0e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd0e3  837d0800               +cmp dword ptr [ebp + 8], 0
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
    // 004cd0e7  743f                   -je 0x4cd128
    if (cpu.flags.zf)
    {
        goto L_0x004cd128;
    }
    // 004cd0e9  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004cd0ec  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004cd0ef  8b0d98125600           -mov ecx, dword ptr [0x561298]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640856) /* 0x561298 */);
    // 004cd0f5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004cd0f8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cd0fa  740a                   -je 0x4cd106
    if (cpu.flags.zf)
    {
        goto L_0x004cd106;
    }
    // 004cd0fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cd0fe  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 004cd101  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x004cd106:
    // 004cd106  83f82a                 +cmp eax, 0x2a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd109  740f                   -je 0x4cd11a
    if (cpu.flags.zf)
    {
        goto L_0x004cd11a;
    }
    // 004cd10b  83f836                 +cmp eax, 0x36
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(54 /*0x36*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd10e  740a                   -je 0x4cd11a
    if (cpu.flags.zf)
    {
        goto L_0x004cd11a;
    }
    // 004cd110  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004cd112  889018485600           -mov byte ptr [eax + 0x564818], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5654552) /* 0x564818 */) = cpu.dl;
    // 004cd118  eb0e                   -jmp 0x4cd128
    goto L_0x004cd128;
L_0x004cd11a:
    // 004cd11a  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004cd11c  883542485600           -mov byte ptr [0x564842], dh
    app->getMemory<x86::reg8>(x86::reg32(5654594) /* 0x564842 */) = cpu.dh;
    // 004cd122  88354e485600           -mov byte ptr [0x56484e], dh
    app->getMemory<x86::reg8>(x86::reg32(5654606) /* 0x56484e */) = cpu.dh;
L_0x004cd128:
    // 004cd128  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd12a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd12b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4cd130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd133  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd135  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004cd138  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004cd13b  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd13f  743e                   -je 0x4cd17f
    if (cpu.flags.zf)
    {
        goto L_0x004cd17f;
    }
    // 004cd141  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd143  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004cd146  7405                   -je 0x4cd14d
    if (cpu.flags.zf)
    {
        goto L_0x004cd14d;
    }
    // 004cd148  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cd14d:
    // 004cd14d  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004cd150  7402                   -je 0x4cd154
    if (cpu.flags.zf)
    {
        goto L_0x004cd154;
    }
    // 004cd152  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004cd154:
    // 004cd154  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004cd157  7402                   -je 0x4cd15b
    if (cpu.flags.zf)
    {
        goto L_0x004cd15b;
    }
    // 004cd159  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004cd15b:
    // 004cd15b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cd15d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004cd15f  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004cd162  6689ce                 -mov si, cx
    cpu.si = cpu.cx;
    // 004cd165  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004cd16b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004cd170  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004cd176  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cd178  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cd17a  e8f1e20200             -call 0x4fb470
    cpu.esp -= 4;
    sub_4fb470(app, cpu);
    if (cpu.terminate) return;
L_0x004cd17f:
    // 004cd17f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd181  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd182  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd184  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4cd190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd191  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd192  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd193  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd195  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004cd198  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004cd19b  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd19f  743b                   -je 0x4cd1dc
    if (cpu.flags.zf)
    {
        goto L_0x004cd1dc;
    }
    // 004cd1a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd1a3  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004cd1a6  7405                   -je 0x4cd1ad
    if (cpu.flags.zf)
    {
        goto L_0x004cd1ad;
    }
    // 004cd1a8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cd1ad:
    // 004cd1ad  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004cd1b0  7402                   -je 0x4cd1b4
    if (cpu.flags.zf)
    {
        goto L_0x004cd1b4;
    }
    // 004cd1b2  0c02                   -or al, 2
    cpu.al |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004cd1b4:
    // 004cd1b4  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004cd1b7  7402                   -je 0x4cd1bb
    if (cpu.flags.zf)
    {
        goto L_0x004cd1bb;
    }
    // 004cd1b9  0c04                   -or al, 4
    cpu.al |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004cd1bb:
    // 004cd1bb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cd1bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004cd1bf  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004cd1c2  6689ce                 -mov si, cx
    cpu.si = cpu.cx;
    // 004cd1c5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004cd1cb  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004cd1d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cd1d3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cd1d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cd1d7  e894e20200             -call 0x4fb470
    cpu.esp -= 4;
    sub_4fb470(app, cpu);
    if (cpu.terminate) return;
L_0x004cd1dc:
    // 004cd1dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd1de  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd1df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd1e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd1e1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4cd1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd1f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd1f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd1f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd1f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd1f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd1f6  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004cd1f9  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004cd1fc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cd1fe  0f8481000000           -je 0x4cd285
    if (cpu.flags.zf)
    {
        goto L_0x004cd285;
    }
    // 004cd204  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd20b  0f8474000000           -je 0x4cd285
    if (cpu.flags.zf)
    {
        goto L_0x004cd285;
    }
    // 004cd211  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 004cd217  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004cd219  740b                   -je 0x4cd226
    if (cpu.flags.zf)
    {
        goto L_0x004cd226;
    }
    // 004cd21b  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004cd21e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd21f  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cd226:
    // 004cd226  8b3580445600           -mov esi, dword ptr [0x564480]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004cd22c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd22d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd233  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004cd236  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd237  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004cd23d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd23e  2eff15f0465300         -call dword ptr cs:[0x5346f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457648) /* 0x5346f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd245  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004cd248  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd249  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004cd24f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd250  2eff1530475300         -call dword ptr cs:[0x534730]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457712) /* 0x534730 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd257  8b1580445600           -mov edx, dword ptr [0x564480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 004cd25d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd25e  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd264  833d8471560000         +cmp dword ptr [0x567184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd26b  740f                   -je 0x4cd27c
    if (cpu.flags.zf)
    {
        goto L_0x004cd27c;
    }
    // 004cd26d  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cd274  7506                   -jne 0x4cd27c
    if (!cpu.flags.zf)
    {
        goto L_0x004cd27c;
    }
    // 004cd276  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cd27c:
    // 004cd27c  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004cd27f  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
L_0x004cd285:
    // 004cd285  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cd28a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd28c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd28d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd28e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd28f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd290  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4cd2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd2a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd2a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd2a3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004cd2a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd2a8  741d                   -je 0x4cd2c7
    if (cpu.flags.zf)
    {
        goto L_0x004cd2c7;
    }
    // 004cd2aa  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004cd2ad  3b9054040000           +cmp edx, dword ptr [eax + 0x454]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd2b3  7512                   -jne 0x4cd2c7
    if (!cpu.flags.zf)
    {
        goto L_0x004cd2c7;
    }
    // 004cd2b5  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cd2bc  7409                   -je 0x4cd2c7
    if (cpu.flags.zf)
    {
        goto L_0x004cd2c7;
    }
    // 004cd2be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cd2c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd2c4  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004cd2c7:
    // 004cd2c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd2c9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd2ca  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4cd2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd2d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd2d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd2d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd2d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd2d6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004cd2d9  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004cd2dc  6850c64c00             -push 0x4cc650
    app->getMemory<x86::reg32>(cpu.esp-4) = 5031504 /*0x4cc650*/;
    cpu.esp -= 4;
    // 004cd2e1  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004cd2e6  ba60707f00             -mov edx, 0x7f7060
    cpu.edx = 8351840 /*0x7f7060*/;
    // 004cd2eb  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cd2ee  8b1d68125600           -mov ebx, dword ptr [0x561268]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5640808) /* 0x561268 */);
    // 004cd2f4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004cd2f6  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004cd2f9  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004cd2fc  e8ffdf0200             -call 0x4fb300
    cpu.esp -= 4;
    sub_4fb300(app, cpu);
    if (cpu.terminate) return;
    // 004cd301  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cd303  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd305  741b                   -je 0x4cd322
    if (cpu.flags.zf)
    {
        goto L_0x004cd322;
    }
    // 004cd307  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cd30a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd30b  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004cd30e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd30f  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004cd312  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd314  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004cd317  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd318  68d0389f00             -push 0x9f38d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434768 /*0x9f38d0*/;
    cpu.esp -= 4;
    // 004cd31d  ff5204                 -call dword ptr [edx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd320  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004cd322:
    // 004cd322  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cd324  7516                   -jne 0x4cd33c
    if (!cpu.flags.zf)
    {
        goto L_0x004cd33c;
    }
    // 004cd326  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004cd329  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd32a  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004cd32d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd32e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd32f  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004cd332  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd333  2eff1524475300         -call dword ptr cs:[0x534724]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457700) /* 0x534724 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd33a  eb03                   -jmp 0x4cd33f
    goto L_0x004cd33f;
L_0x004cd33c:
    // 004cd33c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004cd33f:
    // 004cd33f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd341  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd342  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd343  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd344  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd345  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cd350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd353  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd354  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd355  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd356  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd358  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004cd35b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cd35d  8aa05d040000           -mov ah, byte ptr [eax + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
    // 004cd363  8b358c125600           -mov esi, dword ptr [0x56128c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640844) /* 0x56128c */);
    // 004cd369  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004cd36b  7439                   -je 0x4cd3a6
    if (cpu.flags.zf)
    {
        goto L_0x004cd3a6;
    }
    // 004cd36d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd36f  c7836404000000000000   -mov dword ptr [ebx + 0x464], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = 0 /*0x0*/;
    // 004cd379  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004cd37e  c7836804000000000000   -mov dword ptr [ebx + 0x468], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = 0 /*0x0*/;
    // 004cd388  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd38f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004cd391  81ce00000080           +or esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 004cd397  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cd39a  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd3a1  e998000000             -jmp 0x4cd43e
    goto L_0x004cd43e;
L_0x004cd3a6:
    // 004cd3a6  bf00000400             -mov edi, 0x40000
    cpu.edi = 262144 /*0x40000*/;
    // 004cd3ab  8a1590435600           -mov dl, byte ptr [0x564390]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5653392) /* 0x564390 */);
    // 004cd3b1  81ce0000ca00           -or esi, 0xca0000
    cpu.esi |= x86::reg32(x86::sreg32(13238272 /*0xca0000*/));
    // 004cd3b7  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004cd3ba  7408                   -je 0x4cd3c4
    if (cpu.flags.zf)
    {
        goto L_0x004cd3c4;
    }
    // 004cd3bc  81ce00000500           +or esi, 0x50000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(327680 /*0x50000*/))));
    // 004cd3c2  eb0b                   -jmp 0x4cd3cf
    goto L_0x004cd3cf;
L_0x004cd3c4:
    // 004cd3c4  bf00010400             -mov edi, 0x40100
    cpu.edi = 262400 /*0x40100*/;
    // 004cd3c9  81ce00008000           -or esi, 0x800000
    cpu.esi |= x86::reg32(x86::sreg32(8388608 /*0x800000*/));
L_0x004cd3cf:
    // 004cd3cf  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd3d6  7414                   -je 0x4cd3ec
    if (cpu.flags.zf)
    {
        goto L_0x004cd3ec;
    }
    // 004cd3d8  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 004cd3de  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004cd3e1  8b8364040000           -mov eax, dword ptr [ebx + 0x464]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 004cd3e7  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004cd3ea  eb0b                   -jmp 0x4cd3f7
    goto L_0x004cd3f7;
L_0x004cd3ec:
    // 004cd3ec  b900e0ffff             -mov ecx, 0xffffe000
    cpu.ecx = 4294959104 /*0xffffe000*/;
    // 004cd3f1  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 004cd3f4  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
L_0x004cd3f7:
    // 004cd3f7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd3fa  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004cd3fd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cd3ff  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cd402  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004cd405  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004cd408  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd40a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cd40c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd40d  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004cd410  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004cd413  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd414  2eff15ec465300         -call dword ptr cs:[0x5346ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457644) /* 0x5346ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd41b  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004cd41e  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 004cd424  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd427  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 004cd42d  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cd430  2b45ec                 -sub eax, dword ptr [ebp - 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004cd433  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd436  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cd439  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cd43c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004cd43e:
    // 004cd43e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd440  8b15483d9f00           -mov edx, dword ptr [0x9f3d48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    // 004cd446  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd447  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd449  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd44b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd44c  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cd44f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd450  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 004cd456  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd457  8b9364040000           -mov edx, dword ptr [ebx + 0x464]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 004cd45d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd45e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd45f  8b0da4125600           -mov ecx, dword ptr [0x5612a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
    // 004cd465  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd466  8b35a0125600           -mov esi, dword ptr [0x5612a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640864) /* 0x5612a0 */);
    // 004cd46c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd46d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd46e  2eff1504475300         -call dword ptr cs:[0x534704]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457668) /* 0x534704 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd475  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004cd477  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd479  744b                   -je 0x4cd4c6
    if (cpu.flags.zf)
    {
        goto L_0x004cd4c6;
    }
    // 004cd47b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd47d  2eff1580475300         -call dword ptr cs:[0x534780]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457792) /* 0x534780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd484  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cd48b  7409                   -je 0x4cd496
    if (cpu.flags.zf)
    {
        goto L_0x004cd496;
    }
    // 004cd48d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd48f  2eff1594475300         -call dword ptr cs:[0x534794]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457812) /* 0x534794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cd496:
    // 004cd496  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004cd498  a198125600             -mov eax, dword ptr [0x561298]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640856) /* 0x561298 */);
    // 004cd49d  893d14485600           -mov dword ptr [0x564814], edi
    app->getMemory<x86::reg32>(x86::reg32(5654548) /* 0x564814 */) = cpu.edi;
    // 004cd4a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd4a5  751f                   -jne 0x4cd4c6
    if (!cpu.flags.zf)
    {
        goto L_0x004cd4c6;
    }
    // 004cd4a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd4a9  e862e20200             -call 0x4fb710
    cpu.esp -= 4;
    sub_4fb710(app, cpu);
    if (cpu.terminate) return;
    // 004cd4ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cd4b3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd4b5  e856e20200             -call 0x4fb710
    cpu.esp -= 4;
    sub_4fb710(app, cpu);
    if (cpu.terminate) return;
    // 004cd4ba  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004cd4bf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd4c1  e84ae20200             -call 0x4fb710
    cpu.esp -= 4;
    sub_4fb710(app, cpu);
    if (cpu.terminate) return;
L_0x004cd4c6:
    // 004cd4c6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cd4c8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd4ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd4d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4cd4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd4e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd4e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd4e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cd4e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd4e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd4e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd4e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd4e8  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004cd4eb  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004cd4f0  e85bfeffff             -call 0x4cd350
    cpu.esp -= 4;
    sub_4cd350(app, cpu);
    if (cpu.terminate) return;
    // 004cd4f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cd4f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004cd4f9  e802260100             -call 0x4dfb00
    cpu.esp -= 4;
    sub_4dfb00(app, cpu);
    if (cpu.terminate) return;
    // 004cd4fe  a36c125600             -mov dword ptr [0x56126c], eax
    app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */) = cpu.eax;
    // 004cd503  e868260100             -call 0x4dfb70
    cpu.esp -= 4;
    sub_4dfb70(app, cpu);
    if (cpu.terminate) return;
    // 004cd508  a16c125600             -mov eax, dword ptr [0x56126c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */);
    // 004cd50d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd50f  e8ec260100             -call 0x4dfc00
    cpu.esp -= 4;
    sub_4dfc00(app, cpu);
    if (cpu.terminate) return;
    // 004cd514  8a252d3d9f00           -mov ah, byte ptr [0x9f3d2d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 004cd51a  891d243d9f00           -mov dword ptr [0x9f3d24], ebx
    app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */) = cpu.ebx;
    // 004cd520  891570125600           -mov dword ptr [0x561270], edx
    app->getMemory<x86::reg32>(x86::reg32(5640816) /* 0x561270 */) = cpu.edx;
    // 004cd526  89156c125600           -mov dword ptr [0x56126c], edx
    app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */) = cpu.edx;
    // 004cd52c  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004cd52e  752a                   -jne 0x4cd55a
    if (!cpu.flags.zf)
    {
        goto L_0x004cd55a;
    }
    // 004cd530  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd533  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd534  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd535  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd53c  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd53f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd541  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd548  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cd54b  a3343d9f00             -mov dword ptr [0x9f3d34], eax
    app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */) = cpu.eax;
    // 004cd550  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cd553  a3383d9f00             -mov dword ptr [0x9f3d38], eax
    app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */) = cpu.eax;
    // 004cd558  eb16                   -jmp 0x4cd570
    goto L_0x004cd570;
L_0x004cd55a:
    // 004cd55a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd55b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cd55d  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd564  891d343d9f00           -mov dword ptr [0x9f3d34], ebx
    app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */) = cpu.ebx;
    // 004cd56a  891d383d9f00           -mov dword ptr [0x9f3d38], ebx
    app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */) = cpu.ebx;
L_0x004cd570:
    // 004cd570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd571  2eff157c475300         -call dword ptr cs:[0x53477c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457788) /* 0x53477c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd578  c7054c3d9f0001000000   -mov dword ptr [0x9f3d4c], 1
    app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */) = 1 /*0x1*/;
L_0x004cd582:
    // 004cd582  3b35243d9f00           +cmp esi, dword ptr [0x9f3d24]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd588  0f8520010000           -jne 0x4cd6ae
    if (!cpu.flags.zf)
    {
        goto L_0x004cd6ae;
    }
    // 004cd58e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd590  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd592  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd594  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004cd597  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd598  2eff154c475300         -call dword ptr cs:[0x53474c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457740) /* 0x53474c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd59f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd5a1  744a                   -je 0x4cd5ed
    if (cpu.flags.zf)
    {
        goto L_0x004cd5ed;
    }
    // 004cd5a3  8b0d90125600           -mov ecx, dword ptr [0x561290]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004cd5a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd5aa  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd5b0  833d88747f0000         +cmp dword ptr [0x7f7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8352904) /* 0x7f7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd5b7  751a                   -jne 0x4cd5d3
    if (!cpu.flags.zf)
    {
        goto L_0x004cd5d3;
    }
    // 004cd5b9  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004cd5bc  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004cd5bf  e8dcf4ffff             -call 0x4ccaa0
    cpu.esp -= 4;
    sub_4ccaa0(app, cpu);
    if (cpu.terminate) return;
    // 004cd5c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd5c6  750b                   -jne 0x4cd5d3
    if (!cpu.flags.zf)
    {
        goto L_0x004cd5d3;
    }
    // 004cd5c8  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004cd5cb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd5cc  2eff15a4475300         -call dword ptr cs:[0x5347a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457828) /* 0x5347a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cd5d3:
    // 004cd5d3  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004cd5d6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd5d7  2eff152c475300         -call dword ptr cs:[0x53472c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457708) /* 0x53472c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd5de  8b3d90125600           -mov edi, dword ptr [0x561290]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
    // 004cd5e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd5e5  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd5eb  eb25                   -jmp 0x4cd612
    goto L_0x004cd612;
L_0x004cd5ed:
    // 004cd5ed  833d9c12560000         +cmp dword ptr [0x56129c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640860) /* 0x56129c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd5f4  7408                   -je 0x4cd5fe
    if (cpu.flags.zf)
    {
        goto L_0x004cd5fe;
    }
    // 004cd5f6  ff159c125600           -call dword ptr [0x56129c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5640860) /* 0x56129c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd5fc  eb14                   -jmp 0x4cd612
    goto L_0x004cd612;
L_0x004cd5fe:
    // 004cd5fe  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004cd603  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cd608  b870c84c00             -mov eax, 0x4cc870
    cpu.eax = 5032048 /*0x4cc870*/;
    // 004cd60d  e80e9f0100             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
L_0x004cd612:
    // 004cd612  833d7012560000         +cmp dword ptr [0x561270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640816) /* 0x561270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd619  743a                   -je 0x4cd655
    if (cpu.flags.zf)
    {
        goto L_0x004cd655;
    }
    // 004cd61b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cd61d  8b1dd0389f00           -mov ebx, dword ptr [0x9f38d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 004cd623  890d70125600           -mov dword ptr [0x561270], ecx
    app->getMemory<x86::reg32>(x86::reg32(5640816) /* 0x561270 */) = cpu.ecx;
    // 004cd629  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cd62b  7413                   -je 0x4cd640
    if (cpu.flags.zf)
    {
        goto L_0x004cd640;
    }
    // 004cd62d  833de0389f0000         +cmp dword ptr [0x9f38e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10434784) /* 0x9f38e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd634  740a                   -je 0x4cd640
    if (cpu.flags.zf)
    {
        goto L_0x004cd640;
    }
    // 004cd636  b8d0389f00             -mov eax, 0x9f38d0
    cpu.eax = 10434768 /*0x9f38d0*/;
    // 004cd63b  e810f70100             -call 0x4ecd50
    cpu.esp -= 4;
    sub_4ecd50(app, cpu);
    if (cpu.terminate) return;
L_0x004cd640:
    // 004cd640  a1243d9f00             -mov eax, dword ptr [0x9f3d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cd645  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd646  2eff1528475300         -call dword ptr cs:[0x534728]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457704) /* 0x534728 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd64d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd64f  8915243d9f00           -mov dword ptr [0x9f3d24], edx
    app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */) = cpu.edx;
L_0x004cd655:
    // 004cd655  803d2d3d9f0000         +cmp byte ptr [0x9f3d2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cd65c  0f8420ffffff           -je 0x4cd582
    if (cpu.flags.zf)
    {
        goto L_0x004cd582;
    }
    // 004cd662  e8b9ba0200             -call 0x4f9120
    cpu.esp -= 4;
    sub_4f9120(app, cpu);
    if (cpu.terminate) return;
    // 004cd667  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd669  741a                   -je 0x4cd685
    if (cpu.flags.zf)
    {
        goto L_0x004cd685;
    }
    // 004cd66b  e800ba0200             -call 0x4f9070
    cpu.esp -= 4;
    sub_4f9070(app, cpu);
    if (cpu.terminate) return;
    // 004cd670  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd672  0f850affffff           -jne 0x4cd582
    if (!cpu.flags.zf)
    {
        goto L_0x004cd582;
    }
    // 004cd678  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd679  2eff1594475300         -call dword ptr cs:[0x534794]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457812) /* 0x534794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd680  e9fdfeffff             -jmp 0x4cd582
    goto L_0x004cd582;
L_0x004cd685:
    // 004cd685  8b0d243d9f00           -mov ecx, dword ptr [0x9f3d24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cd68b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd68c  2eff155c475300         -call dword ptr cs:[0x53475c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457756) /* 0x53475c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd693  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd695  0f85e7feffff           -jne 0x4cd582
    if (!cpu.flags.zf)
    {
        goto L_0x004cd582;
    }
    // 004cd69b  8b1d243d9f00           -mov ebx, dword ptr [0x9f3d24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cd6a1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cd6a2  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd6a9  e9d4feffff             -jmp 0x4cd582
    goto L_0x004cd582;
L_0x004cd6ae:
    // 004cd6ae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd6b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd6b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4cd6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cd6c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cd6c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cd6c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd6c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cd6c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cd6c6  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004cd6c9  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cd6cc  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004cd6cf  833d9012560000         +cmp dword ptr [0x561290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd6d6  750a                   -jne 0x4cd6e2
    if (!cpu.flags.zf)
    {
        goto L_0x004cd6e2;
    }
    // 004cd6d8  e803dc0100             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd6dd  a390125600             -mov dword ptr [0x561290], eax
    app->getMemory<x86::reg32>(x86::reg32(5640848) /* 0x561290 */) = cpu.eax;
L_0x004cd6e2:
    // 004cd6e2  803d90747f0000         +cmp byte ptr [0x7f7490], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(8352912) /* 0x7f7490 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cd6e9  0f858d020000           -jne 0x4cd97c
    if (!cpu.flags.zf)
    {
        goto L_0x004cd97c;
    }
    // 004cd6ef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cd6f1  2eff154c455300         -call dword ptr cs:[0x53454c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457228) /* 0x53454c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd6f8  8b0da4125600           -mov ecx, dword ptr [0x5612a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
    // 004cd6fe  a3483d9f00             -mov dword ptr [0x9f3d48], eax
    app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */) = cpu.eax;
    // 004cd703  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cd705  751d                   -jne 0x4cd724
    if (!cpu.flags.zf)
    {
        goto L_0x004cd724;
    }
    // 004cd707  8b35c0389f00           -mov esi, dword ptr [0x9f38c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10434752) /* 0x9f38c0 */);
    // 004cd70d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cd70f  7409                   -je 0x4cd71a
    if (cpu.flags.zf)
    {
        goto L_0x004cd71a;
    }
    // 004cd711  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004cd713  a3a4125600             -mov dword ptr [0x5612a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */) = cpu.eax;
    // 004cd718  eb0a                   -jmp 0x4cd724
    goto L_0x004cd724;
L_0x004cd71a:
    // 004cd71a  c705a4125600ac125600   -mov dword ptr [0x5612a4], 0x5612ac
    app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */) = 5640876 /*0x5612ac*/;
L_0x004cd724:
    // 004cd724  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 004cd729  bad0d24c00             -mov edx, 0x4cd2d0
    cpu.edx = 5034704 /*0x4cd2d0*/;
    // 004cd72e  8b3da8125600           -mov edi, dword ptr [0x5612a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5640872) /* 0x5612a8 */);
    // 004cd734  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cd736  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
    // 004cd739  8955c0                 -mov dword ptr [ebp - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edx;
    // 004cd73c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cd73d  a1483d9f00             -mov eax, dword ptr [0x9f3d48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435912) /* 0x9f3d48 */);
    // 004cd742  894dc4                 -mov dword ptr [ebp - 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ecx;
    // 004cd745  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd746  894dc8                 -mov dword ptr [ebp - 0x38], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ecx;
    // 004cd749  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004cd74c  2eff1560475300         -call dword ptr cs:[0x534760]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457760) /* 0x534760 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd753  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004cd755  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd757  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004cd75a  8955d4                 -mov dword ptr [ebp - 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edx;
    // 004cd75d  2eff155c445300         -call dword ptr cs:[0x53445c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5456988) /* 0x53445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd764  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004cd767  a1a4125600             -mov eax, dword ptr [0x5612a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640868) /* 0x5612a4 */);
    // 004cd76c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004cd76f  a1a0125600             -mov eax, dword ptr [0x5612a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640864) /* 0x5612a0 */);
    // 004cd774  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004cd777  8d45bc                 -lea eax, [ebp - 0x44]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 004cd77a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd77b  2eff1574475300         -call dword ptr cs:[0x534774]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457780) /* 0x534774 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd782  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004cd785  751c                   -jne 0x4cd7a3
    if (!cpu.flags.zf)
    {
        goto L_0x004cd7a3;
    }
    // 004cd787  2eff1534455300         -call dword ptr cs:[0x534534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457204) /* 0x534534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cd78e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd78f  6868045400             -push 0x540468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5506152 /*0x540468*/;
    cpu.esp -= 4;
    // 004cd794  e87738f3ff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 004cd799  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cd79c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cd79e  e9ed020000             -jmp 0x4cda90
    goto L_0x004cda90;
L_0x004cd7a3:
    // 004cd7a3  e838db0100             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd7a8  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004cd7ad  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004cd7af  6860cd4c00             -push 0x4ccd60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033312 /*0x4ccd60*/;
    cpu.esp -= 4;
    // 004cd7b4  a378747f00             -mov dword ptr [0x7f7478], eax
    app->getMemory<x86::reg32>(x86::reg32(8352888) /* 0x7f7478 */) = cpu.eax;
    // 004cd7b9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004cd7bb  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004cd7bd  890d80747f00           -mov dword ptr [0x7f7480], ecx
    app->getMemory<x86::reg32>(x86::reg32(8352896) /* 0x7f7480 */) = cpu.ecx;
    // 004cd7c3  893574747f00           -mov dword ptr [0x7f7474], esi
    app->getMemory<x86::reg32>(x86::reg32(8352884) /* 0x7f7474 */) = cpu.esi;
    // 004cd7c9  89357c747f00           -mov dword ptr [0x7f747c], esi
    app->getMemory<x86::reg32>(x86::reg32(8352892) /* 0x7f747c */) = cpu.esi;
    // 004cd7cf  881590747f00           -mov byte ptr [0x7f7490], dl
    app->getMemory<x86::reg8>(x86::reg32(8352912) /* 0x7f7490 */) = cpu.dl;
    // 004cd7d5  e8f6eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd7da  68d0cd4c00             -push 0x4ccdd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033424 /*0x4ccdd0*/;
    cpu.esp -= 4;
    // 004cd7df  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004cd7e1  e8eaeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd7e6  6850cf4c00             -push 0x4ccf50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033808 /*0x4ccf50*/;
    cpu.esp -= 4;
    // 004cd7eb  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004cd7ed  e8deeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd7f2  6850cf4c00             -push 0x4ccf50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033808 /*0x4ccf50*/;
    cpu.esp -= 4;
    // 004cd7f7  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004cd7f9  e8d2eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd7fe  6840ce4c00             -push 0x4cce40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033536 /*0x4cce40*/;
    cpu.esp -= 4;
    // 004cd803  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004cd805  e8c6eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd80a  6880ce4c00             -push 0x4cce80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033600 /*0x4cce80*/;
    cpu.esp -= 4;
    // 004cd80f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cd811  e8baeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd816  68f0d14c00             -push 0x4cd1f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034480 /*0x4cd1f0*/;
    cpu.esp -= 4;
    // 004cd81b  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 004cd81d  e8aeeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd822  68a0d24c00             -push 0x4cd2a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034656 /*0x4cd2a0*/;
    cpu.esp -= 4;
    // 004cd827  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 004cd829  e8a2eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd82e  68d0ce4c00             -push 0x4cced0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033680 /*0x4cced0*/;
    cpu.esp -= 4;
    // 004cd833  6a1a                   -push 0x1a
    app->getMemory<x86::reg32>(cpu.esp-4) = 26 /*0x1a*/;
    cpu.esp -= 4;
    // 004cd835  e896eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd83a  6890ce4c00             -push 0x4cce90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033616 /*0x4cce90*/;
    cpu.esp -= 4;
    // 004cd83f  6812010000             -push 0x112
    app->getMemory<x86::reg32>(cpu.esp-4) = 274 /*0x112*/;
    cpu.esp -= 4;
    // 004cd844  e887eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd849  6860ce4c00             -push 0x4cce60
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033568 /*0x4cce60*/;
    cpu.esp -= 4;
    // 004cd84e  6866040000             -push 0x466
    app->getMemory<x86::reg32>(cpu.esp-4) = 1126 /*0x466*/;
    cpu.esp -= 4;
    // 004cd853  e878eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd858  68c0cf4c00             -push 0x4ccfc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033920 /*0x4ccfc0*/;
    cpu.esp -= 4;
    // 004cd85d  6802010000             -push 0x102
    app->getMemory<x86::reg32>(cpu.esp-4) = 258 /*0x102*/;
    cpu.esp -= 4;
    // 004cd862  e869eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd867  6820d04c00             -push 0x4cd020
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034016 /*0x4cd020*/;
    cpu.esp -= 4;
    // 004cd86c  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004cd871  e85aeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd876  6820d04c00             -push 0x4cd020
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034016 /*0x4cd020*/;
    cpu.esp -= 4;
    // 004cd87b  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 004cd880  e84beeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd885  68e0d04c00             -push 0x4cd0e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034208 /*0x4cd0e0*/;
    cpu.esp -= 4;
    // 004cd88a  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 004cd88f  e83ceeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd894  68e0d04c00             -push 0x4cd0e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034208 /*0x4cd0e0*/;
    cpu.esp -= 4;
    // 004cd899  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 004cd89e  e82deeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8a3  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8a8  6801020000             -push 0x201
    app->getMemory<x86::reg32>(cpu.esp-4) = 513 /*0x201*/;
    cpu.esp -= 4;
    // 004cd8ad  e81eeeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8b2  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8b7  6807020000             -push 0x207
    app->getMemory<x86::reg32>(cpu.esp-4) = 519 /*0x207*/;
    cpu.esp -= 4;
    // 004cd8bc  e80feeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8c1  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8c6  6804020000             -push 0x204
    app->getMemory<x86::reg32>(cpu.esp-4) = 516 /*0x204*/;
    cpu.esp -= 4;
    // 004cd8cb  e800eeffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8d0  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8d5  6803020000             -push 0x203
    app->getMemory<x86::reg32>(cpu.esp-4) = 515 /*0x203*/;
    cpu.esp -= 4;
    // 004cd8da  e8f1edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8df  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8e4  6809020000             -push 0x209
    app->getMemory<x86::reg32>(cpu.esp-4) = 521 /*0x209*/;
    cpu.esp -= 4;
    // 004cd8e9  e8e2edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8ee  6830d14c00             -push 0x4cd130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034288 /*0x4cd130*/;
    cpu.esp -= 4;
    // 004cd8f3  6806020000             -push 0x206
    app->getMemory<x86::reg32>(cpu.esp-4) = 518 /*0x206*/;
    cpu.esp -= 4;
    // 004cd8f8  e8d3edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd8fd  6890d14c00             -push 0x4cd190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034384 /*0x4cd190*/;
    cpu.esp -= 4;
    // 004cd902  6802020000             -push 0x202
    app->getMemory<x86::reg32>(cpu.esp-4) = 514 /*0x202*/;
    cpu.esp -= 4;
    // 004cd907  e8c4edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd90c  6890d14c00             -push 0x4cd190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034384 /*0x4cd190*/;
    cpu.esp -= 4;
    // 004cd911  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 004cd916  e8b5edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd91b  6890d14c00             -push 0x4cd190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034384 /*0x4cd190*/;
    cpu.esp -= 4;
    // 004cd920  6805020000             -push 0x205
    app->getMemory<x86::reg32>(cpu.esp-4) = 517 /*0x205*/;
    cpu.esp -= 4;
    // 004cd925  e8a6edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
    // 004cd92a  6890d14c00             -push 0x4cd190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5034384 /*0x4cd190*/;
    cpu.esp -= 4;
    // 004cd92f  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004cd934  e897edffff             -call 0x4cc6d0
    cpu.esp -= 4;
    sub_4cc6d0(app, cpu);
    if (cpu.terminate) return;
L_0x004cd939:
    // 004cd939  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cd93e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cd941  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004cd946  881d2d3d9f00           -mov byte ptr [0x9f3d2d], bl
    app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */) = cpu.bl;
    // 004cd94c  a3e4389f00             -mov dword ptr [0x9f38e4], eax
    app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */) = cpu.eax;
    // 004cd951  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cd954  89154c3d9f00           -mov dword ptr [0x9f3d4c], edx
    app->getMemory<x86::reg32>(x86::reg32(10435916) /* 0x9f3d4c */) = cpu.edx;
    // 004cd95a  a3e8389f00             -mov dword ptr [0x9f38e8], eax
    app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */) = cpu.eax;
    // 004cd95f  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004cd962  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004cd964  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cd965  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cd967  b8e0d44c00             -mov eax, 0x4cd4e0
    cpu.eax = 5035232 /*0x4cd4e0*/;
    // 004cd96c  e82f1e0100             -call 0x4df7a0
    cpu.esp -= 4;
    sub_4df7a0(app, cpu);
    if (cpu.terminate) return;
    // 004cd971  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cd973  7534                   -jne 0x4cd9a9
    if (!cpu.flags.zf)
    {
        goto L_0x004cd9a9;
    }
    // 004cd975  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd977  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd978  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd979  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd97a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd97b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cd97c:
    // 004cd97c  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd983  74b4                   -je 0x4cd939
    if (cpu.flags.zf)
    {
        goto L_0x004cd939;
    }
    // 004cd985  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd987  a02d3d9f00             -mov al, byte ptr [0x9f3d2d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 004cd98c  39c3                   +cmp ebx, eax
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
    // 004cd98e  7502                   -jne 0x4cd992
    if (!cpu.flags.zf)
    {
        goto L_0x004cd992;
    }
    // 004cd990  eba7                   -jmp 0x4cd939
    goto L_0x004cd939;
L_0x004cd992:
    // 004cd992  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cd995  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cd998  e833020000             -call 0x4cdbd0
    cpu.esp -= 4;
    sub_4cdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004cd99d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cd9a2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cd9a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd9a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd9a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd9a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cd9a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cd9a9:
    // 004cd9a9  833d6c12560000         +cmp dword ptr [0x56126c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd9b0  7510                   -jne 0x4cd9c2
    if (!cpu.flags.zf)
    {
        goto L_0x004cd9c2;
    }
    // 004cd9b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd9b4  e8779c0100             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004cd9b9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cd9bb  e8201f0100             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd9c0  ebe7                   -jmp 0x4cd9a9
    goto L_0x004cd9a9;
L_0x004cd9c2:
    // 004cd9c2  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd9c9  7405                   -je 0x4cd9d0
    if (cpu.flags.zf)
    {
        goto L_0x004cd9d0;
    }
    // 004cd9cb  e8d0000000             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x004cd9d0:
    // 004cd9d0  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004cd9d3  8b156c125600           -mov edx, dword ptr [0x56126c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */);
    // 004cd9d9  e842210100             -call 0x4dfb20
    cpu.esp -= 4;
    sub_4dfb20(app, cpu);
    if (cpu.terminate) return;
L_0x004cd9de:
    // 004cd9de  833d6c12560000         +cmp dword ptr [0x56126c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640812) /* 0x56126c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cd9e5  7410                   -je 0x4cd9f7
    if (cpu.flags.zf)
    {
        goto L_0x004cd9f7;
    }
    // 004cd9e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cd9e9  e8f21e0100             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cd9ee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cd9f0  e83b9c0100             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004cd9f5  ebe7                   -jmp 0x4cd9de
    goto L_0x004cd9de;
L_0x004cd9f7:
    // 004cd9f7  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004cd9fa  bf60747f00             -mov edi, 0x7f7460
    cpu.edi = 8352864 /*0x7f7460*/;
    // 004cd9ff  8a352d3d9f00           -mov dh, byte ptr [0x9f3d2d]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
    // 004cda05  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cda06  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cda07  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cda08  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cda09  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cda0a  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 004cda0c  7456                   -je 0x4cda64
    if (cpu.flags.zf)
    {
        goto L_0x004cda64;
    }
    // 004cda0e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda10  6874125600             -push 0x561274
    app->getMemory<x86::reg32>(cpu.esp-4) = 5640820 /*0x561274*/;
    cpu.esp -= 4;
    // 004cda15  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda17  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004cda19  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cda20  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda22  6878125600             -push 0x561278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5640824 /*0x561278*/;
    cpu.esp -= 4;
    // 004cda27  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda29  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 004cda2b  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cda32  833d7412560000         +cmp dword ptr [0x561274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640820) /* 0x561274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cda39  740f                   -je 0x4cda4a
    if (cpu.flags.zf)
    {
        goto L_0x004cda4a;
    }
    // 004cda3b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cda3d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda3f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda41  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004cda43  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cda4a:
    // 004cda4a  833d7812560000         +cmp dword ptr [0x561278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5640824) /* 0x561278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cda51  7438                   -je 0x4cda8b
    if (cpu.flags.zf)
    {
        goto L_0x004cda8b;
    }
    // 004cda53  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cda55  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda57  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cda59  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 004cda5b  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cda62  eb27                   -jmp 0x4cda8b
    goto L_0x004cda8b;
L_0x004cda64:
    // 004cda64  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cda6a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cda6b  2eff1588475300         -call dword ptr cs:[0x534788]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457800) /* 0x534788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cda72  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cda75  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cda78  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cda7a  e851010000             -call 0x4cdbd0
    cpu.esp -= 4;
    sub_4cdbd0(app, cpu);
    if (cpu.terminate) return;
    // 004cda7f  890d74125600           -mov dword ptr [0x561274], ecx
    app->getMemory<x86::reg32>(x86::reg32(5640820) /* 0x561274 */) = cpu.ecx;
    // 004cda85  890d78125600           -mov dword ptr [0x561278], ecx
    app->getMemory<x86::reg32>(x86::reg32(5640824) /* 0x561278 */) = cpu.ecx;
L_0x004cda8b:
    // 004cda8b  a1243d9f00             -mov eax, dword ptr [0x9f3d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
L_0x004cda90:
    // 004cda90  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cda92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cda93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cda94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cda95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cda96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4cdaa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdaa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdaa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdaa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdaa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdaa4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdaa5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdaa7  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdaae  7459                   -je 0x4cdb09
    if (cpu.flags.zf)
    {
        goto L_0x004cdb09;
    }
    // 004cdab0  8b0d74125600           -mov ecx, dword ptr [0x561274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5640820) /* 0x561274 */);
    // 004cdab6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cdab8  740e                   -je 0x4cdac8
    if (cpu.flags.zf)
    {
        goto L_0x004cdac8;
    }
    // 004cdaba  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cdabc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdabe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdabf  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 004cdac1  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cdac8:
    // 004cdac8  8b3578125600           -mov esi, dword ptr [0x561278]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640824) /* 0x561278 */);
    // 004cdace  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cdad0  740e                   -je 0x4cdae0
    if (cpu.flags.zf)
    {
        goto L_0x004cdae0;
    }
    // 004cdad2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cdad4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdad6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdad7  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 004cdad9  2eff15a0475300         -call dword ptr cs:[0x5347a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457824) /* 0x5347a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cdae0:
    // 004cdae0  b866040000             -mov eax, 0x466
    cpu.eax = 1126 /*0x466*/;
    // 004cdae5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cdae7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdae9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cdaeb  e8d0ecffff             -call 0x4cc7c0
    cpu.esp -= 4;
    sub_4cc7c0(app, cpu);
    if (cpu.terminate) return;
L_0x004cdaf0:
    // 004cdaf0  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdaf7  7410                   -je 0x4cdb09
    if (cpu.flags.zf)
    {
        goto L_0x004cdb09;
    }
    // 004cdaf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cdafb  e8e01d0100             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cdb00  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cdb02  e8299b0100             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
    // 004cdb07  ebe7                   -jmp 0x4cdaf0
    goto L_0x004cdaf0;
L_0x004cdb09:
    // 004cdb09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdb0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdb0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdb0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdb0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdb0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4cdb10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdb10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdb11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cdb12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdb13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdb15  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004cdb18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdb1a  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004cdb1d  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004cdb20  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cdb22  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004cdb24  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004cdb27  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cdb2d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdb2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdb30  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cdb33  2eff1558475300         -call dword ptr cs:[0x534758]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457752) /* 0x534758 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdb3a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb3b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cdb3e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb3f  2eff15ec465300         -call dword ptr cs:[0x5346ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457644) /* 0x5346ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdb46  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cdb49  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cdb4c  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 004cdb4e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cdb50  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cdb53  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb54  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cdb57  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdb59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb5a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdb5b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdb5c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdb5e  a1243d9f00             -mov eax, dword ptr [0x9f3d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cdb63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb64  2eff158c475300         -call dword ptr cs:[0x53478c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457804) /* 0x53478c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdb6b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cdb6e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb6f  8b15243d9f00           -mov edx, dword ptr [0x9f3d24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cdb75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdb76  2eff153c475300         -call dword ptr cs:[0x53473c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457724) /* 0x53473c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdb7d  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cdb80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb81  8b0d243d9f00           -mov ecx, dword ptr [0x9f3d24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cdb87  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdb88  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdb8f  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cdb92  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cdb93  8b1d243d9f00           -mov ebx, dword ptr [0x9f3d24]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10435876) /* 0x9f3d24 */);
    // 004cdb99  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdb9a  2eff1500475300         -call dword ptr cs:[0x534700]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457664) /* 0x534700 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdba1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cdba4  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cdba7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004cdba9  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cdbac  a3e4389f00             -mov dword ptr [0x9f38e4], eax
    app->getMemory<x86::reg32>(x86::reg32(10434788) /* 0x9f38e4 */) = cpu.eax;
    // 004cdbb1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cdbb4  8935343d9f00           -mov dword ptr [0x9f3d34], esi
    app->getMemory<x86::reg32>(x86::reg32(10435892) /* 0x9f3d34 */) = cpu.esi;
    // 004cdbba  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004cdbbc  893d383d9f00           -mov dword ptr [0x9f3d38], edi
    app->getMemory<x86::reg32>(x86::reg32(10435896) /* 0x9f3d38 */) = cpu.edi;
    // 004cdbc2  a3e8389f00             -mov dword ptr [0x9f38e8], eax
    app->getMemory<x86::reg32>(x86::reg32(10434792) /* 0x9f38e8 */) = cpu.eax;
    // 004cdbc7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cdbc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdbca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdbcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdbcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4cdbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdbd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdbd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdbd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdbd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cdbd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdbd5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdbd7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cdbd9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cdbdb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004cdbdd  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdbe4  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004cdbe6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cdbe8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004cdbeb  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cdbed  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004cdbef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdbf1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004cdbf3  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdbfa  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdbfc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cdbfe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004cdc01  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cdc03  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004cdc05  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004cdc07  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004cdc09  e802ffffff             -call 0x4cdb10
    cpu.esp -= 4;
    sub_4cdb10(app, cpu);
    if (cpu.terminate) return;
    // 004cdc0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4cdc20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdc20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdc21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdc22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdc23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdc24  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdc26  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004cdc28  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdc2f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004cdc31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cdc33  2eff1550475300         -call dword ptr cs:[0x534750]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457744) /* 0x534750 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdc3a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004cdc3c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cdc3e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cdc40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cdc42  e8c9feffff             -call 0x4cdb10
    cpu.esp -= 4;
    sub_4cdb10(app, cpu);
    if (cpu.terminate) return;
    // 004cdc47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cdc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdc50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdc51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdc52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdc53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdc54  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdc56  803d2d3d9f0000         +cmp byte ptr [0x9f3d2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10435885) /* 0x9f3d2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004cdc5d  7420                   -je 0x4cdc7f
    if (cpu.flags.zf)
    {
        goto L_0x004cdc7f;
    }
    // 004cdc5f  8b157c125600           -mov edx, dword ptr [0x56127c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */);
    // 004cdc65  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004cdc67  7416                   -je 0x4cdc7f
    if (cpu.flags.zf)
    {
        goto L_0x004cdc7f;
    }
    // 004cdc69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdc6a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdc6c  2eff15a8475300         -call dword ptr cs:[0x5347a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457832) /* 0x5347a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdc73  891d7c125600           -mov dword ptr [0x56127c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */) = cpu.ebx;
    // 004cdc79  891d80125600           -mov dword ptr [0x561280], ebx
    app->getMemory<x86::reg32>(x86::reg32(5640832) /* 0x561280 */) = cpu.ebx;
L_0x004cdc7f:
    // 004cdc7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdc83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4cdc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdc90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdc91  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdc92  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdc94  891588125600           -mov dword ptr [0x561288], edx
    app->getMemory<x86::reg32>(x86::reg32(5640840) /* 0x561288 */) = cpu.edx;
    // 004cdc9a  8b157c125600           -mov edx, dword ptr [0x56127c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */);
    // 004cdca0  a384125600             -mov dword ptr [0x561284], eax
    app->getMemory<x86::reg32>(x86::reg32(5640836) /* 0x561284 */) = cpu.eax;
    // 004cdca5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004cdca7  7520                   -jne 0x4cdcc9
    if (!cpu.flags.zf)
    {
        goto L_0x004cdcc9;
    }
    // 004cdca9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdcaa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdcab  6870cc4c00             -push 0x4ccc70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5033072 /*0x4ccc70*/;
    cpu.esp -= 4;
    // 004cdcb0  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cdcb2  2eff1590475300         -call dword ptr cs:[0x534790]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457808) /* 0x534790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cdcb9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004cdcbe  a37c125600             -mov dword ptr [0x56127c], eax
    app->getMemory<x86::reg32>(x86::reg32(5640828) /* 0x56127c */) = cpu.eax;
    // 004cdcc3  890d80125600           -mov dword ptr [0x561280], ecx
    app->getMemory<x86::reg32>(x86::reg32(5640832) /* 0x561280 */) = cpu.ecx;
L_0x004cdcc9:
    // 004cdcc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdcca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdccb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cdcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdcd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdcd1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdcd2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdcd4  83f820                 +cmp eax, 0x20
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
    // 004cdcd7  7e07                   -jle 0x4cdce0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cdce0;
    }
    // 004cdcd9  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 004cdcde  eb0a                   -jmp 0x4cdcea
    goto L_0x004cdcea;
L_0x004cdce0:
    // 004cdce0  83f801                 +cmp eax, 1
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
    // 004cdce3  7d05                   -jge 0x4cdcea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cdcea;
    }
    // 004cdce5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cdcea:
    // 004cdcea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cdcec  a380747f00             -mov dword ptr [0x7f7480], eax
    app->getMemory<x86::reg32>(x86::reg32(8352896) /* 0x7f7480 */) = cpu.eax;
    // 004cdcf1  891574747f00           -mov dword ptr [0x7f7474], edx
    app->getMemory<x86::reg32>(x86::reg32(8352884) /* 0x7f7474 */) = cpu.edx;
    // 004cdcf7  89157c747f00           -mov dword ptr [0x7f747c], edx
    app->getMemory<x86::reg32>(x86::reg32(8352892) /* 0x7f747c */) = cpu.edx;
    // 004cdcfd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdcfe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdcff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4cdd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdd00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdd02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdd03  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdd05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cdd07:
    // 004cdd07  3b05a0fd5e00           +cmp eax, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdd0d  7d0c                   -jge 0x4cdd1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cdd1b;
    }
    // 004cdd0f  40                     -inc eax
    (cpu.eax)++;
    // 004cdd10  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004cdd12  890c85ac125600         -mov dword ptr [eax*4 + 0x5612ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5640876) /* 0x5612ac */ + cpu.eax * 4) = cpu.ecx;
    // 004cdd19  ebec                   -jmp 0x4cdd07
    goto L_0x004cdd07;
L_0x004cdd1b:
    // 004cdd1b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cdd1d  891df0125600           -mov dword ptr [0x5612f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5640944) /* 0x5612f0 */) = cpu.ebx;
    // 004cdd23  e8d8000000             -call 0x4cde00
    cpu.esp -= 4;
    sub_4cde00(app, cpu);
    if (cpu.terminate) return;
    // 004cdd28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdd29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdd2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdd2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cdd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdd30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdd31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdd32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdd33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cdd34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdd35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdd37  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cdd39  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cdd3b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004cdd3d  8a9a00020000           -mov bl, byte ptr [edx + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004cdd43  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004cdd45  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004cdd48  743e                   -je 0x4cdd88
    if (cpu.flags.zf)
    {
        goto L_0x004cdd88;
    }
    // 004cdd4a  8b8ac4020000           -mov ecx, dword ptr [edx + 0x2c4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
    // 004cdd50  83f903                 +cmp ecx, 3
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
    // 004cdd53  7533                   -jne 0x4cdd88
    if (!cpu.flags.zf)
    {
        goto L_0x004cdd88;
    }
    // 004cdd55  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004cdd5c  742a                   -je 0x4cdd88
    if (cpu.flags.zf)
    {
        goto L_0x004cdd88;
    }
    // 004cdd5e  3b88c4020000           +cmp ecx, dword ptr [eax + 0x2c4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdd64  7522                   -jne 0x4cdd88
    if (!cpu.flags.zf)
    {
        goto L_0x004cdd88;
    }
    // 004cdd66  8bb038020000           -mov esi, dword ptr [eax + 0x238]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(568) /* 0x238 */);
    // 004cdd6c  3bb238020000           +cmp esi, dword ptr [edx + 0x238]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdd72  7e0a                   -jle 0x4cdd7e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cdd7e;
    }
    // 004cdd74  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004cdd79  e974000000             -jmp 0x4cddf2
    goto L_0x004cddf2;
L_0x004cdd7e:
    // 004cdd7e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cdd83  e96a000000             -jmp 0x4cddf2
    goto L_0x004cddf2;
L_0x004cdd88:
    // 004cdd88  f6820002000001         +test byte ptr [edx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004cdd8f  7409                   -je 0x4cdd9a
    if (cpu.flags.zf)
    {
        goto L_0x004cdd9a;
    }
    // 004cdd91  83bac402000003         +cmp dword ptr [edx + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cdd98  743d                   -je 0x4cddd7
    if (cpu.flags.zf)
    {
        goto L_0x004cddd7;
    }
L_0x004cdd9a:
    // 004cdd9a  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004cdda1  7409                   -je 0x4cddac
    if (cpu.flags.zf)
    {
        goto L_0x004cddac;
    }
    // 004cdda3  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cddaa  7441                   -je 0x4cdded
    if (cpu.flags.zf)
    {
        goto L_0x004cdded;
    }
L_0x004cddac:
    // 004cddac  8b9824020000           -mov ebx, dword ptr [eax + 0x224]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(548) /* 0x224 */);
    // 004cddb2  8b8a24020000           -mov ecx, dword ptr [edx + 0x224]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */);
    // 004cddb8  39d9                   +cmp ecx, ebx
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
    // 004cddba  7e0b                   -jle 0x4cddc7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cddc7;
    }
    // 004cddbc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004cddc1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cddc7:
    // 004cddc7  7524                   -jne 0x4cdded
    if (!cpu.flags.zf)
    {
        goto L_0x004cdded;
    }
    // 004cddc9  8bb828020000           -mov edi, dword ptr [eax + 0x228]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004cddcf  3bba28020000           +cmp edi, dword ptr [edx + 0x228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(552) /* 0x228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cddd5  7e0b                   -jle 0x4cdde2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cdde2;
    }
L_0x004cddd7:
    // 004cddd7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004cdddc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdddd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdde0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdde1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cdde2:
    // 004cdde2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cdde7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdde8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdde9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cdded:
    // 004cdded  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cddf2:
    // 004cddf2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddf3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cddf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cde00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cde00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cde01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cde02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cde03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cde04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cde05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cde07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cde09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004cde0b:
    // 004cde0b  3b05a0fd5e00           +cmp eax, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cde11  7d14                   -jge 0x4cde27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cde27;
    }
    // 004cde13  8b148548fc5e00         -mov edx, dword ptr [eax*4 + 0x5efc48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.eax * 4);
    // 004cde1a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cde1b  c782bc02000000000000   -mov dword ptr [edx + 0x2bc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(700) /* 0x2bc */) = 0 /*0x0*/;
    // 004cde25  ebe4                   -jmp 0x4cde0b
    goto L_0x004cde0b;
L_0x004cde27:
    // 004cde27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cde29:
    // 004cde29  3b15a0fd5e00           +cmp edx, dword ptr [0x5efda0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225312) /* 0x5efda0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cde2f  7d4e                   -jge 0x4cde7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cde7f;
    }
    // 004cde31  8b049548fc5e00         -mov eax, dword ptr [edx*4 + 0x5efc48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224968) /* 0x5efc48 */ + cpu.edx * 4);
    // 004cde38  8a9800020000           -mov bl, byte ptr [eax + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 004cde3e  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004cde41  7539                   -jne 0x4cde7c
    if (!cpu.flags.zf)
    {
        goto L_0x004cde7c;
    }
    // 004cde43  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004cde46  7409                   -je 0x4cde51
    if (cpu.flags.zf)
    {
        goto L_0x004cde51;
    }
    // 004cde48  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cde4f  742b                   -je 0x4cde7c
    if (cpu.flags.zf)
    {
        goto L_0x004cde7c;
    }
L_0x004cde51:
    // 004cde51  f6800002000004         +test byte ptr [eax + 0x200], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 4 /*0x4*/));
    // 004cde58  741a                   -je 0x4cde74
    if (cpu.flags.zf)
    {
        goto L_0x004cde74;
    }
    // 004cde5a  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cde61  7e11                   -jle 0x4cde74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cde74;
    }
    // 004cde63  8b88f0010000           -mov ecx, dword ptr [eax + 0x1f0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004cde69  66833c4dca227a0000     +cmp word ptr [ecx*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.ecx * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cde72  7508                   -jne 0x4cde7c
    if (!cpu.flags.zf)
    {
        goto L_0x004cde7c;
    }
L_0x004cde74:
    // 004cde74  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cde75  8904b5ac125600         -mov dword ptr [esi*4 + 0x5612ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5640876) /* 0x5612ac */ + cpu.esi * 4) = cpu.eax;
L_0x004cde7c:
    // 004cde7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cde7d  ebaa                   -jmp 0x4cde29
    goto L_0x004cde29;
L_0x004cde7f:
    // 004cde7f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cde81  743b                   -je 0x4cdebe
    if (cpu.flags.zf)
    {
        goto L_0x004cdebe;
    }
    // 004cde83  b930dd4c00             -mov ecx, 0x4cdd30
    cpu.ecx = 5037360 /*0x4cdd30*/;
    // 004cde88  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004cde8d  b8b0125600             -mov eax, 0x5612b0
    cpu.eax = 5640880 /*0x5612b0*/;
    // 004cde92  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004cde94  8935f0125600           -mov dword ptr [0x5612f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5640944) /* 0x5612f0 */) = cpu.esi;
    // 004cde9a  e859060200             -call 0x4ee4f8
    cpu.esp -= 4;
    sub_4ee4f8(app, cpu);
    if (cpu.terminate) return;
    // 004cde9f  8b35f0125600           -mov esi, dword ptr [0x5612f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5640944) /* 0x5612f0 */);
    // 004cdea5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cdea7:
    // 004cdea7  39f0                   +cmp eax, esi
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
    // 004cdea9  7d13                   -jge 0x4cdebe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cdebe;
    }
    // 004cdeab  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004cdeae  8b1485b0125600         -mov edx, dword ptr [eax*4 + 0x5612b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5640880) /* 0x5612b0 */ + cpu.eax * 4);
    // 004cdeb5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cdeb6  898abc020000           -mov dword ptr [edx + 0x2bc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(700) /* 0x2bc */) = cpu.ecx;
    // 004cdebc  ebe9                   -jmp 0x4cdea7
    goto L_0x004cdea7;
L_0x004cdebe:
    // 004cdebe  8935f0125600           -mov dword ptr [0x5612f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5640944) /* 0x5612f0 */) = cpu.esi;
    // 004cdec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdec5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdec6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdec7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdec8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdec9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4cded0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cded0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cded1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cded3  8b80bc020000           -mov eax, dword ptr [eax + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(700) /* 0x2bc */);
    // 004cded9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdeda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4cdee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdee0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdee1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdee3  a1f0125600             -mov eax, dword ptr [0x5612f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640944) /* 0x5612f0 */);
    // 004cdee8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdee9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4cdef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdef0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdef1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdef3  83f801                 +cmp eax, 1
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
    // 004cdef6  7e09                   -jle 0x4cdf01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cdf01;
    }
    // 004cdef8  8b0485a8125600         -mov eax, dword ptr [eax*4 + 0x5612a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5640872) /* 0x5612a8 */ + cpu.eax * 4);
    // 004cdeff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdf00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cdf01:
    // 004cdf01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cdf03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdf04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4cdf10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cdf10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cdf11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cdf12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cdf13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cdf14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cdf15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cdf16  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cdf18  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004cdf1b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cdf1d  8aa00b050000           -mov ah, byte ptr [eax + 0x50b]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1291) /* 0x50b */);
    // 004cdf23  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004cdf29  80fc01                 +cmp ah, 1
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
    // 004cdf2c  0f85d3000000           -jne 0x4ce005
    if (!cpu.flags.zf)
    {
        goto L_0x004ce005;
    }
    // 004cdf32  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 004cdf34  d89af4040000           +fcomp dword ptr [edx + 0x4f4]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */));
    cpu.fpu.pop();
    // 004cdf3a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004cdf3c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004cdf3d  760d                   -jbe 0x4cdf4c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004cdf4c;
    }
    // 004cdf3f  d982f4040000           +fld dword ptr [edx + 0x4f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 004cdf45  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004cdf47  d95dfc                 +fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004cdf4a  eb09                   -jmp 0x4cdf55
    goto L_0x004cdf55;
L_0x004cdf4c:
    // 004cdf4c  8b82f4040000           -mov eax, dword ptr [edx + 0x4f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
    // 004cdf52  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004cdf55:
    // 004cdf55  d945fc                 +fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004cdf58  d81da0045400           +fcomp dword ptr [0x5404a0]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(x86::reg32(5506208) /* 0x5404a0 */));
    cpu.fpu.pop();
    // 004cdf5e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004cdf60  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004cdf61  0f839e000000           -jae 0x4ce005
    if (!cpu.flags.cf)
    {
        goto L_0x004ce005;
    }
    // 004cdf67  c7826802000000000000   -mov dword ptr [edx + 0x268], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */) = 0 /*0x0*/;
    // 004cdf71  c7827002000000000000   -mov dword ptr [edx + 0x270], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(624) /* 0x270 */) = 0 /*0x0*/;
    // 004cdf7b  c7827802000000000000   -mov dword ptr [edx + 0x278], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(632) /* 0x278 */) = 0 /*0x0*/;
    // 004cdf85  c7828002000000000000   -mov dword ptr [edx + 0x280], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */) = 0 /*0x0*/;
    // 004cdf8f  c7828802000000000000   -mov dword ptr [edx + 0x288], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(648) /* 0x288 */) = 0 /*0x0*/;
    // 004cdf99  c7826c02000000000000   -mov dword ptr [edx + 0x26c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(620) /* 0x26c */) = 0 /*0x0*/;
    // 004cdfa3  c7827402000000000000   -mov dword ptr [edx + 0x274], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(628) /* 0x274 */) = 0 /*0x0*/;
    // 004cdfad  c7827c02000000000000   -mov dword ptr [edx + 0x27c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(636) /* 0x27c */) = 0 /*0x0*/;
    // 004cdfb7  c7828402000000000000   -mov dword ptr [edx + 0x284], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */) = 0 /*0x0*/;
    // 004cdfc1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004cdfc6  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004cdfc9  c7828c02000000000000   -mov dword ptr [edx + 0x28c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(652) /* 0x28c */) = 0 /*0x0*/;
    // 004cdfd3  890dac747f00           -mov dword ptr [0x7f74ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(8352940) /* 0x7f74ac */) = cpu.ecx;
    // 004cdfd9  890da8747f00           -mov dword ptr [0x7f74a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(8352936) /* 0x7f74a8 */) = cpu.ecx;
    // 004cdfdf  890da4747f00           -mov dword ptr [0x7f74a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(8352932) /* 0x7f74a4 */) = cpu.ecx;
    // 004cdfe5  898260020000           -mov dword ptr [edx + 0x260], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */) = cpu.eax;
    // 004cdfeb  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004cdff0  890da0747f00           -mov dword ptr [0x7f74a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(8352928) /* 0x7f74a0 */) = cpu.ecx;
    // 004cdff6  898264020000           -mov dword ptr [edx + 0x264], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */) = cpu.eax;
    // 004cdffc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cdffe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cdfff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce000  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce001  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce002  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce003  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce004  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ce005:
    // 004ce005  81baf4040000ec51d641   +cmp dword ptr [edx + 0x4f4], 0x41d651ec
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1104564716 /*0x41d651ec*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce00f  7c21                   -jl 0x4ce032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce032;
    }
    // 004ce011  8b9a68020000           -mov ebx, dword ptr [edx + 0x268]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */);
    // 004ce017  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce019  7517                   -jne 0x4ce032
    if (!cpu.flags.zf)
    {
        goto L_0x004ce032;
    }
    // 004ce01b  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce020  2b8264020000           -sub eax, dword ptr [edx + 0x264]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */)));
    // 004ce026  891da8747f00           -mov dword ptr [0x7f74a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(8352936) /* 0x7f74a8 */) = cpu.ebx;
    // 004ce02c  898268020000           -mov dword ptr [edx + 0x268], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(616) /* 0x268 */) = cpu.eax;
L_0x004ce032:
    // 004ce032  81baf40400006de7dd41   +cmp dword ptr [edx + 0x4f4], 0x41dde76d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1105061741 /*0x41dde76d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce03c  7c21                   -jl 0x4ce05f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce05f;
    }
    // 004ce03e  8b9a6c020000           -mov ebx, dword ptr [edx + 0x26c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(620) /* 0x26c */);
    // 004ce044  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce046  7517                   -jne 0x4ce05f
    if (!cpu.flags.zf)
    {
        goto L_0x004ce05f;
    }
    // 004ce048  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce04d  2b8264020000           -sub eax, dword ptr [edx + 0x264]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */)));
    // 004ce053  891dac747f00           -mov dword ptr [0x7f74ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(8352940) /* 0x7f74ac */) = cpu.ebx;
    // 004ce059  89826c020000           -mov dword ptr [edx + 0x26c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(620) /* 0x26c */) = cpu.eax;
L_0x004ce05f:
    // 004ce05f  81baf40400005c8f3242   +cmp dword ptr [edx + 0x4f4], 0x42328f5c
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1110609756 /*0x42328f5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce069  7c21                   -jl 0x4ce08c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce08c;
    }
    // 004ce06b  8b9a70020000           -mov ebx, dword ptr [edx + 0x270]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(624) /* 0x270 */);
    // 004ce071  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce073  7517                   -jne 0x4ce08c
    if (!cpu.flags.zf)
    {
        goto L_0x004ce08c;
    }
    // 004ce075  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce07a  2b8264020000           -sub eax, dword ptr [edx + 0x264]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */)));
    // 004ce080  891da0747f00           -mov dword ptr [0x7f74a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(8352928) /* 0x7f74a0 */) = cpu.ebx;
    // 004ce086  898270020000           -mov dword ptr [edx + 0x270], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(624) /* 0x270 */) = cpu.eax;
L_0x004ce08c:
    // 004ce08c  81baf40400001f853142   +cmp dword ptr [edx + 0x4f4], 0x4231851f
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1110541599 /*0x4231851f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce096  7c21                   -jl 0x4ce0b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce0b9;
    }
    // 004ce098  8b9a74020000           -mov ebx, dword ptr [edx + 0x274]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(628) /* 0x274 */);
    // 004ce09e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce0a0  7517                   -jne 0x4ce0b9
    if (!cpu.flags.zf)
    {
        goto L_0x004ce0b9;
    }
    // 004ce0a2  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce0a7  2b8264020000           -sub eax, dword ptr [edx + 0x264]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */)));
    // 004ce0ad  891da4747f00           -mov dword ptr [0x7f74a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(8352932) /* 0x7f74a4 */) = cpu.ebx;
    // 004ce0b3  898274020000           -mov dword ptr [edx + 0x274], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(628) /* 0x274 */) = cpu.eax;
L_0x004ce0b9:
    // 004ce0b9  a168bc6f00             -mov eax, dword ptr [0x6fbc68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 004ce0be  83f801                 +cmp eax, 1
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
    // 004ce0c1  7405                   -je 0x4ce0c8
    if (cpu.flags.zf)
    {
        goto L_0x004ce0c8;
    }
    // 004ce0c3  83f802                 +cmp eax, 2
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
    // 004ce0c6  7507                   -jne 0x4ce0cf
    if (!cpu.flags.zf)
    {
        goto L_0x004ce0cf;
    }
L_0x004ce0c8:
    // 004ce0c8  bb42000000             -mov ebx, 0x42
    cpu.ebx = 66 /*0x42*/;
    // 004ce0cd  eb05                   -jmp 0x4ce0d4
    goto L_0x004ce0d4;
L_0x004ce0cf:
    // 004ce0cf  bb43000000             -mov ebx, 0x43
    cpu.ebx = 67 /*0x43*/;
L_0x004ce0d4:
    // 004ce0d4  8b3dc0d46f00           -mov edi, dword ptr [0x6fd4c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 004ce0da  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004ce0dc  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004ce0df  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce0e1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ce0e3  742d                   -je 0x4ce112
    if (cpu.flags.zf)
    {
        goto L_0x004ce112;
    }
    // 004ce0e5  8bba60020000           -mov edi, dword ptr [edx + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */);
    // 004ce0eb  39fb                   +cmp ebx, edi
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
    // 004ce0ed  7e15                   -jle 0x4ce104
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce104;
    }
    // 004ce0ef  39f0                   +cmp eax, esi
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
    // 004ce0f1  7e11                   -jle 0x4ce104
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce104;
    }
    // 004ce0f3  39c8                   +cmp eax, ecx
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
    // 004ce0f5  7d0d                   -jge 0x4ce104
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce104;
    }
    // 004ce0f7  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004ce0fa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ce0fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce0fe  7d3d                   -jge 0x4ce13d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce13d;
    }
    // 004ce100  f7d8                   +neg eax
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
    // 004ce102  eb39                   -jmp 0x4ce13d
    goto L_0x004ce13d;
L_0x004ce104:
    // 004ce104  2b8260020000           -sub eax, dword ptr [edx + 0x260]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */)));
    // 004ce10a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce10c  7d2f                   -jge 0x4ce13d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce13d;
    }
    // 004ce10e  f7d8                   +neg eax
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
    // 004ce110  eb2b                   -jmp 0x4ce13d
    goto L_0x004ce13d;
L_0x004ce112:
    // 004ce112  8bba60020000           -mov edi, dword ptr [edx + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */);
    // 004ce118  39fb                   +cmp ebx, edi
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
    // 004ce11a  7e15                   -jle 0x4ce131
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce131;
    }
    // 004ce11c  39f0                   +cmp eax, esi
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
    // 004ce11e  7e11                   -jle 0x4ce131
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce131;
    }
    // 004ce120  39c8                   +cmp eax, ecx
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
    // 004ce122  7d0d                   -jge 0x4ce131
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce131;
    }
    // 004ce124  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004ce127  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ce129  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce12b  7d10                   -jge 0x4ce13d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce13d;
    }
    // 004ce12d  f7d8                   +neg eax
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
    // 004ce12f  eb0c                   -jmp 0x4ce13d
    goto L_0x004ce13d;
L_0x004ce131:
    // 004ce131  2b8260020000           -sub eax, dword ptr [edx + 0x260]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */)));
    // 004ce137  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce139  7d02                   -jge 0x4ce13d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce13d;
    }
    // 004ce13b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ce13d:
    // 004ce13d  39d8                   +cmp eax, ebx
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
    // 004ce13f  7c1d                   -jl 0x4ce15e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce15e;
    }
    // 004ce141  83ba7802000000         +cmp dword ptr [edx + 0x278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(632) /* 0x278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce148  7514                   -jne 0x4ce15e
    if (!cpu.flags.zf)
    {
        goto L_0x004ce15e;
    }
    // 004ce14a  8b3584367d00           -mov esi, dword ptr [0x7d3684]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce150  8bba64020000           -mov edi, dword ptr [edx + 0x264]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */);
    // 004ce156  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ce158  89b278020000           -mov dword ptr [edx + 0x278], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(632) /* 0x278 */) = cpu.esi;
L_0x004ce15e:
    // 004ce15e  39d8                   +cmp eax, ebx
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
    // 004ce160  7c1c                   -jl 0x4ce17e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce17e;
    }
    // 004ce162  83ba7c02000000         +cmp dword ptr [edx + 0x27c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(636) /* 0x27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce169  7513                   -jne 0x4ce17e
    if (!cpu.flags.zf)
    {
        goto L_0x004ce17e;
    }
    // 004ce16b  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce170  8b9a64020000           -mov ebx, dword ptr [edx + 0x264]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */);
    // 004ce176  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce178  89827c020000           -mov dword ptr [edx + 0x27c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(636) /* 0x27c */) = cpu.eax;
L_0x004ce17e:
    // 004ce17e  8b3568bc6f00           -mov esi, dword ptr [0x6fbc68]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 004ce184  83fe01                 +cmp esi, 1
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
    // 004ce187  7405                   -je 0x4ce18e
    if (cpu.flags.zf)
    {
        goto L_0x004ce18e;
    }
    // 004ce189  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce18c  7507                   -jne 0x4ce195
    if (!cpu.flags.zf)
    {
        goto L_0x004ce195;
    }
L_0x004ce18e:
    // 004ce18e  bb0c010000             -mov ebx, 0x10c
    cpu.ebx = 268 /*0x10c*/;
    // 004ce193  eb05                   -jmp 0x4ce19a
    goto L_0x004ce19a;
L_0x004ce195:
    // 004ce195  bba7000000             -mov ebx, 0xa7
    cpu.ebx = 167 /*0xa7*/;
L_0x004ce19a:
    // 004ce19a  8b3dc0d46f00           -mov edi, dword ptr [0x6fd4c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 004ce1a0  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004ce1a2  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004ce1a5  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce1a7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ce1a9  742c                   -je 0x4ce1d7
    if (cpu.flags.zf)
    {
        goto L_0x004ce1d7;
    }
    // 004ce1ab  8bba60020000           -mov edi, dword ptr [edx + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */);
    // 004ce1b1  39fb                   +cmp ebx, edi
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
    // 004ce1b3  7e14                   -jle 0x4ce1c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce1c9;
    }
    // 004ce1b5  39f0                   +cmp eax, esi
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
    // 004ce1b7  7e10                   -jle 0x4ce1c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce1c9;
    }
    // 004ce1b9  39c8                   +cmp eax, ecx
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
    // 004ce1bb  7d0c                   -jge 0x4ce1c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce1c9;
    }
    // 004ce1bd  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ce1bf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce1c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce1c3  7d3c                   -jge 0x4ce201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce201;
    }
    // 004ce1c5  f7d8                   +neg eax
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
    // 004ce1c7  eb38                   -jmp 0x4ce201
    goto L_0x004ce201;
L_0x004ce1c9:
    // 004ce1c9  2b8260020000           -sub eax, dword ptr [edx + 0x260]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */)));
    // 004ce1cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce1d1  7d2e                   -jge 0x4ce201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce201;
    }
    // 004ce1d3  f7d8                   +neg eax
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
    // 004ce1d5  eb2a                   -jmp 0x4ce201
    goto L_0x004ce201;
L_0x004ce1d7:
    // 004ce1d7  8bba60020000           -mov edi, dword ptr [edx + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */);
    // 004ce1dd  39fb                   +cmp ebx, edi
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
    // 004ce1df  7e14                   -jle 0x4ce1f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce1f5;
    }
    // 004ce1e1  39f0                   +cmp eax, esi
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
    // 004ce1e3  7e10                   -jle 0x4ce1f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce1f5;
    }
    // 004ce1e5  39c8                   +cmp eax, ecx
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
    // 004ce1e7  7d0c                   -jge 0x4ce1f5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce1f5;
    }
    // 004ce1e9  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ce1eb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce1ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce1ef  7d10                   -jge 0x4ce201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce201;
    }
    // 004ce1f1  f7d8                   +neg eax
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
    // 004ce1f3  eb0c                   -jmp 0x4ce201
    goto L_0x004ce201;
L_0x004ce1f5:
    // 004ce1f5  2b8260020000           -sub eax, dword ptr [edx + 0x260]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(608) /* 0x260 */)));
    // 004ce1fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce1fd  7d02                   -jge 0x4ce201
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce201;
    }
    // 004ce1ff  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004ce201:
    // 004ce201  39d8                   +cmp eax, ebx
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
    // 004ce203  7c2f                   -jl 0x4ce234
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce234;
    }
    // 004ce205  83ba8002000000         +cmp dword ptr [edx + 0x280], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce20c  7526                   -jne 0x4ce234
    if (!cpu.flags.zf)
    {
        goto L_0x004ce234;
    }
    // 004ce20e  8b0d84367d00           -mov ecx, dword ptr [0x7d3684]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce214  8bb264020000           -mov esi, dword ptr [edx + 0x264]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */);
    // 004ce21a  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ce21c  898a80020000           -mov dword ptr [edx + 0x280], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */) = cpu.ecx;
    // 004ce222  81f980050000           +cmp ecx, 0x580
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1408 /*0x580*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce228  7d0a                   -jge 0x4ce234
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce234;
    }
    // 004ce22a  c7828002000000000000   -mov dword ptr [edx + 0x280], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */) = 0 /*0x0*/;
L_0x004ce234:
    // 004ce234  39d8                   +cmp eax, ebx
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
    // 004ce236  7c36                   -jl 0x4ce26e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce26e;
    }
    // 004ce238  83ba8402000000         +cmp dword ptr [edx + 0x284], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce23f  7409                   -je 0x4ce24a
    if (cpu.flags.zf)
    {
        goto L_0x004ce24a;
    }
    // 004ce241  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ce243  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce244  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce245  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce246  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce247  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce248  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce249  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ce24a:
    // 004ce24a  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce24f  8b8a64020000           -mov ecx, dword ptr [edx + 0x264]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(612) /* 0x264 */);
    // 004ce255  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce257  898284020000           -mov dword ptr [edx + 0x284], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 004ce25d  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce262  7d0a                   -jge 0x4ce26e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce26e;
    }
    // 004ce264  c7828402000000000000   -mov dword ptr [edx + 0x284], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(644) /* 0x284 */) = 0 /*0x0*/;
L_0x004ce26e:
    // 004ce26e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ce270  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce271  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce272  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce273  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce274  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce275  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce276  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ce280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce284  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce285  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce286  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce288  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004ce28b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ce28d  8b8834020000           -mov ecx, dword ptr [eax + 0x234]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 004ce293  83f908                 +cmp ecx, 8
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
    // 004ce296  0f8d40010000           -jge 0x4ce3dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce3dc;
    }
    // 004ce29c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004ce2a3  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004ce2a6  d982f4040000           +fld dword ptr [edx + 0x4f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 004ce2ac  d89998020000           +fcomp dword ptr [ecx + 0x298]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ecx + x86::reg32(664) /* 0x298 */));
    cpu.fpu.pop();
    // 004ce2b2  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ce2b4  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ce2b5  0f8621010000           -jbe 0x4ce3dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ce3dc;
    }
    // 004ce2bb  f6820002000008         +test byte ptr [edx + 0x200], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 8 /*0x8*/));
    // 004ce2c2  0f84df000000           -je 0x4ce3a7
    if (cpu.flags.zf)
    {
        goto L_0x004ce3a7;
    }
    // 004ce2c8  833db0d36f0002         +cmp dword ptr [0x6fd3b0], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce2cf  7c5c                   -jl 0x4ce32d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce32d;
    }
    // 004ce2d1  db82f0010000           +fild dword ptr [edx + 0x1f0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(496) /* 0x1f0 */))));
    // 004ce2d7  d95dec                 +fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce2da  8b8228050000           -mov eax, dword ptr [edx + 0x528]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1320) /* 0x528 */);
    // 004ce2e0  d945ec                 +fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004ce2e3  d80da4045400           +fmul dword ptr [0x5404a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5506212) /* 0x5404a4 */));
    // 004ce2e9  d980cc010000           +fld dword ptr [eax + 0x1cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(460) /* 0x1cc */)));
    // 004ce2ef  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ce2f1  d95df0                 +fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce2f4  d865f0                 +fsub dword ptr [ebp - 0x10]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    // 004ce2f7  d982f4040000           +fld dword ptr [edx + 0x4f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 004ce2fd  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ce2ff  d95df4                 +fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce302  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */));
    cpu.fpu.pop();
    // 004ce305  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ce307  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ce308  7605                   -jbe 0x4ce30f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ce30f;
    }
    // 004ce30a  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ce30d  eb06                   -jmp 0x4ce315
    goto L_0x004ce315;
L_0x004ce30f:
    // 004ce30f  8b82f4040000           -mov eax, dword ptr [edx + 0x4f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
L_0x004ce315:
    // 004ce315  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004ce318  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce31e  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ce321  898c8298020000         -mov dword ptr [edx + eax*4 + 0x298], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(664) /* 0x298 */ + cpu.eax * 4) = cpu.ecx;
    // 004ce328  e986000000             -jmp 0x4ce3b3
    goto L_0x004ce3b3;
L_0x004ce32d:
    // 004ce32d  e8cace0100             -call 0x4eb1fc
    cpu.esp -= 4;
    sub_4eb1fc(app, cpu);
    if (cpu.terminate) return;
    // 004ce332  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ce335  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004ce338  dc0da8045400           +fmul qword ptr [0x5404a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506216) /* 0x5404a8 */));
    // 004ce33e  dc0db0045400           +fmul qword ptr [0x5404b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506224) /* 0x5404b0 */));
    // 004ce344  8b8228050000           -mov eax, dword ptr [edx + 0x528]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1320) /* 0x528 */);
    // 004ce34a  d8a8cc010000           +fsubr dword ptr [eax + 0x1cc]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.eax + x86::reg32(460) /* 0x1cc */) - cpu.fpu.st(0);
    // 004ce350  d982f4040000           +fld dword ptr [edx + 0x4f4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 004ce356  dd5de4                 +fstp qword ptr [ebp - 0x1c]
    app->getMemory<double>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce359  dc5de4                 +fcomp qword ptr [ebp - 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(cpu.ebp + x86::reg32(-28) /* -0x1c */));
    cpu.fpu.pop();
    // 004ce35c  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ce35e  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ce35f  7328                   -jae 0x4ce389
    if (!cpu.flags.cf)
    {
        goto L_0x004ce389;
    }
    // 004ce361  e896ce0100             -call 0x4eb1fc
    cpu.esp -= 4;
    sub_4eb1fc(app, cpu);
    if (cpu.terminate) return;
    // 004ce366  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ce369  db45fc                 +fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004ce36c  dc0da8045400           +fmul qword ptr [0x5404a8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506216) /* 0x5404a8 */));
    // 004ce372  dc0db0045400           +fmul qword ptr [0x5404b0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506224) /* 0x5404b0 */));
    // 004ce378  8b8228050000           -mov eax, dword ptr [edx + 0x528]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1320) /* 0x528 */);
    // 004ce37e  d8a8cc010000           +fsubr dword ptr [eax + 0x1cc]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.eax + x86::reg32(460) /* 0x1cc */) - cpu.fpu.st(0);
    // 004ce384  dd5ddc                 +fstp qword ptr [ebp - 0x24]
    app->getMemory<double>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce387  eb0c                   -jmp 0x4ce395
    goto L_0x004ce395;
L_0x004ce389:
    // 004ce389  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004ce38c  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004ce38f  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004ce392  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x004ce395:
    // 004ce395  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce39b  dd45dc                 +fld qword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004ce39e  d99c8298020000         +fstp dword ptr [edx + eax*4 + 0x298]
    app->getMemory<float>(cpu.edx + x86::reg32(664) /* 0x298 */ + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce3a5  eb0c                   -jmp 0x4ce3b3
    goto L_0x004ce3b3;
L_0x004ce3a7:
    // 004ce3a7  8b82f4040000           -mov eax, dword ptr [edx + 0x4f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */);
    // 004ce3ad  898198020000           -mov dword ptr [ecx + 0x298], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */) = cpu.eax;
L_0x004ce3b3:
    // 004ce3b3  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce3b9  c1e002                 +shl eax, 2
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
    // 004ce3bc  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004ce3bf  d98198020000           +fld dword ptr [ecx + 0x298]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(664) /* 0x298 */)));
    // 004ce3c5  d89ab8020000           +fcomp dword ptr [edx + 0x2b8]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.edx + x86::reg32(696) /* 0x2b8 */));
    cpu.fpu.pop();
    // 004ce3cb  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ce3cd  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ce3ce  760c                   -jbe 0x4ce3dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ce3dc;
    }
    // 004ce3d0  8b8198020000           -mov eax, dword ptr [ecx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 004ce3d6  8982b8020000           -mov dword ptr [edx + 0x2b8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */) = cpu.eax;
L_0x004ce3dc:
    // 004ce3dc  f6820002000001         +test byte ptr [edx + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004ce3e3  0f84f0000000           -je 0x4ce4d9
    if (cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce3e9  8bb204020000           -mov esi, dword ptr [edx + 0x204]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(516) /* 0x204 */);
    // 004ce3ef  3bb234020000           +cmp esi, dword ptr [edx + 0x234]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce3f5  0f84de000000           -je 0x4ce4d9
    if (cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce3fb  83bac402000003         +cmp dword ptr [edx + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce402  0f84d1000000           -je 0x4ce4d9
    if (cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce408  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce40d  8b9a38020000           -mov ebx, dword ptr [edx + 0x238]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */);
    // 004ce413  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce415  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ce417  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce41d  899c8240020000         -mov dword ptr [edx + eax*4 + 0x240], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */ + cpu.eax * 4) = cpu.ebx;
    // 004ce424  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce429  8b3520d56f00           -mov esi, dword ptr [0x6fd520]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7329056) /* 0x6fd520 */);
    // 004ce42f  898238020000           -mov dword ptr [edx + 0x238], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */) = cpu.eax;
    // 004ce435  a118d56f00             -mov eax, dword ptr [0x6fd518]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7329048) /* 0x6fd518 */);
    // 004ce43a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce43c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ce43e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce440:
    // 004ce440  39f0                   +cmp eax, esi
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
    // 004ce442  7d20                   -jge 0x4ce464
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce464;
    }
    // 004ce444  8b1c85c8fa5e00         -mov ebx, dword ptr [eax*4 + 0x5efac8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6224584) /* 0x5efac8 */ + cpu.eax * 4);
    // 004ce44b  83bbbc02000001         +cmp dword ptr [ebx + 0x2bc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(700) /* 0x2bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce452  750d                   -jne 0x4ce461
    if (!cpu.flags.zf)
    {
        goto L_0x004ce461;
    }
    // 004ce454  8b8a34020000           -mov ecx, dword ptr [edx + 0x234]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce45a  8b8c8b40020000         -mov ecx, dword ptr [ebx + ecx*4 + 0x240]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */ + cpu.ecx * 4);
L_0x004ce461:
    // 004ce461  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce462  ebdc                   -jmp 0x4ce440
    goto L_0x004ce440;
L_0x004ce464:
    // 004ce464  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce46a  8b848240020000         -mov eax, dword ptr [edx + eax*4 + 0x240]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */ + cpu.eax * 4);
    // 004ce471  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce473  89823c020000           -mov dword ptr [edx + 0x23c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(572) /* 0x23c */) = cpu.eax;
    // 004ce479  8b8204020000           -mov eax, dword ptr [edx + 0x204]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(516) /* 0x204 */);
    // 004ce47f  8b0db4d46f00           -mov ecx, dword ptr [0x6fd4b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */);
    // 004ce485  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 004ce48b  39c8                   +cmp eax, ecx
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
    // 004ce48d  754a                   -jne 0x4ce4d9
    if (!cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce48f  f6820002000080         +test byte ptr [edx + 0x200], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */) & 128 /*0x80*/));
    // 004ce496  7541                   -jne 0x4ce4d9
    if (!cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce498  83bac402000004         +cmp dword ptr [edx + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce49f  7438                   -je 0x4ce4d9
    if (cpu.flags.zf)
    {
        goto L_0x004ce4d9;
    }
    // 004ce4a1  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce4a6  8b3540d95d00           -mov esi, dword ptr [0x5dd940]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004ce4ac  898228020000           -mov dword ptr [edx + 0x228], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 004ce4b2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ce4b4  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004ce4b7  8bba38020000           -mov edi, dword ptr [edx + 0x238]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */);
    // 004ce4bd  c782c402000003000000   -mov dword ptr [edx + 0x2c4], 3
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = 3 /*0x3*/;
    // 004ce4c7  81ef00020000           -sub edi, 0x200
    (cpu.edi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004ce4cd  89ba38020000           -mov dword ptr [edx + 0x238], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */) = cpu.edi;
    // 004ce4d3  898224020000           -mov dword ptr [edx + 0x224], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */) = cpu.eax;
L_0x004ce4d9:
    // 004ce4d9  8a8a00020000           -mov cl, byte ptr [edx + 0x200]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004ce4df  f6c120                 +test cl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 32 /*0x20*/));
    // 004ce4e2  7441                   -je 0x4ce525
    if (cpu.flags.zf)
    {
        goto L_0x004ce525;
    }
    // 004ce4e4  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004ce4e7  743c                   -je 0x4ce525
    if (cpu.flags.zf)
    {
        goto L_0x004ce525;
    }
    // 004ce4e9  8b0db8d46f00           -mov ecx, dword ptr [0x6fd4b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328952) /* 0x6fd4b8 */);
    // 004ce4ef  3b8acc020000           +cmp ecx, dword ptr [edx + 0x2cc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(716) /* 0x2cc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce4f5  752e                   -jne 0x4ce525
    if (!cpu.flags.zf)
    {
        goto L_0x004ce525;
    }
    // 004ce4f7  83bac402000003         +cmp dword ptr [edx + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce4fe  7425                   -je 0x4ce525
    if (cpu.flags.zf)
    {
        goto L_0x004ce525;
    }
    // 004ce500  c7822402000000000000   -mov dword ptr [edx + 0x224], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */) = 0 /*0x0*/;
    // 004ce50a  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce50f  c782c402000003000000   -mov dword ptr [edx + 0x2c4], 3
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = 3 /*0x3*/;
    // 004ce519  898228020000           -mov dword ptr [edx + 0x228], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 004ce51f  898238020000           -mov dword ptr [edx + 0x238], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(568) /* 0x238 */) = cpu.eax;
L_0x004ce525:
    // 004ce525  8b721c                 -mov esi, dword ptr [edx + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004ce528  3bb22c020000           +cmp esi, dword ptr [edx + 0x22c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce52e  745e                   -je 0x4ce58e
    if (cpu.flags.zf)
    {
        goto L_0x004ce58e;
    }
    // 004ce530  8bbac4020000           -mov edi, dword ptr [edx + 0x2c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
    // 004ce536  89b22c020000           -mov dword ptr [edx + 0x22c], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */) = cpu.esi;
    // 004ce53c  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce53f  744d                   -je 0x4ce58e
    if (cpu.flags.zf)
    {
        goto L_0x004ce58e;
    }
    // 004ce541  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce544  7448                   -je 0x4ce58e
    if (cpu.flags.zf)
    {
        goto L_0x004ce58e;
    }
    // 004ce546  a184367d00             -mov eax, dword ptr [0x7d3684]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce54b  8b0dc0d46f00           -mov ecx, dword ptr [0x6fd4c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328960) /* 0x6fd4c0 */);
    // 004ce551  898228020000           -mov dword ptr [edx + 0x228], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(552) /* 0x228 */) = cpu.eax;
    // 004ce557  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ce559  740e                   -je 0x4ce569
    if (cpu.flags.zf)
    {
        goto L_0x004ce569;
    }
    // 004ce55b  8b0d40d95d00           -mov ecx, dword ptr [0x5dd940]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004ce561  2b8a2c020000           +sub ecx, dword ptr [edx + 0x22c]
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ce567  eb06                   -jmp 0x4ce56f
    goto L_0x004ce56f;
L_0x004ce569:
    // 004ce569  8b8a2c020000           -mov ecx, dword ptr [edx + 0x22c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
L_0x004ce56f:
    // 004ce56f  8bb208020000           -mov esi, dword ptr [edx + 0x208]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(520) /* 0x208 */);
    // 004ce575  8b8234020000           -mov eax, dword ptr [edx + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 004ce57b  8b3d40d95d00           -mov edi, dword ptr [0x5dd940]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004ce581  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ce583  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004ce586  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce588  898224020000           -mov dword ptr [edx + 0x224], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */) = cpu.eax;
L_0x004ce58e:
    // 004ce58e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ce590  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce591  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce592  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce593  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce594  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce595  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4ce5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce5a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce5a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce5a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce5a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce5a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce5a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce5a6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce5a8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004ce5ab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ce5ad  83b82402000000         +cmp dword ptr [eax + 0x224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(548) /* 0x224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce5b4  7e0e                   -jle 0x4ce5c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce5c4;
    }
    // 004ce5b6  8b9828020000           -mov ebx, dword ptr [eax + 0x228]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004ce5bc  81fb00020000           +cmp ebx, 0x200
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
    // 004ce5c2  7f07                   -jg 0x4ce5cb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ce5cb;
    }
L_0x004ce5c4:
    // 004ce5c4  b800302a00             -mov eax, 0x2a3000
    cpu.eax = 2764800 /*0x2a3000*/;
    // 004ce5c9  eb22                   -jmp 0x4ce5ed
    goto L_0x004ce5ed;
L_0x004ce5cb:
    // 004ce5cb  a140d95d00             -mov eax, dword ptr [0x5dd940]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */);
    // 004ce5d0  0faf05b4d46f00         -imul eax, dword ptr [0x6fd4b4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */))));
    // 004ce5d7  8d9300feffff           -lea edx, [ebx - 0x200]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-512) /* -0x200 */);
    // 004ce5dd  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004ce5e0  8bb924020000           -mov edi, dword ptr [ecx + 0x224]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(548) /* 0x224 */);
    // 004ce5e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ce5e8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ce5eb  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
L_0x004ce5ed:
    // 004ce5ed  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ce5ef  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004ce5f1  898138020000           -mov dword ptr [ecx + 0x238], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */) = cpu.eax;
    // 004ce5f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce5f9:
    // 004ce5f9  3b05b4d46f00           +cmp eax, dword ptr [0x6fd4b4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce5ff  7d11                   -jge 0x4ce612
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce612;
    }
    // 004ce601  8bbc8140020000         -mov edi, dword ptr [ecx + eax*4 + 0x240]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(576) /* 0x240 */ + cpu.eax * 4);
    // 004ce608  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ce60a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ce60c  7501                   -jne 0x4ce60f
    if (!cpu.flags.zf)
    {
        goto L_0x004ce60f;
    }
    // 004ce60e  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004ce60f:
    // 004ce60f  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce610  ebe7                   -jmp 0x4ce5f9
    goto L_0x004ce5f9;
L_0x004ce612:
    // 004ce612  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ce614  0f84a5000000           -je 0x4ce6bf
    if (cpu.flags.zf)
    {
        goto L_0x004ce6bf;
    }
    // 004ce61a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce61c  0f8e9d000000           -jle 0x4ce6bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce6bf;
    }
    // 004ce622  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004ce624:
    // 004ce624  3b3db4d46f00           +cmp edi, dword ptr [0x6fd4b4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce62a  0f8d8f000000           -jge 0x4ce6bf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce6bf;
    }
    // 004ce630  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ce637  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004ce63a  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004ce63d  83ba4002000000         +cmp dword ptr [edx + 0x240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce644  7573                   -jne 0x4ce6b9
    if (!cpu.flags.zf)
    {
        goto L_0x004ce6b9;
    }
    // 004ce646  a1104f5500             -mov eax, dword ptr [0x554f10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */);
    // 004ce64b  8b15184f5500           -mov edx, dword ptr [0x554f18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590808) /* 0x554f18 */);
    // 004ce651  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004ce654  a3144f5500             -mov dword ptr [0x554f14], eax
    app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */) = cpu.eax;
    // 004ce659  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004ce65e  a3104f5500             -mov dword ptr [0x554f10], eax
    app->getMemory<x86::reg32>(x86::reg32(5590800) /* 0x554f10 */) = cpu.eax;
    // 004ce663  a1144f5500             -mov eax, dword ptr [0x554f14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590804) /* 0x554f14 */);
    // 004ce668  2500ffff00             -and eax, 0xffff00
    cpu.eax &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 004ce66d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 004ce670  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004ce673  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004ce67a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ce67c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ce67e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ce681  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ce684  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004ce687  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ce689  f77dec                 -idiv dword ptr [ebp - 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ce68c  0faf45f0               -imul eax, dword ptr [ebp - 0x10]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */))));
    // 004ce690  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004ce693  8b9138020000           -mov edx, dword ptr [ecx + 0x238]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */);
    // 004ce699  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ce69b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004ce69e  899138020000           -mov dword ptr [ecx + 0x238], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(568) /* 0x238 */) = cpu.edx;
    // 004ce6a4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ce6a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ce6a8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ce6ab  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ce6ad  0345f4                 +add eax, dword ptr [ebp - 0xc]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ce6b0  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004ce6b3  898240020000           -mov dword ptr [edx + 0x240], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(576) /* 0x240 */) = cpu.eax;
L_0x004ce6b9:
    // 004ce6b9  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce6ba  e965ffffff             -jmp 0x4ce624
    goto L_0x004ce624;
L_0x004ce6bf:
    // 004ce6bf  db0540d95d00           -fild dword ptr [0x5dd940]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6150464) /* 0x5dd940 */))));
    // 004ce6c5  dc0db8045400           -fmul qword ptr [0x5404b8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506232) /* 0x5404b8 */));
    // 004ce6cb  d98198020000           -fld dword ptr [ecx + 0x298]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(664) /* 0x298 */)));
    // 004ce6d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce6d3  d999b8020000           -fstp dword ptr [ecx + 0x2b8]
    app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ce6d9  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ce6dc:
    // 004ce6dc  3b1db4d46f00           +cmp ebx, dword ptr [0x6fd4b4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328948) /* 0x6fd4b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce6e2  7d5f                   -jge 0x4ce743
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce743;
    }
    // 004ce6e4  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ce6eb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce6ed  f78098020000ffffff7f   +test dword ptr [eax + 0x298], 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(664) /* 0x298 */) & 2147483647 /*0x7fffffff*/));
    // 004ce6f7  7520                   -jne 0x4ce719
    if (!cpu.flags.zf)
    {
        goto L_0x004ce719;
    }
    // 004ce6f9  83b84002000000         +cmp dword ptr [eax + 0x240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(576) /* 0x240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce700  7417                   -je 0x4ce719
    if (cpu.flags.zf)
    {
        goto L_0x004ce719;
    }
    // 004ce702  db8040020000           +fild dword ptr [eax + 0x240]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(576) /* 0x240 */))));
    // 004ce708  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004ce70b  dc0dc0045400           +fmul qword ptr [0x5404c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506240) /* 0x5404c0 */));
    // 004ce711  def1                   +fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004ce713  d99898020000           +fstp dword ptr [eax + 0x298]
    app->getMemory<float>(cpu.eax + x86::reg32(664) /* 0x298 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ce719:
    // 004ce719  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ce720  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004ce723  d981b8020000           +fld dword ptr [ecx + 0x2b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(696) /* 0x2b8 */)));
    // 004ce729  d89a98020000           +fcomp dword ptr [edx + 0x298]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.edx + x86::reg32(664) /* 0x298 */));
    cpu.fpu.pop();
    // 004ce72f  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ce731  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ce732  730c                   -jae 0x4ce740
    if (!cpu.flags.cf)
    {
        goto L_0x004ce740;
    }
    // 004ce734  8b8298020000           -mov eax, dword ptr [edx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(664) /* 0x298 */);
    // 004ce73a  8981b8020000           -mov dword ptr [ecx + 0x2b8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.eax;
L_0x004ce740:
    // 004ce740  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce741  eb99                   -jmp 0x4ce6dc
    goto L_0x004ce6dc;
L_0x004ce743:
    // 004ce743  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ce745  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce746  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce748  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce749  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce74a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce74b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ce750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce754  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce755  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce757  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ce759  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004ce75e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce760:
    // 004ce760  3b05a4fd5e00           +cmp eax, dword ptr [0x5efda4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce766  7d3b                   -jge 0x4ce7a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce7a3;
    }
    // 004ce768  8b148548fa5e00         -mov edx, dword ptr [eax*4 + 0x5efa48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.eax * 4);
    // 004ce76f  8a8a00020000           -mov cl, byte ptr [edx + 0x200]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004ce775  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 004ce778  7408                   -je 0x4ce782
    if (cpu.flags.zf)
    {
        goto L_0x004ce782;
    }
    // 004ce77a  899ac4020000           -mov dword ptr [edx + 0x2c4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = cpu.ebx;
    // 004ce780  eb1e                   -jmp 0x4ce7a0
    goto L_0x004ce7a0;
L_0x004ce782:
    // 004ce782  8b8ac4020000           -mov ecx, dword ptr [edx + 0x2c4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
    // 004ce788  83f903                 +cmp ecx, 3
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
    // 004ce78b  7207                   -jb 0x4ce794
    if (cpu.flags.cf)
    {
        goto L_0x004ce794;
    }
    // 004ce78d  7611                   -jbe 0x4ce7a0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ce7a0;
    }
    // 004ce78f  83f904                 +cmp ecx, 4
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
    // 004ce792  740c                   -je 0x4ce7a0
    if (cpu.flags.zf)
    {
        goto L_0x004ce7a0;
    }
L_0x004ce794:
    // 004ce794  c782c402000001000000   -mov dword ptr [edx + 0x2c4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = 1 /*0x1*/;
    // 004ce79e  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
L_0x004ce7a0:
    // 004ce7a0  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce7a1  ebbd                   -jmp 0x4ce760
    goto L_0x004ce760;
L_0x004ce7a3:
    // 004ce7a3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ce7a5:
    // 004ce7a5  3b0d98fd5e00           +cmp ecx, dword ptr [0x5efd98]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225304) /* 0x5efd98 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce7ab  7d4c                   -jge 0x4ce7f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce7f9;
    }
    // 004ce7ad  8b148d08fb5e00         -mov edx, dword ptr [ecx*4 + 0x5efb08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6224648) /* 0x5efb08 */ + cpu.ecx * 4);
    // 004ce7b4  8a8200020000           -mov al, byte ptr [edx + 0x200]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(512) /* 0x200 */);
    // 004ce7ba  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004ce7bc  7538                   -jne 0x4ce7f6
    if (!cpu.flags.zf)
    {
        goto L_0x004ce7f6;
    }
    // 004ce7be  83bac402000003         +cmp dword ptr [edx + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce7c5  7407                   -je 0x4ce7ce
    if (cpu.flags.zf)
    {
        goto L_0x004ce7ce;
    }
    // 004ce7c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ce7c9  e8d2fdffff             -call 0x4ce5a0
    cpu.esp -= 4;
    sub_4ce5a0(app, cpu);
    if (cpu.terminate) return;
L_0x004ce7ce:
    // 004ce7ce  8b82c4020000           -mov eax, dword ptr [edx + 0x2c4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
    // 004ce7d4  83f803                 +cmp eax, 3
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
    // 004ce7d7  7207                   -jb 0x4ce7e0
    if (cpu.flags.cf)
    {
        goto L_0x004ce7e0;
    }
    // 004ce7d9  761b                   -jbe 0x4ce7f6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ce7f6;
    }
    // 004ce7db  83f804                 +cmp eax, 4
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
    // 004ce7de  7416                   -je 0x4ce7f6
    if (cpu.flags.zf)
    {
        goto L_0x004ce7f6;
    }
L_0x004ce7e0:
    // 004ce7e0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ce7e2  740c                   -je 0x4ce7f0
    if (cpu.flags.zf)
    {
        goto L_0x004ce7f0;
    }
    // 004ce7e4  c782c402000003000000   -mov dword ptr [edx + 0x2c4], 3
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = 3 /*0x3*/;
    // 004ce7ee  eb06                   -jmp 0x4ce7f6
    goto L_0x004ce7f6;
L_0x004ce7f0:
    // 004ce7f0  899ac4020000           -mov dword ptr [edx + 0x2c4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = cpu.ebx;
L_0x004ce7f6:
    // 004ce7f6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce7f7  ebac                   -jmp 0x4ce7a5
    goto L_0x004ce7a5;
L_0x004ce7f9:
    // 004ce7f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce7fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce7fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce7fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce7fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce7fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ce800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce800  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce801  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce802  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce803  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce804  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce806  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ce808  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ce80a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce80c:
    // 004ce80c  39f0                   +cmp eax, esi
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
    // 004ce80e  7d1c                   -jge 0x4ce82c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce82c;
    }
    // 004ce810  8b1481                 -mov edx, dword ptr [ecx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4);
    // 004ce813  8bbac4020000           -mov edi, dword ptr [edx + 0x2c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */);
    // 004ce819  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce81c  740b                   -je 0x4ce829
    if (cpu.flags.zf)
    {
        goto L_0x004ce829;
    }
    // 004ce81e  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce821  7406                   -je 0x4ce829
    if (cpu.flags.zf)
    {
        goto L_0x004ce829;
    }
    // 004ce823  899ac4020000           -mov dword ptr [edx + 0x2c4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(708) /* 0x2c4 */) = cpu.ebx;
L_0x004ce829:
    // 004ce829  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce82a  ebe0                   -jmp 0x4ce80c
    goto L_0x004ce80c;
L_0x004ce82c:
    // 004ce82c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce82d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce82e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce82f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce830  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4ce840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce842  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce843  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce844  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce845  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce846  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce848  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ce84a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ce84c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ce84e:
    // 004ce84e  8b35a4fd5e00           -mov esi, dword ptr [0x5efda4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
    // 004ce854  39f1                   +cmp ecx, esi
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
    // 004ce856  0f8d5c000000           -jge 0x4ce8b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce8b8;
    }
    // 004ce85c  8b048d48fa5e00         -mov eax, dword ptr [ecx*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.ecx * 4);
    // 004ce863  f6800002000080         +test byte ptr [eax + 0x200], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 128 /*0x80*/));
    // 004ce86a  7403                   -je 0x4ce86f
    if (cpu.flags.zf)
    {
        goto L_0x004ce86f;
    }
    // 004ce86c  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce86d  eb46                   -jmp 0x4ce8b5
    goto L_0x004ce8b5;
L_0x004ce86f:
    // 004ce86f  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004ce876  741f                   -je 0x4ce897
    if (cpu.flags.zf)
    {
        goto L_0x004ce897;
    }
    // 004ce878  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce87f  7516                   -jne 0x4ce897
    if (!cpu.flags.zf)
    {
        goto L_0x004ce897;
    }
    // 004ce881  8bb028020000           -mov esi, dword ptr [eax + 0x228]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004ce887  8b3d84367d00           -mov edi, dword ptr [0x7d3684]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce88d  81c6c0010000           -add esi, 0x1c0
    (cpu.esi) += x86::reg32(x86::sreg32(448 /*0x1c0*/));
    // 004ce893  39fe                   +cmp esi, edi
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
    // 004ce895  7c1d                   -jl 0x4ce8b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce8b4;
    }
L_0x004ce897:
    // 004ce897  833db0d36f0004         +cmp dword ptr [0x6fd3b0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce89e  7515                   -jne 0x4ce8b5
    if (!cpu.flags.zf)
    {
        goto L_0x004ce8b5;
    }
    // 004ce8a0  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004ce8a6  66833c45ca227a0000     +cmp word ptr [eax*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ce8af  7503                   -jne 0x4ce8b4
    if (!cpu.flags.zf)
    {
        goto L_0x004ce8b4;
    }
    // 004ce8b1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce8b2  eb9a                   -jmp 0x4ce84e
    goto L_0x004ce84e;
L_0x004ce8b4:
    // 004ce8b4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004ce8b5:
    // 004ce8b5  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce8b6  eb96                   -jmp 0x4ce84e
    goto L_0x004ce84e;
L_0x004ce8b8:
    // 004ce8b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ce8ba  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ce8bc  39c2                   +cmp edx, eax
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
    // 004ce8be  750b                   -jne 0x4ce8cb
    if (!cpu.flags.zf)
    {
        goto L_0x004ce8cb;
    }
    // 004ce8c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ce8c2  7e07                   -jle 0x4ce8cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce8cb;
    }
    // 004ce8c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ce8c9  eb02                   -jmp 0x4ce8cd
    goto L_0x004ce8cd;
L_0x004ce8cb:
    // 004ce8cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce8cd:
    // 004ce8cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce8d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4ce8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce8e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce8e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce8e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce8e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce8e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce8e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce8e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ce8e9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ce8eb:
    // 004ce8eb  8b1da4fd5e00           -mov ebx, dword ptr [0x5efda4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */);
    // 004ce8f1  39da                   +cmp edx, ebx
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
    // 004ce8f3  7d4f                   -jge 0x4ce944
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce944;
    }
    // 004ce8f5  8b049548fa5e00         -mov eax, dword ptr [edx*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.edx * 4);
    // 004ce8fc  8a9800020000           -mov bl, byte ptr [eax + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 004ce902  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004ce905  741f                   -je 0x4ce926
    if (cpu.flags.zf)
    {
        goto L_0x004ce926;
    }
    // 004ce907  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce90e  7516                   -jne 0x4ce926
    if (!cpu.flags.zf)
    {
        goto L_0x004ce926;
    }
    // 004ce910  8b9828020000           -mov ebx, dword ptr [eax + 0x228]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004ce916  8b3d84367d00           -mov edi, dword ptr [0x7d3684]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce91c  81c3c0010000           -add ebx, 0x1c0
    (cpu.ebx) += x86::reg32(x86::sreg32(448 /*0x1c0*/));
    // 004ce922  39fb                   +cmp ebx, edi
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
    // 004ce924  7c1a                   -jl 0x4ce940
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce940;
    }
L_0x004ce926:
    // 004ce926  833db0d36f0004         +cmp dword ptr [0x6fd3b0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce92d  7512                   -jne 0x4ce941
    if (!cpu.flags.zf)
    {
        goto L_0x004ce941;
    }
    // 004ce92f  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004ce935  66833c45ca227a0000     +cmp word ptr [eax*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ce93e  7401                   -je 0x4ce941
    if (cpu.flags.zf)
    {
        goto L_0x004ce941;
    }
L_0x004ce940:
    // 004ce940  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004ce941:
    // 004ce941  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce942  eba7                   -jmp 0x4ce8eb
    goto L_0x004ce8eb;
L_0x004ce944:
    // 004ce944  39d9                   +cmp ecx, ebx
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
    // 004ce946  7510                   -jne 0x4ce958
    if (!cpu.flags.zf)
    {
        goto L_0x004ce958;
    }
    // 004ce948  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ce94a  7e0c                   -jle 0x4ce958
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ce958;
    }
    // 004ce94c  e8ff010000             -call 0x4ceb50
    cpu.esp -= 4;
    sub_4ceb50(app, cpu);
    if (cpu.terminate) return;
    // 004ce951  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ce956  eb02                   -jmp 0x4ce95a
    goto L_0x004ce95a;
L_0x004ce958:
    // 004ce958  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ce95a:
    // 004ce95a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce95b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce95c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce95d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce95e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ce95f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ce960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ce960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ce961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ce962  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ce963  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ce964  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ce965  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ce966  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ce968  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ce96b  8b1574305500           -mov edx, dword ptr [0x553074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5582964) /* 0x553074 */);
    // 004ce971  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ce973:
    // 004ce973  3b0d74305500           +cmp ecx, dword ptr [0x553074]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5582964) /* 0x553074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce979  0f8d61000000           -jge 0x4ce9e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ce9e0;
    }
    // 004ce97f  8b048d08fd5e00         -mov eax, dword ptr [ecx*4 + 0x5efd08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6225160) /* 0x5efd08 */ + cpu.ecx * 4);
    // 004ce986  8a9800020000           -mov bl, byte ptr [eax + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 004ce98c  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004ce98f  7409                   -je 0x4ce99a
    if (cpu.flags.zf)
    {
        goto L_0x004ce99a;
    }
    // 004ce991  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce998  7412                   -je 0x4ce9ac
    if (cpu.flags.zf)
    {
        goto L_0x004ce9ac;
    }
L_0x004ce99a:
    // 004ce99a  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004ce9a1  741f                   -je 0x4ce9c2
    if (cpu.flags.zf)
    {
        goto L_0x004ce9c2;
    }
    // 004ce9a3  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce9aa  7516                   -jne 0x4ce9c2
    if (!cpu.flags.zf)
    {
        goto L_0x004ce9c2;
    }
L_0x004ce9ac:
    // 004ce9ac  8b9828020000           -mov ebx, dword ptr [eax + 0x228]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004ce9b2  8b3584367d00           -mov esi, dword ptr [0x7d3684]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004ce9b8  81c3c0010000           -add ebx, 0x1c0
    (cpu.ebx) += x86::reg32(x86::sreg32(448 /*0x1c0*/));
    // 004ce9be  39f3                   +cmp ebx, esi
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
    // 004ce9c0  7c1a                   -jl 0x4ce9dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ce9dc;
    }
L_0x004ce9c2:
    // 004ce9c2  833db0d36f0004         +cmp dword ptr [0x6fd3b0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce9c9  7512                   -jne 0x4ce9dd
    if (!cpu.flags.zf)
    {
        goto L_0x004ce9dd;
    }
    // 004ce9cb  8b80f0010000           -mov eax, dword ptr [eax + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(496) /* 0x1f0 */);
    // 004ce9d1  66833c45ca227a0000     +cmp word ptr [eax*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.eax * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ce9da  7401                   -je 0x4ce9dd
    if (cpu.flags.zf)
    {
        goto L_0x004ce9dd;
    }
L_0x004ce9dc:
    // 004ce9dc  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
L_0x004ce9dd:
    // 004ce9dd  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ce9de  eb93                   -jmp 0x4ce973
    goto L_0x004ce973;
L_0x004ce9e0:
    // 004ce9e0  8b3594fd5e00           -mov esi, dword ptr [0x5efd94]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */);
    // 004ce9e6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ce9e8:
    // 004ce9e8  3b0d94fd5e00           +cmp ecx, dword ptr [0x5efd94]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225300) /* 0x5efd94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ce9ee  7d46                   -jge 0x4cea36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cea36;
    }
    // 004ce9f0  8b048d88fb5e00         -mov eax, dword ptr [ecx*4 + 0x5efb88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224776) /* 0x5efb88 */ + cpu.ecx * 4);
    // 004ce9f7  8a9800020000           -mov bl, byte ptr [eax + 0x200]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */);
    // 004ce9fd  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 004cea00  7409                   -je 0x4cea0b
    if (cpu.flags.zf)
    {
        goto L_0x004cea0b;
    }
    // 004cea02  83b8c402000003         +cmp dword ptr [eax + 0x2c4], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea09  7412                   -je 0x4cea1d
    if (cpu.flags.zf)
    {
        goto L_0x004cea1d;
    }
L_0x004cea0b:
    // 004cea0b  f6800002000001         +test byte ptr [eax + 0x200], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(512) /* 0x200 */) & 1 /*0x1*/));
    // 004cea12  741f                   -je 0x4cea33
    if (cpu.flags.zf)
    {
        goto L_0x004cea33;
    }
    // 004cea14  83b8c402000004         +cmp dword ptr [eax + 0x2c4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(708) /* 0x2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea1b  7516                   -jne 0x4cea33
    if (!cpu.flags.zf)
    {
        goto L_0x004cea33;
    }
L_0x004cea1d:
    // 004cea1d  8b8028020000           -mov eax, dword ptr [eax + 0x228]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(552) /* 0x228 */);
    // 004cea23  8b1d84367d00           -mov ebx, dword ptr [0x7d3684]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004cea29  05c0010000             -add eax, 0x1c0
    (cpu.eax) += x86::reg32(x86::sreg32(448 /*0x1c0*/));
    // 004cea2e  39d8                   +cmp eax, ebx
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
    // 004cea30  7d01                   -jge 0x4cea33
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cea33;
    }
    // 004cea32  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
L_0x004cea33:
    // 004cea33  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cea34  ebb2                   -jmp 0x4ce9e8
    goto L_0x004ce9e8;
L_0x004cea36:
    // 004cea36  8b0d78305500           -mov ecx, dword ptr [0x553078]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5582968) /* 0x553078 */);
    // 004cea3c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cea3e:
    // 004cea3e  3b0578305500           +cmp eax, dword ptr [0x553078]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5582968) /* 0x553078 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea44  7d4a                   -jge 0x4cea90
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cea90;
    }
    // 004cea46  8b1c8508fc5e00         -mov ebx, dword ptr [eax*4 + 0x5efc08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6224904) /* 0x5efc08 */ + cpu.eax * 4);
    // 004cea4d  8bbbc4020000           -mov edi, dword ptr [ebx + 0x2c4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(708) /* 0x2c4 */);
    // 004cea53  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea56  751a                   -jne 0x4cea72
    if (!cpu.flags.zf)
    {
        goto L_0x004cea72;
    }
    // 004cea58  8bbb28020000           -mov edi, dword ptr [ebx + 0x228]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(552) /* 0x228 */);
    // 004cea5e  81c7c0010000           -add edi, 0x1c0
    (cpu.edi) += x86::reg32(x86::sreg32(448 /*0x1c0*/));
    // 004cea64  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 004cea67  8b3d84367d00           -mov edi, dword ptr [0x7d3684]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8205956) /* 0x7d3684 */);
    // 004cea6d  3b7dfc                 +cmp edi, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea70  7f1a                   -jg 0x4cea8c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004cea8c;
    }
L_0x004cea72:
    // 004cea72  833db0d36f0004         +cmp dword ptr [0x6fd3b0], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cea79  7512                   -jne 0x4cea8d
    if (!cpu.flags.zf)
    {
        goto L_0x004cea8d;
    }
    // 004cea7b  8b9bf0010000           -mov ebx, dword ptr [ebx + 0x1f0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(496) /* 0x1f0 */);
    // 004cea81  66833c5dca227a0000     +cmp word ptr [ebx*2 + 0x7a22ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004298) /* 0x7a22ca */ + cpu.ebx * 2);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cea8a  7401                   -je 0x4cea8d
    if (cpu.flags.zf)
    {
        goto L_0x004cea8d;
    }
L_0x004cea8c:
    // 004cea8c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
L_0x004cea8d:
    // 004cea8d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cea8e  ebae                   -jmp 0x4cea3e
    goto L_0x004cea3e;
L_0x004cea90:
    // 004cea90  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004cea92  7504                   -jne 0x4cea98
    if (!cpu.flags.zf)
    {
        goto L_0x004cea98;
    }
    // 004cea94  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cea96  7421                   -je 0x4ceab9
    if (cpu.flags.zf)
    {
        goto L_0x004ceab9;
    }
L_0x004cea98:
    // 004cea98  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004cea9a  7524                   -jne 0x4ceac0
    if (!cpu.flags.zf)
    {
        goto L_0x004ceac0;
    }
    // 004cea9c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cea9e  7520                   -jne 0x4ceac0
    if (!cpu.flags.zf)
    {
        goto L_0x004ceac0;
    }
    // 004ceaa0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ceaa2  741c                   -je 0x4ceac0
    if (cpu.flags.zf)
    {
        goto L_0x004ceac0;
    }
    // 004ceaa4  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004ceaa9  b808fc5e00             -mov eax, 0x5efc08
    cpu.eax = 6224904 /*0x5efc08*/;
    // 004ceaae  8b1578305500           -mov edx, dword ptr [0x553078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5582968) /* 0x553078 */);
    // 004ceab4  e847fdffff             -call 0x4ce800
    cpu.esp -= 4;
    sub_4ce800(app, cpu);
    if (cpu.terminate) return;
L_0x004ceab9:
    // 004ceab9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ceabe  eb02                   -jmp 0x4ceac2
    goto L_0x004ceac2;
L_0x004ceac0:
    // 004ceac0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ceac2:
    // 004ceac2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ceac4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceac5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceac6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceac7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceac8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceac9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceaca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4ceae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004ceae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ceae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ceae2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ceae3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ceae4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ceae6  833d9c367d0000         +cmp dword ptr [0x7d369c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8205980) /* 0x7d369c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ceaed  7550                   -jne 0x4ceb3f
    if (!cpu.flags.zf)
    {
        goto L_0x004ceb3f;
    }
    // 004ceaef  8b15b8d36f00           -mov edx, dword ptr [0x6fd3b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004ceaf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ceaf7  83fa03                 +cmp edx, 3
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
    // 004ceafa  771a                   -ja 0x4ceb16
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004ceb16;
    }
    // 004ceafc  ff2495ccea4c00         -jmp dword ptr [edx*4 + 0x4ceacc]
    cpu.ip = app->getMemory<x86::reg32>(5040844 + cpu.edx * 4); goto dynamic_jump;
  case 0x004ceb03:
    // 004ceb03  e858feffff             -call 0x4ce960
    cpu.esp -= 4;
    sub_4ce960(app, cpu);
    if (cpu.terminate) return;
    // 004ceb08  eb0c                   -jmp 0x4ceb16
    goto L_0x004ceb16;
  case 0x004ceb0a:
    // 004ceb0a  e831fdffff             -call 0x4ce840
    cpu.esp -= 4;
    sub_4ce840(app, cpu);
    if (cpu.terminate) return;
    // 004ceb0f  eb05                   -jmp 0x4ceb16
    goto L_0x004ceb16;
  case 0x004ceb11:
    // 004ceb11  e8cafdffff             -call 0x4ce8e0
    cpu.esp -= 4;
    sub_4ce8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004ceb16:
    // 004ceb16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ceb18  7425                   -je 0x4ceb3f
    if (cpu.flags.zf)
    {
        goto L_0x004ceb3f;
    }
    // 004ceb1a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004ceb1f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004ceb24  890d9c367d00           -mov dword ptr [0x7d369c], ecx
    app->getMemory<x86::reg32>(x86::reg32(8205980) /* 0x7d369c */) = cpu.ecx;
    // 004ceb2a  e821fcffff             -call 0x4ce750
    cpu.esp -= 4;
    sub_4ce750(app, cpu);
    if (cpu.terminate) return;
    // 004ceb2f  8b1da0d36f00           -mov ebx, dword ptr [0x6fd3a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328672) /* 0x6fd3a0 */);
    // 004ceb35  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ceb37  7506                   -jne 0x4ceb3f
    if (!cpu.flags.zf)
    {
        goto L_0x004ceb3f;
    }
    // 004ceb39  891db4367d00           -mov dword ptr [0x7d36b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(8206004) /* 0x7d36b4 */) = cpu.ebx;
L_0x004ceb3f:
    // 004ceb3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceb40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceb41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceb42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceb43  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4ceb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ceb50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ceb51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ceb52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ceb53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ceb54  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004ceb56  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ceb58:
    // 004ceb58  3b15a4fd5e00           +cmp edx, dword ptr [0x5efda4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6225316) /* 0x5efda4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ceb5e  0f8d7d000000           -jge 0x4cebe1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cebe1;
    }
    // 004ceb64  8b049548fa5e00         -mov eax, dword ptr [edx*4 + 0x5efa48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6224456) /* 0x5efa48 */ + cpu.edx * 4);
    // 004ceb6b  8b9878020000           -mov ebx, dword ptr [eax + 0x278]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(632) /* 0x278 */);
    // 004ceb71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ceb73  7412                   -je 0x4ceb87
    if (cpu.flags.zf)
    {
        goto L_0x004ceb87;
    }
    // 004ceb75  81fbc0020000           +cmp ebx, 0x2c0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(704 /*0x2c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ceb7b  7d0a                   -jge 0x4ceb87
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ceb87;
    }
    // 004ceb7d  c7807802000000000000   -mov dword ptr [eax + 0x278], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(632) /* 0x278 */) = 0 /*0x0*/;
L_0x004ceb87:
    // 004ceb87  8bb880020000           -mov edi, dword ptr [eax + 0x280]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */);
    // 004ceb8d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ceb8f  7412                   -je 0x4ceba3
    if (cpu.flags.zf)
    {
        goto L_0x004ceba3;
    }
    // 004ceb91  81ff40060000           +cmp edi, 0x640
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1600 /*0x640*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ceb97  7d0a                   -jge 0x4ceba3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ceba3;
    }
    // 004ceb99  c7808002000000000000   -mov dword ptr [eax + 0x280], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 0 /*0x0*/;
L_0x004ceba3:
    // 004ceba3  8b987c020000           -mov ebx, dword ptr [eax + 0x27c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(636) /* 0x27c */);
    // 004ceba9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cebab  7412                   -je 0x4cebbf
    if (cpu.flags.zf)
    {
        goto L_0x004cebbf;
    }
    // 004cebad  81fbc0020000           +cmp ebx, 0x2c0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(704 /*0x2c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cebb3  7d0a                   -jge 0x4cebbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cebbf;
    }
    // 004cebb5  c7807c02000000000000   -mov dword ptr [eax + 0x27c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(636) /* 0x27c */) = 0 /*0x0*/;
L_0x004cebbf:
    // 004cebbf  8bb884020000           -mov edi, dword ptr [eax + 0x284]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */);
    // 004cebc5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004cebc7  7412                   -je 0x4cebdb
    if (cpu.flags.zf)
    {
        goto L_0x004cebdb;
    }
    // 004cebc9  81ff80040000           +cmp edi, 0x480
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1152 /*0x480*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cebcf  7d0a                   -jge 0x4cebdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cebdb;
    }
    // 004cebd1  c7808402000000000000   -mov dword ptr [eax + 0x284], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(644) /* 0x284 */) = 0 /*0x0*/;
L_0x004cebdb:
    // 004cebdb  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cebdc  e977ffffff             -jmp 0x4ceb58
    goto L_0x004ceb58;
L_0x004cebe1:
    // 004cebe1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cebe2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cebe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cebe4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cebe5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4cebf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cebf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cebf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cebf2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cebf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cebf4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cebf6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004cebf9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cebfb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cebfd  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004cec00  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004cec07  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004cec0c  b8c8045400             -mov eax, 0x5404c8
    cpu.eax = 5506248 /*0x5404c8*/;
    // 004cec11  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004cec14  e8072a0100             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004cec19  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cec1b  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cec1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cec1f:
    // 004cec1f  39c8                   +cmp eax, ecx
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
    // 004cec21  7d25                   -jge 0x4cec48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cec48;
    }
    // 004cec23  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cec26  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004cec29  01fb                   +add ebx, edi
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
    // 004cec2b  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004cec2e  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004cec35  8d3c1e                 -lea edi, [esi + ebx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004cec38  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 004cec3b  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004cec3e  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cec41  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cec42  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004cec44  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004cec46  ebd7                   -jmp 0x4cec1f
    goto L_0x004cec1f;
L_0x004cec48:
    // 004cec48  83f901                 +cmp ecx, 1
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
    // 004cec4b  7463                   -je 0x4cecb0
    if (cpu.flags.zf)
    {
        goto L_0x004cecb0;
    }
    // 004cec4d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cec52:
    // 004cec52  39c8                   +cmp eax, ecx
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
    // 004cec54  7d5a                   -jge 0x4cecb0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cecb0;
    }
    // 004cec56  8b1c82                 -mov ebx, dword ptr [edx + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004cec59  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cec5c  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004cec5f  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004cec62  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004cec64  0fbf1b                 -movsx ebx, word ptr [ebx]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx)));
    // 004cec67  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004cec6a  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004cec6d:
    // 004cec6d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cec6f  7c27                   -jl 0x4cec98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cec98;
    }
    // 004cec71  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 004cec78  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cec7a  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cec7d  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cec7f  7d17                   -jge 0x4cec98
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cec98;
    }
    // 004cec81  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 004cec83  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004cec86  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cec89  8d341b                 -lea esi, [ebx + ebx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004cec8c  01fe                   +add esi, edi
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
    // 004cec8e  668b3e                 -mov di, word ptr [esi]
    cpu.di = app->getMemory<x86::reg16>(cpu.esi);
    // 004cec91  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004cec92  66897e02               -mov word ptr [esi + 2], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.di;
    // 004cec96  ebd5                   -jmp 0x4cec6d
    goto L_0x004cec6d;
L_0x004cec98:
    // 004cec98  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cec9b  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cec9e  897c9a04               -mov dword ptr [edx + ebx*4 + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebx * 4) = cpu.edi;
    // 004ceca2  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ceca4  01f3                   +add ebx, esi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ceca6  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ceca9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cecaa  66897302               -mov word ptr [ebx + 2], si
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.si;
    // 004cecae  eba2                   -jmp 0x4cec52
    goto L_0x004cec52;
L_0x004cecb0:
    // 004cecb0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cecb2  e8d92b0100             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004cecb7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cecb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cecba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cecbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cecbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cecbd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4cecc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cecc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cecc1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cecc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cecc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cecc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cecc6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004cecc9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ceccb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ceccd  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004cecd0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004cecd7  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004cecdc  b8c8045400             -mov eax, 0x5404c8
    cpu.eax = 5506248 /*0x5404c8*/;
    // 004cece1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004cece4  e837290100             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004cece9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ceceb  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ceced  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cecef:
    // 004cecef  39f2                   +cmp edx, esi
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
    // 004cecf1  7d28                   -jge 0x4ced1b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ced1b;
    }
    // 004cecf3  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cecf6  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004cecf9  01d8                   +add eax, ebx
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
    // 004cecfb  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004cecfe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004ced05  d90407                 +fld dword ptr [edi + eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + cpu.eax * 1)));
    // 004ced08  e849100100             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004ced0d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ced0f  db5df8                 +fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ced12  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ced15  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ced16  890419                 -mov dword ptr [ecx + ebx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1) = cpu.eax;
    // 004ced19  ebd4                   -jmp 0x4cecef
    goto L_0x004cecef;
L_0x004ced1b:
    // 004ced1b  83fe01                 +cmp esi, 1
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
    // 004ced1e  0f8496000000           -je 0x4cedba
    if (cpu.flags.zf)
    {
        goto L_0x004cedba;
    }
    // 004ced24  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004ced29:
    // 004ced29  39f2                   +cmp edx, esi
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
    // 004ced2b  0f8d89000000           -jge 0x4cedba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cedba;
    }
    // 004ced31  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ced34  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004ced37  db0491                 -fild dword ptr [ecx + edx*4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 4))));
    // 004ced3a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ced3c  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ced3f  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004ced42  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004ced44  d95dec                 -fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004ced47:
    // 004ced47  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ced49  7c2b                   -jl 0x4ced76
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ced76;
    }
    // 004ced4b  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ced52  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004ced55  db07                   +fild dword ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi))));
    // 004ced57  d85df0                 +fcomp dword ptr [ebp - 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */));
    cpu.fpu.pop();
    // 004ced5a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004ced5c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004ced5d  7617                   -jbe 0x4ced76
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004ced76;
    }
    // 004ced5f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004ced61  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ced64  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004ced67  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004ced6a  01f8                   +add eax, edi
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
    // 004ced6c  668b38                 -mov di, word ptr [eax]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax);
    // 004ced6f  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ced70  66897802               -mov word ptr [eax + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.di;
    // 004ced74  ebd1                   -jmp 0x4ced47
    goto L_0x004ced47;
L_0x004ced76:
    // 004ced76  d945ec                 -fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004ced79  d945f0                 -fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004ced7c  e8d50f0100             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004ced81  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ced88  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ced8a  e8c70f0100             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004ced8f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004ced91  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ced94  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004ced97  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ced9a  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004ced9d  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ceda0  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ceda3  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ceda5  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004ceda8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cedab  42                     -inc edx
    (cpu.edx)++;
    // 004cedac  01c3                   +add ebx, eax
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
    // 004cedae  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cedb1  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004cedb5  e96fffffff             -jmp 0x4ced29
    goto L_0x004ced29;
L_0x004cedba:
    // 004cedba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cedbc  e8cf2a0100             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004cedc1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cedc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cedc4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cedc5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cedc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cedc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cedd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cedd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cedd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cedd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cedd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cedd5  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004cedd8  d94510                 +fld dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 004ceddb  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 004ceddd  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 004ceddf  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004cede1  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004cede2  733a                   -jae 0x4cee1e
    if (!cpu.flags.cf)
    {
        goto L_0x004cee1e;
    }
    // 004cede4  8b0d68bc6f00           -mov ecx, dword ptr [0x6fbc68]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322728) /* 0x6fbc68 */);
    // 004cedea  83f903                 +cmp ecx, 3
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
    // 004ceded  7405                   -je 0x4cedf4
    if (cpu.flags.zf)
    {
        goto L_0x004cedf4;
    }
    // 004cedef  83f904                 +cmp ecx, 4
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
    // 004cedf2  750b                   -jne 0x4cedff
    if (!cpu.flags.zf)
    {
        goto L_0x004cedff;
    }
L_0x004cedf4:
    // 004cedf4  d94510                 +fld dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 004cedf7  d80dd8045400           +fmul dword ptr [0x5404d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5506264) /* 0x5404d8 */));
    // 004cedfd  eb09                   -jmp 0x4cee08
    goto L_0x004cee08;
L_0x004cedff:
    // 004cedff  d94510                 -fld dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */)));
    // 004cee02  d80ddc045400           -fmul dword ptr [0x5404dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5506268) /* 0x5404dc */));
L_0x004cee08:
    // 004cee08  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cee0b  dd1c24                 -fstp qword ptr [esp]
    app->getMemory<double>(cpu.esp) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004cee0e  68cc045400             -push 0x5404cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5506252 /*0x5404cc*/;
    cpu.esp -= 4;
    // 004cee13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cee14  e877080100             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004cee19  83c410                 +add esp, 0x10
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
    // 004cee1c  eb0e                   -jmp 0x4cee2c
    goto L_0x004cee2c;
L_0x004cee1e:
    // 004cee1e  68d4045400             -push 0x5404d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5506260 /*0x5404d4*/;
    cpu.esp -= 4;
    // 004cee23  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cee24  e867080100             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004cee29  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004cee2c:
    // 004cee2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cee2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cee2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cee2f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4cee40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cee40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cee41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cee42  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cee43  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cee44  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cee45  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cee47  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cee4a  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cee4d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cee4f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cee52  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 004cee55  dc0df8045400           -fmul qword ptr [0x5404f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5506296) /* 0x5404f8 */));
    // 004cee5b  e8f60e0100             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004cee60  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004cee63  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cee66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cee68  b970170000             -mov ecx, 0x1770
    cpu.ecx = 6000 /*0x1770*/;
    // 004cee6d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004cee70  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004cee72  0fbfc8                 -movsx ecx, ax
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004cee75  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004cee7c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cee7e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004cee81  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cee83  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004cee86  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cee88  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004cee8b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cee8d  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cee90  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004cee92  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004cee97  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004cee9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cee9c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004cee9f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ceea1  0fbfd8                 -movsx ebx, ax
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004ceea4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ceea6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004ceead  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ceeaf  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004ceeb2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ceeb4  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004ceeb7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ceeba  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ceebc  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 004ceebf  8b45f6                 -mov eax, dword ptr [ebp - 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 004ceec2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ceec5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ceec6  a14cbb6f00             -mov eax, dword ptr [0x6fbb4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
    // 004ceecb  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ceecd  8a902e1b5600           -mov dl, byte ptr [eax + 0x561b2e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5643054) /* 0x561b2e */);
    // 004ceed3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ceed4  8a80281b5600           -mov al, byte ptr [eax + 0x561b28]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5643048) /* 0x561b28 */);
    // 004ceeda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ceedb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ceee0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ceee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ceee2  68e0045400             -push 0x5404e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5506272 /*0x5404e0*/;
    cpu.esp -= 4;
    // 004ceee7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ceee8  e8a3070100             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004ceeed  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ceef0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004ceef2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceef3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceef4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceef6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cef00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cef00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cef01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cef02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cef03  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cef05  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004cef0b  81ed7e010000           -sub ebp, 0x17e
    (cpu.ebp) -= x86::reg32(x86::sreg32(382 /*0x17e*/));
    // 004cef11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cef13  f6052eeb550020         +test byte ptr [0x55eb2e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 32 /*0x20*/));
    // 004cef1a  7407                   -je 0x4cef23
    if (cpu.flags.zf)
    {
        goto L_0x004cef23;
    }
    // 004cef1c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cef21  eb4b                   -jmp 0x4cef6e
    goto L_0x004cef6e;
L_0x004cef23:
    // 004cef23  e8a806f8ff             -call 0x44f5d0
    cpu.esp -= 4;
    sub_44f5d0(app, cpu);
    if (cpu.terminate) return;
    // 004cef28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cef2a  741c                   -je 0x4cef48
    if (cpu.flags.zf)
    {
        goto L_0x004cef48;
    }
    // 004cef2c  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 004cef2f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004cef31  8d5d7e                 -lea ebx, [ebp + 0x7e]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef34  e83707f8ff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 004cef39  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef3c  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef3f  e84c0bf8ff             -call 0x44fa90
    cpu.esp -= 4;
    sub_44fa90(app, cpu);
    if (cpu.terminate) return;
    // 004cef44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cef46  eb24                   -jmp 0x4cef6c
    goto L_0x004cef6c;
L_0x004cef48:
    // 004cef48  e8c305f8ff             -call 0x44f510
    cpu.esp -= 4;
    sub_44f510(app, cpu);
    if (cpu.terminate) return;
    // 004cef4d  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 004cef50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cef52  8d5d7e                 -lea ebx, [ebp + 0x7e]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef55  e81607f8ff             -call 0x44f670
    cpu.esp -= 4;
    sub_44f670(app, cpu);
    if (cpu.terminate) return;
    // 004cef5a  8d557e                 -lea edx, [ebp + 0x7e]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef5d  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004cef60  e82b0bf8ff             -call 0x44fa90
    cpu.esp -= 4;
    sub_44fa90(app, cpu);
    if (cpu.terminate) return;
    // 004cef65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cef67  e88406f8ff             -call 0x44f5f0
    cpu.esp -= 4;
    sub_44f5f0(app, cpu);
    if (cpu.terminate) return;
L_0x004cef6c:
    // 004cef6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004cef6e:
    // 004cef6e  8da57e010000           -lea esp, [ebp + 0x17e]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(382) /* 0x17e */);
    // 004cef74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cef75  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cef76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cef77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cef80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cef80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cef81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cef82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cef83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cef84  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cef86  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004cef88  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cef8a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cef8c  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 004cef8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cef90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cef92  e8396ef8ff             -call 0x455dd0
    cpu.esp -= 4;
    sub_455dd0(app, cpu);
    if (cpu.terminate) return;
    // 004cef97  f6052eeb550040         +test byte ptr [0x55eb2e], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 64 /*0x40*/));
    // 004cef9e  7407                   -je 0x4cefa7
    if (cpu.flags.zf)
    {
        goto L_0x004cefa7;
    }
    // 004cefa0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cefa2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefa3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefa5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefa6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cefa7:
    // 004cefa7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cefa9  7405                   -je 0x4cefb0
    if (cpu.flags.zf)
    {
        goto L_0x004cefb0;
    }
    // 004cefab  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004cefb0:
    // 004cefb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4cefc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cefc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cefc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cefc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cefc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cefc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cefc5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cefc7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004cefc9:
    // 004cefc9  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cefcf  7d18                   -jge 0x4cefe9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cefe9;
    }
    // 004cefd1  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cefd3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004cefd5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cefd7  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004cefd9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cefdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cefdd  e8ee6df8ff             -call 0x455dd0
    cpu.esp -= 4;
    sub_455dd0(app, cpu);
    if (cpu.terminate) return;
    // 004cefe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cefe4  7403                   -je 0x4cefe9
    if (cpu.flags.zf)
    {
        goto L_0x004cefe9;
    }
    // 004cefe6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cefe7  ebe0                   -jmp 0x4cefc9
    goto L_0x004cefc9;
L_0x004cefe9:
    // 004cefe9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cefeb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cefef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ceff0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4cf000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf002  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf005  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf007  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004cf009:
    // 004cf009  3b35307d6700           +cmp esi, dword ptr [0x677d30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6782256) /* 0x677d30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf00f  7d18                   -jge 0x4cf029
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf029;
    }
    // 004cf011  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004cf013  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004cf015  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf017  6a28                   -push 0x28
    app->getMemory<x86::reg32>(cpu.esp-4) = 40 /*0x28*/;
    cpu.esp -= 4;
    // 004cf019  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cf01b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf01d  e8ae6df8ff             -call 0x455dd0
    cpu.esp -= 4;
    sub_455dd0(app, cpu);
    if (cpu.terminate) return;
    // 004cf022  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf024  7403                   -je 0x4cf029
    if (cpu.flags.zf)
    {
        goto L_0x004cf029;
    }
    // 004cf026  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cf027  ebe0                   -jmp 0x4cf009
    goto L_0x004cf009;
L_0x004cf029:
    // 004cf029  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cf02b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf02c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf02d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf02e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf02f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf030  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4cf040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf041  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf043  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf045  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf04c  7e2e                   -jle 0x4cf07c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cf07c;
    }
    // 004cf04e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004cf050:
    // 004cf050  3b0d10d56f00           +cmp ecx, dword ptr [0x6fd510]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7329040) /* 0x6fd510 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf056  7d24                   -jge 0x4cf07c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf07c;
    }
    // 004cf058  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004cf05f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf061  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004cf064  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cf066  83bcc294d56f0000       +cmp dword ptr [edx + eax*8 + 0x6fd594], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7329172) /* 0x6fd594 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf06e  7409                   -je 0x4cf079
    if (cpu.flags.zf)
    {
        goto L_0x004cf079;
    }
    // 004cf070  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf075  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf078  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf079:
    // 004cf079  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cf07a  ebd4                   -jmp 0x4cf050
    goto L_0x004cf050;
L_0x004cf07c:
    // 004cf07c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf07e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf07f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf080  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf081  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4cf090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf090  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf091  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf092  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf093  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf094  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf096  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cf09b  a1b8d36f00             -mov eax, dword ptr [0x6fd3b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004cf0a0  39d0                   +cmp eax, edx
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
    // 004cf0a2  7255                   -jb 0x4cf0f9
    if (cpu.flags.cf)
    {
        goto L_0x004cf0f9;
    }
    // 004cf0a4  762f                   -jbe 0x4cf0d5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004cf0d5;
    }
    // 004cf0a6  83f802                 +cmp eax, 2
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
    // 004cf0a9  754e                   -jne 0x4cf0f9
    if (!cpu.flags.zf)
    {
        goto L_0x004cf0f9;
    }
    // 004cf0ab  a108d46f00             -mov eax, dword ptr [0x6fd408]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328776) /* 0x6fd408 */);
    // 004cf0b0  8b0dacd46f00           -mov ecx, dword ptr [0x6fd4ac]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 004cf0b6  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004cf0b9  39c8                   +cmp eax, ecx
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
    // 004cf0bb  7502                   -jne 0x4cf0bf
    if (!cpu.flags.zf)
    {
        goto L_0x004cf0bf;
    }
    // 004cf0bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cf0bf:
    // 004cf0bf  e83cffffff             -call 0x4cf000
    cpu.esp -= 4;
    sub_4cf000(app, cpu);
    if (cpu.terminate) return;
    // 004cf0c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf0c6  7409                   -je 0x4cf0d1
    if (cpu.flags.zf)
    {
        goto L_0x004cf0d1;
    }
    // 004cf0c8  e8b3feffff             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 004cf0cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf0cf  7428                   -je 0x4cf0f9
    if (cpu.flags.zf)
    {
        goto L_0x004cf0f9;
    }
L_0x004cf0d1:
    // 004cf0d1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004cf0d3  eb24                   -jmp 0x4cf0f9
    goto L_0x004cf0f9;
L_0x004cf0d5:
    // 004cf0d5  8b1d20d05500           -mov ebx, dword ptr [0x55d020]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5623840) /* 0x55d020 */);
    // 004cf0db  3b1dacd46f00           +cmp ebx, dword ptr [0x6fd4ac]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf0e1  7502                   -jne 0x4cf0e5
    if (!cpu.flags.zf)
    {
        goto L_0x004cf0e5;
    }
    // 004cf0e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cf0e5:
    // 004cf0e5  e816ffffff             -call 0x4cf000
    cpu.esp -= 4;
    sub_4cf000(app, cpu);
    if (cpu.terminate) return;
    // 004cf0ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf0ec  7409                   -je 0x4cf0f7
    if (cpu.flags.zf)
    {
        goto L_0x004cf0f7;
    }
    // 004cf0ee  e88dfeffff             -call 0x4cef80
    cpu.esp -= 4;
    sub_4cef80(app, cpu);
    if (cpu.terminate) return;
    // 004cf0f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf0f5  7402                   -je 0x4cf0f9
    if (cpu.flags.zf)
    {
        goto L_0x004cf0f9;
    }
L_0x004cf0f7:
    // 004cf0f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cf0f9:
    // 004cf0f9  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf100  7e15                   -jle 0x4cf117
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cf117;
    }
    // 004cf102  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf109  740a                   -je 0x4cf115
    if (cpu.flags.zf)
    {
        goto L_0x004cf115;
    }
    // 004cf10b  66833ddc227a0000       +cmp word ptr [0x7a22dc], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(8004316) /* 0x7a22dc */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cf113  7402                   -je 0x4cf117
    if (cpu.flags.zf)
    {
        goto L_0x004cf117;
    }
L_0x004cf115:
    // 004cf115  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cf117:
    // 004cf117  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cf119  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf11a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf11b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf11c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf11d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4cf120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf123  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf124  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf125  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf127  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cf129  8b9040020000           -mov edx, dword ptr [eax + 0x240]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(576) /* 0x240 */);
    // 004cf12f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cf131  eb08                   -jmp 0x4cf13b
    goto L_0x004cf13b;
L_0x004cf133:
    // 004cf133  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004cf135:
    // 004cf135  40                     -inc eax
    (cpu.eax)++;
    // 004cf136  83f808                 +cmp eax, 8
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
    // 004cf139  7d19                   -jge 0x4cf154
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf154;
    }
L_0x004cf13b:
    // 004cf13b  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004cf142  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004cf144  8bb140020000           -mov esi, dword ptr [ecx + 0x240]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(576) /* 0x240 */);
    // 004cf14a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cf14c  74e7                   -je 0x4cf135
    if (cpu.flags.zf)
    {
        goto L_0x004cf135;
    }
    // 004cf14e  39f2                   +cmp edx, esi
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
    // 004cf150  7fe1                   -jg 0x4cf133
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004cf133;
    }
    // 004cf152  ebe1                   -jmp 0x4cf135
    goto L_0x004cf135;
L_0x004cf154:
    // 004cf154  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cf156  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf157  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf158  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf159  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf15a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf15b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cf160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf160  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf161  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf163  663d0200               +cmp ax, 2
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cf167  7504                   -jne 0x4cf16d
    if (!cpu.flags.zf)
    {
        goto L_0x004cf16d;
    }
    // 004cf169  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004cf16b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf16c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf16d:
    // 004cf16d  663d0400               +cmp ax, 4
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(4 /*0x4*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cf171  7507                   -jne 0x4cf17a
    if (!cpu.flags.zf)
    {
        goto L_0x004cf17a;
    }
    // 004cf173  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf178  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf179  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf17a:
    // 004cf17a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004cf17f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf180  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4cf190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf190  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf191  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf193  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 004cf196  7507                   -jne 0x4cf19f
    if (!cpu.flags.zf)
    {
        goto L_0x004cf19f;
    }
    // 004cf198  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004cf19d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf19e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf19f:
    // 004cf19f  663d0100               +cmp ax, 1
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004cf1a3  7507                   -jne 0x4cf1ac
    if (!cpu.flags.zf)
    {
        goto L_0x004cf1ac;
    }
    // 004cf1a5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004cf1aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf1ac:
    // 004cf1ac  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004cf1b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4cf1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf1c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf1c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf1c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf1c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf1c6  7508                   -jne 0x4cf1d0
    if (!cpu.flags.zf)
    {
        goto L_0x004cf1d0;
    }
    // 004cf1c8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf1cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf1d0:
    // 004cf1d0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004cf1d2  81395354524d           +cmp dword ptr [ecx], 0x4d525453
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1297241171 /*0x4d525453*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf1d8  7408                   -je 0x4cf1e2
    if (cpu.flags.zf)
    {
        goto L_0x004cf1e2;
    }
    // 004cf1da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf1df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf1e2:
    // 004cf1e2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004cf1e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf1e6  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004cf1e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf1ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4cf1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf1f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf1f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf1f3  39d0                   +cmp eax, edx
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
    // 004cf1f5  770c                   -ja 0x4cf203
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004cf203;
    }
    // 004cf1f7  39c3                   +cmp ebx, eax
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
    // 004cf1f9  7204                   -jb 0x4cf1ff
    if (cpu.flags.cf)
    {
        goto L_0x004cf1ff;
    }
    // 004cf1fb  39d3                   +cmp ebx, edx
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
    // 004cf1fd  720c                   -jb 0x4cf20b
    if (cpu.flags.cf)
    {
        goto L_0x004cf20b;
    }
L_0x004cf1ff:
    // 004cf1ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf202  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf203:
    // 004cf203  39c3                   +cmp ebx, eax
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
    // 004cf205  7304                   -jae 0x4cf20b
    if (!cpu.flags.cf)
    {
        goto L_0x004cf20b;
    }
    // 004cf207  39d3                   +cmp ebx, edx
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
    // 004cf209  7307                   -jae 0x4cf212
    if (!cpu.flags.cf)
    {
        goto L_0x004cf212;
    }
L_0x004cf20b:
    // 004cf20b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf210  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf211  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf212:
    // 004cf212  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf214  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf215  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4cf220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf225  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf227  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cf229  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004cf22b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf22e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf22f  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf235  8b733c                 -mov esi, dword ptr [ebx + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */);
    // 004cf238  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cf23a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf23d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004cf23f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf240  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004cf242  89433c                 -mov dword ptr [ebx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004cf245  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf24b  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004cf24e  39c6                   +cmp esi, eax
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
    // 004cf250  7c21                   -jl 0x4cf273
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cf273;
    }
    // 004cf252  39c7                   +cmp edi, eax
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
    // 004cf254  7d1d                   -jge 0x4cf273
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf273;
    }
    // 004cf256  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004cf259  c7433801000000         -mov dword ptr [ebx + 0x38], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */) = 1 /*0x1*/;
    // 004cf260  83fe01                 +cmp esi, 1
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
    // 004cf263  750e                   -jne 0x4cf273
    if (!cpu.flags.zf)
    {
        goto L_0x004cf273;
    }
    // 004cf265  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf268  8b8368010000           -mov eax, dword ptr [ebx + 0x168]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(360) /* 0x168 */);
    // 004cf26e  e83dd70200             -call 0x4fc9b0
    cpu.esp -= 4;
    sub_4fc9b0(app, cpu);
    if (cpu.terminate) return;
L_0x004cf273:
    // 004cf273  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf274  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf275  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf276  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf277  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf278  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4cf280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf283  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf284  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf285  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf286  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf288  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004cf28a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf28d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf28e  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf294  8b4e58                 -mov ecx, dword ptr [esi + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004cf297  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cf299  7504                   -jne 0x4cf29f
    if (!cpu.flags.zf)
    {
        goto L_0x004cf29f;
    }
    // 004cf29b  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004cf29d  eb37                   -jmp 0x4cf2d6
    goto L_0x004cf2d6;
L_0x004cf29f:
    // 004cf29f  8b3db0747f00           -mov edi, dword ptr [0x7f74b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8352944) /* 0x7f74b0 */);
    // 004cf2a5  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004cf2a8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004cf2aa  894658                 -mov dword ptr [esi + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004cf2ad  81c700010000           +add edi, 0x100
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004cf2b3  893db0747f00           -mov dword ptr [0x7f74b0], edi
    app->getMemory<x86::reg32>(x86::reg32(8352944) /* 0x7f74b0 */) = cpu.edi;
    // 004cf2b9  750a                   -jne 0x4cf2c5
    if (!cpu.flags.zf)
    {
        goto L_0x004cf2c5;
    }
    // 004cf2bb  c705b0747f0000010000   -mov dword ptr [0x7f74b0], 0x100
    app->getMemory<x86::reg32>(x86::reg32(8352944) /* 0x7f74b0 */) = 256 /*0x100*/;
L_0x004cf2c5:
    // 004cf2c5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004cf2c7  a1b0747f00             -mov eax, dword ptr [0x7f74b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8352944) /* 0x7f74b0 */);
    // 004cf2cc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004cf2d2  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf2d4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004cf2d6:
    // 004cf2d6  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004cf2d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf2da  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf2e0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf2e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf2e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4cf2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf2f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf2f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf2f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf2f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf2f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf2f6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cf2f8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cf2fa  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 004cf301  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004cf308  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf30b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf30c  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf312  8b4b54                 -mov ecx, dword ptr [ebx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004cf315  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cf317  750b                   -jne 0x4cf324
    if (!cpu.flags.zf)
    {
        goto L_0x004cf324;
    }
    // 004cf319  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004cf31c  89734c                 -mov dword ptr [ebx + 0x4c], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */) = cpu.esi;
    // 004cf31f  897350                 -mov dword ptr [ebx + 0x50], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.esi;
    // 004cf322  eb06                   -jmp 0x4cf32a
    goto L_0x004cf32a;
L_0x004cf324:
    // 004cf324  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004cf327  89710c                 -mov dword ptr [ecx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x004cf32a:
    // 004cf32a  897354                 -mov dword ptr [ebx + 0x54], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */) = cpu.esi;
    // 004cf32d  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf330  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf331  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf337  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf338  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf339  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf33a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf33b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cf340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf341  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf342  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf343  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf345  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cf347  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004cf349  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004cf34c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004cf351  39c8                   +cmp eax, ecx
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
    // 004cf353  7d1e                   -jge 0x4cf373
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf373;
    }
    // 004cf355  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cf357  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004cf35a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf35c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004cf35f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf361  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004cf364  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004cf367  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf369  3b10                   +cmp edx, dword ptr [eax]
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
    // 004cf36b  7506                   -jne 0x4cf373
    if (!cpu.flags.zf)
    {
        goto L_0x004cf373;
    }
    // 004cf36d  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004cf371  7502                   -jne 0x4cf375
    if (!cpu.flags.zf)
    {
        goto L_0x004cf375;
    }
L_0x004cf373:
    // 004cf373  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cf375:
    // 004cf375  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf376  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf377  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf378  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4cf380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf382  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf383  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf384  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf385  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf387  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004cf38a  39ca                   +cmp edx, ecx
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
    // 004cf38c  7508                   -jne 0x4cf396
    if (!cpu.flags.zf)
    {
        goto L_0x004cf396;
    }
    // 004cf38e  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004cf391  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 004cf394  eb09                   -jmp 0x4cf39f
    goto L_0x004cf39f;
L_0x004cf396:
    // 004cf396  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004cf399  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004cf39c  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004cf39f:
    // 004cf39f  8b5854                 -mov ebx, dword ptr [eax + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004cf3a2  39da                   +cmp edx, ebx
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
    // 004cf3a4  7508                   -jne 0x4cf3ae
    if (!cpu.flags.zf)
    {
        goto L_0x004cf3ae;
    }
    // 004cf3a6  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004cf3a9  894854                 -mov dword ptr [eax + 0x54], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.ecx;
    // 004cf3ac  eb09                   -jmp 0x4cf3b7
    goto L_0x004cf3b7;
L_0x004cf3ae:
    // 004cf3ae  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004cf3b1  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004cf3b4  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x004cf3b7:
    // 004cf3b7  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004cf3ba  39f2                   +cmp edx, esi
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
    // 004cf3bc  7512                   -jne 0x4cf3d0
    if (!cpu.flags.zf)
    {
        goto L_0x004cf3d0;
    }
    // 004cf3be  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004cf3c1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004cf3c3  7508                   -jne 0x4cf3cd
    if (!cpu.flags.zf)
    {
        goto L_0x004cf3cd;
    }
    // 004cf3c5  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004cf3c8  894850                 -mov dword ptr [eax + 0x50], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ecx;
    // 004cf3cb  eb03                   -jmp 0x4cf3d0
    goto L_0x004cf3d0;
L_0x004cf3cd:
    // 004cf3cd  897850                 -mov dword ptr [eax + 0x50], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.edi;
L_0x004cf3d0:
    // 004cf3d0  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004cf3d7  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 004cf3da  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004cf3dd  895058                 -mov dword ptr [eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 004cf3e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf3e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf3e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf3e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf3e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf3e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4cf3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf3f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf3f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf3f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf3f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf3f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf3f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf3f7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cf3f9  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004cf3fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cf3fd:
    // 004cf3fd  3b5114                 +cmp edx, dword ptr [ecx + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf400  7d28                   -jge 0x4cf42a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf42a;
    }
    // 004cf402  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004cf409  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cf40b  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004cf412  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004cf415  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004cf417  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004cf419  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf41c  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004cf41e  39fb                   +cmp ebx, edi
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
    // 004cf420  7505                   -jne 0x4cf427
    if (!cpu.flags.zf)
    {
        goto L_0x004cf427;
    }
    // 004cf422  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004cf425  eb08                   -jmp 0x4cf42f
    goto L_0x004cf42f;
L_0x004cf427:
    // 004cf427  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cf428  ebd3                   -jmp 0x4cf3fd
    goto L_0x004cf3fd;
L_0x004cf42a:
    // 004cf42a  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
L_0x004cf42f:
    // 004cf42f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf430  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf431  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf432  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf433  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4cf440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf444  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf445  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf446  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf448  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004cf44b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cf44d  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004cf450  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004cf453:
    // 004cf453  8b5344                 -mov edx, dword ptr [ebx + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */);
    // 004cf456  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004cf459  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cf45b  83f808                 +cmp eax, 8
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
    // 004cf45e  0f8cf5000000           -jl 0x4cf559
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cf559;
    }
    // 004cf464  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004cf467  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cf469  f7c7000000ff           +test edi, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 4278190080 /*0xff000000*/));
    // 004cf46f  0f85e4000000           -jne 0x4cf559
    if (!cpu.flags.zf)
    {
        goto L_0x004cf559;
    }
    // 004cf475  8b4b48                 -mov ecx, dword ptr [ebx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004cf478  8d043a                 -lea eax, [edx + edi]
    cpu.eax = x86::reg32(cpu.edx + cpu.edi * 1);
    // 004cf47b  39c8                   +cmp eax, ecx
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
    // 004cf47d  0f87d6000000           -ja 0x4cf559
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004cf559;
    }
    // 004cf483  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf485  e866ffffff             -call 0x4cf3f0
    cpu.esp -= 4;
    sub_4cf3f0(app, cpu);
    if (cpu.terminate) return;
    // 004cf48a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004cf48d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf48f  7d38                   -jge 0x4cf4c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf4c9;
    }
    // 004cf491  83f8fe                 -cmp eax, -2
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
    // 004cf494  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf497  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cf498  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf49e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf4a1  83780404               +cmp dword ptr [eax + 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf4a5  7507                   -jne 0x4cf4ae
    if (!cpu.flags.zf)
    {
        goto L_0x004cf4ae;
    }
    // 004cf4a7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf4ac  eb02                   -jmp 0x4cf4b0
    goto L_0x004cf4b0;
L_0x004cf4ae:
    // 004cf4ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cf4b0:
    // 004cf4b0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cf4b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf4b5  0f8576000000           -jne 0x4cf531
    if (!cpu.flags.zf)
    {
        goto L_0x004cf531;
    }
    // 004cf4bb  c706feffffff           -mov dword ptr [esi], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.esi) = 4294967294 /*0xfffffffe*/;
    // 004cf4c1  017b44                 +add dword ptr [ebx + 0x44], edi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004cf4c4  e968000000             -jmp 0x4cf531
    goto L_0x004cf531;
L_0x004cf4c9:
    // 004cf4c9  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004cf4cc  094604                 -or dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf4cf  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf4d2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf4d3  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf4d9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf4dc  83780404               +cmp dword ptr [eax + 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf4e0  7507                   -jne 0x4cf4e9
    if (!cpu.flags.zf)
    {
        goto L_0x004cf4e9;
    }
    // 004cf4e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf4e7  eb02                   -jmp 0x4cf4eb
    goto L_0x004cf4eb;
L_0x004cf4e9:
    // 004cf4e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cf4eb:
    // 004cf4eb  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cf4ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf4f0  753f                   -jne 0x4cf531
    if (!cpu.flags.zf)
    {
        goto L_0x004cf531;
    }
    // 004cf4f2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cf4f5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004cf4f8  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004cf4fb  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004cf4fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cf500  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004cf503  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004cf505  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004cf508  39cf                   +cmp edi, ecx
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
    // 004cf50a  7503                   -jne 0x4cf50f
    if (!cpu.flags.zf)
    {
        goto L_0x004cf50f;
    }
    // 004cf50c  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x004cf50f:
    // 004cf50f  8b4b44                 -mov ecx, dword ptr [ebx + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */);
    // 004cf512  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004cf514  8b533c                 -mov edx, dword ptr [ebx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */);
    // 004cf517  894b44                 -mov dword ptr [ebx + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(68) /* 0x44 */) = cpu.ecx;
    // 004cf51a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cf51c  8b4334                 -mov eax, dword ptr [ebx + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */);
    // 004cf51f  897b3c                 -mov dword ptr [ebx + 0x3c], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(60) /* 0x3c */) = cpu.edi;
    // 004cf522  39c2                   +cmp edx, eax
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
    // 004cf524  7d0b                   -jge 0x4cf531
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf531;
    }
    // 004cf526  39c7                   +cmp edi, eax
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
    // 004cf528  7c07                   -jl 0x4cf531
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cf531;
    }
    // 004cf52a  c7433800000000         -mov dword ptr [ebx + 0x38], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
L_0x004cf531:
    // 004cf531  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf534  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf535  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf53b  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf53f  7518                   -jne 0x4cf559
    if (!cpu.flags.zf)
    {
        goto L_0x004cf559;
    }
    // 004cf541  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf544  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004cf546  3b8220010000           +cmp eax, dword ptr [edx + 0x120]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(288) /* 0x120 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf54c  0f8501ffffff           -jne 0x4cf453
    if (!cpu.flags.zf)
    {
        goto L_0x004cf453;
    }
    // 004cf552  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004cf557  eb02                   -jmp 0x4cf55b
    goto L_0x004cf55b;
L_0x004cf559:
    // 004cf559  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cf55b:
    // 004cf55b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cf55d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf55e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf55f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf561  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf562  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf563  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4cf570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf570  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf571  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf573  8b8368010000           -mov eax, dword ptr [ebx + 0x168]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(360) /* 0x168 */);
    // 004cf579  e882d00200             -call 0x4fc600
    cpu.esp -= 4;
    sub_4fc600(app, cpu);
    if (cpu.terminate) return;
    // 004cf57e  898360010000           -mov dword ptr [ebx + 0x160], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(352) /* 0x160 */) = cpu.eax;
    // 004cf584  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf586  740a                   -je 0x4cf592
    if (cpu.flags.zf)
    {
        goto L_0x004cf592;
    }
    // 004cf588  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf58a  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf58d  e87e020000             -call 0x4cf810
    cpu.esp -= 4;
    sub_4cf810(app, cpu);
    if (cpu.terminate) return;
L_0x004cf592:
    // 004cf592  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf593  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4cf5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf5a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf5a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf5a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf5a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf5a5  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004cf5a7  8b8368010000           -mov eax, dword ptr [ebx + 0x168]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(360) /* 0x168 */);
    // 004cf5ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cf5b2  e849d00200             -call 0x4fc600
    cpu.esp -= 4;
    sub_4fc600(app, cpu);
    if (cpu.terminate) return;
    // 004cf5b7  8d465c                 -lea eax, [esi + 0x5c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 004cf5ba  8b5b30                 -mov ebx, dword ptr [ebx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf5bd  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004cf5bf  e89cd40200             -call 0x4fca60
    cpu.esp -= 4;
    sub_4fca60(app, cpu);
    if (cpu.terminate) return;
    // 004cf5c4  898668010000           -mov dword ptr [esi + 0x168], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(360) /* 0x168 */) = cpu.eax;
    // 004cf5ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf5cc  740a                   -je 0x4cf5d8
    if (cpu.flags.zf)
    {
        goto L_0x004cf5d8;
    }
    // 004cf5ce  ba70f54c00             -mov edx, 0x4cf570
    cpu.edx = 5043568 /*0x4cf570*/;
    // 004cf5d3  e808d30200             -call 0x4fc8e0
    cpu.esp -= 4;
    sub_4fc8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004cf5d8:
    // 004cf5d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf5d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf5da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf5db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cf5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf5e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf5e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf5e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf5e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf5e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf5e6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004cf5e8  8b7350                 -mov esi, dword ptr [ebx + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */);
    // 004cf5eb  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004cf5ee  83f901                 +cmp ecx, 1
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
    // 004cf5f1  7520                   -jne 0x4cf613
    if (!cpu.flags.zf)
    {
        goto L_0x004cf613;
    }
    // 004cf5f3  8b9364010000           -mov edx, dword ptr [ebx + 0x164]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(356) /* 0x164 */);
    // 004cf5f9  8b836c010000           -mov eax, dword ptr [ebx + 0x16c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(364) /* 0x16c */);
    // 004cf5ff  8bbe1c010000           -mov edi, dword ptr [esi + 0x11c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004cf605  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cf607  39fa                   +cmp edx, edi
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
    // 004cf609  7c04                   -jl 0x4cf60f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cf60f;
    }
    // 004cf60b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cf60d  eb20                   -jmp 0x4cf62f
    goto L_0x004cf62f;
L_0x004cf60f:
    // 004cf60f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004cf611  eb1c                   -jmp 0x4cf62f
    goto L_0x004cf62f;
L_0x004cf613:
    // 004cf613  8b8368010000           -mov eax, dword ptr [ebx + 0x168]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(360) /* 0x168 */);
    // 004cf619  e8e2cf0200             -call 0x4fc600
    cpu.esp -= 4;
    sub_4fc600(app, cpu);
    if (cpu.terminate) return;
    // 004cf61e  3b836c010000           +cmp eax, dword ptr [ebx + 0x16c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(364) /* 0x16c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf624  7d07                   -jge 0x4cf62d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf62d;
    }
    // 004cf626  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cf62b  eb02                   -jmp 0x4cf62f
    goto L_0x004cf62f;
L_0x004cf62d:
    // 004cf62d  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004cf62f:
    // 004cf62f  8b8b64010000           -mov ecx, dword ptr [ebx + 0x164]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(356) /* 0x164 */);
    // 004cf635  8b7b48                 -mov edi, dword ptr [ebx + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004cf638  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cf63a  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cf63c  898b64010000           -mov dword ptr [ebx + 0x164], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(356) /* 0x164 */) = cpu.ecx;
    // 004cf642  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf644  897b48                 -mov dword ptr [ebx + 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 004cf647  e8f4fdffff             -call 0x4cf440
    cpu.esp -= 4;
    sub_4cf440(app, cpu);
    if (cpu.terminate) return;
    // 004cf64c  837e0404               +cmp dword ptr [esi + 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf650  750f                   -jne 0x4cf661
    if (!cpu.flags.zf)
    {
        goto L_0x004cf661;
    }
    // 004cf652  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf654  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf657  e854000000             -call 0x4cf6b0
    cpu.esp -= 4;
    sub_4cf6b0(app, cpu);
    if (cpu.terminate) return;
    // 004cf65c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf65d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf65e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf65f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf660  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf661:
    // 004cf661  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004cf663  7504                   -jne 0x4cf669
    if (!cpu.flags.zf)
    {
        goto L_0x004cf669;
    }
    // 004cf665  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf667  7430                   -je 0x4cf699
    if (cpu.flags.zf)
    {
        goto L_0x004cf699;
    }
L_0x004cf669:
    // 004cf669  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf66c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf66d  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf673  837e0404               +cmp dword ptr [esi + 4], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf677  7407                   -je 0x4cf680
    if (cpu.flags.zf)
    {
        goto L_0x004cf680;
    }
    // 004cf679  c7460403000000         -mov dword ptr [esi + 4], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
L_0x004cf680:
    // 004cf680  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004cf683  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf684  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf68a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf68c  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf68f  e81c000000             -call 0x4cf6b0
    cpu.esp -= 4;
    sub_4cf6b0(app, cpu);
    if (cpu.terminate) return;
    // 004cf694  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf695  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf696  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf697  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf698  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf699:
    // 004cf699  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf69b  8b5330                 -mov edx, dword ptr [ebx + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004cf69e  e86d010000             -call 0x4cf810
    cpu.esp -= 4;
    sub_4cf810(app, cpu);
    if (cpu.terminate) return;
    // 004cf6a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf6a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf6a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf6a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf6a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cf6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf6b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf6b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf6b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf6b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf6b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf6b5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf6b7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004cf6ba  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cf6bd  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004cf6c0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf6c3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf6c4  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf6ca  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf6cd  8b4850                 -mov ecx, dword ptr [eax + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004cf6d0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cf6d2  7507                   -jne 0x4cf6db
    if (!cpu.flags.zf)
    {
        goto L_0x004cf6db;
    }
    // 004cf6d4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004cf6d9  eb28                   -jmp 0x4cf703
    goto L_0x004cf703;
L_0x004cf6db:
    // 004cf6db  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004cf6de  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004cf6e0  83ff01                 +cmp edi, 1
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
    // 004cf6e3  7504                   -jne 0x4cf6e9
    if (!cpu.flags.zf)
    {
        goto L_0x004cf6e9;
    }
    // 004cf6e5  31cb                   +xor ebx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004cf6e7  eb16                   -jmp 0x4cf6ff
    goto L_0x004cf6ff;
L_0x004cf6e9:
    // 004cf6e9  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004cf6ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf6ee  7507                   -jne 0x4cf6f7
    if (!cpu.flags.zf)
    {
        goto L_0x004cf6f7;
    }
    // 004cf6f0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004cf6f5  eb08                   -jmp 0x4cf6ff
    goto L_0x004cf6ff;
L_0x004cf6f7:
    // 004cf6f7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf6fa  31cb                   -xor ebx, ecx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004cf6fc  894250                 -mov dword ptr [edx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */) = cpu.eax;
L_0x004cf6ff:
    // 004cf6ff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cf701  740c                   -je 0x4cf70f
    if (cpu.flags.zf)
    {
        goto L_0x004cf70f;
    }
L_0x004cf703:
    // 004cf703  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf706  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004cf70d  eb16                   -jmp 0x4cf725
    goto L_0x004cf725;
L_0x004cf70f:
    // 004cf70f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf712  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004cf715  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004cf718  c7460402000000         -mov dword ptr [esi + 4], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 2 /*0x2*/;
    // 004cf71f  898624010000           -mov dword ptr [esi + 0x124], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(292) /* 0x124 */) = cpu.eax;
L_0x004cf725:
    // 004cf725  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf728  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf72b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf72c  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf732  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cf734  0f85c3000000           -jne 0x4cf7fd
    if (!cpu.flags.zf)
    {
        goto L_0x004cf7fd;
    }
    // 004cf73a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf73d  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf740  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004cf743  894248                 -mov dword ptr [edx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004cf746  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf74a  750b                   -jne 0x4cf757
    if (!cpu.flags.zf)
    {
        goto L_0x004cf757;
    }
    // 004cf74c  899a64010000           -mov dword ptr [edx + 0x164], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(356) /* 0x164 */) = cpu.ebx;
    // 004cf752  e99b000000             -jmp 0x4cf7f2
    goto L_0x004cf7f2;
L_0x004cf757:
    // 004cf757  8b861c010000           -mov eax, dword ptr [esi + 0x11c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(284) /* 0x11c */);
    // 004cf75d  898264010000           -mov dword ptr [edx + 0x164], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(356) /* 0x164 */) = cpu.eax;
    // 004cf763  8d425c                 -lea eax, [edx + 0x5c]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 004cf766  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004cf769  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004cf76c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004cf76e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004cf770  e89beb0100             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004cf775  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf777  0f8475000000           -je 0x4cf7f2
    if (cpu.flags.zf)
    {
        goto L_0x004cf7f2;
    }
    // 004cf77d  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cf780  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004cf781:
    // 004cf781  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004cf783  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004cf785  3c00                   +cmp al, 0
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
    // 004cf787  7410                   -je 0x4cf799
    if (cpu.flags.zf)
    {
        goto L_0x004cf799;
    }
    // 004cf789  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004cf78c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004cf78f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004cf792  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004cf795  3c00                   +cmp al, 0
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
    // 004cf797  75e8                   -jne 0x4cf781
    if (!cpu.flags.zf)
    {
        goto L_0x004cf781;
    }
L_0x004cf799:
    // 004cf799  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf79a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf79d  8b9860010000           -mov ebx, dword ptr [eax + 0x160]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(352) /* 0x160 */);
    // 004cf7a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cf7a5  7525                   -jne 0x4cf7cc
    if (!cpu.flags.zf)
    {
        goto L_0x004cf7cc;
    }
    // 004cf7a7  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cf7aa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cf7af  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cf7b1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004cf7b3  e8a8d20200             -call 0x4fca60
    cpu.esp -= 4;
    sub_4fca60(app, cpu);
    if (cpu.terminate) return;
    // 004cf7b8  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf7bb  898268010000           -mov dword ptr [edx + 0x168], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(360) /* 0x168 */) = cpu.eax;
    // 004cf7c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf7c3  7438                   -je 0x4cf7fd
    if (cpu.flags.zf)
    {
        goto L_0x004cf7fd;
    }
    // 004cf7c5  ba70f54c00             -mov edx, 0x4cf570
    cpu.edx = 5043568 /*0x4cf570*/;
    // 004cf7ca  eb1f                   -jmp 0x4cf7eb
    goto L_0x004cf7eb;
L_0x004cf7cc:
    // 004cf7cc  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cf7cf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf7d1  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf7d4  e8b7d20200             -call 0x4fca90
    cpu.esp -= 4;
    sub_4fca90(app, cpu);
    if (cpu.terminate) return;
    // 004cf7d9  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf7dc  898268010000           -mov dword ptr [edx + 0x168], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(360) /* 0x168 */) = cpu.eax;
    // 004cf7e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf7e4  7417                   -je 0x4cf7fd
    if (cpu.flags.zf)
    {
        goto L_0x004cf7fd;
    }
    // 004cf7e6  baa0f54c00             -mov edx, 0x4cf5a0
    cpu.edx = 5043616 /*0x4cf5a0*/;
L_0x004cf7eb:
    // 004cf7eb  e8f0d00200             -call 0x4fc8e0
    cpu.esp -= 4;
    sub_4fc8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cf7f0  eb0b                   -jmp 0x4cf7fd
    goto L_0x004cf7fd;
L_0x004cf7f2:
    // 004cf7f2  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cf7f5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf7f8  e813000000             -call 0x4cf810
    cpu.esp -= 4;
    sub_4cf810(app, cpu);
    if (cpu.terminate) return;
L_0x004cf7fd:
    // 004cf7fd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cf7ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf800  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf801  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf802  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf803  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf804  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4cf810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cf810  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cf811  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf812  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cf813  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf814  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cf815  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cf817  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cf81a  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cf81d  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
L_0x004cf820:
    // 004cf820  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf823  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf826  8b4a44                 -mov ecx, dword ptr [edx + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */);
    // 004cf829  3b4840                 +cmp ecx, dword ptr [eax + 0x40]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf82c  7424                   -je 0x4cf852
    if (cpu.flags.zf)
    {
        goto L_0x004cf852;
    }
    // 004cf82e  8b4240                 -mov eax, dword ptr [edx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004cf831  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004cf833  83fbff                 +cmp ebx, -1
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
    // 004cf836  7508                   -jne 0x4cf840
    if (!cpu.flags.zf)
    {
        goto L_0x004cf840;
    }
    // 004cf838  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004cf83b  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004cf83e  ebe0                   -jmp 0x4cf820
    goto L_0x004cf820;
L_0x004cf840:
    // 004cf840  83fbfe                 +cmp ebx, -2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf843  750d                   -jne 0x4cf852
    if (!cpu.flags.zf)
    {
        goto L_0x004cf852;
    }
    // 004cf845  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf848  01d0                   +add eax, edx
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
    // 004cf84a  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf84d  894240                 -mov dword ptr [edx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004cf850  ebce                   -jmp 0x4cf820
    goto L_0x004cf820;
L_0x004cf852:
    // 004cf852  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf855  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf858  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf859  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004cf85f:
    // 004cf85f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf862  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004cf865  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004cf868  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf86a  7430                   -je 0x4cf89c
    if (cpu.flags.zf)
    {
        goto L_0x004cf89c;
    }
    // 004cf86c  83780401               +cmp dword ptr [eax + 4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf870  742a                   -je 0x4cf89c
    if (cpu.flags.zf)
    {
        goto L_0x004cf89c;
    }
    // 004cf872  8b8024010000           -mov eax, dword ptr [eax + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 004cf878  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 004cf87b  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf87e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf881  8b5248                 -mov edx, dword ptr [edx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004cf884  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004cf887  e864f9ffff             -call 0x4cf1f0
    cpu.esp -= 4;
    sub_4cf1f0(app, cpu);
    if (cpu.terminate) return;
    // 004cf88c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cf88e  750c                   -jne 0x4cf89c
    if (!cpu.flags.zf)
    {
        goto L_0x004cf89c;
    }
    // 004cf890  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf893  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cf895  e8e6faffff             -call 0x4cf380
    cpu.esp -= 4;
    sub_4cf380(app, cpu);
    if (cpu.terminate) return;
    // 004cf89a  ebc3                   -jmp 0x4cf85f
    goto L_0x004cf85f;
L_0x004cf89c:
    // 004cf89c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf89f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cf8a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cf8a3  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cf8a9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf8ac  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf8af  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004cf8b2  8b5a48                 -mov ebx, dword ptr [edx + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004cf8b5  39d8                   +cmp eax, ebx
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
    // 004cf8b7  760a                   -jbe 0x4cf8c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004cf8c3;
    }
    // 004cf8b9  8b4240                 -mov eax, dword ptr [edx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004cf8bc  29d8                   +sub eax, ebx
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
    // 004cf8be  e97f000000             -jmp 0x4cf942
    goto L_0x004cf942;
L_0x004cf8c3:
    // 004cf8c3  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004cf8c6  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cf8c8  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cf8cb  3d00200000             +cmp eax, 0x2000
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
    // 004cf8d0  7d71                   -jge 0x4cf943
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf943;
    }
    // 004cf8d2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf8d5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004cf8d7  2b5044                 -sub edx, dword ptr [eax + 0x44]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */)));
    // 004cf8da  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf8dd  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 004cf8e0  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004cf8e3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cf8e5  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004cf8e8  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004cf8ea  39c1                   +cmp ecx, eax
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
    // 004cf8ec  7d0f                   -jge 0x4cf8fd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf8fd;
    }
    // 004cf8ee  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf8f1  c7402802000000         -mov dword ptr [eax + 0x28], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 2 /*0x2*/;
    // 004cf8f8  e934010000             -jmp 0x4cfa31
    goto L_0x004cfa31;
L_0x004cf8fd:
    // 004cf8fd  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf900  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004cf902  8b7044                 -mov esi, dword ptr [eax + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004cf905  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004cf908  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf909  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cf90b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004cf90e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cf910  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004cf912  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004cf915  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004cf917  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf918  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf91b  8b4044                 -mov eax, dword ptr [eax + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004cf91e  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 004cf924  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 004cf92b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf92e  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf931  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004cf934  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 004cf937  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cf939  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004cf93c  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 004cf93f  2b4148                 -sub eax, dword ptr [ecx + 0x48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */)));
L_0x004cf942:
    // 004cf942  48                     -dec eax
    (cpu.eax)--;
L_0x004cf943:
    // 004cf943  3d00200000             +cmp eax, 0x2000
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
    // 004cf948  7d12                   -jge 0x4cf95c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cf95c;
    }
    // 004cf94a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf94d  c7402802000000         -mov dword ptr [eax + 0x28], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 2 /*0x2*/;
    // 004cf954  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cf956  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf957  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf958  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf959  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf95a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf95b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf95c:
    // 004cf95c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf95f  8b5250                 -mov edx, dword ptr [edx + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004cf962  837a1001               +cmp dword ptr [edx + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cf966  0f857a000000           -jne 0x4cf9e6
    if (!cpu.flags.zf)
    {
        goto L_0x004cf9e6;
    }
    // 004cf96c  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf96f  8b8964010000           -mov ecx, dword ptr [ecx + 0x164]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(356) /* 0x164 */);
    // 004cf975  8b9a1c010000           -mov ebx, dword ptr [edx + 0x11c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(284) /* 0x11c */);
    // 004cf97b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cf97d  39d9                   +cmp ecx, ebx
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
    // 004cf97f  7e0f                   -jle 0x4cf990
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cf990;
    }
    // 004cf981  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf984  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004cf986  8bb164010000           -mov esi, dword ptr [ecx + 0x164]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(356) /* 0x164 */);
    // 004cf98c  29f0                   +sub eax, esi
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
    // 004cf98e  eb03                   -jmp 0x4cf993
    goto L_0x004cf993;
L_0x004cf990:
    // 004cf990  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004cf993:
    // 004cf993  89816c010000           -mov dword ptr [ecx + 0x16c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(364) /* 0x16c */) = cpu.eax;
    // 004cf999  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf99c  8bb218010000           -mov esi, dword ptr [edx + 0x118]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(280) /* 0x118 */);
    // 004cf9a2  8b886c010000           -mov ecx, dword ptr [eax + 0x16c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */);
    // 004cf9a8  8b7848                 -mov edi, dword ptr [eax + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004cf9ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cf9ac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cf9ae  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004cf9b1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004cf9b3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004cf9b5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004cf9b8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004cf9ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9bb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf9be  8bba18010000           -mov edi, dword ptr [edx + 0x118]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(280) /* 0x118 */);
    // 004cf9c4  8b806c010000           -mov eax, dword ptr [eax + 0x16c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */);
    // 004cf9ca  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf9cd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cf9cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cf9d1  89ba18010000           -mov dword ptr [edx + 0x118], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(280) /* 0x118 */) = cpu.edi;
    // 004cf9d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cf9d9  e802fcffff             -call 0x4cf5e0
    cpu.esp -= 4;
    sub_4cf5e0(app, cpu);
    if (cpu.terminate) return;
    // 004cf9de  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cf9e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9e3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cf9e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cf9e6:
    // 004cf9e6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cf9e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004cf9ea  c7806c01000000200000   -mov dword ptr [eax + 0x16c], 0x2000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */) = 8192 /*0x2000*/;
    // 004cf9f4  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cf9f7  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004cf9fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cf9fb  8b886c010000           -mov ecx, dword ptr [eax + 0x16c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(364) /* 0x16c */);
    // 004cfa01  8b9064010000           -mov edx, dword ptr [eax + 0x164]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(356) /* 0x164 */);
    // 004cfa07  8b8060010000           -mov eax, dword ptr [eax + 0x160]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(352) /* 0x160 */);
    // 004cfa0d  e89ed00200             -call 0x4fcab0
    cpu.esp -= 4;
    sub_4fcab0(app, cpu);
    if (cpu.terminate) return;
    // 004cfa12  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfa15  898268010000           -mov dword ptr [edx + 0x168], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(360) /* 0x168 */) = cpu.eax;
    // 004cfa1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfa1d  7508                   -jne 0x4cfa27
    if (!cpu.flags.zf)
    {
        goto L_0x004cfa27;
    }
    // 004cfa1f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfa21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cfa27:
    // 004cfa27  bae0f54c00             -mov edx, 0x4cf5e0
    cpu.edx = 5043680 /*0x4cf5e0*/;
    // 004cfa2c  e8afce0200             -call 0x4fc8e0
    cpu.esp -= 4;
    sub_4fc8e0(app, cpu);
    if (cpu.terminate) return;
L_0x004cfa31:
    // 004cfa31  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfa33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4cfa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfa40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfa41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfa42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfa43  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfa45  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004cfa47  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 004cfa4e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfa50  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004cfa53  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfa55  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004cfa5c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cfa5e  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004cfa61  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004cfa64  8d9670010000           -lea edx, [esi + 0x170]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(368) /* 0x170 */);
    // 004cfa6a  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004cfa6d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfa6f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004cfa71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfa74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4cfa80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfa80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfa81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cfa82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfa83  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfa85  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfa88  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004cfa8a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004cfa8c  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004cfa8f  e8acffffff             -call 0x4cfa40
    cpu.esp -= 4;
    sub_4cfa40(app, cpu);
    if (cpu.terminate) return;
    // 004cfa94  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004cfa97  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfa99  81fa00600000           +cmp edx, 0x6000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24576 /*0x6000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfa9f  7d07                   -jge 0x4cfaa8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfaa8;
    }
    // 004cfaa1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cfaa3  e9e6010000             -jmp 0x4cfc8e
    goto L_0x004cfc8e;
L_0x004cfaa8:
    // 004cfaa8  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfaab  7d0a                   -jge 0x4cfab7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfab7;
    }
    // 004cfaad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfaaf  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfab1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfab2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfab3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfab4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004cfab7:
    // 004cfab7  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfabd  7e0a                   -jle 0x4cfac9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cfac9;
    }
    // 004cfabf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfac1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfac3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfac4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfac6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004cfac9:
    // 004cfac9  83ff01                 +cmp edi, 1
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
    // 004cfacc  7c05                   -jl 0x4cfad3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cfad3;
    }
    // 004cface  83ff10                 +cmp edi, 0x10
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
    // 004cfad1  7e0a                   -jle 0x4cfadd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cfadd;
    }
L_0x004cfad3:
    // 004cfad3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfad5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfad7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfada  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004cfadd:
    // 004cfadd  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfae0  83fa01                 +cmp edx, 1
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
    // 004cfae3  7c04                   -jl 0x4cfae9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cfae9;
    }
    // 004cfae5  39d7                   +cmp edi, edx
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
    // 004cfae7  7d0a                   -jge 0x4cfaf3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfaf3;
    }
L_0x004cfae9:
    // 004cfae9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfaeb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfaed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfaee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfaef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfaf0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004cfaf3:
    // 004cfaf3  c7015354524d           -mov dword ptr [ecx], 0x4d525453
    app->getMemory<x86::reg32>(cpu.ecx) = 1297241171 /*0x4d525453*/;
    // 004cfaf9  e8e2b70100             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 004cfafe  c7412800000000         -mov dword ptr [ecx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004cfb05  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004cfb08  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004cfb0b  8d8170010000           -lea eax, [ecx + 0x170]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(368) /* 0x170 */);
    // 004cfb11  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004cfb13  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004cfb16  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004cfb1d  c7412c96000000         -mov dword ptr [ecx + 0x2c], 0x96
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 150 /*0x96*/;
    // 004cfb24  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfb26  c7413032000000         -mov dword ptr [ecx + 0x30], 0x32
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = 50 /*0x32*/;
    // 004cfb2d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004cfb30  c7413400000000         -mov dword ptr [ecx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 004cfb37  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfb39  c7413800000000         -mov dword ptr [ecx + 0x38], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 004cfb40  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004cfb43  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004cfb46  c7413c00000000         -mov dword ptr [ecx + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 004cfb4d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfb4f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004cfb51  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004cfb54  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004cfb5b  c7414c00000000         -mov dword ptr [ecx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004cfb62  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cfb64  c7415000000000         -mov dword ptr [ecx + 0x50], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = 0 /*0x0*/;
    // 004cfb6b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004cfb6e  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004cfb71  c7415400000000         -mov dword ptr [ecx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004cfb78  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfb7a  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004cfb7d  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfb80  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004cfb83  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004cfb86  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004cfb89  89710c                 -mov dword ptr [ecx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004cfb8c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfb8e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004cfb91  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004cfb94  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cfb96  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004cfb99  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004cfb9c  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004cfb9f  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 004cfba2  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004cfba5  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004cfbaa  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004cfbad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004cfbaf  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004cfbb2  8d415c                 -lea eax, [ecx + 0x5c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(92) /* 0x5c */);
    // 004cfbb5  897914                 -mov dword ptr [ecx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004cfbb8  e8830a0100             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004cfbbd  c7816001000000000000   -mov dword ptr [ecx + 0x160], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = 0 /*0x0*/;
    // 004cfbc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cfbc9:
    // 004cfbc9  39f0                   +cmp eax, esi
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
    // 004cfbcb  7d44                   -jge 0x4cfc11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfc11;
    }
    // 004cfbcd  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004cfbd4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfbd6  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004cfbd9  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfbdc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfbde  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004cfbe1  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004cfbe4  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004cfbe6  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004cfbe8  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004cfbeb  8d0cd500000000         -lea ecx, [edx*8]
    cpu.ecx = x86::reg32(cpu.edx * 8);
    // 004cfbf2  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfbf4  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004cfbf7  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004cfbfe  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfc00  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc03  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004cfc06  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004cfc09  01d1                   +add ecx, edx
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
    // 004cfc0b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cfc0c  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004cfc0f  ebb8                   -jmp 0x4cfbc9
    goto L_0x004cfbc9;
L_0x004cfc11:
    // 004cfc11  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004cfc14  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004cfc1b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfc1d  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004cfc20  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004cfc22  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc25  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004cfc28  c744c80c00000000       -mov dword ptr [eax + ecx*8 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.ecx * 8) = 0 /*0x0*/;
    // 004cfc30  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004cfc32:
    // 004cfc32  39f9                   +cmp ecx, edi
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
    // 004cfc34  7d29                   -jge 0x4cfc5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfc5f;
    }
    // 004cfc36  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc39  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004cfc40  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004cfc43  29c8                   +sub eax, ecx
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
    // 004cfc45  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
    // 004cfc4c  c744820400000000       -mov dword ptr [edx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004cfc54  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cfc55  c744820801000000       -mov dword ptr [edx + eax*4 + 8], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.eax * 4) = 1 /*0x1*/;
    // 004cfc5d  ebd3                   -jmp 0x4cfc32
    goto L_0x004cfc32;
L_0x004cfc5f:
    // 004cfc5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004cfc61:
    // 004cfc61  3b45f8                 +cmp eax, dword ptr [ebp - 8]
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
    // 004cfc64  7d22                   -jge 0x4cfc88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfc88;
    }
    // 004cfc66  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cfc68  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc6b  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004cfc6e  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004cfc71  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004cfc73  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc76  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004cfc78  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004cfc7b  c7420800000000         -mov dword ptr [edx + 8], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004cfc82  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004cfc83  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004cfc86  ebd9                   -jmp 0x4cfc61
    goto L_0x004cfc61;
L_0x004cfc88:
    // 004cfc88  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfc8b  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
L_0x004cfc8e:
    // 004cfc8e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfc90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfc91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfc92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfc93  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4cfca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfca0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfca1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cfca2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfca3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfca5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004cfca8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cfcaa  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004cfcad  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004cfcaf  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004cfcb2  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfcb5  8d55f4                 -lea edx, [ebp - 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cfcb8  e803f5ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfcbd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfcbf  0f855f000000           -jne 0x4cfd24
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd24;
    }
    // 004cfcc5  83fe01                 +cmp esi, 1
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
    // 004cfcc8  0f8c56000000           -jl 0x4cfd24
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cfd24;
    }
    // 004cfcce  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cfcd1  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004cfcd4  39d6                   +cmp esi, edx
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
    // 004cfcd6  7f4c                   -jg 0x4cfd24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004cfd24;
    }
    // 004cfcd8  7507                   -jne 0x4cfce1
    if (!cpu.flags.zf)
    {
        goto L_0x004cfce1;
    }
    // 004cfcda  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfcdd  09f8                   +or eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edi))));
    // 004cfcdf  7543                   -jne 0x4cfd24
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd24;
    }
L_0x004cfce1:
    // 004cfce1  83f901                 +cmp ecx, 1
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
    // 004cfce4  7d0a                   -jge 0x4cfcf0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfcf0;
    }
    // 004cfce6  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfce9  7405                   -je 0x4cfcf0
    if (cpu.flags.zf)
    {
        goto L_0x004cfcf0;
    }
    // 004cfceb  83f9fe                 +cmp ecx, -2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfcee  7534                   -jne 0x4cfd24
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd24;
    }
L_0x004cfcf0:
    // 004cfcf0  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cfcf3  3b481c                 +cmp ecx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfcf6  7f2c                   -jg 0x4cfd24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004cfd24;
    }
    // 004cfcf8  83782800               +cmp dword ptr [eax + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfcfc  7526                   -jne 0x4cfd24
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd24;
    }
    // 004cfcfe  8d56ff                 -lea edx, [esi - 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 004cfd01  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004cfd08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004cfd0a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004cfd11  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cfd14  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004cfd17  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfd19  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004cfd1c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfd1f  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004cfd22  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004cfd24:
    // 004cfd24  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfd26  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd29  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cfd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfd30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cfd31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfd32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cfd33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfd34  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfd36  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfd39  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cfd3b  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfd3e  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfd41  e87af4ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfd46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfd48  754f                   -jne 0x4cfd99
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd99;
    }
    // 004cfd4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cfd4c  e8cf040000             -call 0x4d0220
    cpu.esp -= 4;
    sub_4d0220(app, cpu);
    if (cpu.terminate) return;
L_0x004cfd51:
    // 004cfd51  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfd54  83782801               +cmp dword ptr [eax + 0x28], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfd58  751b                   -jne 0x4cfd75
    if (!cpu.flags.zf)
    {
        goto L_0x004cfd75;
    }
    // 004cfd5a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfd5c  e8cffb0000             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 004cfd61  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfd63  7407                   -je 0x4cfd6c
    if (cpu.flags.zf)
    {
        goto L_0x004cfd6c;
    }
    // 004cfd65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfd67  e8c4780100             -call 0x4e7630
    cpu.esp -= 4;
    sub_4e7630(app, cpu);
    if (cpu.terminate) return;
L_0x004cfd6c:
    // 004cfd6c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cfd6e  e86dfb0000             -call 0x4df8e0
    cpu.esp -= 4;
    sub_4df8e0(app, cpu);
    if (cpu.terminate) return;
    // 004cfd73  ebdc                   -jmp 0x4cfd51
    goto L_0x004cfd51;
L_0x004cfd75:
    // 004cfd75  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004cfd7b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfd7e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cfd81  e8dab50100             -call 0x4eb360
    cpu.esp -= 4;
    sub_4eb360(app, cpu);
    if (cpu.terminate) return;
    // 004cfd86  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfd89  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004cfd8e  8b8060010000           -mov eax, dword ptr [eax + 0x160]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(352) /* 0x160 */);
    // 004cfd94  e8c7d20200             -call 0x4fd060
    cpu.esp -= 4;
    sub_4fd060(app, cpu);
    if (cpu.terminate) return;
L_0x004cfd99:
    // 004cfd99  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfd9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd9e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfd9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4cfda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfda0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfda1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfda2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfda3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfda5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfda8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004cfdaa  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004cfdac  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfdaf  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdb2  e809f4ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfdb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfdb9  750c                   -jne 0x4cfdc7
    if (!cpu.flags.zf)
    {
        goto L_0x004cfdc7;
    }
    // 004cfdbb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdbe  89482c                 -mov dword ptr [eax + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004cfdc1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdc4  897030                 -mov dword ptr [eax + 0x30], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.esi;
L_0x004cfdc7:
    // 004cfdc7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfdc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfdca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfdcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfdcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4cfdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfdd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cfdd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfdd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfdd3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfdd4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfdd6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfdd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cfddb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cfddd  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfde0  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfde3  e8d8f3ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfde8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfdea  7539                   -jne 0x4cfe25
    if (!cpu.flags.zf)
    {
        goto L_0x004cfe25;
    }
    // 004cfdec  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdef  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdf2  8b5234                 -mov edx, dword ptr [edx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */);
    // 004cfdf5  897034                 -mov dword ptr [eax + 0x34], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 004cfdf8  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfdfb  8b403c                 -mov eax, dword ptr [eax + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */);
    // 004cfdfe  39d0                   +cmp eax, edx
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
    // 004cfe00  7d07                   -jge 0x4cfe09
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfe09;
    }
    // 004cfe02  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cfe07  eb02                   -jmp 0x4cfe0b
    goto L_0x004cfe0b;
L_0x004cfe09:
    // 004cfe09  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cfe0b:
    // 004cfe0b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004cfe0d  39f0                   +cmp eax, esi
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
    // 004cfe0f  7d07                   -jge 0x4cfe18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004cfe18;
    }
    // 004cfe11  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004cfe16  eb02                   -jmp 0x4cfe1a
    goto L_0x004cfe1a;
L_0x004cfe18:
    // 004cfe18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004cfe1a:
    // 004cfe1a  39d3                   +cmp ebx, edx
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
    // 004cfe1c  7407                   -je 0x4cfe25
    if (cpu.flags.zf)
    {
        goto L_0x004cfe25;
    }
    // 004cfe1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cfe20  e80b000000             -call 0x4cfe30
    cpu.esp -= 4;
    sub_4cfe30(app, cpu);
    if (cpu.terminate) return;
L_0x004cfe25:
    // 004cfe25  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfe27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe2a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4cfe30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfe30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cfe31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfe32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfe33  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfe35  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfe38  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004cfe3a  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfe3d  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfe40  e87bf3ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfe45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfe47  7521                   -jne 0x4cfe6a
    if (!cpu.flags.zf)
    {
        goto L_0x004cfe6a;
    }
    // 004cfe49  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfe4c  894838                 -mov dword ptr [eax + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = cpu.ecx;
    // 004cfe4f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004cfe51  7417                   -je 0x4cfe6a
    if (cpu.flags.zf)
    {
        goto L_0x004cfe6a;
    }
    // 004cfe53  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfe56  83782801               +cmp dword ptr [eax + 0x28], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfe5a  750e                   -jne 0x4cfe6a
    if (!cpu.flags.zf)
    {
        goto L_0x004cfe6a;
    }
    // 004cfe5c  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004cfe5f  8b8068010000           -mov eax, dword ptr [eax + 0x168]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(360) /* 0x168 */);
    // 004cfe65  e846cb0200             -call 0x4fc9b0
    cpu.esp -= 4;
    sub_4fc9b0(app, cpu);
    if (cpu.terminate) return;
L_0x004cfe6a:
    // 004cfe6a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfe6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4cfe70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfe70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cfe71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cfe72  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfe73  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfe75  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfe78  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004cfe7a  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfe7d  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfe80  e83bf3ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfe85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfe87  7404                   -je 0x4cfe8d
    if (cpu.flags.zf)
    {
        goto L_0x004cfe8d;
    }
    // 004cfe89  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cfe8b  eb25                   -jmp 0x4cfeb2
    goto L_0x004cfeb2;
L_0x004cfe8d:
    // 004cfe8d  83f901                 +cmp ecx, 1
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
    // 004cfe90  7c08                   -jl 0x4cfe9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004cfe9a;
    }
    // 004cfe92  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfe95  3b481c                 +cmp ecx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cfe98  7e08                   -jle 0x4cfea2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004cfea2;
    }
L_0x004cfe9a:
    // 004cfe9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004cfe9c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfe9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfe9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfea0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfea1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cfea2:
    // 004cfea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004cfea4  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfea7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004cfeaa  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004cfead  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004cfeb0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004cfeb2:
    // 004cfeb2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfeb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfeb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfeb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfeb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4cfec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004cfec1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cfec2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfec3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfec5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cfec8  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfecb  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cfece  e8edf2ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cfed3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cfed5  7404                   -je 0x4cfedb
    if (cpu.flags.zf)
    {
        goto L_0x004cfedb;
    }
    // 004cfed7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cfed9  eb06                   -jmp 0x4cfee1
    goto L_0x004cfee1;
L_0x004cfedb:
    // 004cfedb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cfede  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004cfee1:
    // 004cfee1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cfee3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfee4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfee5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cfee6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4cfef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cfef0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cfef1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cfef2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cfef3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cfef5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004cfef8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004cfefa  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004cfefd  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004cfeff  8d5df4                 -lea ebx, [ebp - 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004cff02  8d55f0                 -lea edx, [ebp - 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff05  e8b6f2ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cff0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cff0c  7407                   -je 0x4cff15
    if (cpu.flags.zf)
    {
        goto L_0x004cff15;
    }
    // 004cff0e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cff10  e993000000             -jmp 0x4cffa8
    goto L_0x004cffa8;
L_0x004cff15:
    // 004cff15  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff18  e863f3ffff             -call 0x4cf280
    cpu.esp -= 4;
    sub_4cf280(app, cpu);
    if (cpu.terminate) return;
    // 004cff1d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004cff1f  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004cff22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cff24  7506                   -jne 0x4cff2c
    if (!cpu.flags.zf)
    {
        goto L_0x004cff2c;
    }
    // 004cff26  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cff28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cff29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cff2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cff2b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cff2c:
    // 004cff2c  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004cff2f  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 004cff34  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004cff36  c740fc00000000         -mov dword ptr [eax - 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = 0 /*0x0*/;
    // 004cff3d  e8ee0e0100             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 004cff42  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cff45  89b920010000           -mov dword ptr [ecx + 0x120], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(288) /* 0x120 */) = cpu.edi;
    // 004cff4b  89811c010000           -mov dword ptr [ecx + 0x11c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(284) /* 0x11c */) = cpu.eax;
    // 004cff51  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004cff53  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff56  e895f3ffff             -call 0x4cf2f0
    cpu.esp -= 4;
    sub_4cf2f0(app, cpu);
    if (cpu.terminate) return;
    // 004cff5b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff5e  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cff61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004cff62  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cff68  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff6b  8b5b28                 -mov ebx, dword ptr [ebx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004cff6e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cff70  750a                   -jne 0x4cff7c
    if (!cpu.flags.zf)
    {
        goto L_0x004cff7c;
    }
    // 004cff72  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff75  c7402801000000         -mov dword ptr [eax + 0x28], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
L_0x004cff7c:
    // 004cff7c  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff7f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cff82  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004cff83  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004cff89  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004cff8b  7516                   -jne 0x4cffa3
    if (!cpu.flags.zf)
    {
        goto L_0x004cffa3;
    }
    // 004cff8d  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004cff90  83783800               +cmp dword ptr [eax + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cff94  7405                   -je 0x4cff9b
    if (cpu.flags.zf)
    {
        goto L_0x004cff9b;
    }
    // 004cff96  8b5030                 -mov edx, dword ptr [eax + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004cff99  eb03                   -jmp 0x4cff9e
    goto L_0x004cff9e;
L_0x004cff9b:
    // 004cff9b  8b502c                 -mov edx, dword ptr [eax + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004cff9e:
    // 004cff9e  e80df7ffff             -call 0x4cf6b0
    cpu.esp -= 4;
    sub_4cf6b0(app, cpu);
    if (cpu.terminate) return;
L_0x004cffa3:
    // 004cffa3  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cffa6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004cffa8:
    // 004cffa8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cffaa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4cffb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004cffb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004cffb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004cffb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004cffb3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004cffb5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004cffb8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004cffba  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004cffbc  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004cffbf  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cffc2  e8f9f1ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004cffc7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cffc9  7407                   -je 0x4cffd2
    if (cpu.flags.zf)
    {
        goto L_0x004cffd2;
    }
    // 004cffcb  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004cffcd  e988000000             -jmp 0x4d005a
    goto L_0x004d005a;
L_0x004cffd2:
    // 004cffd2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004cffd5  e8a6f2ffff             -call 0x4cf280
    cpu.esp -= 4;
    sub_4cf280(app, cpu);
    if (cpu.terminate) return;
    // 004cffda  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004cffdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004cffde  7506                   -jne 0x4cffe6
    if (!cpu.flags.zf)
    {
        goto L_0x004cffe6;
    }
    // 004cffe0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004cffe2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffe3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffe4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004cffe5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004cffe6:
    // 004cffe6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004cffe8  7512                   -jne 0x4cfffc
    if (!cpu.flags.zf)
    {
        goto L_0x004cfffc;
    }
    // 004cffea  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004cffec:
    // 004cffec  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004cffee  7409                   -je 0x4cfff9
    if (cpu.flags.zf)
    {
        goto L_0x004cfff9;
    }
    // 004cfff0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004cfff3  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004cfff5  01d0                   +add eax, edx
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
    // 004cfff7  ebf3                   -jmp 0x4cffec
    goto L_0x004cffec;
L_0x004cfff9:
    // 004cfff9  037004                 -add esi, dword ptr [eax + 4]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
L_0x004cfffc:
    // 004cfffc  c7431001000000         -mov dword ptr [ebx + 0x10], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004d0003  89bb18010000           -mov dword ptr [ebx + 0x118], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(280) /* 0x118 */) = cpu.edi;
    // 004d0009  89b31c010000           -mov dword ptr [ebx + 0x11c], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(284) /* 0x11c */) = cpu.esi;
    // 004d000f  898b20010000           -mov dword ptr [ebx + 0x120], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(288) /* 0x120 */) = cpu.ecx;
    // 004d0015  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004d0017  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d001a  e8d1f2ffff             -call 0x4cf2f0
    cpu.esp -= 4;
    sub_4cf2f0(app, cpu);
    if (cpu.terminate) return;
    // 004d001f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0022  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0025  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d0026  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d002c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d002f  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004d0032  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004d0034  7507                   -jne 0x4d003d
    if (!cpu.flags.zf)
    {
        goto L_0x004d003d;
    }
    // 004d0036  c7402801000000         -mov dword ptr [eax + 0x28], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
L_0x004d003d:
    // 004d003d  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0040  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004d0044  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d004a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004d004c  750a                   -jne 0x4d0058
    if (!cpu.flags.zf)
    {
        goto L_0x004d0058;
    }
    // 004d004e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0051  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004d0053  e858f6ffff             -call 0x4cf6b0
    cpu.esp -= 4;
    sub_4cf6b0(app, cpu);
    if (cpu.terminate) return;
L_0x004d0058:
    // 004d0058  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
L_0x004d005a:
    // 004d005a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004d005c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d005d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d005e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d005f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4d0060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004d0060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004d0061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d0062  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004d0063  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004d0064  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004d0065  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004d0067  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004d006a  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 004d006d  8d5de8                 -lea ebx, [ebp - 0x18]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d0070  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d0073  e848f1ffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004d0078  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d007a  0f8593010000           -jne 0x4d0213
    if (!cpu.flags.zf)
    {
        goto L_0x004d0213;
    }
    // 004d0080  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d0083  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d0087  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d008d  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004d0090  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d0093  e8a8f2ffff             -call 0x4cf340
    cpu.esp -= 4;
    sub_4cf340(app, cpu);
    if (cpu.terminate) return;
    // 004d0098  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004d009a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d009c  7408                   -je 0x4d00a6
    if (cpu.flags.zf)
    {
        goto L_0x004d00a6;
    }
    // 004d009e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d00a1  83f904                 +cmp ecx, 4
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
    // 004d00a4  7507                   -jne 0x4d00ad
    if (!cpu.flags.zf)
    {
        goto L_0x004d00ad;
    }
L_0x004d00a6:
    // 004d00a6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004d00ab  eb53                   -jmp 0x4d0100
    goto L_0x004d0100;
L_0x004d00ad:
    // 004d00ad  83f901                 +cmp ecx, 1
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
    // 004d00b0  750e                   -jne 0x4d00c0
    if (!cpu.flags.zf)
    {
        goto L_0x004d00c0;
    }
    // 004d00b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004d00b4  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d00b7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004d00b9  e8c2f2ffff             -call 0x4cf380
    cpu.esp -= 4;
    sub_4cf380(app, cpu);
    if (cpu.terminate) return;
    // 004d00be  eb40                   -jmp 0x4d0100
    goto L_0x004d0100;
L_0x004d00c0:
    // 004d00c0  c7400404000000         -mov dword ptr [eax + 4], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4 /*0x4*/;
    // 004d00c7  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d00ca  8b5240                 -mov edx, dword ptr [edx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004d00cd  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004d00d0  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d00d3  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d00d6  7505                   -jne 0x4d00dd
    if (!cpu.flags.zf)
    {
        goto L_0x004d00dd;
    }
    // 004d00d8  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004d00db  eb06                   -jmp 0x4d00e3
    goto L_0x004d00e3;
L_0x004d00dd:
    // 004d00dd  8bb024010000           -mov esi, dword ptr [eax + 0x124]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(292) /* 0x124 */);
L_0x004d00e3:
    // 004d00e3  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004d00e6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004d00e8  7406                   -je 0x4d00f0
    if (cpu.flags.zf)
    {
        goto L_0x004d00f0;
    }
    // 004d00ea  837f0401               +cmp dword ptr [edi + 4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d00ee  7508                   -jne 0x4d00f8
    if (!cpu.flags.zf)
    {
        goto L_0x004d00f8;
    }
L_0x004d00f0:
    // 004d00f0  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d00f3  8b7844                 -mov edi, dword ptr [eax + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 004d00f6  eb06                   -jmp 0x4d00fe
    goto L_0x004d00fe;
L_0x004d00f8:
    // 004d00f8  8bbf24010000           -mov edi, dword ptr [edi + 0x124]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(292) /* 0x124 */);
L_0x004d00fe:
    // 004d00fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004d0100:
    // 004d0100  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d0103  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0106  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d0107  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d010d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004d010f  0f85fe000000           -jne 0x4d0213
    if (!cpu.flags.zf)
    {
        goto L_0x004d0213;
    }
    // 004d0115  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
L_0x004d0118:
    // 004d0118  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d011b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d011e  3b501c                 +cmp edx, dword ptr [eax + 0x1c]
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
    // 004d0121  0f8dec000000           -jge 0x4d0213
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004d0213;
    }
    // 004d0127  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004d012a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004d012d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004d012f  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004d0132  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004d0136  0f8ecf000000           -jle 0x4d020b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004d020b;
    }
    // 004d013c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004d013e  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004d0141  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004d0144  e8a7f0ffff             -call 0x4cf1f0
    cpu.esp -= 4;
    sub_4cf1f0(app, cpu);
    if (cpu.terminate) return;
    // 004d0149  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d014b  0f847c000000           -je 0x4d01cd
    if (cpu.flags.zf)
    {
        goto L_0x004d01cd;
    }
    // 004d0151  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d0154  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0157  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004d015a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004d015c  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
L_0x004d015f:
    // 004d015f  39fb                   +cmp ebx, edi
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
    // 004d0161  0f84a4000000           -je 0x4d020b
    if (cpu.flags.zf)
    {
        goto L_0x004d020b;
    }
    // 004d0167  833bff                 +cmp dword ptr [ebx], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d016a  7508                   -jne 0x4d0174
    if (!cpu.flags.zf)
    {
        goto L_0x004d0174;
    }
    // 004d016c  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d016f  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004d0172  ebeb                   -jmp 0x4d015f
    goto L_0x004d015f;
L_0x004d0174:
    // 004d0174  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004d0177  25ffffff00             -and eax, 0xffffff
    cpu.eax &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004d017c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004d017f  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004d0182  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004d0185  25000000ff             -and eax, 0xff000000
    cpu.eax &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004d018a  39d0                   +cmp eax, edx
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
    // 004d018c  753a                   -jne 0x4d01c8
    if (!cpu.flags.zf)
    {
        goto L_0x004d01c8;
    }
    // 004d018e  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d0191  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0194  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d0195  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d019b  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d019e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d01a1  295008                 -sub dword ptr [eax + 8], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004d01a4  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d01a7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d01aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d01ab  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d01b1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d01b4  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004d01b7  e864f0ffff             -call 0x4cf220
    cpu.esp -= 4;
    sub_4cf220(app, cpu);
    if (cpu.terminate) return;
    // 004d01bc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d01bf  c703feffffff           -mov dword ptr [ebx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967294 /*0xfffffffe*/;
    // 004d01c5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004d01c8:
    // 004d01c8  035dfc                 +add ebx, dword ptr [ebp - 4]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004d01cb  eb92                   -jmp 0x4d015f
    goto L_0x004d015f;
L_0x004d01cd:
    // 004d01cd  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d01d0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004d01d2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004d01d5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004d01d7  e814f0ffff             -call 0x4cf1f0
    cpu.esp -= 4;
    sub_4cf1f0(app, cpu);
    if (cpu.terminate) return;
    // 004d01dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d01de  742b                   -je 0x4d020b
    if (cpu.flags.zf)
    {
        goto L_0x004d020b;
    }
L_0x004d01e0:
    // 004d01e0  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d01e3  e818010000             -call 0x4d0300
    cpu.esp -= 4;
    sub_4d0300(app, cpu);
    if (cpu.terminate) return;
    // 004d01e8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004d01ea  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d01ed  e8ce010000             -call 0x4d03c0
    cpu.esp -= 4;
    sub_4d03c0(app, cpu);
    if (cpu.terminate) return;
    // 004d01f2  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004d01f5  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004d01f9  7e10                   -jle 0x4d020b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004d020b;
    }
    // 004d01fb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004d01fd  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004d0200  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004d0202  e8e9efffff             -call 0x4cf1f0
    cpu.esp -= 4;
    sub_4cf1f0(app, cpu);
    if (cpu.terminate) return;
    // 004d0207  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d0209  75d5                   -jne 0x4d01e0
    if (!cpu.flags.zf)
    {
        goto L_0x004d01e0;
    }
L_0x004d020b:
    // 004d020b  ff45f8                 +inc dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004d020e  e905ffffff             -jmp 0x4d0118
    goto L_0x004d0118;
L_0x004d0213:
    // 004d0213  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004d0215  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0216  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0217  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0218  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0219  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d021a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4d0220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004d0220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004d0221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d0222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d0223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004d0224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004d0225  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004d0227  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004d022a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004d022c  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d022f  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0232  e889efffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004d0237  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d0239  0f85ae000000           -jne 0x4d02ed
    if (!cpu.flags.zf)
    {
        goto L_0x004d02ed;
    }
    // 004d023f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0242  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004d0245  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d0247  0f84a0000000           -je 0x4d02ed
    if (cpu.flags.zf)
    {
        goto L_0x004d02ed;
    }
L_0x004d024d:
    // 004d024d  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0250  83fa01                 +cmp edx, 1
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
    // 004d0253  7405                   -je 0x4d025a
    if (cpu.flags.zf)
    {
        goto L_0x004d025a;
    }
    // 004d0255  83fa02                 +cmp edx, 2
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
    // 004d0258  7511                   -jne 0x4d026b
    if (!cpu.flags.zf)
    {
        goto L_0x004d026b;
    }
L_0x004d025a:
    // 004d025a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004d025c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004d025e  e8fdfdffff             -call 0x4d0060
    cpu.esp -= 4;
    sub_4d0060(app, cpu);
    if (cpu.terminate) return;
    // 004d0263  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0266  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004d0269  ebe2                   -jmp 0x4d024d
    goto L_0x004d024d;
L_0x004d026b:
    // 004d026b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d026e  8b7050                 -mov esi, dword ptr [eax + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 004d0271  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004d0274  39f2                   +cmp edx, esi
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
    // 004d0276  7407                   -je 0x4d027f
    if (cpu.flags.zf)
    {
        goto L_0x004d027f;
    }
    // 004d0278  e803f1ffff             -call 0x4cf380
    cpu.esp -= 4;
    sub_4cf380(app, cpu);
    if (cpu.terminate) return;
    // 004d027d  ebec                   -jmp 0x4d026b
    goto L_0x004d026b;
L_0x004d027f:
    // 004d027f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004d0281  c7460404000000         -mov dword ptr [esi + 4], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 4 /*0x4*/;
    // 004d0288  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004d028a:
    // 004d028a  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d028d  3b421c                 +cmp eax, dword ptr [edx + 0x1c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d0290  7d16                   -jge 0x4d02a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004d02a8;
    }
    // 004d0292  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0295  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004d0297  8b4918                 -mov ecx, dword ptr [ecx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004d029a  c1e204                 +shl edx, 4
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
    // 004d029d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004d029e  c744110800000000       -mov dword ptr [ecx + edx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.edx * 1) = 0 /*0x0*/;
    // 004d02a6  ebe2                   -jmp 0x4d028a
    goto L_0x004d028a;
L_0x004d02a8:
    // 004d02a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004d02aa  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 004d02ad  e86eefffff             -call 0x4cf220
    cpu.esp -= 4;
    sub_4cf220(app, cpu);
    if (cpu.terminate) return;
    // 004d02b2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d02b5  8b4040                 -mov eax, dword ptr [eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
L_0x004d02b8:
    // 004d02b8  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d02bb  3b4244                 +cmp eax, dword ptr [edx + 0x44]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d02be  7420                   -je 0x4d02e0
    if (cpu.flags.zf)
    {
        goto L_0x004d02e0;
    }
    // 004d02c0  8338ff                 +cmp dword ptr [eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d02c3  7505                   -jne 0x4d02ca
    if (!cpu.flags.zf)
    {
        goto L_0x004d02ca;
    }
    // 004d02c5  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004d02c8  ebee                   -jmp 0x4d02b8
    goto L_0x004d02b8;
L_0x004d02ca:
    // 004d02ca  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d02cd  c700feffffff           -mov dword ptr [eax], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.eax) = 4294967294 /*0xfffffffe*/;
    // 004d02d3  81e1ffffff00           -and ecx, 0xffffff
    cpu.ecx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004d02d9  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004d02dc  01c8                   +add eax, ecx
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
    // 004d02de  ebd8                   -jmp 0x4d02b8
    goto L_0x004d02b8;
L_0x004d02e0:
    // 004d02e0  837a2802               +cmp dword ptr [edx + 0x28], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d02e4  7507                   -jne 0x4d02ed
    if (!cpu.flags.zf)
    {
        goto L_0x004d02ed;
    }
    // 004d02e6  c7422800000000         -mov dword ptr [edx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x004d02ed:
    // 004d02ed  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004d02ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d02f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d02f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d02f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d02f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d02f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4d0300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004d0300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004d0301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d0302  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d0303  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004d0304  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004d0305  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004d0306  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004d0308  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004d030b  8d5dfc                 -lea ebx, [ebp - 4]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d030e  8d55f8                 -lea edx, [ebp - 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0311  e8aaeeffff             -call 0x4cf1c0
    cpu.esp -= 4;
    sub_4cf1c0(app, cpu);
    if (cpu.terminate) return;
    // 004d0316  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004d0318  7407                   -je 0x4d0321
    if (cpu.flags.zf)
    {
        goto L_0x004d0321;
    }
    // 004d031a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004d031c  e987000000             -jmp 0x4d03a8
    goto L_0x004d03a8;
L_0x004d0321:
    // 004d0321  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d0324  83780800               +cmp dword ptr [eax + 8], 0
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
    // 004d0328  750b                   -jne 0x4d0335
    if (!cpu.flags.zf)
    {
        goto L_0x004d0335;
    }
    // 004d032a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004d032c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004d032e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d032f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0330  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0331  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0332  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0333  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d0334  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004d0335:
    // 004d0335  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004d0338  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004d033b  81e6ffffff00           -and esi, 0xffffff
    cpu.esi &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004d0341  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004d0344  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d0347  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d034a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004d034b  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d0351  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d0354  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004d0357  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004d0359  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004d035c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d035f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004d0363  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004d0369  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004d036b  7e39                   -jle 0x4d03a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004d03a6;
    }
    // 004d036d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d0370  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0373  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 004d0376  8d0433                 -lea eax, [ebx + esi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x004d0379:
    // 004d0379  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d037c  81e6000000ff           -and esi, 0xff000000
    cpu.esi &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004d0382  39d6                   +cmp esi, edx
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
    // 004d0384  741a                   -je 0x4d03a0
    if (cpu.flags.zf)
    {
        goto L_0x004d03a0;
    }
    // 004d0386  8338ff                 +cmp dword ptr [eax], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004d0389  7508                   -jne 0x4d0393
    if (!cpu.flags.zf)
    {
        goto L_0x004d0393;
    }
    // 004d038b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004d038e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004d0391  ebe6                   -jmp 0x4d0379
    goto L_0x004d0379;
L_0x004d0393:
    // 004d0393  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004d0396  81e6ffffff00           -and esi, 0xffffff
    cpu.esi &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 004d039c  01f0                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004d039e  ebd9                   -jmp 0x4d0379
    goto L_0x004d0379;
L_0x004d03a0:
    // 004d03a0  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004d03a3  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004d03a6:
    // 004d03a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004d03a8:
    // 004d03a8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004d03aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004d03b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
