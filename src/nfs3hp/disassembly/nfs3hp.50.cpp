#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_5234d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005234d0  83f802                 +cmp eax, 2
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
    // 005234d3  750d                   -jne 0x5234e2
    if (!cpu.flags.zf)
    {
        goto L_0x005234e2;
    }
    // 005234d5  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 005234db  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 005234e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005234e2:
    // 005234e2  83f801                 +cmp eax, 1
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
    // 005234e5  750d                   -jne 0x5234f4
    if (!cpu.flags.zf)
    {
        goto L_0x005234f4;
    }
    // 005234e7  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 005234ed  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 005234f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005234f4:
    // 005234f4  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 005234fa  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00523500  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_523504(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523504  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523505  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523507  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0052350a  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052350d  83f820                 +cmp eax, 0x20
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
    // 00523510  7210                   -jb 0x523522
    if (cpu.flags.cf)
    {
        goto L_0x00523522;
    }
    // 00523512  7638                   -jbe 0x52354c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052354c;
    }
    // 00523514  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523517  7241                   -jb 0x52355a
    if (cpu.flags.cf)
    {
        goto L_0x0052355a;
    }
    // 00523519  7629                   -jbe 0x523544
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523544;
    }
    // 0052351b  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052351e  7434                   -je 0x523554
    if (cpu.flags.zf)
    {
        goto L_0x00523554;
    }
    // 00523520  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523521  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523522:
    // 00523522  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523524  7607                   -jbe 0x52352d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052352d;
    }
    // 00523526  83f810                 +cmp eax, 0x10
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
    // 00523529  7411                   -je 0x52353c
    if (cpu.flags.zf)
    {
        goto L_0x0052353c;
    }
    // 0052352b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052352c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052352d:
    // 0052352d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00523533  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523535  7523                   -jne 0x52355a
    if (!cpu.flags.zf)
    {
        goto L_0x0052355a;
    }
    // 00523537  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0052353a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052353b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052353c:
    // 0052353c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00523542  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523543  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523544:
    // 00523544  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 0052354a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052354b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052354c:
    // 0052354c  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00523552  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523553  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523554:
    // 00523554  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x0052355a:
    // 0052355a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052355b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_523560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523563  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523565  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052356b  833db077560000         +cmp dword ptr [0x5677b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523572  741d                   -je 0x523591
    if (cpu.flags.zf)
    {
        goto L_0x00523591;
    }
    // 00523574  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523576  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052357c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052357e  7411                   -je 0x523591
    if (cpu.flags.zf)
    {
        goto L_0x00523591;
    }
    // 00523580  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523582  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00523588  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052358d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052358e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052358f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523591:
    // 00523591  a1bcac5600             -mov eax, dword ptr [0x56acbc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5680316) /* 0x56acbc */);
    // 00523596  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00523599  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052359a  2eff152c455300         -call dword ptr cs:[0x53452c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457196) /* 0x53452c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235a1  83f802                 +cmp eax, 2
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
    // 005235a4  7511                   -jne 0x5235b7
    if (!cpu.flags.zf)
    {
        goto L_0x005235b7;
    }
    // 005235a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005235a8  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235ae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005235b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005235b7:
    // 005235b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005235b9  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005235c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005235c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5235d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235d0  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235d6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005235d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5235dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235dc  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235e2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005235e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5235f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005235f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005235f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005235f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005235f3  2eff1594455300         -call dword ptr cs:[0x534594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457300) /* 0x534594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005235fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005235fc  7507                   -jne 0x523605
    if (!cpu.flags.zf)
    {
        goto L_0x00523605;
    }
    // 005235fe  e8f1d9fdff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 00523603  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523604  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523605:
    // 00523605  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523607  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523610  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523611  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523612  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523613  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523616  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523618  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052361a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052361c  7525                   -jne 0x523643
    if (!cpu.flags.zf)
    {
        goto L_0x00523643;
    }
    // 0052361e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00523623  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523625  e8d642fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052362a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052362c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052362e  7511                   -jne 0x523641
    if (!cpu.flags.zf)
    {
        goto L_0x00523641;
    }
    // 00523630  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00523635  e846f2fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 0052363a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052363c  e974000000             -jmp 0x5236b5
    goto L_0x005236b5;
L_0x00523641:
    // 00523641  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00523643:
    // 00523643  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00523645  7405                   -je 0x52364c
    if (cpu.flags.zf)
    {
        goto L_0x0052364c;
    }
    // 00523647  803900                 +cmp byte ptr [ecx], 0
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
    // 0052364a  7510                   -jne 0x52365c
    if (!cpu.flags.zf)
    {
        goto L_0x0052365c;
    }
L_0x0052364c:
    // 0052364c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052364e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523650  e8dbd0fcff             -call 0x4f0730
    cpu.esp -= 4;
    sub_4f0730(app, cpu);
    if (cpu.terminate) return;
    // 00523655  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523658  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052365a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052365b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052365c:
    // 0052365c  ba081b5500             -mov edx, 0x551b08
    cpu.edx = 5577480 /*0x551b08*/;
    // 00523661  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523663  e85868fcff             -call 0x4e9ec0
    cpu.esp -= 4;
    sub_4e9ec0(app, cpu);
    if (cpu.terminate) return;
    // 00523668  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052366a  7528                   -jne 0x523694
    if (!cpu.flags.zf)
    {
        goto L_0x00523694;
    }
    // 0052366c  83fb04                 +cmp ebx, 4
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
    // 0052366f  731a                   -jae 0x52368b
    if (!cpu.flags.cf)
    {
        goto L_0x0052368b;
    }
    // 00523671  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523673  e87843fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00523678  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 0052367d  e8fef1fdff             -call 0x502880
    cpu.esp -= 4;
    sub_502880(app, cpu);
    if (cpu.terminate) return;
    // 00523682  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523684  83c404                 +add esp, 4
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
    // 00523687  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523688  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523689  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052368a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052368b:
    // 0052368b  a1081b5500             -mov eax, dword ptr [0x551b08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5577480) /* 0x551b08 */);
    // 00523690  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00523692  eb1f                   -jmp 0x5236b3
    goto L_0x005236b3;
L_0x00523694:
    // 00523694  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00523696  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523697  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523699  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052369a  2eff1530455300         -call dword ptr cs:[0x534530]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457200) /* 0x534530 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005236a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005236a3  750e                   -jne 0x5236b3
    if (!cpu.flags.zf)
    {
        goto L_0x005236b3;
    }
    // 005236a5  e84ad9fdff             -call 0x500ff4
    cpu.esp -= 4;
    sub_500ff4(app, cpu);
    if (cpu.terminate) return;
    // 005236aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005236ac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005236af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005236b3:
    // 005236b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x005236b5:
    // 005236b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005236b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005236bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5236c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005236c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005236c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005236c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005236c5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005236ca  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005236cd  743f                   -je 0x52370e
    if (cpu.flags.zf)
    {
        goto L_0x0052370e;
    }
    // 005236cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005236d0  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 005236d2  7542                   -jne 0x523716
    if (!cpu.flags.zf)
    {
        goto L_0x00523716;
    }
L_0x005236d4:
    // 005236d4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005236d6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 005236d8  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 005236db  8a80546d5600           -mov al, byte ptr [eax + 0x566d54]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5664084) /* 0x566d54 */);
    // 005236e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005236e3  83f80f                 +cmp eax, 0xf
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
    // 005236e6  7505                   -jne 0x5236ed
    if (!cpu.flags.zf)
    {
        goto L_0x005236ed;
    }
    // 005236e8  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x005236ed:
    // 005236ed  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 005236f0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 005236f3  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 005236f6  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005236f8  81e2f0000000           -and edx, 0xf0
    cpu.edx &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 005236fe  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523701  7548                   -jne 0x52374b
    if (!cpu.flags.zf)
    {
        goto L_0x0052374b;
    }
    // 00523703  83c00f                 -add eax, 0xf
    (cpu.eax) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00523706  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00523708  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052370b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052370c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052370d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052370e:
    // 0052370e  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00523711  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00523714  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523715  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523716:
    // 00523716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523717  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523718  b90c1b5500             -mov ecx, 0x551b0c
    cpu.ecx = 5577484 /*0x551b0c*/;
    // 0052371d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052371e  bb1c1b5500             -mov ebx, 0x551b1c
    cpu.ebx = 5577500 /*0x551b1c*/;
    // 00523723  be35000000             -mov esi, 0x35
    cpu.esi = 53 /*0x35*/;
    // 00523728  682c1b5500             -push 0x551b2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577516 /*0x551b2c*/;
    cpu.esp -= 4;
    // 0052372d  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00523733  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00523739  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052373f  e8ccd8edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523744  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523747  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523748  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523749  eb89                   -jmp 0x5236d4
    goto L_0x005236d4;
L_0x0052374b:
    // 0052374b  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0052374e  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00523750  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00523753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523754  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523764  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00523767  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00523769  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052376b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052376d  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523773  7c49                   -jl 0x5237be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 00523775  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052377b  7d41                   -jge 0x5237be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 0052377d  3b3504505600           +cmp esi, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523783  7c39                   -jl 0x5237be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 00523785  3b350c505600           +cmp esi, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052378b  7d31                   -jge 0x5237be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x005237be;
    }
    // 0052378d  803d1050560010         +cmp byte ptr [0x565010], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523794  7509                   -jne 0x52379f
    if (!cpu.flags.zf)
    {
        goto L_0x0052379f;
    }
    // 00523796  803d1250560000         +cmp byte ptr [0x565012], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052379d  7427                   -je 0x5237c6
    if (cpu.flags.zf)
    {
        goto L_0x005237c6;
    }
L_0x0052379f:
    // 0052379f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005237a1  c1eb18                 -shr ebx, 0x18
    cpu.ebx >>= 24 /*0x18*/ % 32;
    // 005237a4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005237aa  81fbff000000           +cmp ebx, 0xff
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
    // 005237b0  0f84ae000000           -je 0x523864
    if (cpu.flags.zf)
    {
        goto L_0x00523864;
    }
    // 005237b6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005237b8  0f85c0000000           -jne 0x52387e
    if (!cpu.flags.zf)
    {
        goto L_0x0052387e;
    }
L_0x005237be:
    // 005237be  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005237c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005237c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005237c6:
    // 005237c6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005237c8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005237ca  8b1524505600           -mov edx, dword ptr [0x565024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 005237d0  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 005237d3  8b1520505600           -mov edx, dword ptr [0x565020]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 005237d9  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 005237dc  030514505600           -add eax, dword ptr [0x565014]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */)));
    // 005237e2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 005237e4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005237e6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005237ec  726b                   -jb 0x523859
    if (cpu.flags.cf)
    {
        goto L_0x00523859;
    }
    // 005237ee  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005237f4  7340                   -jae 0x523836
    if (!cpu.flags.cf)
    {
        goto L_0x00523836;
    }
    // 005237f6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 005237f9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005237fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005237fd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00523800  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523803  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00523805  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 0052380b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052380e  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00523813  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00523816  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523818  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0052381a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0052381d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052381f  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00523822  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523824  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00523827  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052382d  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00523832  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00523834  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00523836:
    // 00523836  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00523838  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0052383e  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00523841  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523843  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00523846  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0052384c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0052384f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00523852  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523854  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523856  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00523859:
    // 00523859  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052385c  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0052385f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523862  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523864:
    // 00523864  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523866  e8f5befcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052386b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052386d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052386f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523871  e88a020000             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 00523876  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00523879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052387d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052387e:
    // 0052387e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523880  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00523883  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523888  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052388b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052388d  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00523890  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523896  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052389b  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052389f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005238a3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 005238a5  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 005238aa  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 005238ad  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 005238af  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005238b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005238b3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005238b5  e80603feff             -call 0x503bc0
    cpu.esp -= 4;
    sub_503bc0(app, cpu);
    if (cpu.terminate) return;
    // 005238ba  e8e18afeff             -call 0x50c3a0
    cpu.esp -= 4;
    sub_50c3a0(app, cpu);
    if (cpu.terminate) return;
    // 005238bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005238c1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 005238c4  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238ca  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005238ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005238d0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005238d2  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 005238d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238da  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 005238e0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005238e4  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005238e8  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 005238ed  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 005238f2  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005238f4  2b442414               -sub eax, dword ptr [esp + 0x14]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 005238f8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 005238fb  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 00523900  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523902  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00523905  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00523907  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00523909  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 0052390c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052390e  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00523914  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00523918  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052391a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052391c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052391e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523921  c1e810                 +shr eax, 0x10
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
    // 00523924  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523926  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00523929  39d8                   +cmp eax, ebx
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
    // 0052392b  0f8e77000000           -jle 0x5239a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239a8;
    }
    // 00523931  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00523933:
    // 00523933  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523935  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00523937  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052393b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052393f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00523941  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523944  c1e810                 +shr eax, 0x10
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
    // 00523947  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523949  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052394b  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523950  7e6e                   -jle 0x5239c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239c0;
    }
    // 00523952  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00523957:
    // 00523957  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00523959  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052395b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052395f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00523961  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00523964  c1e810                 +shr eax, 0x10
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
    // 00523967  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523969  03442404               -add eax, dword ptr [esp + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0052396d  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523972  7e60                   -jle 0x5239d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005239d4;
    }
    // 00523974  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00523979:
    // 00523979  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052397d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052397f  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00523982  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00523985  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00523987  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00523989  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0052398c  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052398e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00523990  e8cbbdfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00523995  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00523997  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00523999  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052399b  e860010000             -call 0x523b00
    cpu.esp -= 4;
    sub_523b00(app, cpu);
    if (cpu.terminate) return;
    // 005239a0  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 005239a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005239a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005239a8:
    // 005239a8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239aa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 005239ac  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 005239af  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239b1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239b4  c1e810                 +shr eax, 0x10
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
    // 005239b7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239b9  01d8                   +add eax, ebx
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
    // 005239bb  e973ffffff             -jmp 0x523933
    goto L_0x00523933;
L_0x005239c0:
    // 005239c0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005239c4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239c6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239c8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239cb  c1e810                 +shr eax, 0x10
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
    // 005239ce  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239d0  01e8                   +add eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005239d2  eb83                   -jmp 0x523957
    goto L_0x00523957;
L_0x005239d4:
    // 005239d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 005239d8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005239da  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005239de  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 005239e0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 005239e3  c1e810                 +shr eax, 0x10
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
    // 005239e6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 005239e8  01c8                   +add eax, ecx
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
    // 005239ea  eb8d                   -jmp 0x523979
    goto L_0x00523979;
}

/* align: skip  */
void Application::sub_5239ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005239ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005239ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005239ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005239ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005239f0  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005239f5  0f8efb000000           -jle 0x523af6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523af6;
    }
    // 005239fb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005239fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005239ff  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00523a03  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00523a07  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00523a0b  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523a0f  83f901                 +cmp ecx, 1
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
    // 00523a12  0f8cde000000           -jl 0x523af6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523af6;
    }
    // 00523a18  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00523a1a  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00523a1e  7259                   -jb 0x523a79
    if (cpu.flags.cf)
    {
        goto L_0x00523a79;
    }
L_0x00523a20:
    // 00523a20  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
L_0x00523a24:
    // 00523a24  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a27  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a2a  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00523a2d  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00523a30  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a33  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a36  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523a3a  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523a3e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523a41  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523a43  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523a45  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523a47  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523a4a  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a4d  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a50  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523a54  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523a58  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523a5b  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00523a5d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00523a60  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00523a63  7fbf                   -jg 0x523a24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00523a24;
    }
    // 00523a65  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00523a69  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00523a6d  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523a72  75ac                   -jne 0x523a20
    if (!cpu.flags.zf)
    {
        goto L_0x00523a20;
    }
    // 00523a74  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a75  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523a78  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523a79:
    // 00523a79  8344242801             -add dword ptr [esp + 0x28], 1
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00523a7e  8344242c02             -add dword ptr [esp + 0x2c], 2
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00523a83:
    // 00523a83  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523a87  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523a8a  7441                   -je 0x523acd
    if (cpu.flags.zf)
    {
        goto L_0x00523acd;
    }
L_0x00523a8c:
    // 00523a8c  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a8f  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523a92  8a5f02                 -mov bl, byte ptr [edi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00523a95  8a5703                 -mov dl, byte ptr [edi + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00523a98  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523a9b  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523a9e  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523aa2  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523aa6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00523aa9  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523aab  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523aad  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523aaf  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523ab2  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523ab5  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523ab8  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523abc  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523ac0  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523ac3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00523ac5  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00523ac8  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00523acb  7fbf                   -jg 0x523a8c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00523a8c;
    }
L_0x00523acd:
    // 00523acd  8a3e                   -mov bh, byte ptr [esi]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi);
    // 00523acf  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 00523ad1  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00523ad4  88fe                   -mov dh, bh
    cpu.dh = cpu.bh;
    // 00523ad6  c0ef04                 -shr bh, 4
    cpu.bh >>= 4 /*0x4*/ % 32;
    // 00523ad9  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523adc  8a441d00               -mov al, byte ptr [ebp + ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + cpu.ebx * 1);
    // 00523ae0  8a641500               -mov ah, byte ptr [ebp + edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebp + cpu.edx * 1);
    // 00523ae4  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 00523ae7  03742428               -add esi, dword ptr [esp + 0x28]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 00523aeb  037c242c               -add edi, dword ptr [esp + 0x2c]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 00523aef  836c242401             +sub dword ptr [esp + 0x24], 1
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523af4  758d                   -jne 0x523a83
    if (!cpu.flags.zf)
    {
        goto L_0x00523a83;
    }
L_0x00523af6:
    // 00523af6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523af9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523afa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523b01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523b02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523b03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523b05  3b0500505600           +cmp eax, dword ptr [0x565000]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b0b  0f8c9c000000           -jl 0x523bad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b11  3b0508505600           +cmp eax, dword ptr [0x565008]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b17  0f8d90000000           -jge 0x523bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b1d  3b1504505600           +cmp edx, dword ptr [0x565004]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b23  0f8c84000000           -jl 0x523bad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b29  3b150c505600           +cmp edx, dword ptr [0x56500c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523b2f  0f8d78000000           -jge 0x523bad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523bad;
    }
    // 00523b35  a120505600             -mov eax, dword ptr [0x565020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 00523b3a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00523b3d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523b3f  a124505600             -mov eax, dword ptr [0x565024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 00523b44  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00523b46  8b3488                 -mov esi, dword ptr [eax + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ecx * 4);
    // 00523b49  a114505600             -mov eax, dword ptr [0x565014]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */);
    // 00523b4e  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00523b50  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523b52  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00523b57  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523b59  7356                   -jae 0x523bb1
    if (!cpu.flags.cf)
    {
        goto L_0x00523bb1;
    }
    // 00523b5b  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523b5d  0f836b000000           -jae 0x523bce
    if (!cpu.flags.cf)
    {
        goto L_0x00523bce;
    }
L_0x00523b63:
    // 00523b63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523b64  c7059821550053000000   -mov dword ptr [0x552198], 0x53
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 83 /*0x53*/;
    // 00523b6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523b70  a010505600             -mov al, byte ptr [0x565010]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */);
    // 00523b75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523b76  bf681b5500             -mov edi, 0x551b68
    cpu.edi = 5577576 /*0x551b68*/;
    // 00523b7b  bd781b5500             -mov ebp, 0x551b78
    cpu.ebp = 5577592 /*0x551b78*/;
    // 00523b80  68841b5500             -push 0x551b84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577604 /*0x551b84*/;
    cpu.esp -= 4;
    // 00523b85  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00523b8b  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00523b91  e87ad4edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523b96  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00523b99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00523b9a:
    // 00523b9a  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00523b9d  743b                   -je 0x523bda
    if (cpu.flags.zf)
    {
        goto L_0x00523bda;
    }
    // 00523b9f  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00523ba1  80e70f                 -and bh, 0xf
    cpu.bh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00523ba4  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00523ba6  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 00523ba9  08c7                   +or bh, al
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(cpu.al))));
    // 00523bab  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
L_0x00523bad:
    // 00523bad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523baf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bb1:
    // 00523bb1  7608                   -jbe 0x523bbb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523bbb;
    }
    // 00523bb3  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bb5  730b                   -jae 0x523bc2
    if (!cpu.flags.cf)
    {
        goto L_0x00523bc2;
    }
    // 00523bb7  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bb9  75a8                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
L_0x00523bbb:
    // 00523bbb  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00523bbe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bc0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bc2:
    // 00523bc2  7622                   -jbe 0x523be6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523be6;
    }
    // 00523bc4  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bc6  759b                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
    // 00523bc8  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00523bca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bcd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bce:
    // 00523bce  76ca                   -jbe 0x523b9a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523b9a;
    }
    // 00523bd0  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523bd2  758f                   -jne 0x523b63
    if (!cpu.flags.zf)
    {
        goto L_0x00523b63;
    }
    // 00523bd4  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00523bd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523bda:
    // 00523bda  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00523bdc  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00523bde  08d8                   -or al, bl
    cpu.al |= x86::reg8(x86::sreg8(cpu.bl));
    // 00523be0  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00523be2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523be5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523be6:
    // 00523be6  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00523be9  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00523bec  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00523bef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523bf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523c00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523c01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523c02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523c03  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523c04  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00523c06  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523c09  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523c0b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00523c0d  7507                   -jne 0x523c16
    if (!cpu.flags.zf)
    {
        goto L_0x00523c16;
    }
    // 00523c0f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00523c11  e983000000             -jmp 0x523c99
    goto L_0x00523c99;
