#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_5323f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005323f1  833db0d3560000         +cmp dword ptr [0x56d3b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690288) /* 0x56d3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005323f8  751f                   -jne 0x532419
    if (!cpu.flags.zf)
    {
        goto L_0x00532419;
    }
    // 005323fa  68b0d35600             -push 0x56d3b0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690288 /*0x56d3b0*/;
    cpu.esp -= 4;
    // 005323ff  68d8c55600             -push 0x56c5d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686744 /*0x56c5d8*/;
    cpu.esp -= 4;
    // 00532404  e80fcfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532409  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053240b  740c                   -je 0x532419
    if (cpu.flags.zf)
    {
        goto L_0x00532419;
    }
    // 0053240d  c705b0d35600ffffffff   -mov dword ptr [0x56d3b0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690288) /* 0x56d3b0 */) = 4294967295 /*0xffffffff*/;
    // 00532417  eb20                   -jmp 0x532439
    goto L_0x00532439;
L_0x00532419:
    // 00532419  833db0d35600ff         +cmp dword ptr [0x56d3b0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690288) /* 0x56d3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532420  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532425  7412                   -je 0x532439
    if (cpu.flags.zf)
    {
        goto L_0x00532439;
    }
    // 00532427  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053242b  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053242f  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532433  ff15b0d35600           -call dword ptr [0x56d3b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690288) /* 0x56d3b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532439:
    // 00532439  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53243c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053243c  833db4d3560000         +cmp dword ptr [0x56d3b4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690292) /* 0x56d3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532443  751f                   -jne 0x532464
    if (!cpu.flags.zf)
    {
        goto L_0x00532464;
    }
    // 00532445  68b4d35600             -push 0x56d3b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690292 /*0x56d3b4*/;
    cpu.esp -= 4;
    // 0053244a  68ecc55600             -push 0x56c5ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686764 /*0x56c5ec*/;
    cpu.esp -= 4;
    // 0053244f  e8c4ceffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532456  740c                   -je 0x532464
    if (cpu.flags.zf)
    {
        goto L_0x00532464;
    }
    // 00532458  c705b4d35600ffffffff   -mov dword ptr [0x56d3b4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690292) /* 0x56d3b4 */) = 4294967295 /*0xffffffff*/;
    // 00532462  eb20                   -jmp 0x532484
    goto L_0x00532484;
L_0x00532464:
    // 00532464  833db4d35600ff         +cmp dword ptr [0x56d3b4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690292) /* 0x56d3b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053246b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532470  7412                   -je 0x532484
    if (cpu.flags.zf)
    {
        goto L_0x00532484;
    }
    // 00532472  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532476  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053247a  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053247e  ff15b4d35600           -call dword ptr [0x56d3b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690292) /* 0x56d3b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532484:
    // 00532484  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532487(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532487  833db8d3560000         +cmp dword ptr [0x56d3b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690296) /* 0x56d3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053248e  751f                   -jne 0x5324af
    if (!cpu.flags.zf)
    {
        goto L_0x005324af;
    }
    // 00532490  68b8d35600             -push 0x56d3b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690296 /*0x56d3b8*/;
    cpu.esp -= 4;
    // 00532495  6800c65600             -push 0x56c600
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686784 /*0x56c600*/;
    cpu.esp -= 4;
    // 0053249a  e879ceffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053249f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005324a1  740c                   -je 0x5324af
    if (cpu.flags.zf)
    {
        goto L_0x005324af;
    }
    // 005324a3  c705b8d35600ffffffff   -mov dword ptr [0x56d3b8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690296) /* 0x56d3b8 */) = 4294967295 /*0xffffffff*/;
    // 005324ad  eb20                   -jmp 0x5324cf
    goto L_0x005324cf;
L_0x005324af:
    // 005324af  833db8d35600ff         +cmp dword ptr [0x56d3b8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690296) /* 0x56d3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005324b6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005324bb  7412                   -je 0x5324cf
    if (cpu.flags.zf)
    {
        goto L_0x005324cf;
    }
    // 005324bd  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005324c1  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005324c5  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005324c9  ff15b8d35600           -call dword ptr [0x56d3b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690296) /* 0x56d3b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005324cf:
    // 005324cf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5324d2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005324d2  833dbcd3560000         +cmp dword ptr [0x56d3bc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690300) /* 0x56d3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005324d9  751f                   -jne 0x5324fa
    if (!cpu.flags.zf)
    {
        goto L_0x005324fa;
    }
    // 005324db  68bcd35600             -push 0x56d3bc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690300 /*0x56d3bc*/;
    cpu.esp -= 4;
    // 005324e0  6814c65600             -push 0x56c614
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686804 /*0x56c614*/;
    cpu.esp -= 4;
    // 005324e5  e82eceffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005324ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005324ec  740c                   -je 0x5324fa
    if (cpu.flags.zf)
    {
        goto L_0x005324fa;
    }
    // 005324ee  c705bcd35600ffffffff   -mov dword ptr [0x56d3bc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690300) /* 0x56d3bc */) = 4294967295 /*0xffffffff*/;
    // 005324f8  eb18                   -jmp 0x532512
    goto L_0x00532512;
L_0x005324fa:
    // 005324fa  833dbcd35600ff         +cmp dword ptr [0x56d3bc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690300) /* 0x56d3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532501  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532506  740a                   -je 0x532512
    if (cpu.flags.zf)
    {
        goto L_0x00532512;
    }
    // 00532508  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0053250c  ff15bcd35600           -call dword ptr [0x56d3bc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690300) /* 0x56d3bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532512:
    // 00532512  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_532515(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532515  833dc0d3560000         +cmp dword ptr [0x56d3c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690304) /* 0x56d3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053251c  751f                   -jne 0x53253d
    if (!cpu.flags.zf)
    {
        goto L_0x0053253d;
    }
    // 0053251e  68c0d35600             -push 0x56d3c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690304 /*0x56d3c0*/;
    cpu.esp -= 4;
    // 00532523  6824c65600             -push 0x56c624
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686820 /*0x56c624*/;
    cpu.esp -= 4;
    // 00532528  e8ebcdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053252d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053252f  740c                   -je 0x53253d
    if (cpu.flags.zf)
    {
        goto L_0x0053253d;
    }
    // 00532531  c705c0d35600ffffffff   -mov dword ptr [0x56d3c0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690304) /* 0x56d3c0 */) = 4294967295 /*0xffffffff*/;
    // 0053253b  eb1c                   -jmp 0x532559
    goto L_0x00532559;
L_0x0053253d:
    // 0053253d  833dc0d35600ff         +cmp dword ptr [0x56d3c0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690304) /* 0x56d3c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532544  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532549  740e                   -je 0x532559
    if (cpu.flags.zf)
    {
        goto L_0x00532559;
    }
    // 0053254b  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053254f  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532553  ff15c0d35600           -call dword ptr [0x56d3c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690304) /* 0x56d3c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532559:
    // 00532559  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53255c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053255c  833dc4d3560000         +cmp dword ptr [0x56d3c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690308) /* 0x56d3c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532563  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532564  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532566  751f                   -jne 0x532587
    if (!cpu.flags.zf)
    {
        goto L_0x00532587;
    }
    // 00532568  68c4d35600             -push 0x56d3c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690308 /*0x56d3c4*/;
    cpu.esp -= 4;
    // 0053256d  6834c65600             -push 0x56c634
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686836 /*0x56c634*/;
    cpu.esp -= 4;
    // 00532572  e8a1cdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532577  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532579  740c                   -je 0x532587
    if (cpu.flags.zf)
    {
        goto L_0x00532587;
    }
    // 0053257b  c705c4d35600ffffffff   -mov dword ptr [0x56d3c4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690308) /* 0x56d3c4 */) = 4294967295 /*0xffffffff*/;
    // 00532585  eb29                   -jmp 0x5325b0
    goto L_0x005325b0;
L_0x00532587:
    // 00532587  833dc4d35600ff         +cmp dword ptr [0x56d3c4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690308) /* 0x56d3c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053258e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532593  741b                   -je 0x5325b0
    if (cpu.flags.zf)
    {
        goto L_0x005325b0;
    }
    // 00532595  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00532598  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053259b  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053259e  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005325a1  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005325a4  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005325a7  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005325aa  ff15c4d35600           -call dword ptr [0x56d3c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690308) /* 0x56d3c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005325b0:
    // 005325b0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005325b1  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_5325b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005325b4  833dc8d3560000         +cmp dword ptr [0x56d3c8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690312) /* 0x56d3c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005325bb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005325bc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005325be  751f                   -jne 0x5325df
    if (!cpu.flags.zf)
    {
        goto L_0x005325df;
    }
    // 005325c0  68c8d35600             -push 0x56d3c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690312 /*0x56d3c8*/;
    cpu.esp -= 4;
    // 005325c5  684cc65600             -push 0x56c64c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686860 /*0x56c64c*/;
    cpu.esp -= 4;
    // 005325ca  e849cdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005325cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005325d1  740c                   -je 0x5325df
    if (cpu.flags.zf)
    {
        goto L_0x005325df;
    }
    // 005325d3  c705c8d35600ffffffff   -mov dword ptr [0x56d3c8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690312) /* 0x56d3c8 */) = 4294967295 /*0xffffffff*/;
    // 005325dd  eb29                   -jmp 0x532608
    goto L_0x00532608;
L_0x005325df:
    // 005325df  833dc8d35600ff         +cmp dword ptr [0x56d3c8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690312) /* 0x56d3c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005325e6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005325eb  741b                   -je 0x532608
    if (cpu.flags.zf)
    {
        goto L_0x00532608;
    }
    // 005325ed  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005325f0  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005325f3  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005325f6  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005325f9  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005325fc  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005325ff  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532602  ff15c8d35600           -call dword ptr [0x56d3c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690312) /* 0x56d3c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532608:
    // 00532608  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532609  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_53260c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053260c  833dccd3560000         +cmp dword ptr [0x56d3cc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690316) /* 0x56d3cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532613  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532614  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532616  751f                   -jne 0x532637
    if (!cpu.flags.zf)
    {
        goto L_0x00532637;
    }
    // 00532618  68ccd35600             -push 0x56d3cc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690316 /*0x56d3cc*/;
    cpu.esp -= 4;
    // 0053261d  6864c65600             -push 0x56c664
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686884 /*0x56c664*/;
    cpu.esp -= 4;
    // 00532622  e8f1ccffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532627  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532629  740c                   -je 0x532637
    if (cpu.flags.zf)
    {
        goto L_0x00532637;
    }
    // 0053262b  c705ccd35600ffffffff   -mov dword ptr [0x56d3cc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690316) /* 0x56d3cc */) = 4294967295 /*0xffffffff*/;
    // 00532635  eb29                   -jmp 0x532660
    goto L_0x00532660;
L_0x00532637:
    // 00532637  833dccd35600ff         +cmp dword ptr [0x56d3cc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690316) /* 0x56d3cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053263e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532643  741b                   -je 0x532660
    if (cpu.flags.zf)
    {
        goto L_0x00532660;
    }
    // 00532645  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00532648  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053264b  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053264e  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532651  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532654  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532657  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053265a  ff15ccd35600           -call dword ptr [0x56d3cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690316) /* 0x56d3cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532660:
    // 00532660  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532661  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_532664(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532664  833dd0d3560000         +cmp dword ptr [0x56d3d0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690320) /* 0x56d3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053266b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053266c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053266e  751f                   -jne 0x53268f
    if (!cpu.flags.zf)
    {
        goto L_0x0053268f;
    }
    // 00532670  68d0d35600             -push 0x56d3d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690320 /*0x56d3d0*/;
    cpu.esp -= 4;
    // 00532675  687cc65600             -push 0x56c67c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686908 /*0x56c67c*/;
    cpu.esp -= 4;
    // 0053267a  e899ccffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053267f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532681  740c                   -je 0x53268f
    if (cpu.flags.zf)
    {
        goto L_0x0053268f;
    }
    // 00532683  c705d0d35600ffffffff   -mov dword ptr [0x56d3d0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690320) /* 0x56d3d0 */) = 4294967295 /*0xffffffff*/;
    // 0053268d  eb23                   -jmp 0x5326b2
    goto L_0x005326b2;
L_0x0053268f:
    // 0053268f  833dd0d35600ff         +cmp dword ptr [0x56d3d0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690320) /* 0x56d3d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532696  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053269b  7415                   -je 0x5326b2
    if (cpu.flags.zf)
    {
        goto L_0x005326b2;
    }
    // 0053269d  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005326a0  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005326a3  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005326a6  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005326a9  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005326ac  ff15d0d35600           -call dword ptr [0x56d3d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690320) /* 0x56d3d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005326b2:
    // 005326b2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005326b3  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5326b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005326b6  833dd4d3560000         +cmp dword ptr [0x56d3d4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690324) /* 0x56d3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005326bd  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005326be  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005326c0  751f                   -jne 0x5326e1
    if (!cpu.flags.zf)
    {
        goto L_0x005326e1;
    }
    // 005326c2  68d4d35600             -push 0x56d3d4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690324 /*0x56d3d4*/;
    cpu.esp -= 4;
    // 005326c7  6890c65600             -push 0x56c690
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686928 /*0x56c690*/;
    cpu.esp -= 4;
    // 005326cc  e847ccffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005326d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005326d3  740c                   -je 0x5326e1
    if (cpu.flags.zf)
    {
        goto L_0x005326e1;
    }
    // 005326d5  c705d4d35600ffffffff   -mov dword ptr [0x56d3d4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690324) /* 0x56d3d4 */) = 4294967295 /*0xffffffff*/;
    // 005326df  eb23                   -jmp 0x532704
    goto L_0x00532704;
