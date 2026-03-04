#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4601f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004601f0  3b05ccfe4f00           +cmp eax, dword ptr [0x4ffecc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004601f6  7506                   -jne 0x4601fe
    if (!cpu.flags.zf)
    {
        goto L_0x004601fe;
    }
    // 004601f8  a1c8fe4f00             -mov eax, dword ptr [0x4ffec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 004601fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004601fe:
    // 004601fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004601ff  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460200  bb67000000             -mov ebx, 0x67
    cpu.ebx = 103 /*0x67*/;
    // 00460205  bab0b44b00             -mov edx, 0x4bb4b0
    cpu.edx = 4961456 /*0x4bb4b0*/;
    // 0046020a  b8d0b44b00             -mov eax, 0x4bb4d0
    cpu.eax = 4961488 /*0x4bb4d0*/;
    // 0046020f  e8b8a40200             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 00460214  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460215  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460216  a1c8fe4f00             -mov eax, dword ptr [0x4ffec8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 0046021b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_460220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460221  8b15ccfe4f00           -mov edx, dword ptr [0x4ffecc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 00460227  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460229  7502                   -jne 0x46022d
    if (!cpu.flags.zf)
    {
        goto L_0x0046022d;
    }
    // 0046022b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046022c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046022d:
    // 0046022d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046022f  e8fcd40000             -call 0x46d730
    cpu.esp -= 4;
    sub_46d730(app, cpu);
    if (cpu.terminate) return;
    // 00460234  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460235  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460240  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00460245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460253  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460255  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460258  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046025a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046025c:
    // 0046025c  8b9a1cff4f00           -mov ebx, dword ptr [edx + 0x4fff1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5242652) /* 0x4fff1c */);
    // 00460262  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460263  8bb218ff4f00           -mov esi, dword ptr [edx + 0x4fff18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5242648) /* 0x4fff18 */);
    // 00460269  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046026a  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046026d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046026e  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00460270  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460271  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00460275  e8c6aaffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046027a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046027c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046027e  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460281  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460282  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460283  81fa00010000           +cmp edx, 0x100
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
    // 00460289  75d1                   -jne 0x46025c
    if (!cpu.flags.zf)
    {
        goto L_0x0046025c;
    }
    // 0046028b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046028e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046028f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460290  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460291  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460292  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460293  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4602a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004602a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004602a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004602a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004602a3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004602a6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004602a8:
    // 004602a8  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004602aa  e841abffff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 004602af  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004602b1  8dba18ff4f00           -lea edi, [edx + 0x4fff18]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(5242648) /* 0x4fff18 */);
    // 004602b7  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004602ba  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004602bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004602bc  81fa00010000           +cmp edx, 0x100
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
    // 004602c2  75e4                   -jne 0x4602a8
    if (!cpu.flags.zf)
    {
        goto L_0x004602a8;
    }
    // 004602c4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004602c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004602ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4602d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004602d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004602d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004602d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004602d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004602d4  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004602d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004602d9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004602db  895c2464               -mov dword ptr [esp + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 004602df  83b8bc00000000         +cmp dword ptr [eax + 0xbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004602e6  0f85b4000000           -jne 0x4603a0
    if (!cpu.flags.zf)
    {
        goto L_0x004603a0;
    }
L_0x004602ec:
    // 004602ec  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004602ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004602f1  747b                   -je 0x46036e
    if (cpu.flags.zf)
    {
        goto L_0x0046036e;
    }
    // 004602f3  8d5e50                 -lea ebx, [esi + 0x50]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004602f6  8d5150                 -lea edx, [ecx + 0x50]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 004602f9  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004602fc  e83f9c0200             -call 0x489f40
    cpu.esp -= 4;
    sub_489f40(app, cpu);
    if (cpu.terminate) return;
    // 00460301  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00460304  8b9e80000000           -mov ebx, dword ptr [esi + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 0046030a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046030c  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00460310  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00460313  8bae84000000           -mov ebp, dword ptr [esi + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00460319  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046031b  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 0046031f  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00460322  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00460328  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046032a  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0046032e  8d5c243c               -lea ebx, [esp + 0x3c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00460332  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460335  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00460339  83c250                 -add edx, 0x50
    (cpu.edx) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046033c  e83fdc0000             -call 0x46df80
    cpu.esp -= 4;
    sub_46df80(app, cpu);
    if (cpu.terminate) return;
    // 00460341  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460344  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00460348  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0046034b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046034d  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00460350  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460353  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00460357  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 0046035a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046035c  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0046035f  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460362  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00460366  8b407c                 -mov eax, dword ptr [eax + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 00460369  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046036b  89567c                 -mov dword ptr [esi + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.edx;
L_0x0046036e:
    // 0046036e  833e01                 +cmp dword ptr [esi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460371  7544                   -jne 0x4603b7
    if (!cpu.flags.zf)
    {
        goto L_0x004603b7;
    }
    // 00460373  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00460376  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00460378  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046037a  7e1c                   -jle 0x460398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460398;
    }
    // 0046037c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x0046037e:
    // 0046037e  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00460382  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00460384  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00460387  e844ffffff             -call 0x4602d0
    cpu.esp -= 4;
    sub_4602d0(app, cpu);
    if (cpu.terminate) return;
    // 0046038c  41                     -inc ecx
    (cpu.ecx)++;
    // 0046038d  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00460390  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460393  39d9                   +cmp ecx, ebx
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
    // 00460395  7ce7                   -jl 0x46037e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046037e;
    }
    // 00460397  90                     -nop 
    ;
L_0x00460398:
    // 00460398  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046039b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046039c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046039d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046039e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046039f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004603a0:
    // 004603a0  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 004603a6  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 004603ac  ff96bc000000           -call dword ptr [esi + 0xbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004603b2  e935ffffff             -jmp 0x4602ec
    goto L_0x004602ec;
L_0x004603b7:
    // 004603b7  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 004603bd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004603bf  74d7                   -je 0x460398
    if (cpu.flags.zf)
    {
        goto L_0x00460398;
    }
    // 004603c1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004603c3  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 004603c7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004603c9  7ecd                   -jle 0x460398
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460398;
    }
    // 004603cb  8d4650                 -lea eax, [esi + 0x50]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 004603ce  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 004603d2  8d4744                 -lea eax, [edi + 0x44]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 004603d5  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004603d7  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x004603db:
    // 004603db  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 004603e1  833800                 +cmp dword ptr [eax], 0
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
    // 004603e4  742f                   -je 0x460415
    if (cpu.flags.zf)
    {
        goto L_0x00460415;
    }
    // 004603e6  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004603e9  81f900000200           +cmp ecx, 0x20000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004603ef  0f855f010000           -jne 0x460554
    if (!cpu.flags.zf)
    {
        goto L_0x00460554;
    }
    // 004603f5  8b1d14ff4f00           -mov ebx, dword ptr [0x4fff14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5242644) /* 0x4fff14 */);
    // 004603fb  81fb008bffff           +cmp ebx, 0xffff8b00
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294937344 /*0xffff8b00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460401  7d2e                   -jge 0x460431
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460431;
    }
L_0x00460403:
    // 00460403  8b1510ff4f00           -mov edx, dword ptr [0x4fff10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242640) /* 0x4fff10 */);
    // 00460409  81fa006e0000           +cmp edx, 0x6e00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28160 /*0x6e00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046040f  0f8e2e010000           -jle 0x460543
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460543;
    }
L_0x00460415:
    // 00460415  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00460419  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046041c  41                     -inc ecx
    (cpu.ecx)++;
    // 0046041d  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00460423  894c246c               -mov dword ptr [esp + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 00460427  39d9                   +cmp ecx, ebx
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
    // 00460429  0f8d69ffffff           -jge 0x460398
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460398;
    }
    // 0046042f  ebaa                   -jmp 0x4603db
    goto L_0x004603db;
L_0x00460431:
    // 00460431  81fb00200000           +cmp ebx, 0x2000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460437  7fca                   -jg 0x460403
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460403;
    }
L_0x00460439:
    // 00460439  813d14ff4f0000200000   +cmp dword ptr [0x4fff14], 0x2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5242644) /* 0x4fff14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460443  7fd0                   -jg 0x460415
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460415;
    }
L_0x00460445:
    // 00460445  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 00460448  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046044b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046044d  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00460451  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00460454  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00460457  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00460459  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046045d  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00460460  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00460463  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00460467  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460469  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0046046d  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00460471  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00460475  e806db0000             -call 0x46df80
    cpu.esp -= 4;
    sub_46df80(app, cpu);
    if (cpu.terminate) return;
    // 0046047a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046047c  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00460480  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00460484  e8b79a0200             -call 0x489f40
    cpu.esp -= 4;
    sub_489f40(app, cpu);
    if (cpu.terminate) return;
    // 00460489  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 0046048f  8b1528674c00           -mov edx, dword ptr [0x4c6728]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5007144) /* 0x4c6728 */);
    // 00460495  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00460498  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046049a  7447                   -je 0x4604e3
    if (cpu.flags.zf)
    {
        goto L_0x004604e3;
    }
    // 0046049c  83f806                 +cmp eax, 6
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
    // 0046049f  0f85e3000000           -jne 0x460588
    if (!cpu.flags.zf)
    {
        goto L_0x00460588;
    }
L_0x004604a5:
    // 004604a5  8b0d10ff4f00           -mov ecx, dword ptr [0x4fff10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5242640) /* 0x4fff10 */);
    // 004604ab  81f900a0ffff           +cmp ecx, 0xffffa000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294942720 /*0xffffa000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004604b1  0f8e22010000           -jle 0x4605d9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004605d9;
    }
    // 004604b7  81f900600000           +cmp ecx, 0x6000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24576 /*0x6000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004604bd  0f8d16010000           -jge 0x4605d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004605d9;
    }
    // 004604c3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004604c5  0f8edd000000           -jle 0x4605a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004605a8;
    }
    // 004604cb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004604cd:
    // 004604cd  81fa002e0000           +cmp edx, 0x2e00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11776 /*0x2e00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004604d3  7e0e                   -jle 0x4604e3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004604e3;
    }
    // 004604d5  83f806                 +cmp eax, 6
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
    // 004604d8  0f85d3000000           -jne 0x4605b1
    if (!cpu.flags.zf)
    {
        goto L_0x004605b1;
    }
L_0x004604de:
    // 004604de  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x004604e3:
    // 004604e3  833d24674c0000         +cmp dword ptr [0x4c6724], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5007140) /* 0x4c6724 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004604ea  740c                   -je 0x4604f8
    if (cpu.flags.zf)
    {
        goto L_0x004604f8;
    }
    // 004604ec  83f805                 +cmp eax, 5
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
    // 004604ef  7d07                   -jge 0x4604f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004604f8;
    }
    // 004604f1  8b0485a8e84d00         -mov eax, dword ptr [eax*4 + 0x4de8a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105832) /* 0x4de8a8 */ + cpu.eax * 4);
L_0x004604f8:
    // 004604f8  8b5674                 -mov edx, dword ptr [esi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004604fb  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004604fe  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460500  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00460504  8b5678                 -mov edx, dword ptr [esi + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00460507  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0046050a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046050c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00460510  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00460513  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00460516  29da                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00460518  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0046051c  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00460520  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460521  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00460525  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460526  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046052a  8b5c2470               -mov ebx, dword ptr [esp + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 0046052e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046052f  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460533  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00460539  e872d40000             -call 0x46d9b0
    cpu.esp -= 4;
    sub_46d9b0(app, cpu);
    if (cpu.terminate) return;
    // 0046053e  e9d2feffff             -jmp 0x460415
    goto L_0x00460415;
L_0x00460543:
    // 00460543  81fa0092ffff           +cmp edx, 0xffff9200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294939136 /*0xffff9200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460549  0f8cc6feffff           -jl 0x460415
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460415;
    }
    // 0046054f  e9e5feffff             -jmp 0x460439
    goto L_0x00460439;
L_0x00460554:
    // 00460554  8b1510ff4f00           -mov edx, dword ptr [0x4fff10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242640) /* 0x4fff10 */);
    // 0046055a  39ca                   +cmp edx, ecx
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
    // 0046055c  0f8ee3feffff           -jle 0x460445
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460445;
    }
    // 00460562  3b5028                 +cmp edx, dword ptr [eax + 0x28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460565  0f8ddafeffff           -jge 0x460445
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460445;
    }
    // 0046056b  8b1514ff4f00           -mov edx, dword ptr [0x4fff14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242644) /* 0x4fff14 */);
    // 00460571  3b502c                 +cmp edx, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460574  0f8ecbfeffff           -jle 0x460445
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460445;
    }
    // 0046057a  3b5030                 +cmp edx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046057d  0f8c92feffff           -jl 0x460415
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460415;
    }
    // 00460583  e9bdfeffff             -jmp 0x460445
    goto L_0x00460445;
L_0x00460588:
    // 00460588  83f807                 +cmp eax, 7
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
    // 0046058b  0f8414ffffff           -je 0x4604a5
    if (cpu.flags.zf)
    {
        goto L_0x004604a5;
    }
    // 00460591  83f808                 +cmp eax, 8
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
    // 00460594  0f840bffffff           -je 0x4604a5
    if (cpu.flags.zf)
    {
        goto L_0x004604a5;
    }
    // 0046059a  83f809                 +cmp eax, 9
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
    // 0046059d  0f8402ffffff           -je 0x4604a5
    if (cpu.flags.zf)
    {
        goto L_0x004604a5;
    }
    // 004605a3  e93bffffff             -jmp 0x4604e3
    goto L_0x004604e3;
L_0x004605a8:
    // 004605a8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004605aa  f7da                   +neg edx
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
    // 004605ac  e91cffffff             -jmp 0x4604cd
    goto L_0x004604cd;
L_0x004605b1:
    // 004605b1  83f807                 +cmp eax, 7
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
    // 004605b4  750a                   -jne 0x4605c0
    if (!cpu.flags.zf)
    {
        goto L_0x004605c0;
    }
    // 004605b6  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004605bb  e923ffffff             -jmp 0x4604e3
    goto L_0x004604e3;
L_0x004605c0:
    // 004605c0  83f808                 +cmp eax, 8
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
    // 004605c3  750a                   -jne 0x4605cf
    if (!cpu.flags.zf)
    {
        goto L_0x004605cf;
    }
L_0x004605c5:
    // 004605c5  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004605ca  e914ffffff             -jmp 0x4604e3
    goto L_0x004604e3;
L_0x004605cf:
    // 004605cf  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004605d4  e90affffff             -jmp 0x4604e3
    goto L_0x004604e3;
L_0x004605d9:
    // 004605d9  83f806                 +cmp eax, 6
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
    // 004605dc  750a                   -jne 0x4605e8
    if (!cpu.flags.zf)
    {
        goto L_0x004605e8;
    }
    // 004605de  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004605e3  e9fbfeffff             -jmp 0x4604e3
    goto L_0x004604e3;
L_0x004605e8:
    // 004605e8  83f807                 +cmp eax, 7
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
    // 004605eb  0f84edfeffff           -je 0x4604de
    if (cpu.flags.zf)
    {
        goto L_0x004604de;
    }
    // 004605f1  83f808                 +cmp eax, 8
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
    // 004605f4  75cf                   -jne 0x4605c5
    if (!cpu.flags.zf)
    {
        goto L_0x004605c5;
    }
    // 004605f6  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004605fb  e9e3feffff             -jmp 0x4604e3
    goto L_0x004604e3;
}

/* align: skip  */
void Application::sub_460600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460600  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460601  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460602  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460605  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460607  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00460609  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 0046060e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00460610  e82ba8ffff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 00460615  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460617  7508                   -jne 0x460621
    if (!cpu.flags.zf)
    {
        goto L_0x00460621;
    }
L_0x00460619:
    // 00460619  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046061b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046061e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046061f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460620  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460621:
    // 00460621  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00460624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460625  8d5138                 -lea edx, [ecx + 0x38]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 00460628  8d4144                 -lea eax, [ecx + 0x44]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 0046062b  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046062d  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00460632  e829d80000             -call 0x46de60
    cpu.esp -= 4;
    sub_46de60(app, cpu);
    if (cpu.terminate) return;
    // 00460637  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046063c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460640  e8fba7ffff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 00460645  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460647  74d0                   -je 0x460619
    if (cpu.flags.zf)
    {
        goto L_0x00460619;
    }
    // 00460649  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046064d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00460653  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460657  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 0046065e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460662  8b1540995100           -mov edx, dword ptr [0x519940]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5347648) /* 0x519940 */);
    // 00460668  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046066b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046066f  66c74020ffff           -mov word ptr [eax + 0x20], 0xffff
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = 65535 /*0xffff*/;
    // 00460675  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460679  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 0046067f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460683  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 00460689  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046068d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00460690  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00460693  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460697  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046069a  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046069d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004606a0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004606a4  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004606a7  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004606aa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004606ad  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004606b1  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004606b4  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004606b7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004606bb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004606be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4606d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004606d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004606d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004606d3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004606d8  e893000000             -call 0x460770
    cpu.esp -= 4;
    sub_460770(app, cpu);
    if (cpu.terminate) return;
    // 004606dd  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004606e0  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 004606e6  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 004606ec  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 004606f2  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004606f5  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 004606f9  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 004606fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_460700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460700  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460701  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460703  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00460708  e863000000             -call 0x460770
    cpu.esp -= 4;
    sub_460770(app, cpu);
    if (cpu.terminate) return;
    // 0046070d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00460710  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00460716  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0046071c  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00460722  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00460725  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 00460729  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 0046072c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046072d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_460730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460731  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460732  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460734  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00460736  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00460738  8b808c000000           -mov eax, dword ptr [eax + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0046073e  89b48190000000         -mov dword ptr [ecx + eax*4 + 0x90], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */ + cpu.eax * 4) = cpu.esi;
    // 00460745  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00460747  e8b495ffff             -call 0x459d00
    cpu.esp -= 4;
    sub_459d00(app, cpu);
    if (cpu.terminate) return;
    // 0046074c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046074f  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00460752  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00460755  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00460758  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046075b  89514c                 -mov dword ptr [ecx + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0046075e  ff818c000000           -inc dword ptr [ecx + 0x8c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */))++;
    // 00460764  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460765  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460766  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460770  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460771  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460773  b864b54b00             -mov eax, 0x4bb564
    cpu.eax = 4961636 /*0x4bb564*/;
    // 00460778  e813000000             -call 0x460790
    cpu.esp -= 4;
    sub_460790(app, cpu);
    if (cpu.terminate) return;
    // 0046077d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00460784  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00460786  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460791  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460792  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 00460797  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460799  e8f2000000             -call 0x460890
    cpu.esp -= 4;
    sub_460890(app, cpu);
    if (cpu.terminate) return;
    // 0046079e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004607a0  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004607a3  c740e400000000         -mov dword ptr [eax - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004607aa  c740e800000000         -mov dword ptr [eax - 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-24) /* -0x18 */) = 0 /*0x0*/;
    // 004607b1  c7406c00000000         -mov dword ptr [eax + 0x6c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 004607b8  c7809c00000000000000   -mov dword ptr [eax + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 004607c2  c780a000000000000000   -mov dword ptr [eax + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 004607cc  c780a400000000000000   -mov dword ptr [eax + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 004607d6  e845a1feff             -call 0x44a920
    cpu.esp -= 4;
    sub_44a920(app, cpu);
    if (cpu.terminate) return;
    // 004607db  8d4250                 -lea eax, [edx + 0x50]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 004607de  e83da1feff             -call 0x44a920
    cpu.esp -= 4;
    sub_44a920(app, cpu);
    if (cpu.terminate) return;
    // 004607e3  c7424400000000         -mov dword ptr [edx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 004607ea  c7424800000000         -mov dword ptr [edx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 004607f1  c7424c00000000         -mov dword ptr [edx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004607f8  c7828000000000000000   -mov dword ptr [edx + 0x80], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 00460802  c7828400000000000000   -mov dword ptr [edx + 0x84], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 0046080c  c7828800000000000000   -mov dword ptr [edx + 0x88], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 00460816  c7427400000000         -mov dword ptr [edx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 0046081d  c7427800000000         -mov dword ptr [edx + 0x78], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00460824  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460826  c7427c00000000         -mov dword ptr [edx + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 0046082d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046082e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046082f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_460830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460835  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460836  8b15206b4c00           -mov edx, dword ptr [0x4c6b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */);
    // 0046083c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046083e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460840  7e22                   -jle 0x460864
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460864;
    }
    // 00460842  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00460844:
    // 00460844  8bbad0fe4f00           -mov edi, dword ptr [edx + 0x4ffed0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5242576) /* 0x4ffed0 */);
    // 0046084a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046084c  752b                   -jne 0x460879
    if (!cpu.flags.zf)
    {
        goto L_0x00460879;
    }
L_0x0046084e:
    // 0046084e  8b35206b4c00           -mov esi, dword ptr [0x4c6b20]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */);
    // 00460854  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460857  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460859  41                     -inc ecx
    (cpu.ecx)++;
    // 0046085a  899accfe4f00           -mov dword ptr [edx + 0x4ffecc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5242572) /* 0x4ffecc */) = cpu.ebx;
    // 00460860  39f1                   +cmp ecx, esi
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
    // 00460862  7ce0                   -jl 0x460844
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460844;
    }
L_0x00460864:
    // 00460864  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00460866  892d206b4c00           -mov dword ptr [0x4c6b20], ebp
    app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */) = cpu.ebp;
    // 0046086c  892d246b4c00           -mov dword ptr [0x4c6b24], ebp
    app->getMemory<x86::reg32>(x86::reg32(5008164) /* 0x4c6b24 */) = cpu.ebp;
    // 00460872  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460873  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460874  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460875  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460876  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460877  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460878  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460879:
    // 00460879  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046087b  e84c820100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00460880  ebcc                   -jmp 0x46084e
    goto L_0x0046084e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460890  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460891  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460892  8b0d246b4c00           -mov ecx, dword ptr [0x4c6b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5008164) /* 0x4c6b24 */);
    // 00460898  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046089a  7442                   -je 0x4608de
    if (cpu.flags.zf)
    {
        goto L_0x004608de;
    }
    // 0046089c  a1206b4c00             -mov eax, dword ptr [0x4c6b20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */);
    // 004608a1  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004608a8  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004608af  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004608b1  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004608b4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004608b6  8b93ccfe4f00           -mov edx, dword ptr [ebx + 0x4ffecc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5242572) /* 0x4ffecc */);
    // 004608bc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004608bf  41                     -inc ecx
    (cpu.ecx)++;
    // 004608c0  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004608c3  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 004608c8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004608ca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004608cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004608cf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004608d1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004608d3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004608d5  890d246b4c00           -mov dword ptr [0x4c6b24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008164) /* 0x4c6b24 */) = cpu.ecx;
    // 004608db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004608de:
    // 004608de  ba38b54b00             -mov edx, 0x4bb538
    cpu.edx = 4961592 /*0x4bb538*/;
    // 004608e3  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 004608e8  b85cb54b00             -mov eax, 0x4bb55c
    cpu.eax = 4961628 /*0x4bb55c*/;
    // 004608ed  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 004608f3  891d90844c00           -mov dword ptr [0x4c8490], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 004608f9  bad0070000             -mov edx, 0x7d0
    cpu.edx = 2000 /*0x7d0*/;
    // 004608fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460900  e8637d0100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00460905  8b15206b4c00           -mov edx, dword ptr [0x4c6b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */);
    // 0046090b  8b0d246b4c00           -mov ecx, dword ptr [0x4c6b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5008164) /* 0x4c6b24 */);
    // 00460911  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00460914  41                     -inc ecx
    (cpu.ecx)++;
    // 00460915  890495d0fe4f00         -mov dword ptr [edx*4 + 0x4ffed0], eax
    app->getMemory<x86::reg32>(x86::reg32(5242576) /* 0x4ffed0 */ + cpu.edx * 4) = cpu.eax;
    // 0046091c  8935206b4c00           -mov dword ptr [0x4c6b20], esi
    app->getMemory<x86::reg32>(x86::reg32(5008160) /* 0x4c6b20 */) = cpu.esi;
    // 00460922  8b04b5ccfe4f00         -mov eax, dword ptr [esi*4 + 0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */ + cpu.esi * 4);
    // 00460929  890d246b4c00           -mov dword ptr [0x4c6b24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008164) /* 0x4c6b24 */) = cpu.ecx;
    // 0046092f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460930  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460931  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460940  a3286b4c00             -mov dword ptr [0x4c6b28], eax
    app->getMemory<x86::reg32>(x86::reg32(5008168) /* 0x4c6b28 */) = cpu.eax;
    // 00460945  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460950  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460960  e90b000000             -jmp 0x460970
    return sub_460970(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460975  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0046097a  8b1584d54f00           -mov edx, dword ptr [0x4fd584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460980  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460982  891518065000           -mov dword ptr [0x500618], edx
    app->getMemory<x86::reg32>(x86::reg32(5244440) /* 0x500618 */) = cpu.edx;
    // 00460988  89151c065000           -mov dword ptr [0x50061c], edx
    app->getMemory<x86::reg32>(x86::reg32(5244444) /* 0x50061c */) = cpu.edx;
    // 0046098e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00460990:
    // 00460990  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460992  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460994  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
L_0x00460997:
    // 00460997  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046099a  899014035000           -mov dword ptr [eax + 0x500314], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5243668) /* 0x500314 */) = cpu.edx;
    // 004609a0  89b814045000           -mov dword ptr [eax + 0x500414], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5243924) /* 0x500414 */) = cpu.edi;
    // 004609a6  899014055000           -mov dword ptr [eax + 0x500514], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5244180) /* 0x500514 */) = cpu.edx;
    // 004609ac  39c8                   +cmp eax, ecx
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
    // 004609ae  75e7                   -jne 0x460997
    if (!cpu.flags.zf)
    {
        goto L_0x00460997;
    }
    // 004609b0  43                     -inc ebx
    (cpu.ebx)++;
    // 004609b1  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004609b4  83fb10                 +cmp ebx, 0x10
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
    // 004609b7  7cd7                   -jl 0x460990
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460990;
    }
    // 004609b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4609c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004609c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004609c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004609c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004609c3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004609c6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004609c8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004609ca  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004609cc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004609ce  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004609d1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004609d3  751d                   -jne 0x4609f2
    if (!cpu.flags.zf)
    {
        goto L_0x004609f2;
    }
    // 004609d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004609d7  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 004609de  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004609e1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004609e3  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 004609e8  2b8118035000           -sub eax, dword ptr [ecx + 0x500318]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5243672) /* 0x500318 */)));
    // 004609ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004609f0  7e50                   -jle 0x460a42
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460a42;
    }
L_0x004609f2:
    // 004609f2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004609f4  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004609fb  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004609fe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460a00  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460a05  898118035000           -mov dword ptr [ecx + 0x500318], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5243672) /* 0x500318 */) = cpu.eax;
    // 00460a0b  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00460a12  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00460a14  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00460a18  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00460a1f  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00460a26  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00460a28  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00460a2b  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00460a2e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00460a31  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460a35  83bb1804500000         +cmp dword ptr [ebx + 0x500418], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5243928) /* 0x500418 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460a3c  7524                   -jne 0x460a62
    if (!cpu.flags.zf)
    {
        goto L_0x00460a62;
    }
    // 00460a3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460a40  7407                   -je 0x460a49
    if (cpu.flags.zf)
    {
        goto L_0x00460a49;
    }
L_0x00460a42:
    // 00460a42  83c40c                 +add esp, 0xc
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
    // 00460a45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a46  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460a49:
    // 00460a49  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00460a4c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00460a51  8dbf18005000           -lea edi, [edi + 0x500018]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5242904) /* 0x500018 */);
    // 00460a57  899318045000           -mov dword ptr [ebx + 0x500418], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5243928) /* 0x500418 */) = cpu.edx;
    // 00460a5d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460a5e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460a5f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460a60  ebe0                   -jmp 0x460a42
    goto L_0x00460a42;
L_0x00460a62:
    // 00460a62  0518005000             -add eax, 0x500018
    (cpu.eax) += x86::reg32(x86::sreg32(5242904 /*0x500018*/));
    // 00460a67  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00460a69  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00460a6d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460a6f  7435                   -je 0x460aa6
    if (cpu.flags.zf)
    {
        goto L_0x00460aa6;
    }
    // 00460a71  bb33330000             -mov ebx, 0x3333
    cpu.ebx = 13107 /*0x3333*/;
    // 00460a76  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00460a78  e863b7ffff             -call 0x45c1e0
    cpu.esp -= 4;
    sub_45c1e0(app, cpu);
    if (cpu.terminate) return;
    // 00460a7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460a7f  7512                   -jne 0x460a93
    if (!cpu.flags.zf)
    {
        goto L_0x00460a93;
    }
    // 00460a81  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460a82  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460a86  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460a88  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00460a8a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00460a8c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460a8e  e85d000000             -call 0x460af0
    cpu.esp -= 4;
    sub_460af0(app, cpu);
    if (cpu.terminate) return;
L_0x00460a93:
    // 00460a93  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00460a96  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460a98  8984af18045000         -mov dword ptr [edi + ebp*4 + 0x500418], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5243928) /* 0x500418 */ + cpu.ebp * 4) = cpu.eax;
    // 00460a9f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460aa2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460aa3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460aa4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460aa5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460aa6:
    // 00460aa6  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 00460aab  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00460aad  e82eb7ffff             -call 0x45c1e0
    cpu.esp -= 4;
    sub_45c1e0(app, cpu);
    if (cpu.terminate) return;
    // 00460ab2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460ab4  758c                   -jne 0x460a42
    if (!cpu.flags.zf)
    {
        goto L_0x00460a42;
    }
    // 00460ab6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460ab7  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460abb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460abd  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00460abf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00460ac1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460ac3  e828000000             -call 0x460af0
    cpu.esp -= 4;
    sub_460af0(app, cpu);
    if (cpu.terminate) return;
    // 00460ac8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460acc  c7801804500001000000   -mov dword ptr [eax + 0x500418], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5243928) /* 0x500418 */) = 1 /*0x1*/;
    // 00460ad6  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00460ad9  8dbf18005000           -lea edi, [edi + 0x500018]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5242904) /* 0x500018 */);
    // 00460adf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460ae0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460ae1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460ae2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460ae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ae6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ae7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ae8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460af0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460af1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460af2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460af3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00460af6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00460af8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00460afc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00460afe  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00460b00  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00460b04  bb00000e00             -mov ebx, 0xe0000
    cpu.ebx = 917504 /*0xe0000*/;
    // 00460b09  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00460b0b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00460b0d  e8ceb6ffff             -call 0x45c1e0
    cpu.esp -= 4;
    sub_45c1e0(app, cpu);
    if (cpu.terminate) return;
    // 00460b12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460b14  0f857e000000           -jne 0x460b98
    if (!cpu.flags.zf)
    {
        goto L_0x00460b98;
    }
    // 00460b1a  83f903                 +cmp ecx, 3
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
    // 00460b1d  7d5c                   -jge 0x460b7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460b7b;
    }
    // 00460b1f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00460b21  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460b23  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00460b25  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00460b28  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460b2b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00460b2f  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460b31  41                     -inc ecx
    (cpu.ecx)++;
    // 00460b32  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00460b34  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00460b36  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00460b3a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460b3b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00460b3e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00460b42  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460b44  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00460b46  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00460b48  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460b4c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00460b50  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460b52  e899ffffff             -call 0x460af0
    cpu.esp -= 4;
    sub_460af0(app, cpu);
    if (cpu.terminate) return;
    // 00460b57  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460b5b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00460b5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460b60  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460b64  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460b66  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460b67  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00460b6b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460b6d  e87effffff             -call 0x460af0
    cpu.esp -= 4;
    sub_460af0(app, cpu);
    if (cpu.terminate) return;
    // 00460b72  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00460b75  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b76  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b78  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00460b7b:
    // 00460b7b  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00460b7f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00460b83  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00460b85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460b86  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460b88  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460b8a  e891c80000             -call 0x46d420
    cpu.esp -= 4;
    sub_46d420(app, cpu);
    if (cpu.terminate) return;
    // 00460b8f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00460b92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460b95  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00460b98:
    // 00460b98  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00460b9c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460b9e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00460ba0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460ba1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460ba3  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00460ba7  e874c80000             -call 0x46d420
    cpu.esp -= 4;
    sub_46d420(app, cpu);
    if (cpu.terminate) return;
    // 00460bac  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00460baf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460bb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460bb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460bb2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460bc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460bc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460bc2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460bc4  8b1518065000           -mov edx, dword ptr [0x500618]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5244440) /* 0x500618 */);
    // 00460bca  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460bcf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460bd1  83f808                 +cmp eax, 8
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
    // 00460bd4  7f03                   -jg 0x460bd9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460bd9;
    }
    // 00460bd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460bd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460bd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460bd9:
    // 00460bd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460bda  a184d54f00             -mov eax, dword ptr [0x4fd584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460bdf  a318065000             -mov dword ptr [0x500618], eax
    app->getMemory<x86::reg32>(x86::reg32(5244440) /* 0x500618 */) = cpu.eax;
    // 00460be4  e887c00100             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00460be9  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 00460beb  7415                   -je 0x460c02
    if (cpu.flags.zf)
    {
        goto L_0x00460c02;
    }
    // 00460bed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00460bf2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460bf4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460bf6  e8c9e9ffff             -call 0x45f5c4
    cpu.esp -= 4;
    sub_45f5c4(app, cpu);
    if (cpu.terminate) return;
    // 00460bfb  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