L_0x00523c16:
    // 00523c16  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523c18  0f8676000000           -jbe 0x523c94
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
    // 00523c1e  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523c21  7512                   -jne 0x523c35
    if (!cpu.flags.zf)
    {
        goto L_0x00523c35;
    }
    // 00523c23  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00523c25  7405                   -je 0x523c2c
    if (cpu.flags.zf)
    {
        goto L_0x00523c2c;
    }
    // 00523c27  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
L_0x00523c2c:
    // 00523c2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523c2e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523c35:
    // 00523c35  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00523c3c  7419                   -je 0x523c57
    if (cpu.flags.zf)
    {
        goto L_0x00523c57;
    }
    // 00523c3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523c40  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00523c42  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 00523c48  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00523c4a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00523c4f  7406                   -je 0x523c57
    if (cpu.flags.zf)
    {
        goto L_0x00523c57;
    }
    // 00523c51  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523c55  743d                   -je 0x523c94
    if (cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
L_0x00523c57:
    // 00523c57  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523c59  e852790000             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 00523c5e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00523c60  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00523c63  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00523c65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523c66  39c3                   +cmp ebx, eax
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
    // 00523c68  7302                   -jae 0x523c6c
    if (!cpu.flags.cf)
    {
        goto L_0x00523c6c;
    }
    // 00523c6a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00523c6c:
    // 00523c6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523c6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523c6e  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00523c70  a1b8b05600             -mov eax, dword ptr [0x56b0b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */);
    // 00523c75  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523c76  2eff1598455300         -call dword ptr cs:[0x534598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457304) /* 0x534598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00523c7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523c7f  7413                   -je 0x523c94
    if (cpu.flags.zf)
    {
        goto L_0x00523c94;
    }
    // 00523c81  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00523c83  7406                   -je 0x523c8b
    if (cpu.flags.zf)
    {
        goto L_0x00523c8b;
    }
    // 00523c85  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00523c88  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00523c8b:
    // 00523c8b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00523c8d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523c94:
    // 00523c94  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00523c99:
    // 00523c99  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00523c9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523c9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523ca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523ca1  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 00523ca7  743f                   -je 0x523ce8
    if (cpu.flags.zf)
    {
        goto L_0x00523ce8;
    }
    // 00523ca9  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523cab  01c0                   +add eax, eax
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
    // 00523cad  11d2                   +adc edx, edx
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
    // 00523caf  d1db                   -rcr ebx, 1
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
    // 00523cb1  0500000020             +add eax, 0x20000000
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
    // 00523cb6  83d200                 +adc edx, 0
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
    // 00523cb9  7424                   -je 0x523cdf
    if (cpu.flags.zf)
    {
        goto L_0x00523cdf;
    }
    // 00523cbb  81fa0000e08f           +cmp edx, 0x8fe00000
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
    // 00523cc1  731c                   -jae 0x523cdf
    if (!cpu.flags.cf)
    {
        goto L_0x00523cdf;
    }
    // 00523cc3  81fa00002070           +cmp edx, 0x70200000
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
    // 00523cc9  721d                   -jb 0x523ce8
    if (cpu.flags.cf)
    {
        goto L_0x00523ce8;
    }
    // 00523ccb  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 00523cd1  01c0                   +add eax, eax
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
    // 00523cd3  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523cd5  01c0                   +add eax, eax
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
    // 00523cd7  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00523cd9  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523cdb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00523cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523cde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523cdf:
    // 00523cdf  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 00523ce4  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00523ce6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ce7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523ce8:
    // 00523ce8  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00523cea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ceb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_523cec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523cec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00523cee  7507                   -jne 0x523cf7
    if (!cpu.flags.zf)
    {
        goto L_0x00523cf7;
    }
    // 00523cf0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00523cf2  7503                   -jne 0x523cf7
    if (!cpu.flags.zf)
    {
        goto L_0x00523cf7;
    }
    // 00523cf4  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523cf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523cf7:
    // 00523cf7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523cf8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523cf9  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00523cfb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523cfd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523cfe  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523d00  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00523d02  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d03  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 00523d05  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00523d07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523d11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523d12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523d14  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00523d16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523d18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d1a  763c                   -jbe 0x523d58
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
L_0x00523d1c:
    // 00523d1c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d1e  e89d130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d25  7531                   -jne 0x523d58
    if (!cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
    // 00523d27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d29  e892130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d30  7526                   -jne 0x523d58
    if (!cpu.flags.zf)
    {
        goto L_0x00523d58;
    }
    // 00523d32  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00523d34  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d36  e8a5780000             -call 0x52b5e0
    cpu.esp -= 4;
    sub_52b5e0(app, cpu);
    if (cpu.terminate) return;
    // 00523d3b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523d3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d3f  753d                   -jne 0x523d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00523d7e;
    }
    // 00523d41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d43  e8b8130000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 00523d48  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00523d4a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d4c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00523d4d  e8ae130000             -call 0x525100
    cpu.esp -= 4;
    sub_525100(app, cpu);
    if (cpu.terminate) return;
    // 00523d52  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00523d54  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d56  77c4                   -ja 0x523d1c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00523d1c;
    }
L_0x00523d58:
    // 00523d58  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00523d5a  7620                   -jbe 0x523d7c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00523d7c;
    }
    // 00523d5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00523d5e  e85d130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d65  750b                   -jne 0x523d72
    if (!cpu.flags.zf)
    {
        goto L_0x00523d72;
    }
    // 00523d67  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00523d69  e852130000             -call 0x5250c0
    cpu.esp -= 4;
    sub_5250c0(app, cpu);
    if (cpu.terminate) return;
    // 00523d6e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00523d70  740a                   -je 0x523d7c
    if (cpu.flags.zf)
    {
        goto L_0x00523d7c;
    }
L_0x00523d72:
    // 00523d72  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523d74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523d76  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00523d78  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00523d7a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00523d7c:
    // 00523d7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00523d7e:
    // 00523d7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523d80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523d92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_523d94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523d94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523d95  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523d96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523d97  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523d9a  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00523d9e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00523da2  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00523da4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00523da6  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00523daa  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00523dae  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00523db1  81c658f69e00           -add esi, 0x9ef658
    (cpu.esi) += x86::reg32(x86::sreg32(10417752 /*0x9ef658*/));
    // 00523db7  c6460601               -mov byte ptr [esi + 6], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 00523dbb  66c7460a0000           -mov word ptr [esi + 0xa], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 00523dc1  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00523dc8  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00523dcb  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 00523dce  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00523dd2  2403                   -and al, 3
    cpu.al &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00523dd4  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00523dd7  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00523ddb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00523ddd  663d0c00               +cmp ax, 0xc
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(12 /*0xc*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00523de1  0f84a1000000           -je 0x523e88
    if (cpu.flags.zf)
    {
        goto L_0x00523e88;
    }
    // 00523de7  663d1000               +cmp ax, 0x10
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
    // 00523deb  0f85a4000000           -jne 0x523e95
    if (!cpu.flags.zf)
    {
        goto L_0x00523e95;
    }
    // 00523df1  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523df5  c6460409               -mov byte ptr [esi + 4], 9
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 9 /*0x9*/;
L_0x00523df9:
    // 00523df9  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00523dfd  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00523dff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00523e01  e8eae4ffff             -call 0x5222f0
    cpu.esp -= 4;
    sub_5222f0(app, cpu);
    if (cpu.terminate) return;
    // 00523e06  807e0210               +cmp byte ptr [esi + 2], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523e0a  0f85e9000000           -jne 0x523ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00523ef9;
    }
    // 00523e10  807e0301               +cmp byte ptr [esi + 3], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523e14  0f85df000000           -jne 0x523ef9
    if (!cpu.flags.zf)
    {
        goto L_0x00523ef9;
    }
    // 00523e1a  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
L_0x00523e1f:
    // 00523e1f  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00523e23  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00523e25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00523e27  668b1514f69e00         -mov dx, word ptr [0x9ef614]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00523e2e  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00523e31  e8daf0ffff             -call 0x522f10
    cpu.esp -= 4;
    sub_522f10(app, cpu);
    if (cpu.terminate) return;
    // 00523e36  8b1514f69e00           -mov edx, dword ptr [0x9ef614]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10417684) /* 0x9ef614 */);
    // 00523e3c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00523e3f  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00523e41  83ff64                 +cmp edi, 0x64
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
    // 00523e44  0f8e2d010000           -jle 0x523f77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523f77;
    }
    // 00523e4a  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x00523e4f:
    // 00523e4f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00523e53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523e54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523e55  c6460500               -mov byte ptr [esi + 5], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 00523e59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523e5a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00523e5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523e5f  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00523e63  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523e64  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00523e66  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00523e68  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00523e6a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00523e6e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00523e70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00523e72  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00523e75  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00523e77  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00523e7a  e839c2fdff             -call 0x5000b8
    cpu.esp -= 4;
    sub_5000b8(app, cpu);
    if (cpu.terminate) return;
    // 00523e7f  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00523e82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523e85  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523e88:
    // 00523e88  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523e8c  c6460407               -mov byte ptr [esi + 4], 7
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 7 /*0x7*/;
    // 00523e90  e964ffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523e95:
    // 00523e95  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00523e99  750d                   -jne 0x523ea8
    if (!cpu.flags.zf)
    {
        goto L_0x00523ea8;
    }
    // 00523e9b  c6460208               -mov byte ptr [esi + 2], 8
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 8 /*0x8*/;
    // 00523e9f  c6460400               -mov byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00523ea3  e951ffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523ea8:
    // 00523ea8  66f74102fcff           +test word ptr [ecx + 2], 0xfffc
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) & 65532 /*0xfffc*/));
    // 00523eae  750d                   -jne 0x523ebd
    if (!cpu.flags.zf)
    {
        goto L_0x00523ebd;
    }
    // 00523eb0  c6460210               -mov byte ptr [esi + 2], 0x10
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = 16 /*0x10*/;
    // 00523eb4  c6460400               -mov byte ptr [esi + 4], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00523eb8  e93cffffff             -jmp 0x523df9
    goto L_0x00523df9;
L_0x00523ebd:
    // 00523ebd  bab01b5500             -mov edx, 0x551bb0
    cpu.edx = 5577648 /*0x551bb0*/;
    // 00523ec2  b9c01b5500             -mov ecx, 0x551bc0
    cpu.ecx = 5577664 /*0x551bc0*/;
    // 00523ec7  bb44000000             -mov ebx, 0x44
    cpu.ebx = 68 /*0x44*/;
    // 00523ecc  68d81b5500             -push 0x551bd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577688 /*0x551bd8*/;
    cpu.esp -= 4;
    // 00523ed1  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00523ed7  890d94215500           -mov dword ptr [0x552194], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ecx;
    // 00523edd  891d98215500           -mov dword ptr [0x552198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebx;
    // 00523ee3  e828d1edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523ee8  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 00523eed  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523ef0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523ef3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523ef6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523ef9:
    // 00523ef9  807e0210               +cmp byte ptr [esi + 2], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523efd  7510                   -jne 0x523f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00523f0f;
    }
    // 00523eff  807e0302               +cmp byte ptr [esi + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f03  750a                   -jne 0x523f0f
    if (!cpu.flags.zf)
    {
        goto L_0x00523f0f;
    }
    // 00523f05  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 00523f0a  e910ffffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f0f:
    // 00523f0f  807e0208               +cmp byte ptr [esi + 2], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f13  7510                   -jne 0x523f25
    if (!cpu.flags.zf)
    {
        goto L_0x00523f25;
    }
    // 00523f15  807e0301               +cmp byte ptr [esi + 3], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f19  750a                   -jne 0x523f25
    if (!cpu.flags.zf)
    {
        goto L_0x00523f25;
    }
    // 00523f1b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00523f20  e9fafeffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f25:
    // 00523f25  807e0208               +cmp byte ptr [esi + 2], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f29  7510                   -jne 0x523f3b
    if (!cpu.flags.zf)
    {
        goto L_0x00523f3b;
    }
    // 00523f2b  807e0302               +cmp byte ptr [esi + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f2f  750a                   -jne 0x523f3b
    if (!cpu.flags.zf)
    {
        goto L_0x00523f3b;
    }
    // 00523f31  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00523f36  e9e4feffff             -jmp 0x523e1f
    goto L_0x00523e1f;
L_0x00523f3b:
    // 00523f3b  beb01b5500             -mov esi, 0x551bb0
    cpu.esi = 5577648 /*0x551bb0*/;
    // 00523f40  bfc01b5500             -mov edi, 0x551bc0
    cpu.edi = 5577664 /*0x551bc0*/;
    // 00523f45  bd59000000             -mov ebp, 0x59
    cpu.ebp = 89 /*0x59*/;
    // 00523f4a  68181c5500             -push 0x551c18
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577752 /*0x551c18*/;
    cpu.esp -= 4;
    // 00523f4f  893590215500           -mov dword ptr [0x552190], esi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.esi;
    // 00523f55  893d94215500           -mov dword ptr [0x552194], edi
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 00523f5b  892d98215500           -mov dword ptr [0x552198], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 00523f61  e8aad0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00523f66  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00523f6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00523f6e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00523f71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523f74  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00523f77:
    // 00523f77  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00523f79  0f8dd0feffff           -jge 0x523e4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00523e4f;
    }
    // 00523f7f  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00523f81  e9c9feffff             -jmp 0x523e4f
    goto L_0x00523e4f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_523f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00523f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00523f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00523f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00523f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00523f94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00523f95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00523f96  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00523f98  80780500               +cmp byte ptr [eax + 5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523f9c  7c3f                   -jl 0x523fdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00523fdd;
    }
L_0x00523f9e:
    // 00523f9e  807a0600               +cmp byte ptr [edx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fa2  7c70                   -jl 0x524014
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524014;
    }
L_0x00523fa4:
    // 00523fa4  807a0800               +cmp byte ptr [edx + 8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fa8  0f8c9f000000           -jl 0x52404d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052404d;
    }
L_0x00523fae:
    // 00523fae  807a0900               +cmp byte ptr [edx + 9], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fb2  0f8ccf000000           -jl 0x524087
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524087;
    }
L_0x00523fb8:
    // 00523fb8  807a0a00               +cmp byte ptr [edx + 0xa], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fbc  0f8cfe000000           -jl 0x5240c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005240c0;
    }
L_0x00523fc2:
    // 00523fc2  807a0b00               +cmp byte ptr [edx + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fc6  0f856a010000           -jne 0x524136
    if (!cpu.flags.zf)
    {
        goto L_0x00524136;
    }
    // 00523fcc  807a0700               +cmp byte ptr [edx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00523fd0  0f8c24010000           -jl 0x5240fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005240fa;
    }
L_0x00523fd6:
    // 00523fd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00523fdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00523fdd:
    // 00523fdd  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00523fe0  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00523fe5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00523fe8  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 00523fed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00523fee  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00523ff3  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00523ff9  68741c5500             -push 0x551c74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577844 /*0x551c74*/;
    cpu.esp -= 4;
    // 00523ffe  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524004  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052400a  e801d0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052400f  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524012  eb8a                   -jmp 0x523f9e
    goto L_0x00523f9e;
L_0x00524014:
    // 00524014  c705982155000d000000   -mov dword ptr [0x552198], 0xd
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 13 /*0xd*/;
    // 0052401e  8b4203                 -mov eax, dword ptr [edx + 3]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 00524021  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524024  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524025  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 0052402a  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 0052402f  68ac1c5500             -push 0x551cac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577900 /*0x551cac*/;
    cpu.esp -= 4;
    // 00524034  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 0052403a  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 00524040  e8cbcfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524045  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524048  e957ffffff             -jmp 0x523fa4
    goto L_0x00523fa4;
L_0x0052404d:
    // 0052404d  8b4205                 -mov eax, dword ptr [edx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 00524050  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00524055  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524058  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 0052405d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052405e  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00524063  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00524069  68e81c5500             -push 0x551ce8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5577960 /*0x551ce8*/;
    cpu.esp -= 4;
    // 0052406e  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524074  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052407a  e891cfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052407f  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524082  e927ffffff             -jmp 0x523fae
    goto L_0x00523fae;
L_0x00524087:
    // 00524087  c7059821550013000000   -mov dword ptr [0x552198], 0x13
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 19 /*0x13*/;
    // 00524091  8b4206                 -mov eax, dword ptr [edx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00524094  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00524097  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524098  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 0052409d  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 005240a2  681c1d5500             -push 0x551d1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578012 /*0x551d1c*/;
    cpu.esp -= 4;
    // 005240a7  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 005240ad  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 005240b3  e858cfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005240b8  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005240bb  e9f8feffff             -jmp 0x523fb8
    goto L_0x00523fb8;
L_0x005240c0:
    // 005240c0  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 005240c3  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 005240c8  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 005240cb  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 005240d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005240d1  be16000000             -mov esi, 0x16
    cpu.esi = 22 /*0x16*/;
    // 005240d6  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 005240dc  68541d5500             -push 0x551d54
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578068 /*0x551d54*/;
    cpu.esp -= 4;
    // 005240e1  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 005240e7  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 005240ed  e81ecfedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005240f2  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005240f5  e9c8feffff             -jmp 0x523fc2
    goto L_0x00523fc2;
L_0x005240fa:
    // 005240fa  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005240fd  b9501c5500             -mov ecx, 0x551c50
    cpu.ecx = 5577808 /*0x551c50*/;
    // 00524102  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00524105  bb601c5500             -mov ebx, 0x551c60
    cpu.ebx = 5577824 /*0x551c60*/;
    // 0052410a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052410b  be1b000000             -mov esi, 0x1b
    cpu.esi = 27 /*0x1b*/;
    // 00524110  890d90215500           -mov dword ptr [0x552190], ecx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 00524116  68901d5500             -push 0x551d90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578128 /*0x551d90*/;
    cpu.esp -= 4;
    // 0052411b  891d94215500           -mov dword ptr [0x552194], ebx
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 00524121  893598215500           -mov dword ptr [0x552198], esi
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 00524127  e8e4ceedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052412c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052412f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524130  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524131  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524132  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524133  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524134  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524135  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524136:
    // 00524136  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00524139  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052413c  3d00c0ffff             +cmp eax, 0xffffc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294950912 /*0xffffc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524141  7c0c                   -jl 0x52414f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052414f;
    }
    // 00524143  66817a0eff3f           +cmp word ptr [edx + 0xe], 0x3fff
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16383 /*0x3fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524149  0f8e87feffff           -jle 0x523fd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00523fd6;
    }
L_0x0052414f:
    // 0052414f  c7059821550020000000   -mov dword ptr [0x552198], 0x20
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = 32 /*0x20*/;
    // 00524159  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052415c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052415f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524160  bf501c5500             -mov edi, 0x551c50
    cpu.edi = 5577808 /*0x551c50*/;
    // 00524165  bd601c5500             -mov ebp, 0x551c60
    cpu.ebp = 5577824 /*0x551c60*/;
    // 0052416a  68c41d5500             -push 0x551dc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578180 /*0x551dc4*/;
    cpu.esp -= 4;
    // 0052416f  893d90215500           -mov dword ptr [0x552190], edi
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edi;
    // 00524175  892d94215500           -mov dword ptr [0x552194], ebp
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebp;
    // 0052417b  e890ceedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524180  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00524183  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524184  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524186  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524187  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524188  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524189  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524190  803d64af560000         +cmp byte ptr [0x56af64], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5680996) /* 0x56af64 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00524197  741a                   -je 0x5241b3
    if (cpu.flags.zf)
    {
        goto L_0x005241b3;
    }
    // 00524199  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0052419f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005241a1  cc                     -int3 
    NFS2_ASSERT(false);
    // 005241a2  eb06                   -jmp 0x5241aa
    goto L_0x005241aa;
    // 005241a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005241a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005241a6  49                     -dec ecx
    (cpu.ecx)--;
    // 005241a7  44                     -inc esp
    (cpu.esp)++;
    // 005241a8  45                     -inc ebp
    (cpu.ebp)++;
    // 005241a9  4f                     -dec edi
    (cpu.edi)--;
L_0x005241aa:
    // 005241aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005241af  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005241b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005241b3:
    // 005241b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005241b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5241c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005241c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005241c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005241c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005241c4  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005241ca  a14c6f5600             -mov eax, dword ptr [0x566f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 005241cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005241d1  741c                   -je 0x5241ef
    if (cpu.flags.zf)
    {
        goto L_0x005241ef;
    }
