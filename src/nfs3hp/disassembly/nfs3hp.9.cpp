#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x90 */
void Application::sub_4379b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004379b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004379b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004379b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004379b6  e8f54f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 004379bb  dc0d80755300           -fmul qword ptr [0x537580]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469568) /* 0x537580 */));
    // 004379c1  e890830a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004379c6  db1df0bb6f00           -fistp dword ptr [0x6fbbf0]
    app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004379ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4379d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004379d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004379d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004379d2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004379d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004379d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004379d9  e8d24f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 004379de  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 004379e4  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004379e7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004379e9  7519                   -jne 0x437a04
    if (!cpu.flags.zf)
    {
        goto L_0x00437a04;
    }
    // 004379eb  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004379ee  dc0d88755300           -fmul qword ptr [0x537588]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469576) /* 0x537588 */));
    // 004379f4  e85d830a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004379f9  db1df4bb6f00           -fistp dword ptr [0x6fbbf4]
    app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004379ff  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a01  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437a04:
    // 00437a04  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a07  dc0d88755300           -fmul qword ptr [0x537588]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469576) /* 0x537588 */));
    // 00437a0d  e844830a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00437a12  db1d20295500           -fistp dword ptr [0x552920]
    app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a18  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a1a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_437a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437a21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a22  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a24  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00437a27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437a29  e8824f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00437a2e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437a34  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437a37  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437a39  7519                   -jne 0x437a54
    if (!cpu.flags.zf)
    {
        goto L_0x00437a54;
    }
    // 00437a3b  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a3e  dc0d90755300           -fmul qword ptr [0x537590]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469584) /* 0x537590 */));
    // 00437a44  e80d830a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00437a49  db1df8bb6f00           -fistp dword ptr [0x6fbbf8]
    app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a4f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a51  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00437a54:
    // 00437a54  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 00437a57  dc0d90755300           -fmul qword ptr [0x537590]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469584) /* 0x537590 */));
    // 00437a5d  e8f4820a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00437a62  db1d24295500           -fistp dword ptr [0x552924]
    app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a68  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00437a6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_437a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437a71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a74  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437a76  e8354f0300             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00437a7b  dc0d98755300           -fmul qword ptr [0x537598]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469592) /* 0x537598 */));
    // 00437a81  e8d0820a00             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00437a86  db1dfcbb6f00           -fistp dword ptr [0x6fbbfc]
    app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00437a8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437a8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_437a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437a90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00437a91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437a92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437a93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437a94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437a95  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437a97  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00437a99  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00437a9b  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00437aa0  e8bb2b0100             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00437aa5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437aa7  0f8446030000           -je 0x437df3
    if (cpu.flags.zf)
    {
        goto L_0x00437df3;
    }
    // 00437aad  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00437aaf  0f8479020000           -je 0x437d2e
    if (cpu.flags.zf)
    {
        goto L_0x00437d2e;
    }
    // 00437ab5  3b353c4f5500           +cmp esi, dword ptr [0x554f3c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437abb  7559                   -jne 0x437b16
    if (!cpu.flags.zf)
    {
        goto L_0x00437b16;
    }
    // 00437abd  8b0d244f5500           -mov ecx, dword ptr [0x554f24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */);
    // 00437ac3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00437ac5  752d                   -jne 0x437af4
    if (!cpu.flags.zf)
    {
        goto L_0x00437af4;
    }
    // 00437ac7  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ace  751a                   -jne 0x437aea
    if (!cpu.flags.zf)
    {
        goto L_0x00437aea;
    }
    // 00437ad0  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437ad5  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437ada  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437adf  e83c190b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437ae4  890d384f5500           -mov dword ptr [0x554f38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.ecx;
L_0x00437aea:
    // 00437aea  c705244f550001000000   -mov dword ptr [0x554f24], 1
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = 1 /*0x1*/;
L_0x00437af4:
    // 00437af4  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437afb  0f8583020000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437b01  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b06  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00437b0c  e85ff90a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437b11  e96e020000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437b16:
    // 00437b16  3b35404f5500           +cmp esi, dword ptr [0x554f40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b1c  755a                   -jne 0x437b78
    if (!cpu.flags.zf)
    {
        goto L_0x00437b78;
    }
    // 00437b1e  833d204f550000         +cmp dword ptr [0x554f20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b25  752f                   -jne 0x437b56
    if (!cpu.flags.zf)
    {
        goto L_0x00437b56;
    }
    // 00437b27  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b2e  751c                   -jne 0x437b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00437b4c;
    }
    // 00437b30  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437b35  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437b3a  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437b3f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437b41  e8da180b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437b46  890d384f5500           -mov dword ptr [0x554f38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.ecx;
L_0x00437b4c:
    // 00437b4c  c705204f550001000000   -mov dword ptr [0x554f20], 1
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = 1 /*0x1*/;
L_0x00437b56:
    // 00437b56  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b5d  0f8521020000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437b63  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b68  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437b6e  e8fdf80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437b73  e90c020000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437b78:
    // 00437b78  3b35444f5500           +cmp esi, dword ptr [0x554f44]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b7e  0f8587000000           -jne 0x437c0b
    if (!cpu.flags.zf)
    {
        goto L_0x00437c0b;
    }
    // 00437b84  833d284f550000         +cmp dword ptr [0x554f28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b8b  7554                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437b8d  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437b94  7510                   -jne 0x437ba6
    if (!cpu.flags.zf)
    {
        goto L_0x00437ba6;
    }
    // 00437b96  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437b9b  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437ba1  e8caf80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437ba6:
    // 00437ba6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437bab  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437bb1  a3284f5500             -mov dword ptr [0x554f28], eax
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.eax;
    // 00437bb6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437bb8  7527                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437bba  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437bc1  751e                   -jne 0x437be1
    if (!cpu.flags.zf)
    {
        goto L_0x00437be1;
    }
    // 00437bc3  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437bc5  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437bca  8b0df4bb6f00           -mov ecx, dword ptr [0x6fbbf4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */);
    // 00437bd0  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437bd5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437bd7  e8d406feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437bdc  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437be1:
    // 00437be1  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437be8  0f8596010000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437bee  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437bf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437bf5  0f8489010000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437bfb  8b15f4bb6f00           -mov edx, dword ptr [0x6fbbf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */);
    // 00437c01  e8f6190b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437c06  e979010000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437c0b:
    // 00437c0b  3b35484f5500           +cmp esi, dword ptr [0x554f48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c11  0f8587000000           -jne 0x437c9e
    if (!cpu.flags.zf)
    {
        goto L_0x00437c9e;
    }
    // 00437c17  833d2c4f550000         +cmp dword ptr [0x554f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c1e  7554                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c20  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c27  7510                   -jne 0x437c39
    if (!cpu.flags.zf)
    {
        goto L_0x00437c39;
    }
    // 00437c29  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437c2e  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437c34  e837f80a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437c39:
    // 00437c39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437c3e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437c44  a32c4f5500             -mov dword ptr [0x554f2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.eax;
    // 00437c49  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437c4b  7527                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c4d  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c54  751e                   -jne 0x437c74
    if (!cpu.flags.zf)
    {
        goto L_0x00437c74;
    }
    // 00437c56  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437c58  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437c5d  8b0df8bb6f00           -mov ecx, dword ptr [0x6fbbf8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */);
    // 00437c63  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437c68  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437c6a  e84106feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437c6f  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437c74:
    // 00437c74  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437c7b  0f8503010000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437c81  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437c86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437c88  0f84f6000000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437c8e  8b15f8bb6f00           -mov edx, dword ptr [0x6fbbf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */);
    // 00437c94  e863190b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437c99  e9e6000000             -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437c9e:
    // 00437c9e  3b354c4f5500           +cmp esi, dword ptr [0x554f4c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ca4  0f85da000000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437caa  833d304f550000         +cmp dword ptr [0x554f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437cb1  7554                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437cb3  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437cba  7510                   -jne 0x437ccc
    if (!cpu.flags.zf)
    {
        goto L_0x00437ccc;
    }
    // 00437cbc  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437cc1  8b15f0bb6f00           -mov edx, dword ptr [0x6fbbf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00437cc7  e8a4f70a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00437ccc:
    // 00437ccc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00437cd1  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437cd7  a3304f5500             -mov dword ptr [0x554f30], eax
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.eax;
    // 00437cdc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437cde  7527                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437ce0  833d384f550000         +cmp dword ptr [0x554f38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437ce7  751e                   -jne 0x437d07
    if (!cpu.flags.zf)
    {
        goto L_0x00437d07;
    }
    // 00437ce9  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00437ceb  ba07000000             -mov edx, 7
    cpu.edx = 7 /*0x7*/;
    // 00437cf0  8b0dfcbb6f00           -mov ecx, dword ptr [0x6fbbfc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */);
    // 00437cf6  a124115700             -mov eax, dword ptr [0x571124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706020) /* 0x571124 */);
    // 00437cfb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00437cfd  e8ae05feff             -call 0x4182b0
    cpu.esp -= 4;
    sub_4182b0(app, cpu);
    if (cpu.terminate) return;
    // 00437d02  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
L_0x00437d07:
    // 00437d07  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d0e  0f8570000000           -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d14  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437d19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437d1b  0f8463000000           -je 0x437d84
    if (cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d21  8b15fcbb6f00           -mov edx, dword ptr [0x6fbbfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */);
    // 00437d27  e8d0180b00             -call 0x4e95fc
    cpu.esp -= 4;
    sub_4e95fc(app, cpu);
    if (cpu.terminate) return;
    // 00437d2c  eb56                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d2e:
    // 00437d2e  3b353c4f5500           +cmp esi, dword ptr [0x554f3c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d34  750a                   -jne 0x437d40
    if (!cpu.flags.zf)
    {
        goto L_0x00437d40;
    }
    // 00437d36  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00437d38  890d244f5500           -mov dword ptr [0x554f24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.ecx;
    // 00437d3e  eb44                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d40:
    // 00437d40  3b35404f5500           +cmp esi, dword ptr [0x554f40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d46  7509                   -jne 0x437d51
    if (!cpu.flags.zf)
    {
        goto L_0x00437d51;
    }
    // 00437d48  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00437d4a  a3204f5500             -mov dword ptr [0x554f20], eax
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.eax;
    // 00437d4f  eb33                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d51:
    // 00437d51  3b35444f5500           +cmp esi, dword ptr [0x554f44]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d57  750a                   -jne 0x437d63
    if (!cpu.flags.zf)
    {
        goto L_0x00437d63;
    }
    // 00437d59  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00437d5b  890d284f5500           -mov dword ptr [0x554f28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.ecx;
    // 00437d61  eb21                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d63:
    // 00437d63  3b35484f5500           +cmp esi, dword ptr [0x554f48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d69  7509                   -jne 0x437d74
    if (!cpu.flags.zf)
    {
        goto L_0x00437d74;
    }
    // 00437d6b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00437d6d  a32c4f5500             -mov dword ptr [0x554f2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.eax;
    // 00437d72  eb10                   -jmp 0x437d84
    goto L_0x00437d84;
L_0x00437d74:
    // 00437d74  3b354c4f5500           +cmp esi, dword ptr [0x554f4c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d7a  7508                   -jne 0x437d84
    if (!cpu.flags.zf)
    {
        goto L_0x00437d84;
    }
    // 00437d7c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00437d7e  890d304f5500           -mov dword ptr [0x554f30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.ecx;
L_0x00437d84:
    // 00437d84  833d244f550000         +cmp dword ptr [0x554f24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d8b  0f8559000000           -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437d91  833d204f550000         +cmp dword ptr [0x554f20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437d98  7550                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437d9a  833d284f550000         +cmp dword ptr [0x554f28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437da1  7547                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437da3  833d2c4f550000         +cmp dword ptr [0x554f2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437daa  753e                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437dac  833d304f550000         +cmp dword ptr [0x554f30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437db3  7535                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437db5  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437dbc  752c                   -jne 0x437dea
    if (!cpu.flags.zf)
    {
        goto L_0x00437dea;
    }
    // 00437dbe  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00437dc3  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00437dc9  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00437dce  e89df60a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
    // 00437dd3  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00437dd8  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00437ddd  e83e160b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 00437de2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437de4  8915384f5500           -mov dword ptr [0x554f38], edx
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edx;
L_0x00437dea:
    // 00437dea  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00437dec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00437dee  e8ed4c0300             -call 0x46cae0
    cpu.esp -= 4;
    sub_46cae0(app, cpu);
    if (cpu.terminate) return;
L_0x00437df3:
    // 00437df3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00437df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_437e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00437e00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00437e01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00437e02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00437e03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437e04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00437e05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00437e07  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00437e0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00437e0c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437e0e  0f844f020000           -je 0x438063
    if (cpu.flags.zf)
    {
        goto L_0x00438063;
    }
    // 00437e14  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437e1b  740a                   -je 0x437e27
    if (cpu.flags.zf)
    {
        goto L_0x00437e27;
    }
    // 00437e1d  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 00437e22  e809970100             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
L_0x00437e27:
    // 00437e27  e8c47cfdff             -call 0x40faf0
    cpu.esp -= 4;
    sub_40faf0(app, cpu);
    if (cpu.terminate) return;
    // 00437e2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437e2e  7509                   -jne 0x437e39
    if (!cpu.flags.zf)
    {
        goto L_0x00437e39;
    }
    // 00437e30  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00437e32  6689156a635500         -mov word ptr [0x55636a], dx
    app->getMemory<x86::reg16>(x86::reg32(5596010) /* 0x55636a */) = cpu.dx;
L_0x00437e39:
    // 00437e39  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437e40  751d                   -jne 0x437e5f
    if (!cpu.flags.zf)
    {
        goto L_0x00437e5f;
    }
    // 00437e42  baa0755300             -mov edx, 0x5375a0
    cpu.edx = 5469600 /*0x5375a0*/;
    // 00437e47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437e49  e8f2ab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437e4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437e50  740d                   -je 0x437e5f
    if (cpu.flags.zf)
    {
        goto L_0x00437e5f;
    }
    // 00437e52  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
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
    // 00437e59  7e04                   -jle 0x437e5f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00437e5f;
    }
    // 00437e5b  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00437e5f:
    // 00437e5f  baa8755300             -mov edx, 0x5375a8
    cpu.edx = 5469608 /*0x5375a8*/;
    // 00437e64  a100bc6f00             -mov eax, dword ptr [0x6fbc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 00437e69  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00437e6b  a370395f00             -mov dword ptr [0x5f3970], eax
    app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */) = cpu.eax;
    // 00437e70  893d204f5500           -mov dword ptr [0x554f20], edi
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.edi;
    // 00437e76  893d244f5500           -mov dword ptr [0x554f24], edi
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.edi;
    // 00437e7c  893d284f5500           -mov dword ptr [0x554f28], edi
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.edi;
    // 00437e82  a1e4bb6f00             -mov eax, dword ptr [0x6fbbe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 00437e87  893d2c4f5500           -mov dword ptr [0x554f2c], edi
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.edi;
    // 00437e8d  a368395f00             -mov dword ptr [0x5f3968], eax
    app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */) = cpu.eax;
    // 00437e92  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 00437e97  893d304f5500           -mov dword ptr [0x554f30], edi
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.edi;
    // 00437e9d  a364395f00             -mov dword ptr [0x5f3964], eax
    app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */) = cpu.eax;
    // 00437ea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437ea4  893d384f5500           -mov dword ptr [0x554f38], edi
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edi;
    // 00437eaa  e891ab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437eaf  a33c4f5500             -mov dword ptr [0x554f3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */) = cpu.eax;
    // 00437eb4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437eb6  742e                   -je 0x437ee6
    if (cpu.flags.zf)
    {
        goto L_0x00437ee6;
    }
    // 00437eb8  db05e8bb6f00           -fild dword ptr [0x6fbbe8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */))));
    // 00437ebe  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437ec4  ba90794300             -mov edx, 0x437990
    cpu.edx = 4422032 /*0x437990*/;
    // 00437ec9  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437ed0  d95df4                 -fstp dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437ed3  e8e84b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437ed8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00437ed9  a13c4f5500             -mov eax, dword ptr [0x554f3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */);
    // 00437ede  ff75f4                 -push dword ptr [ebp - 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    cpu.esp -= 4;
    // 00437ee1  e86a4a0300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437ee6:
    // 00437ee6  bab8755300             -mov edx, 0x5375b8
    cpu.edx = 5469624 /*0x5375b8*/;
    // 00437eeb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437eed  e84eab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437ef2  a3404f5500             -mov dword ptr [0x554f40], eax
    app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */) = cpu.eax;
    // 00437ef7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437ef9  742f                   -je 0x437f2a
    if (cpu.flags.zf)
    {
        goto L_0x00437f2a;
    }
    // 00437efb  db05f0bb6f00           -fild dword ptr [0x6fbbf0]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */))));
    // 00437f01  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437f07  bab0794300             -mov edx, 0x4379b0
    cpu.edx = 4422064 /*0x4379b0*/;
    // 00437f0c  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437f13  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437f16  e8a54b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437f1b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437f1d  a1404f5500             -mov eax, dword ptr [0x554f40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */);
    // 00437f22  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 00437f25  e8264a0300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437f2a:
    // 00437f2a  bac8755300             -mov edx, 0x5375c8
    cpu.edx = 5469640 /*0x5375c8*/;
    // 00437f2f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437f31  e80aab0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437f36  a3444f5500             -mov dword ptr [0x554f44], eax
    app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */) = cpu.eax;
    // 00437f3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437f3d  7445                   -je 0x437f84
    if (cpu.flags.zf)
    {
        goto L_0x00437f84;
    }
    // 00437f3f  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437f46  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00437f4d  7508                   -jne 0x437f57
    if (!cpu.flags.zf)
    {
        goto L_0x00437f57;
    }
    // 00437f4f  db05f4bb6f00           +fild dword ptr [0x6fbbf4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */))));
    // 00437f55  eb06                   -jmp 0x437f5d
    goto L_0x00437f5d;
L_0x00437f57:
    // 00437f57  db0520295500           -fild dword ptr [0x552920]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */))));
L_0x00437f5d:
    // 00437f5d  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437f63  d95df8                 -fstp dword ptr [ebp - 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437f66  bad0794300             -mov edx, 0x4379d0
    cpu.edx = 4422096 /*0x4379d0*/;
    // 00437f6b  a1444f5500             -mov eax, dword ptr [0x554f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */);
    // 00437f70  e84b4b0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437f75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437f77  a1444f5500             -mov eax, dword ptr [0x554f44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */);
    // 00437f7c  ff75f8                 -push dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    // 00437f7f  e8cc490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437f84:
    // 00437f84  bad8755300             -mov edx, 0x5375d8
    cpu.edx = 5469656 /*0x5375d8*/;
    // 00437f89  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437f8b  e8b0aa0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437f90  a3484f5500             -mov dword ptr [0x554f48], eax
    app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */) = cpu.eax;
    // 00437f95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437f97  7446                   -je 0x437fdf
    if (cpu.flags.zf)
    {
        goto L_0x00437fdf;
    }
    // 00437f99  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00437f9f  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 00437fa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00437fa8  7508                   -jne 0x437fb2
    if (!cpu.flags.zf)
    {
        goto L_0x00437fb2;
    }
    // 00437faa  db05f8bb6f00           +fild dword ptr [0x6fbbf8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */))));
    // 00437fb0  eb06                   -jmp 0x437fb8
    goto L_0x00437fb8;
L_0x00437fb2:
    // 00437fb2  db0524295500           -fild dword ptr [0x552924]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */))));