L_0x00460c02:
    // 00460c02  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00460c07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460c09  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460c0b  e8b4e9ffff             -call 0x45f5c4
    cpu.esp -= 4;
    sub_45f5c4(app, cpu);
    if (cpu.terminate) return;
    // 00460c10  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
    // 00460c17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460c20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460c21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460c22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00460c24  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00460c26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460c28  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00460c2a  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460c2e  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00460c31  83f908                 +cmp ecx, 8
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
    // 00460c34  751e                   -jne 0x460c54
    if (!cpu.flags.zf)
    {
        goto L_0x00460c54;
    }
L_0x00460c36:
    // 00460c36  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00460c39  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00460c3c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00460c3e  8b3584d54f00           -mov esi, dword ptr [0x4fd584]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460c44  2bb718055000           -sub esi, dword ptr [edi + 0x500518]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5244184) /* 0x500518 */)));
    // 00460c4a  83fe02                 +cmp esi, 2
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
    // 00460c4d  7f28                   -jg 0x460c77
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460c77;
    }
L_0x00460c4f:
    // 00460c4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c51  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00460c54:
    // 00460c54  83f907                 +cmp ecx, 7
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
    // 00460c57  74dd                   -je 0x460c36
    if (cpu.flags.zf)
    {
        goto L_0x00460c36;
    }
    // 00460c59  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460c5c  74d8                   -je 0x460c36
    if (cpu.flags.zf)
    {
        goto L_0x00460c36;
    }
    // 00460c5e  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00460c61  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00460c64  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00460c66  8b3584d54f00           -mov esi, dword ptr [0x4fd584]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460c6c  2bb718055000           -sub esi, dword ptr [edi + 0x500518]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5244184) /* 0x500518 */)));
    // 00460c72  83fe0a                 +cmp esi, 0xa
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
    // 00460c75  7ed8                   -jle 0x460c4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460c4f;
    }
L_0x00460c77:
    // 00460c77  8b3584d54f00           -mov esi, dword ptr [0x4fd584]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 00460c7d  89b718055000           -mov dword ptr [edi + 0x500518], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5244184) /* 0x500518 */) = cpu.esi;
    // 00460c83  e83ce9ffff             -call 0x45f5c4
    cpu.esp -= 4;
    sub_45f5c4(app, cpu);
    if (cpu.terminate) return;
    // 00460c88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c89  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460c8a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_460c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460c90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460c91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00460c93  803800                 +cmp byte ptr [eax], 0
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
    // 00460c96  7515                   -jne 0x460cad
    if (!cpu.flags.zf)
    {
        goto L_0x00460cad;
    }
    // 00460c98  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00460c9b  e818aa0100             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00460ca0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460ca2  7402                   -je 0x460ca6
    if (cpu.flags.zf)
    {
        goto L_0x00460ca6;
    }
    // 00460ca4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ca5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460ca6:
    // 00460ca6  e876a90200             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
    // 00460cab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460cad:
    // 00460cad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460cae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460caf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460cb0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00460cb2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00460cb4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00460cb7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460cb8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460cba  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00460cbd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00460cbf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00460cc1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00460cc4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00460cc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cc7  015d08                 -add dword ptr [ebp + 8], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00460cca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ccb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ccc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ccd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_460cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460cd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460cd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460cd2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460cd5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460cd7  803800                 +cmp byte ptr [eax], 0
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
    // 00460cda  7414                   -je 0x460cf0
    if (cpu.flags.zf)
    {
        goto L_0x00460cf0;
    }
    // 00460cdc  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00460cdf  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00460ce1  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00460ce4  ff4208                 -inc dword ptr [edx + 8]
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))++;
L_0x00460ce7:
    // 00460ce7  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00460cea  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460ced  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460cf0:
    // 00460cf0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00460cf5  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00460cf8  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00460cfa  e8b9a90100             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00460cff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460d01  75e4                   -jne 0x460ce7
    if (!cpu.flags.zf)
    {
        goto L_0x00460ce7;
    }
    // 00460d03  e819a90200             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
    // 00460d08  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00460d0b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460d0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460d20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460d21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460d22  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460d25  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460d27  803800                 +cmp byte ptr [eax], 0
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
    // 00460d2a  7415                   -je 0x460d41
    if (cpu.flags.zf)
    {
        goto L_0x00460d41;
    }
    // 00460d2c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00460d2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00460d31  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00460d34  83420804               -add dword ptr [edx + 8], 4
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00460d38:
    // 00460d38  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00460d3b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460d3e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460d41:
    // 00460d41  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00460d46  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00460d49  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00460d4b  e868a90100             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00460d50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460d52  75e4                   -jne 0x460d38
    if (!cpu.flags.zf)
    {
        goto L_0x00460d38;
    }
    // 00460d54  e8c8a80200             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
    // 00460d59  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00460d5c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460d5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460d70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460d71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460d73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460d75  741c                   -je 0x460d93
    if (cpu.flags.zf)
    {
        goto L_0x00460d93;
    }
    // 00460d77  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460d78  803800                 +cmp byte ptr [eax], 0
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
    // 00460d7b  750e                   -jne 0x460d8b
    if (!cpu.flags.zf)
    {
        goto L_0x00460d8b;
    }
    // 00460d7d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00460d80  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00460d82  7407                   -je 0x460d8b
    if (cpu.flags.zf)
    {
        goto L_0x00460d8b;
    }
    // 00460d84  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460d86  e825a90100             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
L_0x00460d8b:
    // 00460d8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460d8d  e83a7d0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00460d92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00460d93:
    // 00460d93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460d94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460da3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460da4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460da7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00460da9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00460dab  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00460daf  ba74b54b00             -mov edx, 0x4bb574
    cpu.edx = 4961652 /*0x4bb574*/;
    // 00460db4  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00460db9  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00460dbe  b894b54b00             -mov eax, 0x4bb594
    cpu.eax = 4961684 /*0x4bb594*/;
    // 00460dc3  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00460dc9  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 00460dcf  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00460dd4  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00460dd9  e8b6780100             -call 0x478694
    cpu.esp -= 4;
    sub_478694(app, cpu);
    if (cpu.terminate) return;
    // 00460dde  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00460de0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460de2  7533                   -jne 0x460e17
    if (!cpu.flags.zf)
    {
        goto L_0x00460e17;
    }
    // 00460de4  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460de9  7422                   -je 0x460e0d
    if (cpu.flags.zf)
    {
        goto L_0x00460e0d;
    }
    // 00460deb  bd74b54b00             -mov ebp, 0x4bb574
    cpu.ebp = 4961652 /*0x4bb574*/;
    // 00460df0  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00460df5  68a0b54b00             -push 0x4bb5a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4961696 /*0x4bb5a0*/;
    cpu.esp -= 4;
    // 00460dfa  892d8c844c00           -mov dword ptr [0x4c848c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebp;
    // 00460e00  a390844c00             -mov dword ptr [0x4c8490], eax
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.eax;
    // 00460e05  e8b6740100             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00460e0a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00460e0d:
    // 00460e0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460e0f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460e12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460e17:
    // 00460e17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00460e19  7543                   -jne 0x460e5e
    if (!cpu.flags.zf)
    {
        goto L_0x00460e5e;
    }
    // 00460e1b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460e1d  753f                   -jne 0x460e5e
    if (!cpu.flags.zf)
    {
        goto L_0x00460e5e;
    }
L_0x00460e1f:
    // 00460e1f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00460e21  7407                   -je 0x460e2a
    if (cpu.flags.zf)
    {
        goto L_0x00460e2a;
    }
    // 00460e23  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00460e25  e8a27c0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x00460e2a:
    // 00460e2a  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460e2f  74dc                   -je 0x460e0d
    if (cpu.flags.zf)
    {
        goto L_0x00460e0d;
    }
    // 00460e31  bb74b54b00             -mov ebx, 0x4bb574
    cpu.ebx = 4961652 /*0x4bb574*/;
    // 00460e36  be18000000             -mov esi, 0x18
    cpu.esi = 24 /*0x18*/;
    // 00460e3b  68c0b54b00             -push 0x4bb5c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4961728 /*0x4bb5c0*/;
    cpu.esp -= 4;
    // 00460e40  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 00460e46  893590844c00           -mov dword ptr [0x4c8490], esi
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 00460e4c  e86f740100             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00460e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460e54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460e56  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460e59  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e5a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e5b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460e5e:
    // 00460e5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00460e60  7404                   -je 0x460e66
    if (cpu.flags.zf)
    {
        goto L_0x00460e66;
    }
    // 00460e62  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460e64  75b9                   -jne 0x460e1f
    if (!cpu.flags.zf)
    {
        goto L_0x00460e1f;
    }
L_0x00460e66:
    // 00460e66  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460e68  7417                   -je 0x460e81
    if (cpu.flags.zf)
    {
        goto L_0x00460e81;
    }
    // 00460e6a  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00460e71  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 00460e74  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x00460e77:
    // 00460e77  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00460e79  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460e7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460e81:
    // 00460e81  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460e85  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460e89  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00460e8b  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00460e8e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00460e92  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00460e95  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460e96  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00460e99  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00460e9b  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00460e9e  e825a50100             -call 0x47b3c8
    cpu.esp -= 4;
    sub_47b3c8(app, cpu);
    if (cpu.terminate) return;
    // 00460ea3  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460ea7  75ce                   -jne 0x460e77
    if (!cpu.flags.zf)
    {
        goto L_0x00460e77;
    }
    // 00460ea9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00460eab  e81c7c0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00460eb0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00460eb2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460eb5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460eb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460eb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460eb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460eb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 09000000000000000b000000020000000d000000040000000e000000050000000c000000030000000f0000000600000010000000070000001100000008000000 */
void Application::sub_460f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460f00  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460f12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460f13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460f14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460f15  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00460f1b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00460f1d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00460f1f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00460f21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00460f22:
    // 00460f22  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00460f24  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00460f26  3c00                   +cmp al, 0
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
    // 00460f28  7410                   -je 0x460f3a
    if (cpu.flags.zf)
    {
        goto L_0x00460f3a;
    }
    // 00460f2a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00460f2d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00460f30  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00460f33  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00460f36  3c00                   +cmp al, 0
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
    // 00460f38  75e8                   -jne 0x460f22
    if (!cpu.flags.zf)
    {
        goto L_0x00460f22;
    }
L_0x00460f3a:
    // 00460f3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f3b  bea8b74b00             -mov esi, 0x4bb7a8
    cpu.esi = 4962216 /*0x4bb7a8*/;
    // 00460f40  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00460f42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00460f44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460f45  2bc9                   +sub ecx, ecx
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
    // 00460f47  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00460f48  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00460f4a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00460f4c  4f                     -dec edi
    (cpu.edi)--;
L_0x00460f4d:
    // 00460f4d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00460f4f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00460f51  3c00                   +cmp al, 0
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
    // 00460f53  7410                   -je 0x460f65
    if (cpu.flags.zf)
    {
        goto L_0x00460f65;
    }
    // 00460f55  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00460f58  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00460f5b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00460f5e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00460f61  3c00                   +cmp al, 0
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
    // 00460f63  75e8                   -jne 0x460f4d
    if (!cpu.flags.zf)
    {
        goto L_0x00460f4d;
    }
L_0x00460f65:
    // 00460f65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f66  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00460f68  e8439d0100             -call 0x47acb0
    cpu.esp -= 4;
    sub_47acb0(app, cpu);
    if (cpu.terminate) return;
    // 00460f6d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460f6f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460f71  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460f73  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00460f7a  e805830100             -call 0x479284
    cpu.esp -= 4;
    sub_479284(app, cpu);
    if (cpu.terminate) return;
    // 00460f7f  83f807                 +cmp eax, 7
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
    // 00460f82  742f                   -je 0x460fb3
    if (cpu.flags.zf)
    {
        goto L_0x00460fb3;
    }
L_0x00460f84:
    // 00460f84  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00460f8b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00460f8d  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00460f94  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00460f9b  899904654d00           -mov dword ptr [ecx + 0x4d6504], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5072132) /* 0x4d6504 */) = cpu.ebx;
    // 00460fa1  8981fc644d00           -mov dword ptr [ecx + 0x4d64fc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5072124) /* 0x4d64fc */) = cpu.eax;
    // 00460fa7  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00460fad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460fae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460faf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460fb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460fb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460fb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460fb3:
    // 00460fb3  bab8b64b00             -mov edx, 0x4bb6b8
    cpu.edx = 4961976 /*0x4bb6b8*/;
    // 00460fb8  bb10030000             -mov ebx, 0x310
    cpu.ebx = 784 /*0x310*/;
    // 00460fbd  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00460fc4  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00460fca  891d90844c00           -mov dword ptr [0x4c8490], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 00460fd0  e8ab800100             -call 0x479080
    cpu.esp -= 4;
    sub_479080(app, cpu);
    if (cpu.terminate) return;
    // 00460fd5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460fd7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00460fd9  b8b0b74b00             -mov eax, 0x4bb7b0
    cpu.eax = 4962224 /*0x4bb7b0*/;
    // 00460fde  e885760100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00460fe3  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00460fea  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460fec  e847810100             -call 0x479138
    cpu.esp -= 4;
    sub_479138(app, cpu);
    if (cpu.terminate) return;
    // 00460ff1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460ff3  e8d47a0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00460ff8  eb8a                   -jmp 0x460f84
    goto L_0x00460f84;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461000  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461001  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00461006  e819930100             -call 0x47a324
    cpu.esp -= 4;
    sub_47a324(app, cpu);
    if (cpu.terminate) return;
    // 0046100b  8b1504654d00           -mov edx, dword ptr [0x4d6504]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5072132) /* 0x4d6504 */);
    // 00461011  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461013  7502                   -jne 0x461017
    if (!cpu.flags.zf)
    {
        goto L_0x00461017;
    }
    // 00461015  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461016  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461017:
    // 00461017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461018  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046101a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046101c  e8ab7a0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00461021  890d04654d00           -mov dword ptr [0x4d6504], ecx
    app->getMemory<x86::reg32>(x86::reg32(5072132) /* 0x4d6504 */) = cpu.ecx;
    // 00461027  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461028  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461033  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00461035:
    // 00461035  8b8a04654d00           -mov ecx, dword ptr [edx + 0x4d6504]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5072132) /* 0x4d6504 */);
    // 0046103b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046103d  750c                   -jne 0x46104b
    if (!cpu.flags.zf)
    {
        goto L_0x0046104b;
    }
    // 0046103f  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00461042  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461045  75ee                   -jne 0x461035
    if (!cpu.flags.zf)
    {
        goto L_0x00461035;
    }
    // 00461047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461048  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461049  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046104a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046104b:
    // 0046104b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046104d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046104f  e8787a0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00461054  899a04654d00           -mov dword ptr [edx + 0x4d6504], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5072132) /* 0x4d6504 */) = cpu.ebx;
    // 0046105a  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046105d  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461060  75d3                   -jne 0x461035
    if (!cpu.flags.zf)
    {
        goto L_0x00461035;
    }
    // 00461062  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461063  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461064  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461070  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461077  7509                   -jne 0x461082
    if (!cpu.flags.zf)
    {
        goto L_0x00461082;
    }
    // 00461079  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461080  7501                   -jne 0x461083
    if (!cpu.flags.zf)
    {
        goto L_0x00461083;
    }
L_0x00461082:
    // 00461082  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461083:
    // 00461083  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461084  e8f75a0200             -call 0x486b80
    cpu.esp -= 4;
    sub_486b80(app, cpu);
    if (cpu.terminate) return;
    // 00461089  a1386b4c00             -mov eax, dword ptr [0x4c6b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */);
    // 0046108e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461090  e8073b0200             -call 0x484b9c
    cpu.esp -= 4;
    sub_484b9c(app, cpu);
    if (cpu.terminate) return;
    // 00461095  890d386b4c00           -mov dword ptr [0x4c6b38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */) = cpu.ecx;
    // 0046109b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046109c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4610a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004610a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004610a1  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004610a8  7509                   -jne 0x4610b3
    if (!cpu.flags.zf)
    {
        goto L_0x004610b3;
    }
    // 004610aa  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004610b1  7502                   -jne 0x4610b5
    if (!cpu.flags.zf)
    {
        goto L_0x004610b5;
    }
L_0x004610b3:
    // 004610b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004610b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004610b5:
    // 004610b5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004610b7  e804d80100             -call 0x47e8c0
    cpu.esp -= 4;
    sub_47e8c0(app, cpu);
    if (cpu.terminate) return;
    // 004610bc  e85b5c0200             -call 0x486d1c
    cpu.esp -= 4;
    sub_486d1c(app, cpu);
    if (cpu.terminate) return;
    // 004610c1  803d346b4c0000         +cmp byte ptr [0x4c6b34], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004610c8  7422                   -je 0x4610ec
    if (cpu.flags.zf)
    {
        goto L_0x004610ec;
    }
    // 004610ca  e8b15a0200             -call 0x486b80
    cpu.esp -= 4;
    sub_486b80(app, cpu);
    if (cpu.terminate) return;
L_0x004610cf:
    // 004610cf  8b0d20065000           -mov ecx, dword ptr [0x500620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */);
    // 004610d5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004610d7  74da                   -je 0x4610b3
    if (cpu.flags.zf)
    {
        goto L_0x004610b3;
    }
    // 004610d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004610da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004610dc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004610de  e8e9790100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004610e3  891d20065000           -mov dword ptr [0x500620], ebx
    app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */) = cpu.ebx;
    // 004610e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004610ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004610eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004610ec:
    // 004610ec  e8eb860200             -call 0x4897dc
    cpu.esp -= 4;
    sub_4897dc(app, cpu);
    if (cpu.terminate) return;
    // 004610f1  ebdc                   -jmp 0x4610cf
    goto L_0x004610cf;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461101  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461102  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461109  7509                   -jne 0x461114
    if (!cpu.flags.zf)
    {
        goto L_0x00461114;
    }
    // 0046110b  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461112  7503                   -jne 0x461117
    if (!cpu.flags.zf)
    {
        goto L_0x00461117;
    }
L_0x00461114:
    // 00461114  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461117:
    // 00461117  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0046111c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046111e  e89d920100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
L_0x00461123:
    // 00461123  e8f8a60200             -call 0x48b820
    cpu.esp -= 4;
    sub_48b820(app, cpu);
    if (cpu.terminate) return;
    // 00461128  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046112a  7e09                   -jle 0x461135
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461135;
    }
    // 0046112c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046112e  e84d6f0100             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00461133  ebee                   -jmp 0x461123
    goto L_0x00461123;
L_0x00461135:
    // 00461135  e8e25b0200             -call 0x486d1c
    cpu.esp -= 4;
    sub_486d1c(app, cpu);
    if (cpu.terminate) return;
    // 0046113a  803d346b4c0000         +cmp byte ptr [0x4c6b34], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461141  7423                   -je 0x461166
    if (cpu.flags.zf)
    {
        goto L_0x00461166;
    }
    // 00461143  e8385a0200             -call 0x486b80
    cpu.esp -= 4;
    sub_486b80(app, cpu);
    if (cpu.terminate) return;
L_0x00461148:
    // 00461148  8b0d20065000           -mov ecx, dword ptr [0x500620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */);
    // 0046114e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461150  74c2                   -je 0x461114
    if (cpu.flags.zf)
    {
        goto L_0x00461114;
    }
    // 00461152  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461153  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00461155  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00461157  e870790100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046115c  891d20065000           -mov dword ptr [0x500620], ebx
    app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */) = cpu.ebx;
    // 00461162  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461165  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461166:
    // 00461166  e871860200             -call 0x4897dc
    cpu.esp -= 4;
    sub_4897dc(app, cpu);
    if (cpu.terminate) return;
    // 0046116b  ebdb                   -jmp 0x461148
    goto L_0x00461148;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_461170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461171  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461172  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00461178  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046117a  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046117d  7502                   -jne 0x461181
    if (!cpu.flags.zf)
    {
        goto L_0x00461181;
    }
    // 0046117f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00461181:
    // 00461181  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461188  0f85d5000000           -jne 0x461263
    if (!cpu.flags.zf)
    {
        goto L_0x00461263;
    }
    // 0046118e  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461195  0f84c8000000           -je 0x461263
    if (cpu.flags.zf)
    {
        goto L_0x00461263;
    }
    // 0046119b  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046119e  0f8fbf000000           -jg 0x461263
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461263;
    }
    // 004611a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004611a6  0f85c0000000           -jne 0x46126c
    if (!cpu.flags.zf)
    {
        goto L_0x0046126c;
    }
    // 004611ac  a3ac2d4c00             -mov dword ptr [0x4c2dac], eax
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = cpu.eax;
L_0x004611b1:
    // 004611b1  833d7c2d4c0001         +cmp dword ptr [0x4c2d7c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992380) /* 0x4c2d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004611b8  7511                   -jne 0x4611cb
    if (!cpu.flags.zf)
    {
        goto L_0x004611cb;
    }
    // 004611ba  83f809                 +cmp eax, 9
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
    // 004611bd  7d0c                   -jge 0x4611cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004611cb;
    }
    // 004611bf  803d1fe04d0000         +cmp byte ptr [0x4de01f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103647) /* 0x4de01f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004611c6  7403                   -je 0x4611cb
    if (cpu.flags.zf)
    {
        goto L_0x004611cb;
    }
    // 004611c8  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x004611cb:
    // 004611cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004611cc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004611cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004611ce  83f812                 +cmp eax, 0x12
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
    // 004611d1  0f84a4000000           -je 0x46127b
    if (cpu.flags.zf)
    {
        goto L_0x0046127b;
    }
    // 004611d7  8b1485e86b4c00         -mov edx, dword ptr [eax*4 + 0x4c6be8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008360) /* 0x4c6be8 */ + cpu.eax * 4);
    // 004611de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004611df  8b0d80e54d00           -mov ecx, dword ptr [0x4de580]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 004611e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004611e6  6800b74b00             -push 0x4bb700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962048 /*0x4bb700*/;
    cpu.esp -= 4;
    // 004611eb  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004611ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004611f0  e82c920100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004611f5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004611f8:
    // 004611f8  be84b74b00             -mov esi, 0x4bb784
    cpu.esi = 4962180 /*0x4bb784*/;
    // 004611fd  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461202  2bc9                   +sub ecx, ecx
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
    // 00461204  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00461205  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00461207  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00461209  4f                     -dec edi
    (cpu.edi)--;
L_0x0046120a:
    // 0046120a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046120c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046120e  3c00                   +cmp al, 0
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
    // 00461210  7410                   -je 0x461222
    if (cpu.flags.zf)
    {
        goto L_0x00461222;
    }
    // 00461212  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00461215  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00461218  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046121b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046121e  3c00                   +cmp al, 0
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
    // 00461220  75e8                   -jne 0x46120a
    if (!cpu.flags.zf)
    {
        goto L_0x0046120a;
    }
L_0x00461222:
    // 00461222  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461223  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046122a  e871800100             -call 0x4792a0
    cpu.esp -= 4;
    sub_4792a0(app, cpu);
    if (cpu.terminate) return;
    // 0046122f  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00461231  8d94240c010000         -lea edx, [esp + 0x10c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00461238  88842414010000         -mov byte ptr [esp + 0x114], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.al;
    // 0046123f  a1386b4c00             -mov eax, dword ptr [0x4c6b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */);
    // 00461244  e877580200             -call 0x486ac0
    cpu.esp -= 4;
    sub_486ac0(app, cpu);
    if (cpu.terminate) return;
    // 00461249  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046124d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046124f  e888590200             -call 0x486bdc
    cpu.esp -= 4;
    sub_486bdc(app, cpu);
    if (cpu.terminate) return;
    // 00461254  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00461259  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046125b  e860910100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00461260  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461261  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461262  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00461263:
    // 00461263  81c410010000           +add esp, 0x110
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046126a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046126b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046126c:
    // 0046126c  c705ac2d4c0001000000   -mov dword ptr [0x4c2dac], 1
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = 1 /*0x1*/;
    // 00461276  e936ffffff             -jmp 0x4611b1
    goto L_0x004611b1;
L_0x0046127b:
    // 0046127b  803d3a6c4c0000         +cmp byte ptr [0x4c6c3a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008442) /* 0x4c6c3a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461282  742d                   -je 0x4612b1
    if (cpu.flags.zf)
    {
        goto L_0x004612b1;
    }
    // 00461284  a180e54d00             -mov eax, dword ptr [0x4de580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461289  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046128a  6808b74b00             -push 0x4bb708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962056 /*0x4bb708*/;
    cpu.esp -= 4;
L_0x0046128f:
    // 0046128f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00461293  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461294  e888910100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461299  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046129c  803d3a6c4c0000         +cmp byte ptr [0x4c6c3a], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008442) /* 0x4c6c3a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004612a3  751a                   -jne 0x4612bf
    if (!cpu.flags.zf)
    {
        goto L_0x004612bf;
    }
    // 004612a5  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004612a7  a23a6c4c00             -mov byte ptr [0x4c6c3a], al
    app->getMemory<x86::reg8>(x86::reg32(5008442) /* 0x4c6c3a */) = cpu.al;
    // 004612ac  e947ffffff             -jmp 0x4611f8
    goto L_0x004611f8;
L_0x004612b1:
    // 004612b1  8b2d80e54d00           -mov ebp, dword ptr [0x4de580]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 004612b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004612b8  6810b74b00             -push 0x4bb710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962064 /*0x4bb710*/;
    cpu.esp -= 4;
    // 004612bd  ebd0                   -jmp 0x46128f
    goto L_0x0046128f;
L_0x004612bf:
    // 004612bf  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004612c1  a23a6c4c00             -mov byte ptr [0x4c6c3a], al
    app->getMemory<x86::reg8>(x86::reg32(5008442) /* 0x4c6c3a */) = cpu.al;
    // 004612c6  e92dffffff             -jmp 0x4611f8
    goto L_0x004611f8;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4612d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004612d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004612d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004612d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004612d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004612d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004612d5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004612db  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004612dd  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 004612e4  bbdc050000             -mov ebx, 0x5dc
    cpu.ebx = 1500 /*0x5dc*/;
    // 004612e9  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004612ec  7502                   -jne 0x4612f0
    if (!cpu.flags.zf)
    {
        goto L_0x004612f0;
    }
    // 004612ee  31c5                   -xor ebp, eax
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004612f0:
    // 004612f0  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004612f2  8a15acdf4d00           -mov dl, byte ptr [0x4ddfac]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
    // 004612f8  8825346b4c00           -mov byte ptr [0x4c6b34], ah
    app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */) = cpu.ah;
    // 004612fe  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00461300  7543                   -jne 0x461345
    if (!cpu.flags.zf)
    {
        goto L_0x00461345;
    }
    // 00461302  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461309  743a                   -je 0x461345
    if (cpu.flags.zf)
    {
        goto L_0x00461345;
    }
    // 0046130b  83fd13                 +cmp ebp, 0x13
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046130e  7f35                   -jg 0x461345
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461345;
    }
    // 00461310  803d1fe04d0000         +cmp byte ptr [0x4de01f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103647) /* 0x4de01f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461317  7538                   -jne 0x461351
    if (!cpu.flags.zf)
    {
        goto L_0x00461351;
    }
    // 00461319  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046131c  7d33                   -jge 0x461351
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461351;
    }
    // 0046131e  803d20e04d0000         +cmp byte ptr [0x4de020], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103648) /* 0x4de020 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461325  7609                   -jbe 0x461330
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00461330;
    }
    // 00461327  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00461329  e8c2010000             -call 0x4614f0
    cpu.esp -= 4;
    sub_4614f0(app, cpu);
    if (cpu.terminate) return;
    // 0046132e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00461330:
    // 00461330  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00461337  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00461339  e832feffff             -call 0x461170
    cpu.esp -= 4;
    sub_461170(app, cpu);
    if (cpu.terminate) return;
    // 0046133e  c605346b4c0001         -mov byte ptr [0x4c6b34], 1
    app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */) = 1 /*0x1*/;
L_0x00461345:
    // 00461345  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0046134b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046134c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046134d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046134e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046134f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461350  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461351:
    // 00461351  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461353  0f852f010000           -jne 0x461488
    if (!cpu.flags.zf)
    {
        goto L_0x00461488;
    }
    // 00461359  892dac2d4c00           -mov dword ptr [0x4c2dac], ebp
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = cpu.ebp;
L_0x0046135f:
    // 0046135f  833d7c2d4c0001         +cmp dword ptr [0x4c2d7c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992380) /* 0x4c2d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461366  7508                   -jne 0x461370
    if (!cpu.flags.zf)
    {
        goto L_0x00461370;
    }
    // 00461368  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046136b  7d03                   -jge 0x461370
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461370;
    }
    // 0046136d  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00461370:
    // 00461370  83fd12                 +cmp ebp, 0x12
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461373  0f841e010000           -je 0x461497
    if (cpu.flags.zf)
    {
        goto L_0x00461497;
    }
    // 00461379  8b0cade86b4c00         -mov ecx, dword ptr [ebp*4 + 0x4c6be8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5008360) /* 0x4c6be8 */ + cpu.ebp * 4);
    // 00461380  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461381  8b3580e54d00           -mov esi, dword ptr [0x4de580]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461387  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461388  6800b74b00             -push 0x4bb700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962048 /*0x4bb700*/;
    cpu.esp -= 4;
    // 0046138d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461391  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461392  e88a900100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461397  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x0046139a:
    // 0046139a  be38b74b00             -mov esi, 0x4bb738
    cpu.esi = 4962104 /*0x4bb738*/;
    // 0046139f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004613a1  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004613a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004613a7  2bc9                   +sub ecx, ecx
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
    // 004613a9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004613aa  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004613ac  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004613ae  4f                     -dec edi
    (cpu.edi)--;