L_0x005241d3:
    // 005241d3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 005241d5  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 005241d8  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 005241db  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 005241dd  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 005241e0  39f3                   +cmp ebx, esi
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
    // 005241e2  7505                   -jne 0x5241e9
    if (!cpu.flags.zf)
    {
        goto L_0x005241e9;
    }
    // 005241e4  e873000000             -call 0x52425c
    cpu.esp -= 4;
    sub_52425c(app, cpu);
    if (cpu.terminate) return;
L_0x005241e9:
    // 005241e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005241eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005241ed  75e4                   -jne 0x5241d3
    if (!cpu.flags.zf)
    {
        goto L_0x005241d3;
    }
L_0x005241ef:
    // 005241ef  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005241f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005241f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005241fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5241fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005241fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005241fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005241fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005241ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524200  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524201  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524203  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00524208  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0052420a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052420b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052420e  2eff1528465300         -call dword ptr cs:[0x534628]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457448) /* 0x534628 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524215  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524217  7507                   -jne 0x524220
    if (!cpu.flags.zf)
    {
        goto L_0x00524220;
    }
    // 00524219  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052421e  eb36                   -jmp 0x524256
    goto L_0x00524256;
L_0x00524220:
    // 00524220  3b1d506f5600           +cmp ebx, dword ptr [0x566f50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524226  751c                   -jne 0x524244
    if (!cpu.flags.zf)
    {
        goto L_0x00524244;
    }
    // 00524228  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052422a  7408                   -je 0x524234
    if (cpu.flags.zf)
    {
        goto L_0x00524234;
    }
    // 0052422c  8935506f5600           -mov dword ptr [0x566f50], esi
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.esi;
    // 00524232  eb10                   -jmp 0x524244
    goto L_0x00524244;
L_0x00524234:
    // 00524234  a14c6f5600             -mov eax, dword ptr [0x566f4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 00524239  8935546f5600           -mov dword ptr [0x566f54], esi
    app->getMemory<x86::reg32>(x86::reg32(5664596) /* 0x566f54 */) = cpu.esi;
    // 0052423f  a3506f5600             -mov dword ptr [0x566f50], eax
    app->getMemory<x86::reg32>(x86::reg32(5664592) /* 0x566f50 */) = cpu.eax;
L_0x00524244:
    // 00524244  3b1d00389f00           +cmp ebx, dword ptr [0x9f3800]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052424a  7508                   -jne 0x524254
    if (!cpu.flags.zf)
    {
        goto L_0x00524254;
    }
    // 0052424c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052424e  893d00389f00           -mov dword ptr [0x9f3800], edi
    app->getMemory<x86::reg32>(x86::reg32(10434560) /* 0x9f3800 */) = cpu.edi;
L_0x00524254:
    // 00524254  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00524256:
    // 00524256  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052425a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052425b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52425c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052425c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052425d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052425e  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00524261  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524264  e893ffffff             -call 0x5241fc
    cpu.esp -= 4;
    sub_5241fc(app, cpu);
    if (cpu.terminate) return;
    // 00524269  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052426b  7516                   -jne 0x524283
    if (!cpu.flags.zf)
    {
        goto L_0x00524283;
    }
    // 0052426d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052426f  7508                   -jne 0x524279
    if (!cpu.flags.zf)
    {
        goto L_0x00524279;
    }
    // 00524271  89154c6f5600           -mov dword ptr [0x566f4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */) = cpu.edx;
    // 00524277  eb03                   -jmp 0x52427c
    goto L_0x0052427c;
L_0x00524279:
    // 00524279  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x0052427c:
    // 0052427c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052427e  7403                   -je 0x524283
    if (cpu.flags.zf)
    {
        goto L_0x00524283;
    }
    // 00524280  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00524283:
    // 00524283  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524284  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524290  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524291  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524292  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00524294  8b1520785600           -mov edx, dword ptr [0x567820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 0052429a  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0052429d  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 005242a0  e81b03fdff             -call 0x4f45c0
    cpu.esp -= 4;
    sub_4f45c0(app, cpu);
    if (cpu.terminate) return;
    // 005242a5  39c2                   +cmp edx, eax
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
    // 005242a7  7316                   -jae 0x5242bf
    if (!cpu.flags.cf)
    {
        goto L_0x005242bf;
    }
    // 005242a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005242aa  e86103fdff             -call 0x4f4610
    cpu.esp -= 4;
    sub_4f4610(app, cpu);
    if (cpu.terminate) return;
    // 005242af  a120785600             -mov eax, dword ptr [0x567820]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 005242b4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 005242b7  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 005242b9  29c4                   +sub esp, eax
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
    // 005242bb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005242bd  eb02                   -jmp 0x5242c1
    goto L_0x005242c1;
L_0x005242bf:
    // 005242bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x005242c1:
    // 005242c1  8b1520785600           -mov edx, dword ptr [0x567820]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666848) /* 0x567820 */);
    // 005242c7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005242c9  a324785600             -mov dword ptr [0x567824], eax
    app->getMemory<x86::reg32>(x86::reg32(5666852) /* 0x567824 */) = cpu.eax;
    // 005242ce  e86d730000             -call 0x52b640
    cpu.esp -= 4;
    sub_52b640(app, cpu);
    if (cpu.terminate) return;
    // 005242d3  8b151482a100           -mov edx, dword ptr [0xa18214]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584596) /* 0xa18214 */);
    // 005242d9  a11082a100             -mov eax, dword ptr [0xa18210]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584592) /* 0xa18210 */);
    // 005242de  e80df7f7ff             -call 0x4a39f0
    cpu.esp -= 4;
    sub_4a39f0(app, cpu);
    if (cpu.terminate) return;
    // 005242e3  e81cbafbff             -call 0x4dfd04
    cpu.esp -= 4;
    sub_4dfd04(app, cpu);
    if (cpu.terminate) return;
    // 005242e8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005242ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005242eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005242ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_5242f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005242f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005242f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005242f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005242f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005242f4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005242f7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005242fb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 005242fd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00524300  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524302  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524304  0f8471000000           -je 0x52437b
    if (cpu.flags.zf)
    {
        goto L_0x0052437b;
    }
L_0x0052430a:
    // 0052430a  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052430e  0f8689000000           -jbe 0x52439d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 00524314  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00524318  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0052431b  7420                   -je 0x52433d
    if (cpu.flags.zf)
    {
        goto L_0x0052433d;
    }
    // 0052431d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052431f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524323  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00524326  e8359dffff             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 0052432b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052432d  83f8ff                 +cmp eax, -1
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
    // 00524330  0f8469000000           -je 0x52439f
    if (cpu.flags.zf)
    {
        goto L_0x0052439f;
    }
    // 00524336  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524339  7762                   -ja 0x52439d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 0052433b  eb09                   -jmp 0x524346
    goto L_0x00524346;
L_0x0052433d:
    // 0052433d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524341  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00524344  eb57                   -jmp 0x52439d
    goto L_0x0052439d;
L_0x00524346:
    // 00524346  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052434a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052434e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524350  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00524351  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00524353  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00524355  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524356  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00524358  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052435b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0052435d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052435f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00524362  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00524364  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524365  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00524366  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00524369  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052436b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052436e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00524370  29d0                   +sub eax, edx
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
    // 00524372  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00524376  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00524379  eb8f                   -jmp 0x52430a
    goto L_0x0052430a;
L_0x0052437b:
    // 0052437b  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524380  741b                   -je 0x52439d
    if (cpu.flags.zf)
    {
        goto L_0x0052439d;
    }
    // 00524382  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524384  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524388  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 0052438c  e8cf9cffff             -call 0x51e060
    cpu.esp -= 4;
    sub_51e060(app, cpu);
    if (cpu.terminate) return;
    // 00524391  83f8ff                 +cmp eax, -1
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
    // 00524394  7409                   -je 0x52439f
    if (cpu.flags.zf)
    {
        goto L_0x0052439f;
    }
    // 00524396  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00524399  01c3                   +add ebx, eax
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
    // 0052439b  ebde                   -jmp 0x52437b
    goto L_0x0052437b;
L_0x0052439d:
    // 0052439d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0052439f:
    // 0052439f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 005243a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5243a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005243a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005243a8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 005243aa  e802000000             -call 0x5243b1
    cpu.esp -= 4;
    sub_5243b1(app, cpu);
    if (cpu.terminate) return;
    // 005243af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005243b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5243b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005243b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005243b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005243b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005243b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005243b6  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 005243b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005243bb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 005243bd  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 005243c0  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 005243c3  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 005243c6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 005243c8  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 005243cb  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 005243ce  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 005243d1  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 005243d4  7407                   -je 0x5243dd
    if (cpu.flags.zf)
    {
        goto L_0x005243dd;
    }
    // 005243d6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 005243db  eb3a                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243dd:
    // 005243dd  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 005243e0  7407                   -je 0x5243e9
    if (cpu.flags.zf)
    {
        goto L_0x005243e9;
    }
    // 005243e2  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005243e7  eb2e                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243e9:
    // 005243e9  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 005243ec  7407                   -je 0x5243f5
    if (cpu.flags.zf)
    {
        goto L_0x005243f5;
    }
    // 005243ee  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 005243f3  eb22                   -jmp 0x524417
    goto L_0x00524417;
L_0x005243f5:
    // 005243f5  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 005243f8  7407                   -je 0x524401
    if (cpu.flags.zf)
    {
        goto L_0x00524401;
    }
    // 005243fa  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 005243ff  eb16                   -jmp 0x524417
    goto L_0x00524417;
L_0x00524401:
    // 00524401  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00524404  7407                   -je 0x52440d
    if (cpu.flags.zf)
    {
        goto L_0x0052440d;
    }
    // 00524406  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0052440b  eb0a                   -jmp 0x524417
    goto L_0x00524417;
L_0x0052440d:
    // 0052440d  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00524410  7405                   -je 0x524417
    if (cpu.flags.zf)
    {
        goto L_0x00524417;
    }
    // 00524412  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x00524417:
    // 00524417  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00524419  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0052441c  8b048570af5600         -mov eax, dword ptr [eax*4 + 0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */ + cpu.eax * 4);
    // 00524423  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 00524426  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00524429  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0052442c  740d                   -je 0x52443b
    if (cpu.flags.zf)
    {
        goto L_0x0052443b;
    }
    // 0052442e  dd057c215500           +fld qword ptr [0x55217c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5579132) /* 0x55217c */)));
    // 00524434  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00524436  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00524439  eb42                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052443b:
    // 0052443b  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0052443e  740a                   -je 0x52444a
    if (cpu.flags.zf)
    {
        goto L_0x0052444a;
    }
    // 00524440  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00524442  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00524445  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00524448  eb33                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052444a:
    // 0052444a  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 0052444d  740f                   -je 0x52445e
    if (cpu.flags.zf)
    {
        goto L_0x0052445e;
    }
    // 0052444f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00524451  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 00524456  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00524459  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 0052445c  eb1f                   -jmp 0x52447d
    goto L_0x0052447d;
L_0x0052445e:
    // 0052445e  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00524461  740f                   -je 0x524472
    if (cpu.flags.zf)
    {
        goto L_0x00524472;
    }
    // 00524463  a17c215500             -mov eax, dword ptr [0x55217c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579132) /* 0x55217c */);
    // 00524468  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 0052446b  a180215500             -mov eax, dword ptr [0x552180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5579136) /* 0x552180 */);
    // 00524470  eb08                   -jmp 0x52447a
    goto L_0x0052447a;
L_0x00524472:
    // 00524472  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00524474  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00524477  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x0052447a:
    // 0052447a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x0052447d:
    // 0052447d  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00524480  e80a720000             -call 0x52b68f
    cpu.esp -= 4;
    sub_52b68f(app, cpu);
    if (cpu.terminate) return;
    // 00524485  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00524488  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524489  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052448a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052448b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52448c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052448c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052448d  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524491  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00524494  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00524499  751c                   -jne 0x5244b7
    if (!cpu.flags.zf)
    {
        goto L_0x005244b7;
    }
    // 0052449b  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244a2  750c                   -jne 0x5244b0
    if (!cpu.flags.zf)
    {
        goto L_0x005244b0;
    }
    // 005244a4  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244a7  7507                   -jne 0x5244b0
    if (!cpu.flags.zf)
    {
        goto L_0x005244b0;
    }
    // 005244a9  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 005244ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244b0:
    // 005244b0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 005244b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244b7:
    // 005244b7  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 005244bd  7516                   -jne 0x5244d5
    if (!cpu.flags.zf)
    {
        goto L_0x005244d5;
    }
    // 005244bf  83780400               +cmp dword ptr [eax + 4], 0
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
    // 005244c3  7509                   -jne 0x5244ce
    if (!cpu.flags.zf)
    {
        goto L_0x005244ce;
    }
    // 005244c5  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005244c8  7504                   -jne 0x5244ce
    if (!cpu.flags.zf)
    {
        goto L_0x005244ce;
    }
    // 005244ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005244cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244ce:
    // 005244ce  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 005244d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005244d5:
    // 005244d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005244da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5244e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005244e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005244e1  ff153cf99e00           -call dword ptr [0x9ef93c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005244e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005244e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005244ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_5244f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005244f0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005244f2  e93931fcff             -jmp 0x4e7630
    return sub_4e7630(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_524500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524500  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524504  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524506  741f                   -je 0x524527
    if (cpu.flags.zf)
    {
        goto L_0x00524527;
    }
    // 00524508  68d0389f00             -push 0x9f38d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 10434768 /*0x9f38d0*/;
    cpu.esp -= 4;
    // 0052450d  6828b95600             -push 0x56b928
    app->getMemory<x86::reg32>(cpu.esp-4) = 5683496 /*0x56b928*/;
    cpu.esp -= 4;
    // 00524512  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00524514  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524515  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524517  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524519  7403                   -je 0x52451e
    if (cpu.flags.zf)
    {
        goto L_0x0052451e;
    }
    // 0052451b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052451e:
    // 0052451e  ff053c3d9f00           -inc dword ptr [0x9f3d3c]
    (app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */))++;
    // 00524524  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00524527:
    // 00524527  a1d0389f00             -mov eax, dword ptr [0x9f38d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */);
    // 0052452c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052452d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0052452f  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524532  8b0d3c3d9f00           -mov ecx, dword ptr [0x9f3d3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */);
    // 00524538  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052453a  41                     -inc ecx
    (cpu.ecx)++;
    // 0052453b  8915d0389f00           -mov dword ptr [0x9f38d0], edx
    app->getMemory<x86::reg32>(x86::reg32(10434768) /* 0x9f38d0 */) = cpu.edx;
    // 00524541  890d3c3d9f00           -mov dword ptr [0x9f3d3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(10435900) /* 0x9f3d3c */) = cpu.ecx;
    // 00524547  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_524550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524550  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00524555  741b                   -je 0x524572
    if (cpu.flags.zf)
    {
        goto L_0x00524572;
    }
    // 00524557  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524558  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 0052455e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052455f  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524566  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052456a  a380715600             -mov dword ptr [0x567180], eax
    app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */) = cpu.eax;
    // 0052456f  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00524572:
    // 00524572  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524578  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524579  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052457f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524583  a380715600             -mov dword ptr [0x567180], eax
    app->getMemory<x86::reg32>(x86::reg32(5665152) /* 0x567180 */) = cpu.eax;
    // 00524588  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_5245a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005245a0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005245a4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005245a8  83fa03                 +cmp edx, 3
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
    // 005245ab  7710                   -ja 0x5245bd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005245bd;
    }
    // 005245ad  ff24958c455200         -jmp dword ptr [edx*4 + 0x52458c]
    cpu.ip = app->getMemory<x86::reg32>(5391756 + cpu.edx * 4); goto dynamic_jump;
  case 0x005245b4:
    // 005245b4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245b5  e856caedff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 005245ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005245bd:
    // 005245bd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245c0:
    // 005245c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245c1  e82ac3fbff             -call 0x4e08f0
    cpu.esp -= 4;
    sub_4e08f0(app, cpu);
    if (cpu.terminate) return;
    // 005245c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005245c9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245cc:
    // 005245cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245cd  e8eeb0fbff             -call 0x4df6c0
    cpu.esp -= 4;
    sub_4df6c0(app, cpu);
    if (cpu.terminate) return;
    // 005245d2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005245d5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  case 0x005245d8:
    // 005245d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005245d9  2eff159c455300         -call dword ptr cs:[0x53459c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457308) /* 0x53459c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005245e0  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5245f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005245f0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005245f4  83f801                 +cmp eax, 1
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
    // 005245f7  7210                   -jb 0x524609
    if (cpu.flags.cf)
    {
        goto L_0x00524609;
    }
    // 005245f9  760e                   -jbe 0x524609
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00524609;
    }
    // 005245fb  83f802                 +cmp eax, 2
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
    // 005245fe  7509                   -jne 0x524609
    if (!cpu.flags.zf)
    {
        goto L_0x00524609;
    }
    // 00524600  833d8471560000         +cmp dword ptr [0x567184], 0
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
    // 00524607  7503                   -jne 0x52460c
    if (!cpu.flags.zf)
    {
        goto L_0x0052460c;
    }
L_0x00524609:
    // 00524609  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0052460c:
    // 0052460c  ff1584715600           -call dword ptr [0x567184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5665156) /* 0x567184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524612  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_524620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524620  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524621  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00524626  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524628  e823000000             -call 0x524650
    cpu.esp -= 4;
    sub_524650(app, cpu);
    if (cpu.terminate) return;
    // 0052462d  891518445600           -mov dword ptr [0x564418], edx
    app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */) = cpu.edx;
    // 00524633  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524634  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_524640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524640  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00524645  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0052464b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0052464e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
    // 00524650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524651  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524653  8a25f0af5600           -mov ah, byte ptr [0x56aff0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524659  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052465b  0f844a010000           -je 0x5247ab
    if (cpu.flags.zf)
    {
        return sub_5247ab(app, cpu);
    }
    // 00524661  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524668  740a                   -je 0x524674
    if (cpu.flags.zf)
    {
        goto L_0x00524674;
    }
    // 0052466a  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 0052466f  e86c2ffcff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x00524674:
    // 00524674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524675  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524676  ff157cf99e00           -call dword ptr [0x9ef97c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052467c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052467e  7405                   -je 0x524685
    if (cpu.flags.zf)
    {
        goto L_0x00524685;
    }
    // 00524680  e81b94faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00524685:
    // 00524685  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00524687  8835f0af5600           -mov byte ptr [0x56aff0], dh
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.dh;
    // 0052468d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524691  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52468f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052468f;
    // 00524640  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00524645  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0052464b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0052464e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
    // 00524650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524651  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524653  8a25f0af5600           -mov ah, byte ptr [0x56aff0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524659  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052465b  0f844a010000           -je 0x5247ab
    if (cpu.flags.zf)
    {
        return sub_5247ab(app, cpu);
    }
    // 00524661  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524668  740a                   -je 0x524674
    if (cpu.flags.zf)
    {
        goto L_0x00524674;
    }
    // 0052466a  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 0052466f  e86c2ffcff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x00524674:
    // 00524674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524675  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524676  ff157cf99e00           -call dword ptr [0x9ef97c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052467c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052467e  7405                   -je 0x524685
    if (cpu.flags.zf)
    {
        goto L_0x00524685;
    }
    // 00524680  e81b94faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00524685:
    // 00524685  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00524687  8835f0af5600           -mov byte ptr [0x56aff0], dh
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.dh;
    // 0052468d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x0052468f:
    // 0052468f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524691  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_524650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00524650;
    // 00524640  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00524645  8d8000000000           -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0052464b  8d5200                 -lea edx, [edx]
    cpu.edx = x86::reg32(cpu.edx);
    // 0052464e  8bdb                   -mov ebx, ebx
    cpu.ebx = cpu.ebx;
L_entry_0x00524650:
    // 00524650  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524651  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524653  8a25f0af5600           -mov ah, byte ptr [0x56aff0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524659  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052465b  0f844a010000           -je 0x5247ab
    if (cpu.flags.zf)
    {
        return sub_5247ab(app, cpu);
    }
    // 00524661  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524668  740a                   -je 0x524674
    if (cpu.flags.zf)
    {
        goto L_0x00524674;
    }
    // 0052466a  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 0052466f  e86c2ffcff             -call 0x4e75e0
    cpu.esp -= 4;
    sub_4e75e0(app, cpu);
    if (cpu.terminate) return;
L_0x00524674:
    // 00524674  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524675  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524676  ff157cf99e00           -call dword ptr [0x9ef97c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418556) /* 0x9ef97c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052467c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052467e  7405                   -je 0x524685
    if (cpu.flags.zf)
    {
        goto L_0x00524685;
    }
    // 00524680  e81b94faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