L_0x00437fb8:
    // 00437fb8  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00437fbe  d95dfc                 -fstp dword ptr [ebp - 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00437fc1  ba207a4300             -mov edx, 0x437a20
    cpu.edx = 4422176 /*0x437a20*/;
    // 00437fc6  a1484f5500             -mov eax, dword ptr [0x554f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */);
    // 00437fcb  e8f04a0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00437fd0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00437fd2  a1484f5500             -mov eax, dword ptr [0x554f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */);
    // 00437fd7  ff75fc                 -push dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    // 00437fda  e871490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00437fdf:
    // 00437fdf  baec755300             -mov edx, 0x5375ec
    cpu.edx = 5469676 /*0x5375ec*/;
    // 00437fe4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00437fe6  e855aa0000             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00437feb  a34c4f5500             -mov dword ptr [0x554f4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */) = cpu.eax;
    // 00437ff0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00437ff2  742f                   -je 0x438023
    if (cpu.flags.zf)
    {
        goto L_0x00438023;
    }
    // 00437ff4  db05fcbb6f00           -fild dword ptr [0x6fbbfc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322620) /* 0x6fbbfc */))));
    // 00437ffa  dc0d00765300           -fmul qword ptr [0x537600]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5469696) /* 0x537600 */));
    // 00438000  ba707a4300             -mov edx, 0x437a70
    cpu.edx = 4422256 /*0x437a70*/;
    // 00438005  c7402c907a4300         -mov dword ptr [eax + 0x2c], 0x437a90
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 4422288 /*0x437a90*/;
    // 0043800c  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0043800f  e8ac4a0300             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00438014  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00438016  a14c4f5500             -mov eax, dword ptr [0x554f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */);
    // 0043801b  ff75f0                 -push dword ptr [ebp - 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    cpu.esp -= 4;
    // 0043801e  e82d490300             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00438023:
    // 00438023  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043802a  7510                   -jne 0x43803c
    if (!cpu.flags.zf)
    {
        goto L_0x0043803c;
    }
    // 0043802c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00438031  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 00438037  e834f40a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x0043803c:
    // 0043803c  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00438041  a124295500             -mov eax, dword ptr [0x552924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */);
    // 00438046  bf20395f00             -mov edi, 0x5f3920
    cpu.edi = 6240544 /*0x5f3920*/;
    // 0043804b  bed0bb6f00             -mov esi, 0x6fbbd0
    cpu.esi = 7322576 /*0x6fbbd0*/;
    // 00438050  a36c395f00             -mov dword ptr [0x5f396c], eax
    app->getMemory<x86::reg32>(x86::reg32(6240620) /* 0x5f396c */) = cpu.eax;
    // 00438055  a120295500             -mov eax, dword ptr [0x552920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */);
    // 0043805a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043805c  a360395f00             -mov dword ptr [0x5f3960], eax
    app->getMemory<x86::reg32>(x86::reg32(6240608) /* 0x5f3960 */) = cpu.eax;
    // 00438061  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438063:
    // 00438063  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438065  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438066  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438067  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438068  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438069  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043806a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_438070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438075  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438076  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438078  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043807a  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438081  7510                   -jne 0x438093
    if (!cpu.flags.zf)
    {
        goto L_0x00438093;
    }
    // 00438083  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00438088  8b15e8bb6f00           -mov edx, dword ptr [0x6fbbe8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322600) /* 0x6fbbe8 */);
    // 0043808e  e8ddf30a00             -call 0x4e7470
    cpu.esp -= 4;
    sub_4e7470(app, cpu);
    if (cpu.terminate) return;
L_0x00438093:
    // 00438093  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00438095  891d404f5500           -mov dword ptr [0x554f40], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590848) /* 0x554f40 */) = cpu.ebx;
    // 0043809b  891d444f5500           -mov dword ptr [0x554f44], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590852) /* 0x554f44 */) = cpu.ebx;
    // 004380a1  891d484f5500           -mov dword ptr [0x554f48], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590856) /* 0x554f48 */) = cpu.ebx;
    // 004380a7  891d4c4f5500           -mov dword ptr [0x554f4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590860) /* 0x554f4c */) = cpu.ebx;
    // 004380ad  891d204f5500           -mov dword ptr [0x554f20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590816) /* 0x554f20 */) = cpu.ebx;
    // 004380b3  891d244f5500           -mov dword ptr [0x554f24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590820) /* 0x554f24 */) = cpu.ebx;
    // 004380b9  891d284f5500           -mov dword ptr [0x554f28], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590824) /* 0x554f28 */) = cpu.ebx;
    // 004380bf  891d2c4f5500           -mov dword ptr [0x554f2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590828) /* 0x554f2c */) = cpu.ebx;
    // 004380c5  891d304f5500           -mov dword ptr [0x554f30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590832) /* 0x554f30 */) = cpu.ebx;
    // 004380cb  891d3c4f5500           -mov dword ptr [0x554f3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5590844) /* 0x554f3c */) = cpu.ebx;
    // 004380d1  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004380d8  745c                   -je 0x438136
    if (cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 004380da  803d0929550000         +cmp byte ptr [0x552909], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5581065) /* 0x552909 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004380e1  7414                   -je 0x4380f7
    if (cpu.flags.zf)
    {
        goto L_0x004380f7;
    }
    // 004380e3  a120295500             -mov eax, dword ptr [0x552920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */);
    // 004380e8  a3f4bb6f00             -mov dword ptr [0x6fbbf4], eax
    app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */) = cpu.eax;
    // 004380ed  a124295500             -mov eax, dword ptr [0x552924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */);
    // 004380f2  a3f8bb6f00             -mov dword ptr [0x6fbbf8], eax
    app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */) = cpu.eax;
L_0x004380f7:
    // 004380f7  803d90e8550000         +cmp byte ptr [0x55e890], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5630096) /* 0x55e890 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004380fe  7536                   -jne 0x438136
    if (!cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 00438100  8b35f0bb6f00           -mov esi, dword ptr [0x6fbbf0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322608) /* 0x6fbbf0 */);
    // 00438106  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438108  742c                   -je 0x438136
    if (cpu.flags.zf)
    {
        goto L_0x00438136;
    }
    // 0043810a  833de4bb6f0002         +cmp dword ptr [0x6fbbe4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438111  7e0e                   -jle 0x438121
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00438121;
    }
    // 00438113  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00438118  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 0043811d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043811f  eb09                   -jmp 0x43812a
    goto L_0x0043812a;
L_0x00438121:
    // 00438121  a1acd46f00             -mov eax, dword ptr [0x6fd4ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328940) /* 0x6fd4ac */);
    // 00438126  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438128  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043812a:
    // 0043812a  e89186fdff             -call 0x4107c0
    cpu.esp -= 4;
    sub_4107c0(app, cpu);
    if (cpu.terminate) return;
    // 0043812f  c60590e8550001         -mov byte ptr [0x55e890], 1
    app->getMemory<x86::reg8>(x86::reg32(5630096) /* 0x55e890 */) = 1 /*0x1*/;
L_0x00438136:
    // 00438136  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00438139  8b4916                 -mov ecx, dword ptr [ecx + 0x16]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0043813c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043813f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00438142  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00438144  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0043814b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043814d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00438150  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438152  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00438155  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0043815a  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043815d  0f85a5000000           -jne 0x438208
    if (!cpu.flags.zf)
    {
        goto L_0x00438208;
    }
    // 00438163  ba08765300             -mov edx, 0x537608
    cpu.edx = 5469704 /*0x537608*/;
    // 00438168  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0043816b  e850a80000             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 00438170  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438172  0f8490000000           -je 0x438208
    if (cpu.flags.zf)
    {
        goto L_0x00438208;
    }
    // 00438178  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0043817d  a160395f00             -mov eax, dword ptr [0x5f3960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240608) /* 0x5f3960 */);
    // 00438182  bfd0bb6f00             -mov edi, 0x6fbbd0
    cpu.edi = 7322576 /*0x6fbbd0*/;
    // 00438187  be20395f00             -mov esi, 0x5f3920
    cpu.esi = 6240544 /*0x5f3920*/;
    // 0043818c  8a1d09295500           -mov bl, byte ptr [0x552909]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5581065) /* 0x552909 */);
    // 00438192  a320295500             -mov dword ptr [0x552920], eax
    app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */) = cpu.eax;
    // 00438197  a16c395f00             -mov eax, dword ptr [0x5f396c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240620) /* 0x5f396c */);
    // 0043819c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043819e  a324295500             -mov dword ptr [0x552924], eax
    app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */) = cpu.eax;
    // 004381a3  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004381a5  7414                   -je 0x4381bb
    if (cpu.flags.zf)
    {
        goto L_0x004381bb;
    }
    // 004381a7  a120295500             -mov eax, dword ptr [0x552920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581088) /* 0x552920 */);
    // 004381ac  a3f4bb6f00             -mov dword ptr [0x6fbbf4], eax
    app->getMemory<x86::reg32>(x86::reg32(7322612) /* 0x6fbbf4 */) = cpu.eax;
    // 004381b1  a124295500             -mov eax, dword ptr [0x552924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5581092) /* 0x552924 */);
    // 004381b6  a3f8bb6f00             -mov dword ptr [0x6fbbf8], eax
    app->getMemory<x86::reg32>(x86::reg32(7322616) /* 0x6fbbf8 */) = cpu.eax;
L_0x004381bb:
    // 004381bb  8b0d34925500           -mov ecx, dword ptr [0x559234]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 004381c1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004381c3  751e                   -jne 0x4381e3
    if (!cpu.flags.zf)
    {
        goto L_0x004381e3;
    }
    // 004381c5  833d344f550000         +cmp dword ptr [0x554f34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004381cc  7415                   -je 0x4381e3
    if (cpu.flags.zf)
    {
        goto L_0x004381e3;
    }
    // 004381ce  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004381d3  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 004381d8  890d344f5500           -mov dword ptr [0x554f34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.ecx;
    // 004381de  e8bd81fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x004381e3:
    // 004381e3  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004381e8  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004381ed  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 004381f2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004381f4  e827120b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 004381f9  893d384f5500           -mov dword ptr [0x554f38], edi
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.edi;
    // 004381ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438204  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438205  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438207  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438208:
    // 00438208  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0043820d  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00438212  a1384f5500             -mov eax, dword ptr [0x554f38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */);
    // 00438217  e804120b00             -call 0x4e9420
    cpu.esp -= 4;
    sub_4e9420(app, cpu);
    if (cpu.terminate) return;
    // 0043821c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043821e  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00438224  a3384f5500             -mov dword ptr [0x554f38], eax
    app->getMemory<x86::reg32>(x86::reg32(5590840) /* 0x554f38 */) = cpu.eax;
    // 00438229  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043822b  7526                   -jne 0x438253
    if (!cpu.flags.zf)
    {
        goto L_0x00438253;
    }
    // 0043822d  833d344f550000         +cmp dword ptr [0x554f34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438234  7509                   -jne 0x43823f
    if (!cpu.flags.zf)
    {
        goto L_0x0043823f;
    }
    // 00438236  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438238  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438239  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043823e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043823f:
    // 0043823f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00438244  a3344f5500             -mov dword ptr [0x554f34], eax
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.eax;
    // 00438249  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 0043824e  e84d81fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x00438253:
    // 00438253  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438255  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043825a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043825b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_438260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438260  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438261  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438262  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438263  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438264  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438265  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438266  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438268  a170395f00             -mov eax, dword ptr [0x5f3970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */);
    // 0043826d  8b1500bc6f00           -mov edx, dword ptr [0x6fbc00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 00438273  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438275  39d0                   +cmp eax, edx
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
    // 00438277  7473                   -je 0x4382ec
    if (cpu.flags.zf)
    {
        goto L_0x004382ec;
    }
    // 00438279  b8e6010000             -mov eax, 0x1e6
    cpu.eax = 486 /*0x1e6*/;
    // 0043827e  891570395f00           -mov dword ptr [0x5f3970], edx
    app->getMemory<x86::reg32>(x86::reg32(6240624) /* 0x5f3970 */) = cpu.edx;
    // 00438284  e857c90000             -call 0x444be0
    cpu.esp -= 4;
    sub_444be0(app, cpu);
    if (cpu.terminate) return;
    // 00438289  e872dc0000             -call 0x445f00
    cpu.esp -= 4;
    sub_445f00(app, cpu);
    if (cpu.terminate) return;
    // 0043828e  e88d0e0a00             -call 0x4d9120
    cpu.esp -= 4;
    sub_4d9120(app, cpu);
    if (cpu.terminate) return;
    // 00438293  e8182c0100             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00438298  e853220100             -call 0x44a4f0
    cpu.esp -= 4;
    sub_44a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043829d  e80eb60000             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 004382a2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004382a4  7405                   -je 0x4382ab
    if (cpu.flags.zf)
    {
        goto L_0x004382ab;
    }
    // 004382a6  e8a5dc0000             -call 0x445f50
    cpu.esp -= 4;
    sub_445f50(app, cpu);
    if (cpu.terminate) return;
L_0x004382ab:
    // 004382ab  e8900e0a00             -call 0x4d9140
    cpu.esp -= 4;
    sub_4d9140(app, cpu);
    if (cpu.terminate) return;
    // 004382b0  e81b87fdff             -call 0x4109d0
    cpu.esp -= 4;
    sub_4109d0(app, cpu);
    if (cpu.terminate) return;
    // 004382b5  e8e687fdff             -call 0x410aa0
    cpu.esp -= 4;
    sub_410aa0(app, cpu);
    if (cpu.terminate) return;
    // 004382ba  e86188fdff             -call 0x410b20
    cpu.esp -= 4;
    sub_410b20(app, cpu);
    if (cpu.terminate) return;
    // 004382bf  e8ec7bfdff             -call 0x40feb0
    cpu.esp -= 4;
    sub_40feb0(app, cpu);
    if (cpu.terminate) return;
    // 004382c4  a100bc6f00             -mov eax, dword ptr [0x6fbc00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322624) /* 0x6fbc00 */);
    // 004382c9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004382ce  e81d7afdff             -call 0x40fcf0
    cpu.esp -= 4;
    sub_40fcf0(app, cpu);
    if (cpu.terminate) return;
    // 004382d3  e808b4fdff             -call 0x4136e0
    cpu.esp -= 4;
    sub_4136e0(app, cpu);
    if (cpu.terminate) return;
    // 004382d8  e85380fdff             -call 0x410330
    cpu.esp -= 4;
    sub_410330(app, cpu);
    if (cpu.terminate) return;
    // 004382dd  a1ecbb6f00             -mov eax, dword ptr [0x6fbbec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 004382e2  e8b980fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
    // 004382e7  e824dc0000             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
L_0x004382ec:
    // 004382ec  8b1de4bb6f00           -mov ebx, dword ptr [0x6fbbe4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7322596) /* 0x6fbbe4 */);
    // 004382f2  3b1d68395f00           +cmp ebx, dword ptr [0x5f3968]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004382f8  741a                   -je 0x438314
    if (cpu.flags.zf)
    {
        goto L_0x00438314;
    }
    // 004382fa  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004382ff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438301  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00438303  891d68395f00           -mov dword ptr [0x5f3968], ebx
    app->getMemory<x86::reg32>(x86::reg32(6240616) /* 0x5f3968 */) = cpu.ebx;
    // 00438309  e89280fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
    // 0043830e  8935344f5500           -mov dword ptr [0x554f34], esi
    app->getMemory<x86::reg32>(x86::reg32(5590836) /* 0x554f34 */) = cpu.esi;
L_0x00438314:
    // 00438314  8b3decbb6f00           -mov edi, dword ptr [0x6fbbec]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7322604) /* 0x6fbbec */);
    // 0043831a  3b3d64395f00           +cmp edi, dword ptr [0x5f3964]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438320  7412                   -je 0x438334
    if (cpu.flags.zf)
    {
        goto L_0x00438334;
    }
    // 00438322  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00438327  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00438329  893d64395f00           -mov dword ptr [0x5f3964], edi
    app->getMemory<x86::reg32>(x86::reg32(6240612) /* 0x5f3964 */) = cpu.edi;
    // 0043832f  e86c80fdff             -call 0x4103a0
    cpu.esp -= 4;
    sub_4103a0(app, cpu);
    if (cpu.terminate) return;
L_0x00438334:
    // 00438334  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438336  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438337  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438338  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438339  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043833c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_438340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438340  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438341  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438343  e858a60100             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 00438348  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438351  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438352  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438353  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438354  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438355  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438357  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043835d  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438363  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438366  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438368  ba64765300             -mov edx, 0x537664
    cpu.edx = 5469796 /*0x537664*/;
    // 0043836d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043836e:
    // 0043836e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438370  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438372  3c00                   +cmp al, 0
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
    // 00438374  7410                   -je 0x438386
    if (cpu.flags.zf)
    {
        goto L_0x00438386;
    }
    // 00438376  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438379  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043837c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043837f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438382  3c00                   +cmp al, 0
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
    // 00438384  75e8                   -jne 0x43836e
    if (!cpu.flags.zf)
    {
        goto L_0x0043836e;
    }
L_0x00438386:
    // 00438386  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438387  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043838a  be58765300             -mov esi, 0x537658
    cpu.esi = 5469784 /*0x537658*/;
    // 0043838f  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438392  e8a9ffffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438397  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438398  2bc9                   +sub ecx, ecx
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
    // 0043839a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043839b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043839d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043839f  4f                     -dec edi
    (cpu.edi)--;
L_0x004383a0:
    // 004383a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004383a2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004383a4  3c00                   +cmp al, 0
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
    // 004383a6  7410                   -je 0x4383b8
    if (cpu.flags.zf)
    {
        goto L_0x004383b8;
    }
    // 004383a8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004383ab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004383ae  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004383b1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004383b4  3c00                   +cmp al, 0
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
    // 004383b6  75e8                   -jne 0x4383a0
    if (!cpu.flags.zf)
    {
        goto L_0x004383a0;
    }
L_0x004383b8:
    // 004383b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383b9  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004383bc  e8275c0b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 004383c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004383c3  7412                   -je 0x4383d7
    if (cpu.flags.zf)
    {
        goto L_0x004383d7;
    }
    // 004383c5  e8365d0b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 004383ca  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004383cd  e80e5f0b00             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
    // 004383d2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004383d7:
    // 004383d7  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 004383dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004383e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4383f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004383f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004383f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004383f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004383f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004383f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004383f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004383f7  81ec34010000           -sub esp, 0x134
    (cpu.esp) -= x86::reg32(x86::sreg32(308 /*0x134*/));
    // 004383fd  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00438400  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00438402  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00438405  eb0a                   -jmp 0x438411
    goto L_0x00438411;
L_0x00438407:
    // 00438407  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043840b  0f8587000000           -jne 0x438498
    if (!cpu.flags.zf)
    {
        goto L_0x00438498;
    }
L_0x00438411:
    // 00438411  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438412  6868765300             -push 0x537668
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469800 /*0x537668*/;
    cpu.esp -= 4;
    // 00438417  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438418  e873720a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043841d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438420  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438423  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438429  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043842a:
    // 0043842a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043842c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043842e  3c00                   +cmp al, 0
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
    // 00438430  7410                   -je 0x438442
    if (cpu.flags.zf)
    {
        goto L_0x00438442;
    }
    // 00438432  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438435  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438438  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043843b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043843e  3c00                   +cmp al, 0
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
    // 00438440  75e8                   -jne 0x43842a
    if (!cpu.flags.zf)
    {
        goto L_0x0043842a;
    }
L_0x00438442:
    // 00438442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438443  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438449  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043844f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438451  e8eafeffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438456  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438457  2bc9                   +sub ecx, ecx
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
    // 00438459  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043845a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043845c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043845e  4f                     -dec edi
    (cpu.edi)--;
L_0x0043845f:
    // 0043845f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438461  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438463  3c00                   +cmp al, 0
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
    // 00438465  7410                   -je 0x438477
    if (cpu.flags.zf)
    {
        goto L_0x00438477;
    }
    // 00438467  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043846a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043846d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438470  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438473  3c00                   +cmp al, 0
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
    // 00438475  75e8                   -jne 0x43845f
    if (!cpu.flags.zf)
    {
        goto L_0x0043845f;
    }