L_0x005326e1:
    // 005326e1  833dd4d35600ff         +cmp dword ptr [0x56d3d4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690324) /* 0x56d3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005326e8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005326ed  7415                   -je 0x532704
    if (cpu.flags.zf)
    {
        goto L_0x00532704;
    }
    // 005326ef  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005326f2  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005326f5  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005326f8  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005326fb  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005326fe  ff15d4d35600           -call dword ptr [0x56d3d4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690324) /* 0x56d3d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532704:
    // 00532704  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532705  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_532708(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532708  833dd8d3560000         +cmp dword ptr [0x56d3d8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690328) /* 0x56d3d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053270f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532710  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532712  751f                   -jne 0x532733
    if (!cpu.flags.zf)
    {
        goto L_0x00532733;
    }
    // 00532714  68d8d35600             -push 0x56d3d8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690328 /*0x56d3d8*/;
    cpu.esp -= 4;
    // 00532719  68a8c65600             -push 0x56c6a8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686952 /*0x56c6a8*/;
    cpu.esp -= 4;
    // 0053271e  e8f5cbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532723  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532725  740c                   -je 0x532733
    if (cpu.flags.zf)
    {
        goto L_0x00532733;
    }
    // 00532727  c705d8d35600ffffffff   -mov dword ptr [0x56d3d8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690328) /* 0x56d3d8 */) = 4294967295 /*0xffffffff*/;
    // 00532731  eb23                   -jmp 0x532756
    goto L_0x00532756;
L_0x00532733:
    // 00532733  833dd8d35600ff         +cmp dword ptr [0x56d3d8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690328) /* 0x56d3d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053273a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053273f  7415                   -je 0x532756
    if (cpu.flags.zf)
    {
        goto L_0x00532756;
    }
    // 00532741  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532744  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532747  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053274a  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053274d  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532750  ff15d8d35600           -call dword ptr [0x56d3d8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690328) /* 0x56d3d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532756:
    // 00532756  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532757  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_53275a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053275a  833ddcd3560000         +cmp dword ptr [0x56d3dc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690332) /* 0x56d3dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532761  751f                   -jne 0x532782
    if (!cpu.flags.zf)
    {
        goto L_0x00532782;
    }
    // 00532763  68dcd35600             -push 0x56d3dc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690332 /*0x56d3dc*/;
    cpu.esp -= 4;
    // 00532768  68c0c65600             -push 0x56c6c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686976 /*0x56c6c0*/;
    cpu.esp -= 4;
    // 0053276d  e8a6cbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532772  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532774  740c                   -je 0x532782
    if (cpu.flags.zf)
    {
        goto L_0x00532782;
    }
    // 00532776  c705dcd35600ffffffff   -mov dword ptr [0x56d3dc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690332) /* 0x56d3dc */) = 4294967295 /*0xffffffff*/;
    // 00532780  eb1c                   -jmp 0x53279e
    goto L_0x0053279e;
L_0x00532782:
    // 00532782  833ddcd35600ff         +cmp dword ptr [0x56d3dc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690332) /* 0x56d3dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532789  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053278e  740e                   -je 0x53279e
    if (cpu.flags.zf)
    {
        goto L_0x0053279e;
    }
    // 00532790  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532794  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532798  ff15dcd35600           -call dword ptr [0x56d3dc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690332) /* 0x56d3dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053279e:
    // 0053279e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5327a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005327a1  833de0d3560000         +cmp dword ptr [0x56d3e0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690336) /* 0x56d3e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005327a8  751f                   -jne 0x5327c9
    if (!cpu.flags.zf)
    {
        goto L_0x005327c9;
    }
    // 005327aa  68e0d35600             -push 0x56d3e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690336 /*0x56d3e0*/;
    cpu.esp -= 4;
    // 005327af  68d4c65600             -push 0x56c6d4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5686996 /*0x56c6d4*/;
    cpu.esp -= 4;
    // 005327b4  e85fcbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005327b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005327bb  740c                   -je 0x5327c9
    if (cpu.flags.zf)
    {
        goto L_0x005327c9;
    }
    // 005327bd  c705e0d35600ffffffff   -mov dword ptr [0x56d3e0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690336) /* 0x56d3e0 */) = 4294967295 /*0xffffffff*/;
    // 005327c7  eb18                   -jmp 0x5327e1
    goto L_0x005327e1;
L_0x005327c9:
    // 005327c9  833de0d35600ff         +cmp dword ptr [0x56d3e0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690336) /* 0x56d3e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005327d0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005327d5  740a                   -je 0x5327e1
    if (cpu.flags.zf)
    {
        goto L_0x005327e1;
    }
    // 005327d7  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 005327db  ff15e0d35600           -call dword ptr [0x56d3e0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690336) /* 0x56d3e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005327e1:
    // 005327e1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5327e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005327e4  833de4d3560000         +cmp dword ptr [0x56d3e4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690340) /* 0x56d3e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005327eb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005327ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005327ee  751f                   -jne 0x53280f
    if (!cpu.flags.zf)
    {
        goto L_0x0053280f;
    }
    // 005327f0  68e4d35600             -push 0x56d3e4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690340 /*0x56d3e4*/;
    cpu.esp -= 4;
    // 005327f5  68e0c65600             -push 0x56c6e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687008 /*0x56c6e0*/;
    cpu.esp -= 4;
    // 005327fa  e819cbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005327ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532801  740c                   -je 0x53280f
    if (cpu.flags.zf)
    {
        goto L_0x0053280f;
    }
    // 00532803  c705e4d35600ffffffff   -mov dword ptr [0x56d3e4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690340) /* 0x56d3e4 */) = 4294967295 /*0xffffffff*/;
    // 0053280d  eb20                   -jmp 0x53282f
    goto L_0x0053282f;
L_0x0053280f:
    // 0053280f  833de4d35600ff         +cmp dword ptr [0x56d3e4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690340) /* 0x56d3e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532816  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053281b  7412                   -je 0x53282f
    if (cpu.flags.zf)
    {
        goto L_0x0053282f;
    }
    // 0053281d  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532820  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532823  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532826  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532829  ff15e4d35600           -call dword ptr [0x56d3e4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690340) /* 0x56d3e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053282f:
    // 0053282f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532830  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_532833(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532833  833de8d3560000         +cmp dword ptr [0x56d3e8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690344) /* 0x56d3e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053283a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053283b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053283d  751f                   -jne 0x53285e
    if (!cpu.flags.zf)
    {
        goto L_0x0053285e;
    }
    // 0053283f  68e8d35600             -push 0x56d3e8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690344 /*0x56d3e8*/;
    cpu.esp -= 4;
    // 00532844  68ecc65600             -push 0x56c6ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687020 /*0x56c6ec*/;
    cpu.esp -= 4;
    // 00532849  e8cacaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053284e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532850  740c                   -je 0x53285e
    if (cpu.flags.zf)
    {
        goto L_0x0053285e;
    }
    // 00532852  c705e8d35600ffffffff   -mov dword ptr [0x56d3e8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690344) /* 0x56d3e8 */) = 4294967295 /*0xffffffff*/;
    // 0053285c  eb20                   -jmp 0x53287e
    goto L_0x0053287e;
L_0x0053285e:
    // 0053285e  833de8d35600ff         +cmp dword ptr [0x56d3e8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690344) /* 0x56d3e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532865  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053286a  7412                   -je 0x53287e
    if (cpu.flags.zf)
    {
        goto L_0x0053287e;
    }
    // 0053286c  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053286f  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532872  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532875  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532878  ff15e8d35600           -call dword ptr [0x56d3e8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690344) /* 0x56d3e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053287e:
    // 0053287e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053287f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_532882(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532882  833decd3560000         +cmp dword ptr [0x56d3ec], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690348) /* 0x56d3ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532889  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053288a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053288c  751f                   -jne 0x5328ad
    if (!cpu.flags.zf)
    {
        goto L_0x005328ad;
    }
    // 0053288e  68ecd35600             -push 0x56d3ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690348 /*0x56d3ec*/;
    cpu.esp -= 4;
    // 00532893  68f8c65600             -push 0x56c6f8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687032 /*0x56c6f8*/;
    cpu.esp -= 4;
    // 00532898  e87bcaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053289d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053289f  740c                   -je 0x5328ad
    if (cpu.flags.zf)
    {
        goto L_0x005328ad;
    }
    // 005328a1  c705ecd35600ffffffff   -mov dword ptr [0x56d3ec], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690348) /* 0x56d3ec */) = 4294967295 /*0xffffffff*/;
    // 005328ab  eb20                   -jmp 0x5328cd
    goto L_0x005328cd;
L_0x005328ad:
    // 005328ad  833decd35600ff         +cmp dword ptr [0x56d3ec], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690348) /* 0x56d3ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005328b4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005328b9  7412                   -je 0x5328cd
    if (cpu.flags.zf)
    {
        goto L_0x005328cd;
    }
    // 005328bb  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005328be  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005328c1  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005328c4  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005328c7  ff15ecd35600           -call dword ptr [0x56d3ec]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690348) /* 0x56d3ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005328cd:
    // 005328cd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005328ce  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5328d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005328d1  833df0d3560000         +cmp dword ptr [0x56d3f0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690352) /* 0x56d3f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005328d8  751f                   -jne 0x5328f9
    if (!cpu.flags.zf)
    {
        goto L_0x005328f9;
    }
    // 005328da  68f0d35600             -push 0x56d3f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690352 /*0x56d3f0*/;
    cpu.esp -= 4;
    // 005328df  6804c75600             -push 0x56c704
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687044 /*0x56c704*/;
    cpu.esp -= 4;
    // 005328e4  e82fcaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005328e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005328eb  740c                   -je 0x5328f9
    if (cpu.flags.zf)
    {
        goto L_0x005328f9;
    }
    // 005328ed  c705f0d35600ffffffff   -mov dword ptr [0x56d3f0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690352) /* 0x56d3f0 */) = 4294967295 /*0xffffffff*/;
    // 005328f7  eb18                   -jmp 0x532911
    goto L_0x00532911;
L_0x005328f9:
    // 005328f9  833df0d35600ff         +cmp dword ptr [0x56d3f0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690352) /* 0x56d3f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532900  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532905  740a                   -je 0x532911
    if (cpu.flags.zf)
    {
        goto L_0x00532911;
    }
    // 00532907  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 0053290b  ff15f0d35600           -call dword ptr [0x56d3f0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690352) /* 0x56d3f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532911:
    // 00532911  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_532914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532914  833df4d3560000         +cmp dword ptr [0x56d3f4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690356) /* 0x56d3f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053291b  751f                   -jne 0x53293c
    if (!cpu.flags.zf)
    {
        goto L_0x0053293c;
    }
    // 0053291d  68f4d35600             -push 0x56d3f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690356 /*0x56d3f4*/;
    cpu.esp -= 4;
    // 00532922  6810c75600             -push 0x56c710
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687056 /*0x56c710*/;
    cpu.esp -= 4;
    // 00532927  e8ecc9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053292c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053292e  740c                   -je 0x53293c
    if (cpu.flags.zf)
    {
        goto L_0x0053293c;
    }
    // 00532930  c705f4d35600ffffffff   -mov dword ptr [0x56d3f4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690356) /* 0x56d3f4 */) = 4294967295 /*0xffffffff*/;
    // 0053293a  eb20                   -jmp 0x53295c
    goto L_0x0053295c;
L_0x0053293c:
    // 0053293c  833df4d35600ff         +cmp dword ptr [0x56d3f4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690356) /* 0x56d3f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532943  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532948  7412                   -je 0x53295c
    if (cpu.flags.zf)
    {
        goto L_0x0053295c;
    }
    // 0053294a  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053294e  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532952  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532956  ff15f4d35600           -call dword ptr [0x56d3f4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690356) /* 0x56d3f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053295c:
    // 0053295c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53295f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053295f  833df8d3560000         +cmp dword ptr [0x56d3f8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690360) /* 0x56d3f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532966  751f                   -jne 0x532987
    if (!cpu.flags.zf)
    {
        goto L_0x00532987;
    }
    // 00532968  68f8d35600             -push 0x56d3f8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690360 /*0x56d3f8*/;
    cpu.esp -= 4;
    // 0053296d  6824c75600             -push 0x56c724
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687076 /*0x56c724*/;
    cpu.esp -= 4;
    // 00532972  e8a1c9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532977  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532979  740c                   -je 0x532987
    if (cpu.flags.zf)
    {
        goto L_0x00532987;
    }
    // 0053297b  c705f8d35600ffffffff   -mov dword ptr [0x56d3f8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690360) /* 0x56d3f8 */) = 4294967295 /*0xffffffff*/;
    // 00532985  eb20                   -jmp 0x5329a7
    goto L_0x005329a7;
