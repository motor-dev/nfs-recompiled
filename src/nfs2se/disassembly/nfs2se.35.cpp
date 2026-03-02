#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4b41d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b41d8  833dfce04c0000         +cmp dword ptr [0x4ce0fc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038332) /* 0x4ce0fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b41df  751f                   -jne 0x4b4200
    if (!cpu.flags.zf)
    {
        goto L_0x004b4200;
    }
    // 004b41e1  68fce04c00             -push 0x4ce0fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038332 /*0x4ce0fc*/;
    cpu.esp -= 4;
    // 004b41e6  6800e54c00             -push 0x4ce500
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5039360 /*0x4ce500*/;
    cpu.esp -= 4;
    // 004b41eb  e890ffffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b41f0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b41f2  740c                   -je 0x4b4200
    if (cpu.flags.zf)
    {
        goto L_0x004b4200;
    }
    // 004b41f4  c705fce04c00ffffffff   -mov dword ptr [0x4ce0fc], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038332) /* 0x4ce0fc */) = 4294967295 /*0xffffffff*/;
    // 004b41fe  eb20                   -jmp 0x4b4220
    goto L_0x004b4220;
L_0x004b4200:
    // 004b4200  833dfce04c00ff         +cmp dword ptr [0x4ce0fc], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038332) /* 0x4ce0fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4207  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b420c  7412                   -je 0x4b4220
    if (cpu.flags.zf)
    {
        goto L_0x004b4220;
    }
    // 004b420e  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4212  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4216  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b421a  ff15fce04c00           -call dword ptr [0x4ce0fc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038332) /* 0x4ce0fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b4220:
    // 004b4220  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b4223(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4223  833d0ce14c0000         +cmp dword ptr [0x4ce10c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038348) /* 0x4ce10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b422a  751f                   -jne 0x4b424b
    if (!cpu.flags.zf)
    {
        goto L_0x004b424b;
    }
    // 004b422c  680ce14c00             -push 0x4ce10c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038348 /*0x4ce10c*/;
    cpu.esp -= 4;
    // 004b4231  6848e54c00             -push 0x4ce548
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5039432 /*0x4ce548*/;
    cpu.esp -= 4;
    // 004b4236  e845ffffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b423b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b423d  740c                   -je 0x4b424b
    if (cpu.flags.zf)
    {
        goto L_0x004b424b;
    }
    // 004b423f  c7050ce14c00ffffffff   -mov dword ptr [0x4ce10c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038348) /* 0x4ce10c */) = 4294967295 /*0xffffffff*/;
    // 004b4249  eb18                   -jmp 0x4b4263
    goto L_0x004b4263;
L_0x004b424b:
    // 004b424b  833d0ce14c00ff         +cmp dword ptr [0x4ce10c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038348) /* 0x4ce10c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4252  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b4257  740a                   -je 0x4b4263
    if (cpu.flags.zf)
    {
        goto L_0x004b4263;
    }
    // 004b4259  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b425d  ff150ce14c00           -call dword ptr [0x4ce10c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038348) /* 0x4ce10c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b4263:
    // 004b4263  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b4266(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4266  833d34e14c0000         +cmp dword ptr [0x4ce134], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038388) /* 0x4ce134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b426d  751f                   -jne 0x4b428e
    if (!cpu.flags.zf)
    {
        goto L_0x004b428e;
    }
    // 004b426f  6834e14c00             -push 0x4ce134
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038388 /*0x4ce134*/;
    cpu.esp -= 4;
    // 004b4274  6818e64c00             -push 0x4ce618
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5039640 /*0x4ce618*/;
    cpu.esp -= 4;
    // 004b4279  e802ffffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b427e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4280  740c                   -je 0x4b428e
    if (cpu.flags.zf)
    {
        goto L_0x004b428e;
    }
    // 004b4282  c70534e14c00ffffffff   -mov dword ptr [0x4ce134], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038388) /* 0x4ce134 */) = 4294967295 /*0xffffffff*/;
    // 004b428c  eb18                   -jmp 0x4b42a6
    goto L_0x004b42a6;