L_0x00524685:
    // 00524685  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00524687  8835f0af5600           -mov byte ptr [0x56aff0], dh
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.dh;
    // 0052468d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052468f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524691  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524692  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_5246a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005246a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005246a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005246a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005246a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005246a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005246a6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 005246ab  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 005246b1  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 005246b7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 005246b9  7505                   -jne 0x5246c0
    if (!cpu.flags.zf)
    {
        goto L_0x005246c0;
    }
    // 005246bb  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x005246c0:
    // 005246c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005246c2  7505                   -jne 0x5246c9
    if (!cpu.flags.zf)
    {
        goto L_0x005246c9;
    }
    // 005246c4  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x005246c9:
    // 005246c9  803df0af560000         +cmp byte ptr [0x56aff0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005246d0  7528                   -jne 0x5246fa
    if (!cpu.flags.zf)
    {
        goto L_0x005246fa;
    }
    // 005246d2  833d8044560000         +cmp dword ptr [0x564480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005246d9  742b                   -je 0x524706
    if (cpu.flags.zf)
    {
        goto L_0x00524706;
    }
L_0x005246db:
    // 005246db  833d243d9f0000         +cmp dword ptr [0x9f3d24], 0
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
    // 005246e2  7512                   -jne 0x5246f6
    if (!cpu.flags.zf)
    {
        goto L_0x005246f6;
    }
    // 005246e4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005246e6  752a                   -jne 0x524712
    if (!cpu.flags.zf)
    {
        goto L_0x00524712;
    }
    // 005246e8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x005246ed:
    // 005246ed  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005246ef  e8cc8ffaff             -call 0x4cd6c0
    cpu.esp -= 4;
    sub_4cd6c0(app, cpu);
    if (cpu.terminate) return;
    // 005246f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005246f6:
    // 005246f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005246f8  751c                   -jne 0x524716
    if (!cpu.flags.zf)
    {
        goto L_0x00524716;
    }
L_0x005246fa:
    // 005246fa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 005246fc  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524701  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524702  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524703  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524704  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524705  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524706:
    // 00524706  e8d56bfcff             -call 0x4eb2e0
    cpu.esp -= 4;
    sub_4eb2e0(app, cpu);
    if (cpu.terminate) return;
    // 0052470b  a380445600             -mov dword ptr [0x564480], eax
    app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */) = cpu.eax;
    // 00524710  ebc9                   -jmp 0x5246db
    goto L_0x005246db;
L_0x00524712:
    // 00524712  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00524714  ebd7                   -jmp 0x5246ed
    goto L_0x005246ed;
L_0x00524716:
    // 00524716  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524717  6a12                   -push 0x12
    app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 00524719  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052471f  e84c73fcff             -call 0x4eba70
    cpu.esp -= 4;
    sub_4eba70(app, cpu);
    if (cpu.terminate) return;
    // 00524724  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524725  6a19                   -push 0x19
    app->getMemory<x86::reg32>(cpu.esp-4) = 25 /*0x19*/;
    cpu.esp -= 4;
    // 00524727  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052472d  68d0af5600             -push 0x56afd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5681104 /*0x56afd0*/;
    cpu.esp -= 4;
    // 00524732  6a13                   -push 0x13
    app->getMemory<x86::reg32>(cpu.esp-4) = 19 /*0x13*/;
    cpu.esp -= 4;
    // 00524734  ff156cf99e00           -call dword ptr [0x9ef96c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418540) /* 0x9ef96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052473a  ff1578f99e00           -call dword ptr [0x9ef978]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418552) /* 0x9ef978 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524740  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524742  7456                   -je 0x52479a
    if (cpu.flags.zf)
    {
        goto L_0x0052479a;
    }
    // 00524744  833d3cf99e0000         +cmp dword ptr [0x9ef93c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10418492) /* 0x9ef93c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052474b  753a                   -jne 0x524787
    if (!cpu.flags.zf)
    {
        goto L_0x00524787;
    }
L_0x0052474d:
    // 0052474d  803df1af560000         +cmp byte ptr [0x56aff1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681137) /* 0x56aff1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00524754  7512                   -jne 0x524768
    if (!cpu.flags.zf)
    {
        goto L_0x00524768;
    }
    // 00524756  b840465200             -mov eax, 0x524640
    cpu.eax = 5391936 /*0x524640*/;
    // 0052475b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 0052475d  e816e3fcff             -call 0x4f2a78
    cpu.esp -= 4;
    sub_4f2a78(app, cpu);
    if (cpu.terminate) return;
    // 00524762  8835f1af5600           -mov byte ptr [0x56aff1], dh
    app->getMemory<x86::reg8>(x86::reg32(5681137) /* 0x56aff1 */) = cpu.dh;
L_0x00524768:
    // 00524768  ba20465200             -mov edx, 0x524620
    cpu.edx = 5391904 /*0x524620*/;
    // 0052476d  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0052476f  891518445600           -mov dword ptr [0x564418], edx
    app->getMemory<x86::reg32>(x86::reg32(5653528) /* 0x564418 */) = cpu.edx;
    // 00524775  881df0af5600           -mov byte ptr [0x56aff0], bl
    app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */) = cpu.bl;
    // 0052477b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052477d  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 00524782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524786  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524787:
    // 00524787  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052478c  b8e0445200             -mov eax, 0x5244e0
    cpu.eax = 5391584 /*0x5244e0*/;
    // 00524791  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00524793  e8882dfcff             -call 0x4e7520
    cpu.esp -= 4;
    sub_4e7520(app, cpu);
    if (cpu.terminate) return;
    // 00524798  ebb3                   -jmp 0x52474d
    goto L_0x0052474d;
L_0x0052479a:
    // 0052479a  e80193faff             -call 0x4cdaa0
    cpu.esp -= 4;
    sub_4cdaa0(app, cpu);
    if (cpu.terminate) return;
    // 0052479f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005247a1  a0f0af5600             -mov al, byte ptr [0x56aff0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681136) /* 0x56aff0 */);
    // 005247a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5247ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005247ab  0f84defeffff           -je 0x52468f
    if (cpu.flags.zf)
    {
        return sub_52468f(app, cpu);
    }
    // 005247b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005247b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005247b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5247c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005247c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005247c2  7505                   -jne 0x5247c9
    if (!cpu.flags.zf)
    {
        goto L_0x005247c9;
    }
    // 005247c4  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
L_0x005247c9:
    // 005247c9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005247cb  7505                   -jne 0x5247d2
    if (!cpu.flags.zf)
    {
        goto L_0x005247d2;
    }
    // 005247cd  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
L_0x005247d2:
    // 005247d2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005247d4  7505                   -jne 0x5247db
    if (!cpu.flags.zf)
    {
        goto L_0x005247db;
    }
    // 005247d6  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x005247db:
    // 005247db  891d8c435600           -mov dword ptr [0x56438c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */) = cpu.ebx;
    // 005247e1  8b1d9c435600           -mov ebx, dword ptr [0x56439c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653404) /* 0x56439c */);
    // 005247e7  a384435600             -mov dword ptr [0x564384], eax
    app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */) = cpu.eax;
    // 005247ec  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005247ee  a3a4435600             -mov dword ptr [0x5643a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5653412) /* 0x5643a4 */) = cpu.eax;
    // 005247f3  a1a0435600             -mov eax, dword ptr [0x5643a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653408) /* 0x5643a0 */);
    // 005247f8  891588435600           -mov dword ptr [0x564388], edx
    app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */) = cpu.edx;
    // 005247fe  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00524800  8915a8435600           -mov dword ptr [0x5643a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5653416) /* 0x5643a8 */) = cpu.edx;
    // 00524806  833d6443560000         +cmp dword ptr [0x564364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052480d  0f842d51feff           -je 0x509940
    if (cpu.flags.zf)
    {
        return sub_509940(app, cpu);
    }
    // 00524813  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_524820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524823  ff1554f99e00           -call dword ptr [0x9ef954]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418516) /* 0x9ef954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524829  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052482b  a32082a100             -mov dword ptr [0xa18220], eax
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.eax;
    // 00524830  8915f4af5600           -mov dword ptr [0x56aff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5681140) /* 0x56aff4 */) = cpu.edx;
    // 00524836  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00524838  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052483b  a31c505600             -mov dword ptr [0x56501c], eax
    app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */) = cpu.eax;
    // 00524840  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524845  a3f84f5600             -mov dword ptr [0x564ff8], eax
    app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */) = cpu.eax;
    // 0052484a  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0052484f  b9444e4957             -mov ecx, 0x57494e44
    cpu.ecx = 1464421956 /*0x57494e44*/;
    // 00524854  a3fc4f5600             -mov dword ptr [0x564ffc], eax
    app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */) = cpu.eax;
    // 00524859  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0052485e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524860  a308505600             -mov dword ptr [0x565008], eax
    app->getMemory<x86::reg32>(x86::reg32(5656584) /* 0x565008 */) = cpu.eax;
    // 00524865  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 0052486a  890df44f5600           -mov dword ptr [0x564ff4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5656564) /* 0x564ff4 */) = cpu.ecx;
    // 00524870  a30c505600             -mov dword ptr [0x56500c], eax
    app->getMemory<x86::reg32>(x86::reg32(5656588) /* 0x56500c */) = cpu.eax;
    // 00524875  a08c435600             -mov al, byte ptr [0x56438c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5653388) /* 0x56438c */);
    // 0052487a  891d00505600           -mov dword ptr [0x565000], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656576) /* 0x565000 */) = cpu.ebx;
    // 00524880  a210505600             -mov byte ptr [0x565010], al
    app->getMemory<x86::reg8>(x86::reg32(5656592) /* 0x565010 */) = cpu.al;
    // 00524885  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00524887  891d04505600           -mov dword ptr [0x565004], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656580) /* 0x565004 */) = cpu.ebx;
    // 0052488d  882512505600           -mov byte ptr [0x565012], ah
    app->getMemory<x86::reg8>(x86::reg32(5656594) /* 0x565012 */) = cpu.ah;
    // 00524893  a18c435600             -mov eax, dword ptr [0x56438c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 00524898  891514505600           -mov dword ptr [0x565014], edx
    app->getMemory<x86::reg32>(x86::reg32(5656596) /* 0x565014 */) = cpu.edx;
    // 0052489e  e82d50feff             -call 0x5098d0
    cpu.esp -= 4;
    sub_5098d0(app, cpu);
    if (cpu.terminate) return;
    // 005248a3  8b0d88435600           -mov ecx, dword ptr [0x564388]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 005248a9  8b151c505600           -mov edx, dword ptr [0x56501c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5656604) /* 0x56501c */);
    // 005248af  a211505600             -mov byte ptr [0x565011], al
    app->getMemory<x86::reg8>(x86::reg32(5656593) /* 0x565011 */) = cpu.al;
    // 005248b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005248b6  891d28505600           -mov dword ptr [0x565028], ebx
    app->getMemory<x86::reg32>(x86::reg32(5656616) /* 0x565028 */) = cpu.ebx;
    // 005248bc  e86f51feff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 005248c1  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 005248c6  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 005248cc  8b158c435600           -mov edx, dword ptr [0x56438c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 005248d2  a320505600             -mov dword ptr [0x565020], eax
    app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */) = cpu.eax;
    // 005248d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005248d9  e85251feff             -call 0x509a30
    cpu.esp -= 4;
    sub_509a30(app, cpu);
    if (cpu.terminate) return;
    // 005248de  a324505600             -mov dword ptr [0x565024], eax
    app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */) = cpu.eax;
    // 005248e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_5248f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005248f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005248f1  8b152082a100           -mov edx, dword ptr [0xa18220]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */);
    // 005248f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005248f9  7502                   -jne 0x5248fd
    if (!cpu.flags.zf)
    {
        goto L_0x005248fd;
    }
    // 005248fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005248fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005248fd:
    // 005248fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005248fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005248ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524900  ff155cf99e00           -call dword ptr [0x9ef95c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10418524) /* 0x9ef95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524906  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524908  a120505600             -mov eax, dword ptr [0x565020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656608) /* 0x565020 */);
    // 0052490d  891d2082a100           -mov dword ptr [0xa18220], ebx
    app->getMemory<x86::reg32>(x86::reg32(10584608) /* 0xa18220 */) = cpu.ebx;
    // 00524913  e8f851feff             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00524918  a124505600             -mov eax, dword ptr [0x565024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5656612) /* 0x565024 */);
    // 0052491d  e8ee51feff             -call 0x509b10
    cpu.esp -= 4;
    sub_509b10(app, cpu);
    if (cpu.terminate) return;
    // 00524922  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524924  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524931  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524933  e8e863fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524938  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052493b  e870e3fcff             -call 0x4f2cb0
    cpu.esp -= 4;
    sub_4f2cb0(app, cpu);
    if (cpu.terminate) return;
    // 00524940  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_524950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524951  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524953  e8c863fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524958  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0052495b  e860c0fcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 00524960  e82b64fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524965  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_524970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524971  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524972  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524973  81ec44010000           -sub esp, 0x144
    (cpu.esp) -= x86::reg32(x86::sreg32(324 /*0x144*/));
    // 00524979  8bbc2458010000         -mov edi, dword ptr [esp + 0x158]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */);
    // 00524980  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 00524987  89942440010000         -mov dword ptr [esp + 0x140], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */) = cpu.edx;
    // 0052498e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00524990  898c243c010000         -mov dword ptr [esp + 0x13c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.ecx;
    // 00524997  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052499c  e85ba6fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 005249a1  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 005249a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005249aa  8b942454010000         -mov edx, dword ptr [esp + 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 005249b1  e846a6fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 005249b6  8b84243c010000         -mov eax, dword ptr [esp + 0x13c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 005249bd  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 005249c3  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 005249c9  e8c2a7fcff             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 005249ce  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 005249d0  89842438010000         -mov dword ptr [esp + 0x138], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */) = cpu.eax;
    // 005249d7  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 005249de  e8edfcfcff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 005249e3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005249e5  e856fdfcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 005249ea  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 005249ef  e82cabfcff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 005249f4  8b842454010000         -mov eax, dword ptr [esp + 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 005249fb  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 005249fd  8b8c243c010000         -mov ecx, dword ptr [esp + 0x13c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524a04  89842428010000         -mov dword ptr [esp + 0x128], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 00524a0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a0c  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a13  8b942444010000         -mov edx, dword ptr [esp + 0x144]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a1a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524a1c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524a1e  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 00524a25  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524a27  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524a2c  e88f6c0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524a31  ff1560445600           -call dword ptr [0x564460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524a37  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524a39  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524a40  e85b63fcff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00524a45  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524a47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524a49  8b8c2454010000         -mov ecx, dword ptr [esp + 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 00524a50  e8dbfeffff             -call 0x524930
    cpu.esp -= 4;
    sub_524930(app, cpu);
    if (cpu.terminate) return;
    // 00524a55  e8c662fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524a5a  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00524a5f  8b9c243c010000         -mov ebx, dword ptr [esp + 0x13c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524a66  e8f5acfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524a6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a6c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00524a6e  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524a75  e8c68afdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 00524a7a  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 00524a7f  8b8c2428010000         -mov ecx, dword ptr [esp + 0x128]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00524a86  8b9c242c010000         -mov ebx, dword ptr [esp + 0x12c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 00524a8d  e8ceacfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524a92  8d5504                 -lea edx, [ebp + 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00524a95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524a96  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524a99  8b842444010000         -mov eax, dword ptr [esp + 0x144]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(324) /* 0x144 */);
    // 00524aa0  83eb05                 -sub ebx, 5
    (cpu.ebx) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00524aa3  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524aa6  e8756c0000             -call 0x52b720
    cpu.esp -= 4;
    sub_52b720(app, cpu);
    if (cpu.terminate) return;
    // 00524aab  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524ab0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524ab2  e8a9acfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524ab7  e874adfcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00524abc  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 00524ac3  8d5509                 -lea edx, [ebp + 9]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(9) /* 0x9 */);
    // 00524ac6  e8956d0000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 00524acb  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524ad1  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524ad6  e8d56d0000             -call 0x52b8b0
    cpu.esp -= 4;
    sub_52b8b0(app, cpu);
    if (cpu.terminate) return;
    // 00524adb  e8b062fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x00524ae0:
    // 00524ae0  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524ae6  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 00524ae8  75f6                   -jne 0x524ae0
    if (!cpu.flags.zf)
    {
        goto L_0x00524ae0;
    }
L_0x00524aea:
    // 00524aea  e8e1b5fcff             -call 0x4f00d0
    cpu.esp -= 4;
    sub_4f00d0(app, cpu);
    if (cpu.terminate) return;
    // 00524aef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524af1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00524af3  ff1568445600           -call dword ptr [0x564468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653608) /* 0x564468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524af9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00524afb  21fe                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 00524afd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524aff  0f8497000000           -je 0x524b9c
    if (cpu.flags.zf)
    {
        goto L_0x00524b9c;
    }
L_0x00524b05:
    // 00524b05  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00524b08  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00524b0b  83f979                 +cmp ecx, 0x79
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524b0e  7505                   -jne 0x524b15
    if (!cpu.flags.zf)
    {
        goto L_0x00524b15;
    }
    // 00524b10  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00524b15:
    // 00524b15  8b842454010000         -mov eax, dword ptr [esp + 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 00524b1c  8b8c2440010000         -mov ecx, dword ptr [esp + 0x140]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b23  8b9c243c010000         -mov ebx, dword ptr [esp + 0x13c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 00524b2a  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b31  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00524b33  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00524b35  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524b36  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524b38  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524b3d  e87e6b0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524b42  ff155c445600           -call dword ptr [0x56445c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524b48  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 00524b4f  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 00524b56  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00524b58  e8f3fdffff             -call 0x524950
    cpu.esp -= 4;
    sub_524950(app, cpu);
    if (cpu.terminate) return;
    // 00524b5d  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524b63  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524b65  e8f6fbfcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 00524b6a  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524b71  e88afbfcff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00524b76  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 00524b7d  e87eb3fcff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 00524b82  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 00524b89  e86ea4fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524b8e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524b90  81c444010000           -add esp, 0x144
    (cpu.esp) += x86::reg32(x86::sreg32(324 /*0x144*/));
    // 00524b96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524b99  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00524b9c:
    // 00524b9c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524b9e  0f8561ffffff           -jne 0x524b05
    if (!cpu.flags.zf)
    {
        goto L_0x00524b05;
    }
    // 00524ba4  e941ffffff             -jmp 0x524aea
    goto L_0x00524aea;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_524bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524bb3  833d6443560000         +cmp dword ptr [0x564364], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653348) /* 0x564364 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524bba  7410                   -je 0x524bcc
    if (cpu.flags.zf)
    {
        goto L_0x00524bcc;
    }
    // 00524bbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524bbe  e86dadfbff             -call 0x4df930
    cpu.esp -= 4;
    sub_4df930(app, cpu);
    if (cpu.terminate) return;
    // 00524bc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524bc5  7442                   -je 0x524c09
    if (cpu.flags.zf)
    {
        goto L_0x00524c09;
    }
    // 00524bc7  e8c461fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
L_0x00524bcc:
    // 00524bcc  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524bd1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524bd3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524bd6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524bd8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524bda  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00524bdd  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524be2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524be4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524be7  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524be9  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524beb  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00524bed  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00524bef  8d50b0                 -lea edx, [eax - 0x50]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-80) /* -0x50 */);
    // 00524bf2  b9a0000000             -mov ecx, 0xa0
    cpu.ecx = 160 /*0xa0*/;
    // 00524bf7  b8741e5500             -mov eax, 0x551e74
    cpu.eax = 5578356 /*0x551e74*/;
    // 00524bfc  e86ffdffff             -call 0x524970
    cpu.esp -= 4;
    sub_524970(app, cpu);
    if (cpu.terminate) return;
    // 00524c01  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524c03  7520                   -jne 0x524c25
    if (!cpu.flags.zf)
    {
        goto L_0x00524c25;
    }
    // 00524c05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524c09:
    // 00524c09  8b0d80445600           -mov ecx, dword ptr [0x564480]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524c0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524c10  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524c16  8b1d80445600           -mov ebx, dword ptr [0x564480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653632) /* 0x564480 */);
    // 00524c1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524c1d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524c23  eba7                   -jmp 0x524bcc
    goto L_0x00524bcc;