L_0x004613af:
    // 004613af  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004613b1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004613b3  3c00                   +cmp al, 0
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
    // 004613b5  7410                   -je 0x4613c7
    if (cpu.flags.zf)
    {
        goto L_0x004613c7;
    }
    // 004613b7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004613ba  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004613bd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004613c0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004613c3  3c00                   +cmp al, 0
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
    // 004613c5  75e8                   -jne 0x4613af
    if (!cpu.flags.zf)
    {
        goto L_0x004613af;
    }
L_0x004613c7:
    // 004613c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004613ca  e8d1980100             -call 0x47aca0
    cpu.esp -= 4;
    sub_47aca0(app, cpu);
    if (cpu.terminate) return;
    // 004613cf  a320065000             -mov dword ptr [0x500620], eax
    app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */) = cpu.eax;
    // 004613d4  e8eb810200             -call 0x4895c4
    cpu.esp -= 4;
    sub_4895c4(app, cpu);
    if (cpu.terminate) return;
    // 004613d9  8b3d64e54d00           -mov edi, dword ptr [0x4de564]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5104996) /* 0x4de564 */);
    // 004613df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004613e0  687cb74b00             -push 0x4bb77c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962172 /*0x4bb77c*/;
    cpu.esp -= 4;
    // 004613e5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004613e9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004613ea  be54b74b00             -mov esi, 0x4bb754
    cpu.esi = 4962132 /*0x4bb754*/;
    // 004613ef  e82d900100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004613f4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004613f7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004613f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004613fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004613fc  2bc9                   +sub ecx, ecx
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
    // 004613fe  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004613ff  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00461401  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00461403  4f                     -dec edi
    (cpu.edi)--;
L_0x00461404:
    // 00461404  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00461406  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00461408  3c00                   +cmp al, 0
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
    // 0046140a  7410                   -je 0x46141c
    if (cpu.flags.zf)
    {
        goto L_0x0046141c;
    }
    // 0046140c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046140f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00461412  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00461415  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00461418  3c00                   +cmp al, 0
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
    // 0046141a  75e8                   -jne 0x461404
    if (!cpu.flags.zf)
    {
        goto L_0x00461404;
    }
L_0x0046141c:
    // 0046141c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046141d  a1386b4c00             -mov eax, dword ptr [0x4c6b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */);
    // 00461422  e839820200             -call 0x489660
    cpu.esp -= 4;
    sub_489660(app, cpu);
    if (cpu.terminate) return;
    // 00461427  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046142c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046142e  e88d8f0100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00461433  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0046143a  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0046143f  e87c8f0100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00461444  833d08d34d0000         +cmp dword ptr [0x4dd308], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100296) /* 0x4dd308 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046144b  0f84f4feffff           -je 0x461345
    if (cpu.flags.zf)
    {
        goto L_0x00461345;
    }
    // 00461451  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461453  0f84ecfeffff           -je 0x461345
    if (cpu.flags.zf)
    {
        goto L_0x00461345;
    }
    // 00461459  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046145c  0f84e3feffff           -je 0x461345
    if (cpu.flags.zf)
    {
        goto L_0x00461345;
    }
    // 00461462  8a04ad486b4c00         -mov al, byte ptr [ebp*4 + 0x4c6b48]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5008200) /* 0x4c6b48 */ + cpu.ebp * 4);
    // 00461469  a2782d4c00             -mov byte ptr [0x4c2d78], al
    app->getMemory<x86::reg8>(x86::reg32(4992376) /* 0x4c2d78 */) = cpu.al;
    // 0046146e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461470  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461472  a0782d4c00             -mov al, byte ptr [0x4c2d78]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4992376) /* 0x4c2d78 */);
    // 00461477  e8d8820200             -call 0x489754
    cpu.esp -= 4;
    sub_489754(app, cpu);
    if (cpu.terminate) return;
    // 0046147c  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461482  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461483  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461484  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461485  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461486  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461487  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461488:
    // 00461488  c705ac2d4c0001000000   -mov dword ptr [0x4c2dac], 1
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = 1 /*0x1*/;
    // 00461492  e9c8feffff             -jmp 0x46135f
    goto L_0x0046135f;
L_0x00461497:
    // 00461497  803d396c4c0000         +cmp byte ptr [0x4c6c39], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008441) /* 0x4c6c39 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046149e  742e                   -je 0x4614ce
    if (cpu.flags.zf)
    {
        goto L_0x004614ce;
    }
    // 004614a0  8b1580e54d00           -mov edx, dword ptr [0x4de580]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 004614a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004614a7  6808b74b00             -push 0x4bb708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962056 /*0x4bb708*/;
    cpu.esp -= 4;
L_0x004614ac:
    // 004614ac  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004614b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004614b1  e86b8f0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004614b6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004614b9  803d396c4c0000         +cmp byte ptr [0x4c6c39], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008441) /* 0x4c6c39 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004614c0  7519                   -jne 0x4614db
    if (!cpu.flags.zf)
    {
        goto L_0x004614db;
    }
    // 004614c2  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004614c4  a2396c4c00             -mov byte ptr [0x4c6c39], al
    app->getMemory<x86::reg8>(x86::reg32(5008441) /* 0x4c6c39 */) = cpu.al;
    // 004614c9  e9ccfeffff             -jmp 0x46139a
    goto L_0x0046139a;
L_0x004614ce:
    // 004614ce  a180e54d00             -mov eax, dword ptr [0x4de580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 004614d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004614d4  6810b74b00             -push 0x4bb710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962064 /*0x4bb710*/;
    cpu.esp -= 4;
    // 004614d9  ebd1                   -jmp 0x4614ac
    goto L_0x004614ac;
L_0x004614db:
    // 004614db  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004614dd  a2396c4c00             -mov byte ptr [0x4c6c39], al
    app->getMemory<x86::reg8>(x86::reg32(5008441) /* 0x4c6c39 */) = cpu.al;
    // 004614e2  e9b3feffff             -jmp 0x46139a
    goto L_0x0046139a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4614f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004614f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004614f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004614f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004614f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004614f4  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004614f7  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004614fc  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004614fe  bec00e4600             -mov esi, 0x460ec0
    cpu.esi = 4591296 /*0x460ec0*/;
    // 00461503  8a151fe04d00           -mov dl, byte ptr [0x4de01f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5103647) /* 0x4de01f */);
    // 00461509  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046150b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046150d  7513                   -jne 0x461522
    if (!cpu.flags.zf)
    {
        goto L_0x00461522;
    }
    // 0046150f  8a3520e04d00           -mov dh, byte ptr [0x4de020]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5103648) /* 0x4de020 */);
    // 00461515  80fe11                 +cmp dh, 0x11
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461518  7410                   -je 0x46152a
    if (cpu.flags.zf)
    {
        goto L_0x0046152a;
    }
    // 0046151a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046151c  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 0046151e  8b4484fc               -mov eax, dword ptr [esp + eax*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
L_0x00461522:
    // 00461522  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00461525  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461526  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461527  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461528  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461529  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046152a:
    // 0046152a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046152b  8a1d74654d00           -mov bl, byte ptr [0x4d6574]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5072244) /* 0x4d6574 */);
    // 00461531  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461533  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 00461535  8a92bd2d4c00           -mov dl, byte ptr [edx + 0x4c2dbd]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4992445) /* 0x4c2dbd */);
    // 0046153b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00461541  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00461546  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461548  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046154b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046154d  fec3                   -inc bl
    (cpu.bl)++;
    // 0046154f  881d74654d00           -mov byte ptr [0x4d6574], bl
    app->getMemory<x86::reg8>(x86::reg32(5072244) /* 0x4d6574 */) = cpu.bl;
    // 00461555  8b449404               -mov eax, dword ptr [esp + edx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 00461559  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046155a  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046155d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046155e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046155f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461560  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461561  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461571  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461572  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00461578  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046157a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046157c  c7842400010000dc050000 -mov dword ptr [esp + 0x100], 0x5dc
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = 1500 /*0x5dc*/;
    // 00461587  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046158a  7502                   -jne 0x46158e
    if (!cpu.flags.zf)
    {
        goto L_0x0046158e;
    }
    // 0046158c  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046158e:
    // 0046158e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00461590  8a15acdf4d00           -mov dl, byte ptr [0x4ddfac]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
    // 00461596  8825346b4c00           -mov byte ptr [0x4c6b34], ah
    app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */) = cpu.ah;
    // 0046159c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046159e  0f854d010000           -jne 0x4616f1
    if (!cpu.flags.zf)
    {
        goto L_0x004616f1;
    }
    // 004615a4  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615ab  0f8440010000           -je 0x4616f1
    if (cpu.flags.zf)
    {
        goto L_0x004616f1;
    }
    // 004615b1  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615b4  0f8f37010000           -jg 0x4616f1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004616f1;
    }
    // 004615ba  803d1fe04d0000         +cmp byte ptr [0x4de01f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103647) /* 0x4de01f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004615c1  7509                   -jne 0x4615cc
    if (!cpu.flags.zf)
    {
        goto L_0x004615cc;
    }
    // 004615c3  83fb09                 +cmp ebx, 9
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
    // 004615c6  0f8c2e010000           -jl 0x4616fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004616fa;
    }
L_0x004615cc:
    // 004615cc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004615ce  0f853f010000           -jne 0x461713
    if (!cpu.flags.zf)
    {
        goto L_0x00461713;
    }
    // 004615d4  891dac2d4c00           -mov dword ptr [0x4c2dac], ebx
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = cpu.ebx;
L_0x004615da:
    // 004615da  833d7c2d4c0001         +cmp dword ptr [0x4c2d7c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992380) /* 0x4c2d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615e1  7508                   -jne 0x4615eb
    if (!cpu.flags.zf)
    {
        goto L_0x004615eb;
    }
    // 004615e3  83fb09                 +cmp ebx, 9
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
    // 004615e6  7d03                   -jge 0x4615eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004615eb;
    }
    // 004615e8  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x004615eb:
    // 004615eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004615ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004615ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004615ee  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615f1  0f842b010000           -je 0x461722
    if (cpu.flags.zf)
    {
        goto L_0x00461722;
    }
    // 004615f7  8b349de86b4c00         -mov esi, dword ptr [ebx*4 + 0x4c6be8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008360) /* 0x4c6be8 */ + cpu.ebx * 4);
    // 004615fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004615ff  8b3d80e54d00           -mov edi, dword ptr [0x4de580]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461605  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461606  6800b74b00             -push 0x4bb700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962048 /*0x4bb700*/;
    cpu.esp -= 4;
    // 0046160b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046160f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461610  e80c8e0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461615  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00461618:
    // 00461618  be38b74b00             -mov esi, 0x4bb738
    cpu.esi = 4962104 /*0x4bb738*/;
    // 0046161d  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461621  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00461626  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461627  2bc9                   +sub ecx, ecx
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
    // 00461629  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046162a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0046162c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0046162e  4f                     -dec edi
    (cpu.edi)--;
L_0x0046162f:
    // 0046162f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00461631  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00461633  3c00                   +cmp al, 0
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
    // 00461635  7410                   -je 0x461647
    if (cpu.flags.zf)
    {
        goto L_0x00461647;
    }
    // 00461637  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046163a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046163d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00461640  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00461643  3c00                   +cmp al, 0
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
    // 00461645  75e8                   -jne 0x46162f
    if (!cpu.flags.zf)
    {
        goto L_0x0046162f;
    }
L_0x00461647:
    // 00461647  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461648  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046164c  e84f960100             -call 0x47aca0
    cpu.esp -= 4;
    sub_47aca0(app, cpu);
    if (cpu.terminate) return;
    // 00461651  a320065000             -mov dword ptr [0x500620], eax
    app->getMemory<x86::reg32>(x86::reg32(5244448) /* 0x500620 */) = cpu.eax;
    // 00461656  e8697f0200             -call 0x4895c4
    cpu.esp -= 4;
    sub_4895c4(app, cpu);
    if (cpu.terminate) return;
    // 0046165b  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046165e  0f8412010000           -je 0x461776
    if (cpu.flags.zf)
    {
        goto L_0x00461776;
    }
    // 00461664  8b0c9d986b4c00         -mov ecx, dword ptr [ebx*4 + 0x4c6b98]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5008280) /* 0x4c6b98 */ + cpu.ebx * 4);
    // 0046166b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046166c  8b1d80e54d00           -mov ebx, dword ptr [0x4de580]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461672  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461673  6800b74b00             -push 0x4bb700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962048 /*0x4bb700*/;
    cpu.esp -= 4;
    // 00461678  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046167c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046167d  e89f8d0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461682  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00461685:
    // 00461685  be54b74b00             -mov esi, 0x4bb754
    cpu.esi = 4962132 /*0x4bb754*/;
    // 0046168a  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046168e  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00461695  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461696  2bc9                   +sub ecx, ecx
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
    // 00461698  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00461699  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0046169b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0046169d  4f                     -dec edi
    (cpu.edi)--;
L_0x0046169e:
    // 0046169e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004616a0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004616a2  3c00                   +cmp al, 0
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
    // 004616a4  7410                   -je 0x4616b6
    if (cpu.flags.zf)
    {
        goto L_0x004616b6;
    }
    // 004616a6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004616a9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004616ac  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004616af  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004616b2  3c00                   +cmp al, 0
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
    // 004616b4  75e8                   -jne 0x46169e
    if (!cpu.flags.zf)
    {
        goto L_0x0046169e;
    }
L_0x004616b6:
    // 004616b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004616b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004616b9  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004616bd  e8de7b0200             -call 0x4892a0
    cpu.esp -= 4;
    sub_4892a0(app, cpu);
    if (cpu.terminate) return;
    // 004616c2  a1386b4c00             -mov eax, dword ptr [0x4c6b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */);
    // 004616c7  e8947f0200             -call 0x489660
    cpu.esp -= 4;
    sub_489660(app, cpu);
    if (cpu.terminate) return;
    // 004616cc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004616d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004616d3  e8e88c0100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
    // 004616d8  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 004616dd  e8be7b0200             -call 0x4892a0
    cpu.esp -= 4;
    sub_4892a0(app, cpu);
    if (cpu.terminate) return;
    // 004616e2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004616e4  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004616e9  e8d28c0100             -call 0x47a3c0
    cpu.esp -= 4;
    sub_47a3c0(app, cpu);
    if (cpu.terminate) return;
    // 004616ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004616ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004616f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004616f1:
    // 004616f1  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004616f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004616f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004616f9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004616fa:
    // 004616fa  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004616fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004616fe  e86dfaffff             -call 0x461170
    cpu.esp -= 4;
    sub_461170(app, cpu);
    if (cpu.terminate) return;
    // 00461703  c605346b4c0001         -mov byte ptr [0x4c6b34], 1
    app->getMemory<x86::reg8>(x86::reg32(5008180) /* 0x4c6b34 */) = 1 /*0x1*/;
    // 0046170a  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461710  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461711  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461712  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461713:
    // 00461713  c705ac2d4c0001000000   -mov dword ptr [0x4c2dac], 1
    app->getMemory<x86::reg32>(x86::reg32(4992428) /* 0x4c2dac */) = 1 /*0x1*/;
    // 0046171d  e9b8feffff             -jmp 0x4615da
    goto L_0x004615da;
L_0x00461722:
    // 00461722  803d386c4c0000         +cmp byte ptr [0x4c6c38], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008440) /* 0x4c6c38 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00461729  7529                   -jne 0x461754
    if (!cpu.flags.zf)
    {
        goto L_0x00461754;
    }
    // 0046172b  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0046172d:
    // 0046172d  a2386c4c00             -mov byte ptr [0x4c6c38], al
    app->getMemory<x86::reg8>(x86::reg32(5008440) /* 0x4c6c38 */) = cpu.al;
    // 00461732  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00461734  7422                   -je 0x461758
    if (cpu.flags.zf)
    {
        goto L_0x00461758;
    }
    // 00461736  8b0d80e54d00           -mov ecx, dword ptr [0x4de580]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 0046173c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046173d  6808b74b00             -push 0x4bb708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962056 /*0x4bb708*/;
    cpu.esp -= 4;
    // 00461742  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00461746  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461747  e8d58c0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0046174c  83c40c                 +add esp, 0xc
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
    // 0046174f  e9c4feffff             -jmp 0x461618
    goto L_0x00461618;
L_0x00461754:
    // 00461754  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00461756  ebd5                   -jmp 0x46172d
    goto L_0x0046172d;
L_0x00461758:
    // 00461758  8b1580e54d00           -mov edx, dword ptr [0x4de580]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 0046175e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046175f  6810b74b00             -push 0x4bb710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962064 /*0x4bb710*/;
    cpu.esp -= 4;
    // 00461764  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00461768  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461769  e8b38c0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0046176e  83c40c                 +add esp, 0xc
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
    // 00461771  e9a2feffff             -jmp 0x461618
    goto L_0x00461618;
L_0x00461776:
    // 00461776  803d386c4c0000         +cmp byte ptr [0x4c6c38], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5008440) /* 0x4c6c38 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046177d  741e                   -je 0x46179d
    if (cpu.flags.zf)
    {
        goto L_0x0046179d;
    }
    // 0046177f  8b1580e54d00           -mov edx, dword ptr [0x4de580]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461785  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461786  6808b74b00             -push 0x4bb708
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962056 /*0x4bb708*/;
    cpu.esp -= 4;
    // 0046178b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046178f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461790  e88c8c0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461795  83c40c                 +add esp, 0xc
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
    // 00461798  e9e8feffff             -jmp 0x461685
    goto L_0x00461685;
L_0x0046179d:
    // 0046179d  a180e54d00             -mov eax, dword ptr [0x4de580]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 004617a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004617a3  6810b74b00             -push 0x4bb710
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962064 /*0x4bb710*/;
    cpu.esp -= 4;
    // 004617a8  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004617ac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004617ad  e86f8c0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004617b2  83c40c                 +add esp, 0xc
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
    // 004617b5  e9cbfeffff             -jmp 0x461685
    goto L_0x00461685;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4617c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004617c0  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004617c7  7509                   -jne 0x4617d2
    if (!cpu.flags.zf)
    {
        goto L_0x004617d2;
    }
    // 004617c9  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004617d0  7501                   -jne 0x4617d3
    if (!cpu.flags.zf)
    {
        goto L_0x004617d3;
    }
L_0x004617d2:
    // 004617d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004617d3:
    // 004617d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004617d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004617d5  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 004617da  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004617dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004617df  e824310200             -call 0x484908
    cpu.esp -= 4;
    sub_484908(app, cpu);
    if (cpu.terminate) return;
    // 004617e4  a3386b4c00             -mov dword ptr [0x4c6b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */) = cpu.eax;
    // 004617e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004617ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004617eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4617f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004617f0  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004617f7  7509                   -jne 0x461802
    if (!cpu.flags.zf)
    {
        goto L_0x00461802;
    }
    // 004617f9  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461800  7501                   -jne 0x461803
    if (!cpu.flags.zf)
    {
        goto L_0x00461803;
    }
L_0x00461802:
    // 00461802  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461803:
    // 00461803  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461805  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 0046180a  b800b00400             -mov eax, 0x4b000
    cpu.eax = 307200 /*0x4b000*/;
    // 0046180f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461811  e8f2300200             -call 0x484908
    cpu.esp -= 4;
    sub_484908(app, cpu);
    if (cpu.terminate) return;
    // 00461816  a3386b4c00             -mov dword ptr [0x4c6b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5008184) /* 0x4c6b38 */) = cpu.eax;
    // 0046181b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046181c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046181d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_461820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461820  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461821  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461822  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461823  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461824  81ec20010000           -sub esp, 0x120
    (cpu.esp) -= x86::reg32(x86::sreg32(288 /*0x120*/));
    // 0046182a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046182c  be00000800             -mov esi, 0x80000
    cpu.esi = 524288 /*0x80000*/;
    // 00461831  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00461833  8a251fe04d00           -mov ah, byte ptr [0x4de01f]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5103647) /* 0x4de01f */);
    // 00461839  89bc241c010000         -mov dword ptr [esp + 0x11c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.edi;
    // 00461840  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00461842  0f845b010000           -je 0x4619a3
    if (cpu.flags.zf)
    {
        goto L_0x004619a3;
    }
    // 00461848  803dacdf4d0000         +cmp byte ptr [0x4ddfac], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5103532) /* 0x4ddfac */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046184f  0f854e010000           -jne 0x4619a3
    if (!cpu.flags.zf)
    {
        goto L_0x004619a3;
    }
    // 00461855  833d7c2d4c0001         +cmp dword ptr [0x4c2d7c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992380) /* 0x4c2d7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046185c  7508                   -jne 0x461866
    if (!cpu.flags.zf)
    {
        goto L_0x00461866;
    }
    // 0046185e  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461861  7d03                   -jge 0x461866
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461866;
    }
    // 00461863  83c109                 -add ecx, 9
    (cpu.ecx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00461866:
    // 00461866  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461867  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461868  bdb8b64b00             -mov ebp, 0x4bb6b8
    cpu.ebp = 4961976 /*0x4bb6b8*/;
    // 0046186d  b85a010000             -mov eax, 0x15a
    cpu.eax = 346 /*0x15a*/;
    // 00461872  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00461874  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461876  a390844c00             -mov dword ptr [0x4c8490], eax
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.eax;
    // 0046187b  b8d4b64b00             -mov eax, 0x4bb6d4
    cpu.eax = 4962004 /*0x4bb6d4*/;
    // 00461880  892d8c844c00           -mov dword ptr [0x4c848c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebp;
    // 00461886  e8dd6d0100             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046188b  8b148d986b4c00         -mov edx, dword ptr [ecx*4 + 0x4c6b98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008280) /* 0x4c6b98 */ + cpu.ecx * 4);
    // 00461892  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461893  8b0d80e54d00           -mov ecx, dword ptr [0x4de580]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5105024) /* 0x4de580 */);
    // 00461899  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046189a  68dcb64b00             -push 0x4bb6dc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962012 /*0x4bb6dc*/;
    cpu.esp -= 4;
    // 0046189f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004618a1  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004618a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004618a6  e8768b0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004618ab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004618ae  8b1d64e54d00           -mov ebx, dword ptr [0x4de564]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104996) /* 0x4de564 */);
    // 004618b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004618b5  6890b64b00             -push 0x4bb690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4961936 /*0x4bb690*/;
    cpu.esp -= 4;
    // 004618ba  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004618c1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004618c2  e85a8b0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004618c7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004618ca  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004618ce  e89d820200             -call 0x489b70
    cpu.esp -= 4;
    sub_489b70(app, cpu);
    if (cpu.terminate) return;
    // 004618d3  89842420010000         -mov dword ptr [esp + 0x120], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 004618da  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004618e1  e88ab80100             -call 0x47d170
    cpu.esp -= 4;
    sub_47d170(app, cpu);
    if (cpu.terminate) return;
    // 004618e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004618e8  0f85c0000000           -jne 0x4619ae
    if (!cpu.flags.zf)
    {
        goto L_0x004619ae;
    }
L_0x004618ee:
    // 004618ee  8d8c2418010000         -lea ecx, [esp + 0x118]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 004618f5  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004618fc  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00461903  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00461907  e8089c0100             -call 0x47b514
    cpu.esp -= 4;
    sub_47b514(app, cpu);
    if (cpu.terminate) return;
    // 0046190c  8d8c241c010000         -lea ecx, [esp + 0x11c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00461913  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046191a  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00461921  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00461928  e8f79b0100             -call 0x47b524
    cpu.esp -= 4;
    sub_47b524(app, cpu);
    if (cpu.terminate) return;
L_0x0046192d:
    // 0046192d  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00461934  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00461936  39f0                   +cmp eax, esi
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
    // 00461938  7d0d                   -jge 0x461947
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461947;
    }
    // 0046193a  c784242401000001000000 -mov dword ptr [esp + 0x124], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = 1 /*0x1*/;
    // 00461945  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00461947:
    // 00461947  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0046194e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00461950  e8739d0100             -call 0x47b6c8
    cpu.esp -= 4;
    sub_47b6c8(app, cpu);
    if (cpu.terminate) return;
    // 00461955  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00461957  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 0046195e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00461960  e8539d0100             -call 0x47b6b8
    cpu.esp -= 4;
    sub_47b6b8(app, cpu);
    if (cpu.terminate) return;
    // 00461965  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0046196c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046196e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00461970  e84b9d0100             -call 0x47b6c0
    cpu.esp -= 4;
    sub_47b6c0(app, cpu);
    if (cpu.terminate) return;
    // 00461975  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0046197c  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046197e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461980  74ab                   -je 0x46192d
    if (cpu.flags.zf)
    {
        goto L_0x0046192d;
    }
    // 00461982  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00461989  e8229d0100             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0046198e  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00461995  e8169d0100             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 0046199a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046199c  e82b710100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004619a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004619a3:
    // 004619a3  81c420010000           +add esp, 0x120
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004619a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619ab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004619ae:
    // 004619ae  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004619b0  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004619b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004619b8  2eff155c554b00         -call dword ptr cs:[0x4b555c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937052) /* 0x4b555c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004619bf  e92affffff             -jmp 0x4618ee
    goto L_0x004618ee;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4619d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004619d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004619d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004619d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004619d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004619d4  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004619da  8b1564e54d00           -mov edx, dword ptr [0x4de564]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104996) /* 0x4de564 */);
    // 004619e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004619e1  6890b64b00             -push 0x4bb690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4961936 /*0x4bb690*/;
    cpu.esp -= 4;
    // 004619e6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004619ea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004619eb  e8318a0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004619f0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004619f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004619f5  be0000f000             -mov esi, 0xf00000
    cpu.esi = 15728640 /*0xf00000*/;
    // 004619fa  e871b70100             -call 0x47d170
    cpu.esp -= 4;
    sub_47d170(app, cpu);
    if (cpu.terminate) return;
    // 004619ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461a01  7545                   -jne 0x461a48
    if (!cpu.flags.zf)
    {
        goto L_0x00461a48;
    }
L_0x00461a03:
    // 00461a03  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00461a0a  8d9c2488000000         -lea ebx, [esp + 0x88]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00461a11  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00461a18  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00461a1a  e8059b0100             -call 0x47b524
    cpu.esp -= 4;
    sub_47b524(app, cpu);
    if (cpu.terminate) return;
    // 00461a1f  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00461a26  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00461a28  e8734cfeff             -call 0x4466a0
    cpu.esp -= 4;
    sub_4466a0(app, cpu);
    if (cpu.terminate) return;
    // 00461a2d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461a2f  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00461a36  e8759c0100             -call 0x47b6b0
    cpu.esp -= 4;
    sub_47b6b0(app, cpu);
    if (cpu.terminate) return;
    // 00461a3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461a3d  81c48c000000           +add esp, 0x8c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461a43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461a48:
    // 00461a48  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00461a4a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00461a4e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461a4f  2eff155c554b00         -call dword ptr cs:[0x4b555c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937052) /* 0x4b555c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00461a56  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00461a58  e8b19c0100             -call 0x47b70e
    cpu.esp -= 4;
    sub_47b70e(app, cpu);
    if (cpu.terminate) return;
    // 00461a5d  eba4                   -jmp 0x461a03
    goto L_0x00461a03;
}

/* align: skip 0x00 */
void Application::sub_461a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461a60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461a61  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00461a67  8b1564e54d00           -mov edx, dword ptr [0x4de564]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104996) /* 0x4de564 */);
    // 00461a6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461a6e  6890b64b00             -push 0x4bb690
    app->getMemory<x86::reg32>(cpu.esp-4) = 4961936 /*0x4bb690*/;
    cpu.esp -= 4;
    // 00461a73  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00461a77  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461a78  e8a4890100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00461a7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00461a80  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00461a82  e8e9b60100             -call 0x47d170
    cpu.esp -= 4;
    sub_47d170(app, cpu);
    if (cpu.terminate) return;
    // 00461a87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461a89  7508                   -jne 0x461a93
    if (!cpu.flags.zf)
    {
        goto L_0x00461a93;
    }
    // 00461a8b  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00461a91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461a93:
    // 00461a93  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461a94  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00461a96  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00461a9a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00461a9b  2eff155c554b00         -call dword ptr cs:[0x4b555c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937052) /* 0x4b555c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00461aa2  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00461aa6  e8639c0100             -call 0x47b70e
    cpu.esp -= 4;
    sub_47b70e(app, cpu);
    if (cpu.terminate) return;
    // 00461aab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461aac  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00461ab2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ab3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461ac0  833d902d4c0000         +cmp dword ptr [0x4c2d90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992400) /* 0x4c2d90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461ac7  0f85b39b0200           -jne 0x48b680
    if (!cpu.flags.zf)
    {
        return sub_48b680(app, cpu);
    }
    // 00461acd  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461ad4  0f85a69b0200           -jne 0x48b680
    if (!cpu.flags.zf)
    {
        return sub_48b680(app, cpu);
    }
    // 00461ada  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461ae0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461ae1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461ae2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461ae3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461ae4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00461ae6  8b3d902d4c00           -mov edi, dword ptr [0x4c2d90]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(4992400) /* 0x4c2d90 */);
    // 00461aec  8935406b4c00           -mov dword ptr [0x4c6b40], esi
    app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */) = cpu.esi;
    // 00461af2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00461af4  7445                   -je 0x461b3b
    if (cpu.flags.zf)
    {
        goto L_0x00461b3b;
    }
L_0x00461af6:
    // 00461af6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461af8  7558                   -jne 0x461b52
    if (!cpu.flags.zf)
    {
        goto L_0x00461b52;
    }
    // 00461afa  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461afc  7554                   -jne 0x461b52
    if (!cpu.flags.zf)
    {
        goto L_0x00461b52;
    }
    // 00461afe  81e308080000           -and ebx, 0x808
    cpu.ebx &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00461b04  81fb08080000           +cmp ebx, 0x808
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461b0a  743d                   -je 0x461b49
    if (cpu.flags.zf)
    {
        goto L_0x00461b49;
    }
L_0x00461b0c:
    // 00461b0c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461b11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00461b13:
    // 00461b13  e8189b0200             -call 0x48b630
    cpu.esp -= 4;
    sub_48b630(app, cpu);
    if (cpu.terminate) return;
    // 00461b18  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00461b1a:
    // 00461b1a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461b1c  0f8d9b000000           -jge 0x461bbd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461bbd;
    }
    // 00461b22  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461b24  890d942d4c00           -mov dword ptr [0x4c2d94], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */) = cpu.ecx;
    // 00461b2a  890db02d4c00           -mov dword ptr [0x4c2db0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992432) /* 0x4c2db0 */) = cpu.ecx;
    // 00461b30  890d902d4c00           -mov dword ptr [0x4c2d90], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992400) /* 0x4c2d90 */) = cpu.ecx;
    // 00461b36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461b3b:
    // 00461b3b  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461b42  75b2                   -jne 0x461af6
    if (!cpu.flags.zf)
    {
        goto L_0x00461af6;
    }
    // 00461b44  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b45  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461b49:
    // 00461b49  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461b4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00461b50  ebc1                   -jmp 0x461b13
    goto L_0x00461b13;