L_0x00438477:
    // 00438477  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438478  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043847e  43                     -inc ebx
    (cpu.ebx)++;
    // 0043847f  e8ccfeffff             -call 0x438350
    cpu.esp -= 4;
    sub_438350(app, cpu);
    if (cpu.terminate) return;
    // 00438484  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438486  0f857bffffff           -jne 0x438407
    if (!cpu.flags.zf)
    {
        goto L_0x00438407;
    }
    // 0043848c  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00438493  e96fffffff             -jmp 0x438407
    goto L_0x00438407;
L_0x00438498:
    // 00438498  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043849a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043849f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4384a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004384a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004384a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004384a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004384a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004384a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004384a6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004384ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004384ae  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 004384b3  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004384ba:
    // 004384ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004384bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004384be  3c00                   +cmp al, 0
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
    // 004384c0  7410                   -je 0x4384d2
    if (cpu.flags.zf)
    {
        goto L_0x004384d2;
    }
    // 004384c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004384c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004384c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004384cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004384ce  3c00                   +cmp al, 0
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
    // 004384d0  75e8                   -jne 0x4384ba
    if (!cpu.flags.zf)
    {
        goto L_0x004384ba;
    }
L_0x004384d2:
    // 004384d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384d3  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384d9  e862feffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004384de  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004384e4  e807ffffff             -call 0x4383f0
    cpu.esp -= 4;
    sub_4383f0(app, cpu);
    if (cpu.terminate) return;
    // 004384e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004384eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004384ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4384f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004384f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004384f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004384f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004384f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004384f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004384f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004384f7  81ec34010000           -sub esp, 0x134
    (cpu.esp) -= x86::reg32(x86::sreg32(308 /*0x134*/));
    // 004384fd  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00438500  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00438502  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00438505  eb0a                   -jmp 0x438511
    goto L_0x00438511;
L_0x00438507:
    // 00438507  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043850b  0f8587000000           -jne 0x438598
    if (!cpu.flags.zf)
    {
        goto L_0x00438598;
    }
L_0x00438511:
    // 00438511  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438512  6870765300             -push 0x537670
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469808 /*0x537670*/;
    cpu.esp -= 4;
    // 00438517  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438518  e873710a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0043851d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438520  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438523  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438529  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043852a:
    // 0043852a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043852c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043852e  3c00                   +cmp al, 0
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
    // 00438530  7410                   -je 0x438542
    if (cpu.flags.zf)
    {
        goto L_0x00438542;
    }
    // 00438532  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438535  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438538  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043853b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043853e  3c00                   +cmp al, 0
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
    // 00438540  75e8                   -jne 0x43852a
    if (!cpu.flags.zf)
    {
        goto L_0x0043852a;
    }
L_0x00438542:
    // 00438542  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438543  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 00438549  8dbdccfeffff           -lea edi, [ebp - 0x134]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043854f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438551  e8eafdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438556  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438557  2bc9                   +sub ecx, ecx
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
    // 00438559  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043855a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0043855c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0043855e  4f                     -dec edi
    (cpu.edi)--;
L_0x0043855f:
    // 0043855f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438561  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438563  3c00                   +cmp al, 0
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
    // 00438565  7410                   -je 0x438577
    if (cpu.flags.zf)
    {
        goto L_0x00438577;
    }
    // 00438567  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043856a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043856d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438570  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438573  3c00                   +cmp al, 0
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
    // 00438575  75e8                   -jne 0x43855f
    if (!cpu.flags.zf)
    {
        goto L_0x0043855f;
    }
L_0x00438577:
    // 00438577  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438578  8d85ccfeffff           -lea eax, [ebp - 0x134]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-308) /* -0x134 */);
    // 0043857e  43                     -inc ebx
    (cpu.ebx)++;
    // 0043857f  e8ccfdffff             -call 0x438350
    cpu.esp -= 4;
    sub_438350(app, cpu);
    if (cpu.terminate) return;
    // 00438584  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438586  0f857bffffff           -jne 0x438507
    if (!cpu.flags.zf)
    {
        goto L_0x00438507;
    }
    // 0043858c  c745fc01000000         -mov dword ptr [ebp - 4], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 1 /*0x1*/;
    // 00438593  e96fffffff             -jmp 0x438507
    goto L_0x00438507;
L_0x00438598:
    // 00438598  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043859a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043859f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4385a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004385a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004385a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004385a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004385a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004385a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004385a6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004385ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004385ae  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 004385b3  8dbdd4feffff           -lea edi, [ebp - 0x12c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385b9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004385ba:
    // 004385ba  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004385bc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004385be  3c00                   +cmp al, 0
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
    // 004385c0  7410                   -je 0x4385d2
    if (cpu.flags.zf)
    {
        goto L_0x004385d2;
    }
    // 004385c2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004385c5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004385c8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004385cb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004385ce  3c00                   +cmp al, 0
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
    // 004385d0  75e8                   -jne 0x4385ba
    if (!cpu.flags.zf)
    {
        goto L_0x004385ba;
    }
L_0x004385d2:
    // 004385d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385d3  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385d9  e862fdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004385de  8d85d4feffff           -lea eax, [ebp - 0x12c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-300) /* -0x12c */);
    // 004385e4  e807ffffff             -call 0x4384f0
    cpu.esp -= 4;
    sub_4384f0(app, cpu);
    if (cpu.terminate) return;
    // 004385e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004385eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004385ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4385f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004385f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004385f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004385f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004385f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004385f4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004385f6  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004385fc  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438602  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438605  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438607  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00438608:
    // 00438608  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043860a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043860c  3c00                   +cmp al, 0
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
    // 0043860e  7410                   -je 0x438620
    if (cpu.flags.zf)
    {
        goto L_0x00438620;
    }
    // 00438610  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438613  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438616  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438619  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043861c  3c00                   +cmp al, 0
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
    // 0043861e  75e8                   -jne 0x438608
    if (!cpu.flags.zf)
    {
        goto L_0x00438608;
    }
L_0x00438620:
    // 00438620  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438621  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438624  be78765300             -mov esi, 0x537678
    cpu.esi = 5469816 /*0x537678*/;
    // 00438629  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043862c  e80ffdffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438631  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438632  2bc9                   +sub ecx, ecx
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
    // 00438634  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438635  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438637  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438639  4f                     -dec edi
    (cpu.edi)--;
L_0x0043863a:
    // 0043863a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043863c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043863e  3c00                   +cmp al, 0
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
    // 00438640  7410                   -je 0x438652
    if (cpu.flags.zf)
    {
        goto L_0x00438652;
    }
    // 00438642  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438645  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438648  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043864b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043864e  3c00                   +cmp al, 0
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
    // 00438650  75e8                   -jne 0x43863a
    if (!cpu.flags.zf)
    {
        goto L_0x0043863a;
    }
L_0x00438652:
    // 00438652  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438653  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438656  8b3495544f5500         -mov esi, dword ptr [edx*4 + 0x554f54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590868) /* 0x554f54 */ + cpu.edx * 4);
    // 0043865d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043865e  2bc9                   +sub ecx, ecx
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
    // 00438660  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438661  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438663  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438665  4f                     -dec edi
    (cpu.edi)--;
L_0x00438666:
    // 00438666  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438668  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043866a  3c00                   +cmp al, 0
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
    // 0043866c  7410                   -je 0x43867e
    if (cpu.flags.zf)
    {
        goto L_0x0043867e;
    }
    // 0043866e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438671  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438674  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438677  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043867a  3c00                   +cmp al, 0
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
    // 0043867c  75e8                   -jne 0x438666
    if (!cpu.flags.zf)
    {
        goto L_0x00438666;
    }
L_0x0043867e:
    // 0043867e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043867f  ba80765300             -mov edx, 0x537680
    cpu.edx = 5469824 /*0x537680*/;
    // 00438684  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438687  e85c590b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0043868c  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438692  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438693  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438695  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438696  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4386a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004386a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004386a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004386a3  e8585a0b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 004386a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004386a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4386b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004386b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004386b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004386b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004386b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004386b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004386b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004386b6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004386b8  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004386be  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004386c4  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004386c9  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 004386ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004386cf:
    // 004386cf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004386d1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004386d3  3c00                   +cmp al, 0
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
    // 004386d5  7410                   -je 0x4386e7
    if (cpu.flags.zf)
    {
        goto L_0x004386e7;
    }
    // 004386d7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004386da  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004386dd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004386e0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004386e3  3c00                   +cmp al, 0
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
    // 004386e5  75e8                   -jne 0x4386cf
    if (!cpu.flags.zf)
    {
        goto L_0x004386cf;
    }
L_0x004386e7:
    // 004386e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004386e8  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386eb  be84765300             -mov esi, 0x537684
    cpu.esi = 5469828 /*0x537684*/;
    // 004386f0  e8fb5b0b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 004386f5  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386f8  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004386fb  e840fcffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438700  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438701  2bc9                   +sub ecx, ecx
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
    // 00438703  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438704  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438706  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438708  4f                     -dec edi
    (cpu.edi)--;
L_0x00438709:
    // 00438709  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043870b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043870d  3c00                   +cmp al, 0
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
    // 0043870f  7410                   -je 0x438721
    if (cpu.flags.zf)
    {
        goto L_0x00438721;
    }
    // 00438711  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438714  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438717  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043871a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043871d  3c00                   +cmp al, 0
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
    // 0043871f  75e8                   -jne 0x438709
    if (!cpu.flags.zf)
    {
        goto L_0x00438709;
    }
L_0x00438721:
    // 00438721  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438722  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 00438727  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0043872a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043872b  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438732  a3784f5500             -mov dword ptr [0x554f78], eax
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.eax;
    // 00438737  83f8ff                 +cmp eax, -1
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
    // 0043873a  7517                   -jne 0x438753
    if (!cpu.flags.zf)
    {
        goto L_0x00438753;
    }
    // 0043873c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043873e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438740  8915784f5500           -mov dword ptr [0x554f78], edx
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.edx;
    // 00438746  e983000000             -jmp 0x4387ce
    goto L_0x004387ce;
L_0x0043874b:
    // 0043874b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043874d  0f8563000000           -jne 0x4387b6
    if (!cpu.flags.zf)
    {
        goto L_0x004387b6;
    }
L_0x00438753:
    // 00438753  f605c03a5f0010         +test byte ptr [0x5f3ac0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240960) /* 0x5f3ac0 */) & 16 /*0x10*/));
    // 0043875a  7438                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 0043875c  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438761  b888765300             -mov eax, 0x537688
    cpu.eax = 5469832 /*0x537688*/;
    // 00438766  e8a55b0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043876b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043876d  7425                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 0043876f  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438774  b88c765300             -mov eax, 0x53768c
    cpu.eax = 5469836 /*0x53768c*/;
    // 00438779  e8925b0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043877e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438780  7412                   -je 0x438794
    if (cpu.flags.zf)
    {
        goto L_0x00438794;
    }
    // 00438782  b8ec3a5f00             -mov eax, 0x5f3aec
    cpu.eax = 6241004 /*0x5f3aec*/;
    // 00438787  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 0043878d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043878e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043878f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438790  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438791  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438792  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438793  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438794:
    // 00438794  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 00438799  8b0d784f5500           -mov ecx, dword ptr [0x554f78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 0043879f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004387a0  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004387a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004387a9  7507                   -jne 0x4387b2
    if (!cpu.flags.zf)
    {
        goto L_0x004387b2;
    }
    // 004387ab  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004387b0  eb99                   -jmp 0x43874b
    goto L_0x0043874b;
L_0x004387b2:
    // 004387b2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004387b4  eb95                   -jmp 0x43874b
    goto L_0x0043874b;
L_0x004387b6:
    // 004387b6  8b1d784f5500           -mov ebx, dword ptr [0x554f78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 004387bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004387bd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004387bf  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004387c6  8935784f5500           -mov dword ptr [0x554f78], esi
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.esi;
    // 004387cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004387ce:
    // 004387ce  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 004387d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004387da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4387e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004387e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004387e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004387e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004387e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004387e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004387e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004387e7  833d784f550000         +cmp dword ptr [0x554f78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004387ee  0f8465000000           -je 0x438859
    if (cpu.flags.zf)
    {
        goto L_0x00438859;
    }
L_0x004387f4:
    // 004387f4  68c03a5f00             -push 0x5f3ac0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240960 /*0x5f3ac0*/;
    cpu.esp -= 4;
    // 004387f9  8b0d784f5500           -mov ecx, dword ptr [0x554f78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 004387ff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438800  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438807  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438809  7438                   -je 0x438843
    if (cpu.flags.zf)
    {
        goto L_0x00438843;
    }
    // 0043880b  f605c03a5f0010         +test byte ptr [0x5f3ac0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240960) /* 0x5f3ac0 */) & 16 /*0x10*/));
    // 00438812  74e0                   -je 0x4387f4
    if (cpu.flags.zf)
    {
        goto L_0x004387f4;
    }
    // 00438814  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 00438819  b888765300             -mov eax, 0x537688
    cpu.eax = 5469832 /*0x537688*/;
    // 0043881e  e8ed5a0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438823  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438825  74cd                   -je 0x4387f4
    if (cpu.flags.zf)
    {
        goto L_0x004387f4;
    }
    // 00438827  baec3a5f00             -mov edx, 0x5f3aec
    cpu.edx = 6241004 /*0x5f3aec*/;
    // 0043882c  b88c765300             -mov eax, 0x53768c
    cpu.eax = 5469836 /*0x53768c*/;
    // 00438831  e8da5a0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438838  7502                   -jne 0x43883c
    if (!cpu.flags.zf)
    {
        goto L_0x0043883c;
    }
    // 0043883a  ebb8                   -jmp 0x4387f4
    goto L_0x004387f4;
L_0x0043883c:
    // 0043883c  b8ec3a5f00             -mov eax, 0x5f3aec
    cpu.eax = 6241004 /*0x5f3aec*/;
    // 00438841  eb18                   -jmp 0x43885b
    goto L_0x0043885b;
L_0x00438843:
    // 00438843  8b1d784f5500           -mov ebx, dword ptr [0x554f78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */);
    // 00438849  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043884a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043884c  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438853  8935784f5500           -mov dword ptr [0x554f78], esi
    app->getMemory<x86::reg32>(x86::reg32(5590904) /* 0x554f78 */) = cpu.esi;
L_0x00438859:
    // 00438859  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043885b:
    // 0043885b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043885f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438860  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438873  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438874  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438875  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438876  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438878  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043887e  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 00438884  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438887  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438889  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 0043888e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043888f:
    // 0043888f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438891  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438893  3c00                   +cmp al, 0
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
    // 00438895  7410                   -je 0x4388a7
    if (cpu.flags.zf)
    {
        goto L_0x004388a7;
    }
    // 00438897  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043889a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043889d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004388a0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388a3  3c00                   +cmp al, 0
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
    // 004388a5  75e8                   -jne 0x43888f
    if (!cpu.flags.zf)
    {
        goto L_0x0043888f;
    }
L_0x004388a7:
    // 004388a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004388a8  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388ab  be84765300             -mov esi, 0x537684
    cpu.esi = 5469828 /*0x537684*/;
    // 004388b0  e83b5a0b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 004388b5  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388b8  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388bb  e880faffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004388c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004388c1  2bc9                   +sub ecx, ecx
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
    // 004388c3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004388c4  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004388c6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004388c8  4f                     -dec edi
    (cpu.edi)--;
L_0x004388c9:
    // 004388c9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004388cb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004388cd  3c00                   +cmp al, 0
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
    // 004388cf  7410                   -je 0x4388e1
    if (cpu.flags.zf)
    {
        goto L_0x004388e1;
    }
    // 004388d1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004388d4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388d7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004388da  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004388dd  3c00                   +cmp al, 0
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
    // 004388df  75e8                   -jne 0x4388c9
    if (!cpu.flags.zf)
    {
        goto L_0x004388c9;
    }
L_0x004388e1:
    // 004388e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004388e2  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 004388e7  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004388ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004388eb  2eff15cc445300         -call dword ptr cs:[0x5344cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457100) /* 0x5344cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004388f2  a37c4f5500             -mov dword ptr [0x554f7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.eax;
    // 004388f7  83f8ff                 +cmp eax, -1
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
    // 004388fa  7510                   -jne 0x43890c
    if (!cpu.flags.zf)
    {
        goto L_0x0043890c;
    }
    // 004388fc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004388fe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438900  89157c4f5500           -mov dword ptr [0x554f7c], edx
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.edx;
    // 00438906  eb59                   -jmp 0x438961
    goto L_0x00438961;
L_0x00438908:
    // 00438908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043890a  753d                   -jne 0x438949
    if (!cpu.flags.zf)
    {
        goto L_0x00438949;
    }
L_0x0043890c:
    // 0043890c  f60580395f0010         +test byte ptr [0x5f3980], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240640) /* 0x5f3980 */) & 16 /*0x10*/));
    // 00438913  7512                   -jne 0x438927
    if (!cpu.flags.zf)
    {
        goto L_0x00438927;
    }
    // 00438915  b8ac395f00             -mov eax, 0x5f39ac
    cpu.eax = 6240684 /*0x5f39ac*/;
    // 0043891a  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438920  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438921  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438922  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438923  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438924  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438925  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438927:
    // 00438927  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 0043892c  8b0d7c4f5500           -mov ecx, dword ptr [0x554f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 00438932  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438933  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0043893a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043893c  7507                   -jne 0x438945
    if (!cpu.flags.zf)
    {
        goto L_0x00438945;
    }
    // 0043893e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00438943  ebc3                   -jmp 0x438908
    goto L_0x00438908;
L_0x00438945:
    // 00438945  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438947  ebbf                   -jmp 0x438908
    goto L_0x00438908;
L_0x00438949:
    // 00438949  8b1d7c4f5500           -mov ebx, dword ptr [0x554f7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 0043894f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438950  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00438952  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438959  89357c4f5500           -mov dword ptr [0x554f7c], esi
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.esi;
    // 0043895f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438961:
    // 00438961  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438967  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438968  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438969  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043896d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_438970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438974  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438975  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438977  833d7c4f550000         +cmp dword ptr [0x554f7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043897e  743d                   -je 0x4389bd
    if (cpu.flags.zf)
    {
        goto L_0x004389bd;
    }
L_0x00438980:
    // 00438980  6880395f00             -push 0x5f3980
    app->getMemory<x86::reg32>(cpu.esp-4) = 6240640 /*0x5f3980*/;
    cpu.esp -= 4;
    // 00438985  8b0d7c4f5500           -mov ecx, dword ptr [0x554f7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 0043898b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043898c  2eff15d0445300         -call dword ptr cs:[0x5344d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457104) /* 0x5344d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00438993  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438995  7410                   -je 0x4389a7
    if (cpu.flags.zf)
    {
        goto L_0x004389a7;
    }
    // 00438997  f60580395f0010         +test byte ptr [0x5f3980], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6240640) /* 0x5f3980 */) & 16 /*0x10*/));
    // 0043899e  75e0                   -jne 0x438980
    if (!cpu.flags.zf)
    {
        goto L_0x00438980;
    }
    // 004389a0  b8ac395f00             -mov eax, 0x5f39ac
    cpu.eax = 6240684 /*0x5f39ac*/;
    // 004389a5  eb18                   -jmp 0x4389bf
    goto L_0x004389bf;
L_0x004389a7:
    // 004389a7  8b1d7c4f5500           -mov ebx, dword ptr [0x554f7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */);
    // 004389ad  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004389ae  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004389b0  2eff15c8445300         -call dword ptr cs:[0x5344c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457096) /* 0x5344c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004389b7  89357c4f5500           -mov dword ptr [0x554f7c], esi
    app->getMemory<x86::reg32>(x86::reg32(5590908) /* 0x554f7c */) = cpu.esi;
L_0x004389bd:
    // 004389bd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004389bf:
    // 004389bf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004389c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4389d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004389d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004389d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004389d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004389d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004389d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004389d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004389d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004389d8  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004389de  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004389e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004389e6  e885feffff             -call 0x438870
    cpu.esp -= 4;
    sub_438870(app, cpu);
    if (cpu.terminate) return;