L_0x00532987:
    // 00532987  833df8d35600ff         +cmp dword ptr [0x56d3f8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690360) /* 0x56d3f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053298e  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532993  7412                   -je 0x5329a7
    if (cpu.flags.zf)
    {
        goto L_0x005329a7;
    }
    // 00532995  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532999  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053299d  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005329a1  ff15f8d35600           -call dword ptr [0x56d3f8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690360) /* 0x56d3f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005329a7:
    // 005329a7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5329aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005329aa  833dfcd3560000         +cmp dword ptr [0x56d3fc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690364) /* 0x56d3fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005329b1  751f                   -jne 0x5329d2
    if (!cpu.flags.zf)
    {
        goto L_0x005329d2;
    }
    // 005329b3  68fcd35600             -push 0x56d3fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690364 /*0x56d3fc*/;
    cpu.esp -= 4;
    // 005329b8  6838c75600             -push 0x56c738
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687096 /*0x56c738*/;
    cpu.esp -= 4;
    // 005329bd  e856c9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005329c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005329c4  740c                   -je 0x5329d2
    if (cpu.flags.zf)
    {
        goto L_0x005329d2;
    }
    // 005329c6  c705fcd35600ffffffff   -mov dword ptr [0x56d3fc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690364) /* 0x56d3fc */) = 4294967295 /*0xffffffff*/;
    // 005329d0  eb20                   -jmp 0x5329f2
    goto L_0x005329f2;
L_0x005329d2:
    // 005329d2  833dfcd35600ff         +cmp dword ptr [0x56d3fc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690364) /* 0x56d3fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005329d9  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005329de  7412                   -je 0x5329f2
    if (cpu.flags.zf)
    {
        goto L_0x005329f2;
    }
    // 005329e0  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005329e4  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005329e8  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005329ec  ff15fcd35600           -call dword ptr [0x56d3fc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690364) /* 0x56d3fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005329f2:
    // 005329f2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5329f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005329f5  833d00d4560000         +cmp dword ptr [0x56d400], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690368) /* 0x56d400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005329fc  751f                   -jne 0x532a1d
    if (!cpu.flags.zf)
    {
        goto L_0x00532a1d;
    }
    // 005329fe  6800d45600             -push 0x56d400
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690368 /*0x56d400*/;
    cpu.esp -= 4;
    // 00532a03  684cc75600             -push 0x56c74c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687116 /*0x56c74c*/;
    cpu.esp -= 4;
    // 00532a08  e80bc9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532a0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532a0f  740c                   -je 0x532a1d
    if (cpu.flags.zf)
    {
        goto L_0x00532a1d;
    }
    // 00532a11  c70500d45600ffffffff   -mov dword ptr [0x56d400], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690368) /* 0x56d400 */) = 4294967295 /*0xffffffff*/;
    // 00532a1b  eb20                   -jmp 0x532a3d
    goto L_0x00532a3d;
L_0x00532a1d:
    // 00532a1d  833d00d45600ff         +cmp dword ptr [0x56d400], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690368) /* 0x56d400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532a24  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532a29  7412                   -je 0x532a3d
    if (cpu.flags.zf)
    {
        goto L_0x00532a3d;
    }
    // 00532a2b  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a2f  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a33  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a37  ff1500d45600           -call dword ptr [0x56d400]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690368) /* 0x56d400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532a3d:
    // 00532a3d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532a40  833d04d4560000         +cmp dword ptr [0x56d404], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690372) /* 0x56d404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532a47  751f                   -jne 0x532a68
    if (!cpu.flags.zf)
    {
        goto L_0x00532a68;
    }
    // 00532a49  6804d45600             -push 0x56d404
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690372 /*0x56d404*/;
    cpu.esp -= 4;
    // 00532a4e  6860c75600             -push 0x56c760
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687136 /*0x56c760*/;
    cpu.esp -= 4;
    // 00532a53  e8c0c8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532a58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532a5a  740c                   -je 0x532a68
    if (cpu.flags.zf)
    {
        goto L_0x00532a68;
    }
    // 00532a5c  c70504d45600ffffffff   -mov dword ptr [0x56d404], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690372) /* 0x56d404 */) = 4294967295 /*0xffffffff*/;
    // 00532a66  eb20                   -jmp 0x532a88
    goto L_0x00532a88;
L_0x00532a68:
    // 00532a68  833d04d45600ff         +cmp dword ptr [0x56d404], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690372) /* 0x56d404 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532a6f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532a74  7412                   -je 0x532a88
    if (cpu.flags.zf)
    {
        goto L_0x00532a88;
    }
    // 00532a76  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a7a  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a7e  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532a82  ff1504d45600           -call dword ptr [0x56d404]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690372) /* 0x56d404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532a88:
    // 00532a88  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532a8b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532a8b  833d08d4560000         +cmp dword ptr [0x56d408], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690376) /* 0x56d408 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532a92  751f                   -jne 0x532ab3
    if (!cpu.flags.zf)
    {
        goto L_0x00532ab3;
    }
    // 00532a94  6808d45600             -push 0x56d408
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690376 /*0x56d408*/;
    cpu.esp -= 4;
    // 00532a99  6874c75600             -push 0x56c774
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687156 /*0x56c774*/;
    cpu.esp -= 4;
    // 00532a9e  e875c8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532aa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532aa5  740c                   -je 0x532ab3
    if (cpu.flags.zf)
    {
        goto L_0x00532ab3;
    }
    // 00532aa7  c70508d45600ffffffff   -mov dword ptr [0x56d408], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690376) /* 0x56d408 */) = 4294967295 /*0xffffffff*/;
    // 00532ab1  eb20                   -jmp 0x532ad3
    goto L_0x00532ad3;
L_0x00532ab3:
    // 00532ab3  833d08d45600ff         +cmp dword ptr [0x56d408], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690376) /* 0x56d408 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532aba  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532abf  7412                   -je 0x532ad3
    if (cpu.flags.zf)
    {
        goto L_0x00532ad3;
    }
    // 00532ac1  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ac5  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ac9  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532acd  ff1508d45600           -call dword ptr [0x56d408]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690376) /* 0x56d408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532ad3:
    // 00532ad3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532ad6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532ad6  833d0cd4560000         +cmp dword ptr [0x56d40c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690380) /* 0x56d40c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532add  751f                   -jne 0x532afe
    if (!cpu.flags.zf)
    {
        goto L_0x00532afe;
    }
    // 00532adf  680cd45600             -push 0x56d40c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690380 /*0x56d40c*/;
    cpu.esp -= 4;
    // 00532ae4  6888c75600             -push 0x56c788
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687176 /*0x56c788*/;
    cpu.esp -= 4;
    // 00532ae9  e82ac8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532aee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532af0  740c                   -je 0x532afe
    if (cpu.flags.zf)
    {
        goto L_0x00532afe;
    }
    // 00532af2  c7050cd45600ffffffff   -mov dword ptr [0x56d40c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690380) /* 0x56d40c */) = 4294967295 /*0xffffffff*/;
    // 00532afc  eb20                   -jmp 0x532b1e
    goto L_0x00532b1e;
L_0x00532afe:
    // 00532afe  833d0cd45600ff         +cmp dword ptr [0x56d40c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690380) /* 0x56d40c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532b05  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532b0a  7412                   -je 0x532b1e
    if (cpu.flags.zf)
    {
        goto L_0x00532b1e;
    }
    // 00532b0c  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532b10  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532b14  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532b18  ff150cd45600           -call dword ptr [0x56d40c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690380) /* 0x56d40c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532b1e:
    // 00532b1e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532b21(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532b21  833d10d4560000         +cmp dword ptr [0x56d410], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690384) /* 0x56d410 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532b28  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532b29  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532b2b  751f                   -jne 0x532b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00532b4c;
    }
    // 00532b2d  6810d45600             -push 0x56d410
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690384 /*0x56d410*/;
    cpu.esp -= 4;
    // 00532b32  689cc75600             -push 0x56c79c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687196 /*0x56c79c*/;
    cpu.esp -= 4;
    // 00532b37  e8dcc7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532b3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532b3e  740c                   -je 0x532b4c
    if (cpu.flags.zf)
    {
        goto L_0x00532b4c;
    }
    // 00532b40  c70510d45600ffffffff   -mov dword ptr [0x56d410], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690384) /* 0x56d410 */) = 4294967295 /*0xffffffff*/;
    // 00532b4a  eb20                   -jmp 0x532b6c
    goto L_0x00532b6c;
L_0x00532b4c:
    // 00532b4c  833d10d45600ff         +cmp dword ptr [0x56d410], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690384) /* 0x56d410 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532b53  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532b58  7412                   -je 0x532b6c
    if (cpu.flags.zf)
    {
        goto L_0x00532b6c;
    }
    // 00532b5a  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532b5d  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532b60  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532b63  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532b66  ff1510d45600           -call dword ptr [0x56d410]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690384) /* 0x56d410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532b6c:
    // 00532b6c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532b6d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_532b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532b70  833d14d4560000         +cmp dword ptr [0x56d414], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690388) /* 0x56d414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532b77  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532b78  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532b7a  751f                   -jne 0x532b9b
    if (!cpu.flags.zf)
    {
        goto L_0x00532b9b;
    }
    // 00532b7c  6814d45600             -push 0x56d414
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690388 /*0x56d414*/;
    cpu.esp -= 4;
    // 00532b81  68acc75600             -push 0x56c7ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687212 /*0x56c7ac*/;
    cpu.esp -= 4;
    // 00532b86  e88dc7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532b8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532b8d  740c                   -je 0x532b9b
    if (cpu.flags.zf)
    {
        goto L_0x00532b9b;
    }
    // 00532b8f  c70514d45600ffffffff   -mov dword ptr [0x56d414], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690388) /* 0x56d414 */) = 4294967295 /*0xffffffff*/;
    // 00532b99  eb23                   -jmp 0x532bbe
    goto L_0x00532bbe;
L_0x00532b9b:
    // 00532b9b  833d14d45600ff         +cmp dword ptr [0x56d414], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690388) /* 0x56d414 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ba2  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532ba7  7415                   -je 0x532bbe
    if (cpu.flags.zf)
    {
        goto L_0x00532bbe;
    }
    // 00532ba9  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532bac  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532baf  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532bb2  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532bb5  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532bb8  ff1514d45600           -call dword ptr [0x56d414]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690388) /* 0x56d414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532bbe:
    // 00532bbe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532bbf  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_532bc2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532bc2  833d18d4560000         +cmp dword ptr [0x56d418], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690392) /* 0x56d418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532bc9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532bca  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532bcc  751f                   -jne 0x532bed
    if (!cpu.flags.zf)
    {
        goto L_0x00532bed;
    }
    // 00532bce  6818d45600             -push 0x56d418
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690392 /*0x56d418*/;
    cpu.esp -= 4;
    // 00532bd3  68bcc75600             -push 0x56c7bc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687228 /*0x56c7bc*/;
    cpu.esp -= 4;
    // 00532bd8  e83bc7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532bdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532bdf  740c                   -je 0x532bed
    if (cpu.flags.zf)
    {
        goto L_0x00532bed;
    }
    // 00532be1  c70518d45600ffffffff   -mov dword ptr [0x56d418], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690392) /* 0x56d418 */) = 4294967295 /*0xffffffff*/;
    // 00532beb  eb23                   -jmp 0x532c10
    goto L_0x00532c10;
L_0x00532bed:
    // 00532bed  833d18d45600ff         +cmp dword ptr [0x56d418], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690392) /* 0x56d418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532bf4  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532bf9  7415                   -je 0x532c10
    if (cpu.flags.zf)
    {
        goto L_0x00532c10;
    }
    // 00532bfb  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532bfe  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532c01  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532c04  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532c07  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532c0a  ff1518d45600           -call dword ptr [0x56d418]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690392) /* 0x56d418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532c10:
    // 00532c10  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532c11  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_532c14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532c14  833d1cd4560000         +cmp dword ptr [0x56d41c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690396) /* 0x56d41c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532c1b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532c1c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532c1e  751f                   -jne 0x532c3f
    if (!cpu.flags.zf)
    {
        goto L_0x00532c3f;
    }
    // 00532c20  681cd45600             -push 0x56d41c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690396 /*0x56d41c*/;
    cpu.esp -= 4;
    // 00532c25  68d0c75600             -push 0x56c7d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687248 /*0x56c7d0*/;
    cpu.esp -= 4;
    // 00532c2a  e8e9c6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532c2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532c31  740c                   -je 0x532c3f
    if (cpu.flags.zf)
    {
        goto L_0x00532c3f;
    }
    // 00532c33  c7051cd45600ffffffff   -mov dword ptr [0x56d41c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690396) /* 0x56d41c */) = 4294967295 /*0xffffffff*/;
    // 00532c3d  eb23                   -jmp 0x532c62
    goto L_0x00532c62;