L_0x004b428e:
    // 004b428e  833d34e14c00ff         +cmp dword ptr [0x4ce134], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038388) /* 0x4ce134 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4295  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b429a  740a                   -je 0x4b42a6
    if (cpu.flags.zf)
    {
        goto L_0x004b42a6;
    }
    // 004b429c  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b42a0  ff1534e14c00           -call dword ptr [0x4ce134]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038388) /* 0x4ce134 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b42a6:
    // 004b42a6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b42a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b42a9  833d4ce14c0000         +cmp dword ptr [0x4ce14c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038412) /* 0x4ce14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b42b0  751f                   -jne 0x4b42d1
    if (!cpu.flags.zf)
    {
        goto L_0x004b42d1;
    }
    // 004b42b2  684ce14c00             -push 0x4ce14c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038412 /*0x4ce14c*/;
    cpu.esp -= 4;
    // 004b42b7  6878e64c00             -push 0x4ce678
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5039736 /*0x4ce678*/;
    cpu.esp -= 4;
    // 004b42bc  e8bffeffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b42c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b42c3  740c                   -je 0x4b42d1
    if (cpu.flags.zf)
    {
        goto L_0x004b42d1;
    }
    // 004b42c5  c7054ce14c00ffffffff   -mov dword ptr [0x4ce14c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038412) /* 0x4ce14c */) = 4294967295 /*0xffffffff*/;
    // 004b42cf  eb20                   -jmp 0x4b42f1
    goto L_0x004b42f1;
L_0x004b42d1:
    // 004b42d1  833d4ce14c00ff         +cmp dword ptr [0x4ce14c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038412) /* 0x4ce14c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b42d8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b42dd  7412                   -je 0x4b42f1
    if (cpu.flags.zf)
    {
        goto L_0x004b42f1;
    }
    // 004b42df  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b42e3  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b42e7  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b42eb  ff154ce14c00           -call dword ptr [0x4ce14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038412) /* 0x4ce14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b42f1:
    // 004b42f1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b42f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b42f4  833de8e14c0000         +cmp dword ptr [0x4ce1e8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038568) /* 0x4ce1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b42fb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b42fc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b42fe  751f                   -jne 0x4b431f
    if (!cpu.flags.zf)
    {
        goto L_0x004b431f;
    }
    // 004b4300  68e8e14c00             -push 0x4ce1e8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038568 /*0x4ce1e8*/;
    cpu.esp -= 4;
    // 004b4305  6884e94c00             -push 0x4ce984
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5040516 /*0x4ce984*/;
    cpu.esp -= 4;
    // 004b430a  e871feffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b430f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4311  740c                   -je 0x4b431f
    if (cpu.flags.zf)
    {
        goto L_0x004b431f;
    }
    // 004b4313  c705e8e14c00ffffffff   -mov dword ptr [0x4ce1e8], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038568) /* 0x4ce1e8 */) = 4294967295 /*0xffffffff*/;
    // 004b431d  eb23                   -jmp 0x4b4342
    goto L_0x004b4342;
L_0x004b431f:
    // 004b431f  833de8e14c00ff         +cmp dword ptr [0x4ce1e8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038568) /* 0x4ce1e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4326  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b432b  7415                   -je 0x4b4342
    if (cpu.flags.zf)
    {
        goto L_0x004b4342;
    }
    // 004b432d  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b4330  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b4333  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b4336  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4339  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b433c  ff15e8e14c00           -call dword ptr [0x4ce1e8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038568) /* 0x4ce1e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b4342:
    // 004b4342  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4343  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b4346(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4346  833df4e14c0000         +cmp dword ptr [0x4ce1f4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038580) /* 0x4ce1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b434d  751f                   -jne 0x4b436e
    if (!cpu.flags.zf)
    {
        goto L_0x004b436e;
    }
    // 004b434f  68f4e14c00             -push 0x4ce1f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038580 /*0x4ce1f4*/;
    cpu.esp -= 4;
    // 004b4354  68b4e94c00             -push 0x4ce9b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5040564 /*0x4ce9b4*/;
    cpu.esp -= 4;
    // 004b4359  e822feffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b435e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4360  740c                   -je 0x4b436e
    if (cpu.flags.zf)
    {
        goto L_0x004b436e;
    }
    // 004b4362  c705f4e14c00ffffffff   -mov dword ptr [0x4ce1f4], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038580) /* 0x4ce1f4 */) = 4294967295 /*0xffffffff*/;
    // 004b436c  eb20                   -jmp 0x4b438e
    goto L_0x004b438e;
L_0x004b436e:
    // 004b436e  833df4e14c00ff         +cmp dword ptr [0x4ce1f4], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038580) /* 0x4ce1f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4375  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b437a  7412                   -je 0x4b438e
    if (cpu.flags.zf)
    {
        goto L_0x004b438e;
    }
    // 004b437c  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4380  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4384  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4388  ff15f4e14c00           -call dword ptr [0x4ce1f4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038580) /* 0x4ce1f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b438e:
    // 004b438e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b4391(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4391  833d10e24c0000         +cmp dword ptr [0x4ce210], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038608) /* 0x4ce210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4398  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4399  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b439b  751f                   -jne 0x4b43bc
    if (!cpu.flags.zf)
    {
        goto L_0x004b43bc;
    }
    // 004b439d  6810e24c00             -push 0x4ce210
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038608 /*0x4ce210*/;
    cpu.esp -= 4;
    // 004b43a2  682cea4c00             -push 0x4cea2c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5040684 /*0x4cea2c*/;
    cpu.esp -= 4;
    // 004b43a7  e8d4fdffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b43ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b43ae  740c                   -je 0x4b43bc
    if (cpu.flags.zf)
    {
        goto L_0x004b43bc;
    }
    // 004b43b0  c70510e24c00ffffffff   -mov dword ptr [0x4ce210], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038608) /* 0x4ce210 */) = 4294967295 /*0xffffffff*/;
    // 004b43ba  eb26                   -jmp 0x4b43e2
    goto L_0x004b43e2;
