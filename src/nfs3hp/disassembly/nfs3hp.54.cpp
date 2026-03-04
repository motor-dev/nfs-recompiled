#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_530591(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530591  833d20d2560000         +cmp dword ptr [0x56d220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530598  751f                   -jne 0x5305b9
    if (!cpu.flags.zf)
    {
        goto L_0x005305b9;
    }
    // 0053059a  6820d25600             -push 0x56d220
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689888 /*0x56d220*/;
    cpu.esp -= 4;
    // 0053059f  6864be5600             -push 0x56be64
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684836 /*0x56be64*/;
    cpu.esp -= 4;
    // 005305a4  e86fedffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005305a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005305ab  740c                   -je 0x5305b9
    if (cpu.flags.zf)
    {
        goto L_0x005305b9;
    }
    // 005305ad  c70520d25600ffffffff   -mov dword ptr [0x56d220], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */) = 4294967295 /*0xffffffff*/;
    // 005305b7  eb1c                   -jmp 0x5305d5
    goto L_0x005305d5;
L_0x005305b9:
    // 005305b9  833d20d25600ff         +cmp dword ptr [0x56d220], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005305c0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005305c5  740e                   -je 0x5305d5
    if (cpu.flags.zf)
    {
        goto L_0x005305d5;
    }
    // 005305c7  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005305cb  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005305cf  ff1520d25600           -call dword ptr [0x56d220]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689888) /* 0x56d220 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005305d5:
    // 005305d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5305d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005305d8  833d24d2560000         +cmp dword ptr [0x56d224], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005305df  751f                   -jne 0x530600
    if (!cpu.flags.zf)
    {
        goto L_0x00530600;
    }
    // 005305e1  6824d25600             -push 0x56d224
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689892 /*0x56d224*/;
    cpu.esp -= 4;
    // 005305e6  6878be5600             -push 0x56be78
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684856 /*0x56be78*/;
    cpu.esp -= 4;
    // 005305eb  e828edffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005305f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005305f2  740c                   -je 0x530600
    if (cpu.flags.zf)
    {
        goto L_0x00530600;
    }
    // 005305f4  c70524d25600ffffffff   -mov dword ptr [0x56d224], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */) = 4294967295 /*0xffffffff*/;
    // 005305fe  eb1c                   -jmp 0x53061c
    goto L_0x0053061c;
L_0x00530600:
    // 00530600  833d24d25600ff         +cmp dword ptr [0x56d224], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530607  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053060c  740e                   -je 0x53061c
    if (cpu.flags.zf)
    {
        goto L_0x0053061c;
    }
    // 0053060e  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530612  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530616  ff1524d25600           -call dword ptr [0x56d224]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689892) /* 0x56d224 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053061c:
    // 0053061c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_53061f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053061f  833d28d2560000         +cmp dword ptr [0x56d228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530626  751f                   -jne 0x530647
    if (!cpu.flags.zf)
    {
        goto L_0x00530647;
    }
    // 00530628  6828d25600             -push 0x56d228
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689896 /*0x56d228*/;
    cpu.esp -= 4;
    // 0053062d  688cbe5600             -push 0x56be8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684876 /*0x56be8c*/;
    cpu.esp -= 4;
    // 00530632  e8e1ecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530639  740c                   -je 0x530647
    if (cpu.flags.zf)
    {
        goto L_0x00530647;
    }
    // 0053063b  c70528d25600ffffffff   -mov dword ptr [0x56d228], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */) = 4294967295 /*0xffffffff*/;
    // 00530645  eb1c                   -jmp 0x530663
    goto L_0x00530663;
L_0x00530647:
    // 00530647  833d28d25600ff         +cmp dword ptr [0x56d228], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053064e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530653  740e                   -je 0x530663
    if (cpu.flags.zf)
    {
        goto L_0x00530663;
    }
    // 00530655  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530659  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053065d  ff1528d25600           -call dword ptr [0x56d228]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689896) /* 0x56d228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530663:
    // 00530663  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530666(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530666  833d2cd2560000         +cmp dword ptr [0x56d22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053066d  751f                   -jne 0x53068e
    if (!cpu.flags.zf)
    {
        goto L_0x0053068e;
    }
    // 0053066f  682cd25600             -push 0x56d22c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689900 /*0x56d22c*/;
    cpu.esp -= 4;
    // 00530674  68a4be5600             -push 0x56bea4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684900 /*0x56bea4*/;
    cpu.esp -= 4;
    // 00530679  e89aecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053067e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530680  740c                   -je 0x53068e
    if (cpu.flags.zf)
    {
        goto L_0x0053068e;
    }
    // 00530682  c7052cd25600ffffffff   -mov dword ptr [0x56d22c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */) = 4294967295 /*0xffffffff*/;
    // 0053068c  eb20                   -jmp 0x5306ae
    goto L_0x005306ae;
L_0x0053068e:
    // 0053068e  833d2cd25600ff         +cmp dword ptr [0x56d22c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530695  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053069a  7412                   -je 0x5306ae
    if (cpu.flags.zf)
    {
        goto L_0x005306ae;
    }
    // 0053069c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306a8  ff152cd25600           -call dword ptr [0x56d22c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689900) /* 0x56d22c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005306ae:
    // 005306ae  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5306b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005306b1  833d30d2560000         +cmp dword ptr [0x56d230], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005306b8  751f                   -jne 0x5306d9
    if (!cpu.flags.zf)
    {
        goto L_0x005306d9;
    }
    // 005306ba  6830d25600             -push 0x56d230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689904 /*0x56d230*/;
    cpu.esp -= 4;
    // 005306bf  68b4be5600             -push 0x56beb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684916 /*0x56beb4*/;
    cpu.esp -= 4;
    // 005306c4  e84fecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005306c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005306cb  740c                   -je 0x5306d9
    if (cpu.flags.zf)
    {
        goto L_0x005306d9;
    }
    // 005306cd  c70530d25600ffffffff   -mov dword ptr [0x56d230], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */) = 4294967295 /*0xffffffff*/;
    // 005306d7  eb20                   -jmp 0x5306f9
    goto L_0x005306f9;
L_0x005306d9:
    // 005306d9  833d30d25600ff         +cmp dword ptr [0x56d230], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005306e0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005306e5  7412                   -je 0x5306f9
    if (cpu.flags.zf)
    {
        goto L_0x005306f9;
    }
    // 005306e7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306eb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306ef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005306f3  ff1530d25600           -call dword ptr [0x56d230]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689904) /* 0x56d230 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005306f9:
    // 005306f9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5306fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005306fc  833d34d2560000         +cmp dword ptr [0x56d234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530703  751f                   -jne 0x530724
    if (!cpu.flags.zf)
    {
        goto L_0x00530724;
    }
    // 00530705  6834d25600             -push 0x56d234
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689908 /*0x56d234*/;
    cpu.esp -= 4;
    // 0053070a  68c4be5600             -push 0x56bec4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684932 /*0x56bec4*/;
    cpu.esp -= 4;
    // 0053070f  e804ecffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530714  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530716  740c                   -je 0x530724
    if (cpu.flags.zf)
    {
        goto L_0x00530724;
    }
    // 00530718  c70534d25600ffffffff   -mov dword ptr [0x56d234], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */) = 4294967295 /*0xffffffff*/;
    // 00530722  eb20                   -jmp 0x530744
    goto L_0x00530744;
L_0x00530724:
    // 00530724  833d34d25600ff         +cmp dword ptr [0x56d234], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053072b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530730  7412                   -je 0x530744
    if (cpu.flags.zf)
    {
        goto L_0x00530744;
    }
    // 00530732  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530736  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053073a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053073e  ff1534d25600           -call dword ptr [0x56d234]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689908) /* 0x56d234 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530744:
    // 00530744  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530747(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530747  833d38d2560000         +cmp dword ptr [0x56d238], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053074e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053074f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530751  751f                   -jne 0x530772
    if (!cpu.flags.zf)
    {
        goto L_0x00530772;
    }
    // 00530753  6838d25600             -push 0x56d238
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689912 /*0x56d238*/;
    cpu.esp -= 4;
    // 00530758  68d4be5600             -push 0x56bed4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684948 /*0x56bed4*/;
    cpu.esp -= 4;
    // 0053075d  e8b6ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530762  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530764  740c                   -je 0x530772
    if (cpu.flags.zf)
    {
        goto L_0x00530772;
    }
    // 00530766  c70538d25600ffffffff   -mov dword ptr [0x56d238], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */) = 4294967295 /*0xffffffff*/;
    // 00530770  eb23                   -jmp 0x530795
    goto L_0x00530795;
L_0x00530772:
    // 00530772  833d38d25600ff         +cmp dword ptr [0x56d238], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530779  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053077e  7415                   -je 0x530795
    if (cpu.flags.zf)
    {
        goto L_0x00530795;
    }
    // 00530780  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530783  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530786  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530789  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053078c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053078f  ff1538d25600           -call dword ptr [0x56d238]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689912) /* 0x56d238 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530795:
    // 00530795  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530796  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_530799(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530799  833d3cd2560000         +cmp dword ptr [0x56d23c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005307a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005307a3  751f                   -jne 0x5307c4
    if (!cpu.flags.zf)
    {
        goto L_0x005307c4;
    }
    // 005307a5  683cd25600             -push 0x56d23c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689916 /*0x56d23c*/;
    cpu.esp -= 4;
    // 005307aa  68e4be5600             -push 0x56bee4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684964 /*0x56bee4*/;
    cpu.esp -= 4;
    // 005307af  e864ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005307b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005307b6  740c                   -je 0x5307c4
    if (cpu.flags.zf)
    {
        goto L_0x005307c4;
    }
    // 005307b8  c7053cd25600ffffffff   -mov dword ptr [0x56d23c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */) = 4294967295 /*0xffffffff*/;
    // 005307c2  eb23                   -jmp 0x5307e7
    goto L_0x005307e7;
L_0x005307c4:
    // 005307c4  833d3cd25600ff         +cmp dword ptr [0x56d23c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307cb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005307d0  7415                   -je 0x5307e7
    if (cpu.flags.zf)
    {
        goto L_0x005307e7;
    }
    // 005307d2  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005307d5  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005307d8  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005307db  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005307de  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005307e1  ff153cd25600           -call dword ptr [0x56d23c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689916) /* 0x56d23c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005307e7:
    // 005307e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005307e8  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5307eb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005307eb  833d40d2560000         +cmp dword ptr [0x56d240], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005307f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005307f3  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005307f5  751f                   -jne 0x530816
    if (!cpu.flags.zf)
    {
        goto L_0x00530816;
    }
    // 005307f7  6840d25600             -push 0x56d240
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689920 /*0x56d240*/;
    cpu.esp -= 4;
    // 005307fc  68f4be5600             -push 0x56bef4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684980 /*0x56bef4*/;
    cpu.esp -= 4;
    // 00530801  e812ebffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530806  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530808  740c                   -je 0x530816
    if (cpu.flags.zf)
    {
        goto L_0x00530816;
    }
    // 0053080a  c70540d25600ffffffff   -mov dword ptr [0x56d240], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */) = 4294967295 /*0xffffffff*/;
    // 00530814  eb23                   -jmp 0x530839
    goto L_0x00530839;
L_0x00530816:
    // 00530816  833d40d25600ff         +cmp dword ptr [0x56d240], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053081d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530822  7415                   -je 0x530839
    if (cpu.flags.zf)
    {
        goto L_0x00530839;
    }
    // 00530824  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530827  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053082a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053082d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530830  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530833  ff1540d25600           -call dword ptr [0x56d240]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689920) /* 0x56d240 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530839:
    // 00530839  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053083a  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_53083d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053083d  833d44d2560000         +cmp dword ptr [0x56d244], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530844  751f                   -jne 0x530865
    if (!cpu.flags.zf)
    {
        goto L_0x00530865;
    }
    // 00530846  6844d25600             -push 0x56d244
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689924 /*0x56d244*/;
    cpu.esp -= 4;
    // 0053084b  6804bf5600             -push 0x56bf04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5684996 /*0x56bf04*/;
    cpu.esp -= 4;
    // 00530850  e8c3eaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530855  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530857  740c                   -je 0x530865
    if (cpu.flags.zf)
    {
        goto L_0x00530865;
    }
    // 00530859  c70544d25600ffffffff   -mov dword ptr [0x56d244], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */) = 4294967295 /*0xffffffff*/;
    // 00530863  eb20                   -jmp 0x530885
    goto L_0x00530885;
L_0x00530865:
    // 00530865  833d44d25600ff         +cmp dword ptr [0x56d244], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053086c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530871  7412                   -je 0x530885
    if (cpu.flags.zf)
    {
        goto L_0x00530885;
    }
    // 00530873  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530877  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053087b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053087f  ff1544d25600           -call dword ptr [0x56d244]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689924) /* 0x56d244 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530885:
    // 00530885  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530888  833d48d2560000         +cmp dword ptr [0x56d248], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053088f  751f                   -jne 0x5308b0
    if (!cpu.flags.zf)
    {
        goto L_0x005308b0;
    }
    // 00530891  6848d25600             -push 0x56d248
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689928 /*0x56d248*/;
    cpu.esp -= 4;
    // 00530896  6818bf5600             -push 0x56bf18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685016 /*0x56bf18*/;
    cpu.esp -= 4;
    // 0053089b  e878eaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005308a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005308a2  740c                   -je 0x5308b0
    if (cpu.flags.zf)
    {
        goto L_0x005308b0;
    }
    // 005308a4  c70548d25600ffffffff   -mov dword ptr [0x56d248], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */) = 4294967295 /*0xffffffff*/;
    // 005308ae  eb20                   -jmp 0x5308d0
    goto L_0x005308d0;
L_0x005308b0:
    // 005308b0  833d48d25600ff         +cmp dword ptr [0x56d248], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005308b7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005308bc  7412                   -je 0x5308d0
    if (cpu.flags.zf)
    {
        goto L_0x005308d0;
    }
    // 005308be  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308c2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308c6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005308ca  ff1548d25600           -call dword ptr [0x56d248]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689928) /* 0x56d248 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005308d0:
    // 005308d0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5308d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005308d3  833d4cd2560000         +cmp dword ptr [0x56d24c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005308da  751f                   -jne 0x5308fb
    if (!cpu.flags.zf)
    {
        goto L_0x005308fb;
    }
    // 005308dc  684cd25600             -push 0x56d24c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689932 /*0x56d24c*/;
    cpu.esp -= 4;
    // 005308e1  682cbf5600             -push 0x56bf2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685036 /*0x56bf2c*/;
    cpu.esp -= 4;
    // 005308e6  e82deaffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005308eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005308ed  740c                   -je 0x5308fb
    if (cpu.flags.zf)
    {
        goto L_0x005308fb;
    }
    // 005308ef  c7054cd25600ffffffff   -mov dword ptr [0x56d24c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */) = 4294967295 /*0xffffffff*/;
    // 005308f9  eb20                   -jmp 0x53091b
    goto L_0x0053091b;
L_0x005308fb:
    // 005308fb  833d4cd25600ff         +cmp dword ptr [0x56d24c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530902  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530907  7412                   -je 0x53091b
    if (cpu.flags.zf)
    {
        goto L_0x0053091b;
    }
    // 00530909  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053090d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530911  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530915  ff154cd25600           -call dword ptr [0x56d24c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689932) /* 0x56d24c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053091b:
    // 0053091b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53091e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053091e  833d50d2560000         +cmp dword ptr [0x56d250], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530925  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530926  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530928  751f                   -jne 0x530949
    if (!cpu.flags.zf)
    {
        goto L_0x00530949;
    }
    // 0053092a  6850d25600             -push 0x56d250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689936 /*0x56d250*/;
    cpu.esp -= 4;
    // 0053092f  6840bf5600             -push 0x56bf40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685056 /*0x56bf40*/;
    cpu.esp -= 4;
    // 00530934  e8dfe9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530939  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053093b  740c                   -je 0x530949
    if (cpu.flags.zf)
    {
        goto L_0x00530949;
    }
    // 0053093d  c70550d25600ffffffff   -mov dword ptr [0x56d250], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */) = 4294967295 /*0xffffffff*/;
    // 00530947  eb20                   -jmp 0x530969
    goto L_0x00530969;