L_0x00532c3f:
    // 00532c3f  833d1cd45600ff         +cmp dword ptr [0x56d41c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690396) /* 0x56d41c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532c46  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532c4b  7415                   -je 0x532c62
    if (cpu.flags.zf)
    {
        goto L_0x00532c62;
    }
    // 00532c4d  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532c50  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532c53  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532c56  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532c59  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532c5c  ff151cd45600           -call dword ptr [0x56d41c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690396) /* 0x56d41c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532c62:
    // 00532c62  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532c63  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_532c66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532c66  833d20d4560000         +cmp dword ptr [0x56d420], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690400) /* 0x56d420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532c6d  751f                   -jne 0x532c8e
    if (!cpu.flags.zf)
    {
        goto L_0x00532c8e;
    }
    // 00532c6f  6820d45600             -push 0x56d420
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690400 /*0x56d420*/;
    cpu.esp -= 4;
    // 00532c74  68e4c75600             -push 0x56c7e4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687268 /*0x56c7e4*/;
    cpu.esp -= 4;
    // 00532c79  e89ac6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532c7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532c80  740c                   -je 0x532c8e
    if (cpu.flags.zf)
    {
        goto L_0x00532c8e;
    }
    // 00532c82  c70520d45600ffffffff   -mov dword ptr [0x56d420], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690400) /* 0x56d420 */) = 4294967295 /*0xffffffff*/;
    // 00532c8c  eb1c                   -jmp 0x532caa
    goto L_0x00532caa;
L_0x00532c8e:
    // 00532c8e  833d20d45600ff         +cmp dword ptr [0x56d420], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690400) /* 0x56d420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532c95  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532c9a  740e                   -je 0x532caa
    if (cpu.flags.zf)
    {
        goto L_0x00532caa;
    }
    // 00532c9c  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532ca0  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532ca4  ff1520d45600           -call dword ptr [0x56d420]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690400) /* 0x56d420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532caa:
    // 00532caa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_532cad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532cad  833d24d4560000         +cmp dword ptr [0x56d424], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cb4  751f                   -jne 0x532cd5
    if (!cpu.flags.zf)
    {
        goto L_0x00532cd5;
    }
    // 00532cb6  6824d45600             -push 0x56d424
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690404 /*0x56d424*/;
    cpu.esp -= 4;
    // 00532cbb  68f4c75600             -push 0x56c7f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687284 /*0x56c7f4*/;
    cpu.esp -= 4;
    // 00532cc0  e853c6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532cc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532cc7  740c                   -je 0x532cd5
    if (cpu.flags.zf)
    {
        goto L_0x00532cd5;
    }
    // 00532cc9  c70524d45600ffffffff   -mov dword ptr [0x56d424], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */) = 4294967295 /*0xffffffff*/;
    // 00532cd3  eb20                   -jmp 0x532cf5
    goto L_0x00532cf5;
L_0x00532cd5:
    // 00532cd5  833d24d45600ff         +cmp dword ptr [0x56d424], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cdc  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532ce1  7412                   -je 0x532cf5
    if (cpu.flags.zf)
    {
        goto L_0x00532cf5;
    }
    // 00532ce3  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ce7  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ceb  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532cef  ff1524d45600           -call dword ptr [0x56d424]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690404) /* 0x56d424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532cf5:
    // 00532cf5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532cf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532cf8  833d28d4560000         +cmp dword ptr [0x56d428], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532cff  751f                   -jne 0x532d20
    if (!cpu.flags.zf)
    {
        goto L_0x00532d20;
    }
    // 00532d01  6828d45600             -push 0x56d428
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690408 /*0x56d428*/;
    cpu.esp -= 4;
    // 00532d06  6804c85600             -push 0x56c804
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687300 /*0x56c804*/;
    cpu.esp -= 4;
    // 00532d0b  e808c6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532d10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532d12  740c                   -je 0x532d20
    if (cpu.flags.zf)
    {
        goto L_0x00532d20;
    }
    // 00532d14  c70528d45600ffffffff   -mov dword ptr [0x56d428], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */) = 4294967295 /*0xffffffff*/;
    // 00532d1e  eb1c                   -jmp 0x532d3c
    goto L_0x00532d3c;
L_0x00532d20:
    // 00532d20  833d28d45600ff         +cmp dword ptr [0x56d428], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d27  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532d2c  740e                   -je 0x532d3c
    if (cpu.flags.zf)
    {
        goto L_0x00532d3c;
    }
    // 00532d2e  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532d32  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532d36  ff1528d45600           -call dword ptr [0x56d428]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690408) /* 0x56d428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532d3c:
    // 00532d3c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_532d3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532d3f  833d2cd4560000         +cmp dword ptr [0x56d42c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d46  751f                   -jne 0x532d67
    if (!cpu.flags.zf)
    {
        goto L_0x00532d67;
    }
    // 00532d48  682cd45600             -push 0x56d42c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690412 /*0x56d42c*/;
    cpu.esp -= 4;
    // 00532d4d  6818c85600             -push 0x56c818
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687320 /*0x56c818*/;
    cpu.esp -= 4;
    // 00532d52  e8c1c5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532d57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532d59  740c                   -je 0x532d67
    if (cpu.flags.zf)
    {
        goto L_0x00532d67;
    }
    // 00532d5b  c7052cd45600ffffffff   -mov dword ptr [0x56d42c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */) = 4294967295 /*0xffffffff*/;
    // 00532d65  eb20                   -jmp 0x532d87
    goto L_0x00532d87;
L_0x00532d67:
    // 00532d67  833d2cd45600ff         +cmp dword ptr [0x56d42c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d6e  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532d73  7412                   -je 0x532d87
    if (cpu.flags.zf)
    {
        goto L_0x00532d87;
    }
    // 00532d75  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d79  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d7d  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532d81  ff152cd45600           -call dword ptr [0x56d42c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690412) /* 0x56d42c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532d87:
    // 00532d87  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532d8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532d8a  833d30d4560000         +cmp dword ptr [0x56d430], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532d91  751f                   -jne 0x532db2
    if (!cpu.flags.zf)
    {
        goto L_0x00532db2;
    }
    // 00532d93  6830d45600             -push 0x56d430
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690416 /*0x56d430*/;
    cpu.esp -= 4;
    // 00532d98  6828c85600             -push 0x56c828
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687336 /*0x56c828*/;
    cpu.esp -= 4;
    // 00532d9d  e876c5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532da2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532da4  740c                   -je 0x532db2
    if (cpu.flags.zf)
    {
        goto L_0x00532db2;
    }
    // 00532da6  c70530d45600ffffffff   -mov dword ptr [0x56d430], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */) = 4294967295 /*0xffffffff*/;
    // 00532db0  eb20                   -jmp 0x532dd2
    goto L_0x00532dd2;
L_0x00532db2:
    // 00532db2  833d30d45600ff         +cmp dword ptr [0x56d430], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532db9  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532dbe  7412                   -je 0x532dd2
    if (cpu.flags.zf)
    {
        goto L_0x00532dd2;
    }
    // 00532dc0  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dc4  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dc8  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532dcc  ff1530d45600           -call dword ptr [0x56d430]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690416) /* 0x56d430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532dd2:
    // 00532dd2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532dd5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532dd5  833d34d4560000         +cmp dword ptr [0x56d434], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ddc  751f                   -jne 0x532dfd
    if (!cpu.flags.zf)
    {
        goto L_0x00532dfd;
    }
    // 00532dde  6834d45600             -push 0x56d434
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690420 /*0x56d434*/;
    cpu.esp -= 4;
    // 00532de3  6838c85600             -push 0x56c838
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687352 /*0x56c838*/;
    cpu.esp -= 4;
    // 00532de8  e82bc5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ded  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532def  740c                   -je 0x532dfd
    if (cpu.flags.zf)
    {
        goto L_0x00532dfd;
    }
    // 00532df1  c70534d45600ffffffff   -mov dword ptr [0x56d434], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */) = 4294967295 /*0xffffffff*/;
    // 00532dfb  eb20                   -jmp 0x532e1d
    goto L_0x00532e1d;
L_0x00532dfd:
    // 00532dfd  833d34d45600ff         +cmp dword ptr [0x56d434], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e04  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e09  7412                   -je 0x532e1d
    if (cpu.flags.zf)
    {
        goto L_0x00532e1d;
    }
    // 00532e0b  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e0f  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e13  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e17  ff1534d45600           -call dword ptr [0x56d434]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690420) /* 0x56d434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532e1d:
    // 00532e1d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532e20  833d38d4560000         +cmp dword ptr [0x56d438], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e27  751f                   -jne 0x532e48
    if (!cpu.flags.zf)
    {
        goto L_0x00532e48;
    }
    // 00532e29  6838d45600             -push 0x56d438
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690424 /*0x56d438*/;
    cpu.esp -= 4;
    // 00532e2e  6848c85600             -push 0x56c848
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687368 /*0x56c848*/;
    cpu.esp -= 4;
    // 00532e33  e8e0c4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532e38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532e3a  740c                   -je 0x532e48
    if (cpu.flags.zf)
    {
        goto L_0x00532e48;
    }
    // 00532e3c  c70538d45600ffffffff   -mov dword ptr [0x56d438], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */) = 4294967295 /*0xffffffff*/;
    // 00532e46  eb20                   -jmp 0x532e68
    goto L_0x00532e68;
L_0x00532e48:
    // 00532e48  833d38d45600ff         +cmp dword ptr [0x56d438], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e4f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e54  7412                   -je 0x532e68
    if (cpu.flags.zf)
    {
        goto L_0x00532e68;
    }
    // 00532e56  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e5a  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e5e  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532e62  ff1538d45600           -call dword ptr [0x56d438]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690424) /* 0x56d438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532e68:
    // 00532e68  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532e6b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532e6b  833d3cd4560000         +cmp dword ptr [0x56d43c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e72  751f                   -jne 0x532e93
    if (!cpu.flags.zf)
    {
        goto L_0x00532e93;
    }
    // 00532e74  683cd45600             -push 0x56d43c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690428 /*0x56d43c*/;
    cpu.esp -= 4;
    // 00532e79  6854c85600             -push 0x56c854
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687380 /*0x56c854*/;
    cpu.esp -= 4;
    // 00532e7e  e895c4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532e83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532e85  740c                   -je 0x532e93
    if (cpu.flags.zf)
    {
        goto L_0x00532e93;
    }
    // 00532e87  c7053cd45600ffffffff   -mov dword ptr [0x56d43c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */) = 4294967295 /*0xffffffff*/;
    // 00532e91  eb20                   -jmp 0x532eb3
    goto L_0x00532eb3;
L_0x00532e93:
    // 00532e93  833d3cd45600ff         +cmp dword ptr [0x56d43c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532e9a  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532e9f  7412                   -je 0x532eb3
    if (cpu.flags.zf)
    {
        goto L_0x00532eb3;
    }
    // 00532ea1  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ea5  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ea9  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ead  ff153cd45600           -call dword ptr [0x56d43c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690428) /* 0x56d43c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532eb3:
    // 00532eb3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532eb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532eb6  833d40d4560000         +cmp dword ptr [0x56d440], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ebd  751f                   -jne 0x532ede
    if (!cpu.flags.zf)
    {
        goto L_0x00532ede;
    }
    // 00532ebf  6840d45600             -push 0x56d440
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690432 /*0x56d440*/;
    cpu.esp -= 4;
    // 00532ec4  6860c85600             -push 0x56c860
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687392 /*0x56c860*/;
    cpu.esp -= 4;
    // 00532ec9  e84ac4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ece  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532ed0  740c                   -je 0x532ede
    if (cpu.flags.zf)
    {
        goto L_0x00532ede;
    }
    // 00532ed2  c70540d45600ffffffff   -mov dword ptr [0x56d440], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */) = 4294967295 /*0xffffffff*/;
    // 00532edc  eb20                   -jmp 0x532efe
    goto L_0x00532efe;