L_0x004b43bc:
    // 004b43bc  833d10e24c00ff         +cmp dword ptr [0x4ce210], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038608) /* 0x4ce210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b43c3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b43c8  7418                   -je 0x4b43e2
    if (cpu.flags.zf)
    {
        goto L_0x004b43e2;
    }
    // 004b43ca  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b43cd  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b43d0  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b43d3  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b43d6  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b43d9  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b43dc  ff1510e24c00           -call dword ptr [0x4ce210]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038608) /* 0x4ce210 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b43e2:
    // 004b43e2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43e3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4b43e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b43e6  833d1ce24c0000         +cmp dword ptr [0x4ce21c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038620) /* 0x4ce21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b43ed  751f                   -jne 0x4b440e
    if (!cpu.flags.zf)
    {
        goto L_0x004b440e;
    }
    // 004b43ef  681ce24c00             -push 0x4ce21c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038620 /*0x4ce21c*/;
    cpu.esp -= 4;
    // 004b43f4  6850ea4c00             -push 0x4cea50
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5040720 /*0x4cea50*/;
    cpu.esp -= 4;
    // 004b43f9  e882fdffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b43fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4400  740c                   -je 0x4b440e
    if (cpu.flags.zf)
    {
        goto L_0x004b440e;
    }
    // 004b4402  c7051ce24c00ffffffff   -mov dword ptr [0x4ce21c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038620) /* 0x4ce21c */) = 4294967295 /*0xffffffff*/;
    // 004b440c  eb1c                   -jmp 0x4b442a
    goto L_0x004b442a;
L_0x004b440e:
    // 004b440e  833d1ce24c00ff         +cmp dword ptr [0x4ce21c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038620) /* 0x4ce21c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4415  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b441a  740e                   -je 0x4b442a
    if (cpu.flags.zf)
    {
        goto L_0x004b442a;
    }
    // 004b441c  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b4420  ff742408               -push dword ptr [esp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b4424  ff151ce24c00           -call dword ptr [0x4ce21c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038620) /* 0x4ce21c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b442a:
    // 004b442a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4b442d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b442d  833d68e24c0000         +cmp dword ptr [0x4ce268], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038696) /* 0x4ce268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4434  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4435  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4437  751f                   -jne 0x4b4458
    if (!cpu.flags.zf)
    {
        goto L_0x004b4458;
    }
    // 004b4439  6868e24c00             -push 0x4ce268
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038696 /*0x4ce268*/;
    cpu.esp -= 4;
    // 004b443e  68c4eb4c00             -push 0x4cebc4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5041092 /*0x4cebc4*/;
    cpu.esp -= 4;
    // 004b4443  e838fdffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b4448  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b444a  740c                   -je 0x4b4458
    if (cpu.flags.zf)
    {
        goto L_0x004b4458;
    }
    // 004b444c  c70568e24c00ffffffff   -mov dword ptr [0x4ce268], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038696) /* 0x4ce268 */) = 4294967295 /*0xffffffff*/;
    // 004b4456  eb23                   -jmp 0x4b447b
    goto L_0x004b447b;
L_0x004b4458:
    // 004b4458  833d68e24c00ff         +cmp dword ptr [0x4ce268], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038696) /* 0x4ce268 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b445f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b4464  7415                   -je 0x4b447b
    if (cpu.flags.zf)
    {
        goto L_0x004b447b;
    }
    // 004b4466  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b4469  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b446c  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b446f  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4472  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b4475  ff1568e24c00           -call dword ptr [0x4ce268]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038696) /* 0x4ce268 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b447b:
    // 004b447b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b447c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b447f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b447f  833d74e24c0000         +cmp dword ptr [0x4ce274], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038708) /* 0x4ce274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4486  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4487  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4489  751f                   -jne 0x4b44aa
    if (!cpu.flags.zf)
    {
        goto L_0x004b44aa;
    }
    // 004b448b  6874e24c00             -push 0x4ce274
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038708 /*0x4ce274*/;
    cpu.esp -= 4;
    // 004b4490  68fceb4c00             -push 0x4cebfc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5041148 /*0x4cebfc*/;
    cpu.esp -= 4;
    // 004b4495  e8e6fcffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b449a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b449c  740c                   -je 0x4b44aa
    if (cpu.flags.zf)
    {
        goto L_0x004b44aa;
    }
    // 004b449e  c70574e24c00ffffffff   -mov dword ptr [0x4ce274], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038708) /* 0x4ce274 */) = 4294967295 /*0xffffffff*/;
    // 004b44a8  eb23                   -jmp 0x4b44cd
    goto L_0x004b44cd;