L_0x004389eb:
    // 004389eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004389ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004389ef  746c                   -je 0x438a5d
    if (cpu.flags.zf)
    {
        goto L_0x00438a5d;
    }
    // 004389f1  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004389f4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004389f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004389f7:
    // 004389f7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004389f9  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004389fb  3c00                   +cmp al, 0
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
    // 004389fd  7410                   -je 0x438a0f
    if (cpu.flags.zf)
    {
        goto L_0x00438a0f;
    }
    // 004389ff  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438a02  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a05  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438a08  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a0b  3c00                   +cmp al, 0
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
    // 00438a0d  75e8                   -jne 0x4389f7
    if (!cpu.flags.zf)
    {
        goto L_0x004389f7;
    }
L_0x00438a0f:
    // 00438a0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a10  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a13  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a16  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438a18  e823f9ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00438a1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438a1e  2bc9                   +sub ecx, ecx
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
    // 00438a20  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00438a21  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00438a23  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00438a25  4f                     -dec edi
    (cpu.edi)--;
L_0x00438a26:
    // 00438a26  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00438a28  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00438a2a  3c00                   +cmp al, 0
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
    // 00438a2c  7410                   -je 0x438a3e
    if (cpu.flags.zf)
    {
        goto L_0x00438a3e;
    }
    // 00438a2e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00438a31  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a34  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00438a37  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00438a3a  3c00                   +cmp al, 0
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
    // 00438a3c  75e8                   -jne 0x438a26
    if (!cpu.flags.zf)
    {
        goto L_0x00438a26;
    }
L_0x00438a3e:
    // 00438a3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a3f  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00438a44  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a47  e874590b00             -call 0x4ee3c0
    cpu.esp -= 4;
    sub_4ee3c0(app, cpu);
    if (cpu.terminate) return;
    // 00438a4c  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00438a4f  e88c580b00             -call 0x4ee2e0
    cpu.esp -= 4;
    sub_4ee2e0(app, cpu);
    if (cpu.terminate) return;
    // 00438a54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438a56  e815ffffff             -call 0x438970
    cpu.esp -= 4;
    sub_438970(app, cpu);
    if (cpu.terminate) return;
    // 00438a5b  eb8e                   -jmp 0x4389eb
    goto L_0x004389eb;
L_0x00438a5d:
    // 00438a5d  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 00438a62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438a64  e857590b00             -call 0x4ee3c0
    cpu.esp -= 4;
    sub_4ee3c0(app, cpu);
    if (cpu.terminate) return;
    // 00438a69  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438a6b  e890590b00             -call 0x4ee400
    cpu.esp -= 4;
    sub_4ee400(app, cpu);
    if (cpu.terminate) return;
    // 00438a70  85c0                   -test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438a72  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00438a78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_438a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438a80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438a81  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438a82  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438a84  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438a8a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438a8c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438a8e  7505                   -jne 0x438a95
    if (!cpu.flags.zf)
    {
        goto L_0x00438a95;
    }
    // 00438a90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438a92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438a95:
    // 00438a95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438a97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438a99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438aa0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438aa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438aa2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438aa4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438aa6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438aa8  7505                   -jne 0x438aaf
    if (!cpu.flags.zf)
    {
        goto L_0x00438aaf;
    }
    // 00438aaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438aac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438aaf:
    // 00438aaf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00438ab1  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438ab3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438ab5  7505                   -jne 0x438abc
    if (!cpu.flags.zf)
    {
        goto L_0x00438abc;
    }
    // 00438ab7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438ab9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438abb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438abc:
    // 00438abc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438abe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438abf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ac0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438ad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438ad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438ad2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438ad3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438ad4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438ad6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438ad8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00438ada  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00438adf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00438ae1  e85a7b0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00438ae6  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00438ae8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ae9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aeb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438aec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438af0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438af1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438af2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438af4  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438afa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438afc  7504                   -jne 0x438b02
    if (!cpu.flags.zf)
    {
        goto L_0x00438b02;
    }
    // 00438afe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438b00  eb02                   -jmp 0x438b04
    goto L_0x00438b04;
L_0x00438b02:
    // 00438b02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00438b04:
    // 00438b04  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b14  8b15cc3c5f00           -mov edx, dword ptr [0x5f3ccc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */);
    // 00438b1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438b1c  7504                   -jne 0x438b22
    if (!cpu.flags.zf)
    {
        goto L_0x00438b22;
    }
    // 00438b1e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00438b20  eb13                   -jmp 0x438b35
    goto L_0x00438b35;
L_0x00438b22:
    // 00438b22  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00438b24  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00438b26  750b                   -jne 0x438b33
    if (!cpu.flags.zf)
    {
        goto L_0x00438b33;
    }
    // 00438b28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438b2a  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438b33:
    // 00438b33  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00438b35:
    // 00438b35  8915cc3c5f00           -mov dword ptr [0x5f3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(6241484) /* 0x5f3ccc */) = cpu.edx;
    // 00438b3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_438b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438b41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b43  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b45  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438b47  e8a4ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
    // 00438b4c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00438b4e:
    // 00438b4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438b50  740c                   -je 0x438b5e
    if (cpu.flags.zf)
    {
        goto L_0x00438b5e;
    }
    // 00438b52  39ca                   +cmp edx, ecx
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
    // 00438b54  7408                   -je 0x438b5e
    if (cpu.flags.zf)
    {
        goto L_0x00438b5e;
    }
    // 00438b56  e8b5ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438b5b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00438b5c  ebf0                   -jmp 0x438b4e
    goto L_0x00438b4e;
L_0x00438b5e:
    // 00438b5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_438b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438b76  e875ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
L_0x00438b7b:
    // 00438b7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438b7d  740b                   -je 0x438b8a
    if (cpu.flags.zf)
    {
        goto L_0x00438b8a;
    }
    // 00438b7f  3b10                   +cmp edx, dword ptr [eax]
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
    // 00438b81  7407                   -je 0x438b8a
    if (cpu.flags.zf)
    {
        goto L_0x00438b8a;
    }
    // 00438b83  e888ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438b88  ebf1                   -jmp 0x438b7b
    goto L_0x00438b7b;
L_0x00438b8a:
    // 00438b8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438b8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438b92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438b93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438b94  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438b96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438b98  e853ffffff             -call 0x438af0
    cpu.esp -= 4;
    sub_438af0(app, cpu);
    if (cpu.terminate) return;
    // 00438b9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438b9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438ba1  750b                   -jne 0x438bae
    if (!cpu.flags.zf)
    {
        goto L_0x00438bae;
    }
    // 00438ba3  8915704f5500           -mov dword ptr [0x554f70], edx
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.edx;
    // 00438ba9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438baa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438bae:
    // 00438bae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00438bb0:
    // 00438bb0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00438bb2  740b                   -je 0x438bbf
    if (cpu.flags.zf)
    {
        goto L_0x00438bbf;
    }
    // 00438bb4  e857ffffff             -call 0x438b10
    cpu.esp -= 4;
    sub_438b10(app, cpu);
    if (cpu.terminate) return;
    // 00438bb9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00438bbb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438bbd  ebf1                   -jmp 0x438bb0
    goto L_0x00438bb0;
L_0x00438bbf:
    // 00438bbf  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00438bc1  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00438bc3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_438bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438bd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438bd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438bd3  a1c83c5f00             -mov eax, dword ptr [0x5f3cc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6241480) /* 0x5f3cc8 */);
    // 00438bd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438bd9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_438be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438be0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438be1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438be2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438be4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00438be7  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438bea  e891feffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00438bef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00438bf1:
    // 00438bf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438bf3  740b                   -je 0x438c00
    if (cpu.flags.zf)
    {
        goto L_0x00438c00;
    }
    // 00438bf5  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438bf8  e8a3feffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00438bfd  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00438bfe  ebf1                   -jmp 0x438bf1
    goto L_0x00438bf1;
L_0x00438c00:
    // 00438c00  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438c02  8915c83c5f00           -mov dword ptr [0x5f3cc8], edx
    app->getMemory<x86::reg32>(x86::reg32(6241480) /* 0x5f3cc8 */) = cpu.edx;
    // 00438c08  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438c0a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_438c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438c10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438c11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438c12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438c13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438c15  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00438c17  a1704f5500             -mov eax, dword ptr [0x554f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438c1c  39d0                   +cmp eax, edx
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
    // 00438c1e  750b                   -jne 0x438c2b
    if (!cpu.flags.zf)
    {
        goto L_0x00438c2b;
    }
    // 00438c20  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00438c22  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
    // 00438c27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c28  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c29  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438c2b:
    // 00438c2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c2d  7412                   -je 0x438c41
    if (cpu.flags.zf)
    {
        goto L_0x00438c41;
    }
    // 00438c2f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438c31  39ca                   +cmp edx, ecx
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
    // 00438c33  7508                   -jne 0x438c3d
    if (!cpu.flags.zf)
    {
        goto L_0x00438c3d;
    }
    // 00438c35  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c37  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00438c39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438c3d:
    // 00438c3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438c3f  ebea                   -jmp 0x438c2b
    goto L_0x00438c2b;
L_0x00438c41:
    // 00438c41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438c44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_438c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438c51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438c52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438c53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438c54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438c55  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438c57  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438c5a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00438c5c  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00438c5f  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 00438c65  837d1800               +cmp dword ptr [ebp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438c69  7508                   -jne 0x438c73
    if (!cpu.flags.zf)
    {
        goto L_0x00438c73;
    }
    // 00438c6b  89751c                 -mov dword ptr [ebp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00438c6e  897518                 -mov dword ptr [ebp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00438c71  eb32                   -jmp 0x438ca5
    goto L_0x00438ca5;
L_0x00438c73:
    // 00438c73  8d4d18                 -lea ecx, [ebp + 0x18]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x00438c76:
    // 00438c76  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c78  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00438c7a  7429                   -je 0x438ca5
    if (cpu.flags.zf)
    {
        goto L_0x00438ca5;
    }
    // 00438c7c  8d5710                 -lea edx, [edi + 0x10]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00438c7f  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00438c82  e889560b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00438c87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c89  7d08                   -jge 0x438c93
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00438c93;
    }
    // 00438c8b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c8d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00438c8f  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 00438c91  eb12                   -jmp 0x438ca5
    goto L_0x00438ca5;
L_0x00438c93:
    // 00438c93  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c95  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00438c97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438c99  75db                   -jne 0x438c76
    if (!cpu.flags.zf)
    {
        goto L_0x00438c76;
    }
    // 00438c9b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00438c9d  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438ca0  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 00438ca2  89751c                 -mov dword ptr [ebp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.esi;
L_0x00438ca5:
    // 00438ca5  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ca8  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00438cab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cad  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438cb0  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00438cb2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cb3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cb4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00438cb6  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438cb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cbd  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_438cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438cc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438cc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438cc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438cc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438cc6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438cc9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438ccb  837d1400               +cmp dword ptr [ebp + 0x14], 0
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
    // 00438ccf  7508                   -jne 0x438cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00438cd9;
    }
    // 00438cd1  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438cd4  8d751c                 -lea esi, [ebp + 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438cd7  eb32                   -jmp 0x438d0b
    goto L_0x00438d0b;
L_0x00438cd9:
    // 00438cd9  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00438cdc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00438cde  751a                   -jne 0x438cfa
    if (!cpu.flags.zf)
    {
        goto L_0x00438cfa;
    }
    // 00438ce0  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ce3  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00438ce6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438ce7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438ce8  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ceb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438ced  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438cef  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438cf1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438cf3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438cf7  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00438cfa:
    // 00438cfa  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00438cfd  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00438d00  8d7df8                 -lea edi, [ebp - 8]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d03  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00438d05  8d7514                 -lea esi, [ebp + 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00438d08  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00438d0b:
    // 00438d0b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d0c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d0d  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d10  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438d12  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438d16  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438d18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d1c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_438d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438d21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438d22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438d24  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438d26  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438d29  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438d2b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00438d2e:
    // 00438d2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438d30  740f                   -je 0x438d41
    if (cpu.flags.zf)
    {
        goto L_0x00438d41;
    }
    // 00438d32  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00438d34  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00438d36  7505                   -jne 0x438d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00438d3d;
    }
    // 00438d38  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00438d3b  eb04                   -jmp 0x438d41
    goto L_0x00438d41;
L_0x00438d3d:
    // 00438d3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00438d3f  ebed                   -jmp 0x438d2e
    goto L_0x00438d2e;
L_0x00438d41:
    // 00438d41  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d44  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438d46  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d47  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438d48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438d4a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438d4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438d50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438d61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438d62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438d63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438d65  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438d67  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438d6a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438d6c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438d6e  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438d74  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438d77  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438d7a:
    // 00438d7a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438d7c  7431                   -je 0x438daf
    if (cpu.flags.zf)
    {
        goto L_0x00438daf;
    }
    // 00438d7e  8a9e80030000           -mov bl, byte ptr [esi + 0x380]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(896) /* 0x380 */);
    // 00438d84  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438d86  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00438d89  7420                   -je 0x438dab
    if (cpu.flags.zf)
    {
        goto L_0x00438dab;
    }
    // 00438d8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438d8d  e87efeffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438d92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438d93  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438d96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438d97  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438d9b  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438d9e  e8adfeffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438da3  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438da9  ebcf                   -jmp 0x438d7a
    goto L_0x00438d7a;
L_0x00438dab:
    // 00438dab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438dad  ebcb                   -jmp 0x438d7a
    goto L_0x00438d7a;
L_0x00438daf:
    // 00438daf  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438db2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438db4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438db5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438db6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438db8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438dba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438dbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_438dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438dc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438dc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438dc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438dc3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438dc4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438dc6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438dc9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438dcb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438dcd  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438dd3  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438dd6  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438dd9:
    // 00438dd9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438ddb  7434                   -je 0x438e11
    if (cpu.flags.zf)
    {
        goto L_0x00438e11;
    }
    // 00438ddd  8bbe88030000           -mov edi, dword ptr [esi + 0x388]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(904) /* 0x388 */);
    // 00438de3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438de5  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438deb  7520                   -jne 0x438e0d
    if (!cpu.flags.zf)
    {
        goto L_0x00438e0d;
    }
    // 00438ded  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438def  e81cfeffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438df4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438df5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438df8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438df9  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438dfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438dfd  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e00  e84bfeffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438e05  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e0b  ebcc                   -jmp 0x438dd9
    goto L_0x00438dd9;
L_0x00438e0d:
    // 00438e0d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438e0f  ebc8                   -jmp 0x438dd9
    goto L_0x00438dd9;
L_0x00438e11:
    // 00438e11  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e14  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438e16  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438e1a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438e1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_438e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438e32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438e33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438e34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438e35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438e37  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00438e3a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00438e3c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00438e3e  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e44  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 00438e47  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x00438e4a:
    // 00438e4a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00438e4c  7444                   -je 0x438e92
    if (cpu.flags.zf)
    {
        goto L_0x00438e92;
    }
    // 00438e4e  8bbe88030000           -mov edi, dword ptr [esi + 0x388]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(904) /* 0x388 */);
    // 00438e54  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00438e56  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438e5c  7430                   -je 0x438e8e
    if (cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e5e  8a9e80030000           -mov bl, byte ptr [esi + 0x380]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(896) /* 0x380 */);
    // 00438e64  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00438e67  7525                   -jne 0x438e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e69  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00438e6c  7520                   -jne 0x438e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00438e8e;
    }
    // 00438e6e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00438e70  e89bfdffff             -call 0x438c10
    cpu.esp -= 4;
    sub_438c10(app, cpu);
    if (cpu.terminate) return;
    // 00438e75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438e76  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438e79  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438e7a  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438e7e  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e81  e8cafdffff             -call 0x438c50
    cpu.esp -= 4;
    sub_438c50(app, cpu);
    if (cpu.terminate) return;
    // 00438e86  8b35704f5500           -mov esi, dword ptr [0x554f70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438e8c  ebbc                   -jmp 0x438e4a
    goto L_0x00438e4a;
L_0x00438e8e:
    // 00438e8e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00438e90  ebb8                   -jmp 0x438e4a
    goto L_0x00438e4a;
L_0x00438e92:
    // 00438e92  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438e95  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00438e97  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e98  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00438e99  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00438e9b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438e9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438e9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438ea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_438eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438eb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438eb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438eb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438eb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438eb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438eb6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438eb8  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00438ebb  e8300b0000             -call 0x4399f0
    cpu.esp -= 4;
    sub_4399f0(app, cpu);
    if (cpu.terminate) return;
    // 00438ec0  833d704f550000         +cmp dword ptr [0x554f70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00438ec7  7475                   -je 0x438f3e
    if (cpu.flags.zf)
    {
        goto L_0x00438f3e;
    }
    // 00438ec9  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438ecc  e85fffffff             -call 0x438e30
    cpu.esp -= 4;
    sub_438e30(app, cpu);
    if (cpu.terminate) return;
    // 00438ed1  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00438ed4  e887feffff             -call 0x438d60
    cpu.esp -= 4;
    sub_438d60(app, cpu);
    if (cpu.terminate) return;
    // 00438ed9  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00438edc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438edd  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00438ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438ee1  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438ee4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438ee5  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438ee8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438ee9  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438eec  e8cffdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438ef1  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438ef4  e8c7feffff             -call 0x438dc0
    cpu.esp -= 4;
    sub_438dc0(app, cpu);
    if (cpu.terminate) return;
    // 00438ef9  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00438efc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438efd  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00438f00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438f01  8b4de4                 -mov ecx, dword ptr [ebp - 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438f04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438f05  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438f09  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f0c  e8affdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438f11  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00438f14  a1704f5500             -mov eax, dword ptr [0x554f70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00438f19  e802feffff             -call 0x438d20
    cpu.esp -= 4;
    sub_438d20(app, cpu);
    if (cpu.terminate) return;
    // 00438f1e  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00438f21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438f22  8b7de8                 -mov edi, dword ptr [ebp - 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00438f25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438f26  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00438f29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00438f2a  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f2d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00438f2e  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f31  e88afdffff             -call 0x438cc0
    cpu.esp -= 4;
    sub_438cc0(app, cpu);
    if (cpu.terminate) return;
    // 00438f36  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00438f39  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
L_0x00438f3e:
    // 00438f3e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00438f40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_438f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00438f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438f61  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438f62  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438f64  e8e70a0000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00438f69  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438f6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438f6d  7443                   -je 0x438fb2
    if (cpu.flags.zf)
    {
        goto L_0x00438fb2;
    }
    // 00438f6f  83fa03                 +cmp edx, 3
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
    // 00438f72  773c                   -ja 0x438fb0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00438fb0;
    }
    // 00438f74  ff2495488f4300         -jmp dword ptr [edx*4 + 0x438f48]
    cpu.ip = app->getMemory<x86::reg32>(4427592 + cpu.edx * 4); goto dynamic_jump;
  case 0x00438f7b:
    // 00438f7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00438f7d  8a818f030000           -mov al, byte ptr [ecx + 0x38f]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(911) /* 0x38f */);
    // 00438f83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f85  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438f86:
    // 00438f86  8a8090030000           -mov al, byte ptr [eax + 0x390]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(912) /* 0x390 */);
    // 00438f8c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438f91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438f93  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438f94:
    // 00438f94  8a8091030000           -mov al, byte ptr [eax + 0x391]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(913) /* 0x391 */);
    // 00438f9a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438f9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fa1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00438fa2:
    // 00438fa2  8a8092030000           -mov al, byte ptr [eax + 0x392]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(914) /* 0x392 */);
    // 00438fa8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00438fad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438faf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00438fb0:
    // 00438fb0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00438fb2:
    // 00438fb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00438fb4  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_438fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00438fc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00438fc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00438fc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00438fc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00438fc4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00438fc5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00438fc7  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00438fca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00438fcc  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00438fcf  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00438fd2  e8a9faffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00438fd7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00438fd9:
    // 00438fd9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00438fdb  0f8454000000           -je 0x439035
    if (cpu.flags.zf)
    {
        goto L_0x00439035;
    }
    // 00438fe1  051c030000             -add eax, 0x31c
    (cpu.eax) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 00438fe6  e8a5090000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00438feb  e840070000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 00438ff0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00438ff2  83f801                 +cmp eax, 1
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
    // 00438ff5  7209                   -jb 0x439000
    if (cpu.flags.cf)
    {
        goto L_0x00439000;
    }
    // 00438ff7  7617                   -jbe 0x439010
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439010;
    }
    // 00438ff9  83f802                 +cmp eax, 2
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
    // 00438ffc  741e                   -je 0x43901c
    if (cpu.flags.zf)
    {
        goto L_0x0043901c;
    }
    // 00438ffe  eb26                   -jmp 0x439026
    goto L_0x00439026;