L_0x00532ede:
    // 00532ede  833d40d45600ff         +cmp dword ptr [0x56d440], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532ee5  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532eea  7412                   -je 0x532efe
    if (cpu.flags.zf)
    {
        goto L_0x00532efe;
    }
    // 00532eec  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef0  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef4  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532ef8  ff1540d45600           -call dword ptr [0x56d440]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690432) /* 0x56d440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532efe:
    // 00532efe  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f01(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f01  833d44d4560000         +cmp dword ptr [0x56d444], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f08  751f                   -jne 0x532f29
    if (!cpu.flags.zf)
    {
        goto L_0x00532f29;
    }
    // 00532f0a  6844d45600             -push 0x56d444
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690436 /*0x56d444*/;
    cpu.esp -= 4;
    // 00532f0f  686cc85600             -push 0x56c86c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687404 /*0x56c86c*/;
    cpu.esp -= 4;
    // 00532f14  e8ffc3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532f19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532f1b  740c                   -je 0x532f29
    if (cpu.flags.zf)
    {
        goto L_0x00532f29;
    }
    // 00532f1d  c70544d45600ffffffff   -mov dword ptr [0x56d444], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */) = 4294967295 /*0xffffffff*/;
    // 00532f27  eb20                   -jmp 0x532f49
    goto L_0x00532f49;
L_0x00532f29:
    // 00532f29  833d44d45600ff         +cmp dword ptr [0x56d444], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f30  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532f35  7412                   -je 0x532f49
    if (cpu.flags.zf)
    {
        goto L_0x00532f49;
    }
    // 00532f37  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f3b  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f3f  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f43  ff1544d45600           -call dword ptr [0x56d444]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690436) /* 0x56d444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532f49:
    // 00532f49  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f4c  833d48d4560000         +cmp dword ptr [0x56d448], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f53  751f                   -jne 0x532f74
    if (!cpu.flags.zf)
    {
        goto L_0x00532f74;
    }
    // 00532f55  6848d45600             -push 0x56d448
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690440 /*0x56d448*/;
    cpu.esp -= 4;
    // 00532f5a  687cc85600             -push 0x56c87c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687420 /*0x56c87c*/;
    cpu.esp -= 4;
    // 00532f5f  e8b4c3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532f64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532f66  740c                   -je 0x532f74
    if (cpu.flags.zf)
    {
        goto L_0x00532f74;
    }
    // 00532f68  c70548d45600ffffffff   -mov dword ptr [0x56d448], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */) = 4294967295 /*0xffffffff*/;
    // 00532f72  eb20                   -jmp 0x532f94
    goto L_0x00532f94;
L_0x00532f74:
    // 00532f74  833d48d45600ff         +cmp dword ptr [0x56d448], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f7b  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532f80  7412                   -je 0x532f94
    if (cpu.flags.zf)
    {
        goto L_0x00532f94;
    }
    // 00532f82  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f86  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f8a  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532f8e  ff1548d45600           -call dword ptr [0x56d448]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690440) /* 0x56d448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532f94:
    // 00532f94  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532f97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532f97  833d4cd4560000         +cmp dword ptr [0x56d44c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532f9e  751f                   -jne 0x532fbf
    if (!cpu.flags.zf)
    {
        goto L_0x00532fbf;
    }
    // 00532fa0  684cd45600             -push 0x56d44c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690444 /*0x56d44c*/;
    cpu.esp -= 4;
    // 00532fa5  688cc85600             -push 0x56c88c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687436 /*0x56c88c*/;
    cpu.esp -= 4;
    // 00532faa  e869c3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532fb1  740c                   -je 0x532fbf
    if (cpu.flags.zf)
    {
        goto L_0x00532fbf;
    }
    // 00532fb3  c7054cd45600ffffffff   -mov dword ptr [0x56d44c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */) = 4294967295 /*0xffffffff*/;
    // 00532fbd  eb20                   -jmp 0x532fdf
    goto L_0x00532fdf;
L_0x00532fbf:
    // 00532fbf  833d4cd45600ff         +cmp dword ptr [0x56d44c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532fc6  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00532fcb  7412                   -je 0x532fdf
    if (cpu.flags.zf)
    {
        goto L_0x00532fdf;
    }
    // 00532fcd  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd1  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd5  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532fd9  ff154cd45600           -call dword ptr [0x56d44c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690444) /* 0x56d44c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532fdf:
    // 00532fdf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532fe2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532fe2  833d50d4560000         +cmp dword ptr [0x56d450], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532fe9  751f                   -jne 0x53300a
    if (!cpu.flags.zf)
    {
        goto L_0x0053300a;
    }
    // 00532feb  6850d45600             -push 0x56d450
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690448 /*0x56d450*/;
    cpu.esp -= 4;
    // 00532ff0  689cc85600             -push 0x56c89c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687452 /*0x56c89c*/;
    cpu.esp -= 4;
    // 00532ff5  e81ec3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532ffa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532ffc  740c                   -je 0x53300a
    if (cpu.flags.zf)
    {
        goto L_0x0053300a;
    }
    // 00532ffe  c70550d45600ffffffff   -mov dword ptr [0x56d450], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */) = 4294967295 /*0xffffffff*/;
    // 00533008  eb1c                   -jmp 0x533026
    goto L_0x00533026;
L_0x0053300a:
    // 0053300a  833d50d45600ff         +cmp dword ptr [0x56d450], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533011  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533016  740e                   -je 0x533026
    if (cpu.flags.zf)
    {
        goto L_0x00533026;
    }
    // 00533018  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053301c  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533020  ff1550d45600           -call dword ptr [0x56d450]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690448) /* 0x56d450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533026:
    // 00533026  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533029(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533029  833d54d4560000         +cmp dword ptr [0x56d454], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533030  751f                   -jne 0x533051
    if (!cpu.flags.zf)
    {
        goto L_0x00533051;
    }
    // 00533032  6854d45600             -push 0x56d454
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690452 /*0x56d454*/;
    cpu.esp -= 4;
    // 00533037  68acc85600             -push 0x56c8ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687468 /*0x56c8ac*/;
    cpu.esp -= 4;
    // 0053303c  e8d7c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533041  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533043  740c                   -je 0x533051
    if (cpu.flags.zf)
    {
        goto L_0x00533051;
    }
    // 00533045  c70554d45600ffffffff   -mov dword ptr [0x56d454], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */) = 4294967295 /*0xffffffff*/;
    // 0053304f  eb1c                   -jmp 0x53306d
    goto L_0x0053306d;
L_0x00533051:
    // 00533051  833d54d45600ff         +cmp dword ptr [0x56d454], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533058  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053305d  740e                   -je 0x53306d
    if (cpu.flags.zf)
    {
        goto L_0x0053306d;
    }
    // 0053305f  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533063  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533067  ff1554d45600           -call dword ptr [0x56d454]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690452) /* 0x56d454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053306d:
    // 0053306d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533070  833d58d4560000         +cmp dword ptr [0x56d458], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533077  751f                   -jne 0x533098
    if (!cpu.flags.zf)
    {
        goto L_0x00533098;
    }
    // 00533079  6858d45600             -push 0x56d458
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690456 /*0x56d458*/;
    cpu.esp -= 4;
    // 0053307e  68bcc85600             -push 0x56c8bc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687484 /*0x56c8bc*/;
    cpu.esp -= 4;
    // 00533083  e890c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053308a  740c                   -je 0x533098
    if (cpu.flags.zf)
    {
        goto L_0x00533098;
    }
    // 0053308c  c70558d45600ffffffff   -mov dword ptr [0x56d458], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */) = 4294967295 /*0xffffffff*/;
    // 00533096  eb1c                   -jmp 0x5330b4
    goto L_0x005330b4;
L_0x00533098:
    // 00533098  833d58d45600ff         +cmp dword ptr [0x56d458], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053309f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005330a4  740e                   -je 0x5330b4
    if (cpu.flags.zf)
    {
        goto L_0x005330b4;
    }
    // 005330a6  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330aa  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330ae  ff1558d45600           -call dword ptr [0x56d458]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690456) /* 0x56d458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005330b4:
    // 005330b4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5330b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005330b7  833d5cd4560000         +cmp dword ptr [0x56d45c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005330be  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005330bf  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005330c1  751f                   -jne 0x5330e2
    if (!cpu.flags.zf)
    {
        goto L_0x005330e2;
    }
    // 005330c3  685cd45600             -push 0x56d45c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690460 /*0x56d45c*/;
    cpu.esp -= 4;
    // 005330c8  68ccc85600             -push 0x56c8cc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687500 /*0x56c8cc*/;
    cpu.esp -= 4;
    // 005330cd  e846c2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005330d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005330d4  740c                   -je 0x5330e2
    if (cpu.flags.zf)
    {
        goto L_0x005330e2;
    }
    // 005330d6  c7055cd45600ffffffff   -mov dword ptr [0x56d45c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */) = 4294967295 /*0xffffffff*/;
    // 005330e0  eb20                   -jmp 0x533102
    goto L_0x00533102;
L_0x005330e2:
    // 005330e2  833d5cd45600ff         +cmp dword ptr [0x56d45c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005330e9  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005330ee  7412                   -je 0x533102
    if (cpu.flags.zf)
    {
        goto L_0x00533102;
    }
    // 005330f0  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005330f3  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005330f6  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005330f9  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005330fc  ff155cd45600           -call dword ptr [0x56d45c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690460) /* 0x56d45c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533102:
    // 00533102  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533103  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533106(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533106  833d60d4560000         +cmp dword ptr [0x56d460], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053310d  751f                   -jne 0x53312e
    if (!cpu.flags.zf)
    {
        goto L_0x0053312e;
    }
    // 0053310f  6860d45600             -push 0x56d460
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690464 /*0x56d460*/;
    cpu.esp -= 4;
    // 00533114  68e4c85600             -push 0x56c8e4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687524 /*0x56c8e4*/;
    cpu.esp -= 4;
    // 00533119  e8fac1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053311e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533120  740c                   -je 0x53312e
    if (cpu.flags.zf)
    {
        goto L_0x0053312e;
    }
    // 00533122  c70560d45600ffffffff   -mov dword ptr [0x56d460], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */) = 4294967295 /*0xffffffff*/;
    // 0053312c  eb20                   -jmp 0x53314e
    goto L_0x0053314e;
L_0x0053312e:
    // 0053312e  833d60d45600ff         +cmp dword ptr [0x56d460], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533135  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053313a  7412                   -je 0x53314e
    if (cpu.flags.zf)
    {
        goto L_0x0053314e;
    }
    // 0053313c  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533140  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533144  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533148  ff1560d45600           -call dword ptr [0x56d460]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690464) /* 0x56d460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053314e:
    // 0053314e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533151(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533151  833d64d4560000         +cmp dword ptr [0x56d464], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533158  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533159  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053315b  751f                   -jne 0x53317c
    if (!cpu.flags.zf)
    {
        goto L_0x0053317c;
    }
    // 0053315d  6864d45600             -push 0x56d464
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690468 /*0x56d464*/;
    cpu.esp -= 4;
    // 00533162  68f4c85600             -push 0x56c8f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687540 /*0x56c8f4*/;
    cpu.esp -= 4;
    // 00533167  e8acc1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053316c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053316e  740c                   -je 0x53317c
    if (cpu.flags.zf)
    {
        goto L_0x0053317c;
    }
    // 00533170  c70564d45600ffffffff   -mov dword ptr [0x56d464], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */) = 4294967295 /*0xffffffff*/;
    // 0053317a  eb23                   -jmp 0x53319f
    goto L_0x0053319f;
L_0x0053317c:
    // 0053317c  833d64d45600ff         +cmp dword ptr [0x56d464], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533183  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533188  7415                   -je 0x53319f
    if (cpu.flags.zf)
    {
        goto L_0x0053319f;
    }
    // 0053318a  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053318d  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533190  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533193  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533196  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533199  ff1564d45600           -call dword ptr [0x56d464]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690468) /* 0x56d464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053319f:
    // 0053319f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005331a0  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5331a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005331a3  833d68d4560000         +cmp dword ptr [0x56d468], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005331aa  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005331ab  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005331ad  751f                   -jne 0x5331ce
    if (!cpu.flags.zf)
    {
        goto L_0x005331ce;
    }
    // 005331af  6868d45600             -push 0x56d468
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690472 /*0x56d468*/;
    cpu.esp -= 4;
    // 005331b4  6804c95600             -push 0x56c904
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687556 /*0x56c904*/;
    cpu.esp -= 4;
    // 005331b9  e85ac1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005331be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005331c0  740c                   -je 0x5331ce
    if (cpu.flags.zf)
    {
        goto L_0x005331ce;
    }
    // 005331c2  c70568d45600ffffffff   -mov dword ptr [0x56d468], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */) = 4294967295 /*0xffffffff*/;
    // 005331cc  eb29                   -jmp 0x5331f7
    goto L_0x005331f7;