L_0x004b44aa:
    // 004b44aa  833d74e24c00ff         +cmp dword ptr [0x4ce274], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038708) /* 0x4ce274 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b44b1  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b44b6  7415                   -je 0x4b44cd
    if (cpu.flags.zf)
    {
        goto L_0x004b44cd;
    }
    // 004b44b8  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b44bb  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b44be  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b44c1  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b44c4  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b44c7  ff1574e24c00           -call dword ptr [0x4ce274]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038708) /* 0x4ce274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b44cd:
    // 004b44cd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44ce  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b44d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b44d1  833d8ce24c0000         +cmp dword ptr [0x4ce28c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038732) /* 0x4ce28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b44d8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b44d9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b44db  751f                   -jne 0x4b44fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b44fc;
    }
    // 004b44dd  688ce24c00             -push 0x4ce28c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038732 /*0x4ce28c*/;
    cpu.esp -= 4;
    // 004b44e2  6868ec4c00             -push 0x4cec68
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5041256 /*0x4cec68*/;
    cpu.esp -= 4;
    // 004b44e7  e894fcffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b44ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b44ee  740c                   -je 0x4b44fc
    if (cpu.flags.zf)
    {
        goto L_0x004b44fc;
    }
    // 004b44f0  c7058ce24c00ffffffff   -mov dword ptr [0x4ce28c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038732) /* 0x4ce28c */) = 4294967295 /*0xffffffff*/;
    // 004b44fa  eb26                   -jmp 0x4b4522
    goto L_0x004b4522;
L_0x004b44fc:
    // 004b44fc  833d8ce24c00ff         +cmp dword ptr [0x4ce28c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038732) /* 0x4ce28c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4503  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b4508  7418                   -je 0x4b4522
    if (cpu.flags.zf)
    {
        goto L_0x004b4522;
    }
    // 004b450a  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b450d  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b4510  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b4513  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b4516  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4519  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b451c  ff158ce24c00           -call dword ptr [0x4ce28c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038732) /* 0x4ce28c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b4522:
    // 004b4522  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4523  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4b4526(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4526  833d94e24c0000         +cmp dword ptr [0x4ce294], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038740) /* 0x4ce294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b452d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b452e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4530  751f                   -jne 0x4b4551
    if (!cpu.flags.zf)
    {
        goto L_0x004b4551;
    }
    // 004b4532  6894e24c00             -push 0x4ce294
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038740 /*0x4ce294*/;
    cpu.esp -= 4;
    // 004b4537  6898ec4c00             -push 0x4cec98
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5041304 /*0x4cec98*/;
    cpu.esp -= 4;
    // 004b453c  e83ffcffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b4541  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4543  740c                   -je 0x4b4551
    if (cpu.flags.zf)
    {
        goto L_0x004b4551;
    }
    // 004b4545  c70594e24c00ffffffff   -mov dword ptr [0x4ce294], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038740) /* 0x4ce294 */) = 4294967295 /*0xffffffff*/;
    // 004b454f  eb2f                   -jmp 0x4b4580
    goto L_0x004b4580;
L_0x004b4551:
    // 004b4551  833d94e24c00ff         +cmp dword ptr [0x4ce294], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038740) /* 0x4ce294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4558  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b455d  7421                   -je 0x4b4580
    if (cpu.flags.zf)
    {
        goto L_0x004b4580;
    }
    // 004b455f  ff7528                 -push dword ptr [ebp + 0x28]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 004b4562  ff7524                 -push dword ptr [ebp + 0x24]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 004b4565  ff7520                 -push dword ptr [ebp + 0x20]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004b4568  ff751c                 -push dword ptr [ebp + 0x1c]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b456b  ff7518                 -push dword ptr [ebp + 0x18]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b456e  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b4571  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b4574  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4577  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b457a  ff1594e24c00           -call dword ptr [0x4ce294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038740) /* 0x4ce294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b4580:
    // 004b4580  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4581  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_4b4584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4584  833d24e34c0000         +cmp dword ptr [0x4ce324], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038884) /* 0x4ce324 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b458b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b458c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b458e  751f                   -jne 0x4b45af
    if (!cpu.flags.zf)
    {
        goto L_0x004b45af;
    }
    // 004b4590  6824e34c00             -push 0x4ce324
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038884 /*0x4ce324*/;
    cpu.esp -= 4;
    // 004b4595  6858ef4c00             -push 0x4cef58
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5042008 /*0x4cef58*/;
    cpu.esp -= 4;
    // 004b459a  e8e1fbffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b459f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b45a1  740c                   -je 0x4b45af
    if (cpu.flags.zf)
    {
        goto L_0x004b45af;
    }
    // 004b45a3  c70524e34c00ffffffff   -mov dword ptr [0x4ce324], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038884) /* 0x4ce324 */) = 4294967295 /*0xffffffff*/;
    // 004b45ad  eb20                   -jmp 0x4b45cf
    goto L_0x004b45cf;