L_0x00439000:
    // 00439000  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439002  7522                   -jne 0x439026
    if (!cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439004  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00439007  741d                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439009  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043900e  eb16                   -jmp 0x439026
    goto L_0x00439026;
L_0x00439010:
    // 00439010  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00439013  7411                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439015  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043901a  eb0a                   -jmp 0x439026
    goto L_0x00439026;
L_0x0043901c:
    // 0043901c  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0043901f  7405                   -je 0x439026
    if (cpu.flags.zf)
    {
        goto L_0x00439026;
    }
    // 00439021  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00439026:
    // 00439026  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439028  7401                   -je 0x43902b
    if (cpu.flags.zf)
    {
        goto L_0x0043902b;
    }
    // 0043902a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x0043902b:
    // 0043902b  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043902e  e86dfaffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439033  eba4                   -jmp 0x438fd9
    goto L_0x00438fd9;
L_0x00439035:
    // 00439035  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0043903c  8d7808                 -lea edi, [eax + 8]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043903f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439041  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439046  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00439048  e8d3850a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0043904d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0043904f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439051  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439054  e8e7750a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00439059  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043905c  e81ffaffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00439061  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00439063:
    // 00439063  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439065  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439067  0f846a000000           -je 0x4390d7
    if (cpu.flags.zf)
    {
        goto L_0x004390d7;
    }
    // 0043906d  8d831c030000           -lea eax, [ebx + 0x31c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(796) /* 0x31c */);
    // 00439073  e818090000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439078  e8b3060000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043907d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043907f  83f801                 +cmp eax, 1
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
    // 00439082  7209                   -jb 0x43908d
    if (cpu.flags.cf)
    {
        goto L_0x0043908d;
    }
    // 00439084  7617                   -jbe 0x43909d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043909d;
    }
    // 00439086  83f802                 +cmp eax, 2
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
    // 00439089  741e                   -je 0x4390a9
    if (cpu.flags.zf)
    {
        goto L_0x004390a9;
    }
    // 0043908b  eb26                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x0043908d:
    // 0043908d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043908f  7522                   -jne 0x4390b3
    if (!cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 00439091  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00439094  741d                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 00439096  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043909b  eb16                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x0043909d:
    // 0043909d  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004390a0  7411                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 004390a2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004390a7  eb0a                   -jmp 0x4390b3
    goto L_0x004390b3;
L_0x004390a9:
    // 004390a9  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004390ac  7405                   -je 0x4390b3
    if (cpu.flags.zf)
    {
        goto L_0x004390b3;
    }
    // 004390ae  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004390b3:
    // 004390b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004390b5  7416                   -je 0x4390cd
    if (cpu.flags.zf)
    {
        goto L_0x004390cd;
    }
    // 004390b7  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004390ba  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004390c1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004390c3  83c310                 +add ebx, 0x10
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004390c6  c6400400               -mov byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004390ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004390cb  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
L_0x004390cd:
    // 004390cd  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004390d0  e8cbf9ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 004390d5  eb8c                   -jmp 0x439063
    goto L_0x00439063;
L_0x004390d7:
    // 004390d7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004390da  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004390dc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004390df  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004390e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004390e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4390f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004390f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004390f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004390f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004390f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004390f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004390f5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004390f7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004390fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004390fc  e84f090000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439101  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439103  0f84b1000000           -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 00439109  f6808003000008         +test byte ptr [eax + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439110  0f85a2000000           -jne 0x4391b8
    if (!cpu.flags.zf)
    {
        goto L_0x004391b8;
    }
    // 00439116  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439118  e8f3040000             -call 0x439610
    cpu.esp -= 4;
    sub_439610(app, cpu);
    if (cpu.terminate) return;
    // 0043911d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043911f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439121  e85a050000             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 00439126  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439128  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043912a  e8b1040000             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043912f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439131  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439134  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439136  e8f5050000             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 0043913b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043913d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439142  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00439145  7406                   -je 0x43914d
    if (cpu.flags.zf)
    {
        goto L_0x0043914d;
    }
    // 00439147  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439149  7502                   -jne 0x43914d
    if (!cpu.flags.zf)
    {
        goto L_0x0043914d;
    }
    // 0043914b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043914d:
    // 0043914d  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00439150  7408                   -je 0x43915a
    if (cpu.flags.zf)
    {
        goto L_0x0043915a;
    }
    // 00439152  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439156  7402                   -je 0x43915a
    if (cpu.flags.zf)
    {
        goto L_0x0043915a;
    }
    // 00439158  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043915a:
    // 0043915a  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0043915d  7406                   -je 0x439165
    if (cpu.flags.zf)
    {
        goto L_0x00439165;
    }
    // 0043915f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439161  7502                   -jne 0x439165
    if (!cpu.flags.zf)
    {
        goto L_0x00439165;
    }
    // 00439163  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439165:
    // 00439165  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00439168  7406                   -je 0x439170
    if (cpu.flags.zf)
    {
        goto L_0x00439170;
    }
    // 0043916a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043916c  7402                   -je 0x439170
    if (cpu.flags.zf)
    {
        goto L_0x00439170;
    }
    // 0043916e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439170:
    // 00439170  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00439173  7406                   -je 0x43917b
    if (cpu.flags.zf)
    {
        goto L_0x0043917b;
    }
    // 00439175  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00439177  7502                   -jne 0x43917b
    if (!cpu.flags.zf)
    {
        goto L_0x0043917b;
    }
    // 00439179  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043917b:
    // 0043917b  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 0043917e  7406                   -je 0x439186
    if (cpu.flags.zf)
    {
        goto L_0x00439186;
    }
    // 00439180  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00439182  7402                   -je 0x439186
    if (cpu.flags.zf)
    {
        goto L_0x00439186;
    }
    // 00439184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00439186:
    // 00439186  f7c200000080           +test edx, 0x80000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2147483648 /*0x80000000*/));
    // 0043918c  752c                   -jne 0x4391ba
    if (!cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 0043918e  f7c200000010           +test edx, 0x10000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 268435456 /*0x10000000*/));
    // 00439194  7406                   -je 0x43919c
    if (cpu.flags.zf)
    {
        goto L_0x0043919c;
    }
    // 00439196  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439198  7402                   -je 0x43919c
    if (cpu.flags.zf)
    {
        goto L_0x0043919c;
    }
    // 0043919a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043919c:
    // 0043919c  f7c200000020           +test edx, 0x20000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 536870912 /*0x20000000*/));
    // 004391a2  7407                   -je 0x4391ab
    if (cpu.flags.zf)
    {
        goto L_0x004391ab;
    }
    // 004391a4  83f901                 +cmp ecx, 1
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
    // 004391a7  7402                   -je 0x4391ab
    if (cpu.flags.zf)
    {
        goto L_0x004391ab;
    }
    // 004391a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004391ab:
    // 004391ab  f7c200000040           +test edx, 0x40000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1073741824 /*0x40000000*/));
    // 004391b1  7407                   -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
    // 004391b3  83f902                 +cmp ecx, 2
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
    // 004391b6  7402                   -je 0x4391ba
    if (cpu.flags.zf)
    {
        goto L_0x004391ba;
    }
L_0x004391b8:
    // 004391b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004391ba:
    // 004391ba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004391bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004391c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4391d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004391d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004391d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004391d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004391d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004391d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004391d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004391d7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004391da  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004391dd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004391df  e8ecf9ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 004391e4  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004391e7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004391ea  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004391ed  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004391ef  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 004391f4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004391f6  e825840a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004391fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004391fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004391ff:
    // 004391ff  3b4df8                 +cmp ecx, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439202  7d34                   -jge 0x439238
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439238;
    }
    // 00439204  f645fc01               +test byte ptr [ebp - 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 1 /*0x1*/));
    // 00439208  750e                   -jne 0x439218
    if (!cpu.flags.zf)
    {
        goto L_0x00439218;
    }
    // 0043920a  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043920d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043920f  e8dcfeffff             -call 0x4390f0
    cpu.esp -= 4;
    sub_4390f0(app, cpu);
    if (cpu.terminate) return;
    // 00439214  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439216  741d                   -je 0x439235
    if (cpu.flags.zf)
    {
        goto L_0x00439235;
    }
L_0x00439218:
    // 00439218  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043921a  e831080000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043921f  f6808003000008         +test byte ptr [eax + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439226  750d                   -jne 0x439235
    if (!cpu.flags.zf)
    {
        goto L_0x00439235;
    }
    // 00439228  43                     -inc ebx
    (cpu.ebx)++;
    // 00439229  83c010                 +add eax, 0x10
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043922c  c644defc00             -mov byte ptr [esi + ebx*8 - 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 8) = 0 /*0x0*/;
    // 00439231  8944def8               -mov dword ptr [esi + ebx*8 - 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ebx * 8) = cpu.eax;
L_0x00439235:
    // 00439235  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439236  ebc7                   -jmp 0x4391ff
    goto L_0x004391ff;
L_0x00439238:
    // 00439238  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043923a  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0043923c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043923e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043923f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439243  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439250  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439251  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439253  3df4010000             +cmp eax, 0x1f4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439258  7c10                   -jl 0x43926a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043926a;
    }
    // 0043925a  3d57020000             +cmp eax, 0x257
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043925f  7f09                   -jg 0x43926a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043926a;
    }
    // 00439261  8b048544c95500         -mov eax, dword ptr [eax*4 + 0x55c944]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5622084) /* 0x55c944 */ + cpu.eax * 4);
    // 00439268  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043926a:
    // 0043926a  83f832                 +cmp eax, 0x32
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
    // 0043926d  7c0e                   -jl 0x43927d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043927d;
    }
    // 0043926f  3df3010000             +cmp eax, 0x1f3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439274  7f07                   -jg 0x43927d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043927d;
    }
    // 00439276  b8804f5500             -mov eax, 0x554f80
    cpu.eax = 5590912 /*0x554f80*/;
    // 0043927b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043927c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043927d:
    // 0043927d  e8ce070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439282  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00439285  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439286  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439291  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439293  e8b8070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439298  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043929a  7405                   -je 0x4392a1
    if (cpu.flags.zf)
    {
        goto L_0x004392a1;
    }
    // 0043929c  0515030000             -add eax, 0x315
    (cpu.eax) += x86::reg32(x86::sreg32(789 /*0x315*/));
L_0x004392a1:
    // 004392a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4392b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004392b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004392b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004392b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004392b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004392b6  e895070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004392bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004392bd  7408                   -je 0x4392c7
    if (cpu.flags.zf)
    {
        goto L_0x004392c7;
    }
    // 004392bf  0510010000             -add eax, 0x110
    (cpu.eax) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 004392c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392c7:
    // 004392c7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004392ce  81faf3010000           +cmp edx, 0x1f3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004392d4  7f09                   -jg 0x4392df
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004392df;
    }
    // 004392d6  8b80b0cf5500           -mov eax, dword ptr [eax + 0x55cfb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5623728) /* 0x55cfb0 */);
    // 004392dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392df:
    // 004392df  81fa57020000           +cmp edx, 0x257
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004392e5  7f09                   -jg 0x4392f0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004392f0;
    }
    // 004392e7  8b802cc95500           -mov eax, dword ptr [eax + 0x55c92c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5622060) /* 0x55c92c */);
    // 004392ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004392f0:
    // 004392f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004392f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004392f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439301  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439302  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439304  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439306  e845070000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043930b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043930d  740a                   -je 0x439319
    if (cpu.flags.zf)
    {
        goto L_0x00439319;
    }
L_0x0043930f:
    // 0043930f  ba94765300             -mov edx, 0x537694
    cpu.edx = 5469844 /*0x537694*/;
    // 00439314  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439316  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439317  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439318  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439319:
    // 00439319  83fa32                 +cmp edx, 0x32
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
    // 0043931c  7c08                   -jl 0x439326
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439326;
    }
    // 0043931e  81faf3010000           +cmp edx, 0x1f3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(499 /*0x1f3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439324  7ee9                   -jle 0x43930f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043930f;
    }
L_0x00439326:
    // 00439326  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043932c  7c08                   -jl 0x439336
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439336;
    }
    // 0043932e  81fa57020000           +cmp edx, 0x257
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(599 /*0x257*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439334  7ed9                   -jle 0x43930f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043930f;
    }
L_0x00439336:
    // 00439336  81fa58020000           +cmp edx, 0x258
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043933c  7c14                   -jl 0x439352
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439352;
    }
    // 0043933e  81fabb020000           +cmp edx, 0x2bb
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(699 /*0x2bb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439344  7f0c                   -jg 0x439352
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00439352;
    }
    // 00439346  8b14955cc75500         -mov edx, dword ptr [edx*4 + 0x55c75c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5621596) /* 0x55c75c */ + cpu.edx * 4);
    // 0043934d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043934f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439350  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439351  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439352:
    // 00439352  ba90765300             -mov edx, 0x537690
    cpu.edx = 5469840 /*0x537690*/;
    // 00439357  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439359  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043935a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043935b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_439360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439362  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439363  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439364  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439365  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439367  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439369  e8e2060000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043936e  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439373  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439375  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00439377  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043937a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043937b:
    // 0043937b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043937d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043937f  3c00                   +cmp al, 0
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
    // 00439381  7410                   -je 0x439393
    if (cpu.flags.zf)
    {
        goto L_0x00439393;
    }
    // 00439383  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439386  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439389  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043938c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043938f  3c00                   +cmp al, 0
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
    // 00439391  75e8                   -jne 0x43937b
    if (!cpu.flags.zf)
    {
        goto L_0x0043937b;
    }
L_0x00439393:
    // 00439393  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439394  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439396  8db110010000           -lea esi, [ecx + 0x110]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 0043939c  e89fefffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 004393a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393a2  2bc9                   +sub ecx, ecx
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
    // 004393a4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393a5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393a7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393a9  4f                     -dec edi
    (cpu.edi)--;
L_0x004393aa:
    // 004393aa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393ac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004393ae  3c00                   +cmp al, 0
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
    // 004393b0  7410                   -je 0x4393c2
    if (cpu.flags.zf)
    {
        goto L_0x004393c2;
    }
    // 004393b2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004393b5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393b8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004393bb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393be  3c00                   +cmp al, 0
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
    // 004393c0  75e8                   -jne 0x4393aa
    if (!cpu.flags.zf)
    {
        goto L_0x004393aa;
    }
L_0x004393c2:
    // 004393c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004393c3  be98765300             -mov esi, 0x537698
    cpu.esi = 5469848 /*0x537698*/;
    // 004393c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393c9  2bc9                   +sub ecx, ecx
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
    // 004393cb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393cc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393ce  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393d0  4f                     -dec edi
    (cpu.edi)--;
L_0x004393d1:
    // 004393d1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393d3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004393d5  3c00                   +cmp al, 0
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
    // 004393d7  7410                   -je 0x4393e9
    if (cpu.flags.zf)
    {
        goto L_0x004393e9;
    }
    // 004393d9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004393dc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393df  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004393e2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004393e5  3c00                   +cmp al, 0
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
    // 004393e7  75e8                   -jne 0x4393d1
    if (!cpu.flags.zf)
    {
        goto L_0x004393d1;
    }
L_0x004393e9:
    // 004393e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004393ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004393ec  e80fffffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 004393f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004393f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004393f4  2bc9                   +sub ecx, ecx
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
    // 004393f6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004393f7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004393f9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004393fb  4f                     -dec edi
    (cpu.edi)--;
L_0x004393fc:
    // 004393fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004393fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439400  3c00                   +cmp al, 0
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
    // 00439402  7410                   -je 0x439414
    if (cpu.flags.zf)
    {
        goto L_0x00439414;
    }
    // 00439404  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439407  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043940a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043940d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439410  3c00                   +cmp al, 0
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
    // 00439412  75e8                   -jne 0x4393fc
    if (!cpu.flags.zf)
    {
        goto L_0x004393fc;
    }
L_0x00439414:
    // 00439414  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439415  be9c765300             -mov esi, 0x53769c
    cpu.esi = 5469852 /*0x53769c*/;
    // 0043941a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043941b  2bc9                   +sub ecx, ecx
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
    // 0043941d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043941e  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439420  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439422  4f                     -dec edi
    (cpu.edi)--;
L_0x00439423:
    // 00439423  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439425  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439427  3c00                   +cmp al, 0
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
    // 00439429  7410                   -je 0x43943b
    if (cpu.flags.zf)
    {
        goto L_0x0043943b;
    }
    // 0043942b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043942e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439431  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439434  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439437  3c00                   +cmp al, 0
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
    // 00439439  75e8                   -jne 0x439423
    if (!cpu.flags.zf)
    {
        goto L_0x00439423;
    }
L_0x0043943b:
    // 0043943b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043943f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439440  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439441  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_439450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439452  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439454  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439455  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439457  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00439459  e8f2050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043945e  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439463  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439465  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00439467  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0043946a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043946b:
    // 0043946b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043946d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043946f  3c00                   +cmp al, 0
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
    // 00439471  7410                   -je 0x439483
    if (cpu.flags.zf)
    {
        goto L_0x00439483;
    }
    // 00439473  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439476  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439479  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043947c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043947f  3c00                   +cmp al, 0
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
    // 00439481  75e8                   -jne 0x43946b
    if (!cpu.flags.zf)
    {
        goto L_0x0043946b;
    }
L_0x00439483:
    // 00439483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439484  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439486  8db110010000           -lea esi, [ecx + 0x110]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(272) /* 0x110 */);
    // 0043948c  e8afeeffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00439491  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439492  2bc9                   +sub ecx, ecx
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
    // 00439494  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439495  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439497  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439499  4f                     -dec edi
    (cpu.edi)--;
L_0x0043949a:
    // 0043949a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043949c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043949e  3c00                   +cmp al, 0
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
    // 004394a0  7410                   -je 0x4394b2
    if (cpu.flags.zf)
    {
        goto L_0x004394b2;
    }
    // 004394a2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394a5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394a8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394ab  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394ae  3c00                   +cmp al, 0
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
    // 004394b0  75e8                   -jne 0x43949a
    if (!cpu.flags.zf)
    {
        goto L_0x0043949a;
    }
L_0x004394b2:
    // 004394b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004394b3  be98765300             -mov esi, 0x537698
    cpu.esi = 5469848 /*0x537698*/;
    // 004394b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004394b9  2bc9                   +sub ecx, ecx
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
    // 004394bb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004394bc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004394be  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004394c0  4f                     -dec edi
    (cpu.edi)--;
L_0x004394c1:
    // 004394c1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004394c3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004394c5  3c00                   +cmp al, 0
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
    // 004394c7  7410                   -je 0x4394d9
    if (cpu.flags.zf)
    {
        goto L_0x004394d9;
    }
    // 004394c9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394cc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394cf  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394d2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394d5  3c00                   +cmp al, 0
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
    // 004394d7  75e8                   -jne 0x4394c1
    if (!cpu.flags.zf)
    {
        goto L_0x004394c1;
    }
L_0x004394d9:
    // 004394d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004394da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004394dc  e81ffeffff             -call 0x439300
    cpu.esp -= 4;
    sub_439300(app, cpu);
    if (cpu.terminate) return;
    // 004394e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004394e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004394e4  2bc9                   +sub ecx, ecx
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
    // 004394e6  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004394e7  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004394e9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004394eb  4f                     -dec edi
    (cpu.edi)--;