L_0x00530949:
    // 00530949  833d50d25600ff         +cmp dword ptr [0x56d250], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530950  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530955  7412                   -je 0x530969
    if (cpu.flags.zf)
    {
        goto L_0x00530969;
    }
    // 00530957  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053095a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053095d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530960  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530963  ff1550d25600           -call dword ptr [0x56d250]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689936) /* 0x56d250 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530969:
    // 00530969  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053096a  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53096d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053096d  833d54d2560000         +cmp dword ptr [0x56d254], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530974  751f                   -jne 0x530995
    if (!cpu.flags.zf)
    {
        goto L_0x00530995;
    }
    // 00530976  6854d25600             -push 0x56d254
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689940 /*0x56d254*/;
    cpu.esp -= 4;
    // 0053097b  6850bf5600             -push 0x56bf50
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685072 /*0x56bf50*/;
    cpu.esp -= 4;
    // 00530980  e893e9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530985  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530987  740c                   -je 0x530995
    if (cpu.flags.zf)
    {
        goto L_0x00530995;
    }
    // 00530989  c70554d25600ffffffff   -mov dword ptr [0x56d254], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */) = 4294967295 /*0xffffffff*/;
    // 00530993  eb20                   -jmp 0x5309b5
    goto L_0x005309b5;
L_0x00530995:
    // 00530995  833d54d25600ff         +cmp dword ptr [0x56d254], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053099c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005309a1  7412                   -je 0x5309b5
    if (cpu.flags.zf)
    {
        goto L_0x005309b5;
    }
    // 005309a3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309a7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309ab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309af  ff1554d25600           -call dword ptr [0x56d254]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689940) /* 0x56d254 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005309b5:
    // 005309b5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5309b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005309b8  833d58d2560000         +cmp dword ptr [0x56d258], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005309bf  751f                   -jne 0x5309e0
    if (!cpu.flags.zf)
    {
        goto L_0x005309e0;
    }
    // 005309c1  6858d25600             -push 0x56d258
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689944 /*0x56d258*/;
    cpu.esp -= 4;
    // 005309c6  685cbf5600             -push 0x56bf5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685084 /*0x56bf5c*/;
    cpu.esp -= 4;
    // 005309cb  e848e9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005309d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005309d2  740c                   -je 0x5309e0
    if (cpu.flags.zf)
    {
        goto L_0x005309e0;
    }
    // 005309d4  c70558d25600ffffffff   -mov dword ptr [0x56d258], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */) = 4294967295 /*0xffffffff*/;
    // 005309de  eb20                   -jmp 0x530a00
    goto L_0x00530a00;
L_0x005309e0:
    // 005309e0  833d58d25600ff         +cmp dword ptr [0x56d258], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005309e7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005309ec  7412                   -je 0x530a00
    if (cpu.flags.zf)
    {
        goto L_0x00530a00;
    }
    // 005309ee  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309f2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309f6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005309fa  ff1558d25600           -call dword ptr [0x56d258]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689944) /* 0x56d258 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a00:
    // 00530a00  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530a03(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530a03  833d5cd2560000         +cmp dword ptr [0x56d25c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a0a  751f                   -jne 0x530a2b
    if (!cpu.flags.zf)
    {
        goto L_0x00530a2b;
    }
    // 00530a0c  685cd25600             -push 0x56d25c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689948 /*0x56d25c*/;
    cpu.esp -= 4;
    // 00530a11  686cbf5600             -push 0x56bf6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685100 /*0x56bf6c*/;
    cpu.esp -= 4;
    // 00530a16  e8fde8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530a1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530a1d  740c                   -je 0x530a2b
    if (cpu.flags.zf)
    {
        goto L_0x00530a2b;
    }
    // 00530a1f  c7055cd25600ffffffff   -mov dword ptr [0x56d25c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */) = 4294967295 /*0xffffffff*/;
    // 00530a29  eb20                   -jmp 0x530a4b
    goto L_0x00530a4b;
L_0x00530a2b:
    // 00530a2b  833d5cd25600ff         +cmp dword ptr [0x56d25c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a32  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530a37  7412                   -je 0x530a4b
    if (cpu.flags.zf)
    {
        goto L_0x00530a4b;
    }
    // 00530a39  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a3d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a41  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a45  ff155cd25600           -call dword ptr [0x56d25c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689948) /* 0x56d25c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a4b:
    // 00530a4b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530a4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530a4e  833d60d2560000         +cmp dword ptr [0x56d260], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530a56  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530a58  751f                   -jne 0x530a79
    if (!cpu.flags.zf)
    {
        goto L_0x00530a79;
    }
    // 00530a5a  6860d25600             -push 0x56d260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689952 /*0x56d260*/;
    cpu.esp -= 4;
    // 00530a5f  687cbf5600             -push 0x56bf7c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685116 /*0x56bf7c*/;
    cpu.esp -= 4;
    // 00530a64  e8afe8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530a69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530a6b  740c                   -je 0x530a79
    if (cpu.flags.zf)
    {
        goto L_0x00530a79;
    }
    // 00530a6d  c70560d25600ffffffff   -mov dword ptr [0x56d260], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */) = 4294967295 /*0xffffffff*/;
    // 00530a77  eb26                   -jmp 0x530a9f
    goto L_0x00530a9f;
L_0x00530a79:
    // 00530a79  833d60d25600ff         +cmp dword ptr [0x56d260], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530a80  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530a85  7418                   -je 0x530a9f
    if (cpu.flags.zf)
    {
        goto L_0x00530a9f;
    }
    // 00530a87  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530a8a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530a8d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530a90  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530a93  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530a96  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530a99  ff1560d25600           -call dword ptr [0x56d260]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689952) /* 0x56d260 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530a9f:
    // 00530a9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530aa0  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530aa3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530aa3  833d64d2560000         +cmp dword ptr [0x56d264], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530aaa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530aab  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530aad  751f                   -jne 0x530ace
    if (!cpu.flags.zf)
    {
        goto L_0x00530ace;
    }
    // 00530aaf  6864d25600             -push 0x56d264
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689956 /*0x56d264*/;
    cpu.esp -= 4;
    // 00530ab4  6888bf5600             -push 0x56bf88
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685128 /*0x56bf88*/;
    cpu.esp -= 4;
    // 00530ab9  e85ae8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530abe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530ac0  740c                   -je 0x530ace
    if (cpu.flags.zf)
    {
        goto L_0x00530ace;
    }
    // 00530ac2  c70564d25600ffffffff   -mov dword ptr [0x56d264], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */) = 4294967295 /*0xffffffff*/;
    // 00530acc  eb26                   -jmp 0x530af4
    goto L_0x00530af4;
L_0x00530ace:
    // 00530ace  833d64d25600ff         +cmp dword ptr [0x56d264], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ad5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ada  7418                   -je 0x530af4
    if (cpu.flags.zf)
    {
        goto L_0x00530af4;
    }
    // 00530adc  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530adf  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530ae2  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530ae5  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530ae8  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530aeb  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530aee  ff1564d25600           -call dword ptr [0x56d264]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689956) /* 0x56d264 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530af4:
    // 00530af4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530af5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530af8  833d68d2560000         +cmp dword ptr [0x56d268], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530aff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00530b00  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00530b02  751f                   -jne 0x530b23
    if (!cpu.flags.zf)
    {
        goto L_0x00530b23;
    }
    // 00530b04  6868d25600             -push 0x56d268
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689960 /*0x56d268*/;
    cpu.esp -= 4;
    // 00530b09  6894bf5600             -push 0x56bf94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685140 /*0x56bf94*/;
    cpu.esp -= 4;
    // 00530b0e  e805e8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530b13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530b15  740c                   -je 0x530b23
    if (cpu.flags.zf)
    {
        goto L_0x00530b23;
    }
    // 00530b17  c70568d25600ffffffff   -mov dword ptr [0x56d268], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */) = 4294967295 /*0xffffffff*/;
    // 00530b21  eb26                   -jmp 0x530b49
    goto L_0x00530b49;
L_0x00530b23:
    // 00530b23  833d68d25600ff         +cmp dword ptr [0x56d268], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b2a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530b2f  7418                   -je 0x530b49
    if (cpu.flags.zf)
    {
        goto L_0x00530b49;
    }
    // 00530b31  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00530b34  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00530b37  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00530b3a  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00530b3d  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530b40  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b43  ff1568d25600           -call dword ptr [0x56d268]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689960) /* 0x56d268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530b49:
    // 00530b49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00530b4a  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_530b4d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530b4d  833d6cd2560000         +cmp dword ptr [0x56d26c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b54  751f                   -jne 0x530b75
    if (!cpu.flags.zf)
    {
        goto L_0x00530b75;
    }
    // 00530b56  686cd25600             -push 0x56d26c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689964 /*0x56d26c*/;
    cpu.esp -= 4;
    // 00530b5b  68a0bf5600             -push 0x56bfa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685152 /*0x56bfa0*/;
    cpu.esp -= 4;
    // 00530b60  e8b3e7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530b65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530b67  740c                   -je 0x530b75
    if (cpu.flags.zf)
    {
        goto L_0x00530b75;
    }
    // 00530b69  c7056cd25600ffffffff   -mov dword ptr [0x56d26c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */) = 4294967295 /*0xffffffff*/;
    // 00530b73  eb1c                   -jmp 0x530b91
    goto L_0x00530b91;
L_0x00530b75:
    // 00530b75  833d6cd25600ff         +cmp dword ptr [0x56d26c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b7c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530b81  740e                   -je 0x530b91
    if (cpu.flags.zf)
    {
        goto L_0x00530b91;
    }
    // 00530b83  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b87  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530b8b  ff156cd25600           -call dword ptr [0x56d26c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689964) /* 0x56d26c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530b91:
    // 00530b91  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530b94  833d70d2560000         +cmp dword ptr [0x56d270], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530b9b  751f                   -jne 0x530bbc
    if (!cpu.flags.zf)
    {
        goto L_0x00530bbc;
    }
    // 00530b9d  6870d25600             -push 0x56d270
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689968 /*0x56d270*/;
    cpu.esp -= 4;
    // 00530ba2  68b8bf5600             -push 0x56bfb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685176 /*0x56bfb8*/;
    cpu.esp -= 4;
    // 00530ba7  e86ce7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530bac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530bae  740c                   -je 0x530bbc
    if (cpu.flags.zf)
    {
        goto L_0x00530bbc;
    }
    // 00530bb0  c70570d25600ffffffff   -mov dword ptr [0x56d270], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */) = 4294967295 /*0xffffffff*/;
    // 00530bba  eb1c                   -jmp 0x530bd8
    goto L_0x00530bd8;
L_0x00530bbc:
    // 00530bbc  833d70d25600ff         +cmp dword ptr [0x56d270], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530bc3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530bc8  740e                   -je 0x530bd8
    if (cpu.flags.zf)
    {
        goto L_0x00530bd8;
    }
    // 00530bca  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530bce  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530bd2  ff1570d25600           -call dword ptr [0x56d270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689968) /* 0x56d270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530bd8:
    // 00530bd8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530bdb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530bdb  833d74d2560000         +cmp dword ptr [0x56d274], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530be2  751f                   -jne 0x530c03
    if (!cpu.flags.zf)
    {
        goto L_0x00530c03;
    }
    // 00530be4  6874d25600             -push 0x56d274
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689972 /*0x56d274*/;
    cpu.esp -= 4;
    // 00530be9  68d0bf5600             -push 0x56bfd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685200 /*0x56bfd0*/;
    cpu.esp -= 4;
    // 00530bee  e825e7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530bf5  740c                   -je 0x530c03
    if (cpu.flags.zf)
    {
        goto L_0x00530c03;
    }
    // 00530bf7  c70574d25600ffffffff   -mov dword ptr [0x56d274], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */) = 4294967295 /*0xffffffff*/;
    // 00530c01  eb1c                   -jmp 0x530c1f
    goto L_0x00530c1f;
L_0x00530c03:
    // 00530c03  833d74d25600ff         +cmp dword ptr [0x56d274], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c0a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530c0f  740e                   -je 0x530c1f
    if (cpu.flags.zf)
    {
        goto L_0x00530c1f;
    }
    // 00530c11  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530c15  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530c19  ff1574d25600           -call dword ptr [0x56d274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689972) /* 0x56d274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530c1f:
    // 00530c1f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530c22(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530c22  833d78d2560000         +cmp dword ptr [0x56d278], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c29  751f                   -jne 0x530c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00530c4a;
    }
    // 00530c2b  6878d25600             -push 0x56d278
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689976 /*0x56d278*/;
    cpu.esp -= 4;
    // 00530c30  68e8bf5600             -push 0x56bfe8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685224 /*0x56bfe8*/;
    cpu.esp -= 4;
    // 00530c35  e8dee6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530c3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530c3c  740c                   -je 0x530c4a
    if (cpu.flags.zf)
    {
        goto L_0x00530c4a;
    }
    // 00530c3e  c70578d25600ffffffff   -mov dword ptr [0x56d278], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */) = 4294967295 /*0xffffffff*/;
    // 00530c48  eb20                   -jmp 0x530c6a
    goto L_0x00530c6a;
L_0x00530c4a:
    // 00530c4a  833d78d25600ff         +cmp dword ptr [0x56d278], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c51  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530c56  7412                   -je 0x530c6a
    if (cpu.flags.zf)
    {
        goto L_0x00530c6a;
    }
    // 00530c58  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c5c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c60  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530c64  ff1578d25600           -call dword ptr [0x56d278]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689976) /* 0x56d278 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530c6a:
    // 00530c6a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530c6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530c6d  833d7cd2560000         +cmp dword ptr [0x56d27c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c74  751f                   -jne 0x530c95
    if (!cpu.flags.zf)
    {
        goto L_0x00530c95;
    }
    // 00530c76  687cd25600             -push 0x56d27c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689980 /*0x56d27c*/;
    cpu.esp -= 4;
    // 00530c7b  68f8bf5600             -push 0x56bff8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685240 /*0x56bff8*/;
    cpu.esp -= 4;
    // 00530c80  e893e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530c85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530c87  740c                   -je 0x530c95
    if (cpu.flags.zf)
    {
        goto L_0x00530c95;
    }
    // 00530c89  c7057cd25600ffffffff   -mov dword ptr [0x56d27c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */) = 4294967295 /*0xffffffff*/;
    // 00530c93  eb20                   -jmp 0x530cb5
    goto L_0x00530cb5;
L_0x00530c95:
    // 00530c95  833d7cd25600ff         +cmp dword ptr [0x56d27c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530c9c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ca1  7412                   -je 0x530cb5
    if (cpu.flags.zf)
    {
        goto L_0x00530cb5;
    }
    // 00530ca3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ca7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530cab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530caf  ff157cd25600           -call dword ptr [0x56d27c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689980) /* 0x56d27c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530cb5:
    // 00530cb5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530cb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530cb8  833d80d2560000         +cmp dword ptr [0x56d280], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530cbf  751f                   -jne 0x530ce0
    if (!cpu.flags.zf)
    {
        goto L_0x00530ce0;
    }
    // 00530cc1  6880d25600             -push 0x56d280
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689984 /*0x56d280*/;
    cpu.esp -= 4;
    // 00530cc6  6808c05600             -push 0x56c008
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685256 /*0x56c008*/;
    cpu.esp -= 4;
    // 00530ccb  e848e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530cd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530cd2  740c                   -je 0x530ce0
    if (cpu.flags.zf)
    {
        goto L_0x00530ce0;
    }
    // 00530cd4  c70580d25600ffffffff   -mov dword ptr [0x56d280], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */) = 4294967295 /*0xffffffff*/;
    // 00530cde  eb1c                   -jmp 0x530cfc
    goto L_0x00530cfc;
L_0x00530ce0:
    // 00530ce0  833d80d25600ff         +cmp dword ptr [0x56d280], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ce7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530cec  740e                   -je 0x530cfc
    if (cpu.flags.zf)
    {
        goto L_0x00530cfc;
    }
    // 00530cee  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530cf2  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530cf6  ff1580d25600           -call dword ptr [0x56d280]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689984) /* 0x56d280 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530cfc:
    // 00530cfc  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530cff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530cff  833d84d2560000         +cmp dword ptr [0x56d284], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d06  751f                   -jne 0x530d27
    if (!cpu.flags.zf)
    {
        goto L_0x00530d27;
    }
    // 00530d08  6884d25600             -push 0x56d284
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689988 /*0x56d284*/;
    cpu.esp -= 4;
    // 00530d0d  681cc05600             -push 0x56c01c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685276 /*0x56c01c*/;
    cpu.esp -= 4;
    // 00530d12  e801e6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530d17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530d19  740c                   -je 0x530d27
    if (cpu.flags.zf)
    {
        goto L_0x00530d27;
    }
    // 00530d1b  c70584d25600ffffffff   -mov dword ptr [0x56d284], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */) = 4294967295 /*0xffffffff*/;
    // 00530d25  eb1c                   -jmp 0x530d43
    goto L_0x00530d43;