L_0x00461b52:
    // 00461b52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461b54  751c                   -jne 0x461b72
    if (!cpu.flags.zf)
    {
        goto L_0x00461b72;
    }
    // 00461b56  83fa01                 +cmp edx, 1
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
    // 00461b59  7517                   -jne 0x461b72
    if (!cpu.flags.zf)
    {
        goto L_0x00461b72;
    }
    // 00461b5b  81e304080000           -and ebx, 0x804
    cpu.ebx &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 00461b61  81fb04080000           +cmp ebx, 0x804
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461b67  75a3                   -jne 0x461b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00461b0c;
    }
    // 00461b69  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461b6e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00461b70  eba1                   -jmp 0x461b13
    goto L_0x00461b13;
L_0x00461b72:
    // 00461b72  83f801                 +cmp eax, 1
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
    // 00461b75  751b                   -jne 0x461b92
    if (!cpu.flags.zf)
    {
        goto L_0x00461b92;
    }
    // 00461b77  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461b79  7517                   -jne 0x461b92
    if (!cpu.flags.zf)
    {
        goto L_0x00461b92;
    }
    // 00461b7b  81e302080000           -and ebx, 0x802
    cpu.ebx &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00461b81  81fb02080000           +cmp ebx, 0x802
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461b87  7583                   -jne 0x461b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00461b0c;
    }
    // 00461b89  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461b8e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00461b90  eb81                   -jmp 0x461b13
    goto L_0x00461b13;
L_0x00461b92:
    // 00461b92  83f801                 +cmp eax, 1
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
    // 00461b95  7583                   -jne 0x461b1a
    if (!cpu.flags.zf)
    {
        goto L_0x00461b1a;
    }
    // 00461b97  39c2                   +cmp edx, eax
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
    // 00461b99  0f857bffffff           -jne 0x461b1a
    if (!cpu.flags.zf)
    {
        goto L_0x00461b1a;
    }
    // 00461b9f  81e301080000           -and ebx, 0x801
    cpu.ebx &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00461ba5  81fb01080000           +cmp ebx, 0x801
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461bab  0f855bffffff           -jne 0x461b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00461b0c;
    }
    // 00461bb1  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461bb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00461bb8  e956ffffff             -jmp 0x461b13
    goto L_0x00461b13;
L_0x00461bbd:
    // 00461bbd  e8aed6fcff             -call 0x42f270
    cpu.esp -= 4;
    sub_42f270(app, cpu);
    if (cpu.terminate) return;
    // 00461bc2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00461bc7  e830bd0100             -call 0x47d8fc
    cpu.esp -= 4;
    sub_47d8fc(app, cpu);
    if (cpu.terminate) return;
    // 00461bcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461bce  a3446b4c00             -mov dword ptr [0x4c6b44], eax
    app->getMemory<x86::reg32>(x86::reg32(5008196) /* 0x4c6b44 */) = cpu.eax;
    // 00461bd3  a3406b4c00             -mov dword ptr [0x4c6b40], eax
    app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */) = cpu.eax;
    // 00461bd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bdc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_461be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461be1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461be2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461be3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461be4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461be5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461be7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00461be9:
    // 00461be9  8982fc644d00           -mov dword ptr [edx + 0x4d64fc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5072124) /* 0x4d64fc */) = cpu.eax;
    // 00461bef  40                     -inc eax
    (cpu.eax)++;
    // 00461bf0  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00461bf3  83f809                 +cmp eax, 9
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
    // 00461bf6  7cf1                   -jl 0x461be9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461be9;
    }
    // 00461bf8  0fb63d1ee04d00         -movzx edi, byte ptr [0x4de01e]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5103646) /* 0x4de01e */));
    // 00461bff  8b35902d4c00           -mov esi, dword ptr [0x4c2d90]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(4992400) /* 0x4c2d90 */);
    // 00461c05  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461c07  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461c09  8a1ddfde4d00           -mov bl, byte ptr [0x4ddedf]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5103327) /* 0x4ddedf */);
    // 00461c0f  8915406b4c00           -mov dword ptr [0x4c6b40], edx
    app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */) = cpu.edx;
    // 00461c15  8a1521e04d00           -mov dl, byte ptr [0x4de021]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5103649) /* 0x4de021 */);
    // 00461c1b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00461c1d  7509                   -jne 0x461c28
    if (!cpu.flags.zf)
    {
        goto L_0x00461c28;
    }
    // 00461c1f  833d942d4c0000         +cmp dword ptr [0x4c2d94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461c26  7458                   -je 0x461c80
    if (cpu.flags.zf)
    {
        goto L_0x00461c80;
    }
L_0x00461c28:
    // 00461c28  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00461c2d  e8cabc0100             -call 0x47d8fc
    cpu.esp -= 4;
    sub_47d8fc(app, cpu);
    if (cpu.terminate) return;
    // 00461c32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00461c34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461c36  7557                   -jne 0x461c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00461c8f;
    }
    // 00461c38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00461c3a  7553                   -jne 0x461c8f
    if (!cpu.flags.zf)
    {
        goto L_0x00461c8f;
    }
    // 00461c3c  81e608080000           -and esi, 0x808
    cpu.esi &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00461c42  81fe08080000           +cmp esi, 0x808
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461c48  743c                   -je 0x461c86
    if (cpu.flags.zf)
    {
        goto L_0x00461c86;
    }
L_0x00461c4a:
    // 00461c4a  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461c4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00461c51:
    // 00461c51  e8da990200             -call 0x48b630
    cpu.esp -= 4;
    sub_48b630(app, cpu);
    if (cpu.terminate) return;
    // 00461c56  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00461c58:
    // 00461c58  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461c5a  0f8c8a000000           -jl 0x461cea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461cea;
    }
    // 00461c60  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00461c62  0f849c000000           -je 0x461d04
    if (cpu.flags.zf)
    {
        goto L_0x00461d04;
    }
    // 00461c68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00461c6a:
    // 00461c6a  e8e9bc0100             -call 0x47d958
    cpu.esp -= 4;
    sub_47d958(app, cpu);
    if (cpu.terminate) return;
    // 00461c6f  e8fcd5fcff             -call 0x42f270
    cpu.esp -= 4;
    sub_42f270(app, cpu);
    if (cpu.terminate) return;
    // 00461c74  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00461c76  a3446b4c00             -mov dword ptr [0x4c6b44], eax
    app->getMemory<x86::reg32>(x86::reg32(5008196) /* 0x4c6b44 */) = cpu.eax;
    // 00461c7b  a3406b4c00             -mov dword ptr [0x4c6b40], eax
    app->getMemory<x86::reg32>(x86::reg32(5008192) /* 0x4c6b40 */) = cpu.eax;
L_0x00461c80:
    // 00461c80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461c86:
    // 00461c86  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461c8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00461c8d  ebc2                   -jmp 0x461c51
    goto L_0x00461c51;
L_0x00461c8f:
    // 00461c8f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461c91  7518                   -jne 0x461cab
    if (!cpu.flags.zf)
    {
        goto L_0x00461cab;
    }
    // 00461c93  83fb01                 +cmp ebx, 1
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
    // 00461c96  7513                   -jne 0x461cab
    if (!cpu.flags.zf)
    {
        goto L_0x00461cab;
    }
    // 00461c98  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 00461c9d  3d04080000             +cmp eax, 0x804
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
    // 00461ca2  75a6                   -jne 0x461c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00461c4a;
    }
    // 00461ca4  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461ca9  eba6                   -jmp 0x461c51
    goto L_0x00461c51;
L_0x00461cab:
    // 00461cab  83fa01                 +cmp edx, 1
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
    // 00461cae  7517                   -jne 0x461cc7
    if (!cpu.flags.zf)
    {
        goto L_0x00461cc7;
    }
    // 00461cb0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00461cb2  7513                   -jne 0x461cc7
    if (!cpu.flags.zf)
    {
        goto L_0x00461cc7;
    }
    // 00461cb4  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00461cb9  3d02080000             +cmp eax, 0x802
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
    // 00461cbe  758a                   -jne 0x461c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00461c4a;
    }
    // 00461cc0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461cc5  eb8a                   -jmp 0x461c51
    goto L_0x00461c51;
L_0x00461cc7:
    // 00461cc7  83fa01                 +cmp edx, 1
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
    // 00461cca  758c                   -jne 0x461c58
    if (!cpu.flags.zf)
    {
        goto L_0x00461c58;
    }
    // 00461ccc  39d3                   +cmp ebx, edx
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
    // 00461cce  7588                   -jne 0x461c58
    if (!cpu.flags.zf)
    {
        goto L_0x00461c58;
    }
    // 00461cd0  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00461cd5  3d01080000             +cmp eax, 0x801
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
    // 00461cda  0f856affffff           -jne 0x461c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00461c4a;
    }
    // 00461ce0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461ce5  e967ffffff             -jmp 0x461c51
    goto L_0x00461c51;
L_0x00461cea:
    // 00461cea  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00461cec  890d942d4c00           -mov dword ptr [0x4c2d94], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992404) /* 0x4c2d94 */) = cpu.ecx;
    // 00461cf2  890db02d4c00           -mov dword ptr [0x4c2db0], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992432) /* 0x4c2db0 */) = cpu.ecx;
    // 00461cf8  890d902d4c00           -mov dword ptr [0x4c2d90], ecx
    app->getMemory<x86::reg32>(x86::reg32(4992400) /* 0x4c2d90 */) = cpu.ecx;
    // 00461cfe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461cff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d04:
    // 00461d04  b8ceffffff             -mov eax, 0xffffffce
    cpu.eax = 4294967246 /*0xffffffce*/;
    // 00461d09  e95cffffff             -jmp 0x461c6a
    goto L_0x00461c6a;
}

/* align: skip 0x00 0x00 */
void Application::sub_461d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461d11  8b153c6c4c00           -mov edx, dword ptr [0x4c6c3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 00461d17  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461d19  7502                   -jne 0x461d1d
    if (!cpu.flags.zf)
    {
        goto L_0x00461d1d;
    }
    // 00461d1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d1d:
    // 00461d1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461d1e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461d20  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461d22  e8a56d0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00461d27  890d3c6c4c00           -mov dword ptr [0x4c6c3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */) = cpu.ecx;
    // 00461d2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_461d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461d31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461d32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461d34  8b0d3c6c4c00           -mov ecx, dword ptr [0x4c6c3c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 00461d3a  8915406c4c00           -mov dword ptr [0x4c6c40], edx
    app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */) = cpu.edx;
    // 00461d40  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461d42  7403                   -je 0x461d47
    if (cpu.flags.zf)
    {
        goto L_0x00461d47;
    }
    // 00461d44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d47:
    // 00461d47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461d48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461d49  bbbcb74b00             -mov ebx, 0x4bb7bc
    cpu.ebx = 4962236 /*0x4bb7bc*/;
    // 00461d4e  beec020000             -mov esi, 0x2ec
    cpu.esi = 748 /*0x2ec*/;
    // 00461d53  baa08c0000             -mov edx, 0x8ca0
    cpu.edx = 36000 /*0x8ca0*/;
    // 00461d58  b8d8b74b00             -mov eax, 0x4bb7d8
    cpu.eax = 4962264 /*0x4bb7d8*/;
    // 00461d5d  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 00461d63  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461d65  893590844c00           -mov dword ptr [0x4c8490], esi
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 00461d6b  e810690100             -call 0x478680
    cpu.esp -= 4;
    sub_478680(app, cpu);
    if (cpu.terminate) return;
    // 00461d70  a33c6c4c00             -mov dword ptr [0x4c6c3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */) = cpu.eax;
    // 00461d75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d76  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d78  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461d82  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461d83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461d84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461d85  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00461d88  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00461d8c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00461d8e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00461d90  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00461d93  8b048528ce4d00         -mov eax, dword ptr [eax*4 + 0x4dce28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099048) /* 0x4dce28 */ + cpu.eax * 4);
    // 00461d9a  898210060000           -mov dword ptr [edx + 0x610], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 00461da0  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461da4  898288000000           -mov dword ptr [edx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00461daa  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00461dac  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00461daf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00461db6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461db8  8b0485e8ca4d00         -mov eax, dword ptr [eax*4 + 0x4dcae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5098216) /* 0x4dcae8 */ + cpu.eax * 4);
    // 00461dbf  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00461dc5  a1406c4c00             -mov eax, dword ptr [0x4c6c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 00461dca  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461dce  898618060000           -mov dword ptr [esi + 0x618], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00461dd4  898284000000           -mov dword ptr [edx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00461dda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461ddc  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00461de2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461de6  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00461dea  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
L_0x00461dee:
    // 00461dee  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00461df2  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00461df5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00461df9  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00461dfc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00461dff  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461e01  7522                   -jne 0x461e25
    if (!cpu.flags.zf)
    {
        goto L_0x00461e25;
    }
L_0x00461e03:
    // 00461e03  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00461e07  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00461e0b  41                     -inc ecx
    (cpu.ecx)++;
    // 00461e0c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461e0f  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00461e13  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00461e17  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461e1a  7cd2                   -jl 0x461dee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461dee;
    }
    // 00461e1c  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00461e1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461e25:
    // 00461e25  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00461e29  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00461e2d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461e2f  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00461e33  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00461e35  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00461e39  895c2440               -mov dword ptr [esp + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebx;
L_0x00461e3d:
    // 00461e3d  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461e41  0344243c               -add eax, dword ptr [esp + 0x3c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 00461e45  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00461e48  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00461e4c  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461e4f  7db2                   -jge 0x461e03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461e03;
    }
    // 00461e51  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00461e55  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461e58  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00461e5a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00461e5c  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 00461e5f  0f843d010000           -je 0x461fa2
    if (cpu.flags.zf)
    {
        goto L_0x00461fa2;
    }
    // 00461e65  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00461e67  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00461e6c  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00461e6f  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x00461e73:
    // 00461e73  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461e75  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00461e79  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00461e7d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461e7f  0f8e04010000           -jle 0x461f89
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461f89;
    }
    // 00461e85  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00461e89  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00461e8b  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00461e8f:
    // 00461e8f  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00461e92  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461e95  8a440708               -mov al, byte ptr [edi + eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 00461e99  88442418               -mov byte ptr [esp + 0x18], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.al;
    // 00461e9d  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00461ea0  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461ea3  8a440709               -mov al, byte ptr [edi + eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */ + cpu.eax * 1);
    // 00461ea7  88442419               -mov byte ptr [esp + 0x19], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.al;
    // 00461eab  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00461eae  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461eb1  8a44070a               -mov al, byte ptr [edi + eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */ + cpu.eax * 1);
    // 00461eb5  8844241a               -mov byte ptr [esp + 0x1a], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.al;
    // 00461eb9  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00461ebc  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461ebf  8a44070b               -mov al, byte ptr [edi + eax + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */ + cpu.eax * 1);
    // 00461ec3  8a5c2419               -mov bl, byte ptr [esp + 0x19]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00461ec7  8844241b               -mov byte ptr [esp + 0x1b], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = cpu.al;
    // 00461ecb  8a442430               -mov al, byte ptr [esp + 0x30]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00461ecf  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00461ed1  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 00461ed3  8874241c               -mov byte ptr [esp + 0x1c], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.dh;
    // 00461ed7  885c2419               -mov byte ptr [esp + 0x19], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.bl;
    // 00461edb  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00461ede  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461ee1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00461ee3  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00461ee5  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00461ee8  0f84f1000000           -je 0x461fdf
    if (cpu.flags.zf)
    {
        goto L_0x00461fdf;
    }
    // 00461eee  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00461ef1  0f84b8000000           -je 0x461faf
    if (cpu.flags.zf)
    {
        goto L_0x00461faf;
    }
    // 00461ef7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461efb  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00461eff  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00461f05  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00461f0b  e890170100             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00461f10  6b1d406c4c000c         -imul ebx, dword ptr [0x4c6c40], 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00461f17  a13c6c4c00             -mov eax, dword ptr [0x4c6c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 00461f1c  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x00461f21:
    // 00461f21  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461f23  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00461f27:
    // 00461f27  e8c8150100             -call 0x4734f4
    cpu.esp -= 4;
    sub_4734f4(app, cpu);
    if (cpu.terminate) return;
    // 00461f2c  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461f30  66a1406c4c00           -mov ax, word ptr [0x4c6c40]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 00461f36  668b9a84000000         -mov bx, word ptr [edx + 0x84]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00461f3d  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00461f41  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00461f45  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461f47  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00461f4a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461f4c  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00461f50  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00461f53  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00461f55  66894202               -mov word ptr [edx + 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00461f59  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00461f5d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00461f60  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00461f63  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00461f67  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00461f69  42                     -inc edx
    (cpu.edx)++;
    // 00461f6a  c6400100               -mov byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 00461f6e  a1406c4c00             -mov eax, dword ptr [0x4c6c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 00461f73  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00461f77  40                     -inc eax
    (cpu.eax)++;
    // 00461f78  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00461f7c  a3406c4c00             -mov dword ptr [0x4c6c40], eax
    app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */) = cpu.eax;
    // 00461f81  39ca                   +cmp edx, ecx
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
    // 00461f83  0f8c06ffffff           -jl 0x461e8f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461e8f;
    }
L_0x00461f89:
    // 00461f89  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00461f8d  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00461f91  47                     -inc edi
    (cpu.edi)++;
    // 00461f92  83c30c                 +add ebx, 0xc
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461f95  897c2440               -mov dword ptr [esp + 0x40], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edi;
    // 00461f99  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00461f9d  e99bfeffff             -jmp 0x461e3d
    goto L_0x00461e3d;
L_0x00461fa2:
    // 00461fa2  c744244801000000       -mov dword ptr [esp + 0x48], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
    // 00461faa  e9c4feffff             -jmp 0x461e73
    goto L_0x00461e73;
L_0x00461faf:
    // 00461faf  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461fb3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00461fb7  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00461fbd  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00461fc3  e8d8160100             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00461fc8  6b05406c4c000c         +imul eax, dword ptr [0x4c6c40], 0xc
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00461fcf  8b1d3c6c4c00           -mov ebx, dword ptr [0x4c6c3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 00461fd5  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00461fda  e942ffffff             -jmp 0x461f21
    goto L_0x00461f21;
L_0x00461fdf:
    // 00461fdf  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00461fe3  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00461fe7  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00461fed  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00461ff3  e8a8160100             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00461ff8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00461ffa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00461fff  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462003  e8ec140100             -call 0x4734f4
    cpu.esp -= 4;
    sub_4734f4(app, cpu);
    if (cpu.terminate) return;
    // 00462008  6b05406c4c000c         -imul eax, dword ptr [0x4c6c40], 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0046200f  8b1d3c6c4c00           -mov ebx, dword ptr [0x4c6c3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 00462015  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046201a  01c3                   +add ebx, eax
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
    // 0046201c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046201e  e904ffffff             -jmp 0x461f27
    goto L_0x00461f27;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462030  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462031  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462032  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462033  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00462036  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046203a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046203e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00462040  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00462043  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046204a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046204c  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046204f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00462053  8b8483e8ca4d00         -mov eax, dword ptr [ebx + eax*4 + 0x4dcae8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5098216) /* 0x4dcae8 */ + cpu.eax * 4);
    // 0046205a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046205c  898214060000           -mov dword ptr [edx + 0x614], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00462062  a1406c4c00             -mov eax, dword ptr [0x4c6c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 00462067  89831c060000           -mov dword ptr [ebx + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 0046206d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046206f  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00462075  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462079  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0046207d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00462081:
    // 00462081  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462085  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00462088  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046208c  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046208f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462092  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00462094  7534                   -jne 0x4620ca
    if (!cpu.flags.zf)
    {
        goto L_0x004620ca;
    }
L_0x00462096:
    // 00462096  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046209a  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046209e  47                     -inc edi
    (cpu.edi)++;
    // 0046209f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004620a2  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004620a6  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004620aa  83ff20                 +cmp edi, 0x20
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620ad  7cd2                   -jl 0x462081
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462081;
    }
    // 004620af  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004620b3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004620b7  8b801c060000           -mov eax, dword ptr [eax + 0x61c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1564) /* 0x61c */);
    // 004620bd  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 004620c3  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004620c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004620c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004620c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004620c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004620ca:
    // 004620ca  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004620ce  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004620d0  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004620d4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004620d7  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x004620db:
    // 004620db  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004620df  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004620e3  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004620e6  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004620ea  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620ed  7da7                   -jge 0x462096
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462096;
    }
    // 004620ef  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004620f2  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004620f5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004620f7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004620f9  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 004620fc  0f84bf000000           -je 0x4621c1
    if (cpu.flags.zf)
    {
        goto L_0x004621c1;
    }
    // 00462102  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00462104  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00462109  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0046210c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00462110:
    // 00462110  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00462114  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462116  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00462118  0f8e8c000000           -jle 0x4621aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004621aa;
    }
    // 0046211e  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x00462121:
    // 00462121  6b1d406c4c000c         -imul ebx, dword ptr [0x4c6c40], 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00462128  a13c6c4c00             -mov eax, dword ptr [0x4c6c3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 0046212d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00462131  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462133  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00462136  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046213a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046213d  8b9214060000           -mov edx, dword ptr [edx + 0x614]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */);
    // 00462143  668b440602             -mov ax, word ptr [esi + eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 00462148  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0046214d  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462151  038584000000           -add eax, dword ptr [ebp + 0x84]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(132) /* 0x84 */)));
    // 00462157  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00462159  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0046215c  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00462160  e81b150100             -call 0x473680
    cpu.esp -= 4;
    sub_473680(app, cpu);
    if (cpu.terminate) return;
    // 00462165  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00462169  66a1406c4c00           -mov ax, word ptr [0x4c6c40]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 0046216f  668b9a18060000         -mov bx, word ptr [edx + 0x618]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(1560) /* 0x618 */);
    // 00462176  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462178  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0046217b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046217d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00462180  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462182  6689540602             -mov word ptr [esi + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 00462187  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0046218a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046218d  c644060100             -mov byte ptr [esi + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00462192  a1406c4c00             -mov eax, dword ptr [0x4c6c40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */);
    // 00462197  41                     -inc ecx
    (cpu.ecx)++;
    // 00462198  40                     -inc eax
    (cpu.eax)++;
    // 00462199  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046219d  a3406c4c00             -mov dword ptr [0x4c6c40], eax
    app->getMemory<x86::reg32>(x86::reg32(5008448) /* 0x4c6c40 */) = cpu.eax;
    // 004621a2  39d1                   +cmp ecx, edx
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
    // 004621a4  0f8c77ffffff           -jl 0x462121
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462121;
    }
L_0x004621aa:
    // 004621aa  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004621ae  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004621b1  43                     -inc ebx
    (cpu.ebx)++;
    // 004621b2  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004621b5  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004621b9  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004621bc  e91affffff             -jmp 0x4620db
    goto L_0x004620db;
L_0x004621c1:
    // 004621c1  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004621c9  e942ffffff             -jmp 0x462110
    goto L_0x00462110;
}

/* align: skip 0x00 0x00 */
/* data blob: 30346377000000003132637700000000313863770000000032376377000000003338637700000000303463630000000031326363000000003138636300000000323763630000000033386363000000003030636300000000ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000ffffffff0000000000000000ffffffff0100000000000000000000000100000000000000000000000000000000000000 */
void Application::sub_462280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462281  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462282  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462283  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462284  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462285  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00462288  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046228a  8b354c6c4c00           -mov esi, dword ptr [0x4c6c4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 00462290  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 00462297  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00462299  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046229b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046229e  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 004622a3  8990b4095100           -mov dword ptr [eax + 0x5109b4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310900) /* 0x5109b4 */) = cpu.edx;
    // 004622a9  bb00095100             -mov ebx, 0x510900
    cpu.ebx = 5310720 /*0x510900*/;
    // 004622ae  8988b8095100           -mov dword ptr [eax + 0x5109b8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310904) /* 0x5109b8 */) = cpu.ecx;
    // 004622b4  8998d4095100           -mov dword ptr [eax + 0x5109d4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310932) /* 0x5109d4 */) = cpu.ebx;
    // 004622ba  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 004622bf  8990bc095100           -mov dword ptr [eax + 0x5109bc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310908) /* 0x5109bc */) = cpu.edx;
    // 004622c5  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004622c7  8990c0095100           -mov dword ptr [eax + 0x5109c0], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310912) /* 0x5109c0 */) = cpu.edx;
    // 004622cd  a14c6c4c00             -mov eax, dword ptr [0x4c6c4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 004622d2  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004622d6  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004622d9  0f8caf000000           -jl 0x46238e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046238e;
    }
    // 004622df  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004622e1:
    // 004622e1  a34c6c4c00             -mov dword ptr [0x4c6c4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */) = cpu.eax;
    // 004622e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004622e8  0f8ea6000000           -jle 0x462394
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462394;
    }
    // 004622ee  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004622f1:
    // 004622f1  6884075100             -push 0x510784
    app->getMemory<x86::reg32>(cpu.esp-4) = 5310340 /*0x510784*/;
    cpu.esp -= 4;
    // 004622f6  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004622fd  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 00462302  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00462304  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 00462309  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046230c  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 00462311  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462313  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462315  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00462319  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046231b  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046231f  e82c4a0000             -call 0x466d50
    cpu.esp -= 4;
    sub_466d50(app, cpu);
    if (cpu.terminate) return;
    // 00462324  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462328  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462329  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046232d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046232e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462332  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462336  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462337  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046233c  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00462341  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462342  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462346  bb61000000             -mov ebx, 0x61
    cpu.ebx = 97 /*0x61*/;
    // 0046234b  e8f089ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462350  6874075100             -push 0x510774
    app->getMemory<x86::reg32>(cpu.esp-4) = 5310324 /*0x510774*/;
    cpu.esp -= 4;
    // 00462355  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462359  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046235b  e8f0490000             -call 0x466d50
    cpu.esp -= 4;
    sub_466d50(app, cpu);
    if (cpu.terminate) return;
    // 00462360  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462364  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462365  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462369  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046236a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046236e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046236f  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462373  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462374  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462378  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046237a  e8c189ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046237f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462381  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462382  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462383  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00462385  83c418                 +add esp, 0x18
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
    // 00462388  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462389  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046238a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046238b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046238c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046238d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046238e:
    // 0046238e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046238f  e94dffffff             -jmp 0x4622e1
    goto L_0x004622e1;
L_0x00462394:
    // 00462394  be4f000000             -mov esi, 0x4f
    cpu.esi = 79 /*0x4f*/;
    // 00462399  e953ffffff             -jmp 0x4622f1
    goto L_0x004622f1;
}

/* align: skip 0x00 0x00 */
void Application::sub_4623a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004623a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004623a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004623a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004623a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004623a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004623a5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004623a8  8b154c6c4c00           -mov edx, dword ptr [0x4c6c4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 004623ae  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004623b0  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004623b7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004623b9  b9b4095100             -mov ecx, 0x5109b4
    cpu.ecx = 5310900 /*0x5109b4*/;
    // 004623be  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004623c1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004623c3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004623c6  8b0d7cd14d00           -mov ecx, dword ptr [0x4dd17c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 004623cc  83f903                 +cmp ecx, 3
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
    // 004623cf  0f84f7000000           -je 0x4624cc
    if (cpu.flags.zf)
    {
        goto L_0x004624cc;
    }
    // 004623d5  83f904                 +cmp ecx, 4
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
    // 004623d8  0f84ee000000           -je 0x4624cc
    if (cpu.flags.zf)
    {
        goto L_0x004624cc;
    }
    // 004623de  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004623e1  0f8c86010000           -jl 0x46256d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046256d;
    }
    // 004623e7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004623e9:
    // 004623e9  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004623f0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004623f2  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 004623f7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004623fa  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004623fc  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00462403  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462405  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 0046240a  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00462411  bde8085100             -mov ebp, 0x5108e8
    cpu.ebp = 5310696 /*0x5108e8*/;
    // 00462416  893c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], edi
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.edi;
    // 0046241d  8b0de8085100           -mov ecx, dword ptr [0x5108e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5310696) /* 0x5108e8 */);
    // 00462423  892c85d4095100         -mov dword ptr [eax*4 + 0x5109d4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.ebp;
    // 0046242a  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046242d  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00462430  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00462433  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 0046243a  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046243d  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00462440  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00462443  890c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ecx;
    // 0046244a  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046244d  0f8c22010000           -jl 0x462575
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462575;
    }
    // 00462453  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462455:
    // 00462455  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462457  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046245a  0f8c1d010000           -jl 0x46257d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046257d;
    }
    // 00462460  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462462:
    // 00462462  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462464  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00462467  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00462469  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 0046246e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462471  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462473  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046247a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046247c  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00462481  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00462488  890c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.ecx;
    // 0046248f  bef4085100             -mov esi, 0x5108f4
    cpu.esi = 5310708 /*0x5108f4*/;
    // 00462494  8b0df4085100           -mov ecx, dword ptr [0x5108f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5310708) /* 0x5108f4 */);
    // 0046249a  893485d4095100         -mov dword ptr [eax*4 + 0x5109d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.esi;
    // 004624a1  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004624a4  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 004624a7  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 004624aa  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 004624b1  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004624b4  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004624b7  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 004624ba  890c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ecx;
    // 004624c1  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004624c4  0f8cb9000000           -jl 0x462583
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462583;
    }
    // 004624ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004624cc:
    // 004624cc  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
    // 004624d1  8b3580d14d00           -mov esi, dword ptr [0x4dd180]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */);
    // 004624d7  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004624de  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004624e0  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 004624e3  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004624ea  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004624ed  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004624ef  89b9b4095100           -mov dword ptr [ecx + 0x5109b4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310900) /* 0x5109b4 */) = cpu.edi;
    // 004624f5  be4c085100             -mov esi, 0x51084c
    cpu.esi = 5310540 /*0x51084c*/;
    // 004624fa  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004624fd  89a9b8095100           -mov dword ptr [ecx + 0x5109b8], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310904) /* 0x5109b8 */) = cpu.ebp;
    // 00462503  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462505  8b804c085100           -mov eax, dword ptr [eax + 0x51084c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310540) /* 0x51084c */);
    // 0046250b  89b1d4095100           -mov dword ptr [ecx + 0x5109d4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310932) /* 0x5109d4 */) = cpu.esi;
    // 00462511  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00462514  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00462517  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046251a  89b1bc095100           -mov dword ptr [ecx + 0x5109bc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310908) /* 0x5109bc */) = cpu.esi;
    // 00462520  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00462523  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00462526  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00462529  8981c0095100           -mov dword ptr [ecx + 0x5109c0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310912) /* 0x5109c0 */) = cpu.eax;
    // 0046252f  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462532  7c55                   -jl 0x462589
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462589;
    }
    // 00462534  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462536:
    // 00462536  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462538  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046253a  7e52                   -jle 0x46258e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046258e;
    }
    // 0046253c  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0046253f:
    // 0046253f  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00462546  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00462548  b9b4095100             -mov ecx, 0x5109b4
    cpu.ecx = 5310900 /*0x5109b4*/;
    // 0046254d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462550  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462552  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462554  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00462556  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046255a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046255b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046255c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046255e  89154c6c4c00           -mov dword ptr [0x4c6c4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */) = cpu.edx;
    // 00462564  83c408                 +add esp, 8
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
    // 00462567  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462568  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462569  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046256a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046256b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046256c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046256d:
    // 0046256d  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00462570  e974feffff             -jmp 0x4623e9
    goto L_0x004623e9;
L_0x00462575:
    // 00462575  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00462578  e9d8feffff             -jmp 0x462455
    goto L_0x00462455;
L_0x0046257d:
    // 0046257d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046257e  e9dffeffff             -jmp 0x462462
    goto L_0x00462462;