L_0x004b45af:
    // 004b45af  833d24e34c00ff         +cmp dword ptr [0x4ce324], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038884) /* 0x4ce324 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b45b6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b45bb  7412                   -je 0x4b45cf
    if (cpu.flags.zf)
    {
        goto L_0x004b45cf;
    }
    // 004b45bd  ff7514                 -push dword ptr [ebp + 0x14]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b45c0  ff7510                 -push dword ptr [ebp + 0x10]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b45c3  ff750c                 -push dword ptr [ebp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b45c6  ff7508                 -push dword ptr [ebp + 8]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b45c9  ff1524e34c00           -call dword ptr [0x4ce324]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038884) /* 0x4ce324 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b45cf:
    // 004b45cf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45d0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4b45d3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b45d3  833d40e34c0000         +cmp dword ptr [0x4ce340], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038912) /* 0x4ce340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b45da  751f                   -jne 0x4b45fb
    if (!cpu.flags.zf)
    {
        goto L_0x004b45fb;
    }
    // 004b45dc  6840e34c00             -push 0x4ce340
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038912 /*0x4ce340*/;
    cpu.esp -= 4;
    // 004b45e1  68e4ef4c00             -push 0x4cefe4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5042148 /*0x4cefe4*/;
    cpu.esp -= 4;
    // 004b45e6  e895fbffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b45eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b45ed  740c                   -je 0x4b45fb
    if (cpu.flags.zf)
    {
        goto L_0x004b45fb;
    }
    // 004b45ef  c70540e34c00ffffffff   -mov dword ptr [0x4ce340], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038912) /* 0x4ce340 */) = 4294967295 /*0xffffffff*/;
    // 004b45f9  eb20                   -jmp 0x4b461b
    goto L_0x004b461b;
L_0x004b45fb:
    // 004b45fb  833d40e34c00ff         +cmp dword ptr [0x4ce340], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038912) /* 0x4ce340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4602  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b4607  7412                   -je 0x4b461b
    if (cpu.flags.zf)
    {
        goto L_0x004b461b;
    }
    // 004b4609  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b460d  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4611  ff74240c               -push dword ptr [esp + 0xc]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b4615  ff1540e34c00           -call dword ptr [0x4ce340]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038912) /* 0x4ce340 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b461b:
    // 004b461b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b461e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b461e  833d6ce34c0000         +cmp dword ptr [0x4ce36c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038956) /* 0x4ce36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4625  751f                   -jne 0x4b4646
    if (!cpu.flags.zf)
    {
        goto L_0x004b4646;
    }
    // 004b4627  686ce34c00             -push 0x4ce36c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5038956 /*0x4ce36c*/;
    cpu.esp -= 4;
    // 004b462c  68c4f04c00             -push 0x4cf0c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5042372 /*0x4cf0c4*/;
    cpu.esp -= 4;
    // 004b4631  e84afbffff             -call 0x4b4180
    cpu.esp -= 4;
    sub_4b4180(app, cpu);
    if (cpu.terminate) return;
    // 004b4636  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4638  740c                   -je 0x4b4646
    if (cpu.flags.zf)
    {
        goto L_0x004b4646;
    }
    // 004b463a  c7056ce34c00ffffffff   -mov dword ptr [0x4ce36c], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(5038956) /* 0x4ce36c */) = 4294967295 /*0xffffffff*/;
    // 004b4644  eb18                   -jmp 0x4b465e
    goto L_0x004b465e;