L_0x00530d27:
    // 00530d27  833d84d25600ff         +cmp dword ptr [0x56d284], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d2e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530d33  740e                   -je 0x530d43
    if (cpu.flags.zf)
    {
        goto L_0x00530d43;
    }
    // 00530d35  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d39  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d3d  ff1584d25600           -call dword ptr [0x56d284]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689988) /* 0x56d284 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530d43:
    // 00530d43  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530d46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530d46  833d88d2560000         +cmp dword ptr [0x56d288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d4d  751f                   -jne 0x530d6e
    if (!cpu.flags.zf)
    {
        goto L_0x00530d6e;
    }
    // 00530d4f  6888d25600             -push 0x56d288
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689992 /*0x56d288*/;
    cpu.esp -= 4;
    // 00530d54  6834c05600             -push 0x56c034
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685300 /*0x56c034*/;
    cpu.esp -= 4;
    // 00530d59  e8bae5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530d5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530d60  740c                   -je 0x530d6e
    if (cpu.flags.zf)
    {
        goto L_0x00530d6e;
    }
    // 00530d62  c70588d25600ffffffff   -mov dword ptr [0x56d288], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */) = 4294967295 /*0xffffffff*/;
    // 00530d6c  eb1c                   -jmp 0x530d8a
    goto L_0x00530d8a;
L_0x00530d6e:
    // 00530d6e  833d88d25600ff         +cmp dword ptr [0x56d288], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d75  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530d7a  740e                   -je 0x530d8a
    if (cpu.flags.zf)
    {
        goto L_0x00530d8a;
    }
    // 00530d7c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d80  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00530d84  ff1588d25600           -call dword ptr [0x56d288]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689992) /* 0x56d288 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530d8a:
    // 00530d8a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_530d8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530d8d  833d8cd2560000         +cmp dword ptr [0x56d28c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530d94  751f                   -jne 0x530db5
    if (!cpu.flags.zf)
    {
        goto L_0x00530db5;
    }
    // 00530d96  688cd25600             -push 0x56d28c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5689996 /*0x56d28c*/;
    cpu.esp -= 4;
    // 00530d9b  684cc05600             -push 0x56c04c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685324 /*0x56c04c*/;
    cpu.esp -= 4;
    // 00530da0  e873e5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530da5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530da7  740c                   -je 0x530db5
    if (cpu.flags.zf)
    {
        goto L_0x00530db5;
    }
    // 00530da9  c7058cd25600ffffffff   -mov dword ptr [0x56d28c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */) = 4294967295 /*0xffffffff*/;
    // 00530db3  eb20                   -jmp 0x530dd5
    goto L_0x00530dd5;
L_0x00530db5:
    // 00530db5  833d8cd25600ff         +cmp dword ptr [0x56d28c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530dbc  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530dc1  7412                   -je 0x530dd5
    if (cpu.flags.zf)
    {
        goto L_0x00530dd5;
    }
    // 00530dc3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dc7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dcb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530dcf  ff158cd25600           -call dword ptr [0x56d28c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5689996) /* 0x56d28c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530dd5:
    // 00530dd5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530dd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530dd8  833d90d2560000         +cmp dword ptr [0x56d290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ddf  751f                   -jne 0x530e00
    if (!cpu.flags.zf)
    {
        goto L_0x00530e00;
    }
    // 00530de1  6890d25600             -push 0x56d290
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690000 /*0x56d290*/;
    cpu.esp -= 4;
    // 00530de6  685cc05600             -push 0x56c05c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685340 /*0x56c05c*/;
    cpu.esp -= 4;
    // 00530deb  e828e5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530df0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530df2  740c                   -je 0x530e00
    if (cpu.flags.zf)
    {
        goto L_0x00530e00;
    }
    // 00530df4  c70590d25600ffffffff   -mov dword ptr [0x56d290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */) = 4294967295 /*0xffffffff*/;
    // 00530dfe  eb20                   -jmp 0x530e20
    goto L_0x00530e20;
L_0x00530e00:
    // 00530e00  833d90d25600ff         +cmp dword ptr [0x56d290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e07  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530e0c  7412                   -je 0x530e20
    if (cpu.flags.zf)
    {
        goto L_0x00530e20;
    }
    // 00530e0e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e12  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e16  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e1a  ff1590d25600           -call dword ptr [0x56d290]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690000) /* 0x56d290 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530e20:
    // 00530e20  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530e23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530e23  833d94d2560000         +cmp dword ptr [0x56d294], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e2a  751f                   -jne 0x530e4b
    if (!cpu.flags.zf)
    {
        goto L_0x00530e4b;
    }
    // 00530e2c  6894d25600             -push 0x56d294
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690004 /*0x56d294*/;
    cpu.esp -= 4;
    // 00530e31  686cc05600             -push 0x56c06c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685356 /*0x56c06c*/;
    cpu.esp -= 4;
    // 00530e36  e8dde4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530e3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530e3d  740c                   -je 0x530e4b
    if (cpu.flags.zf)
    {
        goto L_0x00530e4b;
    }
    // 00530e3f  c70594d25600ffffffff   -mov dword ptr [0x56d294], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */) = 4294967295 /*0xffffffff*/;
    // 00530e49  eb20                   -jmp 0x530e6b
    goto L_0x00530e6b;
L_0x00530e4b:
    // 00530e4b  833d94d25600ff         +cmp dword ptr [0x56d294], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e52  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530e57  7412                   -je 0x530e6b
    if (cpu.flags.zf)
    {
        goto L_0x00530e6b;
    }
    // 00530e59  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e5d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e61  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530e65  ff1594d25600           -call dword ptr [0x56d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690004) /* 0x56d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530e6b:
    // 00530e6b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530e6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530e6e  833d98d2560000         +cmp dword ptr [0x56d298], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e75  751f                   -jne 0x530e96
    if (!cpu.flags.zf)
    {
        goto L_0x00530e96;
    }
    // 00530e77  6898d25600             -push 0x56d298
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690008 /*0x56d298*/;
    cpu.esp -= 4;
    // 00530e7c  687cc05600             -push 0x56c07c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685372 /*0x56c07c*/;
    cpu.esp -= 4;
    // 00530e81  e892e4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530e86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530e88  740c                   -je 0x530e96
    if (cpu.flags.zf)
    {
        goto L_0x00530e96;
    }
    // 00530e8a  c70598d25600ffffffff   -mov dword ptr [0x56d298], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */) = 4294967295 /*0xffffffff*/;
    // 00530e94  eb20                   -jmp 0x530eb6
    goto L_0x00530eb6;
L_0x00530e96:
    // 00530e96  833d98d25600ff         +cmp dword ptr [0x56d298], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530e9d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530ea2  7412                   -je 0x530eb6
    if (cpu.flags.zf)
    {
        goto L_0x00530eb6;
    }
    // 00530ea4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ea8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530eac  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530eb0  ff1598d25600           -call dword ptr [0x56d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690008) /* 0x56d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530eb6:
    // 00530eb6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530eb9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530eb9  833d9cd2560000         +cmp dword ptr [0x56d29c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ec0  751f                   -jne 0x530ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00530ee1;
    }
    // 00530ec2  689cd25600             -push 0x56d29c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690012 /*0x56d29c*/;
    cpu.esp -= 4;
    // 00530ec7  6894c05600             -push 0x56c094
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685396 /*0x56c094*/;
    cpu.esp -= 4;
    // 00530ecc  e847e4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530ed1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530ed3  740c                   -je 0x530ee1
    if (cpu.flags.zf)
    {
        goto L_0x00530ee1;
    }
    // 00530ed5  c7059cd25600ffffffff   -mov dword ptr [0x56d29c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */) = 4294967295 /*0xffffffff*/;
    // 00530edf  eb20                   -jmp 0x530f01
    goto L_0x00530f01;
L_0x00530ee1:
    // 00530ee1  833d9cd25600ff         +cmp dword ptr [0x56d29c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530ee8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530eed  7412                   -je 0x530f01
    if (cpu.flags.zf)
    {
        goto L_0x00530f01;
    }
    // 00530eef  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ef3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530ef7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530efb  ff159cd25600           -call dword ptr [0x56d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690012) /* 0x56d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f01:
    // 00530f01  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f04  833da0d2560000         +cmp dword ptr [0x56d2a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f0b  751f                   -jne 0x530f2c
    if (!cpu.flags.zf)
    {
        goto L_0x00530f2c;
    }
    // 00530f0d  68a0d25600             -push 0x56d2a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690016 /*0x56d2a0*/;
    cpu.esp -= 4;
    // 00530f12  68acc05600             -push 0x56c0ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685420 /*0x56c0ac*/;
    cpu.esp -= 4;
    // 00530f17  e8fce3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530f1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530f1e  740c                   -je 0x530f2c
    if (cpu.flags.zf)
    {
        goto L_0x00530f2c;
    }
    // 00530f20  c705a0d25600ffffffff   -mov dword ptr [0x56d2a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */) = 4294967295 /*0xffffffff*/;
    // 00530f2a  eb20                   -jmp 0x530f4c
    goto L_0x00530f4c;
L_0x00530f2c:
    // 00530f2c  833da0d25600ff         +cmp dword ptr [0x56d2a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f33  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530f38  7412                   -je 0x530f4c
    if (cpu.flags.zf)
    {
        goto L_0x00530f4c;
    }
    // 00530f3a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f3e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f42  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f46  ff15a0d25600           -call dword ptr [0x56d2a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690016) /* 0x56d2a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f4c:
    // 00530f4c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f4f  833da4d2560000         +cmp dword ptr [0x56d2a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f56  751f                   -jne 0x530f77
    if (!cpu.flags.zf)
    {
        goto L_0x00530f77;
    }
    // 00530f58  68a4d25600             -push 0x56d2a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690020 /*0x56d2a4*/;
    cpu.esp -= 4;
    // 00530f5d  68c4c05600             -push 0x56c0c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685444 /*0x56c0c4*/;
    cpu.esp -= 4;
    // 00530f62  e8b1e3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530f67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530f69  740c                   -je 0x530f77
    if (cpu.flags.zf)
    {
        goto L_0x00530f77;
    }
    // 00530f6b  c705a4d25600ffffffff   -mov dword ptr [0x56d2a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */) = 4294967295 /*0xffffffff*/;
    // 00530f75  eb20                   -jmp 0x530f97
    goto L_0x00530f97;
L_0x00530f77:
    // 00530f77  833da4d25600ff         +cmp dword ptr [0x56d2a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530f7e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530f83  7412                   -je 0x530f97
    if (cpu.flags.zf)
    {
        goto L_0x00530f97;
    }
    // 00530f85  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f89  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f8d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530f91  ff15a4d25600           -call dword ptr [0x56d2a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690020) /* 0x56d2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530f97:
    // 00530f97  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530f9a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530f9a  833da8d2560000         +cmp dword ptr [0x56d2a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fa1  751f                   -jne 0x530fc2
    if (!cpu.flags.zf)
    {
        goto L_0x00530fc2;
    }
    // 00530fa3  68a8d25600             -push 0x56d2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690024 /*0x56d2a8*/;
    cpu.esp -= 4;
    // 00530fa8  68dcc05600             -push 0x56c0dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685468 /*0x56c0dc*/;
    cpu.esp -= 4;
    // 00530fad  e866e3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530fb2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530fb4  740c                   -je 0x530fc2
    if (cpu.flags.zf)
    {
        goto L_0x00530fc2;
    }
    // 00530fb6  c705a8d25600ffffffff   -mov dword ptr [0x56d2a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */) = 4294967295 /*0xffffffff*/;
    // 00530fc0  eb20                   -jmp 0x530fe2
    goto L_0x00530fe2;
L_0x00530fc2:
    // 00530fc2  833da8d25600ff         +cmp dword ptr [0x56d2a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fc9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00530fce  7412                   -je 0x530fe2
    if (cpu.flags.zf)
    {
        goto L_0x00530fe2;
    }
    // 00530fd0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fd4  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fd8  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00530fdc  ff15a8d25600           -call dword ptr [0x56d2a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690024) /* 0x56d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00530fe2:
    // 00530fe2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_530fe5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00530fe5  833dacd2560000         +cmp dword ptr [0x56d2ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00530fec  751f                   -jne 0x53100d
    if (!cpu.flags.zf)
    {
        goto L_0x0053100d;
    }
    // 00530fee  68acd25600             -push 0x56d2ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690028 /*0x56d2ac*/;
    cpu.esp -= 4;
    // 00530ff3  68e8c05600             -push 0x56c0e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685480 /*0x56c0e8*/;
    cpu.esp -= 4;
    // 00530ff8  e81be3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00530ffd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00530fff  740c                   -je 0x53100d
    if (cpu.flags.zf)
    {
        goto L_0x0053100d;
    }
    // 00531001  c705acd25600ffffffff   -mov dword ptr [0x56d2ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */) = 4294967295 /*0xffffffff*/;
    // 0053100b  eb20                   -jmp 0x53102d
    goto L_0x0053102d;
L_0x0053100d:
    // 0053100d  833dacd25600ff         +cmp dword ptr [0x56d2ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531014  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531019  7412                   -je 0x53102d
    if (cpu.flags.zf)
    {
        goto L_0x0053102d;
    }
    // 0053101b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053101f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531023  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531027  ff15acd25600           -call dword ptr [0x56d2ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690028) /* 0x56d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053102d:
    // 0053102d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531030  833db0d2560000         +cmp dword ptr [0x56d2b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531037  751f                   -jne 0x531058
    if (!cpu.flags.zf)
    {
        goto L_0x00531058;
    }
    // 00531039  68b0d25600             -push 0x56d2b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690032 /*0x56d2b0*/;
    cpu.esp -= 4;
    // 0053103e  68f8c05600             -push 0x56c0f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685496 /*0x56c0f8*/;
    cpu.esp -= 4;
    // 00531043  e8d0e2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531048  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053104a  740c                   -je 0x531058
    if (cpu.flags.zf)
    {
        goto L_0x00531058;
    }
    // 0053104c  c705b0d25600ffffffff   -mov dword ptr [0x56d2b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */) = 4294967295 /*0xffffffff*/;
    // 00531056  eb20                   -jmp 0x531078
    goto L_0x00531078;
L_0x00531058:
    // 00531058  833db0d25600ff         +cmp dword ptr [0x56d2b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053105f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531064  7412                   -je 0x531078
    if (cpu.flags.zf)
    {
        goto L_0x00531078;
    }
    // 00531066  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053106a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053106e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531072  ff15b0d25600           -call dword ptr [0x56d2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690032) /* 0x56d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531078:
    // 00531078  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53107b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053107b  833db4d2560000         +cmp dword ptr [0x56d2b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531082  751f                   -jne 0x5310a3
    if (!cpu.flags.zf)
    {
        goto L_0x005310a3;
    }
    // 00531084  68b4d25600             -push 0x56d2b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690036 /*0x56d2b4*/;
    cpu.esp -= 4;
    // 00531089  6808c15600             -push 0x56c108
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685512 /*0x56c108*/;
    cpu.esp -= 4;
    // 0053108e  e885e2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531095  740c                   -je 0x5310a3
    if (cpu.flags.zf)
    {
        goto L_0x005310a3;
    }
    // 00531097  c705b4d25600ffffffff   -mov dword ptr [0x56d2b4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */) = 4294967295 /*0xffffffff*/;
    // 005310a1  eb18                   -jmp 0x5310bb
    goto L_0x005310bb;
L_0x005310a3:
    // 005310a3  833db4d25600ff         +cmp dword ptr [0x56d2b4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310aa  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005310af  740a                   -je 0x5310bb
    if (cpu.flags.zf)
    {
        goto L_0x005310bb;
    }
    // 005310b1  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 005310b5  ff15b4d25600           -call dword ptr [0x56d2b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690036) /* 0x56d2b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005310bb:
    // 005310bb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_5310be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005310be  833db8d2560000         +cmp dword ptr [0x56d2b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005310c6  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005310c8  751f                   -jne 0x5310e9
    if (!cpu.flags.zf)
    {
        goto L_0x005310e9;
    }
    // 005310ca  68b8d25600             -push 0x56d2b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690040 /*0x56d2b8*/;
    cpu.esp -= 4;
    // 005310cf  6814c15600             -push 0x56c114
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685524 /*0x56c114*/;
    cpu.esp -= 4;
    // 005310d4  e83fe2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005310d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005310db  740c                   -je 0x5310e9
    if (cpu.flags.zf)
    {
        goto L_0x005310e9;
    }
    // 005310dd  c705b8d25600ffffffff   -mov dword ptr [0x56d2b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */) = 4294967295 /*0xffffffff*/;
    // 005310e7  eb23                   -jmp 0x53110c
    goto L_0x0053110c;