L_0x00462583:
    // 00462583  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00462584  e943ffffff             -jmp 0x4624cc
    goto L_0x004624cc;
L_0x00462589:
    // 00462589  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046258c  eba8                   -jmp 0x462536
    goto L_0x00462536;
L_0x0046258e:
    // 0046258e  b94f000000             -mov ecx, 0x4f
    cpu.ecx = 79 /*0x4f*/;
    // 00462593  ebaa                   -jmp 0x46253f
    goto L_0x0046253f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4625a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004625a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004625a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004625a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004625a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004625a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004625a5  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004625a8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004625aa  ba74075100             -mov edx, 0x510774
    cpu.edx = 5310324 /*0x510774*/;
    // 004625af  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004625b1  a164085100             -mov eax, dword ptr [0x510864]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310564) /* 0x510864 */);
    // 004625b6  e8150d0000             -call 0x4632d0
    cpu.esp -= 4;
    sub_4632d0(app, cpu);
    if (cpu.terminate) return;
    // 004625bb  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 004625c0  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004625c4  ba84075100             -mov edx, 0x510784
    cpu.edx = 5310340 /*0x510784*/;
    // 004625c9  e8120b0000             -call 0x4630e0
    cpu.esp -= 4;
    sub_4630e0(app, cpu);
    if (cpu.terminate) return;
    // 004625ce  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004625d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004625d4  e8f70c0000             -call 0x4632d0
    cpu.esp -= 4;
    sub_4632d0(app, cpu);
    if (cpu.terminate) return;
    // 004625d9  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004625dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004625de  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004625e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004625e3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004625e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004625e8  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004625ec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004625ed  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004625f1  e84a87ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004625f6  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004625fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004625fb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004625ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462600  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462604  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462605  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462609  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046260a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046260e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00462610  e82b87ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462615  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462617  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462618  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462619  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046261b  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046261e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046261f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462620  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462621  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462622  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462623  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462632  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462633  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462635  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00462638  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046263a  a100d14d00             -mov eax, dword ptr [0x4dd100]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099776) /* 0x4dd100 */);
    // 0046263f  8b3530d14d00           -mov esi, dword ptr [0x4dd130]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099824) /* 0x4dd130 */);
    // 00462645  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462648  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046264a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046264c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046264e  882518155100           -mov byte ptr [0x511518], ah
    app->getMemory<x86::reg8>(x86::reg32(5313816) /* 0x511518 */) = cpu.ah;
    // 00462654  e84731feff             -call 0x4457a0
    cpu.esp -= 4;
    sub_4457a0(app, cpu);
    if (cpu.terminate) return;
    // 00462659  833d70d14d0000         +cmp dword ptr [0x4dd170], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099888) /* 0x4dd170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462660  752f                   -jne 0x462691
    if (!cpu.flags.zf)
    {
        goto L_0x00462691;
    }
L_0x00462662:
    // 00462662  833df414510000         +cmp dword ptr [0x5114f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462669  740e                   -je 0x462679
    if (cpu.flags.zf)
    {
        goto L_0x00462679;
    }
    // 0046266b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046266d  89357c665100           -mov dword ptr [0x51667c], esi
    app->getMemory<x86::reg32>(x86::reg32(5334652) /* 0x51667c */) = cpu.esi;
    // 00462673  8935f4145100           -mov dword ptr [0x5114f4], esi
    app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */) = cpu.esi;
L_0x00462679:
    // 00462679  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046267b  e87087ffff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 00462680  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462682  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00462684  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462685  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462686  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00462688  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046268b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046268c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046268d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046268e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046268f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462690  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462691:
    // 00462691  833d7cd14d0000         +cmp dword ptr [0x4dd17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462698  7cc8                   -jl 0x462662
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462662;
    }
    // 0046269a  a180d14d00             -mov eax, dword ptr [0x4dd180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */);
    // 0046269f  e81c140000             -call 0x463ac0
    cpu.esp -= 4;
    sub_463ac0(app, cpu);
    if (cpu.terminate) return;
    // 004626a4  8b3d7cd14d00           -mov edi, dword ptr [0x4dd17c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 004626aa  a380d14d00             -mov dword ptr [0x4dd180], eax
    app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */) = cpu.eax;
    // 004626af  83ff04                 +cmp edi, 4
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
    // 004626b2  740a                   -je 0x4626be
    if (cpu.flags.zf)
    {
        goto L_0x004626be;
    }
    // 004626b4  e897110000             -call 0x463850
    cpu.esp -= 4;
    sub_463850(app, cpu);
    if (cpu.terminate) return;
    // 004626b9  e892100000             -call 0x463750
    cpu.esp -= 4;
    sub_463750(app, cpu);
    if (cpu.terminate) return;
L_0x004626be:
    // 004626be  833df414510000         +cmp dword ptr [0x5114f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004626c5  0f84f2000000           -je 0x4627bd
    if (cpu.flags.zf)
    {
        goto L_0x004627bd;
    }
    // 004626cb  3b35fc145100           +cmp esi, dword ptr [0x5114fc]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5313788) /* 0x5114fc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004626d1  0f85e6000000           -jne 0x4627bd
    if (!cpu.flags.zf)
    {
        goto L_0x004627bd;
    }
    // 004626d7  8b0d80d14d00           -mov ecx, dword ptr [0x4dd180]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */);
    // 004626dd  a1f8145100             -mov eax, dword ptr [0x5114f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313784) /* 0x5114f8 */);
    // 004626e2  39c8                   +cmp eax, ecx
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
    // 004626e4  7542                   -jne 0x462728
    if (!cpu.flags.zf)
    {
        goto L_0x00462728;
    }
    // 004626e6  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004626e8  8b0d7cd14d00           -mov ecx, dword ptr [0x4dd17c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 004626ee  a300155100             -mov dword ptr [0x511500], eax
    app->getMemory<x86::reg32>(x86::reg32(5313792) /* 0x511500 */) = cpu.eax;
    // 004626f3  83f904                 +cmp ecx, 4
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
    // 004626f6  7518                   -jne 0x462710
    if (!cpu.flags.zf)
    {
        goto L_0x00462710;
    }
    // 004626f8  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004626fa  e861010000             -call 0x462860
    cpu.esp -= 4;
    sub_462860(app, cpu);
    if (cpu.terminate) return;
    // 004626ff  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462701  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00462703  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462704  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462705  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00462707  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046270a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046270b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046270c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046270d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046270e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046270f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462710:
    // 00462710  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462712  e809080000             -call 0x462f20
    cpu.esp -= 4;
    sub_462f20(app, cpu);
    if (cpu.terminate) return;
    // 00462717  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462719  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046271b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046271c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046271d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046271f  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00462722  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462723  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462724  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462725  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462726  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462727  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462728:
    // 00462728  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046272d  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462731  890df8145100           -mov dword ptr [0x5114f8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5313784) /* 0x5114f8 */) = cpu.ecx;
    // 00462737  891d00155100           -mov dword ptr [0x511500], ebx
    app->getMemory<x86::reg32>(x86::reg32(5313792) /* 0x511500 */) = cpu.ebx;
    // 0046273d  e85efeffff             -call 0x4625a0
    cpu.esp -= 4;
    sub_4625a0(app, cpu);
    if (cpu.terminate) return;
    // 00462742  833d7cd14d0004         +cmp dword ptr [0x4dd17c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462749  7567                   -jne 0x4627b2
    if (!cpu.flags.zf)
    {
        goto L_0x004627b2;
    }
L_0x0046274b:
    // 0046274b  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046274f  e8dc010000             -call 0x462930
    cpu.esp -= 4;
    sub_462930(app, cpu);
    if (cpu.terminate) return;
L_0x00462754:
    // 00462754  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00462758  e843fcffff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 0046275d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462761  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462762  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462766  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462767  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046276b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046276c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462770  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462771  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00462775  e8c685ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046277a  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046277e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046277f  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00462783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462784  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462788  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462789  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046278d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046278e  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00462792  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462796  e8a585ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046279b  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046279f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004627a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004627a1  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004627a3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004627a5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004627a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004627a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004627a9  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004627ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004627b2:
    // 004627b2  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004627b6  e8e50b0000             -call 0x4633a0
    cpu.esp -= 4;
    sub_4633a0(app, cpu);
    if (cpu.terminate) return;
    // 004627bb  eb97                   -jmp 0x462754
    goto L_0x00462754;
L_0x004627bd:
    // 004627bd  a180d14d00             -mov eax, dword ptr [0x4dd180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */);
    // 004627c2  8935fc145100           -mov dword ptr [0x5114fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5313788) /* 0x5114fc */) = cpu.esi;
    // 004627c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004627ca  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004627ce  890d7c665100           -mov dword ptr [0x51667c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5334652) /* 0x51667c */) = cpu.ecx;
    // 004627d4  a3f8145100             -mov dword ptr [0x5114f8], eax
    app->getMemory<x86::reg32>(x86::reg32(5313784) /* 0x5114f8 */) = cpu.eax;
    // 004627d9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004627de  890df4145100           -mov dword ptr [0x5114f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */) = cpu.ecx;
    // 004627e4  e8e70e0000             -call 0x4636d0
    cpu.esp -= 4;
    sub_4636d0(app, cpu);
    if (cpu.terminate) return;
    // 004627e9  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 004627ee  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004627f2  e8e9080000             -call 0x4630e0
    cpu.esp -= 4;
    sub_4630e0(app, cpu);
    if (cpu.terminate) return;
    // 004627f7  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004627fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004627fc  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462800  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462801  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462805  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462806  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046280a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046280b  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046280f  e82c85ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462814  833d74d14d0000         +cmp dword ptr [0x4dd174], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099892) /* 0x4dd174 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046281b  7426                   -je 0x462843
    if (cpu.flags.zf)
    {
        goto L_0x00462843;
    }
    // 0046281d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462821  e85a050000             -call 0x462d80
    cpu.esp -= 4;
    sub_462d80(app, cpu);
    if (cpu.terminate) return;
    // 00462826  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046282a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046282b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046282f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462830  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462835  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462839  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046283a  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046283e  e8fd84ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
L_0x00462843:
    // 00462843  833d7cd14d0004         +cmp dword ptr [0x4dd17c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046284a  0f84fbfeffff           -je 0x46274b
    if (cpu.flags.zf)
    {
        goto L_0x0046274b;
    }
    // 00462850  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462854  e8470b0000             -call 0x4633a0
    cpu.esp -= 4;
    sub_4633a0(app, cpu);
    if (cpu.terminate) return;
    // 00462859  e9f6feffff             -jmp 0x462754
    goto L_0x00462754;
}

/* align: skip 0x00 0x00 */
void Application::sub_462860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462864  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462865  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00462868  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046286a  ba74075100             -mov edx, 0x510774
    cpu.edx = 5310324 /*0x510774*/;
    // 0046286f  b8fc065100             -mov eax, 0x5106fc
    cpu.eax = 5310204 /*0x5106fc*/;
    // 00462874  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462876  e8d50a0000             -call 0x463350
    cpu.esp -= 4;
    sub_463350(app, cpu);
    if (cpu.terminate) return;
    // 0046287b  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00462880  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462884  e857080000             -call 0x4630e0
    cpu.esp -= 4;
    sub_4630e0(app, cpu);
    if (cpu.terminate) return;
    // 00462889  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046288d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046288e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462892  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462893  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462897  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462898  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046289c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046289d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004628a1  e89a84ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004628a6  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004628aa  e881000000             -call 0x462930
    cpu.esp -= 4;
    sub_462930(app, cpu);
    if (cpu.terminate) return;
    // 004628af  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004628b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628b8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004628b9  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004628be  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004628c3  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004628c7  e87484ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004628cc  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004628d0  e8cbfaffff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 004628d5  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004628da  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004628df  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004628e4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004628e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004628e9  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004628ed  ba84075100             -mov edx, 0x510784
    cpu.edx = 5310340 /*0x510784*/;
    // 004628f2  e84984ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004628f7  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004628fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004628fd  e8ce090000             -call 0x4632d0
    cpu.esp -= 4;
    sub_4632d0(app, cpu);
    if (cpu.terminate) return;
    // 00462902  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462906  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462907  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046290b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046290c  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462910  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462911  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462915  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462916  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046291a  e82184ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046291f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462921  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00462923  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462924  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462925  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462927  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046292a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046292b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046292c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046292d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046292e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046292f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_462930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462933  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462934  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462935  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 0046293b  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046293d  bb60d14d00             -mov ebx, 0x4dd160
    cpu.ebx = 5099872 /*0x4dd160*/;
    // 00462942  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462944  ba54d14d00             -mov edx, 0x4dd154
    cpu.edx = 5099860 /*0x4dd154*/;
    // 00462949  e8a254fdff             -call 0x437df0
    cpu.esp -= 4;
    sub_437df0(app, cpu);
    if (cpu.terminate) return;
    // 0046294e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00462950  e82bd1fdff             -call 0x43fa80
    cpu.esp -= 4;
    sub_43fa80(app, cpu);
    if (cpu.terminate) return;
    // 00462955  6888d14d00             -push 0x4dd188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5099912 /*0x4dd188*/;
    cpu.esp -= 4;
    // 0046295a  6884d14d00             -push 0x4dd184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5099908 /*0x4dd184*/;
    cpu.esp -= 4;
    // 0046295f  b95cd14d00             -mov ecx, 0x4dd15c
    cpu.ecx = 5099868 /*0x4dd15c*/;
    // 00462964  bb58d14d00             -mov ebx, 0x4dd158
    cpu.ebx = 5099864 /*0x4dd158*/;
    // 00462969  6880d14d00             -push 0x4dd180
    app->getMemory<x86::reg32>(cpu.esp-4) = 5099904 /*0x4dd180*/;
    cpu.esp -= 4;
    // 0046296e  ba50d14d00             -mov edx, 0x4dd150
    cpu.edx = 5099856 /*0x4dd150*/;
    // 00462973  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00462975  e8a6d7fdff             -call 0x440120
    cpu.esp -= 4;
    sub_440120(app, cpu);
    if (cpu.terminate) return;
    // 0046297a  a180d14d00             -mov eax, dword ptr [0x4dd180]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */);
    // 0046297f  8db42400010000         -lea esi, [esp + 0x100]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462986  e835110000             -call 0x463ac0
    cpu.esp -= 4;
    sub_463ac0(app, cpu);
    if (cpu.terminate) return;
    // 0046298b  a380d14d00             -mov dword ptr [0x4dd180], eax
    app->getMemory<x86::reg32>(x86::reg32(5099904) /* 0x4dd180 */) = cpu.eax;
    // 00462990  e85b010000             -call 0x462af0
    cpu.esp -= 4;
    sub_462af0(app, cpu);
    if (cpu.terminate) return;
    // 00462995  a158d14d00             -mov eax, dword ptr [0x4dd158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099864) /* 0x4dd158 */);
    // 0046299a  8a802c6d4c00           -mov al, byte ptr [eax + 0x4c6d2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5008684) /* 0x4c6d2c */);
    // 004629a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004629a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004629a6  6888b84b00             -push 0x4bb888
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962440 /*0x4bb888*/;
    cpu.esp -= 4;
    // 004629ab  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004629af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004629b0  8db42414010000         -lea esi, [esp + 0x114]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004629b7  e8657a0100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004629bc  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004629c0  8b1db8075100           -mov ebx, dword ptr [0x5107b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310392) /* 0x5107b8 */);
    // 004629c6  8b15b4075100           -mov edx, dword ptr [0x5107b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310388) /* 0x5107b4 */);
    // 004629cc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004629cf  e81c020000             -call 0x462bf0
    cpu.esp -= 4;
    sub_462bf0(app, cpu);
    if (cpu.terminate) return;
    // 004629d4  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004629db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004629dc  8b8c240c010000         -mov ecx, dword ptr [esp + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004629e3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004629e4  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004629eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004629ec  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 004629f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004629f4  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004629fb  e84083ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462a00  8b155cd14d00           -mov edx, dword ptr [0x4dd15c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099868) /* 0x4dd15c */);
    // 00462a06  a124d14d00             -mov eax, dword ptr [0x4dd124]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099812) /* 0x4dd124 */);
    // 00462a0b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00462a0d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00462a10  c1e810                 +shr eax, 0x10
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
    // 00462a13  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00462a15  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462a17  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00462a1a  c1e210                 +shl edx, 0x10
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
    // 00462a1d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00462a1f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00462a22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462a23  688cb84b00             -push 0x4bb88c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962444 /*0x4bb88c*/;
    cpu.esp -= 4;
    // 00462a28  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462a2c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462a2d  e8ef790100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00462a32  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462a35  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00462a37  8db42408010000         -lea esi, [esp + 0x108]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 00462a3e  8b1d40085100           -mov ebx, dword ptr [0x510840]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310528) /* 0x510840 */);
    // 00462a44  8b153c085100           -mov edx, dword ptr [0x51083c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310524) /* 0x51083c */);
    // 00462a4a  e8a1010000             -call 0x462bf0
    cpu.esp -= 4;
    sub_462bf0(app, cpu);
    if (cpu.terminate) return;
    // 00462a4f  8bbc240c010000         -mov edi, dword ptr [esp + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462a56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462a57  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462a5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462a5f  8b94240c010000         -mov edx, dword ptr [esp + 0x10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462a66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462a67  8b8c240c010000         -mov ecx, dword ptr [esp + 0x10c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462a6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462a6f  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00462a76  e8c582ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462a7b  6a3e                   -push 0x3e
    app->getMemory<x86::reg32>(cpu.esp-4) = 62 /*0x3e*/;
    cpu.esp -= 4;
    // 00462a7d  6890b84b00             -push 0x4bb890
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962448 /*0x4bb890*/;
    cpu.esp -= 4;
    // 00462a82  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462a86  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462a87  8db42414010000         -lea esi, [esp + 0x114]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00462a8e  e88e790100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00462a93  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462a97  8b1d48085100           -mov ebx, dword ptr [0x510848]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310536) /* 0x510848 */);
    // 00462a9d  8b1544085100           -mov edx, dword ptr [0x510844]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310532) /* 0x510844 */);
    // 00462aa3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462aa6  e845010000             -call 0x462bf0
    cpu.esp -= 4;
    sub_462bf0(app, cpu);
    if (cpu.terminate) return;
    // 00462aab  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462ab2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462ab3  8bb4240c010000         -mov esi, dword ptr [esp + 0x10c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462aba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462abb  8bbc240c010000         -mov edi, dword ptr [esp + 0x10c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462ac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462ac3  8b84240c010000         -mov eax, dword ptr [esp + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462aca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462acb  8db42410010000         -lea esi, [esp + 0x110]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00462ad2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00462ad4  e86782ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462ad9  8db42400010000         -lea esi, [esp + 0x100]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462ae0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462ae1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462ae2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00462ae4  81c410010000           -add esp, 0x110
    (cpu.esp) += x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00462aea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462aeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462aec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462aed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462aee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462aef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_462af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462af0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462af1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462af2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462af3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462af4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462af7  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00462af9  8b152c065100           -mov edx, dword ptr [0x51062c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5309996) /* 0x51062c */);
    // 00462aff  8b3524065100           -mov esi, dword ptr [0x510624]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5309988) /* 0x510624 */);
    // 00462b05  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00462b07  8b1550d14d00           -mov edx, dword ptr [0x4dd150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099856) /* 0x4dd150 */);
    // 00462b0d  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00462b10  8b0d54d14d00           -mov ecx, dword ptr [0x4dd154]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099860) /* 0x4dd154 */);
    // 00462b16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00462b18  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00462b1b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00462b1d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462b1f  39f0                   +cmp eax, esi
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
    // 00462b21  7e02                   -jle 0x462b25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462b25;
    }
    // 00462b23  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00462b25:
    // 00462b25  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462b27  7d02                   -jge 0x462b2b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462b2b;
    }
    // 00462b29  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00462b2b:
    // 00462b2b  e8f081ffff             -call 0x45ad20
    cpu.esp -= 4;
    sub_45ad20(app, cpu);
    if (cpu.terminate) return;
    // 00462b30  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00462b35  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b39  e89281ffff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 00462b3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462b40  0f8484000000           -je 0x462bca
    if (cpu.flags.zf)
    {
        goto L_0x00462bca;
    }
    // 00462b46  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b4a  c7400403000000         -mov dword ptr [eax + 4], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
    // 00462b51  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b55  c6402d80               -mov byte ptr [eax + 0x2d], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */) = 128 /*0x80*/;
    // 00462b59  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b5d  c6402e80               -mov byte ptr [eax + 0x2e], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */) = 128 /*0x80*/;
    // 00462b61  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b65  c6402f80               -mov byte ptr [eax + 0x2f], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */) = 128 /*0x80*/;
    // 00462b69  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b6d  c74028a8095100         -mov dword ptr [eax + 0x28], 0x5109a8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 5310888 /*0x5109a8*/;
    // 00462b74  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b78  a12c065100             -mov eax, dword ptr [0x51062c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5309996) /* 0x51062c */);
    // 00462b7d  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00462b80  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b84  a130065100             -mov eax, dword ptr [0x510630]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310000) /* 0x510630 */);
    // 00462b89  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00462b8c  8b352c065100           -mov esi, dword ptr [0x51062c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5309996) /* 0x51062c */);
    // 00462b92  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b96  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00462b98  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00462b9b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462b9f  8b1530065100           -mov edx, dword ptr [0x510630]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310000) /* 0x510630 */);
    // 00462ba5  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00462ba8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462bac  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00462baf  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462bb3  8b1528065100           -mov edx, dword ptr [0x510628]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5309992) /* 0x510628 */);
    // 00462bb9  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00462bbc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462bc0  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00462bc3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462bc7  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
L_0x00462bca:
    // 00462bca  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462bcc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00462bce  e8bd80ffff             -call 0x45ac90
    cpu.esp -= 4;
    sub_45ac90(app, cpu);
    if (cpu.terminate) return;
    // 00462bd3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462bd5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462bd6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462bd7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00462bd9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462bdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bdd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bde  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bdf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462be0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462bf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462bf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462bf3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00462bf6  8b2d4c6c4c00           -mov ebp, dword ptr [0x4c6c4c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 00462bfc  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00462c00  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00462c04  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00462c08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00462c0a  8d04ed00000000         -lea eax, [ebp*8]
    cpu.eax = x86::reg32(cpu.ebp * 8);
    // 00462c11  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00462c13  bab4095100             -mov edx, 0x5109b4
    cpu.edx = 5310900 /*0x5109b4*/;
    // 00462c18  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462c1b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00462c1d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462c1f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462c21  49                     -dec ecx
    (cpu.ecx)--;
    // 00462c22  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00462c24  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462c26  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00462c28  49                     -dec ecx
    (cpu.ecx)--;
    // 00462c29  8b2d4c6c4c00           -mov ebp, dword ptr [0x4c6c4c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 00462c2f  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00462c32  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00462c35  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00462c37  0f8c8e000000           -jl 0x462ccb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462ccb;
    }
    // 00462c3d  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x00462c40:
    // 00462c40  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 00462c42  80fc4e                 +cmp ah, 0x4e
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462c45  0f85d6000000           -jne 0x462d21
    if (!cpu.flags.zf)
    {
        goto L_0x00462d21;
    }
    // 00462c4b  b884095100             -mov eax, 0x510984
    cpu.eax = 5310852 /*0x510984*/;
L_0x00462c50:
    // 00462c50  83fd4f                 +cmp ebp, 0x4f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462c53  0f8cfa000000           -jl 0x462d53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462d53;
    }
    // 00462c59  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00462c5b:
    // 00462c5b  6bc924                 -imul ecx, ecx, 0x24
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00462c5e  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 00462c63  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00462c65  6bcd24                 -imul ecx, ebp, 0x24
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00462c68  89b1b4095100           -mov dword ptr [ecx + 0x5109b4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310900) /* 0x5109b4 */) = cpu.esi;
    // 00462c6e  8981d4095100           -mov dword ptr [ecx + 0x5109d4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310932) /* 0x5109d4 */) = cpu.eax;
    // 00462c74  c781b809510014000000   -mov dword ptr [ecx + 0x5109b8], 0x14
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310904) /* 0x5109b8 */) = 20 /*0x14*/;
    // 00462c7e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00462c80  8b7602                 -mov esi, dword ptr [esi + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00462c83  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00462c86  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00462c8a  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462c8e  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462c92  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00462c94  89b1bc095100           -mov dword ptr [ecx + 0x5109bc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310908) /* 0x5109bc */) = cpu.esi;
    // 00462c9a  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462c9e  89b1c0095100           -mov dword ptr [ecx + 0x5109c0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5310912) /* 0x5109c0 */) = cpu.esi;
    // 00462ca4  83fd4f                 +cmp ebp, 0x4f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462ca7  0f8cae000000           -jl 0x462d5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462d5b;
    }
    // 00462cad  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00462caf:
    // 00462caf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00462cb1  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00462cb4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462cb8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00462cbb  4a                     -dec edx
    (cpu.edx)--;
    // 00462cbc  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00462cbe  4b                     -dec ebx
    (cpu.ebx)--;
    // 00462cbf  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00462cc3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00462cc5  0f8d75ffffff           -jge 0x462c40
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462c40;
    }
L_0x00462ccb:
    // 00462ccb  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00462ccd  0f8e8e000000           -jle 0x462d61
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462d61;
    }
    // 00462cd3  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
L_0x00462cd6:
    // 00462cd6  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00462cdd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462cdf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462ce1  891c85b4095100         -mov dword ptr [eax*4 + 0x5109b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.ebx;
    // 00462ce8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00462cea  0f8e7b000000           -jle 0x462d6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462d6b;
    }
    // 00462cf0  8d45ff                 -lea eax, [ebp - 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
L_0x00462cf3:
    // 00462cf3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462cf5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00462cf8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462cfa  bab4095100             -mov edx, 0x5109b4
    cpu.edx = 5310900 /*0x5109b4*/;
    // 00462cff  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462d02  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462d06  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462d08  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462d0a  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00462d0e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462d0f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462d10  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462d14  892d4c6c4c00           -mov dword ptr [0x4c6c4c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */) = cpu.ebp;
    // 00462d1a  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00462d1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462d1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462d1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462d20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462d21:
    // 00462d21  80fc52                 +cmp ah, 0x52
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(82 /*0x52*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462d24  750a                   -jne 0x462d30
    if (!cpu.flags.zf)
    {
        goto L_0x00462d30;
    }
    // 00462d26  b890095100             -mov eax, 0x510990
    cpu.eax = 5310864 /*0x510990*/;
    // 00462d2b  e920ffffff             -jmp 0x462c50
    goto L_0x00462c50;
L_0x00462d30:
    // 00462d30  80fcb0                 +cmp ah, 0xb0
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(176 /*0xb0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462d33  750a                   -jne 0x462d3f
    if (!cpu.flags.zf)
    {
        goto L_0x00462d3f;
    }
    // 00462d35  b89c095100             -mov eax, 0x51099c
    cpu.eax = 5310876 /*0x51099c*/;
    // 00462d3a  e911ffffff             -jmp 0x462c50
    goto L_0x00462c50;
L_0x00462d3f:
    // 00462d3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462d41  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00462d43  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00462d46  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00462d49  050c095100             +add eax, 0x51090c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5310732 /*0x51090c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00462d4e  e9fdfeffff             -jmp 0x462c50
    goto L_0x00462c50;
L_0x00462d53:
    // 00462d53  8d4d01                 -lea ecx, [ebp + 1]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00462d56  e900ffffff             -jmp 0x462c5b
    goto L_0x00462c5b;
L_0x00462d5b:
    // 00462d5b  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00462d5c  e94effffff             -jmp 0x462caf
    goto L_0x00462caf;
L_0x00462d61:
    // 00462d61  ba4f000000             -mov edx, 0x4f
    cpu.edx = 79 /*0x4f*/;
    // 00462d66  e96bffffff             -jmp 0x462cd6
    goto L_0x00462cd6;
L_0x00462d6b:
    // 00462d6b  b84f000000             -mov eax, 0x4f
    cpu.eax = 79 /*0x4f*/;
    // 00462d70  eb81                   -jmp 0x462cf3
    goto L_0x00462cf3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462d80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462d80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462d81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462d82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462d83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462d84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462d85  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00462d88  8b154c6c4c00           -mov edx, dword ptr [0x4c6c4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 00462d8e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00462d90  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00462d97  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462d99  bbb4095100             -mov ebx, 0x5109b4
    cpu.ebx = 5310900 /*0x5109b4*/;
    // 00462d9e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462da1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462da3  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00462da6  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462da9  0f8c39010000           -jl 0x462ee8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462ee8;
    }
    // 00462daf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462db1:
    // 00462db1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00462db3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00462db6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00462db8  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 00462dbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462dc0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462dc2  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00462dc9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462dcb  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00462dd0  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00462dd7  891c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.ebx;
    // 00462dde  be58085100             -mov esi, 0x510858
    cpu.esi = 5310552 /*0x510858*/;
    // 00462de3  8b1d58085100           -mov ebx, dword ptr [0x510858]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310552) /* 0x510858 */);
    // 00462de9  893485d4095100         -mov dword ptr [eax*4 + 0x5109d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.esi;
    // 00462df0  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00462df3  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00462df6  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00462df9  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 00462e00  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00462e03  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00462e06  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00462e09  891c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ebx;
    // 00462e10  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e13  0f8cd7000000           -jl 0x462ef0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462ef0;
    }
    // 00462e19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462e1b:
    // 00462e1b  8b3d7cd14d00           -mov edi, dword ptr [0x4dd17c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 00462e21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462e23  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00462e25  7573                   -jne 0x462e9a
    if (!cpu.flags.zf)
    {
        goto L_0x00462e9a;
    }
    // 00462e27  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e2a  0f8cc8000000           -jl 0x462ef8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462ef8;
    }
    // 00462e30  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00462e32:
    // 00462e32  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00462e39  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00462e3b  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 00462e40  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462e43  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462e45  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00462e4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00462e4e  bb0c095100             -mov ebx, 0x51090c
    cpu.ebx = 5310732 /*0x51090c*/;
    // 00462e53  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00462e5a  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
    // 00462e5f  891c85d4095100         -mov dword ptr [eax*4 + 0x5109d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.ebx;
    // 00462e66  8b1d0c095100           -mov ebx, dword ptr [0x51090c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310732) /* 0x51090c */);
    // 00462e6c  892c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.ebp;
    // 00462e73  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00462e76  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00462e79  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00462e7c  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 00462e83  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00462e86  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00462e89  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00462e8c  891c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ebx;
    // 00462e93  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e96  7c68                   -jl 0x462f00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462f00;
    }
    // 00462e98  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00462e9a:
    // 00462e9a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00462e9c  7e65                   -jle 0x462f03
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462f03;
    }
    // 00462e9e  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00462ea1:
    // 00462ea1  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00462ea8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00462eaa  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00462eac  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00462eb3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00462eb5  7e53                   -jle 0x462f0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462f0a;
    }
    // 00462eb7  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00462eba:
    // 00462eba  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00462ec1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00462ec3  bbb4095100             -mov ebx, 0x5109b4
    cpu.ebx = 5310900 /*0x5109b4*/;
    // 00462ec8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00462ecb  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462ecd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462ecf  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00462ed1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00462ed5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462ed6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00462ed7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462ed9  89154c6c4c00           -mov dword ptr [0x4c6c4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */) = cpu.edx;
    // 00462edf  83c408                 +add esp, 8
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
    // 00462ee2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ee4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ee5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ee6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ee7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462ee8:
    // 00462ee8  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00462eeb  e9c1feffff             -jmp 0x462db1
    goto L_0x00462db1;