L_0x005331ce:
    // 005331ce  833d68d45600ff         +cmp dword ptr [0x56d468], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005331d5  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005331da  741b                   -je 0x5331f7
    if (cpu.flags.zf)
    {
        goto L_0x005331f7;
    }
    // 005331dc  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005331df  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005331e2  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005331e5  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005331e8  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005331eb  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005331ee  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005331f1  ff1568d45600           -call dword ptr [0x56d468]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690472) /* 0x56d468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005331f7:
    // 005331f7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005331f8  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_5331fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005331fb  833d6cd4560000         +cmp dword ptr [0x56d46c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533202  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533203  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533205  751f                   -jne 0x533226
    if (!cpu.flags.zf)
    {
        goto L_0x00533226;
    }
    // 00533207  686cd45600             -push 0x56d46c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690476 /*0x56d46c*/;
    cpu.esp -= 4;
    // 0053320c  6818c95600             -push 0x56c918
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687576 /*0x56c918*/;
    cpu.esp -= 4;
    // 00533211  e802c1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533216  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533218  740c                   -je 0x533226
    if (cpu.flags.zf)
    {
        goto L_0x00533226;
    }
    // 0053321a  c7056cd45600ffffffff   -mov dword ptr [0x56d46c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */) = 4294967295 /*0xffffffff*/;
    // 00533224  eb29                   -jmp 0x53324f
    goto L_0x0053324f;
L_0x00533226:
    // 00533226  833d6cd45600ff         +cmp dword ptr [0x56d46c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053322d  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533232  741b                   -je 0x53324f
    if (cpu.flags.zf)
    {
        goto L_0x0053324f;
    }
    // 00533234  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00533237  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053323a  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053323d  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533240  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533243  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533246  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533249  ff156cd45600           -call dword ptr [0x56d46c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690476) /* 0x56d46c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053324f:
    // 0053324f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533250  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_533253(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533253  833d70d4560000         +cmp dword ptr [0x56d470], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053325a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053325b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053325d  751f                   -jne 0x53327e
    if (!cpu.flags.zf)
    {
        goto L_0x0053327e;
    }
    // 0053325f  6870d45600             -push 0x56d470
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690480 /*0x56d470*/;
    cpu.esp -= 4;
    // 00533264  682cc95600             -push 0x56c92c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687596 /*0x56c92c*/;
    cpu.esp -= 4;
    // 00533269  e8aac0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053326e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533270  740c                   -je 0x53327e
    if (cpu.flags.zf)
    {
        goto L_0x0053327e;
    }
    // 00533272  c70570d45600ffffffff   -mov dword ptr [0x56d470], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */) = 4294967295 /*0xffffffff*/;
    // 0053327c  eb26                   -jmp 0x5332a4
    goto L_0x005332a4;
L_0x0053327e:
    // 0053327e  833d70d45600ff         +cmp dword ptr [0x56d470], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533285  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053328a  7418                   -je 0x5332a4
    if (cpu.flags.zf)
    {
        goto L_0x005332a4;
    }
    // 0053328c  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053328f  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533292  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533295  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533298  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053329b  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053329e  ff1570d45600           -call dword ptr [0x56d470]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690480) /* 0x56d470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005332a4:
    // 005332a4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005332a5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5332a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005332a8  833d74d4560000         +cmp dword ptr [0x56d474], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005332af  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005332b0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005332b2  751f                   -jne 0x5332d3
    if (!cpu.flags.zf)
    {
        goto L_0x005332d3;
    }
    // 005332b4  6874d45600             -push 0x56d474
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690484 /*0x56d474*/;
    cpu.esp -= 4;
    // 005332b9  6848c95600             -push 0x56c948
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687624 /*0x56c948*/;
    cpu.esp -= 4;
    // 005332be  e855c0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005332c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005332c5  740c                   -je 0x5332d3
    if (cpu.flags.zf)
    {
        goto L_0x005332d3;
    }
    // 005332c7  c70574d45600ffffffff   -mov dword ptr [0x56d474], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */) = 4294967295 /*0xffffffff*/;
    // 005332d1  eb26                   -jmp 0x5332f9
    goto L_0x005332f9;
L_0x005332d3:
    // 005332d3  833d74d45600ff         +cmp dword ptr [0x56d474], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005332da  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005332df  7418                   -je 0x5332f9
    if (cpu.flags.zf)
    {
        goto L_0x005332f9;
    }
    // 005332e1  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005332e4  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005332e7  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005332ea  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005332ed  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005332f0  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005332f3  ff1574d45600           -call dword ptr [0x56d474]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690484) /* 0x56d474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005332f9:
    // 005332f9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005332fa  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5332fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005332fd  833d78d4560000         +cmp dword ptr [0x56d478], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533304  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533305  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533307  751f                   -jne 0x533328
    if (!cpu.flags.zf)
    {
        goto L_0x00533328;
    }
    // 00533309  6878d45600             -push 0x56d478
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690488 /*0x56d478*/;
    cpu.esp -= 4;
    // 0053330e  6864c95600             -push 0x56c964
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687652 /*0x56c964*/;
    cpu.esp -= 4;
    // 00533313  e800c0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053331a  740c                   -je 0x533328
    if (cpu.flags.zf)
    {
        goto L_0x00533328;
    }
    // 0053331c  c70578d45600ffffffff   -mov dword ptr [0x56d478], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */) = 4294967295 /*0xffffffff*/;
    // 00533326  eb29                   -jmp 0x533351
    goto L_0x00533351;
L_0x00533328:
    // 00533328  833d78d45600ff         +cmp dword ptr [0x56d478], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053332f  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533334  741b                   -je 0x533351
    if (cpu.flags.zf)
    {
        goto L_0x00533351;
    }
    // 00533336  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00533339  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053333c  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053333f  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533342  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533345  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533348  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053334b  ff1578d45600           -call dword ptr [0x56d478]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690488) /* 0x56d478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533351:
    // 00533351  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533352  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_533355(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533355  833d7cd4560000         +cmp dword ptr [0x56d47c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053335c  751f                   -jne 0x53337d
    if (!cpu.flags.zf)
    {
        goto L_0x0053337d;
    }
    // 0053335e  687cd45600             -push 0x56d47c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690492 /*0x56d47c*/;
    cpu.esp -= 4;
    // 00533363  6870c95600             -push 0x56c970
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687664 /*0x56c970*/;
    cpu.esp -= 4;
    // 00533368  e8abbfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053336d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053336f  740c                   -je 0x53337d
    if (cpu.flags.zf)
    {
        goto L_0x0053337d;
    }
    // 00533371  c7057cd45600ffffffff   -mov dword ptr [0x56d47c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */) = 4294967295 /*0xffffffff*/;
    // 0053337b  eb20                   -jmp 0x53339d
    goto L_0x0053339d;
L_0x0053337d:
    // 0053337d  833d7cd45600ff         +cmp dword ptr [0x56d47c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533384  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533389  7412                   -je 0x53339d
    if (cpu.flags.zf)
    {
        goto L_0x0053339d;
    }
    // 0053338b  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053338f  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533393  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533397  ff157cd45600           -call dword ptr [0x56d47c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690492) /* 0x56d47c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053339d:
    // 0053339d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5333a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005333a0  833d80d4560000         +cmp dword ptr [0x56d480], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333a7  751f                   -jne 0x5333c8
    if (!cpu.flags.zf)
    {
        goto L_0x005333c8;
    }
    // 005333a9  6880d45600             -push 0x56d480
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690496 /*0x56d480*/;
    cpu.esp -= 4;
    // 005333ae  6884c95600             -push 0x56c984
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687684 /*0x56c984*/;
    cpu.esp -= 4;
    // 005333b3  e860bfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005333b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005333ba  740c                   -je 0x5333c8
    if (cpu.flags.zf)
    {
        goto L_0x005333c8;
    }
    // 005333bc  c70580d45600ffffffff   -mov dword ptr [0x56d480], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */) = 4294967295 /*0xffffffff*/;
    // 005333c6  eb20                   -jmp 0x5333e8
    goto L_0x005333e8;
L_0x005333c8:
    // 005333c8  833d80d45600ff         +cmp dword ptr [0x56d480], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333cf  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005333d4  7412                   -je 0x5333e8
    if (cpu.flags.zf)
    {
        goto L_0x005333e8;
    }
    // 005333d6  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333da  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333de  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005333e2  ff1580d45600           -call dword ptr [0x56d480]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690496) /* 0x56d480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005333e8:
    // 005333e8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5333eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005333eb  833d84d4560000         +cmp dword ptr [0x56d484], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005333f2  751f                   -jne 0x533413
    if (!cpu.flags.zf)
    {
        goto L_0x00533413;
    }
    // 005333f4  6884d45600             -push 0x56d484
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690500 /*0x56d484*/;
    cpu.esp -= 4;
    // 005333f9  6898c95600             -push 0x56c998
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687704 /*0x56c998*/;
    cpu.esp -= 4;
    // 005333fe  e815bfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533403  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533405  740c                   -je 0x533413
    if (cpu.flags.zf)
    {
        goto L_0x00533413;
    }
    // 00533407  c70584d45600ffffffff   -mov dword ptr [0x56d484], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */) = 4294967295 /*0xffffffff*/;
    // 00533411  eb20                   -jmp 0x533433
    goto L_0x00533433;
L_0x00533413:
    // 00533413  833d84d45600ff         +cmp dword ptr [0x56d484], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053341a  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053341f  7412                   -je 0x533433
    if (cpu.flags.zf)
    {
        goto L_0x00533433;
    }
    // 00533421  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533425  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533429  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053342d  ff1584d45600           -call dword ptr [0x56d484]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690500) /* 0x56d484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533433:
    // 00533433  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533436(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533436  833d88d4560000         +cmp dword ptr [0x56d488], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053343d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053343e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533440  751f                   -jne 0x533461
    if (!cpu.flags.zf)
    {
        goto L_0x00533461;
    }
    // 00533442  6888d45600             -push 0x56d488
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690504 /*0x56d488*/;
    cpu.esp -= 4;
    // 00533447  68acc95600             -push 0x56c9ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687724 /*0x56c9ac*/;
    cpu.esp -= 4;
    // 0053344c  e8c7beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533451  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533453  740c                   -je 0x533461
    if (cpu.flags.zf)
    {
        goto L_0x00533461;
    }
    // 00533455  c70588d45600ffffffff   -mov dword ptr [0x56d488], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */) = 4294967295 /*0xffffffff*/;
    // 0053345f  eb20                   -jmp 0x533481
    goto L_0x00533481;
L_0x00533461:
    // 00533461  833d88d45600ff         +cmp dword ptr [0x56d488], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533468  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053346d  7412                   -je 0x533481
    if (cpu.flags.zf)
    {
        goto L_0x00533481;
    }
    // 0053346f  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533472  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533475  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533478  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053347b  ff1588d45600           -call dword ptr [0x56d488]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690504) /* 0x56d488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533481:
    // 00533481  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533482  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533485(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533485  833d8cd4560000         +cmp dword ptr [0x56d48c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053348c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053348d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053348f  751f                   -jne 0x5334b0
    if (!cpu.flags.zf)
    {
        goto L_0x005334b0;
    }
    // 00533491  688cd45600             -push 0x56d48c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690508 /*0x56d48c*/;
    cpu.esp -= 4;
    // 00533496  68bcc95600             -push 0x56c9bc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687740 /*0x56c9bc*/;
    cpu.esp -= 4;
    // 0053349b  e878beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005334a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005334a2  740c                   -je 0x5334b0
    if (cpu.flags.zf)
    {
        goto L_0x005334b0;
    }
    // 005334a4  c7058cd45600ffffffff   -mov dword ptr [0x56d48c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */) = 4294967295 /*0xffffffff*/;
    // 005334ae  eb23                   -jmp 0x5334d3
    goto L_0x005334d3;
L_0x005334b0:
    // 005334b0  833d8cd45600ff         +cmp dword ptr [0x56d48c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005334b7  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005334bc  7415                   -je 0x5334d3
    if (cpu.flags.zf)
    {
        goto L_0x005334d3;
    }
    // 005334be  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005334c1  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005334c4  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005334c7  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005334ca  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005334cd  ff158cd45600           -call dword ptr [0x56d48c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690508) /* 0x56d48c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005334d3:
    // 005334d3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005334d4  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5334d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005334d7  833d90d4560000         +cmp dword ptr [0x56d490], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005334de  751f                   -jne 0x5334ff
    if (!cpu.flags.zf)
    {
        goto L_0x005334ff;
    }
    // 005334e0  6890d45600             -push 0x56d490
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690512 /*0x56d490*/;
    cpu.esp -= 4;
    // 005334e5  68ccc95600             -push 0x56c9cc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687756 /*0x56c9cc*/;
    cpu.esp -= 4;
    // 005334ea  e829beffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005334ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005334f1  740c                   -je 0x5334ff
    if (cpu.flags.zf)
    {
        goto L_0x005334ff;
    }
    // 005334f3  c70590d45600ffffffff   -mov dword ptr [0x56d490], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */) = 4294967295 /*0xffffffff*/;
    // 005334fd  eb20                   -jmp 0x53351f
    goto L_0x0053351f;