L_0x005310e9:
    // 005310e9  833db8d25600ff         +cmp dword ptr [0x56d2b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005310f0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005310f5  7415                   -je 0x53110c
    if (cpu.flags.zf)
    {
        goto L_0x0053110c;
    }
    // 005310f7  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005310fa  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005310fd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531100  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531103  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531106  ff15b8d25600           -call dword ptr [0x56d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690040) /* 0x56d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053110c:
    // 0053110c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053110d  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531110  833dbcd2560000         +cmp dword ptr [0x56d2bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531117  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531118  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053111a  751f                   -jne 0x53113b
    if (!cpu.flags.zf)
    {
        goto L_0x0053113b;
    }
    // 0053111c  68bcd25600             -push 0x56d2bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690044 /*0x56d2bc*/;
    cpu.esp -= 4;
    // 00531121  6824c15600             -push 0x56c124
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685540 /*0x56c124*/;
    cpu.esp -= 4;
    // 00531126  e8ede1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053112b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053112d  740c                   -je 0x53113b
    if (cpu.flags.zf)
    {
        goto L_0x0053113b;
    }
    // 0053112f  c705bcd25600ffffffff   -mov dword ptr [0x56d2bc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */) = 4294967295 /*0xffffffff*/;
    // 00531139  eb29                   -jmp 0x531164
    goto L_0x00531164;
L_0x0053113b:
    // 0053113b  833dbcd25600ff         +cmp dword ptr [0x56d2bc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531142  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531147  741b                   -je 0x531164
    if (cpu.flags.zf)
    {
        goto L_0x00531164;
    }
    // 00531149  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053114c  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053114f  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531152  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531155  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531158  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053115b  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053115e  ff15bcd25600           -call dword ptr [0x56d2bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690044) /* 0x56d2bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531164:
    // 00531164  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531165  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_531168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531168  833dc0d2560000         +cmp dword ptr [0x56d2c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053116f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531170  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531172  751f                   -jne 0x531193
    if (!cpu.flags.zf)
    {
        goto L_0x00531193;
    }
    // 00531174  68c0d25600             -push 0x56d2c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690048 /*0x56d2c0*/;
    cpu.esp -= 4;
    // 00531179  6838c15600             -push 0x56c138
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685560 /*0x56c138*/;
    cpu.esp -= 4;
    // 0053117e  e895e1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531183  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531185  740c                   -je 0x531193
    if (cpu.flags.zf)
    {
        goto L_0x00531193;
    }
    // 00531187  c705c0d25600ffffffff   -mov dword ptr [0x56d2c0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */) = 4294967295 /*0xffffffff*/;
    // 00531191  eb29                   -jmp 0x5311bc
    goto L_0x005311bc;
L_0x00531193:
    // 00531193  833dc0d25600ff         +cmp dword ptr [0x56d2c0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053119a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053119f  741b                   -je 0x5311bc
    if (cpu.flags.zf)
    {
        goto L_0x005311bc;
    }
    // 005311a1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005311a4  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005311a7  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005311aa  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005311ad  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005311b0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005311b3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005311b6  ff15c0d25600           -call dword ptr [0x56d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690048) /* 0x56d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005311bc:
    // 005311bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005311bd  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_5311c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005311c0  833dc4d2560000         +cmp dword ptr [0x56d2c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005311c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005311c8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005311ca  751f                   -jne 0x5311eb
    if (!cpu.flags.zf)
    {
        goto L_0x005311eb;
    }
    // 005311cc  68c4d25600             -push 0x56d2c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690052 /*0x56d2c4*/;
    cpu.esp -= 4;
    // 005311d1  684cc15600             -push 0x56c14c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685580 /*0x56c14c*/;
    cpu.esp -= 4;
    // 005311d6  e83de1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005311db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005311dd  740c                   -je 0x5311eb
    if (cpu.flags.zf)
    {
        goto L_0x005311eb;
    }
    // 005311df  c705c4d25600ffffffff   -mov dword ptr [0x56d2c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */) = 4294967295 /*0xffffffff*/;
    // 005311e9  eb23                   -jmp 0x53120e
    goto L_0x0053120e;
L_0x005311eb:
    // 005311eb  833dc4d25600ff         +cmp dword ptr [0x56d2c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005311f2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005311f7  7415                   -je 0x53120e
    if (cpu.flags.zf)
    {
        goto L_0x0053120e;
    }
    // 005311f9  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005311fc  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005311ff  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531202  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531205  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531208  ff15c4d25600           -call dword ptr [0x56d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690052) /* 0x56d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053120e:
    // 0053120e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053120f  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531212(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531212  833dc8d2560000         +cmp dword ptr [0x56d2c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531219  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053121a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053121c  751f                   -jne 0x53123d
    if (!cpu.flags.zf)
    {
        goto L_0x0053123d;
    }
    // 0053121e  68c8d25600             -push 0x56d2c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690056 /*0x56d2c8*/;
    cpu.esp -= 4;
    // 00531223  685cc15600             -push 0x56c15c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685596 /*0x56c15c*/;
    cpu.esp -= 4;
    // 00531228  e8ebe0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053122d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053122f  740c                   -je 0x53123d
    if (cpu.flags.zf)
    {
        goto L_0x0053123d;
    }
    // 00531231  c705c8d25600ffffffff   -mov dword ptr [0x56d2c8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */) = 4294967295 /*0xffffffff*/;
    // 0053123b  eb23                   -jmp 0x531260
    goto L_0x00531260;
L_0x0053123d:
    // 0053123d  833dc8d25600ff         +cmp dword ptr [0x56d2c8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531244  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531249  7415                   -je 0x531260
    if (cpu.flags.zf)
    {
        goto L_0x00531260;
    }
    // 0053124b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053124e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531251  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531254  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531257  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053125a  ff15c8d25600           -call dword ptr [0x56d2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690056) /* 0x56d2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531260:
    // 00531260  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531261  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531264(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531264  833dccd2560000         +cmp dword ptr [0x56d2cc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053126b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053126c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053126e  751f                   -jne 0x53128f
    if (!cpu.flags.zf)
    {
        goto L_0x0053128f;
    }
    // 00531270  68ccd25600             -push 0x56d2cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690060 /*0x56d2cc*/;
    cpu.esp -= 4;
    // 00531275  686cc15600             -push 0x56c16c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685612 /*0x56c16c*/;
    cpu.esp -= 4;
    // 0053127a  e899e0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053127f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531281  740c                   -je 0x53128f
    if (cpu.flags.zf)
    {
        goto L_0x0053128f;
    }
    // 00531283  c705ccd25600ffffffff   -mov dword ptr [0x56d2cc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */) = 4294967295 /*0xffffffff*/;
    // 0053128d  eb23                   -jmp 0x5312b2
    goto L_0x005312b2;
L_0x0053128f:
    // 0053128f  833dccd25600ff         +cmp dword ptr [0x56d2cc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531296  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053129b  7415                   -je 0x5312b2
    if (cpu.flags.zf)
    {
        goto L_0x005312b2;
    }
    // 0053129d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005312a0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005312a3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005312a6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005312a9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312ac  ff15ccd25600           -call dword ptr [0x56d2cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690060) /* 0x56d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005312b2:
    // 005312b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005312b3  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5312b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005312b6  833dd0d2560000         +cmp dword ptr [0x56d2d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005312bd  751f                   -jne 0x5312de
    if (!cpu.flags.zf)
    {
        goto L_0x005312de;
    }
    // 005312bf  68d0d25600             -push 0x56d2d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690064 /*0x56d2d0*/;
    cpu.esp -= 4;
    // 005312c4  687cc15600             -push 0x56c17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685628 /*0x56c17c*/;
    cpu.esp -= 4;
    // 005312c9  e84ae0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005312ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005312d0  740c                   -je 0x5312de
    if (cpu.flags.zf)
    {
        goto L_0x005312de;
    }
    // 005312d2  c705d0d25600ffffffff   -mov dword ptr [0x56d2d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */) = 4294967295 /*0xffffffff*/;
    // 005312dc  eb1c                   -jmp 0x5312fa
    goto L_0x005312fa;
L_0x005312de:
    // 005312de  833dd0d25600ff         +cmp dword ptr [0x56d2d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005312e5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005312ea  740e                   -je 0x5312fa
    if (cpu.flags.zf)
    {
        goto L_0x005312fa;
    }
    // 005312ec  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312f0  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005312f4  ff15d0d25600           -call dword ptr [0x56d2d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690064) /* 0x56d2d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005312fa:
    // 005312fa  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_5312fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005312fd  833dd4d2560000         +cmp dword ptr [0x56d2d4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531304  751f                   -jne 0x531325
    if (!cpu.flags.zf)
    {
        goto L_0x00531325;
    }
    // 00531306  68d4d25600             -push 0x56d2d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690068 /*0x56d2d4*/;
    cpu.esp -= 4;
    // 0053130b  6890c15600             -push 0x56c190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685648 /*0x56c190*/;
    cpu.esp -= 4;
    // 00531310  e803e0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531317  740c                   -je 0x531325
    if (cpu.flags.zf)
    {
        goto L_0x00531325;
    }
    // 00531319  c705d4d25600ffffffff   -mov dword ptr [0x56d2d4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */) = 4294967295 /*0xffffffff*/;
    // 00531323  eb1c                   -jmp 0x531341
    goto L_0x00531341;
L_0x00531325:
    // 00531325  833dd4d25600ff         +cmp dword ptr [0x56d2d4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053132c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531331  740e                   -je 0x531341
    if (cpu.flags.zf)
    {
        goto L_0x00531341;
    }
    // 00531333  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531337  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053133b  ff15d4d25600           -call dword ptr [0x56d2d4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690068) /* 0x56d2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531341:
    // 00531341  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531344  833dd8d2560000         +cmp dword ptr [0x56d2d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053134b  751f                   -jne 0x53136c
    if (!cpu.flags.zf)
    {
        goto L_0x0053136c;
    }
    // 0053134d  68d8d25600             -push 0x56d2d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690072 /*0x56d2d8*/;
    cpu.esp -= 4;
    // 00531352  68a4c15600             -push 0x56c1a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685668 /*0x56c1a4*/;
    cpu.esp -= 4;
    // 00531357  e8bcdfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053135c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053135e  740c                   -je 0x53136c
    if (cpu.flags.zf)
    {
        goto L_0x0053136c;
    }
    // 00531360  c705d8d25600ffffffff   -mov dword ptr [0x56d2d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */) = 4294967295 /*0xffffffff*/;
    // 0053136a  eb20                   -jmp 0x53138c
    goto L_0x0053138c;
L_0x0053136c:
    // 0053136c  833dd8d25600ff         +cmp dword ptr [0x56d2d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531373  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531378  7412                   -je 0x53138c
    if (cpu.flags.zf)
    {
        goto L_0x0053138c;
    }
    // 0053137a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053137e  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531382  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531386  ff15d8d25600           -call dword ptr [0x56d2d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690072) /* 0x56d2d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053138c:
    // 0053138c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53138f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053138f  833ddcd2560000         +cmp dword ptr [0x56d2dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531396  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531397  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531399  751f                   -jne 0x5313ba
    if (!cpu.flags.zf)
    {
        goto L_0x005313ba;
    }
    // 0053139b  68dcd25600             -push 0x56d2dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690076 /*0x56d2dc*/;
    cpu.esp -= 4;
    // 005313a0  68b8c15600             -push 0x56c1b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685688 /*0x56c1b8*/;
    cpu.esp -= 4;
    // 005313a5  e86edfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005313aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005313ac  740c                   -je 0x5313ba
    if (cpu.flags.zf)
    {
        goto L_0x005313ba;
    }
    // 005313ae  c705dcd25600ffffffff   -mov dword ptr [0x56d2dc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */) = 4294967295 /*0xffffffff*/;
    // 005313b8  eb26                   -jmp 0x5313e0
    goto L_0x005313e0;
L_0x005313ba:
    // 005313ba  833ddcd25600ff         +cmp dword ptr [0x56d2dc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005313c1  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005313c6  7418                   -je 0x5313e0
    if (cpu.flags.zf)
    {
        goto L_0x005313e0;
    }
    // 005313c8  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005313cb  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005313ce  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005313d1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005313d4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005313d7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005313da  ff15dcd25600           -call dword ptr [0x56d2dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690076) /* 0x56d2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005313e0:
    // 005313e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005313e1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_5313e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005313e4  833de0d2560000         +cmp dword ptr [0x56d2e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005313eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005313ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005313ee  751f                   -jne 0x53140f
    if (!cpu.flags.zf)
    {
        goto L_0x0053140f;
    }
    // 005313f0  68e0d25600             -push 0x56d2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690080 /*0x56d2e0*/;
    cpu.esp -= 4;
    // 005313f5  68d0c15600             -push 0x56c1d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685712 /*0x56c1d0*/;
    cpu.esp -= 4;
    // 005313fa  e819dfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005313ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531401  740c                   -je 0x53140f
    if (cpu.flags.zf)
    {
        goto L_0x0053140f;
    }
    // 00531403  c705e0d25600ffffffff   -mov dword ptr [0x56d2e0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */) = 4294967295 /*0xffffffff*/;
    // 0053140d  eb26                   -jmp 0x531435
    goto L_0x00531435;
L_0x0053140f:
    // 0053140f  833de0d25600ff         +cmp dword ptr [0x56d2e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531416  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053141b  7418                   -je 0x531435
    if (cpu.flags.zf)
    {
        goto L_0x00531435;
    }
    // 0053141d  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531420  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531423  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531426  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531429  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053142c  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053142f  ff15e0d25600           -call dword ptr [0x56d2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690080) /* 0x56d2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531435:
    // 00531435  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531436  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_531439(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531439  833de4d2560000         +cmp dword ptr [0x56d2e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531440  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531441  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531443  751f                   -jne 0x531464
    if (!cpu.flags.zf)
    {
        goto L_0x00531464;
    }
    // 00531445  68e4d25600             -push 0x56d2e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690084 /*0x56d2e4*/;
    cpu.esp -= 4;
    // 0053144a  68e8c15600             -push 0x56c1e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685736 /*0x56c1e8*/;
    cpu.esp -= 4;
    // 0053144f  e8c4deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531454  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531456  740c                   -je 0x531464
    if (cpu.flags.zf)
    {
        goto L_0x00531464;
    }
    // 00531458  c705e4d25600ffffffff   -mov dword ptr [0x56d2e4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */) = 4294967295 /*0xffffffff*/;
    // 00531462  eb2f                   -jmp 0x531493
    goto L_0x00531493;
L_0x00531464:
    // 00531464  833de4d25600ff         +cmp dword ptr [0x56d2e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053146b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531470  7421                   -je 0x531493
    if (cpu.flags.zf)
    {
        goto L_0x00531493;
    }
    // 00531472  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00531475  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00531478  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 0053147b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053147e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531481  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531484  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531487  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053148a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053148d  ff15e4d25600           -call dword ptr [0x56d2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690084) /* 0x56d2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531493:
    // 00531493  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531494  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_531497(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531497  833de8d2560000         +cmp dword ptr [0x56d2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053149e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053149f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005314a1  751f                   -jne 0x5314c2
    if (!cpu.flags.zf)
    {
        goto L_0x005314c2;
    }
    // 005314a3  68e8d25600             -push 0x56d2e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690088 /*0x56d2e8*/;
    cpu.esp -= 4;
    // 005314a8  68f4c15600             -push 0x56c1f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685748 /*0x56c1f4*/;
    cpu.esp -= 4;
    // 005314ad  e866deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005314b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005314b4  740c                   -je 0x5314c2
    if (cpu.flags.zf)
    {
        goto L_0x005314c2;
    }
    // 005314b6  c705e8d25600ffffffff   -mov dword ptr [0x56d2e8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */) = 4294967295 /*0xffffffff*/;
    // 005314c0  eb2f                   -jmp 0x5314f1
    goto L_0x005314f1;
L_0x005314c2:
    // 005314c2  833de8d25600ff         +cmp dword ptr [0x56d2e8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005314c9  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005314ce  7421                   -je 0x5314f1
    if (cpu.flags.zf)
    {
        goto L_0x005314f1;
    }
    // 005314d0  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 005314d3  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 005314d6  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005314d9  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005314dc  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005314df  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005314e2  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005314e5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005314e8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005314eb  ff15e8d25600           -call dword ptr [0x56d2e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690088) /* 0x56d2e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005314f1:
    // 005314f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005314f2  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_5314f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005314f5  833decd2560000         +cmp dword ptr [0x56d2ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005314fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005314fd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005314ff  751f                   -jne 0x531520
    if (!cpu.flags.zf)
    {
        goto L_0x00531520;
    }
    // 00531501  68ecd25600             -push 0x56d2ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690092 /*0x56d2ec*/;
    cpu.esp -= 4;
    // 00531506  6800c25600             -push 0x56c200
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685760 /*0x56c200*/;
    cpu.esp -= 4;
    // 0053150b  e808deffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531510  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531512  740c                   -je 0x531520
    if (cpu.flags.zf)
    {
        goto L_0x00531520;
    }
    // 00531514  c705ecd25600ffffffff   -mov dword ptr [0x56d2ec], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */) = 4294967295 /*0xffffffff*/;
    // 0053151e  eb2f                   -jmp 0x53154f
    goto L_0x0053154f;