L_0x004b4646:
    // 004b4646  833d6ce34c00ff         +cmp dword ptr [0x4ce36c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5038956) /* 0x4ce36c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b464d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b4652  740a                   -je 0x4b465e
    if (cpu.flags.zf)
    {
        goto L_0x004b465e;
    }
    // 004b4654  ff742404               -push dword ptr [esp + 4]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b4658  ff156ce34c00           -call dword ptr [0x4ce36c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5038956) /* 0x4ce36c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b465e:
    // 004b465e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: f8f64c000000000003ffff0000000000e8f64c000400000003ffff0000000000d8f64c000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff8000000000180000001000000002000000100000000700000070464b000000000000000000f8f64c000000000003ffff8000010000e8f64c000400000003ffff8000010000d8f64c000800000003ffff800001000048f74c000c00000003ffff800001000038f74c001000000003ffff800001000028f74c001400000003ffff800001000018f74c001800000003ffff800001000018f74c001c00000003ffff800001000008f74c002000000010ffff800000000008f74c002400000010ffff800000000008f74c002800000010ffff800000000008f74c002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c00000000474b00 */
void Application::sub_4b49d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49d8  ff2568544b00           -jmp dword ptr [0x4b5468]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936808), cpu);
}

/* align: skip  */
void Application::sub_4b49de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49de  ff251c554b00           -jmp dword ptr [0x4b551c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936988), cpu);
}

/* align: skip  */
void Application::sub_4b49e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49e4  ff2570554b00           -jmp dword ptr [0x4b5570]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937072), cpu);
}

/* align: skip  */
void Application::sub_4b49ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49ea  ff258c554b00           -jmp dword ptr [0x4b558c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937100), cpu);
}

/* align: skip  */
void Application::sub_4b49f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49f0  ff259c554b00           -jmp dword ptr [0x4b559c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937116), cpu);
}

/* align: skip  */
void Application::sub_4b49f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49f6  ff2520554b00           -jmp dword ptr [0x4b5520]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936992), cpu);
}

/* align: skip  */
void Application::sub_4b49fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b49fc  ff25d4544b00           -jmp dword ptr [0x4b54d4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936916), cpu);
}

/* align: skip  */
void Application::sub_4b4a02(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a02  ff2580554b00           -jmp dword ptr [0x4b5580]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937088), cpu);
}

/* align: skip  */
void Application::sub_4b4a08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a08  ff2588554b00           -jmp dword ptr [0x4b5588]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937096), cpu);
}

/* align: skip  */
void Application::sub_4b4a0e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a0e  ff257c554b00           -jmp dword ptr [0x4b557c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937084), cpu);
}

/* align: skip  */
void Application::sub_4b4a14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a14  ff2564554b00           -jmp dword ptr [0x4b5564]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937060), cpu);
}

/* align: skip  */
void Application::sub_4b4a1a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a1a  ff2584554b00           -jmp dword ptr [0x4b5584]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937092), cpu);
}

/* align: skip  */
void Application::sub_4b4a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a20  ff25b8544b00           -jmp dword ptr [0x4b54b8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936888), cpu);
}

/* align: skip  */
void Application::sub_4b4a26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a26  ff25e8544b00           -jmp dword ptr [0x4b54e8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936936), cpu);
}

/* align: skip  */
void Application::sub_4b4a2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a2c  ff2568554b00           -jmp dword ptr [0x4b5568]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937064), cpu);
}

/* align: skip  */
void Application::sub_4b4a32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a32  ff25f8544b00           -jmp dword ptr [0x4b54f8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936952), cpu);
}

/* align: skip  */
void Application::sub_4b4a38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a38  ff25c0534b00           -jmp dword ptr [0x4b53c0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936640), cpu);
}

/* align: skip  */
void Application::sub_4b4a3e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a3e  ff2598544b00           -jmp dword ptr [0x4b5498]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936856), cpu);
}

/* align: skip  */
void Application::sub_4b4a44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a44  ff2588544b00           -jmp dword ptr [0x4b5488]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936840), cpu);
}

/* align: skip  */
void Application::sub_4b4a4a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a4a  ff2584544b00           -jmp dword ptr [0x4b5484]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936836), cpu);
}

/* align: skip  */
void Application::sub_4b4a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a50  ff25d0544b00           -jmp dword ptr [0x4b54d0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936912), cpu);
}

/* align: skip  */
void Application::sub_4b4a56(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a56  ff25fc544b00           -jmp dword ptr [0x4b54fc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936956), cpu);
}

/* align: skip  */
void Application::sub_4b4a5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a5c  ff25ac544b00           -jmp dword ptr [0x4b54ac]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936876), cpu);
}

/* align: skip  */
void Application::sub_4b4a62(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a62  ff25c4544b00           -jmp dword ptr [0x4b54c4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936900), cpu);
}

/* align: skip  */
void Application::sub_4b4a68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a68  ff2568534b00           -jmp dword ptr [0x4b5368]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936552), cpu);
}