L_0x005334ff:
    // 005334ff  833d90d45600ff         +cmp dword ptr [0x56d490], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533506  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053350b  7412                   -je 0x53351f
    if (cpu.flags.zf)
    {
        goto L_0x0053351f;
    }
    // 0053350d  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533511  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533515  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533519  ff1590d45600           -call dword ptr [0x56d490]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690512) /* 0x56d490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053351f:
    // 0053351f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533522(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533522  833d94d4560000         +cmp dword ptr [0x56d494], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533529  751f                   -jne 0x53354a
    if (!cpu.flags.zf)
    {
        goto L_0x0053354a;
    }
    // 0053352b  6894d45600             -push 0x56d494
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690516 /*0x56d494*/;
    cpu.esp -= 4;
    // 00533530  68dcc95600             -push 0x56c9dc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687772 /*0x56c9dc*/;
    cpu.esp -= 4;
    // 00533535  e8debdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053353a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053353c  740c                   -je 0x53354a
    if (cpu.flags.zf)
    {
        goto L_0x0053354a;
    }
    // 0053353e  c70594d45600ffffffff   -mov dword ptr [0x56d494], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */) = 4294967295 /*0xffffffff*/;
    // 00533548  eb20                   -jmp 0x53356a
    goto L_0x0053356a;
L_0x0053354a:
    // 0053354a  833d94d45600ff         +cmp dword ptr [0x56d494], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533551  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533556  7412                   -je 0x53356a
    if (cpu.flags.zf)
    {
        goto L_0x0053356a;
    }
    // 00533558  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053355c  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533560  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533564  ff1594d45600           -call dword ptr [0x56d494]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690516) /* 0x56d494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053356a:
    // 0053356a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53356d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053356d  833d98d4560000         +cmp dword ptr [0x56d498], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533574  751f                   -jne 0x533595
    if (!cpu.flags.zf)
    {
        goto L_0x00533595;
    }
    // 00533576  6898d45600             -push 0x56d498
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690520 /*0x56d498*/;
    cpu.esp -= 4;
    // 0053357b  68f0c95600             -push 0x56c9f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687792 /*0x56c9f0*/;
    cpu.esp -= 4;
    // 00533580  e893bdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533585  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533587  740c                   -je 0x533595
    if (cpu.flags.zf)
    {
        goto L_0x00533595;
    }
    // 00533589  c70598d45600ffffffff   -mov dword ptr [0x56d498], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */) = 4294967295 /*0xffffffff*/;
    // 00533593  eb20                   -jmp 0x5335b5
    goto L_0x005335b5;
L_0x00533595:
    // 00533595  833d98d45600ff         +cmp dword ptr [0x56d498], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053359c  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005335a1  7412                   -je 0x5335b5
    if (cpu.flags.zf)
    {
        goto L_0x005335b5;
    }
    // 005335a3  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335a7  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335ab  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335af  ff1598d45600           -call dword ptr [0x56d498]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690520) /* 0x56d498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005335b5:
    // 005335b5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5335b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005335b8  833d9cd4560000         +cmp dword ptr [0x56d49c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005335bf  751f                   -jne 0x5335e0
    if (!cpu.flags.zf)
    {
        goto L_0x005335e0;
    }
    // 005335c1  689cd45600             -push 0x56d49c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690524 /*0x56d49c*/;
    cpu.esp -= 4;
    // 005335c6  6800ca5600             -push 0x56ca00
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687808 /*0x56ca00*/;
    cpu.esp -= 4;
    // 005335cb  e848bdffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005335d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005335d2  740c                   -je 0x5335e0
    if (cpu.flags.zf)
    {
        goto L_0x005335e0;
    }
    // 005335d4  c7059cd45600ffffffff   -mov dword ptr [0x56d49c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */) = 4294967295 /*0xffffffff*/;
    // 005335de  eb20                   -jmp 0x533600
    goto L_0x00533600;
L_0x005335e0:
    // 005335e0  833d9cd45600ff         +cmp dword ptr [0x56d49c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005335e7  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005335ec  7412                   -je 0x533600
    if (cpu.flags.zf)
    {
        goto L_0x00533600;
    }
    // 005335ee  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335f2  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335f6  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005335fa  ff159cd45600           -call dword ptr [0x56d49c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690524) /* 0x56d49c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533600:
    // 00533600  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_533603(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533603  833da0d4560000         +cmp dword ptr [0x56d4a0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053360a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053360b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053360d  751f                   -jne 0x53362e
    if (!cpu.flags.zf)
    {
        goto L_0x0053362e;
    }
    // 0053360f  68a0d45600             -push 0x56d4a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690528 /*0x56d4a0*/;
    cpu.esp -= 4;
    // 00533614  6810ca5600             -push 0x56ca10
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687824 /*0x56ca10*/;
    cpu.esp -= 4;
    // 00533619  e8fabcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053361e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533620  740c                   -je 0x53362e
    if (cpu.flags.zf)
    {
        goto L_0x0053362e;
    }
    // 00533622  c705a0d45600ffffffff   -mov dword ptr [0x56d4a0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */) = 4294967295 /*0xffffffff*/;
    // 0053362c  eb20                   -jmp 0x53364e
    goto L_0x0053364e;
L_0x0053362e:
    // 0053362e  833da0d45600ff         +cmp dword ptr [0x56d4a0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533635  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 0053363a  7412                   -je 0x53364e
    if (cpu.flags.zf)
    {
        goto L_0x0053364e;
    }
    // 0053363c  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053363f  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00533642  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533645  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533648  ff15a0d45600           -call dword ptr [0x56d4a0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690528) /* 0x56d4a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053364e:
    // 0053364e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053364f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_533652(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533652  833da4d4560000         +cmp dword ptr [0x56d4a4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533659  751f                   -jne 0x53367a
    if (!cpu.flags.zf)
    {
        goto L_0x0053367a;
    }
    // 0053365b  68a4d45600             -push 0x56d4a4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690532 /*0x56d4a4*/;
    cpu.esp -= 4;
    // 00533660  6828ca5600             -push 0x56ca28
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687848 /*0x56ca28*/;
    cpu.esp -= 4;
    // 00533665  e8aebcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053366a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053366c  740c                   -je 0x53367a
    if (cpu.flags.zf)
    {
        goto L_0x0053367a;
    }
    // 0053366e  c705a4d45600ffffffff   -mov dword ptr [0x56d4a4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */) = 4294967295 /*0xffffffff*/;
    // 00533678  eb20                   -jmp 0x53369a
    goto L_0x0053369a;
L_0x0053367a:
    // 0053367a  833da4d45600ff         +cmp dword ptr [0x56d4a4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533681  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 00533686  7412                   -je 0x53369a
    if (cpu.flags.zf)
    {
        goto L_0x0053369a;
    }
    // 00533688  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053368c  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533690  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00533694  ff15a4d45600           -call dword ptr [0x56d4a4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690532) /* 0x56d4a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053369a:
    // 0053369a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53369d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053369d  833da8d4560000         +cmp dword ptr [0x56d4a8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336a4  751f                   -jne 0x5336c5
    if (!cpu.flags.zf)
    {
        goto L_0x005336c5;
    }
    // 005336a6  68a8d45600             -push 0x56d4a8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690536 /*0x56d4a8*/;
    cpu.esp -= 4;
    // 005336ab  6838ca5600             -push 0x56ca38
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687864 /*0x56ca38*/;
    cpu.esp -= 4;
    // 005336b0  e863bcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005336b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005336b7  740c                   -je 0x5336c5
    if (cpu.flags.zf)
    {
        goto L_0x005336c5;
    }
    // 005336b9  c705a8d45600ffffffff   -mov dword ptr [0x56d4a8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */) = 4294967295 /*0xffffffff*/;
    // 005336c3  eb18                   -jmp 0x5336dd
    goto L_0x005336dd;
L_0x005336c5:
    // 005336c5  833da8d45600ff         +cmp dword ptr [0x56d4a8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336cc  b81d000090             -mov eax, 0x9000001d
    cpu.eax = 2415919133 /*0x9000001d*/;
    // 005336d1  740a                   -je 0x5336dd
    if (cpu.flags.zf)
    {
        goto L_0x005336dd;
    }
    // 005336d3  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 005336d7  ff15a8d45600           -call dword ptr [0x56d4a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690536) /* 0x56d4a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005336dd:
    // 005336dd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5336e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005336e0  833dacd4560000         +cmp dword ptr [0x56d4ac], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005336e7  751f                   -jne 0x533708
    if (!cpu.flags.zf)
    {
        goto L_0x00533708;
    }
    // 005336e9  68acd45600             -push 0x56d4ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690540 /*0x56d4ac*/;
    cpu.esp -= 4;
    // 005336ee  6848ca5600             -push 0x56ca48
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687880 /*0x56ca48*/;
    cpu.esp -= 4;
    // 005336f3  e820bcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005336f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005336fa  740c                   -je 0x533708
    if (cpu.flags.zf)
    {
        goto L_0x00533708;
    }
    // 005336fc  c705acd45600ffffffff   -mov dword ptr [0x56d4ac], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */) = 4294967295 /*0xffffffff*/;
    // 00533706  eb1c                   -jmp 0x533724
    goto L_0x00533724;
L_0x00533708:
    // 00533708  833dacd45600ff         +cmp dword ptr [0x56d4ac], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053370f  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533714  740e                   -je 0x533724
    if (cpu.flags.zf)
    {
        goto L_0x00533724;
    }
    // 00533716  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053371a  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053371e  ff15acd45600           -call dword ptr [0x56d4ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690540) /* 0x56d4ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533724:
    // 00533724  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_533727(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533727  833db0d4560000         +cmp dword ptr [0x56d4b0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053372e  751f                   -jne 0x53374f
    if (!cpu.flags.zf)
    {
        goto L_0x0053374f;
    }
    // 00533730  68b0d45600             -push 0x56d4b0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690544 /*0x56d4b0*/;
    cpu.esp -= 4;
    // 00533735  685cca5600             -push 0x56ca5c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687900 /*0x56ca5c*/;
    cpu.esp -= 4;
    // 0053373a  e8d9bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053373f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533741  740c                   -je 0x53374f
    if (cpu.flags.zf)
    {
        goto L_0x0053374f;
    }
    // 00533743  c705b0d45600ffffffff   -mov dword ptr [0x56d4b0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */) = 4294967295 /*0xffffffff*/;
    // 0053374d  eb1c                   -jmp 0x53376b
    goto L_0x0053376b;
L_0x0053374f:
    // 0053374f  833db0d45600ff         +cmp dword ptr [0x56d4b0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533756  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0053375b  740e                   -je 0x53376b
    if (cpu.flags.zf)
    {
        goto L_0x0053376b;
    }
    // 0053375d  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533761  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533765  ff15b0d45600           -call dword ptr [0x56d4b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690544) /* 0x56d4b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053376b:
    // 0053376b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53376e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053376e  833db4d4560000         +cmp dword ptr [0x56d4b4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533775  751f                   -jne 0x533796
    if (!cpu.flags.zf)
    {
        goto L_0x00533796;
    }
    // 00533777  68b4d45600             -push 0x56d4b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690548 /*0x56d4b4*/;
    cpu.esp -= 4;
    // 0053377c  6874ca5600             -push 0x56ca74
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687924 /*0x56ca74*/;
    cpu.esp -= 4;
    // 00533781  e892bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533786  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533788  740c                   -je 0x533796
    if (cpu.flags.zf)
    {
        goto L_0x00533796;
    }
    // 0053378a  c705b4d45600ffffffff   -mov dword ptr [0x56d4b4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */) = 4294967295 /*0xffffffff*/;
    // 00533794  eb1c                   -jmp 0x5337b2
    goto L_0x005337b2;
L_0x00533796:
    // 00533796  833db4d45600ff         +cmp dword ptr [0x56d4b4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053379d  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005337a2  740e                   -je 0x5337b2
    if (cpu.flags.zf)
    {
        goto L_0x005337b2;
    }
    // 005337a4  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337a8  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337ac  ff15b4d45600           -call dword ptr [0x56d4b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690548) /* 0x56d4b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005337b2:
    // 005337b2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5337b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005337b5  833db8d4560000         +cmp dword ptr [0x56d4b8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005337bc  751f                   -jne 0x5337dd
    if (!cpu.flags.zf)
    {
        goto L_0x005337dd;
    }
    // 005337be  68b8d45600             -push 0x56d4b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690552 /*0x56d4b8*/;
    cpu.esp -= 4;
    // 005337c3  688cca5600             -push 0x56ca8c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687948 /*0x56ca8c*/;
    cpu.esp -= 4;
    // 005337c8  e84bbbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005337cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005337cf  740c                   -je 0x5337dd
    if (cpu.flags.zf)
    {
        goto L_0x005337dd;
    }
    // 005337d1  c705b8d45600ffffffff   -mov dword ptr [0x56d4b8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */) = 4294967295 /*0xffffffff*/;
    // 005337db  eb1c                   -jmp 0x5337f9
    goto L_0x005337f9;