L_0x00524c25:
    // 00524c25  e853defcff             -call 0x4f2a7d
    cpu.esp -= 4;
    sub_4f2a7d(app, cpu);
    if (cpu.terminate) return;
    // 00524c2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524c2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_524c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524c32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524c33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524c34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524c35  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 00524c3b  89842428010000         -mov dword ptr [esp + 0x128], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 00524c42  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00524c44  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524c49  e8aea3fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524c4e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524c50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524c52  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00524c57  e8a0a3fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524c5c  8b0df4435600           -mov ecx, dword ptr [0x5643f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653492) /* 0x5643f4 */);
    // 00524c62  8b1d8c435600           -mov ebx, dword ptr [0x56438c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653388) /* 0x56438c */);
    // 00524c68  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524c6d  e81ea5fcff             -call 0x4ef190
    cpu.esp -= 4;
    sub_4ef190(app, cpu);
    if (cpu.terminate) return;
    // 00524c72  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00524c74  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524c7b  e850fafcff             -call 0x4f46d0
    cpu.esp -= 4;
    sub_4f46d0(app, cpu);
    if (cpu.terminate) return;
    // 00524c80  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524c82  e8b9fafcff             -call 0x4f4740
    cpu.esp -= 4;
    sub_4f4740(app, cpu);
    if (cpu.terminate) return;
    // 00524c87  b8e4625600             -mov eax, 0x5662e4
    cpu.eax = 5661412 /*0x5662e4*/;
    // 00524c8c  e88fa8fcff             -call 0x4ef520
    cpu.esp -= 4;
    sub_4ef520(app, cpu);
    if (cpu.terminate) return;
    // 00524c91  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524c93  e80861fcff             -call 0x4eada0
    cpu.esp -= 4;
    sub_4eada0(app, cpu);
    if (cpu.terminate) return;
    // 00524c98  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524c9e  b82c505600             -mov eax, 0x56502c
    cpu.eax = 5656620 /*0x56502c*/;
    // 00524ca3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524ca4  8d5af6                 -lea ebx, [edx - 0xa]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 00524ca7  8b0d84435600           -mov ecx, dword ptr [0x564384]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524cad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524caf  e80c6a0000             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00524cb4  ff1560445600           -call dword ptr [0x564460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653600) /* 0x564460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524cba  8b1d88435600           -mov ebx, dword ptr [0x564388]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524cc0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524cc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524cc4  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524cc7  e864fcffff             -call 0x524930
    cpu.esp -= 4;
    sub_524930(app, cpu);
    if (cpu.terminate) return;
    // 00524ccc  e84f60fcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524cd1  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00524cd6  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00524cdb  e880aafcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524ce0  8b1d84435600           -mov ebx, dword ptr [0x564384]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524ce6  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524cec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00524ced  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524cf0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00524cf2  e84988fdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 00524cf7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00524cfc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524cfe  e85daafcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 00524d03  e828abfcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 00524d08  8b1588435600           -mov edx, dword ptr [0x564388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d0e  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00524d15  83ea09                 -sub edx, 9
    (cpu.edx) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00524d18  e8436b0000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 00524d1d  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d23  e86860fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524d28  e86360fcff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 00524d2d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524d2f  e8acb9fcff             -call 0x4f06e0
    cpu.esp -= 4;
    sub_4f06e0(app, cpu);
    if (cpu.terminate) return;
    // 00524d34  e8e75ffcff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 00524d39  ff155c445600           -call dword ptr [0x56445c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653596) /* 0x56445c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524d41  8b1d88435600           -mov ebx, dword ptr [0x564388]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524d49  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00524d4c  e8fffbffff             -call 0x524950
    cpu.esp -= 4;
    sub_524950(app, cpu);
    if (cpu.terminate) return;
    // 00524d51  ff1564445600           -call dword ptr [0x564464]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5653604) /* 0x564464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524d57  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00524d59  e802fafcff             -call 0x4f4760
    cpu.esp -= 4;
    sub_4f4760(app, cpu);
    if (cpu.terminate) return;
    // 00524d5e  8d8424b8000000         -lea eax, [esp + 0xb8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 00524d65  e896f9fcff             -call 0x4f4700
    cpu.esp -= 4;
    sub_4f4700(app, cpu);
    if (cpu.terminate) return;
    // 00524d6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524d6c  e88fb1fcff             -call 0x4eff00
    cpu.esp -= 4;
    sub_4eff00(app, cpu);
    if (cpu.terminate) return;
    // 00524d71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524d73  e884a2fdff             -call 0x4feffc
    cpu.esp -= 4;
    sub_4feffc(app, cpu);
    if (cpu.terminate) return;
    // 00524d78  81c42c010000           -add esp, 0x12c
    (cpu.esp) += x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 00524d7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524d83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_524d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524d91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524d92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524d93  a188435600             -mov eax, dword ptr [0x564388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653384) /* 0x564388 */);
    // 00524d98  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524d9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524d9d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524d9f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524da1  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00524da4  a184435600             -mov eax, dword ptr [0x564384]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 00524da9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524dab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00524dae  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00524db0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00524db2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00524db4  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 00524db6  8d9070ffffff           -lea edx, [eax - 0x90]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-144) /* -0x90 */);
    // 00524dbc  b920010000             -mov ecx, 0x120
    cpu.ecx = 288 /*0x120*/;
    // 00524dc1  b8801e5500             -mov eax, 0x551e80
    cpu.eax = 5578368 /*0x551e80*/;
    // 00524dc6  e8a5fbffff             -call 0x524970
    cpu.esp -= 4;
    sub_524970(app, cpu);
    if (cpu.terminate) return;
    // 00524dcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524dce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_524dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524dd0  e9fb6a0000             -jmp 0x52b8d0
    return sub_52b8d0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_524de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524de0  e93b6d0000             -jmp 0x52bb20
    return sub_52bb20(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_524df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524df1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524df3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524df4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524df5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524df8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524dfa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00524dfc  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524dff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524e01  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00524e05  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00524e09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524e0b  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00524e0e  8b2c85c0f59e00         -mov ebp, dword ptr [eax*4 + 0x9ef5c0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10417600) /* 0x9ef5c0 */ + cpu.eax * 4);
    // 00524e15  8b5538                 -mov edx, dword ptr [ebp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 00524e18  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00524e1a  0f85f2000000           -jne 0x524f12
    if (!cpu.flags.zf)
    {
        goto L_0x00524f12;
    }
L_0x00524e20:
    // 00524e20  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524e24  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524e27  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00524e2a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00524e2e  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00524e31  741f                   -je 0x524e52
    if (cpu.flags.zf)
    {
        goto L_0x00524e52;
    }
    // 00524e33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524e35  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524e37  e8a4c2fbff             -call 0x4e10e0
    cpu.esp -= 4;
    sub_4e10e0(app, cpu);
    if (cpu.terminate) return;
    // 00524e3c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e40  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00524e43  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00524e47  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524e4b  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e4f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00524e52:
    // 00524e52  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00524e54  83fe08                 +cmp esi, 8
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
    // 00524e57  7d0e                   -jge 0x524e67
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00524e67;
    }
    // 00524e59  83feff                 +cmp esi, -1
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
    // 00524e5c  0f85bc000000           -jne 0x524f1e
    if (!cpu.flags.zf)
    {
        goto L_0x00524f1e;
    }
    // 00524e62  b900000040             -mov ecx, 0x40000000
    cpu.ecx = 1073741824 /*0x40000000*/;
L_0x00524e67:
    // 00524e67  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524e69  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00524e6b  e870c7fbff             -call 0x4e15e0
    cpu.esp -= 4;
    sub_4e15e0(app, cpu);
    if (cpu.terminate) return;
    // 00524e70  e87bc3fbff             -call 0x4e11f0
    cpu.esp -= 4;
    sub_4e11f0(app, cpu);
    if (cpu.terminate) return;
    // 00524e75  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 00524e78  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00524e7a  4a                     -dec edx
    (cpu.edx)--;
    // 00524e7b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e7e  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00524e80  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00524e82  21d1                   -and ecx, edx
    cpu.ecx &= x86::reg32(x86::sreg32(cpu.edx));
    // 00524e84  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524e88  2b542408               -sub edx, dword ptr [esp + 8]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00524e8c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524e8e  83ea10                 -sub edx, 0x10
    (cpu.edx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e91  83e910                 -sub ecx, 0x10
    (cpu.ecx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524e94  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00524e98  39d1                   +cmp ecx, edx
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
    // 00524e9a  7e06                   -jle 0x524ea2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00524ea2;
    }
    // 00524e9c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00524e9e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00524ea0  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00524ea2:
    // 00524ea2  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00524ea5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00524ea8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524eac  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00524eaf  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00524eb2  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00524eb4  e83756fcff             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00524eb9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524ebd  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00524ec0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00524ec4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ec6  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524ec9  7e35                   -jle 0x524f00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00524f00;
    }
    // 00524ecb  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00524ece  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ed0  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ed4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524ed5  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ed9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524eda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00524edc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00524ede  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00524ee0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ee2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00524ee4  e837c2fbff             -call 0x4e1120
    cpu.esp -= 4;
    sub_4e1120(app, cpu);
    if (cpu.terminate) return;
    // 00524ee9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00524eeb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524eed  e88ec1fbff             -call 0x4e1080
    cpu.esp -= 4;
    sub_4e1080(app, cpu);
    if (cpu.terminate) return;
    // 00524ef2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00524ef6  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00524ef9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00524efd  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00524f00:
    // 00524f00  8b7538                 -mov esi, dword ptr [ebp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(56) /* 0x38 */);
    // 00524f03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524f05  7565                   -jne 0x524f6c
    if (!cpu.flags.zf)
    {
        goto L_0x00524f6c;
    }
    // 00524f07  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524f09  83c410                 +add esp, 0x10
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
    // 00524f0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00524f12:
    // 00524f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524f13  ff15b8445300           -call dword ptr [0x5344b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457080) /* 0x5344b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524f19  e902ffffff             -jmp 0x524e20
    goto L_0x00524e20;
L_0x00524f1e:
    // 00524f1e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00524f20  7c0a                   -jl 0x524f2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00524f2c;
    }
    // 00524f22  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00524f27  e93bffffff             -jmp 0x524e67
    goto L_0x00524e67;
L_0x00524f2c:
    // 00524f2c  833d0c44560000         +cmp dword ptr [0x56440c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5653516) /* 0x56440c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00524f33  0f842effffff           -je 0x524e67
    if (cpu.flags.zf)
    {
        goto L_0x00524e67;
    }
    // 00524f39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f3a  baa01e5500             -mov edx, 0x551ea0
    cpu.edx = 5578400 /*0x551ea0*/;
    // 00524f3f  b8b01e5500             -mov eax, 0x551eb0
    cpu.eax = 5578416 /*0x551eb0*/;
    // 00524f44  68c01e5500             -push 0x551ec0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5578432 /*0x551ec0*/;
    cpu.esp -= 4;
    // 00524f49  891590215500           -mov dword ptr [0x552190], edx
    app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.edx;
    // 00524f4f  ba63000000             -mov edx, 0x63
    cpu.edx = 99 /*0x63*/;
    // 00524f54  a394215500             -mov dword ptr [0x552194], eax
    app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.eax;
    // 00524f59  891598215500           -mov dword ptr [0x552198], edx
    app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.edx;
    // 00524f5f  e8acc0edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 00524f64  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00524f67  e9fbfeffff             -jmp 0x524e67
    goto L_0x00524e67;
L_0x00524f6c:
    // 00524f6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f6d  ff1588455300           -call dword ptr [0x534588]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5457288) /* 0x534588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00524f73  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00524f75  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00524f78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f79  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00524f7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_524f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524f80  e97b29fdff             -jmp 0x4f7900
    return sub_4f7900(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_524f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00524f88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00524f89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00524f8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00524f8b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00524f8c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00524f8d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00524f8e  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 00524f94  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00524f96  0f85c1000000           -jne 0x52505d
    if (!cpu.flags.zf)
    {
        goto L_0x0052505d;
    }
    // 00524f9c  8b2d39785600           -mov ebp, dword ptr [0x567839]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5666873) /* 0x567839 */);
    // 00524fa2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00524fa4  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00524fa7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00524fa9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00524fab  7416                   -je 0x524fc3
    if (cpu.flags.zf)
    {
        goto L_0x00524fc3;
    }
L_0x00524fad:
    // 00524fad  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00524faf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00524fb2  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00524fb4  7404                   -je 0x524fba
    if (cpu.flags.zf)
    {
        goto L_0x00524fba;
    }
    // 00524fb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524fb8  ebf3                   -jmp 0x524fad
    goto L_0x00524fad;
L_0x00524fba:
    // 00524fba  41                     -inc ecx
    (cpu.ecx)++;
    // 00524fbb  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 00524fbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00524fbf  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00524fc1  75ea                   -jne 0x524fad
    if (!cpu.flags.zf)
    {
        goto L_0x00524fad;
    }
L_0x00524fc3:
    // 00524fc3  893d54b1a000           -mov dword ptr [0xa0b154], edi
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edi;
    // 00524fc9  29e8                   +sub eax, ebp
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
    // 00524fcb  7505                   -jne 0x524fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00524fd2;
    }
    // 00524fcd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00524fd2:
    // 00524fd2  e82929fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00524fd7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00524fd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00524fdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524fdd  0f8475000000           -je 0x525058
    if (cpu.flags.zf)
    {
        goto L_0x00525058;
    }
    // 00524fe3  a33082a100             -mov dword ptr [0xa18230], eax
    app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */) = cpu.eax;
    // 00524fe8  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00524fef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00524ff2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00524ff4  e80729fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00524ff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00524ffb  7454                   -je 0x525051
    if (cpu.flags.zf)
    {
        goto L_0x00525051;
    }
    // 00524ffd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00524fff  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00525002  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00525004  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525006  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525008  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052500a  741a                   -je 0x525026
    if (cpu.flags.zf)
    {
        goto L_0x00525026;
    }
L_0x0052500c:
    // 0052500c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052500e  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00525011:
    // 00525011  43                     -inc ebx
    (cpu.ebx)++;
    // 00525012  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00525014  40                     -inc eax
    (cpu.eax)++;
    // 00525015  8853ff                 -mov byte ptr [ebx - 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00525018  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052501a  75f5                   -jne 0x525011
    if (!cpu.flags.zf)
    {
        goto L_0x00525011;
    }
    // 0052501c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052501f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00525021  46                     -inc esi
    (cpu.esi)++;
    // 00525022  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00525024  75e6                   -jne 0x52500c
    if (!cpu.flags.zf)
    {
        goto L_0x0052500c;
    }
L_0x00525026:
    // 00525026  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525028  c7040100000000         -mov dword ptr [ecx + eax], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 0052502f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525032  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00525034  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00525037  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00525039  a350b1a000             -mov dword ptr [0xa0b150], eax
    app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052503e  893d54b1a000           -mov dword ptr [0xa0b154], edi
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.edi;
    // 00525044  e8f7b5fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00525049  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052504f  eb07                   -jmp 0x525058
    goto L_0x00525058;
L_0x00525051:
    // 00525051  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525053  e89829fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525058:
    // 00525058  e8536d0000             -call 0x52bdb0
    cpu.esp -= 4;
    sub_52bdb0(app, cpu);
    if (cpu.terminate) return;
L_0x0052505d:
    // 0052505d  8b3d54b1a000           -mov edi, dword ptr [0xa0b154]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 00525063  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525064  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525065  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525066  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52506c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052506c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052506d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052506e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052506f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525070  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525071  e85a6e0000             -call 0x52bed0
    cpu.esp -= 4;
    sub_52bed0(app, cpu);
    if (cpu.terminate) return;
    // 00525076  8b1554b1a000           -mov edx, dword ptr [0xa0b154]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052507c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052507e  740f                   -je 0x52508f
    if (cpu.flags.zf)
    {
        goto L_0x0052508f;
    }
    // 00525080  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525082  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525084  e86729fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00525089  891d54b1a000           -mov dword ptr [0xa0b154], ebx
    app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.ebx;
L_0x0052508f:
    // 0052508f  8b0d3082a100           -mov ecx, dword ptr [0xa18230]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */);
    // 00525095  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00525097  740f                   -je 0x5250a8
    if (cpu.flags.zf)
    {
        goto L_0x005250a8;
    }
    // 00525099  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052509b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052509d  e84e29fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005250a2  89353082a100           -mov dword ptr [0xa18230], esi
    app->getMemory<x86::reg32>(x86::reg32(10584624) /* 0xa18230 */) = cpu.esi;