L_0x00531520:
    // 00531520  833decd25600ff         +cmp dword ptr [0x56d2ec], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531527  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053152c  7421                   -je 0x53154f
    if (cpu.flags.zf)
    {
        goto L_0x0053154f;
    }
    // 0053152e  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 00531531  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 00531534  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 00531537  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053153a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053153d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531540  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531543  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531546  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531549  ff15ecd25600           -call dword ptr [0x56d2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690092) /* 0x56d2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053154f:
    // 0053154f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531550  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_531553(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531553  833df0d2560000         +cmp dword ptr [0x56d2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053155a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053155b  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053155d  751f                   -jne 0x53157e
    if (!cpu.flags.zf)
    {
        goto L_0x0053157e;
    }
    // 0053155f  68f0d25600             -push 0x56d2f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690096 /*0x56d2f0*/;
    cpu.esp -= 4;
    // 00531564  680cc25600             -push 0x56c20c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685772 /*0x56c20c*/;
    cpu.esp -= 4;
    // 00531569  e8aaddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053156e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531570  740c                   -je 0x53157e
    if (cpu.flags.zf)
    {
        goto L_0x0053157e;
    }
    // 00531572  c705f0d25600ffffffff   -mov dword ptr [0x56d2f0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */) = 4294967295 /*0xffffffff*/;
    // 0053157c  eb20                   -jmp 0x53159e
    goto L_0x0053159e;
L_0x0053157e:
    // 0053157e  833df0d25600ff         +cmp dword ptr [0x56d2f0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531585  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053158a  7412                   -je 0x53159e
    if (cpu.flags.zf)
    {
        goto L_0x0053159e;
    }
    // 0053158c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053158f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531592  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531595  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531598  ff15f0d25600           -call dword ptr [0x56d2f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690096) /* 0x56d2f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053159e:
    // 0053159e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053159f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5315a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005315a2  833df4d2560000         +cmp dword ptr [0x56d2f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005315aa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005315ac  751f                   -jne 0x5315cd
    if (!cpu.flags.zf)
    {
        goto L_0x005315cd;
    }
    // 005315ae  68f4d25600             -push 0x56d2f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690100 /*0x56d2f4*/;
    cpu.esp -= 4;
    // 005315b3  6818c25600             -push 0x56c218
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685784 /*0x56c218*/;
    cpu.esp -= 4;
    // 005315b8  e85bddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005315bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005315bf  740c                   -je 0x5315cd
    if (cpu.flags.zf)
    {
        goto L_0x005315cd;
    }
    // 005315c1  c705f4d25600ffffffff   -mov dword ptr [0x56d2f4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */) = 4294967295 /*0xffffffff*/;
    // 005315cb  eb20                   -jmp 0x5315ed
    goto L_0x005315ed;
L_0x005315cd:
    // 005315cd  833df4d25600ff         +cmp dword ptr [0x56d2f4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315d4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005315d9  7412                   -je 0x5315ed
    if (cpu.flags.zf)
    {
        goto L_0x005315ed;
    }
    // 005315db  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005315de  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005315e1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005315e4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005315e7  ff15f4d25600           -call dword ptr [0x56d2f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690100) /* 0x56d2f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005315ed:
    // 005315ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005315ee  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5315f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005315f1  833df8d2560000         +cmp dword ptr [0x56d2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005315f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005315f9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005315fb  751f                   -jne 0x53161c
    if (!cpu.flags.zf)
    {
        goto L_0x0053161c;
    }
    // 005315fd  68f8d25600             -push 0x56d2f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690104 /*0x56d2f8*/;
    cpu.esp -= 4;
    // 00531602  6824c25600             -push 0x56c224
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685796 /*0x56c224*/;
    cpu.esp -= 4;
    // 00531607  e80cddffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053160c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053160e  740c                   -je 0x53161c
    if (cpu.flags.zf)
    {
        goto L_0x0053161c;
    }
    // 00531610  c705f8d25600ffffffff   -mov dword ptr [0x56d2f8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */) = 4294967295 /*0xffffffff*/;
    // 0053161a  eb20                   -jmp 0x53163c
    goto L_0x0053163c;
L_0x0053161c:
    // 0053161c  833df8d25600ff         +cmp dword ptr [0x56d2f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531623  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531628  7412                   -je 0x53163c
    if (cpu.flags.zf)
    {
        goto L_0x0053163c;
    }
    // 0053162a  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053162d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531630  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531633  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531636  ff15f8d25600           -call dword ptr [0x56d2f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690104) /* 0x56d2f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053163c:
    // 0053163c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053163d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_531640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531640  833dfcd2560000         +cmp dword ptr [0x56d2fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531647  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531648  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053164a  751f                   -jne 0x53166b
    if (!cpu.flags.zf)
    {
        goto L_0x0053166b;
    }
    // 0053164c  68fcd25600             -push 0x56d2fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690108 /*0x56d2fc*/;
    cpu.esp -= 4;
    // 00531651  6830c25600             -push 0x56c230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685808 /*0x56c230*/;
    cpu.esp -= 4;
    // 00531656  e8bddcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053165b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053165d  740c                   -je 0x53166b
    if (cpu.flags.zf)
    {
        goto L_0x0053166b;
    }
    // 0053165f  c705fcd25600ffffffff   -mov dword ptr [0x56d2fc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */) = 4294967295 /*0xffffffff*/;
    // 00531669  eb23                   -jmp 0x53168e
    goto L_0x0053168e;
L_0x0053166b:
    // 0053166b  833dfcd25600ff         +cmp dword ptr [0x56d2fc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531672  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531677  7415                   -je 0x53168e
    if (cpu.flags.zf)
    {
        goto L_0x0053168e;
    }
    // 00531679  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 0053167c  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053167f  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531682  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531685  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531688  ff15fcd25600           -call dword ptr [0x56d2fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690108) /* 0x56d2fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053168e:
    // 0053168e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053168f  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531692(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531692  833d00d3560000         +cmp dword ptr [0x56d300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531699  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053169a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053169c  751f                   -jne 0x5316bd
    if (!cpu.flags.zf)
    {
        goto L_0x005316bd;
    }
    // 0053169e  6800d35600             -push 0x56d300
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690112 /*0x56d300*/;
    cpu.esp -= 4;
    // 005316a3  683cc25600             -push 0x56c23c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685820 /*0x56c23c*/;
    cpu.esp -= 4;
    // 005316a8  e86bdcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005316ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005316af  740c                   -je 0x5316bd
    if (cpu.flags.zf)
    {
        goto L_0x005316bd;
    }
    // 005316b1  c70500d35600ffffffff   -mov dword ptr [0x56d300], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */) = 4294967295 /*0xffffffff*/;
    // 005316bb  eb23                   -jmp 0x5316e0
    goto L_0x005316e0;
L_0x005316bd:
    // 005316bd  833d00d35600ff         +cmp dword ptr [0x56d300], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005316c4  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005316c9  7415                   -je 0x5316e0
    if (cpu.flags.zf)
    {
        goto L_0x005316e0;
    }
    // 005316cb  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005316ce  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005316d1  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005316d4  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005316d7  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005316da  ff1500d35600           -call dword ptr [0x56d300]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690112) /* 0x56d300 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005316e0:
    // 005316e0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005316e1  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_5316e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005316e4  833d04d3560000         +cmp dword ptr [0x56d304], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005316eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005316ec  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005316ee  751f                   -jne 0x53170f
    if (!cpu.flags.zf)
    {
        goto L_0x0053170f;
    }
    // 005316f0  6804d35600             -push 0x56d304
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690116 /*0x56d304*/;
    cpu.esp -= 4;
    // 005316f5  6848c25600             -push 0x56c248
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685832 /*0x56c248*/;
    cpu.esp -= 4;
    // 005316fa  e819dcffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005316ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531701  740c                   -je 0x53170f
    if (cpu.flags.zf)
    {
        goto L_0x0053170f;
    }
    // 00531703  c70504d35600ffffffff   -mov dword ptr [0x56d304], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */) = 4294967295 /*0xffffffff*/;
    // 0053170d  eb23                   -jmp 0x531732
    goto L_0x00531732;
L_0x0053170f:
    // 0053170f  833d04d35600ff         +cmp dword ptr [0x56d304], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531716  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053171b  7415                   -je 0x531732
    if (cpu.flags.zf)
    {
        goto L_0x00531732;
    }
    // 0053171d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531720  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531723  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531726  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531729  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053172c  ff1504d35600           -call dword ptr [0x56d304]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690116) /* 0x56d304 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531732:
    // 00531732  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531733  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531736(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531736  833d08d3560000         +cmp dword ptr [0x56d308], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053173d  751f                   -jne 0x53175e
    if (!cpu.flags.zf)
    {
        goto L_0x0053175e;
    }
    // 0053173f  6808d35600             -push 0x56d308
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690120 /*0x56d308*/;
    cpu.esp -= 4;
    // 00531744  6854c25600             -push 0x56c254
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685844 /*0x56c254*/;
    cpu.esp -= 4;
    // 00531749  e8cadbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053174e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531750  740c                   -je 0x53175e
    if (cpu.flags.zf)
    {
        goto L_0x0053175e;
    }
    // 00531752  c70508d35600ffffffff   -mov dword ptr [0x56d308], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */) = 4294967295 /*0xffffffff*/;
    // 0053175c  eb20                   -jmp 0x53177e
    goto L_0x0053177e;
L_0x0053175e:
    // 0053175e  833d08d35600ff         +cmp dword ptr [0x56d308], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531765  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053176a  7412                   -je 0x53177e
    if (cpu.flags.zf)
    {
        goto L_0x0053177e;
    }
    // 0053176c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531770  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531774  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531778  ff1508d35600           -call dword ptr [0x56d308]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690120) /* 0x56d308 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053177e:
    // 0053177e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531781(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531781  833d0cd3560000         +cmp dword ptr [0x56d30c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531788  751f                   -jne 0x5317a9
    if (!cpu.flags.zf)
    {
        goto L_0x005317a9;
    }
    // 0053178a  680cd35600             -push 0x56d30c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690124 /*0x56d30c*/;
    cpu.esp -= 4;
    // 0053178f  6870c25600             -push 0x56c270
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685872 /*0x56c270*/;
    cpu.esp -= 4;
    // 00531794  e87fdbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531799  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053179b  740c                   -je 0x5317a9
    if (cpu.flags.zf)
    {
        goto L_0x005317a9;
    }
    // 0053179d  c7050cd35600ffffffff   -mov dword ptr [0x56d30c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */) = 4294967295 /*0xffffffff*/;
    // 005317a7  eb20                   -jmp 0x5317c9
    goto L_0x005317c9;
L_0x005317a9:
    // 005317a9  833d0cd35600ff         +cmp dword ptr [0x56d30c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317b0  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005317b5  7412                   -je 0x5317c9
    if (cpu.flags.zf)
    {
        goto L_0x005317c9;
    }
    // 005317b7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317bb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317bf  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005317c3  ff150cd35600           -call dword ptr [0x56d30c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690124) /* 0x56d30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005317c9:
    // 005317c9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5317cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005317cc  833d10d3560000         +cmp dword ptr [0x56d310], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317d3  751f                   -jne 0x5317f4
    if (!cpu.flags.zf)
    {
        goto L_0x005317f4;
    }
    // 005317d5  6810d35600             -push 0x56d310
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690128 /*0x56d310*/;
    cpu.esp -= 4;
    // 005317da  688cc25600             -push 0x56c28c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685900 /*0x56c28c*/;
    cpu.esp -= 4;
    // 005317df  e834dbffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005317e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005317e6  740c                   -je 0x5317f4
    if (cpu.flags.zf)
    {
        goto L_0x005317f4;
    }
    // 005317e8  c70510d35600ffffffff   -mov dword ptr [0x56d310], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */) = 4294967295 /*0xffffffff*/;
    // 005317f2  eb20                   -jmp 0x531814
    goto L_0x00531814;
L_0x005317f4:
    // 005317f4  833d10d35600ff         +cmp dword ptr [0x56d310], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005317fb  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531800  7412                   -je 0x531814
    if (cpu.flags.zf)
    {
        goto L_0x00531814;
    }
    // 00531802  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531806  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053180a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053180e  ff1510d35600           -call dword ptr [0x56d310]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690128) /* 0x56d310 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531814:
    // 00531814  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531817(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531817  833d14d3560000         +cmp dword ptr [0x56d314], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053181e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053181f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531821  751f                   -jne 0x531842
    if (!cpu.flags.zf)
    {
        goto L_0x00531842;
    }
    // 00531823  6814d35600             -push 0x56d314
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690132 /*0x56d314*/;
    cpu.esp -= 4;
    // 00531828  68a8c25600             -push 0x56c2a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685928 /*0x56c2a8*/;
    cpu.esp -= 4;
    // 0053182d  e8e6daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531832  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531834  740c                   -je 0x531842
    if (cpu.flags.zf)
    {
        goto L_0x00531842;
    }
    // 00531836  c70514d35600ffffffff   -mov dword ptr [0x56d314], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */) = 4294967295 /*0xffffffff*/;
    // 00531840  eb26                   -jmp 0x531868
    goto L_0x00531868;
L_0x00531842:
    // 00531842  833d14d35600ff         +cmp dword ptr [0x56d314], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531849  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053184e  7418                   -je 0x531868
    if (cpu.flags.zf)
    {
        goto L_0x00531868;
    }
    // 00531850  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531853  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531856  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531859  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053185c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053185f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531862  ff1514d35600           -call dword ptr [0x56d314]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690132) /* 0x56d314 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531868:
    // 00531868  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531869  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_53186c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053186c  833d18d3560000         +cmp dword ptr [0x56d318], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531873  751f                   -jne 0x531894
    if (!cpu.flags.zf)
    {
        goto L_0x00531894;
    }
    // 00531875  6818d35600             -push 0x56d318
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690136 /*0x56d318*/;
    cpu.esp -= 4;
    // 0053187a  68bcc25600             -push 0x56c2bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685948 /*0x56c2bc*/;
    cpu.esp -= 4;
    // 0053187f  e894daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531884  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531886  740c                   -je 0x531894
    if (cpu.flags.zf)
    {
        goto L_0x00531894;
    }
    // 00531888  c70518d35600ffffffff   -mov dword ptr [0x56d318], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */) = 4294967295 /*0xffffffff*/;
    // 00531892  eb20                   -jmp 0x5318b4
    goto L_0x005318b4;
L_0x00531894:
    // 00531894  833d18d35600ff         +cmp dword ptr [0x56d318], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053189b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005318a0  7412                   -je 0x5318b4
    if (cpu.flags.zf)
    {
        goto L_0x005318b4;
    }
    // 005318a2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318a6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318aa  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318ae  ff1518d35600           -call dword ptr [0x56d318]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690136) /* 0x56d318 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005318b4:
    // 005318b4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5318b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005318b7  833d1cd3560000         +cmp dword ptr [0x56d31c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005318be  751f                   -jne 0x5318df
    if (!cpu.flags.zf)
    {
        goto L_0x005318df;
    }
    // 005318c0  681cd35600             -push 0x56d31c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690140 /*0x56d31c*/;
    cpu.esp -= 4;
    // 005318c5  68d0c25600             -push 0x56c2d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685968 /*0x56c2d0*/;
    cpu.esp -= 4;
    // 005318ca  e849daffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005318cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005318d1  740c                   -je 0x5318df
    if (cpu.flags.zf)
    {
        goto L_0x005318df;
    }
    // 005318d3  c7051cd35600ffffffff   -mov dword ptr [0x56d31c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */) = 4294967295 /*0xffffffff*/;
    // 005318dd  eb20                   -jmp 0x5318ff
    goto L_0x005318ff;
L_0x005318df:
    // 005318df  833d1cd35600ff         +cmp dword ptr [0x56d31c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005318e6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005318eb  7412                   -je 0x5318ff
    if (cpu.flags.zf)
    {
        goto L_0x005318ff;
    }
    // 005318ed  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f5  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005318f9  ff151cd35600           -call dword ptr [0x56d31c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690140) /* 0x56d31c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005318ff:
    // 005318ff  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531902(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531902  833d20d3560000         +cmp dword ptr [0x56d320], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531909  751f                   -jne 0x53192a
    if (!cpu.flags.zf)
    {
        goto L_0x0053192a;
    }
    // 0053190b  6820d35600             -push 0x56d320
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690144 /*0x56d320*/;
    cpu.esp -= 4;
    // 00531910  68e0c25600             -push 0x56c2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5685984 /*0x56c2e0*/;
    cpu.esp -= 4;
    // 00531915  e8fed9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053191a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053191c  740c                   -je 0x53192a
    if (cpu.flags.zf)
    {
        goto L_0x0053192a;
    }
    // 0053191e  c70520d35600ffffffff   -mov dword ptr [0x56d320], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */) = 4294967295 /*0xffffffff*/;
    // 00531928  eb20                   -jmp 0x53194a
    goto L_0x0053194a;