L_0x00462ef0:
    // 00462ef0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00462ef3  e923ffffff             -jmp 0x462e1b
    goto L_0x00462e1b;
L_0x00462ef8:
    // 00462ef8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00462efb  e932ffffff             -jmp 0x462e32
    goto L_0x00462e32;
L_0x00462f00:
    // 00462f00  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00462f01  eb97                   -jmp 0x462e9a
    goto L_0x00462e9a;
L_0x00462f03:
    // 00462f03  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00462f08  eb97                   -jmp 0x462ea1
    goto L_0x00462ea1;
L_0x00462f0a:
    // 00462f0a  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00462f0f  eba9                   -jmp 0x462eba
    goto L_0x00462eba;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462f22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462f23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462f25  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00462f28  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00462f2a  ba74075100             -mov edx, 0x510774
    cpu.edx = 5310324 /*0x510774*/;
    // 00462f2f  b8fc065100             -mov eax, 0x5106fc
    cpu.eax = 5310204 /*0x5106fc*/;
    // 00462f34  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00462f36  e815040000             -call 0x463350
    cpu.esp -= 4;
    sub_463350(app, cpu);
    if (cpu.terminate) return;
    // 00462f3b  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00462f40  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462f44  e897010000             -call 0x4630e0
    cpu.esp -= 4;
    sub_4630e0(app, cpu);
    if (cpu.terminate) return;
    // 00462f49  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f4d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462f4e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f52  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f53  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f57  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462f58  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f5d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462f61  e8da7dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462f66  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462f6a  e871060000             -call 0x4635e0
    cpu.esp -= 4;
    sub_4635e0(app, cpu);
    if (cpu.terminate) return;
    // 00462f6f  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462f74  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f78  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462f79  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462f7e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f82  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462f83  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462f87  e8b47dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462f8c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462f90  e80bf4ffff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 00462f95  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462f9a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f9f  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fa3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462fa4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fa8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462fa9  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462fad  ba84075100             -mov edx, 0x510784
    cpu.edx = 5310340 /*0x510784*/;
    // 00462fb2  e8897dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462fb7  b8c4075100             -mov eax, 0x5107c4
    cpu.eax = 5310404 /*0x5107c4*/;
    // 00462fbc  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462fc0  e88b030000             -call 0x463350
    cpu.esp -= 4;
    sub_463350(app, cpu);
    if (cpu.terminate) return;
    // 00462fc5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462fca  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462fcf  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462fd4  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462fd8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462fd9  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462fdd  e85e7dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00462fe2  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00462fe7  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462feb  e8f0000000             -call 0x4630e0
    cpu.esp -= 4;
    sub_4630e0(app, cpu);
    if (cpu.terminate) return;
    // 00462ff0  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462ff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462ff5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462ff9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462ffa  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462ffe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462fff  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463003  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463004  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463008  e8337dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046300d  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463011  e8da040000             -call 0x4634f0
    cpu.esp -= 4;
    sub_4634f0(app, cpu);
    if (cpu.terminate) return;
    // 00463016  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046301a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046301b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046301f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463020  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463024  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463025  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463029  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046302a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046302e  e80d7dffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00463033  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463037  e864f3ffff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 0046303c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463040  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463041  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463045  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463046  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046304a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046304b  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046304f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463050  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463054  ba94075100             -mov edx, 0x510794
    cpu.edx = 5310356 /*0x510794*/;
    // 00463059  e8e27cffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 0046305e  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463062  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463064  e867020000             -call 0x4632d0
    cpu.esp -= 4;
    sub_4632d0(app, cpu);
    if (cpu.terminate) return;
    // 00463069  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046306d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046306e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463072  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463073  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463077  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463078  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046307c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046307d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463081  e8ba7cffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00463086  833d7cd14d0002         +cmp dword ptr [0x4dd17c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046308d  7411                   -je 0x4630a0
    if (cpu.flags.zf)
    {
        goto L_0x004630a0;
    }
    // 0046308f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463091  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00463093  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463094  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463095  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00463097  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046309a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046309b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046309c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046309d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046309e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046309f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004630a0:
    // 004630a0  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004630a4  e887030000             -call 0x463430
    cpu.esp -= 4;
    sub_463430(app, cpu);
    if (cpu.terminate) return;
    // 004630a9  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004630ae  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004630b3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004630b8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004630bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004630bd  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004630c1  e87a7cffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004630c6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004630c8  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004630ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004630cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004630cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004630ce  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004630d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4630e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004630e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004630e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004630e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004630e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004630e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004630e5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004630e8  8b154c6c4c00           -mov edx, dword ptr [0x4c6c4c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */);
    // 004630ee  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004630f0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004630f2  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004630f9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004630fb  bbb4095100             -mov ebx, 0x5109b4
    cpu.ebx = 5310900 /*0x5109b4*/;
    // 00463100  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463103  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463105  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00463108  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046310b  0f8c83010000           -jl 0x463294
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463294;
    }
    // 00463111  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00463113:
    // 00463113  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0046311a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046311c  bfb4095100             -mov edi, 0x5109b4
    cpu.edi = 5310900 /*0x5109b4*/;
    // 00463121  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463124  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463126  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046312d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046312f  893c85b4095100         -mov dword ptr [eax*4 + 0x5109b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.edi;
    // 00463136  bb4c085100             -mov ebx, 0x51084c
    cpu.ebx = 5310540 /*0x51084c*/;
    // 0046313b  893485b8095100         -mov dword ptr [eax*4 + 0x5109b8], esi
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.esi;
    // 00463142  891c85d4095100         -mov dword ptr [eax*4 + 0x5109d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.ebx;
    // 00463149  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046314b  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 00463152  893485c0095100         -mov dword ptr [eax*4 + 0x5109c0], esi
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.esi;
    // 00463159  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046315c  0f8c3a010000           -jl 0x46329c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046329c;
    }
    // 00463162  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00463164:
    // 00463164  8b2d7cd14d00           -mov ebp, dword ptr [0x4dd17c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 0046316a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046316c  83fd07                 +cmp ebp, 7
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046316f  0f85ec000000           -jne 0x463261
    if (!cpu.flags.zf)
    {
        goto L_0x00463261;
    }
    // 00463175  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463178  0f8c26010000           -jl 0x4632a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004632a4;
    }
    // 0046317e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00463180:
    // 00463180  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00463187  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00463189  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 0046318e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463191  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463193  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046319a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046319c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004631a1  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 004631a8  891c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.ebx;
    // 004631af  be0c095100             -mov esi, 0x51090c
    cpu.esi = 5310732 /*0x51090c*/;
    // 004631b4  8b1d0c095100           -mov ebx, dword ptr [0x51090c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310732) /* 0x51090c */);
    // 004631ba  893485d4095100         -mov dword ptr [eax*4 + 0x5109d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.esi;
    // 004631c1  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004631c4  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 004631c7  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 004631ca  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 004631d1  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004631d4  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004631d7  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004631da  891c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ebx;
    // 004631e1  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004631e4  0f8cc2000000           -jl 0x4632ac
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004632ac;
    }
    // 004631ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004631ec:
    // 004631ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004631ee  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004631f1  0f8cbd000000           -jl 0x4632b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004632b4;
    }
    // 004631f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004631f9:
    // 004631f9  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00463200  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00463202  beb4095100             -mov esi, 0x5109b4
    cpu.esi = 5310900 /*0x5109b4*/;
    // 00463207  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046320a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046320c  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00463213  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463215  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 0046321a  893485b4095100         -mov dword ptr [eax*4 + 0x5109b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5310900) /* 0x5109b4 */ + cpu.eax * 4) = cpu.esi;
    // 00463221  bd18095100             -mov ebp, 0x510918
    cpu.ebp = 5310744 /*0x510918*/;
    // 00463226  893c85b8095100         -mov dword ptr [eax*4 + 0x5109b8], edi
    app->getMemory<x86::reg32>(x86::reg32(5310904) /* 0x5109b8 */ + cpu.eax * 4) = cpu.edi;
    // 0046322d  8b1d18095100           -mov ebx, dword ptr [0x510918]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310744) /* 0x510918 */);
    // 00463233  892c85d4095100         -mov dword ptr [eax*4 + 0x5109d4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5310932) /* 0x5109d4 */ + cpu.eax * 4) = cpu.ebp;
    // 0046323a  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046323d  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00463240  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00463243  893485bc095100         -mov dword ptr [eax*4 + 0x5109bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310908) /* 0x5109bc */ + cpu.eax * 4) = cpu.esi;
    // 0046324a  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046324d  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00463250  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00463253  891c85c0095100         -mov dword ptr [eax*4 + 0x5109c0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5310912) /* 0x5109c0 */ + cpu.eax * 4) = cpu.ebx;
    // 0046325a  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046325d  7c5d                   -jl 0x4632bc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004632bc;
    }
    // 0046325f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00463261:
    // 00463261  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00463263  7e5a                   -jle 0x4632bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004632bf;
    }
    // 00463265  8d42ff                 -lea eax, [edx - 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
L_0x00463268:
    // 00463268  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046326a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046326d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046326f  bbb4095100             -mov ebx, 0x5109b4
    cpu.ebx = 5310900 /*0x5109b4*/;
    // 00463274  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463277  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463279  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046327b  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046327d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00463281  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463282  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463283  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00463285  89154c6c4c00           -mov dword ptr [0x4c6c4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5008460) /* 0x4c6c4c */) = cpu.edx;
    // 0046328b  83c408                 +add esp, 8
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
    // 0046328e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046328f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463290  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463291  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463292  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463293  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463294:
    // 00463294  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00463297  e977feffff             -jmp 0x463113
    goto L_0x00463113;
L_0x0046329c:
    // 0046329c  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046329f  e9c0feffff             -jmp 0x463164
    goto L_0x00463164;
L_0x004632a4:
    // 004632a4  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004632a7  e9d4feffff             -jmp 0x463180
    goto L_0x00463180;
L_0x004632ac:
    // 004632ac  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004632af  e938ffffff             -jmp 0x4631ec
    goto L_0x004631ec;
L_0x004632b4:
    // 004632b4  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004632b7  e93dffffff             -jmp 0x4631f9
    goto L_0x004631f9;
L_0x004632bc:
    // 004632bc  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004632bd  eba2                   -jmp 0x463261
    goto L_0x00463261;
L_0x004632bf:
    // 004632bf  b84f000000             -mov eax, 0x4f
    cpu.eax = 79 /*0x4f*/;
    // 004632c4  eba2                   -jmp 0x463268
    goto L_0x00463268;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4632d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004632d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004632d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004632d2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004632d5  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004632d7  c7420417000000         -mov dword ptr [edx + 4], 0x17
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 23 /*0x17*/;
    // 004632de  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004632e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004632e6  745b                   -je 0x463343
    if (cpu.flags.zf)
    {
        goto L_0x00463343;
    }
    // 004632e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004632e9  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004632ec  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 004632ef  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004632f2  66895a08               -mov word ptr [edx + 8], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 004632f6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004632f9  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004632fc  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 004632ff  66895a0a               -mov word ptr [edx + 0xa], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00463303  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00463306  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00463309  c1e314                 -shl ebx, 0x14
    cpu.ebx <<= 20 /*0x14*/ % 32;
    // 0046330c  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0046330f  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00463312  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00463314  66895a0c               -mov word ptr [edx + 0xc], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00463318  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046331b  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046331e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00463321  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00463324  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00463327  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00463329  6689420e               -mov word ptr [edx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0046332d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046332e:
    // 0046332e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463330  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00463332  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00463336  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00463339  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046333a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046333b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046333d  83c408                 +add esp, 8
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
    // 00463340  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463341  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463342  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463343:
    // 00463343  66c74208ffff           -mov word ptr [edx + 8], 0xffff
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 65535 /*0xffff*/;
    // 00463349  ebe3                   -jmp 0x46332e
    goto L_0x0046332e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463352  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463353  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463356  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00463358  c7420417000000         -mov dword ptr [edx + 4], 0x17
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 23 /*0x17*/;
    // 0046335f  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00463365  668b5810               -mov bx, word ptr [eax + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00463369  66895a08               -mov word ptr [edx + 8], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.bx;
    // 0046336d  668b5814               -mov bx, word ptr [eax + 0x14]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00463371  66895a0a               -mov word ptr [edx + 0xa], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = cpu.bx;
    // 00463375  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00463378  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046337c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046337e  66895a0c               -mov word ptr [edx + 0xc], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bx;
    // 00463382  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463384  668b401c               -mov ax, word ptr [eax + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00463388  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046338c  6689420e               -mov word ptr [edx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00463390  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463391  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463392  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00463394  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463397  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463398  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463399  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046339a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4633a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004633a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004633a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004633a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004633a4  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004633a7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004633a9  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004633ab  e830020000             -call 0x4635e0
    cpu.esp -= 4;
    sub_4635e0(app, cpu);
    if (cpu.terminate) return;
    // 004633b0  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004633b4  e837010000             -call 0x4634f0
    cpu.esp -= 4;
    sub_4634f0(app, cpu);
    if (cpu.terminate) return;
    // 004633b9  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004633bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004633be  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004633c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004633c3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004633c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004633c8  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004633cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004633cd  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004633d1  e86a79ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 004633d6  833d7cd14d0002         +cmp dword ptr [0x4dd17c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004633dd  7410                   -je 0x4633ef
    if (cpu.flags.zf)
    {
        goto L_0x004633ef;
    }
    // 004633df  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004633e1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004633e3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004633e4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004633e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004633e7  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004633ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004633eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004633ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004633ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004633ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004633ef:
    // 004633ef  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004633f3  e838000000             -call 0x463430
    cpu.esp -= 4;
    sub_463430(app, cpu);
    if (cpu.terminate) return;
    // 004633f8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004633fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004633fd  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463402  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463406  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463407  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046340b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046340c  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463410  e82b79ffff             -call 0x45ad40
    cpu.esp -= 4;
    sub_45ad40(app, cpu);
    if (cpu.terminate) return;
    // 00463415  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463417  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00463419  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046341a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046341b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046341d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00463420  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463421  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463422  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463423  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463431  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463432  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463433  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463436  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00463438  e8e378ffff             -call 0x45ad20
    cpu.esp -= 4;
    sub_45ad20(app, cpu);
    if (cpu.terminate) return;
    // 0046343d  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 00463442  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463446  e88578ffff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 0046344b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046344d  0f8483000000           -je 0x4634d6
    if (cpu.flags.zf)
    {
        goto L_0x004634d6;
    }
    // 00463453  8b3558d14d00           -mov esi, dword ptr [0x4dd158]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099864) /* 0x4dd158 */);
    // 00463459  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046345c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463460  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
    // 00463467  c7400413000000         -mov dword ptr [eax + 4], 0x13
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 19 /*0x13*/;
    // 0046346e  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463470  be4c085100             -mov esi, 0x51084c
    cpu.esi = 5310540 /*0x51084c*/;
    // 00463475  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00463478  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046347c  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046347e  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00463481  a158d14d00             -mov eax, dword ptr [0x4dd158]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099864) /* 0x4dd158 */);
    // 00463486  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00463489  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463490  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463492  8b14854c085100         -mov edx, dword ptr [eax*4 + 0x51084c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310540) /* 0x51084c */ + cpu.eax * 4);
    // 00463499  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046349c  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046349f  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004634a3  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 004634a6  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004634a9  8b04854c085100         -mov eax, dword ptr [eax*4 + 0x51084c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310540) /* 0x51084c */ + cpu.eax * 4);
    // 004634b0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004634b3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004634b6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004634ba  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004634bd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004634bf  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004634c2  e8c977ffff             -call 0x45ac90
    cpu.esp -= 4;
    sub_45ac90(app, cpu);
    if (cpu.terminate) return;
    // 004634c7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004634c9  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004634cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004634cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004634cd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004634cf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004634d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004634d6:
    // 004634d6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004634d8  e81379ffff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 004634dd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004634df  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004634e1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004634e2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004634e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004634e5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004634e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004634eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4634f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004634f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004634f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004634f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004634f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004634f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004634f5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004634f8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004634fa  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004634ff  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00463501  be50224600             -mov esi, 0x462250
    cpu.esi = 4596304 /*0x462250*/;
    // 00463506  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0046350b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046350d  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00463512  be34065100             -mov esi, 0x510634
    cpu.esi = 5310004 /*0x510634*/;
    // 00463517  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0046351c  83c678                 -add esi, 0x78
    (cpu.esi) += x86::reg32(x86::sreg32(120 /*0x78*/));
L_0x0046351f:
    // 0046351f  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00463524  668b7c14d8             -mov di, word ptr [esp + edx - 0x28]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-40) /* -0x28 */ + cpu.edx * 1);
    // 00463529  899838065100           -mov dword ptr [eax + 0x510638], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310008) /* 0x510638 */) = cpu.ebx;
    // 0046352f  668b1dc4075100         -mov bx, word ptr [0x5107c4]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310404) /* 0x5107c4 */);
    // 00463536  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463538  668b7c14dc             -mov di, word ptr [esp + edx - 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-36) /* -0x24 */ + cpu.edx * 1);
    // 0046353d  6689983e065100         -mov word ptr [eax + 0x51063e], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310014) /* 0x51063e */) = cpu.bx;
    // 00463544  668b1dc8075100         -mov bx, word ptr [0x5107c8]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310408) /* 0x5107c8 */);
    // 0046354b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046354d  668b7c14d8             -mov di, word ptr [esp + edx - 0x28]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-40) /* -0x28 */ + cpu.edx * 1);
    // 00463552  66899840065100         -mov word ptr [eax + 0x510640], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310016) /* 0x510640 */) = cpu.bx;
    // 00463559  668b1dcc075100         -mov bx, word ptr [0x5107cc]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310412) /* 0x5107cc */);
    // 00463560  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463562  668b7c14dc             -mov di, word ptr [esp + edx - 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-36) /* -0x24 */ + cpu.edx * 1);
    // 00463567  66899842065100         -mov word ptr [eax + 0x510642], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310018) /* 0x510642 */) = cpu.bx;
    // 0046356e  668b1dd0075100         -mov bx, word ptr [0x5107d0]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310416) /* 0x5107d0 */);
    // 00463575  89b034065100           -mov dword ptr [eax + 0x510634], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310004) /* 0x510634 */) = cpu.esi;
    // 0046357b  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046357d  66899844065100         -mov word ptr [eax + 0x510644], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310020) /* 0x510644 */) = cpu.bx;
    // 00463584  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463587  744c                   -je 0x4635d5
    if (cpu.flags.zf)
    {
        goto L_0x004635d5;
    }
    // 00463589  8a1d39085100           -mov bl, byte ptr [0x510839]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5310521) /* 0x510839 */);
L_0x0046358f:
    // 0046358f  88983c065100           -mov byte ptr [eax + 0x51063c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5310012) /* 0x51063c */) = cpu.bl;
    // 00463595  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00463598  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046359b  41                     -inc ecx
    (cpu.ecx)++;
    // 0046359c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046359f  83f90a                 +cmp ecx, 0xa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004635a2  0f8c77ffffff           -jl 0x46351f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046351f;
    }
    // 004635a8  bf98065100             -mov edi, 0x510698
    cpu.edi = 5310104 /*0x510698*/;
    // 004635ad  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004635af  b8e8065100             -mov eax, 0x5106e8
    cpu.eax = 5310184 /*0x5106e8*/;
    // 004635b4  8935e8065100           -mov dword ptr [0x5106e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5310184) /* 0x5106e8 */) = cpu.esi;
    // 004635ba  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 004635be  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004635c2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004635c4  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004635c8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004635c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004635ca  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004635cc  83c430                 +add esp, 0x30
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
    // 004635cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004635d5:
    // 004635d5  8a1d38085100           -mov bl, byte ptr [0x510838]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5310520) /* 0x510838 */);
    // 004635db  ebb2                   -jmp 0x46358f
    goto L_0x0046358f;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4635e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004635e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004635e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004635e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004635e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004635e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004635e5  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004635e8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004635ea  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004635ef  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004635f1  be28224600             -mov esi, 0x462228
    cpu.esi = 4596264 /*0x462228*/;
    // 004635f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004635f8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004635fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004635fc  be34065100             -mov esi, 0x510634
    cpu.esi = 5310004 /*0x510634*/;
    // 00463601  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463603  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00463606:
    // 00463606  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 0046360b  668b3c14               -mov di, word ptr [esp + edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 1);
    // 0046360f  899838065100           -mov dword ptr [eax + 0x510638], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310008) /* 0x510638 */) = cpu.ebx;
    // 00463615  668b1dfc065100         -mov bx, word ptr [0x5106fc]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310204) /* 0x5106fc */);
    // 0046361c  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046361e  668b7c1404             -mov di, word ptr [esp + edx + 4]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 00463623  6689983e065100         -mov word ptr [eax + 0x51063e], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310014) /* 0x51063e */) = cpu.bx;
    // 0046362a  668b1d00075100         -mov bx, word ptr [0x510700]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310208) /* 0x510700 */);
    // 00463631  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463633  668b3c14               -mov di, word ptr [esp + edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + cpu.edx * 1);
    // 00463637  66899840065100         -mov word ptr [eax + 0x510640], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310016) /* 0x510640 */) = cpu.bx;
    // 0046363e  668b1d04075100         -mov bx, word ptr [0x510704]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310212) /* 0x510704 */);
    // 00463645  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463647  668b7c1404             -mov di, word ptr [esp + edx + 4]
    cpu.di = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 0046364c  66899842065100         -mov word ptr [eax + 0x510642], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310018) /* 0x510642 */) = cpu.bx;
    // 00463653  668b1d08075100         -mov bx, word ptr [0x510708]
    cpu.bx = app->getMemory<x86::reg16>(x86::reg32(5310216) /* 0x510708 */);
    // 0046365a  89b034065100           -mov dword ptr [eax + 0x510634], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5310004) /* 0x510634 */) = cpu.esi;
    // 00463660  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463662  66899844065100         -mov word ptr [eax + 0x510644], bx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5310020) /* 0x510644 */) = cpu.bx;
    // 00463669  83f904                 +cmp ecx, 4
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
    // 0046366c  744c                   -je 0x4636ba
    if (cpu.flags.zf)
    {
        goto L_0x004636ba;
    }
    // 0046366e  8a1d71075100           -mov bl, byte ptr [0x510771]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5310321) /* 0x510771 */);
L_0x00463674:
    // 00463674  88983c065100           -mov byte ptr [eax + 0x51063c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5310012) /* 0x51063c */) = cpu.bl;
    // 0046367a  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046367d  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00463680  41                     -inc ecx
    (cpu.ecx)++;
    // 00463681  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463684  83f905                 +cmp ecx, 5
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
    // 00463687  0f8c79ffffff           -jl 0x463606
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463606;
    }
    // 0046368d  bf34065100             -mov edi, 0x510634
    cpu.edi = 5310004 /*0x510634*/;
    // 00463692  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00463694  b884065100             -mov eax, 0x510684
    cpu.eax = 5310084 /*0x510684*/;
    // 00463699  893584065100           -mov dword ptr [0x510684], esi
    app->getMemory<x86::reg32>(x86::reg32(5310084) /* 0x510684 */) = cpu.esi;
    // 0046369f  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 004636a3  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004636a7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004636a9  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004636ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004636ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004636af  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004636b1  83c430                 +add esp, 0x30
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
    // 004636b4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004636ba:
    // 004636ba  8a1d70075100           -mov bl, byte ptr [0x510770]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5310320) /* 0x510770 */);
    // 004636c0  ebb2                   -jmp 0x463674
    goto L_0x00463674;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4636d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004636d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004636d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004636d2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004636d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004636d7  8a2518155100           -mov ah, byte ptr [0x511518]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5313816) /* 0x511518 */);
    // 004636dd  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004636df  754b                   -jne 0x46372c
    if (!cpu.flags.zf)
    {
        goto L_0x0046372c;
    }
    // 004636e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004636e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004636e3  bb19000000             -mov ebx, 0x19
    cpu.ebx = 25 /*0x19*/;
    // 004636e8  be04155100             -mov esi, 0x511504
    cpu.esi = 5313796 /*0x511504*/;
    // 004636ed  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004636f1  a20c155100             -mov byte ptr [0x51150c], al
    app->getMemory<x86::reg8>(x86::reg32(5313804) /* 0x51150c */) = cpu.al;
    // 004636f6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004636f8  891d08155100           -mov dword ptr [0x511508], ebx
    app->getMemory<x86::reg32>(x86::reg32(5313800) /* 0x511508 */) = cpu.ebx;
    // 004636fe  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00463702  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00463706  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046370a  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0046370c  890d04155100           -mov dword ptr [0x511504], ecx
    app->getMemory<x86::reg32>(x86::reg32(5313796) /* 0x511504 */) = cpu.ecx;
    // 00463712  fec3                   -inc bl
    (cpu.bl)++;
    // 00463714  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463715  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463716  881d18155100           -mov byte ptr [0x511518], bl
    app->getMemory<x86::reg8>(x86::reg32(5313816) /* 0x511518 */) = cpu.bl;
    // 0046371c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046371d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046371e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463720  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00463722  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463723  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463724  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00463726  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463729  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046372a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046372b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046372c:
    // 0046372c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046372e  e8bd76ffff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 00463733  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463735  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00463737  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463738  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463739  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046373b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046373e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046373f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463740  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463756  bab81e0000             -mov edx, 0x1eb8
    cpu.edx = 7864 /*0x1eb8*/;
    // 0046375b  a15cd14d00             -mov eax, dword ptr [0x4dd15c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099868) /* 0x4dd15c */);
    // 00463760  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00463762  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00463765  c1e810                 +shr eax, 0x10
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
    // 00463768  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046376a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046376c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046376f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00463771  c1e210                 +shl edx, 0x10
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
    // 00463774  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00463776  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00463779  bbc4075100             -mov ebx, 0x5107c4
    cpu.ebx = 5310404 /*0x5107c4*/;
    // 0046377e  83f80f                 +cmp eax, 0xf
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
    // 00463781  0f8c87000000           -jl 0x46380e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046380e;
    }
    // 00463787  8b3530085100           -mov esi, dword ptr [0x510830]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5310512) /* 0x510830 */);
L_0x0046378d:
    // 0046378d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046378f  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 00463792  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00463795  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00463797  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463799  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046379b  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046379d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004637a2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004637a4  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004637ab  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004637ad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004637af  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004637b1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004637b3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004637b6  c1e810                 +shr eax, 0x10
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
    // 004637b9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004637bb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004637bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004637bf  8b6b70                 -mov ebp, dword ptr [ebx + 0x70]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 004637c2  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004637c8  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004637cb  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004637cd  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004637cf  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004637d1  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004637d3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004637d8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004637da  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004637e1  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004637e3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004637e5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004637e7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004637e9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004637ec  c1e810                 +shr eax, 0x10
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
    // 004637ef  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004637f1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004637f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004637f5  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004637f8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004637fa  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004637fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004637ff  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00463802  e839010000             -call 0x463940
    cpu.esp -= 4;
    sub_463940(app, cpu);
    if (cpu.terminate) return;
    // 00463807  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463808  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463809  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046380a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046380b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046380c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046380d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046380e:
    // 0046380e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463811  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00463814  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00463817  2b4634                 -sub eax, dword ptr [esi + 0x34]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */)));
    // 0046381a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046381c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00463821  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00463827  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046382a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046382c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046382f  c1e210                 +shl edx, 0x10
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
    // 00463832  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00463834  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00463837  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0046383a  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046383c  e94cffffff             -jmp 0x46378d
    goto L_0x0046378d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463852  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463853  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463854  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463855  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463856  8b1550d14d00           -mov edx, dword ptr [0x4dd150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099856) /* 0x4dd150 */);
    // 0046385c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046385e  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00463861  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463863  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00463865  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00463867  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046386a  c1e210                 +shl edx, 0x10
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
    // 0046386d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046386f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00463872  bbfc065100             -mov ebx, 0x5106fc
    cpu.ebx = 5310204 /*0x5106fc*/;
    // 00463877  83f80a                 +cmp eax, 0xa
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
    // 0046387a  0f8c89000000           -jl 0x463909
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463909;
    }
    // 00463880  8b3554075100           -mov esi, dword ptr [0x510754]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5310292) /* 0x510754 */);
L_0x00463886:
    // 00463886  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463888  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0046388b  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0046388e  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00463890  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463892  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00463894  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463896  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046389b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046389d  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004638a4  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004638a6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004638a8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004638aa  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004638ac  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004638af  c1e810                 +shr eax, 0x10
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
    // 004638b2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004638b4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004638b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004638b8  8b7b70                 -mov edi, dword ptr [ebx + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 004638bb  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 004638c1  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 004638c4  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004638c6  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004638c8  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004638ca  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004638cc  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004638d1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004638d3  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 004638da  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004638dc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004638de  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004638e0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004638e2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004638e5  c1e810                 +shr eax, 0x10
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
    // 004638e8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004638ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004638ec  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004638ee  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004638f0  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004638f3  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004638f6  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004638f8  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004638fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004638fd  e83e000000             -call 0x463940
    cpu.esp -= 4;
    sub_463940(app, cpu);
    if (cpu.terminate) return;
    // 00463902  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463903  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463904  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463905  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463906  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463907  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463908  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463909:
    // 00463909  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046390c  8d3403                 -lea esi, [ebx + eax]
    cpu.esi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0046390f  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00463912  8b5634                 -mov edx, dword ptr [esi + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 00463915  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00463917  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463919  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0046391f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00463925  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00463928  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046392a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046392d  c1e210                 +shl edx, 0x10
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
    // 00463930  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00463932  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00463935  8b7630                 -mov esi, dword ptr [esi + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00463938  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046393a  e947ffffff             -jmp 0x463886
    goto L_0x00463886;
}

/* align: skip 0x00 */
void Application::sub_463940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463941  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463942  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463943  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463944  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463945  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463946  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463948  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046394b  39d3                   +cmp ebx, edx
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
    // 0046394d  7e51                   -jle 0x4639a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004639a0;
    }
L_0x0046394f:
    // 0046394f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00463952  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00463955  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463957  7e4d                   -jle 0x4639a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004639a6;
    }
L_0x00463959:
    // 00463959  49                     -dec ecx
    (cpu.ecx)--;
    // 0046395a  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046395d  4a                     -dec edx
    (cpu.edx)--;
    // 0046395e  8b7820                 -mov edi, dword ptr [eax + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00463961  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00463964  39fa                   +cmp edx, edi
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
    // 00463966  7e45                   -jle 0x4639ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004639ad;
    }
L_0x00463968:
    // 00463968  8b6824                 -mov ebp, dword ptr [eax + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0046396b  897810                 -mov dword ptr [eax + 0x10], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0046396e  39e9                   +cmp ecx, ebp
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
    // 00463970  7e3f                   -jle 0x4639b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004639b1;
    }
    // 00463972  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x00463974:
    // 00463974  897814                 -mov dword ptr [eax + 0x14], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 00463977  8b7828                 -mov edi, dword ptr [eax + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046397a  39fb                   +cmp ebx, edi
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
    // 0046397c  7d37                   -jge 0x4639b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004639b5;
    }
L_0x0046397e:
    // 0046397e  8b682c                 -mov ebp, dword ptr [eax + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00463981  897818                 -mov dword ptr [eax + 0x18], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00463984  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463986  7d31                   -jge 0x4639b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004639b9;
    }
    // 00463988  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x0046398a:
    // 0046398a  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0046398d  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 00463990  895828                 -mov dword ptr [eax + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00463993  89702c                 -mov dword ptr [eax + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00463996  89781c                 -mov dword ptr [eax + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00463999  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046399f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004639a0:
    // 004639a0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004639a2  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004639a4  eba9                   -jmp 0x46394f
    goto L_0x0046394f;