L_0x005250a8:
    // 005250a8  8b3d39785600           -mov edi, dword ptr [0x567839]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5666873) /* 0x567839 */);
    // 005250ae  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005250b0  7408                   -je 0x5250ba
    if (cpu.flags.zf)
    {
        goto L_0x005250ba;
    }
    // 005250b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005250b3  2eff15d8445300         -call dword ptr cs:[0x5344d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457112) /* 0x5344d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005250ba:
    // 005250ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5250c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005250c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005250c1  803800                 +cmp byte ptr [eax], 0
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
    // 005250c4  7507                   -jne 0x5250cd
    if (!cpu.flags.zf)
    {
        goto L_0x005250cd;
    }
    // 005250c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005250cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005250cd:
    // 005250cd  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005250d4  7422                   -je 0x5250f8
    if (cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005250d8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 005250da  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 005250e0  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 005250e3  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 005250e9  740d                   -je 0x5250f8
    if (cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250eb  80780100               +cmp byte ptr [eax + 1], 0
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
    // 005250ef  7507                   -jne 0x5250f8
    if (!cpu.flags.zf)
    {
        goto L_0x005250f8;
    }
    // 005250f1  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 005250f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005250f8:
    // 005250f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005250fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005250fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_525100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525100  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525101  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525108  7420                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 0052510a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052510c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0052510e  8a9211b2a000           -mov dl, byte ptr [edx + 0xa0b211]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10531345) /* 0xa0b211 */);
    // 00525114  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00525117  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052511d  740b                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 0052511f  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00525123  7405                   -je 0x52512a
    if (cpu.flags.zf)
    {
        goto L_0x0052512a;
    }
    // 00525125  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525128  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525129  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052512a:
    // 0052512a  40                     -inc eax
    (cpu.eax)++;
    // 0052512b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052512c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_525130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525133  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525134  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525135  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525136  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525139  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052513b  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525142  7505                   -jne 0x525149
    if (!cpu.flags.zf)
    {
        goto L_0x00525149;
    }
    // 00525144  e857010000             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x00525149:
    // 00525149  8b3558b1a000           -mov esi, dword ptr [0xa0b158]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052514f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525151  743d                   -je 0x525190
    if (cpu.flags.zf)
    {
        goto L_0x00525190;
    }
    // 00525153  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00525155  7439                   -je 0x525190
    if (cpu.flags.zf)
    {
        goto L_0x00525190;
    }
    // 00525157  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525159  e8a2010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052515e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00525160  01c0                   +add eax, eax
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
    // 00525162  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00525165  eb23                   -jmp 0x52518a
    goto L_0x0052518a;
L_0x00525167:
    // 00525167  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00525169  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052516b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052516d  e8fe6d0000             -call 0x52bf70
    cpu.esp -= 4;
    sub_52bf70(app, cpu);
    if (cpu.terminate) return;
    // 00525172  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525174  7511                   -jne 0x525187
    if (!cpu.flags.zf)
    {
        goto L_0x00525187;
    }
    // 00525176  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00525179  66833c013d             +cmp word ptr [ecx + eax], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052517e  7507                   -jne 0x525187
    if (!cpu.flags.zf)
    {
        goto L_0x00525187;
    }
    // 00525180  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525183  01c8                   +add eax, ecx
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
    // 00525185  eb0b                   -jmp 0x525192
    goto L_0x00525192;
L_0x00525187:
    // 00525187  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052518a:
    // 0052518a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0052518c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052518e  75d7                   -jne 0x525167
    if (!cpu.flags.zf)
    {
        goto L_0x00525167;
    }
L_0x00525190:
    // 00525190  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00525192:
    // 00525192  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525195  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525197  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525198  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525199  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052519a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052519b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_5251a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005251a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005251a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005251a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005251a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005251a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005251a5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005251a8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005251ab  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005251ad  66813d417856000080     +cmp word ptr [0x567841], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5666881) /* 0x567841 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 005251b6  730e                   -jae 0x5251c6
    if (!cpu.flags.cf)
    {
        goto L_0x005251c6;
    }
    // 005251b8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005251b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005251ba  2eff15e0455300         -call dword ptr cs:[0x5345e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457376) /* 0x5345e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005251c1  e9c3000000             -jmp 0x525289
    goto L_0x00525289;
L_0x005251c6:
    // 005251c6  e835010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005251cb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005251cd  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005251d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005251d2  e82927fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005251d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005251d9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 005251db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005251dd  0f84a6000000           -je 0x525289
    if (cpu.flags.zf)
    {
        goto L_0x00525289;
    }
    // 005251e3  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005251e5  7504                   -jne 0x5251eb
    if (!cpu.flags.zf)
    {
        goto L_0x005251eb;
    }
    // 005251e7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 005251e9  eb2b                   -jmp 0x525216
    goto L_0x00525216;
L_0x005251eb:
    // 005251eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005251ed  e80e010000             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 005251f2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 005251f4  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005251f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005251f9  e80227fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005251fe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525202  7512                   -jne 0x525216
    if (!cpu.flags.zf)
    {
        goto L_0x00525216;
    }
    // 00525204  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525206  e8e527fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052520b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052520d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525210  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525211  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525215  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525216:
    // 00525216  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00525219  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052521b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052521d  e8cef0ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00525222  83f8ff                 +cmp eax, -1
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
    // 00525225  751d                   -jne 0x525244
    if (!cpu.flags.zf)
    {
        goto L_0x00525244;
    }
    // 00525227  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525229  e8c227fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052522e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525230  7407                   -je 0x525239
    if (cpu.flags.zf)
    {
        goto L_0x00525239;
    }
    // 00525232  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00525234  e8b727fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525239:
    // 00525239  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052523b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052523e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052523f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525243  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525244:
    // 00525244  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525246  7422                   -je 0x52526a
    if (cpu.flags.zf)
    {
        goto L_0x0052526a;
    }
    // 00525248  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052524a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052524c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052524e  e89df0ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 00525253  83f8ff                 +cmp eax, -1
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
    // 00525256  7512                   -jne 0x52526a
    if (!cpu.flags.zf)
    {
        goto L_0x0052526a;
    }
    // 00525258  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052525a  e89127fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052525f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00525261  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525264  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525265  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525266  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525267  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525268  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052526a:
    // 0052526a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052526b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052526c  2eff15dc455300         -call dword ptr cs:[0x5345dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457372) /* 0x5345dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525273  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525275  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525277  e87427fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052527c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052527e  7407                   -je 0x525287
    if (cpu.flags.zf)
    {
        goto L_0x00525287;
    }
    // 00525280  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00525282  e86927fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525287:
    // 00525287  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00525289:
    // 00525289  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052528c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052528f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525290  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525291  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5252a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005252a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005252a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005252a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005252a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005252a4  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 005252aa  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 005252ac  7441                   -je 0x5252ef
    if (cpu.flags.zf)
    {
        goto L_0x005252ef;
    }
L_0x005252ae:
    // 005252ae  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 005252b0  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005252b3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005252b5  7438                   -je 0x5252ef
    if (cpu.flags.zf)
    {
        goto L_0x005252ef;
    }
    // 005252b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005252b9  e8922dffff             -call 0x518050
    cpu.esp -= 4;
    sub_518050(app, cpu);
    if (cpu.terminate) return;
    // 005252be  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 005252c1  8d045d00000000         -lea eax, [ebx*2]
    cpu.eax = x86::reg32(cpu.ebx * 2);
    // 005252c8  e83326fdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 005252cd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005252cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005252d1  74db                   -je 0x5252ae
    if (cpu.flags.zf)
    {
        goto L_0x005252ae;
    }
    // 005252d3  e8a82dffff             -call 0x518080
    cpu.esp -= 4;
    sub_518080(app, cpu);
    if (cpu.terminate) return;
    // 005252d8  83f8ff                 +cmp eax, -1
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
    // 005252db  7409                   -je 0x5252e6
    if (cpu.flags.zf)
    {
        goto L_0x005252e6;
    }
    // 005252dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005252df  e8946e0000             -call 0x52c178
    cpu.esp -= 4;
    sub_52c178(app, cpu);
    if (cpu.terminate) return;
    // 005252e4  ebc8                   -jmp 0x5252ae
    goto L_0x005252ae;
L_0x005252e6:
    // 005252e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005252e8  e80327fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 005252ed  ebbf                   -jmp 0x5252ae
    goto L_0x005252ae;
L_0x005252ef:
    // 005252ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005252f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525301  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525302  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525304  66833800               +cmp word ptr [eax], 0
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
    // 00525308  740c                   -je 0x525316
    if (cpu.flags.zf)
    {
        goto L_0x00525316;
    }
L_0x0052530a:
    // 0052530a  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052530e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525311  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00525314  75f4                   -jne 0x52530a
    if (!cpu.flags.zf)
    {
        goto L_0x0052530a;
    }
L_0x00525316:
    // 00525316  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00525318  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052531a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052531b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052531c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_525320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525321  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525322  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525323  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00525325  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00525327  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00525329  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0052532a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0052532c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0052532e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052532f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525331  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00525334  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00525336  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00525338  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052533b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0052533d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052533e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0052533f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00525341  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525342  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525343  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525344  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525352  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00525354:
    // 00525354  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00525357  668b1a                 -mov bx, word ptr [edx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx);
    // 0052535a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052535d  668958fe               -mov word ptr [eax - 2], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00525361  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00525364  75ee                   -jne 0x525354
    if (!cpu.flags.zf)
    {
        goto L_0x00525354;
    }
    // 00525366  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525368  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525369  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052536a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525370  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00525374  7209                   -jb 0x52537f
    if (cpu.flags.cf)
    {
        goto L_0x0052537f;
    }
    // 00525376  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052537a  7703                   -ja 0x52537f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052537f;
    }
    // 0052537c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052537f:
    // 0052537f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525380  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525383  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00525385  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00525387  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052538a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525392  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525393  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525396  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525398  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052539a  ff1580775600           -call dword ptr [0x567780]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666688) /* 0x567780 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005253a0  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 005253a5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 005253a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005253a9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 005253ab  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 005253ae  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005253b0  e817000000             -call 0x5253cc
    cpu.esp -= 4;
    sub_5253cc(app, cpu);
    if (cpu.terminate) return;
    // 005253b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005253b7  0f85bb010000           -jne 0x525578
    if (!cpu.flags.zf)
    {
        return sub_525578(app, cpu);
    }
    // 005253bd  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005253c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 005253c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005253c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253c9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253ca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005253cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_5253cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005253cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005253cd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005253ce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005253cf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005253d2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005253d6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 005253d8  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 005253da  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 005253dd  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 005253df  39d8                   +cmp eax, ebx
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
    // 005253e1  7307                   -jae 0x5253ea
    if (!cpu.flags.cf)
    {
        goto L_0x005253ea;
    }
    // 005253e3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005253e8  eb0a                   -jmp 0x5253f4
    goto L_0x005253f4;
L_0x005253ea:
    // 005253ea  83f810                 +cmp eax, 0x10
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
    // 005253ed  7305                   -jae 0x5253f4
    if (!cpu.flags.cf)
    {
        goto L_0x005253f4;
    }
    // 005253ef  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x005253f4:
    // 005253f4  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 005253f7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 005253fa  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 005253fc  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 005253ff  39d0                   +cmp eax, edx
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
    // 00525401  0f860b010000           -jbe 0x525512
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00525512;
    }
    // 00525407  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052540a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052540c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0052540e:
    // 0052540e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00525411  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00525413  83fbff                 +cmp ebx, -1
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
    // 00525416  750a                   -jne 0x525422
    if (!cpu.flags.zf)
    {
        goto L_0x00525422;
    }
    // 00525418  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0052541d  e94d010000             -jmp 0x52556f
    goto L_0x0052556f;
L_0x00525422:
    // 00525422  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00525425  0f85d9000000           -jne 0x525504
    if (!cpu.flags.zf)
    {
        goto L_0x00525504;
    }
    // 0052542b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0052542e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00525432  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00525435  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00525437  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052543b  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 00525440  663b54240c             +cmp dx, word ptr [esp + 0xc]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00525445  7521                   -jne 0x525468
    if (!cpu.flags.zf)
    {
        goto L_0x00525468;
    }
    // 00525447  8b354c6f5600           -mov esi, dword ptr [0x566f4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 0052544d  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525451  7415                   -je 0x525468
    if (cpu.flags.zf)
    {
        goto L_0x00525468;
    }
L_0x00525453:
    // 00525453  39fe                   +cmp esi, edi
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
    // 00525455  7708                   -ja 0x52545f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052545f;
    }
    // 00525457  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00525459  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052545b  39f8                   +cmp eax, edi
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
    // 0052545d  7709                   -ja 0x525468
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00525468;
    }
L_0x0052545f:
    // 0052545f  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00525462  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525466  75eb                   -jne 0x525453
    if (!cpu.flags.zf)
    {
        goto L_0x00525453;
    }
L_0x00525468:
    // 00525468  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052546b  39d1                   +cmp ecx, edx
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
    // 0052546d  7506                   -jne 0x525475
    if (!cpu.flags.zf)
    {
        goto L_0x00525475;
    }
    // 0052546f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00525472  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00525475:
    // 00525475  3b5d00                 +cmp ebx, dword ptr [ebp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525478  720c                   -jb 0x525486
    if (cpu.flags.cf)
    {
        goto L_0x00525486;
    }
    // 0052547a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052547c  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0052547f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00525481  83f810                 +cmp eax, 0x10
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
    // 00525484  7334                   -jae 0x5254ba
    if (!cpu.flags.cf)
    {
        goto L_0x005254ba;
    }
L_0x00525486:
    // 00525486  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052548a  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052548e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00525491  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525493  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00525497  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052549a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052549d  0118                   -add dword ptr [eax], ebx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052549f  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 005254a2  48                     -dec eax
    (cpu.eax)--;
    // 005254a3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 005254a5  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 005254a8  881541b1a000           -mov byte ptr [0xa0b141], dl
    app->getMemory<x86::reg8>(x86::reg32(10531137) /* 0xa0b141 */) = cpu.dl;
    // 005254ae  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 005254b1  39d3                   +cmp ebx, edx
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
    // 005254b3  7244                   -jb 0x5254f9
    if (cpu.flags.cf)
    {
        goto L_0x005254f9;
    }
    // 005254b5  e9b3000000             -jmp 0x52556d
    goto L_0x0052556d;
L_0x005254ba:
    // 005254ba  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 005254bc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 005254be  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005254c2  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005254c5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005254c9  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 005254cc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005254d0  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 005254d3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 005254d7  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 005254da  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 005254dd  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 005254e0  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 005254e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 005254e4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 005254e6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 005254e8  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 005254ea  882541b1a000           -mov byte ptr [0xa0b141], ah
    app->getMemory<x86::reg8>(x86::reg32(10531137) /* 0xa0b141 */) = cpu.ah;
    // 005254f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005254f2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005254f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005254f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005254f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005254f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005254f9:
    // 005254f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 005254fb  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005254fd  01d9                   +add ecx, ebx
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
    // 005254ff  e90affffff             -jmp 0x52540e
    goto L_0x0052540e;
L_0x00525504:
    // 00525504  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00525509  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052550b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052550e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052550f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525511  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525512:
    // 00525512  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00525514  83fa10                 +cmp edx, 0x10
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
    // 00525517  7254                   -jb 0x52556d
    if (cpu.flags.cf)
    {
        goto L_0x0052556d;
    }
    // 00525519  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052551b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0052551e  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00525521  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00525524  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00525526  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00525529  b84c6f5600             -mov eax, 0x566f4c
    cpu.eax = 5664588 /*0x566f4c*/;
    // 0052552e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00525531  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00525533  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00525535  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00525539  6639da                 +cmp dx, bx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052553c  7521                   -jne 0x52555f
    if (!cpu.flags.zf)
    {
        goto L_0x0052555f;
    }
    // 0052553e  8b354c6f5600           -mov esi, dword ptr [0x566f4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5664588) /* 0x566f4c */);
    // 00525544  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525548  7415                   -je 0x52555f
    if (cpu.flags.zf)
    {
        goto L_0x0052555f;
    }
L_0x0052554a:
    // 0052554a  39fe                   +cmp esi, edi
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
    // 0052554c  7708                   -ja 0x525556
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00525556;
    }
    // 0052554e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00525550  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00525552  39f8                   +cmp eax, edi
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
    // 00525554  7709                   -ja 0x52555f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052555f;
    }
L_0x00525556:
    // 00525556  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00525559  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052555d  75eb                   -jne 0x52554a
    if (!cpu.flags.zf)
    {
        goto L_0x0052554a;
    }
L_0x0052555f:
    // 0052555f  ff4618                 -inc dword ptr [esi + 0x18]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))++;
    // 00525562  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00525565  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525568  e88324fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052556d:
    // 0052556d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0052556f:
    // 0052556f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00525571  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00525574  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525575  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525576  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525577  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525578(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525578  ff1588775600           -call dword ptr [0x567788]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666696) /* 0x567788 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052557e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00525580  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525583  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525586  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525592  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525593  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525594  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525596  8b5054                 -mov edx, dword ptr [eax + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00525599  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052559b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052559d  740d                   -je 0x5255ac
    if (cpu.flags.zf)
    {
        goto L_0x005255ac;
    }
    // 0052559f  83795400               +cmp dword ptr [ecx + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005255a3  752e                   -jne 0x5255d3
    if (!cpu.flags.zf)
    {
        goto L_0x005255d3;
    }
    // 005255a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005255a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005255ac:
    // 005255ac  8b4034                 -mov eax, dword ptr [eax + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 005255af  8b358c715600           -mov esi, dword ptr [0x56718c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005255b5  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005255b8  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 005255bb  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 005255be  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 005255c1  ff16                   -call dword ptr [esi]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005255c3  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 005255c6  83795400               +cmp dword ptr [ecx + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005255ca  7507                   -jne 0x5255d3
    if (!cpu.flags.zf)
    {
        goto L_0x005255d3;
    }
    // 005255cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005255ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005255d3:
    // 005255d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005255d5  e8d6710000             -call 0x52c7b0
    cpu.esp -= 4;
    sub_52c7b0(app, cpu);
    if (cpu.terminate) return;
    // 005255da  8b358c715600           -mov esi, dword ptr [0x56718c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 005255e0  8d597c                 -lea ebx, [ecx + 0x7c]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(124) /* 0x7c */);
    // 005255e3  8b5134                 -mov edx, dword ptr [ecx + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */);
    // 005255e6  8b4154                 -mov eax, dword ptr [ecx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 005255e9  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005255ec  ff5604                 -call dword ptr [esi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005255ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 005255f1  c681bc00000000         -mov byte ptr [ecx + 0xbc], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 005255f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005255fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005255fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_525600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525600  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525601  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525603  83785400               +cmp dword ptr [eax + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525607  7502                   -jne 0x52560b
    if (!cpu.flags.zf)
    {
        goto L_0x0052560b;
    }
    // 00525609  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052560a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052560b:
    // 0052560b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052560c  8b0d8c715600           -mov ecx, dword ptr [0x56718c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00525612  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00525615  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525618  c7425400000000         -mov dword ptr [edx + 0x54], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 0052561f  c682bc00000001         -mov byte ptr [edx + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 00525626  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525627  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525628  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525630  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525631  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525632  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00525634  42                     -inc edx
    (cpu.edx)++;
    // 00525635  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525637  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0052563a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052563c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052563e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052563f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_525650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525650  83f820                 +cmp eax, 0x20
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
    // 00525653  7c12                   -jl 0x525667
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00525667;
    }
    // 00525655  83f87f                 +cmp eax, 0x7f
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
    // 00525658  7f0d                   -jg 0x525667
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00525667;
    }
    // 0052565a  668b0445b8af5600       -mov ax, word ptr [eax*2 + 0x56afb8]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5681080) /* 0x56afb8 */ + cpu.eax * 2);
    // 00525662  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x00525667:
    // 00525667  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_525670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525670  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525671  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525672  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525674  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00525676  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00525678  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0052567a  42                     -inc edx
    (cpu.edx)++;
    // 0052567b  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0052567d  7416                   -je 0x525695
    if (cpu.flags.zf)
    {
        goto L_0x00525695;
    }
    // 0052567f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525680  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00525682  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00525685  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00525687  42                     -inc edx
    (cpu.edx)++;
    // 00525688  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052568a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052568b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0052568d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00525692  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525693  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525694  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525695:
    // 00525695  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0052569a  e8b1ffffff             -call 0x525650
    cpu.esp -= 4;
    sub_525650(app, cpu);
    if (cpu.terminate) return;
    // 0052569f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 005256a1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 005256a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005256a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005256a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_5256b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005256b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005256b1  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005256b4  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 005256bb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005256bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 005256bf  0f8e89000000           -jle 0x52574e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052574e;
    }
L_0x005256c5:
    // 005256c5  d9054082a100           +fld dword ptr [0xa18240]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584640) /* 0xa18240 */)));
    // 005256cb  d81a                   +fcomp dword ptr [edx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx)));
    cpu.fpu.pop();
    // 005256cd  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005256cf  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005256d0  0f8282000000           -jb 0x525758
    if (cpu.flags.cf)
    {
        goto L_0x00525758;
    }
    // 005256d6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
L_0x005256d8:
    // 005256d8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 005256dc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 005256e0  d9054482a100           +fld dword ptr [0xa18244]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584644) /* 0xa18244 */)));
    // 005256e6  a34082a100             -mov dword ptr [0xa18240], eax
    app->getMemory<x86::reg32>(x86::reg32(10584640) /* 0xa18240 */) = cpu.eax;
    // 005256eb  d85a04                 +fcomp dword ptr [edx + 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    cpu.fpu.pop();
    // 005256ee  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 005256f0  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 005256f1  736f                   -jae 0x525762
    if (!cpu.flags.cf)
    {
        goto L_0x00525762;
    }
    // 005256f3  a14482a100             -mov eax, dword ptr [0xa18244]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584644) /* 0xa18244 */);
L_0x005256f8:
    // 005256f8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 005256fc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00525700  d9054c82a100           +fld dword ptr [0xa1824c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584652) /* 0xa1824c */)));
    // 00525706  a34482a100             -mov dword ptr [0xa18244], eax
    app->getMemory<x86::reg32>(x86::reg32(10584644) /* 0xa18244 */) = cpu.eax;
    // 0052570b  d81a                   +fcomp dword ptr [edx]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx)));
    cpu.fpu.pop();
    // 0052570d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052570f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00525710  7655                   -jbe 0x525767
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00525767;
    }
    // 00525712  a14c82a100             -mov eax, dword ptr [0xa1824c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584652) /* 0xa1824c */);
L_0x00525717:
    // 00525717  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052571a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0052571d  d9054882a100           +fld dword ptr [0xa18248]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584648) /* 0xa18248 */)));
    // 00525723  a34c82a100             -mov dword ptr [0xa1824c], eax
    app->getMemory<x86::reg32>(x86::reg32(10584652) /* 0xa1824c */) = cpu.eax;
    // 00525728  d85a04                 +fcomp dword ptr [edx + 4]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    cpu.fpu.pop();
    // 0052572b  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052572d  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052572e  763b                   -jbe 0x52576b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052576b;
    }
    // 00525730  a14882a100             -mov eax, dword ptr [0xa18248]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584648) /* 0xa18248 */);
L_0x00525735:
    // 00525735  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00525739  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052573d  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00525740  41                     -inc ecx
    (cpu.ecx)++;
    // 00525741  a34882a100             -mov dword ptr [0xa18248], eax
    app->getMemory<x86::reg32>(x86::reg32(10584648) /* 0xa18248 */) = cpu.eax;
    // 00525746  39d9                   +cmp ecx, ebx
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
    // 00525748  0f8c77ffffff           -jl 0x5256c5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005256c5;
    }
L_0x0052574e:
    // 0052574e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00525753  83c410                 +add esp, 0x10
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
    // 00525756  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525757  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525758:
    // 00525758  a14082a100             -mov eax, dword ptr [0xa18240]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584640) /* 0xa18240 */);
    // 0052575d  e976ffffff             -jmp 0x5256d8
    goto L_0x005256d8;
L_0x00525762:
    // 00525762  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00525765  eb91                   -jmp 0x5256f8
    goto L_0x005256f8;
L_0x00525767:
    // 00525767  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00525769  ebac                   -jmp 0x525717
    goto L_0x00525717;
L_0x0052576b:
    // 0052576b  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052576e  ebc5                   -jmp 0x525735
    goto L_0x00525735;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_5257c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005257c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005257c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005257c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005257c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005257c4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 005257c6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 005257c9  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 005257cc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005257ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005257d0  83fa10                 +cmp edx, 0x10
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
    // 005257d3  774a                   -ja 0x52581f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052581f;
    }