L_0x0053192a:
    // 0053192a  833d20d35600ff         +cmp dword ptr [0x56d320], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531931  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531936  7412                   -je 0x53194a
    if (cpu.flags.zf)
    {
        goto L_0x0053194a;
    }
    // 00531938  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053193c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531940  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531944  ff1520d35600           -call dword ptr [0x56d320]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690144) /* 0x56d320 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053194a:
    // 0053194a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_53194d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053194d  833d24d3560000         +cmp dword ptr [0x56d324], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690148) /* 0x56d324 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531954  751f                   -jne 0x531975
    if (!cpu.flags.zf)
    {
        goto L_0x00531975;
    }
    // 00531956  6824d35600             -push 0x56d324
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690148 /*0x56d324*/;
    cpu.esp -= 4;
    // 0053195b  68f0c25600             -push 0x56c2f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686000 /*0x56c2f0*/;
    cpu.esp -= 4;
    // 00531960  e8b3d9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531967  740c                   -je 0x531975
    if (cpu.flags.zf)
    {
        goto L_0x00531975;
    }
    // 00531969  c70524d35600ffffffff   -mov dword ptr [0x56d324], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690148) /* 0x56d324 */) = 4294967295 /*0xffffffff*/;
    // 00531973  eb20                   -jmp 0x531995
    goto L_0x00531995;
L_0x00531975:
    // 00531975  833d24d35600ff         +cmp dword ptr [0x56d324], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690148) /* 0x56d324 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053197c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531981  7412                   -je 0x531995
    if (cpu.flags.zf)
    {
        goto L_0x00531995;
    }
    // 00531983  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531987  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053198b  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053198f  ff1524d35600           -call dword ptr [0x56d324]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690148) /* 0x56d324 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531995:
    // 00531995  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531998  833d28d3560000         +cmp dword ptr [0x56d328], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690152) /* 0x56d328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053199f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005319a0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005319a2  751f                   -jne 0x5319c3
    if (!cpu.flags.zf)
    {
        goto L_0x005319c3;
    }
    // 005319a4  6828d35600             -push 0x56d328
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690152 /*0x56d328*/;
    cpu.esp -= 4;
    // 005319a9  6800c35600             -push 0x56c300
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686016 /*0x56c300*/;
    cpu.esp -= 4;
    // 005319ae  e865d9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005319b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005319b5  740c                   -je 0x5319c3
    if (cpu.flags.zf)
    {
        goto L_0x005319c3;
    }
    // 005319b7  c70528d35600ffffffff   -mov dword ptr [0x56d328], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690152) /* 0x56d328 */) = 4294967295 /*0xffffffff*/;
    // 005319c1  eb20                   -jmp 0x5319e3
    goto L_0x005319e3;
L_0x005319c3:
    // 005319c3  833d28d35600ff         +cmp dword ptr [0x56d328], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690152) /* 0x56d328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005319ca  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005319cf  7412                   -je 0x5319e3
    if (cpu.flags.zf)
    {
        goto L_0x005319e3;
    }
    // 005319d1  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005319d4  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005319d7  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005319da  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005319dd  ff1528d35600           -call dword ptr [0x56d328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690152) /* 0x56d328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005319e3:
    // 005319e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005319e4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5319e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005319e7  833d2cd3560000         +cmp dword ptr [0x56d32c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690156) /* 0x56d32c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005319ee  751f                   -jne 0x531a0f
    if (!cpu.flags.zf)
    {
        goto L_0x00531a0f;
    }
    // 005319f0  682cd35600             -push 0x56d32c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690156 /*0x56d32c*/;
    cpu.esp -= 4;
    // 005319f5  6820c35600             -push 0x56c320
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686048 /*0x56c320*/;
    cpu.esp -= 4;
    // 005319fa  e819d9ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005319ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531a01  740c                   -je 0x531a0f
    if (cpu.flags.zf)
    {
        goto L_0x00531a0f;
    }
    // 00531a03  c7052cd35600ffffffff   -mov dword ptr [0x56d32c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690156) /* 0x56d32c */) = 4294967295 /*0xffffffff*/;
    // 00531a0d  eb18                   -jmp 0x531a27
    goto L_0x00531a27;
L_0x00531a0f:
    // 00531a0f  833d2cd35600ff         +cmp dword ptr [0x56d32c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690156) /* 0x56d32c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531a16  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531a1b  740a                   -je 0x531a27
    if (cpu.flags.zf)
    {
        goto L_0x00531a27;
    }
    // 00531a1d  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00531a21  ff152cd35600           -call dword ptr [0x56d32c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690156) /* 0x56d32c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531a27:
    // 00531a27  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_531a2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531a2a  833d30d3560000         +cmp dword ptr [0x56d330], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690160) /* 0x56d330 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531a31  751f                   -jne 0x531a52
    if (!cpu.flags.zf)
    {
        goto L_0x00531a52;
    }
    // 00531a33  6830d35600             -push 0x56d330
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690160 /*0x56d330*/;
    cpu.esp -= 4;
    // 00531a38  6838c35600             -push 0x56c338
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686072 /*0x56c338*/;
    cpu.esp -= 4;
    // 00531a3d  e8d6d8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531a42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531a44  740c                   -je 0x531a52
    if (cpu.flags.zf)
    {
        goto L_0x00531a52;
    }
    // 00531a46  c70530d35600ffffffff   -mov dword ptr [0x56d330], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690160) /* 0x56d330 */) = 4294967295 /*0xffffffff*/;
    // 00531a50  eb18                   -jmp 0x531a6a
    goto L_0x00531a6a;
L_0x00531a52:
    // 00531a52  833d30d35600ff         +cmp dword ptr [0x56d330], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690160) /* 0x56d330 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531a59  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531a5e  740a                   -je 0x531a6a
    if (cpu.flags.zf)
    {
        goto L_0x00531a6a;
    }
    // 00531a60  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00531a64  ff1530d35600           -call dword ptr [0x56d330]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690160) /* 0x56d330 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531a6a:
    // 00531a6a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_531a6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531a6d  833d34d3560000         +cmp dword ptr [0x56d334], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690164) /* 0x56d334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531a74  751f                   -jne 0x531a95
    if (!cpu.flags.zf)
    {
        goto L_0x00531a95;
    }
    // 00531a76  6834d35600             -push 0x56d334
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690164 /*0x56d334*/;
    cpu.esp -= 4;
    // 00531a7b  6854c35600             -push 0x56c354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686100 /*0x56c354*/;
    cpu.esp -= 4;
    // 00531a80  e893d8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531a85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531a87  740c                   -je 0x531a95
    if (cpu.flags.zf)
    {
        goto L_0x00531a95;
    }
    // 00531a89  c70534d35600ffffffff   -mov dword ptr [0x56d334], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690164) /* 0x56d334 */) = 4294967295 /*0xffffffff*/;
    // 00531a93  eb1c                   -jmp 0x531ab1
    goto L_0x00531ab1;
L_0x00531a95:
    // 00531a95  833d34d35600ff         +cmp dword ptr [0x56d334], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690164) /* 0x56d334 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531a9c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531aa1  740e                   -je 0x531ab1
    if (cpu.flags.zf)
    {
        goto L_0x00531ab1;
    }
    // 00531aa3  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531aa7  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531aab  ff1534d35600           -call dword ptr [0x56d334]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690164) /* 0x56d334 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531ab1:
    // 00531ab1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531ab4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531ab4  833d38d3560000         +cmp dword ptr [0x56d338], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690168) /* 0x56d338 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531abb  751f                   -jne 0x531adc
    if (!cpu.flags.zf)
    {
        goto L_0x00531adc;
    }
    // 00531abd  6838d35600             -push 0x56d338
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690168 /*0x56d338*/;
    cpu.esp -= 4;
    // 00531ac2  6868c35600             -push 0x56c368
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686120 /*0x56c368*/;
    cpu.esp -= 4;
    // 00531ac7  e84cd8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531acc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531ace  740c                   -je 0x531adc
    if (cpu.flags.zf)
    {
        goto L_0x00531adc;
    }
    // 00531ad0  c70538d35600ffffffff   -mov dword ptr [0x56d338], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690168) /* 0x56d338 */) = 4294967295 /*0xffffffff*/;
    // 00531ada  eb18                   -jmp 0x531af4
    goto L_0x00531af4;
L_0x00531adc:
    // 00531adc  833d38d35600ff         +cmp dword ptr [0x56d338], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690168) /* 0x56d338 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531ae3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531ae8  740a                   -je 0x531af4
    if (cpu.flags.zf)
    {
        goto L_0x00531af4;
    }
    // 00531aea  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 00531aee  ff1538d35600           -call dword ptr [0x56d338]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690168) /* 0x56d338 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531af4:
    // 00531af4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_531af7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531af7  833d3cd3560000         +cmp dword ptr [0x56d33c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690172) /* 0x56d33c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531afe  751f                   -jne 0x531b1f
    if (!cpu.flags.zf)
    {
        goto L_0x00531b1f;
    }
    // 00531b00  683cd35600             -push 0x56d33c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690172 /*0x56d33c*/;
    cpu.esp -= 4;
    // 00531b05  6878c35600             -push 0x56c378
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686136 /*0x56c378*/;
    cpu.esp -= 4;
    // 00531b0a  e809d8ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531b0f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531b11  740c                   -je 0x531b1f
    if (cpu.flags.zf)
    {
        goto L_0x00531b1f;
    }
    // 00531b13  c7053cd35600ffffffff   -mov dword ptr [0x56d33c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690172) /* 0x56d33c */) = 4294967295 /*0xffffffff*/;
    // 00531b1d  eb20                   -jmp 0x531b3f
    goto L_0x00531b3f;
L_0x00531b1f:
    // 00531b1f  833d3cd35600ff         +cmp dword ptr [0x56d33c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690172) /* 0x56d33c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531b26  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531b2b  7412                   -je 0x531b3f
    if (cpu.flags.zf)
    {
        goto L_0x00531b3f;
    }
    // 00531b2d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b31  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b35  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b39  ff153cd35600           -call dword ptr [0x56d33c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690172) /* 0x56d33c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531b3f:
    // 00531b3f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531b42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531b42  833d40d3560000         +cmp dword ptr [0x56d340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690176) /* 0x56d340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531b49  751f                   -jne 0x531b6a
    if (!cpu.flags.zf)
    {
        goto L_0x00531b6a;
    }
    // 00531b4b  6840d35600             -push 0x56d340
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690176 /*0x56d340*/;
    cpu.esp -= 4;
    // 00531b50  6890c35600             -push 0x56c390
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686160 /*0x56c390*/;
    cpu.esp -= 4;
    // 00531b55  e8bed7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531b5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531b5c  740c                   -je 0x531b6a
    if (cpu.flags.zf)
    {
        goto L_0x00531b6a;
    }
    // 00531b5e  c70540d35600ffffffff   -mov dword ptr [0x56d340], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690176) /* 0x56d340 */) = 4294967295 /*0xffffffff*/;
    // 00531b68  eb20                   -jmp 0x531b8a
    goto L_0x00531b8a;
L_0x00531b6a:
    // 00531b6a  833d40d35600ff         +cmp dword ptr [0x56d340], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690176) /* 0x56d340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531b71  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531b76  7412                   -je 0x531b8a
    if (cpu.flags.zf)
    {
        goto L_0x00531b8a;
    }
    // 00531b78  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b7c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b80  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531b84  ff1540d35600           -call dword ptr [0x56d340]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690176) /* 0x56d340 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531b8a:
    // 00531b8a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531b8d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531b8d  833d44d3560000         +cmp dword ptr [0x56d344], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690180) /* 0x56d344 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531b94  751f                   -jne 0x531bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00531bb5;
    }
    // 00531b96  6844d35600             -push 0x56d344
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690180 /*0x56d344*/;
    cpu.esp -= 4;
    // 00531b9b  68a8c35600             -push 0x56c3a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686184 /*0x56c3a8*/;
    cpu.esp -= 4;
    // 00531ba0  e873d7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531ba5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531ba7  740c                   -je 0x531bb5
    if (cpu.flags.zf)
    {
        goto L_0x00531bb5;
    }
    // 00531ba9  c70544d35600ffffffff   -mov dword ptr [0x56d344], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690180) /* 0x56d344 */) = 4294967295 /*0xffffffff*/;
    // 00531bb3  eb20                   -jmp 0x531bd5
    goto L_0x00531bd5;
L_0x00531bb5:
    // 00531bb5  833d44d35600ff         +cmp dword ptr [0x56d344], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690180) /* 0x56d344 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531bbc  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531bc1  7412                   -je 0x531bd5
    if (cpu.flags.zf)
    {
        goto L_0x00531bd5;
    }
    // 00531bc3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531bc7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531bcb  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531bcf  ff1544d35600           -call dword ptr [0x56d344]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690180) /* 0x56d344 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531bd5:
    // 00531bd5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531bd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531bd8  833d48d3560000         +cmp dword ptr [0x56d348], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690184) /* 0x56d348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531bdf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531be0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531be2  751f                   -jne 0x531c03
    if (!cpu.flags.zf)
    {
        goto L_0x00531c03;
    }
    // 00531be4  6848d35600             -push 0x56d348
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690184 /*0x56d348*/;
    cpu.esp -= 4;
    // 00531be9  68bcc35600             -push 0x56c3bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686204 /*0x56c3bc*/;
    cpu.esp -= 4;
    // 00531bee  e825d7ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531bf5  740c                   -je 0x531c03
    if (cpu.flags.zf)
    {
        goto L_0x00531c03;
    }
    // 00531bf7  c70548d35600ffffffff   -mov dword ptr [0x56d348], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690184) /* 0x56d348 */) = 4294967295 /*0xffffffff*/;
    // 00531c01  eb20                   -jmp 0x531c23
    goto L_0x00531c23;
L_0x00531c03:
    // 00531c03  833d48d35600ff         +cmp dword ptr [0x56d348], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690184) /* 0x56d348 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531c0a  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531c0f  7412                   -je 0x531c23
    if (cpu.flags.zf)
    {
        goto L_0x00531c23;
    }
    // 00531c11  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531c14  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531c17  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531c1a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531c1d  ff1548d35600           -call dword ptr [0x56d348]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690184) /* 0x56d348 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531c23:
    // 00531c23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531c24  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_531c27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531c27  833d4cd3560000         +cmp dword ptr [0x56d34c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690188) /* 0x56d34c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531c2e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531c2f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531c31  751f                   -jne 0x531c52
    if (!cpu.flags.zf)
    {
        goto L_0x00531c52;
    }
    // 00531c33  684cd35600             -push 0x56d34c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690188 /*0x56d34c*/;
    cpu.esp -= 4;
    // 00531c38  68d0c35600             -push 0x56c3d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686224 /*0x56c3d0*/;
    cpu.esp -= 4;
    // 00531c3d  e8d6d6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531c42  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531c44  740c                   -je 0x531c52
    if (cpu.flags.zf)
    {
        goto L_0x00531c52;
    }
    // 00531c46  c7054cd35600ffffffff   -mov dword ptr [0x56d34c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690188) /* 0x56d34c */) = 4294967295 /*0xffffffff*/;
    // 00531c50  eb26                   -jmp 0x531c78
    goto L_0x00531c78;
L_0x00531c52:
    // 00531c52  833d4cd35600ff         +cmp dword ptr [0x56d34c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690188) /* 0x56d34c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531c59  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531c5e  7418                   -je 0x531c78
    if (cpu.flags.zf)
    {
        goto L_0x00531c78;
    }
    // 00531c60  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531c63  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531c66  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531c69  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531c6c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531c6f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531c72  ff154cd35600           -call dword ptr [0x56d34c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690188) /* 0x56d34c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531c78:
    // 00531c78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531c79  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_531c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531c7c  833d50d3560000         +cmp dword ptr [0x56d350], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690192) /* 0x56d350 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531c83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531c84  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531c86  751f                   -jne 0x531ca7
    if (!cpu.flags.zf)
    {
        goto L_0x00531ca7;
    }
    // 00531c88  6850d35600             -push 0x56d350
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690192 /*0x56d350*/;
    cpu.esp -= 4;
    // 00531c8d  68e4c35600             -push 0x56c3e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686244 /*0x56c3e4*/;
    cpu.esp -= 4;
    // 00531c92  e881d6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531c97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531c99  740c                   -je 0x531ca7
    if (cpu.flags.zf)
    {
        goto L_0x00531ca7;
    }
    // 00531c9b  c70550d35600ffffffff   -mov dword ptr [0x56d350], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690192) /* 0x56d350 */) = 4294967295 /*0xffffffff*/;
    // 00531ca5  eb26                   -jmp 0x531ccd
    goto L_0x00531ccd;