L_0x004639a6:
    // 004639a6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004639a8  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004639ab  ebac                   -jmp 0x463959
    goto L_0x00463959;
L_0x004639ad:
    // 004639ad  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004639af  ebb7                   -jmp 0x463968
    goto L_0x00463968;
L_0x004639b1:
    // 004639b1  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004639b3  ebbf                   -jmp 0x463974
    goto L_0x00463974;
L_0x004639b5:
    // 004639b5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004639b7  ebc5                   -jmp 0x46397e
    goto L_0x0046397e;
L_0x004639b9:
    // 004639b9  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004639bb  ebcd                   -jmp 0x46398a
    goto L_0x0046398a;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4639c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004639c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004639c1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004639c3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004639c5  0f84d0000000           -je 0x463a9b
    if (cpu.flags.zf)
    {
        goto L_0x00463a9b;
    }
    // 004639cb  833df414510000         +cmp dword ptr [0x5114f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004639d2  0f84c5000000           -je 0x463a9d
    if (cpu.flags.zf)
    {
        goto L_0x00463a9d;
    }
    // 004639d8  833d0015510000         +cmp dword ptr [0x511500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5313792) /* 0x511500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004639df  0f85c4000000           -jne 0x463aa9
    if (!cpu.flags.zf)
    {
        goto L_0x00463aa9;
    }
L_0x004639e5:
    // 004639e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004639e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004639e7  8b0d18075100           -mov ecx, dword ptr [0x510718]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5310232) /* 0x510718 */);
    // 004639ed  8b1d14075100           -mov ebx, dword ptr [0x510714]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310228) /* 0x510714 */);
    // 004639f3  8b1510075100           -mov edx, dword ptr [0x510710]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310224) /* 0x510710 */);
    // 004639f9  a10c075100             -mov eax, dword ptr [0x51070c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310220) /* 0x51070c */);
    // 004639fe  e8ed320100             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 00463a03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463a05  e8463e0100             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
    // 00463a0a  833d7cd14d0004         +cmp dword ptr [0x4dd17c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463a11  7423                   -je 0x463a36
    if (cpu.flags.zf)
    {
        goto L_0x00463a36;
    }
    // 00463a13  8b0de0075100           -mov ecx, dword ptr [0x5107e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5310432) /* 0x5107e0 */);
    // 00463a19  8b1ddc075100           -mov ebx, dword ptr [0x5107dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5310428) /* 0x5107dc */);
    // 00463a1f  8b15d8075100           -mov edx, dword ptr [0x5107d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310424) /* 0x5107d8 */);
    // 00463a25  a1d4075100             -mov eax, dword ptr [0x5107d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310420) /* 0x5107d4 */);
    // 00463a2a  e8c1320100             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 00463a2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463a31  e81a3e0100             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
L_0x00463a36:
    // 00463a36  833d7cd14d0002         +cmp dword ptr [0x4dd17c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463a3d  7547                   -jne 0x463a86
    if (!cpu.flags.zf)
    {
        goto L_0x00463a86;
    }
    // 00463a3f  8b1558d14d00           -mov edx, dword ptr [0x4dd158]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099864) /* 0x4dd158 */);
    // 00463a45  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463a48  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00463a4f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00463a51  8b04854c085100         -mov eax, dword ptr [eax*4 + 0x51084c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310540) /* 0x51084c */ + cpu.eax * 4);
    // 00463a58  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00463a5b  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00463a5e  8b5802                 -mov ebx, dword ptr [eax + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00463a61  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00463a64  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00463a67  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00463a6a  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00463a6d  c1e014                 -shl eax, 0x14
    cpu.eax <<= 20 /*0x14*/ % 32;
    // 00463a70  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00463a73  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 00463a76  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463a78  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463a7a  e871320100             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 00463a7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463a81  e8ca3d0100             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
L_0x00463a86:
    // 00463a86  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 00463a8b  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00463a90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463a92  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00463a94  e857320100             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 00463a99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00463a9b:
    // 00463a9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463a9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463a9d:
    // 00463a9d  c705f414510001000000   -mov dword ptr [0x5114f4], 1
    app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */) = 1 /*0x1*/;
    // 00463aa7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463aa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463aa9:
    // 00463aa9  e8ba820200             -call 0x48bd68
    cpu.esp -= 4;
    sub_48bd68(app, cpu);
    if (cpu.terminate) return;
    // 00463aae  e932ffffff             -jmp 0x4639e5
    goto L_0x004639e5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463ac1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463ac2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463ac4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00463ac9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00463acb  7c2d                   -jl 0x463afa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463afa;
    }
    // 00463acd  833d0cd34d0000         +cmp dword ptr [0x4dd30c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100300) /* 0x4dd30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463ad4  7405                   -je 0x463adb
    if (cpu.flags.zf)
    {
        goto L_0x00463adb;
    }
L_0x00463ad6:
    // 00463ad6  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
L_0x00463adb:
    // 00463adb  83fa03                 +cmp edx, 3
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
    // 00463ade  7c28                   -jl 0x463b08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463b08;
    }
    // 00463ae0  83fa0a                 +cmp edx, 0xa
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
    // 00463ae3  7c12                   -jl 0x463af7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463af7;
    }
    // 00463ae5  83fa28                 +cmp edx, 0x28
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
    // 00463ae8  7c26                   -jl 0x463b10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463b10;
    }
    // 00463aea  83fa3c                 +cmp edx, 0x3c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463aed  7c25                   -jl 0x463b14
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463b14;
    }
    // 00463aef  83fa5a                 +cmp edx, 0x5a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463af2  7d26                   -jge 0x463b1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00463b1a;
    }
    // 00463af4  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00463af7:
    // 00463af7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463af8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463af9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463afa:
    // 00463afa  8b1d0cd34d00           -mov ebx, dword ptr [0x4dd30c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5100300) /* 0x4dd30c */);
    // 00463b00  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00463b02  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00463b04  75d5                   -jne 0x463adb
    if (!cpu.flags.zf)
    {
        goto L_0x00463adb;
    }
    // 00463b06  ebce                   -jmp 0x463ad6
    goto L_0x00463ad6;
L_0x00463b08:
    // 00463b08  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00463b0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463b10:
    // 00463b10  40                     -inc eax
    (cpu.eax)++;
    // 00463b11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463b14:
    // 00463b14  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00463b17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463b1a:
    // 00463b1a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463b1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463b20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463b21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463b23  e8c842fdff             -call 0x437df0
    cpu.esp -= 4;
    sub_437df0(app, cpu);
    if (cpu.terminate) return;
    // 00463b28  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463b2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463b2c  e84f46fdff             -call 0x438180
    cpu.esp -= 4;
    sub_438180(app, cpu);
    if (cpu.terminate) return;
    // 00463b31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463b33  7517                   -jne 0x463b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00463b4c;
    }
    // 00463b35  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(734) /* 0x2de */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463b3c  750e                   -jne 0x463b4c
    if (!cpu.flags.zf)
    {
        goto L_0x00463b4c;
    }
    // 00463b3e  a17cd14d00             -mov eax, dword ptr [0x4dd17c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 00463b43  8b0485fc6c4c00         -mov eax, dword ptr [eax*4 + 0x4c6cfc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008636) /* 0x4c6cfc */ + cpu.eax * 4);
    // 00463b4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463b4c:
    // 00463b4c  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 00463b51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463b52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463b60  a17cd14d00             -mov eax, dword ptr [0x4dd17c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 00463b65  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00463b68  059c6c4c00             -add eax, 0x4c6c9c
    (cpu.eax) += x86::reg32(x86::sreg32(5008540 /*0x4c6c9c*/));
    // 00463b6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_463b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463b70  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00463b76  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00463b7c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 00463b82  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463b90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463b91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463b93  e85842fdff             -call 0x437df0
    cpu.esp -= 4;
    sub_437df0(app, cpu);
    if (cpu.terminate) return;
    // 00463b98  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463b9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463b9c  e8df45fdff             -call 0x438180
    cpu.esp -= 4;
    sub_438180(app, cpu);
    if (cpu.terminate) return;
    // 00463ba1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463ba3  7524                   -jne 0x463bc9
    if (!cpu.flags.zf)
    {
        goto L_0x00463bc9;
    }
    // 00463ba5  80bade02000000         +cmp byte ptr [edx + 0x2de], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(734) /* 0x2de */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463bac  751b                   -jne 0x463bc9
    if (!cpu.flags.zf)
    {
        goto L_0x00463bc9;
    }
    // 00463bae  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00463bb3:
    // 00463bb3  8b151c155100           -mov edx, dword ptr [0x51151c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313820) /* 0x51151c */);
    // 00463bb9  39d0                   +cmp eax, edx
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
    // 00463bbb  7410                   -je 0x463bcd
    if (cpu.flags.zf)
    {
        goto L_0x00463bcd;
    }
    // 00463bbd  a31c155100             -mov dword ptr [0x51151c], eax
    app->getMemory<x86::reg32>(x86::reg32(5313820) /* 0x51151c */) = cpu.eax;
    // 00463bc2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00463bc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463bc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463bc9:
    // 00463bc9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00463bcb  ebe6                   -jmp 0x463bb3
    goto L_0x00463bb3;
L_0x00463bcd:
    // 00463bcd  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463bcf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463bd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463be0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463bf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463bf1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463bf3  8915f4145100           -mov dword ptr [0x5114f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */) = cpu.edx;
    // 00463bf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463bfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463c00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463c01  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463c06  e8c14e0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00463c0b  8b1510155100           -mov edx, dword ptr [0x511510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313808) /* 0x511510 */);
    // 00463c11  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00463c13  7502                   -jne 0x463c17
    if (!cpu.flags.zf)
    {
        goto L_0x00463c17;
    }
    // 00463c15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463c16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463c17:
    // 00463c17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00463c19  e8ae4e0100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00463c1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463c1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463c20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463c21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463c22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463c23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463c24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463c25  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463c26  81ec60010000           -sub esp, 0x160
    (cpu.esp) -= x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00463c2c  89842458010000         -mov dword ptr [esp + 0x158], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */) = cpu.eax;
    // 00463c33  b916000000             -mov ecx, 0x16
    cpu.ecx = 22 /*0x16*/;
    // 00463c38  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00463c3f  bd4c085100             -mov ebp, 0x51084c
    cpu.ebp = 5310540 /*0x51084c*/;
    // 00463c44  bed0214600             -mov esi, 0x4621d0
    cpu.esi = 4596176 /*0x4621d0*/;
    // 00463c49  a130d14d00             -mov eax, dword ptr [0x4dd130]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5099824) /* 0x4dd130 */);
    // 00463c4e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463c50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463c52  8915f4145100           -mov dword ptr [0x5114f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5313780) /* 0x5114f4 */) = cpu.edx;
    // 00463c58  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00463c5a  a3fc145100             -mov dword ptr [0x5114fc], eax
    app->getMemory<x86::reg32>(x86::reg32(5313788) /* 0x5114fc */) = cpu.eax;
    // 00463c5f  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463c64  bae8b74b00             -mov edx, 0x4bb7e8
    cpu.edx = 4962280 /*0x4bb7e8*/;
    // 00463c69  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463c6e  83c518                 -add ebp, 0x18
    (cpu.ebp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00463c71  e82afa0000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463c76  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463c7b  ba10b84b00             -mov edx, 0x4bb810
    cpu.edx = 4962320 /*0x4bb810*/;
    // 00463c80  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463c85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463c87  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463c8a  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00463c91  e80afa0000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463c96  8d4758                 -lea eax, [edi + 0x58]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(88) /* 0x58 */);
    // 00463c99  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00463c9e  8984245c010000         -mov dword ptr [esp + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(348) /* 0x15c */) = cpu.eax;
L_0x00463ca5:
    // 00463ca5  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463caa  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00463cac  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00463cae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463cb0  e8ebf90000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463cb5  46                     -inc esi
    (cpu.esi)++;
    // 00463cb6  8b8c245c010000         -mov ecx, dword ptr [esp + 0x15c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(348) /* 0x15c */);
    // 00463cbd  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463cc0  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463cc3  39cf                   +cmp edi, ecx
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
    // 00463cc5  75de                   -jne 0x463ca5
    if (!cpu.flags.zf)
    {
        goto L_0x00463ca5;
    }
    // 00463cc7  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463cce  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463cd3  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463cd5  ba18b84b00             -mov edx, 0x4bb818
    cpu.edx = 4962328 /*0x4bb818*/;
    // 00463cda  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463cdd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463cdf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463ce1  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463ce6  46                     -inc esi
    (cpu.esi)++;
    // 00463ce7  e8b4f90000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463cec  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463cf3  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463cf8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463cfa  ba20b84b00             -mov edx, 0x4bb820
    cpu.edx = 4962336 /*0x4bb820*/;
    // 00463cff  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463d02  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463d04  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463d06  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463d0b  46                     -inc esi
    (cpu.esi)++;
    // 00463d0c  e88ff90000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463d11  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463d18  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463d1d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463d1f  ba28b84b00             -mov edx, 0x4bb828
    cpu.edx = 4962344 /*0x4bb828*/;
    // 00463d24  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463d27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463d29  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463d2b  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463d30  e86bf90000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463d35  8b9c2458010000         -mov ebx, dword ptr [esp + 0x158]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(344) /* 0x158 */);
    // 00463d3c  46                     -inc esi
    (cpu.esi)++;
    // 00463d3d  83fb07                 +cmp ebx, 7
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
    // 00463d40  0f84ef000000           -je 0x463e35
    if (cpu.flags.zf)
    {
        goto L_0x00463e35;
    }
    // 00463d46  83fb04                 +cmp ebx, 4
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
    // 00463d49  0f851f010000           -jne 0x463e6e
    if (!cpu.flags.zf)
    {
        goto L_0x00463e6e;
    }
    // 00463d4f  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00463d56  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463d58  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00463d5b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00463d5d  81c54c085100           -add ebp, 0x51084c
    (cpu.ebp) += x86::reg32(x86::sreg32(5310540 /*0x51084c*/));
L_0x00463d63:
    // 00463d63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463d64  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463d68  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463d6c  6840b84b00             -push 0x4bb840
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962368 /*0x4bb840*/;
    cpu.esp -= 4;
    // 00463d71  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00463d73  46                     -inc esi
    (cpu.esi)++;
    // 00463d74  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463d75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463d77  47                     -inc edi
    (cpu.edi)++;
    // 00463d78  e8a4660100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00463d7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463d80  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463d85  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463d88  e813f90000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463d8d  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463d90  7cd1                   -jl 0x463d63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463d63;
    }
    // 00463d92  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463d99  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463d9e  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463da0  ba48b84b00             -mov edx, 0x4bb848
    cpu.edx = 4962376 /*0x4bb848*/;
    // 00463da5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463da8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463daa  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463dac  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463db1  46                     -inc esi
    (cpu.esi)++;
    // 00463db2  e8e9f80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463db7  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463dbe  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463dc3  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463dc5  ba50b84b00             -mov edx, 0x4bb850
    cpu.edx = 4962384 /*0x4bb850*/;
    // 00463dca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463dcd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463dcf  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463dd1  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463dd6  46                     -inc esi
    (cpu.esi)++;
    // 00463dd7  e8c4f80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463ddc  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463de3  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463de8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463dea  ba58b84b00             -mov edx, 0x4bb858
    cpu.edx = 4962392 /*0x4bb858*/;
    // 00463def  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463df2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463df4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463df6  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463dfb  46                     -inc esi
    (cpu.esi)++;
    // 00463dfc  e89ff80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463e01  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463e08  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463e0d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463e0f  ba60b84b00             -mov edx, 0x4bb860
    cpu.edx = 4962400 /*0x4bb860*/;
    // 00463e14  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463e17  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463e19  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463e1b  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463e20  e87bf80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463e25  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00463e28:
    // 00463e28  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00463e2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463e35:
    // 00463e35  b90c095100             -mov ecx, 0x51090c
    cpu.ecx = 5310732 /*0x51090c*/;
    // 00463e3a  ba30b84b00             -mov edx, 0x4bb830
    cpu.edx = 4962352 /*0x4bb830*/;
    // 00463e3f  a110155100             -mov eax, dword ptr [0x511510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313808) /* 0x511510 */);
    // 00463e44  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463e46  e855f80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463e4b  b918095100             -mov ecx, 0x510918
    cpu.ecx = 5310744 /*0x510918*/;
    // 00463e50  ba38b84b00             -mov edx, 0x4bb838
    cpu.edx = 4962360 /*0x4bb838*/;
    // 00463e55  a110155100             -mov eax, dword ptr [0x511510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313808) /* 0x511510 */);
    // 00463e5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463e5c  e83ff80000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463e61  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00463e67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463e6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463e6e:
    // 00463e6e  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00463e71  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00463e78  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463e7a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463e7d  054c085100             -add eax, 0x51084c
    (cpu.eax) += x86::reg32(x86::sreg32(5310540 /*0x51084c*/));
    // 00463e82  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00463e84  0f8495000000           -je 0x463f1f
    if (cpu.flags.zf)
    {
        goto L_0x00463f1f;
    }
    // 00463e8a  83fb02                 +cmp ebx, 2
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
    // 00463e8d  7599                   -jne 0x463e28
    if (!cpu.flags.zf)
    {
        goto L_0x00463e28;
    }
    // 00463e8f  ba70b84b00             -mov edx, 0x4bb870
    cpu.edx = 4962416 /*0x4bb870*/;
    // 00463e94  8b3514155100           -mov esi, dword ptr [0x511514]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463e9a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00463e9c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463e9e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463ea0  e8fbf70000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463ea5  b94c085100             -mov ecx, 0x51084c
    cpu.ecx = 5310540 /*0x51084c*/;
    // 00463eaa  ba78b84b00             -mov edx, 0x4bb878
    cpu.edx = 4962424 /*0x4bb878*/;
    // 00463eaf  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00463eb6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463eb8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00463eba  8d7701                 -lea esi, [edi + 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00463ebd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463ec0  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00463ec5  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00463ecc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463ece  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00463ed0  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463ed5  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 00463ed8  e8c3f70000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463edd  81c54c085100           -add ebp, 0x51084c
    (cpu.ebp) += x86::reg32(x86::sreg32(5310540 /*0x51084c*/));
L_0x00463ee3:
    // 00463ee3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463ee4  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463ee8  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463eec  6880b84b00             -push 0x4bb880
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962432 /*0x4bb880*/;
    cpu.esp -= 4;
    // 00463ef1  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00463ef3  46                     -inc esi
    (cpu.esi)++;
    // 00463ef4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463ef5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463ef7  47                     -inc edi
    (cpu.edi)++;
    // 00463ef8  e824650100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00463efd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463f00  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463f05  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463f08  e893f70000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463f0d  83ff07                 +cmp edi, 7
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
    // 00463f10  7cd1                   -jl 0x463ee3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463ee3;
    }
    // 00463f12  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00463f18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463f1f:
    // 00463f1f  ba68b84b00             -mov edx, 0x4bb868
    cpu.edx = 4962408 /*0x4bb868*/;
    // 00463f24  8b3514155100           -mov esi, dword ptr [0x511514]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00463f2a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00463f2c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00463f2e  e86df70000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00463f33  81c460010000           -add esp, 0x160
    (cpu.esp) += x86::reg32(x86::sreg32(352 /*0x160*/));
    // 00463f39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_463f40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463f40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463f41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463f42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463f43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463f44  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00463f4a  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463f51  7414                   -je 0x463f67
    if (cpu.flags.zf)
    {
        goto L_0x00463f67;
    }
    // 00463f53  8b35ecd24d00           -mov esi, dword ptr [0x4dd2ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 00463f59  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 00463f5c  8bb650d34d00           -mov esi, dword ptr [esi + 0x4dd350]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5100368) /* 0x4dd350 */);
    // 00463f62  83fe0c                 +cmp esi, 0xc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463f65  7c0b                   -jl 0x463f72
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463f72;
    }
L_0x00463f67:
    // 00463f67  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00463f6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463f72:
    // 00463f72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463f73  8b0d7ce54d00           -mov ecx, dword ptr [0x4de57c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5105020) /* 0x4de57c */);
    // 00463f79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463f7a  68f0b74b00             -push 0x4bb7f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962288 /*0x4bb7f0*/;
    cpu.esp -= 4;
    // 00463f7f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463f83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463f84  e898640100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00463f89  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463f8c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463f8e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00463f90  e82f7e0100             -call 0x47bdc4
    cpu.esp -= 4;
    sub_47bdc4(app, cpu);
    if (cpu.terminate) return;
    // 00463f95  a314155100             -mov dword ptr [0x511514], eax
    app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */) = cpu.eax;
    // 00463f9a  83fe05                 +cmp esi, 5
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
    // 00463f9d  746f                   -je 0x46400e
    if (cpu.flags.zf)
    {
        goto L_0x0046400e;
    }
    // 00463f9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463fa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463fa3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00463fa8  e853f30000             -call 0x473300
    cpu.esp -= 4;
    sub_473300(app, cpu);
    if (cpu.terminate) return;
L_0x00463fad:
    // 00463fad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463faf  891d10155100           -mov dword ptr [0x511510], ebx
    app->getMemory<x86::reg32>(x86::reg32(5313808) /* 0x511510 */) = cpu.ebx;
    // 00463fb5  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463fb8  75ad                   -jne 0x463f67
    if (!cpu.flags.zf)
    {
        goto L_0x00463f67;
    }
    // 00463fba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463fbb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463fbc  8b3d7ce54d00           -mov edi, dword ptr [0x4de57c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5105020) /* 0x4de57c */);
    // 00463fc2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463fc3  6800b84b00             -push 0x4bb800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4962304 /*0x4bb800*/;
    cpu.esp -= 4;
    // 00463fc8  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463fcc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463fcd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463fcf  e84d640100             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00463fd4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00463fd7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463fdb  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00463fdd  e8e27d0100             -call 0x47bdc4
    cpu.esp -= 4;
    sub_47bdc4(app, cpu);
    if (cpu.terminate) return;
    // 00463fe2  8b0decd24d00           -mov ecx, dword ptr [0x4dd2ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 00463fe8  a310155100             -mov dword ptr [0x511510], eax
    app->getMemory<x86::reg32>(x86::reg32(5313808) /* 0x511510 */) = cpu.eax;
    // 00463fed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463fef  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00463ff2  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00463ff7  8b895cd34d00           -mov ecx, dword ptr [ecx + 0x4dd35c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5100380) /* 0x4dd35c */);
    // 00463ffd  e85e790000             -call 0x46b960
    cpu.esp -= 4;
    sub_46b960(app, cpu);
    if (cpu.terminate) return;
    // 00464002  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464003  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00464009  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046400a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046400b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046400c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046400d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046400e:
    // 0046400e  8b0decd24d00           -mov ecx, dword ptr [0x4dd2ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100268) /* 0x4dd2ec */);
    // 00464014  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00464016  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464018  c1e106                 +shl ecx, 6
    {
        x86::reg8 tmp = 6 /*0x6*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046401b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00464020  8b895cd34d00           -mov ecx, dword ptr [ecx + 0x4dd35c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5100380) /* 0x4dd35c */);
    // 00464026  e835790000             -call 0x46b960
    cpu.esp -= 4;
    sub_46b960(app, cpu);
    if (cpu.terminate) return;
    // 0046402b  eb80                   -jmp 0x463fad
    goto L_0x00463fad;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_464030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464031  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464032  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464033  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464034  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464035  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464038  833d7cd14d0000         +cmp dword ptr [0x4dd17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046403f  7d09                   -jge 0x46404a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046404a;
    }
    // 00464041  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464044  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464045  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464048  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464049  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046404a:
    // 0046404a  bae8b74b00             -mov edx, 0x4bb7e8
    cpu.edx = 4962280 /*0x4bb7e8*/;
    // 0046404f  a114155100             -mov eax, dword ptr [0x511514]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5313812) /* 0x511514 */);
    // 00464054  e84b2d0100             -call 0x476da4
    cpu.esp -= 4;
    sub_476da4(app, cpu);
    if (cpu.terminate) return;
    // 00464059  e8d67b0200             -call 0x48bc34
    cpu.esp -= 4;
    sub_48bc34(app, cpu);
    if (cpu.terminate) return;
    // 0046405e  8b0d7cd14d00           -mov ecx, dword ptr [0x4dd17c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 00464064  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00464066  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00464069  83f904                 +cmp ecx, 4
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
    // 0046406c  755e                   -jne 0x4640cc
    if (!cpu.flags.zf)
    {
        goto L_0x004640cc;
    }
    // 0046406e  bf2c065100             -mov edi, 0x51062c
    cpu.edi = 5309996 /*0x51062c*/;
    // 00464073  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00464075  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464076  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464077  bf24065100             -mov edi, 0x510624
    cpu.edi = 5309988 /*0x510624*/;
    // 0046407c  8d7508                 -lea esi, [ebp + 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046407f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464080  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464081  bf44085100             -mov edi, 0x510844
    cpu.edi = 5310532 /*0x510844*/;
    // 00464086  8d7510                 -lea esi, [ebp + 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00464089  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046408a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046408b  bf3c085100             -mov edi, 0x51083c
    cpu.edi = 5310524 /*0x51083c*/;
    // 00464090  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00464093  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464094  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464095  bfb4075100             -mov edi, 0x5107b4
    cpu.edi = 5310388 /*0x5107b4*/;
    // 0046409a  8d7520                 -lea esi, [ebp + 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0046409d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046409e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046409f  bf0c075100             -mov edi, 0x51070c
    cpu.edi = 5310220 /*0x51070c*/;
    // 004640a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004640a6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004640a7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004640a8  bf14075100             -mov edi, 0x510714
    cpu.edi = 5310228 /*0x510714*/;
    // 004640ad  8d7528                 -lea esi, [ebp + 0x28]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 004640b0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004640b1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004640b2:
    // 004640b2  833d7cd14d0000         +cmp dword ptr [0x4dd17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004640b9  7462                   -je 0x46411d
    if (cpu.flags.zf)
    {
        goto L_0x0046411d;
    }
    // 004640bb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004640bd  8935bc075100           -mov dword ptr [0x5107bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5310396) /* 0x5107bc */) = cpu.esi;
    // 004640c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004640c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004640cc:
    // 004640cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004640cd  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004640d4  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 004640d9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004640db  b9506c4c00             -mov ecx, 0x4c6c50
    cpu.ecx = 5008464 /*0x4c6c50*/;
    // 004640e0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004640e2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004640e4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004640e6  b8fc065100             -mov eax, 0x5106fc
    cpu.eax = 5310204 /*0x5106fc*/;
    // 004640eb  e850000000             -call 0x464140
    cpu.esp -= 4;
    sub_464140(app, cpu);
    if (cpu.terminate) return;
    // 004640f0  8b157cd14d00           -mov edx, dword ptr [0x4dd17c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
    // 004640f6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004640fd  b9506c4c00             -mov ecx, 0x4c6c50
    cpu.ecx = 5008464 /*0x4c6c50*/;
    // 00464102  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00464104  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00464109  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046410b  8d5560                 -lea edx, [ebp + 0x60]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
    // 0046410e  01c1                   +add ecx, eax
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
    // 00464110  b8c4075100             -mov eax, 0x5107c4
    cpu.eax = 5310404 /*0x5107c4*/;
    // 00464115  e826000000             -call 0x464140
    cpu.esp -= 4;
    sub_464140(app, cpu);
    if (cpu.terminate) return;
    // 0046411a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046411b  eb95                   -jmp 0x4640b2
    goto L_0x004640b2;
L_0x0046411d:
    // 0046411d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00464120  8b4038                 -mov eax, dword ptr [eax + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 00464123  a3bc075100             -mov dword ptr [0x5107bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5310396) /* 0x5107bc */) = cpu.eax;
    // 00464128  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046412b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046412c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046412d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046412e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046412f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464130  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464140  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464141  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464142  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464143  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464146  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00464148  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046414a  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046414d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046414f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00464151  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00464154  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00464157  8d7208                 -lea esi, [edx + 8]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046415a  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046415c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046415f  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00464162  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00464164  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00464166  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464168  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046416a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046416c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046416f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00464171  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00464174  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00464176  e8e5780200             -call 0x48ba60
    cpu.esp -= 4;
    sub_48ba60(app, cpu);
    if (cpu.terminate) return;
    // 0046417b  8d4f30                 -lea ecx, [edi + 0x30]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(48) /* 0x30 */);
    // 0046417e  894770                 -mov dword ptr [edi + 0x70], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00464181  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00464183:
    // 00464183  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464186  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00464188  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046418b  e8404e0200             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 00464190  8941fc                 -mov dword ptr [ecx - 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00464193  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00464194  7550                   -jne 0x4641e6
    if (!cpu.flags.zf)
    {
        goto L_0x004641e6;
    }
    // 00464196  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00464199  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046419b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046419e  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004641a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004641a3  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004641a5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004641a8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004641ab  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004641ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004641af  8a5102                 -mov dl, byte ptr [ecx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004641b2  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004641b4  e8a3230100             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004641b9  884774                 -mov byte ptr [edi + 0x74], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(116) /* 0x74 */) = cpu.al;
    // 004641bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004641be  8a4103                 -mov al, byte ptr [ecx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 004641c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004641c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004641c5  8a4104                 -mov al, byte ptr [ecx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004641c8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004641cb  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004641ce  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004641d0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004641d2  8a4105                 -mov al, byte ptr [ecx + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 004641d5  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004641d7  e880230100             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 004641dc  884775                 -mov byte ptr [edi + 0x75], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(117) /* 0x75 */) = cpu.al;
    // 004641df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004641e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004641e6:
    // 004641e6  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004641e8  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 004641ea  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004641ed  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004641ef  2b4704                 +sub eax, dword ptr [edi + 4]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004641f2  eb8f                   -jmp 0x464183
    goto L_0x00464183;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 0000000000000000000000000000000000000000000000000000000000000000 */
void Application::sub_464220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464220  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464222  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464230  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00464235  0f8555000000           -jne 0x464290
    if (!cpu.flags.zf)
    {
        goto L_0x00464290;
    }
    // 0046423b  f6056819510020         +test byte ptr [0x511968], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 32 /*0x20*/));
    // 00464242  7546                   -jne 0x46428a
    if (!cpu.flags.zf)
    {
        goto L_0x0046428a;
    }
L_0x00464244:
    // 00464244  83f84b                 +cmp eax, 0x4b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(75 /*0x4b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464247  7509                   -jne 0x464252
    if (!cpu.flags.zf)
    {
        goto L_0x00464252;
    }
    // 00464249  f6056819510004         +test byte ptr [0x511968], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 4 /*0x4*/));
    // 00464250  7538                   -jne 0x46428a
    if (!cpu.flags.zf)
    {
        goto L_0x0046428a;
    }
L_0x00464252:
    // 00464252  83f84d                 +cmp eax, 0x4d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(77 /*0x4d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464255  7509                   -jne 0x464260
    if (!cpu.flags.zf)
    {
        goto L_0x00464260;
    }
    // 00464257  f6056819510008         +test byte ptr [0x511968], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 8 /*0x8*/));
    // 0046425e  752a                   -jne 0x46428a
    if (!cpu.flags.zf)
    {
        goto L_0x0046428a;
    }