L_0x005257d5:
    // 005257d5  ff249570575200         -jmp dword ptr [edx*4 + 0x525770]
    cpu.ip = app->getMemory<x86::reg32>(5396336 + cpu.edx * 4); goto dynamic_jump;
  case 0x005257dc:
    // 005257dc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 005257e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005257e3  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 005257e5  e8d6ffffff             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 005257ea  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 005257ef  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 005257f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005257f6  e8c5ffffff             -call 0x5257c0
    cpu.esp -= 4;
    sub_5257c0(app, cpu);
    if (cpu.terminate) return;
    // 005257fb  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 00525800  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00525805  ebce                   -jmp 0x5257d5
    goto L_0x005257d5;
  case 0x00525807:
    // 00525807  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00525809  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052580c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00525810  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00525813  dc0de01e5500           -fmul qword ptr [0x551ee0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578464) /* 0x551ee0 */));
    // 00525819  d999c0000000           -fstp dword ptr [ecx + 0xc0]
    app->getMemory<float>(cpu.ecx + x86::reg32(192) /* 0xc0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052581f:
    // 0052581f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525821  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525822  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525823  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525824  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525825  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525826:
    // 00525826  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00525828  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052582b  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052582f  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00525832  dc0de01e5500           -fmul qword ptr [0x551ee0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578464) /* 0x551ee0 */));
    // 00525838  d999c4000000           -fstp dword ptr [ecx + 0xc4]
    app->getMemory<float>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052583e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525840  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525841  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525842  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525843  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525844  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525845:
    // 00525845  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525847  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052584a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052584e  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00525851  dc0de01e5500           -fmul qword ptr [0x551ee0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578464) /* 0x551ee0 */));
    // 00525857  d999c8000000           -fstp dword ptr [ecx + 0xc8]
    app->getMemory<float>(cpu.ecx + x86::reg32(200) /* 0xc8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052585d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052585f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525860  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525861  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525862  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525863  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525864:
    // 00525864  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525866  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00525869  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052586d  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 00525870  dc0de01e5500           -fmul qword ptr [0x551ee0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578464) /* 0x551ee0 */));
    // 00525876  d8b1c8000000           -fdiv dword ptr [ecx + 0xc8]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(200) /* 0xc8 */));
    // 0052587c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052587f  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00525882  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525883  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00525886  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525888  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525889  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052588a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052588b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052588c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052588d:
    // 0052588d  83f801                 +cmp eax, 1
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
    // 00525890  750e                   -jne 0x5258a0
    if (!cpu.flags.zf)
    {
        goto L_0x005258a0;
    }
    // 00525892  8089cc00000001         -or byte ptr [ecx + 0xcc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00525899  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052589b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052589c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052589d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052589e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052589f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005258a0:
    // 005258a0  80a1cc000000fe         -and byte ptr [ecx + 0xcc], 0xfe
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 005258a7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005258a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ad  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x005258ae:
    // 005258ae  83f801                 +cmp eax, 1
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
    // 005258b1  750e                   -jne 0x5258c1
    if (!cpu.flags.zf)
    {
        goto L_0x005258c1;
    }
    // 005258b3  8089cc00000002         -or byte ptr [ecx + 0xcc], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 005258ba  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005258bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005258c1:
    // 005258c1  80a1cc000000fd         -and byte ptr [ecx + 0xcc], 0xfd
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 005258c8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005258ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ce  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x005258cf:
    // 005258cf  83f801                 +cmp eax, 1
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
    // 005258d2  750e                   -jne 0x5258e2
    if (!cpu.flags.zf)
    {
        goto L_0x005258e2;
    }
    // 005258d4  8089cc00000004         -or byte ptr [ecx + 0xcc], 4
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 005258db  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005258dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005258e2:
    // 005258e2  80a1cc000000fb         -and byte ptr [ecx + 0xcc], 0xfb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(204) /* 0xcc */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 005258e9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 005258eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005258ef  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x005258f0:
    // 005258f0  3b416c                 +cmp eax, dword ptr [ecx + 0x6c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005258f3  0f8426ffffff           -je 0x52581f
    if (cpu.flags.zf)
    {
        goto L_0x0052581f;
    }
    // 005258f9  c681bc00000001         -mov byte ptr [ecx + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 00525900  89416c                 -mov dword ptr [ecx + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00525903  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525905  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525906  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525907  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525908  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525909  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052590a:
    // 0052590a  3b4170                 +cmp eax, dword ptr [ecx + 0x70]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052590d  0f840cffffff           -je 0x52581f
    if (cpu.flags.zf)
    {
        goto L_0x0052581f;
    }
    // 00525913  c681bc00000001         -mov byte ptr [ecx + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 0052591a  894170                 -mov dword ptr [ecx + 0x70], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0052591d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052591f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525920  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525921  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525922  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525923  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525924:
    // 00525924  3b4174                 +cmp eax, dword ptr [ecx + 0x74]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525927  0f84f2feffff           -je 0x52581f
    if (cpu.flags.zf)
    {
        goto L_0x0052581f;
    }
    // 0052592d  c681bc00000001         -mov byte ptr [ecx + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 00525934  894174                 -mov dword ptr [ecx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00525937  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525939  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052593a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052593b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052593c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052593d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052593e:
    // 0052593e  3b4178                 +cmp eax, dword ptr [ecx + 0x78]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525941  0f84d8feffff           -je 0x52581f
    if (cpu.flags.zf)
    {
        goto L_0x0052581f;
    }
    // 00525947  c681bc00000001         -mov byte ptr [ecx + 0xbc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(188) /* 0xbc */) = 1 /*0x1*/;
    // 0052594e  894178                 -mov dword ptr [ecx + 0x78], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00525951  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525953  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525955  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525957  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525958:
    // 00525958  894160                 -mov dword ptr [ecx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0052595b  894164                 -mov dword ptr [ecx + 0x64], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0052595e  894168                 -mov dword ptr [ecx + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */) = cpu.eax;
  [[fallthrough]];
  case 0x00525961:
    // 00525961  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 00525964  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525966  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525967  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525968  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525969  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052596a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052596b:
    // 0052596b  894160                 -mov dword ptr [ecx + 0x60], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0052596e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525970  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525971  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525972  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525973  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525974  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525975:
    // 00525975  894164                 -mov dword ptr [ecx + 0x64], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00525978  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0052597a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052597b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052597c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052597d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052597e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052597f:
    // 0052597f  894168                 -mov dword ptr [ecx + 0x68], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00525982  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00525984  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525985  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525986  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525987  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525988  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_5259d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 005259d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005259d1  4a                     -dec edx
    (cpu.edx)--;
    // 005259d2  83fa0f                 +cmp edx, 0xf
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
    // 005259d5  771c                   -ja 0x5259f3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x005259f3;
    }
    // 005259d7  ff24958c595200         -jmp dword ptr [edx*4 + 0x52598c]
    cpu.ip = app->getMemory<x86::reg32>(5396876 + cpu.edx * 4); goto dynamic_jump;
  case 0x005259de:
    // 005259de  d980c0000000           -fld dword ptr [eax + 0xc0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(192) /* 0xc0 */)));
    // 005259e4  dc0de81e5500           -fmul qword ptr [0x551ee8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578472) /* 0x551ee8 */));
    // 005259ea  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005259ed  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 005259f0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005259f1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x005259f3:
    // 005259f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 005259f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005259f6  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x005259f7:
    // 005259f7  d980c4000000           -fld dword ptr [eax + 0xc4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(196) /* 0xc4 */)));
    // 005259fd  dc0de81e5500           -fmul qword ptr [0x551ee8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578472) /* 0x551ee8 */));
    // 00525a03  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525a06  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00525a09  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a0a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525a0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a0f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a10:
    // 00525a10  d980c8000000           -fld dword ptr [eax + 0xc8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(200) /* 0xc8 */)));
    // 00525a16  dc0de81e5500           -fmul qword ptr [0x551ee8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578472) /* 0x551ee8 */));
    // 00525a1c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525a1f  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00525a22  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a23  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525a25  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a28  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a29:
    // 00525a29  db4018                 -fild dword ptr [eax + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */))));
    // 00525a2c  d888c8000000           -fmul dword ptr [eax + 0xc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(200) /* 0xc8 */));
    // 00525a32  dc0de81e5500           -fmul qword ptr [0x551ee8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5578472) /* 0x551ee8 */));
    // 00525a38  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00525a3b  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00525a3e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a3f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525a41  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a44  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a45:
    // 00525a45  f680cc00000001         +test byte ptr [eax + 0xcc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(204) /* 0xcc */) & 1 /*0x1*/));
    // 00525a4c  7409                   -je 0x525a57
    if (cpu.flags.zf)
    {
        goto L_0x00525a57;
    }
    // 00525a4e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00525a53  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525a57:
    // 00525a57  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525a59  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a5c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a5d:
    // 00525a5d  f680cc00000002         +test byte ptr [eax + 0xcc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(204) /* 0xcc */) & 2 /*0x2*/));
    // 00525a64  74f1                   -je 0x525a57
    if (cpu.flags.zf)
    {
        goto L_0x00525a57;
    }
    // 00525a66  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00525a6b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a6e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a6f:
    // 00525a6f  f680cc00000004         +test byte ptr [eax + 0xcc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(204) /* 0xcc */) & 4 /*0x4*/));
    // 00525a76  74df                   -je 0x525a57
    if (cpu.flags.zf)
    {
        goto L_0x00525a57;
    }
    // 00525a78  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00525a7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a80  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a81:
    // 00525a81  8b486c                 -mov ecx, dword ptr [eax + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 00525a84  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a87  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a88:
    // 00525a88  8b4870                 -mov ecx, dword ptr [eax + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00525a8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a8e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a8f:
    // 00525a8f  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00525a92  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a95  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a96:
    // 00525a96  8b4878                 -mov ecx, dword ptr [eax + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 00525a99  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525a9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525a9c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525a9d:
    // 00525a9d  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 00525aa0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525aa2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525aa3  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525aa4:
    // 00525aa4  8b4860                 -mov ecx, dword ptr [eax + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 00525aa7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525aa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525aaa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525aab:
    // 00525aab  8b4864                 -mov ecx, dword ptr [eax + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 00525aae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525ab0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525ab1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00525ab2:
    // 00525ab2  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 00525ab5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525ab7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525ab8  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_525ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525ac0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525ac1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525ac2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525ac3  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00525ac6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00525ac8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00525aca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525acc  89154482a100           -mov dword ptr [0xa18244], edx
    app->getMemory<x86::reg32>(x86::reg32(10584644) /* 0xa18244 */) = cpu.edx;
    // 00525ad2  89154c82a100           -mov dword ptr [0xa1824c], edx
    app->getMemory<x86::reg32>(x86::reg32(10584652) /* 0xa1824c */) = cpu.edx;
    // 00525ad8  89154882a100           -mov dword ptr [0xa18248], edx
    app->getMemory<x86::reg32>(x86::reg32(10584648) /* 0xa18248 */) = cpu.edx;
    // 00525ade  89154082a100           -mov dword ptr [0xa18240], edx
    app->getMemory<x86::reg32>(x86::reg32(10584640) /* 0xa18240 */) = cpu.edx;
    // 00525ae4  8b158c715600           -mov edx, dword ptr [0x56718c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */);
    // 00525aea  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00525aec  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00525aef  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00525af2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00525af6  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00525af9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00525afd  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00525b00  bdb0565200             -mov ebp, 0x5256b0
    cpu.ebp = 5396144 /*0x5256b0*/;
    // 00525b05  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00525b09  896c2410               -mov dword ptr [esp + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 00525b0d  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00525b10  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00525b14  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00525b17  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00525b1b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00525b1d  a38c715600             -mov dword ptr [0x56718c], eax
    app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */) = cpu.eax;
    // 00525b22  803e00                 +cmp byte ptr [esi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00525b25  7543                   -jne 0x525b6a
    if (!cpu.flags.zf)
    {
        goto L_0x00525b6a;
    }
L_0x00525b27:
    // 00525b27  d9054082a100           -fld dword ptr [0xa18240]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584640) /* 0xa18240 */)));
    // 00525b2d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00525b2f  d9054482a100           -fld dword ptr [0xa18244]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584644) /* 0xa18244 */)));
    // 00525b35  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00525b37  d9054c82a100           -fld dword ptr [0xa1824c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584652) /* 0xa1824c */)));
    // 00525b3d  d9054882a100           -fld dword ptr [0xa18248]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(10584648) /* 0xa18248 */)));
    // 00525b43  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00525b47  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00525b49  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00525b4b  dee4                   -fsubrp st(4)
    cpu.fpu.st(4) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(4));
    cpu.fpu.pop();
    // 00525b4d  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00525b4f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00525b51  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00525b53  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00525b57  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00525b59  89158c715600           -mov dword ptr [0x56718c], edx
    app->getMemory<x86::reg32>(x86::reg32(5665164) /* 0x56718c */) = cpu.edx;
    // 00525b5f  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00525b61  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00525b64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525b65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525b66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525b67  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00525b6a:
    // 00525b6a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525b6b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00525b6d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00525b6f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00525b71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525b72  e8b942ffff             -call 0x519e30
    cpu.esp -= 4;
    sub_519e30(app, cpu);
    if (cpu.terminate) return;
    // 00525b77  83c414                 +add esp, 0x14
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
    // 00525b7a  ebab                   -jmp 0x525b27
    goto L_0x00525b27;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_525b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525b80  895850                 -mov dword ptr [eax + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00525b83  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 00525b86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_525b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525b91  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00525b94  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00525b96  8b4050                 -mov eax, dword ptr [eax + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 00525b99  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00525b9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525b9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_525ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525ba0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525ba1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525ba2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525ba3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525ba4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525ba5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00525ba8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525baa  83f8ff                 +cmp eax, -1
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
    // 00525bad  750e                   -jne 0x525bbd
    if (!cpu.flags.zf)
    {
        goto L_0x00525bbd;
    }
    // 00525baf  2eff15e0445300         -call dword ptr cs:[0x5344e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457120) /* 0x5344e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525bb6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525bb8  e998000000             -jmp 0x525c55
    goto L_0x00525c55;
L_0x00525bbd:
    // 00525bbd  83f8fe                 +cmp eax, -2
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
    // 00525bc0  750e                   -jne 0x525bd0
    if (!cpu.flags.zf)
    {
        goto L_0x00525bd0;
    }
    // 00525bc2  2eff1550455300         -call dword ptr cs:[0x534550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457232) /* 0x534550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525bc9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525bcb  e985000000             -jmp 0x525c55
    goto L_0x00525c55;
L_0x00525bd0:
    // 00525bd0  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525bd3  7526                   -jne 0x525bfb
    if (!cpu.flags.zf)
    {
        goto L_0x00525bfb;
    }
    // 00525bd5  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00525bda  b810b2a000             -mov eax, 0xa0b210
    cpu.eax = 10531344 /*0xa0b210*/;
    // 00525bdf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525be1  e85aaafbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00525be6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525be8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00525bea  891500b2a000           -mov dword ptr [0xa0b200], edx
    app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */) = cpu.edx;
    // 00525bf0  8915b8b05600           -mov dword ptr [0x56b0b8], edx
    app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */) = cpu.edx;
    // 00525bf6  e9ff000000             -jmp 0x525cfa
    goto L_0x00525cfa;
L_0x00525bfb:
    // 00525bfb  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525bfe  7555                   -jne 0x525c55
    if (!cpu.flags.zf)
    {
        goto L_0x00525c55;
    }
    // 00525c00  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00525c05  b810b2a000             -mov eax, 0xa0b210
    cpu.eax = 10531344 /*0xa0b210*/;
    // 00525c0a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525c0c  e82faafbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00525c11  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 00525c16  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x00525c18:
    // 00525c18  40                     -inc eax
    (cpu.eax)++;
    // 00525c19  889010b2a000           -mov byte ptr [eax + 0xa0b210], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531344) /* 0xa0b210 */) = cpu.dl;
    // 00525c1f  3d9f000000             +cmp eax, 0x9f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(159 /*0x9f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525c24  7ef2                   -jle 0x525c18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00525c18;
    }
    // 00525c26  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00525c2b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x00525c2d:
    // 00525c2d  40                     -inc eax
    (cpu.eax)++;
    // 00525c2e  88b010b2a000           -mov byte ptr [eax + 0xa0b210], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531344) /* 0xa0b210 */) = cpu.dh;
    // 00525c34  3dfc000000             +cmp eax, 0xfc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00525c39  7ef2                   -jle 0x525c2d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00525c2d;
    }
    // 00525c3b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00525c40  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 00525c45  892d00b2a000           -mov dword ptr [0xa0b200], ebp
    app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */) = cpu.ebp;
    // 00525c4b  a3b8b05600             -mov dword ptr [0x56b0b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */) = cpu.eax;
    // 00525c50  e9a3000000             -jmp 0x525cf8
    goto L_0x00525cf8;
L_0x00525c55:
    // 00525c55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00525c57  7505                   -jne 0x525c5e
    if (!cpu.flags.zf)
    {
        goto L_0x00525c5e;
    }
    // 00525c59  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00525c5e:
    // 00525c5e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00525c60  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00525c61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525c62  2eff15e4445300         -call dword ptr cs:[0x5344e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457124) /* 0x5344e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525c69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525c6b  750e                   -jne 0x525c7b
    if (!cpu.flags.zf)
    {
        goto L_0x00525c7b;
    }
    // 00525c6d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00525c72  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00525c75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525c76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525c77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525c78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525c79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525c7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525c7b:
    // 00525c7b  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00525c80  b810b2a000             -mov eax, 0xa0b210
    cpu.eax = 10531344 /*0xa0b210*/;
    // 00525c85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525c87  e8b4a9fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 00525c8c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525c8e  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00525c92  890d00b2a000           -mov dword ptr [0xa0b200], ecx
    app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */) = cpu.ecx;
    // 00525c98  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00525c9a  740a                   -je 0x525ca6
    if (cpu.flags.zf)
    {
        goto L_0x00525ca6;
    }
    // 00525c9c  c70500b2a00001000000   -mov dword ptr [0xa0b200], 1
    app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */) = 1 /*0x1*/;
L_0x00525ca6:
    // 00525ca6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00525ca8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00525caa  eb1c                   -jmp 0x525cc8
    goto L_0x00525cc8;
L_0x00525cac:
    // 00525cac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00525cae  8a441c06               -mov al, byte ptr [esp + ebx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
    // 00525cb2  eb07                   -jmp 0x525cbb
    goto L_0x00525cbb;
L_0x00525cb4:
    // 00525cb4  40                     -inc eax
    (cpu.eax)++;
    // 00525cb5  888810b2a000           -mov byte ptr [eax + 0xa0b210], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531344) /* 0xa0b210 */) = cpu.cl;
L_0x00525cbb:
    // 00525cbb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525cbd  8a541c07               -mov dl, byte ptr [esp + ebx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
    // 00525cc1  39d0                   +cmp eax, edx
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
    // 00525cc3  7eef                   -jle 0x525cb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00525cb4;
    }
    // 00525cc5  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00525cc8:
    // 00525cc8  807c1c0600             +cmp byte ptr [esp + ebx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00525ccd  75dd                   -jne 0x525cac
    if (!cpu.flags.zf)
    {
        goto L_0x00525cac;
    }
    // 00525ccf  807c1c0700             +cmp byte ptr [esp + ebx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00525cd4  75d6                   -jne 0x525cac
    if (!cpu.flags.zf)
    {
        goto L_0x00525cac;
    }
    // 00525cd6  83fe01                 +cmp esi, 1
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
    // 00525cd9  7517                   -jne 0x525cf2
    if (!cpu.flags.zf)
    {
        goto L_0x00525cf2;
    }
    // 00525cdb  2eff1550455300         -call dword ptr cs:[0x534550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457232) /* 0x534550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525ce2  a3b8b05600             -mov dword ptr [0x56b0b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */) = cpu.eax;
    // 00525ce7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00525ce9  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00525cec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525ced  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cf0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cf1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525cf2:
    // 00525cf2  8935b8b05600           -mov dword ptr [0x56b0b8], esi
    app->getMemory<x86::reg32>(x86::reg32(5681336) /* 0x56b0b8 */) = cpu.esi;
L_0x00525cf8:
    // 00525cf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00525cfa:
    // 00525cfa  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00525cfd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525cff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525d00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525d01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525d02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_525d04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525d04  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00525d06  781e                   -js 0x525d26
    if (cpu.flags.sf)
    {
        goto L_0x00525d26;
    }
    // 00525d08  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00525d0a  7806                   -js 0x525d12
    if (cpu.flags.sf)
    {
        goto L_0x00525d12;
    }
    // 00525d0c  e848000000             -call 0x525d59
    cpu.esp -= 4;
    sub_525d59(app, cpu);
    if (cpu.terminate) return;
    // 00525d11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d12:
    // 00525d12  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00525d14  f7db                   +neg ebx
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
    // 00525d16  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d19  e83b000000             -call 0x525d59
    cpu.esp -= 4;
    sub_525d59(app, cpu);
    if (cpu.terminate) return;
    // 00525d1e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00525d20  f7d8                   +neg eax
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
    // 00525d22  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d26:
    // 00525d26  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00525d28  f7d8                   +neg eax
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
    // 00525d2a  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d2d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00525d2f  7914                   -jns 0x525d45
    if (!cpu.flags.sf)
    {
        goto L_0x00525d45;
    }
    // 00525d31  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00525d33  f7db                   +neg ebx
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
    // 00525d35  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d38  e81c000000             -call 0x525d59
    cpu.esp -= 4;
    sub_525d59(app, cpu);
    if (cpu.terminate) return;
    // 00525d3d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00525d3f  f7db                   +neg ebx
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
    // 00525d41  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d45:
    // 00525d45  e80f000000             -call 0x525d59
    cpu.esp -= 4;
    sub_525d59(app, cpu);
    if (cpu.terminate) return;
    // 00525d4a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00525d4c  f7db                   +neg ebx
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
    // 00525d4e  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d51  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00525d53  f7d8                   +neg eax
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
    // 00525d55  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00525d58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525d59(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525d59  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00525d5b  751a                   -jne 0x525d77
    if (!cpu.flags.zf)
    {
        goto L_0x00525d77;
    }
    // 00525d5d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00525d5e  7416                   -je 0x525d76
    if (cpu.flags.zf)
    {
        goto L_0x00525d76;
    }
    // 00525d60  43                     -inc ebx
    (cpu.ebx)++;
    // 00525d61  39d3                   +cmp ebx, edx
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
    // 00525d63  7709                   -ja 0x525d6e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00525d6e;
    }
    // 00525d65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00525d67  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525d69  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00525d6b  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00525d6d  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x00525d6e:
    // 00525d6e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00525d70  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00525d72  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00525d74  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00525d76:
    // 00525d76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d77:
    // 00525d77  39d1                   +cmp ecx, edx
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
    // 00525d79  721c                   -jb 0x525d97
    if (cpu.flags.cf)
    {
        goto L_0x00525d97;
    }
    // 00525d7b  7512                   -jne 0x525d8f
    if (!cpu.flags.zf)
    {
        goto L_0x00525d8f;
    }
    // 00525d7d  39c3                   +cmp ebx, eax
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
    // 00525d7f  770e                   -ja 0x525d8f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00525d8f;
    }
    // 00525d81  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525d83  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00525d85  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525d87  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00525d89  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00525d8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d8f:
    // 00525d8f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00525d91  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525d93  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00525d94  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 00525d96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00525d97:
    // 00525d97  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525d98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525d99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525d9a  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00525d9c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00525d9e  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00525da0:
    // 00525da0  01db                   +add ebx, ebx
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
    // 00525da2  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525da4  7213                   -jb 0x525db9
    if (cpu.flags.cf)
    {
        goto L_0x00525db9;
    }
    // 00525da6  45                     -inc ebp
    (cpu.ebp)++;
    // 00525da7  39d1                   +cmp ecx, edx
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
    // 00525da9  72f5                   -jb 0x525da0
    if (cpu.flags.cf)
    {
        goto L_0x00525da0;
    }
    // 00525dab  7704                   -ja 0x525db1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00525db1;
    }
    // 00525dad  39c3                   +cmp ebx, eax
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
    // 00525daf  76ef                   -jbe 0x525da0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00525da0;
    }