L_0x004394ec:
    // 004394ec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004394ee  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004394f0  3c00                   +cmp al, 0
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
    // 004394f2  7410                   -je 0x439504
    if (cpu.flags.zf)
    {
        goto L_0x00439504;
    }
    // 004394f4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004394f7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004394fa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004394fd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439500  3c00                   +cmp al, 0
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
    // 00439502  75e8                   -jne 0x4394ec
    if (!cpu.flags.zf)
    {
        goto L_0x004394ec;
    }
L_0x00439504:
    // 00439504  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439505  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439506  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439507  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439508  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439509  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043950a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_439510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439511  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439513  e838050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439518  0594030000             -add eax, 0x394
    (cpu.eax) += x86::reg32(x86::sreg32(916 /*0x394*/));
    // 0043951d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043951e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439520  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439521  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439523  e828050000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439528  051c030000             -add eax, 0x31c
    (cpu.eax) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 0043952d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043952e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439530  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439531  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439532  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439534  e857040000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439539  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043953b  e830000000             -call 0x439570
    cpu.esp -= 4;
    sub_439570(app, cpu);
    if (cpu.terminate) return;
    // 00439540  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439542  7405                   -je 0x439549
    if (cpu.flags.zf)
    {
        goto L_0x00439549;
    }
    // 00439544  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439546  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439547  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439548  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439549:
    // 00439549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043954b  e830010000             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 00439550  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439552  7405                   -je 0x439559
    if (cpu.flags.zf)
    {
        goto L_0x00439559;
    }
    // 00439554  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439556  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439557  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439559:
    // 00439559  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043955e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043955f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439560  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439570  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439571  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439573  e8d8040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439578  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 0043957e  83e040                 -and eax, 0x40
    cpu.eax &= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00439581  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439582  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439590  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439591  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439593  e8f8030000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439598  e8d3ffffff             -call 0x439570
    cpu.esp -= 4;
    sub_439570(app, cpu);
    if (cpu.terminate) return;
    // 0043959d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043959e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4395a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395a3  e8a8040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395a8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ae  83e008                 -and eax, 8
    cpu.eax &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004395b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4395c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395c3  e888040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395c8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ce  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004395d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4395e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004395e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004395e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004395e3  e868040000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004395e8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004395ee  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004395f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004395f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439600  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439601  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439603  e888030000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439608  e8d3ffffff             -call 0x4395e0
    cpu.esp -= 4;
    sub_4395e0(app, cpu);
    if (cpu.terminate) return;
    // 0043960d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043960e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439610  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439611  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439613  e808ffffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439618  e803000000             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 0043961d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043961e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439621  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439622  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439624  6683780400             +cmp word ptr [eax + 4], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00439629  7524                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 0043962b  6683780600             +cmp word ptr [eax + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00439630  751d                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 00439632  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439635  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439638  7515                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 0043963a  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0043963d  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439640  750d                   -jne 0x43964f
    if (!cpu.flags.zf)
    {
        goto L_0x0043964f;
    }
    // 00439642  833832                 +cmp dword ptr [eax], 0x32
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439645  7308                   -jae 0x43964f
    if (!cpu.flags.cf)
    {
        goto L_0x0043964f;
    }
    // 00439647  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043964c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043964d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043964e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043964f:
    // 0043964f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439651  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439652  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439653  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439660  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439661  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439662  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439664  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439666  e8b5ffffff             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 0043966b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043966d  7508                   -jne 0x439677
    if (!cpu.flags.zf)
    {
        goto L_0x00439677;
    }
    // 0043966f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439674  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439675  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439676  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439677:
    // 00439677  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00439679  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043967a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043967b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_439680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439680  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439681  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439683  e8c8030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439688  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 0043968e  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00439691  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4396a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396a3  e8e8020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 004396a8  e8d3ffffff             -call 0x439680
    cpu.esp -= 4;
    sub_439680(app, cpu);
    if (cpu.terminate) return;
    // 004396ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4396b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396b1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396b3  e898030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004396b8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004396be  83e010                 -and eax, 0x10
    cpu.eax &= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004396c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4396d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396d3  e8b8020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 004396d8  e8d3ffffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 004396dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4396e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004396e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004396e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004396e3  e868030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004396e8  8b8080030000           -mov eax, dword ptr [eax + 0x380]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(896) /* 0x380 */);
    // 004396ee  83e020                 -and eax, 0x20
    cpu.eax &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004396f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004396f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439700  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439701  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439703  e888020000             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439708  e8d3ffffff             -call 0x4396e0
    cpu.esp -= 4;
    sub_4396e0(app, cpu);
    if (cpu.terminate) return;
    // 0043970d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043970e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439710  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439711  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439713  e838030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439718  8a80a0030000           -mov al, byte ptr [eax + 0x3a0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(928) /* 0x3a0 */);
    // 0043971e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00439723  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439731  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439733  e818030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439738  8b8088030000           -mov eax, dword ptr [eax + 0x388]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(904) /* 0x388 */);
    // 0043973e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043973f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439740  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439741  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439743  e808030000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439748  8b8084030000           -mov eax, dword ptr [eax + 0x384]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(900) /* 0x384 */);
    // 0043974e  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00439751  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439752  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439760  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439761  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439763  e8e8020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439768  8b8034030000           -mov eax, dword ptr [eax + 0x334]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(820) /* 0x334 */);
    // 0043976e  40                     -inc eax
    (cpu.eax)++;
    // 0043976f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439770  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439780  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439781  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439783  e8d8ffffff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00439788  48                     -dec eax
    (cpu.eax)--;
    // 00439789  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043978a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_439790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439790  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439791  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439793  e8b8020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439798  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043979a  7405                   -je 0x4397a1
    if (cpu.flags.zf)
    {
        goto L_0x004397a1;
    }
    // 0043979c  83fa01                 +cmp edx, 1
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
    // 0043979f  7509                   -jne 0x4397aa
    if (!cpu.flags.zf)
    {
        goto L_0x004397aa;
    }
L_0x004397a1:
    // 004397a1  8b84902c030000         -mov eax, dword ptr [eax + edx*4 + 0x32c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(812) /* 0x32c */ + cpu.edx * 4);
    // 004397a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004397aa:
    // 004397aa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004397af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4397c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004397c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004397c1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004397c3  83c21e                 -add edx, 0x1e
    (cpu.edx) += x86::reg32(x86::sreg32(30 /*0x1e*/));
    // 004397c6  e8e5020000             -call 0x439ab0
    cpu.esp -= 4;
    sub_439ab0(app, cpu);
    if (cpu.terminate) return;
    // 004397cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004397cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4397d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004397d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004397d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004397d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004397d3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004397d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004397d7  e874020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004397dc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004397de  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004397e0  7405                   -je 0x4397e7
    if (cpu.flags.zf)
    {
        goto L_0x004397e7;
    }
    // 004397e2  83fa01                 +cmp edx, 1
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
    // 004397e5  751f                   -jne 0x439806
    if (!cpu.flags.zf)
    {
        goto L_0x00439806;
    }
L_0x004397e7:
    // 004397e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004397e9  899c962c030000         -mov dword ptr [esi + edx*4 + 0x32c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(812) /* 0x32c */ + cpu.edx * 4) = cpu.ebx;
    // 004397f0  e8fb1f0000             -call 0x43b7f0
    cpu.esp -= 4;
    sub_43b7f0(app, cpu);
    if (cpu.terminate) return;
    // 004397f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004397f7  e8648b0300             -call 0x472360
    cpu.esp -= 4;
    sub_472360(app, cpu);
    if (cpu.terminate) return;
    // 004397fc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004397fe  7506                   -jne 0x439806
    if (!cpu.flags.zf)
    {
        goto L_0x00439806;
    }
    // 00439800  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439803  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439804  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439805  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439806:
    // 00439806  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043980b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043980e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439810  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439811  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439812  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439813  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439815  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439817  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00439819  e832020000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043981e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439820  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439822  e839ffffff             -call 0x439760
    cpu.esp -= 4;
    sub_439760(app, cpu);
    if (cpu.terminate) return;
    // 00439827  39c2                   +cmp edx, eax
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
    // 00439829  7e0a                   -jle 0x439835
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439835;
    }
    // 0043982b  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00439830  e979000000             -jmp 0x4398ae
    goto L_0x004398ae;
L_0x00439835:
    // 00439835  48                     -dec eax
    (cpu.eax)--;
    // 00439836  39c2                   +cmp edx, eax
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
    // 00439838  7543                   -jne 0x43987d
    if (!cpu.flags.zf)
    {
        goto L_0x0043987d;
    }
    // 0043983a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043983c  7c05                   -jl 0x439843
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00439843;
    }
    // 0043983e  83fb01                 +cmp ebx, 1
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
    // 00439841  7e0d                   -jle 0x439850
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439850;
    }
L_0x00439843:
    // 00439843  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00439848  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043984a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043984d  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00439850:
    // 00439850  8a849978030000         -mov al, byte ptr [ecx + ebx*4 + 0x378]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(888) /* 0x378 */ + cpu.ebx * 4);
    // 00439857  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439859  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043985c  8a849979030000         -mov al, byte ptr [ecx + ebx*4 + 0x379]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(889) /* 0x379 */ + cpu.ebx * 4);
    // 00439863  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439865  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00439868  8a84997a030000         -mov al, byte ptr [ecx + ebx*4 + 0x37a]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(890) /* 0x37a */ + cpu.ebx * 4);
    // 0043986f  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439871  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00439874  8a84997b030000         -mov al, byte ptr [ecx + ebx*4 + 0x37b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(891) /* 0x37b */ + cpu.ebx * 4);
    // 0043987b  eb2d                   -jmp 0x4398aa
    goto L_0x004398aa;
L_0x0043987d:
    // 0043987d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00439880  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 00439883  8a8338030000           -mov al, byte ptr [ebx + 0x338]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(824) /* 0x338 */);
    // 00439889  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043988b  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0043988e  8a8339030000           -mov al, byte ptr [ebx + 0x339]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(825) /* 0x339 */);
    // 00439894  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00439896  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00439899  8a833a030000           -mov al, byte ptr [ebx + 0x33a]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(826) /* 0x33a */);
    // 0043989f  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004398a1  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004398a4  8a833b030000           -mov al, byte ptr [ebx + 0x33b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(827) /* 0x33b */);
L_0x004398aa:
    // 004398aa  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004398ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004398ae:
    // 004398ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004398b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398b3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4398c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004398c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004398c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004398c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004398c4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004398c6  e885010000             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 004398cb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004398cd  7c05                   -jl 0x4398d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004398d4;
    }
    // 004398cf  83fa01                 +cmp edx, 1
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
    // 004398d2  7e0a                   -jle 0x4398de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004398de;
    }
L_0x004398d4:
    // 004398d4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004398d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004398db  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004398de:
    // 004398de  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004398e1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004398e3  889878030000           -mov byte ptr [eax + 0x378], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(888) /* 0x378 */) = cpu.bl;
    // 004398e9  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004398ec  888879030000           -mov byte ptr [eax + 0x379], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(889) /* 0x379 */) = cpu.cl;
    // 004398f2  88907a030000           -mov byte ptr [eax + 0x37a], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(890) /* 0x37a */) = cpu.dl;
    // 004398f8  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004398fb  88907b030000           -mov byte ptr [eax + 0x37b], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(891) /* 0x37b */) = cpu.dl;
    // 00439901  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439903  e8e81e0000             -call 0x43b7f0
    cpu.esp -= 4;
    sub_43b7f0(app, cpu);
    if (cpu.terminate) return;
    // 00439908  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043990a  740a                   -je 0x439916
    if (cpu.flags.zf)
    {
        goto L_0x00439916;
    }
    // 0043990c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439911  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439912  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439913  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00439916:
    // 00439916  e8458a0300             -call 0x472360
    cpu.esp -= 4;
    sub_472360(app, cpu);
    if (cpu.terminate) return;
    // 0043991b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043991d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043991e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043991f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_439930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439930  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439931  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439933  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439935  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439936  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439940  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439941  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439943  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439945  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439946  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439950  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439951  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439953  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439956  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439960  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439961  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439963  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439965  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439971  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439973  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439975  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439976  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439980  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439981  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439983  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439985  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439991  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439992  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439993  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439994  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439995  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439996  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439998  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043999b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043999d  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004399a0  e8dbf0ffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 004399a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004399a7:
    // 004399a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004399a9  742b                   -je 0x4399d6
    if (cpu.flags.zf)
    {
        goto L_0x004399d6;
    }
    // 004399ab  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004399b0  8db81c030000           -lea edi, [eax + 0x31c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(796) /* 0x31c */);
    // 004399b6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004399b8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004399ba  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 004399bc  7405                   -je 0x4399c3
    if (cpu.flags.zf)
    {
        goto L_0x004399c3;
    }
    // 004399be  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004399c0  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x004399c3:
    // 004399c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004399c5  7504                   -jne 0x4399cb
    if (!cpu.flags.zf)
    {
        goto L_0x004399cb;
    }
    // 004399c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004399c9  eb10                   -jmp 0x4399db
    goto L_0x004399db;
L_0x004399cb:
    // 004399cb  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004399ce  e8cdf0ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 004399d3  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004399d4  ebd1                   -jmp 0x4399a7
    goto L_0x004399a7;
L_0x004399d6:
    // 004399d6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004399db:
    // 004399db  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004399dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004399e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4399f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004399f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004399f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004399f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004399f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004399f5  bbc8000000             -mov ebx, 0xc8
    cpu.ebx = 200 /*0xc8*/;
    // 004399fa  b8003c5f00             -mov eax, 0x5f3c00
    cpu.eax = 6241280 /*0x5f3c00*/;
    // 004399ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439a01  e83a6c0a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00439a06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439a10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439a11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439a12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439a14  8b1485844f5500         -mov edx, dword ptr [eax*4 + 0x554f84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590916) /* 0x554f84 */ + cpu.eax * 4);
    // 00439a1b  b8c0d26f00             -mov eax, 0x6fd2c0
    cpu.eax = 7328448 /*0x6fd2c0*/;
    // 00439a20  e8abf0ffff             -call 0x438ad0
    cpu.esp -= 4;
    sub_438ad0(app, cpu);
    if (cpu.terminate) return;
    // 00439a25  b8c0d26f00             -mov eax, 0x6fd2c0
    cpu.eax = 7328448 /*0x6fd2c0*/;
    // 00439a2a  e861ffffff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439a2f  a3bcd26f00             -mov dword ptr [0x6fd2bc], eax
    app->getMemory<x86::reg32>(x86::reg32(7328444) /* 0x6fd2bc */) = cpu.eax;
    // 00439a34  e8f7fcffff             -call 0x439730
    cpu.esp -= 4;
    sub_439730(app, cpu);
    if (cpu.terminate) return;
    // 00439a39  a3d0d26f00             -mov dword ptr [0x6fd2d0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328464) /* 0x6fd2d0 */) = cpu.eax;
    // 00439a3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_439a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439a52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439a53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439a54  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439a56  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439a59  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00439a5b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439a5d  83f831                 +cmp eax, 0x31
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439a60  7e04                   -jle 0x439a66
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439a66;
    }
    // 00439a62  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439a64  eb38                   -jmp 0x439a9e
    goto L_0x00439a9e;
L_0x00439a66:
    // 00439a66  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00439a69  8b98003c5f00           -mov ebx, dword ptr [eax + 0x5f3c00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6241280) /* 0x5f3c00 */);
    // 00439a6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00439a71  7409                   -je 0x439a7c
    if (cpu.flags.zf)
    {
        goto L_0x00439a7c;
    }
    // 00439a73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439a75  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439a77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439a7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439a7c:
    // 00439a7c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439a7f  e8fcefffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
L_0x00439a84:
    // 00439a84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439a86  740f                   -je 0x439a97
    if (cpu.flags.zf)
    {
        goto L_0x00439a97;
    }
    // 00439a88  39d1                   +cmp ecx, edx
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
    // 00439a8a  740b                   -je 0x439a97
    if (cpu.flags.zf)
    {
        goto L_0x00439a97;
    }
    // 00439a8c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439a8f  e80cf0ffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439a94  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439a95  ebed                   -jmp 0x439a84
    goto L_0x00439a84;
L_0x00439a97:
    // 00439a97  890495003c5f00         -mov dword ptr [edx*4 + 0x5f3c00], eax
    app->getMemory<x86::reg32>(x86::reg32(6241280) /* 0x5f3c00 */ + cpu.edx * 4) = cpu.eax;
L_0x00439a9e:
    // 00439a9e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439aa0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_439ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439ab1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439ab2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439ab4  e897ffffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439ab9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439abb  7508                   -jne 0x439ac5
    if (!cpu.flags.zf)
    {
        goto L_0x00439ac5;
    }
    // 00439abd  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439ac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ac4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ac5:
    // 00439ac5  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00439ac8  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00439acb  49                     -dec ecx
    (cpu.ecx)--;
    // 00439acc  39ca                   +cmp edx, ecx
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
    // 00439ace  7e08                   -jle 0x439ad8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439ad8;
    }
    // 00439ad0  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439ad5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ad6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ad7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ad8:
    // 00439ad8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439adb  e810000000             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 00439ae0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ae1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ae2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439af0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439af1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439af2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439af4  0fbf08                 -movsx ecx, word ptr [eax]
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 00439af7  49                     -dec ecx
    (cpu.ecx)--;
    // 00439af8  39ca                   +cmp edx, ecx
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
    // 00439afa  7e05                   -jle 0x439b01
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00439b01;
    }
    // 00439afc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439afe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439aff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439b01:
    // 00439b01  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00439b08  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439b0b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00439b0e  030411                 -add eax, dword ptr [ecx + edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1)));
    // 00439b11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_439b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439b20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439b21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439b22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439b23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439b24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439b25  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439b27  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439b2a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439b2c  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439b2f  e84cefffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
    // 00439b34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00439b36:
    // 00439b36  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439b38  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439b3a  7419                   -je 0x439b55
    if (cpu.flags.zf)
    {
        goto L_0x00439b55;
    }
    // 00439b3c  8d5110                 -lea edx, [ecx + 0x10]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00439b3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439b41  e8ca470b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00439b46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439b48  740b                   -je 0x439b55
    if (cpu.flags.zf)
    {
        goto L_0x00439b55;
    }
    // 00439b4a  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439b4d  e84eefffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439b52  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439b53  ebe1                   -jmp 0x439b36
    goto L_0x00439b36;
L_0x00439b55:
    // 00439b55  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439b57  7404                   -je 0x439b5d
    if (cpu.flags.zf)
    {
        goto L_0x00439b5d;
    }
    // 00439b59  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439b5b  eb05                   -jmp 0x439b62
    goto L_0x00439b62;
L_0x00439b5d:
    // 00439b5d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00439b62:
    // 00439b62  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439b64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439b69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439b71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439b72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
L_0x00439b74:
    // 00439b74  8b15704f5500           -mov edx, dword ptr [0x554f70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */);
    // 00439b7a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439b7c  7427                   -je 0x439ba5
    if (cpu.flags.zf)
    {
        goto L_0x00439ba5;
    }
    // 00439b7e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00439b80  a3704f5500             -mov dword ptr [0x554f70], eax
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.eax;
    // 00439b85  f6828003000008         +test byte ptr [edx + 0x380], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(896) /* 0x380 */) & 8 /*0x8*/));
    // 00439b8c  7407                   -je 0x439b95
    if (cpu.flags.zf)
    {
        goto L_0x00439b95;
    }
    // 00439b8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b90  e80b170000             -call 0x43b2a0
    cpu.esp -= 4;
    sub_43b2a0(app, cpu);
    if (cpu.terminate) return;
L_0x00439b95:
    // 00439b95  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b97  e814000000             -call 0x439bb0
    cpu.esp -= 4;
    sub_439bb0(app, cpu);
    if (cpu.terminate) return;
    // 00439b9c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439b9e  e8ed7c0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00439ba3  ebcf                   -jmp 0x439b74
    goto L_0x00439b74;