/* align: skip  */
void Application::sub_4b4a6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a6e  ff2574534b00           -jmp dword ptr [0x4b5374]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936564), cpu);
}

/* align: skip  */
void Application::sub_4b4a74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a74  ff2570534b00           -jmp dword ptr [0x4b5370]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936560), cpu);
}

/* align: skip  */
void Application::sub_4b4a7a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a7a  ff2518544b00           -jmp dword ptr [0x4b5418]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936728), cpu);
}

/* align: skip  */
void Application::sub_4b4a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a80  ff25bc534b00           -jmp dword ptr [0x4b53bc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936636), cpu);
}

/* align: skip  */
void Application::sub_4b4a86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a86  ff25a8544b00           -jmp dword ptr [0x4b54a8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936872), cpu);
}

/* align: skip  */
void Application::sub_4b4a8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a8c  ff2594554b00           -jmp dword ptr [0x4b5594]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937108), cpu);
}

/* align: skip  */
void Application::sub_4b4a92(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a92  ff25ec544b00           -jmp dword ptr [0x4b54ec]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936940), cpu);
}

/* align: skip  */
void Application::sub_4b4a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a98  ff2598554b00           -jmp dword ptr [0x4b5598]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937112), cpu);
}

/* align: skip  */
void Application::sub_4b4a9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4a9e  ff256c534b00           -jmp dword ptr [0x4b536c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936556), cpu);
}

/* align: skip  */
void Application::sub_4b4aa4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4aa4  ff2538554b00           -jmp dword ptr [0x4b5538]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937016), cpu);
}

/* align: skip  */
void Application::sub_4b4aaa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4aaa  ff2580544b00           -jmp dword ptr [0x4b5480]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936832), cpu);
}

/* align: skip  */
void Application::sub_4b4ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ab0  ff253c554b00           -jmp dword ptr [0x4b553c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937020), cpu);
}

/* align: skip  */
void Application::sub_4b4ab6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ab6  ff2578544b00           -jmp dword ptr [0x4b5478]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936824), cpu);
}

/* align: skip  */
void Application::sub_4b4abc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4abc  ff2550544b00           -jmp dword ptr [0x4b5450]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936784), cpu);
}

/* align: skip  */
void Application::sub_4b4ac2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ac2  ff2528554b00           -jmp dword ptr [0x4b5528]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937000), cpu);
}

/* align: skip  */
void Application::sub_4b4ac8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ac8  ff25e0544b00           -jmp dword ptr [0x4b54e0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936928), cpu);
}

/* align: skip  */
void Application::sub_4b4ace(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ace  ff2540544b00           -jmp dword ptr [0x4b5440]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936768), cpu);
}

/* align: skip  */
void Application::sub_4b4ad4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ad4  ff2510554b00           -jmp dword ptr [0x4b5510]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936976), cpu);
}

/* align: skip  */
void Application::sub_4b4ada(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ada  ff254c544b00           -jmp dword ptr [0x4b544c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936780), cpu);
}

/* align: skip  */
void Application::sub_4b4ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ae0  ff250c554b00           -jmp dword ptr [0x4b550c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936972), cpu);
}

/* align: skip  */
void Application::sub_4b4ae6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ae6  ff2558554b00           -jmp dword ptr [0x4b5558]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937048), cpu);
}

/* align: skip  */
void Application::sub_4b4aec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4aec  ff2558544b00           -jmp dword ptr [0x4b5458]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936792), cpu);
}

/* align: skip  */
void Application::sub_4b4af2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4af2  ff256c554b00           -jmp dword ptr [0x4b556c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937068), cpu);
}

/* align: skip  */
void Application::sub_4b4af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4af8  ff25f0544b00           -jmp dword ptr [0x4b54f0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936944), cpu);
}

/* align: skip  */
void Application::sub_4b4afe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4afe  ff2578554b00           -jmp dword ptr [0x4b5578]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937080), cpu);
}

/* align: skip  */
void Application::sub_4b4b04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b04  ff2574554b00           -jmp dword ptr [0x4b5574]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937076), cpu);
}

/* align: skip  */
void Application::sub_4b4b0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b0a  ff2534554b00           -jmp dword ptr [0x4b5534]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937012), cpu);
}

/* align: skip  */
void Application::sub_4b4b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b10  ff2538544b00           -jmp dword ptr [0x4b5438]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936760), cpu);
}

/* align: skip  */
void Application::sub_4b4b16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b16  ff2548544b00           -jmp dword ptr [0x4b5448]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936776), cpu);
}

/* align: skip  */
void Application::sub_4b4b1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b1c  ff25a0544b00           -jmp dword ptr [0x4b54a0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936864), cpu);
}