L_0x00525db1:
    // 00525db1  f8                     +clc 
    cpu.flags.cf = 0;
L_0x00525db2:
    // 00525db2  11f6                   +adc esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525db4  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525db6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00525db7  7822                   -js 0x525ddb
    if (cpu.flags.sf)
    {
        goto L_0x00525ddb;
    }
L_0x00525db9:
    // 00525db9  d1d9                   +rcr ecx, 1
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
    // 00525dbb  d1db                   -rcr ebx, 1
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
    // 00525dbd  29d8                   +sub eax, ebx
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
    // 00525dbf  19ca                   +sbb edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525dc1  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 00525dc2  72ee                   -jb 0x525db2
    if (cpu.flags.cf)
    {
        goto L_0x00525db2;
    }
L_0x00525dc4:
    // 00525dc4  01f6                   +add esi, esi
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
    // 00525dc6  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525dc8  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00525dc9  780c                   -js 0x525dd7
    if (cpu.flags.sf)
    {
        goto L_0x00525dd7;
    }
    // 00525dcb  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00525dcd  d1db                   -rcr ebx, 1
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
    // 00525dcf  01d8                   +add eax, ebx
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
    // 00525dd1  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00525dd3  73ef                   -jae 0x525dc4
    if (!cpu.flags.cf)
    {
        goto L_0x00525dc4;
    }
    // 00525dd5  ebdb                   -jmp 0x525db2
    goto L_0x00525db2;
L_0x00525dd7:
    // 00525dd7  01d8                   +add eax, ebx
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
    // 00525dd9  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x00525ddb:
    // 00525ddb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00525ddd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00525ddf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00525de1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00525de3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525de4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525de5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525de6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525df1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00525df4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00525df6  e8051bfdff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 00525dfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525dfd  7407                   -je 0x525e06
    if (cpu.flags.zf)
    {
        goto L_0x00525e06;
    }
    // 00525dff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00525e01  e83aa8fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x00525e06:
    // 00525e06  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525e07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_525e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525e10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525e11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525e12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525e13  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00525e15  e86e8affff             -call 0x51e888
    cpu.esp -= 4;
    sub_51e888(app, cpu);
    if (cpu.terminate) return;
    // 00525e1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00525e1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525e1e  7410                   -je 0x525e30
    if (cpu.flags.zf)
    {
        goto L_0x00525e30;
    }
    // 00525e20  8b1560775600           -mov edx, dword ptr [0x567760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 00525e26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525e27  2eff1514465300         -call dword ptr cs:[0x534614]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457428) /* 0x534614 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525e2e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00525e30:
    // 00525e30  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00525e32  750f                   -jne 0x525e43
    if (!cpu.flags.zf)
    {
        goto L_0x00525e43;
    }
    // 00525e34  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00525e39  b8f01e5500             -mov eax, 0x551ef0
    cpu.eax = 5578480 /*0x551ef0*/;
    // 00525e3e  e8c9befeff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_0x00525e43:
    // 00525e43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00525e45  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525e46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525e47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525e48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_525e4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525e4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525e4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525e4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525e4f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525e50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525e51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525e52  ff1590775600           -call dword ptr [0x567790]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666704) /* 0x567790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525e58  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525e5f  8b1d5082a100           -mov ebx, dword ptr [0xa18250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */);
    // 00525e65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00525e67  740b                   -je 0x525e74
    if (cpu.flags.zf)
    {
        goto L_0x00525e74;
    }
L_0x00525e69:
    // 00525e69  3b4304                 +cmp eax, dword ptr [ebx + 4]
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
    // 00525e6c  7406                   -je 0x525e74
    if (cpu.flags.zf)
    {
        goto L_0x00525e74;
    }
    // 00525e6e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00525e70  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00525e72  75f5                   -jne 0x525e69
    if (!cpu.flags.zf)
    {
        goto L_0x00525e69;
    }
L_0x00525e74:
    // 00525e74  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 00525e78  7425                   -je 0x525e9f
    if (cpu.flags.zf)
    {
        goto L_0x00525e9f;
    }
    // 00525e7a  8b1570af5600           -mov edx, dword ptr [0x56af70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 00525e80  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00525e83  e83827ffff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 00525e88  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00525e8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525e8c  755e                   -jne 0x525eec
    if (!cpu.flags.zf)
    {
        goto L_0x00525eec;
    }
    // 00525e8e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00525e93  b8181f5500             -mov eax, 0x551f18
    cpu.eax = 5578520 /*0x551f18*/;
    // 00525e98  e86fbefeff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 00525e9d  eb4d                   -jmp 0x525eec
    goto L_0x00525eec;
L_0x00525e9f:
    // 00525e9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00525ea4  8b1570af5600           -mov edx, dword ptr [0x56af70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 00525eaa  e841ffffff             -call 0x525df0
    cpu.esp -= 4;
    sub_525df0(app, cpu);
    if (cpu.terminate) return;
    // 00525eaf  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00525eb1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525eb3  750f                   -jne 0x525ec4
    if (!cpu.flags.zf)
    {
        goto L_0x00525ec4;
    }
    // 00525eb5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00525eba  b8401f5500             -mov eax, 0x551f40
    cpu.eax = 5578560 /*0x551f40*/;
    // 00525ebf  e848befeff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
L_0x00525ec4:
    // 00525ec4  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00525ec7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00525ec9  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00525ecf  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00525ed0  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00525ed2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00525ed4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00525ed5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525ed7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00525eda  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00525edc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00525ede  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00525ee1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00525ee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525ee4  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00525ee5  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00525eec:
    // 00525eec  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00525eef  a170af5600             -mov eax, dword ptr [0x56af70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681008) /* 0x56af70 */);
    // 00525ef4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00525ef5  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00525ef9  8b3560775600           -mov esi, dword ptr [0x567760]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5666656) /* 0x567760 */);
    // 00525eff  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00525f03  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525f04  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00525f0a  2eff1518465300         -call dword ptr cs:[0x534618]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457432) /* 0x534618 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525f11  ff1594775600           -call dword ptr [0x567794]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666708) /* 0x567794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525f17  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00525f19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525f22  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00525f23  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00525f25  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00525f27  ff1590775600           -call dword ptr [0x567790]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666704) /* 0x567790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525f2d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00525f32  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00525f37  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525f39  e8b2feffff             -call 0x525df0
    cpu.esp -= 4;
    sub_525df0(app, cpu);
    if (cpu.terminate) return;
    // 00525f3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00525f40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525f42  742f                   -je 0x525f73
    if (cpu.flags.zf)
    {
        goto L_0x00525f73;
    }
    // 00525f44  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00525f46  e8d9680000             -call 0x52c824
    cpu.esp -= 4;
    sub_52c824(app, cpu);
    if (cpu.terminate) return;
    // 00525f4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525f4d  7409                   -je 0x525f58
    if (cpu.flags.zf)
    {
        goto L_0x00525f58;
    }
    // 00525f4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525f51  e89a1afdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00525f56  eb1b                   -jmp 0x525f73
    goto L_0x00525f73;
L_0x00525f58:
    // 00525f58  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00525f5b  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00525f5e  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00525f61  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00525f64  a15082a100             -mov eax, dword ptr [0xa18250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */);
    // 00525f69  89155082a100           -mov dword ptr [0xa18250], edx
    app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */) = cpu.edx;
    // 00525f6f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00525f71  eb02                   -jmp 0x525f75
    goto L_0x00525f75;
L_0x00525f73:
    // 00525f73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00525f75:
    // 00525f75  ff1594775600           -call dword ptr [0x567794]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666708) /* 0x567794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525f7b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00525f7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525f80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_525f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525f85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525f86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525f87  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00525f89  ff1590775600           -call dword ptr [0x567790]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666704) /* 0x567790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525f8f  8b155082a100           -mov edx, dword ptr [0xa18250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */);
    // 00525f95  b95082a100             -mov ecx, 0xa18250
    cpu.ecx = 10584656 /*0xa18250*/;
    // 00525f9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00525f9c  7428                   -je 0x525fc6
    if (cpu.flags.zf)
    {
        goto L_0x00525fc6;
    }
L_0x00525f9e:
    // 00525f9e  3b5a04                 +cmp ebx, dword ptr [edx + 4]
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
    // 00525fa1  751b                   -jne 0x525fbe
    if (!cpu.flags.zf)
    {
        goto L_0x00525fbe;
    }
    // 00525fa3  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00525fa7  7408                   -je 0x525fb1
    if (cpu.flags.zf)
    {
        goto L_0x00525fb1;
    }
    // 00525fa9  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00525fac  e83f1afdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00525fb1:
    // 00525fb1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00525fb3  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00525fb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00525fb7  e8341afdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 00525fbc  eb08                   -jmp 0x525fc6
    goto L_0x00525fc6;
L_0x00525fbe:
    // 00525fbe  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00525fc0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00525fc2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00525fc4  75d8                   -jne 0x525f9e
    if (!cpu.flags.zf)
    {
        goto L_0x00525f9e;
    }
L_0x00525fc6:
    // 00525fc6  ff1594775600           -call dword ptr [0x567794]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666708) /* 0x567794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525fcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525fcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525fce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_525fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525fd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525fd1  ff1590775600           -call dword ptr [0x567790]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666704) /* 0x567790 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525fd7  a15082a100             -mov eax, dword ptr [0xa18250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */);
    // 00525fdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525fde  740d                   -je 0x525fed
    if (cpu.flags.zf)
    {
        goto L_0x00525fed;
    }
L_0x00525fe0:
    // 00525fe0  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00525fe3  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00525fe7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00525fe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00525feb  75f3                   -jne 0x525fe0
    if (!cpu.flags.zf)
    {
        goto L_0x00525fe0;
    }
L_0x00525fed:
    // 00525fed  ff1594775600           -call dword ptr [0x567794]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666708) /* 0x567794 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00525ff3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00525ff4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_525ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00525ff8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00525ff9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00525ffa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00525ffb  8b155082a100           -mov edx, dword ptr [0xa18250]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10584656) /* 0xa18250 */);
    // 00526001  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00526003  741e                   -je 0x526023
    if (cpu.flags.zf)
    {
        goto L_0x00526023;
    }
L_0x00526005:
    // 00526005  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00526008  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0052600a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052600c  7408                   -je 0x526016
    if (cpu.flags.zf)
    {
        goto L_0x00526016;
    }
    // 0052600e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00526011  e8da19fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x00526016:
    // 00526016  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00526018  e8d319fdff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052601d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052601f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00526021  75e2                   -jne 0x526005
    if (!cpu.flags.zf)
    {
        goto L_0x00526005;
    }
L_0x00526023:
    // 00526023  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526024  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526025  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526026  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_526030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526033  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526035  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00526037  741b                   -je 0x526054
    if (cpu.flags.zf)
    {
        goto L_0x00526054;
    }
    // 00526039  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052603b  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00526042  e8d98bffff             -call 0x51ec20
    cpu.esp -= 4;
    sub_51ec20(app, cpu);
    if (cpu.terminate) return;
    // 00526047  2eff150c455300         -call dword ptr cs:[0x53450c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457164) /* 0x53450c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052604e  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00526054:
    // 00526054  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526055  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526056  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526057  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_526060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526060  e993ffffff             -jmp 0x525ff8
    return sub_525ff8(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_526070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526070  dbe2                   -fnclex 
    /*nothing*/;
    // 00526072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_526080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00526082  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526084  83f807                 +cmp eax, 7
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
    // 00526087  7405                   -je 0x52608e
    if (cpu.flags.zf)
    {
        goto L_0x0052608e;
    }
    // 00526089  83f804                 +cmp eax, 4
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
    // 0052608c  7518                   -jne 0x5260a6
    if (!cpu.flags.zf)
    {
        goto L_0x005260a6;
    }
L_0x0052608e:
    // 0052608e  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00526095  8b98bcb05600           -mov ebx, dword ptr [eax + 0x56b0bc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5681340) /* 0x56b0bc */);
    // 0052609b  8990bcb05600           -mov dword ptr [eax + 0x56b0bc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5681340) /* 0x56b0bc */) = cpu.edx;
    // 005260a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005260a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005260a6:
    // 005260a6  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 005260ad  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005260b3  8b5c0158               -mov ebx, dword ptr [ecx + eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1);
    // 005260b7  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005260bd  89540158               -mov dword ptr [ecx + eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1) = cpu.edx;
    // 005260c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 005260c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5260c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005260c8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005260c9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005260cb  83f807                 +cmp eax, 7
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
    // 005260ce  7405                   -je 0x5260d5
    if (cpu.flags.zf)
    {
        goto L_0x005260d5;
    }
    // 005260d0  83f804                 +cmp eax, 4
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
    // 005260d3  7509                   -jne 0x5260de
    if (!cpu.flags.zf)
    {
        goto L_0x005260de;
    }
L_0x005260d5:
    // 005260d5  8b04d5bcb05600         -mov eax, dword ptr [edx*8 + 0x56b0bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681340) /* 0x56b0bc */ + cpu.edx * 8);
    // 005260dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005260de:
    // 005260de  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005260e4  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 005260e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005260e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5260ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005260ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005260ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005260ef  83f807                 +cmp eax, 7
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
    // 005260f2  7405                   -je 0x5260f9
    if (cpu.flags.zf)
    {
        goto L_0x005260f9;
    }
    // 005260f4  83f804                 +cmp eax, 4
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
    // 005260f7  7509                   -jne 0x526102
    if (!cpu.flags.zf)
    {
        goto L_0x00526102;
    }
L_0x005260f9:
    // 005260f9  8b04d5c0b05600         -mov eax, dword ptr [edx*8 + 0x56b0c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5681344) /* 0x56b0c0 */ + cpu.edx * 8);
    // 00526100  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526101  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526102:
    // 00526102  ff1564775600           -call dword ptr [0x567764]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5666660) /* 0x567764 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00526108  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 0052610c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052610d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_526110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00526111  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00526113  e8d4ffffff             -call 0x5260ec
    cpu.esp -= 4;
    sub_5260ec(app, cpu);
    if (cpu.terminate) return;
    // 00526118  39c2                   +cmp edx, eax
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
    // 0052611a  7509                   -jne 0x526125
    if (!cpu.flags.zf)
    {
        goto L_0x00526125;
    }
    // 0052611c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052611e  e8a5ffffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 00526123  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526124  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00526125:
    // 00526125  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00526127  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526128  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52612c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052612c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00526130  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00526132  760a                   -jbe 0x52613e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052613e;
    }
    // 00526134  83f801                 +cmp eax, 1
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
    // 00526137  7424                   -je 0x52615d
    if (cpu.flags.zf)
    {
        goto L_0x0052615d;
    }
    // 00526139  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052613b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052613e:
    // 0052613e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00526143  e880ffffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 00526148  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052614a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052614c  7503                   -jne 0x526151
    if (!cpu.flags.zf)
    {
        goto L_0x00526151;
    }
    // 0052614e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00526151:
    // 00526151  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00526156  e8dd010000             -call 0x526338
    cpu.esp -= 4;
    sub_526338(app, cpu);
    if (cpu.terminate) return;
    // 0052615b  eb1d                   -jmp 0x52617a
    goto L_0x0052617a;
L_0x0052615d:
    // 0052615d  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00526162  e861ffffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 00526167  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00526169  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052616b  7503                   -jne 0x526170
    if (!cpu.flags.zf)
    {
        goto L_0x00526170;
    }
    // 0052616d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00526170:
    // 00526170  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00526175  e8be010000             -call 0x526338
    cpu.esp -= 4;
    sub_526338(app, cpu);
    if (cpu.terminate) return;
L_0x0052617a:
    // 0052617a  83fa02                 +cmp edx, 2
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
    // 0052617d  7405                   -je 0x526184
    if (cpu.flags.zf)
    {
        goto L_0x00526184;
    }
    // 0052617f  83fa03                 +cmp edx, 3
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
    // 00526182  7505                   -jne 0x526189
    if (!cpu.flags.zf)
    {
        goto L_0x00526189;
    }
L_0x00526184:
    // 00526184  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00526186  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00526189:
    // 00526189  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052618e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_526194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526194  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00526195  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0052619a  e829ffffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 0052619f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005261a1  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 005261a6  e81dffffff             -call 0x5260c8
    cpu.esp -= 4;
    sub_5260c8(app, cpu);
    if (cpu.terminate) return;
    // 005261ab  83fa02                 +cmp edx, 2
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
    // 005261ae  7405                   -je 0x5261b5
    if (cpu.flags.zf)
    {
        goto L_0x005261b5;
    }
    // 005261b0  83fa03                 +cmp edx, 3
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
    // 005261b3  750a                   -jne 0x5261bf
    if (!cpu.flags.zf)
    {
        goto L_0x005261bf;
    }
L_0x005261b5:
    // 005261b5  83f802                 +cmp eax, 2
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
    // 005261b8  740c                   -je 0x5261c6
    if (cpu.flags.zf)
    {
        goto L_0x005261c6;
    }
    // 005261ba  83f803                 +cmp eax, 3
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
    // 005261bd  7407                   -je 0x5261c6
    if (cpu.flags.zf)
    {
        goto L_0x005261c6;
    }
L_0x005261bf:
    // 005261bf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005261c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005261c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005261c6:
    // 005261c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005261c8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005261c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5261cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005261cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005261cd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005261ce  803d24b1560000         +cmp byte ptr [0x56b124], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005261d5  7519                   -jne 0x5261f0
    if (!cpu.flags.zf)
    {
        goto L_0x005261f0;
    }
    // 005261d7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 005261d9  682c615200             -push 0x52612c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5398828 /*0x52612c*/;
    cpu.esp -= 4;
    // 005261de  2eff15cc455300         -call dword ptr cs:[0x5345cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457356) /* 0x5345cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005261e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005261e7  7407                   -je 0x5261f0
    if (cpu.flags.zf)
    {
        goto L_0x005261f0;
    }
    // 005261e9  c60524b1560001         -mov byte ptr [0x56b124], 1
    app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */) = 1 /*0x1*/;
L_0x005261f0:
    // 005261f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005261f2  a024b15600             -mov al, byte ptr [0x56b124]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */);
    // 005261f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005261f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005261f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_5261fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005261fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005261fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005261fe  803d24b1560000         +cmp byte ptr [0x56b124], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00526205  741a                   -je 0x526221
    if (cpu.flags.zf)
    {
        goto L_0x00526221;
    }
    // 00526207  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00526209  682c615200             -push 0x52612c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5398828 /*0x52612c*/;
    cpu.esp -= 4;
    // 0052620e  2eff15cc455300         -call dword ptr cs:[0x5345cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457356) /* 0x5345cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00526215  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00526217  7408                   -je 0x526221
    if (cpu.flags.zf)
    {
        goto L_0x00526221;
    }
    // 00526219  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052621b  881524b15600           -mov byte ptr [0x56b124], dl
    app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */) = cpu.dl;
L_0x00526221:
    // 00526221  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00526223  a024b15600             -mov al, byte ptr [0x56b124]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5681444) /* 0x56b124 */);
    // 00526228  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052622a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0052622d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00526232  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526233  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00526234  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_526238(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00526238  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052623d  e9f6000000             -jmp 0x526338
    return sub_526338(app, cpu);
}

}