L_0x00439ba5:
    // 00439ba5  8915704f5500           -mov dword ptr [0x554f70], edx
    app->getMemory<x86::reg32>(x86::reg32(5590896) /* 0x554f70 */) = cpu.edx;
    // 00439bab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439bad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439baf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_439bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bb0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bb1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439bb5  7507                   -jne 0x439bbe
    if (!cpu.flags.zf)
    {
        goto L_0x00439bbe;
    }
    // 00439bb7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439bbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439bbe:
    // 00439bbe  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00439bc1  e82a000000             -call 0x439bf0
    cpu.esp -= 4;
    sub_439bf0(app, cpu);
    if (cpu.terminate) return;
    // 00439bc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439bc8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_439bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bd1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bd3  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00439bd6  668b522d               -mov dx, word ptr [edx + 0x2d]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(45) /* 0x2d */);
    // 00439bda  66895004               -mov word ptr [eax + 4], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 00439bde  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00439be1  83c22f                 -add edx, 0x2f
    (cpu.edx) += x86::reg32(x86::sreg32(47 /*0x2f*/));
    // 00439be4  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00439be7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439bec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439bed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_439bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439bf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439bf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439bf2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439bf4  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00439bf7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439bf9  7407                   -je 0x439c02
    if (cpu.flags.zf)
    {
        goto L_0x00439c02;
    }
    // 00439bfb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439bfd  e88e7c0a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439c02:
    // 00439c02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_439c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439c10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439c11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439c12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439c14  f6808003000001         +test byte ptr [eax + 0x380], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) & 1 /*0x1*/));
    // 00439c1b  7505                   -jne 0x439c22
    if (!cpu.flags.zf)
    {
        goto L_0x00439c22;
    }
    // 00439c1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c22:
    // 00439c22  8d901c030000           -lea edx, [eax + 0x31c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(796) /* 0x31c */);
    // 00439c28  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439c2a  e8f1f9ffff             -call 0x439620
    cpu.esp -= 4;
    sub_439620(app, cpu);
    if (cpu.terminate) return;
    // 00439c2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439c31  7503                   -jne 0x439c36
    if (!cpu.flags.zf)
    {
        goto L_0x00439c36;
    }
    // 00439c33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c36:
    // 00439c36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439c38  e823faffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 00439c3d  833da8d26f0000         +cmp dword ptr [0x6fd2a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328424) /* 0x6fd2a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c44  0f846d000000           -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c4a  83f824                 +cmp eax, 0x24
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c4d  7214                   -jb 0x439c63
    if (cpu.flags.cf)
    {
        goto L_0x00439c63;
    }
    // 00439c4f  764a                   -jbe 0x439c9b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c9b;
    }
    // 00439c51  83f827                 +cmp eax, 0x27
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(39 /*0x27*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c54  0f825d000000           -jb 0x439cb7
    if (cpu.flags.cf)
    {
        goto L_0x00439cb7;
    }
    // 00439c5a  7615                   -jbe 0x439c71
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c71;
    }
    // 00439c5c  83f831                 +cmp eax, 0x31
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c5f  7448                   -je 0x439ca9
    if (cpu.flags.zf)
    {
        goto L_0x00439ca9;
    }
    // 00439c61  eb54                   -jmp 0x439cb7
    goto L_0x00439cb7;
L_0x00439c63:
    // 00439c63  83f811                 +cmp eax, 0x11
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
    // 00439c66  724f                   -jb 0x439cb7
    if (cpu.flags.cf)
    {
        goto L_0x00439cb7;
    }
    // 00439c68  7623                   -jbe 0x439c8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00439c8d;
    }
    // 00439c6a  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439c6d  7410                   -je 0x439c7f
    if (cpu.flags.zf)
    {
        goto L_0x00439c7f;
    }
    // 00439c6f  eb46                   -jmp 0x439cb7
    goto L_0x00439cb7;
L_0x00439c71:
    // 00439c71  f605a8d26f0001         +test byte ptr [0x6fd2a8], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 1 /*0x1*/));
    // 00439c78  743d                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c7f:
    // 00439c7f  f605a8d26f0002         +test byte ptr [0x6fd2a8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 2 /*0x2*/));
    // 00439c86  742f                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c8d:
    // 00439c8d  f605a8d26f0004         +test byte ptr [0x6fd2a8], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 4 /*0x4*/));
    // 00439c94  7421                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439c96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439c98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439c9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439c9b:
    // 00439c9b  f605a8d26f0008         +test byte ptr [0x6fd2a8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 8 /*0x8*/));
    // 00439ca2  7413                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439ca4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439ca6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ca7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439ca8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439ca9:
    // 00439ca9  f605a8d26f0010         +test byte ptr [0x6fd2a8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(7328424) /* 0x6fd2a8 */) & 16 /*0x10*/));
    // 00439cb0  7405                   -je 0x439cb7
    if (cpu.flags.zf)
    {
        goto L_0x00439cb7;
    }
    // 00439cb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439cb4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cb5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439cb7:
    // 00439cb7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439cbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_439cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439cc0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439cc1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439cc3  e888fdffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 00439cc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439cca  7405                   -je 0x439cd1
    if (cpu.flags.zf)
    {
        goto L_0x00439cd1;
    }
    // 00439ccc  e83fffffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
L_0x00439cd1:
    // 00439cd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439cd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_439ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439ce0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439ce1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439ce2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439ce4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00439ce7  ba25000000             -mov edx, 0x25
    cpu.edx = 37 /*0x25*/;
    // 00439cec  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439cef  e8dcedffff             -call 0x438ad0
    cpu.esp -= 4;
    sub_438ad0(app, cpu);
    if (cpu.terminate) return;
    // 00439cf4  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439cf7  e894fcffff             -call 0x439990
    cpu.esp -= 4;
    sub_439990(app, cpu);
    if (cpu.terminate) return;
    // 00439cfc  83f8ff                 +cmp eax, -1
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
    // 00439cff  7507                   -jne 0x439d08
    if (!cpu.flags.zf)
    {
        goto L_0x00439d08;
    }
    // 00439d01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00439d03  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439d05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d07  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00439d08:
    // 00439d08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00439d0d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439d0f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_439d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439d21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439d22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439d23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439d24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439d25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439d26  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439d28  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00439d2b  e8a0eeffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 00439d30  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439d33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00439d35:
    // 00439d35  3b55fc                 +cmp edx, dword ptr [ebp - 4]
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
    // 00439d38  7d45                   -jge 0x439d7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7f;
    }
    // 00439d3a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439d3c  e8dff7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d41  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00439d44  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
L_0x00439d47:
    // 00439d47  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439d4a  7d30                   -jge 0x439d7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00439d7c;
    }
    // 00439d4c  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00439d51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00439d53  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00439d56  e8c5f7ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 00439d5b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439d5d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439d5f  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
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
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (!cpu.flags.zf)
            break;
    }
    // 00439d61  7405                   -je 0x439d68
    if (cpu.flags.zf)
    {
        goto L_0x00439d68;
    }
    // 00439d63  19c0                   +sbb eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00439d65  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x00439d68:
    // 00439d68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439d6a  750d                   -jne 0x439d79
    if (!cpu.flags.zf)
    {
        goto L_0x00439d79;
    }
    // 00439d6c  68a4765300             -push 0x5376a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469860 /*0x5376a4*/;
    cpu.esp -= 4;
    // 00439d71  e89a72fcff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00439d76  83c404                 +add esp, 4
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
L_0x00439d79:
    // 00439d79  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7a  ebcb                   -jmp 0x439d47
    goto L_0x00439d47;
L_0x00439d7c:
    // 00439d7c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00439d7d  ebb6                   -jmp 0x439d35
    goto L_0x00439d35;
L_0x00439d7f:
    // 00439d7f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00439d81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_439d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00439d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00439d91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00439d92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00439d93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00439d94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439d95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00439d96  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00439d98  81ec78020000           -sub esp, 0x278
    (cpu.esp) -= x86::reg32(x86::sreg32(632 /*0x278*/));
    // 00439d9e  e84dfcffff             -call 0x4399f0
    cpu.esp -= 4;
    sub_4399f0(app, cpu);
    if (cpu.terminate) return;
    // 00439da3  e838eeffff             -call 0x438be0
    cpu.esp -= 4;
    sub_438be0(app, cpu);
    if (cpu.terminate) return;
    // 00439da8  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00439dab  b8b4287a00             -mov eax, 0x7a28b4
    cpu.eax = 8005812 /*0x7a28b4*/;
    // 00439db0  e8fbe8ffff             -call 0x4386b0
    cpu.esp -= 4;
    sub_4386b0(app, cpu);
    if (cpu.terminate) return;
L_0x00439db5:
    // 00439db5  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00439db8  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439dbc  0f8483050000           -je 0x43a345
    if (cpu.flags.zf)
    {
        goto L_0x0043a345;
    }
    // 00439dc2  bad0765300             -mov edx, 0x5376d0
    cpu.edx = 5469904 /*0x5376d0*/;
    // 00439dc7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439dca  e8f1000b00             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00439dcf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439dd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439dd3  0f8462050000           -je 0x43a33b
    if (cpu.flags.zf)
    {
        goto L_0x0043a33b;
    }
    // 00439dd9  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00439ddc  e89fecffff             -call 0x438a80
    cpu.esp -= 4;
    sub_438a80(app, cpu);
    if (cpu.terminate) return;
L_0x00439de1:
    // 00439de1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439de3  7422                   -je 0x439e07
    if (cpu.flags.zf)
    {
        goto L_0x00439e07;
    }
    // 00439de5  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439de8  0510010000             -add eax, 0x110
    (cpu.eax) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00439ded  e81e450b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00439df2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439df4  7507                   -jne 0x439dfd
    if (!cpu.flags.zf)
    {
        goto L_0x00439dfd;
    }
    // 00439df6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00439dfb  eb0a                   -jmp 0x439e07
    goto L_0x00439e07;
L_0x00439dfd:
    // 00439dfd  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00439e00  e89becffff             -call 0x438aa0
    cpu.esp -= 4;
    sub_438aa0(app, cpu);
    if (cpu.terminate) return;
    // 00439e05  ebda                   -jmp 0x439de1
    goto L_0x00439de1;
L_0x00439e07:
    // 00439e07  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439e09  0f852c050000           -jne 0x43a33b
    if (!cpu.flags.zf)
    {
        goto L_0x0043a33b;
    }
    // 00439e0f  beb4287a00             -mov esi, 0x7a28b4
    cpu.esi = 8005812 /*0x7a28b4*/;
    // 00439e14  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e1a  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00439e1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00439e1e:
    // 00439e1e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439e20  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439e22  3c00                   +cmp al, 0
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
    // 00439e24  7410                   -je 0x439e36
    if (cpu.flags.zf)
    {
        goto L_0x00439e36;
    }
    // 00439e26  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439e29  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e2c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439e2f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e32  3c00                   +cmp al, 0
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
    // 00439e34  75e8                   -jne 0x439e1e
    if (!cpu.flags.zf)
    {
        goto L_0x00439e1e;
    }
L_0x00439e36:
    // 00439e36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439e37  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e3d  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00439e40  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e46  41                     -inc ecx
    (cpu.ecx)++;
    // 00439e47  e8f4e4ffff             -call 0x438340
    cpu.esp -= 4;
    sub_438340(app, cpu);
    if (cpu.terminate) return;
    // 00439e4c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00439e4f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00439e50  2bc9                   +sub ecx, ecx
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
    // 00439e52  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439e53  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00439e55  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439e57  4f                     -dec edi
    (cpu.edi)--;
L_0x00439e58:
    // 00439e58  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439e5a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439e5c  3c00                   +cmp al, 0
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
    // 00439e5e  7410                   -je 0x439e70
    if (cpu.flags.zf)
    {
        goto L_0x00439e70;
    }
    // 00439e60  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439e63  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e66  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439e69  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439e6c  3c00                   +cmp al, 0
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
    // 00439e6e  75e8                   -jne 0x439e58
    if (!cpu.flags.zf)
    {
        goto L_0x00439e58;
    }
L_0x00439e70:
    // 00439e70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439e71  a1503a7a00             -mov eax, dword ptr [0x7a3a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(8010320) /* 0x7a3a50 */);
    // 00439e76  e835e40300             -call 0x4782b0
    cpu.esp -= 4;
    sub_4782b0(app, cpu);
    if (cpu.terminate) return;
    // 00439e7b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439e7c  68d8765300             -push 0x5376d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469912 /*0x5376d8*/;
    cpu.esp -= 4;
    // 00439e81  8dbdb4feffff           -lea edi, [ebp - 0x14c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e87  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00439e89  49                     -dec ecx
    (cpu.ecx)--;
    // 00439e8a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00439e8c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00439e8e  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00439e90  49                     -dec ecx
    (cpu.ecx)--;
    // 00439e91  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439e97  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00439e99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439e9a  e8f1570a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00439e9f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00439ea2  bae4765300             -mov edx, 0x5376e4
    cpu.edx = 5469924 /*0x5376e4*/;
    // 00439ea7  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439ead  e836410b00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 00439eb2  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00439eb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439eb7  7421                   -je 0x439eda
    if (cpu.flags.zf)
    {
        goto L_0x00439eda;
    }
    // 00439eb9  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00439ebe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00439ec0  e8c3f10a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 00439ec5  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439ec8  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00439eca  e851450b00             -call 0x4ee420
    cpu.esp -= 4;
    sub_4ee420(app, cpu);
    if (cpu.terminate) return;
    // 00439ecf  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00439ed2  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00439ed5  e983000000             -jmp 0x439f5d
    goto L_0x00439f5d;
L_0x00439eda:
    // 00439eda  8db5b4feffff           -lea esi, [ebp - 0x14c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439ee0  8dbd88fdffff           -lea edi, [ebp - 0x278]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439ee6  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 00439eeb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00439eec:
    // 00439eec  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00439eee  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00439ef0  3c00                   +cmp al, 0
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
    // 00439ef2  7410                   -je 0x439f04
    if (cpu.flags.zf)
    {
        goto L_0x00439f04;
    }
    // 00439ef4  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00439ef7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439efa  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00439efd  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00439f00  3c00                   +cmp al, 0
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
    // 00439f02  75e8                   -jne 0x439eec
    if (!cpu.flags.zf)
    {
        goto L_0x00439eec;
    }
L_0x00439f04:
    // 00439f04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00439f05  8d8588fdffff           -lea eax, [ebp - 0x278]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439f0b  e8e0430b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 00439f10  68e8765300             -push 0x5376e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5469928 /*0x5376e8*/;
    cpu.esp -= 4;
    // 00439f15  40                     -inc eax
    (cpu.eax)++;
    // 00439f16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00439f17  e874570a00             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00439f1c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00439f1f  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f22  8d8588fdffff           -lea eax, [ebp - 0x278]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-632) /* -0x278 */);
    // 00439f28  e803190000             -call 0x43b830
    cpu.esp -= 4;
    sub_43b830(app, cpu);
    if (cpu.terminate) return;
    // 00439f2d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439f2f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00439f31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439f33  7508                   -jne 0x439f3d
    if (!cpu.flags.zf)
    {
        goto L_0x00439f3d;
    }
    // 00439f35  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439f38  e9fe030000             -jmp 0x43a33b
    goto L_0x0043a33b;
L_0x00439f3d:
    // 00439f3d  ba5c000000             -mov edx, 0x5c
    cpu.edx = 92 /*0x5c*/;
    // 00439f42  8d85b4feffff           -lea eax, [ebp - 0x14c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-332) /* -0x14c */);
    // 00439f48  8d4de0                 -lea ecx, [ebp - 0x20]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00439f4b  e8a0430b00             -call 0x4ee2f0
    cpu.esp -= 4;
    sub_4ee2f0(app, cpu);
    if (cpu.terminate) return;
    // 00439f50  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00439f53  8d5de4                 -lea ebx, [ebp - 0x1c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00439f56  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00439f58  e8731a0000             -call 0x43b9d0
    cpu.esp -= 4;
    sub_43b9d0(app, cpu);
    if (cpu.terminate) return;
L_0x00439f5d:
    // 00439f5d  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00439f61  7525                   -jne 0x439f88
    if (!cpu.flags.zf)
    {
        goto L_0x00439f88;
    }
    // 00439f63  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439f65  740c                   -je 0x439f73
    if (cpu.flags.zf)
    {
        goto L_0x00439f73;
    }
    // 00439f67  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439f6c  e83f1a0000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00439f71  eb08                   -jmp 0x439f7b
    goto L_0x00439f7b;
L_0x00439f73:
    // 00439f73  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439f76  e885410b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00439f7b:
    // 00439f7b  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00439f7e  e85de8ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 00439f83  e92dfeffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x00439f88:
    // 00439f88  baa4030000             -mov edx, 0x3a4
    cpu.edx = 932 /*0x3a4*/;
    // 00439f8d  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439f92  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439f94  e887760a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00439f99  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00439f9c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00439f9e  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00439fa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00439fa3  b890765300             -mov eax, 0x537690
    cpu.eax = 5469840 /*0x537690*/;
    // 00439fa8  42                     -inc edx
    (cpu.edx)++;
    // 00439fa9  e872760a00             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 00439fae  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00439fb0  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00439fb3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439fb5  7404                   -je 0x439fbb
    if (cpu.flags.zf)
    {
        goto L_0x00439fbb;
    }
    // 00439fb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00439fb9  753e                   -jne 0x439ff9
    if (!cpu.flags.zf)
    {
        goto L_0x00439ff9;
    }
L_0x00439fbb:
    // 00439fbb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00439fbd  740c                   -je 0x439fcb
    if (cpu.flags.zf)
    {
        goto L_0x00439fcb;
    }
    // 00439fbf  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439fc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00439fc4  e8e7190000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 00439fc9  eb08                   -jmp 0x439fd3
    goto L_0x00439fd3;
L_0x00439fcb:
    // 00439fcb  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00439fce  e82d410b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x00439fd3:
    // 00439fd3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00439fd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00439fd8  7407                   -je 0x439fe1
    if (cpu.flags.zf)
    {
        goto L_0x00439fe1;
    }
    // 00439fda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00439fdc  e8af780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439fe1:
    // 00439fe1  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00439fe4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00439fe6  7407                   -je 0x439fef
    if (cpu.flags.zf)
    {
        goto L_0x00439fef;
    }
    // 00439fe8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00439fea  e8a1780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00439fef:
    // 00439fef  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00439ff4  e9c0040000             -jmp 0x43a4b9
    goto L_0x0043a4b9;
L_0x00439ff9:
    // 00439ff9  bba4030000             -mov ebx, 0x3a4
    cpu.ebx = 932 /*0x3a4*/;
    // 00439ffe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a000  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a002  e839660a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043a007  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0043a00a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a00d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a00f  e874f00a00             -call 0x4e9088
    cpu.esp -= 4;
    sub_4e9088(app, cpu);
    if (cpu.terminate) return;
    // 0043a014  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a017  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043a01c  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0043a01f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043a021  e8daf10a00             -call 0x4e9200
    cpu.esp -= 4;
    sub_4e9200(app, cpu);
    if (cpu.terminate) return;
    // 0043a026  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043a028  740c                   -je 0x43a036
    if (cpu.flags.zf)
    {
        goto L_0x0043a036;
    }
    // 0043a02a  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a02d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043a02f  e87c190000             -call 0x43b9b0
    cpu.esp -= 4;
    sub_43b9b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a034  eb08                   -jmp 0x43a03e
    goto L_0x0043a03e;
L_0x0043a036:
    // 0043a036  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0043a039  e8c2400b00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