/* align: skip  */
void Application::sub_4b4b22(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b22  ff2594544b00           -jmp dword ptr [0x4b5494]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936852), cpu);
}

/* align: skip  */
void Application::sub_4b4b28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b28  ff259c544b00           -jmp dword ptr [0x4b549c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936860), cpu);
}

/* align: skip  */
void Application::sub_4b4b2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b2e  ff25a0554b00           -jmp dword ptr [0x4b55a0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4937120), cpu);
}

/* align: skip  */
void Application::sub_4b4b34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b34  ff25b0544b00           -jmp dword ptr [0x4b54b0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936880), cpu);
}

/* align: skip  */
void Application::sub_4b4b3a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b3a  ff2564544b00           -jmp dword ptr [0x4b5464]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936804), cpu);
}

/* align: skip  */
void Application::sub_4b4b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b40  ff2544544b00           -jmp dword ptr [0x4b5444]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936772), cpu);
}

/* align: skip  */
void Application::sub_4b4b46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b46  ff2554544b00           -jmp dword ptr [0x4b5454]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936788), cpu);
}

/* align: skip  */
void Application::sub_4b4b4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b4c  ff2508544b00           -jmp dword ptr [0x4b5408]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936712), cpu);
}

/* align: skip  */
void Application::sub_4b4b52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b52  ff25b0534b00           -jmp dword ptr [0x4b53b0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936624), cpu);
}

/* align: skip  */
void Application::sub_4b4b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b58  ff2534544b00           -jmp dword ptr [0x4b5434]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936756), cpu);
}

/* align: skip  */
void Application::sub_4b4b5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b5e  ff25f4544b00           -jmp dword ptr [0x4b54f4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936948), cpu);
}

/* align: skip  */
void Application::sub_4b4b64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b64  ff2500544b00           -jmp dword ptr [0x4b5400]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936704), cpu);
}

/* align: skip  */
void Application::sub_4b4b6a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b6a  ff2514544b00           -jmp dword ptr [0x4b5414]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936724), cpu);
}

/* align: skip  */
void Application::sub_4b4b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b70  ff25fc534b00           -jmp dword ptr [0x4b53fc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936700), cpu);
}

/* align: skip  */
void Application::sub_4b4b76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b76  ff25e4534b00           -jmp dword ptr [0x4b53e4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936676), cpu);
}

/* align: skip  */
void Application::sub_4b4b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b7c  ff257c534b00           -jmp dword ptr [0x4b537c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936572), cpu);
}

/* align: skip  */
void Application::sub_4b4b82(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b82  ff25d0534b00           -jmp dword ptr [0x4b53d0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936656), cpu);
}

/* align: skip  */
void Application::sub_4b4b88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b88  ff25a4534b00           -jmp dword ptr [0x4b53a4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936612), cpu);
}

/* align: skip  */
void Application::sub_4b4b8e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b8e  ff25ec534b00           -jmp dword ptr [0x4b53ec]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936684), cpu);
}

/* align: skip  */
void Application::sub_4b4b94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b94  ff25f8534b00           -jmp dword ptr [0x4b53f8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936696), cpu);
}

/* align: skip  */
void Application::sub_4b4b9a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4b9a  ff25c8534b00           -jmp dword ptr [0x4b53c8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936648), cpu);
}

/* align: skip  */
void Application::sub_4b4ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ba0  ff259c534b00           -jmp dword ptr [0x4b539c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936604), cpu);
}

/* align: skip  */
void Application::sub_4b4ba6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4ba6  ff2584534b00           -jmp dword ptr [0x4b5384]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936580), cpu);
}

/* align: skip  */
void Application::sub_4b4bac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bac  ff258c534b00           -jmp dword ptr [0x4b538c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936588), cpu);
}

/* align: skip  */
void Application::sub_4b4bb2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bb2  ff25b4534b00           -jmp dword ptr [0x4b53b4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936628), cpu);
}

/* align: skip  */
void Application::sub_4b4bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bb8  ff25a0534b00           -jmp dword ptr [0x4b53a0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936608), cpu);
}

/* align: skip  */
void Application::sub_4b4bbe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bbe  ff25ac534b00           -jmp dword ptr [0x4b53ac]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936620), cpu);
}

/* align: skip  */
void Application::sub_4b4bc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bc4  ff2588534b00           -jmp dword ptr [0x4b5388]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936584), cpu);
}

/* align: skip  */
void Application::sub_4b4bca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bca  ff253c544b00           -jmp dword ptr [0x4b543c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936764), cpu);
}

/* align: skip  */
void Application::sub_4b4bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4bd0  ff2524554b00           -jmp dword ptr [0x4b5524]
    return app->dynamic_call(*app->getMemory<x86::reg32>(4936996), cpu);
}

}