L_0x00464260:
    // 00464260  83f848                 +cmp eax, 0x48
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(72 /*0x48*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464263  7509                   -jne 0x46426e
    if (!cpu.flags.zf)
    {
        goto L_0x0046426e;
    }
    // 00464265  f6056819510001         +test byte ptr [0x511968], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 1 /*0x1*/));
    // 0046426c  751c                   -jne 0x46428a
    if (!cpu.flags.zf)
    {
        goto L_0x0046428a;
    }
L_0x0046426e:
    // 0046426e  83f850                 +cmp eax, 0x50
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
    // 00464271  7509                   -jne 0x46427c
    if (!cpu.flags.zf)
    {
        goto L_0x0046427c;
    }
    // 00464273  f6056819510002         +test byte ptr [0x511968], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 2 /*0x2*/));
    // 0046427a  750e                   -jne 0x46428a
    if (!cpu.flags.zf)
    {
        goto L_0x0046428a;
    }
L_0x0046427c:
    // 0046427c  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046427f  751a                   -jne 0x46429b
    if (!cpu.flags.zf)
    {
        goto L_0x0046429b;
    }
    // 00464281  f6056819510010         +test byte ptr [0x511968], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) & 16 /*0x10*/));
    // 00464288  7411                   -je 0x46429b
    if (cpu.flags.zf)
    {
        goto L_0x0046429b;
    }
L_0x0046428a:
    // 0046428a  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0046428f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464290:
    // 00464290  80b884854c0000         +cmp byte ptr [eax + 0x4c8584], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014916) /* 0x4c8584 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00464297  74ab                   -je 0x464244
    if (cpu.flags.zf)
    {
        goto L_0x00464244;
    }
    // 00464299  ebef                   -jmp 0x46428a
    goto L_0x0046428a;
L_0x0046429b:
    // 0046429b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046429d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4642a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004642a0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004642a5  80b884854c0000         +cmp byte ptr [eax + 0x4c8584], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014916) /* 0x4c8584 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004642ac  7503                   -jne 0x4642b1
    if (!cpu.flags.zf)
    {
        goto L_0x004642b1;
    }
    // 004642ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004642b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004642b1:
    // 004642b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004642b2  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004642b4  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004642b9  8835bb854c00           -mov byte ptr [0x4c85bb], dh
    app->getMemory<x86::reg8>(x86::reg32(5014971) /* 0x4c85bb */) = cpu.dh;
    // 004642bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004642c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4642d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004642d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004642d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004642d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004642d3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004642d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004642d7  c1ea14                 -shr edx, 0x14
    cpu.edx >>= 20 /*0x14*/ % 32;
    // 004642da  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004642dd  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004642e0  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004642e3  8b848240155100         -mov eax, dword ptr [edx + eax*4 + 0x511540]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5313856) /* 0x511540 */ + cpu.eax * 4);
    // 004642ea  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004642ec  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004642f2  81e200ff0000           -and edx, 0xff00
    cpu.edx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004642f8  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004642fb  39ca                   +cmp edx, ecx
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
    // 004642fd  7d34                   -jge 0x464333
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00464333;
    }
    // 004642ff  39d0                   +cmp eax, edx
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
    // 00464301  7c0d                   -jl 0x464310
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464310;
    }
    // 00464303  39c8                   +cmp eax, ecx
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
    // 00464305  7e0f                   -jle 0x464316
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464316;
    }
L_0x00464307:
    // 00464307  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0046430c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046430d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046430e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046430f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464310:
    // 00464310  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464312  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464315  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464316:
    // 00464316  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00464318  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046431a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046431d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046431f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00464321  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00464324  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464326  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00464328  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046432a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046432d  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046432f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464330  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464331  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464332  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464333:
    // 00464333  7e08                   -jle 0x46433d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046433d;
    }
    // 00464335  39c8                   +cmp eax, ecx
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
    // 00464337  7cce                   -jl 0x464307
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464307;
    }
    // 00464339  39d0                   +cmp eax, edx
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
    // 0046433b  7e06                   -jle 0x464343
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464343;
    }
L_0x0046433d:
    // 0046433d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046433f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464340  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464341  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464342  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464343:
    // 00464343  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00464345  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00464347  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00464349  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046434c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046434e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00464350  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00464353  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464355  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464357  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00464359  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046435b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046435e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00464360  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464361  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464362  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464363  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464371  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464372  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464374  c1e814                 -shr eax, 0x14
    cpu.eax >>= 20 /*0x14*/ % 32;
    // 00464377  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0046437a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046437c  e89f000000             -call 0x464420
    cpu.esp -= 4;
    sub_464420(app, cpu);
    if (cpu.terminate) return;
    // 00464381  b820155100             -mov eax, 0x511520
    cpu.eax = 5313824 /*0x511520*/;
    // 00464386  c1e106                 -shl ecx, 6
    cpu.ecx <<= 6 /*0x6*/ % 32;
    // 00464389  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0046438c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046438e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00464391  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00464394  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464396  89841120155100         -mov dword ptr [ecx + edx + 0x511520], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5313824) /* 0x511520 */ + cpu.edx * 1) = cpu.eax;
    // 0046439d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046439f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4643b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004643b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004643b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004643b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004643b4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004643b7  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004643ba  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004643bc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004643c1  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004643c4  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004643c6  85825c155100           -test dword ptr [edx + 0x51155c], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5313884) /* 0x51155c */) & cpu.eax));
    // 004643cc  7408                   -je 0x4643d6
    if (cpu.flags.zf)
    {
        goto L_0x004643d6;
    }
    // 004643ce  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004643d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004643d6:
    // 004643d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004643d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004643da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4643e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004643e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004643e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004643e3  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004643e6  83fa10                 +cmp edx, 0x10
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
    // 004643e9  7d17                   -jge 0x464402
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00464402;
    }
    // 004643eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004643ec  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004643ef  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004643f1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004643f6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004643f8  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004643fa  21049520195100         -and dword ptr [edx*4 + 0x511920], eax
    app->getMemory<x86::reg32>(x86::reg32(5314848) /* 0x511920 */ + cpu.edx * 4) &= x86::reg32(x86::sreg32(cpu.eax));
    // 00464401  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00464402:
    // 00464402  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464404  e817000000             -call 0x464420
    cpu.esp -= 4;
    sub_464420(app, cpu);
    if (cpu.terminate) return;
    // 00464409  b820155100             -mov eax, 0x511520
    cpu.eax = 5313824 /*0x511520*/;
    // 0046440e  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00464411  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00464413  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00464416  89823c155100           -mov dword ptr [edx + 0x51153c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5313852) /* 0x51153c */) = cpu.eax;
    // 0046441c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046441e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046441f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_464420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464421  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464422  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00464424  b86c195100             -mov eax, 0x51196c
    cpu.eax = 5314924 /*0x51196c*/;
L_0x00464429:
    // 00464429  0fbe10                 -movsx edx, byte ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 0046442c  83faff                 +cmp edx, -1
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
    // 0046442f  7e07                   -jle 0x464438
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464438;
    }
    // 00464431  39ca                   +cmp edx, ecx
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
    // 00464433  7403                   -je 0x464438
    if (cpu.flags.zf)
    {
        goto L_0x00464438;
    }
    // 00464435  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464436  ebf1                   -jmp 0x464429
    goto L_0x00464429;
L_0x00464438:
    // 00464438  803800                 +cmp byte ptr [eax], 0
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
    // 0046443b  7c03                   -jl 0x464440
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464440;
    }
    // 0046443d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046443e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046443f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464440:
    // 00464440  c64001ff               -mov byte ptr [eax + 1], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 255 /*0xff*/;
    // 00464444  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00464446  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464447  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464448  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464452  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464453  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464454  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464455  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464456  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464459  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046445b  bf6c195100             -mov edi, 0x51196c
    cpu.edi = 5314924 /*0x51196c*/;
    // 00464460  891568195100           -mov dword ptr [0x511968], edx
    app->getMemory<x86::reg32>(x86::reg32(5314920) /* 0x511968 */) = cpu.edx;
L_0x00464466:
    // 00464466  0fbe37                 -movsx esi, byte ptr [edi]
    cpu.esi = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edi)));
    // 00464469  83feff                 +cmp esi, -1
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
    // 0046446c  7e30                   -jle 0x46449e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046449e;
    }
    // 0046446e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00464470  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00464473  0520155100             +add eax, 0x511520
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5313824 /*0x511520*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00464478  8b6818                 -mov ebp, dword ptr [eax + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046447b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046447c  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046447f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464480  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00464483  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464484  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464487  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046448a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046448b  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046448e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00464491  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464492  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00464494  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00464496  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464497  e8f4010000             -call 0x464690
    cpu.esp -= 4;
    sub_464690(app, cpu);
    if (cpu.terminate) return;
    // 0046449c  ebc8                   -jmp 0x464466
    goto L_0x00464466;
L_0x0046449e:
    // 0046449e  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004644a3  e8c85f0100             -call 0x47a470
    cpu.esp -= 4;
    sub_47a470(app, cpu);
    if (cpu.terminate) return;
    // 004644a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004644aa  754d                   -jne 0x4644f9
    if (!cpu.flags.zf)
    {
        goto L_0x004644f9;
    }
    // 004644ac  833d68d54f0000         +cmp dword ptr [0x4fd568], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5231976) /* 0x4fd568 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004644b3  743b                   -je 0x4644f0
    if (cpu.flags.zf)
    {
        goto L_0x004644f0;
    }
L_0x004644b5:
    // 004644b5  8b3d64195100           -mov edi, dword ptr [0x511964]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5314916) /* 0x511964 */);
    // 004644bb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004644bd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004644bf  7e38                   -jle 0x4644f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004644f9;
    }
    // 004644c1  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x004644c5:
    // 004644c5  8d6c2404               -lea ebp, [esp + 4]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004644c9  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004644cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004644cf  b96c195100             -mov ecx, 0x51196c
    cpu.ecx = 5314924 /*0x51196c*/;
    // 004644d4  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004644d8  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004644dc  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004644df  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
L_0x004644e1:
    // 004644e1  0fbe01                 -movsx eax, byte ptr [ecx]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.ecx)));
    // 004644e4  83f8ff                 +cmp eax, -1
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
    // 004644e7  7e51                   -jle 0x46453a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046453a;
    }
    // 004644e9  39f0                   +cmp eax, esi
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
    // 004644eb  7416                   -je 0x464503
    if (cpu.flags.zf)
    {
        goto L_0x00464503;
    }
L_0x004644ed:
    // 004644ed  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004644ee  ebf1                   -jmp 0x4644e1
    goto L_0x004644e1;
L_0x004644f0:
    // 004644f0  833df4d24d0002         +cmp dword ptr [0x4dd2f4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004644f7  7dbc                   -jge 0x4644b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004644b5;
    }
L_0x004644f9:
    // 004644f9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004644fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004644ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464500  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464501  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464502  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464503:
    // 00464503  ba20155100             -mov edx, 0x511520
    cpu.edx = 5313824 /*0x511520*/;
    // 00464508  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046450b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046450d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046450f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464511  7407                   -je 0x46451a
    if (cpu.flags.zf)
    {
        goto L_0x0046451a;
    }
    // 00464513  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00464515  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464517  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0046451a:
    // 0046451a  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046451d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046451f  7408                   -je 0x464529
    if (cpu.flags.zf)
    {
        goto L_0x00464529;
    }
    // 00464521  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00464523  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00464525  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00464529:
    // 00464529  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0046452c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046452e  74bd                   -je 0x4644ed
    if (cpu.flags.zf)
    {
        goto L_0x004644ed;
    }
    // 00464530  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00464532  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00464534  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00464538  ebb3                   -jmp 0x4644ed
    goto L_0x004644ed;
L_0x0046453a:
    // 0046453a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046453c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046453e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464540  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464542  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00464544  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464546  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00464548  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046454a  e841010000             -call 0x464690
    cpu.esp -= 4;
    sub_464690(app, cpu);
    if (cpu.terminate) return;
    // 0046454f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00464551  744e                   -je 0x4645a1
    if (cpu.flags.zf)
    {
        goto L_0x004645a1;
    }
    // 00464553  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00464556  3d00400000             +cmp eax, 0x4000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046455b  7d63                   -jge 0x4645c0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004645c0;
    }
    // 0046455d  800d6819510004         -or byte ptr [0x511968], 4
    app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00464564:
    // 00464564  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00464568  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046456e  7d60                   -jge 0x4645d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004645d0;
    }
    // 00464570  800d6819510001         -or byte ptr [0x511968], 1
    app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00464577:
    // 00464577  8b1568195100           -mov edx, dword ptr [0x511968]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314920) /* 0x511968 */);
    // 0046457d  8b3df4d24d00           -mov edi, dword ptr [0x4dd2f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
    // 00464583  80ca10                 -or dl, 0x10
    cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00464586  83ff02                 +cmp edi, 2
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
    // 00464589  7c56                   -jl 0x4645e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004645e1;
    }
    // 0046458b  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046458f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464593  858120195100           -test dword ptr [ecx + 0x511920], eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5314848) /* 0x511920 */) & cpu.eax));
L_0x00464599:
    // 00464599  7406                   -je 0x4645a1
    if (cpu.flags.zf)
    {
        goto L_0x004645a1;
    }
    // 0046459b  891568195100           -mov dword ptr [0x511968], edx
    app->getMemory<x86::reg32>(x86::reg32(5314920) /* 0x511968 */) = cpu.edx;
L_0x004645a1:
    // 004645a1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004645a5  8b1564195100           -mov edx, dword ptr [0x511964]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314916) /* 0x511964 */);
    // 004645ab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004645ae  46                     -inc esi
    (cpu.esi)++;
    // 004645af  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004645b3  39d6                   +cmp esi, edx
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
    // 004645b5  0f8d3effffff           -jge 0x4644f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004644f9;
    }
    // 004645bb  e905ffffff             -jmp 0x4644c5
    goto L_0x004644c5;
L_0x004645c0:
    // 004645c0  3d00c00000             +cmp eax, 0xc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004645c5  7e9d                   -jle 0x464564
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464564;
    }
    // 004645c7  800d6819510008         +or byte ptr [0x511968], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 004645ce  eb94                   -jmp 0x464564
    goto L_0x00464564;
L_0x004645d0:
    // 004645d0  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004645d6  7e9f                   -jle 0x464577
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464577;
    }
    // 004645d8  800d6819510002         +or byte ptr [0x511968], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5314920) /* 0x511968 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 004645df  eb96                   -jmp 0x464577
    goto L_0x00464577;
L_0x004645e1:
    // 004645e1  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004645e6  ebb1                   -jmp 0x464599
    goto L_0x00464599;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4645f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004645f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004645f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004645f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645f3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004645f6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004645f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004645fc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004645fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464600  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464601  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00464605  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464609  e882000000             -call 0x464690
    cpu.esp -= 4;
    sub_464690(app, cpu);
    if (cpu.terminate) return;
    // 0046460e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00464611  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464614  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464615  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464616  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464617  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464622  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464623  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464624  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464625  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00464628  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0046462d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046462f  be00424600             -mov esi, 0x464200
    cpu.esi = 4604416 /*0x464200*/;
    // 00464634  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00464636  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00464638  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0046463c  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046463f  7d0e                   -jge 0x46464f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046464f;
    }
    // 00464641  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00464648  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046464c  89140c                 -mov dword ptr [esp + ecx], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ecx * 1) = cpu.edx;
L_0x0046464f:
    // 0046464f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00464651  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00464655  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464656  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046465a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046465b  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046465f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464660  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00464664  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00464668  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464669  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046466b  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046466f  e81c000000             -call 0x464690
    cpu.esp -= 4;
    sub_464690(app, cpu);
    if (cpu.terminate) return;
    // 00464674  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00464678  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046467b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046467c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046467d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046467e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046467f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464680  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464690  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464691  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464692  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464693  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00464697  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464698  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046469c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046469d  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004646a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004646a2  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004646a6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004646a7  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004646ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004646ac  e84fbefbff             -call 0x420500
    cpu.esp -= 4;
    sub_420500(app, cpu);
    if (cpu.terminate) return;
    // 004646b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004646b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004646b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004646b4  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4646c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004646c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004646c1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004646c6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004646c8  740c                   -je 0x4646d6
    if (cpu.flags.zf)
    {
        goto L_0x004646d6;
    }
    // 004646ca  b81a000000             -mov eax, 0x1a
    cpu.eax = 26 /*0x1a*/;
    // 004646cf  e8fc3efeff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 004646d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004646d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004646d6:
    // 004646d6  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 004646db  e8f03efeff             -call 0x4485d0
    cpu.esp -= 4;
    sub_4485d0(app, cpu);
    if (cpu.terminate) return;
    // 004646e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004646e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4646f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004646f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004646f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004646f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004646f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004646f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004646f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004646f6  833d6019510000         +cmp dword ptr [0x511960], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5314912) /* 0x511960 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004646fd  7429                   -je 0x464728
    if (cpu.flags.zf)
    {
        goto L_0x00464728;
    }
    // 004646ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00464701:
    // 00464701  8b82b0d94d00           -mov eax, dword ptr [edx + 0x4dd9b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5102000) /* 0x4dd9b0 */);
    // 00464707  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046470c  83f801                 +cmp eax, 1
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
    // 0046470f  750c                   -jne 0x46471d
    if (!cpu.flags.zf)
    {
        goto L_0x0046471d;
    }
    // 00464711  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464713  05b0d94d00             -add eax, 0x4dd9b0
    (cpu.eax) += x86::reg32(x86::sreg32(5102000 /*0x4dd9b0*/));
    // 00464718  e883010000             -call 0x4648a0
    cpu.esp -= 4;
    sub_4648a0(app, cpu);
    if (cpu.terminate) return;
L_0x0046471d:
    // 0046471d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464720  81fa60010000           +cmp edx, 0x160
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(352 /*0x160*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464726  75d9                   -jne 0x464701
    if (!cpu.flags.zf)
    {
        goto L_0x00464701;
    }
L_0x00464728:
    // 00464728  b903010000             -mov ecx, 0x103
    cpu.ecx = 259 /*0x103*/;
    // 0046472d  be04480000             -mov esi, 0x4804
    cpu.esi = 18436 /*0x4804*/;
    // 00464732  bf04500000             -mov edi, 0x5004
    cpu.edi = 20484 /*0x5004*/;
    // 00464737  bd044b0000             -mov ebp, 0x4b04
    cpu.ebp = 19204 /*0x4b04*/;
    // 0046473c  b8044d0000             -mov eax, 0x4d04
    cpu.eax = 19716 /*0x4d04*/;
    // 00464741  ba041c0000             -mov edx, 0x1c04
    cpu.edx = 7172 /*0x1c04*/;
    // 00464746  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464748  890d28da4d00           -mov dword ptr [0x4dda28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */) = cpu.ecx;
    // 0046474e  891d2cda4d00           -mov dword ptr [0x4dda2c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102124) /* 0x4dda2c */) = cpu.ebx;
    // 00464754  893514da4d00           -mov dword ptr [0x4dda14], esi
    app->getMemory<x86::reg32>(x86::reg32(5102100) /* 0x4dda14 */) = cpu.esi;
    // 0046475a  893d18da4d00           -mov dword ptr [0x4dda18], edi
    app->getMemory<x86::reg32>(x86::reg32(5102104) /* 0x4dda18 */) = cpu.edi;
    // 00464760  892d1cda4d00           -mov dword ptr [0x4dda1c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102108) /* 0x4dda1c */) = cpu.ebp;
    // 00464766  a320da4d00             -mov dword ptr [0x4dda20], eax
    app->getMemory<x86::reg32>(x86::reg32(5102112) /* 0x4dda20 */) = cpu.eax;
    // 0046476b  891524da4d00           -mov dword ptr [0x4dda24], edx
    app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */) = cpu.edx;
    // 00464771  b9030f0000             -mov ecx, 0xf03
    cpu.ecx = 3843 /*0xf03*/;
    // 00464776  bb033b0000             -mov ebx, 0x3b03
    cpu.ebx = 15107 /*0x3b03*/;
    // 0046477b  be033c0000             -mov esi, 0x3c03
    cpu.esi = 15363 /*0x3c03*/;
    // 00464780  bf033d0000             -mov edi, 0x3d03
    cpu.edi = 15619 /*0x3d03*/;
    // 00464785  bd033e0000             -mov ebp, 0x3e03
    cpu.ebp = 15875 /*0x3e03*/;
    // 0046478a  b8033f0000             -mov eax, 0x3f03
    cpu.eax = 16131 /*0x3f03*/;
    // 0046478f  ba03400000             -mov edx, 0x4003
    cpu.edx = 16387 /*0x4003*/;
    // 00464794  890d30da4d00           -mov dword ptr [0x4dda30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */) = cpu.ecx;
    // 0046479a  891d3cda4d00           -mov dword ptr [0x4dda3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */) = cpu.ebx;
    // 004647a0  893538da4d00           -mov dword ptr [0x4dda38], esi
    app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */) = cpu.esi;
    // 004647a6  893d44da4d00           -mov dword ptr [0x4dda44], edi
    app->getMemory<x86::reg32>(x86::reg32(5102148) /* 0x4dda44 */) = cpu.edi;
    // 004647ac  892d48da4d00           -mov dword ptr [0x4dda48], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102152) /* 0x4dda48 */) = cpu.ebp;
    // 004647b2  a358da4d00             -mov dword ptr [0x4dda58], eax
    app->getMemory<x86::reg32>(x86::reg32(5102168) /* 0x4dda58 */) = cpu.eax;
    // 004647b7  89155cda4d00           -mov dword ptr [0x4dda5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5102172) /* 0x4dda5c */) = cpu.edx;
    // 004647bd  b903410000             -mov ecx, 0x4103
    cpu.ecx = 16643 /*0x4103*/;
    // 004647c2  bb03420000             -mov ebx, 0x4203
    cpu.ebx = 16899 /*0x4203*/;
    // 004647c7  be03430000             -mov esi, 0x4303
    cpu.esi = 17155 /*0x4303*/;
    // 004647cc  bf03440000             -mov edi, 0x4403
    cpu.edi = 17411 /*0x4403*/;
    // 004647d1  a1f4d24d00             -mov eax, dword ptr [0x4dd2f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
    // 004647d6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004647d8  890d54da4d00           -mov dword ptr [0x4dda54], ecx
    app->getMemory<x86::reg32>(x86::reg32(5102164) /* 0x4dda54 */) = cpu.ecx;
    // 004647de  891d68da4d00           -mov dword ptr [0x4dda68], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */) = cpu.ebx;
    // 004647e4  893564da4d00           -mov dword ptr [0x4dda64], esi
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.esi;
    // 004647ea  893d34da4d00           -mov dword ptr [0x4dda34], edi
    app->getMemory<x86::reg32>(x86::reg32(5102132) /* 0x4dda34 */) = cpu.edi;
    // 004647f0  892d10da4d00           -mov dword ptr [0x4dda10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102096) /* 0x4dda10 */) = cpu.ebp;
    // 004647f6  83f802                 +cmp eax, 2
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
    // 004647f9  0f8c6e000000           -jl 0x46486d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046486d;
    }
    // 004647ff  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00464804  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00464806:
    // 00464806  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00464809  898a1c195100           -mov dword ptr [edx + 0x51191c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5314844) /* 0x51191c */) = cpu.ecx;
    // 0046480f  83fa40                 +cmp edx, 0x40
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
    // 00464812  75f2                   -jne 0x464806
    if (!cpu.flags.zf)
    {
        goto L_0x00464806;
    }
    // 00464814  a16cda4d00             -mov eax, dword ptr [0x4dda6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102188) /* 0x4dda6c */);
    // 00464819  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046481b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00464821  83fa02                 +cmp edx, 2
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
    // 00464824  752b                   -jne 0x464851
    if (!cpu.flags.zf)
    {
        goto L_0x00464851;
    }
    // 00464826  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464828  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0046482b  83fa10                 +cmp edx, 0x10
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
    // 0046482e  7d21                   -jge 0x464851
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00464851;
    }
    // 00464830  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00464832  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00464835  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046483a  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0046483d  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046483f  8b1c9520195100         -mov ebx, dword ptr [edx*4 + 0x511920]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314848) /* 0x511920 */ + cpu.edx * 4);
    // 00464846  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00464848  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0046484a  891c9520195100         -mov dword ptr [edx*4 + 0x511920], ebx
    app->getMemory<x86::reg32>(x86::reg32(5314848) /* 0x511920 */ + cpu.edx * 4) = cpu.ebx;
L_0x00464851:
    // 00464851  a174da4d00             -mov eax, dword ptr [0x4dda74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102196) /* 0x4dda74 */);
    // 00464856  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464858  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046485e  83fa02                 +cmp edx, 2
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
    // 00464861  750a                   -jne 0x46486d
    if (!cpu.flags.zf)
    {
        goto L_0x0046486d;
    }
    // 00464863  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464865  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00464868  83fa10                 +cmp edx, 0x10
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
    // 0046486b  7c07                   -jl 0x464874
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464874;
    }
L_0x0046486d:
    // 0046486d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046486e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046486f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464870  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464871  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464872  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464873  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464874:
    // 00464874  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00464876  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00464879  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046487e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00464881  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00464883  8b349520195100         -mov esi, dword ptr [edx*4 + 0x511920]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5314848) /* 0x511920 */ + cpu.edx * 4);
    // 0046488a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0046488c  21c6                   -and esi, eax
    cpu.esi &= x86::reg32(x86::sreg32(cpu.eax));
    // 0046488e  89349520195100         -mov dword ptr [edx*4 + 0x511920], esi
    app->getMemory<x86::reg32>(x86::reg32(5314848) /* 0x511920 */ + cpu.edx * 4) = cpu.esi;
    // 00464895  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464896  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464897  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464898  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464899  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046489a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046489b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4648a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004648a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004648a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004648a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004648a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004648a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004648a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004648a6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004648a9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004648ad  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004648b1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004648b5  8b0d60195100           -mov ecx, dword ptr [0x511960]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5314912) /* 0x511960 */);
    // 004648bb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004648bd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004648bf  c1f81c                 -sar eax, 0x1c
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (28 /*0x1c*/ % 32));
    // 004648c2  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004648c5  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004648c9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004648cd  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004648cf  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004648d1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004648d3  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004648d6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004648d9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004648dd  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004648e0  c1e21c                 -shl edx, 0x1c
    cpu.edx <<= 28 /*0x1c*/ % 32;
    // 004648e3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004648e7  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004648ea  81e600ff0000           -and esi, 0xff00
    cpu.esi &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004648f0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004648f2  81e300ff0000           -and ebx, 0xff00
    cpu.ebx &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004648f8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x004648fb:
    // 004648fb  a160195100             -mov eax, dword ptr [0x511960]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314912) /* 0x511960 */);
    // 00464900  3b38                   +cmp edi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464902  0f8d7f010000           -jge 0x464a87
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00464a87;
    }
    // 00464908  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046490c  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046490e  7406                   -je 0x464916
    if (cpu.flags.zf)
    {
        goto L_0x00464916;
    }
L_0x00464910:
    // 00464910  83c114                 +add ecx, 0x14
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00464913  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464914  ebe5                   -jmp 0x4648fb
    goto L_0x004648fb;
L_0x00464916:
    // 00464916  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046491a  3b5104                 +cmp edx, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046491d  75f1                   -jne 0x464910
    if (!cpu.flags.zf)
    {
        goto L_0x00464910;
    }
    // 0046491f  8d830080ffff           -lea eax, [ebx - 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-32768) /* -0x8000 */);
    // 00464925  8dae0080ffff           -lea ebp, [esi - 0x8000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-32768) /* -0x8000 */);
    // 0046492b  39f3                   +cmp ebx, esi
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
    // 0046492d  0f8dcb000000           -jge 0x4649fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004649fe;
    }
    // 00464933  81fb00800000           +cmp ebx, 0x8000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464939  0f8d8b000000           -jge 0x4649ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004649ca;
    }
    // 0046493f  8b690c                 -mov ebp, dword ptr [ecx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464942  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00464945  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00464947  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00464949  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 0046494b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046494d  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00464950  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464952  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00464955  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00464958  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046495a  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0046495d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046495f  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00464962  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464965  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464969  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046496c  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046496f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464971  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00464974  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00464977:
    // 00464977  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00464979:
    // 00464979  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0046497c  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0046497f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00464981  0f8cf2000000           -jl 0x464a79
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a79;
    }
    // 00464987  81fbff000000           +cmp ebx, 0xff
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
    // 0046498d  7e05                   -jle 0x464994
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464994;
    }
    // 0046498f  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
L_0x00464994:
    // 00464994  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00464996  0f8ce4000000           -jl 0x464a80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464a80;
    }
    // 0046499c  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004649a2  7e05                   -jle 0x4649a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004649a9;
    }
    // 004649a4  beff000000             -mov esi, 0xff
    cpu.esi = 255 /*0xff*/;
L_0x004649a9:
    // 004649a9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004649ab  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004649ae  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004649b1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004649b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004649b5  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004649b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004649ba  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004649be  40                     -inc eax
    (cpu.eax)++;
    // 004649bf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004649c1  83c114                 +add ecx, 0x14
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004649c4  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004649c5  e931ffffff             -jmp 0x4648fb
    goto L_0x004648fb;
L_0x004649ca:
    // 004649ca  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004649cd  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004649d0  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004649d2  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004649d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004649d7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004649da  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004649dd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004649df  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 004649e2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004649e4  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004649e7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004649e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004649eb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004649ee  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004649f1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004649f3  c1f80f                 +sar eax, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004649f6  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004649f9  e979ffffff             -jmp 0x464977
    goto L_0x00464977;
L_0x004649fe:
    // 004649fe  81fb00800000           +cmp ebx, 0x8000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464a04  7e3d                   -jle 0x464a43
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00464a43;
    }
    // 00464a06  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464a09  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00464a0c  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00464a0e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00464a10  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00464a12  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00464a15  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464a17  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00464a1a  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00464a1d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464a1f  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00464a22  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00464a25  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00464a27  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00464a29  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00464a2c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464a2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00464a31  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00464a34  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464a36  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00464a39  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00464a3c  29c3                   +sub ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00464a3e  e936ffffff             -jmp 0x464979
    goto L_0x00464979;
L_0x00464a43:
    // 00464a43  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00464a46  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464a49  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00464a4b  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00464a4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00464a50  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00464a53  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00464a56  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464a58  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00464a5b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00464a5d  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00464a60  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00464a62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464a64  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00464a67  c1e20f                 +shl edx, 0xf
    {
        x86::reg8 tmp = 15 /*0xf*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00464a6a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00464a6c  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 00464a6f  8b7108                 -mov esi, dword ptr [ecx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00464a72  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00464a74  e900ffffff             -jmp 0x464979
    goto L_0x00464979;
L_0x00464a79:
    // 00464a79  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00464a7b  e914ffffff             -jmp 0x464994
    goto L_0x00464994;
L_0x00464a80:
    // 00464a80  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00464a82  e922ffffff             -jmp 0x4649a9
    goto L_0x004649a9;
L_0x00464a87:
    // 00464a87  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00464a8a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a8d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464a90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464aa0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464aa1  8b1560195100           -mov edx, dword ptr [0x511960]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314912) /* 0x511960 */);
    // 00464aa7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00464aa9  7502                   -jne 0x464aad
    if (!cpu.flags.zf)
    {
        goto L_0x00464aad;
    }
    // 00464aab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464aac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00464aad:
    // 00464aad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00464aaf  e818400100             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00464ab4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00464ab5  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