L_0x00531ca7:
    // 00531ca7  833d50d35600ff         +cmp dword ptr [0x56d350], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690192) /* 0x56d350 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531cae  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531cb3  7418                   -je 0x531ccd
    if (cpu.flags.zf)
    {
        goto L_0x00531ccd;
    }
    // 00531cb5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531cb8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531cbb  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531cbe  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531cc1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531cc4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531cc7  ff1550d35600           -call dword ptr [0x56d350]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690192) /* 0x56d350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531ccd:
    // 00531ccd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531cce  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_531cd1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531cd1  833d54d3560000         +cmp dword ptr [0x56d354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690196) /* 0x56d354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531cd8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531cd9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531cdb  751f                   -jne 0x531cfc
    if (!cpu.flags.zf)
    {
        goto L_0x00531cfc;
    }
    // 00531cdd  6854d35600             -push 0x56d354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690196 /*0x56d354*/;
    cpu.esp -= 4;
    // 00531ce2  68f8c35600             -push 0x56c3f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686264 /*0x56c3f8*/;
    cpu.esp -= 4;
    // 00531ce7  e82cd6ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531cec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531cee  740c                   -je 0x531cfc
    if (cpu.flags.zf)
    {
        goto L_0x00531cfc;
    }
    // 00531cf0  c70554d35600ffffffff   -mov dword ptr [0x56d354], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690196) /* 0x56d354 */) = 4294967295 /*0xffffffff*/;
    // 00531cfa  eb26                   -jmp 0x531d22
    goto L_0x00531d22;
L_0x00531cfc:
    // 00531cfc  833d54d35600ff         +cmp dword ptr [0x56d354], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690196) /* 0x56d354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531d03  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531d08  7418                   -je 0x531d22
    if (cpu.flags.zf)
    {
        goto L_0x00531d22;
    }
    // 00531d0a  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00531d0d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531d10  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531d13  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531d16  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531d19  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531d1c  ff1554d35600           -call dword ptr [0x56d354]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690196) /* 0x56d354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531d22:
    // 00531d22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531d23  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_531d26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531d26  833d58d3560000         +cmp dword ptr [0x56d358], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690200) /* 0x56d358 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531d2d  751f                   -jne 0x531d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00531d4e;
    }
    // 00531d2f  6858d35600             -push 0x56d358
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690200 /*0x56d358*/;
    cpu.esp -= 4;
    // 00531d34  680cc45600             -push 0x56c40c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686284 /*0x56c40c*/;
    cpu.esp -= 4;
    // 00531d39  e8dad5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531d3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531d40  740c                   -je 0x531d4e
    if (cpu.flags.zf)
    {
        goto L_0x00531d4e;
    }
    // 00531d42  c70558d35600ffffffff   -mov dword ptr [0x56d358], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690200) /* 0x56d358 */) = 4294967295 /*0xffffffff*/;
    // 00531d4c  eb1c                   -jmp 0x531d6a
    goto L_0x00531d6a;
L_0x00531d4e:
    // 00531d4e  833d58d35600ff         +cmp dword ptr [0x56d358], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690200) /* 0x56d358 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531d55  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531d5a  740e                   -je 0x531d6a
    if (cpu.flags.zf)
    {
        goto L_0x00531d6a;
    }
    // 00531d5c  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531d60  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531d64  ff1558d35600           -call dword ptr [0x56d358]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690200) /* 0x56d358 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531d6a:
    // 00531d6a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531d6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531d6d  833d5cd3560000         +cmp dword ptr [0x56d35c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690204) /* 0x56d35c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531d74  751f                   -jne 0x531d95
    if (!cpu.flags.zf)
    {
        goto L_0x00531d95;
    }
    // 00531d76  685cd35600             -push 0x56d35c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690204 /*0x56d35c*/;
    cpu.esp -= 4;
    // 00531d7b  6820c45600             -push 0x56c420
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686304 /*0x56c420*/;
    cpu.esp -= 4;
    // 00531d80  e893d5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531d85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531d87  740c                   -je 0x531d95
    if (cpu.flags.zf)
    {
        goto L_0x00531d95;
    }
    // 00531d89  c7055cd35600ffffffff   -mov dword ptr [0x56d35c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690204) /* 0x56d35c */) = 4294967295 /*0xffffffff*/;
    // 00531d93  eb20                   -jmp 0x531db5
    goto L_0x00531db5;
L_0x00531d95:
    // 00531d95  833d5cd35600ff         +cmp dword ptr [0x56d35c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690204) /* 0x56d35c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531d9c  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531da1  7412                   -je 0x531db5
    if (cpu.flags.zf)
    {
        goto L_0x00531db5;
    }
    // 00531da3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531da7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531dab  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531daf  ff155cd35600           -call dword ptr [0x56d35c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690204) /* 0x56d35c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531db5:
    // 00531db5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_531db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531db8  833d60d3560000         +cmp dword ptr [0x56d360], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690208) /* 0x56d360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531dbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531dc0  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531dc2  751f                   -jne 0x531de3
    if (!cpu.flags.zf)
    {
        goto L_0x00531de3;
    }
    // 00531dc4  6860d35600             -push 0x56d360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690208 /*0x56d360*/;
    cpu.esp -= 4;
    // 00531dc9  6830c45600             -push 0x56c430
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686320 /*0x56c430*/;
    cpu.esp -= 4;
    // 00531dce  e845d5ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531dd3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531dd5  740c                   -je 0x531de3
    if (cpu.flags.zf)
    {
        goto L_0x00531de3;
    }
    // 00531dd7  c70560d35600ffffffff   -mov dword ptr [0x56d360], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690208) /* 0x56d360 */) = 4294967295 /*0xffffffff*/;
    // 00531de1  eb23                   -jmp 0x531e06
    goto L_0x00531e06;
L_0x00531de3:
    // 00531de3  833d60d35600ff         +cmp dword ptr [0x56d360], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690208) /* 0x56d360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531dea  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531def  7415                   -je 0x531e06
    if (cpu.flags.zf)
    {
        goto L_0x00531e06;
    }
    // 00531df1  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531df4  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531df7  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531dfa  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531dfd  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531e00  ff1560d35600           -call dword ptr [0x56d360]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690208) /* 0x56d360 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531e06:
    // 00531e06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531e07  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531e0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531e0a  833d64d3560000         +cmp dword ptr [0x56d364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690212) /* 0x56d364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531e11  751f                   -jne 0x531e32
    if (!cpu.flags.zf)
    {
        goto L_0x00531e32;
    }
    // 00531e13  6864d35600             -push 0x56d364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690212 /*0x56d364*/;
    cpu.esp -= 4;
    // 00531e18  6844c45600             -push 0x56c444
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686340 /*0x56c444*/;
    cpu.esp -= 4;
    // 00531e1d  e8f6d4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531e22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531e24  740c                   -je 0x531e32
    if (cpu.flags.zf)
    {
        goto L_0x00531e32;
    }
    // 00531e26  c70564d35600ffffffff   -mov dword ptr [0x56d364], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690212) /* 0x56d364 */) = 4294967295 /*0xffffffff*/;
    // 00531e30  eb1c                   -jmp 0x531e4e
    goto L_0x00531e4e;
L_0x00531e32:
    // 00531e32  833d64d35600ff         +cmp dword ptr [0x56d364], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690212) /* 0x56d364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531e39  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531e3e  740e                   -je 0x531e4e
    if (cpu.flags.zf)
    {
        goto L_0x00531e4e;
    }
    // 00531e40  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531e44  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531e48  ff1564d35600           -call dword ptr [0x56d364]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690212) /* 0x56d364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531e4e:
    // 00531e4e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531e51(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531e51  833d68d3560000         +cmp dword ptr [0x56d368], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690216) /* 0x56d368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531e58  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531e59  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531e5b  751f                   -jne 0x531e7c
    if (!cpu.flags.zf)
    {
        goto L_0x00531e7c;
    }
    // 00531e5d  6868d35600             -push 0x56d368
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690216 /*0x56d368*/;
    cpu.esp -= 4;
    // 00531e62  685cc45600             -push 0x56c45c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686364 /*0x56c45c*/;
    cpu.esp -= 4;
    // 00531e67  e8acd4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531e6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531e6e  740c                   -je 0x531e7c
    if (cpu.flags.zf)
    {
        goto L_0x00531e7c;
    }
    // 00531e70  c70568d35600ffffffff   -mov dword ptr [0x56d368], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690216) /* 0x56d368 */) = 4294967295 /*0xffffffff*/;
    // 00531e7a  eb23                   -jmp 0x531e9f
    goto L_0x00531e9f;
L_0x00531e7c:
    // 00531e7c  833d68d35600ff         +cmp dword ptr [0x56d368], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690216) /* 0x56d368 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531e83  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531e88  7415                   -je 0x531e9f
    if (cpu.flags.zf)
    {
        goto L_0x00531e9f;
    }
    // 00531e8a  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00531e8d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531e90  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531e93  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531e96  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531e99  ff1568d35600           -call dword ptr [0x56d368]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690216) /* 0x56d368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531e9f:
    // 00531e9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531ea0  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_531ea3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531ea3  833d6cd3560000         +cmp dword ptr [0x56d36c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690220) /* 0x56d36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531eaa  751f                   -jne 0x531ecb
    if (!cpu.flags.zf)
    {
        goto L_0x00531ecb;
    }
    // 00531eac  686cd35600             -push 0x56d36c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690220 /*0x56d36c*/;
    cpu.esp -= 4;
    // 00531eb1  6878c45600             -push 0x56c478
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686392 /*0x56c478*/;
    cpu.esp -= 4;
    // 00531eb6  e85dd4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531ebb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531ebd  740c                   -je 0x531ecb
    if (cpu.flags.zf)
    {
        goto L_0x00531ecb;
    }
    // 00531ebf  c7056cd35600ffffffff   -mov dword ptr [0x56d36c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690220) /* 0x56d36c */) = 4294967295 /*0xffffffff*/;
    // 00531ec9  eb1c                   -jmp 0x531ee7
    goto L_0x00531ee7;
L_0x00531ecb:
    // 00531ecb  833d6cd35600ff         +cmp dword ptr [0x56d36c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690220) /* 0x56d36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531ed2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531ed7  740e                   -je 0x531ee7
    if (cpu.flags.zf)
    {
        goto L_0x00531ee7;
    }
    // 00531ed9  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531edd  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531ee1  ff156cd35600           -call dword ptr [0x56d36c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690220) /* 0x56d36c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531ee7:
    // 00531ee7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531eea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531eea  833d70d3560000         +cmp dword ptr [0x56d370], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690224) /* 0x56d370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531ef1  751f                   -jne 0x531f12
    if (!cpu.flags.zf)
    {
        goto L_0x00531f12;
    }
    // 00531ef3  6870d35600             -push 0x56d370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690224 /*0x56d370*/;
    cpu.esp -= 4;
    // 00531ef8  6890c45600             -push 0x56c490
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686416 /*0x56c490*/;
    cpu.esp -= 4;
    // 00531efd  e816d4ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531f02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531f04  740c                   -je 0x531f12
    if (cpu.flags.zf)
    {
        goto L_0x00531f12;
    }
    // 00531f06  c70570d35600ffffffff   -mov dword ptr [0x56d370], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690224) /* 0x56d370 */) = 4294967295 /*0xffffffff*/;
    // 00531f10  eb1c                   -jmp 0x531f2e
    goto L_0x00531f2e;
L_0x00531f12:
    // 00531f12  833d70d35600ff         +cmp dword ptr [0x56d370], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690224) /* 0x56d370 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531f19  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531f1e  740e                   -je 0x531f2e
    if (cpu.flags.zf)
    {
        goto L_0x00531f2e;
    }
    // 00531f20  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531f24  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531f28  ff1570d35600           -call dword ptr [0x56d370]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690224) /* 0x56d370 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531f2e:
    // 00531f2e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_531f31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531f31  833d74d3560000         +cmp dword ptr [0x56d374], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690228) /* 0x56d374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531f38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531f39  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531f3b  751f                   -jne 0x531f5c
    if (!cpu.flags.zf)
    {
        goto L_0x00531f5c;
    }
    // 00531f3d  6874d35600             -push 0x56d374
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690228 /*0x56d374*/;
    cpu.esp -= 4;
    // 00531f42  68a8c45600             -push 0x56c4a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686440 /*0x56c4a8*/;
    cpu.esp -= 4;
    // 00531f47  e8ccd3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531f4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531f4e  740c                   -je 0x531f5c
    if (cpu.flags.zf)
    {
        goto L_0x00531f5c;
    }
    // 00531f50  c70574d35600ffffffff   -mov dword ptr [0x56d374], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690228) /* 0x56d374 */) = 4294967295 /*0xffffffff*/;
    // 00531f5a  eb20                   -jmp 0x531f7c
    goto L_0x00531f7c;
L_0x00531f5c:
    // 00531f5c  833d74d35600ff         +cmp dword ptr [0x56d374], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690228) /* 0x56d374 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531f63  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531f68  7412                   -je 0x531f7c
    if (cpu.flags.zf)
    {
        goto L_0x00531f7c;
    }
    // 00531f6a  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531f6d  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531f70  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531f73  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531f76  ff1574d35600           -call dword ptr [0x56d374]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690228) /* 0x56d374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531f7c:
    // 00531f7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531f7d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_531f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531f80  833d78d3560000         +cmp dword ptr [0x56d378], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690232) /* 0x56d378 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531f87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531f88  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531f8a  751f                   -jne 0x531fab
    if (!cpu.flags.zf)
    {
        goto L_0x00531fab;
    }
    // 00531f8c  6878d35600             -push 0x56d378
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690232 /*0x56d378*/;
    cpu.esp -= 4;
    // 00531f91  68bcc45600             -push 0x56c4bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686460 /*0x56c4bc*/;
    cpu.esp -= 4;
    // 00531f96  e87dd3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531f9b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531f9d  740c                   -je 0x531fab
    if (cpu.flags.zf)
    {
        goto L_0x00531fab;
    }
    // 00531f9f  c70578d35600ffffffff   -mov dword ptr [0x56d378], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690232) /* 0x56d378 */) = 4294967295 /*0xffffffff*/;
    // 00531fa9  eb20                   -jmp 0x531fcb
    goto L_0x00531fcb;
L_0x00531fab:
    // 00531fab  833d78d35600ff         +cmp dword ptr [0x56d378], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690232) /* 0x56d378 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531fb2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00531fb7  7412                   -je 0x531fcb
    if (cpu.flags.zf)
    {
        goto L_0x00531fcb;
    }
    // 00531fb9  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00531fbc  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00531fbf  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00531fc2  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00531fc5  ff1578d35600           -call dword ptr [0x56d378]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690232) /* 0x56d378 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00531fcb:
    // 00531fcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00531fcc  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_531fcf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00531fcf  833d7cd3560000         +cmp dword ptr [0x56d37c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690236) /* 0x56d37c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00531fd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00531fd7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00531fd9  751f                   -jne 0x531ffa
    if (!cpu.flags.zf)
    {
        goto L_0x00531ffa;
    }
    // 00531fdb  687cd35600             -push 0x56d37c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690236 /*0x56d37c*/;
    cpu.esp -= 4;
    // 00531fe0  68d0c45600             -push 0x56c4d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686480 /*0x56c4d0*/;
    cpu.esp -= 4;
    // 00531fe5  e82ed3ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00531fea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00531fec  740c                   -je 0x531ffa
    if (cpu.flags.zf)
    {
        goto L_0x00531ffa;
    }
    // 00531fee  c7057cd35600ffffffff   -mov dword ptr [0x56d37c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690236) /* 0x56d37c */) = 4294967295 /*0xffffffff*/;
    // 00531ff8  eb20                   -jmp 0x53201a
    goto L_0x0053201a;
L_0x00531ffa:
    // 00531ffa  833d7cd35600ff         +cmp dword ptr [0x56d37c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690236) /* 0x56d37c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532001  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532006  7412                   -je 0x53201a
    if (cpu.flags.zf)
    {
        goto L_0x0053201a;
    }
    // 00532008  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 0053200b  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053200e  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532011  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532014  ff157cd35600           -call dword ptr [0x56d37c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690236) /* 0x56d37c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053201a:
    // 0053201a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0053201b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_53201e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053201e  833d80d3560000         +cmp dword ptr [0x56d380], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690240) /* 0x56d380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532025  751f                   -jne 0x532046
    if (!cpu.flags.zf)
    {
        goto L_0x00532046;
    }
    // 00532027  6880d35600             -push 0x56d380
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690240 /*0x56d380*/;
    cpu.esp -= 4;
    // 0053202c  68e4c45600             -push 0x56c4e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686500 /*0x56c4e4*/;
    cpu.esp -= 4;
    // 00532031  e8e2d2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532036  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532038  740c                   -je 0x532046
    if (cpu.flags.zf)
    {
        goto L_0x00532046;
    }
    // 0053203a  c70580d35600ffffffff   -mov dword ptr [0x56d380], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690240) /* 0x56d380 */) = 4294967295 /*0xffffffff*/;
    // 00532044  eb20                   -jmp 0x532066
    goto L_0x00532066;