L_0x005337dd:
    // 005337dd  833db8d45600ff         +cmp dword ptr [0x56d4b8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005337e4  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005337e9  740e                   -je 0x5337f9
    if (cpu.flags.zf)
    {
        goto L_0x005337f9;
    }
    // 005337eb  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337ef  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005337f3  ff15b8d45600           -call dword ptr [0x56d4b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690552) /* 0x56d4b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005337f9:
    // 005337f9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5337fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005337fc  833dbcd4560000         +cmp dword ptr [0x56d4bc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533803  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533804  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533806  751f                   -jne 0x533827
    if (!cpu.flags.zf)
    {
        goto L_0x00533827;
    }
    // 00533808  68bcd45600             -push 0x56d4bc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690556 /*0x56d4bc*/;
    cpu.esp -= 4;
    // 0053380d  689cca5600             -push 0x56ca9c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687964 /*0x56ca9c*/;
    cpu.esp -= 4;
    // 00533812  e801bbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533817  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533819  740c                   -je 0x533827
    if (cpu.flags.zf)
    {
        goto L_0x00533827;
    }
    // 0053381b  c705bcd45600ffffffff   -mov dword ptr [0x56d4bc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */) = 4294967295 /*0xffffffff*/;
    // 00533825  eb20                   -jmp 0x533847
    goto L_0x00533847;
L_0x00533827:
    // 00533827  833dbcd45600ff         +cmp dword ptr [0x56d4bc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053382e  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533833  7412                   -je 0x533847
    if (cpu.flags.zf)
    {
        goto L_0x00533847;
    }
    // 00533835  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533838  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053383b  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053383e  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533841  ff15bcd45600           -call dword ptr [0x56d4bc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690556) /* 0x56d4bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533847:
    // 00533847  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533848  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53384b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053384b  833dc0d4560000         +cmp dword ptr [0x56d4c0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533852  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533853  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533855  751f                   -jne 0x533876
    if (!cpu.flags.zf)
    {
        goto L_0x00533876;
    }
    // 00533857  68c0d45600             -push 0x56d4c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690560 /*0x56d4c0*/;
    cpu.esp -= 4;
    // 0053385c  68b0ca5600             -push 0x56cab0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5687984 /*0x56cab0*/;
    cpu.esp -= 4;
    // 00533861  e8b2baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533866  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533868  740c                   -je 0x533876
    if (cpu.flags.zf)
    {
        goto L_0x00533876;
    }
    // 0053386a  c705c0d45600ffffffff   -mov dword ptr [0x56d4c0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */) = 4294967295 /*0xffffffff*/;
    // 00533874  eb20                   -jmp 0x533896
    goto L_0x00533896;
L_0x00533876:
    // 00533876  833dc0d45600ff         +cmp dword ptr [0x56d4c0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053387d  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533882  7412                   -je 0x533896
    if (cpu.flags.zf)
    {
        goto L_0x00533896;
    }
    // 00533884  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533887  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053388a  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053388d  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533890  ff15c0d45600           -call dword ptr [0x56d4c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690560) /* 0x56d4c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533896:
    // 00533896  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533897  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53389a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053389a  833dc4d4560000         +cmp dword ptr [0x56d4c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338a1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005338a2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005338a4  751f                   -jne 0x5338c5
    if (!cpu.flags.zf)
    {
        goto L_0x005338c5;
    }
    // 005338a6  68c4d45600             -push 0x56d4c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690564 /*0x56d4c4*/;
    cpu.esp -= 4;
    // 005338ab  68c8ca5600             -push 0x56cac8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5688008 /*0x56cac8*/;
    cpu.esp -= 4;
    // 005338b0  e863baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005338b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005338b7  740c                   -je 0x5338c5
    if (cpu.flags.zf)
    {
        goto L_0x005338c5;
    }
    // 005338b9  c705c4d45600ffffffff   -mov dword ptr [0x56d4c4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */) = 4294967295 /*0xffffffff*/;
    // 005338c3  eb20                   -jmp 0x5338e5
    goto L_0x005338e5;
L_0x005338c5:
    // 005338c5  833dc4d45600ff         +cmp dword ptr [0x56d4c4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338cc  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005338d1  7412                   -je 0x5338e5
    if (cpu.flags.zf)
    {
        goto L_0x005338e5;
    }
    // 005338d3  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005338d6  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005338d9  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005338dc  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005338df  ff15c4d45600           -call dword ptr [0x56d4c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690564) /* 0x56d4c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005338e5:
    // 005338e5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005338e6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5338e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005338e9  833dc8d4560000         +cmp dword ptr [0x56d4c8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005338f0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005338f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005338f3  751f                   -jne 0x533914
    if (!cpu.flags.zf)
    {
        goto L_0x00533914;
    }
    // 005338f5  68c8d45600             -push 0x56d4c8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690568 /*0x56d4c8*/;
    cpu.esp -= 4;
    // 005338fa  68e0ca5600             -push 0x56cae0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5688032 /*0x56cae0*/;
    cpu.esp -= 4;
    // 005338ff  e814baffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533904  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533906  740c                   -je 0x533914
    if (cpu.flags.zf)
    {
        goto L_0x00533914;
    }
    // 00533908  c705c8d45600ffffffff   -mov dword ptr [0x56d4c8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */) = 4294967295 /*0xffffffff*/;
    // 00533912  eb32                   -jmp 0x533946
    goto L_0x00533946;
L_0x00533914:
    // 00533914  833dc8d45600ff         +cmp dword ptr [0x56d4c8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053391b  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533920  7424                   -je 0x533946
    if (cpu.flags.zf)
    {
        goto L_0x00533946;
    }
    // 00533922  ff752c                 -push dword ptr [ebp + 0x2c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 00533925  ff7528                 -push dword ptr [ebp + 0x28]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00533928  ff7524                 -push dword ptr [ebp + 0x24]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0053392b  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053392e  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00533931  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533934  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533937  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053393a  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053393d  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533940  ff15c8d45600           -call dword ptr [0x56d4c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690568) /* 0x56d4c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533946:
    // 00533946  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533947  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_53394a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053394a  833dccd4560000         +cmp dword ptr [0x56d4cc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00533951  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00533952  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00533954  751f                   -jne 0x533975
    if (!cpu.flags.zf)
    {
        goto L_0x00533975;
    }
    // 00533956  68ccd45600             -push 0x56d4cc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690572 /*0x56d4cc*/;
    cpu.esp -= 4;
    // 0053395b  68f8ca5600             -push 0x56caf8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5688056 /*0x56caf8*/;
    cpu.esp -= 4;
    // 00533960  e8b3b9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00533965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00533967  740c                   -je 0x533975
    if (cpu.flags.zf)
    {
        goto L_0x00533975;
    }
    // 00533969  c705ccd45600ffffffff   -mov dword ptr [0x56d4cc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */) = 4294967295 /*0xffffffff*/;
    // 00533973  eb32                   -jmp 0x5339a7
    goto L_0x005339a7;
L_0x00533975:
    // 00533975  833dccd45600ff         +cmp dword ptr [0x56d4cc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053397c  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 00533981  7424                   -je 0x5339a7
    if (cpu.flags.zf)
    {
        goto L_0x005339a7;
    }
    // 00533983  ff752c                 -push dword ptr [ebp + 0x2c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 00533986  ff7528                 -push dword ptr [ebp + 0x28]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00533989  ff7524                 -push dword ptr [ebp + 0x24]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 0053398c  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053398f  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00533992  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00533995  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00533998  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053399b  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053399e  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005339a1  ff15ccd45600           -call dword ptr [0x56d4cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690572) /* 0x56d4cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005339a7:
    // 005339a7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005339a8  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_5339ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005339ab  833dd0d4560000         +cmp dword ptr [0x56d4d0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005339b2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005339b3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005339b5  751f                   -jne 0x5339d6
    if (!cpu.flags.zf)
    {
        goto L_0x005339d6;
    }
    // 005339b7  68d0d45600             -push 0x56d4d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5690576 /*0x56d4d0*/;
    cpu.esp -= 4;
    // 005339bc  6810cb5600             -push 0x56cb10
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5688080 /*0x56cb10*/;
    cpu.esp -= 4;
    // 005339c1  e852b9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005339c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005339c8  740c                   -je 0x5339d6
    if (cpu.flags.zf)
    {
        goto L_0x005339d6;
    }
    // 005339ca  c705d0d45600ffffffff   -mov dword ptr [0x56d4d0], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */) = 4294967295 /*0xffffffff*/;
    // 005339d4  eb32                   -jmp 0x533a08
    goto L_0x00533a08;
L_0x005339d6:
    // 005339d6  833dd0d45600ff         +cmp dword ptr [0x56d4d0], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005339dd  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 005339e2  7424                   -je 0x533a08
    if (cpu.flags.zf)
    {
        goto L_0x00533a08;
    }
    // 005339e4  ff752c                 -push dword ptr [ebp + 0x2c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 005339e7  ff7528                 -push dword ptr [ebp + 0x28]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 005339ea  ff7524                 -push dword ptr [ebp + 0x24]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 005339ed  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005339f0  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005339f3  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005339f6  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005339f9  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005339fc  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005339ff  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00533a02  ff15d0d45600           -call dword ptr [0x56d4d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5690576) /* 0x56d4d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00533a08:
    // 00533a08  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00533a09  c22800                 -ret 0x28
    cpu.esp += 4+40 /*0x28*/;
    return;
}

/* align: skip  */
void Application::sub_533a0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a0c  ff2594455300           -jmp dword ptr [0x534594]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457300), cpu);
}

/* align: skip  */
void Application::sub_533a12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a12  ff252c455300           -jmp dword ptr [0x53452c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457196), cpu);
}

/* align: skip  */
void Application::sub_533a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a18  ff25d4445300           -jmp dword ptr [0x5344d4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457108), cpu);
}

/* align: skip  */
void Application::sub_533a1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a1e  ff2500465300           -jmp dword ptr [0x534600]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457408), cpu);
}

/* align: skip  */
void Application::sub_533a24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a24  ff252c465300           -jmp dword ptr [0x53462c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457452), cpu);
}

/* align: skip  */
void Application::sub_533a2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a2a  ff2598455300           -jmp dword ptr [0x534598]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457304), cpu);
}

/* align: skip  */
void Application::sub_533a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a30  ff2548455300           -jmp dword ptr [0x534548]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457224), cpu);
}

/* align: skip  */
void Application::sub_533a36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a36  ff2510465300           -jmp dword ptr [0x534610]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457424), cpu);
}

/* align: skip  */
void Application::sub_533a3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a3c  ff2518465300           -jmp dword ptr [0x534618]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457432), cpu);
}

/* align: skip  */
void Application::sub_533a42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a42  ff250c465300           -jmp dword ptr [0x53460c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457420), cpu);
}

/* align: skip  */
void Application::sub_533a48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a48  ff2514465300           -jmp dword ptr [0x534614]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457428), cpu);
}

/* align: skip  */
void Application::sub_533a4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a4e  ff255c455300           -jmp dword ptr [0x53455c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457244), cpu);
}

/* align: skip  */
void Application::sub_533a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a54  ff25f8455300           -jmp dword ptr [0x5345f8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457400), cpu);
}

/* align: skip  */
void Application::sub_533a5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a5a  ff2538465300           -jmp dword ptr [0x534638]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457464), cpu);
}

/* align: skip  */
void Application::sub_533a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a60  ff25c4455300           -jmp dword ptr [0x5345c4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457348), cpu);
}

/* align: skip  */
void Application::sub_533a66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a66  ff25f0445300           -jmp dword ptr [0x5344f0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457136), cpu);
}

/* align: skip  */
void Application::sub_533a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a6c  ff25c8455300           -jmp dword ptr [0x5345c8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457352), cpu);
}

/* align: skip  */
void Application::sub_533a72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a72  ff25e8445300           -jmp dword ptr [0x5344e8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457128), cpu);
}

/* align: skip  */
void Application::sub_533a78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a78  ff25bc445300           -jmp dword ptr [0x5344bc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457084), cpu);
}

/* align: skip  */
void Application::sub_533a7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a7e  ff25a8455300           -jmp dword ptr [0x5345a8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457320), cpu);
}

/* align: skip  */
void Application::sub_533a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a84  ff2554455300           -jmp dword ptr [0x534554]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457236), cpu);
}

/* align: skip  */
void Application::sub_533a8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a8a  ff2548475300           -jmp dword ptr [0x534748]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457736), cpu);
}

/* align: skip  */
void Application::sub_533a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a90  ff256c455300           -jmp dword ptr [0x53456c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457260), cpu);
}

/* align: skip  */
void Application::sub_533a96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a96  ff2538455300           -jmp dword ptr [0x534538]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457208), cpu);
}

/* align: skip  */
void Application::sub_533a9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533a9c  ff2508455300           -jmp dword ptr [0x534508]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457160), cpu);
}

/* align: skip  */
void Application::sub_533aa2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aa2  ff2534465300           -jmp dword ptr [0x534634]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457460), cpu);
}

/* align: skip  */
void Application::sub_533aa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00533aa8  ff2560455300           -jmp dword ptr [0x534560]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5457248), cpu);
}

}