L_0x0043a03e:
    // 0043a03e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a041  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0043a044  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a047  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a04a  88828e030000           -mov byte ptr [edx + 0x38e], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(910) /* 0x38e */) = cpu.al;
    // 0043a050  83f809                 +cmp eax, 9
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
    // 0043a053  741c                   -je 0x43a071
    if (cpu.flags.zf)
    {
        goto L_0x0043a071;
    }
    // 0043a055  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a057  e834780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a05c  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a05f  e82c780a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a064  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a067  e874e7ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a06c  e944fdffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a071:
    // 0043a071  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a074  8a9a84030000           -mov bl, byte ptr [edx + 0x384]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(900) /* 0x384 */);
    // 0043a07a  8b400a                 -mov eax, dword ptr [eax + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0043a07d  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 0043a080  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a083  889a84030000           -mov byte ptr [edx + 0x384], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(900) /* 0x384 */) = cpu.bl;
    // 0043a089  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0043a08c  8bb284030000           -mov esi, dword ptr [edx + 0x384]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(900) /* 0x384 */);
    // 0043a092  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a094  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0043a099  89b284030000           -mov dword ptr [edx + 0x384], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(900) /* 0x384 */) = cpu.esi;
    // 0043a09f  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0a2  8dba1c030000           -lea edi, [edx + 0x31c]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(796) /* 0x31c */);
    // 0043a0a8  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043a0ab  bb05000000             -mov ebx, 5
    cpu.ebx = 5 /*0x5*/;
    // 0043a0b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a0b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a0b3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043a0b6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043a0b8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043a0ba  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043a0bd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043a0bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a0c0  8dba15030000           -lea edi, [edx + 0x315]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(789) /* 0x315 */);
    // 0043a0c6  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0043a0cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043a0cd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a0cf  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0d2  e869650a00             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0043a0d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043a0d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a0da  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0043a0dd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043a0df  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0043a0e1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0043a0e4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0043a0e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a0e7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0ea  6683780600             +cmp word ptr [eax + 6], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a0ef  740a                   -je 0x43a0fb
    if (cpu.flags.zf)
    {
        goto L_0x0043a0fb;
    }
    // 0043a0f1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a0f4  80888003000001         -or byte ptr [eax + 0x380], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0043a0fb:
    // 0043a0fb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a0fe  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a103  740a                   -je 0x43a10f
    if (cpu.flags.zf)
    {
        goto L_0x0043a10f;
    }
    // 0043a105  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a108  80888003000002         -or byte ptr [eax + 0x380], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0043a10f:
    // 0043a10f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a112  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a117  740a                   -je 0x43a123
    if (cpu.flags.zf)
    {
        goto L_0x0043a123;
    }
    // 0043a119  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a11c  80888003000004         -or byte ptr [eax + 0x380], 4
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0043a123:
    // 0043a123  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a126  6683781000             +cmp word ptr [eax + 0x10], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a12b  740a                   -je 0x43a137
    if (cpu.flags.zf)
    {
        goto L_0x0043a137;
    }
    // 0043a12d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a130  80888003000010         -or byte ptr [eax + 0x380], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0043a137:
    // 0043a137  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a13a  6683781400             +cmp word ptr [eax + 0x14], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043a13f  740a                   -je 0x43a14b
    if (cpu.flags.zf)
    {
        goto L_0x0043a14b;
    }
    // 0043a141  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a144  80888003000040         -or byte ptr [eax + 0x380], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0043a14b:
    // 0043a14b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a14e  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a151  8a4012                 -mov al, byte ptr [eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0043a154  8882a0030000           -mov byte ptr [edx + 0x3a0], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(928) /* 0x3a0 */) = cpu.al;
    // 0043a15a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a15d  668b4016               -mov ax, word ptr [eax + 0x16]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0043a161  6689828c030000         -mov word ptr [edx + 0x38c], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(908) /* 0x38c */) = cpu.ax;
    // 0043a168  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a16b  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0043a16e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043a171  898288030000           -mov dword ptr [edx + 0x388], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(904) /* 0x388 */) = cpu.eax;
    // 0043a177  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a17a  8a4028                 -mov al, byte ptr [eax + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0043a17d  88828f030000           -mov byte ptr [edx + 0x38f], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(911) /* 0x38f */) = cpu.al;
    // 0043a183  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a186  8a4029                 -mov al, byte ptr [eax + 0x29]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */);
    // 0043a189  888290030000           -mov byte ptr [edx + 0x390], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(912) /* 0x390 */) = cpu.al;
    // 0043a18f  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a192  8a402a                 -mov al, byte ptr [eax + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(42) /* 0x2a */);
    // 0043a195  888291030000           -mov byte ptr [edx + 0x391], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(913) /* 0x391 */) = cpu.al;
    // 0043a19b  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a19e  8a402b                 -mov al, byte ptr [eax + 0x2b]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(43) /* 0x2b */);
    // 0043a1a1  888292030000           -mov byte ptr [edx + 0x392], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(914) /* 0x392 */) = cpu.al;
    // 0043a1a7  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a1aa  8a402c                 -mov al, byte ptr [eax + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0043a1ad  8a1d2eeb5500           -mov bl, byte ptr [0x55eb2e]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */);
    // 0043a1b3  888293030000           -mov byte ptr [edx + 0x393], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(915) /* 0x393 */) = cpu.al;
    // 0043a1b9  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0043a1bc  7505                   -jne 0x43a1c3
    if (!cpu.flags.zf)
    {
        goto L_0x0043a1c3;
    }
    // 0043a1be  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0043a1c1  743e                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
L_0x0043a1c3:
    // 0043a1c3  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a1c6  81c21c030000           -add edx, 0x31c
    (cpu.edx) += x86::reg32(x86::sreg32(796 /*0x31c*/));
    // 0043a1cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a1ce  e88df4ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a1d3  83f80f                 +cmp eax, 0xf
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
    // 0043a1d6  7429                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
    // 0043a1d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a1da  e881f4ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a1df  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a1e2  741d                   -je 0x43a201
    if (cpu.flags.zf)
    {
        goto L_0x0043a201;
    }
    // 0043a1e4  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a1e7  e8a4760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a1ec  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a1ef  e89c760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a1f4  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a1f7  e8e4e5ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a1fc  e9b4fbffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a201:
    // 0043a201  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a204  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a207  e8c4f9ffff             -call 0x439bd0
    cpu.esp -= 4;
    sub_439bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a20c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a20e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a211  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a213  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043a216  e8d5f8ffff             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 0043a21b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043a21d  b8f0765300             -mov eax, 0x5376f0
    cpu.eax = 5469936 /*0x5376f0*/;
    // 0043a222  e899fc0a00             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 0043a227  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a229  750a                   -jne 0x43a235
    if (!cpu.flags.zf)
    {
        goto L_0x0043a235;
    }
    // 0043a22b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a22e  80888003000020         -or byte ptr [eax + 0x380], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0043a235:
    // 0043a235  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a238  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043a23a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043a23d  e8aef8ffff             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 0043a242  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043a244  b8f8765300             -mov eax, 0x5376f8
    cpu.eax = 5469944 /*0x5376f8*/;
    // 0043a249  e872fc0a00             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 0043a24e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a250  750a                   -jne 0x43a25c
    if (!cpu.flags.zf)
    {
        goto L_0x0043a25c;
    }
    // 0043a252  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a255  80888003000020         -or byte ptr [eax + 0x380], 0x20
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(896) /* 0x380 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0043a25c:
    // 0043a25c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043a25e  751e                   -jne 0x43a27e
    if (!cpu.flags.zf)
    {
        goto L_0x0043a27e;
    }
    // 0043a260  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0043a263  e828760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a268  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a26b  e820760a00             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 0043a270  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0043a275  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043a277  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a278  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a279  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a27d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043a27e:
    // 0043a27e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a281  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0043a286  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043a289  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a28c  e85ff8ffff             -call 0x439af0
    cpu.esp -= 4;
    sub_439af0(app, cpu);
    if (cpu.terminate) return;
    // 0043a291  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a294  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043a296  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a297:
    // 0043a297  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a299  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a29b  3c00                   +cmp al, 0
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
    // 0043a29d  7410                   -je 0x43a2af
    if (cpu.flags.zf)
    {
        goto L_0x0043a2af;
    }
    // 0043a29f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2a2  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2a5  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2a8  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2ab  3c00                   +cmp al, 0
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
    // 0043a2ad  75e8                   -jne 0x43a297
    if (!cpu.flags.zf)
    {
        goto L_0x0043a297;
    }
L_0x0043a2af:
    // 0043a2af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a2b0  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a2b3  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043a2b6  81c710010000           -add edi, 0x110
    (cpu.edi) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0043a2bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a2bd:
    // 0043a2bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a2bf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a2c1  3c00                   +cmp al, 0
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
    // 0043a2c3  7410                   -je 0x43a2d5
    if (cpu.flags.zf)
    {
        goto L_0x0043a2d5;
    }
    // 0043a2c5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2c8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2cb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2ce  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2d1  3c00                   +cmp al, 0
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
    // 0043a2d3  75e8                   -jne 0x43a2bd
    if (!cpu.flags.zf)
    {
        goto L_0x0043a2bd;
    }
L_0x0043a2d5:
    // 0043a2d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a2d6  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a2d9  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0043a2dc  81c710020000           -add edi, 0x210
    (cpu.edi) += x86::reg32(x86::sreg32(528 /*0x210*/));
    // 0043a2e2  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0043a2e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0043a2e8:
    // 0043a2e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0043a2ea  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0043a2ec  3c00                   +cmp al, 0
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
    // 0043a2ee  7410                   -je 0x43a300
    if (cpu.flags.zf)
    {
        goto L_0x0043a300;
    }
    // 0043a2f0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0043a2f3  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2f6  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0043a2f9  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0043a2fc  3c00                   +cmp al, 0
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
    // 0043a2fe  75e8                   -jne 0x43a2e8
    if (!cpu.flags.zf)
    {
        goto L_0x0043a2e8;
    }
L_0x0043a300:
    // 0043a300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a301  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a304  ba94765300             -mov edx, 0x537694
    cpu.edx = 5469844 /*0x537694*/;
    // 0043a309  0510030000             +add eax, 0x310
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(784 /*0x310*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043a30e  e81d6b0a00             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0043a313  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a316  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0043a319  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0043a31f  e86ce8ffff             -call 0x438b90
    cpu.esp -= 4;
    sub_438b90(app, cpu);
    if (cpu.terminate) return;
    // 0043a324  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0043a327  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0043a328  a3744f5500             -mov dword ptr [0x554f74], eax
    app->getMemory<x86::reg32>(x86::reg32(5590900) /* 0x554f74 */) = cpu.eax;
    // 0043a32d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a32f  e8bc100000             -call 0x43b3f0
    cpu.esp -= 4;
    sub_43b3f0(app, cpu);
    if (cpu.terminate) return;
    // 0043a334  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a336  e805140000             -call 0x43b740
    cpu.esp -= 4;
    sub_43b740(app, cpu);
    if (cpu.terminate) return;
L_0x0043a33b:
    // 0043a33b  e8a0e4ffff             -call 0x4387e0
    cpu.esp -= 4;
    sub_4387e0(app, cpu);
    if (cpu.terminate) return;
    // 0043a340  e970faffff             -jmp 0x439db5
    goto L_0x00439db5;
L_0x0043a345:
    // 0043a345  e896e8ffff             -call 0x438be0
    cpu.esp -= 4;
    sub_438be0(app, cpu);
    if (cpu.terminate) return;
    // 0043a34a  e861ebffff             -call 0x438eb0
    cpu.esp -= 4;
    sub_438eb0(app, cpu);
    if (cpu.terminate) return;
    // 0043a34f  b8c1000000             -mov eax, 0xc1
    cpu.eax = 193 /*0xc1*/;
    // 0043a354  babe000000             -mov edx, 0xbe
    cpu.edx = 190 /*0xbe*/;
    // 0043a359  bbbf000000             -mov ebx, 0xbf
    cpu.ebx = 191 /*0xbf*/;
    // 0043a35e  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 0043a363  66a330515500           -mov word ptr [0x555130], ax
    app->getMemory<x86::reg16>(x86::reg32(5591344) /* 0x555130 */) = cpu.ax;
    // 0043a369  66891532515500         -mov word ptr [0x555132], dx
    app->getMemory<x86::reg16>(x86::reg32(5591346) /* 0x555132 */) = cpu.dx;
    // 0043a370  66891d34515500         -mov word ptr [0x555134], bx
    app->getMemory<x86::reg16>(x86::reg32(5591348) /* 0x555134 */) = cpu.bx;
    // 0043a377  b8fd9d64ff             -mov eax, 0xff649dfd
    cpu.eax = 4284784125 /*0xff649dfd*/;
    // 0043a37c  66890d36515500         -mov word ptr [0x555136], cx
    app->getMemory<x86::reg16>(x86::reg32(5591350) /* 0x555136 */) = cpu.cx;
    // 0043a383  a304525500             -mov dword ptr [0x555204], eax
    app->getMemory<x86::reg32>(x86::reg32(5591556) /* 0x555204 */) = cpu.eax;
    // 0043a388  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043a38a  a308525500             -mov dword ptr [0x555208], eax
    app->getMemory<x86::reg32>(x86::reg32(5591560) /* 0x555208 */) = cpu.eax;
    // 0043a38f  a30c525500             -mov dword ptr [0x55520c], eax
    app->getMemory<x86::reg32>(x86::reg32(5591564) /* 0x55520c */) = cpu.eax;
    // 0043a394  a310525500             -mov dword ptr [0x555210], eax
    app->getMemory<x86::reg32>(x86::reg32(5591568) /* 0x555210 */) = cpu.eax;
    // 0043a399  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043a39b:
    // 0043a39b  e830e8ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a3a0  39c2                   +cmp edx, eax
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
    // 0043a3a2  7d63                   -jge 0x43a407
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a407;
    }
    // 0043a3a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3a6  e8a5f6ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a3ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043a3ad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3af  e8fcf2ffff             -call 0x4396b0
    cpu.esp -= 4;
    sub_4396b0(app, cpu);
    if (cpu.terminate) return;
    // 0043a3b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a3b6  754f                   -jne 0x43a407
    if (!cpu.flags.zf)
    {
        goto L_0x0043a407;
    }
    // 0043a3b8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a3ba  8d0c12                 -lea ecx, [edx + edx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0043a3bd  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0043a3c2  05bd070000             -add eax, 0x7bd
    (cpu.eax) += x86::reg32(x86::sreg32(1981 /*0x7bd*/));
    // 0043a3c7  6689b9a2515500         -mov word ptr [ecx + 0x5551a2], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591458) /* 0x5551a2 */) = cpu.di;
    // 0043a3ce  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0043a3d5  66898138515500         -mov word ptr [ecx + 0x555138], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591352) /* 0x555138 */) = cpu.ax;
    // 0043a3dc  c78714525500fd9d64ff   -mov dword ptr [edi + 0x555214], 0xff649dfd
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591572) /* 0x555214 */) = 4284784125 /*0xff649dfd*/;
    // 0043a3e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043a3e8  e823f8ffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
    // 0043a3ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a3ef  7413                   -je 0x43a404
    if (cpu.flags.zf)
    {
        goto L_0x0043a404;
    }
    // 0043a3f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a3f3  668981a2515500         -mov word ptr [ecx + 0x5551a2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5591458) /* 0x5551a2 */) = cpu.ax;
    // 0043a3fa  c7871452550080809000   -mov dword ptr [edi + 0x555214], 0x908080
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591572) /* 0x555214 */) = 9470080 /*0x908080*/;
L_0x0043a404:
    // 0043a404  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a405  eb94                   -jmp 0x43a39b
    goto L_0x0043a39b;
L_0x0043a407:
    // 0043a407  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a409  66891c5538515500       -mov word ptr [edx*2 + 0x555138], bx
    app->getMemory<x86::reg16>(x86::reg32(5591352) /* 0x555138 */ + cpu.edx * 2) = cpu.bx;
    // 0043a411  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043a413:
    // 0043a413  e8b8e7ffff             -call 0x438bd0
    cpu.esp -= 4;
    sub_438bd0(app, cpu);
    if (cpu.terminate) return;
    // 0043a418  39c2                   +cmp edx, eax
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
    // 0043a41a  0f8d72000000           -jge 0x43a492
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043a492;
    }
    // 0043a420  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a422  e829f6ffff             -call 0x439a50
    cpu.esp -= 4;
    sub_439a50(app, cpu);
    if (cpu.terminate) return;
    // 0043a427  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043a429  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a42b  e8f0f0ffff             -call 0x439520
    cpu.esp -= 4;
    sub_439520(app, cpu);
    if (cpu.terminate) return;
    // 0043a430  e82bf2ffff             -call 0x439660
    cpu.esp -= 4;
    sub_439660(app, cpu);
    if (cpu.terminate) return;
    // 0043a435  83f821                 +cmp eax, 0x21
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043a438  7508                   -jne 0x43a442
    if (!cpu.flags.zf)
    {
        goto L_0x0043a442;
    }
    // 0043a43a  891530dc6f00           -mov dword ptr [0x6fdc30], edx
    app->getMemory<x86::reg32>(x86::reg32(7330864) /* 0x6fdc30 */) = cpu.edx;
    // 0043a440  eb50                   -jmp 0x43a492
    goto L_0x0043a492;
L_0x0043a442:
    // 0043a442  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0043a447  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043a449  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0043a44c  bbfd9d64ff             -mov ebx, 0xff649dfd
    cpu.ebx = 4284784125 /*0xff649dfd*/;
    // 0043a451  05bd070000             -add eax, 0x7bd
    (cpu.eax) += x86::reg32(x86::sreg32(1981 /*0x7bd*/));
    // 0043a456  6689be0a505500         -mov word ptr [esi + 0x55500a], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5591050) /* 0x55500a */) = cpu.di;
    // 0043a45d  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0043a464  668986a84f5500         -mov word ptr [esi + 0x554fa8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5590952) /* 0x554fa8 */) = cpu.ax;
    // 0043a46b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043a46d  899f6c505500           -mov dword ptr [edi + 0x55506c], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591148) /* 0x55506c */) = cpu.ebx;
    // 0043a473  e898f7ffff             -call 0x439c10
    cpu.esp -= 4;
    sub_439c10(app, cpu);
    if (cpu.terminate) return;
    // 0043a478  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043a47a  7413                   -je 0x43a48f
    if (cpu.flags.zf)
    {
        goto L_0x0043a48f;
    }
    // 0043a47c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043a47e  6689860a505500         -mov word ptr [esi + 0x55500a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5591050) /* 0x55500a */) = cpu.ax;
    // 0043a485  c7876c50550080809000   -mov dword ptr [edi + 0x55506c], 0x908080
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5591148) /* 0x55506c */) = 9470080 /*0x908080*/;
L_0x0043a48f:
    // 0043a48f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0043a490  eb81                   -jmp 0x43a413
    goto L_0x0043a413;
L_0x0043a492:
    // 0043a492  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043a494  66891c55a84f5500       -mov word ptr [edx*2 + 0x554fa8], bx
    app->getMemory<x86::reg16>(x86::reg32(5590952) /* 0x554fa8 */ + cpu.edx * 2) = cpu.bx;
    // 0043a49c  e8df000000             -call 0x43a580
    cpu.esp -= 4;
    sub_43a580(app, cpu);
    if (cpu.terminate) return;
    // 0043a4a1  e87af8ffff             -call 0x439d20
    cpu.esp -= 4;
    sub_439d20(app, cpu);
    if (cpu.terminate) return;
    // 0043a4a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043a4a8  e893240a00             -call 0x4dc940
    cpu.esp -= 4;
    sub_4dc940(app, cpu);
    if (cpu.terminate) return;
    // 0043a4ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043a4b2  e889240a00             -call 0x4dc940
    cpu.esp -= 4;
    sub_4dc940(app, cpu);
    if (cpu.terminate) return;
    // 0043a4b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043a4b9:
    // 0043a4b9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0043a4bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_43a4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043a4d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043a4d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0043a4d3  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0043a4d5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0043a4d7  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a4da  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0043a4dd  e82e3e0b00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0043a4e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043a4e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