L_0x00532046:
    // 00532046  833d80d35600ff         +cmp dword ptr [0x56d380], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690240) /* 0x56d380 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053204d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532052  7412                   -je 0x532066
    if (cpu.flags.zf)
    {
        goto L_0x00532066;
    }
    // 00532054  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532058  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053205c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532060  ff1580d35600           -call dword ptr [0x56d380]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690240) /* 0x56d380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532066:
    // 00532066  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532069(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532069  833d84d3560000         +cmp dword ptr [0x56d384], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690244) /* 0x56d384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532070  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00532071  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532073  751f                   -jne 0x532094
    if (!cpu.flags.zf)
    {
        goto L_0x00532094;
    }
    // 00532075  6884d35600             -push 0x56d384
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690244 /*0x56d384*/;
    cpu.esp -= 4;
    // 0053207a  68fcc45600             -push 0x56c4fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686524 /*0x56c4fc*/;
    cpu.esp -= 4;
    // 0053207f  e894d2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532084  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532086  740c                   -je 0x532094
    if (cpu.flags.zf)
    {
        goto L_0x00532094;
    }
    // 00532088  c70584d35600ffffffff   -mov dword ptr [0x56d384], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690244) /* 0x56d384 */) = 4294967295 /*0xffffffff*/;
    // 00532092  eb38                   -jmp 0x5320cc
    goto L_0x005320cc;
L_0x00532094:
    // 00532094  833d84d35600ff         +cmp dword ptr [0x56d384], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690244) /* 0x56d384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053209b  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005320a0  742a                   -je 0x5320cc
    if (cpu.flags.zf)
    {
        goto L_0x005320cc;
    }
    // 005320a2  ff7534                 -push dword ptr [ebp + 0x34]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    // 005320a5  ff7530                 -push dword ptr [ebp + 0x30]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    // 005320a8  ff752c                 -push dword ptr [ebp + 0x2c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    // 005320ab  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 005320ae  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 005320b1  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005320b4  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005320b7  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005320ba  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005320bd  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005320c0  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005320c3  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005320c6  ff1584d35600           -call dword ptr [0x56d384]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690244) /* 0x56d384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005320cc:
    // 005320cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005320cd  c23000                 -ret 0x30
    cpu.esp += 4+48 /*0x30*/;
    return;
}

/* align: skip  */
void Application::sub_5320d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005320d0  833d88d3560000         +cmp dword ptr [0x56d388], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690248) /* 0x56d388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005320d7  751f                   -jne 0x5320f8
    if (!cpu.flags.zf)
    {
        goto L_0x005320f8;
    }
    // 005320d9  6888d35600             -push 0x56d388
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690248 /*0x56d388*/;
    cpu.esp -= 4;
    // 005320de  6810c55600             -push 0x56c510
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686544 /*0x56c510*/;
    cpu.esp -= 4;
    // 005320e3  e830d2ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005320e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005320ea  740c                   -je 0x5320f8
    if (cpu.flags.zf)
    {
        goto L_0x005320f8;
    }
    // 005320ec  c70588d35600ffffffff   -mov dword ptr [0x56d388], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690248) /* 0x56d388 */) = 4294967295 /*0xffffffff*/;
    // 005320f6  eb1c                   -jmp 0x532114
    goto L_0x00532114;
L_0x005320f8:
    // 005320f8  833d88d35600ff         +cmp dword ptr [0x56d388], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690248) /* 0x56d388 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005320ff  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532104  740e                   -je 0x532114
    if (cpu.flags.zf)
    {
        goto L_0x00532114;
    }
    // 00532106  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053210a  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053210e  ff1588d35600           -call dword ptr [0x56d388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690248) /* 0x56d388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532114:
    // 00532114  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_532117(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532117  833d8cd3560000         +cmp dword ptr [0x56d38c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690252) /* 0x56d38c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053211e  751f                   -jne 0x53213f
    if (!cpu.flags.zf)
    {
        goto L_0x0053213f;
    }
    // 00532120  688cd35600             -push 0x56d38c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690252 /*0x56d38c*/;
    cpu.esp -= 4;
    // 00532125  6824c55600             -push 0x56c524
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686564 /*0x56c524*/;
    cpu.esp -= 4;
    // 0053212a  e8e9d1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053212f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532131  740c                   -je 0x53213f
    if (cpu.flags.zf)
    {
        goto L_0x0053213f;
    }
    // 00532133  c7058cd35600ffffffff   -mov dword ptr [0x56d38c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690252) /* 0x56d38c */) = 4294967295 /*0xffffffff*/;
    // 0053213d  eb20                   -jmp 0x53215f
    goto L_0x0053215f;
L_0x0053213f:
    // 0053213f  833d8cd35600ff         +cmp dword ptr [0x56d38c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690252) /* 0x56d38c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532146  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053214b  7412                   -je 0x53215f
    if (cpu.flags.zf)
    {
        goto L_0x0053215f;
    }
    // 0053214d  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532151  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532155  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532159  ff158cd35600           -call dword ptr [0x56d38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690252) /* 0x56d38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053215f:
    // 0053215f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_532162(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532162  833d90d3560000         +cmp dword ptr [0x56d390], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690256) /* 0x56d390 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532169  751f                   -jne 0x53218a
    if (!cpu.flags.zf)
    {
        goto L_0x0053218a;
    }
    // 0053216b  6890d35600             -push 0x56d390
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690256 /*0x56d390*/;
    cpu.esp -= 4;
    // 00532170  6834c55600             -push 0x56c534
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686580 /*0x56c534*/;
    cpu.esp -= 4;
    // 00532175  e89ed1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053217a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053217c  740c                   -je 0x53218a
    if (cpu.flags.zf)
    {
        goto L_0x0053218a;
    }
    // 0053217e  c70590d35600ffffffff   -mov dword ptr [0x56d390], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690256) /* 0x56d390 */) = 4294967295 /*0xffffffff*/;
    // 00532188  eb20                   -jmp 0x5321aa
    goto L_0x005321aa;
L_0x0053218a:
    // 0053218a  833d90d35600ff         +cmp dword ptr [0x56d390], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690256) /* 0x56d390 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532191  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532196  7412                   -je 0x5321aa
    if (cpu.flags.zf)
    {
        goto L_0x005321aa;
    }
    // 00532198  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053219c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005321a0  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005321a4  ff1590d35600           -call dword ptr [0x56d390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690256) /* 0x56d390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005321aa:
    // 005321aa  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_5321ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005321ad  833d94d3560000         +cmp dword ptr [0x56d394], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690260) /* 0x56d394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005321b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005321b5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005321b7  751f                   -jne 0x5321d8
    if (!cpu.flags.zf)
    {
        goto L_0x005321d8;
    }
    // 005321b9  6894d35600             -push 0x56d394
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690260 /*0x56d394*/;
    cpu.esp -= 4;
    // 005321be  684cc55600             -push 0x56c54c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686604 /*0x56c54c*/;
    cpu.esp -= 4;
    // 005321c3  e850d1ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005321c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005321ca  740c                   -je 0x5321d8
    if (cpu.flags.zf)
    {
        goto L_0x005321d8;
    }
    // 005321cc  c70594d35600ffffffff   -mov dword ptr [0x56d394], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690260) /* 0x56d394 */) = 4294967295 /*0xffffffff*/;
    // 005321d6  eb29                   -jmp 0x532201
    goto L_0x00532201;
L_0x005321d8:
    // 005321d8  833d94d35600ff         +cmp dword ptr [0x56d394], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690260) /* 0x56d394 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005321df  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005321e4  741b                   -je 0x532201
    if (cpu.flags.zf)
    {
        goto L_0x00532201;
    }
    // 005321e6  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 005321e9  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005321ec  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005321ef  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005321f2  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005321f5  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005321f8  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005321fb  ff1594d35600           -call dword ptr [0x56d394]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690260) /* 0x56d394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532201:
    // 00532201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532202  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip  */
void Application::sub_532205(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532205  833d98d3560000         +cmp dword ptr [0x56d398], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690264) /* 0x56d398 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053220c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053220d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053220f  751f                   -jne 0x532230
    if (!cpu.flags.zf)
    {
        goto L_0x00532230;
    }
    // 00532211  6898d35600             -push 0x56d398
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690264 /*0x56d398*/;
    cpu.esp -= 4;
    // 00532216  685cc55600             -push 0x56c55c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686620 /*0x56c55c*/;
    cpu.esp -= 4;
    // 0053221b  e8f8d0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532220  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532222  740c                   -je 0x532230
    if (cpu.flags.zf)
    {
        goto L_0x00532230;
    }
    // 00532224  c70598d35600ffffffff   -mov dword ptr [0x56d398], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690264) /* 0x56d398 */) = 4294967295 /*0xffffffff*/;
    // 0053222e  eb20                   -jmp 0x532250
    goto L_0x00532250;
L_0x00532230:
    // 00532230  833d98d35600ff         +cmp dword ptr [0x56d398], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690264) /* 0x56d398 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532237  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053223c  7412                   -je 0x532250
    if (cpu.flags.zf)
    {
        goto L_0x00532250;
    }
    // 0053223e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532241  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532244  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532247  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053224a  ff1598d35600           -call dword ptr [0x56d398]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690264) /* 0x56d398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532250:
    // 00532250  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532251  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_532254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532254  833d9cd3560000         +cmp dword ptr [0x56d39c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690268) /* 0x56d39c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053225b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053225c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0053225e  751f                   -jne 0x53227f
    if (!cpu.flags.zf)
    {
        goto L_0x0053227f;
    }
    // 00532260  689cd35600             -push 0x56d39c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690268 /*0x56d39c*/;
    cpu.esp -= 4;
    // 00532265  686cc55600             -push 0x56c56c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686636 /*0x56c56c*/;
    cpu.esp -= 4;
    // 0053226a  e8a9d0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053226f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532271  740c                   -je 0x53227f
    if (cpu.flags.zf)
    {
        goto L_0x0053227f;
    }
    // 00532273  c7059cd35600ffffffff   -mov dword ptr [0x56d39c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690268) /* 0x56d39c */) = 4294967295 /*0xffffffff*/;
    // 0053227d  eb20                   -jmp 0x53229f
    goto L_0x0053229f;
L_0x0053227f:
    // 0053227f  833d9cd35600ff         +cmp dword ptr [0x56d39c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690268) /* 0x56d39c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532286  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053228b  7412                   -je 0x53229f
    if (cpu.flags.zf)
    {
        goto L_0x0053229f;
    }
    // 0053228d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532290  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532293  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 00532296  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532299  ff159cd35600           -call dword ptr [0x56d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690268) /* 0x56d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0053229f:
    // 0053229f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005322a0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5322a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005322a3  833da0d3560000         +cmp dword ptr [0x56d3a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690272) /* 0x56d3a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005322aa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005322ab  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005322ad  751f                   -jne 0x5322ce
    if (!cpu.flags.zf)
    {
        goto L_0x005322ce;
    }
    // 005322af  68a0d35600             -push 0x56d3a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690272 /*0x56d3a0*/;
    cpu.esp -= 4;
    // 005322b4  6880c55600             -push 0x56c580
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686656 /*0x56c580*/;
    cpu.esp -= 4;
    // 005322b9  e85ad0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005322be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005322c0  740c                   -je 0x5322ce
    if (cpu.flags.zf)
    {
        goto L_0x005322ce;
    }
    // 005322c2  c705a0d35600ffffffff   -mov dword ptr [0x56d3a0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690272) /* 0x56d3a0 */) = 4294967295 /*0xffffffff*/;
    // 005322cc  eb20                   -jmp 0x5322ee
    goto L_0x005322ee;
L_0x005322ce:
    // 005322ce  833da0d35600ff         +cmp dword ptr [0x56d3a0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690272) /* 0x56d3a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005322d5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005322da  7412                   -je 0x5322ee
    if (cpu.flags.zf)
    {
        goto L_0x005322ee;
    }
    // 005322dc  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005322df  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005322e2  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005322e5  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005322e8  ff15a0d35600           -call dword ptr [0x56d3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690272) /* 0x56d3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005322ee:
    // 005322ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005322ef  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_5322f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005322f2  833da4d3560000         +cmp dword ptr [0x56d3a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690276) /* 0x56d3a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005322f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005322fa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005322fc  751f                   -jne 0x53231d
    if (!cpu.flags.zf)
    {
        goto L_0x0053231d;
    }
    // 005322fe  68a4d35600             -push 0x56d3a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690276 /*0x56d3a4*/;
    cpu.esp -= 4;
    // 00532303  6894c55600             -push 0x56c594
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686676 /*0x56c594*/;
    cpu.esp -= 4;
    // 00532308  e80bd0ffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 0053230d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0053230f  740c                   -je 0x53231d
    if (cpu.flags.zf)
    {
        goto L_0x0053231d;
    }
    // 00532311  c705a4d35600ffffffff   -mov dword ptr [0x56d3a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690276) /* 0x56d3a4 */) = 4294967295 /*0xffffffff*/;
    // 0053231b  eb26                   -jmp 0x532343
    goto L_0x00532343;
L_0x0053231d:
    // 0053231d  833da4d35600ff         +cmp dword ptr [0x56d3a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690276) /* 0x56d3a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532324  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 00532329  7418                   -je 0x532343
    if (cpu.flags.zf)
    {
        goto L_0x00532343;
    }
    // 0053232b  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 0053232e  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532331  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532334  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 00532337  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053233a  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 0053233d  ff15a4d35600           -call dword ptr [0x56d3a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690276) /* 0x56d3a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532343:
    // 00532343  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532344  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_532347(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00532347  833da8d3560000         +cmp dword ptr [0x56d3a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690280) /* 0x56d3a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0053234e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0053234f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00532351  751f                   -jne 0x532372
    if (!cpu.flags.zf)
    {
        goto L_0x00532372;
    }
    // 00532353  68a8d35600             -push 0x56d3a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690280 /*0x56d3a8*/;
    cpu.esp -= 4;
    // 00532358  68a8c55600             -push 0x56c5a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686696 /*0x56c5a8*/;
    cpu.esp -= 4;
    // 0053235d  e8b6cfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 00532362  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00532364  740c                   -je 0x532372
    if (cpu.flags.zf)
    {
        goto L_0x00532372;
    }
    // 00532366  c705a8d35600ffffffff   -mov dword ptr [0x56d3a8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690280) /* 0x56d3a8 */) = 4294967295 /*0xffffffff*/;
    // 00532370  eb26                   -jmp 0x532398
    goto L_0x00532398;
L_0x00532372:
    // 00532372  833da8d35600ff         +cmp dword ptr [0x56d3a8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690280) /* 0x56d3a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00532379  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 0053237e  7418                   -je 0x532398
    if (cpu.flags.zf)
    {
        goto L_0x00532398;
    }
    // 00532380  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 00532383  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 00532386  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 00532389  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 0053238c  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0053238f  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 00532392  ff15a8d35600           -call dword ptr [0x56d3a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690280) /* 0x56d3a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00532398:
    // 00532398  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00532399  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_53239c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0053239c  833dacd3560000         +cmp dword ptr [0x56d3ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690284) /* 0x56d3ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005323a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005323a4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005323a6  751f                   -jne 0x5323c7
    if (!cpu.flags.zf)
    {
        goto L_0x005323c7;
    }
    // 005323a8  68acd35600             -push 0x56d3ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5690284 /*0x56d3ac*/;
    cpu.esp -= 4;
    // 005323ad  68c0c55600             -push 0x56c5c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5686720 /*0x56c5c0*/;
    cpu.esp -= 4;
    // 005323b2  e861cfffff             -call 0x52f318
    cpu.esp -= 4;
    sub_52f318(app, cpu);
    if (cpu.terminate) return;
    // 005323b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005323b9  740c                   -je 0x5323c7
    if (cpu.flags.zf)
    {
        goto L_0x005323c7;
    }
    // 005323bb  c705acd35600ffffffff   -mov dword ptr [0x56d3ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5690284) /* 0x56d3ac */) = 4294967295 /*0xffffffff*/;
    // 005323c5  eb26                   -jmp 0x5323ed
    goto L_0x005323ed;
L_0x005323c7:
    // 005323c7  833dacd35600ff         +cmp dword ptr [0x56d3ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5690284) /* 0x56d3ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005323ce  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 005323d3  7418                   -je 0x5323ed
    if (cpu.flags.zf)
    {
        goto L_0x005323ed;
    }
    // 005323d5  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 005323d8  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 005323db  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 005323de  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 005323e1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 005323e4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 005323e7  ff15acd35600           -call dword ptr [0x56d3ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5690284) /* 0x56d3ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005323ed:
    // 005323ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005323ee  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

}
